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

#ifndef __AIE_API_DETAIL_AIE2_EMULATED_MUL_INTRINSICS_HPP__
#define __AIE_API_DETAIL_AIE2_EMULATED_MUL_INTRINSICS_HPP__

#include "../accum.hpp"
#include "../vector.hpp"

namespace aie::detail {

// Any 32bit width integer (signed, unsigned)
template <typename T> concept Integral32 = utils::is_one_of_v<T, int32, uint32>;

// Any 16bit width integer (signed, unsigned)
template <typename T> concept Integral16 = utils::is_one_of_v<T, int16, uint16>;

// Integral32 x Integral16
template <Integral32 T1, Integral16 T2>
inline accum<acc64, 16> mul_conv_16x4( vector<T1, 16> a0, vector<T1, 16> a1,  bool a_sign, vector<T2, 32> b, bool b_sign )
{
    using hi_type = std::conditional_t<is_signed_v<T1>, v32int16, v32uint16>;

    vector<uint16, 32> lo = (v32uint16)::shuffle( a0, a1, T16_32x2_lo );
    hi_type            hi = (hi_type)  ::shuffle( a0, a1, T16_32x2_hi );
    accum<acc64, 16>  acc = ::mul_conv_16x4( hi, a_sign, b, b_sign );
    acc = ::mac_conv_16x4_conf( lo, false, b, b_sign, acc, 0, 1, 0, 0 );
    return acc;
}

template <Integral32 T1, Integral16 T2>
inline accum<acc64, 16> negmul_conv_16x4( vector<T1, 16> a0, vector<T1, 16> a1, bool a_sign, vector<T2, 32> b, bool b_sign )
{
    using hi_type = std::conditional_t<is_signed_v<T1>, v32int16, v32uint16>;

    vector<uint16, 32> lo = (v32uint16)::shuffle( a0, a1, T16_32x2_lo );
    hi_type            hi = (hi_type)  ::shuffle( a0, a1, T16_32x2_hi );
    accum<acc64, 16>  acc = ::mul_conv_16x4( hi, a_sign, b, b_sign );
    acc = ::mac_conv_16x4_conf( lo, false, b, b_sign, acc, 0, 1, 1, 1 );
    return acc;
}

template <Integral32 T1, Integral16 T2>
inline accum<acc64, 16> mac_conv_16x4( vector<T1, 16> a0, vector<T1, 16> a1, bool a_sign, vector<T2, 32> b, bool b_sign, accum<acc64, 16> acc )
{
    using hi_type = std::conditional_t<is_signed_v<T1>, v32int16, v32uint16>;

    vector<uint16, 32>   lo = (v32uint16)::shuffle( a0, a1, T16_32x2_lo);
    hi_type              hi = (hi_type)  ::shuffle( a0, a1, T16_32x2_hi);
    accum<acc64, 16> acc_hi = ::mul_conv_16x4( hi, a_sign, b, b_sign);
    acc = ::addmac_conv_16x4_conf( lo, false, b, b_sign, acc_hi, acc, 0, 1, 0, 0, 0);
    return acc;
}

template <Integral32 T1, Integral16 T2>
inline accum<acc64, 16> msc_conv_16x4( vector<T1, 16> a0, vector<T1, 16> a1, bool a_sign, vector<T2, 32> b, bool b_sign, accum<acc64, 16> acc )
{
    using hi_type = std::conditional_t<is_signed_v<T1>, v32int16, v32uint16>;

    vector<uint16, 32>   lo = (v32uint16)::shuffle( a0, a1, T16_32x2_lo);
    hi_type              hi = (hi_type)  ::shuffle( a0, a1, T16_32x2_hi);
    accum<acc64, 16> acc_hi = ::mul_conv_16x4( hi, a_sign, b, b_sign);
    acc = ::addmac_conv_16x4_conf( lo, false, b, b_sign, acc_hi, acc, 0, 1, 1, 1, 0);
    return acc;
}

// Integral16 x Integral32
template <Integral16 T1, Integral32 T2>
inline accum<acc64, 16> mul_conv_16x4( vector<T1, 32> a,  bool a_sign, vector<T2, 16> b0, vector<T2, 16> b1, bool b_sign )
{
    using b_hi_type = std::conditional_t<is_signed_v<T2>, int16, uint16>;

    aie::vector<uint16, 32>    b_lo = ::shuffle(b0.template cast_to<uint16>(),    b1.template cast_to<uint16>(),    T16_32x2_lo);
    aie::vector<b_hi_type, 32> b_hi = ::shuffle(b0.template cast_to<b_hi_type>(), b1.template cast_to<b_hi_type>(), T16_32x2_hi);

    accum<acc64, 16> acc = ::mul_conv_16x4(a, a_sign, b_hi, b_sign);
    acc = ::mac_conv_16x4_conf(a, a_sign, b_lo, false, acc, 0, 1, 0, 0);
    return acc;
}

template <Integral16 T1, Integral32 T2>
inline accum<acc64, 16> negmul_conv_16x4( vector<T1, 32> a, bool a_sign, vector<T2, 16> b0, vector<T2, 16> b1, bool b_sign )
{
    using b_hi_type = std::conditional_t<is_signed_v<T2>, int16, uint16>;

    aie::vector<uint16, 32>    b_lo = ::shuffle(b0.template cast_to<uint16>(),    b1.template cast_to<uint16>(),    T16_32x2_lo);
    aie::vector<b_hi_type, 32> b_hi = ::shuffle(b0.template cast_to<b_hi_type>(), b1.template cast_to<b_hi_type>(), T16_32x2_hi);

    accum<acc64, 16> acc = ::mul_conv_16x4( a, a_sign, b_hi, b_sign );
    acc = ::mac_conv_16x4_conf( a, a_sign, b_lo, false, acc, 0, 1, 1, 1 );
    return acc;
}

template <Integral16 T1, Integral32 T2>
inline accum<acc64, 16> mac_conv_16x4( vector<T1, 32> a, bool a_sign, vector<T2, 16> b0, vector<T2, 16> b1, bool b_sign, accum<acc64, 16> acc )
{
    using b_hi_type = std::conditional_t<is_signed_v<T2>, int16, uint16>;

    aie::vector<uint16, 32>    b_lo = ::shuffle(b0.template cast_to<uint16>(),    b1.template cast_to<uint16>(),    T16_32x2_lo);
    aie::vector<b_hi_type, 32> b_hi = ::shuffle(b0.template cast_to<b_hi_type>(), b1.template cast_to<b_hi_type>(), T16_32x2_hi);

    accum<acc64, 16> acc_hi = ::mul_conv_16x4( a, a_sign, b_hi, b_sign);
    acc = ::addmac_conv_16x4_conf( a, a_sign, b_lo, false, acc_hi, acc, 0, 1, 0, 0, 0);
    return acc;
}

template <Integral16 T1, Integral32 T2>
inline accum<acc64, 16> msc_conv_16x4( vector<T1, 32> a, bool a_sign, vector<T2, 16> b0, vector<T2, 16> b1, bool b_sign, accum<acc64, 16> acc )
{
    using b_hi_type = std::conditional_t<is_signed_v<T2>, int16, uint16>;

    aie::vector<uint16, 32>    b_lo = ::shuffle(b0.template cast_to<uint16>(),    b1.template cast_to<uint16>(),    T16_32x2_lo);
    aie::vector<b_hi_type, 32> b_hi = ::shuffle(b0.template cast_to<b_hi_type>(), b1.template cast_to<b_hi_type>(), T16_32x2_hi);

    accum<acc64, 16> acc_hi = ::mul_conv_16x4( a, a_sign, b_hi, b_sign);
    acc = ::addmac_conv_16x4_conf(a , a_sign, b_lo, false, acc_hi, acc, 0, 1, 1, 1, 0);
    return acc;
}

// Integral32 x Integral32
template <Integral32 T1, Integral32 T2>
inline accum<acc64, 16> mul_conv_16x4(vector<T1, 16> a0, vector<T1, 16> a1, int sgn_x, vector<T2, 16> b0, vector<T2, 16> b1, int sgn_y)
{
    using a_hi_type = std::conditional_t<is_signed_v<T1>, int16, uint16>;
    using b_hi_type = std::conditional_t<is_signed_v<T2>, int16, uint16>;

    aie::vector<uint16, 32>    a_lo = ::shuffle(a0.template cast_to<uint16>(),    a1.template cast_to<uint16>(),    T16_32x2_lo);
    aie::vector<a_hi_type, 32> a_hi = ::shuffle(a0.template cast_to<a_hi_type>(), a1.template cast_to<a_hi_type>(), T16_32x2_hi);
    aie::vector<uint16, 32>    b_lo = ::shuffle(b0.template cast_to<uint16>(),    b1.template cast_to<uint16>(),    T16_32x2_lo);
    aie::vector<b_hi_type, 32> b_hi = ::shuffle(b0.template cast_to<b_hi_type>(), b1.template cast_to<b_hi_type>(), T16_32x2_hi);

    accum<acc64, 16> acc = ::mul_conv_16x4(a_hi, sgn_x, b_hi, sgn_y);
    acc = ::mac_conv_16x4_conf(a_hi,sgn_x,b_lo,false,acc,0,1,0,0);
    acc = ::mac_conv_16x4_conf(a_lo,false,b_hi,sgn_y,acc,0,0,0,0);
    acc = ::mac_conv_16x4_conf(a_lo,false,b_lo,false,acc,0,1,0,0);
    return acc;
}

template <Integral32 T1, Integral32 T2>
inline accum<acc64, 16> negmul_conv_16x4(vector<T1, 16> a0, vector<T1, 16> a1, int sgn_x, vector<T2, 16> b0, vector<T2, 16> b1, int sgn_y)
{
    using a_hi_type = std::conditional_t<is_signed_v<T1>, int16, uint16>;
    using b_hi_type = std::conditional_t<is_signed_v<T2>, int16, uint16>;

    aie::vector<uint16, 32>    a_lo = ::shuffle(a0.template cast_to<uint16>(),    a1.template cast_to<uint16>(),    T16_32x2_lo);
    aie::vector<a_hi_type, 32> a_hi = ::shuffle(a0.template cast_to<a_hi_type>(), a1.template cast_to<a_hi_type>(), T16_32x2_hi);
    aie::vector<uint16, 32>    b_lo = ::shuffle(b0.template cast_to<uint16>(),    b1.template cast_to<uint16>(),    T16_32x2_lo);
    aie::vector<b_hi_type, 32> b_hi = ::shuffle(b0.template cast_to<b_hi_type>(), b1.template cast_to<b_hi_type>(), T16_32x2_hi);

    accum<acc64, 16> acc = ::negmul_conv_16x4(a_hi,sgn_x,b_hi,sgn_y);
    acc = ::msc_conv_16x4_conf(a_hi,sgn_x,b_lo,false,acc,0,1,0,0);
    acc = ::msc_conv_16x4_conf(a_lo,false,b_hi,sgn_y,acc,0,0,0,0);
    acc = ::msc_conv_16x4_conf(a_lo,false,b_lo,false,acc,0,1,0,0);
    return acc;
}

template <Integral32 T1, Integral32 T2>
inline accum<acc64, 16> mac_conv_16x4(vector<T1, 16> a0, vector<T1, 16> a1, int sgn_x, vector<T2, 16> b0, vector<T2, 16> b1, int sgn_y, accum<acc64, 16> acc1)
{
    using a_hi_type = std::conditional_t<is_signed_v<T1>, int16, uint16>;
    using b_hi_type = std::conditional_t<is_signed_v<T2>, int16, uint16>;

    aie::vector<uint16, 32>    a_lo = ::shuffle(a0.template cast_to<uint16>(),    a1.template cast_to<uint16>(),    T16_32x2_lo);
    aie::vector<a_hi_type, 32> a_hi = ::shuffle(a0.template cast_to<a_hi_type>(), a1.template cast_to<a_hi_type>(), T16_32x2_hi);
    aie::vector<uint16, 32>    b_lo = ::shuffle(b0.template cast_to<uint16>(),    b1.template cast_to<uint16>(),    T16_32x2_lo);
    aie::vector<b_hi_type, 32> b_hi = ::shuffle(b0.template cast_to<b_hi_type>(), b1.template cast_to<b_hi_type>(), T16_32x2_hi);

    accum<acc64, 16> acc = ::mul_conv_16x4(a_hi,sgn_x,b_hi,sgn_y);
    acc = ::mac_conv_16x4_conf(a_hi,sgn_x,b_lo,false,acc,0,1,0,0);
    acc = ::mac_conv_16x4_conf(a_lo,false,b_hi,sgn_y,acc,0,0,0,0);
    acc = ::addmac_conv_16x4_conf(a_lo,false,b_lo,false,acc,acc1,0,1,0,0,0);
    return acc;
}

template <Integral32 T1, Integral32 T2>
inline accum<acc64, 16> msc_conv_16x4(vector<T1, 16> a0, vector<T1, 16> a1, int sgn_x, vector<T2, 16> b0, vector<T2, 16> b1, int sgn_y, accum<acc64, 16> acc1)
{
    using a_hi_type = std::conditional_t<is_signed_v<T1>, int16, uint16>;
    using b_hi_type = std::conditional_t<is_signed_v<T2>, int16, uint16>;

    aie::vector<uint16, 32>    a_lo = ::shuffle(a0.template cast_to<uint16>(),    a1.template cast_to<uint16>(),    T16_32x2_lo);
    aie::vector<a_hi_type, 32> a_hi = ::shuffle(a0.template cast_to<a_hi_type>(), a1.template cast_to<a_hi_type>(), T16_32x2_hi);
    aie::vector<uint16, 32>    b_lo = ::shuffle(b0.template cast_to<uint16>(),    b1.template cast_to<uint16>(),    T16_32x2_lo);
    aie::vector<b_hi_type, 32> b_hi = ::shuffle(b0.template cast_to<b_hi_type>(), b1.template cast_to<b_hi_type>(), T16_32x2_hi);

    accum<acc64, 16> acc = ::negmul_conv_16x4(a_hi,sgn_x,b_hi,sgn_y);
    acc = ::msc_conv_16x4_conf(a_hi,sgn_x,b_lo,false,acc,0,1,0,0);
    acc = ::msc_conv_16x4_conf(a_lo,false,b_hi,sgn_y,acc,0,0,0,0);
    acc = ::addmsc_conv_16x4_conf(a_lo,false,b_lo,false,acc,acc1,0,1,0,0,0);
    return acc;
}

}

#endif
