// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
/*  (c) Copyright 2021 - 2023 Xilinx, Inc. All rights reserved.

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


#ifndef __AIE_API_DETAIL_AIE2_SPARSE_VECTOR_NATIVE_TYPES__HPP__
#define __AIE_API_DETAIL_AIE2_SPARSE_VECTOR_NATIVE_TYPES__HPP__

namespace aie::detail {

template <typename T, unsigned Elems>
struct sparse_vector_storage;

// No undef?
template <> struct sparse_vector_storage< int4,    256> { using type =                 v256int4_sparse; using pointer_type =    v256int4_sparse_compress; };
template <> struct sparse_vector_storage<uint4,    256> { using type =                v256uint4_sparse; using pointer_type =   v256uint4_sparse_compress; };

template <> struct sparse_vector_storage< int8,    128> { using type =                 v128int8_sparse; using pointer_type =    v128int8_sparse_compress; };
template <> struct sparse_vector_storage<uint8,    128> { using type =                v128uint8_sparse; using pointer_type =   v128uint8_sparse_compress; };

template <> struct sparse_vector_storage< int8,    256> { using type = std::array< v128int8_sparse, 2>; using pointer_type =    v128int8_sparse_compress; };
template <> struct sparse_vector_storage<uint8,    256> { using type = std::array<v128uint8_sparse, 2>; using pointer_type =   v128uint8_sparse_compress; };

template <> struct sparse_vector_storage< int16,    64> { using type =                 v64int16_sparse; using pointer_type =    v64int16_sparse_compress; };
template <> struct sparse_vector_storage<uint16,    64> { using type =                v64uint16_sparse; using pointer_type =   v64uint16_sparse_compress; };

template <> struct sparse_vector_storage< int16,   128> { using type = std::array< v64int16_sparse, 2>; using pointer_type =    v64int16_sparse_compress; };
template <> struct sparse_vector_storage<uint16,   128> { using type = std::array<v64uint16_sparse, 2>; using pointer_type =   v64uint16_sparse_compress; };

template <> struct sparse_vector_storage<bfloat16,  64> { using type =                v64bfloat16_sparse; using pointer_type = v64bfloat16_sparse_compress; };
template <> struct sparse_vector_storage<bfloat16, 128> { using type = std::array<v64bfloat16_sparse, 2>; using pointer_type = v64bfloat16_sparse_compress; };

template <typename T>
struct is_valid_sparse_element_type
{
    static constexpr bool value = utils::is_one_of_v<T, int8, uint8, int16, uint16, int4, uint4, bfloat16>;
};

template <typename T, unsigned Elems>
struct native_sparse_vector_type;

template <> struct native_sparse_vector_type< int4,    256> { using type =  v256int4_sparse; };
template <> struct native_sparse_vector_type<uint4,    256> { using type = v256uint4_sparse; };

template <> struct native_sparse_vector_type< int8,    128> { using type =  v128int8_sparse; };
template <> struct native_sparse_vector_type<uint8,    128> { using type = v128uint8_sparse; };

template <> struct native_sparse_vector_type< int16,    64> { using type =  v64int16_sparse; };
template <> struct native_sparse_vector_type<uint16,    64> { using type = v64uint16_sparse; };

template <> struct native_sparse_vector_type<bfloat16,  64> { using type =  v64bfloat16_sparse; };

template <typename T> struct native_vector_traits;
template <> struct native_vector_traits<    v256int4_sparse> { using value_type =     int4; static constexpr unsigned size = 256; };
template <> struct native_vector_traits<   v256uint4_sparse> { using value_type =    uint4; static constexpr unsigned size = 256; };

template <> struct native_vector_traits<    v128int8_sparse> { using value_type =     int8; static constexpr unsigned size = 128; };
template <> struct native_vector_traits<   v128uint8_sparse> { using value_type =    uint8; static constexpr unsigned size = 128; };

template <> struct native_vector_traits<    v64int16_sparse> { using value_type =    int16; static constexpr unsigned size =  64; };
template <> struct native_vector_traits<   v64uint16_sparse> { using value_type =   uint16; static constexpr unsigned size =  64; };

template <> struct native_vector_traits< v64bfloat16_sparse> { using value_type = bfloat16; static constexpr unsigned size =  64; };

} // namespace aie::detail

#endif // __AIE_API_DETAIL_AIE2_SPARSE_VECTOR_NATIVE_TYPES__HPP__

