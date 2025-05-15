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
 * @mainpage Overview
 *
 * AIE arch property APIs provides interface to query the 
 * AIE architecture specific properties or traits. It is 
 * implemented as a C++ header-only library. These APIs 
 * can be used in kernel code (core program) as well as 
 * ADF graph code. Currently the library supports only 
 * following architecture versions:
 * __AIE_ARCH__ = 10, 20, 21, 22, 40.
 */
 
/**
 * @file
 * @brief AIE arch property APIs.
 */

#pragma once

#if __AIE_ARCH__ == 10

#include "aie_arch_properties_10.hpp"

#elif __AIE_ARCH__ == 20

#include "aie_arch_properties_20.hpp"

#elif __AIE_ARCH__ == 21

#include "aie_arch_properties_21.hpp"

#elif __AIE_ARCH__ == 22

#include "aie_arch_properties_22.hpp"

#elif __AIE_ARCH__ == 40

#include "aie_arch_properties_40.hpp"

#else

#error "AIE arch property APIs not defined for this aie arch version"

#endif

/**
 * @defgroup group_aie_arch_property Arch Property
 *
 * Set of APIs to query architecture related properties.
 */

namespace adf
{

/**
 * @ingroup group_aie_arch_property
 *
 * @return Number of input stream ports in aie core.
 */
constexpr int get_input_streams_core_module() { return NUM_INPUT_STREAMS_CORE_MODULE; }

/**
 * @ingroup group_aie_arch_property
 *
 * @return Number of output stream ports in aie core.
 */
constexpr int get_output_streams_core_module() { return NUM_OUTPUT_STREAMS_CORE_MODULE; }

/**
 * @ingroup group_aie_arch_property
 *
 * @return Data memory per core tile in bytes.
 */
constexpr int get_memory_size_aie_tile() { return MEMORY_SIZE_AIE_TILE; }

/**
 * @ingroup group_aie_arch_property
 *
 * @return true if mem tile is available.
 */
constexpr bool has_memory_tile() { return (MEMORY_SIZE_MEMORY_TILE > 0); }

/**
 * @ingroup group_aie_arch_property
 *
 * @return Memory per mem tile in bytes.
 */
constexpr int get_memory_size_memory_tile() { return MEMORY_SIZE_MEMORY_TILE; }

} //namespace adf
