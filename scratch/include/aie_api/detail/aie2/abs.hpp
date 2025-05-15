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

#ifndef __AIE_API_DETAIL_AIE2_ABS__HPP__
#define __AIE_API_DETAIL_AIE2_ABS__HPP__

#include "../broadcast.hpp"

namespace aie::detail {

template <typename T, unsigned Elems>
struct abs_bits_impl<8, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &v)
    {
        vector_type ret;

        constexpr unsigned native_abs_elems = 64;
        using native_abs_type = abs_bits_impl<8, T, native_abs_elems>;

        if constexpr (vector_type::is_signed()) {
            if constexpr (Elems == 16 || Elems == 32) {
                ret = native_abs_type::run(v.template grow<native_abs_elems>()).template extract<Elems>(0);
            }
            else if constexpr (Elems == 64) {
                ret = ::abs(v);
            }
            else if constexpr (Elems == 128) {
                ret = concat_vector(native_abs_type::run(v.template extract<native_abs_elems>(0)),
                                    native_abs_type::run(v.template extract<native_abs_elems>(1)));
            }
        }
        else {
            ret = v;
        }

        return ret;
    }
};

template <typename T, unsigned Elems>
struct abs_bits_impl<16, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &v)
    {
        vector_type ret;

        constexpr unsigned native_abs_elems = 32;
        using native_abs_type = abs_bits_impl<16, T, native_abs_elems>;

        if constexpr (vector_type::is_signed()) {
            if constexpr (Elems == 8 || Elems == 16) {
                ret = native_abs_type::run(v.template grow<native_abs_elems>()).template extract<Elems>(0);
            }
            else if constexpr (Elems == 32) {
                ret = ::abs(v);
            }
            else if constexpr (Elems == 64) {
                ret = concat_vector(native_abs_type::run(v.template extract<native_abs_elems>(0)),
                                    native_abs_type::run(v.template extract<native_abs_elems>(1)));
            }
        }
        else {
            ret = v;
        }

        return ret;
    }
};

template <typename T, unsigned Elems>
struct abs_bits_impl<32, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &v)
    {
        vector_type ret;

        constexpr unsigned native_abs_elems = 16;
        using native_abs_type = abs_bits_impl<32, T, native_abs_elems>;

        if constexpr (vector_type::is_signed()) {
            if constexpr (Elems == 4 || Elems == 8) {
                ret = native_abs_type::run(v.template grow<native_abs_elems>()).template extract<Elems>(0);
            }
            else if constexpr (Elems == 16) {
                ret = ::abs(v);
            }
            else if constexpr (Elems == 32) {
                ret = concat_vector(native_abs_type::run(v.template extract<native_abs_elems>(0)),
                                    native_abs_type::run(v.template extract<native_abs_elems>(1)));
            }
        }
        else {
            ret = v;
        }

        return ret;
    }
};

#if __AIE_API_FP32_EMULATION__

template <unsigned Elems>
struct abs_bits_impl<32, float, Elems>
{
    using           T = float;
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &v)
    {
        vector_type ret;

        constexpr unsigned native_abs_elems = 16;
        using native_abs_type = abs_bits_impl<32, T, native_abs_elems>;

        if constexpr (Elems == 4 || Elems == 8) {
            ret = native_abs_type::run(v.template grow<native_abs_elems>()).template extract<Elems>(0);
        }
        else if constexpr (Elems == 16) {
            vector<uint32, Elems> tmp;

            // Implement abs by clearing the upper bit of the elements using an & operation
            tmp = ::band(vector_cast<uint32>(v), broadcast<uint32, Elems>::run(0x7fffffff));

            ret = vector_cast<T>(tmp);
        }
        else if constexpr (Elems == 32) {
            ret = concat_vector(native_abs_type::run(v.template extract<native_abs_elems>(0)),
                                native_abs_type::run(v.template extract<native_abs_elems>(1)));
        }

        return ret;
    }
};

#endif

}

#endif
