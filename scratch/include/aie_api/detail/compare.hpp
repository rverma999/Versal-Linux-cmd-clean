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

#ifndef __AIE_API_DETAIL_COMPARE__HPP__
#define __AIE_API_DETAIL_COMPARE__HPP__

#include "../mask.hpp"
#include "vector.hpp"

namespace aie::detail {

enum class CmpOp
{
    LT,
    GE,
    EQ,
    NEQ,
    LE,
    GT
};

template <CmpOp op>
constexpr bool is_compare_commutative() {
    return op == CmpOp::EQ || op == CmpOp::NEQ;
}

template <CmpOp op>
constexpr CmpOp with_swapped_operands() {
    if constexpr (op == CmpOp::LT)
        return CmpOp::GT;
    else if constexpr (op == CmpOp::GE)
        return CmpOp::LE;
    else if constexpr (op == CmpOp::LE)
        return CmpOp::GE;
    else if constexpr (op == CmpOp::GT)
        return CmpOp::LT;
    else if (is_compare_commutative<op>())
        return op;
}

template <typename T, unsigned Elems>
struct contains
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    using vector_type = vector<T, Elems>;

    static bool run(T a, const vector_type &v)
    {
        for (unsigned i = 0; i < Elems; ++i) {
            if (v[i] == a)
                return true;
        }

        return false;
    }
#endif
};

template <unsigned TypeBits, typename T, unsigned Elems>
struct equal_bits_impl
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    using vector_type = vector<T, Elems>;

    static bool run(const vector_type &v1, const vector_type &v2)
    {
        for (unsigned i = 0; i < Elems; ++i) {
            if (v1[i] != v2[i])
                return false;
        }

        return true;
    }

    static bool run(T a, const vector_type &v)
    {
        for (unsigned i = 0; i < Elems; ++i) {
            if (a != v[i])
                return false;
        }

        return true;
    }


    static bool run(const vector_type &v, T a)
    {
        for (unsigned i = 0; i < Elems; ++i) {
            if (v[i] != a)
                return false;
        }

        return true;
    }
#endif
};

template <CmpOp Op, unsigned TypeBits, typename T, unsigned Elems>
struct cmp_bits_impl
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    using vector_type = vector<T, Elems>;
    using   mask_type = mask<Elems>;

    static constexpr auto get_op()
    {
        if      constexpr (Op == CmpOp::LT)  return [](auto a, auto b) { return a  < b;  };
        else if constexpr (Op == CmpOp::GE)  return [](auto a, auto b) { return a >= b; };
        else if constexpr (Op == CmpOp::EQ)  return [](auto a, auto b) { return a == b; };
        else if constexpr (Op == CmpOp::NEQ) return [](auto a, auto b) { return a != b; };
    }

    static mask_type run(const vector_type &v1, const vector_type &v2)
    {
        constexpr auto op = get_op();
        mask_type ret;

        for (unsigned i = 0; i < Elems; ++i) {
            if (op(v1[i], v2[i]))
                ret.set(i);
        }

        return ret;
    }

    static mask_type run(T a, const vector_type &v)
    {
        constexpr auto op = get_op();
        mask_type ret;

        for (unsigned i = 0; i < Elems; ++i) {
            if (op(v[i], a))
                ret.set(i);
        }

        return ret;
    }

    static mask_type run(const vector_type &v, T a)
    {
        constexpr auto op = get_op();
        mask_type ret;

        for (unsigned i = 0; i < Elems; ++i) {
            if (a, op(v[i]))
                ret.set(i);
        }

        return ret;
    }
#endif
};

// Default implementation compares against a vector of zeros.
// Specializations can take advantage of hardware support for comparisons against zero.
template <CmpOp Op, unsigned TypeBits, typename T, unsigned Elems>
struct cmp_zero_bits_impl
{
    using vector_type = vector<T, Elems>;
    using   mask_type = mask<Elems>;

    static mask_type run(const vector_type &v)
    {
        return cmp_bits_impl<Op, TypeBits, T, Elems>::run(v, zeros<T, Elems>::run());
    }
};

template <CmpOp Op, typename T, unsigned Elems>
struct cmp_impl
{
    using vector_type = vector<T, Elems>;
    using mask_type = mask<Elems>;

    __aie_inline
    static mask_type run(const vector_type &v1, const vector_type &v2)
    {
        return cmp_bits_impl<Op, type_bits_v<T>, T, Elems>::run(v1, v2);
    }

    __aie_inline
    static mask_type run(const T &a, const vector_type &v)
    {
#if __AIE_ARCH__ == 20
        // zero-comparison assumes zero is on the right hand side,
        // so we need to replace the compare operation with an equivalent
        if (chess_manifest(a == scalar_zero())) {
            constexpr CmpOp equivalent = with_swapped_operands<Op>();
            return cmp_zero_bits_impl<equivalent, type_bits_v<T>, T, Elems>::run(v);
        }
#endif

        return cmp_bits_impl<Op, type_bits_v<T>, T, Elems>::run(a, v);
    }

    __aie_inline
    static mask_type run(const vector_type &v, const T &a)
    {
#if __AIE_ARCH__ == 20
        if (chess_manifest(a == scalar_zero()))
            return cmp_zero_bits_impl<Op, type_bits_v<T>, T, Elems>::run(v);
#endif

        return cmp_bits_impl<Op, type_bits_v<T>, T, Elems>::run(v, a);
    }

    template <unsigned Elems2>
    __aie_inline
    static mask_type run(vector_elem_const_ref<T, Elems2> a, const vector_type &v)
    {
#if __AIE_ARCH__ == 20
        // zero-comparison assumes zero is on the right hand side,
        // so we need to replace the compare operation with an equivalent
        if (chess_manifest(a == scalar_zero())) {
            constexpr CmpOp equivalent = with_swapped_operands<Op>();
            return cmp_zero_bits_impl<equivalent, type_bits_v<T>, T, Elems>::run(v);
        }
#endif

        return cmp_bits_impl<Op, type_bits_v<T>, T, Elems>::run(a, v);
    }

    template <unsigned Elems2>
    __aie_inline
    static mask_type run(const vector_type &v, vector_elem_const_ref<T, Elems2> a)
    {
#if __AIE_ARCH__ == 20
        if (chess_manifest(a == scalar_zero()))
            return cmp_zero_bits_impl<Op, type_bits_v<T>, T, Elems>::run(v);
#endif

        return cmp_bits_impl<Op, type_bits_v<T>, T, Elems>::run(v, a);
    }

    static constexpr T scalar_zero()
    {
        if constexpr (is_complex_v<T>)
            return T(0, 0);
        else
            return T(0);
    }
};

template <typename T, unsigned Elems>
struct equal
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static bool run(const vector_type &v1, const vector_type &v2)
    {
        return equal_bits_impl<type_bits_v<T>, T, Elems>::run(v1, v2);
    }

    __aie_inline
    static bool run(const T &a, const vector_type &v)
    {
        return equal_bits_impl<type_bits_v<T>, T, Elems>::run(a, v);
    }

    template <unsigned Elems2>
    __aie_inline
    static bool run(vector_elem_const_ref<T, Elems2> a, const vector_type &v)
    {
        return equal_bits_impl<type_bits_v<T>, T, Elems>::run(a, v);
    }

    __aie_inline
    static bool run(const vector_type &v, const T &a)
    {
        return equal_bits_impl<type_bits_v<T>, T, Elems>::run(v, a);
    }

    template <unsigned Elems2>
    __aie_inline
    static bool run(const vector_type &v, vector_elem_const_ref<T, Elems2> a)
    {
        return equal_bits_impl<type_bits_v<T>, T, Elems>::run(v, a);
    }
};

template <typename T, unsigned Elems>
struct not_equal
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static bool run(const vector_type &v1, const vector_type &v2)
    {
        return !equal<T, Elems>::run(v1, v2);
    }

    __aie_inline
    static bool run(const T &a, const vector_type &v)
    {
        return !equal<T, Elems>::run(a, v);
    }

    template <unsigned Elems2>
    __aie_inline
    static bool run(vector_elem_const_ref<T, Elems2> a, const vector_type &v)
    {
        return !equal<T, Elems>::run(a, v);
    }

    __aie_inline
    static bool run(const vector_type &v, const T &a)
    {
        return !equal<T, Elems>::run(v, a);
    }

    template <unsigned Elems2>
    __aie_inline
    static bool run(const vector_type &v, vector_elem_const_ref<T, Elems2> a)
    {
        return !equal<T, Elems>::run(v, a);
    }
};

template <typename T, unsigned Elems>
using lt = cmp_impl<CmpOp::LT, T, Elems>;

template <typename T, unsigned Elems>
using ge = cmp_impl<CmpOp::GE, T, Elems>;

template <typename T, unsigned Elems>
using eq = cmp_impl<CmpOp::EQ, T, Elems>;

template <typename T, unsigned Elems>
using neq = cmp_impl<CmpOp::NEQ, T, Elems>;

}

#if __AIE_ARCH__ == 10

#include "aie1/compare.hpp"

#elif __AIE_ARCH__ == 20

#include "aie2/compare.hpp"

#endif

#endif
