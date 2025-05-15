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

#ifndef __AIE_API_DETAIL_CONFIG__HPP__
#define __AIE_API_DETAIL_CONFIG__HPP__

#ifdef __chess__
#define AIE_API_NATIVE 0
#else
#define AIE_API_NATIVE 1
#endif

#define __AIE_API_PROVIDE_DEFAULT_SCALAR_IMPLEMENTATION__

#if AIE_API_NATIVE == 0
#define __AIE_API_FUNDAMENTAL_TYPE__ [[chess::behave_as_fundamental_type]]
#define __AIE_API_KEEP_IN_REGISTERS__ [[chess::keep_in_registers]]
#else
#define __AIE_API_FUNDAMENTAL_TYPE__
#define __AIE_API_KEEP_IN_REGISTERS__
#endif

#ifdef AIE_DEBUG_NOINLINE
#define __aie_inline
#else
#define __aie_inline __attribute__((always_inline))
#endif
#define __aie_noinline __attribute__((noinline))

#if __AIE_ARCH__ == 10

#include "aie1/config.hpp"

#elif __AIE_ARCH__ == 20

#include "aie2/config.hpp"

#endif

#if (AIE_API_NATIVE == 0) && (__AIE_API_SCALAR_TYPES_CONSTEXPR__ != 0)
#define SCALAR_TYPES_CONSTEXPR constexpr
#else
#define SCALAR_TYPES_CONSTEXPR
#endif

#if (AIE_API_NATIVE == 0) && __AIE_API_CONSTEXPR_BFLOAT16__
//TODO: Pending CRVO-7585
#define BFLOAT16_CONSTEXPR constexpr
#else
#define BFLOAT16_CONSTEXPR
#endif

#if __AIE_ARCH__ == 20

#if __AIE_API_SHIFT_BYTES__
#define SHIFT_BYTES ::shift_bytes
#else
#define SHIFT_BYTES ::shift
#endif

#endif

namespace aie {

/**
 * Structure used to represent the AIE architecture being compiled against.
 */
struct arch {
    /**
     * An enum defining available AIE architectures.
     */
    enum ArchVersion : unsigned {
        AIE     = 10,
        AIE_ML  = 20
    };

    /**
     * Represents the current AIE architecture version.
     */
    static constexpr ArchVersion version = ArchVersion(__AIE_ARCH__);

    /**
     * Checks if the current AIE architecture version against the supplied pack.
     *
     * @param vs A pack of ArchVersions to test the current version against
     */
    template <typename... T> requires (std::is_same_v<T, ArchVersion> && ...)
    static constexpr bool is(T... vs) { return ((version == vs) || ...); }
};

}

#endif
