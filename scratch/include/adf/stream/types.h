// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef __STREAM_TYPES_H__
#define __STREAM_TYPES_H__

template<typename T> struct input_stream;
template<typename T> struct output_stream;
template<typename Ty, typename Enable=void> struct input_cascade;
template<typename Ty, typename Enable=void> struct output_cascade;

typedef input_stream<int8> input_stream_int8;
typedef input_stream<int16> input_stream_int16;
typedef input_stream<int32> input_stream_int32;
typedef input_stream<int64> input_stream_int64;
typedef input_stream<uint8> input_stream_uint8;
typedef input_stream<uint16> input_stream_uint16;
typedef input_stream<uint32> input_stream_uint32;
typedef input_stream<uint64> input_stream_uint64;
typedef input_stream<float> input_stream_float;
typedef input_stream<cint16> input_stream_cint16;
typedef input_stream<cint32> input_stream_cint32;

typedef output_stream<int8> output_stream_int8;
typedef output_stream<int16> output_stream_int16;
typedef output_stream<int32> output_stream_int32;
typedef output_stream<int64> output_stream_int64;
typedef output_stream<uint8> output_stream_uint8;
typedef output_stream<uint16> output_stream_uint16;
typedef output_stream<uint32> output_stream_uint32;
typedef output_stream<uint64> output_stream_uint64;
typedef output_stream<float> output_stream_float;
typedef output_stream<cint16> output_stream_cint16;
typedef output_stream<cint32> output_stream_cint32;


#if __AIE_ARCH__<20
typedef input_stream<cfloat> input_stream_cfloat;
typedef input_stream<cacc48> input_stream_cacc48;
typedef input_stream<cacc80> input_stream_cacc80;
typedef input_stream<caccfloat> input_stream_caccfloat;

typedef output_stream<cfloat> output_stream_cfloat;
typedef output_stream<cacc48> output_stream_cacc48;
typedef output_stream<cacc80> output_stream_cacc80;
typedef output_stream<caccfloat> output_stream_caccfloat;

typedef input_stream<acc48> input_stream_acc48;
typedef input_stream<acc80> input_stream_acc80;
typedef input_stream<accfloat> input_stream_accfloat;
typedef output_stream<acc48> output_stream_acc48;
typedef output_stream<acc80> output_stream_acc80;
typedef output_stream<accfloat> output_stream_accfloat;
#elif __AIE_ARCH__>=20
typedef input_stream<int4> input_stream_int4;
typedef input_stream<uint4> input_stream_uint4;
typedef input_stream<bfloat16> input_stream_bfloat16;
typedef input_stream<acc32>  input_stream_acc32;
typedef input_stream<acc64>  input_stream_acc64;
typedef input_stream<cacc64>  input_stream_cacc64;
typedef input_stream<accfloat>  input_stream_accfloat;
typedef output_stream<int4> output_stream_int4;
typedef output_stream<uint4> output_stream_uint4;
typedef output_stream<bfloat16> output_stream_bfloat16;
typedef output_stream<acc32>  output_stream_acc32;
typedef output_stream<acc64>  output_stream_acc64;
typedef output_stream<cacc64>  output_stream_cacc64;
typedef output_stream<accfloat>  output_stream_accfloat;
#endif
#if __AIE_ARCH__==20
typedef input_stream<cfloat> input_stream_cfloat;
typedef output_stream<cfloat> output_stream_cfloat;
#endif
#if __AIE_ARCH__>=22
typedef input_stream<float16> input_stream_float16;
typedef output_stream<float16> output_stream_float16;
typedef input_stream<bfloat8> input_stream_bfloat8;
typedef output_stream<bfloat8> output_stream_bfloat8;
typedef input_stream<float8> input_stream_float8;
typedef output_stream<float8> output_stream_float8;
#endif

struct input_pktstream;
struct output_pktstream;


#endif // __STREAM_TYPES_H__
