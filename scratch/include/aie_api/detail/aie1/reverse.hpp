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

#ifndef __AIE_API_DETAIL_AIE1_REVERSE__HPP__
#define __AIE_API_DETAIL_AIE1_REVERSE__HPP__

#include "../vector.hpp"

namespace aie::detail {

template <typename T, unsigned Elems>
struct reverse_impl<8, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &a)
    {
        vector_type ret;

        if constexpr (Elems == 128) {
            const vector<T, Elems / 2> tmp_1 = a.template extract<Elems / 2>(0);
            const vector<T, Elems / 2> tmp_2 = a.template extract<Elems / 2>(1);

            ret.insert(0, reverse_impl<8, T, Elems / 2>::run(tmp_2));
            ret.insert(1, reverse_impl<8, T, Elems / 2>::run(tmp_1));
        }
        else {
            ret = reverse_impl<16, int16, Elems>::run(a.unpack()).template pack<T>();
        }

        return ret;
    }
};

template <typename T, unsigned Elems>
struct reverse_impl<16, T, Elems>
{
    using vector_type = vector<T, Elems>;
    using native_vector_type = vector<int16, 32>;

    static vector_type run(const vector_type &a)
    {
        vector_type ret;

        if constexpr (Elems == 8) {
            native_vector_type tmp = a.template grow<32>();
            tmp = shuffle32(tmp, 0, 0x0002,     0x0,        0x0123);

            ret = tmp.template extract<Elems>(0);
        }
        else if constexpr (Elems == 16) {
            native_vector_type tmp = a.template grow<32>();
            tmp = shuffle32(tmp, 0, 0x00020406, 0x0,        0x0123);

            ret = tmp.template extract<Elems>(0);
        }
        else if constexpr (Elems == 32) {
            ret = shuffle32(a,   0, 0x080a0c0e, 0x00020406, 0x0123);
        }
        else if constexpr (Elems == 64) {
            auto tmp1 = reverse<T, Elems / 2>::run(vector_cast<T>(a.template extract<32>(0)));
            auto tmp2 = reverse<T, Elems / 2>::run(vector_cast<T>(a.template extract<32>(1)));

            ret.insert(0, vector_cast<T>(tmp2));
            ret.insert(1, vector_cast<T>(tmp1));
        }

        return ret;
    }
};

template <typename T, unsigned Elems>
struct reverse_impl<32, T, Elems>
{
    using vector_type        = vector<T, Elems>;
    using native_vector_type = vector<int32, 16>;

    static vector_type run(const vector_type &a)
    {
        vector_type ret;

        if constexpr (Elems == 4) {
            native_vector_type tmp = vector_cast<int32>(a.template grow<16>());
            tmp = shuffle16(tmp, 0, 0x0123,     0x0);

            ret = vector_cast<T>(tmp).template extract<Elems>(0);
        }
        else if constexpr (Elems == 8) {
            native_vector_type tmp = vector_cast<int32>(a.template grow<16>());
            tmp = shuffle16(tmp, 0, 0x01234567, 0x0);

            ret = vector_cast<T>(tmp).template extract<Elems>(0);
        }
        else if constexpr (Elems == 16) {
            native_vector_type tmp = vector_cast<int32>(a);
            tmp = shuffle16(tmp, 0, 0x89abcdef, 0x01234567);

            ret = vector_cast<T>(tmp);
        }
        else if constexpr (Elems == 32) {
            auto tmp1 = reverse<int32, Elems / 2>::run(vector_cast<int32>(a.template extract<16>(0)));
            auto tmp2 = reverse<int32, Elems / 2>::run(vector_cast<int32>(a.template extract<16>(1)));

            ret.insert(0, vector_cast<T>(tmp2));
            ret.insert(1, vector_cast<T>(tmp1));
        }

        return ret;
    }
};

template <typename T, unsigned Elems>
struct reverse_impl<64, T, Elems>
{
    using vector_type        = vector<T, Elems>;
    using native_vector_type = vector<cint32, 8>;

    static vector_type run(const vector_type &a)
    {
        vector_type ret;

        if constexpr (Elems == 2) {
            native_vector_type tmp = vector_cast<cint32>(a.template grow<8>());
            tmp = shuffle8(tmp, 0, 0x01);

            ret = vector_cast<T>(tmp).template extract<Elems>(0);
        }
        else if constexpr (Elems == 4) {
            native_vector_type tmp = vector_cast<cint32>(a.template grow<8>());
            tmp = shuffle8(tmp, 0, 0x0123);

            ret = vector_cast<T>(tmp).template extract<Elems>(0);
        }
        else if constexpr (Elems == 8) {
            native_vector_type tmp = vector_cast<cint32>(a);
            tmp = shuffle8(tmp, 0, 0x01234567);

            ret = vector_cast<T>(tmp);
        }
        else if constexpr (Elems == 16) {
            auto tmp1 = reverse<cint32, Elems / 2>::run(vector_cast<cint32>(a.template extract<8>(0)));
            auto tmp2 = reverse<cint32, Elems / 2>::run(vector_cast<cint32>(a.template extract<8>(1)));

            ret.insert(0, vector_cast<T>(tmp2));
            ret.insert(1, vector_cast<T>(tmp1));
        }

        return ret;
    }
};

}

#endif
