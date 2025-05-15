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

#ifndef __AIE_API_DETAIL_AIE2_MUL_ACC32_FP__HPP__
#define __AIE_API_DETAIL_AIE2_MUL_ACC32_FP__HPP__

namespace aie::detail {

template <MulMacroOp MulOp>
struct mul_bits_impl<MulOp, 32, 16, bfloat16, 16, bfloat16>
{
    using T = bfloat16;

    template <unsigned Elems>
    using vector_type = vector<bfloat16, Elems>;
    template <unsigned Elems>
    using  accum_type = accum<accfloat, Elems>;

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if      constexpr (MulOp == MulMacroOp::Mul)     return [](auto &&... args) __aie_inline { return ::mul_elem_16_2(args...); };
        else if constexpr (MulOp == MulMacroOp::NegMul)  return [](auto &&... args) __aie_inline { return ::negmul_elem_16_2(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_Mul) return [](auto &&... args) __aie_inline { return ::mac_elem_16_2(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_Mul) return [](auto &&... args) __aie_inline { return ::msc_elem_16_2(args...); };
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static accum_type<Elems> run(const vector_type<Elems> &v1, bool v1_sign, const vector_type<Elems> &v2, bool v2_sign, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();

        constexpr unsigned num_mul = Elems < 16? 1 : Elems / 16;

        accum_type<Elems> ret;

        const vector_type<16> z = zeros<bfloat16, 16>::run();

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const vector_type<32> v1_ = v1.template grow_extract<16>(idx)
                                          .template grow<32>()
                                          .template insert(1, z);
            const vector_type<32> v2_ = v2.template grow_extract<16>(idx)
                                          .template grow<32>()
                                          .template insert(1, z);
            const accum_type<16> tmp = mul_op(v1_, v2_, acc.template grow_extract<16>(idx)...);
            ret.insert(idx, tmp.template extract<std::min(Elems, 16u)>(0));
        });

        return ret;
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static accum_type<Elems> run(T a, bool a_sign, const vector_type<Elems> &v, bool v_sign, const Acc &... acc)
    {
        return run(broadcast<T, Elems>::run(a), a_sign, v, v_sign, acc...);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static accum_type<Elems> run(const vector_type<Elems> &v, bool v_sign, T a, bool a_sign, const Acc &... acc)
    {
        return run(v, v_sign, broadcast<T, Elems>::run(a), a_sign, acc...);
    }
};

template <MulMacroOp MulOp>
struct mul_bits_impl<MulOp, 32, 32, float, 32, float>
{
    using T = float;

    template <unsigned Elems>
    using vector_type = vector<float, Elems>;
    template <unsigned Elems>
    using  accum_type = accum<accfloat, Elems>;

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if      constexpr (MulOp == MulMacroOp::Mul)     return [](auto &&... args) __aie_inline { return ::mul_elem_16(args...); };
        else if constexpr (MulOp == MulMacroOp::NegMul)  return [](auto &&... args) __aie_inline { return ::negmul_elem_16(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_Mul) return [](auto &&... args) __aie_inline { return ::mac_elem_16(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_Mul) return [](auto &&... args) __aie_inline { return ::msc_elem_16(args...); };
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static accum_type<Elems> run(const vector_type<Elems> &v1, const bool v1_sign, const vector_type<Elems> &v2, const bool v2_sign, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();

        constexpr unsigned num_mul = Elems < 16? 1 : Elems / 16;

        accum_type<Elems> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const accum_type<16> tmp = mul_op(v1.template grow_extract<16>(idx),
                                              v2.template grow_extract<16>(idx),
                                              acc.template grow_extract<16>(idx)...);
            ret.insert(idx, tmp.template extract<std::min(Elems, 16u)>(0));
        });

        return ret;
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static accum_type<Elems> run(T a, const bool a_sign, const vector_type<Elems> &v, const bool v_sign, const Acc &... acc)
    {
        return run(broadcast<T, Elems>::run(a), a_sign, v, v_sign, acc...);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static accum_type<Elems> run(const vector_type<Elems> &v, const bool v_sign, T a, const bool a_sign, const Acc &... acc)
    {
        return run(v, v_sign, broadcast<T, Elems>::run(a), a_sign, acc...);
    }
};

#if __AIE_API_COMPLEX_FP32_EMULATION__

template <MulMacroOp MulOp>
struct mul_bits_impl<MulOp, 32, 64, cfloat, 64, cfloat>
{
    using T = cfloat;

    template <unsigned Elems>
    using vector_type = vector<cfloat, Elems>;
    template <unsigned Elems>
    using  accum_type = accum<caccfloat, Elems>;

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if      constexpr (MulOp == MulMacroOp::Mul)     return [](auto &&... args) __aie_inline { return ::mul_elem_8(args...); };
        else if constexpr (MulOp == MulMacroOp::NegMul)  return [](auto &&... args) __aie_inline { return ::negmul_elem_8(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_Mul) return [](auto &&... args) __aie_inline { return ::mac_elem_8(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_Mul) return [](auto &&... args) __aie_inline { return ::msc_elem_8(args...); };
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static accum_type<Elems> run(const vector_type<Elems> &v1, const bool v1_sign, const vector_type<Elems> &v2, const bool v2_sign, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();

        constexpr unsigned num_mul = Elems < 8? 1 : Elems / 8;

        accum_type<Elems> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const accum_type<8> tmp = mul_op( v1.template grow_extract<8>(idx),
                                              v2.template grow_extract<8>(idx),
                                             acc.template grow_extract<8>(idx)...);
            ret.insert(idx, tmp.template extract<std::min(Elems, 8u)>(0));
        });

        return ret;
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static accum_type<Elems> run(T a, const bool a_sign, const vector_type<Elems> &v, const bool v_sign, const Acc &... acc)
    {
        return run(broadcast<T, Elems>::run(a), a_sign, v, v_sign, acc...);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static accum_type<Elems> run(const vector_type<Elems> &v, const bool v_sign, T a, const bool a_sign, const Acc &... acc)
    {
        return run(v, v_sign, broadcast<T, Elems>::run(a), a_sign, acc...);
    }
};

template <MulMacroOp MulOp>
struct mul_bits_impl<MulOp, 32, 64, cfloat, 32, float>
{
    using T1 = cfloat;
    using T2 = float;

    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;
    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;
    template <unsigned Elems>
    using  accum_type = accum<caccfloat, Elems>;

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if      constexpr (MulOp == MulMacroOp::Mul)     return [](auto &&... args) __aie_inline { return ::mul_elem_8(args...); };
        else if constexpr (MulOp == MulMacroOp::NegMul)  return [](auto &&... args) __aie_inline { return ::negmul_elem_8(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_Mul) return [](auto &&... args) __aie_inline { return ::mac_elem_8(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_Mul) return [](auto &&... args) __aie_inline { return ::msc_elem_8(args...); };
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static accum_type<Elems> run(const vector_type1<Elems> &v1, const bool v1_sign, const vector_type2<Elems> &v2, const bool v2_sign, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();

        constexpr unsigned num_mul = Elems < 8? 1 : Elems / 8;

        accum_type<Elems> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const accum_type<8> tmp = mul_op( v1.template grow_extract<8>(idx),
                                              v2.template grow_extract<8>(idx),
                                             acc.template grow_extract<8>(idx)...);
            ret.insert(idx, tmp.template extract<std::min(Elems, 8u)>(0));
        });

        return ret;
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static accum_type<Elems> run(T1 a, const bool a_sign, const vector_type2<Elems> &v, const bool v_sign, const Acc &... acc)
    {
        return run(broadcast<T1, Elems>::run(a), a_sign, v, v_sign, acc...);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static accum_type<Elems> run(const vector_type1<Elems> &v, const bool v_sign, T2 a, const bool a_sign, const Acc &... acc)
    {
        return run(v, v_sign, broadcast<T2, Elems>::run(a), a_sign, acc...);
    }
};

template <MulMacroOp MulOp>
struct mul_bits_impl<MulOp, 32, 32, float, 64, cfloat>
{
    using T1 = float;
    using T2 = cfloat;

    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;
    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;
    template <unsigned Elems>
    using  accum_type = accum<caccfloat, Elems>;

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if      constexpr (MulOp == MulMacroOp::Mul)     return [](auto &&... args) __aie_inline { return ::mul_elem_8(args...); };
        else if constexpr (MulOp == MulMacroOp::NegMul)  return [](auto &&... args) __aie_inline { return ::negmul_elem_8(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_Mul) return [](auto &&... args) __aie_inline { return ::mac_elem_8(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_Mul) return [](auto &&... args) __aie_inline { return ::msc_elem_8(args...); };
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static accum_type<Elems> run(const vector_type1<Elems> &v1, const bool v1_sign, const vector_type2<Elems> &v2, const bool v2_sign, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();

        constexpr unsigned num_mul = Elems < 8? 1 : Elems / 8;

        accum_type<Elems> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const accum_type<8> tmp = mul_op( v1.template grow_extract<8>(idx),
                                              v2.template grow_extract<8>(idx),
                                             acc.template grow_extract<8>(idx)...);
            ret.insert(idx, tmp.template extract<std::min(Elems, 8u)>(0));
        });

        return ret;
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static accum_type<Elems> run(T1 a, const bool a_sign, const vector_type2<Elems> &v, const bool v_sign, const Acc &... acc)
    {
        return run(broadcast<T1, Elems>::run(a), a_sign, v, v_sign, acc...);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static accum_type<Elems> run(const vector_type1<Elems> &v, const bool v_sign, T2 a, const bool a_sign, const Acc &... acc)
    {
        return run(v, v_sign, broadcast<T2, Elems>::run(a), a_sign, acc...);
    }
};

#endif

}
#endif
