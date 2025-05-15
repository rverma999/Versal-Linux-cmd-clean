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


#ifndef __AIE_API_AIE_DETAIL_BIT__HPP__
#define __AIE_API_AIE_DETAIL_BIT__HPP__

#include "vector.hpp"

namespace aie::detail {

enum class BitOp {
    And,
    Not,
    Or,
    Xor,
};

// TODO: implement element/vector, element_ref/vector variants

template <unsigned TypeBits, typename T, unsigned Elems, BitOp Op>
struct bit_bits_impl
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &v1, const vector_type &v2)
    {
        vector_type ret;

        for (unsigned i = 0; i < Elems; ++i) {
            if constexpr (Op == BitOp::And)
                ret[i] = v1[i] & v2[i];
            else if constexpr (Op == BitOp::Or)
                ret[i] = v1[i] | v2[i];
            else if constexpr (Op == BitOp::Xor)
                ret[i] = v1[i] ^ v2[i];
        }

        return ret;
    }


    static vector_type run(T a, const vector_type &v)
    {
        vector_type ret;

        for (unsigned i = 0; i < Elems; ++i) {
            if constexpr (Op == BitOp::And)
                ret[i] = a & v[i];
            else if constexpr (Op == BitOp::Or)
                ret[i] = a | v[i];
            else if constexpr (Op == BitOp::Xor)
                ret[i] = a ^ v[i];
        }

        return ret;
    }

    static vector_type run(const vector_type &v, T a)
    {
        vector_type ret;

        for (unsigned i = 0; i < Elems; ++i) {
            if constexpr (Op == BitOp::And)
                ret[i] = v[i] & a;
            else if constexpr (Op == BitOp::Or)
                ret[i] = v[i] | a;
            else if constexpr (Op == BitOp::Xor)
                ret[i] = v[i] ^ a;
        }

        return ret;
    }

    static vector_type run(const vector_type &v)
    {
        vector_type ret;

        for (unsigned i = 0; i < Elems; ++i) {
            if constexpr (Op == BitOp::Not)
                ret[i] = ~v[i];
        }

        return ret;
    }
#endif
};

template <unsigned TypeBits, typename T, unsigned Elems, BitOp Op>
struct bit_bits
{
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &v1, const vector_type &v2)
    {
        return bit_bits_impl<TypeBits, T, Elems, Op>::run(v1, v2);
    }

    template <unsigned Elems2>
    static vector_type run(vector_elem_const_ref<T, Elems2> a, const vector_type &v)
    {
        return bit_bits_impl<TypeBits, T, Elems, Op>::run(a, v);
    }

    template <unsigned Elems2>
    static vector_type run(const vector_type &v, vector_elem_const_ref<T, Elems2> a)
    {
        return bit_bits_impl<TypeBits, T, Elems, Op>::run(v, a);
    }

    static vector_type run(const T &a, const vector_type &v)
    {
        return bit_bits_impl<TypeBits, T, Elems, Op>::run(a, v);
    }

    static vector_type run(const vector_type &v, const T &a)
    {
        return bit_bits_impl<TypeBits, T, Elems, Op>::run(v, a);
    }

    static vector_type run(const vector_type &v)
    {
        return bit_bits_impl<TypeBits, T, Elems, Op>::run(v);
    }
};

template <typename T, unsigned Elems, BitOp Op>
using bit = bit_bits<type_bits_v<T>, T, Elems, Op>;

}

#if __AIE_ARCH__ == 20

#include "aie2/bit.hpp"

#endif

#endif
