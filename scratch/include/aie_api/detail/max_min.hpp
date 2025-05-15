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

#ifndef __AIE_API_DETAIL_MAX_MIN__HPP__
#define __AIE_API_DETAIL_MAX_MIN__HPP__

#include <algorithm>

#include "vector.hpp"
#include "../mask.hpp"

namespace aie::detail {

enum class MaxMinOperation
{
    Max,
    Min,
    MaxCmp,
    MinCmp,
    MaxDiff,
};

template <unsigned TypeBits, typename T, unsigned Elems, MaxMinOperation Op>
struct max_min_bits_impl
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &v1, const vector_type &v2)
    {
        vector_type ret;

        for (unsigned i = 0; i < Elems; ++i) {
            if constexpr (Op == MaxMinOperation::Max || Op == MaxMinOperation::MaxCmp)
                ret[i] = std::max(v1[i], v2[i]);
            else if constexpr (Op == MaxMinOperation::Min || Op == MaxMinOperation::MinCmp)
                ret[i] = std::min(v1[i], v2[i]);
            else if constexpr (Op == MaxMinOperation::MaxDiff)
                ret[i] = std::max(v1[i] - v2[i], 0);
        }

        return ret;
    }

    static vector_type run(T a, const vector_type &v)
    {
        vector_type ret;

        for (unsigned i = 0; i < Elems; ++i) {
            if constexpr (Op == MaxMinOperation::Max)
                ret[i] = std::max(a, v[i]);
            else if constexpr (Op == MaxMinOperation::Min)
                ret[i] = std::min(a, v[i]);
            else if constexpr (Op == MaxMinOperation::MaxDiff)
                ret[i] = std::max(a - v[i], 0);
        }

        return ret;
    }
#endif
};

template <unsigned TypeBits, typename T, unsigned Elems, MaxMinOperation Op>
struct max_min_cmp_bits_impl
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    using vector_type = vector<T, Elems>;

    static auto run(const vector_type &v1, const vector_type &v2)
    {
        vector_type ret;
        mask<Elems> m;

        for (unsigned i = 0; i < Elems; ++i) {
            if constexpr (Op == MaxMinOperation::MaxCmp) {
                if (v1[i] < v2[i]) {
                    ret[i] = v2[i];
                    m.set(i);
                }
                else {
                    ret[i] = v1[i];
                }
            }
            else if constexpr (Op == MaxMinOperation::MinCmp) {
                if (v1[i] < v2[i]) {
                    ret[i] = v1[i];
                }
                else {
                    ret[i] = v2[i];
                    m.set(i);
                }
            }
        }

        return std::make_tuple(ret, m);
    }
#endif
};

template <unsigned TypeBits, typename T, unsigned Elems, MaxMinOperation Op>
struct max_min_bits_reduce_impl
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    using vector_type = vector<T, Elems>;

    static T run(const vector_type &v)
    {
        T ret = v[0];

        for (unsigned i = 1; i < Elems; ++i) {
            if constexpr (Op == MaxMinOperation::Max)
                ret = std::max((T)v[i], ret);
            else if constexpr (Op == MaxMinOperation::Min)
                ret = std::min((T)v[i], ret);
        }

        return ret;
    }
#endif
};

template <unsigned TypeBits, typename T, unsigned Elems, MaxMinOperation Op>
struct max_min_bits
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v1, const vector_type &v2)
    {
        return max_min_bits_impl<TypeBits, T, Elems, Op>::run(v1, v2);
    }

    __aie_inline
    static vector_type run(const T &a, const vector_type &v)
    {
        return max_min_bits_impl<TypeBits, T, Elems, Op>::run(a, v);
    }

    __aie_inline
    static vector_type run(const vector_type &v, const T &a)
    {
        return max_min_bits_impl<TypeBits, T, Elems, Op>::run(v, a);
    }

    template <unsigned Elems2>
    __aie_inline
    static vector_type run(vector_elem_const_ref<T, Elems2> a, const vector_type &v)
    {
        return max_min_bits_impl<TypeBits, T, Elems, Op>::run(a, v);
    }

    template <unsigned Elems2>
    __aie_inline
    static vector_type run(const vector_type &v, vector_elem_const_ref<T, Elems2> a)
    {
        return max_min_bits_impl<TypeBits, T, Elems, Op>::run(v, a);
    }

    __aie_inline
    static vector_type run(const vector_type &v1, const vector_type &v2, bool sign)
    {
        return max_min_bits_impl<TypeBits, T, Elems, Op>::run(v1, v2, sign);
    }

    __aie_inline
    static vector_type run(const T &a, const vector_type &v, bool sign)
    {
        return max_min_bits_impl<TypeBits, T, Elems, Op>::run(a, v, sign);
    }

    __aie_inline
    static vector_type run(const vector_type &v, const T &a, bool sign)
    {
        return max_min_bits_impl<TypeBits, T, Elems, Op>::run(v, a, sign);
    }

    template <unsigned Elems2>
    __aie_inline
    static vector_type run(vector_elem_const_ref<T, Elems2> a, const vector_type &v, bool sign)
    {
        return max_min_bits_impl<TypeBits, T, Elems, Op>::run(a, v, sign);
    }

    template <unsigned Elems2>
    __aie_inline
    static vector_type run(const vector_type &v, vector_elem_const_ref<T, Elems2> a, bool sign)
    {
        return max_min_bits_impl<TypeBits, T, Elems, Op>::run(v, a, sign);
    }
};

template <unsigned TypeBits, typename T, unsigned Elems, MaxMinOperation Op>
struct max_min_cmp_bits
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static auto run(const vector_type &v1, const vector_type &v2)
    {
        return max_min_cmp_bits_impl<TypeBits, T, Elems, Op>::run(v1, v2);
    }
};

template <unsigned TypeBits, typename T, unsigned Elems, MaxMinOperation Op>
struct max_min_reduce_bits
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static T run(const vector_type &v)
    {
        return max_min_bits_reduce_impl<TypeBits, T, Elems, Op>::run(v);
    }
};

template <typename T, unsigned Elems>
using max = max_min_bits<type_bits_v<T>, T, Elems, MaxMinOperation::Max>;

template <typename T, unsigned Elems>
using min = max_min_bits<type_bits_v<T>, T, Elems, MaxMinOperation::Min>;

template <typename T, unsigned Elems>
using max_cmp = max_min_cmp_bits<type_bits_v<T>, T, Elems, MaxMinOperation::MaxCmp>;

template <typename T, unsigned Elems>
using min_cmp = max_min_cmp_bits<type_bits_v<T>, T, Elems, MaxMinOperation::MinCmp>;

template <typename T, unsigned Elems>
using maxdiff = max_min_bits<type_bits_v<T>, T, Elems, MaxMinOperation::MaxDiff>;

template <typename T, unsigned Elems>
using max_reduce = max_min_reduce_bits<type_bits_v<T>, T, Elems, MaxMinOperation::Max>;

template <typename T, unsigned Elems>
using min_reduce = max_min_reduce_bits<type_bits_v<T>, T, Elems, MaxMinOperation::Min>;

}

#if __AIE_ARCH__ == 10

#include "aie1/max_min.hpp"
#include "aie1/max_min_cmp.hpp"
#include "aie1/max_min_reduce.hpp"

#elif __AIE_ARCH__ == 20

#include "aie2/max_min.hpp"
#include "aie2/max_min_cmp.hpp"
#include "aie2/max_min_reduce.hpp"

#endif

#endif
