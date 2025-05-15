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

#ifndef __AIE_API_DETAIL_AIE2_MMUL_C32_C32__HPP__
#define __AIE_API_DETAIL_AIE2_MMUL_C32_C32__HPP__

#include "../broadcast.hpp"

namespace aie::detail {

template <unsigned M, unsigned K, unsigned N, unsigned AccumBits>
struct mmul_c32_c32;

template <>
struct mmul_c32_c32<1, 2, 8, 64> : public C_block<cint32, cint32, 64, 8, 1>
{
    using TypeA = cint32;
    using TypeB = cint32;

    using vector_A_type = vector<TypeA, 2>;
    using vector_B_type = vector<TypeB, 16>;

    using C_block<TypeA, TypeB, 64, 8, 1>::C_block;

    __aie_inline void mac(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        const vector<TypeA, 8> tmp1 = broadcast<TypeA, 8>::run(a[0]);
        const vector<TypeA, 8> tmp2 = broadcast<TypeA, 8>::run(a[1]);
#if __AIE_API_MUL_CONJUGATE_32BIT_INTRINSICS__
        this->data = ::mac_elem_8_conf(tmp1, b.template extract<8>(0), this->data, this->zero, OP_TERM_NEG_COMPLEX, 0, 0);
#else
        this->data = ::mac_elem_8_conf(tmp1, b.template extract<8>(0), this->data, this->zero, 0, 0);
#endif
        this->data = ::mac_elem_8     (tmp2, b.template extract<8>(1), this->data);
        this->zero = false;
    }

    __aie_inline void mul(const vector_A_type &a, bool a_sign, const vector_B_type &b, bool b_sign)
    {
        const vector<TypeA, 8> tmp1 = broadcast<TypeA, 8>::run(a[0]);
        const vector<TypeA, 8> tmp2 = broadcast<TypeA, 8>::run(a[1]);
        this->data = ::mul_elem_8(tmp1, b.template extract<8>(0));
        this->data = ::mac_elem_8(tmp2, b.template extract<8>(1), this->data);
        this->zero = false;
    }
};

template <unsigned M, unsigned K, unsigned N>
struct mmul<M, K, N, cint32, cint32, 64> : public mmul_c32_c32<M, K, N, 64> { using mmul_c32_c32<M, K, N, 64>::mmul_c32_c32; };

}

#endif
