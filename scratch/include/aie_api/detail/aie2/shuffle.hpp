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

#ifndef __AIE_API_DETAIL_AIE2_SHUFFLE__HPP__
#define __AIE_API_DETAIL_AIE2_SHUFFLE__HPP__

#include "../../vector.hpp"
#include "../../mask.hpp"

namespace aie::detail {

template <typename T, unsigned Elems>
struct shuffle_down_fill_bits_impl<4, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, const vector_type &fill, unsigned n)
    {
        using next_type = utils::get_next_integer_type_t<T>;
        vector_type ret;

        if (chess_manifest(n == 0))
            return v;

        if (chess_manifest(n % 2 == 0))
            return shuffle_down_fill_bits_impl<8, next_type, Elems / 2>::run(v.template cast_to<next_type>(), fill.template cast_to<next_type>(), n / 2).template cast_to<T>();

        if constexpr (vector_type::bits() <= 512) {
            ret = shuffle_down_fill_bits_impl<8, next_type, Elems>::run(v.unpack(), fill.unpack(), n).template pack<T>();

            return ret;
        }
        else if constexpr (vector_type::bits() <= 1024) {
            return shuffle_down_fill_bits_impl_scalar<4, T, Elems>::run(v, fill, n);
        }
    }
};

template <typename T, unsigned Elems>
struct shuffle_down_bits_impl<4, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, unsigned n)
    {
        using next_type = utils::get_next_integer_type_t<T>;
        vector_type ret;

        if (chess_manifest(n == 0))
            return v;

        if (chess_manifest(n % 2 == 0))
            return shuffle_down_bits_impl<8, next_type, Elems / 2>::run(v.template cast_to<next_type>(), n / 2).template cast_to<T>();

        if constexpr (vector_type::bits() <= 512) {
            ret = shuffle_down_bits_impl<8, next_type, Elems>::run(v.unpack(), n).template pack<T>();

            return ret;
        }
        else if constexpr (vector_type::bits() <= 1024) {
            return shuffle_down_bits_impl_scalar<4, T, Elems>::run(v, n);
        }
    }
};

template <unsigned TypeBits, typename T, unsigned Elems> requires(TypeBits >= 4)
struct shuffle_up_rotate_bits_impl<TypeBits, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, unsigned n)
    {
        return shuffle_down_rotate_bits_impl<TypeBits, T, Elems>::run(v, Elems - n);
    }
};

template <unsigned TypeBits, typename T, unsigned Elems> requires(TypeBits >= 4)
struct shuffle_up_fill_bits_impl<TypeBits, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, const vector_type &fill, unsigned n)
    {
        return shuffle_down_fill_bits_impl<TypeBits, T, Elems>::run(fill, v, Elems - n);
    }
};

template <unsigned TypeBits, typename T, unsigned Elems> requires(TypeBits >= 4)
struct shuffle_up_bits_impl<TypeBits, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, unsigned n)
    {
        return shuffle_up_fill_bits_impl<TypeBits, T, Elems>::run(v, vector_type(), n);
    }
};

template <unsigned TypeBits, typename T, unsigned Elems> requires(TypeBits >= 4)
struct shuffle_down_rotate_bits_impl<TypeBits, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, unsigned n)
    {
        return shuffle_down_fill_bits_impl<TypeBits, T, Elems>::run(v, v, n);
    }
};

template <unsigned TypeBits, typename T, unsigned Elems> requires(TypeBits >= 8)
struct shuffle_down_fill_bits_impl<TypeBits, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, const vector_type &fill, unsigned n)
    {
        vector_type ret;

        if (chess_manifest(n == 0))
            return v;

        if constexpr (vector_type::bits() == 128) {
            ret = shuffle_down_fill_bits_impl<TypeBits, T, Elems * 4>::run(concat_vector(            v,           fill, vector_type(), vector_type()),
                                                                           concat_vector(vector_type(),  vector_type(), vector_type(), vector_type()), n).template extract<Elems>(0);
        }
        else if constexpr (vector_type::bits() == 256) {
            ret = shuffle_down_fill_bits_impl<TypeBits, T, Elems * 2>::run(concat_vector(            v,           fill),
                                                                           concat_vector(vector_type(),  vector_type()), n).template extract<Elems>(0);
        }
        else if constexpr (vector_type::bits() == 512) {
            ret = SHIFT_BYTES(v, fill, n * sizeof(T));
        }
        else if constexpr (vector_type::bits() == 1024) {
            if (chess_manifest(n >= Elems / 2)) {
                ret.template insert<Elems / 2>(0, SHIFT_BYTES(   v.template extract<Elems / 2>(1),
                                                              fill.template extract<Elems / 2>(0), (n - Elems / 2) * sizeof(T)));
                ret.template insert<Elems / 2>(1, SHIFT_BYTES(fill.template extract<Elems / 2>(0),
                                                              fill.template extract<Elems / 2>(1), (n - Elems / 2) * sizeof(T)));
            }
            else if (chess_manifest(n < Elems / 2)) {
                ret.template insert<Elems / 2>(0, SHIFT_BYTES(   v.template extract<Elems / 2>(0),
                                                                 v.template extract<Elems / 2>(1), n * sizeof(T)));
                ret.template insert<Elems / 2>(1, SHIFT_BYTES(   v.template extract<Elems / 2>(1),
                                                              fill.template extract<Elems / 2>(0), n * sizeof(T)));
            }
            else {
                vector<T, Elems / 2> tmp1a, tmp1b, tmp2a, tmp2b;

                mask<Elems / 2> mask1(true), mask2(true);

                mask1 <<= Elems - n;
                mask2 <<= Elems - n;

                tmp1a = SHIFT_BYTES(v.template extract<Elems / 2>(0),    v.template extract<Elems / 2>(1), n * sizeof(T));
                tmp1b = SHIFT_BYTES(vector<T, Elems / 2>(),           fill.template extract<Elems / 2>(0), (n - Elems / 2) * sizeof(T));

                tmp2a = SHIFT_BYTES(v.template extract<Elems / 2>(1), fill.template extract<Elems / 2>(0), n * sizeof(T));
                tmp2b = SHIFT_BYTES(vector<T, Elems / 2>(),           fill.template extract<Elems / 2>(1), (n - Elems / 2) * sizeof(T));

                if constexpr (Elems > 64) {
                    ret.template insert<Elems / 2>(0, ::sel(tmp1a, tmp1b, mask1.to_uint64()));
                    ret.template insert<Elems / 2>(1, ::sel(tmp2a, tmp2b, mask2.to_uint64()));
                }
                else {
                    ret.template insert<Elems / 2>(0, ::sel(tmp1a, tmp1b, mask1.to_uint32()));
                    ret.template insert<Elems / 2>(1, ::sel(tmp2a, tmp2b, mask2.to_uint32()));
                }
            }
        }

        return ret;
    }
};

template <unsigned TypeBits, typename T, unsigned Elems> requires(TypeBits >= 8)
struct shuffle_down_bits_impl<TypeBits, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, unsigned n)
    {
        vector_type ret;

        if (chess_manifest(n == 0))
            return v;

        if constexpr (vector_type::bits() == 128) {
            ret = shuffle_down_bits_impl<TypeBits, T, Elems * 4>::run(v.template grow<Elems * 4>(), n).template extract<Elems>(0);
        }
        else if constexpr (vector_type::bits() == 256) {
            ret = shuffle_down_bits_impl<TypeBits, T, Elems * 2>::run(v.template grow<Elems * 2>(), n).template extract<Elems>(0);
        }
        else if constexpr (vector_type::bits() == 512) {
            ret = SHIFT_BYTES(v, v, n * sizeof(T));
        }
        else if constexpr (vector_type::bits() == 1024) {
            ret.template insert<Elems / 2>(0, SHIFT_BYTES(v.template extract<Elems / 2>(0), v.template extract<Elems / 2>(1), n * sizeof(T)));
            ret.template insert<Elems / 2>(1, SHIFT_BYTES(v.template extract<Elems / 2>(1), vector<T, Elems / 2>(),           n * sizeof(T)));
        }

        return ret;
    }
};

}

#endif
