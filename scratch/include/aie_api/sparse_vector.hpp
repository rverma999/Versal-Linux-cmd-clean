// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
/*  (c) Copyright 2021 - 2023 Xilinx, Inc. All rights reserved.

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

#ifndef __AIE_API_SPARSE_VECTOR__HPP__
#define __AIE_API_SPARSE_VECTOR__HPP__

#include "detail/config.hpp"
#include "detail/utils.hpp"
#include "detail/vector.hpp"

#if __AIE_ARCH__ == 20

#include "detail/aie2/sparse_vector_native_types.hpp"

#endif

#include "vector.hpp"
#include "concepts.hpp"

#include <type_traits>

namespace aie {

template <ElemBaseType T, unsigned N>
    requires(arch::is(arch::AIE_ML))
class sparse_vector;

namespace detail {

template <typename T>
struct is_sparse_vector
{
    static constexpr bool value = false;
};

template <typename T, unsigned Elems>
struct is_sparse_vector<sparse_vector<T, Elems>>
{
    static constexpr bool value = true;
};

template <typename T, unsigned Elems>
struct sparse_vector_storage;

template <typename T, unsigned Elems>
using sparse_vector_storage_t = typename sparse_vector_storage<T, Elems>::type;

template <typename T>
struct is_valid_sparse_element_type;

template <typename T, unsigned Elems>
struct native_sparse_vector_type
{
    using type = void;
};

template <typename T, unsigned Elems>
using native_sparse_vector_type_t = typename native_sparse_vector_type<T, Elems>::type;

template <typename T>
struct native_vector_traits;

template <typename T>
concept NativeSparseVector = requires {
    typename native_vector_traits<T>::value_type;
    requires native_vector_traits<T>::elems > 0;
};

} // namespace aie::detail

template <ElemBaseType T, unsigned Elems>
    requires(arch::is(arch::AIE_ML))
class __AIE_API_FUNDAMENTAL_TYPE__ sparse_vector
{
private:
    template <ElemBaseType T2, unsigned Elems2>
         requires(arch::is(arch::AIE_ML))
    friend class sparse_vector;

public:
    using vector_storage_type = detail::sparse_vector_storage<T, Elems>;

    /** \brief Equivalent intrinsic type for the same element type and size. */
    using         native_type = detail::native_sparse_vector_type_t<T, Elems>;

    /** \brief Type that holds the actual sparse_vector's data. May be different to its native type. */
    using           storage_t = typename vector_storage_type::type;

    /** \brief Intrinsic type of pointers referring to data stored in sparse format. */
    using native_pointer_type = typename vector_storage_type::pointer_type;

    /** \brief Type of the elements in the sparse_vector. */
    using          value_type = T;

    /**
     * \brief Returns the size of each vector element in bits.
     */
    static constexpr unsigned type_bits()
    {
        return detail::type_bits_v<T>;
    }

    /**
     * \brief Returns the number of elements in the vector.
     */
    static constexpr unsigned size()
    {
        return Elems;
    }

    static constexpr unsigned sparsity_ratio()
    {
        return 2;
    }

    static constexpr unsigned mask_bits()
    {
        // 1b per byte in the mask
        return (Elems * type_bits()) / 8;
    }

    static constexpr unsigned bytes()
    {
        static_assert(bits() % 8 == 0);

        return bits() / 8;
    }

    static constexpr unsigned bits()
    {
        unsigned res = Elems * type_bits();

        return res;
    }

    static constexpr unsigned memory_bytes()
    {
        return memory_bits() / 8;
    }

    static constexpr unsigned memory_bits()
    {
        unsigned res = (Elems / sparsity_ratio()) * type_bits();

        res += mask_bits();

        return res;
    }

    /**
     * \brief Returns true if the element type is signed.
     */
    static constexpr bool is_signed()
    {
        return detail::is_signed_v<T>;
    }

    /**
     * \brief Returns true if the element type is a complex number.
     */
    static constexpr bool is_complex()
    {
        return detail::is_complex_v<T>;
    }

    /**
     * \brief Returns true if the element type is an integer.
     */
    static constexpr bool is_integral()
    {
        return detail::is_integral_v<T>;
    }

    /**
     * \brief Returns true if the element type is floating-point.
     */
    static constexpr bool is_floating_point()
    {
        return detail::is_floating_point_v<T>;
    }

    /**
     * \brief Default constructor. The value of the elements is undefined.
     */
    sparse_vector() = default;

    /**
     * \brief Construct a sparse_vector from internal native types.
     *
     * @param data Data used to construct the vector from.
     */
    __aie_inline
    sparse_vector(const storage_t &data) :
        data(data)
    {
    }

    /**
     * \brief Returns the value of the vector using its native type.
     */
    __aie_inline
    operator native_type() const
        requires(size() != 128 || !std::is_same_v<T, bfloat16>)
        // No v128bfloat16_sparse in the compiler
    {
        return to_native();
    }

    /**
     * \brief Returns the value of the element on the given index.
     *
     * @warning Currently not implemented.
     *
     * @param idx Index of the element.
     */
    // TODO: can be emulated?
    __aie_inline
    value_type get(unsigned idx) const
    {
        REQUIRES_MSG(idx < Elems, "idx needs to be a valid element index");

        UNREACHABLE_MSG("Not implemented");
    }

    /**
     * \brief Updates the contents of a region of the sparse_vector.
     *
     * The updated region will contain the values in the given subvector.
     *
     * @param idx Index of the subvector to be replaced.
     * @param v Subvector to be written into the region.
     * @returns a reference to the updated vector.
     */
    template <unsigned ElemsIn>
    __aie_inline
    sparse_vector &insert(unsigned idx, const sparse_vector<T, ElemsIn> &v)
        requires(ElemsIn == Elems / 2 || ElemsIn == Elems)
    {
        REQUIRES_MSG(idx < Elems / ElemsIn, "idx needs to be a valid subvector index");

        if constexpr (ElemsIn == Elems) {
            data = v.data;
        }
        else {
            data[idx] = v.data;
        }

        return *this;
    }

    /**
     * \brief Returns a subvector with the contents of a region of the sparse_vector.
     *
     * @tparam ElemsOut Size of the returned subvector.
     * @param idx Index of the subvector to be returned.
     */
    template <unsigned Elems2>
    __aie_inline
    sparse_vector<T, Elems2> extract(unsigned idx) const
        requires(Elems2 == Elems / 2)
    {
        if constexpr (detail::utils::num_elems_v<storage_t> == 2) {
            return data[idx];
        }
    }

    /**
     * \brief Returns an aie::vector holding the contents in dense representation.
     */
    __aie_inline
    vector<T, Elems / 2> extract_data() const
    // Even though this type won't be instantiate in unsupported architectures,
    // ::extract_sparse_data does not exist in AIE1 and will trigger a compiler error. 
#if __AIE_ARCH__ == 20
    {
        if constexpr (detail::utils::num_elems_v<storage_t> == 2 || bytes() == 256) {
            vector<T, Elems / 2> ret;

            ret.template insert<Elems / 4>(0, this->extract<Elems / 2>(0).extract_data());
            ret.template insert<Elems / 4>(1, this->extract<Elems / 2>(1).extract_data());

            return ret;
        }
        else {
            return ::extract_sparse_data(data);
        }
    }
#else
        = delete;
#endif

private:
    __aie_inline
    native_type to_native() const
        requires(size() != 128 || !std::is_same_v<T, bfloat16>)
        // No v128bfloat16_sparse in the compiler
    {
        // TODO: verify performance of the ::concat approach
        if constexpr (detail::utils::num_elems_v<storage_t> == 2)
            return ::concat(data[0], data[1]);
        else
            return data;
    }

    storage_t data;
};

/**
 * \brief Template deduction guidelines for aie::sparse_vector
 */
template <detail::NativeSparseVector T>
sparse_vector(T) -> sparse_vector<typename detail::native_vector_traits<T>::value_type, detail::native_vector_traits<T>::size>;

} // namespace aie

#endif // __AIE_API_SPARSE_VECTOR__HPP__
