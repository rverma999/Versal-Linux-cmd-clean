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

#ifndef __AIE_API_DETAIL_AIE2_BROADCAST__HPP__
#define __AIE_API_DETAIL_AIE2_BROADCAST__HPP__

#include "../../types.hpp"
#include "../accum.hpp"
#include "../vector.hpp"

namespace aie::detail {

template <typename T, unsigned Elems>
struct broadcast_bits_impl<4, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const T &a)
    {
        using next_type = utils::get_next_integer_type_t<T>;

        next_type tmp = (uint4) a | ((uint4) a << 4);

        if constexpr (Elems == 32)
            return  broadcast_bits_impl<8, next_type, Elems>::run(tmp).template extract<Elems / 2>(0).template cast_to<T>();
        else
            return  broadcast_bits_impl<8, next_type, Elems / 2>::run(tmp).template cast_to<T>();
    }
};

template <typename T, unsigned Elems>
struct broadcast_bits_impl<8, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const T &a)
    {
        constexpr unsigned native_broadcast_elems = 64;
        using native_broadcast_type = broadcast_bits_impl<8, T, native_broadcast_elems>;

        vector_type ret;

        if constexpr (Elems == 16 || Elems == 32) {
            ret = native_broadcast_type::run(a).template extract<Elems>(0);
        }
        else if constexpr (Elems == 64) {
            if constexpr (vector_type::is_signed())
                ret = ::broadcast_to_v64int8(a);
            else
                ret = ::broadcast_to_v64uint8(a);
        }
        else if constexpr (Elems == 128) {
            const auto tmp = native_broadcast_type::run(a);
            ret.insert(0, tmp);
            ret.insert(1, tmp);
        }

        return ret;
    }
};

template <typename T, unsigned Elems>
struct broadcast_bits_impl<16, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const T &a)
    {
        constexpr unsigned native_broadcast_elems = 32;
        using native_broadcast_type = broadcast_bits_impl<16, T, native_broadcast_elems>;

        vector_type ret;

        if constexpr (Elems == 8 || Elems == 16) {
            ret = native_broadcast_type::run(a).template extract<Elems>(0);
        }
        else if constexpr (Elems == 32) {
            if      constexpr (std::is_same_v<T, bfloat16>)
                ret = ::broadcast_to_v32bfloat16(a);
            else if constexpr (vector_type::is_signed())
                ret = ::broadcast_to_v32int16(a);
            else
                ret = ::broadcast_to_v32uint16(a);
        }
        else if constexpr (Elems == 64) {
            const auto tmp = native_broadcast_type::run(a);
            ret.insert(0, tmp);
            ret.insert(1, tmp);
        }

        return ret;
    }
};

template <typename T, unsigned Elems>
struct broadcast_bits_impl<32, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const T &a)
    {
        constexpr unsigned native_broadcast_elems = 16;
        using native_broadcast_type = broadcast_bits_impl<32, T, native_broadcast_elems>;

        vector_type ret;

        if constexpr (Elems == 4 || Elems == 8) {
            ret = native_broadcast_type::run(a).template extract<Elems>(0);
        }
        else if constexpr (Elems == 16) {
            if constexpr (vector_type::is_complex())
                ret = ::broadcast_to_v16cint16(a);
            else if constexpr (vector_type::is_floating_point())
                ret = ::broadcast_to_v16float(a);
            else if constexpr (vector_type::is_signed())
                ret = ::broadcast_to_v16int32(a);
            else
                ret = ::broadcast_to_v16uint32(a);
        }
        else if constexpr (Elems == 32) {
            const auto tmp = native_broadcast_type::run(a);
            ret.insert(0, tmp);
            ret.insert(1, tmp);
        }

        return ret;
    }
};

template <typename T, unsigned Elems>
struct broadcast_bits_impl<64, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const T &a)
    {
        constexpr unsigned native_broadcast_elems = 8;
        using native_broadcast_type = broadcast_bits_impl<64, T, native_broadcast_elems>;

        vector_type ret;

        if constexpr (Elems == 2 || Elems == 4) {
            ret = native_broadcast_type::run(a).template extract<Elems>(0);
        }
        else if constexpr (Elems == 8) {
#if __AIE_API_COMPLEX_FP32_EMULATION__
            if constexpr (std::is_same_v<T, cfloat>)
                ret = (v8cfloat)::broadcast_to_v8cint32(__builtin_bit_cast(cint32, a));
            else
#endif
                ret = ::broadcast_to_v8cint32(a);
        }
        else if constexpr (Elems == 16) {
            const auto tmp = native_broadcast_type::run(a);
            ret.insert(0, tmp);
            ret.insert(1, tmp);
        }

        return ret;
    }
};

template <typename T, unsigned Elems>
struct zeros_bits_impl<4, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run()
    {
        using next_type = utils::get_next_integer_type_t<T>;

        if constexpr (Elems == 32)
            return zeros_bits_impl<8, next_type, Elems>::run().template extract<Elems / 2>(0).template cast_to<T>();
        else
            return zeros_bits_impl<8, next_type, Elems / 2>::run().template cast_to<T>();
    }
};

template <typename T, unsigned Elems>
struct zeros_bits_impl<8, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run()
    {
        constexpr unsigned native_zeros_elems = 64;
        using native_zeros_type = zeros_bits_impl<8, T, native_zeros_elems>;

        vector_type ret;

        if constexpr (Elems == 16 || Elems == 32) {
            ret = native_zeros_type::run().template extract<Elems>(0);
        }
        else if constexpr (Elems == 64) {
            if constexpr (vector_type::is_signed())
                ret = ::broadcast_zero_to_v64int8();
            else
                ret = ::broadcast_zero_to_v64uint8();
        }
        else if constexpr (Elems == 128) {
            const auto tmp = native_zeros_type::run();
            ret.insert(0, tmp);
            ret.insert(1, tmp);
        }

        return ret;
    }
};

template <typename T, unsigned Elems>
struct zeros_bits_impl<16, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run()
    {
        constexpr unsigned native_zeros_elems = 32;
        using native_zeros_type = zeros_bits_impl<16, T, native_zeros_elems>;

        vector_type ret;

        if constexpr (Elems == 8 || Elems == 16) {
            ret = native_zeros_type::run().template extract<Elems>(0);
        }
        else if constexpr (Elems == 32) {
            if      constexpr (std::is_same_v<T, bfloat16>)
                ret = ::broadcast_zero_to_v32bfloat16();
            else if constexpr (vector_type::is_signed())
                ret = ::broadcast_zero_to_v32int16();
            else
                ret = ::broadcast_zero_to_v32uint16();
        }
        else if constexpr (Elems == 64) {
            const auto tmp = native_zeros_type::run();
            ret.insert(0, tmp);
            ret.insert(1, tmp);
        }

        return ret;
    }
};

template <typename T, unsigned Elems>
struct zeros_bits_impl<32, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run()
    {
        constexpr unsigned native_zeros_elems = 16;
        using native_zeros_type = zeros_bits_impl<32, T, native_zeros_elems>;

        vector_type ret;

        if constexpr (Elems == 4 || Elems == 8) {
            ret = native_zeros_type::run().template extract<Elems>(0);
        }
        else if constexpr (Elems == 16) {
            if constexpr (vector_type::is_complex())
                ret = ::broadcast_zero_to_v16cint16();
            else if constexpr (vector_type::is_floating_point())
                ret = ::broadcast_zero_to_v16float();
            else if constexpr (vector_type::is_signed())
                ret = ::broadcast_zero_to_v16int32();
            else
                ret = ::broadcast_zero_to_v16uint32();
        }
        else if constexpr (Elems == 32) {
            const auto tmp = native_zeros_type::run();
            ret.insert(0, tmp);
            ret.insert(1, tmp);
        }

        return ret;
    }
};

template <typename T, unsigned Elems>
struct zeros_bits_impl<64, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run()
    {
        constexpr unsigned native_zeros_elems = 8;
        using native_zeros_type = zeros_bits_impl<64, T, native_zeros_elems>;

        vector_type ret;

        if constexpr (Elems == 2 || Elems == 4) {
            ret = native_zeros_type::run().template extract<Elems>(0);
        }
        else if constexpr (Elems == 8) {
#if __AIE_API_COMPLEX_FP32_EMULATION__
            if constexpr (std::is_same_v<T, cfloat>)
                ret = (v8cfloat)::broadcast_zero_to_v8cint32();
            else
#endif
                ret = ::broadcast_zero_to_v8cint32();
        }
        else if constexpr (Elems == 16) {
            const auto tmp = native_zeros_type::run();
            ret.insert(0, tmp);
            ret.insert(1, tmp);
        }

        return ret;
    }
};

template <AccumClass Class, unsigned AccumBits, unsigned Elems>
struct zeros_acc_bits_impl
{
    using  accum_tag = accum_tag_t<Class, AccumBits>;
    using accum_type = accum<accum_tag, Elems>;

    __aie_inline
    static constexpr auto get_op()
    {
#if __AIE_API_COMPLEX_FP32_EMULATION__
        if constexpr (Class == AccumClass::CFP) {
            return []() {
                // Defer zeroization to the FP variant, then cast the result to a complex accumulator.
                using base             = zeros_acc_bits_impl<AccumClass::FP, AccumBits, Elems * 2>;
                constexpr auto base_op = base::get_op();
                return accum(base_op()).template cast_to<caccfloat>();
            };
        }
#endif
        if constexpr (AccumBits == 32) {
            if constexpr (Class == AccumClass::Int)  return []() { return ::broadcast_zero_to_v32acc32();    };
            if constexpr (Class == AccumClass::CInt) return []() { return ::broadcast_zero_to_v8cacc64();    };
            if constexpr (Class == AccumClass::FP)   return []() { return ::broadcast_zero_to_v16accfloat(); };
        }
        else if constexpr (AccumBits <= 64) {
            if constexpr (Class == AccumClass::Int)  return []() { return ::broadcast_zero_to_v16acc64();    };
            if constexpr (Class == AccumClass::CInt) return []() { return ::broadcast_zero_to_v8cacc64();    };
        }
    }

    __aie_inline
    static accum_type run()
    {
        auto op = get_op();
        accum tmp = op();
        accum_type ret;
        if constexpr (ret.size() <= tmp.size())
            ret = tmp.template extract<Elems>(0);
        else
            utils::unroll_times<ret.size() / tmp.size()>([&](auto idx) __aie_inline {
                ret.insert(idx, tmp);
            });
        return ret;
    }
};

}

#endif
