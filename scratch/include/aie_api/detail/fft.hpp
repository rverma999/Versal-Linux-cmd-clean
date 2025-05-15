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

#ifndef __AIE_API_DETAIL_FFT_HPP__
#define __AIE_API_DETAIL_FFT_HPP__

#include "array_helpers.hpp"
#include "utils.hpp"

/**
 * @ingroup group_fft
 * @page group_fft_page_supported_modes Supported Fast Fourier Transform Modes
 *
 * <table>
 * <caption>Supported FFT/IFFT Modes</caption>
 * <tr><th>Input Type <th>Output Type <th>Twiddle Type <th>AIE Supported Radices <th>AIE-ML Supported Radices
 * <tr>
 *   <td>c16b   <td>c16b   <td>c16b   <td align="center"> 2, 4       <td align="center"> 2, 4
 * <tr>
 *   <td>c16b   <td>c32b   <td>c16b   <td align="center"> 2, 3, 4, 5 <td align="center"> 2, 3, 4, 5
 * <tr>
 *   <td>c32b   <td>c16b   <td>c16b   <td align="center"> 2, 4,      <td align="center"> 2, 4
 * <tr>
 *   <td>c32b   <td>c32b   <td>c16b   <td align="center"> 2, 3, 4, 5 <td align="center"> 2, 3, 4, 5
 * <tr>
 *   <td>c32b   <td>c16b   <td>c32b   <td align="center"> 2          <td align="center">
 * <tr>
 *   <td>c32b   <td>c32b   <td>c32b   <td align="center"> 2, 3, 4, 5 <td align="center">
 * <tr>
 *   <td>cfloat <td>cfloat <td>cfloat <td align="center"> 2, 3, 5    <td align="center">
 * </table>
 */

namespace aie::detail {

#if __AIE_ARCH__ == 10

template<unsigned Vectorization, unsigned Radix, typename Input, typename Output, typename Twiddle>
static constexpr unsigned fft_get_stage()
{
    //TODO: check legal vectorization value? Also refactor to compute this directly from datatype bits?
    if      constexpr (std::is_same_v<Twiddle, cint16>) {
        if constexpr (std::is_same_v<Input, Output>) {
            if      constexpr (Radix == 2 && std::is_same_v<Input, cint16>) {
                if      constexpr (Vectorization == 1) { return 3; }
                else if constexpr (Vectorization == 2) { return 2; }
                else if constexpr (Vectorization == 4) { return 1; }
                else                                   { return 0; }
            }
            else if constexpr (Radix == 2 && std::is_same_v<Input, cint32>) {
                if      constexpr (Vectorization == 1) { return 2; }
                else if constexpr (Vectorization == 2) { return 1; }
                else                                   { return 0; }
            }
            else if constexpr (Radix == 4) {
                if      constexpr (Vectorization == 1) { return 1; }
                else if constexpr (Vectorization >= 4) { return 0; }
                else                                   { UNREACHABLE_MSG("Requested vectorization not supported for Radix 4\n"); }
            }
            //Only plans to support stage 0 for odd radix at this time
            else if constexpr (Radix == 3 || Radix == 5) {
                if      constexpr (Vectorization >= 4) { return 0; }
                else                                   { UNREACHABLE_MSG("Only vectorization of 4 or greater is supported in Radix 3 and 5\n"); }
            }
        }
        else {
            if constexpr (Vectorization == 1) {
                if      constexpr (Radix == 2) { return 2; }
                else if constexpr (Radix == 4) { return 1; }
            }
            else { return 0; }
        }
    }
    else if constexpr (std::is_same_v<Twiddle, cint32>) {
        if constexpr (std::is_same_v<Input, Output>) {
            if     constexpr (Radix == 2 && std::is_same_v<Input, cint16>) {
                if      constexpr (Vectorization == 1) { return 2; }
                else                                   { UNREACHABLE_MSG("Requested vectorization not supported for Radix 2\n"); }
            }
            if     constexpr (Radix == 2 && std::is_same_v<Input, cint32>) {
                if      constexpr (Vectorization == 1) { return 1; }
                else                                   { return 0; }
            }
            else if constexpr (Radix == 4 && std::is_same_v<Input, cint32>) {
                if      constexpr (Vectorization == 1) { return 1; }
                else if constexpr (Vectorization >= 4) { return 0; }
                else                                   { UNREACHABLE_MSG("Requested vectorization not supported for Radix 4\n"); }
            }
            else if constexpr (Radix == 3 || Radix == 5) {
                if      constexpr (Vectorization >= 2) { return 0; }
                else                                   { UNREACHABLE_MSG("Only vectorization of 2 or greater is supported in Radix 3 and 5\n"); }
            }
        }
        else {
            if constexpr (Vectorization == 1) {
                if      constexpr (Radix == 2) { return 1; }
                else if constexpr (Radix == 4) { return 1; }
            }
            else { return 0; }
        }
    }
    else if constexpr (std::is_same_v<Twiddle, cfloat>) {
        if constexpr (std::is_same_v<Input, cfloat>) {
            if constexpr (Radix == 2) {
                if      constexpr (Vectorization == 1) { return 2; }
                else if constexpr (Vectorization == 2) { return 1; }
                else                                   { return 0; }
            }
            else if constexpr (Radix == 3 || Radix == 5) {
                if      constexpr (Vectorization >= 4) { return 0; }
                else                                   { UNREACHABLE_MSG("Only vectorization of 4 or greater is supported in Radix 3 and 5\n"); }
            }
        }
    }
}

template <unsigned Radix, typename Input, typename Output, typename Twiddle>
static constexpr unsigned fft_get_out_vector_size()
{
    if      constexpr (std::is_same_v<Twiddle, cint16>) {
        if   constexpr (std::is_same_v<Input, cint16> && Radix == 2 ) { return 8; } //cint16 radix2 has vectors of 8 elems unless it is a stage 0 upscaling to cint32
        else                                                          { return 4; }
    }
    else if constexpr (std::is_same_v<Twiddle, cint32>) {
        if      constexpr (std::is_same_v<Input, cint16> && std::is_same_v<Output, cint16> && Radix == 2) { return 4; }
        else if constexpr (std::is_same_v<Input, cint16> && std::is_same_v<Output, cint32>)               { return 4; }
        else if constexpr (std::is_same_v<Input, cint32> && std::is_same_v<Output, cint16>)               { return 4; }
        else if constexpr (std::is_same_v<Input, cint32> && std::is_same_v<Output, cint32>)               { return 2; }
    }
    else if constexpr (std::is_same_v<Twiddle, cfloat>) {
        return 4;
    }
}

#elif __AIE_ARCH__ == 20

template<unsigned Vectorization, unsigned Radix, typename Input, typename Output, typename Twiddle>
static constexpr unsigned fft_get_stage()
{
    //TODO: check legal vectorization value? Also could probably refactor to an expression compute this directly from datatype bits, fft_get_out_vector_number and fft_get_out_vector_size
    if      constexpr (std::is_same_v<Twiddle, cint16>) {
        if constexpr (std::is_same_v<Input, Output>) {
            if      constexpr (Radix == 2) {
                if      constexpr (Vectorization == 1) { return 3; }
                else if constexpr (Vectorization == 2) { return 2; }
                else if constexpr (Vectorization == 4) { return 1; }
                else                                   { return 0; }
            }
            else if constexpr (Radix == 4) {
                if      constexpr (Vectorization == 1) { return 2; }
                else if constexpr (Vectorization == 4) { return 1; }
                else                                   { return 0; }
            }
            else if constexpr (Radix == 3 || Radix == 5) {
                if      constexpr (Vectorization >= 8) { return 0; }
                else                                   { UNREACHABLE_MSG("Only vectorization of 8 or greater is supported in Radix 3 and 5\n"); }
            }
        }
        else {
            //TODO: this only covers the up/down levels we currently implement
            if      constexpr (std::is_same_v<Input, cint16>) { return 0; }
            else if constexpr (std::is_same_v<Input, cint32>) {
                if      constexpr (Radix == 2) {
                    if      constexpr (Vectorization == 1) { return 3; }
                }
                else if constexpr (Radix == 4) {
                    if      constexpr (Vectorization == 1) { return 2; }
                    else if constexpr (Vectorization == 4) { return 1; }
                    else                                   { return 0; }
                }
            }
        }
    }
}

template <unsigned Radix, typename Input, typename Output, typename Twiddle>
static constexpr unsigned fft_get_out_vector_size()
{
    return 8;
}

#endif

template <typename Input, typename Output>
struct default_twiddle_type
{
    using type = cint16;
};

#if __AIE_ARCH__ == 10
template <>
struct default_twiddle_type<cfloat, cfloat>
{
    using type = cfloat;
};
#endif

template <typename Input, typename Output = Input>
using default_twiddle_type_t = typename default_twiddle_type<Input, Output>::type;

template <unsigned Vectorization, unsigned Stage, unsigned Radix,
          typename Input, typename Output = Input, typename Twiddle = default_twiddle_type_t<Input, Output>>
struct fft_dit_common
{
    static constexpr unsigned stage = Stage;
    static constexpr unsigned radix = Radix;

    static constexpr unsigned out_vector_size = fft_get_out_vector_size<Radix, Input, Output, Twiddle>();
    static constexpr unsigned num_out_vector  = Radix;
    static constexpr unsigned min_point_size  = out_vector_size * num_out_vector;

    using output_data = std::array<vector<Output, out_vector_size>, num_out_vector>;

    __aie_inline
    static constexpr int block_size(unsigned n)
    {
        RUNTIME_ASSERT((n % min_point_size) == 0, "FFT point size not a multiple of min_point_size");

        unsigned size;
        if constexpr (Radix == 3) {
            size = ((n * 10923) >> 15) / out_vector_size;
        } else if constexpr (Radix == 5) {
            size = ((n * 6554) >> 15) / out_vector_size;
        } else {
            size = n / (Radix * out_vector_size);
        }
        return size;
    }
};

template <unsigned Vectorization, unsigned Stage, unsigned Radix,
          typename Input, typename Output = Input, typename Twiddle = default_twiddle_type_t<Input, Output>>
struct fft_dit;

template <unsigned Radix, typename Input, typename Output, typename Twiddle>
struct is_valid_fft_op
{
    static constexpr bool value()
    {
#if __AIE_ARCH__ == 10
        if      constexpr (std::is_same_v<Twiddle, cint16>) {
            if      constexpr (std::is_same_v<Input, cint32> && std::is_same_v<Output, cint32> && (Radix == 2 || Radix == 3 || Radix == 4 || Radix == 5))
                return true;
            else if constexpr (std::is_same_v<Input, cint16> && std::is_same_v<Output, cint32> && (Radix == 2 || Radix == 3 || Radix == 4 || Radix == 5))
                return true;
            else if constexpr (std::is_same_v<Input, cint32> && std::is_same_v<Output, cint16> && (Radix == 2 || Radix == 4))
                return true;
            else if constexpr (std::is_same_v<Input, cint16> && std::is_same_v<Output, cint16> && (Radix == 2 || Radix == 4))
                return true;
        }
        else if constexpr (std::is_same_v<Twiddle, cint32>) {
            if      constexpr (std::is_same_v<Input, cint16> && std::is_same_v<Output, cint16> && Radix == 2)
                return true;
            else if constexpr (std::is_same_v<Input, cint16> && std::is_same_v<Output, cint32> && (Radix == 2 || Radix == 4))
                return true;
            else if constexpr (std::is_same_v<Input, cint32> && std::is_same_v<Output, cint16> && (Radix == 2 || Radix == 4))
                return true;
            else if constexpr (std::is_same_v<Input, cint32> && std::is_same_v<Output, cint32> && (Radix == 2 || Radix == 3 || Radix == 4 || Radix == 5))
                return true;
        }
        else if constexpr (std::is_same_v<Twiddle, cfloat>) {
            if      constexpr (std::is_same_v<Input, cfloat> && std::is_same_v<Output, cfloat> && (Radix == 2 || Radix == 3 || Radix == 5))
                return true;
        }
#elif __AIE_ARCH__ == 20
        if      constexpr (std::is_same_v<Twiddle, cint16>) {
            if      constexpr (utils::is_one_of_v<Input, cint16, cint32> && utils::is_one_of_v<Output, cint16, cint32> && (Radix == 2 || Radix == 4))
                return true;
            else if constexpr (std::is_same_v<Input, cint32> && std::is_same_v<Output, cint32> && (Radix == 3 || Radix == 5))
                return true;
            else if constexpr (std::is_same_v<Input, cint16> && std::is_same_v<Output, cint32> && (Radix == 3 || Radix == 5))
                return true;
        }
#endif

        return false;
    }
};

template <unsigned Radix, typename Input, typename Output, typename Twiddle>
static constexpr bool is_valid_fft_op_v = is_valid_fft_op<Radix, Input, Output, Twiddle>::value();

template <unsigned Radix, unsigned Vectorization, typename Input, typename Output, typename Twiddle>
struct fft_dit_stage;

}

#if __AIE_ARCH__ == 10

#include "aie1/fft_dit.hpp"

#elif __AIE_ARCH__ == 20

#include "aie2/fft_dit.hpp"

#endif

#endif
