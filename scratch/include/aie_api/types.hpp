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

/**
 * @file
 * @brief Basic types exposed to users.
 */

#pragma once

#ifndef __AIE_API_TYPES__HPP__
#define __AIE_API_TYPES__HPP__

#include "detail/config.hpp"

#include <type_traits>
#include <cstdint>

using int8  = int8_t;
using int16 = int16_t;
using int32 = int32_t;

using uint8  = uint8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;

#if __AIE_API_REGISTER_ATTR_DEFINED__ == 0

#define __aie_register(...) chess_storage(__VA_ARGS__)

#endif

#if __AIE_ARCH__ == 10

struct  exact_acc48 {};
struct  exact_acc80 {};
struct exact_cacc48 {};
struct exact_cacc80 {};

#elif __AIE_ARCH__ == 20

struct  exact_acc32 {};
struct  exact_acc64 {};

#endif

/**
 * @ingroup group_basic_types_accum
 * Internal tag used to signal that the default accumulator precision is needed. This type is not meant to be directly
 * used by AIE API users.
 */
struct accauto {};

using cint16_t = cint16;
using cint32_t = cint32;

#if AIE_API_MATH_VERSION < 100

struct     acc72 {};
struct    cacc72 {};
struct     acc80 {};
struct    cacc80 {};

#if !__AIE_API_COMPLEX_FP32_EMULATION__
struct caccfloat {};
#endif

#endif

using cfloat_t = cfloat;

#if AIE_API_ML_VERSION <= 100

struct int4_t {};

struct bfloat16 {};

#endif

using int4  = int4_t;
using uint4 = uint4_t;

#if AIE_API_ML_VERSION >= 200

namespace aie {

// TODO: CRVO-2167: bfloat16 constructor is not constexpr
#if AIE_API_NATIVE == 0
constexpr
#endif
static inline bfloat16 abs(bfloat16 a)
{
    bfloat16 ret;

#if AIE_API_NATIVE == 0
    ret.m0 = a.m0 & 0x7fff; // Clear upper bit to compute the absolute
#else
    ret = (bfloat16)std::abs((float)a);
#endif

    return ret;
}

#if AIE_API_NATIVE == 0
constexpr
#endif
static inline int4_t abs(const int4_t &a)
{
    int4_t ret;

#if AIE_API_NATIVE == 0
    ret.m0 = a.m0 & 0x7; // Clear upper bit to compute the absolute
#else
    ret = std::abs((int)a);
#endif

    return ret;
}

#if AIE_API_NATIVE == 0
constexpr
#endif
static inline uint4_t abs(const uint4_t &a)
{
    return a;
}

}

#if __AIE_API_TERM_NEG_COMPLEX_DEFINES__ == 0

#define OP_TERM_NEG_COMPLEX                     0x0A
#define OP_TERM_NEG_COMPLEX_CONJUGATE_X         0xA0
#define OP_TERM_NEG_COMPLEX_CONJUGATE_Y         0x50
#define OP_TERM_NEG_COMPLEX_CONJUGATE_X_Y       0xFA
#define OP_TERM_NEG_COMPLEX_CONJUGATE_BUTTERFLY 0xC6
#define OP_TERM_NEG_COMPLEX_BUTTERFLY           0x9C

#endif

#endif

#endif
