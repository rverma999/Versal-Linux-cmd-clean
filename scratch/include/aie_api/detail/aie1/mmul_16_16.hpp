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

#ifndef __AIE_API_DETAIL_AIE1_MMUL_16_16__HPP__
#define __AIE_API_DETAIL_AIE1_MMUL_16_16__HPP__

#include "../vector.hpp"
#include "../ld_st.hpp"

namespace aie::detail {

template <unsigned M, unsigned K, unsigned N, typename T1, typename T2, unsigned AccumBits>
struct mmul_16_16;

template <unsigned AccumBits>
struct mmul_16_16<4, 4, 4, int16, int16, AccumBits> : public C_block<int16, int16, AccumBits, 16, 1>
{
    using vector_A_type = vector<int16, 16>;
    using vector_B_type = vector<int16, 16>;

    using C_block<int16, int16, AccumBits, 16, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mac16(this->data,
                             a.template grow<32>(), 0, 0x02020000, 0x06060404, 0x1010,
                             b,                     0, 0x32103210, 0x32103210, 4);

        this->data = ::mac16(this->data,
                             a.template grow<32>(), 2, 0x02020000, 0x06060404, 0x1010,
                             b,                     8, 0x32103210, 0x32103210, 4);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mul16(a.template grow<32>(), 0, 0x02020000, 0x06060404, 0x1010,
                             b,                     0, 0x32103210, 0x32103210, 4);

        this->data = ::mac16(this->data,
                             a.template grow<32>(), 2, 0x02020000, 0x06060404, 0x1010,
                             b,                     8, 0x32103210, 0x32103210, 4);
    }
};

template <unsigned AccumBits>
struct mmul_16_16<2, 4, 8, int16, int16, AccumBits> : public C_block<int16, int16, AccumBits, 16, 1>
{
    using vector_A_type = vector<int16, 8>;
    using vector_B_type = vector<int16, 32>;

    using C_block<int16, int16, AccumBits, 16, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mac16(this->data,
                             a.template grow<32>(),     0, 0x00000000, 0x02020202, 0x1010,
                             b.template extract<16>(0), 0, 0x76543210, 0x76543210, 8);

        this->data = ::mac16(this->data,
                             a.template grow<32>(),     2, 0x00000000, 0x02020202, 0x1010,
                             b.template extract<16>(1), 0, 0x76543210, 0x76543210, 8);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mul16(a.template grow<32>(),     0, 0x00000000, 0x02020202, 0x1010,
                             b.template extract<16>(0), 0, 0x76543210, 0x76543210, 8);

        this->data = ::mac16(this->data,
                             a.template grow<32>(),     2, 0x00000000, 0x02020202, 0x1010,
                             b.template extract<16>(1), 0, 0x76543210, 0x76543210, 8);
    }
};

template <unsigned AccumBits>
struct mmul_16_16<4, 4, 8, int16, int16, AccumBits> : public C_block<int16, int16, AccumBits, 32, 2>
{
    using vector_A_type = vector<int16, 16>;
    using vector_B_type = vector<int16, 32>;

    using C_block<int16, int16, AccumBits, 32, 2>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mac16(this->data[0],
                                a.template grow<32>(),     0, 0x00000000, 0x02020202, 0x1010,
                                b.template extract<16>(0), 0, 0x76543210, 0x76543210, 8);
        this->data[0] = ::mac16(this->data[0],
                                a.template grow<32>(),     2, 0x00000000, 0x02020202, 0x1010,
                                b.template extract<16>(1), 0, 0x76543210, 0x76543210, 8);

        this->data[1] = ::mac16(this->data[1],
                                a.template grow<32>(),     8, 0x00000000, 0x02020202, 0x1010,
                                b.template extract<16>(0), 0, 0x76543210, 0x76543210, 8);
        this->data[1] = ::mac16(this->data[1],
                                a.template grow<32>(),     10, 0x00000000, 0x02020202, 0x1010,
                                b.template extract<16>(1),  0, 0x76543210, 0x76543210, 8);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mul16(a.template grow<32>(),     0, 0x00000000, 0x02020202, 0x1010,
                                b.template extract<16>(0), 0, 0x76543210, 0x76543210, 8);
        this->data[0] = ::mac16(this->data[0],
                                a.template grow<32>(),     2, 0x00000000, 0x02020202, 0x1010,
                                b.template extract<16>(1), 0, 0x76543210, 0x76543210, 8);

        this->data[1] = ::mul16(a.template grow<32>(),     8, 0x00000000, 0x02020202, 0x1010,
                                b.template extract<16>(0), 0, 0x76543210, 0x76543210, 8);
        this->data[1] = ::mac16(this->data[1],
                                a.template grow<32>(),     10, 0x00000000, 0x02020202, 0x1010,
                                b.template extract<16>(1),  0, 0x76543210, 0x76543210, 8);
    }
};

template <unsigned AccumBits>
struct mmul_16_16<4, 2, 8, int16, int16, AccumBits> : public C_block<int16, int16, AccumBits, 32, 2>
{
    using vector_A_type = vector<int16, 8>;
    using vector_B_type = vector<int16, 16>;

    using C_block<int16, int16, AccumBits, 32, 2>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mac16(this->data[0],
                                a.template grow<32>(), 0, 0x00000000, 0x01010101, 0x1010,
                                b,                     0, 0x76543210, 0x76543210, 8);

        this->data[1] = ::mac16(this->data[1],
                                a.template grow<32>(), 4, 0x00000000, 0x01010101, 0x1010,
                                b,                     0, 0x76543210, 0x76543210, 8);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mul16(a.template grow<32>(), 0, 0x00000000, 0x01010101, 0x1010,
                                b,                     0, 0x76543210, 0x76543210, 8);

        this->data[1] = ::mul16(a.template grow<32>(), 4, 0x00000000, 0x01010101, 0x1010,
                                b,                     0, 0x76543210, 0x76543210, 8);
    }
};

template <unsigned AccumBits>
struct mmul_16_16<8, 8, 1, int16, int16, AccumBits> : public C_block<int16, int16, AccumBits, 8, 1>
{
    using vector_A_type = vector<int16, 64>;
    using vector_B_type = vector<int16, 8>;

    using C_block<int16, int16, AccumBits, 8, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        auto a1 = ::select32(0xffff0000,
                             a.template extract<32>(0), 0, 0x0c080400, 0x0,        0x3210,
                             a.template extract<32>(1), 0, 0x0,        0x0c080400, 0x3210);
        this->data = ::mac8(this->data,
                            a1,                    0, 0x1c181410, 2, 0x3210,
                            b.template grow<16>(), 0, 0x0,        1);
        auto a2 = ::select32(0xffff0000,
                             a.template extract<32>(0), 4, 0x0c080400, 0x0,        0x3210,
                             a.template extract<32>(1), 4, 0x0,        0x0c080400, 0x3210);
        this->data = ::mac8(this->data,
                            a2,                    0, 0x1c181410, 2, 0x3210,
                            b.template grow<16>(), 4, 0x0,        1);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        auto a1 = ::select32(0xffff0000,
                             a.template extract<32>(0), 0, 0x0c080400, 0x0,        0x3210,
                             a.template extract<32>(1), 0, 0x0,        0x0c080400, 0x3210);
        this->data = ::mul8(a1,                    0, 0x1c181410, 2, 0x3210,
                            b.template grow<16>(), 0, 0x0,        1);
        auto a2 = ::select32(0xffff0000,
                             a.template extract<32>(0), 4, 0x0c080400, 0x0,        0x3210,
                             a.template extract<32>(1), 4, 0x0,        0x0c080400, 0x3210);
        this->data = ::mac8(this->data,
                            a2,                    0, 0x1c181410, 2, 0x3210,
                            b.template grow<16>(), 4, 0x0,        1);
    }
};

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, int16, int16, 48> : public mmul_16_16<M, K, N, int16, int16, 48> { using mmul_16_16<M, K, N, int16, int16, 48>::mmul_16_16; };

}

#endif
