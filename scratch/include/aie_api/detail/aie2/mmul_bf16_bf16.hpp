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

#ifndef __AIE_API_DETAIL_AIE2_MMUL_BF16_BF16__HPP__
#define __AIE_API_DETAIL_AIE2_MMUL_BF16_BF16__HPP__

#include "../broadcast.hpp"
#include "../transpose.hpp"
#include "../vector_accum_cast.hpp"

namespace aie::detail {

template <unsigned M, unsigned K, unsigned N, unsigned AccumBits>
struct mmul_bf16_bf16;

template <>
struct mmul_bf16_bf16<4, 8, 4, 32> : public C_block<bfloat16, bfloat16, 32, 16, 1>
{
    using TypeA = bfloat16;
    using TypeB = bfloat16;

    using vector_A_type = vector<TypeA, 32>;
    using vector_B_type = vector<TypeB, 32>;

    using C_block<TypeA, TypeB, 32, 16, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mac_4x8_8x4_conf(a, b, this->data, this->zero, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mul_4x8_8x4(a, b);
        this->zero = false;
    }
};

template <>
struct mmul_bf16_bf16<4, 8, 8, 32> : public C_block_interleave_cols<bfloat16, bfloat16, 32, 32, 8>
{
    using TypeA = bfloat16;
    using TypeB = bfloat16;

    using vector_A_type = vector<TypeA, 32>;
    using vector_B_type = vector<TypeB, 64>;

    using C_block_interleave_cols<TypeA, TypeB, 32, 32, 8>::C_block_interleave_cols;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        auto [b1, b2] = interleave_unzip<TypeB, 32>::run(b.template extract<32>(0),
                                                         b.template extract<32>(1), 4);

        this->data[0] = ::mac_4x8_8x4_conf(a, b1, this->data[0], this->zero, 0, 0);
        this->data[1] = ::mac_4x8_8x4_conf(a, b2, this->data[1], this->zero, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        auto [b1, b2] = interleave_unzip<TypeB, 32>::run(b.template extract<32>(0),
                                                         b.template extract<32>(1), 4);

        this->data[0] = ::mul_4x8_8x4(a, b1);
        this->data[1] = ::mul_4x8_8x4(a, b2);
        this->zero = false;
    }
};

template <>
struct mmul_bf16_bf16<4, 16, 4, 32> : public C_block<bfloat16, bfloat16, 32, 16, 1>
{
    using TypeA = bfloat16;
    using TypeB = bfloat16;

    using vector_A_type        = vector<TypeA, 64>;
    using vector_B_type = sparse_vector<TypeB, 64>;

    using C_block<TypeA, TypeB, 32, 16, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mac_4x16_16x4_conf(a, ::shuffle(b, T16_4x8), this->data, this->zero, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mul_4x16_16x4(a, ::shuffle(b, T16_4x8));
        this->zero = false;
    }
};

//TODO: Was there a reason this one doesn't use a C_block?
template <>
struct mmul_bf16_bf16<4, 16, 8, 32>
{
    using TypeA = bfloat16;
    using TypeB = bfloat16;

    using vector_A_type        = vector<TypeA, 64>;
    using vector_B_type = sparse_vector<TypeB, 128>;

    using accum_type          = accum<accfloat, 32>;
    using internal_accum_type = accum<accfloat, 16>;

    internal_accum_type data[2];
    bool       zero;

    __aie_inline
    mmul_bf16_bf16() : zero(true)
    {}

    __aie_inline
    mmul_bf16_bf16(const accum_type &acc, bool to_zero = false)
    {
        accum_type ret;
        zero = to_zero;

        const auto [tmp1, tmp2] = interleave_unzip<int32, 16>::run(accum_to_vector_cast<int32, accfloat, 16>::run(acc.template extract<16>(0)),
                                                                   accum_to_vector_cast<int32, accfloat, 16>::run(acc.template extract<16>(1)),
                                                                   4);

        data[0] = vector_to_accum_cast<accfloat, int32, 16>::run(tmp1);
        data[1] = vector_to_accum_cast<accfloat, int32, 16>::run(tmp2);
    }

    template <typename T>
    __aie_inline
    mmul_bf16_bf16(const vector<T, 32> &v, int shift = 0)
    {
        accum_type ret;

        const auto [tmp1, tmp2] = interleave_unzip<T, 16>::run(v.template extract<16>(0),
                                                               v.template extract<16>(1),
                                                               4);

        data[0].from_vector(tmp1, shift);
        data[1].from_vector(tmp2, shift);
        zero = false;
    }

    __aie_inline
    accum_type to_accum() const
    {
        accum_type ret;

        const auto [tmp1, tmp2] = interleave_zip<int32, 16>::run(accum_to_vector_cast<int32, accfloat, 16>::run(data[0]),
                                                                 accum_to_vector_cast<int32, accfloat, 16>::run(data[1]),
                                                                 4);

        ret.insert(0, vector_to_accum_cast<accfloat, int32, 16>::run(tmp1));
        ret.insert(1, vector_to_accum_cast<accfloat, int32, 16>::run(tmp2));

        return ret;
    }

    __aie_inline
    operator accum_type() const
    {
        return to_accum();
    }

    template <typename T>
    __aie_inline
    vector<T, 32> to_vector(int shift = 0) const
    {
        vector<T, 32> ret;

        const auto [tmp1, tmp2] = interleave_zip<T, 16>::run(data[0].template to_vector<T>(shift),
                                                             data[1].template to_vector<T>(shift),
                                                             4);

        ret.insert(0, tmp1);
        ret.insert(1, tmp2);

        return ret;
    }

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        const auto tmp1 = b.template extract<64>(0);
        const auto tmp2 = b.template extract<64>(1);

        this->data[0] = ::mac_4x16_16x4_conf(a, ::shuffle(tmp1, T16_4x8), this->data[0], this->zero, 0, 0);
        this->data[1] = ::mac_4x16_16x4_conf(a, ::shuffle(tmp2, T16_4x8), this->data[1], this->zero, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        const auto tmp1 = b.template extract<64>(0);
        const auto tmp2 = b.template extract<64>(1);

        this->data[0] = ::mul_4x16_16x4(a, ::shuffle(tmp1, T16_4x8));
        this->data[1] = ::mul_4x16_16x4(a, ::shuffle(tmp2, T16_4x8));
        this->zero = false;
    }
};

template <>
struct mmul_bf16_bf16<8, 8, 4, 32> : public C_block<bfloat16, bfloat16, 32, 32, 2>
{
    using TypeA = bfloat16;
    using TypeB = bfloat16;

    using vector_A_type = vector<TypeA, 64>;
    using vector_B_type = vector<TypeB, 32>;

    using C_block<TypeA, TypeB, 32, 32, 2>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mac_4x8_8x4_conf(a.template extract<32>(0), b, this->data[0], this->zero, 0, 0);
        this->data[1] = ::mac_4x8_8x4_conf(a.template extract<32>(1), b, this->data[1], this->zero, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mul_4x8_8x4(a.template extract<32>(0), b);
        this->data[1] = ::mul_4x8_8x4(a.template extract<32>(1), b);
        this->zero = false;
    }
};

template <>
struct mmul_bf16_bf16<8, 1, 8, 32> : public C_block<bfloat16, bfloat16, 32, 64, 4>
{
    using TypeA = bfloat16;
    using TypeB = bfloat16;

    using vector_A_type = vector<TypeA, 8>;
    using vector_B_type = vector<TypeB, 8>;

    using C_block<TypeA, TypeB, 32, 64, 4>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        auto zero = zeros<TypeA, 16>::run();
        auto ai = transpose<TypeA, 64>::run(a.template grow_replicate<64>(), 8, 8);
        auto bi =                           b.template grow_replicate<16>();
        //TODO: Refactor to use mul_bits<MulMacroOp::Add_Mul, 32, 16, TypeA, 16, TypeB> when zeroization is supported
        this->data[0] = ::mac_elem_16_2_conf(::concat(ai.template extract<16>(0), zero), ::concat(bi, zero), this->data[0], this->zero, 0, 0);
        this->data[1] = ::mac_elem_16_2_conf(::concat(ai.template extract<16>(1), zero), ::concat(bi, zero), this->data[1], this->zero, 0, 0);
        this->data[2] = ::mac_elem_16_2_conf(::concat(ai.template extract<16>(2), zero), ::concat(bi, zero), this->data[2], this->zero, 0, 0);
        this->data[3] = ::mac_elem_16_2_conf(::concat(ai.template extract<16>(3), zero), ::concat(bi, zero), this->data[3], this->zero, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        auto zero = zeros<TypeA, 16>::run();
        auto ai = transpose<TypeA, 64>::run(a.template grow_replicate<64>(), 8, 8);
        auto bi =                           b.template grow_replicate<16>();
        //TODO: Refactor to use mul_bits<MulMacroOp::Mul, 32, 16, TypeA, 16, TypeB> when zeroization is supported
        this->data[0] = ::mul_elem_16_2(::concat(ai.template extract<16>(0), zero), ::concat(bi, zero));
        this->data[1] = ::mul_elem_16_2(::concat(ai.template extract<16>(1), zero), ::concat(bi, zero));
        this->data[2] = ::mul_elem_16_2(::concat(ai.template extract<16>(2), zero), ::concat(bi, zero));
        this->data[3] = ::mul_elem_16_2(::concat(ai.template extract<16>(3), zero), ::concat(bi, zero));
        this->zero = false;
    }
};

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, bfloat16, bfloat16, 32> : public mmul_bf16_bf16<M, K, N, 32> { using mmul_bf16_bf16<M, K, N, 32>::mmul_bf16_bf16; };

}

#endif
