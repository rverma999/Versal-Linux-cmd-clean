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

#ifndef __AIE_API_DETAIL_AIE2_ADD_ACCUM__HPP__
#define __AIE_API_DETAIL_AIE2_ADD_ACCUM__HPP__

#include "../add.hpp"
#include "../vector.hpp"

namespace aie::detail {

template <AddSubOperation Op>
constexpr auto get_add_sub_accum_op()
{
    if      constexpr (Op == AddSubOperation::Add) return [](auto... args) { return ::add_conf(args...); };
    else if constexpr (Op == AddSubOperation::Sub) return [](auto... args) { return ::sub_conf(args...); };
}

template <unsigned AccumBits, unsigned TypeBits, typename T, unsigned Elems, AddSubOperation Op>
struct add_sub_accum_vector_bits_impl_common
{
    using vector_type = vector<T, Elems>;
    using   accum_tag = accum_tag_for_type<T, AccumBits>;
    template <unsigned Elems2 = Elems>
    using  accum_type = accum<accum_tag, Elems2>;

    __aie_inline
    static accum_type<> run(const accum_type<> &acc, bool zero_acc, const vector_type &v)
    {
        constexpr auto op = get_add_sub_accum_op<Op>();

        constexpr unsigned native_elems = 1024 / accum_type<>::value_bits();

        if constexpr (accum_type<>::bits() <= 1024) {
            accum_type<native_elems> tmp;

            const accum_type<native_elems> acc2(v.template grow<native_elems>());

            tmp = op(acc.template grow<native_elems>(), acc2, zero_acc, 0, 0, 0);

            return tmp.template extract<Elems>(0);
        }
        else if constexpr (accum_type<>::bits() == 2048) {
            accum_type<> ret;

            const accum_type<native_elems> acc2_1(v.template extract<native_elems>(0));
            const accum_type<native_elems> acc2_2(v.template extract<native_elems>(1));

            ret.template insert<native_elems>(0, op(acc.template extract<native_elems>(0), acc2_1, zero_acc, 0, 0, 0));
            ret.template insert<native_elems>(1, op(acc.template extract<native_elems>(1), acc2_2, zero_acc, 0, 0, 0));

            return ret;
        }
        else if constexpr (accum_type<>::bits() == 4096) {
            accum_type<> ret;

            const accum_type<native_elems> acc2_1(v.template extract<native_elems>(0));
            const accum_type<native_elems> acc2_2(v.template extract<native_elems>(1));
            const accum_type<native_elems> acc2_3(v.template extract<native_elems>(2));
            const accum_type<native_elems> acc2_4(v.template extract<native_elems>(3));

            ret.template insert<native_elems>(0, op(acc.template extract<native_elems>(0), acc2_1, zero_acc, 0, 0, 0));
            ret.template insert<native_elems>(1, op(acc.template extract<native_elems>(1), acc2_2, zero_acc, 0, 0, 0));
            ret.template insert<native_elems>(2, op(acc.template extract<native_elems>(2), acc2_3, zero_acc, 0, 0, 0));
            ret.template insert<native_elems>(3, op(acc.template extract<native_elems>(3), acc2_4, zero_acc, 0, 0, 0));

            return ret;
        }
    }

    template <unsigned Elems2>
    __aie_inline
    static accum_type<> run(const accum_type<> &acc, bool zero_acc, vector_elem_const_ref<T, Elems2> a)
    {
        return run(acc, zero_acc, broadcast<T, Elems>::run(a));
    }

    __aie_inline
    static accum_type<> run(const accum_type<> &acc, bool zero_acc, const T &a)
    {
        return run(acc, zero_acc, broadcast<T, Elems>::run(a));
    }
};

template <unsigned AccumBits, AccumClass Class, unsigned Elems, AddSubOperation Op>
struct add_sub_accum_bits_impl_common
{
    using   accum_tag = accum_tag_t<Class, AccumBits>;
    template <unsigned Elems2 = Elems>
    using  accum_type = accum<accum_tag, Elems2>;

    __aie_inline
    static accum_type<> run(const accum_type<> &acc1, bool zero_acc1, const accum_type<> &acc2)
    {
        constexpr auto op = get_add_sub_accum_op<Op>();

        constexpr unsigned native_elems = 1024 / accum_type<>::value_bits();

        if constexpr (accum_type<>::bits() <= 1024) {
            accum_type<native_elems> tmp;

            tmp = op(acc1.template grow<native_elems>(), acc2.template grow<native_elems>(), zero_acc1, 0, 0, 0);

            return tmp.template extract<Elems>(0);
        }
        else if constexpr (accum_type<>::bits() == 2048) {
            accum_type<> ret;

            ret.template insert<native_elems>(0, op(acc1.template extract<native_elems>(0), acc2.template extract<native_elems>(0), zero_acc1, 0, 0, 0));
            ret.template insert<native_elems>(1, op(acc1.template extract<native_elems>(1), acc2.template extract<native_elems>(1), zero_acc1, 0, 0, 0));

            return ret;
        }
        else if constexpr (accum_type<>::bits() == 4096) {
            accum_type<> ret;

            ret.template insert<native_elems>(0, op(acc1.template extract<native_elems>(0), acc2.template extract<native_elems>(0), zero_acc1, 0, 0, 0));
            ret.template insert<native_elems>(1, op(acc1.template extract<native_elems>(1), acc2.template extract<native_elems>(1), zero_acc1, 0, 0, 0));
            ret.template insert<native_elems>(2, op(acc1.template extract<native_elems>(2), acc2.template extract<native_elems>(2), zero_acc1, 0, 0, 0));
            ret.template insert<native_elems>(3, op(acc1.template extract<native_elems>(3), acc2.template extract<native_elems>(3), zero_acc1, 0, 0, 0));

            return ret;
        }
    }
};

template <unsigned Elems, AddSubOperation Op>
struct add_sub_accum_bits_impl_common<32, AccumClass::FP, Elems, Op>
{
    static constexpr unsigned AccumBits = 32;

    using   accum_tag = accum_tag_t<AccumClass::FP, 32>;
    template <unsigned Elems2 = Elems>
    using  accum_type = accum<accum_tag, Elems2>;

    __aie_inline
    static accum_type<> run(const accum_type<> &acc1, bool zero_acc1, const accum_type<> &acc2)
    {
        constexpr auto op = get_add_sub_accum_op<Op>();

        constexpr unsigned native_elems = 512 / accum_type<>::value_bits();

        if constexpr (accum_type<>::bits() <= 512) {
            accum_type<native_elems> tmp;

            tmp = op(acc1.template grow<native_elems>(), acc2.template grow<native_elems>(), zero_acc1, 0, 0);

            return tmp.template extract<Elems>(0);
        }
        else if constexpr (accum_type<>::bits() <= 1024) {
            accum_type<> ret;

            accum_type<native_elems> tmp1, tmp2;

            tmp1 = op(acc1.template extract<native_elems>(0), acc2.template extract<native_elems>(0), zero_acc1, 0, 0);
            tmp2 = op(acc1.template extract<native_elems>(1), acc2.template extract<native_elems>(1), zero_acc1, 0, 0);

            ret.insert(0, tmp1);
            ret.insert(1, tmp2);

            return ret;
        }
        else if constexpr (accum_type<>::bits() == 2048) {
            accum_type<> ret;

            accum_type<native_elems> tmp1, tmp2;

            tmp1 = op(acc1.template extract<native_elems>(0), acc2.template extract<native_elems>(0), zero_acc1, 0, 0);
            tmp2 = op(acc1.template extract<native_elems>(1), acc2.template extract<native_elems>(1), zero_acc1, 0, 0);

            ret.insert(0, tmp1);
            ret.insert(1, tmp2);

            tmp1 = op(acc1.template extract<native_elems>(2), acc2.template extract<native_elems>(2), zero_acc1, 0, 0);
            tmp2 = op(acc1.template extract<native_elems>(3), acc2.template extract<native_elems>(3), zero_acc1, 0, 0);

            ret.insert(2, tmp1);
            ret.insert(3, tmp2);

            return ret;
        }
        else if constexpr (accum_type<>::bits() == 4096) {
            accum_type<> ret;

            accum_type<native_elems> tmp1, tmp2;

            tmp1 = op(acc1.template extract<native_elems>(0), acc2.template extract<native_elems>(0), zero_acc1, 0, 0);
            tmp2 = op(acc1.template extract<native_elems>(1), acc2.template extract<native_elems>(1), zero_acc1, 0, 0);

            ret.insert(0, tmp1);
            ret.insert(1, tmp2);

            tmp1 = op(acc1.template extract<native_elems>(2), acc2.template extract<native_elems>(2), zero_acc1, 0, 0);
            tmp2 = op(acc1.template extract<native_elems>(3), acc2.template extract<native_elems>(3), zero_acc1, 0, 0);

            ret.insert(2, tmp1);
            ret.insert(3, tmp2);

            tmp1 = op(acc1.template extract<native_elems>(4), acc2.template extract<native_elems>(4), zero_acc1, 0, 0);
            tmp2 = op(acc1.template extract<native_elems>(5), acc2.template extract<native_elems>(5), zero_acc1, 0, 0);

            ret.insert(4, tmp1);
            ret.insert(5, tmp2);

            tmp1 = op(acc1.template extract<native_elems>(6), acc2.template extract<native_elems>(6), zero_acc1, 0, 0);
            tmp2 = op(acc1.template extract<native_elems>(7), acc2.template extract<native_elems>(7), zero_acc1, 0, 0);

            ret.insert(6, tmp1);
            ret.insert(7, tmp2);

            return ret;
        }
    }
};

#if __AIE_API_COMPLEX_FP32_EMULATION__
template <unsigned Elems, AddSubOperation Op>
struct add_sub_accum_bits_impl_common<32, AccumClass::CFP, Elems, Op>
{
    using   accum_tag = accum_tag_t<AccumClass::CFP, 32>;
    template <unsigned Elems2 = Elems>
    using  accum_type = accum<accum_tag, Elems2>;

    __aie_inline
    static accum_type<> run(const accum_type<> &acc1, bool zero_acc1, const accum_type<> &acc2)
    {
        auto tmp = add_sub_accum_bits_impl_common<32, AccumClass::FP, Elems * 2, Op>::run(acc1.template cast_to<accfloat>(),
                                                                                          zero_acc1,
                                                                                          acc2.template cast_to<accfloat>());

        return tmp.template cast_to<caccfloat>();
    }
};
#endif

template <unsigned TypeBits, typename T, unsigned Elems, AddSubOperation Op>
struct add_sub_accum_vector_bits_impl<32, TypeBits, T, Elems, Op> : public add_sub_accum_vector_bits_impl_common<32, TypeBits, T, Elems, Op> {};

template <unsigned TypeBits, typename T, unsigned Elems, AddSubOperation Op>
struct add_sub_accum_vector_bits_impl<64, TypeBits, T, Elems, Op> : public add_sub_accum_vector_bits_impl_common<64, TypeBits, T, Elems, Op> {};

template <AccumElemBaseType AccumTag, unsigned Elems, AddSubOperation Op>
    requires(accum<AccumTag, Elems>::accum_bits() == 32)
struct add_sub_accum_bits_impl<AccumTag, Elems, Op> : public add_sub_accum_bits_impl_common<32, accum_class_for_tag_v<AccumTag>, Elems, Op> {};

template <AccumElemBaseType AccumTag, unsigned Elems, AddSubOperation Op>
    requires(accum<AccumTag, Elems>::accum_bits() == 64)
struct add_sub_accum_bits_impl<AccumTag, Elems, Op> : public add_sub_accum_bits_impl_common<64, accum_class_for_tag_v<AccumTag>, Elems, Op> {};


template <typename T, unsigned Elems, AddSubOperation Op>
struct add_sub_accum_vector_bits_impl_float_common
{
    using vector_type = vector<T, Elems>;
    using   accum_tag = accum_tag_t<(std::is_same_v<T, cfloat>? AccumClass::CFP : AccumClass::FP), 32>;
    template <unsigned Elems2 = Elems>
    using  accum_type = accum<accum_tag, Elems2>;

    __aie_inline
    static accum_type<> run(const accum_type<> &acc, bool zero_acc, const vector_type &v)
    {
        constexpr auto op = get_add_sub_accum_op<Op>();

        constexpr unsigned native_elems = (std::is_same_v<T, cfloat>? 8 : 16);

        if constexpr (accum_type<>::bits() <= 512) {
            accum_type<native_elems> tmp;

            const accum_type<native_elems> acc2(v.template grow<native_elems>());

            tmp = op(acc.template grow<native_elems>(), acc2, zero_acc, 0, 0);

            return tmp.template extract<Elems>(0);
        }
        else if constexpr (accum_type<>::bits() == 1024) {
            accum_type<> ret;

            const accum_type<native_elems> acc2_1(v.template extract<native_elems>(0));
            const accum_type<native_elems> acc2_2(v.template extract<native_elems>(1));

            ret.template insert<native_elems>(0, op(acc.template extract<native_elems>(0), acc2_1, zero_acc, 0, 0));
            ret.template insert<native_elems>(1, op(acc.template extract<native_elems>(1), acc2_2, zero_acc, 0, 0));

            return ret;
        }
        else if constexpr (accum_type<>::bits() == 2048) {
            accum_type<> ret;

            const accum_type<native_elems> acc2_1(v.template extract<native_elems>(0));
            const accum_type<native_elems> acc2_2(v.template extract<native_elems>(1));
            const accum_type<native_elems> acc2_3(v.template extract<native_elems>(2));
            const accum_type<native_elems> acc2_4(v.template extract<native_elems>(3));

            ret.template insert<native_elems>(0, op(acc.template extract<native_elems>(0), acc2_1, zero_acc, 0, 0));
            ret.template insert<native_elems>(1, op(acc.template extract<native_elems>(1), acc2_2, zero_acc, 0, 0));
            ret.template insert<native_elems>(2, op(acc.template extract<native_elems>(2), acc2_3, zero_acc, 0, 0));
            ret.template insert<native_elems>(3, op(acc.template extract<native_elems>(3), acc2_4, zero_acc, 0, 0));

            return ret;
        }
    }

    template <unsigned Elems2>
    __aie_inline
    static accum_type<> run(const accum_type<> &acc, bool zero_acc, vector_elem_const_ref<T, Elems2> a)
    {
        return run(acc, zero_acc, broadcast<T, Elems>::run(a));
    }

    __aie_inline
    static accum_type<> run(const accum_type<> &acc, bool zero_acc, const T &a)
    {
        return run(acc, zero_acc, broadcast<T, Elems>::run(a));
    }
};

template <unsigned Elems, AddSubOperation Op>
struct add_sub_accum_vector_bits_impl<32, 32, float,    Elems, Op> : public add_sub_accum_vector_bits_impl_float_common<float,    Elems, Op> {};

template <unsigned Elems, AddSubOperation Op>
struct add_sub_accum_vector_bits_impl<32, 16, bfloat16, Elems, Op> : public add_sub_accum_vector_bits_impl_float_common<bfloat16, Elems, Op> {};

#if __AIE_API_COMPLEX_FP32_EMULATION__
template <unsigned Elems, AddSubOperation Op>
struct add_sub_accum_vector_bits_impl<32, 64, cfloat,   Elems, Op> : public add_sub_accum_vector_bits_impl_float_common<cfloat,   Elems, Op> {};
#endif

}

#endif
