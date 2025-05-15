// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
/*  (c) Copyright 2020 - 2023 Xilinx, Inc. All rights reserved.

    This file contains confidential and proprietary information
    of Xilinx, Inc. and is protected under U.S. and
    international copyright and other intellectual property
    laws.

    DISCLAIMER
    This disclaimer is not a license and does not grant any
    rights to the materials distributed herewith. Except as
    otherwise provided in a valid license issued to you by
    Xilinx, and to the maximum extent permitted by applicable
    law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
    WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
    AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
    BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
    INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
    (2) Xilinx shall not be liable (whether in contract or tort,
    including negligence, or under any other theory of
    liability) for any loss or damage of any kind or nature
    related to, arising under or in connection with these
    materials, including for any direct, or any indirect,
    special, incidental, or consequential loss or damage
    (including loss of data, profits, goodwill, or any type of
    loss or damage suffered as a result of any action brought
    by a third party) even if such damage or loss was
    reasonably foreseeable or Xilinx had been advised of the
    possibility of the same.

    CRITICAL APPLICATIONS
    Xilinx products are not designed or intended to be fail-
    safe, or for use in any application requiring fail-safe
    performance, such as life-support or safety devices or
    systems, Class III medical devices, nuclear facilities,
    applications related to the deployment of airbags, or any
    other applications that could lead to death, personal
    injury, or severe property or environmental damage
    (individually and collectively, "Critical
    Applications"). Customer assumes the sole risk and
    liability of any use of Xilinx products in Critical
    Applications, subject only to applicable laws and
    regulations governing limitations on product liability.

    THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
    PART OF THIS FILE AT ALL TIMES.                       */


#pragma once

#ifndef __AIE_API_DETAIL_AIE2_SLIDING_MUL_ACC32_FP_HPP__
#define __AIE_API_DETAIL_AIE2_SLIDING_MUL_ACC32_FP_HPP__

#include "../mul.hpp"
#include "../vector.hpp"

namespace aie::detail {

template <MulMacroOp MulOp, typename CoeffType, typename DataType>
static constexpr auto sliding_mul_accfloat_get_mul_op()
{
    if      constexpr (std::is_same_v<CoeffType, bfloat16>) {
        if      constexpr (MulOp == MulMacroOp::Mul)     return [](auto &&... args) __aie_inline { return ::mul_elem_16_2(args...); };
        else if constexpr (MulOp == MulMacroOp::NegMul)  return [](auto &&... args) __aie_inline { return ::negmul_elem_16_2(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_Mul) return [](auto &&... args) __aie_inline { return ::mac_elem_16_2(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_Mul) return [](auto &&... args) __aie_inline { return ::msc_elem_16_2(args...); };
    }
    else if constexpr (std::is_same_v<CoeffType, float>) {
        if      constexpr (MulOp == MulMacroOp::Mul)     return [](auto &&... args) __aie_inline { return ::mul_elem_16(args...); };
        else if constexpr (MulOp == MulMacroOp::NegMul)  return [](auto &&... args) __aie_inline { return ::negmul_elem_16(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_Mul) return [](auto &&... args) __aie_inline { return ::mac_elem_16(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_Mul) return [](auto &&... args) __aie_inline { return ::msc_elem_16(args...); };
    }
}

template <unsigned Lanes, unsigned Points>
struct sliding_mul_bits_impl<Lanes, Points, 1, 1, 1, 32, 16, 16, bfloat16, bfloat16>
{
    using  data_type = bfloat16;
    using coeff_type = bfloat16;
    using  accum_tag = accum_tag_for_mul_types<data_type, coeff_type, 32>;
    using accum_type = accum<accum_tag, Lanes>;

    static constexpr unsigned   lanes_per_mul = 16;
    static constexpr unsigned columns_per_mul = 1;
    static_assert(Points >= columns_per_mul);

    template <MulMacroOp MulOp, unsigned N_Coeff, unsigned N_Data, typename... Acc> requires((is_accum_v<Acc> && ...))
    static auto run(const vector<coeff_type, N_Coeff> &coeff,
                    unsigned coeff_start,
                    bool coeff_sign,
                    const vector<data_type, N_Data> &data,
                    unsigned data_start,
                    bool data_sign,
                    const Acc &... acc)
    {
        constexpr auto mac_op = sliding_mul_accfloat_get_mul_op<add_to_op<MulOp>(), coeff_type, data_type>();
        constexpr auto mul_op = sliding_mul_accfloat_get_mul_op<             MulOp, coeff_type, data_type>();

        constexpr unsigned data_elems = std::max(N_Data, lanes_per_mul);

        using accum_fp = decltype(accum_type().template grow_extract<lanes_per_mul>(0));

        accum_type ret;

        const auto zero = zeros<bfloat16, lanes_per_mul>::run();

        utils::unroll_for<unsigned, 0, std::max(1u, Lanes / lanes_per_mul)>([&](auto idx_y) __aie_inline {
            const unsigned data_start_local  = (data_start + idx_y * lanes_per_mul) % data_elems;
            const unsigned coeff_start_local = coeff_start % N_Coeff;

            accum_fp tmp;
            vector<data_type, lanes_per_mul> data_local;
            vector<coeff_type, lanes_per_mul> coeff_local;

            coeff_local = broadcast<coeff_type, lanes_per_mul>::run(coeff[coeff_start_local]);
            data_local  = shuffle_down_rotate<data_type, data_elems>::run(data.template grow_replicate<data_elems>(),
                                                                          data_start_local).template extract<lanes_per_mul>(0);

            tmp = mul_op(::concat(coeff_local, zero),
                         ::concat(data_local, zero),
                         (acc.template grow_extract<lanes_per_mul>(idx_y))...);

            utils::unroll_for<unsigned, 1, Points / columns_per_mul>([&](auto idx) __aie_inline {
                const unsigned data_start_local =  (data_start + columns_per_mul * idx + idx_y * lanes_per_mul) % data_elems;
                const unsigned coeff_start_local = (coeff_start + columns_per_mul * idx) % N_Coeff;

                coeff_local = broadcast<coeff_type, lanes_per_mul>::run(coeff[coeff_start_local]);
                data_local = shuffle_down_rotate<data_type, data_elems>::run(data.template grow_replicate<data_elems>(),
                                                                             data_start_local)
                                 .template extract<lanes_per_mul>(0);

                tmp = mac_op(::concat(coeff_local, zero),
                             ::concat(data_local, zero),
                             tmp);
            });

            if constexpr (Lanes <= lanes_per_mul)
                ret = tmp.template extract<Lanes>(0);
            else
                ret.insert(idx_y, tmp);
        });

        return ret;
    }
};

template <unsigned Lanes, unsigned Points>
struct sliding_mul_bits_impl<Lanes, Points, 1, 1, 1, 32, 32, 32, float, float>
{
    using  data_type = float;
    using coeff_type = float;
    using  accum_tag = accum_tag_for_mul_types<data_type, coeff_type, 32>;
    using accum_type = accum<accum_tag, Lanes>;

    static constexpr unsigned   lanes_per_mul = 16;
    static constexpr unsigned columns_per_mul = 1;
    static_assert(Points >= columns_per_mul);

    template <MulMacroOp MulOp, unsigned N_Coeff, unsigned N_Data, typename... Acc> requires((is_accum_v<Acc> && ...))
    static auto run(const vector<coeff_type, N_Coeff> &coeff,
                    unsigned coeff_start,
                    bool coeff_sign,
                    const vector<data_type, N_Data> &data,
                    unsigned data_start,
                    bool data_sign,
                    const Acc &... acc)
    {
        constexpr auto mac_op = sliding_mul_accfloat_get_mul_op<add_to_op<MulOp>(), coeff_type, data_type>();
        constexpr auto mul_op = sliding_mul_accfloat_get_mul_op<             MulOp, coeff_type, data_type>();


        constexpr unsigned data_elems = std::max(N_Data, lanes_per_mul);

        using accum_fp = decltype(accum_type().template grow_extract<lanes_per_mul>(0));

        accum_type ret;

        utils::unroll_for<unsigned, 0, std::max(1u, Lanes / lanes_per_mul)>([&](auto idx_y) __aie_inline {
            const unsigned data_start_local =  (data_start + idx_y * lanes_per_mul) % data_elems;
            const unsigned coeff_start_local = coeff_start % N_Coeff;

            accum_fp tmp;
            vector<data_type, lanes_per_mul> data_local;
            vector<coeff_type, lanes_per_mul> coeff_local;

            coeff_local = broadcast<coeff_type, lanes_per_mul>::run(coeff[coeff_start_local]);
            data_local  = shuffle_down_rotate<data_type, data_elems>::run(data.template grow_replicate<data_elems>(),
                                                                          data_start_local)
                             .template extract<lanes_per_mul>(0);

            tmp = mul_op(coeff_local, data_local, (acc.template grow_extract<lanes_per_mul>(idx_y))...);

            utils::unroll_for<unsigned, 1, Points / columns_per_mul>([&](auto idx) __aie_inline {
                const unsigned data_start_local =  (data_start + columns_per_mul * idx + idx_y * lanes_per_mul) % data_elems;
                const unsigned coeff_start_local = (coeff_start + columns_per_mul * idx) % N_Coeff;

                coeff_local = broadcast<float, lanes_per_mul>::run(coeff[coeff_start_local]);
                data_local = shuffle_down_rotate<data_type, data_elems>::run(data.template grow_replicate<data_elems>(),
                                                                             data_start_local)
                                 .template extract<lanes_per_mul>(0);

                tmp = mac_op(coeff_local, data_local, tmp);
            });

            if constexpr (Lanes <= lanes_per_mul)
                ret = tmp.template extract<Lanes>(0);
            else
                ret.insert(idx_y, tmp);
        });

        return ret;
    }
};

} // namespace aie::detail

#endif
