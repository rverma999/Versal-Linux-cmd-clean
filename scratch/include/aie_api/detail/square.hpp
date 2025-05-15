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

#ifndef __AIE_API_DETAIL_SQUARE__HPP__
#define __AIE_API_DETAIL_SQUARE__HPP__

#include <cstdlib>
#include <cmath>
#include <climits>

#include "mul.hpp"

namespace aie::detail {

template <MulMacroOp MulOp, unsigned AccumBits, unsigned TypeBits, typename T>
struct square_bits_impl
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    template <unsigned Elems>
    using vector_type = vector<T, Elems>;

    using accum_tag = accum_tag_for_type<T, AccumBits>;

    template <unsigned Elems>
    using  accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type<Elems> &v, const Acc &... acc)
    {
        return mul<MulOp, AccumBits, T, T>::run(v, is_signed_v<T>, v, is_signed_v<T>, acc...);
    }
#endif
};

template <MulMacroOp MulOp, unsigned AccumBits, unsigned TypeBits, typename T>
struct square_bits
{
    template <unsigned Elems>
    using vector_type = vector<T, Elems>;

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static auto run(const vector_type<Elems> &v, const Acc &... acc)
    {
#if __AIE_ARCH__ == 10
        return square_bits_impl<MulOp, AccumBits, TypeBits, T>::run(v, acc...);
#else
        return mul<MulOp, AccumBits, T, T>::run(v, is_signed_v<T>, v, is_signed_v<T>, acc...);
#endif
    }
};

template <MulMacroOp MulOp, unsigned AccumBits, typename T>
using square = square_bits<MulOp, AccumBits, type_bits_v<T>, T>;

}

#if __AIE_ARCH__ == 10

#include "aie1/square.hpp"

#endif

#endif
