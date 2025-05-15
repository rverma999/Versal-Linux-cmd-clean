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

#ifndef __AIE_API_DETAIL_AIE1_MMUL_16_8__HPP__
#define __AIE_API_DETAIL_AIE1_MMUL_16_8__HPP__

#include "../vector.hpp"
#include "../ld_st.hpp"

namespace aie::detail {

template <unsigned M, unsigned K, unsigned N, typename TypeA, typename TypeB, unsigned AccumBits>
struct mmul_16_8;

template <typename TypeB, unsigned AccumBits>
struct mmul_16_8<4, 4, 4, int16, TypeB, AccumBits> : public C_block<int16, TypeB, AccumBits, 16, 1>
{
    using vector_A_type = vector<int16, 16>;
    using vector_B_type = vector<TypeB, 16>;

    using C_block<int16, TypeB, AccumBits, 16, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mac16(this->data,
                             a.template grow<32>(), 0, 0x02020000, 0x06060404, 2, 0x1010,
                             b.template grow<32>(), 0, 0x31203120, 0x31203120, 8, 0x3120);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mul16(a.template grow<32>(), 0, 0x02020000, 0x06060404,  2, 0x1010,
                             b.template grow<32>(), 0, 0x31203120, 0x31203120,  8, 0x3120);
    }
};

template <typename TypeB, unsigned AccumBits>
struct mmul_16_8<4, 8, 4, int16, TypeB, AccumBits> : public C_block<int16, TypeB, AccumBits, 16, 1>
{
    using vector_A_type = vector<int16, 32>;
    using vector_B_type = vector<TypeB, 32>;

    using C_block<int16, TypeB, AccumBits, 16, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mac16(this->data,
                             a, 0, 0x04040000, 0x0c0c0808, 2, 0x1010,
                             b, 0, 0x31203120, 0x31203120, 8, 0x3120);

        this->data = ::mac16(this->data,
                             a, 4, 0x04040000, 0x0c0c0808, 2, 0x1010,
                             b, 0, 0xb9a8b9a8, 0xb9a8b9a8, 8, 0x3120);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mul16(a, 0, 0x04040000, 0x0c0c0808, 2, 0x1010,
                             b, 0, 0x31203120, 0x31203120, 8, 0x3120);

        this->data = ::mac16(this->data,
                             a, 4, 0x04040000, 0x0c0c0808, 2, 0x1010,
                             b, 0, 0xb9a8b9a8, 0xb9a8b9a8, 8, 0x3120);
    }
};

template <typename TypeB, unsigned AccumBits>
struct mmul_16_8<4, 4, 8, int16, TypeB, AccumBits> : public C_block<int16, TypeB, AccumBits, 32, 2>
{
    using vector_A_type = vector<int16, 16>;
    using vector_B_type = vector<TypeB, 32>;

    using C_block<int16, TypeB, AccumBits, 32, 2>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mac16(this->data[0],
                                a.template grow<32>(), 0, 0x00000000, 0x02020202,   2, 0x1010,
                                b,                     0, 0x73625140, 0x73625140,  16, 0x3120);

        this->data[1] = ::mac16(this->data[1],
                                a.template grow<32>(), 8, 0x00000000, 0x02020202,   2, 0x1010,
                                b,                     0, 0x73625140, 0x73625140,  16, 0x3120);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mul16(a.template grow<32>(), 0, 0x00000000, 0x02020202,   2, 0x1010,
                                b,                     0, 0x73625140, 0x73625140,  16, 0x3120);

        this->data[1] = ::mul16(a.template grow<32>(), 8, 0x00000000, 0x02020202,   2, 0x1010,
                                b,                     0, 0x73625140, 0x73625140,  16, 0x3120);
    }
};

template <typename TypeB, unsigned AccumBits>
struct mmul_16_8<8, 4, 4, int16, TypeB, AccumBits> : public C_block<int16, TypeB, AccumBits, 32, 2>
{
    using vector_A_type = vector<int16, 32>;
    using vector_B_type = vector<TypeB, 16>;

    using C_block<int16, TypeB, AccumBits, 32, 2>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mac16(this->data[0],
                                a,                      0, 0x02020000, 0x06060404,  2, 0x1010,
                                b.template grow<32>(),  0, 0x31203120, 0x31203120,  8, 0x3120);

        this->data[1] = ::mac16(this->data[1],
                                a,                     16, 0x02020000, 0x06060404,  2, 0x1010,
                                b.template grow<32>(),  0, 0x31203120, 0x31203120,  8, 0x3120);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mul16(a,                      0, 0x02020000, 0x06060404,  2, 0x1010,
                                b.template grow<32>(),  0, 0x31203120, 0x31203120,  8, 0x3120);

        this->data[1] = ::mul16(a,                     16, 0x02020000, 0x06060404,  2, 0x1010,
                                b.template grow<32>(),  0, 0x31203120, 0x31203120,  8, 0x3120);
    }
};

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, int16, int8, 48> : public mmul_16_8<M, K, N, int16, int8, 48>   { using mmul_16_8<M, K, N, int16, int8, 48>::mmul_16_8; };

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, int16, uint8, 48> : public mmul_16_8<M, K, N, int16, uint8, 48> { using mmul_16_8<M, K, N, int16, uint8, 48>::mmul_16_8; };

}

#endif
