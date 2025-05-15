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

#ifndef __AIE_API_DETAIL_AIE2_FFT_DIT_RADIX4_HPP__
#define __AIE_API_DETAIL_AIE2_FFT_DIT_RADIX4_HPP__

#include "../array_helpers.hpp"
#include "../broadcast.hpp"

namespace aie::detail {

__aie_inline
inline v16cint16 swap16(v16cint16 in) {
    return ::shuffle(in, ::undef_v16cint16(), T16_1x2_flip);
}

template<unsigned Vectorization, typename Output>
struct fft_dit<Vectorization, 0, 4, cint16, Output, cint16> : public fft_dit_common<Vectorization, 0, 4, cint16, Output, cint16>
{
    using   input_type = cint16;
    using  output_type = Output;
    using twiddle_type = cint16;
    using  output_data = typename fft_dit_common<Vectorization, 0, 4, input_type, output_type, twiddle_type>::output_data;

    struct input_data
    {
        const v8cint16* dat0;
        const v8cint16* dat1;
        unsigned off;
        twiddle_type tw1;
        twiddle_type tw2;
        twiddle_type tw3;
    };

    class stage_iterator
    {
    public:
        using        value_type = input_data;
        using         reference = value_type;
        using iterator_category = std::input_iterator_tag;
        using   difference_type = ptrdiff_t;

        __aie_inline
        SCALAR_TYPES_CONSTEXPR stage_iterator(const input_type * __restrict ptr, const twiddle_type * __restrict ptw1, const twiddle_type * __restrict ptw2, const twiddle_type * __restrict ptw3, unsigned r) :
            ptr_begin0_((const v8cint16  __aie_dm_resource_a *)(ptr)),
            ptr_begin1_((const v8cint16 __aie_dm_resource_a *)(ptr + r)),
            ptw1_((const cint16 *)ptw2),
            ptw2_((const cint16 *)ptw1),
            ptw3_((const cint16 *)ptw3),
            r_(r),
            off_(r/4),
            cnt0_(0),
            cnt1_(0),
            cnt_tw1_(0),
            cnt_tw2_(0),
            cnt_tw3_(0)
        {}

        __aie_inline
        stage_iterator &operator++()
        {
           ptr_begin0_ = ::add_2d_ptr(ptr_begin0_, 3*r_ / 8 + 1, r_ / 8 - 1, cnt0_, 1);
           ptr_begin1_ = ::add_2d_ptr(ptr_begin1_, 3*r_ / 8 + 1, r_ / 8 - 1, cnt1_, 1);

           ptw1_ = ::add_2d_ptr(ptw1_, 1, r_ / 8 - 1, cnt_tw1_, 0);
           ptw2_ = ::add_2d_ptr(ptw2_, 1, r_ / 8 - 1, cnt_tw2_, 0);
           ptw3_ = ::add_2d_ptr(ptw3_, 1, r_ / 8 - 1, cnt_tw3_, 0);
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
            return {  ptr_begin0_, ptr_begin1_, off_,
                     *ptw1_, *ptw2_, *ptw3_ };
        }

    private:
        const v8cint16 * __restrict ptr_begin0_; //TODO: this will need DM_bankA
        const v8cint16 * __restrict ptr_begin1_; //TODO: this will need DM_bankA
        const cint16 * __restrict ptw1_;
        const cint16 * __restrict ptw2_;
        const cint16 * __restrict ptw3_;
        unsigned r_;
        unsigned off_;
        addr_t cnt0_;
        addr_t cnt1_;
        addr_t cnt_tw1_;
        addr_t cnt_tw2_;
        addr_t cnt_tw3_;
    };

    __aie_inline
    stage_iterator begin_stage(const input_type * __restrict data, const twiddle_type * __restrict ptw1, const twiddle_type * __restrict ptw2, const twiddle_type * __restrict ptw3)
    {
        return stage_iterator(data, ptw1, ptw2, ptw3, Vectorization);
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

        v8cacc64 a, g, h, o0, o1, o2, o3;
        v16cint16 b, c;
        v16cint16 w1, w2, w3;

        int cmplx_mask    = (inv_ ? OP_TERM_NEG_COMPLEX_CONJUGATE_Y         : OP_TERM_NEG_COMPLEX);
        int cmplx_mask_mj = (inv_ ? OP_TERM_NEG_COMPLEX_CONJUGATE_BUTTERFLY : OP_TERM_NEG_COMPLEX_BUTTERFLY);

        a = ::lups(data.dat0[0], shift_tw_);
        b = ::insert(::set_v16cint16(0, data.dat1[0]), 1, data.dat1[data.off]);
        c = ::concat(data.dat0[data.off], c_);

        w1 = broadcast<cint16, 16>::run(data.tw1);
        w2 = broadcast<cint16, 16>::run(data.tw2);
        w3 = broadcast<cint16, 16>::run(data.tw3);

        g = ::mac_elem_8_2_conf(c, w2, a, 0, 0, cmplx_mask,    0, 0);
        h = ::msc_elem_8_2_conf(c, w2, a, 0, 0, cmplx_mask,    0, 0);

        w1 = ::shuffle(w1, w3, T256_2x2_lo);

        o0 = ::mac_elem_8_2_conf(b,        w1,  g, 0, 0, cmplx_mask,    0, 0);
        o1 = ::mac_elem_8_2_conf(b, swap16(w1), h, 0, 0, cmplx_mask_mj, 0, 0);
        o2 = ::msc_elem_8_2_conf(b,        w1,  g, 0, 0, cmplx_mask,    0, 0);
        o3 = ::msc_elem_8_2_conf(b, swap16(w1), h, 0, 0, cmplx_mask_mj, 0, 0);

        if      constexpr (std::is_same_v<Output, cint16>)
        {
            ret[0] = ::ssrs(o0, shift_);
            ret[1] = ::ssrs(o1, shift_);
            ret[2] = ::ssrs(o2, shift_);
            ret[3] = ::ssrs(o3, shift_);
        }
        else if constexpr (std::is_same_v<Output, cint32>)
        {
            ret[0] = ::lsrs(o0, shift_);
            ret[1] = ::lsrs(o1, shift_);
            ret[2] = ::lsrs(o2, shift_);
            ret[3] = ::lsrs(o3, shift_);
        }

        return ret;
    }

    __aie_inline
    fft_dit()
        : c_(zeros<cint16, 8>::run())
    {}

    __aie_inline
    fft_dit(unsigned shift_tw, unsigned shift, bool inv)
        : shift_tw_(shift_tw),
          shift_(shift),
          inv_(inv),
          c_(zeros<cint16, 8>::run())
    {}
private:
    unsigned shift_tw_, shift_;
    bool inv_;
    v8cint16 c_;
};

template<unsigned Vectorization>
struct fft_dit<Vectorization, 1, 4, cint16, cint16, cint16> : public fft_dit_common<Vectorization, 1, 4, cint16, cint16, cint16>
{
    using   input_type = cint16;
    using  output_type = cint16;
    using twiddle_type = cint16;
    using  output_data = typename fft_dit_common<Vectorization, 1, 4, input_type, output_type, twiddle_type>::output_data;

    struct input_data
    {
        const v8cint16* dat;
        const twiddle_type* tw1;
        const twiddle_type* tw2;
        const twiddle_type* tw3;
    };

    class stage_iterator
    {
    public:
        using        value_type = input_data;
        using         reference = value_type;
        using iterator_category = std::input_iterator_tag;
        using   difference_type = ptrdiff_t;

        __aie_inline
        SCALAR_TYPES_CONSTEXPR stage_iterator(const input_type * __restrict ptr, const twiddle_type * __restrict ptw1, const twiddle_type * __restrict ptw2, const twiddle_type * __restrict ptw3) :
            ptr_begin_((const v8cint16 __aie_dm_resource_a *)(ptr)),
            ptw1_((const cint16 *)ptw2),
            ptw2_((const cint16 *)ptw1),
            ptw3_((const cint16 *)ptw3)
        {}

        __aie_inline
        stage_iterator &operator++()
        {
           ptr_begin_ += 4;

           ptw1_ += 2;
           ptw2_ += 2;
           ptw3_ += 2;
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
            return { ptr_begin_, ptw1_, ptw2_, ptw3_};
        }

    private:
        const v8cint16 * __restrict ptr_begin_; //TODO: this will need DM_bankA
        const cint16 * __restrict ptw1_;
        const cint16 * __restrict ptw2_;
        const cint16 * __restrict ptw3_;
    };

    __aie_inline
    stage_iterator begin_stage(const input_type * __restrict data, const twiddle_type * __restrict ptw1, const twiddle_type * __restrict ptw2, const twiddle_type * __restrict ptw3)
    {
        return stage_iterator(data, ptw1, ptw2, ptw3);
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

        v8cacc64 g, h;
        v8cacc64 o0, o1, o2, o3;
        v16cint16 i0, i1;
        v16cint16 b, c;
        v16cint16 w1, w2, w3;

        int cmplx_mask    = (this->inv_ ? OP_TERM_NEG_COMPLEX_CONJUGATE_Y         : OP_TERM_NEG_COMPLEX);
        int cmplx_mask_mj = (this->inv_ ? OP_TERM_NEG_COMPLEX_CONJUGATE_BUTTERFLY : OP_TERM_NEG_COMPLEX_BUTTERFLY);

        i0 = ::set_v16cint16(0, data.dat[0]);
        i1 = ::set_v16cint16(0, data.dat[1]);
        i0 = ::insert(i0,    1, data.dat[2]);
        i1 = ::insert(i1,    1, data.dat[3]);

        b = ::shuffle(i1, i0, T128_4x2_hi);
        c = ::shuffle(i1, i0, T128_4x2_lo);

        w2 = broadcast_2c16_T32_4x4(data.tw2[0] , data.tw2[1]);
        w2 = ::insert(w2, 1, ::ssrs(ones_, 0));       ones_ = chess_copy(ones_);

        g = ::mul_elem_8_2_conf(c, w2, (this->inv_ ? 0xD4 : OP_TERM_NEG_COMPLEX_CONJUGATE_BUTTERFLY), 0);
        h = ::mul_elem_8_2_conf(c, w2, (this->inv_ ? 0xE7 : 0xF5), 0);

        w1 = broadcast_2c16(data.tw3[0], data.tw1[0]);
        w3 = broadcast_2c16(data.tw3[1], data.tw1[1]);

        w1 = ::shuffle(w1, w3, T32_8x4_lo);

        o0 = ::mac_elem_8_2_conf(b,        w1,  g, 0, 0, cmplx_mask,    0, 0);
        o1 = ::msc_elem_8_2_conf(b, swap16(w1), h, 0, 0, cmplx_mask_mj, 0, 0);
        o2 = ::msc_elem_8_2_conf(b,        w1,  g, 0, 0, cmplx_mask,    0, 0);
        o3 = ::mac_elem_8_2_conf(b, swap16(w1), h, 0, 0, cmplx_mask_mj, 0, 0);

        ret[0] = ::ssrs(o0, this->shift_);
        ret[1] = ::ssrs(o1, this->shift_);
        ret[2] = ::ssrs(o2, this->shift_);
        ret[3] = ::ssrs(o3, this->shift_);

        return ret;
    }

    __aie_inline fft_dit() = default;
    __aie_inline fft_dit(unsigned shift_tw, unsigned shift, bool inv) : shift_tw_(shift_tw), shift_(shift), inv_(inv)
    {
        cint16 one  = {int16_t(std::numeric_limits<int16_t>::min() >> (std::numeric_limits<int16_t>::digits - this->shift_tw_)), 0};
        ones_       = ::lups(broadcast<cint16, 8>::run(one), 0);
    }
private:
    unsigned shift_tw_, shift_;
    bool inv_;
    v8cacc64 ones_;
};

template<unsigned Vectorization>
struct fft_dit<Vectorization, 2, 4, cint16, cint16, cint16> : public fft_dit_common<Vectorization, 2, 4, cint16, cint16, cint16>
{
    using   input_type = cint16;
    using  output_type = cint16;
    using twiddle_type = cint16;
    using  output_data = typename fft_dit_common<Vectorization, 2, 4, input_type, output_type, twiddle_type>::output_data;

    struct input_data
    {
        const v8cint16* dat;
        vector<twiddle_type, 8> tw1;
        vector<twiddle_type, 8> tw2;
        vector<twiddle_type, 8> tw3;
    };

    class stage_iterator
    {
    public:
        using        value_type = input_data;
        using         reference = value_type;
        using iterator_category = std::input_iterator_tag;
        using   difference_type = ptrdiff_t;

        __aie_inline
        SCALAR_TYPES_CONSTEXPR stage_iterator(const input_type * __restrict ptr, const twiddle_type * __restrict ptw1, const twiddle_type * __restrict ptw2, const twiddle_type * __restrict ptw3) :
            ptr_begin_((const v8cint16 __aie_dm_resource_a *)(ptr)),
            ptw1_((const v8cint16 *)ptw2),
            ptw2_((const v8cint16 *)ptw1),
            ptw3_((const v8cint16 *)ptw3)
        {}

        __aie_inline
        stage_iterator &operator++()
        {
           ptr_begin_ += 4;

           ptw1_++;
           ptw2_++;
           ptw3_++;
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
            return { ptr_begin_, *ptw1_, *ptw2_, *ptw3_};
        }

    private:
        const v8cint16 * __restrict ptr_begin_; //TODO: this will need DM_bankA to avoid memory conflicts
        const v8cint16 * __restrict ptw1_;
        const v8cint16 * __restrict ptw2_;
        const v8cint16 * __restrict ptw3_;
    };

    __aie_inline
    stage_iterator begin_stage(const input_type * __restrict data, const twiddle_type * __restrict ptw1, const twiddle_type * __restrict ptw2, const twiddle_type * __restrict ptw3)
    {
        return stage_iterator(data, ptw1, ptw2, ptw3);
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

        v8cacc64 a, g, h, o0, o1, o2, o3;
        v16cint16 b, c;
        v16cint16 i0, i1;
        v16cint16 w1, w2, w3;

        int cmplx_mask    = (inv_ ? OP_TERM_NEG_COMPLEX_CONJUGATE_Y         : OP_TERM_NEG_COMPLEX);
        int cmplx_mask_mj = (inv_ ? OP_TERM_NEG_COMPLEX_CONJUGATE_BUTTERFLY : OP_TERM_NEG_COMPLEX_BUTTERFLY);

        i0 = ::set_v16cint16(0, data.dat[0]);
        i0 = ::insert(i0,    1, data.dat[1]);
        i1 = ::set_v16cint16(0, data.dat[2]);
        i1 = ::insert(i1,    1, data.dat[3]);

        a = ::lups(extract_v8cint16(::shuffle(i0, i1, T32_8x4_lo), 0), shift_tw_);
        b = ::shuffle(i0, i1, T32_8x4_lo);
        c = ::shuffle(i0, i1, T32_8x4_hi);
        b = ::shuffle(b,  c,  T256_2x2_hi);

        w1 = ::set_v16cint16(0, data.tw1);
        w2 = ::concat(data.tw2, w2_);
        w3 = ::set_v16cint16(0, data.tw3);

        g = ::mac_elem_8_2_conf(c, w2, a, 0, 0, cmplx_mask,    0, 0);
        h = ::msc_elem_8_2_conf(c, w2, a, 0, 0, cmplx_mask,    0, 0);

        w1 = ::shuffle(w1, w3, T256_2x2_lo);

        o0 = ::mac_elem_8_2_conf(b,        w1,  g, 0, 0, cmplx_mask,    0, 0);
        o1 = ::mac_elem_8_2_conf(b, swap16(w1), h, 0, 0, cmplx_mask_mj, 0, 0);
        o2 = ::msc_elem_8_2_conf(b,        w1,  g, 0, 0, cmplx_mask,    0, 0);
        o3 = ::msc_elem_8_2_conf(b, swap16(w1), h, 0, 0, cmplx_mask_mj, 0, 0);


        ret[0] = ::ssrs(o0, shift_);
        ret[1] = ::ssrs(o1, shift_);
        ret[2] = ::ssrs(o2, shift_);
        ret[3] = ::ssrs(o3, shift_);

        return ret;
    }

    __aie_inline
    fft_dit()
        : w2_(zeros<cint16, 8>::run())
    {}

    __aie_inline
    fft_dit(unsigned shift_tw, unsigned shift, bool inv)
        : shift_tw_(shift_tw),
          shift_(shift),
          inv_(inv),
          w2_(zeros<cint16, 8>::run())
    {}
private:
    unsigned shift_tw_, shift_;
    bool inv_;
    v8cint16 w2_;
};

template<unsigned Vectorization, typename Output>
struct fft_dit<Vectorization, 0, 4, cint32, Output, cint16> : public fft_dit_common<Vectorization, 0, 4, cint32, Output, cint16>
{
    using   input_type = cint32;
    using  output_type = Output;
    using twiddle_type = cint16;
    using  output_data = typename fft_dit_common<Vectorization, 0, 4, input_type, output_type, twiddle_type>::output_data;

    struct input_data
    {
        const v4cint32* dat0;
        const v4cint32* dat1;
        const int off;
        twiddle_type tw1;
        twiddle_type tw2;
        twiddle_type tw3;
    };

    class stage_iterator
    {
    public:
        using        value_type = input_data;
        using         reference = value_type;
        using iterator_category = std::input_iterator_tag;
        using   difference_type = ptrdiff_t;

        __aie_inline
        SCALAR_TYPES_CONSTEXPR stage_iterator(const input_type * ptr, const twiddle_type * ptw1, const twiddle_type * ptw2, const twiddle_type * ptw3, unsigned r) :
            ptr_begin0_((const v4cint32 __aie_dm_resource_a *)(2*r + ptr)),
            ptr_begin1_((const v4cint32 __aie_dm_resource_a *)(2*r + ptr+r)),
            ptw1_((const cint16 *)ptw2),
            ptw2_((const cint16 *)ptw1),
            ptw3_((const cint16 *)ptw3),
            r_(r),
            off_(-2*(int)r/4),
            cnt0_(0),
            cnt1_(0),
            cnt_tw1_(0),
            cnt_tw2_(0),
            cnt_tw3_(0)
        {}

        __aie_inline
        stage_iterator &operator++()
        {
           ptr_begin0_ = ::add_2d_ptr(ptr_begin0_, 6*r_/8+2, r_/8-1, cnt0_, 2);
           ptr_begin1_ = ::add_2d_ptr(ptr_begin1_, 6*r_/8+2, r_/8-1, cnt1_, 2);

           ptw1_ = ::add_2d_ptr(ptw1_, 1, r_ / 8 - 1, cnt_tw1_, 0);
           ptw2_ = ::add_2d_ptr(ptw2_, 1, r_ / 8 - 1, cnt_tw2_, 0);
           ptw3_ = ::add_2d_ptr(ptw3_, 1, r_ / 8 - 1, cnt_tw3_, 0);
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
            return {  ptr_begin0_, ptr_begin1_, off_,
                     *ptw1_, *ptw2_, *ptw3_ };
        }

    private:
        const v4cint32 * ptr_begin0_; //TODO: this will need DM_bankA to avoid memory conflicts
        const v4cint32 * ptr_begin1_; //TODO: this will need DM_bankA to avoid memory conflicts
        const cint16   * ptw1_;
        const cint16   * ptw2_;
        const cint16   * ptw3_;
        unsigned r_;
        int off_;
        addr_t cnt0_;
        addr_t cnt1_;
        addr_t cnt_tw1_;
        addr_t cnt_tw2_;
        addr_t cnt_tw3_;
    };

    __aie_inline
    stage_iterator begin_stage(const input_type * data, const twiddle_type * ptw1, const twiddle_type * ptw2, const twiddle_type * ptw3)
    {
        return stage_iterator(data, ptw1, ptw2, ptw3, Vectorization);
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

        v8cacc64 a, g, h, k, l, o0, o1, o2, o3;
        v8cint32 b, c, d;
        v16cint16 w1, w2, w3;

        int cmplx_mask    = (inv_ ? OP_TERM_NEG_COMPLEX_CONJUGATE_Y : OP_TERM_NEG_COMPLEX);
        int cmplx_mask_mj = (inv_ ? OP_TERM_NEG_COMPLEX : OP_TERM_NEG_COMPLEX_CONJUGATE_Y);

        int tmp0 = chess_copy(data.off+1);
        int tmp1 = chess_copy(data.off);

        a = ::set_v8cacc64(1, ::lups(data.dat0[tmp0], shift_tw_));
        a = ::insert( a,   0, ::lups(data.dat0[tmp1], shift_tw_));

        b = ::set_v8cint32(1, data.dat1[tmp0]);
        b = ::insert(b,    0, data.dat1[tmp1]);

        c = ::set_v8cint32(1, data.dat0[1]);
        c = ::insert(c,    0, data.dat0[0]);

        d = ::set_v8cint32(1, data.dat1[1]);
        d = ::insert(d,    0, data.dat1[0]);

        w1 = broadcast<cint16, 16>::run(data.tw1);
        w2 = broadcast<cint16, 16>::run(data.tw2);
        w3 = broadcast<cint16, 16>::run(data.tw3);

        g = ::mac_elem_8_conf(c, w2, a, 0, 0, cmplx_mask,    0, 0);
        h = ::msc_elem_8_conf(c, w2, a, 0, 0, cmplx_mask,    0, 0);
        k = ::mul_elem_8_conf(b, w1,          cmplx_mask,    0);
        l = ::mul_elem_8_conf(b, swap16(w1),  cmplx_mask_mj, 0);

        o0 = ::addmac_elem_8_conf(d,        w3,  g, k, 0, 0, cmplx_mask,    0, 0, 0);
        o1 = ::addmsc_elem_8_conf(d, swap16(w3), h, l, 0, 0, cmplx_mask_mj, 0, 0, 0);
        o2 = ::submsc_elem_8_conf(d,        w3,  g, k, 0,    cmplx_mask,    0, 0, 0);
        o3 = ::submac_elem_8_conf(d, swap16(w3), h, l, 0,    cmplx_mask_mj, 0, 0, 0);

        if      constexpr (std::is_same_v<Output, cint16>)
        {
            ret[0] = ::ssrs(o0, shift_);
            ret[1] = ::ssrs(o1, shift_);
            ret[2] = ::ssrs(o2, shift_);
            ret[3] = ::ssrs(o3, shift_);
        }
        else if constexpr (std::is_same_v<Output, cint32>)
        {
            ret[0] = ::lsrs(o0, shift_);
            ret[1] = ::lsrs(o1, shift_);
            ret[2] = ::lsrs(o2, shift_);
            ret[3] = ::lsrs(o3, shift_);
        }

        return ret;
    }

    __aie_inline fft_dit() = default;
    __aie_inline fft_dit(unsigned shift_tw, unsigned shift, bool inv) : shift_tw_(shift_tw), shift_(shift), inv_(inv)
    {}
private:
    unsigned shift_tw_, shift_;
    bool inv_;
};

template<unsigned Vectorization, typename Output>
struct fft_dit<Vectorization, 1, 4, cint32, Output, cint16> : public fft_dit_common<Vectorization, 1, 4, cint32, Output, cint16>
{
    using   input_type = cint32;
    using  output_type = Output;
    using twiddle_type = cint16;
    using  output_data = typename fft_dit_common<Vectorization, 1, 4, input_type, output_type, twiddle_type>::output_data;

    struct input_data
    {
        const v4cint32* dat;
        twiddle_type tw1_0;
        twiddle_type tw1_1;
        twiddle_type tw2_0;
        twiddle_type tw2_1;
        twiddle_type tw3_0;
        twiddle_type tw3_1;
    };

    class stage_iterator
    {
    public:
        using        value_type = input_data;
        using         reference = value_type;
        using iterator_category = std::input_iterator_tag;
        using   difference_type = ptrdiff_t;

        __aie_inline
        SCALAR_TYPES_CONSTEXPR stage_iterator(const input_type * ptr, const twiddle_type * ptw1, const twiddle_type * ptw2, const twiddle_type * ptw3) :
            ptr_begin_((const v4cint32 __aie_dm_resource_a *)(ptr)),
            ptw1_((const cint16 *)ptw2),
            ptw2_((const cint16 *)ptw1),
            ptw3_((const cint16 *)ptw3)
        {}

        __aie_inline
        stage_iterator &operator++()
        {
           ptr_begin_ += 8;
           ptw1_ += 2;
           ptw2_ += 2;
           ptw3_ += 2;
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
            return {  ptr_begin_,
                     *ptw1_, *(ptw1_ + 1), *ptw2_, *(ptw2_ + 1), *ptw3_, *(ptw3_ + 1)};
        }

    private:
        const v4cint32 * ptr_begin_; //TODO: this will need DM_bankA to avoid memory conflicts
        const cint16 *  ptw1_;
        const cint16 *  ptw2_;
        const cint16 *  ptw3_;
    };

    __aie_inline
    stage_iterator begin_stage(const input_type * data, const twiddle_type * ptw1, const twiddle_type * ptw2, const twiddle_type * ptw3)
    {
        return stage_iterator(data, ptw1, ptw2, ptw3);
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

        v8cacc64 a, g, h, k, l;
        v8cacc64 o0, o1, o2, o3;
        v8cint32 b, c, d;
        v16cint16 w1, w2, w3;

        int cmplx_mask    = (inv_ ? OP_TERM_NEG_COMPLEX_CONJUGATE_Y : OP_TERM_NEG_COMPLEX);
        int cmplx_mask_mj = (inv_ ? OP_TERM_NEG_COMPLEX : OP_TERM_NEG_COMPLEX_CONJUGATE_Y);

        a = ::set_v8cacc64(0, ::lups(data.dat[0], shift_tw_));
        a = ::insert( a,   1, ::lups(data.dat[4], shift_tw_));

        c = ::set_v8cint32(0, data.dat[2]);
        c = ::insert(c,    1, data.dat[6]);

        b = ::set_v8cint32(0, data.dat[1]);
        b = ::insert(b,    1, data.dat[5]);

        d = ::set_v8cint32(0, data.dat[3]);
        d = ::insert(d,    1, data.dat[7]);

        w1 = broadcast_2c16_T32_4x4(data.tw1_0, data.tw1_1);
        w2 = broadcast_2c16_T32_4x4(data.tw2_0, data.tw2_1);
        w3 = broadcast_2c16_T32_4x4(data.tw3_0, data.tw3_1);

        g = ::mac_elem_8_conf(c, w2, a, 0, 0, cmplx_mask,    0, 0);
        h = ::msc_elem_8_conf(c, w2, a, 0, 0, cmplx_mask,    0, 0);
        k = ::mul_elem_8_conf(b, w1,          cmplx_mask,    0);
        l = ::mul_elem_8_conf(b, swap16(w1),  cmplx_mask_mj, 0);

        o0 = ::addmac_elem_8_conf(d,        w3,  g, k, 0, 0, cmplx_mask,    0, 0, 0);
        o1 = ::addmsc_elem_8_conf(d, swap16(w3), h, l, 0, 0, cmplx_mask_mj, 0, 0, 0);
        o2 = ::submsc_elem_8_conf(d,        w3,  g, k, 0,    cmplx_mask,    0, 0, 0);
        o3 = ::submac_elem_8_conf(d, swap16(w3), h, l, 0,    cmplx_mask_mj, 0, 0, 0);

        if      constexpr (std::is_same_v<Output, cint16>)
        {
            ret[0] = ::ssrs(o0, shift_);
            ret[1] = ::ssrs(o1, shift_);
            ret[2] = ::ssrs(o2, shift_);
            ret[3] = ::ssrs(o3, shift_);
        }
        else if constexpr (std::is_same_v<Output, cint32>)
        {
            ret[0] = ::lsrs(o0, shift_);
            ret[1] = ::lsrs(o1, shift_);
            ret[2] = ::lsrs(o2, shift_);
            ret[3] = ::lsrs(o3, shift_);
        }

        return ret;
    }

    __aie_inline fft_dit() = default;
    __aie_inline fft_dit(unsigned shift_tw, unsigned shift, bool inv) : shift_tw_(shift_tw), shift_(shift), inv_(inv)
    {}
private:
    unsigned shift_tw_, shift_;
    bool inv_;
};

template<unsigned Vectorization, typename Output>
struct fft_dit<Vectorization, 2, 4, cint32, Output, cint16> : public fft_dit_common<Vectorization, 2, 4, cint32, Output, cint16>
{
    using   input_type = cint32;
    using  output_type = Output;
    using twiddle_type = cint16;
    using  output_data = typename fft_dit_common<Vectorization, 2, 4, input_type, output_type, twiddle_type>::output_data;

    struct input_data
    {
        const v4cint32* dat;
        vector<twiddle_type, 8> tw1;
        vector<twiddle_type, 8> tw2;
        vector<twiddle_type, 8> tw3;
    };

    class stage_iterator
    {
    public:
        using        value_type = input_data;
        using         reference = value_type;
        using iterator_category = std::input_iterator_tag;
        using   difference_type = ptrdiff_t;

        __aie_inline
        SCALAR_TYPES_CONSTEXPR stage_iterator(const input_type * ptr, const twiddle_type * ptw1, const twiddle_type * ptw2, const twiddle_type * ptw3) :
            ptr_begin_((const v4cint32 *)(ptr)),
            ptw1_((const v8cint16 *)ptw2),
            ptw2_((const v8cint16 *)ptw1),
            ptw3_((const v8cint16 *)ptw3)
        {}

        __aie_inline
        stage_iterator &operator++()
        {
           ptr_begin_ += 8;
           ptw1_++;
           ptw2_++;
           ptw3_++;
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
            return { ptr_begin_,
                     *ptw1_, *ptw2_, *ptw3_ };
        }

    private:
        const v4cint32 * ptr_begin_; //TODO: this will need DM_bankA to avoid memory conflicts
        const v8cint16 * ptw1_;
        const v8cint16 * ptw2_;
        const v8cint16 * ptw3_;
    };

    __aie_inline
    stage_iterator begin_stage(const input_type * data, const twiddle_type * ptw1, const twiddle_type * ptw2, const twiddle_type * ptw3)
    {
        return stage_iterator(data, ptw1, ptw2, ptw3);
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

        v8cacc64 a, g, h, k, l, o0, o1, o2, o3;
        v8cint32 b, c, d;
        v8cint32 i0, i1, i2, i3;
        v8cint32 s0, s1, s2, s3;
        v16cint16 w1, w2, w3;

        int cmplx_mask    = (inv_ ? OP_TERM_NEG_COMPLEX_CONJUGATE_Y : OP_TERM_NEG_COMPLEX);
        int cmplx_mask_mj = (inv_ ? OP_TERM_NEG_COMPLEX : OP_TERM_NEG_COMPLEX_CONJUGATE_Y);

        i0 = ::set_v8cint32(0, data.dat[0]);
        i0 = ::insert(i0,   1, data.dat[1]);
        i1 = ::set_v8cint32(0, data.dat[2]);
        i1 = ::insert(i1,   1, data.dat[3]);
        i2 = ::set_v8cint32(0, data.dat[4]);
        i2 = ::insert(i2,   1, data.dat[5]);
        i3 = ::set_v8cint32(0, data.dat[6]);
        i3 = ::insert(i3,   1, data.dat[7]);

        s0 = ::shuffle(i0, i1, T64_8x2_lo);
        s1 = ::shuffle(i0, i1, T64_8x2_hi);
        s2 = ::shuffle(i2, i3, T64_8x2_lo);
        s3 = ::shuffle(i2, i3, T64_8x2_hi);

        a = ::lups(::shuffle(s0, s2, T64_8x2_lo), shift_tw_);
        b = ::shuffle(s1, s3, T64_8x2_lo);
        c = ::shuffle(s0, s2, T64_8x2_hi);
        d = ::shuffle(s1, s3, T64_8x2_hi);

        w1 = ::set_v16cint16(0, data.tw1);
        w2 = ::set_v16cint16(0, data.tw2);
        w3 = ::set_v16cint16(0, data.tw3);

        g = ::mac_elem_8_conf(c, w2, a, 0, 0, cmplx_mask,    0, 0);
        h = ::msc_elem_8_conf(c, w2, a, 0, 0, cmplx_mask,    0, 0);
        k = ::mul_elem_8_conf(b, w1,          cmplx_mask,    0);
        l = ::mul_elem_8_conf(b, swap16(w1),  cmplx_mask_mj, 0);

        o0 = ::addmac_elem_8_conf(d,        w3,  g, k, 0, 0, cmplx_mask,    0, 0, 0);
        o1 = ::addmsc_elem_8_conf(d, swap16(w3), h, l, 0, 0, cmplx_mask_mj, 0, 0, 0);
        // addmac-like instructions reuse their first input accumulator as the output register and therefore overwrite its
        // contents with the result of the operation. To allow these instructions to be pipelined, the first input
        // accumulators need to be duplicated. As the compiler does not do this optimally, we use add_conf with zeroization
        // to manually force the duplication of g and h below
        o2 = ::submsc_elem_8_conf(d,        w3,  ::add_conf(::undef_v8cacc64(), g, 1, 0, 0, 0), k, 0, cmplx_mask,    0, 0, 0);
        o3 = ::submac_elem_8_conf(d, swap16(w3), ::add_conf(::undef_v8cacc64(), h, 1, 0, 0, 0), l, 0, cmplx_mask_mj, 0, 0, 0);

        if      constexpr (std::is_same_v<Output, cint16>)
        {
            ret[0] = ::ssrs(o0, shift_);
            ret[1] = ::ssrs(o1, shift_);
            ret[2] = ::ssrs(o2, shift_);
            ret[3] = ::ssrs(o3, shift_);
        }
        else if constexpr (std::is_same_v<Output, cint32>)
        {
            ret[0] = ::lsrs(o0, shift_);
            ret[1] = ::lsrs(o1, shift_);
            ret[2] = ::lsrs(o2, shift_);
            ret[3] = ::lsrs(o3, shift_);
        }

        return ret;
    }

    __aie_inline fft_dit() = default;
    __aie_inline fft_dit(unsigned shift_tw, unsigned shift, bool inv) : shift_tw_(shift_tw), shift_(shift), inv_(inv)
    {}
private:
    unsigned shift_tw_, shift_;
    bool inv_;
};

}

#endif
