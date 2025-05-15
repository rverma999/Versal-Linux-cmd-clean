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

#ifndef __AIE_API_DETAIL_AIE1_MUL_MAXMIN_ACC48__HPP__
#define __AIE_API_DETAIL_AIE1_MUL_MAXMIN_ACC48__HPP__

#include <algorithm>

#include "../accum.hpp"
#include "../vector.hpp"

namespace aie::detail {

template <MulMacroOp MulOp, typename T1, typename T2>
struct mul_maxmin_bits_impl<MulOp, 48, 8, T1, 8, T2>
{
    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using accum_tag = accum_tag_for_mul_types<T1, T2, 48>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &m1,
                                 const vector_type1<Elems> &m2,
                                 const vector_type2<Elems> &v,
                                 const Acc &... acc)
    {
        if constexpr (Elems == 128) {
            accum_type<64> tmp1, tmp2;

            tmp1 = mul_maxmin<MulOp, 48, int16, int16>::run( m1.template extract<64>(0).unpack(),
                                                             m2.template extract<64>(0).unpack(),
                                                              v.template extract<64>(0).unpack(),
                                                            acc.template extract<64>(0)...);
            tmp2 = mul_maxmin<MulOp, 48, int16, int16>::run( m1.template extract<64>(1).unpack(),
                                                             m2.template extract<64>(1).unpack(),
                                                              v.template extract<64>(1).unpack(),
                                                            acc.template extract<64>(1)...);

            return concat_accum(tmp1, tmp2);
        }
        else {
            accum_type<Elems> tmp;

            tmp = mul_maxmin<MulOp, 48, int16, int16>::run(m1.unpack(),
                                                           m2.unpack(),
                                                            v.unpack(),
                                                           acc...);

            return tmp;
        }
    }
};

template <MulMacroOp MulOp, typename T2>
struct mul_maxmin_bits_impl<MulOp, 48, 16, int16, 8, T2>
{
    using T1 = int16;

    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using accum_tag = accum_tag_for_mul_types<T1, T2, 48>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &m1,
                                 const vector_type1<Elems> &m2,
                                 const vector_type2<Elems> &v,
                                 const Acc &... acc)
    {
        accum_type<Elems> tmp;

        tmp = mul_maxmin<MulOp, 48, int16, int16>::run(m1,
                                                       m2,
                                                       v.unpack(),
                                                       acc...);

        return tmp;
    }
};

template <MulMacroOp MulOp, typename T1>
struct mul_maxmin_bits_impl<MulOp, 48, 8, T1, 16, int16>
{
    using T2 = int16;

    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using accum_tag = accum_tag_for_mul_types<T1, T2, 48>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &m1,
                                 const vector_type1<Elems> &m2,
                                 const vector_type2<Elems> &v,
                                 const Acc &... acc)
    {
        accum_type<Elems> tmp;

        tmp = mul_maxmin<MulOp, 48, int16, int16>::run(m1.unpack(),
                                                       m2.unpack(),
                                                       v,
                                                       acc...);

        return tmp;
    }
};


template <MulMacroOp MulOp>
struct mul_maxmin_bits_impl<MulOp, 48, 16, int16, 16, int16>
{
    using T1 = int16;
    using T2 = int16;

    template <unsigned Elems>
    using vector_type = vector<T1, Elems>;

    using accum_tag = accum_tag_for_mul_types<T1, T2, 48>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if      constexpr (MulOp == MulMacroOp::MulMax)     return [](auto &&... args) __aie_inline { return ::mul16_max(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_MulMax) return [](auto &&... args) __aie_inline { return ::mac16_max(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_MulMax) return [](auto &&... args) __aie_inline { return ::msc16_max(args...); };
        else if constexpr (MulOp == MulMacroOp::MulMin)     return [](auto &&... args) __aie_inline { return ::mul16_min(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_MulMin) return [](auto &&... args) __aie_inline { return ::mac16_min(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_MulMin) return [](auto &&... args) __aie_inline { return ::msc16_min(args...); };
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type<Elems> &m1,
                                 const vector_type<Elems> &m2,
                                 const vector_type<Elems> &v,
                                 const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();
        constexpr unsigned num_mul = Elems < 16? 1 : Elems / 16;

        accum_type<Elems> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const accum_type<16> tmp = mul_op(acc.template grow_extract<16>(idx)...,
                                              ::concat(m1.template grow_extract<16>(idx), *(const v16int16 *)ZERO), 0, 0x73727170, 0x77767574, 0x3120,
                                              ::concat(m2.template grow_extract<16>(idx), *(const v16int16 *)ZERO), 0,                         0x3120,
                                              v.template grow_extract<16>(idx),                                     0, 0x76543210, 0xfedcba98, 0);
            ret.insert(idx, tmp.template extract<(Elems < 16? Elems : 16)>(0));
        });

        return ret;
    }
};

template <MulMacroOp MulOp>
struct mul_maxmin_bits_impl<MulOp, 48, 32, int32, 16, int16>
{
    using T1 = int32;
    using T2 = int16;

    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using accum_tag = accum_tag_for_mul_types<T1, T2, 48>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if      constexpr (MulOp == MulMacroOp::MulMax)     return [](auto &&... args) __aie_inline { return ::mul16_max(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_MulMax) return [](auto &&... args) __aie_inline { return ::mac16_max(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_MulMax) return [](auto &&... args) __aie_inline { return ::msc16_max(args...); };
        else if constexpr (MulOp == MulMacroOp::MulMin)     return [](auto &&... args) __aie_inline { return ::mul16_min(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_MulMin) return [](auto &&... args) __aie_inline { return ::mac16_min(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_MulMin) return [](auto &&... args) __aie_inline { return ::msc16_min(args...); };
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &m1,
                                 const vector_type1<Elems> &m2,
                                 const vector_type2<Elems> &v,
                                 const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();
        constexpr unsigned num_mul = Elems < 16? 1 : Elems / 16;

        accum_type<Elems> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const accum_type<16> tmp = mul_op(acc.template grow_extract<16>(idx)...,
                                              m1.template grow_extract<16>(idx), 0, 0x76543210, 0xfedcba98,
                                              m2.template grow_extract<16>(idx), 0,
                                              v.template grow_extract<16>(idx),  0, 0x76543210, 0xfedcba98);
            ret.insert(idx, tmp.template extract<(Elems < 16? Elems : 16)>(0));
        });

        return ret;
    }
};

template <MulMacroOp MulOp>
struct mul_maxmin_bits_impl<MulOp, 48, 16, int16, 32, int32>
{
    using T1 = int16;
    using T2 = int32;

    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using accum_tag = accum_tag_for_mul_types<T1, T2, 48>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if      constexpr (MulOp == MulMacroOp::MulMax)     return [](auto &&... args) __aie_inline { return ::mul16_max(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_MulMax) return [](auto &&... args) __aie_inline { return ::mac16_max(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_MulMax) return [](auto &&... args) __aie_inline { return ::msc16_max(args...); };
        else if constexpr (MulOp == MulMacroOp::MulMin)     return [](auto &&... args) __aie_inline { return ::mul16_min(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_MulMin) return [](auto &&... args) __aie_inline { return ::mac16_min(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_MulMin) return [](auto &&... args) __aie_inline { return ::msc16_min(args...); };
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &m1,
                                 const vector_type1<Elems> &m2,
                                 const vector_type2<Elems> &v,
                                 const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();
        constexpr unsigned num_mul = Elems < 16? 1 : Elems / 16;

        accum_type<Elems> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            accum_type<16> tmp = mul_op(acc.template grow_extract<16>(idx)...,
                                        m1.template grow_extract<32>(idx / 2), 16 * (idx % 2), 0x76543210, 0x00000000,
                                        m2.template grow_extract<32>(idx / 2), 16 * (idx % 2),
                                        v.template grow_extract<8>(idx * 2),                0, 0x76543210, 0x00000000);
            ret.insert(idx * 2,     tmp.template extract<8>(0));

            if constexpr (Elems == 8) return;

            tmp                = mul_op(acc.template grow_extract<16>(idx)...,
                                        m1.template grow_extract<32>(idx / 2),  16 * (idx % 2), 0x00000000, 0xfedcba98,
                                        m2.template grow_extract<32>(idx / 2),  16 * (idx % 2),
                                        v.template grow_extract<8>(idx * 2 + 1),             0, 0x00000000, 0x76543210);
            ret.insert(idx * 2 + 1, tmp.template extract<8>(1));
        });

        return ret;
    }
};

template <MulMacroOp MulOp>
struct mul_maxmin_bits_impl<MulOp, 48, 16, int16, 32, cint16>
{
    using T1 = int16;
    using T2 = cint16;

    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using accum_tag = accum_tag_for_mul_types<T1, T2, 48>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems>
    static constexpr auto get_mul_op()
    {
        if      constexpr (MulOp == MulMacroOp::MulMax)     return [](auto &&... args) __aie_inline { return ::mul8_max(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_MulMax) return [](auto &&... args) __aie_inline { return ::mac8_max(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_MulMax) return [](auto &&... args) __aie_inline { return ::msc8_max(args...); };
        else if constexpr (MulOp == MulMacroOp::MulMin)     return [](auto &&... args) __aie_inline { return ::mul8_min(args...); };
        else if constexpr (MulOp == MulMacroOp::Add_MulMin) return [](auto &&... args) __aie_inline { return ::mac8_min(args...); };
        else if constexpr (MulOp == MulMacroOp::Sub_MulMin) return [](auto &&... args) __aie_inline { return ::msc8_min(args...); };
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &m1,
                                 const vector_type1<Elems> &m2,
                                 const vector_type2<Elems> &v,
                                 const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<Elems>();
        constexpr unsigned num_mul = Elems / 8;

        accum_type<Elems> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            accum_type<8> tmp = mul_op(acc.template grow_extract<8>(idx)...,
                                       ::concat(m1.template grow_extract<16>(idx / 2), *(const v16int16 *)ZERO), 8 * (idx % 2), 0x76543210, 16,
                                       ::concat(m2.template grow_extract<16>(idx / 2), *(const v16int16 *)ZERO), 8 * (idx % 2),
                                         v.template grow_extract<8>(idx),                                                    0, 0x76543210, 0);
            ret.insert(idx, tmp);
        });

        return ret;
    }
};

}

#endif
