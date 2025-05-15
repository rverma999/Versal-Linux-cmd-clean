// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
/*  (c) Copyright 2022 - 2022 Xilinx, Inc. All rights reserved.

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


#ifndef __AIE_API_DETAIL_AIE2_ELEMENTARY__HPP__
#define __AIE_API_DETAIL_AIE2_ELEMENTARY__HPP__

#include "tile.hpp"

#include "../vector.hpp"

#include "../add.hpp"
#include "../broadcast.hpp"

namespace aie::detail {

template <unsigned Bits, typename TR, typename T, unsigned N>
struct elementary_vector_bits_impl<ElementaryOp::Fix2Float, Bits, TR, T, N>
{
    using vector_ret_type = vector<TR, N>;
    using     vector_type = vector<T, N>;

    __aie_inline
    static vector_ret_type run(const vector_type &v, int shift = 0)
    {
        constexpr unsigned N_Op = std::max(N, 32u);

        using upper_t = std::conditional_t<std::is_signed_v<T>, int16, uint16>;

        using acc_fp_t  = aie::accum<accfloat, N_Op>;
        using acc_int_t = aie::accum<acc32, N_Op>;

        using acc_fp16_t = aie::accum<accfloat, 16>;

        acc_fp_t magic_h, magic_l;

        vector<bfloat16, 32> vmagic_h = broadcast<int16, 32>::run(0x5301 - 128 * shift).template cast_to<bfloat16>();
        vector<bfloat16, 32> vmagic_l = broadcast<int16, 32>::run(0x4b01 - 128 * shift).template cast_to<bfloat16>();

        if constexpr (N <= 16) {
            magic_h.insert(0, acc_fp16_t(vmagic_h.extract<16>(0)));
            magic_l.insert(0, acc_fp16_t(vmagic_l.extract<16>(0)));
        }
        else if constexpr (N == 32) {
            magic_h.insert(0, acc_fp16_t(vmagic_h.extract<16>(0)));
            magic_h.insert(1, acc_fp16_t(vmagic_h.extract<16>(0)));

            magic_l.insert(0, acc_fp16_t(vmagic_l.extract<16>(0)));
            magic_l.insert(1, acc_fp16_t(vmagic_l.extract<16>(0)));
        }
        else if constexpr (N == 64) {
            magic_h.insert(0, acc_fp16_t(vmagic_h.extract<16>(0)));
            magic_h.insert(1, acc_fp16_t(vmagic_h.extract<16>(0)));
            magic_h.insert(2, acc_fp16_t(vmagic_h.extract<16>(0)));
            magic_h.insert(3, acc_fp16_t(vmagic_h.extract<16>(0)));

            magic_l.insert(0, acc_fp16_t(vmagic_l.extract<16>(0)));
            magic_l.insert(1, acc_fp16_t(vmagic_l.extract<16>(0)));
            magic_l.insert(2, acc_fp16_t(vmagic_l.extract<16>(0)));
            magic_l.insert(3, acc_fp16_t(vmagic_l.extract<16>(0)));
        }

        acc_fp_t vfp;
        if constexpr (sizeof(T) > 2) {
            acc_fp_t tmp;
            acc_int_t vint_h(filter<upper_t, N_Op * 2, FilterOp::Odd >::run(v.template cast_to<upper_t>().template grow<N_Op * 2>(), 1));
            acc_int_t vint_l(filter<uint16,  N_Op * 2, FilterOp::Even>::run(v.template cast_to<uint16>().template  grow<N_Op * 2>(), 1));

            vint_h = add_accum<acc32, N_Op>::run(vint_h, false, magic_h.template cast_to<acc32>());
            vint_l = add_accum<acc32, N_Op>::run(vint_l, false, magic_l.template cast_to<acc32>());

            tmp = sub_accum<accfloat, N_Op>::run(vint_h.template cast_to<accfloat>(), false, magic_h);
            vfp = sub_accum<accfloat, N_Op>::run(vint_l.template cast_to<accfloat>(), false, magic_l);

            vfp = add_accum<accfloat, N_Op>::run(vfp, false, tmp);
        }
        else {
            acc_int_t vint(aie::accum<acc32, N>(v).template grow<N_Op>());

            vint = add_accum<acc32, N_Op>::run(vint, false, magic_l.template cast_to<acc32>());
            vfp  = sub_accum<accfloat,  N_Op>::run(vint.template cast_to<accfloat>(), false, magic_l);
        }

        return vfp.template extract<N>(0).template to_vector<TR>();
    }
};

template <unsigned Bits, typename TR, typename T, unsigned N>
struct elementary_vector_bits_impl<ElementaryOp::Float2Fix, Bits, TR, T, N>
{
    using vector_ret_type = vector<TR, N>;
    using     vector_type = vector<T, N>;

    __aie_inline
    static vector_ret_type run(const vector_type &v, int shift = 0)
    {
        constexpr unsigned N_Op = std::max(N, 32u);

        using upper_t = std::conditional_t<std::is_signed_v<T>, int16, uint16>;

        using acc_fp_t  = aie::accum<accfloat, N_Op>;
        using acc_int_t = aie::accum<acc32, N_Op>;

        using acc_fp16_t = aie::accum<accfloat, 16>;

        acc_fp_t magic_h, magic_l;

        vector<bfloat16, 32> vmagic_h = broadcast<int16, 32>::run(0x5301 - 128 * shift).template cast_to<bfloat16>();
        vector<bfloat16, 32> vmagic_l = broadcast<int16, 32>::run(0x4b01 - 128 * shift).template cast_to<bfloat16>();

        if constexpr (N <= 16) {
            magic_h.insert(0, acc_fp16_t(vmagic_h.extract<16>(0)));
            magic_l.insert(0, acc_fp16_t(vmagic_l.extract<16>(0)));
        }
        else if constexpr (N == 32) {
            magic_h.insert(0, acc_fp16_t(vmagic_h.extract<16>(0)));
            magic_h.insert(1, acc_fp16_t(vmagic_h.extract<16>(0)));

            magic_l.insert(0, acc_fp16_t(vmagic_l.extract<16>(0)));
            magic_l.insert(1, acc_fp16_t(vmagic_l.extract<16>(0)));
        }
        else if constexpr (N == 64) {
            magic_h.insert(0, acc_fp16_t(vmagic_h.extract<16>(0)));
            magic_h.insert(1, acc_fp16_t(vmagic_h.extract<16>(0)));
            magic_h.insert(2, acc_fp16_t(vmagic_h.extract<16>(0)));
            magic_h.insert(3, acc_fp16_t(vmagic_h.extract<16>(0)));

            magic_l.insert(0, acc_fp16_t(vmagic_l.extract<16>(0)));
            magic_l.insert(1, acc_fp16_t(vmagic_l.extract<16>(0)));
            magic_l.insert(2, acc_fp16_t(vmagic_l.extract<16>(0)));
            magic_l.insert(3, acc_fp16_t(vmagic_l.extract<16>(0)));
        }

        const saturation_mode sat = tile::current().get_saturation();
        tile::current().set_saturation(saturation_mode::saturate);

        const acc_fp_t acc_input(v.template grow<N_Op>());
        acc_fp_t vfp = acc_input;
        acc_int_t vint;
        vector<upper_t, N_Op> out_h;
        vector<TR, N> output;

        if constexpr (sizeof(TR) > 2 ) {
            acc_fp_t tmp;
            vfp  = add_accum<accfloat,  N_Op>::run(vfp, false, magic_h);
            vint = sub_accum<acc32,     N_Op>::run(vfp.template cast_to<acc32>(),
                                                   false,
                                                   magic_h.template cast_to<acc32>());

            out_h = vint.template to_vector<upper_t>();

            vint = add_accum<acc32, N_Op>::run(acc_int_t(out_h),
                                               false,
                                               magic_h.template cast_to<acc32>());
            tmp  = sub_accum<accfloat, N_Op>::run(vint.template cast_to<accfloat>(), false, magic_h);
            vfp  = sub_accum<accfloat, N_Op>::run(acc_input, false, tmp);
        }

        vfp  = add_accum<accfloat, N_Op>::run(vfp, false, magic_l);
        vint = sub_accum<acc32,    N_Op>::run(vfp.template cast_to<acc32>(),
                                              false,
                                              magic_l.template cast_to<acc32>());

        if constexpr (sizeof(TR) > 2) {
            auto out_lp = vint.template to_vector<uint16>();
            aie::accum<acc32, 32> vint_neg = ::neg(vint.template grow<32>());
            auto out_ln = vint_neg.extract<N_Op>(0).template to_vector<uint16>();

            using acc_t = aie::accum<acc64, N_Op>;
            acc_t tmp;
            tmp = add_accum<acc64, N_Op>::run(acc_t(out_h, 16), false, acc_t(out_lp));
            auto acc = sub_accum<acc64, N_Op>::run(tmp, false, acc_t(out_ln));
            output = acc.template to_vector<TR>().template extract<N>(0);
        }
        else {
            output = vint.template to_vector<TR>().template extract<N>(0);
        }

        tile::current().set_saturation(sat);

        return output;
    }
};

template <unsigned N>
struct elementary_vector_bits_impl<ElementaryOp::Float2Fix, 16, int16, bfloat16, N>
{
    using vector_ret_type = vector<int16, N>;
    using     vector_type = vector<bfloat16, N>;

    __aie_inline
    static vector_ret_type run(const vector_type &v, int shift = 0)
    {
        constexpr unsigned num_op = N < 32? 1 : N / 32;

        vector_ret_type ret;

        utils::unroll_times<num_op>([&](auto idx) __aie_inline {
            vector<int32, 16> tmp1, tmp2;

            tmp1 = ::bfloat16_to_int(v.template grow_extract<16>(idx * 2), shift);

            if constexpr (N > 16)
                tmp2 = ::bfloat16_to_int(v.template grow_extract<16>(idx * 2 + 1), shift);

            tmp1 = ::shuffle(tmp1, tmp2, DINTLV_lo_16o32);

            if constexpr (N <= 16)
                ret = tmp1.cast_to<int16>().extract<N>(0);
            else
                ret.insert(idx, tmp1.cast_to<int16>());
        });

        return ret;
    }
};

template <unsigned N>
struct elementary_vector_bits_impl<ElementaryOp::Float2Fix, 16, int32, bfloat16, N>
{
    using vector_ret_type = vector<int32, N>;
    using     vector_type = vector<bfloat16, N>;

    __aie_inline
    static vector_ret_type run(const vector_type &v, int shift = 0)
    {
        constexpr unsigned num_op = N < 16? 1 : N / 16;

        vector_ret_type ret;

        utils::unroll_times<num_op>([&](auto idx) __aie_inline {
            vector<int32, 16> tmp;

            tmp = ::bfloat16_to_int(v.template grow_extract<16>(idx), shift);

            if constexpr (N < 16)
                ret = tmp.extract<N>(0);
            else
                ret.insert(idx, tmp);
        });

        return ret;
    }
};

template <unsigned N>
struct elementary_vector_bits_impl<ElementaryOp::Inv, 16, bfloat16, bfloat16, N>
{
    using vector_ret_type = vector<bfloat16, N>;
    using     vector_type = vector<bfloat16, N>;

    __aie_inline
    static vector_ret_type run(const vector_type &v, int shift = 0)
    {
        constexpr unsigned num_op = N < 16? 1 : N / 16;

        vector_ret_type ret;

        utils::unroll_times<num_op>([&](auto idx) __aie_inline {
            vector<bfloat16, 32> current = zeros<bfloat16, 32>::run();
            current.insert(0, v.template grow_extract<16>(idx));

            const vector<int16, 32> magic = broadcast<int16, 32>::run(0x7eb5);
            vector<bfloat16, 32>       k1 = broadcast<bfloat16, 32>::run(1.9395974f);
            const accum<accfloat, 16>   acc_k2(broadcast<float, 16>::run(1.436142f));
            const accum<accfloat, 16> acc_twos(broadcast<float, 16>::run(2.0f));

            k1.insert(1, zeros<bfloat16, 16>::run());

            // int16 i = *(int16*)&v;
            // i = 0x7eb5 - i;
            // bfloat16 y = *(bfloat16*)&i;
            vector<bfloat16, 32> y = zeros<bfloat16, 32>::run();
            y.insert(0, sub<int16, 32>::run(magic, current.template cast_to<int16>()).template cast_to<bfloat16>().template extract<16>(0));

            // y = k1*y*((-v)*y + k2);
            accum<accfloat, 16> acc = ::negmul_elem_16_2(current, y);
            acc = add_accum<accfloat, 16>::run(acc, false, acc_k2);

            vector<bfloat16, 32> tmp2 = zeros<bfloat16, 32>::run();
            tmp2.insert(0, acc.to_vector<bfloat16>());

            acc = ::mul_elem_16_2(tmp2, y);
            tmp2.insert(0, acc.to_vector<bfloat16>());

            // This computes -y
            acc = ::negmul_elem_16_2(tmp2, k1);
            tmp2.insert(0, acc.to_vector<bfloat16>());

            y = tmp2;

            // bfloat16 r = -y * v + 2.0f;
            acc = ::mac_elem_16_2( y, current, acc_twos);
            tmp2.insert(0, acc.to_vector<bfloat16>());

            // y = y*r
            acc = ::negmul_elem_16_2( y, tmp2);

            if constexpr (N < 16)
                ret = acc.to_vector<bfloat16>().extract<N>(0);
            else
                ret.insert(idx, acc.to_vector<bfloat16>());
        });

        return ret;
    }
};

template <unsigned N>
struct elementary_vector_bits_impl<ElementaryOp::InvSqrt, 16, bfloat16, bfloat16, N>
{
    using vector_ret_type = vector<bfloat16, N>;
    using     vector_type = vector<bfloat16, N>;

    __aie_inline
    static vector_ret_type run(const vector_type &v, int shift = 0)
    {
        // Implementation based on http://rrrola.wz.cz/inv_sqrt.html
        constexpr int   C1 = 0x5F1FFFF9;
        constexpr float C2 = 0.703952253f;
        constexpr float C3 = 2.38924456f;

        constexpr unsigned num_op = N < 16? 1 : N / 16;

        vector_ret_type ret;

        const vector<int32, 16>               c1 = broadcast<int32, 16>::run(C1);
        const vector<bfloat16, 32>            c2 = broadcast<bfloat16, 32>::run(C2);
        const accum<accfloat, 16> c2c3(broadcast<float, 16>::run(C2 * C3));

        vector<bfloat16, 32> current_zero = zeros<bfloat16, 32>::run();
        vector<bfloat16, 32>           x2 = zeros<bfloat16, 32>::run();
        vector<bfloat16, 32>            y = zeros<bfloat16, 32>::run();
        vector<bfloat16, 32>           yy = zeros<bfloat16, 32>::run();
        vector<bfloat16, 32>         x2yy = zeros<bfloat16, 32>::run();

        utils::unroll_times<num_op>([&](auto idx) __aie_inline {
            const vector<bfloat16, 16> current = v.template grow_extract<16>(idx);
            current_zero.insert(0, current);

            accum<accfloat, 16> x2_acc = ::mul_elem_16_2(current_zero, c2);
            x2.insert(0, x2_acc.to_vector<bfloat16>());

            accum<accfloat, 16> current_acc(current);
            accum<acc64, 16> current_int_acc(current_acc.cast_to<acc32>().to_vector<int32>());

            vector<int32, 16> i = ::sub(c1, current_int_acc.to_vector<int32>(1));
            accum<accfloat, 16> ii(i.cast_to<float>());
            y.insert<16>(0, ii.to_vector<bfloat16>());

            const accum<accfloat, 16> yy_acc = ::mul_elem_16_2(y, y);
            yy.insert<16>(0, yy_acc.to_vector<bfloat16>());

            const accum<accfloat, 16> x2yy_acc = ::msc_elem_16_2(x2, yy, c2c3);
            x2yy.insert<16>(0, x2yy_acc.to_vector<bfloat16>());

            const accum<accfloat, 16> acc = ::mul_elem_16_2(y, x2yy);

            if constexpr (N < 16)
                ret = acc.to_vector<bfloat16>().extract<N>(0);
            else
                ret.insert(idx, acc.to_vector<bfloat16>());
        });

        return ret;
    }
};

template <unsigned N>
struct elementary_vector_bits_impl<ElementaryOp::Inv, 32, float, float, N>
{
    using vector_ret_type = vector<float, N>;
    using     vector_type = vector<float, N>;

    __aie_inline
    static vector_ret_type run(const vector_type &v, int shift = 0)
    {
        constexpr unsigned num_op = N < 16? 1 : N / 16;

        vector_ret_type ret;

        utils::unroll_times<num_op>([&](auto idx) __aie_inline {
            vector<float, 16> current = v.template grow_extract<16>(idx);

            const vector<int32, 16> magic = broadcast<int32, 16>::run(0x7eb53567);
            const vector<float, 16>    k1 = broadcast<float, 16>::run(1.9395974f);
            const accum<accfloat, 16>   acc_k2(broadcast<float, 16>::run(1.436142f));
            const accum<accfloat, 16> acc_twos(broadcast<float, 16>::run(2.0f));

            // int32 i = *(int32*)&v;
            // i = 0x7eb53567 - i;
            // float y = *(float *)&i;
            vector<float, 16> y = sub<int32, 16>::run(magic, current.template cast_to<int32>()).template cast_to<float>();

            // y = k1*y*((-v)*y + k2);
            accum<accfloat, 16> acc = ::negmul_elem_16(current, y);
            acc = add_accum<accfloat, 16>::run(acc, false, acc_k2);

            acc = ::mul_elem_16(acc.to_vector<float>(), y);

            // This computes -y
            acc = ::negmul_elem_16(acc.to_vector<float>(), k1);

            y = acc.to_vector<float>();

            // bfloat16 r = -y * v + 2.0f;
            acc = ::mac_elem_16( y, current, acc_twos);

            // y = y*r
            acc = ::negmul_elem_16( y, acc.to_vector<float>());

            if constexpr (N < 16)
                ret = acc.to_vector<float>().extract<N>(0);
            else
                ret.insert(idx, acc.to_vector<float>());
        });

        return ret;
    }
};

template <unsigned N>
struct elementary_vector_bits_impl<ElementaryOp::InvSqrt, 32, float, float, N>
{
    using vector_ret_type = vector<float, N>;
    using     vector_type = vector<float, N>;

    __aie_inline
    static vector_ret_type run(const vector_type &v, int shift = 0)
    {
        // Implementation based on http://rrrola.wz.cz/inv_sqrt.html
        constexpr int   C1 = 0x5F1FFFF9;
        constexpr float C2 = 0.703952253f;
        constexpr float C3 = 2.38924456f;

        constexpr unsigned num_op = N < 16? 1 : N / 16;

        vector_ret_type ret;

        const vector<int32, 16>               c1 = broadcast<int32, 16>::run(C1);
        const vector<float, 16>               c2 = broadcast<float, 16>::run(C2);
        const accum<accfloat, 16> c2c3(broadcast<float, 16>::run(C2 * C3));

        utils::unroll_times<num_op>([&](auto idx) __aie_inline {
            const vector<float, 16> current = v.template grow_extract<16>(idx);

            accum<accfloat, 16> x2_acc = ::mul_elem_16(current, c2);

            accum<accfloat, 16> current_acc(current);
            accum<acc64, 16> current_int_acc(current_acc.cast_to<acc32>().to_vector<int32>());

            vector<int32, 16> i = ::sub(c1, current_int_acc.to_vector<int32>(1));
            vector<float, 16> y = i.cast_to<float>();

            const accum<accfloat, 16> yy_acc = ::mul_elem_16(y, y);

            const accum<accfloat, 16> x2yy_acc = ::msc_elem_16(x2_acc.to_vector<float>(),
                                                                         yy_acc.to_vector<float>(),
                                                                         c2c3);
            const accum<accfloat, 16> acc = ::mul_elem_16(y, x2yy_acc.to_vector<float>());

            if constexpr (N < 16)
                ret = acc.to_vector<float>().extract<N>(0);
            else
                ret.insert(idx, acc.to_vector<float>());
        });

        return ret;
    }
};


template <ElementaryOp Op, unsigned TypeBits, typename TR, typename T>
struct elementary_bits_common_impl
{
    static constexpr unsigned native_elems = ((Op == ElementaryOp::Inv || Op == ElementaryOp::InvSqrt)? 256 : 512) / TypeBits;

    __aie_inline
    static TR run(const T &a, int shift = 0)
    {
        vector<T, native_elems> v(a);

        return elementary_vector<Op, TR, T, native_elems>::run(v, shift)[0];
    }
};

template <unsigned TypeBits, typename TR, typename T>
struct elementary_bits_impl<ElementaryOp::Float2Fix, TypeBits, TR, T> : elementary_bits_common_impl<ElementaryOp::Float2Fix, TypeBits, TR, T> {};
template <unsigned TypeBits, typename TR, typename T>
struct elementary_bits_impl<ElementaryOp::Fix2Float, TypeBits, TR, T> : elementary_bits_common_impl<ElementaryOp::Fix2Float, TypeBits, TR, T> {};

template <unsigned TypeBits>
struct elementary_bits_impl<ElementaryOp::Inv,     TypeBits, bfloat16, bfloat16> : elementary_bits_common_impl<ElementaryOp::Inv,     TypeBits, bfloat16, bfloat16> {};
template <unsigned TypeBits>
struct elementary_bits_impl<ElementaryOp::InvSqrt, TypeBits, bfloat16, bfloat16> : elementary_bits_common_impl<ElementaryOp::InvSqrt, TypeBits, bfloat16, bfloat16> {};

}

#endif
