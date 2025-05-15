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

#ifndef __AIE_API_DETAIL_VECTOR_ACCUM_CAST__HPP__
#define __AIE_API_DETAIL_VECTOR_ACCUM_CAST__HPP__

#include "accum.hpp"
#include "vector.hpp"

namespace aie::detail {

template <typename DstTag, typename T, unsigned Elems>
struct vector_to_accum_cast_bits_impl;

template <typename DstT, AccumClass Class, unsigned Bits, unsigned Elems>
struct accum_to_vector_cast_bits_impl;

template <typename DstTag, typename T, unsigned Elems>
struct vector_to_accum_cast_bits
{
    using vector_type = vector<T,  Elems>;

    static auto run(const vector_type &v)
    {
        return vector_to_accum_cast_bits_impl<DstTag, T, Elems>::run(v);
    }
};

template <typename DstTag, typename T, unsigned Elems>
using vector_to_accum_cast = vector_to_accum_cast_bits<DstTag, T, Elems>;

template <typename DstT, AccumClass Class, unsigned Bits, unsigned Elems>
struct accum_to_vector_cast_bits
{
    using  accum_tag = accum_tag_t<Class, Bits>;
    using accum_type = accum<accum_tag, Elems>;

    static auto run(const accum_type &acc)
    {
        return accum_to_vector_cast_bits_impl<DstT, Class, Bits, Elems>::run(acc);
    }
};

template <typename DstT, typename Tag, unsigned Elems>
using accum_to_vector_cast = accum_to_vector_cast_bits<DstT,
                                                       accum_class_for_tag_v<Tag>,
                                                       accum_bits_for_tag_v<Tag>,
                                                       Elems>;

}

#if __AIE_ARCH__ == 20

#include "aie2/vector_accum_cast.hpp"

#endif

#endif
