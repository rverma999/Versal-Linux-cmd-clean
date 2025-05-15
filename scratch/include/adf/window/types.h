// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef __TYPES_H__
#define __TYPES_H__
#include <stdint.h>


// raw window for compiler / testbench manipulations
struct window_internal;

#define INT_TYPEDEF(type) \
  typedef type ## _t type ;

#if !defined(__AIENGINE__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
struct int4_t {};
struct uint4_t {};
struct bfloat16
{
  // Converts float to bfloat16 using round-nearest-to-even as rounding mode.
  // https://hhhhhojeihsu.github.io/tensorflow_1.8_woboq/tensorflow_1.8_xla/tensorflow/tensorflow/core/lib/bfloat16/bfloat16.h.html
  static uint16_t floatToBfloat16(float value) noexcept {
    uint32_t hexValue = *reinterpret_cast<uint32_t*>(&value);
    uint32_t lsb = (hexValue >> 16) & 1;
    hexValue += 0x7fff + lsb;
    return (static_cast<uint16_t>(hexValue >> 16)) ;
  }
  static float bfloat16ToFloat(uint16_t hexValue) noexcept {
    uint32_t floatValue = (uint32_t) hexValue;
    floatValue <<= 16;
    return *reinterpret_cast<float*>(&floatValue);
  }
  constexpr bfloat16() noexcept
  : data(0)
  {
  }
  bfloat16(float fval) noexcept
  : data(floatToBfloat16(fval))
  {
  }
  explicit bfloat16(uint16_t uval) noexcept
  : data(uval)
  {
  }
  bfloat16(bfloat16 const &other)
      : data(other.data)
  {
  }
  bfloat16 &operator= (bfloat16 const &other)
  {
    data = other.data;
    return *this;
  }
  operator float() const
  {
    return bfloat16ToFloat(data);
  }
  uint16_t data;
};
struct float16
{
  // Converts float point to float16, with round-nearest-to-even as rounding method.
  // https://stackoverflow.com/questions/1659440/32-bit-to-16-bit-floating-point-conversion
  static uint16_t floatToFloat16(float value) {
      uint32_t hexValue = *reinterpret_cast<uint32_t*>(&value);
      hexValue += 0x00001000;
      uint32_t e = (hexValue & 0x7F800000) >> 23;
      uint32_t m = hexValue & 0x007FFFFF;
      return (hexValue & 0x80000000) >> 16 | 
             (e > 112) * ((((e - 112) << 10) & 0x7C00) | m >> 13) | 
             ((e < 113) & (e > 101)) * ((((0x007FF000 + m) >> (125 - e)) + 1) >> 1) | 
             (e > 143) * 0x7FFF;
  }

  static float float16ToFloat(uint16_t hexValue) {
      uint32_t e = (hexValue & 0x7C00) >> 10;
      uint32_t m = (hexValue & 0x03FF) << 13;
      float temp = (float)m;
      uint32_t v = *reinterpret_cast<uint32_t*>(&temp) >> 23;
      uint32_t floatValue = (hexValue & 0x8000) << 16 | (e != 0) * ((e + 112) << 23 | m) | 
                        ((e == 0) & (m != 0)) * ((v - 37) << 23 | ((m << (150 - v)) & 0x007FE000));
      return *reinterpret_cast<float*>(&floatValue);
  }
  constexpr float16() noexcept
  : data(0.0)
  {
  }
  float16(float fval) noexcept
      : data(floatToFloat16(fval))
  {
  }
  explicit float16(uint16_t uval) noexcept
      : data(uval)
  {
  }
  float16(float16 const &other)
      : data(other.data)
  {
  }
  float16(float16 &&other)
      : data(other.data)
  {
  }
  float16 &operator= (float16 const &other)
  {
    data = other.data;
    return *this;
  }
  operator float() const
  {
    return float16ToFloat(data);
  }
  uint16_t data;
};

struct bfloat8 {
  // conversion of float16 to bfloat8 is similar to that of float to bfloat16.
  static uint8_t floatToBfloat8(float value) {
      uint16_t hexValue = float16::floatToFloat16(value);
      uint16_t lsb = (hexValue >> 8) & 1;
      hexValue += 0x7F + lsb;
      return static_cast<uint8_t>(hexValue >> 8);
  }

  // convert bfloat8 to float16 and then float16 to float.
  static float bfloat8ToFloat(uint8_t hexValue) {
      uint16_t float16Value = *reinterpret_cast<uint16_t*>(&hexValue);
      // left shift by 8 to convert to 16 bit floating point
      float16Value <<= 8;
      return float16::float16ToFloat(float16Value);
  }
  constexpr bfloat8() noexcept
      : data(0)
  {
  }
  bfloat8(float fval) noexcept
      : data(floatToBfloat8(fval))
  {
  }
  explicit bfloat8(uint8_t uval) noexcept
      : data(uval)
  {
  }
  bfloat8(bfloat8 const &other)
      : data(other.data)
  {
  }
  bfloat8 &operator= (bfloat8 const &other)
  {
    data = other.data;
    return *this;
  }
  operator float() const
  {
    return bfloat8ToFloat(data);
  }
  uint8_t data; 
};

struct float8 {
static uint8_t floatToFloat8(float value) {
    uint32_t hexValue = *reinterpret_cast<uint32_t*>(&value);
    hexValue += 0x00080000;
    uint32_t e = (hexValue & 0x7F800000) >> 23;
    uint32_t m = hexValue & 0x007FFFFF;
    return ((hexValue & 0x80000000) >> 24 |
           (e > 120) * ((((e - 120) << 3) & 0x78) | m >> 20) |
           ((e < 121) & (e > 116)) * ((((0x00780000 + m) >> (140 - e)) + 1) >> 1) |
           (e > 135) * (0x7F));

  }

  static float float8ToFloat(uint8_t hexValue) {
    uint32_t e = (hexValue & 0x78) >> 3;
    uint32_t m = (hexValue & 0x07) << 20;
    float temp = (float)m;
    uint32_t v = *reinterpret_cast<uint32_t*>(&temp) >> 23;
    uint32_t floatValue = (hexValue & 0x80) << 24 | (e != 0) * ((e + 120) << 23| m) |
                          ((e == 0) & (m != 0)) * ((v - 29) << 23 | ((m << (150-v)) & 0x00700000));
    return *reinterpret_cast<float*>(&floatValue);
  }
  constexpr float8() noexcept
      : data(0)
  {
  }
  float8(float fval) noexcept
      : data(floatToFloat8(fval))
  {
  }
  explicit float8(uint8_t uval) noexcept
      : data(uval)
  {
  }
  float8(float8 const &other) noexcept
      : data(other.data)
  {
  }
  float8 &operator= (float8 const &other)
  {
    data = other.data;
    return *this;
  }
  operator float() const
  {
    return float8ToFloat(data);
  } 
  uint8_t data;
};
#pragma clang diagnostic pop
#endif // !defined(__AIENGINE__)

#if __AIE_ARCH__ >= 20
  INT_TYPEDEF(int4)
  INT_TYPEDEF(uint4)
#endif // __AIE_ARCH__ >= 20

  INT_TYPEDEF(int8)
  INT_TYPEDEF(int16)
  INT_TYPEDEF(int32)

  INT_TYPEDEF(uint8)
  INT_TYPEDEF(uint16)
  INT_TYPEDEF(uint32)
  
#if !defined(_WIN32) && defined(__x86_64__)
  #if !defined(SYSTEMC_H)
    typedef long long int64;
    typedef unsigned long long uint64;
  #endif
#else
  INT_TYPEDEF(int64)
  INT_TYPEDEF(uint64)
#endif

#undef INT_TYPEDEF

#include "adf/window/complexint.h"
#include "adf/window/acc_types.h"

template<typename T> struct input_window;
template<typename T> struct output_window;

typedef input_window<int8> input_window_int8;
typedef input_window<uint8> input_window_uint8;
typedef input_window<int16> input_window_int16;
typedef input_window<uint16> input_window_uint16;
typedef input_window<int32> input_window_int32;
typedef input_window<uint32> input_window_uint32;
typedef input_window<int64> input_window_int64;
typedef input_window<uint64> input_window_uint64;
typedef input_window<float> input_window_float;
typedef input_window<cint16> input_window_cint16;
typedef input_window<cint32> input_window_cint32;
#if __AIE_ARCH__<20
typedef input_window<cfloat> input_window_cfloat;
#endif

typedef output_window<int8> output_window_int8;
typedef output_window<uint8> output_window_uint8;
typedef output_window<int16> output_window_int16;
typedef output_window<uint16> output_window_uint16;
typedef output_window<int32> output_window_int32;
typedef output_window<uint32> output_window_uint32;
typedef output_window<int64> output_window_int64;
typedef output_window<uint64> output_window_uint64;
typedef output_window<float> output_window_float;
typedef output_window<cint16> output_window_cint16;
typedef output_window<cint32> output_window_cint32;
#if __AIE_ARCH__<20
typedef output_window<cfloat> output_window_cfloat;
#endif

#endif // __TYPES_H__
