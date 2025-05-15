// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
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

#ifndef __AIE_API_DETAIL_FILTER__HPP__
#define __AIE_API_DETAIL_FILTER__HPP__

#include "vector.hpp"

namespace aie::detail {

// Tag type used to disambiguate between the types of filtering when
// constructing a FilterMode object.
struct filter_odd_tag {};
struct filter_even_tag {};

template <unsigned TypeBits, unsigned Elems>
class filter_mode;

enum class FilterOp {
    Odd,
    Even,
    Dynamic
};

template <unsigned TypeBits, typename T, unsigned Elems, FilterOp Op>
struct filter_bits_impl
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    using        vector_type = vector<T, Elems>;
    using return_vector_type = vector<T, Elems / 2>;

    // TODO: CRVO-9533 default scalar implementation for dynamic filters
    static_assert(Op != FilterOp::Dynamic, "Not implemented");

    static return_vector_type run(const vector_type &v, unsigned n)
    {
        return_vector_type ret;

        const unsigned start = [=]() constexpr {
            if      constexpr (Op == FilterOp::Odd)
                return n;
            else if constexpr (Op == FilterOp::Even)
                return 0;
        }();

        unsigned out = 0;

        for (unsigned i = start; i < Elems; i += n) {
            for (unsigned j = 0; j < n; ++j)
                ret[out++] = v[i++];
        }

        return ret;
    }
#endif
};

template <unsigned TypeBits, typename T, unsigned Elems, FilterOp Op>
struct filter_bits
{
    using        vector_type = vector<T, Elems>;
    using return_vector_type = vector<T, Elems / 2>;

    static return_vector_type run(const vector_type &v, unsigned n)
    {
        return filter_bits_impl<TypeBits, T, Elems, Op>::run(v, n);
    }
};

template <unsigned TypeBits, typename T, unsigned Elems>
struct filter_bits<TypeBits, T, Elems, FilterOp::Dynamic>
{
    using        vector_type = vector<T, Elems>;
    using return_vector_type = vector<T, Elems / 2>;

    static return_vector_type run(const vector_type &v, const filter_mode<TypeBits, Elems> &mode)
    {
        return filter_bits_impl<TypeBits, T, Elems, FilterOp::Dynamic>::run(v, mode);
    }
};

template <typename T, unsigned Elems, FilterOp Op>
using filter = filter_bits<type_bits_v<T>, T, Elems, Op>;

}

#if __AIE_ARCH__ == 10

#include "aie1/filter.hpp"

#elif __AIE_ARCH__ == 20

#include "aie2/filter.hpp"

#endif

#endif
