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

#ifndef __AIE_API_DETAIL_AIE2_CONJ__HPP__
#define __AIE_API_DETAIL_AIE2_CONJ__HPP__

namespace aie::detail {

template <unsigned TypeBits, typename T, unsigned Elems>
struct conj_bits_impl_common
{
    using vector_type = vector<T, Elems>;
    using component_type = utils::get_complex_component_type_t<T>;

    static vector_type run(const vector_type &v)
    {
        // Cast the input vector to a vector of the underlying component type
        // containing twice as many elements. ::addsub is used to add the real
        // components to, and subtract the imaginary components from, the zero
        // vector. The result is cast back to the input type to return the
        // conjugate.
        //
        // Example:
        //   input                   [a1 + b1i, a2 + b2i, ... aN + bNi]
        //   cast to component type  [a1 , b1 , a2 , b2 , ... aN , bN ]
        //   addsub mask              +    -    +    -        +    -
        //   zero                    [0  , 0  , 0  , 0  , ... 0  , 0  ]
        //   addsub result           [a1 ,-b1 , a2 ,-b2 , ... aN ,-bN ]
        //   cast back to input type [a1 - b1i, a2 - b2i, ... aN - bNi]
        constexpr unsigned elems_per_vector = 512 / TypeBits;
        constexpr unsigned num_components   = 2 * elems_per_vector;
        constexpr unsigned num_it           = Elems < elems_per_vector? 1 : Elems / elems_per_vector;

        const vector zero = zeros<component_type, num_components>::run();
        const auto values = v.template cast_to<component_type>();

        vector_type ret;

        utils::unroll_times<num_it>([&](auto idx) __aie_inline {
            vector<component_type, num_components> tmp = ::addsub(zero, values.template grow_extract<num_components>(idx), 0xaaaaaaaa);

            ret.insert(idx, tmp.template cast_to<T>().template extract<(Elems < elems_per_vector)? Elems : elems_per_vector>(0));
        });

        return ret;
    }
};

template <unsigned Elems> struct conj_bits_impl<32, cint16, Elems> : public conj_bits_impl_common<32, cint16, Elems> {};
template <unsigned Elems> struct conj_bits_impl<64, cint32, Elems> : public conj_bits_impl_common<64, cint32, Elems> {};

}

#endif
