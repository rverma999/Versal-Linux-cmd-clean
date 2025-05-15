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

#ifndef __AIE_API_DETAIL_SHUFFLE__HPP__
#define __AIE_API_DETAIL_SHUFFLE__HPP__

#include "vector.hpp"
#include "broadcast.hpp"

namespace aie::detail {

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_up_bits_impl_scalar
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &v, unsigned n)
    {
        vector_type ret;

        for (unsigned i = 0; i < Elems - n; ++i)
            ret[i + n] = v[i];

        return ret;
    }
#endif
};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_up_fill_bits_impl_scalar
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &v, const vector_type &fill, unsigned n)
    {
        vector_type ret;

        for (unsigned i = 0; i < Elems - n; ++i)
            ret[i + n] = v[i];

        for (unsigned i = 0; i < n; ++i)
            ret[i] = fill[i + Elems - n];

        return ret;
    }
#endif
};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_up_rotate_bits_impl_scalar
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &v, unsigned n)
    {
        vector_type ret;

        for (unsigned i = 0; i < Elems - n; ++i)
            ret[i + n] = v[i];

        for (unsigned i = 0; i < n; ++i)
            ret[i] = v[i + Elems - n];

        return ret;
    }
#endif
};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_up_replicate_bits_impl_scalar
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &v, unsigned n)
    {
        vector_type ret;

        for (unsigned i = 0; i < Elems - n; ++i)
            ret[i + n] = v[i];

        for (unsigned i = 0; i < n; ++i)
            ret[i] = v[0];

        return ret;
    }
#endif
};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_down_replicate_bits_impl_scalar
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &v, unsigned n)
    {
        vector_type ret;

        for (unsigned i = 0; i < Elems - n; ++i)
            ret[i] = v[i + n];

        for (unsigned i = Elems - n; i < Elems; ++i)
            ret[i] = v[Elems - 1];

        return ret;
    }
#endif
};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_up_bits_impl           : public shuffle_up_bits_impl_scalar<TypeBits, T, Elems> {};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_up_fill_bits_impl      : public shuffle_up_fill_bits_impl_scalar<TypeBits, T, Elems> {};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_up_rotate_bits_impl    : public shuffle_up_rotate_bits_impl_scalar<TypeBits, T, Elems> {};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_up_replicate_bits_impl : public shuffle_up_replicate_bits_impl_scalar<TypeBits, T, Elems> {};


template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_down_bits_impl_scalar
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &v, unsigned n)
    {
        vector_type ret;

        for (unsigned i = 0; i < Elems - n; ++i)
            ret[i] = v[i + n];

        return ret;
    }
#endif
};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_down_fill_bits_impl_scalar
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &v, const vector_type &fill, unsigned n)
    {
        vector_type ret;

        for (unsigned i = 0; i < Elems - n; ++i)
            ret[i] = v[i + n];

        for (unsigned i = 0; i < n; ++i)
            ret[i + Elems - n] = fill[i];

        return ret;
    }
#endif
};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_down_rotate_bits_impl_scalar
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &v, unsigned n)
    {
        vector_type ret;

        for (unsigned i = 0; i < Elems - n; ++i)
            ret[i] = v[i + n];

        for (unsigned i = 0; i < n; ++i)
            ret[i + Elems - n] = v[i];

        return ret;
    }
#endif
};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_down_bits_impl        : public shuffle_down_bits_impl_scalar<TypeBits, T, Elems> {};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_down_fill_bits_impl   : public shuffle_down_fill_bits_impl_scalar<TypeBits, T, Elems> {};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_down_rotate_bits_impl : public shuffle_down_rotate_bits_impl_scalar<TypeBits, T, Elems> {};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_down_replicate_bits_impl : public shuffle_down_replicate_bits_impl_scalar<TypeBits, T, Elems> {};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_up_bits
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, unsigned n)
    {
        return shuffle_up_bits_impl<TypeBits, T, Elems>::run(v, n);
    }
};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_up_fill_bits
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, const vector_type &fill, unsigned n)
    {
        return shuffle_up_fill_bits_impl<TypeBits, T, Elems>::run(v, fill, n);
    }
};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_up_replicate_bits
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, unsigned n)
    {
#if __AIE_ARCH__ == 20
        return shuffle_up_fill_bits_impl<TypeBits, T, Elems>::run(v, broadcast<T, Elems>::run(v[0]),  n);
#else
        return shuffle_up_replicate_bits_impl<TypeBits, T, Elems>::run(v, n);
#endif
    }
};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_up_rotate_bits
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, unsigned n)
    {
        return shuffle_up_rotate_bits_impl<TypeBits, T, Elems>::run(v, n);
    }
};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_down_bits
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, unsigned n)
    {
        return shuffle_down_bits_impl<TypeBits, T, Elems>::run(v, n);
    }
};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_down_fill_bits
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, const vector_type &fill, unsigned n)
    {
        return shuffle_down_fill_bits_impl<TypeBits, T, Elems>::run(v, fill, n);
    }
};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_down_rotate_bits
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, unsigned n)
    {
        return shuffle_down_rotate_bits_impl<TypeBits, T, Elems>::run(v, n);
    }
};

template <unsigned TypeBits, typename T, unsigned Elems>
struct shuffle_down_replicate_bits
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, unsigned n)
    {
#if __AIE_ARCH__ == 20
        return shuffle_down_fill_bits_impl<TypeBits, T, Elems>::run(v, broadcast<T, Elems>::run(v[Elems - 1]), n);
#else
        return shuffle_down_replicate_bits_impl<TypeBits, T, Elems>::run(v, n);
#endif
    }
};

template <typename T, unsigned Elems>
using shuffle_up             = shuffle_up_bits<type_bits_v<T>, T, Elems>;

template <typename T, unsigned Elems>
using shuffle_up_fill        = shuffle_up_fill_bits<type_bits_v<T>, T, Elems>;

template <typename T, unsigned Elems>
using shuffle_up_rotate      = shuffle_up_rotate_bits<type_bits_v<T>, T, Elems>;

template <typename T, unsigned Elems>
using shuffle_up_replicate   = shuffle_up_replicate_bits<type_bits_v<T>, T, Elems>;

template <typename T, unsigned Elems>
using shuffle_down           = shuffle_down_bits<type_bits_v<T>, T, Elems>;

template <typename T, unsigned Elems>
using shuffle_down_fill      = shuffle_down_fill_bits<type_bits_v<T>, T, Elems>;

template <typename T, unsigned Elems>
using shuffle_down_rotate    = shuffle_down_rotate_bits<type_bits_v<T>, T, Elems>;

template <typename T, unsigned Elems>
using shuffle_down_replicate = shuffle_down_replicate_bits<type_bits_v<T>, T, Elems>;

}

#if __AIE_ARCH__ == 10

#include "aie1/shuffle.hpp"
#include "aie1/shuffle_replicate.hpp"

#elif __AIE_ARCH__ == 20

#include "aie2/shuffle.hpp"

#endif

#endif
