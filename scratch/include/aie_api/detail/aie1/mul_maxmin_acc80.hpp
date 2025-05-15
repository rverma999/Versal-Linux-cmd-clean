// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
/*  (c) Copyright 2020 - 2022 Xilinx, Inc. All rights reserved.

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

#ifndef __AIE_API_DETAIL_AIE1_MUL_MAXMIN_ACC80__HPP__
#define __AIE_API_DETAIL_AIE1_MUL_MAXMIN_ACC80__HPP__

#include <algorithm>

#include "../accum.hpp"
#include "../vector.hpp"

namespace aie::detail {

template <MulMacroOp MulOp>
struct mul_maxmin_bits_impl<MulOp, 80, 32, int32, 16, int16>
{
    using T1 = int32;
    using T2 = int16;

    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using accum_tag = accum_tag_for_mul_types<T1, T2, 80>;

    template <unsigned Elems>
    using accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if      constexpr (MulOp == MulMacroOp::MulMax)     return [](auto &&... args) __aie_inline { return ::lmul8_max(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_MulMax) return [](auto &&... args) __aie_inline { return ::lmac8_max(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_MulMax) return [](auto &&... args) __aie_inline { return ::lmsc8_max(args...); };
        else if constexpr (MulOp == MulMacroOp::MulMin)     return [](auto &&... args) __aie_inline { return ::lmul8_min(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_MulMin) return [](auto &&... args) __aie_inline { return ::lmac8_min(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_MulMin) return [](auto &&... args) __aie_inline { return ::lmsc8_min(args...); };
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &m1,
                                 const vector_type1<Elems> &m2,
                                 const vector_type2<Elems> &v, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();

        accum_type<Elems> ret;

        utils::unroll_times<Elems / 8>([&](auto idx) __aie_inline {
            ret.template insert<8>(idx, mul_op(acc.template grow_extract<16>(idx)...,
                                               m1.template grow_extract<16>(idx / 2), 8 * (idx % 2), 0x76543210,
                                               m2.template grow_extract<16>(idx / 2), 8 * (idx % 2),
                                               v.template grow_extract<16>(idx / 2),  8 * (idx % 2), 0x76543210));
        });

        return ret;
    }
};

template <MulMacroOp MulOp>
struct mul_maxmin_bits_impl<MulOp, 80, 16, int16, 32, int32>
{
    using T1 = int16;
    using T2 = int32;

    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using accum_tag = accum_tag_for_mul_types<T1, T2, 80>;

    template <unsigned Elems>
    using accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if      constexpr (MulOp == MulMacroOp::MulMax)     return [](auto &&... args) __aie_inline { return ::lmul8_max(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_MulMax) return [](auto &&... args) __aie_inline { return ::lmac8_max(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_MulMax) return [](auto &&... args) __aie_inline { return ::lmsc8_max(args...); };
        else if constexpr (MulOp == MulMacroOp::MulMin)     return [](auto &&... args) __aie_inline { return ::lmul8_min(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_MulMin) return [](auto &&... args) __aie_inline { return ::lmac8_min(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_MulMin) return [](auto &&... args) __aie_inline { return ::lmsc8_min(args...); };
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &m1,
                                 const vector_type1<Elems> &m2,
                                 const vector_type2<Elems> &v, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();

        accum_type<Elems> ret;

        utils::unroll_times<Elems / 8>([&](auto idx) __aie_inline {
            ret.template insert<8>(idx, mul_op(acc.template grow_extract<16>(idx)...,
                                               m1.template grow_extract<32>(idx / 4), 8 * (idx % 4), 0x76543210,
                                               m2.template grow_extract<32>(idx / 4), 8 * (idx % 4),
                                               v.template grow_extract<8>(idx),                   0, 0x76543210));
        });

        return ret;
    }
};

template <MulMacroOp MulOp>
struct mul_maxmin_bits_impl<MulOp, 80, 32, int32, 32, int32>
{
    using T1 = int32;
    using T2 = int32;

    template <unsigned Elems>
    using vector_type = vector<T1, Elems>;

    using accum_tag = accum_tag_for_mul_types<T1, T2, 80>;

    template <unsigned Elems>
    using accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if      constexpr (MulOp == MulMacroOp::MulMax)     return [](auto &&... args) __aie_inline { return ::lmul8_max(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_MulMax) return [](auto &&... args) __aie_inline { return ::lmac8_max(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_MulMax) return [](auto &&... args) __aie_inline { return ::lmsc8_max(args...); };
        else if constexpr (MulOp == MulMacroOp::MulMin)     return [](auto &&... args) __aie_inline { return ::lmul8_min(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_MulMin) return [](auto &&... args) __aie_inline { return ::lmac8_min(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_MulMin) return [](auto &&... args) __aie_inline { return ::lmsc8_min(args...); };
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type<Elems> &m1,
                                 const vector_type<Elems> &m2,
                                 const vector_type<Elems> &v, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();
        constexpr unsigned num_mul = Elems < 8? 1 : Elems / 8;

        accum_type<Elems> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const accum_type<8> tmp = mul_op(acc.template grow_extract<8>(idx)...,
                                             m1.template grow_extract<16>(idx / 2), 8 * (idx % 2), 0x76543210,
                                             m2.template grow_extract<16>(idx / 2), 8 * (idx % 2),
                                             v.template grow_extract<8>(idx),                   0, 0x76543210);
            ret.insert(idx, tmp.template extract<(Elems < 8? Elems : 8)>(0));
        });

        return ret;
    }
};

}

#endif
