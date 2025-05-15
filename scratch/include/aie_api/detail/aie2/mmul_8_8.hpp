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

#ifndef __AIE_API_DETAIL_AIE2_MMUL_8_8__HPP__
#define __AIE_API_DETAIL_AIE2_MMUL_8_8__HPP__

#include "../accum.hpp"
#include "../vector.hpp"
#include "../../sparse_vector.hpp"
#include "../ld_st.hpp"
#include "../interleave.hpp"
#include "../broadcast.hpp"
#include "../shuffle.hpp"
#include "../utils.hpp"
#include "../vector_accum_cast.hpp"

namespace aie::detail {

template <unsigned M, unsigned K, unsigned N, typename TypeA, typename TypeB, unsigned AccumBits>
struct mmul_8_8;

template <typename TypeA, typename TypeB, unsigned AccumBits>
struct C_block_8_8_64
{
    using           accum_tag = accum_tag_t<AccumClass::Int, AccumBits>;
    using          accum_type = accum<accum_tag, 16>;
    using internal_accum_type = accum<acc64, 16>;

    internal_accum_type data;
    bool       zero;

    __aie_inline
    C_block_8_8_64() : zero(true)
    {
    }

    __aie_inline
    C_block_8_8_64(const accum_type &acc, bool to_zero = false) : zero(to_zero)
    {
        if constexpr (AccumBits > 32) {
            data = acc;
        }
        else {
            const vector<int32, 16> v_acc = (v16int32)acc;

            data = internal_accum_type(v_acc);
        }
    }

    template <typename TR>
    __aie_inline
    C_block_8_8_64(const vector<TR, 16> &v, int shift = 0) : C_block_8_8_64(accum_type(v, shift))
    {
    }

    __aie_inline
    accum_type to_accum() const
    {
        if constexpr (AccumBits > 32) {
            return data;
        }
        else {
            return (v16acc32)::shuffle((v8cint32)data.template extract<8>(0),
                                       (v8cint32)data.template extract<8>(1), DINTLV_lo_32o64);
        }
    }

    __aie_inline
    operator accum_type() const
    {
        return to_accum();
    }

    template <typename TR>
    __aie_inline
    vector<TR, 16> to_vector_sign(bool v_sign, int shift = 0) const
    {
        return to_accum().template to_vector_sign<TR>(v_sign, shift);
    }

    template <typename TR>
    __aie_inline
    vector<TR, 16> to_vector(int shift = 0) const
    {
        return to_vector_sign<TR>(is_signed_v<TR>, shift);
    }
};


template <typename TypeA, typename TypeB, unsigned AccumBits>
requires(AccumBits <= 64)
struct mmul_8_8<4, 8, 4, TypeA, TypeB, AccumBits> : public C_block_8_8_64<TypeA, TypeB, AccumBits>
{
    using vector_A_type = vector<TypeA, 32>;
    using vector_B_type = vector<TypeB, 32>;

    using big_vector_A_type = vector<utils::get_next_integer_type_t<TypeA>, 32>;

    using C_block_8_8_64<TypeA, TypeB, AccumBits>::C_block_8_8_64;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        big_vector_A_type big_vector = a.unpack_sign(a_sign);

        this->data = ::mac_4x8_8x4_conf(big_vector, a_sign, b.template grow<64>(), b_sign, this->data, this->zero, 0, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        big_vector_A_type big_vector = a.unpack_sign(a_sign);

        this->data = ::mul_4x8_8x4(big_vector, a_sign, b.template grow<64>(), b_sign);
        this->zero = false;
    }
};

template <typename TypeA, typename TypeB, unsigned AccumBits>
requires(AccumBits <= 64)
struct mmul_8_8<4, 16, 4, TypeA, TypeB, AccumBits> : public C_block_8_8_64<TypeA, TypeB, AccumBits>
{
    using vector_A_type = vector<TypeA, 64>;
    using vector_B_type = vector<TypeB, 64>;

    using big_A_type = utils::get_next_integer_type_t<TypeA>;
    using big_vector_A_type = vector<big_A_type, 32>;

    using C_block_8_8_64<TypeA, TypeB, AccumBits>::C_block_8_8_64;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        big_vector_A_type tmp[2];

        std::tie(tmp[0], tmp[1]) = interleave_unzip<big_A_type, 32>::run(a.template extract<32>(0).unpack_sign(a_sign),
                                                                         a.template extract<32>(1).unpack_sign(a_sign),
                                                                         8);

        this->data = ::mac_4x8_8x4_conf(tmp[0], a_sign, b,                                             b_sign, this->data, this->zero, 0, 0, 0);
        this->data = ::mac_4x8_8x4     (tmp[1], a_sign, b.template extract<32>(1).template grow<64>(), b_sign, this->data);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        big_vector_A_type tmp[2];

        std::tie(tmp[0], tmp[1]) = interleave_unzip<big_A_type, 32>::run(a.template extract<32>(0).unpack_sign(a_sign),
                                                                         a.template extract<32>(1).unpack_sign(a_sign),
                                                                         8);

        this->data = ::mul_4x8_8x4(tmp[0], a_sign, b,                                             b_sign);
        this->data = ::mac_4x8_8x4(tmp[1], a_sign, b.template extract<32>(1).template grow<64>(), b_sign, this->data);
        this->zero = false;
    }
};

template <typename TypeA, typename TypeB>
struct mmul_8_8<4, 8, 8, TypeA, TypeB, 32> : public C_block<TypeA, TypeB, 32, 32, 1>
{
    using vector_A_type = vector<TypeA, 32>;
    using vector_B_type = vector<TypeB, 64>;

    using C_block<TypeA, TypeB, 32, 32, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mac_4x8_8x8_conf(a.template grow<64>(), a_sign, b, b_sign, this->data, this->zero, 0, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mul_4x8_8x8(a.template grow<64>(), a_sign, b, b_sign);
        this->zero = false;
    }
};

template <typename TypeA, typename TypeB>
struct mmul_8_8<8, 8, 8, TypeA, TypeB, 32> : public C_block<TypeA, TypeB, 32, 64, 2>
{
    using vector_A_type = vector<TypeA, 64>;
    using vector_B_type = vector<TypeB, 64>;

    using C_block<TypeA, TypeB, 32, 64, 2>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mac_4x8_8x8_conf(a,                         a_sign, b, b_sign, this->data[0], this->zero, 0, 0, 0);
        this->data[1] = ::mac_4x8_8x8_conf(::shuffle(a, T256_2x2_hi), a_sign, b, b_sign, this->data[1], this->zero, 0, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mul_4x8_8x8(a,                         a_sign, b, b_sign);
        this->data[1] = ::mul_4x8_8x8(::shuffle(a, T256_2x2_hi), a_sign, b, b_sign);
        this->zero = false;
    }
};

template <typename TypeA, typename TypeB, unsigned AccumBits>
requires(AccumBits <= 64)
struct mmul_8_8<8, 8, 4, TypeA, TypeB, AccumBits>
{
    using vector_A_type = vector<TypeA, 64>;
    using vector_B_type = vector<TypeB, 32>;

    using accum_tag           = accum_tag_t<AccumClass::Int, AccumBits>;
    using accum_type          = accum<accum_tag, 32>;
    using internal_accum_type = accum<acc64, 16>;

    internal_accum_type data[2];
    bool       zero;

    __aie_inline
    mmul_8_8() : zero(true)
    {}

    __aie_inline
    mmul_8_8(const accum_type &acc, bool to_zero = false) : zero(to_zero)
    {
        if constexpr (AccumBits > 32) {
            data[0] = acc.template extract<16>(0);
            data[1] = acc.template extract<16>(1);
        }
        else {
            const vector<int32, 16> v_acc1 = (v16int32)acc.template extract<16>(0);
            const vector<int32, 16> v_acc2 = (v16int32)acc.template extract<16>(1);
            data[0] = internal_accum_type(v_acc1);
            data[1] = internal_accum_type(v_acc2);
        }
    }

    template <typename T>
    __aie_inline
    mmul_8_8(const vector<T, 32> &v, int shift = 0) : mmul_8_8(accum_type(v, shift))
    {}

    __aie_inline
    accum_type to_accum() const
    {
        if constexpr (AccumBits > 32) {
            accum_type ret;

            ret.insert(0, data[0]);
            ret.insert(1, data[1]);

            return ret;
        }
        else {
            return accum_type(::concat((v16acc32)::shuffle((v16int32)data[0].template extract<8>(0), (v16int32)data[0].template extract<8>(1), DINTLV_lo_32o64),
                                       (v16acc32)::shuffle((v16int32)data[1].template extract<8>(0), (v16int32)data[1].template extract<8>(1), DINTLV_lo_32o64)));
        }
    }

    __aie_inline
    operator accum_type() const
    {
        return to_accum();
    }

    template <typename T>
    __aie_inline
    vector<T, 32> to_vector_sign(bool v_sign, int shift = 0) const
    {
        if constexpr (type_bits_v<T> == 32) {
            vector<T, 32> v;

            if constexpr (is_signed_v<T>)
                v = ::concat(::lsrs(data[0], shift, v_sign), ::lsrs(data[1], shift, v_sign));
            else
                v = ::concat(::ulsrs(data[0], shift, v_sign), ::ulsrs(data[1], shift, v_sign));

            return v;
        }
        else {
            using type = utils::get_integer_type_t<is_signed_v<T>, 16>;
            vector<type, 32> v;

            if constexpr (is_signed_v<T>)
                v = ::concat(::ssrs(data[0], shift, v_sign), ::ssrs(data[1], shift, v_sign));
            else
                v = ::concat(::ussrs(data[0], shift, v_sign), ::ussrs(data[1], shift, v_sign));

            if constexpr (type_bits_v<T> == 8)
                return v.template pack_sign<T>(v_sign);
            else
                return v;
        }
    }

    template <typename T>
    __aie_inline
    vector<T, 32> to_vector(int shift = 0) const
    {
        return to_vector_sign<T>(is_signed_v<T>, shift);
    }

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mac_4x8_8x4_conf(a.template extract<32>(0).unpack_sign(a_sign), a_sign, b.template grow<64>(), b_sign, this->data[0], this->zero, 0, 0, 0);
        this->data[1] = ::mac_4x8_8x4_conf(a.template extract<32>(1).unpack_sign(a_sign), a_sign, b.template grow<64>(), b_sign, this->data[1], this->zero, 0, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mul_4x8_8x4(a.template extract<32>(0).unpack_sign(a_sign), a_sign, b.template grow<64>(), b_sign);
        this->data[1] = ::mul_4x8_8x4(a.template extract<32>(1).unpack_sign(a_sign), a_sign, b.template grow<64>(), b_sign);
        this->zero = false;
    }
};

template <typename TypeA, typename TypeB>
struct mmul_8_8<2, 8, 8, TypeA, TypeB, 32> : public C_block_larger_internal<TypeA, TypeB, 32, 16, 2>
{
    using vector_A_type = vector<TypeA, 16>;
    using vector_B_type = vector<TypeB, 64>;

    using C_block_larger_internal<TypeA, TypeB, 32, 16, 2>::C_block_larger_internal;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mac_4x8_8x8_conf(a.template grow<64>(), a_sign, b, b_sign, this->data, this->zero, 0, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mul_4x8_8x8(a.template grow<64>(), a_sign, b, b_sign);
        this->zero = false;
    }
};

template <typename TypeA, typename TypeB>
struct mmul_8_8<1, 16, 8, TypeA, TypeB, 32> : public C_block_larger_internal<TypeA, TypeB, 32, 8, 4>
{
    using vector_A_type = vector<TypeA, 16>;
    using vector_B_type = vector<TypeB, 128>;

    using C_block_larger_internal<TypeA, TypeB, 32, 8, 4>::C_block_larger_internal;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        mmul_8_8<2, 16, 8, TypeA, TypeB, 32> m;

        m.data = this->data;
        m.zero = this->zero;
        m.mac(a.template grow<32>(), a_sign, b, b_sign);

        this->data = m.data;
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        mmul_8_8<2, 16, 8, TypeA, TypeB, 32> m;

        m.mul(a.template grow<32>(), a_sign, b, b_sign);

        this->data = m.data;
        this->zero = false;
    }
};

template <typename TypeA, typename TypeB>
struct mmul_8_8<2, 16, 8, TypeA, TypeB, 32> : public C_block_larger_internal<TypeA, TypeB, 32, 16, 2>
{
    using vector_A_type = vector<TypeA, 32>;
    using vector_B_type = vector<TypeB, 128>;

    using C_block_larger_internal<TypeA, TypeB, 32, 16, 2>::C_block_larger_internal;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        vector<TypeA, 64> tmp[2];

        std::tie(tmp[0], tmp[1]) = interleave_unzip<TypeA, 64>::run(a.template grow<64>(),
                                                                    vector<TypeA, 64>(), 8);

        this->data = ::mac_4x8_8x8_conf(tmp[0], a_sign, b.template extract<64>(0), b_sign, this->data, this->zero, 0, 0, 0);
        this->data = ::mac_4x8_8x8     (tmp[1], a_sign, b.template extract<64>(1), b_sign, this->data);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        vector<TypeA, 64> tmp[2];

        std::tie(tmp[0], tmp[1]) = interleave_unzip<TypeA, 64>::run(a.template grow<64>(),
                                                                    vector<TypeA, 64>(), 8);

        this->data = ::mul_4x8_8x8(tmp[0], a_sign, b.template extract<64>(0), b_sign);
        this->data = ::mac_4x8_8x8(tmp[1], a_sign, b.template extract<64>(1), b_sign, this->data);
        this->zero = false;
    }
};

template <typename TypeA, typename TypeB>
struct mmul_8_8<4, 16, 8, TypeA, TypeB, 32> : public C_block<TypeA, TypeB, 32, 32, 1>
{
    using vector_A_type        = vector<TypeA, 64>;
    using vector_B_type        = vector<TypeB, 128>;
    using vector_B_sparse_type = sparse_vector<TypeB, 128>;

    using C_block<TypeA, TypeB, 32, 32, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        vector<TypeA, 64> tmp[2];

        std::tie(tmp[0], tmp[1]) = interleave_unzip<TypeA, 64>::run(a.template grow<64>(),
                                                                    vector<TypeA, 64>(), 8);

        this->data = ::mac_4x8_8x8_conf(tmp[0], a_sign, b.template extract<64>(0), b_sign, this->data, this->zero, 0, 0, 0);
        this->data = ::mac_4x8_8x8     (tmp[1], a_sign, b.template extract<64>(1), b_sign, this->data);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        vector<TypeA, 64> tmp[2];

        std::tie(tmp[0], tmp[1]) = interleave_unzip<TypeA, 64>::run(a.template grow<64>(),
                                                                    vector<TypeA, 64>(), 8);

        this->data = ::mul_4x8_8x8(tmp[0], a_sign, b.template extract<64>(0), b_sign);
        this->data = ::mac_4x8_8x8(tmp[1], a_sign, b.template extract<64>(1), b_sign, this->data);
        this->zero = false;
    }

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_sparse_type &b, bool b_sign)
    {
        this->data = ::mac_4x16_16x8_conf(a, a_sign, ::shuffle(b, T8_8x8), b_sign, this->data, this->zero, 0, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_sparse_type &b, bool b_sign)
    {
        this->data = ::mul_4x16_16x8(a, a_sign, ::shuffle(b, T8_8x8), b_sign);
        this->zero = false;
    }
};

template <typename TypeA, typename TypeB>
struct mmul_8_8<8, 16, 8, TypeA, TypeB, 32> : public C_block<TypeA, TypeB, 32, 64, 2>
{
    using vector_A_type        = vector<TypeA, 128>;
    using vector_B_type = sparse_vector<TypeB, 128>;

    using C_block<TypeA, TypeB, 32, 64, 2>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mac_4x16_16x8_conf(a.template extract<64>(0), a_sign, ::shuffle(b, T8_8x8), b_sign, this->data[0], this->zero, 0, 0, 0);
        this->data[1] = ::mac_4x16_16x8_conf(a.template extract<64>(1), a_sign, ::shuffle(b, T8_8x8), b_sign, this->data[1], this->zero, 0, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mul_4x16_16x8(a.template extract<64>(0), a_sign, ::shuffle(b, T8_8x8), b_sign);
        this->data[1] = ::mul_4x16_16x8(a.template extract<64>(1), a_sign, ::shuffle(b, T8_8x8), b_sign);
        this->zero = false;
    }
};

template <typename TypeA, typename TypeB>
struct mmul_8_8<4, 16, 16, TypeA, TypeB, 32>
{
    using vector_A_type        = vector<TypeA, 64>;
    using vector_B_type = sparse_vector<TypeB, 256>;

    using accum_type          = accum<acc32, 64>;
    using internal_accum_type = accum<acc32, 32>;

    internal_accum_type data[2];
    bool       zero;

    __aie_inline
    mmul_8_8() : zero(true)
    {}

    __aie_inline
    mmul_8_8(const accum_type &acc, bool to_zero = false)
    {
        zero = to_zero;
        accum_type ret;

        const auto [tmp1, tmp2] = interleave_unzip<int32, 32>::run(accum_to_vector_cast<int32, acc32, 32>::run(acc.template extract<32>(0)),
                                                                   accum_to_vector_cast<int32, acc32, 32>::run(acc.template extract<32>(1)),
                                                                   8);

        data[0] = vector_to_accum_cast<acc32, int32, 32>::run(tmp1);
        data[1] = vector_to_accum_cast<acc32, int32, 32>::run(tmp2);
    }

    template <typename T>
    __aie_inline
    mmul_8_8(const vector<T, 64> &v, int shift = 0)
    {
        accum_type ret;

        const auto [tmp1, tmp2] = interleave_unzip<T, 32>::run(v.template extract<32>(0),
                                                               v.template extract<32>(1),
                                                               8);

        data[0].from_vector(tmp1, shift);
        data[1].from_vector(tmp2, shift);
        zero = false;
    }

    __aie_inline
    accum_type to_accum() const
    {
        accum_type ret;

        const auto [tmp1, tmp2] = interleave_zip<int32, 16>::run(accum_to_vector_cast<int32, acc32, 16>::run(data[0].template extract<16>(0)),
                                                                 accum_to_vector_cast<int32, acc32, 16>::run(data[1].template extract<16>(0)),
                                                                 8);

        ret.insert(0, vector_to_accum_cast<acc32, int32, 16>::run(tmp1));
        ret.insert(1, vector_to_accum_cast<acc32, int32, 16>::run(tmp2));

        const auto [tmp3, tmp4] = interleave_zip<int32, 16>::run(accum_to_vector_cast<int32, acc32, 16>::run(data[0].template extract<16>(1)),
                                                                 accum_to_vector_cast<int32, acc32, 16>::run(data[1].template extract<16>(1)),
                                                                 8);

        ret.insert(2, vector_to_accum_cast<acc32, int32, 16>::run(tmp3));
        ret.insert(3, vector_to_accum_cast<acc32, int32, 16>::run(tmp4));

        return ret;
    }

    __aie_inline
    operator accum_type() const
    {
        return to_accum();
    }

    template <typename T>
    __aie_inline
    vector<T, 64> to_vector(int shift = 0) const
    {
        vector<T, 64> ret;

        const auto [tmp1, tmp2] = interleave_zip<T, 32>::run(data[0].template to_vector<T>(shift),
                                                             data[1].template to_vector<T>(shift),
                                                             8);

        ret.insert(0, tmp1);
        ret.insert(1, tmp2);

        return ret;
    }

    // Sparse variant
    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        const auto tmp1 = b.template extract<128>(0);
        const auto tmp2 = b.template extract<128>(1);

        data[0] = ::mac_4x16_16x8_conf(a, a_sign, ::shuffle(tmp1, T8_8x8), b_sign, data[0], this->zero, 0, 0, 0);
        data[1] = ::mac_4x16_16x8_conf(a, a_sign, ::shuffle(tmp2, T8_8x8), b_sign, data[1], this->zero, 0, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        const auto tmp1 = b.template extract<128>(0);
        const auto tmp2 = b.template extract<128>(1);

        data[0] = ::mul_4x16_16x8(a, a_sign, ::shuffle(tmp1, T8_8x8), b_sign);
        data[1] = ::mul_4x16_16x8(a, a_sign, ::shuffle(tmp2, T8_8x8), b_sign);
        this->zero = false;
    }
};

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, int8, int8, 32>   : public mmul_8_8<M, K, N, int8,  int8, 32>  { using mmul_8_8<M, K, N, int8,  int8, 32>::mmul_8_8; };

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, uint8, uint8, 32> : public mmul_8_8<M, K, N, uint8, uint8, 32> { using mmul_8_8<M, K, N, uint8, uint8, 32>::mmul_8_8; };

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, int8, uint8, 32>  : public mmul_8_8<M, K, N, int8,  uint8, 32> { using mmul_8_8<M, K, N, int8,  uint8, 32>::mmul_8_8; };

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, uint8, int8, 32>  : public mmul_8_8<M, K, N, uint8, int8, 32>  { using mmul_8_8<M, K, N, uint8, int8, 32>::mmul_8_8; };

}

#endif
