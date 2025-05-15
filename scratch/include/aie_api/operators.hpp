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
 * @brief Operator overloading for AIE API types, currently expects "using namespace aie::operators"
 * in the user code to make use of them directly.
 */

#pragma once

#ifndef __AIE_API_OPERATORS__HPP__
#define __AIE_API_OPERATORS__HPP__

namespace aie::operators {

/**
 * @ingroup group_operators
 *
 * Negation operator. It is equivalent to aie::neg.
 *
 */
template <typename T>
constexpr auto operator-(const T &a)
{
    return aie::neg(a);
}

/**
 * @ingroup group_operators
 *
 * Subtraction operator. It is equivalent to aie::sub.
 *
 */
template <typename T1, typename T2>
constexpr auto operator-(const T1 &a, const T2 &b)
{
    return aie::sub(a, b);
}

/**
 * @ingroup group_operators
 *
 * Addition operator. It is equivalent to aie::add.
 *
 */
template <typename T1, typename T2>
constexpr auto operator+(const T1 &a, const T2 &b)
{
    return aie::add(a, b);
}

/**
 * @ingroup group_operators
 *
 * Less than comparison operator. It is equivalent to aie::lt.
 *
 */
template <typename T1, typename T2>
constexpr auto operator<(const T1 &a, const T2 &b)
{
    return aie::lt(a, b);
}

/**
 * @ingroup group_operators
 *
 * Less than or equal comparison operator. It is equivalent to aie::le.
 *
 */
template <typename T1, typename T2>
constexpr auto operator<=(const T1 &a, const T2 &b)
{
    return aie::le(a, b);
}

/**
 * @ingroup group_operators
 *
 * Greater than comparison operator. It is equivalent to aie::gt.
 *
 */
template <typename T1, typename T2>
constexpr auto operator>(const T1 &a, const T2 &b)
{
    return aie::gt(a, b);
}

/**
 * @ingroup group_operators
 *
 * Greater than or equal comparison operator. It is equivalent to aie::ge.
 *
 */
template <typename T1, typename T2>
constexpr auto operator>=(const T1 &a, const T2 &b)
{
    return aie::ge(a, b);
}

/**
 * @ingroup group_operators
 *
 * Equal to comparison operator. It is equivalent to aie::eq.
 *
 */
template <typename T1, typename T2>
constexpr auto operator==(const T1 &a, const T2 &b)
{
    return aie::eq(a, b);
}

/**
 * @ingroup group_operators
 *
 * Not equal to comparison operator. It is equivalent to aie::neq.
 *
 */
template <typename T1, typename T2>
constexpr auto operator!=(const T1 &a, const T2 &b)
{
    return aie::neq(a, b);
}

/**
 * @ingroup group_operators
 *
 * Bitwise left shift operator. It is equivalent to aie::upshift.
 *
 */
template <typename T>
constexpr auto operator<<(const T &a, unsigned shift)
{
    return aie::upshift(a, shift);
}

/**
 * @ingroup group_operators
 *
 * Bitwise right shift operator. It is equivalent to aie::downshift.
 *
 */
template <typename T>
constexpr auto operator>>(const T &a, unsigned shift)
{
    return aie::downshift(a, shift);
}

/**
 * @ingroup group_operators
 *
 * Addition assignment operator.
 *
 */
template <typename T1, typename T2>
constexpr T1& operator+=(T1 &lhs, const T2 &rhs)
{
    lhs = lhs + rhs;
    return lhs;
}

/**
 * @ingroup group_operators
 *
 * Subtraction assignment operator.
 *
 */
template <typename T1, typename T2>
constexpr T1& operator-=(T1 &lhs, const T2 &rhs)
{
    lhs = lhs - rhs;
    return lhs;
}

/**
 * @ingroup group_operators
 *
 * Bitwise OR operation. It is equivalent to aie::bit_or.
 *
 */
template <typename T1, typename T2>
constexpr auto operator|(const T1 &a, const T2 &b)
{
    return aie::bit_or(a, b);
}

/**
 * @ingroup group_operators
 *
 * Bitwise XOR operation. It is equivalent to aie::bit_xor.
 *
 */
template <typename T1, typename T2>
constexpr auto operator^(const T1 &a, const T2 &b)
{
    return aie::bit_xor(a, b);
}

/**
 * @ingroup group_operators
 *
 * Bitwise AND operation. It is equivalent to aie::bit_and.
 *
 */
template <typename T1, typename T2>
constexpr auto operator&(const T1 &a, const T2 &b)
{
    return aie::bit_and(a, b);
}

/**
 * @ingroup group_operators
 *
 * Bitwise NOT operation. It is equivalent to aie::bit_not.
 *
 */
template <typename T>
constexpr auto operator~(const T &a)
{
    return aie::bit_not(a);
}

// TODO Support XOR (emulated)

} // namespace aie::operators

#endif
