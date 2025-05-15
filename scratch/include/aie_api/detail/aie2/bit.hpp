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

#ifndef __AIE_API_DETAIL_AIE2_BIT__HPP__
#define __AIE_API_DETAIL_AIE2_BIT__HPP__

#include "../vector.hpp"

namespace aie::detail {

template <typename T, unsigned Elems, BitOp Op>
struct bit_bits_impl<4, T, Elems, Op>
{
    using vector_type = vector<T, Elems>;

    static vector_type run(const vector_type &v1, const vector_type &v2)
    {
        using next_type = utils::get_next_integer_type_t<T>;

        vector_type ret;

        if constexpr (vector_type::bits() == 1024) {
            const auto v1_1 = v1.template extract<128>(0).unpack();
            const auto v1_2 = v1.template extract<128>(1).unpack();
            const auto v2_1 = v2.template extract<128>(0).unpack();
            const auto v2_2 = v2.template extract<128>(1).unpack();

            ret = concat_vector(bit_bits_impl<8, next_type, 128, Op>::run(v1_1, v2_1).pack(),
                                bit_bits_impl<8, next_type, 128, Op>::run(v1_2, v2_2).pack());
        }
        else {
            return bit_bits_impl<8, next_type, Elems, Op>::run(v1.unpack(), v2.unpack()).pack();
        }

        return ret;
    }

    template <unsigned Elems2>
    static vector_type run(vector_elem_const_ref<T, Elems2> a, const vector_type &v)
    {
        return run((T)a, v);
    }

    template <unsigned Elems2>
    static vector_type run(const vector_type &v, vector_elem_const_ref<T, Elems2> a)
    {
        return run(v, (T)a);
    }

    static vector_type run(const T &a, const vector_type &v)
    {
        using next_type = utils::get_next_integer_type_t<T>;

        vector_type ret;

        if constexpr (vector_type::bits() == 1024) {
            const auto v1 = broadcast<next_type, 128>::run(a);
            const auto v2_1 = v.template extract<128>(0).unpack();
            const auto v2_2 = v.template extract<128>(1).unpack();

            ret.template insert<128>(0, bit_bits_impl<8, next_type, 128, Op>::run(v1, v2_1).pack());
            ret.template insert<128>(1, bit_bits_impl<8, next_type, 128, Op>::run(v1, v2_2).pack());
        }
        else {
            const auto v1 = broadcast<next_type, Elems>::run(a);
            const auto v2 = v.unpack();
            return bit_bits_impl<8, next_type, Elems, Op>::run(v1, v2).pack();
        }

        return ret;
    }

    static vector_type run(const vector_type &v, const T &a)
    {
        using next_type = utils::get_next_integer_type_t<T>;

        vector_type ret;

        if constexpr (vector_type::bits() == 1024) {
            const auto v1_1 = v.template extract<128>(0).unpack();
            const auto v1_2 = v.template extract<128>(1).unpack();
            const auto v2 = broadcast<next_type, 128>::run(a);

            ret.template insert<128>(0, bit_bits_impl<8, next_type, 128, Op>::run(v1_1, v2).pack());
            ret.template insert<128>(1, bit_bits_impl<8, next_type, 128, Op>::run(v1_2, v2).pack());
        }
        else {
            const auto v2 = broadcast<next_type, Elems>::run(a);
            const auto v1 = v.unpack();
            return bit_bits_impl<8, next_type, Elems, Op>::run(v1, v2).pack();
        }

        return ret;
    }

    static vector_type run(const vector_type &v)
    {
        using next_type = utils::get_next_integer_type_t<T>;

        vector_type ret;

        if constexpr (vector_type::bits() == 1024) {
            const auto v1_1 = v.template extract<128>(0).unpack();
            const auto v1_2 = v.template extract<128>(1).unpack();

            ret.template insert<128>(0, bit_bits_impl<8, next_type, 128, Op>::run(v1_1).pack());
            ret.template insert<128>(1, bit_bits_impl<8, next_type, 128, Op>::run(v1_2).pack());
        }
        else {
            const auto v1 = v.unpack();
            return bit_bits_impl<8, next_type, Elems, Op>::run(v1).pack();
        }

        return ret;
    }
};

template <unsigned TypeBits, typename T, unsigned Elems, BitOp Op>
struct bit_bits_impl_common
{
    using vector_type = vector<T, Elems>;

    static constexpr unsigned native_elems = 512 / TypeBits;

    static constexpr auto get_op1()
    {
        if constexpr (Op == BitOp::Not) return [](auto &&... args) __aie_inline { return ::bneg(args...); };
    }

    static constexpr auto get_op2()
    {
        if      constexpr (Op == BitOp::And) return [](auto &&... args) __aie_inline { return ::band(args...); };
        else if constexpr (Op == BitOp::Or)  return [](auto &&... args) __aie_inline { return ::bor(args...); };
        else if constexpr (Op == BitOp::Xor) return [](auto &&... args) __aie_inline { return ::bxor(args...); };
    }

    static vector_type run(const vector_type &v1, const vector_type &v2)
    {
        constexpr auto op = get_op2();

        vector_type ret;

        if constexpr (vector_type::bits() <= 256) {
            const vector<T, native_elems> tmp = bit_bits_impl<TypeBits, T, native_elems, Op>::run(v1.template grow<native_elems>(),
                                                                                                  v2.template grow<native_elems>());
            ret = tmp.template extract<Elems>(0);
        }
        else if constexpr (vector_type::bits() == 512) {
            ret = op(v1, v2);
        }
        else if constexpr (vector_type::bits() == 1024) {
            ret.template insert<native_elems>(0, op(v1.template extract<Elems / 2>(0), v2.template extract<Elems / 2>(0)));
            ret.template insert<native_elems>(1, op(v1.template extract<Elems / 2>(1), v2.template extract<Elems / 2>(1)));
        }

        return ret;
    }

    static vector_type run(const T a, const vector_type &v)
    {
        constexpr auto op = get_op2();

        if constexpr (vector_type::bits() == 1024) {
            const vector<T, Elems / 2> vals = broadcast<T, Elems / 2>::run(a);

            vector_type ret;

            ret.template insert<native_elems>(0, op(vals, v.template extract<Elems / 2>(0)));
            ret.template insert<native_elems>(1, op(vals, v.template extract<Elems / 2>(1)));

            return ret;
        }
        else {
            return run(broadcast<T, Elems>::run(a), v);
        }
    }

    static vector_type run(const vector_type &v, const T a)
    {
        constexpr auto op = get_op2();

        if constexpr (vector_type::bits() == 1024) {
            const vector<T, Elems / 2> vals = broadcast<T, Elems / 2>::run(a);

            vector_type ret;

            ret.template insert<native_elems>(0, op(v.template extract<Elems / 2>(0), vals));
            ret.template insert<native_elems>(1, op(v.template extract<Elems / 2>(1), vals));

            return ret;
        }
        else {
            return run(v, broadcast<T, Elems>::run(a));
        }
    }

    static vector_type run(const vector_type &v)
    {
        constexpr auto op = get_op1();

        vector_type ret;

        if constexpr (vector_type::bits() <= 256) {
            const vector<T, native_elems> tmp = bit_bits_impl<TypeBits, T, native_elems, Op>::run(v.template grow<native_elems>());
            ret = tmp.template extract<Elems>(0);
        }
        else if constexpr (vector_type::bits() == 512) {
            ret = op(v);
        }
        else if constexpr (vector_type::bits() == 1024) {
            ret.template insert<native_elems>(0, op(v.template extract<Elems / 2>(0)));
            ret.template insert<native_elems>(1, op(v.template extract<Elems / 2>(1)));
        }

        return ret;
    }
};

template <typename T, unsigned Elems, BitOp Op> struct bit_bits_impl< 8, T, Elems, Op> : public bit_bits_impl_common< 8, T, Elems, Op> {};
template <typename T, unsigned Elems, BitOp Op> struct bit_bits_impl<16, T, Elems, Op> : public bit_bits_impl_common<16, T, Elems, Op> {};
template <typename T, unsigned Elems, BitOp Op> struct bit_bits_impl<32, T, Elems, Op> : public bit_bits_impl_common<32, T, Elems, Op> {};
template <typename T, unsigned Elems, BitOp Op> struct bit_bits_impl<64, T, Elems, Op> : public bit_bits_impl_common<64, T, Elems, Op> {};

}

#endif
