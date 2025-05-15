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

#ifndef __AIE_API_DETAIL_AIE1_MMUL_16_64__HPP__
#define __AIE_API_DETAIL_AIE1_MMUL_16_64__HPP__

#include "../vector.hpp"
#include "../ld_st.hpp"
#include "../mul.hpp"

namespace aie::detail {

template <unsigned AccumBits, bool IsAcc>
static constexpr auto get_mmul_16_64_op()
{
    if constexpr (IsAcc) {
        if constexpr (AccumBits <= 48) return [](auto ... params) { return ::mac4(params...);  };
        else                           return [](auto ... params) { return ::lmac4(params...); };
    }
    else {
        if constexpr (AccumBits <= 48) return [](auto ... params) { return ::mul4(params...);  };
        else                           return [](auto ... params) { return ::lmul4(params...); };
    }
}

template <unsigned M, unsigned K, unsigned N, typename T1, typename T2, unsigned AccumBits>
struct mmul_16_64;

template <unsigned AccumBits>
struct mmul_16_64<2, 4, 2, int16, cint32, AccumBits> : public C_block<int16, cint32, AccumBits, 4, 1>
{
    using vector_A_type = vector<int16, 8>;
    using vector_B_type = vector<cint32, 8>;

    using C_block<int16, cint32, AccumBits, 4, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        constexpr auto mac_op = get_mmul_16_64_op<AccumBits, true>();

        this->data = mac_op(this->data,
                            a.template grow<32>(),    0, 0x4400, 1,
                            b.template extract<4>(0), 0, 0x1010, 2);

        this->data = mac_op(this->data,
                            a.template grow<32>(),    2, 0x4400, 1,
                            b.template extract<4>(1), 0, 0x1010, 2);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        constexpr auto mul_op = get_mmul_16_64_op<AccumBits, false>();
        constexpr auto mac_op = get_mmul_16_64_op<AccumBits, true>();

        this->data = mul_op(a.template grow<32>(),    0, 0x4400, 1,
                            b.template extract<4>(0), 0, 0x1010, 2);

        this->data = mac_op(this->data,
                            a.template grow<32>(),    2, 0x4400, 1,
                            b.template extract<4>(1), 0, 0x1010, 2);
    }
};

template <unsigned AccumBits>
struct mmul_16_64<2, 8, 2, int16, cint32, AccumBits> : public C_block<int16, cint32, AccumBits, 4, 1>
{
    using vector_A_type = vector<int16,  16>;
    using vector_B_type = vector<cint32, 16>;

    using C_block<int16, cint32, AccumBits, 4, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        constexpr auto mac_op = get_mmul_16_64_op<AccumBits, true>();

        this->data = mac_op(this->data,
                            a.template grow<32>(),    0, 0x8800, 1,
                            b.template extract<4>(0), 0, 0x1010, 2);

        this->data = mac_op(this->data,
                            a.template grow<32>(),    2, 0x8800, 1,
                            b.template extract<4>(1), 0, 0x1010, 2);

        this->data = mac_op(this->data,
                            a.template grow<32>(),    4, 0x8800, 1,
                            b.template extract<4>(2), 0, 0x1010, 2);

        this->data = mac_op(this->data,
                            a.template grow<32>(),    6, 0x8800, 1,
                            b.template extract<4>(3), 0, 0x1010, 2);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        constexpr auto mul_op = get_mmul_16_64_op<AccumBits, false>();
        constexpr auto mac_op = get_mmul_16_64_op<AccumBits, true>();

        this->data = mul_op(a.template grow<32>(),    0, 0x8800, 1,
                            b.template extract<4>(0), 0, 0x1010, 2);

        this->data = mac_op(this->data,
                            a.template grow<32>(),    2, 0x8800, 1,
                            b.template extract<4>(1), 0, 0x1010, 2);

        this->data = mac_op(this->data,
                            a.template grow<32>(),    4, 0x8800, 1,
                            b.template extract<4>(2), 0, 0x1010, 2);

        this->data = mac_op(this->data,
                            a.template grow<32>(),    6, 0x8800, 1,
                            b.template extract<4>(3), 0, 0x1010, 2);
    }
};


template <unsigned AccumBits>
struct mmul_16_64<4, 4, 2, int16, cint32, AccumBits> : public C_block<int16, cint32, AccumBits, 8, 2>
{
    using vector_A_type = vector<int16,  16>;
    using vector_B_type = vector<cint32, 8>;

    using C_block<int16, cint32, AccumBits, 8, 2>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        constexpr auto mac_op = get_mmul_16_64_op<AccumBits, true>();

        this->data[0] = mac_op(this->data[0],
                               a.template grow<32>(),     0, 0x4400, 1,
                               b.template extract<4>(0),  0, 0x1010, 2);
        this->data[0] = mac_op(this->data[0],
                               a.template grow<32>(),     2, 0x4400, 1,
                               b.template extract<4>(1),  0, 0x1010, 2);

        this->data[1] = mac_op(this->data[1],
                               a.template grow<32>(),     8, 0x4400, 1,
                               b.template extract<4>(0),  0, 0x1010, 2);
        this->data[1] = mac_op(this->data[1],
                               a.template grow<32>(),    10, 0x4400, 1,
                               b.template extract<4>(1),  0, 0x1010, 2);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        constexpr auto mul_op = get_mmul_16_64_op<AccumBits, false>();
        constexpr auto mac_op = get_mmul_16_64_op<AccumBits, true>();

        this->data[0] = mul_op(a.template grow<32>(),     0, 0x4400, 1,
                               b.template extract<4>(0),  0, 0x1010, 2);
        this->data[0] = mac_op(this->data[0],
                               a.template grow<32>(),     2, 0x4400, 1,
                               b.template extract<4>(1),  0, 0x1010, 2);

        this->data[1] = mul_op(a.template grow<32>(),     8, 0x4400, 1,
                               b.template extract<4>(0),  0, 0x1010, 2);
        this->data[1] = mac_op(this->data[1],
                               a.template grow<32>(),    10, 0x4400, 1,
                               b.template extract<4>(1),  0, 0x1010, 2);
    }
};

template <unsigned AccumBits>
struct mmul_16_64<2, 4, 4, int16, cint32, AccumBits> : public C_block<int16, cint32, AccumBits, 8, 2>
{
    using vector_A_type = vector<int16,  8>;
    using vector_B_type = vector<cint32, 16>;

    using C_block<int16, cint32, AccumBits, 8, 2>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        constexpr auto mac_op = get_mmul_16_64_op<AccumBits, true>();

        this->data[0] = mac_op(this->data[0],
                               b.template extract<8>(0), 0, 0x3210, 4,
                               a.template grow<16>(),    0, 0x0000, 1);
        this->data[0] = mac_op(this->data[0],
                               b.template extract<8>(1), 0, 0x3210, 4,
                               a.template grow<16>(),    2, 0x0000, 1);

        this->data[1] = mac_op(this->data[1],
                               b.template extract<8>(0), 0, 0x3210, 4,
                               a.template grow<16>(),    4, 0x0000, 1);
        this->data[1] = mac_op(this->data[1],
                               b.template extract<8>(1), 0, 0x3210, 4,
                               a.template grow<16>(),    6, 0x0000, 1);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        constexpr auto mul_op = get_mmul_16_64_op<AccumBits, false>();
        constexpr auto mac_op = get_mmul_16_64_op<AccumBits, true>();

        this->data[0] = mul_op(b.template extract<8>(0), 0, 0x3210, 4,
                               a.template grow<16>(),    0, 0x0000, 1);
        this->data[0] = mac_op(this->data[0],
                               b.template extract<8>(1), 0, 0x3210, 4,
                               a.template grow<16>(),    2, 0x0000, 1);

        this->data[1] = mul_op(b.template extract<8>(0), 0, 0x3210, 4,
                               a.template grow<16>(),    4, 0x0000, 1);
        this->data[1] = mac_op(this->data[1],
                               b.template extract<8>(1), 0, 0x3210, 4,
                               a.template grow<16>(),    6, 0x0000, 1);
    }
};

template <unsigned AccumBits>
struct mmul_16_64<4, 4, 1, int16, cint32, AccumBits> : public C_block<int16, cint32, AccumBits, 4, 1>
{
    using vector_A_type = vector<int16,  16>;
    using vector_B_type = vector<cint32, 4>;

    using C_block<int16, cint32, AccumBits, 4, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        constexpr auto mac_op = get_mmul_16_64_op<AccumBits, true>();

        this->data = mac_op(this->data,
                            a.template grow<32>(), 0, 0xc840, 1,
                            b,                     0, 0x0000, 1);

        this->data = mac_op(this->data,
                            a.template grow<32>(), 2, 0xc840, 1,
                            b,                     2, 0x0000, 1);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        constexpr auto mul_op = get_mmul_16_64_op<AccumBits, false>();
        constexpr auto mac_op = get_mmul_16_64_op<AccumBits, true>();

        this->data = mul_op(a.template grow<32>(), 0, 0xc840, 1,
                            b,                     0, 0x0000, 1);

        this->data = mac_op(this->data,
                            a.template grow<32>(), 2, 0xc840, 1,
                            b,                     2, 0x0000, 1);
    }
};

template <unsigned M, unsigned K, unsigned N, unsigned AccumBits>
struct mmul<M, K, N, int16, cint32, AccumBits> : public mmul_16_64<M, K, N, int16, cint32, AccumBits> { using mmul_16_64<M, K, N, int16, cint32, AccumBits>::mmul_16_64; };

}

#endif
