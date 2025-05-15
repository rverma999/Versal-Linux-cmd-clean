// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
/*  (c) Copyright 2020 - 2023 Xilinx, Inc. All rights reserved.

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

#ifndef __AIE_API_DETAIL_AIE1_VECTOR_NATIVE_TYPES__HPP__
#define __AIE_API_DETAIL_AIE1_VECTOR_NATIVE_TYPES__HPP__

namespace aie::detail {

template <typename T, unsigned Elems>
struct vector_storage;

template <typename T, unsigned Elems>
using vector_storage_t = typename vector_storage<T, Elems>::type;

template <> struct vector_storage<int8,    16> { using type =                  v16int8; static type undef() { return undef_v16int8();                          } };
template <> struct vector_storage<int8,    32> { using type =                  v32int8; static type undef() { return undef_v32int8();                          } };
template <> struct vector_storage<int8,    64> { using type =                  v64int8; static type undef() { return undef_v64int8();                          } };
#ifdef __AIE_API_USE_NATIVE_1024B_VECTOR__
template <> struct vector_storage<int8,   128> { using type =                 v128int8; static type undef() { return undef_v128int8();                         } };
#else
template <> struct vector_storage<int8,   128> { using type =   std::array<v64int8, 2>; static type undef() { return { undef_v64int8(), undef_v64int8() };     } };
#endif

template <> struct vector_storage<uint8,   16> { using type =                 v16uint8; static type undef() { return undef_v16uint8();                         } };
template <> struct vector_storage<uint8,   32> { using type =                 v32uint8; static type undef() { return undef_v32uint8();                         } };
template <> struct vector_storage<uint8,   64> { using type =                 v64uint8; static type undef() { return undef_v64uint8();                         } };
#ifdef __AIE_API_USE_NATIVE_1024B_VECTOR__
template <> struct vector_storage<uint8,  128> { using type =                v128uint8; static type undef() { return undef_v128uint8();                        } };
#else
template <> struct vector_storage<uint8,  128> { using type =  std::array<v64uint8, 2>; static type undef() { return { undef_v64uint8(), undef_v64uint8() };   } };
#endif

template <> struct vector_storage<int16,    8> { using type =                  v8int16; static type undef() { return undef_v8int16();                          } };
template <> struct vector_storage<int16,   16> { using type =                 v16int16; static type undef() { return undef_v16int16();                         } };
template <> struct vector_storage<int16,   32> { using type =                 v32int16; static type undef() { return undef_v32int16();                         } };
#ifdef __AIE_API_USE_NATIVE_1024B_VECTOR__
template <> struct vector_storage<int16,   64> { using type =                 v64int16; static type undef() { return undef_v64int16();                         } };
#else
template <> struct vector_storage<int16,   64> { using type =  std::array<v32int16, 2>; static type undef() { return { undef_v32int16(), undef_v32int16() };   } };
#endif

template <> struct vector_storage<int32,    4> { using type =                  v4int32; static type undef() { return undef_v4int32();                          } };
template <> struct vector_storage<int32,    8> { using type =                  v8int32; static type undef() { return undef_v8int32();                          } };
template <> struct vector_storage<int32,   16> { using type =                 v16int32; static type undef() { return undef_v16int32();                         } };
#ifdef __AIE_API_USE_NATIVE_1024B_VECTOR__
template <> struct vector_storage<int32,   32> { using type =                 v32int32; static type undef() { return undef_v32int32();                         } };
#else
template <> struct vector_storage<int32,   32> { using type =  std::array<v16int32, 2>; static type undef() { return { undef_v16int32(), undef_v16int32() };   } };
#endif

template <> struct vector_storage<float,    4> { using type =                  v4float; static type undef() { return undef_v4float();                          } };
template <> struct vector_storage<float,    8> { using type =                  v8float; static type undef() { return undef_v8float();                          } };
template <> struct vector_storage<float,   16> { using type =                 v16float; static type undef() { return undef_v16float();                         } };
#ifdef __AIE_API_USE_NATIVE_1024B_VECTOR__
template <> struct vector_storage<float,   32> { using type =                 v32float; static type undef() { return undef_v32float();                         } };
#else
template <> struct vector_storage<float,   32> { using type =  std::array<v16float, 2>; static type undef() { return { undef_v16float(), undef_v16float() };   } };
#endif

template <> struct vector_storage<cint16,   4> { using type =                 v4cint16; static type undef() { return undef_v4cint16();                         } };
template <> struct vector_storage<cint16,   8> { using type =                 v8cint16; static type undef() { return undef_v8cint16();                         } };
template <> struct vector_storage<cint16,  16> { using type =                v16cint16; static type undef() { return undef_v16cint16();                        } };
#ifdef __AIE_API_USE_NATIVE_1024B_VECTOR__
template <> struct vector_storage<cint16,  32> { using type =                v32cint16; static type undef() { return undef_v32cint16();                        } };
#else
template <> struct vector_storage<cint16,  32> { using type = std::array<v16cint16, 2>; static type undef() { return { undef_v16cint16(), undef_v16cint16() }; } };
#endif

template <> struct vector_storage<cint32,   2> { using type =                 v2cint32; static type undef() { return undef_v2cint32();                         } };
template <> struct vector_storage<cint32,   4> { using type =                 v4cint32; static type undef() { return undef_v4cint32();                         } };
template <> struct vector_storage<cint32,   8> { using type =                 v8cint32; static type undef() { return undef_v8cint32();                         } };
#ifdef __AIE_API_USE_NATIVE_1024B_VECTOR__
template <> struct vector_storage<cint32,  16> { using type =                v16cint32; static type undef() { return undef_v16cint32();                        } };
#else
template <> struct vector_storage<cint32,  16> { using type =  std::array<v8cint32, 2>; static type undef() { return { undef_v8cint32(), undef_v8cint32() };   } };
#endif

template <> struct vector_storage<cfloat,   2> { using type =                 v2cfloat; static type undef() { return undef_v2cfloat();                         } };
template <> struct vector_storage<cfloat,   4> { using type =                 v4cfloat; static type undef() { return undef_v4cfloat();                         } };
template <> struct vector_storage<cfloat,   8> { using type =                 v8cfloat; static type undef() { return undef_v8cfloat();                         } };
#ifdef __AIE_API_USE_NATIVE_1024B_VECTOR__
template <> struct vector_storage<cfloat,  16> { using type =                v16cfloat; static type undef() { return undef_v16cfloat();                        } };
#else
template <> struct vector_storage<cfloat,  16> { using type =  std::array<v8cfloat, 2>; static type undef() { return { undef_v8cfloat(), undef_v8cfloat() };   } };
#endif

template <typename T> struct native_vector_traits;

template <> struct native_vector_traits<    v16int8> { using value_type = int8;      static constexpr unsigned size =  16; };
template <> struct native_vector_traits<    v32int8> { using value_type = int8;      static constexpr unsigned size =  32; };
template <> struct native_vector_traits<    v64int8> { using value_type = int8;      static constexpr unsigned size =  64; };
#ifdef __AIE_API_USE_NATIVE_1024B_VECTOR__
template <> struct native_vector_traits<   v128int8> { using value_type = int8;      static constexpr unsigned size = 128; };
#endif

template <> struct native_vector_traits<   v16uint8> { using value_type = uint8;     static constexpr unsigned size =  16; };
template <> struct native_vector_traits<   v32uint8> { using value_type = uint8;     static constexpr unsigned size =  32; };
template <> struct native_vector_traits<   v64uint8> { using value_type = uint8;     static constexpr unsigned size =  64; };
#ifdef __AIE_API_USE_NATIVE_1024B_VECTOR__
template <> struct native_vector_traits<  v128uint8> { using value_type = uint8;     static constexpr unsigned size = 128; };
#endif

template <> struct native_vector_traits<    v8int16> { using value_type = int16;     static constexpr unsigned size =   8; };
template <> struct native_vector_traits<   v16int16> { using value_type = int16;     static constexpr unsigned size =  16; };
template <> struct native_vector_traits<   v32int16> { using value_type = int16;     static constexpr unsigned size =  32; };
#ifdef __AIE_API_USE_NATIVE_1024B_VECTOR__
template <> struct native_vector_traits<   v64int16> { using value_type = int16;     static constexpr unsigned size =  64; };
#endif

template <> struct native_vector_traits<    v4int32> { using value_type = int32;     static constexpr unsigned size =   4; };
template <> struct native_vector_traits<    v8int32> { using value_type = int32;     static constexpr unsigned size =   8; };
template <> struct native_vector_traits<   v16int32> { using value_type = int32;     static constexpr unsigned size =  16; };
#ifdef __AIE_API_USE_NATIVE_1024B_VECTOR__
template <> struct native_vector_traits<   v32int32> { using value_type = int32;     static constexpr unsigned size =  32; };
#endif

template <> struct native_vector_traits<   v4cint16> { using value_type = cint16;    static constexpr unsigned size =   4; };
template <> struct native_vector_traits<   v8cint16> { using value_type = cint16;    static constexpr unsigned size =   8; };
template <> struct native_vector_traits<  v16cint16> { using value_type = cint16;    static constexpr unsigned size =  16; };
#ifdef __AIE_API_USE_NATIVE_1024B_VECTOR__
template <> struct native_vector_traits<  v32cint16> { using value_type = cint32;    static constexpr unsigned size =  32; };
#endif

template <> struct native_vector_traits<   v2cint32> { using value_type = cint32;    static constexpr unsigned size =   2; };
template <> struct native_vector_traits<   v4cint32> { using value_type = cint32;    static constexpr unsigned size =   4; };
template <> struct native_vector_traits<   v8cint32> { using value_type = cint32;    static constexpr unsigned size =   8; };
#ifdef __AIE_API_USE_NATIVE_1024B_VECTOR__
template <> struct native_vector_traits<  v16cint32> { using value_type = cint32;    static constexpr unsigned size =  16; };
#endif

template <> struct native_vector_traits<    v4float> { using value_type =  float;    static constexpr unsigned size =  4; };
template <> struct native_vector_traits<    v8float> { using value_type =  float;    static constexpr unsigned size =  8; };
template <> struct native_vector_traits<   v16float> { using value_type =  float;    static constexpr unsigned size = 16; };
#ifdef __AIE_API_USE_NATIVE_1024B_VECTOR__
template <> struct native_vector_traits<   v32float> { using value_type =  float;    static constexpr unsigned size = 32; };
#endif

template <> struct native_vector_traits<    v2cfloat> { using value_type =   cfloat; static constexpr unsigned size =  2; };
template <> struct native_vector_traits<    v4cfloat> { using value_type =   cfloat; static constexpr unsigned size =  4; };
template <> struct native_vector_traits<    v8cfloat> { using value_type =   cfloat; static constexpr unsigned size =  8; };
#ifdef __AIE_API_USE_NATIVE_1024B_VECTOR__
template <> struct native_vector_traits<   v16cfloat> { using value_type =   cfloat; static constexpr unsigned size = 16; };
#endif

template <typename T>
struct is_valid_element_type
{
    static constexpr bool value = utils::is_one_of_v<T, int8, uint8, int16, int32, cint16, cint32, float, cfloat>;
};

template <typename T>
struct is_complex
{
    static constexpr bool value = utils::is_one_of_v<T, cint16, cint32, cfloat>;
};

template <typename T>
struct is_integral
{
    static constexpr bool value = utils::is_one_of_v<T, int8, uint8, int16, int32, cint16, cint32>;
};

template <typename T>
struct is_floating_point
{
    static constexpr bool value = utils::is_one_of_v<T, float, cfloat>;
};

template <typename T>
struct is_signed
{
    static constexpr bool value = utils::is_one_of_v<T, int8, int16, int32, cint16, cint32, float, cfloat>;
};

template <typename T, unsigned Elems>
struct native_vector_type;

template <> struct native_vector_type<int8,    16> { using type =   v16int8; };
template <> struct native_vector_type<int8,    32> { using type =   v32int8; };
template <> struct native_vector_type<int8,    64> { using type =   v64int8; };
template <> struct native_vector_type<int8,   128> { using type =  v128int8; };

template <> struct native_vector_type<uint8,   16> { using type =  v16uint8; };
template <> struct native_vector_type<uint8,   32> { using type =  v32uint8; };
template <> struct native_vector_type<uint8,   64> { using type =  v64uint8; };
template <> struct native_vector_type<uint8,  128> { using type = v128uint8; };

template <> struct native_vector_type<int16,    8> { using type =   v8int16; };
template <> struct native_vector_type<int16,   16> { using type =  v16int16; };
template <> struct native_vector_type<int16,   32> { using type =  v32int16; };
template <> struct native_vector_type<int16,   64> { using type =  v64int16; };

template <> struct native_vector_type<int32,    4> { using type =   v4int32; };
template <> struct native_vector_type<int32,    8> { using type =   v8int32; };
template <> struct native_vector_type<int32,   16> { using type =  v16int32; };
template <> struct native_vector_type<int32,   32> { using type =  v32int32; };

template <> struct native_vector_type<float,    4> { using type =   v4float; };
template <> struct native_vector_type<float,    8> { using type =   v8float; };
template <> struct native_vector_type<float,   16> { using type =  v16float; };
template <> struct native_vector_type<float,   32> { using type =  v32float; };

template <> struct native_vector_type<cint16,   4> { using type =  v4cint16; };
template <> struct native_vector_type<cint16,   8> { using type =  v8cint16; };
template <> struct native_vector_type<cint16,  16> { using type = v16cint16; };
template <> struct native_vector_type<cint16,  32> { using type = v32cint16; };

template <> struct native_vector_type<cint32,   2> { using type =  v2cint32; };
template <> struct native_vector_type<cint32,   4> { using type =  v4cint32; };
template <> struct native_vector_type<cint32,   8> { using type =  v8cint32; };
template <> struct native_vector_type<cint32,  16> { using type = v16cint32; };

template <> struct native_vector_type<cfloat,   2> { using type =  v2cfloat; };
template <> struct native_vector_type<cfloat,   4> { using type =  v4cfloat; };
template <> struct native_vector_type<cfloat,   8> { using type =  v8cfloat; };
template <> struct native_vector_type<cfloat,  16> { using type = v16cfloat; };

template <typename T, unsigned Elems>
using native_vector_type_t = typename native_vector_type<T, Elems>::type;

} // namespace aie::detail

#endif // __AIE_API_DETAIL_AIE1_VECTOR_NATIVE_TYPES__HPP__
