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

#ifndef __AIE_API_DETAIL_AIE2_ACCUM_NATIVE_TYPES__HPP__
#define __AIE_API_DETAIL_AIE2_ACCUM_NATIVE_TYPES__HPP__

namespace aie::detail {

template <typename AccumTag>
struct accum_native_type;

template <> struct accum_native_type<acc16>    { using type = acc32; };
template <> struct accum_native_type<acc24>    { using type = acc32; };
template <> struct accum_native_type<acc32>    { using type = acc32; };

template <> struct accum_native_type<acc40>    { using type = acc64; };
template <> struct accum_native_type<acc48>    { using type = acc64; };
template <> struct accum_native_type<acc56>    { using type = acc64; };
template <> struct accum_native_type<acc64>    { using type = acc64; };

template <> struct accum_native_type<cacc16>   { using type = cacc64; };
template <> struct accum_native_type<cacc24>   { using type = cacc64; };
template <> struct accum_native_type<cacc32>   { using type = cacc64; };

template <> struct accum_native_type<cacc40>   { using type = cacc64; };
template <> struct accum_native_type<cacc48>   { using type = cacc64; };
template <> struct accum_native_type<cacc56>   { using type = cacc64; };
template <> struct accum_native_type<cacc64>   { using type = cacc64; };

template <> struct accum_native_type<accfloat>  { using type = accfloat; };
#if __AIE_API_COMPLEX_FP32_EMULATION__
template <> struct accum_native_type<caccfloat> { using type = caccfloat; };
#endif

template <typename AccumTag>
struct accum_class_for_tag;

template <> struct accum_class_for_tag<exact_acc32> { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <> struct accum_class_for_tag<exact_acc64> { static constexpr AccumClass value() { return AccumClass::Int;  } };

template <> struct accum_bits_for_tag<exact_acc32>  { static constexpr unsigned value() { return 32; } };
template <> struct accum_bits_for_tag<exact_acc64>  { static constexpr unsigned value() { return 64; } };

// TODO: remove accum_class_for_type as it is mainly required in the context of multiplications,
// which is already handled by accum_class_for_mul_types
template <typename AccumTag>
struct accum_class_for_type;

template <> struct accum_class_for_type<int4>     { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <> struct accum_class_for_type<uint4>    { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <> struct accum_class_for_type<int8>     { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <> struct accum_class_for_type<uint8>    { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <> struct accum_class_for_type<int16>    { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <> struct accum_class_for_type<uint16>   { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <> struct accum_class_for_type<int32>    { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <> struct accum_class_for_type<uint32>   { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <> struct accum_class_for_type<cint16>   { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <> struct accum_class_for_type<cint32>   { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <> struct accum_class_for_type<bfloat16> { static constexpr AccumClass value() { return AccumClass::FP;  } };
template <> struct accum_class_for_type<float>    { static constexpr AccumClass value() { return AccumClass::FP;  } };
#if __AIE_API_COMPLEX_FP32_EMULATION__
template <> struct accum_class_for_type<cfloat>   { static constexpr AccumClass value() { return AccumClass::CFP; } };
#endif

template <typename T, typename U>
struct accum_class_for_mul_types;

template <typename T> struct accum_class_for_mul_types<T,        int4>      { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <typename T> struct accum_class_for_mul_types<T,        uint4>     { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <typename T> struct accum_class_for_mul_types<T,        int8>      { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <typename T> struct accum_class_for_mul_types<T,        uint8>     { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <typename T> struct accum_class_for_mul_types<T,        int16>     { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <typename T> struct accum_class_for_mul_types<T,        uint16>    { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <          > struct accum_class_for_mul_types<cint16,   int16>     { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <          > struct accum_class_for_mul_types<cint16,   uint16>    { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <          > struct accum_class_for_mul_types<cint32,   int16>     { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <          > struct accum_class_for_mul_types<cint32,   uint16>    { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <typename T> struct accum_class_for_mul_types<T,        int32>     { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <typename T> struct accum_class_for_mul_types<T,        uint32>    { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <          > struct accum_class_for_mul_types<cint16,   int32>     { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <          > struct accum_class_for_mul_types<cint16,   uint32>    { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <          > struct accum_class_for_mul_types<cint32,   int32>     { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <          > struct accum_class_for_mul_types<cint32,   uint32>    { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <typename T> struct accum_class_for_mul_types<T,        cint16>    { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <typename T> struct accum_class_for_mul_types<T,        cint32>    { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <          > struct accum_class_for_mul_types<bfloat16, bfloat16>  { static constexpr AccumClass value() { return AccumClass::FP;   } };
template <          > struct accum_class_for_mul_types<float,    float>     { static constexpr AccumClass value() { return AccumClass::FP;   } };
#if __AIE_API_COMPLEX_FP32_EMULATION__
template <          > struct accum_class_for_mul_types< float,   cfloat>    { static constexpr AccumClass value() { return AccumClass::CFP;  } };
template <          > struct accum_class_for_mul_types<cfloat,    float>    { static constexpr AccumClass value() { return AccumClass::CFP;  } };
template <          > struct accum_class_for_mul_types<cfloat,   cfloat>    { static constexpr AccumClass value() { return AccumClass::CFP;  } };
#endif

template <AccumClass Class, unsigned Bits, unsigned Elems>
struct accum_storage;

template <AccumClass Class, unsigned Bits, unsigned Elems>
using accum_storage_t = typename accum_storage<Class, Bits, Elems>::type;

template <> struct accum_storage<AccumClass::Int,  32,   8> { using type =                 v8acc32; static type undef() { return undef_v8acc32();                                                            } };
template <> struct accum_storage<AccumClass::Int,  32,  16> { using type =                v16acc32; static type undef() { return undef_v16acc32();                                                           } };
template <> struct accum_storage<AccumClass::Int,  32,  32> { using type =                v32acc32; static type undef() { return undef_v32acc32();                                                           } };
template <> struct accum_storage<AccumClass::Int,  32,  64> { using type = std::array<v32acc32, 2>; static type undef() { return { undef_v32acc32(), undef_v32acc32()                                     }; } };
template <> struct accum_storage<AccumClass::Int,  32, 128> { using type = std::array<v32acc32, 4>; static type undef() { return { undef_v32acc32(), undef_v32acc32(), undef_v32acc32(), undef_v32acc32() }; } };

template <> struct accum_storage<AccumClass::Int,  64,   4> { using type =                 v4acc64; static type undef() { return undef_v4acc64();                                                            } };
template <> struct accum_storage<AccumClass::Int,  64,   8> { using type =                 v8acc64; static type undef() { return undef_v8acc64();                                                            } };
template <> struct accum_storage<AccumClass::Int,  64,  16> { using type =                v16acc64; static type undef() { return undef_v16acc64();                                                           } };
template <> struct accum_storage<AccumClass::Int,  64,  32> { using type = std::array<v16acc64, 2>; static type undef() { return { undef_v16acc64(), undef_v16acc64()                                     }; } };
template <> struct accum_storage<AccumClass::Int,  64,  64> { using type = std::array<v16acc64, 4>; static type undef() { return { undef_v16acc64(), undef_v16acc64(), undef_v16acc64(), undef_v16acc64() }; } };

template <> struct accum_storage<AccumClass::CInt, 64,   2> { using type =                v2cacc64; static type undef() { return undef_v2cacc64();                                                           } };
template <> struct accum_storage<AccumClass::CInt, 64,   4> { using type =                v4cacc64; static type undef() { return undef_v4cacc64();                                                           } };
template <> struct accum_storage<AccumClass::CInt, 64,   8> { using type =                v8cacc64; static type undef() { return undef_v8cacc64();                                                           } };
template <> struct accum_storage<AccumClass::CInt, 64,  16> { using type = std::array<v8cacc64, 2>; static type undef() { return { undef_v8cacc64(), undef_v8cacc64()                                     }; } };
template <> struct accum_storage<AccumClass::CInt, 64,  32> { using type = std::array<v8cacc64, 4>; static type undef() { return { undef_v8cacc64(), undef_v8cacc64(), undef_v8cacc64(), undef_v8cacc64() }; } };

template <> struct accum_storage<AccumClass::FP,   32,   4> { using type =                 v8accfloat; static type undef() { return undef_v8accfloat();                                                                      } };
template <> struct accum_storage<AccumClass::FP,   32,   8> { using type =                 v8accfloat; static type undef() { return undef_v8accfloat();                                                                      } };
template <> struct accum_storage<AccumClass::FP,   32,  16> { using type =                v16accfloat; static type undef() { return undef_v16accfloat();                                                                     } };
template <> struct accum_storage<AccumClass::FP,   32,  32> { using type =                v32accfloat; static type undef() { return undef_v32accfloat();                                                                     } };
template <> struct accum_storage<AccumClass::FP,   32,  64> { using type = std::array<v32accfloat, 2>; static type undef() { return { undef_v32accfloat(), undef_v32accfloat()                                           };  } };
template <> struct accum_storage<AccumClass::FP,   32, 128> { using type = std::array<v32accfloat, 4>; static type undef() { return { undef_v32accfloat(), undef_v32accfloat(), undef_v32accfloat(), undef_v32accfloat() };  } };

#if __AIE_API_COMPLEX_FP32_EMULATION__
template <> struct accum_storage<AccumClass::CFP,  32,   2> { using type =                 v4caccfloat; static type undef() { return undef_v4caccfloat();                                                                        } };
template <> struct accum_storage<AccumClass::CFP,  32,   4> { using type =                 v4caccfloat; static type undef() { return undef_v4caccfloat();                                                                        } };
template <> struct accum_storage<AccumClass::CFP,  32,   8> { using type =                 v8caccfloat; static type undef() { return undef_v8caccfloat();                                                                        } };
template <> struct accum_storage<AccumClass::CFP,  32,  16> { using type =                v16caccfloat; static type undef() { return undef_v16caccfloat();                                                                       } };
template <> struct accum_storage<AccumClass::CFP,  32,  32> { using type = std::array<v16caccfloat, 2>; static type undef() { return { undef_v16caccfloat(), undef_v16caccfloat()                                             }; } };
template <> struct accum_storage<AccumClass::CFP,  32,  64> { using type = std::array<v16caccfloat, 4>; static type undef() { return { undef_v16caccfloat(), undef_v16caccfloat(), undef_v16caccfloat(), undef_v16caccfloat() }; } };
#endif

template <typename T> struct native_accum_traits;

template <> struct native_accum_traits<     v8acc32> { using value_type =     acc32; static constexpr unsigned size =  8; };
template <> struct native_accum_traits<    v16acc32> { using value_type =     acc32; static constexpr unsigned size = 16; };
template <> struct native_accum_traits<    v32acc32> { using value_type =     acc32; static constexpr unsigned size = 32; };

template <> struct native_accum_traits<     v4acc64> { using value_type =     acc64; static constexpr unsigned size =  4; };
template <> struct native_accum_traits<     v8acc64> { using value_type =     acc64; static constexpr unsigned size =  8; };
template <> struct native_accum_traits<    v16acc64> { using value_type =     acc64; static constexpr unsigned size = 16; };

template <> struct native_accum_traits<    v2cacc64> { using value_type =    cacc64; static constexpr unsigned size =  2; };
template <> struct native_accum_traits<    v4cacc64> { using value_type =    cacc64; static constexpr unsigned size =  4; };
template <> struct native_accum_traits<    v8cacc64> { using value_type =    cacc64; static constexpr unsigned size =  8; };

template <> struct native_accum_traits<  v8accfloat> { using value_type =  accfloat; static constexpr unsigned size =  8; };
template <> struct native_accum_traits< v16accfloat> { using value_type =  accfloat; static constexpr unsigned size = 16; };
template <> struct native_accum_traits< v32accfloat> { using value_type =  accfloat; static constexpr unsigned size = 32; };

#if __AIE_API_COMPLEX_FP32_EMULATION__
template <> struct native_accum_traits< v4caccfloat> { using value_type = caccfloat; static constexpr unsigned size =  4; };
template <> struct native_accum_traits< v8caccfloat> { using value_type = caccfloat; static constexpr unsigned size =  8; };
template <> struct native_accum_traits<v16caccfloat> { using value_type = caccfloat; static constexpr unsigned size = 16; };
#endif

} // namespace aie::detail

#endif // __AIE_API_DETAIL_AIE2_ACCUM_NATIVE_TYPES__HPP__

