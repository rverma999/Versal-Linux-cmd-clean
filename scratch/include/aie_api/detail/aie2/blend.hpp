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

#ifndef __AIE_API_DETAIL_AIE2_BLEND__HPP__
#define __AIE_API_DETAIL_AIE2_BLEND__HPP__

#include "../vector.hpp"

namespace aie::detail {

template <typename T, unsigned Elems>
struct select_bits_impl<4, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &v1, const vector_type &v2, const mask<Elems> &m)
    {
         using next_type = utils::get_next_integer_type_t<T>;

         if constexpr (Elems < 256) {
             return select_bits_impl<8, next_type, Elems>::run(v1.unpack(), v2.unpack(), m).pack();
         }
         else {
            vector_type ret;

            auto mask1 = m.template get_submask<128>(0);
            auto mask2 = m.template get_submask<128>(1);

            vector<T, Elems / 2> tmp1 = select_bits_impl<8, next_type, Elems / 2>::run(v1.template extract<Elems / 2>(0).unpack(),
                                                                                       v2.template extract<Elems / 2>(0).unpack(), mask1).pack();
            ret.insert(0, tmp1);
            vector<T, Elems / 2> tmp2 = select_bits_impl<8, next_type, Elems / 2>::run(v1.template extract<Elems / 2>(1).unpack(),
                                                                                       v2.template extract<Elems / 2>(1).unpack(), mask2).pack();
            ret.insert(1, tmp2);

            return ret;
         }
    }

    template <unsigned Elems2>
    static vector_type run(vector_elem_const_ref<T, Elems2> a, const vector_type &v, const mask<Elems> &m)
    {
        return run((T)a, v, m);
    }

    template <unsigned Elems2>
    static vector_type run(const vector_type &v, vector_elem_const_ref<T, Elems2> a, const mask<Elems> &m)
    {
        return run(v, (T)a, m);
    }

    static vector_type run(const T &a, const vector_type &v, const mask<Elems> &m)
    {
        return run(broadcast<T, Elems>::run(a), v, m);
    }

    static vector_type run(const vector_type &v, const T &a, const mask<Elems> &m)
    {
        return run(v, broadcast<T, Elems>::run(a), m);
    }

    static vector_type run(T a, T b, const mask<Elems> &m)
    {
        return run(broadcast<T, Elems>::run(a), broadcast<T, Elems>::run(b), m);
    }
};

template <typename T, unsigned Elems>
struct select_bits_impl<8, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &v1, const vector_type &v2, const mask<Elems> &m)
    {
        if constexpr (Elems <= 32) {
            const vector<T, 64> tmp = ::sel(v1.template grow<64>(), v2.template grow<64>(), uint64_t(m.to_uint32(0)));

            return tmp.template extract<Elems>(0);
        }
        else if constexpr (Elems == 64) {
            const vector_type ret = ::sel(v1, v2, m.to_uint64(0));

            return ret;

        }
        else if constexpr (Elems == 128) {
            vector_type ret;

            vector<T, 64> tmp1 = ::sel(v1.template extract<64>(0), v2.template extract<64>(0), m.to_uint64(0));
            ret.insert(0, tmp1);
            vector<T, 64> tmp2 = ::sel(v1.template extract<64>(1), v2.template extract<64>(1), m.to_uint64(1));
            ret.insert(1, tmp2);

            return ret;
        }
    }

    template <unsigned Elems2>
    static vector_type run(vector_elem_const_ref<T, Elems2> a, const vector_type &v, const mask<Elems> &m)
    {
        return run((T)a, v, m);
    }

    template <unsigned Elems2>
    static vector_type run(const vector_type &v, vector_elem_const_ref<T, Elems2> a, const mask<Elems> &m)
    {
        return run(v, (T)a, m);
    }

    static vector_type run(const T &a, const vector_type &v, const mask<Elems> &m)
    {
        return run(broadcast<T, Elems>::run(a), v, m);
    }

    static vector_type run(const vector_type &v, const T &a, const mask<Elems> &m)
    {
        return run(v, broadcast<T, Elems>::run(a), m);
    }

    static vector_type run(T a, T b, const mask<Elems> &m)
    {
        return run(broadcast<T, Elems>::run(a), broadcast<T, Elems>::run(b), m);
    }
};

template <typename T, unsigned Elems>
struct select_bits_impl<16, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &v1, const vector_type &v2, const mask<Elems> &m)
    {
        if constexpr (Elems <= 16) {
            const vector<T, 32> tmp = ::sel(v1.template grow<32>(), v2.template grow<32>(), m.to_uint32(0));

            return tmp.template extract<Elems>(0);
        }
        else if constexpr (Elems == 32) {
            const vector_type ret = ::sel(v1, v2, m.to_uint32(0));

            return ret;

        }
        else if constexpr (Elems == 64) {
            vector_type ret;
            vector<T, 32> tmp1, tmp2;

            tmp1 = ::sel(v1.template extract<32>(0), v2.template extract<32>(0), m.to_uint32(0));
            ret.insert(0, tmp1);
            tmp2 = ::sel(v1.template extract<32>(1), v2.template extract<32>(1), m.to_uint32(1));
            ret.insert(1, tmp2);

            return ret;
        }
    }

    template <unsigned Elems2>
    static vector_type run(vector_elem_const_ref<T, Elems2> a, const vector_type &v, const mask<Elems> &m)
    {
        return run((T)a, v, m);
    }

    template <unsigned Elems2>
    static vector_type run(const vector_type &v, vector_elem_const_ref<T, Elems2> a, const mask<Elems> &m)
    {
        return run(v, (T)a, m);
    }

    static vector_type run(const T &a, const vector_type &v, const mask<Elems> &m)
    {
        return run(broadcast<T, Elems>::run(a), v, m);
    }

    static vector_type run(const vector_type &v, const T &a, const mask<Elems> &m)
    {
        return run(v, broadcast<T, Elems>::run(a), m);
    }

    static vector_type run(T a, T b, const mask<Elems> &m)
    {
        return run(broadcast<T, Elems>::run(a), broadcast<T, Elems>::run(b), m);
    }
};

template <typename T, unsigned Elems>
struct select_bits_impl<32, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &v1, const vector_type &v2, const mask<Elems> &m)
    {
        if constexpr (Elems <= 8) {
            const vector<T, 16> tmp = ::sel(v1.template grow<16>(), v2.template grow<16>(), m.to_uint32(0));

            return tmp.template extract<Elems>(0);
        }
        else if constexpr (Elems == 16) {
            const vector_type ret = ::sel(v1, v2, m.to_uint32(0));

            return ret;

        }
        else if constexpr (Elems == 32) {
            vector_type ret;
            vector<T, 16> tmp1, tmp2;

            tmp1 = ::sel(v1.template extract<16>(0), v2.template extract<16>(0), m.to_uint32(0));
            ret.insert(0, tmp1);
            tmp2 = ::sel(v1.template extract<16>(1), v2.template extract<16>(1), m.to_uint32(0) >> 16);
            ret.insert(1, tmp2);

            return ret;
        }
    }

    template <unsigned Elems2>
    static vector_type run(vector_elem_const_ref<T, Elems2> a, const vector_type &v, const mask<Elems> &m)
    {
        return run((T)a, v, m);
    }

    template <unsigned Elems2>
    static vector_type run(const vector_type &v, vector_elem_const_ref<T, Elems2> a, const mask<Elems> &m)
    {
        return run(v, (T)a, m);
    }

    static vector_type run(const T &a, const vector_type &v, const mask<Elems> &m)
    {
        return run(broadcast<T, Elems>::run(a), v, m);
    }

    static vector_type run(const vector_type &v, const T &a, const mask<Elems> &m)
    {
        return run(v, broadcast<T, Elems>::run(a), m);
    }

    static vector_type run(T a, T b, const mask<Elems> &m)
    {
        return run(broadcast<T, Elems>::run(a), broadcast<T, Elems>::run(b), m);
    }
};

template <typename T, unsigned Elems>
struct select_bits_impl<64, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &v1, const vector_type &v2, const mask<Elems> &m)
    {
        if constexpr (Elems <= 4) {
            const vector<T, 8> tmp = ::sel(v1.template grow<8>(), v2.template grow<8>(), m.to_uint32(0));

            return tmp.template extract<Elems>(0);
        }
        else if constexpr (Elems == 8) {
            const vector_type ret = ::sel(v1, v2, m.to_uint32(0));

            return ret;
        }
        else if constexpr (Elems == 16) {
            vector_type ret;
            vector<T, 8> tmp1, tmp2;

            tmp1 = ::sel(v1.template extract<8>(0), v2.template extract<8>(0), m.to_uint32(0));
            ret.insert(0, tmp1);
            tmp2 = ::sel(v1.template extract<8>(1), v2.template extract<8>(1), m.to_uint32(0) >> 8);
            ret.insert(1, tmp2);

            return ret;
        }
    }

    template <unsigned Elems2>
    static vector_type run(vector_elem_const_ref<T, Elems2> a, const vector_type &v, const mask<Elems> &m)
    {
        return run((T)a, v, m);
    }

    template <unsigned Elems2>
    static vector_type run(const vector_type &v, vector_elem_const_ref<T, Elems2> a, const mask<Elems> &m)
    {
        return run(v, (T)a, m);
    }

    static vector_type run(const T &a, const vector_type &v, const mask<Elems> &m)
    {
        return run(broadcast<T, Elems>::run(a), v, m);
    }

    static vector_type run(const vector_type &v, const T &a, const mask<Elems> &m)
    {
        return run(v, broadcast<T, Elems>::run(a), m);
    }

    static vector_type run(T a, T b, const mask<Elems> &m)
    {
        return run(broadcast<T, Elems>::run(a), broadcast<T, Elems>::run(b), m);
    }
};

}

#endif
