// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef _SRC_X86SIM_INCLUDE_STREAM_API_H_
#define _SRC_X86SIM_INCLUDE_STREAM_API_H_

/*Note: This files get included from adf.h" for all
 * types of kernel compilation
*/

#include<cmath>

#include "adf/window/types.h"
#include "adf/stream/types.h"
#include "streamStructs.h"

#if defined(__PL_KERNEL__)

typedef struct X86SIM_EXPORT v16int8 {
    int8  data[16];
    int8& operator[](int i) { return data[i]; }
} v16int8;

typedef struct X86SIM_EXPORT v16uint8 {
    uint8  data[16];
    uint8& operator[](int i) { return data[i]; }
} v16uint8;

typedef struct X86SIM_EXPORT v8int16 {
    int16  data[8];
    int16& operator[](int i) { return data[i]; }
} v8int16;

typedef struct X86SIM_EXPORT v4int32 {
    int32  data[4];
    int32& operator[](int i) { return data[i]; }
} v4int32;

#if __AIE_ARCH__<20
typedef struct X86SIM_EXPORT v4cint16 {
    cint16  data[4];
    cint16& operator[](int i) { return data[i]; }
} v4cint16;

typedef struct X86SIM_EXPORT v2cint32 {
    cint32  data[2];
    cint32& operator[](int i) { return data[i]; }
} v2cint32;

typedef struct X86SIM_EXPORT v4float {
    float  data[4];
    float& operator[](int i) { return data[i]; }
} v4float;

typedef struct X86SIM_EXPORT v2cfloat {
    cfloat  data[2];
    cfloat& operator[](int i) { return data[i]; }
} v2cfloat;

// This variant of the API generateHeader is only for PL kernels.
X86SIM_EXPORT extern uint32 generateHeader(unsigned int pcktType, 
                                           unsigned int col, 
                                           unsigned int row, 
                                           unsigned int pktId);

#endif //__AIE_ARCH__<20
#endif // __PL_KERNEL__

//int8
#if __AIE_ARCH__<20
X86SIM_EXPORT extern int8 readincr(input_stream_int8 *in );
X86SIM_EXPORT extern int8 readincr(input_stream_int8 *in, bool &tlast); 
X86SIM_EXPORT extern void writeincr(output_stream_int8 *out, int8 value, bool= false);
// wide writes only supported on AIE1
X86SIM_EXPORT extern v16int8 readincr_v16(input_stream_int8 *in );
X86SIM_EXPORT extern v16int8 readincr_v16(input_stream_int8 *in, bool &tlast); 
X86SIM_EXPORT extern void writeincr_v16(output_stream_int8 *out, v16int8 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_int8 *out, v16int8 value, bool= false); 

//uint8
X86SIM_EXPORT extern uint8 readincr(input_stream_uint8 *in );
X86SIM_EXPORT extern uint8 readincr(input_stream_uint8 *in, bool &tlast); 
X86SIM_EXPORT extern void writeincr(output_stream_uint8 *out, uint8 value, bool= false);
// wide writes only supported on AIE1
X86SIM_EXPORT extern v16uint8 readincr_v16(input_stream_uint8 *in );
X86SIM_EXPORT extern v16uint8 readincr_v16(input_stream_uint8 *in, bool &tlast); 
X86SIM_EXPORT extern void writeincr_v16(output_stream_uint8 *out, v16uint8 value, bool= false); 
X86SIM_EXPORT extern void writeincr(output_stream_uint8 *out, v16uint8 value, bool= false);

//int16
X86SIM_EXPORT extern int16 readincr(input_stream_int16 *in );
X86SIM_EXPORT extern int16 readincr(input_stream_int16 *in, bool &tlast); 
X86SIM_EXPORT extern void writeincr(output_stream_int16 *out, int16 value, bool= false);
// wide writes only supported on AIE1
X86SIM_EXPORT extern v8int16 readincr_v8(input_stream_int16 *in );
X86SIM_EXPORT extern v8int16 readincr_v8(input_stream_int16 *in, bool &tlast); 
X86SIM_EXPORT extern void writeincr_v8(output_stream_int16 *out, v8int16 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_int16 *out, v8int16 value, bool= false); 

//uint16
X86SIM_EXPORT extern uint16 readincr(input_stream_uint16 *in );
X86SIM_EXPORT extern uint16 readincr(input_stream_uint16 *in, bool &tlast); 
X86SIM_EXPORT extern void writeincr(output_stream_uint16 *out, uint16 value, bool= false);

//cint16
X86SIM_EXPORT extern cint16 readincr(input_stream_cint16 *in );
X86SIM_EXPORT extern cint16 readincr(input_stream_cint16 *in, bool &tlast);
X86SIM_EXPORT extern void writeincr(output_stream_cint16 *out, cint16 value, bool= false); 
X86SIM_EXPORT extern v4cint16 readincr_v4(input_stream_cint16 *in);
X86SIM_EXPORT extern v4cint16 readincr_v4(input_stream_cint16 *in, bool &tlast);
X86SIM_EXPORT extern void writeincr_v4(output_stream_cint16 *out, v4cint16 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_cint16 *out, v4cint16 value, bool= false);

//cint32
X86SIM_EXPORT extern cint32 readincr(input_stream_cint32 *in );
X86SIM_EXPORT extern cint32 readincr(input_stream_cint32 *in, bool &tlast);
X86SIM_EXPORT extern void writeincr(output_stream_cint32 *out, cint32 value, bool= false);
X86SIM_EXPORT extern v2cint32 readincr_v2(input_stream_cint32 *in );
X86SIM_EXPORT extern v2cint32 readincr_v2(input_stream_cint32 *in, bool &tlast);
X86SIM_EXPORT extern void writeincr_v2(output_stream_cint32 *out, v2cint32 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_cint32 *out, v2cint32 value, bool= false);
#endif

//int32
X86SIM_EXPORT extern int32 readincr(input_stream_int32 *in );
X86SIM_EXPORT extern int32 readincr(input_stream_int32 *in, bool &tlast); 
X86SIM_EXPORT extern void writeincr(output_stream_int32 *out, int32 value, bool= false);
#if __AIE_ARCH__<20
// wide writes only supported on AIE1
X86SIM_EXPORT extern v4int32 readincr_v4(input_stream_int32 *in );
X86SIM_EXPORT extern v4int32 readincr_v4(input_stream_int32 *in, bool &tlast); 
X86SIM_EXPORT extern void writeincr_v4(output_stream_int32 *out, v4int32 value, bool= false); 
X86SIM_EXPORT extern void writeincr(output_stream_int32 *out, v4int32 value, bool= false);
#endif

//int64
X86SIM_EXPORT extern int64 readincr(input_stream_int64 *in );
X86SIM_EXPORT extern int64 readincr(input_stream_int64 *in, bool &tlast); 
X86SIM_EXPORT extern void writeincr(output_stream_int64 *out, int64 value, bool= false); 

//uint32
X86SIM_EXPORT extern uint32 readincr(input_stream_uint32 *in );
X86SIM_EXPORT extern void writeincr(output_stream_uint32 *out, uint32 val, bool= false);
X86SIM_EXPORT extern uint32 readincr(input_stream_uint32 *in, bool &tlast );

//uint64
X86SIM_EXPORT extern uint64 readincr(input_stream_uint64 *in ); 
X86SIM_EXPORT extern uint64 readincr(input_stream_uint64 *in, bool &tlast);
X86SIM_EXPORT extern void writeincr(output_stream_uint64 *out, uint64 value, bool= false); 

//float
X86SIM_EXPORT extern float readincr(input_stream_float *in );
X86SIM_EXPORT extern float readincr(input_stream_float *in, bool &tlast);
X86SIM_EXPORT extern void writeincr(output_stream_float *out, float value, bool= false);

//float 
#if __AIE_ARCH__<20
X86SIM_EXPORT extern v4float readincr_v4(input_stream_float *in );
X86SIM_EXPORT extern v4float readincr_v4(input_stream_float *in, bool &tlast);
X86SIM_EXPORT extern void writeincr_v4(output_stream_float *out, v4float value, bool= false); 
X86SIM_EXPORT extern void writeincr(output_stream_float *out, v4float value, bool= false);
#endif

#if __AIE_ARCH__<=20
//cfloat
X86SIM_EXPORT extern cfloat readincr(input_stream_cfloat *in );
X86SIM_EXPORT extern cfloat readincr(input_stream_cfloat *in, bool &tlast);
X86SIM_EXPORT extern v2cfloat readincr_v2(input_stream_cfloat *in); 
X86SIM_EXPORT extern v2cfloat readincr_v2(input_stream_cfloat *in, bool &tlast); 
X86SIM_EXPORT extern void writeincr_v2(output_stream_cfloat*out, v2cfloat value, bool= false); 
X86SIM_EXPORT extern void writeincr(output_stream_cfloat*out, v2cfloat value, bool= false); 
X86SIM_EXPORT extern void writeincr(output_stream_cfloat *out, cfloat val, bool= false);
#endif
#if __AIE_ARCH__==20
X86SIM_EXPORT extern v4cfloat readincr_v4(input_stream_cfloat *in); 
X86SIM_EXPORT extern v4cfloat readincr_v4(input_stream_cfloat *in, bool &tlast); 
X86SIM_EXPORT extern v8cfloat readincr_v8(input_stream_cfloat *in); 
X86SIM_EXPORT extern v8cfloat readincr_v8(input_stream_cfloat *in, bool &tlast); 
X86SIM_EXPORT extern v16cfloat readincr_v16(input_stream_cfloat *in); 
X86SIM_EXPORT extern v16cfloat readincr_v16(input_stream_cfloat *in, bool &tlast); 
X86SIM_EXPORT extern void writeincr_v4(output_stream_cfloat *out, v4cfloat value, bool= false); 
X86SIM_EXPORT extern void writeincr_v8(output_stream_cfloat *out, v8cfloat value, bool= false); 
X86SIM_EXPORT extern void writeincr_v16(output_stream_cfloat *out, v16cfloat value, bool= false); 
X86SIM_EXPORT extern void writeincr(output_stream_cfloat *out, v4cfloat value, bool= false); 
X86SIM_EXPORT extern void writeincr(output_stream_cfloat *out, v8cfloat value, bool= false); 
X86SIM_EXPORT extern void writeincr(output_stream_cfloat *out, v16cfloat value, bool= false); 
#endif

// packet stream
X86SIM_EXPORT extern int32 getPacketid(output_pktstream *out, int idx);
X86SIM_EXPORT extern int32 getPacketid(input_pktstream *in, int idx);
X86SIM_EXPORT extern uint32 generateHeader(unsigned int pcktType, unsigned int pktId);
X86SIM_EXPORT extern uint32 generateCtrlHeader(unsigned int returnID, unsigned int op, unsigned int numWords, unsigned int addr);
X86SIM_EXPORT extern void writeincr(output_pktstream *str, int32 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_pktstream *str, uint32 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_pktstream *str, float value, bool= false);
X86SIM_EXPORT extern int32 readincr(input_pktstream *str);
X86SIM_EXPORT extern int32 readincr(input_pktstream *str, bool &tlast);

X86SIM_EXPORT extern void writeHeader(output_pktstream *str, unsigned int pcktType, unsigned int id, bool= false);
X86SIM_EXPORT extern void writeCtrlHeader(output_pktstream *str, unsigned int returnId, unsigned int op, 
                                                     unsigned int numWords, unsigned int addr, bool= false);

#if !defined(__PL_KERNEL__)
/* PL does not have cascade */
#if __AIE_ARCH__<20
X86SIM_EXPORT extern v8acc48 readincr_v8(input_stream_acc48 *str);
X86SIM_EXPORT extern v4cacc48 readincr_v4(input_stream_cacc48 *str);
X86SIM_EXPORT extern v4acc80 readincr_v4(input_stream_acc80 *str);
X86SIM_EXPORT extern v2cacc80 readincr_v2(input_stream_cacc80 *str);
X86SIM_EXPORT extern v32int8 readincr_v32int8(input_stream_acc48 *str);
X86SIM_EXPORT extern v32uint8 readincr_v32uint8(input_stream_acc48 *str);
X86SIM_EXPORT extern v16int16 readincr_v16int16(input_stream_acc48 *str);
X86SIM_EXPORT extern v8cint16 readincr_v8cint16(input_stream_acc48 *str);
X86SIM_EXPORT extern v8int32 readincr_v8int32(input_stream_acc48 *str);
X86SIM_EXPORT extern v4cint32 readincr_v4cint32(input_stream_cacc48 *str);
X86SIM_EXPORT extern v4cfloat readincr_v4cfloat(input_stream_cacc48 *str);
X86SIM_EXPORT extern v8float readincr_v8float(input_stream_acc48 *str);
X86SIM_EXPORT extern v4cfloat readincr_v4(input_stream_caccfloat *str);
X86SIM_EXPORT extern v8float readincr_v8(input_stream_accfloat *str);

X86SIM_EXPORT extern void writeincr_v4(output_stream_cacc48 *str, v4cacc48 value);
X86SIM_EXPORT extern void writeincr_v8(output_stream_acc48 *str, v8acc48 value);
X86SIM_EXPORT extern void writeincr_v4(output_stream_acc80 *str, v4acc80 value);
X86SIM_EXPORT extern void writeincr_v2(output_stream_cacc80 *str, v2cacc80 value);
X86SIM_EXPORT extern void writeincr_v32int8(output_stream_acc48 *str, v32int8 value);
X86SIM_EXPORT extern void writeincr_v32uint8(output_stream_acc48 *str, v32uint8 value);
X86SIM_EXPORT extern void writeincr_v16int16(output_stream_acc48 *str, v16int16 value);
X86SIM_EXPORT extern void writeincr_v8cint16(output_stream_acc48 *str, v8cint16 value);
X86SIM_EXPORT extern void writeincr_v8int32(output_stream_acc48 *str, v8int32 value);
X86SIM_EXPORT extern void writeincr_v4cint32(output_stream_cacc48 *str, v4cint32 value);
X86SIM_EXPORT extern void writeincr_v4cfloat(output_stream_cacc48 *str, v4cfloat value);
X86SIM_EXPORT extern void writeincr_v8float(output_stream_acc48 *str, v8float value);
X86SIM_EXPORT extern void writeincr_v4(output_stream_caccfloat *str, v4cfloat value);
X86SIM_EXPORT extern void writeincr_v8(output_stream_accfloat *str, v8float value);

X86SIM_EXPORT extern void writeincr(output_stream_cacc48 *str, v4cacc48 value);
X86SIM_EXPORT extern void writeincr(output_stream_acc48 *str, v8acc48 value);
X86SIM_EXPORT extern void writeincr(output_stream_acc80 *str, v4acc80 value);
X86SIM_EXPORT extern void writeincr(output_stream_cacc80 *str, v2cacc80 value);
X86SIM_EXPORT extern void writeincr(output_stream_acc48 *str, v32int8 value);
X86SIM_EXPORT extern void writeincr(output_stream_acc48 *str, v32uint8 value);
X86SIM_EXPORT extern void writeincr(output_stream_acc48 *str, v16int16 value);
X86SIM_EXPORT extern void writeincr(output_stream_acc48 *str, v8cint16 value);
X86SIM_EXPORT extern void writeincr(output_stream_acc48 *str, v8int32 value);
X86SIM_EXPORT extern void writeincr(output_stream_cacc48 *str, v4cint32 value);
X86SIM_EXPORT extern void writeincr(output_stream_cacc48 *str, v4cfloat value);
X86SIM_EXPORT extern void writeincr(output_stream_acc48 *str, v8float value);
X86SIM_EXPORT extern void writeincr(output_stream_caccfloat *str, v4cfloat value);
X86SIM_EXPORT extern void writeincr(output_stream_accfloat *str, v8float value);

#else
//int4
X86SIM_EXPORT extern int4 readincr(input_stream_int4 *in );
X86SIM_EXPORT extern int4 readincr(input_stream_int4 *in, bool &tlast);
X86SIM_EXPORT extern void writeincr(output_stream_int4 *out, int4 value, bool= false);
X86SIM_EXPORT extern v128int4 readincr_v128(input_stream_int4 *in);
X86SIM_EXPORT extern v256int4 readincr_v256(input_stream_int4 *in);
X86SIM_EXPORT extern v128int4 readincr_v128(input_stream_int4 *in, bool &tlast);
X86SIM_EXPORT extern v256int4 readincr_v256(input_stream_int4 *in, bool &tlast);
X86SIM_EXPORT extern void writeincr_v128(output_stream_int4 *out, v128int4 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_int4 *out, v128int4 value, bool= false);
X86SIM_EXPORT extern void writeincr_v256(output_stream_int4 *out, v256int4 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_int4 *out, v256int4 value, bool= false);
X86SIM_EXPORT extern v32int4 readincr_v32(input_stream_int4 *in);
X86SIM_EXPORT extern v64int4 readincr_v64(input_stream_int4 *in);
X86SIM_EXPORT extern v32int4 readincr_v32(input_stream_int4 *in, bool &tlast);
X86SIM_EXPORT extern v64int4 readincr_v64(input_stream_int4 *in, bool &tlast);
X86SIM_EXPORT extern void writeincr_v32(output_stream_int4 *out, v32int4 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_int4 *out, v32int4 value, bool= false);
X86SIM_EXPORT extern void writeincr_v64(output_stream_int4 *out, v64int4 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_int4 *out, v64int4 value, bool= false);

//uint4
X86SIM_EXPORT extern uint4 readincr(input_stream_uint4 *in );
X86SIM_EXPORT extern uint4 readincr(input_stream_uint4 *in, bool &tlast);
X86SIM_EXPORT extern void writeincr(output_stream_uint4 *out, uint4 value, bool= false);
X86SIM_EXPORT extern v128uint4 readincr_v128(input_stream_uint4 *in);
X86SIM_EXPORT extern v256uint4 readincr_v256(input_stream_uint4 *in);
X86SIM_EXPORT extern v128uint4 readincr_v128(input_stream_uint4 *in, bool &tlast);
X86SIM_EXPORT extern v256uint4 readincr_v256(input_stream_uint4 *in, bool &tlast);
X86SIM_EXPORT extern void writeincr_v128(output_stream_uint4 *out, v128uint4 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_uint4 *out, v128uint4 value, bool= false);
X86SIM_EXPORT extern void writeincr_v256(output_stream_uint4 *out, v256uint4 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_uint4 *out, v256uint4 value, bool= false);
X86SIM_EXPORT extern v32uint4 readincr_v32(input_stream_uint4 *in);
X86SIM_EXPORT extern v64uint4 readincr_v64(input_stream_uint4 *in);
X86SIM_EXPORT extern v32uint4 readincr_v32(input_stream_uint4 *in, bool &tlast);
X86SIM_EXPORT extern v64uint4 readincr_v64(input_stream_uint4 *in, bool &tlast);
X86SIM_EXPORT extern void writeincr_v32(output_stream_uint4 *out, v32uint4 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_uint4 *out, v32uint4 value, bool= false);
X86SIM_EXPORT extern void writeincr_v64(output_stream_uint4 *out, v64uint4 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_uint4 *out, v64uint4 value, bool= false);

//bfloat16
X86SIM_EXPORT extern bfloat16 readincr(input_stream_bfloat16 *in );
X86SIM_EXPORT extern bfloat16 readincr(input_stream_bfloat16 *in, bool &tlast);
X86SIM_EXPORT extern void writeincr(output_stream_bfloat16 *out, bfloat16 value, bool= false);
X86SIM_EXPORT extern v32bfloat16 readincr_v32(input_stream_bfloat16* str);
X86SIM_EXPORT extern v32bfloat16 readincr_v32(input_stream_bfloat16* str, bool &tlast);
X86SIM_EXPORT extern void writeincr_v32(output_stream_bfloat16* str, v32bfloat16 val,bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_bfloat16* str, v32bfloat16 val,bool= false);
X86SIM_EXPORT extern v8bfloat16 readincr_v8(input_stream_bfloat16* str);
X86SIM_EXPORT extern v8bfloat16 readincr_v8(input_stream_bfloat16* str, bool &tlast);
X86SIM_EXPORT extern void writeincr_v8(output_stream_bfloat16* str, v8bfloat16 val,bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_bfloat16* str, v8bfloat16 val,bool= false);
X86SIM_EXPORT extern v16bfloat16 readincr_v16(input_stream_bfloat16* str);
X86SIM_EXPORT extern v16bfloat16 readincr_v16(input_stream_bfloat16* str, bool &tlast);
X86SIM_EXPORT extern void writeincr_v16(output_stream_bfloat16* str, v16bfloat16 val,bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_bfloat16* str, v16bfloat16 val,bool= false);
X86SIM_EXPORT extern v64bfloat16 readincr_v64(input_stream_bfloat16* str);
X86SIM_EXPORT extern v64bfloat16 readincr_v64(input_stream_bfloat16* str, bool &tlast);
X86SIM_EXPORT extern void writeincr_v64(output_stream_bfloat16* str, v64bfloat16 val,bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_bfloat16* str, v64bfloat16 val,bool= false);

#if __AIE_ARCH__>=22
//float16
X86SIM_EXPORT extern float16 readincr(input_stream_float16* in);
X86SIM_EXPORT extern float16 readincr(input_stream_float16* in, bool &tlast);
X86SIM_EXPORT extern void writeincr(output_stream_float16* out, float16 value, bool= false);

//bfloat8
X86SIM_EXPORT extern bfloat8 readincr(input_stream_bfloat8* in);
X86SIM_EXPORT extern bfloat8 readincr(input_stream_bfloat8* in, bool &tlast);
X86SIM_EXPORT extern void writeincr(output_stream_bfloat8* out, bfloat8 value, bool= false);

//float8
X86SIM_EXPORT extern float8 readincr(input_stream_float8* in);
X86SIM_EXPORT extern float8 readincr(input_stream_float8* in, bool &tlast);
X86SIM_EXPORT extern void writeincr(output_stream_float8* out, float8 value, bool= false);
#endif

//float
#if __AIE_ARCH__ < 22
X86SIM_EXPORT extern v4float readincr_v4(input_stream_float* str);
X86SIM_EXPORT extern v4float readincr_v4(input_stream_float* str, bool &tlast);
X86SIM_EXPORT extern void writeincr_v4(output_stream_float* str, v4float val,bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_float* str, v4float val,bool= false);
X86SIM_EXPORT extern v8float readincr_v8(input_stream_float* str);
X86SIM_EXPORT extern v8float readincr_v8(input_stream_float* str, bool &tlast);
X86SIM_EXPORT extern void writeincr_v8(output_stream_float* str, v8float val,bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_float* str, v8float val,bool= false);
X86SIM_EXPORT extern v16float readincr_v16(input_stream_float* str);
X86SIM_EXPORT extern v16float readincr_v16(input_stream_float* str, bool &tlast);
X86SIM_EXPORT extern void writeincr_v16(output_stream_float* str, v16float val,bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_float* str, v16float val,bool= false);
X86SIM_EXPORT extern v32float readincr_v32(input_stream_float* str);
X86SIM_EXPORT extern v32float readincr_v32(input_stream_float* str, bool &tlast);
X86SIM_EXPORT extern void writeincr_v32(output_stream_float* str, v32float val,bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_float* str, v32float val,bool= false);
#endif

//cint16
X86SIM_EXPORT extern cint16 readincr(input_stream_cint16 *in );
X86SIM_EXPORT extern cint16 readincr(input_stream_cint16 *in, bool &tlast);
X86SIM_EXPORT extern void writeincr(output_stream_cint16 *out, cint16 value, bool= false);
X86SIM_EXPORT extern v16cint16 readincr_v16(input_stream_cint16 *in);
X86SIM_EXPORT extern v32cint16 readincr_v32(input_stream_cint16 *in);
X86SIM_EXPORT extern v16cint16 readincr_v16(input_stream_cint16 *in, bool &tlast);
X86SIM_EXPORT extern v32cint16 readincr_v32(input_stream_cint16 *in, bool &tlast);
X86SIM_EXPORT extern void writeincr_v16(output_stream_cint16 *out, v16cint16 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_cint16 *out, v16cint16 value, bool= false);
X86SIM_EXPORT extern void writeincr_v32(output_stream_cint16 *out, v32cint16 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_cint16 *out, v32cint16 value, bool= false);
X86SIM_EXPORT extern v4cint16 readincr_v4(input_stream_cint16 *in);
X86SIM_EXPORT extern v8cint16 readincr_v8(input_stream_cint16 *in);
X86SIM_EXPORT extern v4cint16 readincr_v4(input_stream_cint16 *in, bool &tlast);
X86SIM_EXPORT extern v8cint16 readincr_v8(input_stream_cint16 *in, bool &tlast);
X86SIM_EXPORT extern void writeincr_v4(output_stream_cint16 *out, v4cint16 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_cint16 *out, v4cint16 value, bool= false);
X86SIM_EXPORT extern void writeincr_v8(output_stream_cint16 *out, v8cint16 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_cint16 *out, v8cint16 value, bool= false);

//cint32
X86SIM_EXPORT extern cint32 readincr(input_stream_cint32 *in );
X86SIM_EXPORT extern cint32 readincr(input_stream_cint32 *in, bool &tlast);
X86SIM_EXPORT extern void writeincr(output_stream_cint32 *out, cint32 value, bool= false);
X86SIM_EXPORT extern v8cint32 readincr_v8(input_stream_cint32 *in);
X86SIM_EXPORT extern v16cint32 readincr_v16(input_stream_cint32 *in);
X86SIM_EXPORT extern v8cint32 readincr_v8(input_stream_cint32 *in, bool &tlast);
X86SIM_EXPORT extern v16cint32 readincr_v16(input_stream_cint32 *in, bool &tlast);
X86SIM_EXPORT extern void writeincr_v8(output_stream_cint32 *out, v8cint32 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_cint32 *out, v8cint32 value, bool= false);
X86SIM_EXPORT extern void writeincr_v16(output_stream_cint32 *out, v16cint32 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_cint32 *out, v16cint32 value, bool= false);
X86SIM_EXPORT extern v2cint32 readincr_v2(input_stream_cint32 *in);
X86SIM_EXPORT extern v4cint32 readincr_v4(input_stream_cint32 *in);
X86SIM_EXPORT extern v2cint32 readincr_v2(input_stream_cint32 *in, bool &tlast);
X86SIM_EXPORT extern v4cint32 readincr_v4(input_stream_cint32 *in, bool &tlast);
X86SIM_EXPORT extern void writeincr_v2(output_stream_cint32 *out, v2cint32 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_cint32 *out, v2cint32 value, bool= false);
X86SIM_EXPORT extern void writeincr_v4(output_stream_cint32 *out, v4cint32 value, bool= false);
X86SIM_EXPORT extern void writeincr(output_stream_cint32 *out, v4cint32 value, bool= false);

X86SIM_EXPORT extern v16acc32 readincr_v16(input_stream_acc32* str);
X86SIM_EXPORT extern v8acc64 readincr_v8(input_stream_acc64* str);
X86SIM_EXPORT extern v4cacc64 readincr_v4(input_stream_cacc64* str);
X86SIM_EXPORT extern v16accfloat readincr_v16(input_stream_accfloat* str);
X86SIM_EXPORT extern void writeincr_v16(output_stream_acc32* str, v16acc32 value);
X86SIM_EXPORT extern void writeincr(output_stream_acc32* str, v16acc32 value);
X86SIM_EXPORT extern void writeincr_v8(output_stream_acc64* str, v8acc64 value);
X86SIM_EXPORT extern void writeincr(output_stream_acc64* str, v8acc64 value);
X86SIM_EXPORT extern void writeincr_v4(output_stream_cacc64* str, v4cacc64 value);
X86SIM_EXPORT extern void writeincr(output_stream_cacc64* str, v4cacc64 value);
X86SIM_EXPORT extern void writeincr_v16(output_stream_accfloat* str, v16accfloat value);
X86SIM_EXPORT extern void writeincr(output_stream_accfloat* str, v16accfloat value);

X86SIM_EXPORT extern v64int8 readincr_v64(input_stream_int8* str);
X86SIM_EXPORT extern v128int8 readincr_v128(input_stream_int8* str);
X86SIM_EXPORT extern v16int8 readincr_v16(input_stream_int8* str);
X86SIM_EXPORT extern v32int8 readincr_v32(input_stream_int8* str);
X86SIM_EXPORT extern v32int16 readincr_v32(input_stream_int16* str);
X86SIM_EXPORT extern v64int16 readincr_v64(input_stream_int16* str);
X86SIM_EXPORT extern v8int16 readincr_v8(input_stream_int16* str);
X86SIM_EXPORT extern v16int16 readincr_v16(input_stream_int16* str);
X86SIM_EXPORT extern v16int32 readincr_v16(input_stream_int32* str);
X86SIM_EXPORT extern v32int32 readincr_v32(input_stream_int32* str);
X86SIM_EXPORT extern v4int32 readincr_v4(input_stream_int32* str);
X86SIM_EXPORT extern v8int32 readincr_v8(input_stream_int32* str);
X86SIM_EXPORT extern v64uint8 readincr_v64(input_stream_uint8* str);
X86SIM_EXPORT extern v128uint8 readincr_v128(input_stream_uint8* str);
X86SIM_EXPORT extern v16uint8 readincr_v16(input_stream_uint8* str);
X86SIM_EXPORT extern v32uint8 readincr_v32(input_stream_uint8* str);
X86SIM_EXPORT extern v32uint16 readincr_v32(input_stream_uint16* str);
X86SIM_EXPORT extern v64uint16 readincr_v64(input_stream_uint16* str);
X86SIM_EXPORT extern v8uint16 readincr_v8(input_stream_uint16* str);
X86SIM_EXPORT extern v16uint16 readincr_v16(input_stream_uint16* str);
X86SIM_EXPORT extern v16uint32 readincr_v16(input_stream_uint32* str);
X86SIM_EXPORT extern v32uint32 readincr_v32(input_stream_uint32* str);
X86SIM_EXPORT extern v4uint32 readincr_v4(input_stream_uint32* str);
X86SIM_EXPORT extern v8uint32 readincr_v8(input_stream_uint32* str);

X86SIM_EXPORT extern v64int8 readincr_v64(input_stream_int8* str, bool &tlast);
X86SIM_EXPORT extern v128int8 readincr_v128(input_stream_int8* str, bool &tlast);
X86SIM_EXPORT extern v16int8 readincr_v16(input_stream_int8* str, bool &tlast);
X86SIM_EXPORT extern v32int8 readincr_v32(input_stream_int8* str, bool &tlast);
X86SIM_EXPORT extern v32int16 readincr_v32(input_stream_int16* str, bool &tlast);
X86SIM_EXPORT extern v64int16 readincr_v64(input_stream_int16* str, bool &tlast);
X86SIM_EXPORT extern v8int16 readincr_v8(input_stream_int16* str, bool &tlast);
X86SIM_EXPORT extern v16int16 readincr_v16(input_stream_int16* str, bool &tlast);
X86SIM_EXPORT extern v16int32 readincr_v16(input_stream_int32* str, bool &tlast);
X86SIM_EXPORT extern v32int32 readincr_v32(input_stream_int32* str, bool &tlast);
X86SIM_EXPORT extern v4int32 readincr_v4(input_stream_int32* str, bool &tlast);
X86SIM_EXPORT extern v8int32 readincr_v8(input_stream_int32* str, bool &tlast);
X86SIM_EXPORT extern v64uint8 readincr_v64(input_stream_uint8* str, bool &tlast);
X86SIM_EXPORT extern v128uint8 readincr_v128(input_stream_uint8* str, bool &tlast);
X86SIM_EXPORT extern v16uint8 readincr_v16(input_stream_uint8* str, bool &tlast);
X86SIM_EXPORT extern v32uint8 readincr_v32(input_stream_uint8* str, bool &tlast);
X86SIM_EXPORT extern v32uint16 readincr_v32(input_stream_uint16* str, bool &tlast);
X86SIM_EXPORT extern v64uint16 readincr_v64(input_stream_uint16* str, bool &tlast);
X86SIM_EXPORT extern v8uint16 readincr_v8(input_stream_uint16* str, bool &tlast);
X86SIM_EXPORT extern v16uint16 readincr_v16(input_stream_uint16* str, bool &tlast);
X86SIM_EXPORT extern v16uint32 readincr_v16(input_stream_uint32* str, bool &tlast);
X86SIM_EXPORT extern v32uint32 readincr_v32(input_stream_uint32* str, bool &tlast);
X86SIM_EXPORT extern v4uint32 readincr_v4(input_stream_uint32* str, bool &tlast);
X86SIM_EXPORT extern v8uint32 readincr_v8(input_stream_uint32* str, bool &tlast);

X86SIM_EXPORT extern void writeincr_v64(output_stream_int8* str, v64int8 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v128(output_stream_int8* str, v128int8 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v16(output_stream_int8* str, v16int8 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v32(output_stream_int8* str, v32int8 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v32(output_stream_int16* str, v32int16 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v64(output_stream_int16* str, v64int16 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v8(output_stream_int16* str, v8int16 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v16(output_stream_int16* str, v16int16 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v16(output_stream_int32* str, v16int32 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v32(output_stream_int32* str, v32int32 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v4(output_stream_int32* str, v4int32 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v8(output_stream_int32* str, v8int32 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v64(output_stream_uint8* str, v64uint8 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v128(output_stream_uint8* str, v128uint8 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v16(output_stream_uint8* str, v16uint8 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v32(output_stream_uint8* str, v32uint8 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v32(output_stream_uint16* str, v32uint16 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v64(output_stream_uint16* str, v64uint16 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v8(output_stream_uint16* str, v8uint16 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v16(output_stream_uint16* str, v16uint16 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v16(output_stream_uint32* str, v16uint32 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v32(output_stream_uint32* str, v32uint32 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v4(output_stream_uint32* str, v4uint32 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr_v8(output_stream_uint32* str, v8uint32 val,bool tlast=false);

X86SIM_EXPORT extern void writeincr(output_stream_int8* str, v64int8 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_int8* str, v128int8 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_int8* str, v16int8 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_int8* str, v32int8 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_int16* str, v32int16 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_int16* str, v64int16 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_int16* str, v8int16 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_int16* str, v16int16 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_int32* str, v16int32 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_int32* str, v32int32 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_int32* str, v4int32 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_int32* str, v8int32 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_uint8* str, v64uint8 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_uint8* str, v128uint8 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_uint8* str, v16uint8 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_uint8* str, v32uint8 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_uint16* str, v32uint16 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_uint16* str, v64uint16 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_uint16* str, v8uint16 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_uint16* str, v16uint16 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_uint32* str, v16uint32 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_uint32* str, v32uint32 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_uint32* str, v4uint32 val,bool tlast=false);
X86SIM_EXPORT extern void writeincr(output_stream_uint32* str, v8uint32 val,bool tlast=false);
#endif // #if __AIE_ARCH__<20

#include "streamRedirect.h"

#define X86SIM_CASCADE_READ(ty, ln)                                                 \
  static inline v ## ln ## ty readincr_v ## ln(input_cascade< ty > * str) {         \
    return get_scd_v ## ln ## ty();                                                 \
  }


#define X86SIM_CASCADE_READ3(accty, ty, ln)                              \
  static inline v ## ln ## ty readincr_v ## ln(input_cascade< accty > * str) {         \
    return get_scd_v ## ln ## ty();                                                 \
  }

#if __AIE_ARCH__<20

X86SIM_CASCADE_READ(acc48, 8);
X86SIM_CASCADE_READ(cacc48, 4);
X86SIM_CASCADE_READ(acc80, 4);
X86SIM_CASCADE_READ(cacc80, 2);
X86SIM_CASCADE_READ3(accfloat, float, 8);
X86SIM_CASCADE_READ3(caccfloat, cfloat, 4);

X86SIM_CASCADE_READ(int8, 32);
X86SIM_CASCADE_READ(uint8, 32);
X86SIM_CASCADE_READ(int16, 16);

X86SIM_CASCADE_READ(cint16, 8);
X86SIM_CASCADE_READ(int32, 8);
X86SIM_CASCADE_READ(cint32, 4);
X86SIM_CASCADE_READ(cfloat, 4);
X86SIM_CASCADE_READ(float, 8);

#else // #if __AIE_ARCH__>=20

X86SIM_CASCADE_READ(acc32, 32);
X86SIM_CASCADE_READ(acc32, 16);
X86SIM_CASCADE_READ(acc64, 16);
X86SIM_CASCADE_READ(accfloat, 16);
X86SIM_CASCADE_READ(acc64, 8);
X86SIM_CASCADE_READ(cacc64, 8);
X86SIM_CASCADE_READ(cacc64, 4);

X86SIM_CASCADE_READ(int4, 128);
X86SIM_CASCADE_READ(uint4, 128);
X86SIM_CASCADE_READ(int8, 128);
X86SIM_CASCADE_READ(uint8, 128);

X86SIM_CASCADE_READ(int4, 256);
X86SIM_CASCADE_READ(uint4, 256);

X86SIM_CASCADE_READ(cint16, 16);
X86SIM_CASCADE_READ(cint32, 16);
X86SIM_CASCADE_READ(int32, 16);
X86SIM_CASCADE_READ(uint32, 16);

X86SIM_CASCADE_READ(cint32, 8);

X86SIM_CASCADE_READ(bfloat16, 32);
X86SIM_CASCADE_READ(cint16, 32);
X86SIM_CASCADE_READ(int16, 32);
X86SIM_CASCADE_READ(uint16, 32);
X86SIM_CASCADE_READ(int32, 32);
X86SIM_CASCADE_READ(uint32, 32);

X86SIM_CASCADE_READ(int16, 64);
X86SIM_CASCADE_READ(uint16, 64);
X86SIM_CASCADE_READ(int8, 64);
X86SIM_CASCADE_READ(uint8, 64);

#endif
#if __AIE_ARCH__==20
X86SIM_CASCADE_READ(caccfloat, 8);
#endif

template <typename streamTy, typename vectorTy>
static inline 
std::enable_if_t< x86sim::is_valid_vector_acc_data_type< streamTy, vectorTy> >
writeincr(output_cascade< streamTy > * str, vectorTy val)
{
    __x86Sim_put_mcd(val);
}


#endif // !__PL_KERNEL__

#if __AIE_ARCH__<20
// Internal access functions with stream resource typecast
#define READINCR(rspec, str) read32bits((x86sim::stream_internal*) str)
#define READINCRW(rspec, str) read128bits((x86sim::stream_internal*) str)
#define READINCRT(rspec, str, tlast) read32bits((x86sim::stream_internal*) str, tlast)
#define READINCRWT(rspec, str, tlast) read128bits((x86sim::stream_internal*) str, tlast)
#define WRITEINCR(rspec, str, val) write32bits((x86sim::stream_internal*) str, val, false)
#define WRITEINCRW(rspec, str, val) write128bits((x86sim::stream_internal*) str, val, false)
#define WRITEINCRT(rspec, str, val, tlast) write32bits((x86sim::stream_internal*) str, val, tlast)
#define WRITEINCRWT(rspec, str, val, tlast) write128bits((x86sim::stream_internal*) str, val, tlast)
#endif //__AIE_ARCH__<20

X86SIM_EXPORT extern void  write32bits(x86sim::stream_internal *strm, int32 value, bool);
X86SIM_EXPORT extern void  write128bits(x86sim::stream_internal *strm, v4int32 value, bool);
X86SIM_EXPORT extern int32 read32bits(x86sim::stream_internal *strm);
X86SIM_EXPORT extern int32 read32bits(x86sim::stream_internal *strm, bool &tlast);
X86SIM_EXPORT extern v4int32 read128bits(x86sim::stream_internal *strm);
X86SIM_EXPORT extern v4int32 read128bits(x86sim::stream_internal *strm, bool &tlast);

#if !defined(__PL_KERNEL__)
template<typename Ty>
struct is_stream_data_type: public std::false_type {};
template<> struct is_stream_data_type<int32>: public std::true_type {};
template<> struct is_stream_data_type<int64>: public std::true_type {};
template<> struct is_stream_data_type<float>: public std::true_type {};
template<> struct is_stream_data_type<uint32>: public std::true_type {};
template<> struct is_stream_data_type<uint64>: public std::true_type {};
template<> struct is_stream_data_type<cint16>: public std::true_type {};
template<> struct is_stream_data_type<cint32>: public std::true_type {};
#if __AIE_ARCH__<=20
template<> struct is_stream_data_type<cfloat>: public std::true_type {};
#endif
#if __AIE_ARCH__<20
template<> struct is_stream_data_type<int8>: public std::true_type {};
template<> struct is_stream_data_type<int16>: public std::true_type {};
template<> struct is_stream_data_type<uint8>: public std::true_type {};
template<> struct is_stream_data_type<uint16>: public std::true_type {};
#else
template<> struct is_stream_data_type<int4>: public std::true_type {};
template<> struct is_stream_data_type<uint4>: public std::true_type {};
template<> struct is_stream_data_type<bfloat16>: public std::true_type {};
#endif
#if __AIE_ARCH__>=22
template<> struct is_stream_data_type<float16>: public std::true_type {};
template<> struct is_stream_data_type<bfloat8>: public std::true_type {};
template<> struct is_stream_data_type<float8>: public std::true_type {};
#endif

template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
          typename streamTy=void>
static inline std::enable_if_t<is_stream_data_type<streamTy>::value, streamTy>
readincr(input_stream<streamTy> *in)
{
    return readincr(in);
}

template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
          typename streamTy=void>
static inline std::enable_if_t<is_stream_data_type<streamTy>::value, streamTy>
readincr(input_stream<streamTy> *in, bool &tlast)
{
    return readincr(in,tlast);
}
#if __AIE_ARCH__<20
template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
          typename streamTy=void,
          typename = std::enable_if_t<is_stream_data_type<streamTy>::value>>
static inline auto
readincr_v2(input_stream<streamTy> *in)
{
    static_assert( sizeof(streamTy) == 8,
        "Error : readincr_v2 only supported with 64-bit types cint32 and cfloat.");
    return readincr_v2(in);
}

template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
          typename streamTy=void,
          typename = std::enable_if_t<is_stream_data_type<streamTy>::value>>
static inline auto
readincr_v2(input_stream<streamTy> *in, bool &tlast)
{
    static_assert( sizeof(streamTy) == 8,
        "Error : readincr_v2 only supported with 64-bit types cint32 and cfloat.");
    return readincr_v2(in,tlast);
}

template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
          typename streamTy=void,
          typename = std::enable_if_t<is_stream_data_type<streamTy>::value>>
static inline auto
readincr_v4(input_stream<streamTy> *in)
{
    static_assert( sizeof(streamTy) == 4,
        "Error : readincr_v4 only supported with 32-bit types int32, cint16 and float.");
    return readincr_v4(in);
}

template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
          typename streamTy=void,
          typename = std::enable_if_t<is_stream_data_type<streamTy>::value>>
static inline auto
readincr_v4(input_stream<streamTy> *in, bool &tlast)
{
    static_assert( sizeof(streamTy) == 4,
        "Error : readincr_v4 only supported with 32-bit types int32, cint16 and float.");
    return readincr_v4(in,tlast);
}

template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
          typename streamTy=void,
          typename = std::enable_if_t<is_stream_data_type<streamTy>::value>>
static inline auto
readincr_v8(input_stream<streamTy> *in)
{
    static_assert( sizeof(streamTy) == 2,
        "Error : readincr_v8 only supported with 16-bit type int16.");
    return readincr_v8(in);
}
template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
          typename streamTy=void,
          typename = std::enable_if_t<is_stream_data_type<streamTy>::value>>
static inline auto
readincr_v8(input_stream<streamTy> *in, bool &tlast)
{
    static_assert( sizeof(streamTy) == 2,
        "Error : readincr_v8 only supported with 16-bit type int16.");
    return readincr_v8(in,tlast);
}

template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
          typename streamTy=void,
          typename = std::enable_if_t<is_stream_data_type<streamTy>::value>>
static inline auto readincr_v16(input_stream<streamTy> *in)
{
    static_assert( sizeof(streamTy) == 1,
        "Error : readincr_v16 only supported with 8-bit types int8 and uint8.");
    return readincr_v16(in);
}

template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
    typename streamTy=void,
    typename = std::enable_if_t<is_stream_data_type<streamTy>::value>>
static inline auto readincr_v16(input_stream<streamTy> *in, bool &tlast)
{
    static_assert( sizeof(streamTy) == 1,
        "Error : readincr_v16 only supported with 8-bit types int8 and uint8.");
    return readincr_v16(in,tlast);
}

#else

// checks if AIE2 valid stream for vector access
template<typename Ty>
struct is_valid_stream_vector_access: public std::false_type {};
template<> struct is_valid_stream_vector_access<int4>: public std::true_type {};
template<> struct is_valid_stream_vector_access<uint4>: public std::true_type {};
template<> struct is_valid_stream_vector_access<bfloat16>: public std::true_type {};
template<> struct is_valid_stream_vector_access<float>: public std::true_type {};
template<> struct is_valid_stream_vector_access<int8>: public std::true_type {};
template<> struct is_valid_stream_vector_access<uint8>: public std::true_type {};
template<> struct is_valid_stream_vector_access<int16>: public std::true_type {};
template<> struct is_valid_stream_vector_access<uint16>: public std::true_type {};
template<> struct is_valid_stream_vector_access<int32>: public std::true_type {};
template<> struct is_valid_stream_vector_access<uint32>: public std::true_type {};
template<> struct is_valid_stream_vector_access<cint16>: public std::true_type {};
template<> struct is_valid_stream_vector_access<cint32>: public std::true_type {};
#if __AIE_ARCH__ == 20
template<> struct is_valid_stream_vector_access<cfloat>: public std::true_type {};
#endif

template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
          typename streamTy=void,
          typename = std::enable_if_t<is_stream_data_type<streamTy>::value>>
static inline auto
readincr_v2(input_stream<streamTy> *in)
{
    static_assert( sizeof(streamTy) == 8,
        "Error : readincr_v2 is supported only for cint32.");
    return readincr_v2(in);
}
 
template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
    typename streamTy=void,
    typename = std::enable_if_t<is_valid_stream_vector_access<streamTy>::value>>
static inline auto readincr_v4(input_stream<streamTy> *in)
{
    static_assert(((sizeof(streamTy) == 8) || (sizeof(streamTy) == 4)), 
        "Error : readincr_v4 only supported with 32-bit types int32, uint32, "
        "float and cint16 and 64-bit type cint32.");
    return readincr_v4(in);
}

template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
    typename streamTy=void,
    typename = std::enable_if_t<is_valid_stream_vector_access<streamTy>::value>>
static inline auto readincr_v8(input_stream<streamTy> *in)
{
    static_assert(((sizeof(streamTy) == 8) || (sizeof(streamTy) == 4) ||
        (sizeof(streamTy) == 2)),
        "Error : readincr_v8 only supported with 16-bit types int16, uint16 and "
        "bfloat16, 32-bit types int32, uint32, float and cint16 and 64-bit type "
        "cint32.");
    return readincr_v8(in);
}

template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
    typename streamTy=void,
    typename = std::enable_if_t<is_valid_stream_vector_access<streamTy>::value>>
static inline auto readincr_v16(input_stream<streamTy> *in)
{
    // Supported with all types except int4/uint4
    return readincr_v16(in);
}

template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
    typename streamTy=void,
    typename = std::enable_if_t<is_valid_stream_vector_access<streamTy>::value>>
static inline auto readincr_v32(input_stream<streamTy> *in)
{
    static_assert(((sizeof(streamTy) == 2) || (sizeof(streamTy) == 4) ||
        (sizeof(streamTy) == 1)),
        "Error : readincr_v32 only supported with 4-bit types int4,uint4 ,"
        "8-bit types int8,uint8, 16-bit type int16, uint16,"
        " bfloat16 and 32-bit types int32, uint32, float and cint16.");
    return readincr_v32(in);
}

template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
    typename streamTy=void,
    typename = std::enable_if_t<is_valid_stream_vector_access<streamTy>::value>>
static inline auto readincr_v64(input_stream<streamTy> *in)
{
    static_assert(((sizeof(streamTy) == 2) || (sizeof(streamTy) == 1)),
        "Error : readincr_v64 only supported with 16-bit type int16, uint16,"
        "bfloat16, 8-bit types int8 and uint8 and 4-bit types int4,uint4.");
    return readincr_v64(in);
}

template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
    typename streamTy=void,
    typename = std::enable_if_t<is_valid_stream_vector_access<streamTy>::value>>
static inline auto readincr_v128(input_stream<streamTy> *in)
{
    static_assert(sizeof(streamTy) == 1,
        "Error : readincr_v128 only supported with "
        "8-bit types int8, uint8 and 4-bit types int4, uint4 .");
    return readincr_v128(in);
}

// Specialization for int4 and uint4
template <aie_stream_resource_in Resource = aie_stream_resource_in::none>
static inline v256int4 readincr_v256(input_stream<int4> *in)
{
    return readincr_v256(in);
}

template <aie_stream_resource_in Resource = aie_stream_resource_in::none>
static inline v256uint4 readincr_v256(input_stream<uint4> *in)
{
    return readincr_v256(in);
}

template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
          typename streamTy=void,
          typename = std::enable_if_t<is_stream_data_type<streamTy>::value>>
static inline auto
readincr_v2(input_stream<streamTy> *in, bool &tlast)
{
    static_assert( sizeof(streamTy) == 8,
        "Error : readincr_v2 is supported only for cint32.");
    return readincr_v2(in,tlast);
}

template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
    typename streamTy=void,
    typename = std::enable_if_t<is_valid_stream_vector_access<streamTy>::value>>
static inline auto readincr_v4(input_stream<streamTy> *in, bool &tlast)
{
    static_assert(((sizeof(streamTy) == 8) || (sizeof(streamTy) == 4)), 
        "Error : readincr_v4 only supported with 32-bit types int32, uint32, "
        "float and cint16 and 64-bit type cint32.");
    return readincr_v4(in, tlast);
}

template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
    typename streamTy=void,
    typename = std::enable_if_t<is_valid_stream_vector_access<streamTy>::value>>
static inline auto readincr_v8(input_stream<streamTy> *in, bool &tlast)
{
    static_assert(((sizeof(streamTy) == 8) || (sizeof(streamTy) == 4) ||
        (sizeof(streamTy) == 2)),
        "Error : readincr_v8 only supported with 16-bit types int16, uint16 and "
        "bfloat16, 32-bit types int32, uint32, float and cint16 and 64-bit type "
        "cint32.");
    return readincr_v8(in, tlast);
}

template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
    typename streamTy=void,
    typename = std::enable_if_t<is_valid_stream_vector_access<streamTy>::value>>
static inline auto readincr_v16(input_stream<streamTy> *in, bool &tlast)
{
    // Supported with all types except int4/uint4
    return readincr_v16(in, tlast);
}

template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
    typename streamTy=void,
    typename = std::enable_if_t<is_valid_stream_vector_access<streamTy>::value>>
static inline auto readincr_v32(input_stream<streamTy> *in, bool &tlast)
{
    static_assert(((sizeof(streamTy) == 2) || (sizeof(streamTy) == 4) ||
        (sizeof(streamTy) == 1)),
        "Error : readincr_v32 only supported with 4-bit types int4,uint4 ,"
        "8-bit types int8,uint8, 16-bit type int16, uint16,"
        " bfloat16 and 32-bit types int32, uint32, float and cint16.");
    return readincr_v32(in, tlast);
}

template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
    typename streamTy=void,
    typename = std::enable_if_t<is_valid_stream_vector_access<streamTy>::value>>
static inline auto readincr_v64(input_stream<streamTy> *in, bool &tlast)
{
    static_assert(((sizeof(streamTy) == 2) || (sizeof(streamTy) == 1)),
        "Error : readincr_v64 only supported with 16-bit type int16, uint16,"
        "bfloat16, 8-bit types int8 and uint8 and 4-bit types int4,uint4.");
    return readincr_v64(in, tlast);
}

template <aie_stream_resource_in Resource = aie_stream_resource_in::none,
    typename streamTy=void,
    typename = std::enable_if_t<is_valid_stream_vector_access<streamTy>::value>>
static inline auto readincr_v128(input_stream<streamTy> *in, bool &tlast)
{
    static_assert(sizeof(streamTy) == 1,
        "Error : readincr_v128 only supported with "
        "8-bit types int8, uint8 and 4-bit types int4, uint4 .");
    return readincr_v128(in, tlast);
}

// Specialization for int4 and uint4
template <aie_stream_resource_in Resource = aie_stream_resource_in::none>
static inline v256int4 readincr_v256(input_stream<int4> *in, bool &tlast)
{
    return readincr_v256(in, tlast);
}

template <aie_stream_resource_in Resource = aie_stream_resource_in::none>
static inline v256uint4 readincr_v256(input_stream<uint4> *in, bool &tlast)
{
    return readincr_v256(in, tlast);
}

#endif //if __AIE_ARCH__<20

// writeincr for non vector types can be templatized
template <aie_stream_resource_out Resource = aie_stream_resource_out::none,
          typename streamTy=void>
static inline std::enable_if_t< is_stream_data_type< streamTy >::value>
writeincr(output_stream<streamTy> *out, streamTy value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

#if __AIE_ARCH__<20
// aie_api/HEAD/adf/stream.hpp globally defines a templatized writeincr API
// for aie::vector types which does not allow us to create templatized 
// writeincr API for different vector types.
// Added writeincr specializations for different vector types
// TODO : Fix this in 2022.2
template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<int8> *out, v16int8 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<uint8> *out, v16uint8 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<int16> *out, v8int16 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<int32> *out, v4int32 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<float> *out, v4float value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<cint16> *out, v4cint16 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<cint32> *out, v2cint32 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<cfloat> *out, v2cfloat value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template<typename streamTy, typename dataTy>
struct is_stream_vector_data_type: public std::false_type {};
template<> struct is_stream_vector_data_type<int8, v16int8>: public std::true_type {};
template<> struct is_stream_vector_data_type<uint8, v16uint8>: public std::true_type {};
template<> struct is_stream_vector_data_type<int16, v8int16>: public std::true_type {};
template<> struct is_stream_vector_data_type<int32, v4int32>: public std::true_type {};
template<> struct is_stream_vector_data_type<float, v4float>: public std::true_type {};
template<> struct is_stream_vector_data_type<cint16, v4cint16>: public std::true_type {};
template<> struct is_stream_vector_data_type<cint32, v2cint32>: public std::true_type {};
template<> struct is_stream_vector_data_type<cfloat, v2cfloat>: public std::true_type {};

template <aie_stream_resource_out Resource = aie_stream_resource_out::none,
          typename streamTy=void, typename dataTy=void>
static inline std::enable_if_t<is_stream_vector_data_type<streamTy, dataTy>::value>
writeincr_v2(output_stream<streamTy> *out, dataTy value, bool tlast = false)
{
    static_assert( sizeof(streamTy) == 8,
        "Error : writeincr_v2 only supported with 64-bit types cint32 and cfloat.");
    writeincr_v2(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none,
          typename streamTy=void, typename dataTy=void>
static inline std::enable_if_t<is_stream_vector_data_type<streamTy, dataTy>::value>
writeincr_v4(output_stream<streamTy> *out, dataTy value, bool tlast = false)
{
    static_assert( sizeof(streamTy) == 4,
        "Error : writeincr_v4 only supported with 32-bit types int32, cint16 and float.");
    writeincr_v4(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none,
          typename streamTy=void, typename dataTy=void>
static inline std::enable_if_t<is_stream_vector_data_type<streamTy, dataTy>::value>
writeincr_v8(output_stream<streamTy> *out, dataTy value, bool tlast = false)
{
    static_assert( sizeof(streamTy) == 2,
        "Error : writeincr_v8 only supported with 16-bit type int16.");
    writeincr_v8(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none,
          typename streamTy=void, typename dataTy=void>
static inline std::enable_if_t<is_stream_vector_data_type<streamTy, dataTy>::value>
writeincr_v16(output_stream<streamTy> *out, dataTy value, bool tlast = false)
{
    static_assert( sizeof(streamTy) == 1,
        "Error : writeincr_v16 only supported with 8-bit types int8 and uint8.");
    writeincr_v16(out,value,tlast);
}

#else

template<typename streamTy, typename dataTy>
struct is_stream_vector_data_type: public std::false_type {};
template<> struct is_stream_vector_data_type<int4, v32int4>: public std::true_type {};
template<> struct is_stream_vector_data_type<int4, v64int4>: public std::true_type {};
template<> struct is_stream_vector_data_type<int4, v128int4>: public std::true_type {};
template<> struct is_stream_vector_data_type<int4, v256int4>: public std::true_type {};

template<> struct is_stream_vector_data_type<uint4, v32uint4>: public std::true_type {};
template<> struct is_stream_vector_data_type<uint4, v64uint4>: public std::true_type {};
template<> struct is_stream_vector_data_type<uint4, v128uint4>: public std::true_type {};
template<> struct is_stream_vector_data_type<uint4, v256uint4>: public std::true_type {};

template<> struct is_stream_vector_data_type<bfloat16, v8bfloat16>: public std::true_type {};
template<> struct is_stream_vector_data_type<bfloat16, v16bfloat16>: public std::true_type {};
template<> struct is_stream_vector_data_type<bfloat16, v32bfloat16>: public std::true_type {};
template<> struct is_stream_vector_data_type<bfloat16, v64bfloat16>: public std::true_type {};

template<> struct is_stream_vector_data_type<float, v4float>: public std::true_type {};
template<> struct is_stream_vector_data_type<float, v8float>: public std::true_type {};
template<> struct is_stream_vector_data_type<float, v16float>: public std::true_type {};
template<> struct is_stream_vector_data_type<float, v32float>: public std::true_type {};

template<> struct is_stream_vector_data_type<int8, v16int8>: public std::true_type {};
template<> struct is_stream_vector_data_type<int8, v32int8>: public std::true_type {};
template<> struct is_stream_vector_data_type<int8, v64int8>: public std::true_type {};
template<> struct is_stream_vector_data_type<int8, v128int8>: public std::true_type {};

template<> struct is_stream_vector_data_type<uint8, v16uint8>: public std::true_type {};
template<> struct is_stream_vector_data_type<uint8, v32uint8>: public std::true_type {};
template<> struct is_stream_vector_data_type<uint8, v64uint8>: public std::true_type {};
template<> struct is_stream_vector_data_type<uint8, v128uint8>: public std::true_type {};

template<> struct is_stream_vector_data_type<int16, v8int16>: public std::true_type {};
template<> struct is_stream_vector_data_type<int16, v16int16>: public std::true_type {};
template<> struct is_stream_vector_data_type<int16, v32int16>: public std::true_type {};
template<> struct is_stream_vector_data_type<int16, v64int16>: public std::true_type {};

template<> struct is_stream_vector_data_type<uint16, v8uint16>: public std::true_type {};
template<> struct is_stream_vector_data_type<uint16, v16uint16>: public std::true_type {};
template<> struct is_stream_vector_data_type<uint16, v32uint16>: public std::true_type {};
template<> struct is_stream_vector_data_type<uint16, v64uint16>: public std::true_type {};

template<> struct is_stream_vector_data_type<int32, v4int32>: public std::true_type {};
template<> struct is_stream_vector_data_type<int32, v8int32>: public std::true_type {};
template<> struct is_stream_vector_data_type<int32, v16int32>: public std::true_type {};
template<> struct is_stream_vector_data_type<int32, v32int32>: public std::true_type {};

template<> struct is_stream_vector_data_type<uint32, v4uint32>: public std::true_type {};
template<> struct is_stream_vector_data_type<uint32, v8uint32>: public std::true_type {};
template<> struct is_stream_vector_data_type<uint32, v16uint32>: public std::true_type {};
template<> struct is_stream_vector_data_type<uint32, v32uint32>: public std::true_type {};

template<> struct is_stream_vector_data_type<cint16, v4cint16>: public std::true_type {};
template<> struct is_stream_vector_data_type<cint16, v8cint16>: public std::true_type {};
template<> struct is_stream_vector_data_type<cint16, v16cint16>: public std::true_type {};
template<> struct is_stream_vector_data_type<cint16, v32cint16>: public std::true_type {};

template<> struct is_stream_vector_data_type<cint32, v2cint32>: public std::true_type {};
template<> struct is_stream_vector_data_type<cint32, v4cint32>: public std::true_type {};
template<> struct is_stream_vector_data_type<cint32, v8cint32>: public std::true_type {};
template<> struct is_stream_vector_data_type<cint32, v16cint32>: public std::true_type {};

#if __AIE_ARCH__ == 20
template<> struct is_stream_vector_data_type<cfloat, v2cfloat>: public std::true_type {};
template<> struct is_stream_vector_data_type<cfloat, v4cfloat>: public std::true_type {};
template<> struct is_stream_vector_data_type<cfloat, v8cfloat>: public std::true_type {};
template<> struct is_stream_vector_data_type<cfloat, v16cfloat>: public std::true_type {};
#endif

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<int4> *out, v32int4 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<int4> *out, v64int4 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<int4> *out, v128int4 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<int4> *out, v256int4 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<uint4> *out, v32uint4 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<uint4> *out, v64uint4 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<uint4> *out, v128uint4 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<uint4> *out, v256uint4 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}   

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<bfloat16> *out, v8bfloat16 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<bfloat16> *out, v16bfloat16 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<bfloat16> *out, v32bfloat16 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<bfloat16> *out, v64bfloat16 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<float> *out, v4float value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<float> *out, v8float value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<float> *out, v16float value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<float> *out, v32float value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<cint16> *out, v4cint16 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<cint16> *out, v8cint16 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<cint16> *out, v16cint16 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<cint16> *out, v32cint16 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<cint32> *out, v2cint32 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<cint32> *out, v4cint32 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<cint32> *out, v8cint32 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<cint32> *out, v16cint32 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

#if __AIE_ARCH__ == 20
template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<cfloat> *out, v2cfloat value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<cfloat> *out, v4cfloat value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<cfloat> *out, v8cfloat value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<cfloat> *out, v16cfloat value, bool tlast = false)
{
    writeincr(out,value,tlast);
}
#endif

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<int8> *out, v16int8 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<int8> *out, v32int8 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<int8> *out, v64int8 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<int8> *out, v128int8 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<uint8> *out, v16uint8 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<uint8> *out, v32uint8 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<uint8> *out, v64uint8 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<uint8> *out, v128uint8 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<int16> *out, v8int16 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<int16> *out, v16int16 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<int16> *out, v32int16 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<int16> *out, v64int16 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<uint16> *out, v8uint16 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<uint16> *out, v16uint16 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<uint16> *out, v32uint16 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<uint16> *out, v64uint16 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<int32> *out, v4int32 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<int32> *out, v8int32 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<int32> *out, v16int32 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<int32> *out, v32int32 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<uint32> *out, v4uint32 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<uint32> *out, v8uint32 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<uint32> *out, v16uint32 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr(output_stream<uint32> *out, v32uint32 value, bool tlast = false)
{
    writeincr(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none,
          typename streamTy=void, typename dataTy=void>
static inline std::enable_if_t<is_stream_vector_data_type<streamTy, dataTy>::value>
writeincr_v2(output_stream<streamTy> *out, dataTy value, bool tlast = false)
{
    static_assert( sizeof(streamTy) == 8,
        "Error : writeincr_v2 only supported with 64-bit types cint32.");
    writeincr_v2(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none,
          typename streamTy=void, typename dataTy=void>
static inline std::enable_if_t<is_stream_vector_data_type<streamTy, dataTy>::value>
writeincr_v4(output_stream<streamTy> *out, dataTy value, bool tlast = false)
{
    static_assert(((sizeof(streamTy) == 8) || (sizeof(streamTy) == 4)),
        "Error : writeincr_v8 only supported with 32-bit types int32, uint32, "
        "float and cint16 and 64-bit type cint32.");
    writeincr_v4(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none,
          typename streamTy=void, typename dataTy=void>
static inline std::enable_if_t<is_stream_vector_data_type<streamTy, dataTy>::value>
writeincr_v8(output_stream<streamTy> *out, dataTy value, bool tlast = false)
{
    static_assert(((sizeof(streamTy) == 8) || (sizeof(streamTy) == 4) ||
        (sizeof(streamTy) == 2)),
        "Error : writeincr_v8 only supported with 16-bit types int16, uint16 and "
        "bfloat16, 32-bit types int32, uint32, float and cint16 and 64-bit type "
        "cint32.");
    writeincr_v8(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none,
          typename streamTy=void, typename dataTy=void>
static inline std::enable_if_t<is_stream_vector_data_type<streamTy, dataTy>::value>
writeincr_v16(output_stream<streamTy> *out, dataTy value, bool tlast = false)
{
    // Supported with all types except int4/uint4
    writeincr_v16(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none,
          typename streamTy=void, typename dataTy=void>
static inline std::enable_if_t<is_stream_vector_data_type<streamTy, dataTy>::value>
writeincr_v32(output_stream<streamTy> *out, dataTy value, bool tlast = false)
{
    static_assert(((sizeof(streamTy) == 2) || (sizeof(streamTy) == 4) ||
        (sizeof(streamTy) == 1)),
        "Error : writeincr_v32 only supported with 4-bit types int4,uint4 ,"
        "8-bit types int8,uint8, 16-bit type int16, uint16,"
        " bfloat16 and 32-bit types int32, uint32, float and cint16.");
    writeincr_v32(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none,
          typename streamTy=void, typename dataTy=void>
static inline std::enable_if_t<is_stream_vector_data_type<streamTy, dataTy>::value>
writeincr_v64(output_stream<streamTy> *out, dataTy value, bool tlast = false)
{
    static_assert(( sizeof(streamTy) == 1 || sizeof(streamTy) == 2),
        "Error : writeincr_v64 only supported with 16-bit type int16, uint16,"
        "bfloat16, 8-bit types int8 and uint8 and 4-bit types int4,uint4.");
    writeincr_v64(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none,
          typename streamTy=void, typename dataTy=void>
static inline std::enable_if_t<is_stream_vector_data_type<streamTy, dataTy>::value>
writeincr_v128(output_stream<streamTy> *out, dataTy value, bool tlast = false)
{
    static_assert(( sizeof(streamTy) == 1),
        "Error : writeincr_v128 only supported with 8-bit types int8, uint8"
        " and 4-bit types int4, uint4.");
    writeincr_v128(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr_v256(output_stream<int4> *out, v256int4 value, bool tlast = false)
{
    writeincr_v256(out,value,tlast);
}

template <aie_stream_resource_out Resource = aie_stream_resource_out::none>
static inline void
writeincr_v256(output_stream<uint4> *out, v256uint4 value, bool tlast = false)
{
    writeincr_v256(out,value,tlast);
}

#endif // if __AIE_ARCH__<20
#endif // if !defined(__PL_KERNEL__)
#endif // _SRC_X86SIM_INCLUDE_STREAM_API_H_
