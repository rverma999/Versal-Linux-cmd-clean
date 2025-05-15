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

#ifndef __AIE_API_DETAIL_AIE2_MAX_MIN_CMP__HPP__
#define __AIE_API_DETAIL_AIE2_MAX_MIN_CMP__HPP__

#include "../max_min.hpp"
#include "../vector.hpp"

namespace aie::detail {

template <MaxMinOperation Op>
static constexpr auto get_max_min_cmp_op()
{
    if constexpr (Op == MaxMinOperation::MaxCmp)
        return [](auto &&... args) __aie_inline { return ::max_lt(args...); };
    else if constexpr (Op == MaxMinOperation::MinCmp)
        return [](auto &&... args) __aie_inline { return ::min_ge(args...); };
}

template <typename T, unsigned Elems, MaxMinOperation Op>
struct max_min_cmp_bits_impl<4, T, Elems, Op>
{
    using vector_type = vector<T, Elems>;

    static auto run(const vector_type &v1, const vector_type &v2)
    {
        using next_type = utils::get_next_integer_type_t<T>;

        if constexpr (Elems < 256) {
            auto [tmp, mask] = max_min_cmp_bits_impl<8, next_type, Elems, Op>::run(v1.unpack(), v2.unpack());
            return std::make_tuple(tmp.pack(), mask);
        }
        else {
            vector_type ret;

            auto [tmp1, mask1] = max_min_cmp_bits_impl<8, next_type, Elems / 2, Op>::run(v1.template extract<Elems / 2>(0).unpack(), v2.template extract<Elems / 2>(0).unpack());
            ret.insert(0, tmp1.pack());
            auto [tmp2, mask2] = max_min_cmp_bits_impl<8, next_type, Elems / 2, Op>::run(v1.template extract<Elems / 2>(1).unpack(), v2.template extract<Elems / 2>(1).unpack());
            ret.insert(1, tmp2.pack());

            return std::make_tuple(ret, mask<Elems>::from_masks(mask1, mask2));
        }
   }

    template <unsigned Elems2>
    static auto run(vector_elem_const_ref<T, Elems2> a, const vector_type &v)
    {
        return run((T)a, v);
    }

    template <unsigned Elems2>
    static auto run(const vector_type &v, vector_elem_const_ref<T, Elems2> a)
    {
        return run(v, (T)a);
    }

    static auto run(const T &a, const vector_type &v)
    {
        return run(broadcast<T, Elems>::run(a), v);
    }

    static auto run(const vector_type &v, const T &a)
    {
        return run(v, broadcast<T, Elems>::run(a));
    }
};

template <typename T, unsigned Elems, MaxMinOperation Op>
struct max_min_cmp_bits_impl<8, T, Elems, Op>
{
    using vector_type = vector<T, Elems>;

    static auto run(const vector_type &v1, const vector_type &v2)
    {
        constexpr auto op = get_max_min_cmp_op<Op>();

        vector_type ret;

        if constexpr (Elems == 16 || Elems == 32) {
            unsigned long long cmp;
            vector<T, 64> tmp;

            tmp = op(v1.template grow<64>(), v2.template grow<64>(), cmp);
            ret = tmp.template extract<Elems>(0);

            return std::make_tuple(ret, mask<Elems>::from_uint32(cmp));
        }
        else if constexpr (Elems == 64) {
            unsigned long long cmp;
            ret = op(v1, v2, cmp);

            return std::make_tuple(ret, mask<Elems>::from_uint64(cmp));
        }
        else if constexpr (Elems == 128) {
            unsigned long long cmp1;
            unsigned long long cmp2;

            const vector<T, Elems / 2> tmp1 = op(v1.template extract<Elems / 2>(0), v2.template extract<Elems / 2>(0), cmp1); ret.insert(0, tmp1);
            const vector<T, Elems / 2> tmp2 = op(v1.template extract<Elems / 2>(1), v2.template extract<Elems / 2>(1), cmp2); ret.insert(1, tmp2);

            return std::make_tuple(ret, mask<Elems>::from_uint64(cmp1, cmp2));
        }
    }
};

template <typename T, unsigned Elems, MaxMinOperation Op>
struct max_min_cmp_bits_impl<16, T, Elems, Op>
{
    using vector_type = vector<T, Elems>;

    static auto run(const vector_type &v1, const vector_type &v2)
    {
        constexpr auto op = get_max_min_cmp_op<Op>();

        vector_type ret;

        if constexpr (Elems == 8 || Elems == 16) {
            unsigned cmp;
            vector<T, 32> tmp;

            tmp = op(v1.template grow<32>(), v2.template grow<32>(), cmp);
            ret = tmp.template extract<Elems>(0);

            return std::make_tuple(ret, mask<Elems>::from_uint32(cmp));
        }
        else if constexpr (Elems == 32) {
            unsigned cmp;

            ret = op(v1, v2, cmp);

            return std::make_tuple(ret, mask<Elems>::from_uint32(cmp));
        }
        else if constexpr (Elems == 64) {
            unsigned cmp1, cmp2;

            const vector<T, Elems / 2> tmp1 = op(v1.template extract<Elems / 2>(0), v2.template extract<Elems / 2>(0), cmp1); ret.insert(0, tmp1);
            const vector<T, Elems / 2> tmp2 = op(v1.template extract<Elems / 2>(1), v2.template extract<Elems / 2>(1), cmp2); ret.insert(1, tmp2);

            return std::make_tuple(ret, mask<Elems>::from_uint32(cmp1, cmp2));
        }
    }
};

template <typename T, unsigned Elems, MaxMinOperation Op>
struct max_min_cmp_bits_impl<32, T, Elems, Op>
{
    using vector_type = vector<T, Elems>;

    static auto run(const vector_type &v1, const vector_type &v2)
    {
        constexpr auto op = get_max_min_cmp_op<Op>();

        vector_type ret;

        if constexpr (Elems == 4 || Elems == 8) {
            unsigned cmp;
            vector<T, 16> tmp;

            tmp = op(v1.template grow<16>(), v2.template grow<16>(), cmp);
            ret = tmp.template extract<Elems>(0);

            return std::make_tuple(ret, mask<Elems>::from_uint32(cmp));
        }
        else if constexpr (Elems == 16) {
            unsigned cmp;

            ret = op(v1, v2, cmp);

            return std::make_tuple(ret, mask<Elems>::from_uint32(cmp));
        }
        else if constexpr (Elems == 32) {
            unsigned cmp1, cmp2;

            const vector<T, Elems / 2> tmp1 = op(v1.template extract<Elems / 2>(0), v2.template extract<Elems / 2>(0), cmp1); ret.insert(0, tmp1);
            const vector<T, Elems / 2> tmp2 = op(v1.template extract<Elems / 2>(1), v2.template extract<Elems / 2>(1), cmp2); ret.insert(1, tmp2);

            return std::make_tuple(ret, mask<Elems>::from_uint32((cmp2 << 16) | cmp1));
        }
    }
};

}

#endif
