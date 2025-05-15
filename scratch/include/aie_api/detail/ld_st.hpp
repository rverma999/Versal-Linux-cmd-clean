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

#ifndef __AIE_API_DETAIL_LD_ST__HPP__
#define __AIE_API_DETAIL_LD_ST__HPP__

#include "accum.hpp"
#include "vector.hpp"

namespace aie::detail {

static constexpr unsigned vector_decl_align = AIE_VECTOR_LDST_ALIGN;

#if __AIE_ARCH__ == 10

template <typename T, unsigned Elems>
struct vector_ldst_align
{
    static constexpr unsigned value = 16;
};

#elif __AIE_ARCH__ == 20

template <typename T, unsigned Elems>
struct vector_ldst_align
{
    static constexpr unsigned value = (detail::type_bits_v<T> * Elems == 128)? 16 : 32;
};

#endif

template <typename T, unsigned Elems>
static constexpr unsigned vector_ldst_align_v = vector_ldst_align<T, Elems>::value;

namespace utils {

// This function is used to mimic hardware pointer semantics on Native
// i.e. truncate the pointer to perform an aligned load.
//
// Default behaviour is to truncate the pointer to the native load size.
// Passing a number of elements as a template parameter can be used to
// truncate the pointer as required for an aligned load of the given size.
template <unsigned Elems, typename T>
__aie_inline
constexpr T *floor_ptr(T *ptr)
{
#if AIE_API_NATIVE == 1
    constexpr uintptr_t mask = ~(vector_ldst_align_v<T, Elems> - 1);

    return (T *)((uintptr_t)ptr & mask);
#else
    // Rely on automatic HW truncation for enhanced performance
    return ptr;
#endif
}

template <typename T>
__aie_inline
constexpr T *floor_ptr(T *ptr)
{
    return floor_ptr<native_vector_length_v<T>, T>(ptr);
}

}

template <typename T, unsigned Elems, aie_dm_resource Resource>
struct load_vector_helper
{
    using vector_type = vector<aie_dm_resource_remove_t<T>, Elems>;

    __aie_inline
    static vector_type run(const T *ptr)
    {
        vector_type ret;

#ifdef AIE_API_EMULATION
        for (unsigned i = 0; i < Elems; ++i)
            ret.data[i] = ptr[i];
#else
        ret.template load<Resource>(ptr);
#endif

        return ret;
    }
};

template <typename T, unsigned Elems, aie_dm_resource Resource>
struct store_vector_helper
{
    using vector_type = vector<aie_dm_resource_remove_t<T>, Elems>;

    __aie_inline
    static T *run(T *ptr, const vector_type &v)
    {
#ifdef AIE_API_EMULATION
        for (unsigned i = 0; i < Elems; ++i)
            ptr[i] = v.data[i];
#else
        v.template store<Resource>(ptr);
#endif

        return ptr;
    }
};

template <typename T, unsigned Elems, aie_dm_resource Resource>
struct load_unaligned_vector_helper
{
    using vector_type = vector<aie_dm_resource_remove_t<T>, Elems>;

    __aie_inline
    static vector_type run(const T *ptr, unsigned aligned_elems)
    {
        vector_type ret;

#ifdef AIE_API_EMULATION
        for (unsigned i = 0; i < Elems; ++i)
            ret.data[i] = ptr[i];
#else
        ret.template load_unaligned<Resource>(ptr, aligned_elems);
#endif

        return ret;
    }
};

template <typename T, unsigned Elems, aie_dm_resource Resource>
struct store_unaligned_vector_helper
{
    using vector_type = vector<aie_dm_resource_remove_t<T>, Elems>;

    __aie_inline
    static T *run(T *ptr, const vector_type &v, unsigned aligned_elems)
    {
#ifdef AIE_API_EMULATION
        for (unsigned i = 0; i < Elems; ++i)
            ptr[i] = v.data[i];
#else
        v.template store_unaligned<Resource>(ptr, aligned_elems);
#endif

        return ptr;
    }
};

template <unsigned Elems, aie_dm_resource Resource = aie_dm_resource::none, typename T>
__aie_inline
auto load_vector(const T *ptr)
{
    return load_vector_helper<T, Elems, Resource>::run(ptr);
}

template <unsigned Elems, aie_dm_resource Resource = aie_dm_resource::none, typename T>
__aie_inline
auto load_unaligned_vector(const T *ptr, unsigned aligned_elems = 1)
{
    return load_unaligned_vector_helper<T, Elems, Resource>::run(ptr, aligned_elems);
}

template <unsigned Elems, aie_dm_resource Resource = aie_dm_resource::none, typename T1, typename T2>
__aie_inline
T1 *store_vector(T1 *ptr, const vector<T2, Elems> &v)
{
    return store_vector_helper<T1, Elems, Resource>::run(ptr, v);
}

template <unsigned Elems, aie_dm_resource Resource = aie_dm_resource::none, typename T1, typename T2>
__aie_inline
T1 *store_unaligned_vector(T1 *ptr, const vector<T2, Elems> &v, unsigned aligned_elems = 1)
{
    return store_unaligned_vector_helper<T1, Elems, Resource>::run(ptr, v, aligned_elems);
}

template <unsigned Elems, typename T>
__attribute__((pure))
constexpr bool check_vector_alignment(const T *ptr)
{
    return (uintptr_t(ptr) % vector_ldst_align_v<aie_dm_resource_remove_t<T>, Elems>) == 0;
}

template <typename T>
__attribute__((pure))
constexpr bool check_alignment(const T *ptr, unsigned aligned_elems)
{
    return (uintptr_t(ptr) % ((detail::type_bits_v<aie_dm_resource_remove_t<T>> * aligned_elems) / 8)) == 0;
}

}

#endif
