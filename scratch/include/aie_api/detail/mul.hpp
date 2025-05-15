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

#ifndef __AIE_API_DETAIL_MUL__HPP__
#define __AIE_API_DETAIL_MUL__HPP__

#include "filter.hpp"
#include "shuffle.hpp"

#include "../accum.hpp"
#include "../expr.hpp"
#include "../vector.hpp"

#include <cstdlib>
#include <cmath>
#include <climits>

namespace aie::detail {

enum class MulMacroOp
{
    Unavailable = -1,
    Mul = 0,
    NegMul,

    Add_Mul,
    Add_NegMul,
    Sub_Mul    = Add_NegMul ,   // Synonym of Add_NegMul
#if __AIE_ARCH__ == 10
    MulSym,
    NegMulSym,
    MulAntisym,
    NegMulAntisym,

    Add_MulSym,
    Add_NegMulSym,
    Sub_MulSym = Add_NegMulSym,
    Add_MulAntisym,
    Add_NegMulAntisym,
    Sub_MulAntisym = Add_NegMulAntisym,

    MulAbs1,
    MulAbs1Conj2,
    MulConj1,
    MulConj1Conj2,
    MulConj2,
    NegMulAbs1,
    NegMulAbs1Conj2,
    NegMulConj1,
    NegMulConj1Conj2,
    NegMulConj2,

    MulSymConj1,
    MulSymConj1Conj2,
    MulSymConj2,
    NegMulSymConj1,
    NegMulSymConj1Conj2,
    NegMulSymConj2,

    MulAntisymConj1,
    MulAntisymConj1Conj2,
    MulAntisymConj2,
    NegMulAntisymConj1,
    NegMulAntisymConj1Conj2,
    NegMulAntisymConj2,

    MulMax,
    MulMin,

    Add_MulAbs1,
    Add_MulAbs1Conj2,
    Add_MulConj1,
    Add_MulConj1Conj2,
    Add_MulConj2,
    Sub_MulAbs1,
    Sub_MulAbs1Conj2,
    Sub_MulConj1,
    Sub_MulConj1Conj2,
    Sub_MulConj2,

    Add_MulSymConj1,
    Add_MulSymConj1Conj2,
    Add_MulSymConj2,
    Sub_MulSymConj1,
    Sub_MulSymConj1Conj2,
    Sub_MulSymConj2,

    Add_MulAntisymConj1,
    Add_MulAntisymConj1Conj2,
    Add_MulAntisymConj2,
    Sub_MulAntisymConj1,
    Sub_MulAntisymConj1Conj2,
    Sub_MulAntisymConj2,

    Add_MulMax,
    Add_MulMin,
    Sub_MulMax,
    Sub_MulMin,
#elif __AIE_ARCH__ == 20
    MulConj1,
    MulConj1Conj2,
    MulConj2,
    NegMulConj1,
    NegMulConj1Conj2,
    NegMulConj2,

    Add_MulConj1,
    Add_MulConj1Conj2,
    Add_MulConj2,
    Sub_MulConj1,
    Sub_MulConj1Conj2,
    Sub_MulConj2,
#endif
};

template <MulMacroOp MulOp>
static constexpr MulMacroOp swap_conjugate_order()
{
#if __AIE_ARCH__ == 10
    if      constexpr (MulOp == MulMacroOp::MulConj1)            return MulMacroOp::MulConj2;
    else if constexpr (MulOp == MulMacroOp::MulConj2)            return MulMacroOp::MulConj1;
    else if constexpr (MulOp == MulMacroOp::NegMulConj1)         return MulMacroOp::NegMulConj2;
    else if constexpr (MulOp == MulMacroOp::NegMulConj2)         return MulMacroOp::NegMulConj1;

    else if constexpr (MulOp == MulMacroOp::MulSymConj1)         return MulMacroOp::MulSymConj2;
    else if constexpr (MulOp == MulMacroOp::MulSymConj2)         return MulMacroOp::MulSymConj1;
    else if constexpr (MulOp == MulMacroOp::NegMulSymConj1)      return MulMacroOp::NegMulSymConj2;
    else if constexpr (MulOp == MulMacroOp::NegMulSymConj2)      return MulMacroOp::NegMulSymConj1;

    else if constexpr (MulOp == MulMacroOp::MulAntisymConj1)     return MulMacroOp::MulAntisymConj2;
    else if constexpr (MulOp == MulMacroOp::MulAntisymConj2)     return MulMacroOp::MulAntisymConj1;
    else if constexpr (MulOp == MulMacroOp::NegMulAntisymConj1)  return MulMacroOp::NegMulAntisymConj2;
    else if constexpr (MulOp == MulMacroOp::NegMulAntisymConj2)  return MulMacroOp::NegMulAntisymConj1;

    else if constexpr (MulOp == MulMacroOp::Add_MulConj1)        return MulMacroOp::Add_MulConj2;
    else if constexpr (MulOp == MulMacroOp::Add_MulConj2)        return MulMacroOp::Add_MulConj1;
    else if constexpr (MulOp == MulMacroOp::Sub_MulConj1)        return MulMacroOp::Sub_MulConj2;
    else if constexpr (MulOp == MulMacroOp::Sub_MulConj2)        return MulMacroOp::Sub_MulConj1;

    else if constexpr (MulOp == MulMacroOp::Add_MulSymConj1)     return MulMacroOp::Add_MulSymConj2;
    else if constexpr (MulOp == MulMacroOp::Add_MulSymConj2)     return MulMacroOp::Add_MulSymConj1;
    else if constexpr (MulOp == MulMacroOp::Sub_MulSymConj1)     return MulMacroOp::Sub_MulSymConj2;
    else if constexpr (MulOp == MulMacroOp::Sub_MulSymConj2)     return MulMacroOp::Sub_MulSymConj1;

    else if constexpr (MulOp == MulMacroOp::Add_MulAntisymConj1) return MulMacroOp::Add_MulAntisymConj2;
    else if constexpr (MulOp == MulMacroOp::Add_MulAntisymConj2) return MulMacroOp::Add_MulAntisymConj1;
    else if constexpr (MulOp == MulMacroOp::Sub_MulAntisymConj1) return MulMacroOp::Sub_MulAntisymConj2;
    else if constexpr (MulOp == MulMacroOp::Sub_MulAntisymConj2) return MulMacroOp::Sub_MulAntisymConj1;

#elif __AIE_ARCH__ == 20
    if      constexpr (MulOp == MulMacroOp::MulConj1)            return MulMacroOp::MulConj2;
    else if constexpr (MulOp == MulMacroOp::MulConj2)            return MulMacroOp::MulConj1;
    else if constexpr (MulOp == MulMacroOp::NegMulConj1)         return MulMacroOp::NegMulConj2;
    else if constexpr (MulOp == MulMacroOp::NegMulConj2)         return MulMacroOp::NegMulConj1;

    else if constexpr (MulOp == MulMacroOp::Add_MulConj1)        return MulMacroOp::Add_MulConj2;
    else if constexpr (MulOp == MulMacroOp::Add_MulConj2)        return MulMacroOp::Add_MulConj1;
    else if constexpr (MulOp == MulMacroOp::Sub_MulConj1)        return MulMacroOp::Sub_MulConj2;
    else if constexpr (MulOp == MulMacroOp::Sub_MulConj2)        return MulMacroOp::Sub_MulConj1;
#endif
    else                                                         return MulOp;
};

template <MulMacroOp MulOp>
static constexpr MulMacroOp remove_conj1()
{
#if __AIE_ARCH__ == 10
    if      constexpr (MulOp == MulMacroOp::MulConj1)                 return MulMacroOp::Mul;
    else if constexpr (MulOp == MulMacroOp::MulConj1Conj2)            return MulMacroOp::MulConj2;
    else if constexpr (MulOp == MulMacroOp::NegMulConj1)              return MulMacroOp::NegMul;
    else if constexpr (MulOp == MulMacroOp::NegMulConj1Conj2)         return MulMacroOp::NegMulConj2;

    else if constexpr (MulOp == MulMacroOp::MulSymConj1)              return MulMacroOp::MulSym;
    else if constexpr (MulOp == MulMacroOp::MulSymConj1Conj2)         return MulMacroOp::MulSymConj2;
    else if constexpr (MulOp == MulMacroOp::NegMulSymConj1)           return MulMacroOp::NegMulSym;
    else if constexpr (MulOp == MulMacroOp::NegMulSymConj1Conj2)      return MulMacroOp::NegMulSymConj2;

    else if constexpr (MulOp == MulMacroOp::MulAntisymConj1)          return MulMacroOp::MulAntisym;
    else if constexpr (MulOp == MulMacroOp::MulAntisymConj1Conj2)     return MulMacroOp::MulAntisymConj2;
    else if constexpr (MulOp == MulMacroOp::NegMulAntisymConj1)       return MulMacroOp::NegMulAntisym;
    else if constexpr (MulOp == MulMacroOp::NegMulAntisymConj1Conj2)  return MulMacroOp::NegMulAntisymConj2;

    else if constexpr (MulOp == MulMacroOp::Add_MulConj1)             return MulMacroOp::Add_Mul;
    else if constexpr (MulOp == MulMacroOp::Add_MulConj1Conj2)        return MulMacroOp::Add_MulConj2;
    else if constexpr (MulOp == MulMacroOp::Sub_MulConj1)             return MulMacroOp::Sub_Mul;
    else if constexpr (MulOp == MulMacroOp::Sub_MulConj1Conj2)        return MulMacroOp::Sub_MulConj2;

    else if constexpr (MulOp == MulMacroOp::Add_MulSymConj1)          return MulMacroOp::Add_MulSym;
    else if constexpr (MulOp == MulMacroOp::Add_MulSymConj1Conj2)     return MulMacroOp::Add_MulSymConj2;
    else if constexpr (MulOp == MulMacroOp::Sub_MulSymConj1)          return MulMacroOp::Sub_MulSym;
    else if constexpr (MulOp == MulMacroOp::Sub_MulSymConj1Conj2)     return MulMacroOp::Sub_MulSymConj2;

    else if constexpr (MulOp == MulMacroOp::Add_MulAntisymConj1)      return MulMacroOp::Add_MulAntisym;
    else if constexpr (MulOp == MulMacroOp::Add_MulAntisymConj1Conj2) return MulMacroOp::Add_MulAntisymConj2;
    else if constexpr (MulOp == MulMacroOp::Sub_MulAntisymConj1)      return MulMacroOp::Sub_MulAntisym;
    else if constexpr (MulOp == MulMacroOp::Sub_MulAntisymConj1Conj2) return MulMacroOp::Sub_MulAntisymConj2;

#elif __AIE_ARCH__ == 20
    if      constexpr (MulOp == MulMacroOp::MulConj1)                 return MulMacroOp::Mul;
    else if constexpr (MulOp == MulMacroOp::MulConj1Conj2)            return MulMacroOp::MulConj2;
    else if constexpr (MulOp == MulMacroOp::NegMulConj1)              return MulMacroOp::NegMul;
    else if constexpr (MulOp == MulMacroOp::NegMulConj1Conj2)         return MulMacroOp::NegMulConj2;

    else if constexpr (MulOp == MulMacroOp::Add_MulConj1)             return MulMacroOp::Add_Mul;
    else if constexpr (MulOp == MulMacroOp::Add_MulConj1Conj2)        return MulMacroOp::Add_MulConj2;
    else if constexpr (MulOp == MulMacroOp::Sub_MulConj1)             return MulMacroOp::Sub_Mul;
    else if constexpr (MulOp == MulMacroOp::Sub_MulConj1Conj2)        return MulMacroOp::Sub_MulConj2;
#endif
    else                                                              return MulOp;
};

template <MulMacroOp MulOp>
static constexpr MulMacroOp remove_conj2()
{
#if __AIE_ARCH__ == 10
    if      constexpr (MulOp == MulMacroOp::MulAbs1Conj2)             return MulMacroOp::MulAbs1;
    else if constexpr (MulOp == MulMacroOp::MulConj1Conj2)            return MulMacroOp::MulConj1;
    else if constexpr (MulOp == MulMacroOp::MulConj2)                 return MulMacroOp::Mul;
    else if constexpr (MulOp == MulMacroOp::NegMulAbs1Conj2)          return MulMacroOp::NegMulAbs1;
    else if constexpr (MulOp == MulMacroOp::NegMulConj1Conj2)         return MulMacroOp::NegMulConj1;
    else if constexpr (MulOp == MulMacroOp::NegMulConj2)              return MulMacroOp::NegMul;

    else if constexpr (MulOp == MulMacroOp::MulSymConj1Conj2)         return MulMacroOp::MulSymConj1;
    else if constexpr (MulOp == MulMacroOp::MulSymConj2)              return MulMacroOp::MulSym;
    else if constexpr (MulOp == MulMacroOp::NegMulSymConj1Conj2)      return MulMacroOp::NegMulSymConj1;
    else if constexpr (MulOp == MulMacroOp::NegMulSymConj2)           return MulMacroOp::NegMulSym;

    else if constexpr (MulOp == MulMacroOp::MulAntisymConj1Conj2)     return MulMacroOp::MulAntisymConj1;
    else if constexpr (MulOp == MulMacroOp::MulAntisymConj2)          return MulMacroOp::MulAntisym;
    else if constexpr (MulOp == MulMacroOp::NegMulAntisymConj1Conj2)  return MulMacroOp::NegMulAntisymConj1;
    else if constexpr (MulOp == MulMacroOp::NegMulAntisymConj2)       return MulMacroOp::NegMulAntisym;

    else if constexpr (MulOp == MulMacroOp::Add_MulAbs1Conj2)         return MulMacroOp::Add_MulAbs1;
    else if constexpr (MulOp == MulMacroOp::Add_MulConj1Conj2)        return MulMacroOp::Add_MulConj1;
    else if constexpr (MulOp == MulMacroOp::Add_MulConj2)             return MulMacroOp::Add_Mul;
    else if constexpr (MulOp == MulMacroOp::Sub_MulAbs1Conj2)         return MulMacroOp::Sub_MulAbs1;
    else if constexpr (MulOp == MulMacroOp::Sub_MulConj1Conj2)        return MulMacroOp::Sub_MulConj1;
    else if constexpr (MulOp == MulMacroOp::Sub_MulConj2)             return MulMacroOp::Sub_Mul;

    else if constexpr (MulOp == MulMacroOp::Add_MulSymConj1Conj2)     return MulMacroOp::Add_MulSymConj1;
    else if constexpr (MulOp == MulMacroOp::Add_MulSymConj2)          return MulMacroOp::Add_MulSym;
    else if constexpr (MulOp == MulMacroOp::Sub_MulSymConj1Conj2)     return MulMacroOp::Sub_MulSymConj1;
    else if constexpr (MulOp == MulMacroOp::Sub_MulSymConj2)          return MulMacroOp::Sub_MulSym;

    else if constexpr (MulOp == MulMacroOp::Add_MulAntisymConj1Conj2) return MulMacroOp::Add_MulAntisymConj1;
    else if constexpr (MulOp == MulMacroOp::Add_MulAntisymConj2)      return MulMacroOp::Add_MulAntisym;
    else if constexpr (MulOp == MulMacroOp::Sub_MulAntisymConj1Conj2) return MulMacroOp::Sub_MulAntisymConj1;
    else if constexpr (MulOp == MulMacroOp::Sub_MulAntisymConj2)      return MulMacroOp::Sub_MulAntisym;

#elif __AIE_ARCH__ == 20
    if      constexpr (MulOp == MulMacroOp::MulConj1Conj2)            return MulMacroOp::MulConj1;
    else if constexpr (MulOp == MulMacroOp::MulConj2)                 return MulMacroOp::Mul;
    else if constexpr (MulOp == MulMacroOp::NegMulConj1Conj2)         return MulMacroOp::NegMulConj1;
    else if constexpr (MulOp == MulMacroOp::NegMulConj2)              return MulMacroOp::NegMul;

    else if constexpr (MulOp == MulMacroOp::Add_MulConj1Conj2)        return MulMacroOp::Add_MulConj1;
    else if constexpr (MulOp == MulMacroOp::Add_MulConj2)             return MulMacroOp::Add_Mul;
    else if constexpr (MulOp == MulMacroOp::Sub_MulConj1Conj2)        return MulMacroOp::Sub_MulConj1;
    else if constexpr (MulOp == MulMacroOp::Sub_MulConj2)             return MulMacroOp::Sub_Mul;
#endif
    else                                                              return MulOp;
};

template <MulMacroOp Op>
constexpr bool has_abs()
{
#if __AIE_ARCH__ == 10
    return (Op == MulMacroOp::MulAbs1          ||
            Op == MulMacroOp::MulAbs1Conj2     ||
            Op == MulMacroOp::NegMulAbs1       ||
            Op == MulMacroOp::NegMulAbs1Conj2  ||
            Op == MulMacroOp::Add_MulAbs1      ||
            Op == MulMacroOp::Add_MulAbs1Conj2 ||
            Op == MulMacroOp::Sub_MulAbs1      ||
            Op == MulMacroOp::Sub_MulAbs1Conj2);
#elif __AIE_ARCH__ == 20
    return false;
#endif
}

template <MulMacroOp Op>
constexpr bool has_conj1()
{
#if __AIE_ARCH__ == 10
    return (Op == MulMacroOp::MulConj1                 ||
            Op == MulMacroOp::MulConj1Conj2            ||
            Op == MulMacroOp::NegMulConj1              ||
            Op == MulMacroOp::NegMulConj1Conj2         ||
            Op == MulMacroOp::MulSymConj1              ||
            Op == MulMacroOp::MulSymConj1Conj2         ||
            Op == MulMacroOp::NegMulSymConj1           ||
            Op == MulMacroOp::NegMulSymConj1Conj2      ||
            Op == MulMacroOp::MulAntisymConj1          ||
            Op == MulMacroOp::MulAntisymConj1Conj2     ||
            Op == MulMacroOp::NegMulAntisymConj1       ||
            Op == MulMacroOp::NegMulAntisymConj1Conj2  ||
            Op == MulMacroOp::Add_MulConj1             ||
            Op == MulMacroOp::Add_MulConj1Conj2        ||
            Op == MulMacroOp::Add_MulSymConj1          ||
            Op == MulMacroOp::Add_MulSymConj1Conj2     ||
            Op == MulMacroOp::Add_MulAntisymConj1      ||
            Op == MulMacroOp::Add_MulAntisymConj1Conj2 ||
            Op == MulMacroOp::Sub_MulConj1             ||
            Op == MulMacroOp::Sub_MulConj1Conj2)       ||
            Op == MulMacroOp::Sub_MulSymConj1          ||
            Op == MulMacroOp::Sub_MulSymConj1Conj2     ||
            Op == MulMacroOp::Sub_MulAntisymConj1      ||
            Op == MulMacroOp::Sub_MulAntisymConj1Conj2;
#elif __AIE_ARCH__ == 20
    return (Op == MulMacroOp::MulConj1          ||
            Op == MulMacroOp::MulConj1Conj2     ||
            Op == MulMacroOp::NegMulConj1       ||
            Op == MulMacroOp::NegMulConj1Conj2  ||
            Op == MulMacroOp::Add_MulConj1      ||
            Op == MulMacroOp::Add_MulConj1Conj2 ||
            Op == MulMacroOp::Sub_MulConj1      ||
            Op == MulMacroOp::Sub_MulConj1Conj2);
#endif
}

template <MulMacroOp Op>
constexpr bool has_conj2()
{
#if __AIE_ARCH__ == 10
    return (Op == MulMacroOp::MulConj2                 ||
            Op == MulMacroOp::MulConj1Conj2            ||
            Op == MulMacroOp::NegMulConj2              ||
            Op == MulMacroOp::NegMulConj1Conj2         ||
            Op == MulMacroOp::MulSymConj2              ||
            Op == MulMacroOp::MulSymConj1Conj2         ||
            Op == MulMacroOp::NegMulSymConj2           ||
            Op == MulMacroOp::NegMulSymConj1Conj2      ||
            Op == MulMacroOp::MulAntisymConj2          ||
            Op == MulMacroOp::MulAntisymConj1Conj2     ||
            Op == MulMacroOp::NegMulAntisymConj2       ||
            Op == MulMacroOp::NegMulAntisymConj1Conj2  ||
            Op == MulMacroOp::Add_MulConj2             ||
            Op == MulMacroOp::Add_MulConj1Conj2        ||
            Op == MulMacroOp::Add_MulSymConj2          ||
            Op == MulMacroOp::Add_MulSymConj1Conj2     ||
            Op == MulMacroOp::Add_MulAntisymConj2      ||
            Op == MulMacroOp::Add_MulAntisymConj1Conj2 ||
            Op == MulMacroOp::Sub_MulConj2             ||
            Op == MulMacroOp::Sub_MulConj1Conj2)       ||
            Op == MulMacroOp::Sub_MulSymConj2          ||
            Op == MulMacroOp::Sub_MulSymConj1Conj2     ||
            Op == MulMacroOp::Sub_MulAntisymConj2      ||
            Op == MulMacroOp::Sub_MulAntisymConj1Conj2;
#elif __AIE_ARCH__ == 20
    return (Op == MulMacroOp::MulConj2          ||
            Op == MulMacroOp::MulConj1Conj2     ||
            Op == MulMacroOp::NegMulConj2       ||
            Op == MulMacroOp::NegMulConj1Conj2  ||
            Op == MulMacroOp::Add_MulConj2      ||
            Op == MulMacroOp::Add_MulConj1Conj2 ||
            Op == MulMacroOp::Sub_MulConj2      ||
            Op == MulMacroOp::Sub_MulConj1Conj2);
#endif
}

template <Operation Op1, Operation Op2>
constexpr MulMacroOp to_mul_macro_op()
{
#if __AIE_ARCH__ == 10
    if      constexpr (Op1 == Operation::Abs  && Op2 == Operation::None) return MulMacroOp::MulAbs1;
    else if constexpr (Op1 == Operation::Abs  && Op2 == Operation::Conj) return MulMacroOp::MulAbs1Conj2;
    else if constexpr (Op1 == Operation::Conj && Op2 == Operation::None) return MulMacroOp::MulConj1;
    else if constexpr (Op1 == Operation::Conj && Op2 == Operation::Conj) return MulMacroOp::MulConj1Conj2;
    else if constexpr (Op1 == Operation::Min  && Op2 == Operation::None) return MulMacroOp::MulMin;
    else if constexpr (Op1 == Operation::Max  && Op2 == Operation::None) return MulMacroOp::MulMax;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::Conj) return MulMacroOp::MulConj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::None) return MulMacroOp::Mul;
#elif __AIE_ARCH__ == 20
    static_assert(Op1 == Operation::None || Op1 == Operation::Conj);
    static_assert(Op2 == Operation::None || Op2 == Operation::Conj);

    if      constexpr (Op1 == Operation::Conj && Op2 == Operation::None) return MulMacroOp::MulConj1;
    else if constexpr (Op1 == Operation::Conj && Op2 == Operation::Conj) return MulMacroOp::MulConj1Conj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::Conj) return MulMacroOp::MulConj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::None) return MulMacroOp::Mul;
#endif
}

template <Operation AccOp, Operation Op1, Operation Op2>
constexpr MulMacroOp to_mul_macro_op()
{
#if __AIE_ARCH__ == 10
    if      constexpr (Op1 == Operation::Abs  && Op2 == Operation::None) return (AccOp == Operation::Acc_Add)? MulMacroOp::Add_MulAbs1       : MulMacroOp::Sub_MulAbs1;
    else if constexpr (Op1 == Operation::Abs  && Op2 == Operation::Conj) return (AccOp == Operation::Acc_Add)? MulMacroOp::Add_MulAbs1Conj2  : MulMacroOp::Sub_MulAbs1Conj2;
    else if constexpr (Op1 == Operation::Conj && Op2 == Operation::None) return (AccOp == Operation::Acc_Add)? MulMacroOp::Add_MulConj1      : MulMacroOp::Sub_MulConj1;
    else if constexpr (Op1 == Operation::Conj && Op2 == Operation::Conj) return (AccOp == Operation::Acc_Add)? MulMacroOp::Add_MulConj1Conj2 : MulMacroOp::Sub_MulConj1Conj2;
    else if constexpr (Op1 == Operation::Min  && Op2 == Operation::None) return (AccOp == Operation::Acc_Add)? MulMacroOp::Add_MulMin        : MulMacroOp::Sub_MulMin;
    else if constexpr (Op1 == Operation::Max  && Op2 == Operation::None) return (AccOp == Operation::Acc_Add)? MulMacroOp::Add_MulMax        : MulMacroOp::Sub_MulMax;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::Conj) return (AccOp == Operation::Acc_Add)? MulMacroOp::Add_MulConj2      : MulMacroOp::Sub_MulConj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::None) return (AccOp == Operation::Acc_Add)? MulMacroOp::Add_Mul           : MulMacroOp::Sub_Mul;
#elif __AIE_ARCH__ == 20
    static_assert(Op1 == Operation::None || Op1 == Operation::Conj);
    static_assert(Op2 == Operation::None || Op2 == Operation::Conj);

    if      constexpr (Op1 == Operation::Conj && Op2 == Operation::None) return (AccOp == Operation::Acc_Add)? MulMacroOp::Add_MulConj1      : MulMacroOp::Sub_MulConj1;
    else if constexpr (Op1 == Operation::Conj && Op2 == Operation::Conj) return (AccOp == Operation::Acc_Add)? MulMacroOp::Add_MulConj1Conj2 : MulMacroOp::Sub_MulConj1Conj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::Conj) return (AccOp == Operation::Acc_Add)? MulMacroOp::Add_MulConj2      : MulMacroOp::Sub_MulConj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::None) return (AccOp == Operation::Acc_Add)? MulMacroOp::Add_Mul           : MulMacroOp::Sub_Mul;
#endif
}

template <Operation Op1, Operation Op2>
constexpr MulMacroOp to_mul_sym_macro_op()
{
#if __AIE_ARCH__ == 10
    if      constexpr (Op1 == Operation::Conj && Op2 == Operation::None) return MulMacroOp::MulSymConj1;
    else if constexpr (Op1 == Operation::Conj && Op2 == Operation::Conj) return MulMacroOp::MulSymConj1Conj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::Conj) return MulMacroOp::MulSymConj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::None) return MulMacroOp::MulSym;
#else
    UNREACHABLE_MSG("Not supported in the current architecture");
    return MulMacroOp::Unavailable;
#endif
}

template <Operation AccOp, Operation Op1, Operation Op2>
constexpr MulMacroOp to_mul_sym_macro_op()
{
#if __AIE_ARCH__ == 10
    if      constexpr (Op1 == Operation::Conj && Op2 == Operation::None) return (AccOp == Operation::Acc_Add)? MulMacroOp::Add_MulSymConj1      : MulMacroOp::Sub_MulSymConj1;
    else if constexpr (Op1 == Operation::Conj && Op2 == Operation::Conj) return (AccOp == Operation::Acc_Add)? MulMacroOp::Add_MulSymConj1Conj2 : MulMacroOp::Sub_MulSymConj1Conj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::Conj) return (AccOp == Operation::Acc_Add)? MulMacroOp::Add_MulSymConj2      : MulMacroOp::Sub_MulSymConj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::None) return (AccOp == Operation::Acc_Add)? MulMacroOp::Add_MulSym           : MulMacroOp::Sub_MulSym;
#else
    UNREACHABLE_MSG("Not supported in the current architecture");
    return MulMacroOp::Unavailable;
#endif
}

template <Operation Op1, Operation Op2>
constexpr MulMacroOp to_mul_antisym_macro_op()
{
#if __AIE_ARCH__ == 10
    if      constexpr (Op1 == Operation::Conj && Op2 == Operation::None) return MulMacroOp::MulAntisymConj1;
    else if constexpr (Op1 == Operation::Conj && Op2 == Operation::Conj) return MulMacroOp::MulAntisymConj1Conj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::Conj) return MulMacroOp::MulAntisymConj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::None) return MulMacroOp::MulAntisym;
#else
    UNREACHABLE_MSG("Not supported in the current architecture");
    return MulMacroOp::Unavailable;
#endif
}

template <Operation AccOp, Operation Op1, Operation Op2>
constexpr MulMacroOp to_mul_antisym_macro_op()
{
#if __AIE_ARCH__ == 10
    if      constexpr (Op1 == Operation::Conj && Op2 == Operation::None) return (AccOp == Operation::Acc_Add)? MulMacroOp::Add_MulAntisymConj1      : MulMacroOp::Sub_MulAntisymConj1;
    else if constexpr (Op1 == Operation::Conj && Op2 == Operation::Conj) return (AccOp == Operation::Acc_Add)? MulMacroOp::Add_MulAntisymConj1Conj2 : MulMacroOp::Sub_MulAntisymConj1Conj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::Conj) return (AccOp == Operation::Acc_Add)? MulMacroOp::Add_MulAntisymConj2      : MulMacroOp::Sub_MulAntisymConj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::None) return (AccOp == Operation::Acc_Add)? MulMacroOp::Add_MulAntisym           : MulMacroOp::Sub_MulAntisym;
#else
    UNREACHABLE_MSG("Not supported in the current architecture");
    return MulMacroOp::Unavailable;
#endif
}

template <Operation Op1, Operation Op2>
constexpr MulMacroOp to_negmul_macro_op()
{
#if __AIE_ARCH__ == 10
    if      constexpr (Op1 == Operation::Abs  && Op2 == Operation::None) return MulMacroOp::NegMulAbs1;
    else if constexpr (Op1 == Operation::Abs  && Op2 == Operation::Conj) return MulMacroOp::NegMulAbs1Conj2;
    else if constexpr (Op1 == Operation::Conj && Op2 == Operation::None) return MulMacroOp::NegMulConj1;
    else if constexpr (Op1 == Operation::Conj && Op2 == Operation::Conj) return MulMacroOp::NegMulConj1Conj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::Conj) return MulMacroOp::NegMulConj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::None) return MulMacroOp::NegMul;
#elif __AIE_ARCH__ == 20
    static_assert(Op1 == Operation::None || Op1 == Operation::Conj);
    static_assert(Op2 == Operation::None || Op2 == Operation::Conj);

    if      constexpr (Op1 == Operation::Conj && Op2 == Operation::None) return MulMacroOp::NegMulConj1;
    else if constexpr (Op1 == Operation::Conj && Op2 == Operation::Conj) return MulMacroOp::NegMulConj1Conj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::Conj) return MulMacroOp::NegMulConj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::None) return MulMacroOp::NegMul;
#endif
}

template <Operation Op1, Operation Op2>
constexpr MulMacroOp to_negmul_sym_macro_op()
{
#if __AIE_ARCH__ == 10
    if      constexpr (Op1 == Operation::Conj && Op2 == Operation::None) return MulMacroOp::NegMulSymConj1;
    else if constexpr (Op1 == Operation::Conj && Op2 == Operation::Conj) return MulMacroOp::NegMulSymConj1Conj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::Conj) return MulMacroOp::NegMulSymConj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::None) return MulMacroOp::NegMulSym;
#else
    UNREACHABLE_MSG("Not supported in the current architecture");
    return MulMacroOp::Unavailable;
#endif
}

template <Operation Op1, Operation Op2>
constexpr MulMacroOp to_negmul_antisym_macro_op()
{
#if __AIE_ARCH__ == 10
    if      constexpr (Op1 == Operation::Conj && Op2 == Operation::None) return MulMacroOp::NegMulAntisymConj1;
    else if constexpr (Op1 == Operation::Conj && Op2 == Operation::Conj) return MulMacroOp::NegMulAntisymConj1Conj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::Conj) return MulMacroOp::NegMulAntisymConj2;
    else if constexpr (Op1 == Operation::None && Op2 == Operation::None) return MulMacroOp::NegMulAntisym;
#else
    UNREACHABLE_MSG("Not supported in the current architecture");
    return MulMacroOp::Unavailable;
#endif
}

template <MulMacroOp Op>
constexpr MulMacroOp add_to_op()
{
    if      constexpr (Op == MulMacroOp::Mul                     || Op == MulMacroOp::Add_Mul)                  return MulMacroOp::Add_Mul;
    else if constexpr (Op == MulMacroOp::NegMul                  || Op == MulMacroOp::Add_NegMul)               return MulMacroOp::Add_NegMul;
#if __AIE_ARCH__ == 10
    else if constexpr (Op == MulMacroOp::MulSym                  || Op == MulMacroOp::Add_MulSym)               return MulMacroOp::Add_MulSym;
    else if constexpr (Op == MulMacroOp::NegMulSym               || Op == MulMacroOp::Add_NegMulSym)            return MulMacroOp::Add_NegMulSym;
    else if constexpr (Op == MulMacroOp::MulAntisym              || Op == MulMacroOp::Add_MulAntisym)           return MulMacroOp::Add_MulAntisym;
    else if constexpr (Op == MulMacroOp::NegMulAntisym           || Op == MulMacroOp::Add_NegMulAntisym)        return MulMacroOp::Add_NegMulAntisym;
    else if constexpr (Op == MulMacroOp::MulAbs1                 || Op == MulMacroOp::Add_MulAbs1)              return MulMacroOp::Add_MulAbs1;
    else if constexpr (Op == MulMacroOp::MulAbs1Conj2            || Op == MulMacroOp::Add_MulAbs1Conj2)         return MulMacroOp::Add_MulAbs1Conj2;
    else if constexpr (Op == MulMacroOp::MulConj1                || Op == MulMacroOp::Add_MulConj1)             return MulMacroOp::Add_MulConj1;
    else if constexpr (Op == MulMacroOp::MulConj2                || Op == MulMacroOp::Add_MulConj2)             return MulMacroOp::Add_MulConj2;
    else if constexpr (Op == MulMacroOp::MulConj1Conj2           || Op == MulMacroOp::Add_MulConj1Conj2)        return MulMacroOp::Add_MulConj1Conj2;
    else if constexpr (Op == MulMacroOp::MulSymConj1             || Op == MulMacroOp::Add_MulSymConj1)          return MulMacroOp::Add_MulSymConj1;
    else if constexpr (Op == MulMacroOp::MulSymConj2             || Op == MulMacroOp::Add_MulSymConj2)          return MulMacroOp::Add_MulSymConj2;
    else if constexpr (Op == MulMacroOp::MulSymConj1Conj2        || Op == MulMacroOp::Add_MulSymConj1Conj2)     return MulMacroOp::Add_MulSymConj1Conj2;
    else if constexpr (Op == MulMacroOp::MulAntisymConj1         || Op == MulMacroOp::Add_MulAntisymConj1)      return MulMacroOp::Add_MulAntisymConj1;
    else if constexpr (Op == MulMacroOp::MulAntisymConj2         || Op == MulMacroOp::Add_MulAntisymConj2)      return MulMacroOp::Add_MulAntisymConj2;
    else if constexpr (Op == MulMacroOp::MulAntisymConj1Conj2    || Op == MulMacroOp::Add_MulAntisymConj1Conj2) return MulMacroOp::Add_MulAntisymConj1Conj2;
    else if constexpr (Op == MulMacroOp::NegMulAbs1              || Op == MulMacroOp::Sub_MulAbs1)              return MulMacroOp::Sub_MulAbs1;
    else if constexpr (Op == MulMacroOp::NegMulAbs1Conj2         || Op == MulMacroOp::Sub_MulAbs1Conj2)         return MulMacroOp::Sub_MulAbs1Conj2;
    else if constexpr (Op == MulMacroOp::NegMulConj1             || Op == MulMacroOp::Sub_MulConj1)             return MulMacroOp::Sub_MulConj1;
    else if constexpr (Op == MulMacroOp::NegMulConj2             || Op == MulMacroOp::Sub_MulConj2)             return MulMacroOp::Sub_MulConj2;
    else if constexpr (Op == MulMacroOp::NegMulConj1Conj2        || Op == MulMacroOp::Sub_MulConj1Conj2)        return MulMacroOp::Sub_MulConj1Conj2;
    else if constexpr (Op == MulMacroOp::NegMulSymConj1          || Op == MulMacroOp::Sub_MulSymConj1)          return MulMacroOp::Sub_MulSymConj1;
    else if constexpr (Op == MulMacroOp::NegMulSymConj2          || Op == MulMacroOp::Sub_MulSymConj2)          return MulMacroOp::Sub_MulSymConj2;
    else if constexpr (Op == MulMacroOp::NegMulSymConj1Conj2     || Op == MulMacroOp::Sub_MulSymConj1Conj2)     return MulMacroOp::Sub_MulSymConj1Conj2;
    else if constexpr (Op == MulMacroOp::NegMulAntisymConj1      || Op == MulMacroOp::Sub_MulAntisymConj1)      return MulMacroOp::Sub_MulAntisymConj1;
    else if constexpr (Op == MulMacroOp::NegMulAntisymConj2      || Op == MulMacroOp::Sub_MulAntisymConj2)      return MulMacroOp::Sub_MulAntisymConj2;
    else if constexpr (Op == MulMacroOp::NegMulAntisymConj1Conj2 || Op == MulMacroOp::Sub_MulAntisymConj1Conj2) return MulMacroOp::Sub_MulAntisymConj1Conj2;
    else if constexpr (Op == MulMacroOp::MulMax                  || Op == MulMacroOp::Add_MulMax)               return MulMacroOp::Add_MulMax;
    else if constexpr (Op == MulMacroOp::MulMin                  || Op == MulMacroOp::Add_MulMin)               return MulMacroOp::Add_MulMin;
#elif __AIE_ARCH__ == 20
    else if constexpr (Op == MulMacroOp::MulConj1                || Op == MulMacroOp::Add_MulConj1)             return MulMacroOp::Add_MulConj1;
    else if constexpr (Op == MulMacroOp::MulConj2                || Op == MulMacroOp::Add_MulConj2)             return MulMacroOp::Add_MulConj2;
    else if constexpr (Op == MulMacroOp::MulConj1Conj2           || Op == MulMacroOp::Add_MulConj1Conj2)        return MulMacroOp::Add_MulConj1Conj2;
    else if constexpr (Op == MulMacroOp::NegMulConj1             || Op == MulMacroOp::Sub_MulConj1)             return MulMacroOp::Sub_MulConj1;
    else if constexpr (Op == MulMacroOp::NegMulConj2             || Op == MulMacroOp::Sub_MulConj2)             return MulMacroOp::Sub_MulConj2;
    else if constexpr (Op == MulMacroOp::NegMulConj1Conj2        || Op == MulMacroOp::Sub_MulConj1Conj2)        return MulMacroOp::Sub_MulConj1Conj2;
#endif
}

#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
template <MulMacroOp MulOp>
static constexpr auto get_scalar_mul_op()
{
    if constexpr (MulOp == MulMacroOp::Mul)
        return [](const auto &a, const auto &b) { return a * b; };
    else if constexpr (MulOp == MulMacroOp::NegMul)
        return [](const auto &a, const auto &b) { return -(a * b); };
    else if constexpr (MulOp == MulMacroOp::Add_Mul)
        return [](const auto &a, const auto &b, const auto &acc) { return acc + a * b; };
    else if constexpr (MulOp == MulMacroOp::Add_NegMul || MulOp == MulMacroOp::Sub_Mul)
        return [](const auto &a, const auto &b, const auto &acc) { return acc -(a * b); };
#if __AIE_ARCH__ == 10
    else if constexpr (MulOp == MulMacroOp::MulAbs1)
        return [](const auto &a, const auto &b)                    { return std::abs(a) * b; };
    else if constexpr (MulOp == MulMacroOp::MulAbs1Conj2)
        return [](const auto &a, const auto &_b)                   { auto b = { _b.real, (decltype(_b.imag))-_b.imag }; return std::abs(a) * b; };
    else if constexpr (MulOp == MulMacroOp::MulConj1)
        return [](const auto &_a, const auto &b)                   { auto a = { _a.real, (decltype(_a.imag))-_a.imag }; return a * b; };
    else if constexpr (MulOp == MulMacroOp::MulConj1Conj2)
        return [](const auto &_a, const auto &_b)                  { auto a = { _a.real, (decltype(_a.imag))-_a.imag }; auto b = { _b.real, (decltype(_b.imag))-_b.imag }; return a * b; };
    else if constexpr (MulOp == MulMacroOp::NegMulAbs1)
        return [](const auto &a, const auto &b)                    { return -(std::abs(a) * b); };
    else if constexpr (MulOp == MulMacroOp::NegMulAbs1Conj2)
        return [](const auto &a, const auto &_b)                   { auto b = { _b.real, (decltype(_b.imag))-_b.imag }; return -(std::abs(a) * b); };
    else if constexpr (MulOp == MulMacroOp::NegMulConj1)
        return [](const auto &_a, const auto &b)                   { auto a = { _a.real, (decltype(_a.imag))-_a.imag }; return -(a * b); };
    else if constexpr (MulOp == MulMacroOp::MulConj1Conj2)
        return [](const auto &_a, const auto &_b)                  { auto a = { _a.real, (decltype(_a.imag))-_a.imag }; auto b = { _b.real, (decltype(_b.imag))-_b.imag }; return -(a * b); };
    else if constexpr (MulOp == MulMacroOp::MulMax)
        return [](const auto &a, const auto &m1, const auto &m2)   { return a * std::max(m1, m2); };
    else if constexpr (MulOp == MulMacroOp::MulMin)
        return [](const auto &a, const auto &m1, const auto &m2)   { return a * std::min(m1, m2); };
    else if constexpr (MulOp == MulMacroOp::Add_MulAbs1)
        return [](const auto &a, const auto &b, const auto &acc)   { return acc + std::abs(a) * b; };
    else if constexpr (MulOp == MulMacroOp::Add_MulAbs1Conj2)
        return [](const auto &a, const auto &_b, const auto &acc)  { auto b = { _b.real, (decltype(_b.imag))-_b.imag }; return acc + std::abs(a) * b; };
    else if constexpr (MulOp == MulMacroOp::Add_MulConj1)
        return [](const auto &_a, const auto &b, const auto &acc)  { auto a = { _a.real, (decltype(_a.imag))-_a.imag }; return acc + a * b; };
    else if constexpr (MulOp == MulMacroOp::Add_MulConj1Conj2)
        return [](const auto &_a, const auto &_b, const auto &acc) { auto a = { _a.real, (decltype(_a.imag))-_a.imag }; auto b = { _b.real, (decltype(_b.imag))-_b.imag }; return acc + a * b; };
    else if constexpr (MulOp == MulMacroOp::Sub_MulAbs1)
        return [](const auto &a, const auto &b, const auto &acc)  { return acc -(std::abs(a) * b); };
    else if constexpr (MulOp == MulMacroOp::Sub_MulAbs1Conj2)
        return [](const auto &a, const auto &_b, const auto &acc)  { auto b = { _b.real, (decltype(_b.imag))-_b.imag }; return acc - std::abs(a) * b; };
    else if constexpr (MulOp == MulMacroOp::Sub_MulConj1)
        return [](const auto &_a, const auto &b, const auto &acc)  { auto a = { _a.real, (decltype(_a.imag))-_a.imag }; return acc - a * b; };
    else if constexpr (MulOp == MulMacroOp::Sub_MulConj1Conj2)
        return [](const auto &_a, const auto &_b, const auto &acc) { auto a = { _a.real, (decltype(_a.imag))-_a.imag }; auto b = { _b.real, (decltype(_b.imag))-_b.imag }; return acc - a * b; };
    else if constexpr (MulOp == MulMacroOp::Add_MulMax)
        return [](const auto &m1, const auto &m2, const auto &a, const auto &acc) { return acc - a * std::max(m1, m2); };
    else if constexpr (MulOp == MulMacroOp::Sub_MulMax)
        return [](const auto &m1, const auto &m2, const auto &a, const auto &acc) { return acc + a * std::max(m1, m2); };
    else if constexpr (MulOp == MulMacroOp::Add_MulMin)
        return [](const auto &m1, const auto &m2, const auto &a, const auto &acc) { return acc - a * std::min(m1, m2); };
    else if constexpr (MulOp == MulMacroOp::Sub_MulMin)
        return [](const auto &m1, const auto &m2, const auto &a, const auto &acc) { return acc + a * std::min(m1, m2); };
#elif __AIE_ARCH__ == 20
    else if constexpr (MulOp == MulMacroOp::MulConj1)
        return [](const auto &_a, const auto &b)                   { auto a = { _a.real, (decltype(_a.imag))-_a.imag }; return a * b; };
    else if constexpr (MulOp == MulMacroOp::MulConj1Conj2)
        return [](const auto &_a, const auto &_b)                  { auto a = { _a.real, (decltype(_a.imag))-_a.imag }; auto b = { _b.real, (decltype(_b.imag))-_b.imag }; return a * b; };
    else if constexpr (MulOp == MulMacroOp::NegMulConj1)
        return [](const auto &_a, const auto &b)                   { auto a = { _a.real, (decltype(_a.imag))-_a.imag }; return -(a * b); };
    else if constexpr (MulOp == MulMacroOp::MulConj1Conj2)
        return [](const auto &_a, const auto &_b)                  { auto a = { _a.real, (decltype(_a.imag))-_a.imag }; auto b = { _b.real, (decltype(_b.imag))-_b.imag }; return -(a * b); };
    else if constexpr (MulOp == MulMacroOp::Add_MulConj1)
        return [](const auto &_a, const auto &b, const auto &acc)  { auto a = { _a.real, (decltype(_a.imag))-_a.imag }; return acc + a * b; };
    else if constexpr (MulOp == MulMacroOp::Add_MulConj1Conj2)
        return [](const auto &_a, const auto &_b, const auto &acc) { auto a = { _a.real, (decltype(_a.imag))-_a.imag }; auto b = { _b.real, (decltype(_b.imag))-_b.imag }; return acc + a * b; };
    else if constexpr (MulOp == MulMacroOp::Sub_MulConj1)
        return [](const auto &_a, const auto &b, const auto &acc)  { auto a = { _a.real, (decltype(_a.imag))-_a.imag }; return acc - a * b; };
    else if constexpr (MulOp == MulMacroOp::Sub_MulConj1Conj2)
        return [](const auto &_a, const auto &_b, const auto &acc) { auto a = { _a.real, (decltype(_a.imag))-_a.imag }; auto b = { _b.real, (decltype(_b.imag))-_b.imag }; return acc - a * b; };
#endif
}
#endif

template <typename T>
__aie_inline
constexpr bool get_mul_sign(T v)
{
        if constexpr (is_op_v<T> && T::is_operation(Operation::Sign))
            return v.parent2();
        else
            return detail::is_signed_v<typename T::value_type>;
}

template <typename T>
__aie_inline
constexpr Operation evaluate_mul_operation()
{
    //TODO: Simplify based on evaluating on parent ops if parent isn't a vector
    if constexpr (T::is_operation(Operation::Sign))
        return Operation::None;
    else
        return T::operation;
}

template <MulMacroOp MulOp, unsigned AccumBits, unsigned Type1Bits, typename T1, unsigned Type2Bits, typename T2>
struct mul_bits_impl
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using    accum_tag = accum_tag_for_mul_types<T1, T2, AccumBits>;
    template <unsigned Elems>
    using   accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v1, bool v1_sign, const vector_type2<Elems> &v2, bool v2_sign, const Acc &... acc)
    {
        // Add subscript operator for accumulators
        accum_type<Elems> ret;
        auto mul_op = get_scalar_mul_op<MulOp>();

        for (unsigned i = 0; i < Elems; ++i)
            ret[i] = mul_op(v1[i], v2[i], acc...);

        return ret;
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(T1 a, bool a_sign, const vector_type2<Elems> &v, bool v_sign, const Acc &... acc)
    {
        accum_type<Elems> ret;
        auto mul_op = get_scalar_mul_op<MulOp>();

        for (unsigned i = 0; i < Elems; ++i)
            ret[i] = mul_op(a, v[i], acc...);

        return ret;
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<Elems> run(const vector_type1<Elems> &v, bool v_sign, T2 a, bool a_sign, const Acc &... acc)
    {
        accum_type<Elems> ret;
        auto mul_op = get_scalar_mul_op<MulOp>();

        for (unsigned i = 0; i < Elems; ++i)
            ret[i] = mul_op(v[i], a, acc...);

        return ret;
    }
#endif
};

template <MulMacroOp MulOp, unsigned AccumBits, unsigned Type1Bits, typename T1, unsigned Type2Bits, typename T2>
struct mul_maxmin_bits_impl
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;

    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    using    accum_tag = accum_tag_for_mul_types<T1, T2, AccumBits>;

    template <unsigned Elems>
    using   accum_type = accum<accum_tag, Elems>;

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    static auto run(const vector_type1<Elems> &m1,
                    const vector_type1<Elems> &m2,
                    const vector_type2<Elems> &v, const Acc &... acc)
    {
        // Add subscript operator for accumulators
        accum_type<Elems> ret;
        auto mul_op = get_scalar_mul_op<MulOp>();

        for (unsigned i = 0; i < Elems; ++i)
            ret[i] = mul_op(m1[i], m2[i], v[i], acc...);

        return ret;
    }
#endif
};

template <unsigned AccumBits, unsigned TypeBits, typename T, unsigned Elems>
struct mul_reduce_bits_impl
{
#ifdef __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__
    using vector_type = vector<T, Elems>;

    static T run(const vector_type &v)
    {
        T ret = v[0];

        for (unsigned i = 1; i < Elems; ++i)
            ret *= v[i];

        return ret;
    }
#endif
};

// TODO: do scalar implementation
template <unsigned OutElems, unsigned Points, int CoeffStep, int DataStepX, int DataStepY, unsigned AccumBits, unsigned CoeffTypeBits, unsigned DataTypeBits, typename CoeffType, typename DataType>
struct sliding_mul_bits_impl;

template <unsigned OutElems, unsigned Points, bool HasOddPoints, int CoeffStep, int DataStepX, int DataStepY, unsigned AccumBits, unsigned CoeffTypeBits, unsigned DataTypeBits, typename CoeffType, typename DataType>
struct sliding_mul_sym_bits_impl;

template <unsigned OutElems, unsigned Points, int CoeffStep, int DataStep, unsigned AccumBits, unsigned CoeffTypeBits, unsigned DataTypeBits, typename CoeffType, typename DataType>
struct sliding_mul_sym_uct_bits_impl;

template <unsigned OutElems, unsigned Points, unsigned Channels, int CoeffStep, int DataStepX, int DataStepY, unsigned AccumBits, unsigned CoeffTypeBits, unsigned DataTypeBits, typename CoeffType, typename DataType>
struct sliding_mul_ch_bits_impl;

template <MulMacroOp MulOp, unsigned AccumBits, unsigned Type1Bits, typename T1, unsigned Type2Bits, typename T2>
struct mul_bits
{
    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;
    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static auto run(const vector_type1<Elems> &v1, bool v1_sign, const vector_type2<Elems> &v2, bool v2_sign, const Acc &... acc)
    {
        return mul_bits_impl<MulOp, AccumBits, Type1Bits, T1, Type2Bits, T2>::run(v1, v1_sign, v2, v2_sign, acc...);
    }

    template <unsigned Elems, unsigned Elems2, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static auto run(vector_elem_const_ref<T1, Elems> a, bool a_sign, const vector_type2<Elems2> &v, bool v_sign, const Acc &... acc)
    {
        return mul_bits_impl<MulOp, AccumBits, Type1Bits, T1, Type2Bits, T2>::run(a, a_sign, v, v_sign, acc...);
    }

    template <unsigned Elems, unsigned Elems2, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static auto run(const vector_type1<Elems> &v, bool v_sign, vector_elem_const_ref<T2, Elems2> a, bool a_sign, const Acc &... acc)
    {
#if __AIE_ARCH__ == 10
        if (!chess_const(a.offset))
            return mul_bits_impl<MulOp, AccumBits, Type1Bits, T1, Type2Bits, T2>::run(v, v_sign, a.get(), a_sign, acc...);
        else
#endif
            return mul_bits_impl<MulOp, AccumBits, Type1Bits, T1, Type2Bits, T2>::run(v, v_sign, a, a_sign, acc...);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static auto run(const T1 &a, bool a_sign, const vector_type2<Elems> &v, bool v_sign, const Acc &... acc)
    {
        return mul_bits_impl<MulOp, AccumBits, Type1Bits, T1, Type2Bits, T2>::run(a, a_sign, v, v_sign, acc...);
    }

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static auto run(const vector_type1<Elems> &v, bool v_sign, const T2 &a, bool a_sign, const Acc &... acc)
    {
        return mul_bits_impl<MulOp, AccumBits, Type1Bits, T1, Type2Bits, T2>::run(v, v_sign, a, a_sign, acc...);
    }
};

template <MulMacroOp MulOp, unsigned AccumBits, unsigned Type1Bits, typename T1, unsigned Type2Bits, typename T2>
struct mul_maxmin_bits
{
    template <unsigned Elems>
    using vector_type1 = vector<T1, Elems>;
    template <unsigned Elems>
    using vector_type2 = vector<T2, Elems>;

    template <unsigned Elems, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static auto run(const vector_type1<Elems> &m1,
                    const vector_type1<Elems> &m2,
                    const vector_type2<Elems> &v, const Acc &... acc)
    {
        return mul_maxmin_bits_impl<MulOp, AccumBits, Type1Bits, T1, Type2Bits, T2>::run(m1, m2, v, acc...);
    }
};

template <unsigned AccumBits, unsigned TypeBits, typename T, unsigned Elems>
struct mul_reduce_bits
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static T run(const vector_type &v)
    {
        return mul_reduce_bits_impl<AccumBits, TypeBits, T, Elems>::run(v);
    }
};

template <unsigned OutElems, unsigned Points, int CoeffStep, int DataStepX, int DataStepY, unsigned AccumBits, unsigned CoeffTypeBits, unsigned DataTypeBits, typename CoeffType, typename DataType>
struct sliding_mul_bits
{
    using impl_type = sliding_mul_bits_impl<OutElems, Points, CoeffStep, DataStepX, DataStepY, AccumBits, CoeffTypeBits, DataTypeBits, CoeffType, DataType>;

    using  data_type = typename impl_type::data_type;
    using coeff_type = typename impl_type::coeff_type;
    using accum_type = typename impl_type::accum_type;

    static constexpr unsigned columns_per_mul = impl_type::columns_per_mul;
    static constexpr unsigned   lanes_per_mul = impl_type::lanes_per_mul;
    static constexpr unsigned         num_mul = impl_type::num_mul;
    static constexpr unsigned           lanes = OutElems;
    static constexpr unsigned          points = Points;

    template <MulMacroOp Op, unsigned N_Coeff, unsigned N_Data, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static auto run(const vector<CoeffType, N_Coeff> &coeff,
                    unsigned coeff_start,
                    bool coeff_sign,
                    const vector<DataType, N_Data> &data,
                    unsigned data_start,
                    bool data_sign,
                    const Acc &... acc)
    {
        REQUIRES_CONSTANT_MSG(coeff_start, "coeff_start must be a compile-time constant");

        return impl_type::template run<Op>(coeff, coeff_start, coeff_sign, data, data_start, data_sign, acc...);
    }
};

template <unsigned OutElems, unsigned Points, int CoeffStep, int DataStepX, int DataStepY, unsigned AccumBits, unsigned CoeffTypeBits, unsigned DataTypeBits, typename CoeffType, typename DataType>
struct sliding_mul_sym_bits
{
    using impl_type = sliding_mul_sym_bits_impl<OutElems, Points, (Points % 2) == 1, CoeffStep, DataStepX, DataStepY, AccumBits, CoeffTypeBits, DataTypeBits, CoeffType, DataType>;

    using  data_type = typename impl_type::data_type;
    using coeff_type = typename impl_type::coeff_type;
    using accum_type = typename impl_type::accum_type;

    static constexpr unsigned columns_per_mul = impl_type::columns_per_mul;
    static constexpr unsigned   lanes_per_mul = impl_type::lanes_per_mul;
    static constexpr unsigned         num_mul = impl_type::num_mul;
    static constexpr unsigned           lanes = OutElems;
    static constexpr unsigned          points = Points;

    template <MulMacroOp Op, unsigned N_Coeff, unsigned N_Data, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static auto run(const vector<CoeffType, N_Coeff> &coeff,
                    unsigned coeff_start,
                    const vector<DataType, N_Data> &data,
                    unsigned data_start,
                    const Acc &... acc)
    {
        REQUIRES_CONSTANT_MSG(coeff_start, "coeff_start must be a compile-time constant");

        if constexpr (Points % 2 == 0)
            return impl_type::template run<Op>(coeff, coeff_start, data, data_start, data_start + (Points - 1) * DataStepX, acc...);
        else
            return impl_type::template run<Op>(coeff, coeff_start, data, data_start,                                        acc...);
    }

    template <MulMacroOp Op, unsigned N_Coeff, unsigned N_Data, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static auto run(const vector<CoeffType, N_Coeff> &coeff,
                    unsigned coeff_start,
                    const vector<DataType, N_Data> &data,
                    unsigned ldata_start,
                    unsigned rdata_start,
                    const Acc &... acc)
    {
        REQUIRES_CONSTANT_MSG(coeff_start, "coeff_start must be a compile-time constant");

        return impl_type::template run<Op>(coeff, coeff_start, data, ldata_start, rdata_start, acc...);
    }

    template <MulMacroOp Op, unsigned N_Coeff, unsigned N_Data, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static auto run_2buff(const vector<CoeffType, N_Coeff> &coeff,
                          unsigned coeff_start,
                          const vector<DataType, N_Data> &ldata,
                          unsigned ldata_start,
                          const vector<DataType, N_Data> &rdata,
                          unsigned rdata_start,
                          const Acc &... acc)
    {
        REQUIRES_CONSTANT_MSG(coeff_start, "coeff_start must be a compile-time constant");

        return impl_type::template run<Op>(coeff, coeff_start, ldata, ldata_start, rdata, rdata_start, acc...);
    }
};

template <unsigned OutElems, unsigned Points, int CoeffStep, int DataStep, unsigned AccumBits, unsigned CoeffTypeBits, unsigned DataTypeBits, typename CoeffType, typename DataType>
struct sliding_mul_sym_uct_bits
{
    using impl_type = sliding_mul_sym_uct_bits_impl<OutElems, Points, CoeffStep, DataStep, AccumBits, CoeffTypeBits, DataTypeBits, CoeffType, DataType>;

    using  data_type = typename impl_type::data_type;
    using coeff_type = typename impl_type::coeff_type;
    using accum_type = typename impl_type::accum_type;

    static constexpr unsigned columns_per_mul = impl_type::columns_per_mul;
    static constexpr unsigned   lanes_per_mul = impl_type::lanes_per_mul;
    static constexpr unsigned         num_mul = impl_type::num_mul;
    static constexpr unsigned           lanes = OutElems;
    static constexpr unsigned          points = Points;

    template <MulMacroOp Op, unsigned N_Coeff, unsigned N_Data, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static auto run(const vector<CoeffType, N_Coeff> &coeff,
                    unsigned coeff_start,
                    const vector<DataType, N_Data> &data,
                    unsigned data_start,
                    unsigned uct_shift,
                    const Acc &... acc)
    {
        REQUIRES_CONSTANT_MSG(coeff_start, "coeff_start must be a compile-time constant");

        return impl_type::template run<Op>(coeff, coeff_start, data, data_start, uct_shift, acc...);
    }

    template <MulMacroOp Op, unsigned N_Coeff, unsigned N_Data, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static auto run_2buff(const vector<CoeffType, N_Coeff> &coeff,
                          unsigned coeff_start,
                          const vector<DataType, N_Data> &ldata,
                          unsigned ldata_start,
                          const vector<DataType, N_Data> &rdata,
                          unsigned rdata_start,
                          unsigned uct_shift,
                          const Acc &... acc)
    {
        REQUIRES_CONSTANT_MSG(coeff_start, "coeff_start must be a compile-time constant");

        return impl_type::template run<Op>(coeff, coeff_start, ldata, ldata_start, rdata, rdata_start, uct_shift, acc...);
    }
};

template <typename CoeffType, unsigned CoeffBits, typename DataType, unsigned DataBits> struct sliding_mul_ch_accum_tag;
template <typename CoeffType,                     typename DataType>                    struct sliding_mul_ch_accum_tag<CoeffType,  8, DataType,  8> { using type = acc32; };

template <typename CoeffType, typename DataType>
using sliding_mul_ch_accum_tag_t = typename sliding_mul_ch_accum_tag<CoeffType, type_bits_v<CoeffType>, DataType, type_bits_v<DataType>>::type;

template <unsigned Outputs, unsigned Channels, unsigned Points, int CoeffStep, int DataStepX, int DataStepY, unsigned AccumBits, unsigned CoeffTypeBits, unsigned DataTypeBits, typename CoeffType, typename DataType>
struct sliding_mul_ch_bits
{
    using impl_type = sliding_mul_ch_bits_impl<Outputs, Channels, Points, CoeffStep, DataStepX, DataStepY, AccumBits, CoeffTypeBits, DataTypeBits, CoeffType, DataType>;

    using  data_type = typename impl_type::data_type;
    using coeff_type = typename impl_type::coeff_type;
    using accum_type = typename impl_type::accum_type;

    static constexpr unsigned columns_per_mul = impl_type::columns_per_mul;
    static constexpr unsigned   lanes_per_mul = impl_type::lanes_per_mul;
    static constexpr unsigned         num_mul = impl_type::num_mul;
    static constexpr unsigned           lanes = Outputs * Channels;
    static constexpr unsigned          points = Points;
    static constexpr unsigned        channels = Channels;

    template <MulMacroOp Op, unsigned N_Coeff, unsigned N_Data, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static auto run(const vector<CoeffType, N_Coeff> &coeff,
                    unsigned coeff_start,
                    bool coeff_sign,
                    const vector<DataType, N_Data> &data,
                    unsigned data_start,
                    bool data_sign,
                    const Acc &... acc)
    {
        REQUIRES_CONSTANT_MSG(coeff_start, "coeff_start must be a compile-time constant");

        return impl_type::template run<Op>(coeff, coeff_start, coeff_sign, data, data_start, data_sign, acc...);
    }
};

#if __AIE_ARCH__ == 20

// AIE2 has limited support for permute patterns. These specializations handle patterns in
// which the DataStep is 2. They are implemented by unzipping data first and then calling sliding_mul with DataStep = 1

template <unsigned OutElems, unsigned Points, int CoeffStep, unsigned AccumBits, unsigned CoeffTypeBits, unsigned DataTypeBits, typename CoeffType, typename DataType>
struct sliding_mul_bits_impl<OutElems, Points, CoeffStep, 2, 2, AccumBits, CoeffTypeBits, DataTypeBits, CoeffType, DataType>
{
    using impl_type = sliding_mul_bits_impl<OutElems, Points, CoeffStep, 1, 1, AccumBits, CoeffTypeBits, DataTypeBits, CoeffType, DataType>;

    using  data_type = typename impl_type::data_type;
    using coeff_type = typename impl_type::coeff_type;
    using accum_type = typename impl_type::accum_type;

    static constexpr unsigned columns_per_mul = impl_type::columns_per_mul;
    static constexpr unsigned   lanes_per_mul = impl_type::lanes_per_mul;
    static constexpr unsigned         num_mul = impl_type::num_mul;
    static constexpr unsigned           lanes = OutElems;
    static constexpr unsigned          points = Points;

    template <MulMacroOp Op, unsigned N_Coeff, unsigned N_Data, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static auto run(const vector<CoeffType, N_Coeff> &coeff,
                    unsigned coeff_start,
                    bool coeff_sign,
                    const vector<DataType, N_Data> &data,
                    unsigned data_start,
                    bool data_sign,
                    const Acc &... acc)
    {
        REQUIRES_CONSTANT_MSG(coeff_start, "coeff_start must be a compile-time constant");

        constexpr unsigned native_data_elems = native_vector_length_v<DataType>;
        constexpr unsigned data_elems = std::max(N_Data, native_data_elems);

        vector<data_type, native_data_elems> data2;
        vector<data_type, data_elems> tmp;

        data_start = data_start % data_elems;

        tmp = shuffle_down_rotate<data_type, data_elems>::run(data.template grow_replicate<data_elems>(),
                                                              data_start);

        data2 = filter<DataType, data_elems, FilterOp::Even>::run(tmp, 1).template grow_replicate<native_data_elems>();

        return impl_type::template run<Op>(coeff, coeff_start, coeff_sign, data2, 0, data_sign, acc...);
    }
};

template <unsigned OutElems, unsigned Points, unsigned AccumBits, unsigned CoeffTypeBits, unsigned DataTypeBits, typename CoeffType, typename DataType>
struct sliding_mul_bits_impl<OutElems, Points, 2, 1, 1, AccumBits, CoeffTypeBits, DataTypeBits, CoeffType, DataType>
{
    using impl_type = sliding_mul_bits_impl<OutElems, Points, 1, 1, 1, AccumBits, CoeffTypeBits, DataTypeBits, CoeffType, DataType>;

    using  data_type = typename impl_type::data_type;
    using coeff_type = typename impl_type::coeff_type;
    using accum_type = typename impl_type::accum_type;
    
    static constexpr unsigned columns_per_mul = impl_type::columns_per_mul;
    static constexpr unsigned   lanes_per_mul = impl_type::lanes_per_mul;
    static constexpr unsigned         num_mul = impl_type::num_mul;
    static constexpr unsigned           lanes = OutElems;
    static constexpr unsigned          points = Points;
    
    template <MulMacroOp Op, unsigned N_Coeff, unsigned N_Data, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static auto run(const vector<CoeffType, N_Coeff> &coeff,
            unsigned coeff_start,
            bool coeff_sign,
            const vector<DataType, N_Data> &data,
            unsigned data_start,
            bool data_sign,
            const Acc &... acc)
    {
        REQUIRES_CONSTANT_MSG(coeff_start, "coeff_start must be a compile-time constant");

        constexpr unsigned native_coeff_elems = native_vector_length_v<CoeffType>;
        constexpr unsigned coeff_elems = std::max(N_Coeff, native_coeff_elems);
        
        vector<coeff_type, native_coeff_elems> coeff2;
        
        vector<coeff_type, coeff_elems> tmp;
        
        coeff_start = coeff_start % coeff_elems;
        
        tmp = shuffle_down_rotate<coeff_type, coeff_elems>::run(coeff.template grow_replicate<coeff_elems>(),
                coeff_start);
        
        coeff2 = filter<CoeffType, coeff_elems, FilterOp::Even>::run(tmp, 1).template grow_replicate<native_coeff_elems>();
        
        return impl_type::template run<Op>(coeff2, 0, coeff_sign, data, data_start, data_sign, acc...);
    }
};

template <unsigned Outputs, unsigned Channels, unsigned Points, int CoeffStep, unsigned AccumBits, unsigned CoeffTypeBits, unsigned DataTypeBits, typename CoeffType, typename DataType>
struct sliding_mul_ch_bits_impl<Outputs, Channels, Points, CoeffStep, 2, 2, AccumBits, CoeffTypeBits, DataTypeBits, CoeffType, DataType>
{
    using  impl_type = sliding_mul_ch_bits_impl<Outputs, Channels, Points, CoeffStep, 1, 1, AccumBits, CoeffTypeBits, DataTypeBits, CoeffType, DataType>;

    using  data_type = typename impl_type::data_type;
    using coeff_type = typename impl_type::coeff_type;
    using accum_type = typename impl_type::accum_type;

    static constexpr unsigned columns_per_mul = impl_type::columns_per_mul;
    static constexpr unsigned   lanes_per_mul = impl_type::lanes_per_mul;
    static constexpr unsigned         num_mul = impl_type::num_mul;
    static constexpr unsigned           lanes = Outputs * Channels;
    static constexpr unsigned          points = Points;
    static constexpr unsigned        channels = Channels;

    template <MulMacroOp Op, unsigned N_Coeff, unsigned N_Data, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static auto run(const vector<CoeffType, N_Coeff> &coeff,
                    unsigned coeff_start,
                    bool coeff_sign,
                    const vector<DataType, N_Data> &data,
                    unsigned data_start,
                    bool data_sign,
                    const Acc &... acc)
    {
        REQUIRES_CONSTANT_MSG(coeff_start, "coeff_start must be a compile-time constant");

        constexpr unsigned native_data_elems = native_vector_length_v<DataType>;
        constexpr unsigned data_elems = std::max(N_Data, native_data_elems);

        vector<data_type, native_data_elems> data2;
        vector<data_type, data_elems> tmp;

        data_start = data_start % data_elems;

        tmp = shuffle_down_rotate<data_type, data_elems>::run(data.template grow_replicate<data_elems>(),
                                                              data_start * Channels);

        data2 = filter<DataType, data_elems, FilterOp::Even>::run(tmp, Channels).template grow_replicate<native_data_elems>();

        return impl_type::template run<Op>(coeff, coeff_start, coeff_sign, data2, 0, data_sign, acc...);
    }
};

template <unsigned Outputs, unsigned Channels, unsigned Points, unsigned AccumBits, unsigned CoeffTypeBits, unsigned DataTypeBits, typename CoeffType, typename DataType>
struct sliding_mul_ch_bits_impl<Outputs, Channels, Points, 2, 1, 1, AccumBits, CoeffTypeBits, DataTypeBits, CoeffType, DataType>
{
    using  impl_type = sliding_mul_ch_bits_impl<Outputs, Channels, Points, 1, 1, 1, AccumBits, CoeffTypeBits, DataTypeBits, CoeffType, DataType>;

    using  data_type = typename impl_type::data_type;
    using coeff_type = typename impl_type::coeff_type;
    using accum_type = typename impl_type::accum_type;
    
    static constexpr unsigned columns_per_mul = impl_type::columns_per_mul;
    static constexpr unsigned   lanes_per_mul = impl_type::lanes_per_mul;
    static constexpr unsigned         num_mul = impl_type::num_mul;
    static constexpr unsigned           lanes = Outputs * Channels;
    static constexpr unsigned          points = Points;
    static constexpr unsigned        channels = Channels;
    
    template <MulMacroOp Op, unsigned N_Coeff, unsigned N_Data, typename... Acc> requires((is_accum_v<Acc> && ...))
    __aie_inline
    static auto run(const vector<CoeffType, N_Coeff> &coeff,
            unsigned coeff_start,
            bool coeff_sign,
            const vector<DataType, N_Data> &data,
            unsigned data_start,
            bool data_sign,
            const Acc &... acc)
    {
        REQUIRES_CONSTANT_MSG(coeff_start, "coeff_start must be a compile-time constant");

        constexpr unsigned native_coeff_elems = native_vector_length_v<DataType>;
        constexpr unsigned coeff_elems = std::max(N_Coeff, native_coeff_elems);
        
        vector<coeff_type, native_coeff_elems> coeff2;
        
        vector<coeff_type, coeff_elems> tmp;
        
        coeff_start = coeff_start % coeff_elems;
        
        tmp = shuffle_down_rotate<coeff_type, coeff_elems>::run(coeff.template grow_replicate<coeff_elems>(),
                coeff_start * Channels);
        
        coeff2 = filter<CoeffType, coeff_elems, FilterOp::Even>::run(tmp, Channels).template grow_replicate<native_coeff_elems>();
        
        return impl_type::template run<Op>(coeff2, 0, coeff_sign, data, data_start, data_sign, acc...);
    }
};

#endif

template <MulMacroOp MulOp, unsigned AccumBits, typename T1, typename T2>
using             mul  = mul_bits<MulOp, AccumBits, type_bits_v<T1>, T1, type_bits_v<T2>, T2>;

template <MulMacroOp MulOp, unsigned AccumBits, typename T1, typename T2>
using      mul_maxmin = mul_maxmin_bits<MulOp, AccumBits, type_bits_v<T1>, T1, type_bits_v<T2>, T2>;

template <unsigned AccumBits, typename T, unsigned Elems>
using      mul_reduce = mul_reduce_bits<AccumBits, type_bits_v<T>, T, Elems>;

template <unsigned OutElems, unsigned Points, int CoeffStep, int DataStepX, int DataStepY, unsigned AccumBits, typename CoeffType, typename DataType>
using     sliding_mul = sliding_mul_bits    <OutElems, Points, CoeffStep, DataStepX, DataStepY, AccumBits, type_bits_v<CoeffType>, type_bits_v<DataType>, CoeffType, DataType>;

template <unsigned OutElems, unsigned Points, int CoeffStep, int DataStepX, int DataStepY, unsigned AccumBits, typename CoeffType, typename DataType>
using sliding_mul_sym = sliding_mul_sym_bits<OutElems, Points, CoeffStep, DataStepX, DataStepY, AccumBits, type_bits_v<CoeffType>, type_bits_v<DataType>, CoeffType, DataType>;

template <unsigned OutElems, unsigned Points, int CoeffStep, int DataStep, unsigned AccumBits, typename CoeffType, typename DataType>
using sliding_mul_sym_uct = sliding_mul_sym_uct_bits<OutElems, Points, CoeffStep, DataStep, AccumBits, type_bits_v<CoeffType>, type_bits_v<DataType>, CoeffType, DataType>;

template <unsigned Outputs, unsigned Channels, unsigned Points, int CoeffStep, int DataStepX, int DataStepY, unsigned AccumBits, typename CoeffType, typename DataType>
using   sliding_mul_ch = sliding_mul_ch_bits  <Outputs, Channels, Points, CoeffStep, DataStepX, DataStepY, AccumBits, type_bits_v<CoeffType>, type_bits_v<DataType>, CoeffType, DataType>;

}

#if __AIE_ARCH__ == 10

#include "aie1/mul.hpp"
#include "aie1/mul_reduce.hpp"
#include "aie1/sliding_mul.hpp"
#include "aie1/sliding_mul_sym.hpp"

#elif __AIE_ARCH__ == 20

#include "aie2/mul.hpp"
#include "aie2/mul_reduce.hpp"
#include "aie2/sliding_mul.hpp"

#endif

#endif
