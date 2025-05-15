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

#ifndef __AIE_API_DETAIL_AIE2_COMPARE__HPP__
#define __AIE_API_DETAIL_AIE2_COMPARE__HPP__

#include "../../mask.hpp"
#include "../broadcast.hpp"
#include "../vector.hpp"

namespace aie::detail {

template <CmpOp Op, typename T>
struct compare_vector_traits {
    static constexpr auto get_op()
    {
        if      constexpr (Op == CmpOp::LT)  return [](auto a, auto b) __aie_inline { return ::lt(a, b); };
        else if constexpr (Op == CmpOp::GE)  return [](auto a, auto b) __aie_inline { return ::ge(a, b); };
        else if constexpr (Op == CmpOp::EQ)  return [](auto a, auto b) __aie_inline { return ::eq(a, b); };
        else if constexpr (Op == CmpOp::NEQ) return [](auto a, auto b) __aie_inline { return ::ne(a, b); };
        else if constexpr (Op == CmpOp::LE)  return [](auto a, auto b) __aie_inline { return ::le(a, b); };
        else if constexpr (Op == CmpOp::GT)  return [](auto a, auto b) __aie_inline { return ::gt(a, b); };
    }

    // Returns whether an operator is derived from the negation of another and
    // returns that operator if that's the case.
    static constexpr bool is_derived()
    {
        if constexpr (Op == CmpOp::NEQ) return true;
        return false;
    }

    static constexpr CmpOp get_derived()
    {
        if constexpr (Op == CmpOp::NEQ) return CmpOp::EQ;
        return Op;
    }

    static constexpr auto get_derived_op()
    {
        return compare_vector_traits<get_derived(), T>::get_op();
    }
};

template <CmpOp Op, typename T>
struct compare_zero_traits {
    static constexpr auto get_op()
    {
        if constexpr (is_unsigned_v<T>) {
            // ltz intrinsic for unsigned vector types is wrong in AIE2(P)(PS). See CRVO-9293
            if      constexpr (Op == CmpOp::LT)  return [](auto a) __aie_inline { return 0llu; };
            else if constexpr (Op == CmpOp::GE)  return [](auto a) __aie_inline { return ~0llu; };
            else if constexpr (Op == CmpOp::EQ)  return [](auto a) __aie_inline { return ::eqz(a); };
            else if constexpr (Op == CmpOp::NEQ) return [](auto a) __aie_inline { return ::gtz(a); };
            else if constexpr (Op == CmpOp::LE)  return [](auto a) __aie_inline { return ::eqz(a); };
            else if constexpr (Op == CmpOp::GT)  return [](auto a) __aie_inline { return ::gtz(a); };
        }
        else if constexpr (Op == CmpOp::LT)  return [](auto a) __aie_inline { return ::ltz(a); };
        else if constexpr (Op == CmpOp::GE)  return [](auto a) __aie_inline { return ~::ltz(a); };
        else if constexpr (Op == CmpOp::EQ)  return [](auto a) __aie_inline { return ::eqz(a); };
        else if constexpr (Op == CmpOp::NEQ) return [](auto a) __aie_inline { return ~::eqz(a); };
        else if constexpr (Op == CmpOp::LE)  return [](auto a) __aie_inline { return ~::gtz(a); };
        else if constexpr (Op == CmpOp::GT)  return [](auto a) __aie_inline { return ::gtz(a); };
    }

    // Returns whether an operator is derived from the negation of another and
    // returns that operator if that's the case.
    static constexpr bool is_derived()
    {
        if constexpr (is_unsigned_v<T>) {
            if constexpr (Op == CmpOp::GE) return true;
        }
        else {
            if      constexpr (Op == CmpOp::GE)  return true;
            else if constexpr (Op == CmpOp::NEQ) return true;
            else if constexpr (Op == CmpOp::LE)  return true;
        }
        return false;
    }

    static constexpr CmpOp get_derived()
    {
        if constexpr (is_unsigned_v<T>) {
            if constexpr (Op == CmpOp::GE) return CmpOp::LT;
        }
        else {
            if      constexpr (Op == CmpOp::GE)  return CmpOp::LT;
            else if constexpr (Op == CmpOp::NEQ) return CmpOp::EQ;
            else if constexpr (Op == CmpOp::LE)  return CmpOp::GT;
        }
        return Op;
    }

    static constexpr auto get_derived_op()
    {
        return compare_zero_traits<get_derived(), T>::get_op();
    }
};

template <CmpOp Op, typename T, unsigned Elems>
struct cmp_bits_impl<Op, 4, T, Elems>
{
     using vector_type = vector<T, Elems>;
     using   mask_type = mask<Elems>;
     using   next_type = utils::get_next_integer_type_t<T>;

    __aie_inline
     static mask_type run(const vector_type &v1, const vector_type &v2)
     {
         if constexpr (Elems < 256) {
             return cmp_bits_impl<Op, 8, next_type, Elems>::run(v1.unpack(), v2.unpack());
         }
         else {
             mask<Elems / 2> tmp1 = cmp_bits_impl<Op, 8, next_type, Elems / 2>::run(v1.template extract<Elems / 2>(0).unpack(),
                                                                                    v2.template extract<Elems / 2>(0).unpack());
             mask<Elems / 2> tmp2 = cmp_bits_impl<Op, 8, next_type, Elems / 2>::run(v1.template extract<Elems / 2>(1).unpack(),
                                                                                    v2.template extract<Elems / 2>(1).unpack());

             return mask_type::from_masks(tmp1, tmp2);
         }
    }

    __aie_inline
    static mask_type run(T a, const vector_type &v)
    {
        return run(broadcast<T, Elems>::run(a), v);
    }

    __aie_inline
    static mask_type run(const vector_type &v, T a)
    {
        return run(v, broadcast<T, Elems>::run(a));
    }
};

template <CmpOp Op, typename T, unsigned Elems>
struct cmp_zero_bits_impl<Op, 4, T, Elems>
{
    using vector_type = vector<T, Elems>;
    using   mask_type = mask<Elems>;
    using   next_type = utils::get_next_integer_type_t<T>;
    using   op_traits = compare_zero_traits<Op, T>;

    __aie_inline
    static mask_type run(const vector_type &v)
    {
        if constexpr (Elems <= 64) {
            using sub_op = cmp_zero_bits_impl<Op, 8, next_type, 64>;
            auto m = sub_op::run(v.unpack().template grow<64>());
            return m.template get_submask<Elems>(0);
        }
        else {
            constexpr bool is_derived = op_traits::is_derived();
            constexpr CmpOp derived_op = op_traits::get_derived();
            using sub_op = cmp_zero_bits_impl<derived_op, 8, next_type, Elems / 2>;
            mask<Elems / 2> tmp1 = sub_op::run(v.template extract<Elems / 2>(0).unpack());
            mask<Elems / 2> tmp2 = sub_op::run(v.template extract<Elems / 2>(1).unpack());

            mask_type m = mask_type::from_masks(tmp1, tmp2);
            if constexpr (is_derived)
                return ~m;
            else
                return m;
        }
    }
};

template <CmpOp Op, typename T, unsigned Elems>
struct cmp_bits_impl<Op, 8, T, Elems>
{
    using vector_type = vector<T, Elems>;
    using   mask_type = mask<Elems>;
    using   op_traits = compare_vector_traits<Op, T>;

    static constexpr auto op = op_traits::get_op();

    __aie_inline
    static mask_type run(const vector_type &v1, const vector_type &v2)
    {
        if constexpr (Elems == 128) {
            const uint64_t a = op(v1.template extract<64>(0), v2.template extract<64>(0));
            const uint64_t b = op(v1.template extract<64>(1), v2.template extract<64>(1));

            return mask_type::from_uint64(a, b);
        }
        else if constexpr (Elems == 64) {
            const uint64_t a = op(v1, v2);

            return mask_type::from_uint64(a);
        }
        else if constexpr (Elems <= 32) {
            const uint64_t a = op(v1.template grow<64>(), v2.template grow<64>());

            return mask_type::from_uint32((unsigned)a);
        }
    }

    __aie_inline
    static mask_type run(T a, const vector_type &v)
    {
        return run(broadcast<T, Elems>::run(a), v);
    }

    __aie_inline
    static mask_type run(const vector_type &v, T a)
    {
        return run(v, broadcast<T, Elems>::run(a));
    }
};

template <CmpOp Op, typename T, unsigned Elems>
struct cmp_zero_bits_impl<Op, 8, T, Elems>
{
    using vector_type = vector<T, Elems>;
    using   mask_type = mask<Elems>;
    using   op_traits = compare_zero_traits<Op, T>;

    static constexpr auto op = op_traits::get_op();

    __aie_inline
    static mask_type run(const vector_type &v)
    {
        if constexpr (Elems < 64) {
            const uint64_t a = op(v.template grow<64>());

            return mask_type::from_uint32((unsigned)a);
        }
        else if constexpr (Elems == 64) {
            const uint64_t a = op(v);

            return mask_type::from_uint64(a);
        }
        else {
            using sub_op = cmp_zero_bits_impl<Op, 8, T, Elems / 2>;
            mask<Elems / 2> tmp1 = sub_op::run(v.template extract<Elems / 2>(0));
            mask<Elems / 2> tmp2 = sub_op::run(v.template extract<Elems / 2>(1));

            return mask_type::from_masks(tmp1, tmp2);
        }
    }
};

template <CmpOp Op, typename T, unsigned Elems>
struct cmp_bits_impl<Op, 16, T, Elems>
{
    using vector_type = vector<T, Elems>;
    using   mask_type = mask<Elems>;
    using   op_traits = compare_vector_traits<Op, T>;

    static constexpr auto op = op_traits::get_op();

    __aie_inline
    static mask_type run(const vector_type &v1, const vector_type &v2)
    {
        if constexpr (Elems == 64) {
            const unsigned result1 = op(v1.template extract<32>(0), v2.template extract<32>(0));
            const unsigned result2 = op(v1.template extract<32>(1), v2.template extract<32>(1));

            return mask_type::from_uint32(result1, result2);
        }
        else if constexpr (Elems <= 32) {
            const unsigned result = op(v1.template grow<32>(), v2.template grow<32>());

            return mask_type::from_uint32(result);
        }
    }

    __aie_inline
    static mask_type run(T a, const vector_type &v)
    {
        return run(broadcast<T, Elems>::run(a), v);
    }

    __aie_inline
    static mask_type run(const vector_type &v, T a)
    {
        return run(v, broadcast<T, Elems>::run(a));
    }
};

template <CmpOp Op, typename T, unsigned Elems>
struct cmp_zero_bits_impl<Op, 16, T, Elems>
{
    using vector_type = vector<T, Elems>;
    using   mask_type = mask<Elems>;
    using   op_traits = compare_zero_traits<Op, T>;

    __aie_inline
    static mask_type run(const vector_type &v)
    {
        if constexpr (Elems <= 32) {
            constexpr auto op = op_traits::get_op();
            const uint32_t a = op(v.template grow<32>());

            return mask_type::from_uint32(a);
        }
        else {
            // Some operators such as ::ne negate the bits coming from another op (::eq)
            // since we need to mask some of the bits to combine the upper and lower 16bit,
            // we use the original operator instead and then perform the bitwise negation once the combination is done
            constexpr bool is_derived = op_traits::is_derived();
            constexpr CmpOp derived_op = op_traits::get_derived();
            using sub_op = cmp_zero_bits_impl<derived_op, 16, T, Elems / 2>;

            mask<Elems / 2> tmp1 = sub_op::run(v.template extract<Elems / 2>(0));
            mask<Elems / 2> tmp2 = sub_op::run(v.template extract<Elems / 2>(1));

            mask m = mask<Elems>::from_masks(tmp1, tmp2);
            if constexpr (is_derived)
                return ~m;
            else
                return m;
        }
    }
};

template <CmpOp Op, unsigned Elems>
struct cmp_bits_impl<Op, 16, bfloat16, Elems>
{
    using           T = bfloat16;
    using vector_type = vector<T, Elems>;
    using   mask_type = mask<Elems>;
    using   op_traits = compare_vector_traits<Op, bfloat16>;

    static constexpr auto op = op_traits::get_op();

    __aie_inline
    static mask_type run(const vector_type &v1, const vector_type &v2)
    {
        if constexpr (Elems == 64) {
            accum<accfloat, 64> acc(v1);
            accum<accfloat, 16> zero = zeros_acc<AccumClass::FP, 32, 16>::run();

            const vector<T, 16> v1_1 = ::to_v16bfloat16(::add(acc.template extract<16>(0), zero));
            const vector<T, 16> v1_2 = ::to_v16bfloat16(::add(acc.template extract<16>(1), zero));
            const vector<T, 16> v1_3 = ::to_v16bfloat16(::add(acc.template extract<16>(2), zero));
            const vector<T, 16> v1_4 = ::to_v16bfloat16(::add(acc.template extract<16>(3), zero));

            const unsigned result1 = op(::concat(v1_1, v1_2), v2.template extract<32>(0));
            const unsigned result2 = op(::concat(v1_3, v1_4), v2.template extract<32>(1));

            return mask_type::from_uint32(result1, result2);
        }
        else if constexpr (Elems == 32) {
            accum<accfloat, 32> acc(v1);
            accum<accfloat, 16> zero = zeros_acc<AccumClass::FP, 32, 16>::run();

            const vector<T, 16> v1_1 = ::to_v16bfloat16(::add(acc.template extract<16>(0), zero));
            const vector<T, 16> v1_2 = ::to_v16bfloat16(::add(acc.template extract<16>(1), zero));

            const unsigned result = op(::concat(v1_1, v1_2), v2.template extract<32>(0));

            return mask_type::from_uint32(result);
        }
        else if constexpr (Elems <= 16) {
            accum<accfloat, 16> acc(v1.template grow<16>());
            accum<accfloat, 16> zero = zeros_acc<AccumClass::FP, 32, 16>::run();

            const vector<T, 16> v1_1 = ::to_v16bfloat16(::add(acc, zero));

            const unsigned result = op(v1_1.template grow<32>(), v2.template grow<32>());

            return mask_type::from_uint32(result);
        }
    }

    __aie_inline
    static mask_type run(const T &a, const vector_type &v)
    {
        return run(broadcast<T, Elems>::run(a), v);
    }

    __aie_inline
    static mask_type run(const vector_type &v, const T &a)
    {
        return run(v, broadcast<T, Elems>::run(a));
    }
};

template <CmpOp Op, typename T, unsigned Elems>
struct cmp_bits_impl<Op, 32, T, Elems>
{
    using vector_type = vector<T, Elems>;
    using   mask_type = mask<Elems>;
    using   op_traits = compare_vector_traits<Op, T>;

    __aie_inline
    static mask_type run(const vector_type &v1, const vector_type &v2)
    {
        if constexpr (vector_type::is_complex()) {
            return cmp_bits_impl<Op, 32, int32, Elems>::run(v1.template cast_to<int32>(), v2.template cast_to<int32>());
        }
        else {
            if constexpr (Elems == 32) {
                // Some operators such as ::ne negate the bits coming from another op (::eq)
                // since we need to mask some of the bits to combine the upper and lower 16bit,
                // we use the original operator instead and then perform the bitwise negation once the combination is done
                constexpr bool is_derived = op_traits::is_derived();
                constexpr auto op = op_traits::get_derived_op();

                const unsigned result1 = op(v1.template extract<16>(0), v2.template extract<16>(0));
                const unsigned result2 = op(v1.template extract<16>(1), v2.template extract<16>(1));

                mask_type m = mask_type::from_uint32(result2 << 16 | result1);
                if constexpr (is_derived)
                    return ~m;
                else
                    return m;
            }
            else if constexpr (Elems <= 16) {
                auto op = op_traits::get_op();
                const unsigned result = op(v1.template grow<16>(), v2.template grow<16>());

                return mask_type::from_uint32(result);
            }
        }
    }

    __aie_inline
    static mask_type run(T a, const vector_type &v)
    {
        return run(broadcast<T, Elems>::run(a), v);
    }

    __aie_inline
    static mask_type run(const vector_type &v, T a)
    {
        return run(v, broadcast<T, Elems>::run(a));
    }
};

template <CmpOp Op, typename T, unsigned Elems>
    requires(!is_floating_point_v<T>)
struct cmp_zero_bits_impl<Op, 32, T, Elems>
{
    using vector_type = vector<T, Elems>;
    using   mask_type = mask<Elems>;
    using   op_traits = compare_zero_traits<Op, T>;

    __aie_inline
    static mask_type run(const vector_type &v)
    {
        if constexpr (vector_type::is_complex()) {
            return cmp_zero_bits_impl<Op, 32, int32, Elems>::run(v.template cast_to<int32>());
        }
        else {
            if constexpr (Elems == 32) {
                // Some operators such as ::ne negate the bits coming from another op (::eq)
                // since we need to mask some of the bits to combine the upper and lower 16bit,
                // we use the original operator instead and then perform the bitwise negation once the combination is done
                constexpr bool is_derived = op_traits::is_derived();
                constexpr auto op = op_traits::get_derived_op();

                const unsigned result1 = op(v.template extract<16>(0));
                const unsigned result2 = op(v.template extract<16>(1));

                mask_type m = mask_type::from_uint32(result2 << 16 | result1);
                if constexpr (is_derived)
                    return ~m;
                else
                    return m;
            }
            else if constexpr (Elems <= 16) {
                constexpr auto op = op_traits::get_op();
                const unsigned result = op(v.template grow<16>());

                return mask_type::from_uint32(result);
            }
        }
    }
};

// We need this specialisation because comparisons against zero have support for
// an additional comparison mode (GT, and the complementary LE)
// None of the zero comparators are available for float, so we fall back to vector
// comparisons with the operators that are available there.
template <CmpOp Op, typename T, unsigned Elems>
    requires(is_floating_point_v<T>)
struct cmp_zero_bits_impl<Op, 32, T, Elems>
{
    using vector_type = vector<T, Elems>;
    using   mask_type = mask<Elems>;

    __aie_inline
    static mask_type run(const vector_type &v)
    {
        if constexpr (Op == CmpOp::LE) {
            using base_impl = cmp_bits_impl<CmpOp::GE, 32, T, Elems>;
            return base_impl::run(zeros<T, Elems>::run(), v);
        }
        else if constexpr (Op == CmpOp::GT) {
            using base_impl = cmp_bits_impl<CmpOp::LT, 32, T, Elems>;
            return base_impl::run(zeros<T, Elems>::run(), v);
        }
        else {
            using base_impl = cmp_bits_impl<Op, 32, T, Elems>;
            return base_impl::run(v, zeros<T, Elems>::run());
        }
    }
};

template <CmpOp Op, unsigned Elems>
struct cmp_bits_impl<Op, 64, cint32, Elems>
{
    using           T = cint32;
    using vector_type = vector<T, Elems>;
    using   mask_type = mask<Elems>;
    using   op_traits = compare_vector_traits<Op, T>;

    static constexpr auto op = op_traits::get_op();

    __aie_inline
    static mask_type run(const vector_type &v1, const vector_type &v2)
    {
        if constexpr (Elems == 16) {
            vector<int32, 16> v1_r = (v16int32)::shuffle(v1.template extract<8>(0), v1.template extract<8>(1), DINTLV_lo_32o64);
            vector<int32, 16> v1_i = (v16int32)::shuffle(v1.template extract<8>(0), v1.template extract<8>(1), DINTLV_hi_32o64);
            vector<int32, 16> v2_r = (v16int32)::shuffle(v2.template extract<8>(0), v2.template extract<8>(1), DINTLV_lo_32o64);
            vector<int32, 16> v2_i = (v16int32)::shuffle(v2.template extract<8>(0), v2.template extract<8>(1), DINTLV_hi_32o64);

            const unsigned result_r = op(v1_r, v2_r);
            const unsigned result_i = op(v1_i, v2_i);

            if constexpr (Op == CmpOp::NEQ)
                return mask_type::from_uint32(result_r | result_i);
            else
                return mask_type::from_uint32(result_r & result_i);
        }
        else if constexpr (Elems <= 8) {
            // TODO: investigate performance optimizations for vectors smaller than 16
            vector<int32, 16> v1_r = (v16int32)::shuffle(v1.template grow<8>(), vector<cint32, 8>(), DINTLV_lo_32o64);
            vector<int32, 16> v1_i = (v16int32)::shuffle(v1.template grow<8>(), vector<cint32, 8>(), DINTLV_hi_32o64);
            vector<int32, 16> v2_r = (v16int32)::shuffle(v2.template grow<8>(), vector<cint32, 8>(), DINTLV_lo_32o64);
            vector<int32, 16> v2_i = (v16int32)::shuffle(v2.template grow<8>(), vector<cint32, 8>(), DINTLV_hi_32o64);

            const unsigned result_r = op(v1_r, v2_r);
            const unsigned result_i = op(v1_i, v2_i);

            if constexpr (Op == CmpOp::NEQ)
                return mask_type::from_uint32(result_r | result_i);
            else
                return mask_type::from_uint32(result_r & result_i);
        }
    }

    __aie_inline
    static mask_type run(T a, const vector_type &v)
    {
        return run(broadcast<T, Elems>::run(a), v);
    }

    __aie_inline
    static mask_type run(const vector_type &v, T a)
    {
        return run(v, broadcast<T, Elems>::run(a));
    }
};

template <CmpOp Op, unsigned Elems>
struct cmp_zero_bits_impl<Op, 64, cint32, Elems>
{
    using           T = cint32;
    using vector_type = vector<T, Elems>;
    using   mask_type = mask<Elems>;
    using   op_traits = compare_zero_traits<Op, T>;

    static constexpr auto op = op_traits::get_op();

    __aie_inline
    static mask_type run(const vector_type &v)
    {
        if constexpr (Elems == 16) {
            auto [lo, hi] = v.template cast_to<int32>().template split<16>();
            vector<int32, 16> v_r = ::shuffle(lo, hi, DINTLV_lo_32o64);
            vector<int32, 16> v_i = ::shuffle(lo, hi, DINTLV_hi_32o64);

            const unsigned result_r = op(v_r);
            const unsigned result_i = op(v_i);

            if constexpr (Op == CmpOp::NEQ)
                return mask_type::from_uint32(result_r | result_i);
            else
                return mask_type::from_uint32(result_r & result_i);
        }
        else if constexpr (Elems <= 8) {
            // TODO: investigate performance optimizations for vectors smaller than 16
            // TODO: use detail::unzip_complex
            auto lo = v.template cast_to<int32>().template grow<16>();
            vector<int32, 16> v_r = ::shuffle(lo, {}, DINTLV_lo_32o64);
            vector<int32, 16> v_i = ::shuffle(lo, {}, DINTLV_hi_32o64);

            const unsigned result_r = op(v_r);
            const unsigned result_i = op(v_i);

            if constexpr (Op == CmpOp::NEQ)
                return mask_type::from_uint32(result_r | result_i);
            else
                return mask_type::from_uint32(result_r & result_i);
        }
    }
};

template <CmpOp Op, unsigned TypeBits, typename T, unsigned Elems>
struct cmp_bits_impl_float_common
{
    using vector_type = vector<T, Elems>;
    using   mask_type = mask<Elems>;

    __aie_inline
    static mask_type run(const vector_type &v1, const vector_type &v2)
    {
        if      constexpr (Op == CmpOp::NEQ)
            return lt<T, Elems>::run(v1, v2) | lt<T, Elems>::run(v2, v1);
        else if constexpr (Op == CmpOp::EQ)
            return ge<T, Elems>::run(v1, v2) & ge<T, Elems>::run(v2, v1);
    }

    __aie_inline
    static mask_type run(T a, const vector_type &v)
    {
        return run(broadcast<T, Elems>::run(a), v);
    }

    __aie_inline
    static mask_type run(const vector_type &v, T a)
    {
        return run(v, broadcast<T, Elems>::run(a));
    }
};

template <unsigned Elems>
struct cmp_bits_impl<CmpOp::EQ,  16, bfloat16, Elems> : public cmp_bits_impl_float_common<CmpOp::EQ,  16, bfloat16, Elems> {};

template <unsigned Elems>
struct cmp_bits_impl<CmpOp::NEQ, 16, bfloat16, Elems> : public cmp_bits_impl_float_common<CmpOp::NEQ, 16, bfloat16, Elems> {};

template <unsigned Elems>
struct cmp_bits_impl<CmpOp::EQ,  32, float,    Elems> : public cmp_bits_impl_float_common<CmpOp::EQ,  32, float,    Elems> {};

template <unsigned Elems>
struct cmp_bits_impl<CmpOp::NEQ, 32, float,    Elems> : public cmp_bits_impl_float_common<CmpOp::NEQ, 32, float,    Elems> {};

template <typename T, unsigned Elems>
struct equal_bits_impl<4, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static bool run(const vector_type &v1, const vector_type &v2)
    {
        return equal_bits_impl<16, uint16, Elems / 4>::run(v1.template cast_to<uint16>(), v2.template cast_to<uint16>());
    }

    __aie_inline
    static bool run(T a, const vector_type &v)
    {
        return run(broadcast<T, Elems>::run(a), v);
    }

    __aie_inline
    static bool run(const vector_type &v, T a)
    {
        return run(v, broadcast<T, Elems>::run(a));
    }
};

template <typename T, unsigned Elems>
struct equal_bits_impl<8, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static bool run(const vector_type &v1, const vector_type &v2)
    {
        return equal_bits_impl<16, uint16, Elems / 2>::run(v1.template cast_to<uint16>(), v2.template cast_to<uint16>());
    }

    __aie_inline
    static bool run(T a, const vector_type &v)
    {
        return run(broadcast<T, Elems>::run(a), v);
    }

    __aie_inline
    static bool run(const vector_type &v, T a)
    {
        return run(v, broadcast<T, Elems>::run(a));
    }
};

template <typename T, unsigned Elems>
struct equal_bits_impl<16, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static bool run(const vector_type &v1, const vector_type &v2)
    {
        // Use the 16b implementation as masks are 32b and don't introduce EXTEND instructions
        if constexpr (Elems == 64) {
            const auto mask1 = eq<T, Elems / 2>::run(v1.template extract<32>(0), v2.template extract<32>(0));
            const auto mask2 = eq<T, Elems / 2>::run(v1.template extract<32>(1), v2.template extract<32>(1));

            return (mask1 & mask2).full();
        }
        else {
            return eq<T, Elems>::run(v1, v2).full();
        }
    }

    __aie_inline
    static bool run(T a, const vector_type &v)
    {
        return run(broadcast<T, Elems>::run(a), v);
    }

    __aie_inline
    static bool run(const vector_type &v, T a)
    {
        return run(v, broadcast<T, Elems>::run(a));
    }
};

template <typename T, unsigned Elems>
struct equal_bits_impl<32, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static bool run(const vector_type &v1, const vector_type &v2)
    {
        // Use the 16b implementation as masks are 32b and don't introduce EXTEND instructions
        const vector<uint16, Elems * 2> tmp1 = vector_cast<uint16>(v1);
        const vector<uint16, Elems * 2> tmp2 = vector_cast<uint16>(v2);

        return equal_bits_impl<16, uint16, Elems * 2>::run(tmp1, tmp2);
    }

    __aie_inline
    static bool run(T a, const vector_type &v)
    {
        return run(broadcast<T, Elems>::run(a), v);
    }

    __aie_inline
    static bool run(const vector_type &v, T a)
    {
        return run(v, broadcast<T, Elems>::run(a));
    }
};

template <unsigned Elems>
struct equal_bits_impl<32, float, Elems>
{
    using           T = float;
    using vector_type = vector<T, Elems>;

    __aie_inline
    static bool run(const vector_type &v1, const vector_type &v2)
    {
        return eq<T, Elems>::run(v1, v2).full();
    }

    __aie_inline
    static bool run(T a, const vector_type &v)
    {
        return run(broadcast<T, Elems>::run(a), v);
    }

    __aie_inline
    static bool run(const vector_type &v, T a)
    {
        return run(v, broadcast<T, Elems>::run(a));
    }
};

template <typename T, unsigned Elems>
struct equal_bits_impl<64, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static_assert(vector_type::is_complex());

    __aie_inline
    static bool run(const vector_type &v1, const vector_type &v2)
    {
        // Use the 16b implementation as masks are 32b and don't introduce EXTEND instructions
        const vector<uint16, Elems * 4> tmp1 = vector_cast<uint16>(v1);
        const vector<uint16, Elems * 4> tmp2 = vector_cast<uint16>(v2);

        return equal_bits_impl<16, uint16, Elems * 4>::run(tmp1, tmp2);
    }

    __aie_inline
    static bool run(T a, const vector_type &v)
    {
        return run(broadcast<T, Elems>::run(a), v);
    }

    __aie_inline
    static bool run(const vector_type &v, T a)
    {
        return run(v, broadcast<T, Elems>::run(a));
    }
};

}

#endif
