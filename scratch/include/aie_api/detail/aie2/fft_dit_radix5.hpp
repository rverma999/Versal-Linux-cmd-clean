// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
/*  (c) Copyright 2021 - 2022 Xilinx, Inc. All rights reserved.

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

#ifndef __AIE_API_DETAIL_AIE2_FFT_DIT_RADIX5_HPP__
#define __AIE_API_DETAIL_AIE2_FFT_DIT_RADIX5_HPP__

#include "../array_helpers.hpp"

namespace aie::detail {

template<unsigned Vectorization, typename Input>
struct fft_dit<Vectorization, 0, 5, Input, cint32, cint16> : public fft_dit_common<Vectorization, 0, 5, Input, cint32, cint16>
{
    using   input_type = Input;
    using  output_type = cint32;
    using twiddle_type = cint16;
    using  output_data = typename fft_dit_common<Vectorization, 0, 5, input_type, output_type, twiddle_type>::output_data;

    using native_input_type = std::conditional_t<std::is_same_v<Input, cint32>, v8cint32, v8cint16>;

    struct input_data
    {
        vector<input_type, 8> d0, d1, d2, d3, d4;
        twiddle_type tw1, tw2, tw3, tw4;
    };

    class stage_iterator
    {
    public:
        using        value_type = input_data;
        using         reference = value_type;
        using iterator_category = std::input_iterator_tag;
        using   difference_type = ptrdiff_t;

        __aie_inline
        SCALAR_TYPES_CONSTEXPR stage_iterator(const input_type * __restrict ptr,
                                              const twiddle_type * __restrict ptw1,
                                              const twiddle_type * __restrict ptw2,
                                              const twiddle_type * __restrict ptw3,
                                              const twiddle_type * __restrict ptw4,
                                              unsigned r) :
            ptr_begin_((const native_input_type __aie_dm_resource_a *)(ptr)),
            ptw1_(ptw1),
            ptw2_(ptw2),
            ptw3_(ptw3),
            ptw4_(ptw4),
            r_(r),
            cnt_(0),
            cnt_tw1_(0),
            cnt_tw2_(0),
            cnt_tw3_(0),
            cnt_tw4_(0)
        {}

        __aie_inline
        stage_iterator &operator++()
        {
            ptr_begin_  = ::add_2d_ptr(ptr_begin_, 1+4*r_/8, r_ /8-1, cnt_, 1);
            ptw1_       = ::add_2d_ptr(ptw1_, 1, r_ /8-1, cnt_tw1_, 0);
            ptw2_       = ::add_2d_ptr(ptw2_, 1, r_ /8-1, cnt_tw2_, 0);
            ptw3_       = ::add_2d_ptr(ptw3_, 1, r_ /8-1, cnt_tw3_, 0);
            ptw4_       = ::add_2d_ptr(ptw4_, 1, r_ /8-1, cnt_tw4_, 0);

            return *this;
        }

        __aie_inline
        stage_iterator  operator++(int)
        {
            const stage_iterator it = *this;
            ++(*this);
            return it;
        }

        __aie_inline
        reference operator*()
        {
            return { *ptr_begin_,
                     *(ptr_begin_+ r_ / 8),
                     *(ptr_begin_+ 2 * r_ / 8),
                     *(ptr_begin_+ 3 * r_ / 8),
                     *(ptr_begin_+ 4 * r_ / 8),
                     *ptw1_, *ptw2_, *ptw3_, *ptw4_ };
        }

    private:
        const native_input_type __aie_dm_resource_a * __restrict ptr_begin_; //TODO: this DM_bankA annotation seems to be ignored
        const cint16 * __restrict ptw1_;
        const cint16 * __restrict ptw2_;
        const cint16 * __restrict ptw3_;
        const cint16 * __restrict ptw4_;
        unsigned r_;
        addr_t cnt_;
        addr_t cnt_tw1_, cnt_tw2_, cnt_tw3_, cnt_tw4_;
    };

    __aie_inline
    stage_iterator begin_stage(const input_type * __restrict data,
                               const twiddle_type * __restrict ptw1,
                               const twiddle_type * __restrict ptw2,
                               const twiddle_type * __restrict ptw3,
                               const twiddle_type * __restrict ptw4)
    {
        return stage_iterator(data, ptw1, ptw2, ptw3, ptw4, Vectorization);
    }

    __aie_inline
    output_data dit(const input_data &data, unsigned shift_tw, unsigned shift, bool inv)
    {
        return fft_dit(shift_tw, shift, inv).dit(data);
    }

    __aie_inline
    output_data dit(const input_data &data)
    {
        output_data ret;

        accum<cacc64, 8> o0, o1, o2, o3, o4;

        int cmplx_mask       = (inv_ ? OP_TERM_NEG_COMPLEX_CONJUGATE_Y : OP_TERM_NEG_COMPLEX);
        int cmplx_mask_conjy = (inv_ ? OP_TERM_NEG_COMPLEX             : OP_TERM_NEG_COMPLEX_CONJUGATE_Y);

        constexpr unsigned twiddle_elems = std::is_same_v<Input, cint32> ? 8 : 16;
        vector<cint16, twiddle_elems> w1, w2, w3, w4;

        w1.insert(0, broadcast<twiddle_type, 8>::run(data.tw1));
        w2.insert(0, broadcast<twiddle_type, 8>::run(data.tw2));
        w3.insert(0, broadcast<twiddle_type, 8>::run(data.tw3));
        w4.insert(0, broadcast<twiddle_type, 8>::run(data.tw4));

        accum<cacc64, 8> d_acc, e_acc, f_acc, g_acc;

        if constexpr (std::is_same_v<Input, cint32>) {
            d_acc = ::mul_elem_8_conf(data.d1, w1.template grow<16>(), cmplx_mask, 0);
            e_acc = ::mul_elem_8_conf(data.d2, w2.template grow<16>(), cmplx_mask, 0);
            f_acc = ::mul_elem_8_conf(data.d3, w3.template grow<16>(), cmplx_mask, 0);
            g_acc = ::mul_elem_8_conf(data.d4, w4.template grow<16>(), cmplx_mask, 0);
        }
        else {
            w1.insert(1, zeros<twiddle_type, 8>::run());
            w2.insert(1, zeros<twiddle_type, 8>::run());
            w3.insert(1, zeros<twiddle_type, 8>::run());
            w4.insert(1, zeros<twiddle_type, 8>::run());

            d_acc = ::mul_elem_8_2_conf(data.d1.template grow<16>(), w1, cmplx_mask, 0);
            e_acc = ::mul_elem_8_2_conf(data.d2.template grow<16>(), w2, cmplx_mask, 0);
            f_acc = ::mul_elem_8_2_conf(data.d3.template grow<16>(), w3, cmplx_mask, 0);
            g_acc = ::mul_elem_8_2_conf(data.d4.template grow<16>(), w4, cmplx_mask, 0);
        }

        vector<cint32, 8> d = d_acc.template to_vector<cint32>(shift_tw_);
        vector<cint32, 8> e = e_acc.template to_vector<cint32>(shift_tw_);
        vector<cint32, 8> f = f_acc.template to_vector<cint32>(shift_tw_);
        vector<cint32, 8> g = g_acc.template to_vector<cint32>(shift_tw_);

        accum<cacc64, 8> a_acc = ::lups(data.d0, shift_tw_);

        o0 = add_accum<cacc64, 8>::run(a_acc, false, d_acc);
        o0 = add_accum<cacc64, 8>::run(o0,    false, e_acc);
        o0 = add_accum<cacc64, 8>::run(o0,    false, f_acc);
        o0 = add_accum<cacc64, 8>::run(o0,    false, g_acc);

        o1 = ::msc_elem_8_conf(d, q1_.template grow<16>(), a_acc, 0, 0, cmplx_mask,       0, 0);
        o1 = ::msc_elem_8_conf(e, q2_.template grow<16>(), o1,    0, 0, cmplx_mask,       0, 0);
        o1 = ::msc_elem_8_conf(f, q2_.template grow<16>(), o1,    0, 0, cmplx_mask_conjy, 0, 0);
        o1 = ::msc_elem_8_conf(g, q1_.template grow<16>(), o1,    0, 0, cmplx_mask_conjy, 0, 0);

        o2 = ::msc_elem_8_conf(d, q2_.template grow<16>(), a_acc, 0, 0, cmplx_mask,       0, 0);
        o2 = ::msc_elem_8_conf(e, q1_.template grow<16>(), o2,    0, 0, cmplx_mask_conjy, 0, 0);
        o2 = ::msc_elem_8_conf(f, q1_.template grow<16>(), o2,    0, 0, cmplx_mask,       0, 0);
        o2 = ::msc_elem_8_conf(g, q2_.template grow<16>(), o2,    0, 0, cmplx_mask_conjy, 0, 0);

        o3 = ::msc_elem_8_conf(d, q2_.template grow<16>(), a_acc, 0, 0, cmplx_mask_conjy, 0, 0);
        o3 = ::msc_elem_8_conf(e, q1_.template grow<16>(), o3,    0, 0, cmplx_mask,       0, 0);
        o3 = ::msc_elem_8_conf(f, q1_.template grow<16>(), o3,    0, 0, cmplx_mask_conjy, 0, 0);
        o3 = ::msc_elem_8_conf(g, q2_.template grow<16>(), o3,    0, 0, cmplx_mask,       0, 0);

        o4 = ::msc_elem_8_conf(d, q1_.template grow<16>(), a_acc, 0, 0, cmplx_mask_conjy, 0, 0);
        o4 = ::msc_elem_8_conf(e, q2_.template grow<16>(), o4,    0, 0, cmplx_mask_conjy, 0, 0);
        o4 = ::msc_elem_8_conf(f, q2_.template grow<16>(), o4,    0, 0, cmplx_mask,       0, 0);
        o4 = ::msc_elem_8_conf(g, q1_.template grow<16>(), o4,    0, 0, cmplx_mask,       0, 0);

        ret[0] = o0.to_vector<output_type>(shift_);
        ret[1] = o1.to_vector<output_type>(shift_);
        ret[2] = o2.to_vector<output_type>(shift_);
        ret[3] = o3.to_vector<output_type>(shift_);
        ret[4] = o4.to_vector<output_type>(shift_);

        return ret;
    }

    __aie_inline
    fft_dit() = default;

    __aie_inline
    fft_dit(unsigned shift_tw, unsigned shift, bool inv)
        : shift_tw_(shift_tw),
          shift_(shift),
          inv_(inv)
    {
        twiddle_type k1 = as_cint16(((-10126 >> (15 - shift_tw_)) & 0xFFFF) | ((31164 >> (15 - shift_tw_)) << 16)); // -exp(-2j*pi/5)
        twiddle_type k2 = as_cint16( ( 26510 >> (15 - shift_tw_))           | ((19261 >> (15 - shift_tw_)) << 16)); // -(-exp(-2j*pi/5))^2
        q1_ = broadcast<twiddle_type, 8>::run(k1);
        q2_ = broadcast<twiddle_type, 8>::run(k2);
    }
private:
    unsigned shift_tw_, shift_;
    bool inv_;
    vector<twiddle_type, 8> q1_, q2_;
};

}

#endif
