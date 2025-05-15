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

#ifndef __AIE_API_DETAIL_AIE1_MAX_MIN_REDUCE_HPP__
#define __AIE_API_DETAIL_AIE1_MAX_MIN_REDUCE_HPP__

#include "../max_min.hpp"
#include "../vector.hpp"

namespace aie::detail {

template <typename T, unsigned Elems, MaxMinOperation Op>
struct max_min_bits_reduce_impl<8, T, Elems, Op>
{
    using vector_type = vector<T, Elems>;

    static T run(const vector_type &v)
    {
        if constexpr (Elems == 128) {
            const T res1 = max_min_reduce_bits<16, int16, Elems / 2, Op>::run(v.template extract<Elems / 2>(0).unpack());
            const T res2 = max_min_reduce_bits<16, int16, Elems / 2, Op>::run(v.template extract<Elems / 2>(1).unpack());

            if constexpr (Op == MaxMinOperation::Max)
                return (T) std::max(res1, res2);
            else
                return (T) std::min(res1, res2);
        }
        else {
            return (T) max_min_reduce_bits<16, int16, Elems, Op>::run(v.unpack());
        }
    }
};

template <unsigned Elems, MaxMinOperation Op>
struct max_min_bits_reduce_impl<16, int16, Elems, Op>
{
    using           T = int16;
    using vector_type = vector<T, Elems>;

    static constexpr auto get_op()
    {
        if constexpr (Op == MaxMinOperation::Max)
            return [](auto &&... args) __aie_inline { return ::max32(args...); };
        else
            return [](auto &&... args) __aie_inline { return ::min32(args...); };
    }

    static T run(const vector_type &v)
    {
        constexpr auto op = get_op();

        vector<T, 32> v2;

        if constexpr (Elems == 64) {
            v2 = op(v.template extract<32>(0), 0, 0x06040200, 0x0e0c0a08, 0x3210, v.template extract<32>(1),  0, 0x06040200, 0x0e0c0a08, 0x3210);
            v2 = op(                       v2, 0, 0x06040200, 0x0,        0x3210,                            16, 0x06040200, 0x0,        0x3210);
            v2 = op(                       v2, 0, 0x06040200, 0x0,        0x3210,                             8, 0x06040200, 0x0,        0x3210);
            v2 = op(                       v2, 0, 0x06040200, 0x0,        0x3210,                             4, 0x06040200, 0x0,        0x3210);
            v2 = op(                       v2, 0, 0x06040200, 0x0,        0x3210,                             2, 0x06040200, 0x0,        0x3210);
            v2 = op(                       v2, 0, 0x06040200, 0x0,        0x3210,                             0, 0x06040200, 0x0,        0x1);
        }
        else if constexpr (Elems == 32) {
            v2 = op(                        v, 0, 0x06040200, 0x0,        0x3210,                            16, 0x06040200, 0x0,        0x3210);
            v2 = op(                       v2, 0, 0x06040200, 0x0,        0x3210,                             8, 0x06040200, 0x0,        0x3210);
            v2 = op(                       v2, 0, 0x06040200, 0x0,        0x3210,                             4, 0x06040200, 0x0,        0x3210);
            v2 = op(                       v2, 0, 0x06040200, 0x0,        0x3210,                             2, 0x06040200, 0x0,        0x3210);
            v2 = op(                       v2, 0, 0x06040200, 0x0,        0x3210,                             0, 0x06040200, 0x0,        0x1);
        }
        else if constexpr (Elems == 16) {
            v2 = op(    v.template grow<32>(), 0, 0x06040200, 0x0,        0x3210,                             8, 0x06040200, 0x0,        0x3210);
            v2 = op(                       v2, 0, 0x06040200, 0x0,        0x3210,                             4, 0x06040200, 0x0,        0x3210);
            v2 = op(                       v2, 0, 0x06040200, 0x0,        0x3210,                             2, 0x06040200, 0x0,        0x3210);
            v2 = op(                       v2, 0, 0x06040200, 0x0,        0x3210,                             0, 0x06040200, 0x0,        0x1);
        }
        else if constexpr (Elems == 8) {
            v2 = op(    v.template grow<32>(), 0, 0x0,        0x0,        0x3210,                             4, 0x0,        0x0,        0x3210);
            v2 = op(                       v2, 0, 0x0,        0x0,        0x3210,                             2, 0x0,        0x0,        0x3210);
            v2 = op(                       v2, 0, 0x0,        0x0,        0x3210,                             0, 0x0,        0x0,        0x1);
        }

        return v2[0];
    }
};


template <unsigned Elems, MaxMinOperation Op>
struct max_min_bits_reduce_impl<32, int32, Elems, Op>
{
    using           T = int32;
    using vector_type = vector<T, Elems>;

    static constexpr auto get_op()
    {
        if constexpr (Op == MaxMinOperation::Max)
            return [](auto &&... args) __aie_inline { return ::max16(args...); };
        else
            return [](auto &&... args) __aie_inline { return ::min16(args...); };
    }

    static T run(const vector_type &v)
    {
        constexpr auto op = get_op();

        vector<T, 16> v2;

        if constexpr (Elems == 32) {
            v2 = op(v.template extract<16>(0), 0, 0x76543210, 0xfedcba98, v.template extract<16>(1), 0, 0x76543210, 0xfedcba98);
            v2 = op(                       v2, 0, 0x76543210, 0x0,                                   8, 0x76543210, 0x0);
            v2 = op(                       v2, 0, 0x76543210, 0x0,                                   4, 0x76543210, 0x0);
            v2 = op(                       v2, 0, 0x76543210, 0x0,                                   2, 0x76543210, 0x0);
            v2 = op(                       v2, 0, 0x76543210, 0x0,                                   1, 0x76543210, 0x0);
        }
        else if constexpr (Elems == 16) {
            v2 = op(                        v, 0, 0x76543210, 0x0,                                   8, 0x76543210, 0x0);
            v2 = op(                       v2, 0, 0x76543210, 0x0,                                   4, 0x76543210, 0x0);
            v2 = op(                       v2, 0, 0x76543210, 0x0,                                   2, 0x76543210, 0x0);
            v2 = op(                       v2, 0, 0x76543210, 0x0,                                   1, 0x76543210, 0x0);
        }
        else if constexpr (Elems == 8) {
            v2 = op(    v.template grow<16>(), 0, 0x76543210, 0x0,                                   4, 0x76543210, 0x0);
            v2 = op(                       v2, 0, 0x76543210, 0x0,                                   2, 0x76543210, 0x0);
            v2 = op(                       v2, 0, 0x76543210, 0x0,                                   1, 0x76543210, 0x0);
        }
        else if constexpr (Elems == 4) {
            v2 = op(    v.template grow<16>(), 0, 0x76543210, 0x0,                                   2, 0x76543210, 0x0);
            v2 = op(                       v2, 0, 0x76543210, 0x0,                                   1, 0x76543210, 0x0);
        }

        return v2[0];
    }
};

template <unsigned Elems, MaxMinOperation Op>
struct max_min_bits_reduce_impl<32, float, Elems, Op>
{
    using           T = float;
    using vector_type = vector<T, Elems>;

    static constexpr auto get_op()
    {
        if constexpr (Op == MaxMinOperation::Max)
            return [](auto &&... args) __aie_inline { return ::fpmax(args...); };
        else
            return [](auto &&... args) __aie_inline { return ::fpmin(args...); };
    }

    static T run(const vector_type &v)
    {
        constexpr auto op = get_op();

        vector<T, 8> v2;

        if constexpr (Elems == 32) {
            v2              = v.template extract<8>(0);
            vector<T, 8> v3 = v.template extract<8>(2);

            v2 = op(v2, v.template extract<16>(0), 8, 0x76543210);
            v3 = op(v3, v.template extract<16>(1), 8, 0x76543210);

            v2 = op(v2, v3.template grow<16>(), 0, 0x76543210);

            v2 = op(v2, v2.template grow<16>(), 4, 0x76543210);
            v2 = op(v2, v2.template grow<16>(), 2, 0x76543210);
            v2 = op(v2, v2.template grow<16>(), 1, 0x76543210);
        }
        else if constexpr (Elems == 16) {
            v2 = v.template extract<8>(0);

            v2 = op(v2, v,                      8, 0x76543210);
            v2 = op(v2, v2.template grow<16>(), 4, 0x76543210);
            v2 = op(v2, v2.template grow<16>(), 2, 0x76543210);
            v2 = op(v2, v2.template grow<16>(), 1, 0x76543210);
        }
        else if constexpr (Elems == 8) {
            v2 = op(v,   v.template grow<16>(), 4, 0x76543210);
            v2 = op(v2, v2.template grow<16>(), 2, 0x76543210);
            v2 = op(v2, v2.template grow<16>(), 1, 0x76543210);
        }
        else if constexpr (Elems == 4) {
            v2 = v.template grow<8>();

            v2 = op(v2,  v.template grow<16>(), 2, 0x76543210);
            v2 = op(v2, v2.template grow<16>(), 1, 0x76543210);
        }

        return v2[0];
    }
};

}

#endif
