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

#ifndef __AIE_API_DETAIL_AIE1_NEG__HPP__
#define __AIE_API_DETAIL_AIE1_NEG__HPP__

#include "../vector.hpp"

namespace aie::detail {

template <typename T, unsigned Elems>
struct neg_bits_impl<16, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static_assert(vector_type::is_signed());

    static vector_type run(const vector_type &v)
    {
        vector_type ret;

        constexpr unsigned native_neg_elems = 32;
        using native_neg_type = neg_bits_impl<16, T, native_neg_elems>;

        if constexpr (Elems <= 16) {
            ret = native_neg_type::run(v.template grow<native_neg_elems>()).template extract<Elems>(0);
        }
        else if constexpr (Elems == 32) {
            const vector<int16, 16> zero(0);

            ret  = ::sub32(zero.template grow<32>(), 0, 0x00000000, 0x00000000, 0x0000,
                                                  v, 0, 0x06040200, 0x0e0c0a08, 0x3210);
        }
        else if constexpr (Elems == 64) {
            const vector<T, 16> zero(0);

            const vector<T, 32> tmp1 = ::sub32(zero.template grow<32>(),  0, 0x00000000, 0x00000000, 0x0000,
                                               v.template extract<32>(0), 0, 0x06040200, 0x0e0c0a08, 0x3210);
            ret.insert(0, tmp1);
            const vector<T, 32> tmp2 = ::sub32(zero.template grow<32>(),  0, 0x00000000, 0x00000000, 0x0000,
                                               v.template extract<32>(1), 0, 0x06040200, 0x0e0c0a08, 0x3210);
            ret.insert(1, tmp2);
        }

        return ret;
    }
};

template <typename T, unsigned Elems>
struct neg_bits_impl<32, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static_assert(vector_type::is_signed());

    static vector_type run(const vector_type &v)
    {
        vector_type ret;

        constexpr unsigned native_neg_elems = 16;
        using native_neg_type = neg_bits_impl<32, T, native_neg_elems>;

        if constexpr (Elems <= 8) {
            ret = native_neg_type::run(v.template grow<native_neg_elems>()).template extract<Elems>(0);
        }
        else if constexpr (Elems == 16) {
            if constexpr (vector_type::is_complex()) {
                const vector<int16, 16> zero(0);
                vector<int16, 32> tmp = vector_cast<int16>(v);

                tmp  = ::sub32(zero.template grow<32>(), 0, 0x00000000, 0x00000000, 0x0000,
                                                    tmp, 0, 0x06040200, 0x0e0c0a08, 0x3210);

                ret = vector_cast<T>(tmp);
            }
            else {
                const vector<T, 8> zero(0);

                ret = ::sub16(zero.template grow<16>(), 0, 0x00000000, 0x00000000,
                                                     v, 0, 0x76543210, 0xfedcba98);
            }
        }
        else if constexpr (Elems == 32) {
            if constexpr (vector_type::is_complex()) {
                const vector<int16, 16> zero(0);
                vector<int16, 64> tmp = vector_cast<int16>(v);

                const vector<int16, 32> tmp1 = ::sub32(zero.template grow<32>(),    0, 0x00000000, 0x00000000, 0x0000,
                                                       tmp.template extract<32>(0), 0, 0x06040200, 0x0e0c0a08, 0x3210);
                tmp.insert(0, tmp1);

                const vector<int16, 32> tmp2 = ::sub32(zero.template grow<32>(),    0, 0x00000000, 0x00000000, 0x0000,
                                                       tmp.template extract<32>(1), 0, 0x06040200, 0x0e0c0a08, 0x3210);
                tmp.insert(1, tmp2);

                ret = vector_cast<T>(tmp);
            }
            else {
                const vector<T, 8> zero(0);

                const vector<T, 16> tmp1 = ::sub16(zero.template grow<16>(),  0, 0x00000000, 0x00000000,
                                                   v.template extract<16>(0), 0, 0x76543210, 0xfedcba98);
                ret.insert(0, tmp1);
                const vector<T, 16> tmp2 = ::sub16(zero.template grow<16>(),  0, 0x00000000, 0x00000000,
                                                   v.template extract<16>(1), 0, 0x76543210, 0xfedcba98);
                ret.insert(1, tmp2);
            }
        }

        return ret;
    }
};

template <unsigned Elems>
struct neg_bits_impl<32, float, Elems>
{
    using vector_type = vector<float, Elems>;

    static vector_type run(const vector_type &v)
    {
        vector_type ret;

        if constexpr (Elems == 4) {
            const vector<float, 8> tmp = ::fpneg(v.template grow<16>(), 0, 0x3210);

            ret = tmp.template extract<Elems>(0);
        }
        else if constexpr (Elems == 8) {
            ret = ::fpneg(v.template grow<16>(), 0, 0x76543210);
        }
        else if constexpr (Elems == 16) {
            ret = ::concat(::fpneg(v, 0, 0x76543210),
                           ::fpneg(v, 8, 0x76543210));
        }
        else if constexpr (Elems == 32) {
            const vector<float, 8> tmp1 = ::fpneg(v.template extract<16>(0), 0, 0x76543210); ret.insert(0, tmp1);
            const vector<float, 8> tmp2 = ::fpneg(v.template extract<16>(0), 8, 0x76543210); ret.insert(1, tmp2);
            const vector<float, 8> tmp3 = ::fpneg(v.template extract<16>(1), 0, 0x76543210); ret.insert(2, tmp3);
            const vector<float, 8> tmp4 = ::fpneg(v.template extract<16>(1), 8, 0x76543210); ret.insert(3, tmp4);
        }

        return ret;
    }
};

template <unsigned Elems>
struct neg_bits_impl<64, cint32, Elems>
{
    using vector_type = vector<cint32, Elems>;

    static vector_type run(const vector_type &v)
    {
        return neg_bits<32, int32, Elems * 2>::run(v.template cast_to<int32>()).template cast_to<cint32>();
    }
};

template <unsigned Elems>
struct neg_bits_impl<64, cfloat, Elems>
{
    using vector_type = vector<cfloat, Elems>;

    static vector_type run(const vector_type &v)
    {
        return neg_bits<32, float, Elems * 2>::run(v.template cast_to<float>()).template cast_to<cfloat>();
    }
};

}

#endif
