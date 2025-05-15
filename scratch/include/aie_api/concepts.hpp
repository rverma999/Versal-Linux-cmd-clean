// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
/*  (c) Copyright 2020 - 2023 Xilinx, Inc. All rights reserved.

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

/**
 * @file
 * @brief Concepts exposed to users.
 */

#pragma once

#ifndef __AIE_API_CONCEPTS__HPP__
#define __AIE_API_CONCEPTS__HPP__

#include "detail/config.hpp"

#include "types.hpp"

namespace aie {

template <typename T> struct is_accum_op;

template <typename T> struct is_vector_op;

template <typename T> struct is_sparse_vector_op;

template <typename T> struct is_elem;

template <typename T> struct is_elem_op;

template <typename T> struct operand_base_type;

namespace detail {

template <typename T> struct is_valid_element_type;

template <typename ...Ts>
static constexpr bool is_valid_element_type_v = (is_valid_element_type<Ts>::value && ...);

template <typename T> struct is_valid_accum_type;

template <typename T>
static constexpr bool is_valid_accum_type_v = is_valid_accum_type<T>::value;

template <typename T> struct is_accum;

template <typename T>
static constexpr bool is_accum_v = is_accum<T>::value;

template <typename T> struct is_vector;

template <typename T>
static constexpr bool is_vector_v = is_vector<T>::value;

template <typename T> struct is_vector_ref;

template <typename T>
static constexpr bool is_vector_ref_v = is_vector_ref<T>::value;

template <typename T> struct is_sparse_vector;

template <typename T>
static constexpr bool is_sparse_vector_v = is_sparse_vector<T>::value;

template <typename T> struct is_mask;

template <typename T>
static constexpr bool is_mask_v = is_mask<T>::value;

template <typename T> struct is_vector_elem_ref;

template <typename T>
static constexpr bool is_vector_elem_ref_v = is_vector_elem_ref<T>::value;

template <typename T> struct is_complex;

template <typename T>
static constexpr bool is_complex_v = is_complex<T>::value;

template <typename T> struct is_integral;

template <typename T>
static constexpr bool is_integral_v = is_integral<T>::value;

template <typename T> struct is_floating_point;

template <typename T>
static constexpr bool is_floating_point_v = is_floating_point<T>::value;

template <typename T> struct is_signed;

template <typename T>
static constexpr bool is_signed_v = is_signed<T>::value;

template <typename T>
struct is_unsigned
{
    static constexpr bool value = !is_signed<T>::value;
};


template <typename T>
static constexpr bool is_unsigned_v = is_unsigned<T>::value;

template <typename T>
static constexpr bool is_vector_or_op_v = is_vector<aie_dm_resource_remove_t<T>>::value ||
                                          is_vector_ref<aie_dm_resource_remove_t<T>>::value ||
                                          is_vector_op<T>::value;

template <typename T>
static constexpr bool is_sparse_vector_or_op_v = is_sparse_vector<aie_dm_resource_remove_t<T>>::value ||
                                                 is_sparse_vector_op<T>::value;

template <typename T>
static constexpr bool is_accum_or_op_v = is_accum<T>::value || is_accum_op<T>::value;

template <typename T>
static constexpr bool is_elem_or_op_v = is_elem<T>::value || is_elem_op<T>::value;

template <typename T> struct native_vector_traits;
template <typename T> struct native_accum_traits;

} // namespace detail

template <typename T>
struct is_elem {
    static constexpr bool value = detail::is_valid_element_type<T>::value || detail::is_vector_elem_ref<T>::value;
};

/**
 * @ingroup group_basic_types_concepts
 *
 * @concept aie::ElemBaseType
 * Concept for all the basic types that can be used in operations and as vector element type.
 *
 * \sa @ref vector_valid_parameters "Supported vector types and sizes".
 */
template <typename T>
concept ElemBaseType      = detail::is_valid_element_type<T>::value;

/**
 * @ingroup group_basic_types_concepts
 *
 * @concept aie::Elem
 * Concept for element operands. It can be a value that meets aie::ElemBaseType or a vector element reference.
 */
template <typename T>
concept Elem = ElemBaseType<T> || detail::is_vector_elem_ref<T>::value;

/**
 * @ingroup group_basic_types_concepts
 *
 * @concept aie::ComplexElem
 * Concept similar to aie::Elem, but it only accepts complex types.
 */
template <typename T>
concept ComplexElem = Elem<T> && detail::is_complex<typename operand_base_type<T>::type>::value;

/**
 * @ingroup group_basic_types_concepts
 *
 * @concept aie::RealElem
 * Concept similar to aie::Elem, but it only accepts real (i.e. non-complex) types.
 */
template <typename T>
concept RealElem = Elem<T> && !detail::is_complex<typename operand_base_type<T>::type>::value;

/**
 * @ingroup group_basic_types_concepts
 *
 * @concept aie::ElemOrOp
 * Concept that allows aie::Elem or an element operation modifier.
 */
template <typename T>
concept ElemOrOp = detail::is_elem_or_op_v<T>;

/**
 * @ingroup group_basic_types_concepts
 *
 * @concept aie::Vector
 * Concept for vector types. Accepts any aie::vector, aie::vector_ref or aie::unaligned_vector_ref type.
 */
template <typename T>
concept Vector = detail::is_vector<aie_dm_resource_remove_t<T>>::value || detail::is_vector_ref<aie_dm_resource_remove_t<T>>::value;

/**
 * @ingroup group_basic_types_concepts
 *
 * @concept aie::ComplexVector
 * Similar to aie::Vector, but it only accepts vectors with complex element types.
 */
template <typename T>
concept ComplexVector = Vector<T> && T::is_complex();

/**
 * @ingroup group_basic_types_concepts
 *
 * @concept aie::RealVector
 * Similar to aie::Vector, but it only accepts vectors with real element types.
 */
template <typename T>
concept RealVector = Vector<T> && !T::is_complex();

/**
 * @ingroup group_basic_types_concepts
 *
 * @concept aie::VectorOrOp
 * Concept that allows aie::Vector or a vector operation modifier.
 */
template <typename T>
concept VectorOrOp = detail::is_vector_or_op_v<T>;

/**
 * @ingroup group_basic_types_concepts
 *
 * @concept aie::SparseVector
 * Concept for vector types. Accepts any aie::sparse_vector type.
 */
template <typename T>
concept SparseVector = detail::is_sparse_vector<aie_dm_resource_remove_t<T>>::value;

/**
 * @ingroup group_basic_types_concepts
 *
 * @concept aie::SparseVectorOrOp
 * Concept that allows aie::SparseVector or a vector operation modifier.
 */
template <typename T>
concept SparseVectorOrOp = detail::is_sparse_vector_or_op_v<T>;

/**
 * @ingroup group_basic_types_concepts
 *
 * @concept aie::Accum
 * Concept for accumulator types. Accepts any aie::accum type.
 */
template <typename T>
concept Accum = detail::is_accum<aie_dm_resource_remove_t<T>>::value;

/**
 * @ingroup group_basic_types_concepts
 *
 * @concept aie::AccumOrOp
 * Concept that allows aie::Accum or an accumulator operation modifier.
 */
template <typename T>
concept AccumOrOp = detail::is_accum_or_op_v<T>;

/**
 * @ingroup group_basic_types_concepts
 *
 * @concept aie::Mask
 * Concept for mask types. Accepts any aie::mask type.
 */
template <typename T>
concept Mask = detail::is_mask<T>::value;

/**
 * @ingroup group_basic_types_concepts
 *
 * @concept aie::DecoratedElemBaseType
 * Concept for the pointers to basic types that can be used in operations and as vector element type.
 */
template <typename T>
concept DecoratedElemBaseType = detail::is_valid_element_type<std::remove_const_t<aie_dm_resource_remove_t<T>>>::value;

/**
 * @ingroup group_basic_types_concepts
 *
 * @concept aie::AccumElemBaseType
 * Concept for the supported accumulator element types.
 *
 * \sa @ref accum_valid_parameters "Supported accumulator types and sizes".
 */
template <typename T>
concept AccumElemBaseType = detail::is_valid_accum_type<T>::value || std::is_same<T, accauto>::value;

template <typename T>
concept NativeVectorType = requires { typename detail::native_vector_traits<T>::value_type; };

template <typename T>
concept NativeAccumType = requires { typename detail::native_accum_traits<T>::value_type; };

} // namespace aie

#endif // __AIE_API_CONCEPTS__HPP__
