/*  (c) Copyright 2021 - 2022 Xilinx, Inc. All rights reserved.

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

#ifndef __AIE_API_DETAIL_AIE2_MAX_MIN_REDUCE__HPP__
#define __AIE_API_DETAIL_AIE2_MAX_MIN_REDUCE__HPP__

#include "../max_min.hpp"
#include "../shuffle.hpp"
#include "../vector.hpp"
#include "../utils.hpp"

namespace aie::detail {

template <typename T, unsigned Elems, MaxMinOperation Op>
struct max_min_bits_reduce_impl<4, T, Elems, Op>
{
    using vector_type = vector<T, Elems>;

    static T run(const vector_type &v)
    {
        using next_type = utils::get_next_integer_type_t<T>;

        if constexpr (Elems <= 128) {
            return (T) max_min_bits_reduce_impl<8, next_type, Elems, Op>::run(v.unpack());
        }
        else if constexpr (Elems == 256) {
            const T tmp1 = max_min_bits_reduce_impl<8, next_type, Elems / 2, Op>::run(v.template extract<128>(0).unpack());
            const T tmp2 = max_min_bits_reduce_impl<8, next_type, Elems / 2, Op>::run(v.template extract<128>(1).unpack());

            if      constexpr (Op == MaxMinOperation::Max) return std::max(tmp1, tmp2);
            else if constexpr (Op == MaxMinOperation::Min) return std::min(tmp1, tmp2);
        }
    }
};

template <typename T, unsigned Elems, MaxMinOperation Op>
struct max_min_bits_reduce_impl<8, T, Elems, Op>
{
    using vector_type = vector<T, Elems>;

    static T run(const vector_type &v)
    {
        constexpr auto op = get_max_min_op<Op>();

        if constexpr (Elems <= 64) {
            vector<T, 64> tmp = v.template grow<64>();

            utils::unroll_times<utils::log2(Elems)>([&](auto idx) __aie_inline {
                tmp = op(tmp, SHIFT_BYTES(tmp, vector<T, 64>(), Elems >> (idx + 1)));
            });

            return (T) tmp[0];
        }
        else if constexpr (Elems == 128) {
            const vector<T, 64> tmp = max_min_bits_impl<8, T, 64, Op>::run(v.template extract<64>(0),
                                                                           v.template extract<64>(1));

            return max_min_bits_reduce_impl<8, T, 64, Op>::run(tmp);
        }
    }
};

template <typename T, unsigned Elems, MaxMinOperation Op>
struct max_min_bits_reduce_impl<16, T, Elems, Op>
{
    using vector_type = vector<T, Elems>;

    static T run(const vector_type &v)
    {
        constexpr auto op = get_max_min_op<Op>();

        if constexpr (Elems <= 32) {
            vector<T, 32> tmp = v.template grow<32>();

            utils::unroll_times<utils::log2(Elems)>([&](auto idx) __aie_inline {
                tmp = op(tmp, SHIFT_BYTES(tmp, vector<T, 32>(), (Elems >> (idx + 1)) * sizeof(T)));
            });

            return (T) tmp[0];
        }
        else if constexpr (Elems == 64) {
            const vector<T, 32> tmp = max_min_bits_impl<16, T, 32, Op>::run(v.template extract<32>(0),
                                                                            v.template extract<32>(1));

            return max_min_bits_reduce_impl<16, T, 32, Op>::run(tmp);
        }
    }
};

template <typename T, unsigned Elems, MaxMinOperation Op>
struct max_min_bits_reduce_impl<32, T, Elems, Op>
{
    using vector_type = vector<T, Elems>;

    static T run(const vector_type &v)
    {
        constexpr auto op = get_max_min_op<Op>();

        if constexpr (Elems <= 16) {
            vector<T, 16> tmp = v.template grow<16>();

            utils::unroll_times<utils::log2(Elems)>([&](auto idx) __aie_inline {
                tmp = op(tmp, SHIFT_BYTES(tmp, vector<T, 16>(), (Elems >> (idx + 1)) * sizeof(T)));
            });

            return (T) tmp[0];
        }
        else if constexpr (Elems == 32) {
            const vector<T, 16> tmp = max_min_bits_impl<32, T, 16, Op>::run(v.template extract<16>(0),
                                                                            v.template extract<16>(1));

            return max_min_bits_reduce_impl<32, T, 16, Op>::run(tmp);
        }
    }
};

}

#endif
