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

#ifndef __AIE_API_DETAIL_AIE1_ACCUM_NATIVE_TYPES__HPP__
#define __AIE_API_DETAIL_AIE1_ACCUM_NATIVE_TYPES__HPP__

namespace aie::detail {

template <typename AccumTag>
struct accum_native_type;

template <> struct accum_native_type<acc16>    { using type = acc48; };
template <> struct accum_native_type<acc24>    { using type = acc48; };
template <> struct accum_native_type<acc32>    { using type = acc48; };
template <> struct accum_native_type<acc40>    { using type = acc48; };
template <> struct accum_native_type<acc48>    { using type = acc48; };

template <> struct accum_native_type<acc56>    { using type = acc80; };
template <> struct accum_native_type<acc64>    { using type = acc80; };
template <> struct accum_native_type<acc72>    { using type = acc80; };
template <> struct accum_native_type<acc80>    { using type = acc80; };

template <> struct accum_native_type<cacc16>   { using type = cacc48; };
template <> struct accum_native_type<cacc24>   { using type = cacc48; };
template <> struct accum_native_type<cacc32>   { using type = cacc48; };
template <> struct accum_native_type<cacc40>   { using type = cacc48; };
template <> struct accum_native_type<cacc48>   { using type = cacc48; };

template <> struct accum_native_type<cacc56>   { using type = cacc80; };
template <> struct accum_native_type<cacc64>   { using type = cacc80; };
template <> struct accum_native_type<cacc72>   { using type = cacc80; };
template <> struct accum_native_type<cacc80>   { using type = cacc80; };

template <> struct accum_native_type<accfloat>  { using type = accfloat; };
template <> struct accum_native_type<caccfloat> { using type = caccfloat; };

template <typename AccumTag>
struct accum_class_for_tag;

template <> struct accum_class_for_tag<exact_acc48>  { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <> struct accum_class_for_tag<exact_acc80>  { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <> struct accum_class_for_tag<exact_cacc48> { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <> struct accum_class_for_tag<exact_cacc80> { static constexpr AccumClass value() { return AccumClass::CInt; } };

template <typename AccumTag>
struct accum_bits_for_tag;

template <> struct accum_bits_for_tag<exact_acc48>   { static constexpr unsigned value() { return 48; } };
template <> struct accum_bits_for_tag<exact_acc80>   { static constexpr unsigned value() { return 80; } };
template <> struct accum_bits_for_tag<exact_cacc48>  { static constexpr unsigned value() { return 48; } };
template <> struct accum_bits_for_tag<exact_cacc80>  { static constexpr unsigned value() { return 80; } };

// TODO: remove accum_class_for_type as it is mainly required in the context of multiplications,
// which is already handled by accum_class_for_mul_types
template <typename AccumTag>
struct accum_class_for_type;

template <> struct accum_class_for_type<int8>   { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <> struct accum_class_for_type<uint8>  { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <> struct accum_class_for_type<int16>  { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <> struct accum_class_for_type<int32>  { static constexpr AccumClass value() { return AccumClass::Int;  } };

template <> struct accum_class_for_type<cint16> { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <> struct accum_class_for_type<cint32> { static constexpr AccumClass value() { return AccumClass::CInt; } };

template <> struct accum_class_for_type<float>  { static constexpr AccumClass value() { return AccumClass::FP;   } };
template <> struct accum_class_for_type<cfloat> { static constexpr AccumClass value() { return AccumClass::CFP;  } };

template <typename T, typename U>
struct accum_class_for_mul_types;

template <typename T> struct accum_class_for_mul_types<T,      int8>   { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <typename T> struct accum_class_for_mul_types<T,      uint8>  { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <>           struct accum_class_for_mul_types<int8,   int16>  { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <>           struct accum_class_for_mul_types<uint8,  int16>  { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <>           struct accum_class_for_mul_types<int16,  int16>  { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <>           struct accum_class_for_mul_types<int16,  int32>  { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <>           struct accum_class_for_mul_types<int32,  int16>  { static constexpr AccumClass value() { return AccumClass::Int;  } };
template <>           struct accum_class_for_mul_types<int32,  int32>  { static constexpr AccumClass value() { return AccumClass::Int;  } };

template <>           struct accum_class_for_mul_types<cint16, cint16> { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <>           struct accum_class_for_mul_types<cint16,  int16> { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <>           struct accum_class_for_mul_types< int16, cint16> { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <>           struct accum_class_for_mul_types<cint16,  int32> { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <>           struct accum_class_for_mul_types< int32, cint16> { static constexpr AccumClass value() { return AccumClass::CInt; } };

template <>           struct accum_class_for_mul_types<cint32, cint32> { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <>           struct accum_class_for_mul_types<cint32,  int16> { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <>           struct accum_class_for_mul_types< int16, cint32> { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <>           struct accum_class_for_mul_types<cint32,  int32> { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <>           struct accum_class_for_mul_types< int32, cint32> { static constexpr AccumClass value() { return AccumClass::CInt; } };

template <>           struct accum_class_for_mul_types<cint32, cint16> { static constexpr AccumClass value() { return AccumClass::CInt; } };
template <>           struct accum_class_for_mul_types<cint16, cint32> { static constexpr AccumClass value() { return AccumClass::CInt; } };

template <>           struct accum_class_for_mul_types<float,  float>  { static constexpr AccumClass value() { return AccumClass::FP;   } };

template <>           struct accum_class_for_mul_types<cfloat, cfloat> { static constexpr AccumClass value() { return AccumClass::CFP;  } };
template <>           struct accum_class_for_mul_types< float, cfloat> { static constexpr AccumClass value() { return AccumClass::CFP;  } };
template <>           struct accum_class_for_mul_types<cfloat,  float> { static constexpr AccumClass value() { return AccumClass::CFP;  } };

template <AccumClass Class, unsigned Bits, unsigned Elems>
struct accum_storage;

template <AccumClass Class, unsigned Bits, unsigned Elems>
using accum_storage_t = typename accum_storage<Class, Bits, Elems>::type;

template <> struct accum_storage<AccumClass::Int,  48,   8> { using type =                 v8acc48; static type undef() { return undef_v8acc48();                                                            } };
template <> struct accum_storage<AccumClass::Int,  48,  16> { using type =                v16acc48; static type undef() { return undef_v16acc48();                                                           } };
template <> struct accum_storage<AccumClass::Int,  48,  32> { using type = std::array<v16acc48, 2>; static type undef() { return { undef_v16acc48(), undef_v16acc48()                                     }; } };
template <> struct accum_storage<AccumClass::Int,  48,  64> { using type = std::array<v16acc48, 4>; static type undef() { return { undef_v16acc48(), undef_v16acc48(), undef_v16acc48(), undef_v16acc48() }; } };
template <> struct accum_storage<AccumClass::Int,  48, 128> { using type = std::array<v16acc48, 8>; static type undef() { return { undef_v16acc48(), undef_v16acc48(), undef_v16acc48(), undef_v16acc48(),
                                                                                                                                   undef_v16acc48(), undef_v16acc48(), undef_v16acc48(), undef_v16acc48() }; } };

template <> struct accum_storage<AccumClass::Int,  80,   4> { using type =                 v4acc80; static type undef() { return undef_v4acc80();                                                            } };
template <> struct accum_storage<AccumClass::Int,  80,   8> { using type =                 v8acc80; static type undef() { return undef_v8acc80();                                                            } };
template <> struct accum_storage<AccumClass::Int,  80,  16> { using type =  std::array<v8acc80, 2>; static type undef() { return { undef_v8acc80(),  undef_v8acc80()                                      }; } };
template <> struct accum_storage<AccumClass::Int,  80,  32> { using type =  std::array<v8acc80, 4>; static type undef() { return { undef_v8acc80(),  undef_v8acc80(),  undef_v8acc80(),  undef_v8acc80()  }; } };
template <> struct accum_storage<AccumClass::Int,  80,  64> { using type =  std::array<v8acc80, 8>; static type undef() { return { undef_v8acc80(),  undef_v8acc80(),  undef_v8acc80(),  undef_v8acc80(),
                                                                                                                                   undef_v8acc80(),  undef_v8acc80(),  undef_v8acc80(),  undef_v8acc80()  }; } };

template <> struct accum_storage<AccumClass::CInt, 48,   4> { using type =                v4cacc48; static type undef() { return undef_v4cacc48();                                                           } };
template <> struct accum_storage<AccumClass::CInt, 48,   8> { using type =                v8cacc48; static type undef() { return undef_v8cacc48();                                                           } };
template <> struct accum_storage<AccumClass::CInt, 48,  16> { using type = std::array<v8cacc48, 2>; static type undef() { return { undef_v8cacc48(), undef_v8cacc48()                                     }; } };
template <> struct accum_storage<AccumClass::CInt, 48,  32> { using type = std::array<v8cacc48, 4>; static type undef() { return { undef_v8cacc48(), undef_v8cacc48(), undef_v8cacc48(), undef_v8cacc48() }; } };
template <> struct accum_storage<AccumClass::CInt, 48,  64> { using type = std::array<v8cacc48, 8>; static type undef() { return { undef_v8cacc48(), undef_v8cacc48(), undef_v8cacc48(), undef_v8cacc48(),
                                                                                                                                   undef_v8cacc48(), undef_v8cacc48(), undef_v8cacc48(), undef_v8cacc48() }; } };

template <> struct accum_storage<AccumClass::CInt, 80,   2> { using type =                v2cacc80; static type undef() { return undef_v2cacc80();                                                           } };
template <> struct accum_storage<AccumClass::CInt, 80,   4> { using type =                v4cacc80; static type undef() { return undef_v4cacc80();                                                           } };
template <> struct accum_storage<AccumClass::CInt, 80,   8> { using type = std::array<v4cacc80, 2>; static type undef() { return { undef_v4cacc80(), undef_v4cacc80()                                     }; } };
template <> struct accum_storage<AccumClass::CInt, 80,  16> { using type = std::array<v4cacc80, 4>; static type undef() { return { undef_v4cacc80(), undef_v4cacc80(), undef_v4cacc80(), undef_v4cacc80() }; } };
template <> struct accum_storage<AccumClass::CInt, 80,  32> { using type = std::array<v4cacc80, 8>; static type undef() { return { undef_v4cacc80(), undef_v4cacc80(), undef_v4cacc80(), undef_v4cacc80(),
                                                                                                                                   undef_v4cacc80(), undef_v4cacc80(), undef_v4cacc80(), undef_v4cacc80() }; } };

template <> struct accum_storage<AccumClass::FP,   32,   4> { using type =                 v4accfloat; static type undef() { return undef_v4float();                                                         } };
template <> struct accum_storage<AccumClass::FP,   32,   8> { using type =                 v8accfloat; static type undef() { return undef_v8float();                                                         } };
template <> struct accum_storage<AccumClass::FP,   32,  16> { using type =                v16accfloat; static type undef() { return undef_v16float();                                                        } };
template <> struct accum_storage<AccumClass::FP,   32,  32> { using type = std::array<v16accfloat, 2>; static type undef() { return { undef_v16float(), undef_v16float()                                  }; } };

template <> struct accum_storage<AccumClass::CFP,  32,   2> { using type =                v2caccfloat; static type undef() { return undef_v2cfloat();                                                        } };
template <> struct accum_storage<AccumClass::CFP,  32,   4> { using type =                v4caccfloat; static type undef() { return undef_v4cfloat();                                                        } };
template <> struct accum_storage<AccumClass::CFP,  32,   8> { using type =                v8caccfloat; static type undef() { return undef_v8cfloat();                                                        } };
template <> struct accum_storage<AccumClass::CFP,  32,  16> { using type = std::array<v8caccfloat, 2>; static type undef() { return { undef_v8cfloat(), undef_v8cfloat()                                  }; } };


template <typename T> struct native_accum_traits;

template <> struct native_accum_traits<    v8acc48> { using value_type =     acc48; static constexpr unsigned size =  8; };
template <> struct native_accum_traits<   v16acc48> { using value_type =     acc48; static constexpr unsigned size = 16; };

template <> struct native_accum_traits<   v4cacc48> { using value_type =    cacc48; static constexpr unsigned size =  4; };
template <> struct native_accum_traits<   v8cacc48> { using value_type =    cacc48; static constexpr unsigned size =  8; };

template <> struct native_accum_traits<    v4acc80> { using value_type =     acc80; static constexpr unsigned size =  4; };
template <> struct native_accum_traits<    v8acc80> { using value_type =     acc80; static constexpr unsigned size =  8; };

template <> struct native_accum_traits<   v2cacc80> { using value_type =    cacc80; static constexpr unsigned size =  2; };
template <> struct native_accum_traits<   v4cacc80> { using value_type =    cacc80; static constexpr unsigned size =  4; };

template <> struct native_accum_traits< v4accfloat> { using value_type =  accfloat; static constexpr unsigned size =  4; };
template <> struct native_accum_traits< v8accfloat> { using value_type =  accfloat; static constexpr unsigned size =  8; };
template <> struct native_accum_traits<v16accfloat> { using value_type =  accfloat; static constexpr unsigned size = 16; };

template <> struct native_accum_traits<v2caccfloat> { using value_type = caccfloat; static constexpr unsigned size =  2; };
template <> struct native_accum_traits<v4caccfloat> { using value_type = caccfloat; static constexpr unsigned size =  4; };
template <> struct native_accum_traits<v8caccfloat> { using value_type = caccfloat; static constexpr unsigned size =  8; };

} // namespace aie::detail

#endif // __AIE_API_DETAIL_AIE1_ACCUM_NATIVE_TYPES__HPP__

