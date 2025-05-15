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

#ifndef __AIE_API_DETAIL_AIE2_MMUL_16_8__HPP__
#define __AIE_API_DETAIL_AIE2_MMUL_16_8__HPP__

#include "../accum.hpp"
#include "../vector.hpp"
#include "../ld_st.hpp"
#include "../interleave.hpp"
#include "../broadcast.hpp"
#include "../shuffle.hpp"
#include "../utils.hpp"

namespace aie::detail {

template <unsigned M, unsigned K, unsigned N, typename TypeA, typename TypeB, unsigned AccumBits>
struct mmul_16_8;

template <typename TypeA, typename TypeB>
struct mmul_16_8<4, 8, 4, TypeA, TypeB, 32> : public C_block<TypeA, TypeB, 64, 16, 1>
{
    using vector_A_type = vector<TypeA, 32>;
    using vector_B_type = vector<TypeB, 32>;

    using C_block<TypeA, TypeB, 64, 16, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mac_4x8_8x4_conf(a, a_sign, b.template grow<64>(), b_sign, this->data, this->zero, 0, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mul_4x8_8x4(a, a_sign, b.template grow<64>(), b_sign);
        this->zero = false;
    }
};

template <typename TypeA, typename TypeB>
struct mmul_16_8<4, 4, 8, TypeA, TypeB, 32> : public C_block<TypeA, TypeB, 32, 32, 1>
{
    using vector_A_type = vector<TypeA, 16>;
    using vector_B_type = vector<TypeB, 32>;

    using C_block<TypeA, TypeB, 32, 32, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mac_4x4_4x8_conf(a.template grow<32>(), a_sign, b.template grow<64>(), b_sign, this->data, this->zero, 0, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mul_4x4_4x8(a.template grow<32>(), a_sign, b.template grow<64>(), b_sign);
        this->zero = false;
    }
};

template <typename TypeA, typename TypeB>
struct mmul_16_8<8, 4, 4, TypeA, TypeB, 32>
{
    using vector_A_type = vector<TypeA, 32>;
    using vector_B_type = vector<TypeB, 16>;

    using accum_type = accum<acc32, 32>;

    accum_type data;
    bool       zero;

    mmul_16_8() : zero(true)
    {}

    mmul_16_8(const accum_type &acc, bool to_zero = false)
    {
        zero = to_zero;
        data.insert<16>(0, (v16acc32) ::shuffle((v16int32) acc.template extract<16>(0), (v16int32) acc.template extract<16>(1), INTLV_lo_32o64));
        data.insert<16>(1, (v16acc32) ::shuffle((v16int32) acc.template extract<16>(0), (v16int32) acc.template extract<16>(1), INTLV_hi_32o64));
    }

    template <typename T>
    mmul_16_8(const vector<T, 32> &v, int shift = 0) : mmul_16_8(accum_type(v, shift))
    {}

    accum_type to_accum() const
    {
        const v16acc32 acc0 = (v16acc32) ::shuffle((v16int32) data.template extract<16>(0),
                                                   (v16int32) data.template extract<16>(1), DINTLV_lo_32o64);
        const v16acc32 acc1 = (v16acc32) ::shuffle((v16int32) data.template extract<16>(0),
                                                   (v16int32) data.template extract<16>(1), DINTLV_hi_32o64);

        accum<acc32, 32> full_acc;

        full_acc.insert<16>(0, acc0);
        full_acc.insert<16>(1, acc1);

        return full_acc;
    }

    operator accum_type () const
    {
        return to_accum();
    }

    template <typename T>
    vector<T, 32> to_vector(int shift = 0) const
    {
        return to_accum().template to_vector<T>(shift);
    }

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        vector<TypeA, 32> tmpA = ::shuffle(a,                     a.template extract<16>(1).template grow<32>(), INTLV_lo_16o32);
        vector<TypeB, 64> tmpB = ::shuffle(b.template grow<64>(), b.template grow<64>(),                         INTLV_lo_8o16);

        this->data = ::mac_4x4_4x4_2ch_conf(tmpA, a_sign, tmpB, b_sign, this->data, this->zero, 0, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        vector<TypeA, 32> tmpA = ::shuffle(a,                     a.template extract<16>(1).template grow<32>(), INTLV_lo_16o32);
        vector<TypeB, 64> tmpB = ::shuffle(b.template grow<64>(), b.template grow<64>(),                         INTLV_lo_8o16);

        this->data = ::mul_4x4_4x4_2ch(tmpA, a_sign, tmpB, b_sign);
        this->zero = false;
    }

};

template <typename TypeA, typename TypeB>
struct mmul_16_8<8, 4, 8, TypeA, TypeB, 32> : public C_block<TypeA, TypeB, 32, 64, 2>
{
    using vector_A_type = vector<TypeA, 32>;
    using vector_B_type = vector<TypeB, 32>;

    using C_block<TypeA, TypeB, 32, 64, 2>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mac_4x4_4x8_conf(a,                                   a_sign, b.template grow<64>(), b_sign, this->data[0], this->zero, 0, 0, 0);
        this->data[1] = ::mac_4x4_4x8_conf(shuffle_down<TypeA, 32>::run(a, 16), a_sign, b.template grow<64>(), b_sign, this->data[1], this->zero, 0, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mul_4x4_4x8(a,                                   a_sign, b.template grow<64>(), b_sign);
        this->data[1] = ::mul_4x4_4x8(shuffle_down<TypeA, 32>::run(a, 16), a_sign, b.template grow<64>(), b_sign);
        this->zero = false;
    }
};

template <typename TypeA, typename TypeB>
struct mmul_16_8<4, 4, 4, TypeA, TypeB, 32>
{
    using vector_A_type = vector<TypeA, 16>;
    using vector_B_type = vector<TypeB, 16>;

    using accum_type          = accum<acc32, 16>;
    using internal_accum_type = accum<acc32, 32>;

    internal_accum_type data;
    bool       zero;

    mmul_16_8() : zero(true)
    {}

    mmul_16_8(const accum_type &acc, bool to_zero = false)
    {
        zero = to_zero;
        data.insert<16>(0, (v16acc32) ::shuffle((v16int32) acc, (v16int32) acc, INTLV_lo_32o64));
        data.insert<16>(1, (v16acc32) ::shuffle((v16int32) acc, (v16int32) acc, INTLV_hi_32o64));
    }

    template <typename T>
    mmul_16_8(const vector<T, 16> &v, int shift = 0) : mmul_16_8(accum_type(v, shift))
    {}

    accum_type to_accum() const
    {
        return (v16acc32) ::shuffle((v16int32) data.template extract<16>(0),
                                    (v16int32) data.template extract<16>(1), DINTLV_lo_32o64);
    }

    operator accum_type () const
    {
        return to_accum();
    }

    template <typename T>
    vector<T, 16> to_vector(int shift = 0) const
    {
        return to_accum().template to_vector<T>(shift);
    }

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        vector<TypeA, 32> tmpA = ::shuffle(a.template grow<32>(), a.template grow<32>(), INTLV_lo_16o32);
        vector<TypeB, 64> tmpB = ::shuffle(b.template grow<64>(), b.template grow<64>(), INTLV_lo_8o16);

        this->data = mac_4x4_4x4_2ch_conf(tmpA, a_sign, tmpB, b_sign, this->data, this->zero, 0, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        vector<TypeA, 32> tmpA = ::shuffle(a.template grow<32>(), a.template grow<32>(), INTLV_lo_16o32);
        vector<TypeB, 64> tmpB = ::shuffle(b.template grow<64>(), b.template grow<64>(), INTLV_lo_8o16);

        this->data = ::mul_4x4_4x4_2ch(tmpA, a_sign, tmpB, b_sign);
        this->zero = false;
    }
};

template <typename TypeA, typename TypeB>
struct mmul_16_8<2, 8, 8, TypeA, TypeB, 32> : public C_block<TypeA, TypeB, 64, 16, 1>
{
    using vector_A_type = vector<TypeA, 16>;
    using vector_B_type = vector<TypeB, 64>;

    using C_block<TypeA, TypeB, 64, 16, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mac_2x8_8x8_conf(a.template grow<32>(), a_sign, b, b_sign, this->data, this->zero, 0, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mul_2x8_8x8(a.template grow<32>(), a_sign, b, b_sign);
        this->zero = false;
    }
};

template <typename TypeA, typename TypeB>
struct mmul_16_8<2, 16, 8, TypeA, TypeB, 32> : public C_block<TypeA, TypeB, 64, 16, 1>
{
    using vector_A_type        = vector<TypeA, 32>;
    using vector_B_sparse_type = sparse_vector<TypeB, 128>;

    using C_block<TypeA, TypeB, 64, 16, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_sparse_type &b, bool b_sign)
    {
        this->data = ::mac_2x16_16x8_conf(a, a_sign, ::shuffle(b, T8_8x8), b_sign, this->data, this->zero, 0, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_sparse_type &b, bool b_sign)
    {
        this->data = ::mul_2x16_16x8(a, a_sign, ::shuffle(b, T8_8x8), b_sign);
        this->zero = false;
    }
};

template <typename TypeA, typename TypeB>
struct mmul_16_8<4, 16, 8, TypeA, TypeB, 32> : public C_block<TypeA, TypeB, 64, 32, 2>
{
    using vector_A_type        = vector<TypeA, 64>;
    using vector_B_sparse_type = sparse_vector<TypeB, 128>;

    using C_block<TypeA, TypeB, 64, 32, 2>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_sparse_type &b, bool b_sign)
    {
        this->data[0] = ::mac_2x16_16x8_conf(a.template extract<32>(0), a_sign, ::shuffle(b, T8_8x8), b_sign, this->data[0], this->zero, 0, 0, 0);
        this->data[1] = ::mac_2x16_16x8_conf(a.template extract<32>(1), a_sign, ::shuffle(b, T8_8x8), b_sign, this->data[1], this->zero, 0, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_sparse_type &b, bool b_sign)
    {
        this->data[0] = ::mul_2x16_16x8(a.template extract<32>(0), a_sign, ::shuffle(b, T8_8x8), b_sign);
        this->data[1] = ::mul_2x16_16x8(a.template extract<32>(1), a_sign, ::shuffle(b, T8_8x8), b_sign);
        this->zero = false;
    }
};


template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, int16, int8, 32>   : public mmul_16_8<M, K, N, int16,  int8, 32>  { using mmul_16_8<M, K, N, int16,  int8, 32>::mmul_16_8; };

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, uint16, uint8, 32> : public mmul_16_8<M, K, N, uint16, uint8, 32> { using mmul_16_8<M, K, N, uint16, uint8, 32>::mmul_16_8; };

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, int16, uint8, 32>  : public mmul_16_8<M, K, N, int16,  uint8, 32> { using mmul_16_8<M, K, N, int16,  uint8, 32>::mmul_16_8; };

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, uint16, int8, 32>  : public mmul_16_8<M, K, N, uint16, int8, 32>  { using mmul_16_8<M, K, N, uint16, int8, 32>::mmul_16_8; };

}

#endif
