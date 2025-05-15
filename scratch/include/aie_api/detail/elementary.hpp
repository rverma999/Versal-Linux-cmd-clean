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


#ifndef __AIE_API_DETAIL_ELEMENTARY__HPP__
#define __AIE_API_DETAIL_ELEMENTARY__HPP__

#include <cmath>

#include "vector.hpp"

namespace aie::detail {

enum class ElementaryOp {
    Sqrt,
    Inv,
    InvSqrt,
    SinCos,
    SinCosComplex,
    Sin,
    Cos,
    Fix2Float,
    Float2Fix,
    Tanh,
    Exp2
};

template <ElementaryOp Op, unsigned TypeBits, typename TR, typename T>
struct elementary_bits_impl
{
    static TR run(const T &a, int shift = 0)
    {
        if constexpr (Op == ElementaryOp::Sqrt)
            return std::sqrt(a);
        else if constexpr (Op == ElementaryOp::Inv)
            return T(1)/a;
        else if constexpr (Op == ElementaryOp::InvSqrt)
            return T(1)/std::sqrt(a);
        else if constexpr (Op == ElementaryOp::Fix2Float)
            return TR(a >> shift);
        else if constexpr (Op == ElementaryOp::Float2Fix)
            return TR(a) << shift;
        else
            UNREACHABLE_MSG("Unsupported operation");
        // TODO: CRVO-7950: add support for tanh/exp2 emulation once support is added to libm.a
    }
};

template <ElementaryOp Op, unsigned TypeBits, typename TR, typename T, unsigned N>
struct elementary_vector_bits_impl
{
    using vector_type     = vector<T, N>;
    using vector_ret_type = vector<TR, N>;

    static auto run(const vector_type &v, int shift = 0)
    {
        vector_ret_type ret;

        // Ensure that each subvector in a loop is at least 128b
        constexpr unsigned bits = std::min(vector_type::bits(), vector_ret_type::bits());

        // AIE1 supports element insert/extract for 128b only. Later architectures support it for 512b.
        constexpr unsigned native_insert_bits = (__AIE_ARCH__ == 10)? 128 : 512;
        constexpr unsigned num_loops = bits < native_insert_bits? 1 :
                                                                  bits / native_insert_bits;

        constexpr unsigned elems_per_loop = N / num_loops;

        // Apply the elementary operation to each element. Create as many loops as subvectors that can be indexed
        // efficiently.
        if constexpr (bits > native_insert_bits) {
            utils::unroll_times<num_loops>([&](auto idx) __aie_inline {
                ret.insert(idx, elementary_vector_bits_impl<Op, TypeBits, TR, T, elems_per_loop>::run(v.template extract<elems_per_loop>(idx)));
            });
        }
        else {
            for (unsigned i = 0; i < N; ++i) {
                const T val = v[i];
                TR out_val;

                if constexpr (is_complex_v<T>) {
                    if constexpr (is_floating_point_v<T>) {
                        out_val.real = elementary_bits_impl<Op, 32, TR, T>::run(val.real);
                        out_val.imag = elementary_bits_impl<Op, 32, TR, T>::run(val.imag);
                    }
                    else {
                        out_val.real = elementary_bits_impl<Op, 32, TR, uint32>::run(uint32(val.real));
                        out_val.imag = elementary_bits_impl<Op, 32, TR, uint32>::run(uint32(val.imag));
                    }
                }
                else {
                    if constexpr (is_floating_point_v<T>)
                        out_val = elementary_bits_impl<Op, 32, TR, T>::run(val);
                    else
                        out_val = elementary_bits_impl<Op, 32, TR, uint32>::run(uint32(val));
                }

                ret[i] = out_val;
            }
        }

        return ret;
    }
};

template <ElementaryOp Op, unsigned TypeBits, typename TR, typename T>
struct elementary_bits
{
    __aie_inline
    static auto run(const T &a, int shift = 0)
    {
        return elementary_bits_impl<Op, TypeBits, TR, T>::run(a, shift);
    }
};

template <ElementaryOp Op, unsigned TypeBits, typename TR, typename T, unsigned N>
struct elementary_vector_bits
{
    using vector_type = vector<T, N>;

    __aie_inline
    static auto run(const vector_type &v, int shift = 0)
    {
        return elementary_vector_bits_impl<Op, TypeBits, TR, T, N>::run(v, shift);
    }
};

template <ElementaryOp Op, typename TR, typename T>
using elementary        = elementary_bits<Op, type_bits_v<T>, TR, T>;

template <ElementaryOp Op, typename TR, typename T, unsigned N>
using elementary_vector = elementary_vector_bits<Op, type_bits_v<T>, TR, T, N>;

}

#if __AIE_ARCH__ == 10

#include "aie1/elementary.hpp"

#elif __AIE_ARCH__ == 20

#include "aie2/elementary.hpp"

#endif

#endif
