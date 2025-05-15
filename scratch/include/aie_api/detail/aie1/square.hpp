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

#ifndef __AIE_API_DETAIL_AIE1_SQUARE__HPP__
#define __AIE_API_DETAIL_AIE1_SQUARE__HPP__

#include <algorithm>

#include "../accum.hpp"
#include "../vector.hpp"

namespace aie::detail {

template <MulMacroOp MulOp, typename T>
struct square_bits_impl<MulOp, 48, 8, T>
{
    template <unsigned Elems>
    using vector_type = vector<T, Elems>;

    using   accum_tag = accum_tag_for_type<T, 48>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type<Elems> &v, const Acc &... acc)
    {
        if constexpr (Elems == 128) {
            accum_type<64> tmp1, tmp2;

            tmp1 = square<MulOp, 48, int16>::run(  v.template extract<64>(0).unpack(),
                                                 acc.template extract<64>(0)...);
            tmp2 = square<MulOp, 48, int16>::run(  v.template extract<64>(1).unpack(),
                                                 acc.template extract<64>(1)...);

            return concat_accum(tmp1, tmp2);
        }
        else {
            return square<MulOp, 48, int16>::run(v.unpack(), acc...);
        }
    }
};

template <MulMacroOp MulOp>
struct square_bits_impl<MulOp, 48, 16, int16>
{
    using T = int16;
    template <unsigned Elems>
    using vector_type = vector<T, Elems>;

    using   accum_tag = accum_tag_for_type<T, 48>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if constexpr (Elems == 8) {
            if constexpr (MulOp == MulMacroOp::Mul)
                return [](auto &&... args) __aie_inline { return ::ext_lo(::mul16(args...)); };
            else if constexpr (MulOp == MulMacroOp::Add_Mul)
                return [](auto &&... args) __aie_inline { return ::ext_lo(::mac16(args...)); };
            else if constexpr (MulOp == MulMacroOp::Sub_Mul)
                return [](auto &&... args) __aie_inline { return ::ext_lo(::msc16(args...)); };
        }
        else {
            if constexpr (MulOp == MulMacroOp::Mul)
                return [](auto &&... args) __aie_inline { return ::mul16(args...); };
            else if constexpr (MulOp == MulMacroOp::Add_Mul)
                return [](auto &&... args) __aie_inline { return ::mac16(args...); };
            else if constexpr (MulOp == MulMacroOp::Sub_Mul)
                return [](auto &&... args) __aie_inline { return ::msc16(args...); };
        }
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type<Elems> &v, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();

        if constexpr (Elems <= 16) {
            return mul_op(acc.template grow<16>()...,
                          ::concat(v.template grow<16>(), *(const v16int16 *)ZERO), 0, 0x73727170, 0x77767574, 0x3120,
                                                                                    0, 0x73727170, 0x77767574, 0x3120);
        }
        else if constexpr (Elems == 32) {
            return concat_accum(square<MulOp, 48, T>::run(v.template extract<16>(0), acc.template extract<16>(0)...),
                                square<MulOp, 48, T>::run(v.template extract<16>(1), acc.template extract<16>(1)...));
        }
        else if constexpr (Elems == 64) {
            return concat_accum(square<MulOp, 48, T>::run(v.template extract<16>(0), acc.template extract<16>(0)...),
                                square<MulOp, 48, T>::run(v.template extract<16>(1), acc.template extract<16>(1)...),
                                square<MulOp, 48, T>::run(v.template extract<16>(2), acc.template extract<16>(2)...),
                                square<MulOp, 48, T>::run(v.template extract<16>(3), acc.template extract<16>(3)...));
        }
    }
};

template <MulMacroOp MulOp>
struct square_bits_impl<MulOp, 48, 32, cint16>
{
    using T = cint16;
    template <unsigned Elems>
    using vector_type = vector<T, Elems>;

    using   accum_tag = accum_tag_for_type<T, 48>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if constexpr (Elems == 4) {
            if constexpr (MulOp == MulMacroOp::Mul)
                return [](auto &&... args) __aie_inline { return ::ext_lo(::mul8(args...)); };
            else if constexpr (MulOp == MulMacroOp::Add_Mul)
                return [](auto &&... args) __aie_inline { return ::ext_lo(::mac8(args...)); };
            else if constexpr (MulOp == MulMacroOp::Sub_Mul)
                return [](auto &&... args) __aie_inline { return ::ext_lo(::msc8(args...)); };
        }
        else {
            if constexpr (MulOp == MulMacroOp::Mul)
                return [](auto &&... args) __aie_inline { return ::mul8(args...); };
            else if constexpr (MulOp == MulMacroOp::Add_Mul)
                return [](auto &&... args) __aie_inline { return ::mac8(args...); };
            else if constexpr (MulOp == MulMacroOp::Sub_Mul)
                return [](auto &&... args) __aie_inline { return ::msc8(args...); };
        }
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type<Elems> &v, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();

        if constexpr (Elems <= 8) {
            return mul_op(acc.template grow<8>()..., v.template grow<16>(), 0, 0x76543210, 0, 0x76543210);
        }
        else if constexpr (Elems == 16) {
            return concat_accum(square<MulOp, 48, T>::run(v.template extract<8>(0), acc.template extract<8>(0)...),
                                square<MulOp, 48, T>::run(v.template extract<8>(1), acc.template extract<8>(1)...));
        }
        else if constexpr (Elems == 32) {
            return concat_accum(square<MulOp, 48, T>::run(v.template extract<8>(0), acc.template extract<8>(0)...),
                                square<MulOp, 48, T>::run(v.template extract<8>(1), acc.template extract<8>(1)...),
                                square<MulOp, 48, T>::run(v.template extract<8>(2), acc.template extract<8>(2)...),
                                square<MulOp, 48, T>::run(v.template extract<8>(3), acc.template extract<8>(3)...));
        }
    }
};

template <MulMacroOp MulOp>
struct square_bits_impl<MulOp, 80, 32, int32>
{
    using T = int32;
    template <unsigned Elems>
    using vector_type = vector<T, Elems>;

    using   accum_tag = accum_tag_for_type<T, 80>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if constexpr (Elems == 4) {
            if constexpr (MulOp == MulMacroOp::Mul)
                return [](auto &&... args) __aie_inline { return ::ext_lo(::lmul8(args...)); };
            else if constexpr (MulOp == MulMacroOp::Add_Mul)
                return [](auto &&... args) __aie_inline { return ::ext_lo(::lmac8(args...)); };
            else if constexpr (MulOp == MulMacroOp::Sub_Mul)
                return [](auto &&... args) __aie_inline { return ::ext_lo(::lmsc8(args...)); };
        }
        else {
            if constexpr (MulOp == MulMacroOp::Mul)
                return [](auto &&... args) __aie_inline { return ::lmul8(args...); };
            else if constexpr (MulOp == MulMacroOp::Add_Mul)
                return [](auto &&... args) __aie_inline { return ::lmac8(args...); };
            else if constexpr (MulOp == MulMacroOp::Sub_Mul)
                return [](auto &&... args) __aie_inline { return ::lmsc8(args...); };
        }
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type<Elems> &v, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();

        if constexpr (Elems <= 8) {
            return mul_op(acc.template grow<8>()..., v.template grow<16>(), 0, 0x76543210, 0, 0x76543210);
        }
        else if constexpr (Elems == 16) {
            const accum_type<Elems / 2> acc1 = mul_op(acc.template extract<8>(0)..., v, 0, 0x76543210, 0, 0x76543210);
            const accum_type<Elems / 2> acc2 = mul_op(acc.template extract<8>(1)..., v, 8, 0x76543210, 8, 0x76543210);

            return concat_accum(acc1, acc2);
        }
        else if constexpr (Elems == 32) {
            const accum_type<Elems / 4> acc1 = mul_op(acc.template extract<8>(0)..., v.template extract<16>(0), 0, 0x76543210, 0, 0x76543210);
            const accum_type<Elems / 4> acc2 = mul_op(acc.template extract<8>(1)..., v.template extract<16>(0), 8, 0x76543210, 8, 0x76543210);
            const accum_type<Elems / 4> acc3 = mul_op(acc.template extract<8>(2)..., v.template extract<16>(1), 0, 0x76543210, 0, 0x76543210);
            const accum_type<Elems / 4> acc4 = mul_op(acc.template extract<8>(3)..., v.template extract<16>(1), 8, 0x76543210, 8, 0x76543210);

            return concat_accum(acc1, acc2, acc3, acc4);
        }
    }
};

template <MulMacroOp MulOp>
struct square_bits_impl<MulOp, 32, 32, float>
{
    using T = float;
    template <unsigned Elems>
    using vector_type = vector<T, Elems>;

    using accum_tag   = accum_tag_for_type<T, 32>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if constexpr (Elems == 4) {
            if constexpr (MulOp == MulMacroOp::Mul)
                return [](auto &&... args) __aie_inline { return ::ext_v(::fpmul(args...), 0); };
            else if constexpr (MulOp == MulMacroOp::Add_Mul)
                return [](auto &&... args) __aie_inline { return ::ext_v(::fpmac(args...), 0); };
            else if constexpr (MulOp == MulMacroOp::Sub_Mul)
                return [](auto &&... args) __aie_inline { return ::ext_v(::fpmsc(args...), 0); };
        }
        else {
            if constexpr (MulOp == MulMacroOp::Mul)
                return [](auto &&... args) __aie_inline { return ::fpmul(args...); };
            else if constexpr (MulOp == MulMacroOp::Add_Mul)
                return [](auto &&... args) __aie_inline { return ::fpmac(args...); };
            else if constexpr (MulOp == MulMacroOp::Sub_Mul)
                return [](auto &&... args) __aie_inline { return ::fpmsc(args...); };
        }
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type<Elems> &v, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();

        if constexpr (Elems <= 8) {
            return mul_op(acc.template grow<8>()..., v.template grow<16>(), 0, 0x76543210, 0, 0x76543210);
        }
        else if constexpr (Elems == 16) {
            const accum_type<Elems / 2> acc1 = mul_op(acc.template extract<8>(0)..., v, 0, 0x76543210, 0, 0x76543210);
            const accum_type<Elems / 2> acc2 = mul_op(acc.template extract<8>(1)..., v, 8, 0x76543210, 8, 0x76543210);

            return concat_accum(acc1, acc2);
        }
        else if constexpr (Elems == 32) {
            const accum_type<Elems / 4> acc1 = mul_op(acc.template extract<8>(0)..., v.template extract<16>(0), 0, 0x76543210, 0, 0x76543210);
            const accum_type<Elems / 4> acc2 = mul_op(acc.template extract<8>(1)..., v.template extract<16>(0), 8, 0x76543210, 8, 0x76543210);
            const accum_type<Elems / 4> acc3 = mul_op(acc.template extract<8>(2)..., v.template extract<16>(1), 0, 0x76543210, 0, 0x76543210);
            const accum_type<Elems / 4> acc4 = mul_op(acc.template extract<8>(3)..., v.template extract<16>(1), 8, 0x76543210, 8, 0x76543210);

            return concat_accum(acc1, acc2, acc3, acc4);
        }
    }
};

template <MulMacroOp MulOp>
struct square_bits_impl<MulOp, 80, 64, cint32>
{
    using T = cint32;
    template <unsigned Elems>
    using vector_type = vector<T, Elems>;

    using   accum_tag = accum_tag_for_type<T, 80>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if constexpr (MulOp == MulMacroOp::Mul)
            return [](auto &&... args) __aie_inline { return ::lmul2(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_Mul)
            return [](auto &&... args) __aie_inline { return ::lmac2(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_Mul)
            return [](auto &&... args) __aie_inline { return ::lmsc2(args...); };
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type<Elems> &v, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();

        if constexpr (Elems == 2) {
            return mul_op(acc..., v.template grow<8>(), 0, 0x10, 0, 0x10);
        }
        else if constexpr (Elems == 4) {
            const accum_type<Elems> ret = concat(mul_op(acc.template extract<2>(0)..., v.template grow<8>(), 0, 0x10, 0, 0x10),
                                                 mul_op(acc.template extract<2>(1)..., v.template grow<8>(), 2, 0x10, 2, 0x10));

            return ret;
        }
        else if constexpr (Elems == 8) {
            const accum_type<Elems / 2> acc1 = concat(mul_op(acc.template extract<2>(0)..., v, 0, 0x10, 0, 0x10),
                                                      mul_op(acc.template extract<2>(1)..., v, 2, 0x10, 2, 0x10));
            const accum_type<Elems / 2> acc2 = concat(mul_op(acc.template extract<2>(2)..., v, 4, 0x10, 4, 0x10),
                                                      mul_op(acc.template extract<2>(3)..., v, 6, 0x10, 6, 0x10));

            return concat_accum(acc1, acc2);
        }
        else if constexpr (Elems == 16) {
            const accum_type<Elems / 4> acc1 = ::concat(mul_op(acc.template extract<2>(0)..., v.template extract<8>(0), 0, 0x10, 0, 0x10),
                                                        mul_op(acc.template extract<2>(1)..., v.template extract<8>(0), 2, 0x10, 2, 0x10));
            const accum_type<Elems / 4> acc2 = ::concat(mul_op(acc.template extract<2>(2)..., v.template extract<8>(0), 4, 0x10, 4, 0x10),
                                                        mul_op(acc.template extract<2>(3)..., v.template extract<8>(0), 6, 0x10, 6, 0x10));
            const accum_type<Elems / 4> acc3 = ::concat(mul_op(acc.template extract<2>(4)..., v.template extract<8>(1), 0, 0x10, 0, 0x10),
                                                        mul_op(acc.template extract<2>(5)..., v.template extract<8>(1), 2, 0x10, 2, 0x10));
            const accum_type<Elems / 4> acc4 = ::concat(mul_op(acc.template extract<2>(6)..., v.template extract<8>(1), 4, 0x10, 4, 0x10),
                                                        mul_op(acc.template extract<2>(7)..., v.template extract<8>(1), 6, 0x10, 6, 0x10));

            return concat_accum(acc1, acc2, acc3, acc4);
        }
    }
};

}

#endif
