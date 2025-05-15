// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef _SRC_X86SIM_INCLUDE_STREAM_REDIRECT_H_
#define _SRC_X86SIM_INCLUDE_STREAM_REDIRECT_H_

#include<type_traits>
#include "streamUtils.h"

#if __AIE_ARCH__<20

v8acc48  __x86Sim_get_scd();
v4cacc48 __x86Sim_getc_scd();
v4acc80 __x86Sim_getl_scd ();
v2cacc80 __x86Sim_getlc_scd(); 
v8acc48 __x86Sim_get_scd_v8acc48 ();
v4cacc48 __x86Sim_get_scd_v4cacc48 ();
v4acc80 __x86Sim_get_scd_v4acc80 ();
v2cacc80 __x86Sim_get_scd_v2cacc80 (); 

v32int8 __x86Sim_get_scd_v32int8 ();
v32uint8 __x86Sim_get_scd_v32uint8 ();
v16int16 __x86Sim_get_scd_v16int16 ();
v8cint16 __x86Sim_get_scd_v8cint16 ();
v8int32 __x86Sim_get_scd_v8int32 ();
v4cint32 __x86Sim_get_scd_v4cint32 ();
v8float __x86Sim_get_scd_v8float ();
v4cfloat __x86Sim_get_scd_v4cfloat ();

int32 __x86Sim_get_ss(int idx);
float __x86Sim_getf_ss(int idx);
cint16 __x86Sim_getc_ss(int idx);

void write384bits(v8acc48 a);

template <typename streamTy>
static inline std::enable_if_t< x86sim::is_acc_data_type< streamTy > ||
                       x86sim::is_256bit_stream_data_type< streamTy > >
__x86Sim_put_mcd(streamTy val)
{
    if constexpr (x86sim::is_acc_data_type< streamTy >)
        write384bits(as_v8acc48(val));  
 
    // packa: This intrinsic sign extends each 32bit word to 48bit and then assigns
    // the result to a accumulator of the return type.
    // packa for complex types returns v4cacc48, we need to call __x86Sim_put_mcd 
    // to convert to v8acc48 so as to call write384bits(v8acc48 a).
    if constexpr (x86sim::is_256bit_stream_data_type< streamTy >)
        __x86Sim_put_mcd(packa(val));
        
}

void write32bits(int idx, int32 val, int tlast = 0);

template <typename streamTy>
static inline std::enable_if_t< x86sim::is_32bit_stream_data_type< streamTy >>
__x86Sim_put_ms(int idx, streamTy val, int tlast = 0)
{
    write32bits(idx, (int32) val, tlast);
}

v4int32 __x86Sim_getl_wss(int idx);
v16int8 __x86Sim_getb_wss(int idx);
v16uint8 __x86Sim_getub_wss(int idx);
v8int16 __x86Sim_get_wss(int idx);

v4float __x86Sim_getf_wss(int idx);
v2cfloat __x86Sim_getfc_wss(int idx);
v4cint16 __x86Sim_getc_wss(int idx);
v2cint32 __x86Sim_getlc_wss(int idx);


void write128bits(int idx, v4int32 val, int tlast = 0);

template <typename streamTy>
static inline std::enable_if_t< x86sim::is_128bit_stream_data_type< streamTy >>
__x86Sim_put_wms(int idx, streamTy val, int tlast = 0)
{
    write128bits(idx, as_v4int32(val), tlast);
}

void __x86Sim_put_ms_packet_header(int idx, int tlast, unsigned dstID, unsigned pcktType);
void __x86Sim_put_ms_packet_header(int idx, unsigned dstID, unsigned pcktType);
void __x86Sim_put_ms_ctrl_packet_header(int idx, int tlast, unsigned addr, 
                                        unsigned nWords, unsigned opType, unsigned rspID);
void __x86Sim_put_ms_ctrl_packet_header(int idx, unsigned addr, unsigned nWords, 
                                        unsigned opType, unsigned rspID);

#endif // #if __AIE_ARCH__<20

#if __AIE_ARCH__>=20

int read32bits(bool &tlast);

template <typename streamTy>
static inline std::enable_if_t<x86sim::is_32bit_stream_data_type<streamTy>, streamTy>
__x86Sim_get_ss()
{
    bool tlast;
    if constexpr (std::is_same_v<streamTy, float>)
        return as_float(read32bits(tlast));
    else if constexpr (std::is_same_v<streamTy, cint16>)
        return as_cint16(read32bits(tlast));
    else
    {
        int val = read32bits(tlast);
        return *reinterpret_cast<streamTy*>(&val);    
    }
}

template <typename streamTy>
static inline std::enable_if_t<x86sim::is_32bit_stream_data_type<streamTy>, streamTy>
__x86Sim_get_ss(bool &tlast)
{
    if constexpr (std::is_same_v<streamTy, float>)
        return as_float(read32bits(tlast));
    else if constexpr (std::is_same_v<streamTy, cint16>)
        return as_cint16(read32bits(tlast));
    else
    {
        int val = read32bits(tlast);
        return *reinterpret_cast<streamTy*>(&val);    
    }
}


v4int32 read128bits(bool &tlast);
v8int32 read256bits(bool &tlast);
v16int32 read512bits(bool &tlast);
v32int32 read1024bits(bool &tlast);

template <typename streamTy>
static inline std::enable_if_t<
              x86sim::is_128bit_stream_data_type<streamTy> ||
              x86sim::is_256bit_stream_data_type<streamTy> ||
              x86sim::is_512bit_stream_data_type<streamTy> ||
              x86sim::is_1024bit_stream_data_type<streamTy>, streamTy >
__x86Sim_get_ss()
{
    bool tlast;
    
    if constexpr (x86sim::is_128bit_stream_data_type<streamTy>)
        return (streamTy)read128bits(tlast);
    if constexpr (x86sim::is_256bit_stream_data_type<streamTy>)
        return (streamTy)read256bits(tlast);
    if constexpr (x86sim::is_512bit_stream_data_type<streamTy>)
        return (streamTy)read512bits(tlast);
    if constexpr (x86sim::is_1024bit_stream_data_type<streamTy>)
        return (streamTy)read1024bits(tlast);
}

template <typename streamTy>
static inline std::enable_if_t<
              x86sim::is_128bit_stream_data_type<streamTy> ||
              x86sim::is_256bit_stream_data_type<streamTy> ||
              x86sim::is_512bit_stream_data_type<streamTy> ||
              x86sim::is_1024bit_stream_data_type<streamTy>, streamTy >
__x86Sim_get_ss(bool &tlast)
{
    if constexpr (x86sim::is_128bit_stream_data_type<streamTy>)
        return (streamTy)read128bits(tlast);
    if constexpr (x86sim::is_256bit_stream_data_type<streamTy>)
        return (streamTy)read256bits(tlast);
    if constexpr (x86sim::is_512bit_stream_data_type<streamTy>)
        return (streamTy)read512bits(tlast);
    if constexpr (x86sim::is_1024bit_stream_data_type<streamTy>)
        return (streamTy)read1024bits(tlast);
}


void write32bits(int val, int tlast);
template <typename streamTy>
static inline std::enable_if_t< x86sim::is_32bit_stream_data_type< streamTy >>
__x86Sim_put_ms(streamTy val, int tlast = 0)
{
    if constexpr (std::is_same_v<streamTy, float> || 
                  std::is_same_v<streamTy, cint16>)
        write32bits(as_int32(val), tlast);
    // Needed for aie::vector
    else if constexpr (std::is_constructible<int, streamTy>::value)
        write32bits((int32) val, tlast);
    else
        write32bits(( *reinterpret_cast<int32*>(&val)), tlast);
}

void write128bits(v4int32 val, int tlast);
void write256bits(v8int32 val, int tlast);
void write512bits(v16int32 val, int tlast);
void write1024bits(v32int32 val, int tlast);

template <typename streamTy>
static inline std::enable_if_t<
              x86sim::is_128bit_stream_data_type<streamTy> ||
              x86sim::is_256bit_stream_data_type<streamTy> ||
              x86sim::is_512bit_stream_data_type<streamTy> ||
              x86sim::is_1024bit_stream_data_type<streamTy>>
__x86Sim_put_ms(streamTy val, int tlast)
{
    if constexpr (x86sim::is_128bit_stream_data_type<streamTy>)
        write128bits((v4int32)(val), tlast);
    if constexpr (x86sim::is_256bit_stream_data_type<streamTy>)
        write256bits((v8int32)(val), tlast);
    if constexpr (x86sim::is_512bit_stream_data_type<streamTy>)
        write512bits((v16int32)(val), tlast);
    if constexpr (x86sim::is_1024bit_stream_data_type<streamTy>)
        write1024bits((v32int32)(val), tlast);
}

template <typename streamTy>
static inline std::enable_if_t<
              x86sim::is_128bit_stream_data_type<streamTy> ||
              x86sim::is_256bit_stream_data_type<streamTy> ||
              x86sim::is_512bit_stream_data_type<streamTy> ||
              x86sim::is_1024bit_stream_data_type<streamTy>>
__x86Sim_put_ms(streamTy val, int en, int tlast)
{
    if constexpr (x86sim::is_128bit_stream_data_type<streamTy>)
        write128bits((v4int32)(val), tlast);
    if constexpr (x86sim::is_256bit_stream_data_type<streamTy>)
        write256bits((v8int32)(val), tlast);
    if constexpr (x86sim::is_512bit_stream_data_type<streamTy>)
        write512bits((v16int32)(val), tlast);
    if constexpr (x86sim::is_1024bit_stream_data_type<streamTy>)
        write1024bits((v32int32)(val), tlast);
}

void __x86Sim_put_ms_packet_header(int tlast, unsigned dstID, unsigned pcktType);
void __x86Sim_put_ms_packet_header(unsigned dstID, unsigned pcktType);
void __x86Sim_put_ms_ctrl_packet_header(int tlast, unsigned addr, 
                             unsigned nWords, unsigned opType, unsigned rspID);
void __x86Sim_put_ms_ctrl_packet_header(unsigned addr, unsigned nWords, 
                                        unsigned opType, unsigned rspID);
unsigned int __x86Sim_packet_header (unsigned dstID, unsigned pcktType);
unsigned int __x86Sim_ctrl_packet_header (unsigned addr, unsigned nWords, 
                                          unsigned opType, unsigned rspID);

v16acc32 read512bits_from_acc_stream(int en);
v32acc32 read1024bits_from_acc_stream(int en);

template <typename streamTy>
static inline std::enable_if_t<
              x86sim::is_512bit_acc_data_type<streamTy> || 
              x86sim::is_1024bit_acc_data_type<streamTy>, streamTy>
__x86Sim_get_scd(int en = 1)
{
    if constexpr (x86sim::is_512bit_acc_data_type<streamTy>)
        return (streamTy)read512bits_from_acc_stream(en);
    if constexpr (x86sim::is_1024bit_acc_data_type<streamTy>)
        return (streamTy)read1024bits_from_acc_stream(en);
}

#if __AIE_ARCH__ > 20

v64acc32 read2048bits_from_acc_stream(int en);

template <typename streamTy>
static inline std::enable_if_t<x86sim::is_2048bit_acc_data_type<streamTy>, streamTy>
__x86Sim_get_scd(int en = 1)
{
    return (streamTy)read2048bits_from_acc_stream(en);
}
#endif // #if __AIE_ARCH__ > 20

void write512bits_to_acc_stream(v16acc32 a, int en);
void write1024bits_to_acc_stream(v32acc32 a, int en);

template <typename streamTy>
static inline std::enable_if_t< 
              x86sim::is_512bit_acc_data_type< streamTy > ||
              x86sim::is_1024bit_acc_data_type< streamTy >>
__x86Sim_put_mcd(streamTy val, int en = 1)
{
    if constexpr (x86sim::is_512bit_acc_data_type<streamTy>)
        write512bits_to_acc_stream((v16acc32)val, en);
    if constexpr (x86sim::is_1024bit_acc_data_type<streamTy>)
        write1024bits_to_acc_stream((v32acc32)val, en);
}


v32acc32 __x86Sim_get_scd_v32acc32_lo(int en = 1);
v32acc32 __x86Sim_get_scd_v32acc32_hi(int en = 1);
v16acc64 __x86Sim_get_scd_v16acc64_lo(int en = 1);
v16acc64 __x86Sim_get_scd_v16acc64_hi(int en = 1);

#if __AIE_ARCH__ > 20

v32accfloat __x86Sim_get_scd_v32accfloat_lo(int en = 1);
v32accfloat __x86Sim_get_scd_v32accfloat_hi(int en = 1);

v64acc32 __x86Sim_get_scd_v64acc32_0(int en = 1);
v64acc32 __x86Sim_get_scd_v64acc32_1(int en = 1);
v64acc32 __x86Sim_get_scd_v64acc32_2(int en = 1);
v64acc32 __x86Sim_get_scd_v64acc32_3(int en = 1);

v32acc64 __x86Sim_get_scd_v32acc64_0(int en = 1);
v32acc64 __x86Sim_get_scd_v32acc64_1(int en = 1);
v32acc64 __x86Sim_get_scd_v32acc64_2(int en = 1);
v32acc64 __x86Sim_get_scd_v32acc64_3(int en = 1);

v64accfloat __x86Sim_get_scd_v64accfloat_0(int en = 1);
v64accfloat __x86Sim_get_scd_v64accfloat_1(int en = 1);
v64accfloat __x86Sim_get_scd_v64accfloat_2(int en = 1);
v64accfloat __x86Sim_get_scd_v64accfloat_3(int en = 1);

v32acc32 __x86Sim_get_scd_expand_v32acc32_incr(int en, int& pos);
v16acc64 __x86Sim_get_scd_expand_v16acc64_incr(int en, int& pos);
v32accfloat __x86Sim_get_scd_expand_v32accfloat_incr(int en, int& pos);

v32acc32 __x86Sim_get_scd_expand_v32acc32_incr(int& pos);
v16acc64 __x86Sim_get_scd_expand_v16acc64_incr(int& pos);
v32accfloat __x86Sim_get_scd_expand_v32accfloat_incr(int& pos);

v32acc32 __x86Sim_get_scd_expand_v32acc32(int en, int pos);
v16acc64 __x86Sim_get_scd_expand_v16acc64(int en, int pos);
v32accfloat __x86Sim_get_scd_expand_v32accfloat(int en, int pos);

v32acc32 __x86Sim_get_scd_expand_v32acc32(int pos);
v16acc64 __x86Sim_get_scd_expand_v16acc64(int pos);
v32accfloat __x86Sim_get_scd_expand_v32accfloat(int pos);

#if __AIE_ARCH__ == 22
v8cacc64 __x86Sim_get_scd_expand_v8cacc64(int en, int pos);
v8cacc64 __x86Sim_get_scd_expand_v8cacc64(int pos);
#endif

v64acc32 __x86Sim_get_scd_expand_v64acc32_incr(int en, int& pos);
v32acc64 __x86Sim_get_scd_expand_v32acc64_incr(int en, int& pos);
v64accfloat __x86Sim_get_scd_expand_v64accfloat_incr(int en, int& pos);

v64acc32 __x86Sim_get_scd_expand_v64acc32_incr(int& pos);
v32acc64 __x86Sim_get_scd_expand_v32acc64_incr(int& pos);
v64accfloat __x86Sim_get_scd_expand_v64accfloat_incr(int& pos);

v64acc32 __x86Sim_get_scd_expand_v64acc32(int en, int pos);
v32acc64 __x86Sim_get_scd_expand_v32acc64(int en, int pos);
v64accfloat __x86Sim_get_scd_expand_v64accfloat(int en, int pos);

v64acc32 __x86Sim_get_scd_expand_v64acc32(int pos);
v32acc64 __x86Sim_get_scd_expand_v32acc64(int pos);
v64accfloat __x86Sim_get_scd_expand_v64accfloat(int pos);

#endif

#endif // #if __AIE_ARCH__>=20

#if __AIE_ARCH__<20

#define get_scd __x86Sim_get_scd
#define getc_scd __x86Sim_getc_scd
#define getl_scd __x86Sim_getl_scd
#define getlc_scd __x86Sim_getlc_scd
#define get_scd_v8acc48 __x86Sim_get_scd_v8acc48
#define get_scd_v4cacc48 __x86Sim_get_scd_v4cacc48
#define get_scd_v4acc80 __x86Sim_get_scd_v4acc80
#define get_scd_v2cacc80 __x86Sim_get_scd_v2cacc80

#define get_scd_v32int8 __x86Sim_get_scd_v32int8
#define get_scd_v32uint8 __x86Sim_get_scd_v32uint8
#define get_scd_v16int16 __x86Sim_get_scd_v16int16
#define get_scd_v8cint16 __x86Sim_get_scd_v8cint16
#define get_scd_v8int32 __x86Sim_get_scd_v8int32
#define get_scd_v4cint32 __x86Sim_get_scd_v4cint32
#define get_scd_v8float __x86Sim_get_scd_v8float
#define get_scd_v4cfloat __x86Sim_get_scd_v4cfloat

#define get_ss __x86Sim_get_ss
#define getf_ss __x86Sim_getf_ss
#define getc_ss __x86Sim_getc_ss

#define getl_wss __x86Sim_getl_wss
#define getb_wss __x86Sim_getb_wss
#define getub_wss __x86Sim_getub_wss
#define getf_wss __x86Sim_getf_wss
#define getfc_wss __x86Sim_getfc_wss
#define get_wss __x86Sim_get_wss
#define getc_wss __x86Sim_getc_wss
#define getlc_wss __x86Sim_getlc_wss

#define put_wms __x86Sim_put_wms

#endif

#if __AIE_ARCH__ >= 20

#define get_ss __x86Sim_get_ss<int>
#define get_ss_int __x86Sim_get_ss<int>
#define get_ss_uint __x86Sim_get_ss<unsigned int>
#define getf_ss __x86Sim_get_ss<float>
#define get_ss_float __x86Sim_get_ss<float>
#define get_ss_v8int4 __x86Sim_get_ss<v8int4>
#define get_ss_v8uint4 __x86Sim_get_ss<v8uint4>
#define get_ss_v4int8 __x86Sim_get_ss<v4int8>
#define get_ss_v4uint8 __x86Sim_get_ss<v4uint8>
#define get_ss_v2int16 __x86Sim_get_ss<v2int16>
#define get_ss_v2uint16 __x86Sim_get_ss<v2uint16>
#define get_ss_cint16 __x86Sim_get_ss<cint16>
#define get_ss_v2bfloat16 __x86Sim_get_ss<v2bfloat16>

#define get_ss_v4int32 __x86Sim_get_ss<v4int32>
#define get_ss_v32int4 __x86Sim_get_ss<v32int4>
#define get_ss_v32uint4 __x86Sim_get_ss<v32uint4>
#define get_ss_v16int8 __x86Sim_get_ss<v16int8>
#define get_ss_v16uint8 __x86Sim_get_ss<v16uint8>
#define get_ss_v8int16 __x86Sim_get_ss<v8int16>
#define get_ss_v8uint16 __x86Sim_get_ss<v8uint16>
#define get_ss_v4cint16 __x86Sim_get_ss<v4cint16>
#define get_ss_v4uint32 __x86Sim_get_ss<v4uint32>
#define get_ss_v2cint32 __x86Sim_get_ss<v2cint32>
#define get_ss_v8bfloat16 __x86Sim_get_ss<v8bfloat16>
#define get_ss_v4float __x86Sim_get_ss<v4float>
#if __AIE_ARCH__==20
#define get_ss_v2cfloat __x86Sim_get_ss<v2cfloat>
#define get_ss_v4cfloat __x86Sim_get_ss<v4cfloat>
#define get_ss_v8cfloat __x86Sim_get_ss<v8cfloat>
#define get_ss_v16cfloat __x86Sim_get_ss<v16cfloat>
#endif

#define get_ss_v8int32 __x86Sim_get_ss<v8int32>
#define get_ss_v64int4 __x86Sim_get_ss<v64int4>
#define get_ss_v64uint4 __x86Sim_get_ss<v64uint4>
#define get_ss_v32int8 __x86Sim_get_ss<v32int8>
#define get_ss_v32uint8 __x86Sim_get_ss<v32uint8>
#define get_ss_v16int16 __x86Sim_get_ss<v16int16>
#define get_ss_v16uint16 __x86Sim_get_ss<v16uint16>
#define get_ss_v8cint16 __x86Sim_get_ss<v8cint16>
#define get_ss_v8uint32 __x86Sim_get_ss<v8uint32>
#define get_ss_v4cint32 __x86Sim_get_ss<v4cint32>
#define get_ss_v16bfloat16 __x86Sim_get_ss<v16bfloat16>
#define get_ss_v8float __x86Sim_get_ss<v8float>

#define get_ss_v16int32 __x86Sim_get_ss<v16int32>
#define get_ss_v128int4 __x86Sim_get_ss<v128int4>
#define get_ss_v128uint4 __x86Sim_get_ss<v128uint4>
#define get_ss_v64int8 __x86Sim_get_ss<v64int8>
#define get_ss_v64uint8 __x86Sim_get_ss<v64uint8>
#define get_ss_v32int16 __x86Sim_get_ss<v32int16>
#define get_ss_v32uint16 __x86Sim_get_ss<v32uint16>
#define get_ss_v16cint16 __x86Sim_get_ss<v16cint16>
#define get_ss_v16uint32 __x86Sim_get_ss<v16uint32>
#define get_ss_v8cint32 __x86Sim_get_ss<v8cint32>
#define get_ss_v32bfloat16 __x86Sim_get_ss<v32bfloat16>
#define get_ss_v16float __x86Sim_get_ss<v16float>

#define get_ss_v32int32 __x86Sim_get_ss<v32int32>
#define get_ss_v256int4 __x86Sim_get_ss<v256int4>
#define get_ss_v256uint4 __x86Sim_get_ss<v256uint4>
#define get_ss_v128int8 __x86Sim_get_ss<v128int8>
#define get_ss_v128uint8 __x86Sim_get_ss<v128uint8>
#define get_ss_v64int16 __x86Sim_get_ss<v64int16>
#define get_ss_v64uint16 __x86Sim_get_ss<v64uint16>
#define get_ss_v32cint16 __x86Sim_get_ss<v32cint16>
#define get_ss_v32uint32 __x86Sim_get_ss<v32uint32>
#define get_ss_v16cint32 __x86Sim_get_ss<v16cint32>
#define get_ss_v64bfloat16 __x86Sim_get_ss<v64bfloat16>
#define get_ss_v32float __x86Sim_get_ss<v32float>

#define get_scd __x86Sim_get_scd<v16acc32>
#define getl_scd __x86Sim_get_scd<v8acc64>
#define getf_scd __x86Sim_get_scd<v16accfloat>

#define get_scd_v16acc32 __x86Sim_get_scd<v16acc32>
#define get_scd_v8acc64 __x86Sim_get_scd<v8acc64>
#define get_scd_v4cacc64 __x86Sim_get_scd<v4cacc64>
#define get_scd_v16accfloat __x86Sim_get_scd<v16accfloat>
#define get_scd_v128int4 __x86Sim_get_scd<v128int4>
#define get_scd_v128uint4 __x86Sim_get_scd<v128uint4>
#define get_scd_v64int8 __x86Sim_get_scd<v64int8>
#define get_scd_v64uint8 __x86Sim_get_scd<v64uint8>
#define get_scd_v32int16 __x86Sim_get_scd<v32int16>
#define get_scd_v32uint16 __x86Sim_get_scd<v32uint16>
#define get_scd_v16cint16 __x86Sim_get_scd<v16cint16>
#define get_scd_v16int32 __x86Sim_get_scd<v16int32>
#define get_scd_v16uint32 __x86Sim_get_scd<v16uint32>
#define get_scd_v8cint32 __x86Sim_get_scd<v8cint32>
#define get_scd_v32bfloat16 __x86Sim_get_scd<v32bfloat16>

#if __AIE_ARCH__ == 20
#define get_scd_v8caccfloat __x86Sim_get_scd<v8caccfloat>
#define get_scd_v8cfloat __x86Sim_get_scd<v8cfloat>
#endif

#if __AIE_ARCH__ == 22
#define get_scd_v32float16 __x86Sim_get_scd<v32float16>
#define get_scd_v64bfloat8 __x86Sim_get_scd<v64bfloat8>
#define get_scd_v64float8 __x86Sim_get_scd<v64float8>
#endif

#define get_scd_v32acc32 __x86Sim_get_scd<v32acc32>
#define get_scd_v16acc64 __x86Sim_get_scd<v16acc64>
#define get_scd_v8cacc64 __x86Sim_get_scd<v8cacc64>
#define get_scd_v32accfloat __x86Sim_get_scd<v32accfloat>
#define get_scd_v256int4 __x86Sim_get_scd<v256int4>
#define get_scd_v256uint4 __x86Sim_get_scd<v256uint4>
#define get_scd_v128int8 __x86Sim_get_scd<v128int8>
#define get_scd_v128uint8 __x86Sim_get_scd<v128uint8>
#define get_scd_v64int16 __x86Sim_get_scd<v64int16>
#define get_scd_v64uint16 __x86Sim_get_scd<v64uint16>
#define get_scd_v32cint16 __x86Sim_get_scd<v32cint16>
#define get_scd_v32int32 __x86Sim_get_scd<v32int32>
#define get_scd_v32uint32 __x86Sim_get_scd<v32uint32>
#define get_scd_v16cint32 __x86Sim_get_scd<v16cint32>

#if __AIE_ARCH__ == 20
#define get_scd_v16caccfloat __x86Sim_get_scd<v16caccfloat>
#define get_scd_v16cfloat __x86Sim_get_scd<v16cfloat>
#endif

#if __AIE_ARCH__ > 20
#define get_scd_v16float __x86Sim_get_scd<v16float>
#define get_scd_v32float __x86Sim_get_scd<v32float>
#define get_scd_v32accfloat_lo __x86Sim_get_scd_v32accfloat_lo
#define get_scd_v32accfloat_hi __x86Sim_get_scd_v32accfloat_hi
#define get_scd_v64acc32 __x86Sim_get_scd<v64acc32>
#define get_scd_v64accfloat __x86Sim_get_scd<v64accfloat>

#define get_scd_v32acc64 __x86Sim_get_scd<v32acc64>
#define get_scd_v16cacc64 __x86Sim_get_scd<v16cacc64>

#define get_scd_v32acc64_0 __x86Sim_get_scd_v32acc64_0
#define get_scd_v32acc64_1 __x86Sim_get_scd_v32acc64_1
#define get_scd_v32acc64_2 __x86Sim_get_scd_v32acc64_2
#define get_scd_v32acc64_3 __x86Sim_get_scd_v32acc64_3

#define get_scd_v64acc32_0 __x86Sim_get_scd_v64acc32_0
#define get_scd_v64acc32_1 __x86Sim_get_scd_v64acc32_1
#define get_scd_v64acc32_2 __x86Sim_get_scd_v64acc32_2
#define get_scd_v64acc32_3 __x86Sim_get_scd_v64acc32_3

#define get_scd_v64accfloat_0 __x86Sim_get_scd_v64accfloat_0
#define get_scd_v64accfloat_1 __x86Sim_get_scd_v64accfloat_1
#define get_scd_v64accfloat_2 __x86Sim_get_scd_v64accfloat_2
#define get_scd_v64accfloat_3 __x86Sim_get_scd_v64accfloat_3

#define get_scd_expand_v32acc32 __x86Sim_get_scd_expand_v32acc32
#define get_scd_expand_v16acc64 __x86Sim_get_scd_expand_v16acc64
#define get_scd_expand_v32accfloat __x86Sim_get_scd_expand_v32accfloat

#if __AIE_ARCH__ == 22
#define get_scd_expand_v8cacc64 __x86Sim_get_scd_expand_v8cacc64
#endif

#define get_scd_expand_v32acc32_incr __x86Sim_get_scd_expand_v32acc32_incr
#define get_scd_expand_v16acc64_incr __x86Sim_get_scd_expand_v16acc64_incr
#define get_scd_expand_v32accfloat_incr __x86Sim_get_scd_expand_v32accfloat_incr

#define get_scd_expand_v64acc32 __x86Sim_get_scd_expand_v64acc32
#define get_scd_expand_v32acc64 __x86Sim_get_scd_expand_v32acc64
#define get_scd_expand_v64accfloat __x86Sim_get_scd_expand_v64accfloat

#define get_scd_expand_v64acc32_incr __x86Sim_get_scd_expand_v64acc32_incr
#define get_scd_expand_v32acc64_incr __x86Sim_get_scd_expand_v32acc64_incr
#define get_scd_expand_v64accfloat_incr __x86Sim_get_scd_expand_v64accfloat_incr

#endif

#define get_scd_v32acc32_lo __x86Sim_get_scd_v32acc32_lo
#define get_scd_v32acc32_hi __x86Sim_get_scd_v32acc32_hi
#define get_scd_v16acc64_lo __x86Sim_get_scd_v16acc64_lo
#define get_scd_v16acc64_hi __x86Sim_get_scd_v16acc64_hi
#define get_scd_lo __x86Sim_get_scd_v32acc32_lo
#define get_scd_hi __x86Sim_get_scd_v32acc32_hi
#define getl_scd_lo __x86Sim_get_scd_v16acc64_lo
#define getl_scd_hi __x86Sim_get_scd_v16acc64_hi
#endif
#if __AIE_ARCH__==20
#define get_scd_v8caccfloat __x86Sim_get_scd<v8caccfloat>
#endif

#define put_ms_packet_header __x86Sim_put_ms_packet_header
#define put_ms_ctrl_packet_header __x86Sim_put_ms_ctrl_packet_header
#define packet_header __x86Sim_packet_header
#define ctrl_packet_header __x86Sim_ctrl_packet_header

#define put_ms __x86Sim_put_ms
#define put_mcd __x86Sim_put_mcd

#endif  // _SRC_X86SIM_INCLUDE_STREAM_REDIRECT_H_
