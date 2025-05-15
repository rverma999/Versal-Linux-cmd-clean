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

#ifndef __AIE_API_DETAIL_AIE2_MMUL_8_4__HPP__
#define __AIE_API_DETAIL_AIE2_MMUL_8_4__HPP__

#include "../accum.hpp"
#include "../vector.hpp"
#include "../ld_st.hpp"
#include "../interleave.hpp"
#include "../broadcast.hpp"
#include "../shuffle.hpp"
#include "../utils.hpp"

namespace aie::detail {

template <unsigned M, unsigned K, unsigned N, typename TypeA, typename TypeB, unsigned AccumBits>
struct mmul_8_4;

template <typename TypeA, typename TypeB>
struct mmul_8_4<4, 16, 8, TypeA, TypeB, 32> : public C_block<TypeA, TypeB, 32, 32, 1>
{
    using vector_A_type = vector<TypeA, 64>;
    using vector_B_type = vector<TypeB, 128>;

    using C_block<TypeA, TypeB, 32, 32, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mac_4x16_16x8_conf(a, a_sign, b, b_sign, this->data, this->zero, 0, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mul_4x16_16x8(a, a_sign, b, b_sign);
        this->zero = false;
    }
};

template <typename TypeA, typename TypeB>
struct mmul_8_4<8, 16, 8, TypeA, TypeB, 32> : public C_block<TypeA, TypeB, 32, 64, 2>
{
    using vector_A_type = vector<TypeA, 128>;
    using vector_B_type = vector<TypeB, 128>;

    using C_block<TypeA, TypeB, 32, 64, 2>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mac_4x16_16x8_conf(a.template extract<64>(0), a_sign, b.template grow<128>(), b_sign, this->data[0], this->zero, 0, 0, 0);
        this->data[1] = ::mac_4x16_16x8_conf(a.template extract<64>(1), a_sign, b.template grow<128>(), b_sign, this->data[1], this->zero, 0, 0, 0);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mul_4x16_16x8(a.template extract<64>(0), a_sign, b.template grow<128>(), b_sign);
        this->data[1] = ::mul_4x16_16x8(a.template extract<64>(1), a_sign, b.template grow<128>(), b_sign);
        this->zero = false;
    }
};

template <typename TypeA, typename TypeB>
struct mmul_8_4<4, 32, 8, TypeA, TypeB, 32> : public C_block<TypeA, TypeB, 32, 32, 1>
{
    using vector_A_type = vector<TypeA, 128>;
    using vector_B_type = vector<TypeB, 256>;

    using C_block<TypeA, TypeB, 32, 32, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        auto [tmp1, tmp2] = interleave_unzip<TypeA, 64>::run(a.template extract<64>(0), a.template extract<64>(1), 16);

        this->data = ::mac_4x16_16x8_conf(tmp1, a_sign, b.template extract<128>(0), b_sign, this->data, this->zero, 0, 0, 0);
        this->data = ::mac_4x16_16x8     (tmp2, a_sign, b.template extract<128>(1), b_sign, this->data);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        auto [tmp1, tmp2] = interleave_unzip<TypeA, 64>::run(a.template extract<64>(0), a.template extract<64>(1), 16);

        this->data = ::mul_4x16_16x8(tmp1, a_sign, b.template extract<128>(0), b_sign);
        this->data = ::mac_4x16_16x8(tmp2, a_sign, b.template extract<128>(1), b_sign, this->data);
        this->zero = false;
    }
};

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, int8, int4, 32>   : public mmul_8_4<M, K, N, int8,  int4, 32>  { using mmul_8_4<M, K, N, int8,  int4, 32>::mmul_8_4; };

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, uint8, uint4, 32> : public mmul_8_4<M, K, N, uint8, uint4, 32> { using mmul_8_4<M, K, N, uint8, uint4, 32>::mmul_8_4; };

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, int8, uint4, 32>  : public mmul_8_4<M, K, N, int8,  uint4, 32> { using mmul_8_4<M, K, N, int8,  uint4, 32>::mmul_8_4; };

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, uint8, int4, 32>  : public mmul_8_4<M, K, N, uint8, int4, 32>  { using mmul_8_4<M, K, N, uint8, int4, 32>::mmul_8_4; };

}


#endif
