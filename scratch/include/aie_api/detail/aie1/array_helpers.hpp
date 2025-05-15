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

#ifndef __AIE_API_DETAIL_AIE1_ARRAY_HELPERS__HPP__
#define __AIE_API_DETAIL_AIE1_ARRAY_HELPERS__HPP__

#include <iterator>

#include "../vector.hpp"

namespace aie::detail {

template <typename Pointer, size_t ArrayElems>
struct circular_iterator_storage_static property(keep_in_registers)
{
    Pointer ptr;
    Pointer base;
    static constexpr size_t elems = ArrayElems;
};

template <typename Pointer>
struct circular_iterator_storage_dynamic property(keep_in_registers)
{
    Pointer ptr;
    Pointer base;
    size_t elems;
};

template <typename T, size_t ArrayElems, size_t Stride, aie_dm_resource Resource>
class circular_iterator property(keep_in_registers)
{
    static constexpr bool is_static()
    {
        return ArrayElems != dynamic_extent;
    }

    static constexpr bool is_stride_static()
    {
        return Stride != dynamic_extent;
    }

public:
    using        value_type = T;
    using         reference = value_type&;
    using           pointer = value_type* ;
    using iterator_category = std::forward_iterator_tag;
    using   difference_type = ptrdiff_t;

    template <bool IsStatic = is_static(), bool IsStrideStatic = is_stride_static()> requires(!IsStatic && !IsStrideStatic)
    constexpr circular_iterator(pointer ptr, size_t elems, size_t stride) :
        storage_{ptr, ptr, elems},
        stride_{stride}
    {}

    template <bool IsStatic = is_static(), bool IsStrideStatic = is_stride_static()> requires(!IsStatic && IsStrideStatic)
    constexpr circular_iterator(pointer ptr, size_t elems) :
        storage_{ptr, ptr, elems}
    {}

    template <bool IsStatic = is_static(), bool IsStrideStatic = is_stride_static()> requires(IsStatic && !IsStrideStatic)
    constexpr circular_iterator(pointer ptr, size_t stride) :
        storage_{ptr, ptr},
        stride_{stride}
    {}

    template <bool IsStatic = is_static(), bool IsStrideStatic = is_stride_static()> requires(IsStatic && IsStrideStatic)
    constexpr circular_iterator(pointer ptr) :
        storage_{ptr, ptr}
    {}

    template <bool IsStatic = is_static(), bool IsStrideStatic = is_stride_static()> requires(!IsStatic && !IsStrideStatic)
    constexpr circular_iterator(pointer ptr, pointer base, size_t elems, size_t stride) :
        storage_{ptr, base, elems},
        stride_{stride}
    {
        REQUIRES_MSG(ptr >= base, "Start address must be greater or equal to base address");
        REQUIRES_MSG(ptr < base + elems, "Start address must be less than base address plus array size");
    }

    template <bool IsStatic = is_static(), bool IsStrideStatic = is_stride_static()> requires(!IsStatic && IsStrideStatic)
    constexpr circular_iterator(pointer ptr, pointer base, size_t elems) :
        storage_{ptr, base, elems}
    {
        REQUIRES_MSG(ptr >= base, "Start address must be greater or equal to base address");
        REQUIRES_MSG(ptr < base + elems, "Start address must be less than base address plus array size");
    }

    template <bool IsStatic = is_static(), bool IsStrideStatic = is_stride_static()> requires(IsStatic && !IsStrideStatic)
    constexpr circular_iterator(pointer ptr, pointer base, size_t stride) :
        storage_{ptr, base},
        stride_{stride}
    {
        REQUIRES_MSG(ptr >= base, "Start address must be greater or equal to base address");
        REQUIRES_MSG(ptr < base + ArrayElems, "Start address must be less than base address plus array size");
    }

    template <bool IsStatic = is_static(), bool IsStrideStatic = is_stride_static()> requires(IsStatic && IsStrideStatic)
    constexpr circular_iterator(pointer ptr, pointer base) :
        storage_{ptr, base}
    {
        REQUIRES_MSG(ptr >= base, "Start address must be greater or equal to base address");
        REQUIRES_MSG(ptr < base + ArrayElems, "Start address must be less than base address plus array size");
    }

    /** \brief Advances the iterator one step.
     * Every time the iterator reaches the end, it jumps back to its base position.
     *
     * \return a reference to the iterator
     * \sa operator++(int)
     */
    circular_iterator  &operator++()
    {
        storage_.ptr = ::cyclic_add(storage_.ptr, stride_.value(), storage_.base, storage_.elems);
        return *this;
    }

    /** \brief Advances the iterator one step and returns a copy of its old state.
     *
     * \return a copy of the iterator before the increment operation took place.
     * \sa operator++()
     */
    circular_iterator   operator++(int)
    {
        circular_iterator it = *this;
        ++(*this);
        return it;
    }

    /** \brief Accesses the value in the iterator. */
    constexpr reference operator*()                                   { return *storage_.ptr;                    }

    /** \brief Accesses the value in the iterator. */
    constexpr pointer   operator->()                                  { return storage_.ptr;                     }

    /** \brief Return true if the two iterators reference the same value. */
    constexpr bool      operator==(const circular_iterator& rhs) const { return storage_.ptr == rhs.storage_.ptr; }

    /** \brief Return true if the two iterators reference different values. */
    constexpr bool      operator!=(const circular_iterator& rhs) const { return storage_.ptr != rhs.storage_.ptr; }

private:
    using storage_type = std::conditional_t<is_static(),
                                            circular_iterator_storage_static<pointer, ArrayElems>,
                                            circular_iterator_storage_dynamic<pointer>>;

    storage_type storage_;
    [[no_unique_address]] iterator_stride<Stride> stride_;
};

template <typename T, unsigned Elems, size_t ArrayElems, size_t Stride, aie_dm_resource Resource>
class vector_circular_iterator
{
    static constexpr bool is_static()
    {
        return ArrayElems != dynamic_extent;
    }

    static constexpr bool is_stride_static()
    {
        return Stride != dynamic_extent;
    }

public:
    using         elem_type = std::remove_const_t<aie_dm_resource_remove_t<T>>;
    using       vector_type = add_memory_bank_t<Resource, aie_dm_resource_set_t<vector<elem_type, Elems>, aie_dm_resource_get_v<T>>>;

    using        value_type = vector_type;
    using         reference = std::conditional_t<std::is_const_v<T>, const vector_type &, vector_type &>;
    using           pointer = std::conditional_t<std::is_const_v<T>, const vector_type *, vector_type *>;
    using iterator_category = std::forward_iterator_tag;
    using   difference_type = ptrdiff_t;

    template <bool IsStatic = is_static(), bool IsStrideStatic = is_stride_static()> requires(!IsStatic && !IsStrideStatic)
    constexpr vector_circular_iterator(T *ptr, size_t elems, size_t stride) :
        storage_{ptr, ptr, elems},
        stride_{stride}
    {
        REQUIRES_MSG(elems % Elems == 0, "Array size needs to be a multiple of vector size");
    }

    template <bool IsStatic = is_static(), bool IsStrideStatic = is_stride_static()> requires(!IsStatic && IsStrideStatic)
    constexpr vector_circular_iterator(T *ptr, size_t elems) :
        storage_{ptr, ptr, elems}
    {
        REQUIRES_MSG(elems % Elems == 0, "Array size needs to be a multiple of vector size");
    }

    template <bool IsStatic = is_static(), bool IsStrideStatic = is_stride_static()> requires(IsStatic && !IsStrideStatic)
    constexpr vector_circular_iterator(T *ptr, size_t stride) :
        storage_{ptr, ptr},
        stride_{stride}
    {
        REQUIRES_MSG(ArrayElems % Elems == 0, "Array size needs to be a multiple of vector size");
    }

    template <bool IsStatic = is_static(), bool IsStrideStatic = is_stride_static()> requires(IsStatic && IsStrideStatic)
    constexpr vector_circular_iterator(T *ptr) :
        storage_{ptr, ptr}
    {
        REQUIRES_MSG(ArrayElems % Elems == 0, "Array size needs to be a multiple of vector size");
    }

    template <bool IsStatic = is_static(), bool IsStrideStatic = is_stride_static()> requires(!IsStatic && !IsStrideStatic)
    constexpr vector_circular_iterator(T *ptr, T *base, size_t elems, size_t stride) :
        storage_{ptr, base, elems},
        stride_{stride}
    {
        REQUIRES_MSG(elems % Elems == 0, "Array size needs to be a multiple of vector size");
        REQUIRES_MSG(ptr >= base, "Start address must be greater or equal to base address");
        REQUIRES_MSG(ptr < base + elems, "Start address must be less than base address plus array size");
        REQUIRES_MSG((ptr - base) % Elems == 0, "Start address must be offset from base address by a multiple of vector size");
    }

    template <bool IsStatic = is_static(), bool IsStrideStatic = is_stride_static()> requires(!IsStatic && IsStrideStatic)
    constexpr vector_circular_iterator(T *ptr, T *base, size_t elems) :
        storage_{ptr, base, elems}
    {
        REQUIRES_MSG(elems % Elems == 0, "Array size needs to be a multiple of vector size");
        REQUIRES_MSG(ptr >= base, "Start address must be greater or equal to base address");
        REQUIRES_MSG(ptr < base + elems, "Start address must be less than base address plus array size");
        REQUIRES_MSG((ptr - base) % Elems == 0, "Start address must be offset from base address by a multiple of vector size");
    }

    template <bool IsStatic = is_static(), bool IsStrideStatic = is_stride_static()> requires(IsStatic && !IsStrideStatic)
    constexpr vector_circular_iterator(T *ptr, T *base, size_t stride) :
        storage_{ptr, base},
        stride_{stride}
    {
        REQUIRES_MSG(ArrayElems % Elems == 0, "Array size needs to be a multiple of vector size");
        REQUIRES_MSG(ptr >= base, "Start address must be greater or equal to base address");
        REQUIRES_MSG(ptr < base + ArrayElems, "Start address must be less than base address plus array size");
        REQUIRES_MSG((ptr - base) % Elems == 0, "Start address must be offset from base address by a multiple of vector size");
    }

    template <bool IsStatic = is_static(), bool IsStrideStatic = is_stride_static()> requires(IsStatic && IsStrideStatic)
    constexpr vector_circular_iterator(T *ptr, T *base) :
        storage_{ptr, base}
    {
        REQUIRES_MSG(ArrayElems % Elems == 0,   "Array size needs to be a multiple of vector size");
        REQUIRES_MSG(ptr >= base,               "Start address must be greater or equal to base address");
        REQUIRES_MSG(ptr < base + ArrayElems,   "Start address must be less than base address plus array size");
        REQUIRES_MSG((ptr - base) % Elems == 0, "Start address must be offset from base address by a multiple of vector size");
    }

    /** \brief Advances the iterator one step.
     * Every time the iterator reaches the end, it jumps back to its base position.
     *
     * \return a reference to the iterator
     * \sa operator++(int)
     */
    vector_circular_iterator  &operator++()
    {
        storage_.ptr = ::cyclic_add(storage_.ptr, Elems * stride_.value(), storage_.base, storage_.elems);
        return *this;
    }

    /** \brief Advances the iterator one step and returns a copy of its old state.
     *
     * \return a copy of the iterator before the increment operation took place.
     * \sa operator++()
     */
    vector_circular_iterator   operator++(int)
    {
        vector_circular_iterator it = *this;
        ++(*this);
        return it;
    }

    /** \brief Accesses the first `Elems` contiguous elements starting at the the iterator's current position. */
    constexpr reference operator*()                                          { return *(pointer)storage_.ptr;           }

    /** \brief Accesses the first `Elems` contiguous elements starting at the the iterator's current position. */
    constexpr pointer   operator->()                                         { return (pointer)storage_.ptr;            }

    /** \brief Return true if the two iterators reference the same value. */
    constexpr bool      operator==(const vector_circular_iterator& rhs) const { return storage_.ptr == rhs.storage_.ptr; }

    /** \brief Return true if the two iterators reference different values. */
    constexpr bool      operator!=(const vector_circular_iterator& rhs) const { return storage_.ptr != rhs.storage_.ptr; }

private:
    using storage_type = std::conditional_t<is_static(),
                                            circular_iterator_storage_static<T *, ArrayElems>,
                                            circular_iterator_storage_dynamic<T *>>;

    storage_type storage_;
    [[no_unique_address]] iterator_stride<Stride> stride_;
};

}

#endif
