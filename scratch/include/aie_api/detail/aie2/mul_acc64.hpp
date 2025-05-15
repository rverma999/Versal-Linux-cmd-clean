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

#ifndef __AIE_API_DETAIL_AIE2_MUL_ACC64__HPP__
#define __AIE_API_DETAIL_AIE2_MUL_ACC64__HPP__

#include <algorithm>

#include "../vector.hpp"
#include "../conj.hpp"
#include "../interleave.hpp"

namespace aie::detail {

// 16b * 8b
template <MulMacroOp MulOp, typename T1, typename T2>
struct mul_bits_impl<MulOp, 64, 16, T1, 8, T2>
{
    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using   accum_tag = accum_tag_for_mul_types<T1, T2, 64>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v1, bool v1_sign, const vector_type2<Elems> &v2, bool v2_sign, const Acc &... acc)
    {
        return mul<MulOp, 64, T1, utils::get_next_integer_type_t<T2>>::run(v1, v1_sign, v2.unpack_sign(v2_sign), v2_sign, acc...);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(T1 a, bool a_sign, const vector_type2<Elems> &v, bool v_sign, const Acc &... acc)
    {
        return mul<MulOp, 64, T1, utils::get_next_integer_type_t<T2>>::run(a, a_sign, v.unpack_sign(v_sign), v_sign, acc...);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v, bool v_sign, T2 a, bool a_sign, const Acc &... acc)
    {
        return mul<MulOp, 64, T1, utils::get_next_integer_type_t<T2>>::run(v, v_sign, a, a_sign, acc...);
    }
};

// 8b * 16b
template <MulMacroOp MulOp, typename T1, typename T2>
struct mul_bits_impl<MulOp, 64, 8, T1, 16, T2>
{
    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using    accum_tag = accum_tag_for_mul_types<T1, T2, 64>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v1,  bool v1_sign, const vector_type2<Elems> &v2, bool v2_sign, const Acc &... acc)
    {
        return mul<MulOp, 64, utils::get_next_integer_type_t<T1>, T2>::run(v1.unpack_sign(v1_sign), v1_sign, v2, v2_sign, acc...);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(T1 a, bool a_sign, const vector_type2<Elems> &v, bool v_sign, const Acc &... acc)
    {
        return mul<MulOp, 64, utils::get_next_integer_type_t<T1>, T2>::run(a, a_sign, v, v_sign, acc...);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type2<Elems> &v, bool v_sign, T1 a, bool a_sign, const Acc &... acc)
    {
        return mul<MulOp, 64, utils::get_next_integer_type_t<T1>, T2>::run(v.unpack_sign(v_sign), v_sign, a, a_sign, acc...);
    }
};

// 16b * 16b
template <MulMacroOp MulOp, typename T1, typename T2>
struct mul_bits_impl<MulOp, 64, 16, T1, 16, T2>
{
    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using   accum_tag = accum_tag_for_mul_types<T1, T2, 64>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    static constexpr unsigned native_num_mul = 16;

    static constexpr unsigned max_t1_elems = 1024 / type_bits_v<T1>;
    static constexpr unsigned max_t2_elems = 1024 / type_bits_v<T2>;

    static constexpr unsigned max_elems     = std::min(max_t1_elems, max_t2_elems);
    static constexpr unsigned default_elems = std::min(native_num_mul, max_elems);

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if constexpr (MulOp == MulMacroOp::Mul)     return [](auto &&... args) __aie_inline { return ::mul_elem_16_2(args...); };
        if constexpr (MulOp == MulMacroOp::NegMul)  return [](auto &&... args) __aie_inline { return ::negmul_elem_16_2(args...); };
        if constexpr (MulOp == MulMacroOp::Add_Mul) return [](auto &&... args) __aie_inline { return ::mac_elem_16_2(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_Mul) return [](auto &&... args) __aie_inline { return ::msc_elem_16_2(args...); };
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v1, bool v1_sign, const vector_type2<Elems> &v2, bool v2_sign, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();
        constexpr unsigned num_mul = Elems < 16? 1 : Elems / 16;

        accum_type<Elems> ret;

        const vector_type1<16> z = zeros<T1, 16>::run();

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const vector_type1<32> v1_zeros = v1.template grow_extract<16>(idx)
                                                .template grow<32>()
                                                .template insert(1, z);
            const accum_type<16> tmp = mul_op( v1_zeros,
                                               v1_sign,
                                               v2.template grow_extract<16>(idx).template grow<32>(),
                                               v2_sign,
                                              acc.template grow_extract<16>(idx)...);
            ret.insert(idx, tmp.template extract<(Elems < 16? Elems : 16)>(0));
        });

        return ret;
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(T1 a, bool a_sign, const vector_type2<Elems> &v, bool v_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(broadcast<T1, elems>::run(a), a_sign, v.template grow<elems>(), v_sign, acc...);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v, bool v_sign, T2 a, bool a_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(v.template grow<elems>(), v_sign, broadcast<T2, elems>::run(a), a_sign, acc...);
    }
};

// 16b * 16b
template <MulMacroOp MulOp, typename T2>
struct mul_bits_impl<MulOp, 64, 32, cint16, 16, T2>
{
    using T1 = cint16;

    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using   accum_tag = accum_tag_for_mul_types<T1, T2, 64>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    static constexpr unsigned native_num_mul = 8;

    static constexpr unsigned max_t1_elems = 1024 / type_bits_v<T1>;
    static constexpr unsigned max_t2_elems = 1024 / type_bits_v<T2>;

    static constexpr unsigned max_elems     = std::min(max_t1_elems, max_t2_elems);
    static constexpr unsigned default_elems = std::min(native_num_mul, max_elems);

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if constexpr (MulOp == MulMacroOp::Mul)               return [](auto &&... args) __aie_inline { return ::mul_elem_8_2(args...); };
        if constexpr (MulOp == MulMacroOp::NegMul)            return [](auto &&... args) __aie_inline { return ::negmul_elem_8_2(args...); };
        if constexpr (MulOp == MulMacroOp::Add_Mul)           return [](auto &&... args) __aie_inline { return ::mac_elem_8_2(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_Mul)           return [](auto &&... args) __aie_inline { return ::msc_elem_8_2(args...); };
#if __AIE_API_MUL_CONJUGATE_INTRINSICS__
        if constexpr (MulOp == MulMacroOp::MulConj1)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_2_cn(args...); };
        if constexpr (MulOp == MulMacroOp::MulConj1Conj2)     return [](auto &&... args) __aie_inline { return ::mul_elem_8_2_cc(args...); };
        if constexpr (MulOp == MulMacroOp::MulConj2)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_2_nc(args...); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_2_cn(args...); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1Conj2)  return [](auto &&... args) __aie_inline { return ::negmul_elem_8_2_cc(args...); };
        if constexpr (MulOp == MulMacroOp::NegMulConj2)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_2_nc(args...); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_2_cn(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::msc_elem_8_2_cc(args...); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj2)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_2_nc(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_2_cn(args...); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::mac_elem_8_2_cc(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj2)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_2_nc(args...); };
#else
        if constexpr (MulOp == MulMacroOp::MulConj1)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_2_conf(args...,       OP_TERM_NEG_COMPLEX_CONJUGATE_X,   0); };
        if constexpr (MulOp == MulMacroOp::MulConj1Conj2)     return [](auto &&... args) __aie_inline { return ::mul_elem_8_2_conf(args...,       OP_TERM_NEG_COMPLEX_CONJUGATE_X_Y, 0); };
        if constexpr (MulOp == MulMacroOp::MulConj2)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_2_conf(args...,       OP_TERM_NEG_COMPLEX_CONJUGATE_Y,   0); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_2_conf(args...,    OP_TERM_NEG_COMPLEX_CONJUGATE_X,   0); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1Conj2)  return [](auto &&... args) __aie_inline { return ::negmul_elem_8_2_conf(args...,    OP_TERM_NEG_COMPLEX_CONJUGATE_X_Y, 0); };
        if constexpr (MulOp == MulMacroOp::NegMulConj2)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_2_conf(args...,    OP_TERM_NEG_COMPLEX_CONJUGATE_Y,   0); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_2_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_X,   0, 0); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::mac_elem_8_2_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_X_Y, 0, 0); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj2)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_2_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_Y,   0, 0); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_2_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_X,   0, 0); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::msc_elem_8_2_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_X_Y, 0, 0); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj2)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_2_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_Y,   0, 0); };
#endif
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v1, bool v1_sign, const vector_type2<Elems> &v2, bool v2_sign, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();
        constexpr unsigned num_mul = Elems < 8? 1 : Elems / 8;

        accum_type<Elems> ret;

        const vector<T1, 8> z = zeros<T1, 8>::run();

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const vector_type1<8> v2_complex = interleave_zip<T2, 16>::run(v2.template extract<8>(idx).template grow<16>(),
                                                                           z.template cast_to<T2>(), 1).first.template cast_to<T1>();
            const vector_type1<16> v2_complex_zeros = v2_complex.template grow<16>()
                                                                .template insert(1, z);
            const accum_type<8> tmp = mul_op( v1.template grow_extract<8>(idx).template grow<16>(),
                                              v2_complex_zeros,
                                             acc.template grow_extract<8>(idx)...);
            ret.insert(idx, tmp.template extract<(Elems < 8? Elems : 8)>(0));
        });

        return ret;
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(T1 a, bool a_sign, const vector_type2<Elems> &v, bool v_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(broadcast<T1, elems>::run(a), a_sign, v.template grow<elems>(), v_sign, acc...).template extract<Elems>(0);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v, bool v_sign, T2 a, bool a_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(v.template grow<elems>(), v_sign, broadcast<T2, elems>::run(a), a_sign, acc...).template extract<Elems>(0);
    }
};

template <MulMacroOp MulOp, typename T1>
struct mul_bits_impl<MulOp, 64, 16, T1, 32, cint16>
{
    using T2 = cint16;

    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using   accum_tag = accum_tag_for_mul_types<T1, T2, 64>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    static constexpr unsigned native_num_mul = 8;

    static constexpr unsigned max_t1_elems = 1024 / type_bits_v<T1>;
    static constexpr unsigned max_t2_elems = 1024 / type_bits_v<T2>;

    static constexpr unsigned max_elems     = std::min(max_t1_elems, max_t2_elems);
    static constexpr unsigned default_elems = std::min(native_num_mul, max_elems);

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if constexpr (MulOp == MulMacroOp::Mul)               return [](auto &&... args) __aie_inline { return ::mul_elem_8_2(args...); };
        if constexpr (MulOp == MulMacroOp::NegMul)            return [](auto &&... args) __aie_inline { return ::negmul_elem_8_2(args...); };
        if constexpr (MulOp == MulMacroOp::Add_Mul)           return [](auto &&... args) __aie_inline { return ::mac_elem_8_2(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_Mul)           return [](auto &&... args) __aie_inline { return ::msc_elem_8_2(args...); };
#if __AIE_API_MUL_CONJUGATE_INTRINSICS__
        if constexpr (MulOp == MulMacroOp::MulConj1)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_2_cn(args...); };
        if constexpr (MulOp == MulMacroOp::MulConj1Conj2)     return [](auto &&... args) __aie_inline { return ::mul_elem_8_2_cc(args...); };
        if constexpr (MulOp == MulMacroOp::MulConj2)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_2_nc(args...); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_2_cn(args...); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1Conj2)  return [](auto &&... args) __aie_inline { return ::negmul_elem_8_2_cc(args...); };
        if constexpr (MulOp == MulMacroOp::NegMulConj2)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_2_nc(args...); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_2_cn(args...); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::mac_elem_8_2_cc(args...); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj2)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_2_nc(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_2_cn(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::msc_elem_8_2_cc(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj2)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_2_nc(args...); };
#else
        if constexpr (MulOp == MulMacroOp::MulConj1)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_2_conf(args...,       OP_TERM_NEG_COMPLEX_CONJUGATE_X,   0); };
        if constexpr (MulOp == MulMacroOp::MulConj1Conj2)     return [](auto &&... args) __aie_inline { return ::mul_elem_8_2_conf(args...,       OP_TERM_NEG_COMPLEX_CONJUGATE_X_Y, 0); };
        if constexpr (MulOp == MulMacroOp::MulConj2)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_2_conf(args...,       OP_TERM_NEG_COMPLEX_CONJUGATE_Y,   0); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_2_conf(args...,    OP_TERM_NEG_COMPLEX_CONJUGATE_X,   0); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1Conj2)  return [](auto &&... args) __aie_inline { return ::negmul_elem_8_2_conf(args...,    OP_TERM_NEG_COMPLEX_CONJUGATE_X_Y, 0); };
        if constexpr (MulOp == MulMacroOp::NegMulConj2)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_2_conf(args...,    OP_TERM_NEG_COMPLEX_CONJUGATE_Y,   0); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_2_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_X,   0, 0); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::mac_elem_8_2_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_X_Y, 0, 0); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj2)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_2_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_Y,   0, 0); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_2_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_X,   0, 0); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::msc_elem_8_2_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_X_Y, 0, 0); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj2)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_2_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_Y,   0, 0); };
#endif
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v1, bool v1_sign, const vector_type2<Elems> &v2, bool v2_sign, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();
        constexpr unsigned num_mul = Elems < 8? 1 : Elems / 8;

        accum_type<Elems> ret;

        const vector<T2, 8> z = zeros<T2, 8>::run();

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const vector_type2<8> v1_complex = interleave_zip<T1, 16>::run(v1.template extract<8>(idx).template grow<16>(),
                                                                           z.template cast_to<T1>(), 1).first.template cast_to<T2>();
            const vector_type2<16> v1_complex_zeros = v1_complex.template grow<16>()
                                                                .template insert(1, z);
            const accum_type<8> tmp = mul_op( v1_complex_zeros,
                                              v2.template grow_extract<8>(idx).template grow<16>(),
                                             acc.template grow_extract<8>(idx)...);
            ret.insert(idx, tmp.template extract<(Elems < 8? Elems : 8)>(0));
        });

        return ret;
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(T1 a, bool a_sign, const vector_type2<Elems> &v, bool v_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(broadcast<T1, elems>::run(a), a_sign, v.template grow<elems>(), v_sign, acc...).template extract<Elems>(0);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v, bool v_sign, T2 a, bool a_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(v.template grow<elems>(), v_sign, broadcast<T2, elems>::run(a), a_sign, acc...).template extract<Elems>(0);
    }
};

template <MulMacroOp MulOp>
struct mul_bits_impl<MulOp, 64, 32, cint16, 32, cint16>
{
    using T1 = cint16;
    using T2 = cint16;

    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using    accum_tag = accum_tag_for_mul_types<T1, T2, 64>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    static constexpr unsigned native_num_mul = 8;

    static constexpr unsigned max_t1_elems = 1024 / type_bits_v<T1>;
    static constexpr unsigned max_t2_elems = 1024 / type_bits_v<T2>;

    static constexpr unsigned max_elems     = std::min(max_t1_elems, max_t2_elems);
    static constexpr unsigned default_elems = std::min(native_num_mul, max_elems);

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if constexpr (MulOp == MulMacroOp::Mul)               return [](auto &&... args) __aie_inline { return ::mul_elem_8_2(args...); };
        if constexpr (MulOp == MulMacroOp::NegMul)            return [](auto &&... args) __aie_inline { return ::negmul_elem_8_2(args...); };
        if constexpr (MulOp == MulMacroOp::Add_Mul)           return [](auto &&... args) __aie_inline { return ::mac_elem_8_2(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_Mul)           return [](auto &&... args) __aie_inline { return ::msc_elem_8_2(args...); };
#if __AIE_API_MUL_CONJUGATE_INTRINSICS__
        if constexpr (MulOp == MulMacroOp::MulConj1)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_2_cn(args...); };
        if constexpr (MulOp == MulMacroOp::MulConj1Conj2)     return [](auto &&... args) __aie_inline { return ::mul_elem_8_2_cc(args...); };
        if constexpr (MulOp == MulMacroOp::MulConj2)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_2_nc(args...); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_2_cn(args...); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1Conj2)  return [](auto &&... args) __aie_inline { return ::negmul_elem_8_2_cc(args...); };
        if constexpr (MulOp == MulMacroOp::NegMulConj2)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_2_nc(args...); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_2_cn(args...); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::mac_elem_8_2_cc(args...); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj2)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_2_nc(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_2_cn(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::msc_elem_8_2_cc(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj2)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_2_nc(args...); };
#else
        if constexpr (MulOp == MulMacroOp::MulConj1)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_2_conf(args...,       OP_TERM_NEG_COMPLEX_CONJUGATE_X,   0); };
        if constexpr (MulOp == MulMacroOp::MulConj1Conj2)     return [](auto &&... args) __aie_inline { return ::mul_elem_8_2_conf(args...,       OP_TERM_NEG_COMPLEX_CONJUGATE_X_Y, 0); };
        if constexpr (MulOp == MulMacroOp::MulConj2)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_2_conf(args...,       OP_TERM_NEG_COMPLEX_CONJUGATE_Y,   0); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_2_conf(args...,    OP_TERM_NEG_COMPLEX_CONJUGATE_X,   0); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1Conj2)  return [](auto &&... args) __aie_inline { return ::negmul_elem_8_2_conf(args...,    OP_TERM_NEG_COMPLEX_CONJUGATE_X_Y, 0); };
        if constexpr (MulOp == MulMacroOp::NegMulConj2)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_2_conf(args...,    OP_TERM_NEG_COMPLEX_CONJUGATE_Y,   0); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_2_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_X,   0, 0); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::mac_elem_8_2_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_X_Y, 0, 0); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj2)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_2_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_Y,   0, 0); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_2_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_X,   0, 0); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::msc_elem_8_2_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_X_Y, 0, 0); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj2)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_2_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_Y,   0, 0); };
#endif
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v1, bool v1_sign, const vector_type2<Elems> &v2, bool v2_sign, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();
        constexpr unsigned num_mul = Elems < 8? 1 : Elems / 8;

        accum_type<Elems> ret;

        const vector<T2, 8> z = zeros<T2, 8>::run();

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const vector_type1<16> v1_zeros = v1.template grow_extract<8>(idx)
                                                .template grow<16>()
                                                .template insert(1, z);
            const accum_type<8> tmp = mul_op( v1_zeros,
                                              v2.template grow_extract<8>(idx).template grow<16>(),
                                             acc.template grow_extract<8>(idx)...);
            ret.insert(idx, tmp.template extract<(Elems < 8? Elems : 8)>(0));
        });

        return ret;
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(T1 a, bool a_sign, const vector_type2<Elems> &v, bool v_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(broadcast<T1, elems>::run(a), a_sign, v.template grow<elems>(), v_sign, acc...).template extract<Elems>(0);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v, bool v_sign, T2 a, bool a_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(v.template grow<elems>(), v_sign, broadcast<T2, elems>::run(a), a_sign, acc...).template extract<Elems>(0);
    }
};

// 32b * 16b
template <MulMacroOp MulOp, typename T1, typename T2>
struct mul_bits_impl<MulOp, 64, 32, T1, 16, T2>
{
    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using   accum_tag = accum_tag_for_mul_types<T1, T2, 64>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    static constexpr unsigned native_num_mul = 16;

    static constexpr unsigned max_t1_elems = 1024 / type_bits_v<T1>;
    static constexpr unsigned max_t2_elems = 1024 / type_bits_v<T2>;

    static constexpr unsigned max_elems     = std::min(max_t1_elems, max_t2_elems);
    static constexpr unsigned default_elems = std::min(native_num_mul, max_elems);

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if constexpr (MulOp == MulMacroOp::Mul)     return [](auto &&... args) __aie_inline { return ::mul_elem_16_2(args...); };
        if constexpr (MulOp == MulMacroOp::NegMul)  return [](auto &&... args) __aie_inline { return ::negmul_elem_16_2(args...); };
        if constexpr (MulOp == MulMacroOp::Add_Mul) return [](auto &&... args) __aie_inline { return ::mac_elem_16_2(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_Mul) return [](auto &&... args) __aie_inline { return ::msc_elem_16_2(args...); };
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v1, bool v1_sign, const vector_type2<Elems> &v2, bool v2_sign, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();
        constexpr unsigned num_mul = Elems < 16? 1 : Elems / 16;

        accum_type<Elems> ret;

        const vector_type1<16> z = zeros<T1, 16>::run();

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const accum_type<16> tmp = mul_op( v1.template grow_extract<16>(idx),
                                               z,
                                               v1_sign,
                                               v2.template grow_extract<16>(idx).template grow<32>(),
                                               v2_sign,
                                              acc.template grow_extract<16>(idx)...);
            ret.insert(idx, tmp.template extract<(Elems < 16? Elems : 16)>(0));
        });

        return ret;
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(T1 a, bool a_sign, const vector_type2<Elems> &v, bool v_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(broadcast<T1, elems>::run(a), a_sign, v.template grow<elems>(), v_sign, acc...).template extract<Elems>(0);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v, bool v_sign, T2 a, bool a_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(v.template grow<elems>(), v_sign, broadcast<T2, elems>::run(a), a_sign, acc...).template extract<Elems>(0);
    }
};

template <MulMacroOp MulOp>
struct mul_bits_impl<MulOp, 64, 32, int32, 32, cint16>
{
    using T1 = int32;
    using T2 = cint16;

    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using   accum_tag = accum_tag_for_mul_types<T1, T2, 64>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    using mul_bits_impl_complex = mul_bits_impl<MulOp, 64, 64, cint32, 32, cint16>;
    using mul_bits_impl_real    = mul_bits_impl<MulOp, 64, 32,  int32, 16,  int16>;

    static constexpr unsigned native_num_mul = has_conj2<MulOp>()? mul_bits_impl_complex::native_num_mul :
                                                                   mul_bits_impl_real::native_num_mul;

    static constexpr unsigned max_t1_elems = 512 / type_bits_v<T1>;
    static constexpr unsigned max_t2_elems = 512 / type_bits_v<T2>;

    static constexpr unsigned max_elems     = std::min(max_t1_elems, max_t2_elems);
    static constexpr unsigned default_elems = std::min(native_num_mul, max_elems);

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v1, bool v1_sign, const vector_type2<Elems> &v2, bool v2_sign, const Acc &... acc)
    {
        accum_type<Elems> res;

        // split v1 to prevent vectors growing larger than 1k
        constexpr unsigned num_muls      = std::max(1u, vector_type1<Elems>::bits() / 512);
        constexpr unsigned elems_per_mul = std::min(Elems, 512 / vector_type1<Elems>::type_bits());

        utils::unroll_times<num_muls>([&](unsigned idx) __aie_inline {
            if constexpr (has_conj2<MulOp>()) {
                auto [tmp1, tmp2] = interleave_zip<T1, elems_per_mul>::run(v1.template extract<elems_per_mul>(idx),
                                                                           zeros<int32, elems_per_mul>::run(),
                                                                           1);

                vector_type2<elems_per_mul> tmp = tmp1.template grow<elems_per_mul * 2>(0)
                                                      .insert(1, tmp2)
                                                      .template cast_to<T2>();

                res.insert(idx, mul_bits_impl_complex::run(tmp,                                     v1_sign,
                                                           v2.template extract<elems_per_mul>(idx), v2_sign,
                                                           acc.template extract<elems_per_mul>(idx)...));

            }
            else {
                auto [tmp1, tmp2] = interleave_zip<T1, elems_per_mul>::run(v1.template extract<elems_per_mul>(idx),
                                                                           v1.template extract<elems_per_mul>(idx),
                                                                           1);

                vector_type1<elems_per_mul * 2> tmp = tmp1.template grow<elems_per_mul * 2>(0)
                                                          .insert(1, tmp2);

                res.insert(idx, mul_bits_impl_real::run(tmp,                                    v1_sign,
                                                        v2.template extract<elems_per_mul>(idx)
                                                          .template cast_to<int16>(),           v2_sign,
                                                        acc.template extract<elems_per_mul>(idx)
                                                           .template cast_to<acc64>()...).template cast_to<cacc64>());
            }
        });

        return res;
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(T1 a, bool a_sign, const vector_type2<Elems> &v, bool v_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(broadcast<T1, elems>::run(a), a_sign, v.template grow<elems>(), v_sign, acc.template grow<elems>()...).template extract<Elems>(0);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v, bool v_sign, T2 a, bool a_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(v.template grow<elems>(), v_sign, broadcast<T2, elems>::run(a), a_sign, acc.template grow<elems>()...).template extract<Elems>(0);
    }
};

template <MulMacroOp MulOp>
struct mul_bits_impl<MulOp, 64, 64, cint32, 32, cint16>
{
    using T1 = cint32;
    using T2 = cint16;

    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using   accum_tag = accum_tag_for_mul_types<T1, T2, 64>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    static constexpr unsigned native_num_mul = 8;

    static constexpr unsigned max_t1_elems = 1024 / type_bits_v<T1>;
    static constexpr unsigned max_t2_elems = 1024 / type_bits_v<T2>;

    static constexpr unsigned max_elems     = std::min(max_t1_elems, max_t2_elems);
    static constexpr unsigned default_elems = std::min(native_num_mul, max_elems);

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if constexpr (MulOp == MulMacroOp::Mul)               return [](auto &&... args) __aie_inline { return ::mul_elem_8(args...); };
        if constexpr (MulOp == MulMacroOp::NegMul)            return [](auto &&... args) __aie_inline { return ::negmul_elem_8(args...); };
        if constexpr (MulOp == MulMacroOp::Add_Mul)           return [](auto &&... args) __aie_inline { return ::mac_elem_8(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_Mul)           return [](auto &&... args) __aie_inline { return ::msc_elem_8(args...); };
#if __AIE_API_MUL_CONJUGATE_INTRINSICS__
        if constexpr (MulOp == MulMacroOp::MulConj1)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_cn(args...); };
        if constexpr (MulOp == MulMacroOp::MulConj1Conj2)     return [](auto &&... args) __aie_inline { return ::mul_elem_8_cc(args...); };
        if constexpr (MulOp == MulMacroOp::MulConj2)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_nc(args...); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_cn(args...); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1Conj2)  return [](auto &&... args) __aie_inline { return ::negmul_elem_8_cc(args...); };
        if constexpr (MulOp == MulMacroOp::NegMulConj2)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_nc(args...); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_cn(args...); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::mac_elem_8_cc(args...); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj2)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_nc(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_cn(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::msc_elem_8_cc(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj2)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_nc(args...); };
#else
        if constexpr (MulOp == MulMacroOp::MulConj1)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_conf(args...,       OP_TERM_NEG_COMPLEX_CONJUGATE_X,   0); };
        if constexpr (MulOp == MulMacroOp::MulConj1Conj2)     return [](auto &&... args) __aie_inline { return ::mul_elem_8_conf(args...,       OP_TERM_NEG_COMPLEX_CONJUGATE_X_Y, 0); };
        if constexpr (MulOp == MulMacroOp::MulConj2)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_conf(args...,       OP_TERM_NEG_COMPLEX_CONJUGATE_Y,   0); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_conf(args...,    OP_TERM_NEG_COMPLEX_CONJUGATE_X,   0); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1Conj2)  return [](auto &&... args) __aie_inline { return ::negmul_elem_8_conf(args...,    OP_TERM_NEG_COMPLEX_CONJUGATE_X_Y, 0); };
        if constexpr (MulOp == MulMacroOp::NegMulConj2)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_conf(args...,    OP_TERM_NEG_COMPLEX_CONJUGATE_Y,   0); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_X,   0, 0); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::mac_elem_8_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_X_Y, 0, 0); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj2)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_Y,   0, 0); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_X,   0, 0); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::msc_elem_8_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_X_Y, 0, 0); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj2)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_Y,   0, 0); };
#endif
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v1, bool v1_sign, const vector_type2<Elems> &v2, bool v2_sign, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();
        constexpr unsigned num_mul = Elems < 8? 1 : Elems / 8;

        accum_type<Elems> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const accum_type<8> tmp = mul_op(v1.template grow_extract<8>(idx),
                                             v2.template grow_extract<8>(idx).template grow<16>(),
                                             acc.template grow_extract<8>(idx)...);
            ret.insert(idx, tmp.template extract<(Elems < 8? Elems : 8)>(0));
        });

        return ret;
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(T1 a, bool a_sign, const vector_type2<Elems> &v, bool v_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(broadcast<T1, elems>::run(a), a_sign, v.template grow<elems>(), v_sign, acc.template grow<elems>()...).template extract<Elems>(0);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v, bool v_sign, T2 a, bool a_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(v.template grow<elems>(), v_sign, broadcast<T2, elems>::run(a), a_sign, acc.template grow<elems>()...).template extract<Elems>(0);
    }
};

template <MulMacroOp MulOp>
struct mul_bits_impl<MulOp, 64, 64, cint32, 16, int16>
{
    using T1 = cint32;
    using T2 = int16;

    using base_impl = mul_bits_impl<MulOp, 64, 64, cint32, 32, cint16>;

    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using accum_tag = accum_tag_for_mul_types<T1, T2, 64>;
    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    static constexpr unsigned native_num_mul = 8;

    static constexpr unsigned max_t1_elems = 1024 / type_bits_v<T1>;
    static constexpr unsigned max_t2_elems = 1024 / type_bits_v<T2>;

    static constexpr unsigned max_elems     = std::min(max_t1_elems, max_t2_elems);
    static constexpr unsigned default_elems = std::min(native_num_mul, max_elems);

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v1, bool v1_sign, const vector_type2<Elems> &v2, bool v2_sign, const Acc &... acc)
    {
        auto [v2_tmp1, v2_tmp2] = interleave_zip<T2, Elems>::run(v2, zeros<T2, Elems>::run(), 1);
        auto v2_tmp = v2_tmp1.template grow<Elems * 2>().template insert(1, v2_tmp2);

        return base_impl::run(v1,                                v1_sign,
                              v2_tmp.template cast_to<cint16>(), v2_sign,
                              acc...);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(T1 a, bool a_sign, const vector_type2<Elems> &v, bool v_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(broadcast<T1, elems>::run(a), a_sign, v.template grow<elems>(), v_sign, acc...).template extract<Elems>(0);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v, bool v_sign, T2 a, bool a_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return base_impl::run(v.template grow<elems>(),                     v_sign,
                               broadcast<cint16, elems>::run(cint16(a, 0)), a_sign,
                               acc...).template extract<Elems>(0);
    }
};

// 16b * 32b
template <MulMacroOp MulOp, typename T1, typename T2> requires(!is_complex_v<T2>)
struct mul_bits_impl<MulOp, 64, 16, T1, 32, T2>
{
    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using    accum_tag = accum_tag_for_mul_types<T1, T2, 64>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    static constexpr unsigned native_num_mul = 16;

    static constexpr unsigned max_t1_elems = 1024 / type_bits_v<T1>;
    static constexpr unsigned max_t2_elems = 1024 / type_bits_v<T2>;

    static constexpr unsigned max_elems     = std::min(max_t1_elems, max_t2_elems);
    static constexpr unsigned default_elems = std::min(native_num_mul, max_elems);

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if constexpr (MulOp == MulMacroOp::Mul)     return [](auto &&... args) __aie_inline { return ::mul_elem_16_2(args...); };
        if constexpr (MulOp == MulMacroOp::NegMul)  return [](auto &&... args) __aie_inline { return ::negmul_elem_16_2(args...); };
        if constexpr (MulOp == MulMacroOp::Add_Mul) return [](auto &&... args) __aie_inline { return ::mac_elem_16_2(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_Mul) return [](auto &&... args) __aie_inline { return ::msc_elem_16_2(args...); };
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v1, bool v1_sign, const vector_type2<Elems> &v2, bool v2_sign, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();
        constexpr unsigned num_mul = Elems < 16? 1 : Elems / 16;

        accum_type<Elems> ret;

        const vector_type2<16> z = zeros<T2, 16>::run();

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const accum_type<16> tmp = mul_op( v2.template grow_extract<16>(idx),
                                               z,
                                               v2_sign,
                                               v1.template grow_extract<16>(idx).template grow<32>(),
                                               v1_sign,
                                              acc.template grow_extract<16>(idx)...);
            ret.insert(idx, tmp.template extract<(Elems < 16? Elems : 16)>(0));
        });

        return ret;
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(T1 a, bool a_sign, const vector_type2<Elems> &v, bool v_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(broadcast<T1, elems>::run(a), a_sign, v.template grow<elems>(), v_sign, acc...).template extract<Elems>(0);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v, bool v_sign, T2 a, bool a_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(v.template grow<elems>(), v_sign, broadcast<T2, elems>::run(a), a_sign, acc...).template extract<Elems>(0);
    }
};

template <MulMacroOp MulOp>
struct mul_bits_impl<MulOp, 64, 32, cint16, 32, int32>
{
    using T1 = cint16;
    using T2 = int32;

    using base_impl = mul_bits_impl<swap_conjugate_order<MulOp>(), 64, 32, int32, 32, cint16>;

    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using    accum_tag = accum_tag_for_mul_types<T1, T2, 64>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v1, bool v1_sign, const vector_type2<Elems> &v2, bool v2_sign, const Acc &... acc)
    {
        return base_impl::run(v2, v2_sign, v1, v1_sign, acc...);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(T1 a, bool a_sign, const vector_type2<Elems> &v, bool v_sign, const Acc &... acc)
    {
        return base_impl::run(v, v_sign, a, a_sign, acc...);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v, bool v_sign, T2 a, bool a_sign, const Acc &... acc)
    {
        return base_impl::run(a, a_sign, v, v_sign, acc...);
    }
};

template <MulMacroOp MulOp>
struct mul_bits_impl<MulOp, 64, 16, int16, 64, cint32>
{
    using T1 = int16;
    using T2 = cint32;

    using base_impl = mul_bits_impl<swap_conjugate_order<MulOp>(), 64, 64, cint32, 16, int16>;

    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using   accum_tag = accum_tag_for_mul_types<T1, T2, 64>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v1, bool v1_sign, const vector_type2<Elems> &v2, bool v2_sign, const Acc &... acc)
    {
        return base_impl::run(v2, v2_sign, v1, v1_sign, acc...);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(T1 a, bool a_sign, const vector_type2<Elems> &v, bool v_sign, const Acc &... acc)
    {
        return base_impl::run(v, v_sign, a, a_sign, acc...);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v, bool v_sign, T2 a, bool a_sign, const Acc &... acc)
    {
        return base_impl::run(a, a_sign, v, v_sign, acc...);
    }
};

template <MulMacroOp MulOp>
struct mul_bits_impl<MulOp, 64, 32, cint16, 64, cint32>
{
    using T1 = cint16;
    using T2 = cint32;

    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using   accum_tag = accum_tag_for_mul_types<T1, T2, 64>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    static constexpr unsigned native_num_mul = 8;

    static constexpr unsigned max_t1_elems = 1024 / type_bits_v<T1>;
    static constexpr unsigned max_t2_elems = 1024 / type_bits_v<T2>;

    static constexpr unsigned max_elems     = std::min(max_t1_elems, max_t2_elems);
    static constexpr unsigned default_elems = std::min(native_num_mul, max_elems);

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        // Note that v1 and v2 are reversed in this type combination
        if constexpr (MulOp == MulMacroOp::Mul)               return [](auto &&... args) __aie_inline { return ::mul_elem_8(args...); };
        if constexpr (MulOp == MulMacroOp::NegMul)            return [](auto &&... args) __aie_inline { return ::negmul_elem_8(args...); };
        if constexpr (MulOp == MulMacroOp::Add_Mul)           return [](auto &&... args) __aie_inline { return ::mac_elem_8(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_Mul)           return [](auto &&... args) __aie_inline { return ::msc_elem_8(args...); };
#if __AIE_API_MUL_CONJUGATE_INTRINSICS__
        if constexpr (MulOp == MulMacroOp::MulConj1)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_nc(args...); };
        if constexpr (MulOp == MulMacroOp::MulConj1Conj2)     return [](auto &&... args) __aie_inline { return ::mul_elem_8_cc(args...); };
        if constexpr (MulOp == MulMacroOp::MulConj2)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_cn(args...); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_nc(args...); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1Conj2)  return [](auto &&... args) __aie_inline { return ::negmul_elem_8_cc(args...); };
        if constexpr (MulOp == MulMacroOp::NegMulConj2)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_cn(args...); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_nc(args...); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::mac_elem_8_cc(args...); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj2)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_cn(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_nc(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::msc_elem_8_cc(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj2)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_cn(args...); };
#else
        if constexpr (MulOp == MulMacroOp::MulConj1)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_conf(args...,       OP_TERM_NEG_COMPLEX_CONJUGATE_X,   0); };
        if constexpr (MulOp == MulMacroOp::MulConj1Conj2)     return [](auto &&... args) __aie_inline { return ::mul_elem_8_conf(args...,       OP_TERM_NEG_COMPLEX_CONJUGATE_X_Y, 0); };
        if constexpr (MulOp == MulMacroOp::MulConj2)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_conf(args...,       OP_TERM_NEG_COMPLEX_CONJUGATE_Y,   0); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_conf(args...,    OP_TERM_NEG_COMPLEX_CONJUGATE_X,   0); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1Conj2)  return [](auto &&... args) __aie_inline { return ::negmul_elem_8_conf(args...,    OP_TERM_NEG_COMPLEX_CONJUGATE_X_Y, 0); };
        if constexpr (MulOp == MulMacroOp::NegMulConj2)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_conf(args...,    OP_TERM_NEG_COMPLEX_CONJUGATE_Y,   0); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_X,   0, 0); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::mac_elem_8_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_X_Y, 0, 0); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj2)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_Y,   0, 0); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_X,   0, 0); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::msc_elem_8_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_X_Y, 0, 0); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj2)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_conf(args..., 0, 0, OP_TERM_NEG_COMPLEX_CONJUGATE_Y,   0, 0); };
#endif
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v1, bool v1_sign, const vector_type2<Elems> &v2, bool v2_sign, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();
        constexpr unsigned num_mul = Elems < 8? 1 : Elems / 8;

        accum_type<Elems> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const accum_type<8> tmp = mul_op(v2.template grow_extract<8>(idx),
                                             v1.template grow_extract<8>(idx).template grow<16>(),
                                             acc.template grow_extract<8>(idx)...);
            ret.insert(idx, tmp.template extract<(Elems < 8? Elems : 8)>(0));
        });

        return ret;
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(T1 a, bool a_sign, const vector_type2<Elems> &v, bool v_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(broadcast<T1, elems>::run(a), a_sign, v.template grow<elems>(), v_sign, acc...).template extract<Elems>(0);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v, bool v_sign, T2 a, bool a_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(v.template grow<elems>(), v_sign, broadcast<T2, elems>::run(a), a_sign, acc...).template extract<Elems>(0);
    }
};

// 32b * 32b
template <MulMacroOp MulOp, typename T1, typename T2>
struct mul_bits_impl<MulOp, 64, 32, T1, 32, T2>
{
    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using   accum_tag = accum_tag_for_mul_types<T1, T2, 64>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    static constexpr unsigned native_num_mul = 16;

    static constexpr unsigned max_t1_elems = 1024 / type_bits_v<T1>;
    static constexpr unsigned max_t2_elems = 1024 / type_bits_v<T2>;

    static constexpr unsigned max_elems     = std::min(max_t1_elems, max_t2_elems);
    static constexpr unsigned default_elems = std::min(native_num_mul, max_elems);

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if constexpr (MulOp == MulMacroOp::Mul)     return [](auto &&... args) __aie_inline { return ::mul_elem_16_2(args...); };
        if constexpr (MulOp == MulMacroOp::NegMul)  return [](auto &&... args) __aie_inline { return ::negmul_elem_16_2(args...); };
        if constexpr (MulOp == MulMacroOp::Add_Mul) return [](auto &&... args) __aie_inline { return ::mac_elem_16_2(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_Mul) return [](auto &&... args) __aie_inline { return ::msc_elem_16_2(args...); };
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v1, bool v1_sign, const vector_type2<Elems> &v2, bool v2_sign, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();
        constexpr unsigned num_mul = Elems < 16? 1 : Elems / 16;

        accum_type<Elems> ret;

        const vector_type1<16> z = zeros<T1, 16>::run();

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const accum_type<16> tmp = mul_op( v1.template grow_extract<16>(idx),
                                               z,
                                               v1_sign,
                                               v2.template grow_extract<16>(idx),
                                               vector<T2, 16>(),
                                               v2_sign,
                                              acc.template grow_extract<16>(idx)...);
            ret.insert(idx, tmp.template extract<(Elems < 16? Elems : 16)>(0));
        });

        return ret;
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(T1 a, bool a_sign, const vector_type2<Elems> &v, bool v_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(broadcast<T1, elems>::run(a), a_sign, v.template grow<elems>(), v_sign, acc...).template extract<Elems>(0);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v, bool v_sign, T2 a, bool a_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(v.template grow<elems>(), v_sign, broadcast<T2, elems>::run(a), a_sign, acc...).template extract<Elems>(0);
    }
};

template <MulMacroOp MulOp>
struct mul_bits_impl<MulOp, 64, 64, cint32, 32, int32>
{
    using T1 = cint32;
    using T2 = int32;

    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using   accum_tag = accum_tag_for_mul_types<T1, T2, 64>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    using mul_bits_impl_complex = mul_bits_impl<MulOp, 64, 64, cint32, 64, cint32>;
    using mul_bits_impl_real    = mul_bits_impl<MulOp, 64, 32, int32, 32, int32>;

    static constexpr unsigned native_num_mul = has_conj1<MulOp>()? mul_bits_impl_complex::native_num_mul :
                                                                   mul_bits_impl_real::native_num_mul;

    static constexpr unsigned max_t1_elems = 1024 / type_bits_v<T1>;
    static constexpr unsigned max_t2_elems = 1024 / type_bits_v<T2>;

    static constexpr unsigned max_elems     = std::min(max_t1_elems, max_t2_elems);
    static constexpr unsigned default_elems = std::min(native_num_mul, max_elems);

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v1, bool v1_sign, const vector_type2<Elems> &v2, bool v2_sign, const Acc &... acc)
    {
        if constexpr (has_conj1<MulOp>()) {
            auto [tmp1, tmp2] = interleave_zip<T2, Elems>::run(v2, zeros<int32, Elems>::run(), 1);

            vector_type1<Elems> tmp = tmp1.template grow<Elems * 2>().insert(1, tmp2).template cast_to<T1>();

            return mul_bits_impl_complex::run(v1, v1_sign, tmp, v2_sign, acc...);

        }
        else {
            auto [tmp1, tmp2] = interleave_zip<T2, Elems>::run(v2, v2, 1);

            vector_type2<Elems * 2> tmp = tmp1.template grow<Elems * 2>().insert(1, tmp2);

            return mul_bits_impl_real::run(v1.template cast_to<int32>(), v1_sign, tmp, v2_sign, acc.template cast_to<acc64>()...).template cast_to<cacc64>();
        }
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(T1 a, bool a_sign, const vector_type2<Elems> &v, bool v_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(broadcast<T1, elems>::run(a), a_sign, v.template grow<elems>(), v_sign, acc...).template extract<Elems>(0);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v, bool v_sign, T2 a, bool a_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(v.template grow<elems>(), v_sign, broadcast<T2, elems>::run(a), a_sign, acc...).template extract<Elems>(0);
    }
};

template <MulMacroOp MulOp>
struct mul_bits_impl<MulOp, 64, 32, int32, 64, cint32>
{
    using T1 = int32;
    using T2 = cint32;

    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using   accum_tag = accum_tag_for_mul_types<T1, T2, 64>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    using mul_bits_impl_complex = mul_bits_impl<MulOp, 64, 64, cint32, 64, cint32>;
    using mul_bits_impl_real    = mul_bits_impl<MulOp, 64, 32, int32, 32, int32>;

    static constexpr unsigned native_num_mul = has_conj2<MulOp>()? mul_bits_impl_complex::native_num_mul :
                                                                   mul_bits_impl_real::native_num_mul;

    static constexpr unsigned max_t1_elems = 1024 / type_bits_v<T1>;
    static constexpr unsigned max_t2_elems = 1024 / type_bits_v<T2>;

    static constexpr unsigned max_elems     = std::min(max_t1_elems, max_t2_elems);
    static constexpr unsigned default_elems = std::min(native_num_mul, max_elems);

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v1, bool v1_sign, const vector_type2<Elems> &v2, bool v2_sign, const Acc &... acc)
    {
        if constexpr (has_conj2<MulOp>()) {
            auto [tmp1, tmp2] = interleave_zip<T1, Elems>::run(v1, zeros<int32, Elems>::run(), 1);

            vector_type2<Elems> tmp = tmp1.template grow<Elems * 2>(0).insert(1, tmp2).template cast_to<T2>();

            return mul_bits_impl_complex::run(tmp, v1_sign, v2, v2_sign, acc...);

        }
        else {
            auto [tmp1, tmp2] = interleave_zip<T1, Elems>::run(v1, v1, 1);

            vector_type1<Elems * 2> tmp = tmp1.template grow<Elems * 2>(0).insert(1, tmp2);

            return mul_bits_impl<MulOp, 64, 32, int32, 32, int32>::run(tmp, v1_sign, v2.template cast_to<int32>(), v2_sign, acc.template cast_to<acc64>()...).template cast_to<cacc64>();
        }
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(T1 a, bool a_sign, const vector_type2<Elems> &v, bool v_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(broadcast<T1, elems>::run(a), a_sign, v.template grow<elems>(), v_sign, acc...).template extract<Elems>(0);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v, bool v_sign, T2 a, bool a_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(v.template grow<elems>(), v_sign, broadcast<T2, elems>::run(a), a_sign, acc...).template extract<Elems>(0);
    }
};

template <MulMacroOp MulOp>
struct mul_bits_impl<MulOp, 64, 64, cint32, 64, cint32>
{
    using T1 = cint32;
    using T2 = cint32;

    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using   accum_tag = accum_tag_for_mul_types<T1, T2, 64>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    static constexpr unsigned native_num_mul = 8;

    static constexpr unsigned max_t1_elems = 1024 / type_bits_v<T1>;
    static constexpr unsigned max_t2_elems = 1024 / type_bits_v<T2>;

    static constexpr unsigned max_elems     = std::min(max_t1_elems, max_t2_elems);
    static constexpr unsigned default_elems = std::min(native_num_mul, max_elems);

    static constexpr auto get_mul_op()
    {
        if constexpr (MulOp == MulMacroOp::Mul)               return [](auto &&... args) __aie_inline { return ::mul_elem_8(args...); };
        if constexpr (MulOp == MulMacroOp::NegMul)            return [](auto &&... args) __aie_inline { return ::negmul_elem_8(args...); };
        if constexpr (MulOp == MulMacroOp::Add_Mul)           return [](auto &&... args) __aie_inline { return ::mac_elem_8(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_Mul)           return [](auto &&... args) __aie_inline { return ::msc_elem_8(args...); };
        if constexpr (MulOp == MulMacroOp::MulConj1)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_cn(args...); };
        if constexpr (MulOp == MulMacroOp::MulConj1Conj2)     return [](auto &&... args) __aie_inline { return ::mul_elem_8_cc(args...); };
        if constexpr (MulOp == MulMacroOp::MulConj2)          return [](auto &&... args) __aie_inline { return ::mul_elem_8_nc(args...); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_cn(args...); };
        if constexpr (MulOp == MulMacroOp::NegMulConj1Conj2)  return [](auto &&... args) __aie_inline { return ::negmul_elem_8_cc(args...); };
        if constexpr (MulOp == MulMacroOp::NegMulConj2)       return [](auto &&... args) __aie_inline { return ::negmul_elem_8_nc(args...); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_cn(args...); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::mac_elem_8_cc(args...); };
        if constexpr (MulOp == MulMacroOp::Add_MulConj2)      return [](auto &&... args) __aie_inline { return ::mac_elem_8_nc(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_cn(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj1Conj2) return [](auto &&... args) __aie_inline { return ::msc_elem_8_cc(args...); };
        if constexpr (MulOp == MulMacroOp::Sub_MulConj2)      return [](auto &&... args) __aie_inline { return ::msc_elem_8_nc(args...); };
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v1, bool v1_sign, const vector_type2<Elems> &v2, bool v2_sign, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op();
        constexpr unsigned num_mul = Elems < 8? 1 : Elems / 8;

        accum_type<Elems> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const accum_type<8> tmp = mul_op( v1.template grow_extract<8>(idx),
                                              v2.template grow_extract<8>(idx),
                                             acc.template grow_extract<8>(idx)...);
            ret.insert(idx, tmp.template extract<(Elems < 8? Elems : 8)>(0));
        });

        return ret;
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(T1 a, bool a_sign, const vector_type2<Elems> &v, bool v_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(broadcast<T1, elems>::run(a), a_sign, v.template grow<elems>(), v_sign, acc...).template extract<Elems>(0);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v, bool v_sign, T2 a, bool a_sign, const Acc &... acc)
    {
        constexpr unsigned elems = std::max(Elems, default_elems);
        return run(v.template grow<elems>(), v_sign, broadcast<T2, elems>::run(a), a_sign, acc...).template extract<Elems>(0);
    }
};

}

#endif
