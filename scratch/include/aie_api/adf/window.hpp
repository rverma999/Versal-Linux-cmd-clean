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

#ifndef __AIE_API_AIE_ADF_WINDOW_HPP__
#define __AIE_API_AIE_ADF_WINDOW_HPP__

#include <adf.h>
#include "../aie.hpp"

namespace aie::detail::adf {

template <typename T, unsigned N, aie_dm_resource Resource>
struct window_helper
{
    using vector_type = aie::vector<T, N>;

    __aie_inline
    static void window_write(output_window<T> *w, vector_type value)
    {
#ifndef __AIE_API_USE_NATIVE_1024B_VECTOR__
        if constexpr (vector_type::bits() == 1024) {
            ::window_write<Resource>(w, value.template extract<N / 2>(0));
            ::window_write<Resource>(w, value.template extract<N / 2>(1));

            return;
        }
#endif // __AIE_API_USE_NATIVE_1024B_VECTOR__

#if __AIE_ARCH__ == 20
        // TODO: CRVO-3196: implement this more efficiently if possible
        if constexpr (vector_type::bits() == 128)
            value.template store<Resource>((typename vector_type::value_type *)w->ptr);
        else
#endif
        ::window_write<Resource>(w, value);
    }

    __aie_inline
    static void window_writeincr(output_window<T> *w, vector_type value)
    {
#ifndef __AIE_API_USE_NATIVE_1024B_VECTOR__
        if constexpr (vector_type::bits() == 1024) {
            ::window_writeincr<Resource>(w, value.template extract<N / 2>(0));
            ::window_writeincr<Resource>(w, value.template extract<N / 2>(1));

            return;
        }
#endif // __AIE_API_USE_NATIVE_1024B_VECTOR__

#if __AIE_ARCH__ == 20
        // TODO: CRVO-3196: implement this more efficiently if possible
        if constexpr (vector_type::bits() == 128) {
            value.template store<Resource>((typename vector_type::value_type *)w->ptr);
            ::window_incr(w, value.size());
        }
        else
#endif

        ::window_writeincr<Resource>(w, value);
    }

    __aie_inline
    static vector_type window_read(input_window<T> *w)
    {
#ifndef __AIE_API_USE_NATIVE_1024B_VECTOR__
        if constexpr (vector_type::bits() == 1024) {
            vector_type ret;

            ret.insert(0, window_helper<T, N / 2, Resource>::window_read(w));
            ret.insert(1, window_helper<T, N / 2, Resource>::window_read(w));

            return ret;
        }
        else
#endif // __AIE_API_USE_NATIVE_1024B_VECTOR__
        {
#if __AIE_ARCH__ == 20
            // TODO: CRVO-3196: implement this more efficiently if possible
            if constexpr (vector_type::bits() == 128) {
                vector_type ret;

                ret.template load<Resource>((const typename vector_type::value_type *)w->ptr);

                return ret;
            }
            else
#endif
            {
                if constexpr (N == 2)
#if AIE_API_PLATFORM_VERSION == 100
                    return ::window_read_v2<Resource>(w);
#else
                { // TODO: CRVO-3196
                    return vector_type();
                }
#endif
                else if constexpr (N == 4)
                    return ::window_read_v4<Resource>(w);
                else if constexpr (N == 8)
                    return ::window_read_v8<Resource>(w);
                else if constexpr (N == 16)
                    return ::window_read_v16<Resource>(w);
                else if constexpr (N == 32)
                    return ::window_read_v32<Resource>(w);
                else if constexpr (N == 64)
                    return ::window_read_v64<Resource>(w);
                else if constexpr (N == 128)
                    return ::window_read_v128<Resource>(w);
            }
        }
    }

    __aie_inline
    static vector_type window_readincr(input_window<T> *w)
    {
#ifndef __AIE_API_USE_NATIVE_1024B_VECTOR__
        if constexpr (vector_type::bits() == 1024) {
            vector_type ret;

            ret.insert(0, window_helper<T, N / 2, Resource>::window_readincr(w));
            ret.insert(1, window_helper<T, N / 2, Resource>::window_readincr(w));

            return ret;
        }
        else
#endif // __AIE_API_USE_NATIVE_1024B_VECTOR__
        {
#if __AIE_ARCH__ == 20
            // TODO: CRVO-3196: implement this more efficiently if possible
            if constexpr (vector_type::bits() == 128) {
                vector_type ret;

                ret.template load<Resource>((const typename vector_type::value_type *)w->ptr);
                ::window_incr(w, ret.size());

                return ret;
            }
            else
#endif
            {
                if constexpr (N == 2)
#if AIE_API_PLATFORM_VERSION == 100
                    return ::window_readincr_v2<Resource>(w);
#else
                { // TODO: CRVO-3196
                    ::window_incr(w, 2);
                    return vector_type();
                }
#endif
                else if constexpr (N == 4)
                    return ::window_readincr_v4<Resource>(w);
                else if constexpr (N == 8)
                    return ::window_readincr_v8<Resource>(w);
                else if constexpr (N == 16)
                    return ::window_readincr_v16<Resource>(w);
                else if constexpr (N == 32)
                    return ::window_readincr_v32<Resource>(w);
                else if constexpr (N == 64)
                    return ::window_readincr_v64<Resource>(w);
                else if constexpr (N == 128)
                    return ::window_readincr_v128<Resource>(w);
            }
        }
    }

    __aie_inline
    static vector_type window_readdecr(input_window<T> *w)
    {
#ifndef __AIE_API_USE_NATIVE_1024B_VECTOR__
        if constexpr (vector_type::bits() == 1024) {
            vector_type ret;

            ret.insert(0, window_helper<T, N / 2, Resource>::window_readdecr(w));
            ret.insert(1, window_helper<T, N / 2, Resource>::window_readdecr(w));

            return ret;
        }
        else
#endif // __AIE_API_USE_NATIVE_1024B_VECTOR__
        {
            if constexpr (N == 2)
#if AIE_API_PLATFORM_VERSION == 100
                return ::window_readdecr_v2<Resource>(w);
#else
            { // TODO: CRVO-3196
                ::window_decr(w, 2);
                return vector_type();
            }
#endif
            else if constexpr (N == 4)
                return ::window_readdecr_v4<Resource>(w);
            else if constexpr (N == 8)
                return ::window_readdecr_v8<Resource>(w);
            else if constexpr (N == 16)
                return ::window_readdecr_v16<Resource>(w);
            else if constexpr (N == 32)
                return ::window_readdecr_v32<Resource>(w);
            else if constexpr (N == 64)
                return ::window_readdecr_v64<Resource>(w);
            else if constexpr (N == 128)
                return ::window_readdecr_v128<Resource>(w);
        }
    }

    __aie_inline
    static void window_read(input_window<T> *w, vector_type & value)     { value = window_helper::window_read(w);     }
    __aie_inline
    static void window_readincr(input_window<T> *w, vector_type & value) { value = window_helper::window_readincr(w); }
    __aie_inline
    static void window_readdecr(input_window<T> *w, vector_type & value) { value = window_helper::window_readdecr(w); }
};

}

/**
 * @ingroup group_adf
 *
 * Write a vector into an output window.
 *
 * @param w Output window
 * @param value Vector to be written
 */
template <aie_dm_resource Resource = aie_dm_resource::none, typename T, unsigned N>
__aie_inline
void              window_write      (output_window<T> *w, const aie::vector<T, N> &value) {        aie::detail::adf::window_helper<T, N, Resource>::window_write(w, value);     }

/**
 * @ingroup group_adf
 *
 * Write a vector into an output window and increment the window pointer.
 *
 * @param w Output window
 * @param value Vector to be written
 */
template <aie_dm_resource Resource = aie_dm_resource::none, typename T, unsigned N>
__aie_inline
void              window_writeincr  (output_window<T> *w, const aie::vector<T, N> &value) {        aie::detail::adf::window_helper<T, N, Resource>::window_writeincr(w, value); }

/**
 * @ingroup group_adf
 *
 * Read a vector from an input window.
 *
 * @tparam N Size of the vector to be read
 * @param w Input window
 */
template <unsigned N, aie_dm_resource Resource = aie_dm_resource::none, typename T>
__aie_inline
aie::vector<T, N> window_read_v     ( input_window<T> *w)                                 { return aie::detail::adf::window_helper<T, N, Resource>::window_read(w);             }

/**
 * @ingroup group_adf
 *
 * Read a vector from an input window and increment the window pointer.
 *
 * @tparam N Size of the vector to be read
 * @param w Input window
 */
template <unsigned N, aie_dm_resource Resource = aie_dm_resource::none, typename T>
__aie_inline
aie::vector<T, N> window_readincr_v ( input_window<T> *w)                                 { return aie::detail::adf::window_helper<T, N, Resource>::window_readincr(w);         }

/**
 * @ingroup group_adf
 *
 * Read a vector from an input window and decrement the window pointer.
 *
 * @tparam N Size of the vector to be read
 * @param w Input window
 */
template <unsigned N, aie_dm_resource Resource = aie_dm_resource::none, typename T>
__aie_inline
aie::vector<T, N> window_readdecr_v ( input_window<T> *w)                                 { return aie::detail::adf::window_helper<T, N, Resource>::window_readdecr(w);         }

/**
 * @ingroup group_adf
 *
 * Read a vector from an input window.
 *
 * @param w Input window
 * @param value Output parameter that contains the read vector
 */
template <unsigned N, aie_dm_resource Resource = aie_dm_resource::none, typename T>
__aie_inline
void              window_read_v     ( input_window<T> *w, aie::vector<T, N> &value)       {        aie::detail::adf::window_helper<T, N, Resource>::window_read(w, value);      }

/**
 * @ingroup group_adf
 *
 * Read a vector from an input window and increment the window pointer.
 *
 * @param w Input window
 * @param value Output parameter that contains the read vector
 */
template <unsigned N, aie_dm_resource Resource = aie_dm_resource::none, typename T>
__aie_inline
void              window_readincr_v ( input_window<T> *w, aie::vector<T, N> &value)       {        aie::detail::adf::window_helper<T, N, Resource>::window_readincr(w, value);  }

/**
 * @ingroup group_adf
 *
 * Read a vector from an input window and decrement the window pointer.
 *
 * @param w Input window
 * @param value Output parameter that contains the read vector
 */
template <unsigned N, aie_dm_resource Resource = aie_dm_resource::none, typename T>
__aie_inline
void              window_readdecr_v ( input_window<T> *w, aie::vector<T, N> &value)       {        aie::detail::adf::window_helper<T, N, Resource>::window_readdecr(w, value);  }

#endif
