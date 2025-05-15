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

#ifndef __AIE_API_DETAIL_AIE1_MMUL_8_8__HPP__
#define __AIE_API_DETAIL_AIE1_MMUL_8_8__HPP__

#include "../accum.hpp"
#include "../vector.hpp"
#include "../ld_st.hpp"
#include "../mul.hpp"

namespace aie::detail {

template <unsigned M, unsigned K, unsigned N, typename TypeA, typename TypeB, unsigned AccumBits>
struct mmul_8_8;

template <typename TypeA, typename TypeB>
struct mmul_8_8<4, 8, 4, TypeA, TypeB, 48> : public C_block<TypeA, TypeB, 48, 16, 1>
{
    using vector_A_type = vector<TypeA, 32>;
    using vector_B_type = vector<TypeB, 32>;

    using C_block<TypeA, TypeB, 48, 16, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mac16(this->data,
                             b.template grow<64>(), 0, 0x00000000, 8, 0x3120,
                             a,                     0, 0xcc884400, 2, 0x3210);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mul16(b.template grow<64>(), 0, 0x00000000, 8, 0x3120,
                             a,                     0, 0xcc884400, 2, 0x3210);
    }
};

template <typename TypeA, typename TypeB>
struct mmul_8_8<8, 8, 4, TypeA, TypeB, 48> : public C_block<TypeA, TypeB, 48, 32, 1>
{
    using vector_A_type = vector<TypeA, 64>;
    using vector_B_type = vector<TypeB, 32>;

    using C_block<TypeA, TypeB, 48, 32, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data.template insert<16>(0, ::mac16(this->data.template extract<16>(0),
                                                  b.template grow<64>(),     0, 0x00000000, 8, 0x3120,
                                                  a.template extract<32>(0), 0, 0xcc884400, 2, 0x3210));

        this->data.template insert<16>(1, ::mac16(this->data.template extract<16>(1),
                                                  b.template grow<64>(),     0, 0x00000000, 8, 0x3120,
                                                  a.template extract<32>(1), 0, 0xcc884400, 2, 0x3210));
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data.template insert<16>(0, ::mul16(b.template grow<64>(),     0, 0x00000000, 8, 0x3120,
                                                  a.template extract<32>(0), 0, 0xcc884400, 2, 0x3210));

        this->data.template insert<16>(1, ::mul16(b.template grow<64>(),     0, 0x00000000, 8, 0x3120,
                                                  a.template extract<32>(1), 0, 0xcc884400, 2, 0x3210));
    }
};

template <typename TypeA, typename TypeB>
struct mmul_8_8<4, 8, 8, TypeA, TypeB, 48> : public C_block<TypeA, TypeB, 48, 32, 1>
{
    using vector_A_type = vector<TypeA, 32>;
    using vector_B_type = vector<TypeB, 64>;

    using C_block<TypeA, TypeB, 48, 32, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data.template insert<16>(0, ::mac16(this->data.template extract<16>(0),
                                                  b, 0, 0x11101110, 16, 0x3120,
                                                  a, 0, 0x44440000,  2, 0x3210));

        this->data.template insert<16>(1, ::mac16(this->data.template extract<16>(1),
                                                  b, 0, 0x11101110, 16, 0x3120,
                                                  a, 0, 0xcccc8888,  2, 0x3210));
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data.template insert<16>(0, ::mul16(b, 0, 0x11101110, 16, 0x3120,
                                                  a, 0, 0x44440000,  2, 0x3210));

        this->data.template insert<16>(1, ::mul16(b, 0, 0x11101110, 16, 0x3120,
                                                  a, 0, 0xcccc8888,  2, 0x3210));
    }

};

template <typename TypeA, typename TypeB>
struct mmul_8_8<2, 8, 8, TypeA, TypeB, 48> : public C_block<TypeA, TypeB, 48, 16, 1>
{
    using vector_A_type = vector<TypeA, 16>;
    using vector_B_type = vector<TypeB, 64>;

    using C_block<TypeA, TypeB, 48, 16, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mac16(this->data,
                             b,                     0, 0x11101110, 16, 0x3120,
                             a.template grow<32>(), 0, 0x44440000,  2, 0x3210);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mul16(b,                     0, 0x11101110, 16, 0x3120,
                             a.template grow<32>(), 0, 0x44440000,  2, 0x3210);
    }
};

template <typename TypeA, typename TypeB>
struct mmul_8_8<1, 16, 8, TypeA, TypeB, 48> : public C_block<TypeA, TypeB, 48, 8, 1>
{
    using vector_A_type = vector<TypeA, 16>;
    using vector_B_type = vector<TypeB, 128>;

    using C_block<TypeA, TypeB, 48, 8, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mac8(this->data,
                            b,                     0, 0x11101110, 16, 0x3120,
                            a.template grow<32>(), 0, 0x00000000,  2, 0x3210);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mul8(b,                     0, 0x11101110, 16, 0x3120,
                            a.template grow<32>(), 0, 0x00000000,  2, 0x3210);
    }
};

template <typename TypeA, typename TypeB>
struct mmul_8_8<2, 16, 8, TypeA, TypeB, 48> : public C_block<TypeA, TypeB, 48, 16, 1>
{
    using vector_A_type = vector<TypeA, 32>;
    using vector_B_type = vector<TypeB, 128>;

    using C_block<TypeA, TypeB, 48, 16, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mac16(this->data,
                             b.template extract<64>(0), 0, 0x11101110, 16, 0x3120,
                             a,                         0, 0x88880000,  2, 0x3210);

        this->data = ::mac16(this->data,
                             b.template extract<64>(1), 0, 0x11101110, 16, 0x3120,
                             a,                         8, 0x88880000,  2, 0x3210);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::mul16(b.template extract<64>(0), 0, 0x11101110, 16, 0x3120,
                             a,                         0, 0x88880000,  2, 0x3210);

        this->data = ::mac16(this->data,
                             b.template extract<64>(1), 0, 0x11101110, 16, 0x3120,
                             a,                         8, 0x88880000,  2, 0x3210);
    }
};

template <typename TypeA, typename TypeB>
struct mmul_8_8<4, 16, 4, TypeA, TypeB, 48> : public C_block<TypeA, TypeB, 48, 16, 2>
{
    using vector_A_type = vector<TypeA, 64>;
    using vector_B_type = vector<TypeB, 64>;

    using C_block<TypeA, TypeB, 48, 16, 2>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mac8(this->data[0],
                               b,                         0, 0x00000000, 8, 0x3120,
                               a.template extract<32>(0), 0, 0x00008800, 2, 0x3210);

        this->data[1] = ::mac8(this->data[1],
                               b,                         0, 0x00000000, 8, 0x3120,
                               a.template extract<32>(1), 0, 0x00008800, 2, 0x3210);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::mul8(b,                         0, 0x00000000, 8, 0x3120,
                               a.template extract<32>(0), 0, 0x00008800, 2, 0x3210);

        this->data[1] = ::mul8(b,                         0, 0x00000000, 8, 0x3120,
                               a.template extract<32>(1), 0, 0x00008800, 2, 0x3210);
    }
};

template <typename TypeA, typename TypeB>
struct mmul_8_8<4, 16, 8, TypeA, TypeB, 48> : public C_block<TypeA, TypeB, 48, 32, 1>
{
    using vector_A_type = vector<TypeA, 64>;
    using vector_B_type = vector<TypeB, 128>;

    using C_block<TypeA, TypeB, 48, 32, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data.template insert<16>(0, ::mac16(this->data.template extract<16>(0),
                                                  b.template extract<64>(0), 0, 0x11101110, 16, 0x3120,
                                                  a.template extract<32>(0), 0, 0x88880000,  2, 0x3210));

        this->data.template insert<16>(1, ::mac16(this->data.template extract<16>(1),
                                                  b.template extract<64>(0), 0, 0x11101110, 16, 0x3120,
                                                  a.template extract<32>(1), 0, 0x88880000,  2, 0x3210));

        this->data.template insert<16>(0, ::mac16(this->data.template extract<16>(0),
                                                  b.template extract<64>(1), 0, 0x11101110, 16, 0x3120,
                                                  a.template extract<32>(0), 8, 0x88880000,  2, 0x3210));

        this->data.template insert<16>(1, ::mac16(this->data.template extract<16>(1),
                                                  b.template extract<64>(1), 0, 0x11101110, 16, 0x3120,
                                                  a.template extract<32>(1), 8, 0x88880000,  2, 0x3210));
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data.template insert<16>(0, ::mul16(b.template extract<64>(0), 0, 0x11101110, 16, 0x3120,
                                                  a.template extract<32>(0), 0, 0x88880000,  2, 0x3210));

        this->data.template insert<16>(1, ::mul16(b.template extract<64>(0), 0, 0x11101110, 16, 0x3120,
                                                  a.template extract<32>(1), 0, 0x88880000,  2, 0x3210));

        this->data.template insert<16>(0, ::mac16(this->data.template extract<16>(0),
                                                  b.template extract<64>(1), 0, 0x11101110, 16, 0x3120,
                                                  a.template extract<32>(0), 8, 0x88880000,  2, 0x3210));

        this->data.template insert<16>(1, ::mac16(this->data.template extract<16>(1),
                                                  b.template extract<64>(1), 0, 0x11101110, 16, 0x3120,
                                                  a.template extract<32>(1), 8, 0x88880000,  2, 0x3210));
    }
};

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, int8, int8, 48>   : public mmul_8_8<M, K, N, int8,  int8, 48>  { using mmul_8_8<M, K, N, int8,  int8, 48>::mmul_8_8; };

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, uint8, uint8, 48> : public mmul_8_8<M, K, N, uint8, uint8, 48> { using mmul_8_8<M, K, N, uint8, uint8, 48>::mmul_8_8; };

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, int8, uint8, 48>  : public mmul_8_8<M, K, N, int8,  uint8, 48> { using mmul_8_8<M, K, N, int8,  uint8, 48>::mmul_8_8; };

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, uint8, int8, 48>  : public mmul_8_8<M, K, N, uint8, int8, 48>  { using mmul_8_8<M, K, N, uint8, int8, 48>::mmul_8_8; };

}

#endif
