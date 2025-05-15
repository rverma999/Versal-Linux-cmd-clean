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

#ifndef __AIE_API_DETAIL_VECTOR__HPP__
#define __AIE_API_DETAIL_VECTOR__HPP__

#include "config.hpp"
#include "utils.hpp"

#include <array>
#include <tuple>

namespace aie::detail {

template <typename T>
struct native_vector_length;

template <typename T>
static constexpr unsigned native_vector_length_v = native_vector_length<T>::value;

template <typename T>
struct type_bits
{
    static constexpr unsigned value = sizeof(T) * 8;
};

template <typename T>
static constexpr unsigned type_bits_v = type_bits<T>::value;

template <aie_dm_resource Resource, typename T> struct add_memory_bank { using type = T; };

template <typename T> struct add_memory_bank<aie_dm_resource::a,     T> { using type = T chess_storage(DM_bankA); };
template <typename T> struct add_memory_bank<aie_dm_resource::b,     T> { using type = T chess_storage(DM_bankB); };
template <typename T> struct add_memory_bank<aie_dm_resource::c,     T> { using type = T chess_storage(DM_bankC); };
template <typename T> struct add_memory_bank<aie_dm_resource::d,     T> { using type = T chess_storage(DM_bankD); };
#if __AIE_API_COMPOUND_DM_RESOURCE__
template <typename T> struct add_memory_bank<aie_dm_resource::ab,    T> { using type = T chess_storage(DM_bankAB); };
template <typename T> struct add_memory_bank<aie_dm_resource::ac,    T> { using type = T chess_storage(DM_bankAC); };
template <typename T> struct add_memory_bank<aie_dm_resource::ad,    T> { using type = T chess_storage(DM_bankAD); };
template <typename T> struct add_memory_bank<aie_dm_resource::bc,    T> { using type = T chess_storage(DM_bankBC); };
template <typename T> struct add_memory_bank<aie_dm_resource::bd,    T> { using type = T chess_storage(DM_bankBD); };
template <typename T> struct add_memory_bank<aie_dm_resource::cd,    T> { using type = T chess_storage(DM_bankCD); };
#endif

template <typename T> struct add_memory_bank<aie_dm_resource::stack, T> { using type = T chess_storage(DM_stack); };

template <aie_dm_resource Resource, typename T>
using add_memory_bank_t = typename add_memory_bank<Resource, T>::type;

template <typename T, unsigned Elems>
struct vector_ldst_align;

} // namespace aie::detail

#endif
