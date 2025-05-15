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

#ifndef __AIE_API_DETAIL_AIE2_MAX_MIN__HPP__
#define __AIE_API_DETAIL_AIE2_MAX_MIN__HPP__

#include "../add.hpp"
#include "../broadcast.hpp"
#include "../interleave.hpp"

namespace aie::detail {

template <MaxMinOperation Op>
static constexpr auto get_max_min_op()
{
    if      constexpr (Op == MaxMinOperation::Max)     return [](auto &&... args) __aie_inline { return ::max(args...); };
    else if constexpr (Op == MaxMinOperation::Min)     return [](auto &&... args) __aie_inline { return ::min(args...); };
    else if constexpr (Op == MaxMinOperation::MaxDiff) return [](auto &&... args) __aie_inline { return ::maxdiff(args...); };
}

template <typename T, unsigned Elems, MaxMinOperation Op>
struct max_min_bits_impl<4, T, Elems, Op>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v1, const vector_type &v2)
    {
        using next_type = utils::get_next_integer_type_t<T>;

        if constexpr (Elems < 256) {
            return max_min_bits_impl<8, next_type, Elems, Op>::run(v1.unpack(), v2.unpack()).pack();
        }
        else {
            vector_type ret;

            const vector<next_type, Elems / 2> tmp1 = max_min_bits_impl<8, next_type, Elems / 2, Op>::run(v1.template extract<Elems / 2>(0).unpack(),
                                                                                                          v2.template extract<Elems / 2>(0).unpack());
            ret.insert(0, tmp1.pack());
            const vector<next_type, Elems / 2> tmp2 = max_min_bits_impl<8, next_type, Elems / 2, Op>::run(v1.template extract<Elems / 2>(1).unpack(),
                                                                                                          v2.template extract<Elems / 2>(1).unpack());
            ret.insert(1, tmp2.pack());

            return ret;
        }
   }

    __aie_inline
    static vector_type run(const vector_type &v1, const vector_type &v2, bool sign)
    {
        using next_type = utils::get_next_integer_type_t<T>;

        if constexpr (Elems < 256) {
            return max_min_bits_impl<8, next_type, Elems, Op>::run(v1.unpack_sign(sign), v2.unpack_sign(sign), sign).pack_sign(sign);
        }
        else {
            vector_type ret;

            const vector<next_type, Elems / 2> tmp1 = max_min_bits_impl<8, next_type, Elems / 2, Op>::run(v1.template extract<Elems / 2>(0).unpack_sign(sign),
                                                                                                          v2.template extract<Elems / 2>(0).unpack_sign(sign),
                                                                                                          sign);
            ret.insert(0, tmp1.pack_sign(sign));
            const vector<next_type, Elems / 2> tmp2 = max_min_bits_impl<8, next_type, Elems / 2, Op>::run(v1.template extract<Elems / 2>(1).unpack_sign(sign),
                                                                                                          v2.template extract<Elems / 2>(1).unpack_sign(sign),
                                                                                                          sign);
            ret.insert(1, tmp2.pack_sign(sign));

            return ret;
        }
   }

    __aie_inline
    static vector_type run(const T &a, const vector_type &v)
    {
        return run(broadcast<T, Elems>::run(a), v);
    }

    __aie_inline
    static vector_type run(const vector_type &v, const T &a)
    {
        return run(v, broadcast<T, Elems>::run(a));
    }

    __aie_inline
    static vector_type run(const T &a, const vector_type &v, bool sign)
    {
        return run(broadcast<T, Elems>::run(a), v, sign);
    }

    __aie_inline
    static vector_type run(const vector_type &v, const T &a, bool sign)
    {
        return run(v, broadcast<T, Elems>::run(a), sign);
    }
};

template <typename T, unsigned Elems, MaxMinOperation Op>
struct max_min_bits_impl_common
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v1, const vector_type &v2)
    {
        constexpr auto op = get_max_min_op<Op>();
        constexpr unsigned native_elems = native_vector_length_v<T>;

        vector_type ret;

        if constexpr (vector_type::bits() <= 512) {
            vector<T, native_elems> tmp;

            tmp = op(v1.template grow<native_elems>(), v2.template grow<native_elems>());

            ret = tmp.template extract<Elems>(0);
        }
        else {
            ret.template insert<native_elems>(0, max_min_bits_impl_common<T, Elems / 2, Op>::run(v1.template extract<Elems / 2>(0), v2.template extract<Elems / 2>(0)));
            ret.template insert<native_elems>(1, max_min_bits_impl_common<T, Elems / 2, Op>::run(v1.template extract<Elems / 2>(1), v2.template extract<Elems / 2>(1)));
        }

        return ret;
    }

    __aie_inline
    static vector_type run(const vector_type &v1, const vector_type &v2, bool sign)
    {
        constexpr auto op = get_max_min_op<Op>();
        constexpr unsigned native_elems = 512 / type_bits_v<T>;

        vector_type ret;

        if constexpr (vector_type::bits() <= 512) {
            vector<T, native_elems> tmp;

            if constexpr (vector_type::is_floating_point())
                tmp = op(v1.template grow<native_elems>(), v2.template grow<native_elems>());
            else
                tmp = op(v1.template grow<native_elems>(), v2.template grow<native_elems>(), sign);

            ret = tmp.template extract<Elems>(0);
        }
        else {
            ret.template insert<native_elems>(0, max_min_bits_impl_common<T, Elems / 2, Op>::run(v1.template extract<Elems / 2>(0), v2.template extract<Elems / 2>(0), sign));
            ret.template insert<native_elems>(1, max_min_bits_impl_common<T, Elems / 2, Op>::run(v1.template extract<Elems / 2>(1), v2.template extract<Elems / 2>(1), sign));
        }

        return ret;
    }

    __aie_inline
    static vector_type run(const T &a, const vector_type &v)
    {
        return run(broadcast<T, Elems>::run(a), v);
    }

    __aie_inline
    static vector_type run(const vector_type &v, const T &a)
    {
        return run(v, broadcast<T, Elems>::run(a));
    }

    __aie_inline
    static vector_type run(const T &a, const vector_type &v, bool sign)
    {
        return run(broadcast<T, Elems>::run(a), v, sign);
    }

    __aie_inline
    static vector_type run(const vector_type &v, const T &a, bool sign)
    {
        return run(v, broadcast<T, Elems>::run(a), sign);
    }
};

template <typename T, unsigned Elems, MaxMinOperation Op>
struct max_min_bits_impl<8, T, Elems, Op> : public max_min_bits_impl_common<T, Elems, Op> {};

template <typename T, unsigned Elems, MaxMinOperation Op>
struct max_min_bits_impl<16, T, Elems, Op> : public max_min_bits_impl_common<T, Elems, Op> {};

template <typename T, unsigned Elems, MaxMinOperation Op>
struct max_min_bits_impl<32, T, Elems, Op> : public max_min_bits_impl_common<T, Elems, Op> {};

template <unsigned Elems>
struct max_min_bits_impl<16, bfloat16, Elems, MaxMinOperation::MaxDiff>
{
    using T = bfloat16;
    using vector_type = vector<T, Elems>;

    static constexpr MaxMinOperation Op = MaxMinOperation::MaxDiff;

    __aie_inline
    static vector_type run(const vector_type &v1, const vector_type &v2)
    {
        vector_type ret;

        if constexpr (Elems <= 32) {
            vector<T, 32> tmp;
            const unsigned cmp = ::lt(v2.template grow<32>(), v1.template grow<32>());
            tmp = ::sel(zeros<T, 32>::run(), sub<T, 32>::run(v1.template grow<32>(), v2.template grow<32>()), cmp);

            ret = tmp.template extract<Elems>(0);
        }
        else if constexpr (Elems == 64) {
            ret.template insert<Elems / 2>(0, max_min_bits<16, T, Elems / 2, Op>::run(v1.template extract<Elems / 2>(0), v2.template extract<Elems / 2>(0)));
            ret.template insert<Elems / 2>(1, max_min_bits<16, T, Elems / 2, Op>::run(v1.template extract<Elems / 2>(1), v2.template extract<Elems / 2>(1)));
        }

        return ret;
    }

    __aie_inline
    static vector_type run(const vector_type &v1, const vector_type &v2, bool sign)
    {
        return run(v1, v2);
    }

    __aie_inline
    static vector_type run(const T &a, const vector_type &v)
    {
        return run(broadcast<T, Elems>::run(a), v);
    }

    __aie_inline
    static vector_type run(const vector_type &v, const T &a)
    {
        return run(v, broadcast<T, Elems>::run(a));
    }

    __aie_inline
    static vector_type run(const T &a, const vector_type &v, bool sign)
    {
        return run(broadcast<T, Elems>::run(a), v);
    }

    __aie_inline
    static vector_type run(const vector_type &v, const T &a, bool sign)
    {
        return run(v, broadcast<T, Elems>::run(a));
    }
};

#if __AIE_API_FP32_EMULATION__

template <unsigned Elems>
struct max_min_bits_impl<32, float, Elems, MaxMinOperation::MaxDiff>
{
    using           T = float;
    using vector_type = vector<T, Elems>;

    static constexpr MaxMinOperation Op = MaxMinOperation::MaxDiff;

    __aie_inline
    static vector_type run(const vector_type &v1, const vector_type &v2)
    {
        vector_type ret;

        if constexpr (Elems <= 16) {
            vector<T, 16> tmp;
            const unsigned cmp = ::lt(v2.template grow<16>(), v1.template grow<16>());
            tmp = ::sel(zeros<float, 16>::run(), sub<float, 16>::run(v1.template grow<16>(), v2.template grow<16>()), cmp);

            ret = tmp.template extract<Elems>(0);
        }
        else if constexpr (Elems == 32) {
            ret.template insert<Elems / 2>(0, max_min_bits<32, T, Elems / 2, Op>::run(v1.template extract<Elems / 2>(0), v2.template extract<Elems / 2>(0)));
            ret.template insert<Elems / 2>(1, max_min_bits<32, T, Elems / 2, Op>::run(v1.template extract<Elems / 2>(1), v2.template extract<Elems / 2>(1)));
        }

        return ret;
    }

    __aie_inline
    static vector_type run(const vector_type &v1, const vector_type &v2, bool sign)
    {
        return run(v1, v2);
    }

    __aie_inline
    static vector_type run(const T &a, const vector_type &v)
    {
        return run(broadcast<T, Elems>::run(a), v);
    }

    __aie_inline
    static vector_type run(const vector_type &v, const T &a)
    {
        return run(v, broadcast<T, Elems>::run(a));
    }

    __aie_inline
    static vector_type run(const T &a, const vector_type &v, bool sign)
    {
        return run(broadcast<T, Elems>::run(a), v);
    }

    __aie_inline
    static vector_type run(const vector_type &v, const T &a, bool sign)
    {
        return run(v, broadcast<T, Elems>::run(a));
    }
};

#endif

}

#endif
