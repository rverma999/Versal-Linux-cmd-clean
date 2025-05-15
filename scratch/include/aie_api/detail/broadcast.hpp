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

#ifndef __AIE_API_DETAIL_BROADCAST__HPP__
#define __AIE_API_DETAIL_BROADCAST__HPP__

#include "utils.hpp"

#include "../concepts.hpp"
#include "../accum.hpp"
#include "../vector.hpp"

namespace aie::detail {

template <unsigned TypeBits, typename T, unsigned Elems>
struct broadcast_bits_impl
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    using vector_type = vector<T, Elems>;

    static vector_type run(T a)
    {
        vector_type ret;

        for (unsigned i = 0; i < Elems; ++i)
            ret[i] = a;

        return ret;
    }
#endif
};

template <unsigned TypeBits, typename T, unsigned Elems>
struct zeros_bits_impl
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    using vector_type = vector<T, Elems>;

    static vector_type run()
    {
        vector_type ret;

        for (unsigned i = 0; i < Elems; ++i) {
            if constexpr (vector_type::is_complex())
                ret[i] = T({0, 0});
            else
                ret[i] = T(0);
        }

        return ret;
    }
#endif
};

template <unsigned TypeBits, typename T, unsigned Elems>
struct broadcast_bits
{
    using vector_type = vector<T, Elems>;

    static vector_type run(const T &a)
    {
        return broadcast_bits_impl<TypeBits, T, Elems>::run(a);
    }

    template <unsigned Elems2>
    static vector_type run(vector_elem_const_ref<T, Elems2> a)
    {
#if __AIE_ARCH__ == 10
        return broadcast_bits_impl<TypeBits, T, Elems>::run(a);
#else
        return run(a.get());
#endif
    }
};

template <typename T, unsigned Elems>
using broadcast = broadcast_bits<type_bits_v<T>, T, Elems>;

template <unsigned TypeBits, typename T, unsigned Elems>
struct zeros_bits
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run()
    {
#if __AIE_ARCH__ == 10
        if constexpr (vector_type::bits() == 128) {
            const vector<int32, 4> tmp(*(v4int32 *)ZERO);
            return vector_cast<T>(tmp);
        }
        else if constexpr (vector_type::bits() == 256) {
            const vector<int32, 8> tmp(*(v8int32 *)ZERO);
            return vector_cast<T>(tmp);
        }
        else if constexpr (vector_type::bits() == 512) {
            const vector<int32, 8> tmp(*(v8int32 *)ZERO);
            return vector_cast<T>(concat_vector(tmp, tmp));
        }
        else if constexpr (vector_type::bits() == 1024) {
            const vector<int32, 8> tmp(*(v8int32 *)ZERO);
            return vector_cast<T>(concat_vector(tmp, tmp, tmp, tmp));
        }
#else
        if constexpr (vector_type::is_complex())
            return zeros_bits_impl<TypeBits, T, Elems>::run();
        else
            return zeros_bits_impl<TypeBits, T, Elems>::run();
#endif
    }
};

template <typename T, unsigned Elems>
using zeros = zeros_bits<type_bits_v<T>, T, Elems>;


template <AccumClass Class>
struct zeros_type_for_accum;

template <AccumClass Class>
using zeros_type_for_accum_t = typename zeros_type_for_accum<Class>::type;

template <> struct zeros_type_for_accum<AccumClass::Int>  { using type = int32;    };
template <> struct zeros_type_for_accum<AccumClass::CInt> { using type = cint32;   };
#if __AIE_ARCH__ == 10
template <> struct zeros_type_for_accum<AccumClass::FP>   { using type = float;    };
#elif __AIE_ARCH__ == 20
template <> struct zeros_type_for_accum<AccumClass::FP>   { using type = float;    };
#endif
#if __AIE_ARCH__ == 10 || __AIE_API_COMPLEX_FP32_EMULATION__
template <> struct zeros_type_for_accum<AccumClass::CFP>  { using type = cfloat;   };
#endif

template <AccumClass Class, unsigned AccumBits, unsigned Elems>
struct zeros_acc_bits_impl;

template <AccumClass Class, unsigned AccumBits, unsigned Elems>
struct zeros_acc_bits
{
    using accum_tag  = accum_tag_t<Class, AccumBits>;
    using accum_type = accum<accum_tag, Elems>;

    __aie_inline
    static accum_type run()
    {
#if __AIE_ARCH__ == 10
        using zeros_type = zeros_type_for_accum_t<Class>;
        accum_type ret;

        constexpr unsigned num_accums = std::max(1u, (unsigned)(type_bits_v<zeros_type> * Elems) / 1024);

        accum<accum_tag, Elems / num_accums> tmp;
        tmp.from_vector(zeros<zeros_type, Elems / num_accums>::run());
        utils::unroll_for<unsigned, 0, num_accums>([&](auto idx) __aie_inline {
            ret.template insert<Elems / num_accums>(idx, tmp);
        });

        return ret;
#else
        return zeros_acc_bits_impl<Class, AccumBits, Elems>::run();
#endif
    }
};

template <AccumClass Class, unsigned AccumBits, unsigned Elems>
using zeros_acc = zeros_acc_bits<Class, AccumBits, Elems>;


}

#if __AIE_ARCH__ == 10

#include "aie1/broadcast.hpp"

#elif __AIE_ARCH__ == 20

#include "aie2/broadcast.hpp"

#endif

#endif
