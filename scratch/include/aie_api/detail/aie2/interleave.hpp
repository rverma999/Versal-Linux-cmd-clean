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

#ifndef __AIE_API_DETAIL_AIE2_INTERLEAVE__HPP__
#define __AIE_API_DETAIL_AIE2_INTERLEAVE__HPP__

#include "shuffle_mode.hpp"
#include "../vector.hpp"
#include "../utils.hpp"
#include "../vector_accum_cast.hpp"

namespace aie::detail {

template <unsigned TypeBits, typename T, unsigned Elems>
struct interleave_bits_zip_impl
{
    static constexpr unsigned native_elems = 512 / TypeBits;
    using vector_type                      = vector<T, Elems>;
    using native_interleave                = interleave_bits_zip_impl<TypeBits, T, native_elems>;

    __aie_inline
    static std::pair<vector_type, vector_type> run(const vector_type &v, const vector_type &w, unsigned step)
    {
        const shuffle_mode<TypeBits, Elems> mode{step, shuffle_zip_tag{}};
        return run(v, w, mode);
    }

    __aie_inline
    static std::pair<vector_type, vector_type> run(const vector_type &v, const vector_type &w,
                                                   const shuffle_mode<TypeBits, Elems> &mode)
    {
        // Comparing shuffle_mode does not work beyond 512bit vectors
        if (chess_manifest(mode.is_bypass())) {
            return {v, w};
        }

        vector_type ret1, ret2;

        if constexpr (vector_type::bits() < 512) {
            vector<T, native_elems> tmp;

            const shuffle_mode<TypeBits, native_elems> native_mode{mode};
            std::tie(tmp, std::ignore) = native_interleave::run(v.template grow<native_elems>(),
                                                                w.template grow<native_elems>(),
                                                                native_mode);

            ret1 = tmp.template extract<Elems>(0);
            ret2 = tmp.template extract<Elems>(1);
        }
        else if constexpr (vector_type::bits() == 512) {
            ret1 = ::shuffle(v, w, mode.low());
            ret2 = ::shuffle(v, w, mode.high());
        }
        else if constexpr (vector_type::bits() == 1024) {
            if (mode.is_bypass()) {
                return {v, w};
            }

            const shuffle_mode<TypeBits, native_elems> native_mode{mode};
            auto [tmp1, tmp2] = native_interleave::run(v.template extract<Elems / 2>(0),
                                                       w.template extract<Elems / 2>(0),
                                                       native_mode);
            auto [tmp3, tmp4] = native_interleave::run(v.template extract<Elems / 2>(1),
                                                       w.template extract<Elems / 2>(1),
                                                       native_mode);
            ret1 = concat(tmp1, tmp2);
            ret2 = concat(tmp3, tmp4);
        }

        return {ret1, ret2};
    }
};

template <unsigned AccumBits, typename AccumTag, unsigned Elems>
struct interleave_accum_bits_zip_impl
{
    static constexpr unsigned native_elems = 512 / AccumBits;
    using accum_type                       = accum<AccumTag, Elems>;
    using vector_type                      = vector<int32, accum_type::bits() / type_bits_v<int32>>;
    using native_interleave                = interleave_accum_bits_zip_impl<AccumBits, AccumTag, native_elems>;

    __aie_inline
    static std::pair<accum_type, accum_type> run(const accum_type &v, const accum_type &w, unsigned step)
    {
        const shuffle_mode<AccumBits, native_elems> mode{step, shuffle_zip_tag{}};

        accum_type ret1, ret2;

        if constexpr (vector_type::bits() < 512) {
            accum<AccumTag, native_elems> tmp;
            std::tie(tmp, std::ignore) = native_interleave::run(v.template grow<native_elems>(),
                                                                w.template grow<native_elems>(),
                                                                step);

            ret1 = tmp.template extract<Elems>(0);
            ret2 = tmp.template extract<Elems>(1);
        }
        else if constexpr (vector_type::bits() == 512) {
            using storage_t = typename accum_type::storage_t;
            using to_vector = accum_to_vector_cast<int32, AccumTag, Elems>; 
            ret1 = (storage_t)::shuffle(to_vector::run(v), to_vector::run(w), mode.low());
            ret2 = (storage_t)::shuffle(to_vector::run(v), to_vector::run(w), mode.high());
        }
        else if constexpr (vector_type::bits() == 1024) {
            if (step == Elems) {
                return {v, w};
            }
            auto v0 = v.template extract<native_elems>(0),
                 v1 = v.template extract<native_elems>(1);
            auto w0 = w.template extract<native_elems>(0),
                 w1 = w.template extract<native_elems>(1);

            auto [tmp1, tmp2] = native_interleave::run(v0, w0, step);
            auto [tmp3, tmp4] = native_interleave::run(v1, w1, step);
            ret1 = concat(tmp1, tmp2);
            ret2 = concat(tmp3, tmp4);
        }

        return {ret1, ret2};
    }
};

template <typename T, unsigned Elems> struct interleave_bits_zip< 4, T, Elems> : public interleave_bits_zip_impl< 4, T, Elems> {};
template <typename T, unsigned Elems> struct interleave_bits_zip< 8, T, Elems> : public interleave_bits_zip_impl< 8, T, Elems> {};
template <typename T, unsigned Elems> struct interleave_bits_zip<16, T, Elems> : public interleave_bits_zip_impl<16, T, Elems> {};
template <typename T, unsigned Elems> struct interleave_bits_zip<32, T, Elems> : public interleave_bits_zip_impl<32, T, Elems> {};
template <typename T, unsigned Elems> struct interleave_bits_zip<64, T, Elems> : public interleave_bits_zip_impl<64, T, Elems> {};
template <unsigned Elems>             struct interleave_bits_zip<32, acc32, Elems> : public interleave_accum_bits_zip_impl<32, acc32, Elems> {};
template <unsigned Elems>             struct interleave_bits_zip<64, acc64, Elems> : public interleave_accum_bits_zip_impl<64, acc64, Elems> {};


template <unsigned TypeBits, typename T, unsigned Elems>
struct interleave_bits_unzip_impl
{
    static constexpr unsigned native_elems = 512 / TypeBits;
    using vector_type                      = vector<T, Elems>;
    using native_interleave                = interleave_bits_unzip_impl<TypeBits, T, native_elems>;

    __aie_inline
    static std::pair<vector_type, vector_type> run(const vector_type &v, const vector_type &w, unsigned step)
    {
        const shuffle_mode<TypeBits, Elems> mode{step, shuffle_unzip_tag{}};
        return run(v, w, mode);
    }

    __aie_inline
    static std::pair<vector_type, vector_type> run(const vector_type &v, const vector_type &w,
                                                   const shuffle_mode<TypeBits, Elems> &mode)
    {
        if (chess_manifest(mode.is_bypass())) {
            return {v, w};
        }

        vector_type ret1, ret2;

        if constexpr (vector_type::bits() < 512) {
            vector<T, native_elems> tmp = concat(v, w).template grow<native_elems>();

            const shuffle_mode<TypeBits, native_elems> native_mode{mode};
            auto [even, odd] = native_interleave::run(tmp, tmp, native_mode);
            ret1 = even.template extract<Elems>(0);
            ret2 = odd .template extract<Elems>(0);
        }
        else if constexpr (vector_type::bits() == 512) {
            ret1 = ::shuffle(v, w, mode.low());
            ret2 = ::shuffle(v, w, mode.high());
        }
        else if constexpr (vector_type::bits() == 1024) {
            auto v0 = v.template extract<native_elems>(0),
                 v1 = v.template extract<native_elems>(1);
            auto w0 = w.template extract<native_elems>(0),
                 w1 = w.template extract<native_elems>(1);

            if (chess_manifest(mode.is_swap())) {
                ret1 = concat(v0, w0);
                ret2 = concat(v1, w1);
            }
            else if (mode.is_bypass()) {
                return {v, w};
            }
            else {
                const shuffle_mode<TypeBits, native_elems> native_mode{mode};
                auto [even0, odd0] = native_interleave::run(v0, v1, native_mode);
                auto [even1, odd1] = native_interleave::run(w0, w1, native_mode);

                ret1 = concat(even0, even1);
                ret2 = concat(odd0, odd1);
            }
        }

        return {ret1, ret2};
    }

    __aie_inline
    static std::pair<vector<T, Elems/2>, vector<T, Elems/2>> run(const vector_type &v, unsigned step)
    {
        if constexpr (Elems <= native_elems) {
            // Avoid concat overhead when input vector is smaller than native.
            // We pass the same input twice to avoid creating a temporary
            // (the second half of the result will be discarded in the extract).
            auto w = v.template grow<native_elems>();
            auto [even, odd] = native_interleave::run(w, w, step);
            return {even.template extract<Elems / 2>(0),
                    odd .template extract<Elems / 2>(0)};
        }
        else {
            auto [lo, hi] = v.template split<Elems / 2>();
            return interleave_bits_unzip_impl<TypeBits, T, Elems / 2>::run(lo, hi, step);
        }
    }
};

template <unsigned AccumBits, typename AccumTag, unsigned Elems>
struct interleave_accum_bits_unzip_impl
{
    static constexpr unsigned native_elems = 512 / AccumBits;
    using accum_type                       = accum<AccumTag, Elems>;
    using native_interleave                = interleave_accum_bits_unzip_impl<AccumBits, AccumTag, native_elems>;

    __aie_inline
    static std::pair<accum_type, accum_type> run(const accum_type &v, const accum_type &w, unsigned step)
    {
        if (chess_manifest(step == Elems))
            return {v, w};

        const shuffle_mode<AccumBits, native_elems> mode{step, shuffle_unzip_tag{}};

        accum_type ret1, ret2;

        if constexpr (accum_type::bits() < 512) {
            accum<AccumTag, native_elems> tmp;
            tmp = concat(v, w).template grow<native_elems>();

            std::tie(tmp, std::ignore) = native_interleave::run(tmp, tmp, step);
            ret1 = tmp.template extract<Elems>(0);
            ret2 = tmp.template extract<Elems>(1);
        }
        else if constexpr (accum_type::bits() == 512) {
            using storage_t = typename accum_type::storage_t;
            using to_vector = accum_to_vector_cast<int32, AccumTag, Elems>;
            ret1 = (storage_t)::shuffle(to_vector::run(v), to_vector::run(w), mode.low());
            ret2 = (storage_t)::shuffle(to_vector::run(v), to_vector::run(w), mode.high());
        }
        else if constexpr (accum_type::bits() == 1024) {
            if (step == Elems) {
                return {v, w};
            }

            auto v0 = v.template extract<native_elems>(0),
                 v1 = v.template extract<native_elems>(1);
            auto w0 = w.template extract<native_elems>(0),
                 w1 = w.template extract<native_elems>(1);

            auto [lo1, hi1] = native_interleave::run(v0, v1, step);
            auto [lo2, hi2] = native_interleave::run(w0, w1, step);
            ret1 = concat(lo1, lo2);
            ret2 = concat(hi1, hi2);
        }

        return {ret1, ret2};
    }

    __aie_inline
    static std::pair<accum<AccumTag, Elems / 2>, accum<AccumTag, Elems / 2>> run(const accum_type &a, unsigned step)
    {
        if constexpr (Elems <= native_elems) {
            // Avoid concat overhead when input vector is smaller than native.
            // We pass the same input twice to avoid creating a temporary
            // (the second half of the result will be discarded in the extract).
            auto a2 = a.template grow<native_elems>();
            auto [odd, even] = native_interleave::run(a2, a2, step);
            return {odd.template extract<Elems / 2>(0), even.template extract<Elems / 2>(0)};
        }
        else {
            auto lo = a.template extract<Elems / 2>(0);
            auto hi = a.template extract<Elems / 2>(1);
            return interleave_accum_bits_unzip_impl<AccumBits, AccumTag, Elems / 2>::run(lo, hi, step);
        }
    }
};

template <ElemBaseType T, unsigned Elems>      struct interleave_bits_unzip< 4, T, Elems> : public interleave_bits_unzip_impl< 4, T, Elems> {};
template <ElemBaseType T, unsigned Elems>      struct interleave_bits_unzip< 8, T, Elems> : public interleave_bits_unzip_impl< 8, T, Elems> {};
template <ElemBaseType T, unsigned Elems>      struct interleave_bits_unzip<16, T, Elems> : public interleave_bits_unzip_impl<16, T, Elems> {};
template <ElemBaseType T, unsigned Elems>      struct interleave_bits_unzip<32, T, Elems> : public interleave_bits_unzip_impl<32, T, Elems> {};
template <ElemBaseType T, unsigned Elems>      struct interleave_bits_unzip<64, T, Elems> : public interleave_bits_unzip_impl<64, T, Elems> {};
template <AccumElemBaseType A, unsigned Elems> struct interleave_bits_unzip<32, A, Elems> : public interleave_accum_bits_unzip_impl<32, A, Elems> {};
template <AccumElemBaseType A, unsigned Elems> struct interleave_bits_unzip<64, A, Elems> : public interleave_accum_bits_unzip_impl<64, A, Elems> {};

}

#endif
