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

/**
 * @file
 * @brief Expression templates types.
 */

#pragma once

#ifndef __AIE_API_EXPR__HPP__
#define __AIE_API_EXPR__HPP__

#include "aie_types.hpp"

namespace aie {

enum class Operation
{
    None,

    Acc_Add,
    Acc_Sub,

    Abs,
    Conj,
    Transpose,

    // Binary
    Max,
    Min,
    Sign,
    Zero,
};

template <typename Parent, Operation Op>
struct unary_op;

template <typename Parent1, typename Parent2, Operation Op>
struct binary_op;

template <typename T>
struct is_unary_op
{
    static constexpr bool value = false;
};

template <typename Parent, Operation Op>
struct is_unary_op<unary_op<Parent, Op>>
{
    static constexpr bool value = true;
};

template <typename T>
struct is_binary_op
{
    static constexpr bool value = false;
};

template <typename Parent1, typename Parent2, Operation Op>
struct is_binary_op<binary_op<Parent1, Parent2, Op>>
{
    static constexpr bool value = true;
};

template <typename T>
struct is_complex_op
{
    static constexpr bool value = false;
};

template <typename Parent, Operation Op>
struct is_complex_op<unary_op<Parent, Op>>
{
    static constexpr bool value = detail::is_complex_v<typename unary_op<Parent, Op>::result_type>;
};

template <typename Parent1, typename Parent2, Operation Op>
struct is_complex_op<binary_op<Parent1, Parent2, Op>>
{
    static constexpr bool value = detail::is_complex_v<typename binary_op<Parent1, Parent2, Op>::result_type>;
};

template <typename T>
struct is_real_op
{
    static constexpr bool value = !is_complex_op<T>::value;
};

template <typename T>
struct is_elem_op
{
    static constexpr bool value = false;
};

template <typename Parent, Operation Op>
struct is_elem_op<unary_op<Parent, Op>>
{
    static constexpr bool value = unary_op<Parent, Op>::size() == 1;
};

template <typename Parent1, typename Parent2, Operation Op>
struct is_elem_op<binary_op<Parent1, Parent2, Op>>
{
    static constexpr bool value = binary_op<Parent1, Parent2, Op>::size() == 1;
};

template <typename T>
struct is_vector_op
{
    static constexpr bool value = false;
};

template <typename Parent, Operation Op>
struct is_vector_op<unary_op<Parent, Op>>
{
    static constexpr bool value = detail::is_vector_v<typename unary_op<aie_dm_resource_remove_t<Parent>, Op>::result_type>;
};

template <typename Parent1, typename Parent2, Operation Op>
struct is_vector_op<binary_op<Parent1, Parent2, Op>>
{
    static constexpr bool value = detail::is_vector_v<typename binary_op<aie_dm_resource_remove_t<Parent1>,
                                                                         aie_dm_resource_remove_t<Parent2>, Op>::result_type>;
};

template <typename T>
struct is_sparse_vector_op
{
    static constexpr bool value = false;
};

template <typename Parent, Operation Op>
struct is_sparse_vector_op<unary_op<Parent, Op>>
{
    static constexpr bool value = detail::is_sparse_vector_v<typename unary_op<aie_dm_resource_remove_t<Parent>, Op>::result_type>;
};

template <typename Parent1, typename Parent2, Operation Op>
struct is_sparse_vector_op<binary_op<Parent1, Parent2, Op>>
{
    static constexpr bool value = detail::is_sparse_vector_v<typename binary_op<aie_dm_resource_remove_t<Parent1>,
                                                                                aie_dm_resource_remove_t<Parent2>, Op>::result_type>;
};

template <typename T>
struct is_accum_op
{
    static constexpr bool value = false;
};

template <typename Parent, Operation Op>
struct is_accum_op<unary_op<Parent, Op>>
{
    static constexpr bool value = detail::is_accum_v<typename unary_op<Parent, Op>::result_type>;
};

template <typename Parent1, typename Parent2, Operation Op>
struct is_accum_op<binary_op<Parent1, Parent2, Op>>
{
    static constexpr bool value = detail::is_accum_v<typename binary_op<Parent1, Parent2, Op>::result_type>;
};

template <typename T>
struct is_mmul_op
{
    static constexpr bool value = false;
};

template <typename T>
static constexpr bool is_unary_op_v  = is_unary_op<T>::value;

template <typename T>
static constexpr bool is_binary_op_v = is_binary_op<T>::value;

template <typename T>
static constexpr bool is_op_v = is_unary_op_v<T> || is_binary_op_v<T>;

template <typename T>
static constexpr bool is_complex_op_v  = is_complex_op<T>::value;

template <typename T>
static constexpr bool is_real_op_v  = is_real_op<T>::value;

template <typename T>
static constexpr bool is_elem_op_v   = is_elem_op<T>::value;

template <typename T>
static constexpr bool is_vector_op_v = is_vector_op<T>::value;

template <typename T>
static constexpr bool is_sparse_vector_op_v = is_sparse_vector_op<T>::value;

template <typename T>
static constexpr bool is_accum_op_v  = is_accum_op<T>::value;

template <typename T>
struct op_value_type_helper
{
    using type = T;
};

template <typename T, unsigned Elems>
struct op_value_type_helper<vector<T, Elems>>
{
    using type = typename vector<T, Elems>::value_type;
};

template <typename T, unsigned Elems>
struct op_value_type_helper<sparse_vector<T, Elems>>
{
    using type = typename sparse_vector<T, Elems>::value_type;
};

template <typename T, unsigned Elems, aie_dm_resource Resource>
struct op_value_type_helper<vector_ref<T, Elems, Resource>>
{
    using type = typename vector_ref<T, Elems, Resource>::value_type;
};

template <typename T, unsigned Elems, aie_dm_resource Resource>
struct op_value_type_helper<unaligned_vector_ref<T, Elems, Resource>>
{
    using type = typename unaligned_vector_ref<T, Elems, Resource>::value_type;
};

template <typename T, unsigned Elems>
struct op_value_type_helper<vector_elem_ref<T, Elems>>
{
    using type = typename vector_elem_ref<T, Elems>::value_type;
};

template <typename T, unsigned Elems>
struct op_value_type_helper<vector_elem_const_ref<T, Elems>>
{
    using type = typename vector_elem_const_ref<T, Elems>::value_type;
};

template <typename Parent, Operation Op>
struct op_value_type_helper<unary_op<Parent, Op>>
{
    using type = typename unary_op<Parent, Op>::value_type;
};

template <typename Parent1, typename Parent2, Operation Op>
struct op_value_type_helper<binary_op<Parent1, Parent2, Op>>
{
    using type = typename binary_op<Parent1, Parent2, Op>::value_type;
};

template <typename T, Operation Op>
struct op_result_helper
{
    using type = T;
};

template <typename Parent>
struct op_result_helper<Parent, Operation::None>
{
    using type = Parent;
};

template <typename T, unsigned Elems, aie_dm_resource Resource, Operation Op> requires(Op != Operation::None)
struct op_result_helper<vector_ref<T, Elems, Resource>, Op>
{
    using type = vector<T, Elems>;
};

template <typename T, unsigned Elems, aie_dm_resource Resource, Operation Op> requires(Op != Operation::None)
struct op_result_helper<unaligned_vector_ref<T, Elems, Resource>, Op>
{
    using type = vector<T, Elems>;
};

template <typename T, unsigned Elems, Operation Op> requires(Op != Operation::None)
struct op_result_helper<vector_elem_ref<T, Elems>, Op>
{
    using type = T;
};

template <typename T, unsigned Elems, Operation Op> requires(Op != Operation::None)
struct op_result_helper<vector_elem_const_ref<T, Elems>, Op>
{
    using type = T;
};

template <typename Parent, Operation ParentOp, Operation Op>
struct op_result_helper<unary_op<Parent, ParentOp>, Op>
{
    using type = typename op_result_helper<typename unary_op<Parent, ParentOp>::result_type, Op>::type;
};

template <typename Parent1, typename Parent2, Operation ParentOp, Operation Op>
struct op_result_helper<binary_op<Parent1, Parent2, ParentOp>, Op>
{
    using type = typename op_result_helper<typename binary_op<Parent1, Parent2, ParentOp>::result_type, Op>::type;
};

template <typename T, Operation Op>
using op_result_type_t = typename op_result_helper<T, Op>::type;

template <typename T>
using op_value_type_t = typename op_value_type_helper<aie_dm_resource_remove_t<T>>::type;

template <typename Parent, Operation Op>
struct unary_op_common
{
    using parent1_type = aie_dm_resource_remove_t<Parent>;
    using result_type = op_result_type_t<parent1_type, Op>;
    using  value_type = op_value_type_t<result_type>;

    static constexpr unsigned type_bits()
    {
        if constexpr (detail::is_valid_element_type_v<result_type> || detail::is_vector_elem_ref_v<result_type>)
            return detail::type_bits_v<result_type>;
        else
            return result_type::type_bits();
    }

    static constexpr unsigned size()
    {
        if constexpr (detail::is_valid_element_type_v<result_type> || detail::is_vector_elem_ref_v<result_type>)
            return 1;
        else
            return result_type::size();
    }

    static constexpr unsigned bits()
    {
        return type_bits() * size();
    }

    template <typename... Operations> requires(... && std::is_same_v<Operations, Operation>)
    static constexpr bool is_operation(Operation op, Operations... ops)
    {
        bool ret = Op != Operation::None && Op == op;

        if constexpr (sizeof...(Operations) > 0)
            ret = ret || is_operation(ops...);

        return ret;
    }

    template <typename... Operations> requires(... && std::is_same_v<Operations, Operation>)
    static constexpr bool is_operation_not(Operation op, Operations... ops)
    {
        bool ret = Op != Operation::None && Op != op;

        if constexpr (sizeof...(Operations) > 0)
            ret = ret && is_operation_not(ops...);

        return ret;
    }

    static constexpr bool is_operation_none()
    {
        return Op == Operation::None;
    }

    __aie_inline
    auto parent1() const //TODO: Use helper to decide between current + parent op, and drop redundant ones by returning parent's parent directly
    {
        if constexpr(is_op_v<parent1_type>)
            return parent_();
        else
            return parent_;
    }

    static constexpr Operation operation = Op;

    __aie_inline
    constexpr unary_op_common(const parent1_type parent) :
        parent_(parent)
    {
    }

private:
    const parent1_type parent_;
};

template <typename Parent, Operation Op>
struct unary_op;

#define UNARY_OP(op)                                                                   \
template <typename Parent>                                                             \
struct unary_op<Parent, Operation::op> : public unary_op_common<Parent, Operation::op> \
{                                                                                      \
    using parent1_type = Parent;                                                        \
    using result_type = op_result_type_t<parent1_type, Operation::op>;                  \
    using  value_type = op_value_type_t<result_type>;                                  \
                                                                                       \
    using unary_op_common<Parent, Operation::op>::unary_op_common;                     \
                                                                                       \
    result_type operator()() const;                                                    \
};

#define UNARY_OP_IMPL(op)                                                                                 \
template <typename Parent>                                                                                \
__aie_inline                                                                            \
typename unary_op<Parent, Operation::op>::result_type unary_op<Parent, Operation::op>::operator()() const

UNARY_OP(None)
UNARY_OP(Abs)
UNARY_OP(Conj)
UNARY_OP(Transpose)

UNARY_OP(Acc_Add)
UNARY_OP(Acc_Sub)

UNARY_OP_IMPL(None)
{
    return this->parent1();
}

template <typename Parent1, typename Parent2, Operation Op>
struct binary_op_common
{
    using parent1_type = aie_dm_resource_remove_t<Parent1>;
    using parent2_type = aie_dm_resource_remove_t<Parent2>;
    using  result_type = op_result_type_t<parent1_type, Op>; //TODO: Helper to correctly resolve result type as it won't always be parent1
    using  value_type = op_value_type_t<result_type>;

    static constexpr unsigned type_bits()
    {
        if constexpr (detail::is_valid_element_type_v<result_type> || detail::is_vector_elem_ref_v<result_type>)
            return detail::type_bits_v<result_type>;
        else
            return result_type::type_bits();
    }

    static constexpr unsigned size()
    {
        if constexpr (detail::is_valid_element_type_v<result_type> || detail::is_vector_elem_ref_v<result_type>)
            return 1;
        else
            return result_type::size();
    }

    static constexpr unsigned bits()
    {
        return type_bits() * size();
    }

    template <typename... Operations> requires(... && std::is_same_v<Operations, Operation>)
    static constexpr bool is_operation(Operation op, Operations... ops)
    {
        bool ret = Op == op;

        if constexpr (sizeof...(Operations) > 0)
            ret = ret || is_operation(ops...);

        return ret;
    }

    template <typename... Operations> requires(... && std::is_same_v<Operations, Operation>)
    static constexpr bool is_operation_not(Operation op, Operations... ops)
    {
        bool ret = Op != op;

        if constexpr (sizeof...(Operations) > 0)
            ret = ret && is_operation_not(ops...);

        return ret;
    }

    static constexpr bool is_operation_none()
    {
        return false;
    }

    __aie_inline
    auto parent1() const
    {
        if constexpr(is_op_v<parent1_type>) //TODO: Use helper to decide between current + parent op, and drop redundant ones by returning parent's parent directly
            return parent1_();
        else
            return parent1_;
    }

    __aie_inline
    auto parent2() const
    {
        if constexpr(is_op_v<parent2_type>)
            return parent2_();
        else
            return parent2_;
    }

    static constexpr Operation operation = Op;

    __aie_inline
    constexpr binary_op_common(const parent1_type parent1, const parent2_type parent2) :
        parent1_(parent1),
        parent2_(parent2)
    {
    }

private:
    const parent1_type parent1_;
    const parent2_type parent2_;
};

template <typename Parent1, typename Parent2, Operation Op>
struct binary_op;

#define BINARY_OP(op)                                                                                        \
                                                                                                             \
template <typename Parent1, typename Parent2>                                                                \
struct binary_op<Parent1, Parent2, Operation::op> : public binary_op_common<Parent1, Parent2, Operation::op> \
{                                                                                                            \
    using parent1_type = Parent1;                                                                            \
    using parent2_type = Parent2;                                                                            \
    using  result_type = op_result_type_t<parent1_type, Operation::op>;                                      \
    using   value_type = op_value_type_t<result_type>;                                                       \
                                                                                                             \
    using binary_op_common<Parent1, Parent2, Operation::op>::binary_op_common;                               \
                                                                                                             \
    result_type operator()() const;                                                                          \
};

#define BINARY_OP_IMPL(op)                                                                                                      \
template <typename Parent1, typename Parent2>                                                                                   \
__aie_inline                                                                                                  \
typename binary_op<Parent1, Parent2, Operation::op>::result_type binary_op<Parent1, Parent2, Operation::op>::operator()() const

BINARY_OP(Max)
BINARY_OP(Min)
BINARY_OP(Sign)
BINARY_OP(Zero)


}

#endif
