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

#ifndef __AIE_API_DETAIL_AIE1_MMUL_64_64__HPP__
#define __AIE_API_DETAIL_AIE1_MMUL_64_64__HPP__

#include "../vector.hpp"
#include "../ld_st.hpp"
#include "../mul.hpp"

namespace aie::detail {

template <unsigned M, unsigned K, unsigned N, typename T1, typename T2, unsigned AccumBits>
struct mmul_64_64;

template <unsigned AccumBits>
struct mmul_64_64<2, 2, 1, cint32, cint32, AccumBits> : public C_block<cint32, cint32, AccumBits, 2, 1>
{
    using vector_A_type = vector<cint32, 4>;
    using vector_B_type = vector<cint32, 2>;

    using C_block<cint32, cint32, AccumBits, 2, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::lmac2(this->data,
                             a.template grow<8>(), 0, 0x20,
                             b.template grow<4>(), 0, 0x00);

        this->data = ::lmac2(this->data,
                             a.template grow<8>(), 1, 0x20,
                             b.template grow<4>(), 1, 0x00);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::lmul2(a.template grow<8>(), 0, 0x20,
                             b.template grow<4>(), 0, 0x00);

        this->data = ::lmac2(this->data,
                             a.template grow<8>(), 1, 0x20,
                             b.template grow<4>(), 1, 0x00);
    }
};

template <unsigned AccumBits>
struct mmul_64_64<1, 2, 2, cint32, cint32, AccumBits> : public C_block<cint32, cint32, AccumBits, 2, 1>
{
    using vector_A_type = vector<cint32, 2>;
    using vector_B_type = vector<cint32, 4>;

    using C_block<cint32, cint32, AccumBits, 2, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::lmac2(this->data,
                             a.template grow<8>(), 0, 0x00,
                             b,                    0, 0x10);

        this->data = ::lmac2(this->data,
                             a.template grow<8>(), 1, 0x00,
                             b,                    2, 0x10);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::lmul2(a.template grow<8>(), 0, 0x00,
                             b,                    0, 0x10);

        this->data = ::lmac2(this->data,
                             a.template grow<8>(), 1, 0x00,
                             b,                    2, 0x10);
    }
};

template <unsigned AccumBits>
struct mmul_64_64<2, 2, 2, cint32, cint32, AccumBits> : public C_block<cint32, cint32, AccumBits, 4, 2>
{
    using vector_A_type = vector<cint32, 4>;
    using vector_B_type = vector<cint32, 4>;

    using C_block<cint32, cint32, AccumBits, 4, 2>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::lmac2(this->data[0],
                                a.template grow<8>(), 0, 0x00,
                                b,                    0, 0x10);

        this->data[1] = ::lmac2(this->data[1],
                                a.template grow<8>(), 2, 0x00,
                                b,                    0, 0x10);

        this->data[0] = ::lmac2(this->data[0],
                                a.template grow<8>(), 1, 0x00,
                                b,                    2, 0x10);

        this->data[1] = ::lmac2(this->data[1],
                                a.template grow<8>(), 3, 0x00,
                                b,                    2, 0x10);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::lmul2(a.template grow<8>(), 0, 0x00,
                                b,                    0, 0x10);

        this->data[1] = ::lmul2(a.template grow<8>(), 2, 0x00,
                                b,                    0, 0x10);

        this->data[0] = ::lmac2(this->data[0],
                                a.template grow<8>(), 1, 0x00,
                                b,                    2, 0x10);

        this->data[1] = ::lmac2(this->data[1],
                                a.template grow<8>(), 3, 0x00,
                                b,                    2, 0x10);
    }
};

template <>
struct mmul_64_64<2, 2, 2, cfloat, cfloat, 32> : public C_block<cfloat, cfloat, 32, 4, 1>
{
    using vector_A_type = vector<cfloat, 4>;
    using vector_B_type = vector<cfloat, 4>;

    using C_block<cfloat, cfloat, 32, 4, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::fpmac(this->data,
                             a.template grow<8>(), 0, 0x2200,
                             b,                    0, 0x1010);

        this->data = ::fpmac(this->data,
                             a.template grow<8>(), 1, 0x2200,
                             b,                    2, 0x1010);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::fpmul(a.template grow<8>(), 0, 0x2200,
                             b,                    0, 0x1010);

        this->data = ::fpmac(this->data,
                             a.template grow<8>(), 1, 0x2200,
                             b,                    2, 0x1010);
    }
};

template <>
struct mmul_64_64<2, 4, 2, cfloat, cfloat, 32> : public C_block<cfloat, cfloat, 32, 4, 1>
{
    using vector_A_type = vector<cfloat, 8>;
    using vector_B_type = vector<cfloat, 8>;

    using C_block<cfloat, cfloat, 32, 4, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::fpmac(this->data,
                             a,                        0, 0x4400,
                             b.template extract<4>(0), 0, 0x1010);

        this->data = ::fpmac(this->data,
                             a,                        1, 0x4400,
                             b.template extract<4>(0), 2, 0x1010);

        this->data = ::fpmac(this->data,
                             a,                        2, 0x4400,
                             b.template extract<4>(1), 0, 0x1010);

        this->data = ::fpmac(this->data,
                             a,                        3, 0x4400,
                             b.template extract<4>(1), 2, 0x1010);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::fpmul(a,                        0, 0x4400,
                             b.template extract<4>(0), 0, 0x1010);

        this->data = ::fpmac(this->data,
                             a,                        1, 0x4400,
                             b.template extract<4>(0), 2, 0x1010);

        this->data = ::fpmac(this->data,
                             a,                        2, 0x4400,
                             b.template extract<4>(1), 0, 0x1010);

        this->data = ::fpmac(this->data,
                             a,                        3, 0x4400,
                             b.template extract<4>(1), 2, 0x1010);
    }
};

template <>
struct mmul_64_64<2, 2, 4, cfloat, cfloat, 32> : public C_block<cfloat, cfloat, 32, 8, 2>
{
    using vector_A_type = vector<cfloat, 4>;
    using vector_B_type = vector<cfloat, 8>;

    using C_block<cfloat, cfloat, 32, 8, 2>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::fpmac(this->data[0],
                                a.template grow<8>(),     0, 0x0000,
                                b.template extract<4>(0), 0, 0x3210);

        this->data[1] = ::fpmac(this->data[1],
                                a.template grow<8>(),     2, 0x0000,
                                b.template extract<4>(0), 0, 0x3210);

        this->data[0] = ::fpmac(this->data[0],
                                a.template grow<8>(),     1, 0x0000,
                                b.template extract<4>(1), 0, 0x3210);

        this->data[1] = ::fpmac(this->data[1],
                                a.template grow<8>(),     3, 0x0000,
                                b.template extract<4>(1), 0, 0x3210);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::fpmul(a.template grow<8>(),     0, 0x0000,
                                b.template extract<4>(0), 0, 0x3210);

        this->data[1] = ::fpmul(a.template grow<8>(),     2, 0x0000,
                                b.template extract<4>(0), 0, 0x3210);

        this->data[0] = ::fpmac(this->data[0],
                                a.template grow<8>(),     1, 0x0000,
                                b.template extract<4>(1), 0, 0x3210);

        this->data[1] = ::fpmac(this->data[1],
                                a.template grow<8>(),     3, 0x0000,
                                b.template extract<4>(1), 0, 0x3210);
    }
};

template <>
struct mmul_64_64<4, 2, 2, cfloat, cfloat, 32> : public C_block<cfloat, cfloat, 32, 8, 2>
{
    using vector_A_type = vector<cfloat, 8>;
    using vector_B_type = vector<cfloat, 4>;

    using C_block<cfloat, cfloat, 32, 8, 2>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::fpmac(this->data[0],
                                a, 0, 0x2200,
                                b, 0, 0x1010);

        this->data[1] = ::fpmac(this->data[1],
                                a, 4, 0x2200,
                                b, 0, 0x1010);

        this->data[0] = ::fpmac(this->data[0],
                                a, 1, 0x2200,
                                b, 2, 0x1010);

        this->data[1] = ::fpmac(this->data[1],
                                a, 5, 0x2200,
                                b, 2, 0x1010);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data[0] = ::fpmul(a, 0, 0x2200,
                                b, 0, 0x1010);

        this->data[1] = ::fpmul(a, 4, 0x2200,
                                b, 0, 0x1010);

        this->data[0] = ::fpmac(this->data[0],
                                a, 1, 0x2200,
                                b, 2, 0x1010);

        this->data[1] = ::fpmac(this->data[1],
                                a, 5, 0x2200,
                                b, 2, 0x1010);
    }
};

template <>
struct mmul_64_64<4, 2, 1, cfloat, cfloat, 32> : public C_block<cfloat, cfloat, 32, 4, 1>
{
    using vector_A_type = vector<cfloat, 8>;
    using vector_B_type = vector<cfloat, 2>;

    using C_block<cfloat, cfloat, 32, 4, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::fpmac(this->data,
                             a,                    0, 0x6420,
                             b.template grow<4>(), 0, 0x0000);

        this->data = ::fpmac(this->data,
                             a,                    1, 0x6420,
                             b.template grow<4>(), 1, 0x0000);
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        this->data = ::fpmul(a,                    0, 0x6420,
                             b.template grow<4>(), 0, 0x0000);

        this->data = ::fpmac(this->data,
                             a,                    1, 0x6420,
                             b.template grow<4>(), 1, 0x0000);
    }
};

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, cint32, cint32, 80> : public mmul_64_64<M, K, N, cint32, cint32, 80> { using mmul_64_64<M, K, N, cint32, cint32, 80>::mmul_64_64; };

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, cfloat, cfloat, 32> : public mmul_64_64<M, K, N, cfloat, cfloat, 32> { using mmul_64_64<M, K, N, cfloat, cfloat, 32>::mmul_64_64; };

}

#endif
