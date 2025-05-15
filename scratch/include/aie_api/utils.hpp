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
 * @brief Utilities exposed to users.
 */

#pragma once

#ifndef __AIE_API_UTILS__HPP__
#define __AIE_API_UTILS__HPP__

// AIE API currently requires C++20
#define AIE_API_CXX_VERSION 202002L

// TODO: When host/graph compiler is updated to C++20 we will need to change this logic
#if __cplusplus < AIE_API_CXX_VERSION

#ifdef __chess__

#error "C++20 or greater is required to compile AIE API kernels"

#endif

#else

#include "aie.hpp"
#include "vector.hpp"

#include <cstdio>
#include <cmath>
#include <limits>
#include <utility>

namespace aie {

namespace detail {

// An accumulator that stores overlapping ranges of bits
// It requires SRS to add the overlapping bits before shifting, so it
// is not trivial to inspect its contents in memory directly.
template <typename A>
concept OverlappingAcc = is_accum_v<A> && !A::is_floating_point() && A::accum_bits() > 64;

// An accumulator that does not have overlapping ranges of bits
// We can inspect the contents of the accumulator from memory directly
template <typename A>
concept RegularAcc = is_accum_v<A> && !OverlappingAcc<A>;

template <typename T, unsigned Elems>
concept ValidVector = requires { typename native_vector_type_t<T, Elems>; };

// Retrieves the largest size less than or equal the current size that would
// yield a valid aie::vector for type T. If no such vector would exist it returns 0
template <typename T, unsigned Elems>
constexpr unsigned largest_valid_vector_size()
{
    if constexpr (ValidVector<T, Elems>)
        return Elems;
    else if (Elems > 0)
        return largest_valid_vector_size<T, Elems / 2>();
    UNREACHABLE_MSG("No valid vector found");
}

// Interprets an integer as fixed point number and converts it into a floating point number.
template <typename T>
    requires(detail::is_integral_v<T>)
__aie_inline
static double to_floating_point(T value, int scale)
{
    constexpr size_t double_precision = std::numeric_limits<double>::digits;
    if constexpr (detail::type_bits_v<T> > double_precision)
        chess_warning("Type conversion loses precision");
    return std::ldexp(double(value), scale);
}

template <typename T>
__aie_inline
void print_value(const T &e, int scale = 0)
{
    if constexpr (detail::is_complex_v<T>) {
        if constexpr (detail::is_floating_point_v<T>)
            printf("(%f %f) ", (float)e.real, (float)e.imag);
        else if (scale == 0) // Integral
            printf("(%d %d) ", (int)e.real, (int)e.imag);
        else
            printf("(%f %f) ", to_floating_point(e.real, scale), to_floating_point(e.imag, scale));
    }
    else if constexpr (detail::is_floating_point_v<T>) {
        printf("%f ", (float)e);
    }
    else if (scale != 0) {
        printf("%f ", to_floating_point(e, scale));
    }
    else if constexpr (detail::is_signed_v<T>) {
        printf("%d ", (int)e);
    }
    else {
        printf("%u ", (unsigned)e);
    }
}

template <typename T, unsigned Elems>
__aie_inline
void print_elem(const vector<T, Elems> &v, unsigned i)
{
    print_value(T(v[i]));
}

template <RegularAcc Acc>
    requires(Acc::is_floating_point())
__aie_inline
void print_elem(const Acc &acc, unsigned i) {
#if AIE_API_MATH_VERSION >= 100 || __AIE_API_COMPLEX_FP32_EMULATION__
    if constexpr (Acc::is_complex()) {
        const cfloat *ptr = ((const cfloat *)&acc) + i;
        const cfloat e = *ptr;

        detail::print_value(e);
    }
    else
#endif
    {
        const float *ptr = ((const float *)&acc) + i;
        const float e = *ptr;

        detail::print_value(e);
    }
}

// Prints the hex representation of an accumulator's element

// - Helper function used by both integer and complex representations
template <RegularAcc Acc, unsigned memory_bits>
    requires(!Acc::is_floating_point())
__aie_inline
void print_int_component(const char *acc_ptr, const char *prefix = "", const char *suffix = "")
{
    constexpr unsigned representable_bytes = Acc::accum_min_bits() / 8;
    printf("%s0x", prefix);
    for (unsigned j = representable_bytes; j > 0; --j) {
        printf("%02hhx", acc_ptr[j-1]);
    }
    printf("%s", suffix);
}

// - Prints hex representation of an integer element
template <RegularAcc Acc>
    requires(!Acc::is_floating_point() && !Acc::is_complex())
__aie_inline
void print_elem(const Acc &acc, unsigned i)
{
    constexpr unsigned component_bits = Acc::memory_bits();
    const char *ptr = ((const char *)&acc) + i * acc.memory_bits() / 8;
    print_int_component<Acc, component_bits>(ptr, "", " ");
}

// - Prints hex representation of a complex element
template <RegularAcc Acc>
    requires(!Acc::is_floating_point() && Acc::is_complex())
__aie_inline
void print_elem(const Acc &acc, unsigned i)
{
    constexpr unsigned complex_size = Acc::memory_bits() / 8;
    constexpr unsigned component_bits = Acc::memory_bits() / 2;
    const char *real = ((const char *)&acc) + i * complex_size;
    const char *imag = real + component_bits / 8;

    print_int_component<Acc, component_bits>(real, "(", ", ");
    print_int_component<Acc, component_bits>(imag, "", ") ");
}

// Retrieves a sub accumulator and the element index referring to acc[i] that
// can be converted into a vector
// This is because there may not be vectors with the same capacity
template <Accum Acc>
    requires(!Acc::is_floating_point())
__aie_inline
auto get_sub_accum(const Acc &acc, unsigned i)
{
    constexpr unsigned sub_acc_size = largest_valid_vector_size<int32, Acc::size()>();
    if constexpr (sub_acc_size == Acc::size())
        return std::pair{acc, i};

    const unsigned bucket = i / sub_acc_size;
    const unsigned sub_i = i % sub_acc_size;
    const auto sub_acc = acc.template extract<sub_acc_size>(bucket);
    return std::pair{sub_acc, sub_i};
}

// Prints the hex representation of an integer accumulator's element
template <OverlappingAcc Acc>
    requires(!Acc::is_complex())
__aie_inline
void print_elem(const Acc &acc, unsigned i, const char *prefix = "", const char *suffix = " ")
{
    auto [sub_acc, sub_i] = get_sub_accum(acc, i);
    int32 a = Acc::accum_min_bits() <= 64
        ? 0
        : sub_acc.template to_vector<int32>(56)[sub_i];
    int32 b = sub_acc.template to_vector<int32>(32)[sub_i];
    int32 c = sub_acc.template to_vector<int32>(0)[sub_i];

    // For 56b and 64b, ignore 'a' argument.
    // Mask is used to ensure exact number of bits are printed in MSB slots.
    struct Pattern {
        const char *format = nullptr;
        uint32_t mask_a, mask_b;
    };
    constexpr Pattern pattern = []() -> Pattern {
        switch (Acc::accum_min_bits()) {
            case 56: return {"%s0x%06x%08x%s",     0,          0x00ffffff};
            case 64: return {"%s0x%08x%08x%s",     0,          0xffffffff};
            case 72: return {"%s0x%04x%06x%08x%s", 0x0000ffff, 0x00ffffff};
            case 80: return {"%s0x%06x%06x%08x%s", 0x00ffffff, 0x00ffffff};
            default: UNREACHABLE_MSG("Unsupported accum bits");
        }
    }();
    if constexpr (pattern.mask_a == 0)
        printf(pattern.format, prefix, pattern.mask_b & b, c, suffix);
    else
        printf(pattern.format, prefix, pattern.mask_a & a, pattern.mask_b & b, c, suffix);
}

// Prints the hex representation of an complex accumulator's element
template <OverlappingAcc Acc>
    requires(Acc::is_complex())
__aie_inline
void print_elem(const Acc &acc, unsigned i)
{
    // Remove complex tag to access its components like a regular accumulator
    using new_tag = accum_tag_t<AccumClass::Int, Acc::accum_bits()>;
    auto components = accum_cast<new_tag>(acc);

    print_elem(components, 2 * i, "(", " ");
    print_elem(components, 2 * i + 1, "", ") ");
}

} // namespace detail

/** Displays the contents of a vector or an accumulator.
 * \param[in] c      A vector or an accumulator.
 * \param[in] nl     Set to `true` to print add newline at the end.
 * \param[in] prefix Optional text to print before the first element.
 */
template <typename C>
    requires(Vector<C> || Accum<C>)
__aie_noinline
void print(const C &c, bool nl = false, const char *prefix = nullptr)
{
    if (prefix)
        printf("%s", prefix);

    aie::rounding_mode rnd;
    if constexpr (detail::OverlappingAcc<C>)
        rnd = aie::swap_rounding(aie::rounding_mode::floor);

    for (unsigned i = 0; i < C::size(); ++i) {
        detail::print_elem(c, i);
    }

    if (nl)
        printf("\n");

    if constexpr (detail::OverlappingAcc<C>)
        aie::set_rounding(rnd);
}

/** Displays the contents of a vector integers represented as real numbers in fixed point.
 * Applies a scaling factor to each value before printing, which represents the exponent in a multiplication by a power
 * of two: positive scale values will make the numbers larger while negative values will make the numbers smaller.
 * \param[in] v      The vector.
 * \param[in] scale  Power-of-two exponent to apply to each value. Can be positive or negative.
 * \param[in] nl     Set to `true` to print a newline after the last element.
 * \param[in] prefix Optional text to print before the first element.
 */
template <typename T, unsigned Elems>
    requires(!detail::is_floating_point_v<T>)
__aie_noinline
void print_fixed(const aie::vector<T, Elems> &v, int scale, bool nl = false, const char *prefix = nullptr)
{
    if (prefix)
        printf("%s", prefix);

    for (unsigned i = 0; i < Elems; ++i) {
        T e = v[i];
        detail::print_value(e, scale);
    }

    if (nl)
        printf("\n");
}

/** Displays the contents of a vector or accumulator, arranged in a matrix layout.
 * \param[in] m       A vector or an accumulator.
 * \param[in] cols    The number of columns in the matrix. Must be an exact divisor of the number of elements in `m`.
 * \param[in] prefix  Optional text to print before the first element.
 */
template <typename Matrix>
    requires(Vector<Matrix> || Accum<Matrix>)
__aie_noinline
void print_matrix(const Matrix &m, unsigned cols, const char *prefix = nullptr)
{
    const unsigned rows = Matrix::size() / cols;
    REQUIRES_MSG(rows > 0, "The number of columns must be, at most, the number of elements in the Vector");
    REQUIRES_MSG(cols > 0 && (cols & (cols - 1)) == 0, "The number of columns must be a power of two");

    unsigned n_white = 0;
    if (prefix) {
        printf("%s", prefix);
        n_white = strlen(prefix);
    }

    aie::rounding_mode rnd;
    if constexpr (detail::OverlappingAcc<Matrix>)
        rnd = aie::swap_rounding(aie::rounding_mode::floor);

    for (unsigned i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < cols; ++j) {
            detail::print_elem(m, i * cols + j);
        }

        printf("\n");

        if (i < rows - 1)
            printf("%*c", n_white, ' ');
    }

    if constexpr (detail::OverlappingAcc<Matrix>)
        aie::set_rounding(rnd);
}

/** Displays the contents of a mask.
 * \param[in] m       The mask.
 * \param[in] nl      Set to `true` in order to add a newline at the end.
 * \param[in] prefix  Optional text to print before the first element.
 */
template <unsigned N>
__aie_noinline
void print(const aie::mask<N> &m, bool nl = false, const char *prefix = nullptr)
{
    if (prefix)
        printf("%s", prefix);

    for (unsigned i = 0; i < N; ++i) {
        bool b = m.test(i);

        printf("%d ", b? 1 : 0);
    }

    if (nl)
        printf("\n");
}

using detail::utils::circular_index;
using detail::utils::unroll_for;
using detail::utils::unroll_for_2d;
using detail::utils::unroll_times;
using detail::utils::unroll_times_2d;

} // namespace aie

#endif

#endif
