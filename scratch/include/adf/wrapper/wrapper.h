// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#include "systemc.h"

#include <bitset>
#include "adf/wrapper/me_ip_block.h"
#include "adf/wrapper/me_axi_stream.h"

#ifndef WRAPPER_H
#define WRAPPER_H

using namespace sc_core;

#include <type_traits>
#include "adf/stream/streams.h"
template<typename T> struct input_stream {
    MEStream64_get_port* fifo;
};

template<typename T> struct output_stream {
    MEStream64_put_port* fifo;
};

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
#if __AIE_ARCH__<=20
typedef input_stream<cfloat> input_stream_cfloat;
#endif
#if __AIE_ARCH__>=20
typedef input_stream<int4> input_stream_int4;
typedef input_stream<uint4> input_stream_uint4;
typedef input_stream<bfloat16> input_stream_bfloat16;
#endif
#if __AIE_ARCH__>=22
typedef input_stream<float16> input_stream_float16;
typedef input_stream<bfloat8> input_stream_bfloat8;
typedef input_stream<float8> input_stream_float8;
#endif

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
#if __AIE_ARCH__<=20
typedef output_stream<cfloat> output_stream_cfloat;
#endif
#if __AIE_ARCH__>=20
typedef output_stream<int4> output_stream_int4;
typedef output_stream<uint4> output_stream_uint4;
typedef output_stream<bfloat16> output_stream_bfloat16;
#endif
#if __AIE_ARCH__>=22
typedef output_stream<float16> output_stream_float16;
typedef output_stream<bfloat8> output_stream_bfloat8;
typedef output_stream<float8> output_stream_float8;
#endif


struct input_pktstream {
    MEStream64_get_port* fifo;
    std::vector<unsigned> pktIds; 
};

struct output_pktstream {
    MEStream64_put_port* fifo;
    std::vector<unsigned> pktIds; 
};


/////////////////////////////////////////////////////////////////////////////////////
// Stream read/write functions
// vector API are not implemented yet:
// 32 bit: v4int8, v4uint8, v2int16
// 64 bit: v8int8, v8uint8, v4int16, v2int32, v2cint16

// Reads------------------------------------------------------------
unsigned int readincr(input_stream_uint32 * in, bool &tlast) { 
  static_assert(sizeof(uint32) == 4, "uint32 is not a 32-bit type on this architecture");
  MEStreamData64  sample;
  (*(in->fifo))->get(sample);
  tlast = sample.tlast;
  return sample.data[0];
};

// this ignores tlast
unsigned int readincr(input_stream_uint32 * in ) { 
  bool tlast;
  return readincr(in, tlast);
};

int readincr(input_stream_int32 * in, bool &tlast) { 
  return (int) readincr((input_stream_uint32 *)in, tlast);
};

// this ignores tlast
int readincr(input_stream_int32 * in ) { 
  bool tlast;
  return readincr(in, tlast);
};

uint64 readincr(input_stream_uint64 * in, bool &tlast ) {
  static_assert(sizeof(uint64) == 8, "uint64 is not a 64-bit type on this architecture");
  MEStreamData64  sample;
  (*(in->fifo))->get(sample);
  tlast = sample.tlast;
  uint64 value;
  memcpy(&value, &sample.data[0], 8);
  return value;
};

// this ignores tlast
uint64 readincr(input_stream_uint64 * in) {
  bool tlast;
  return readincr(in, tlast);
}

int64 readincr(input_stream_int64 * in, bool &tlast) { 
  return (int64) readincr((input_stream_uint64 *)in, tlast);
};

// this ignores tlast
int64 readincr(input_stream_int64 * in ) { 
  bool tlast;
  return readincr(in, tlast);
};

float readincr(input_stream_float * in, bool &tlast) {
    uint32 value = readincr((input_stream_uint32 *)in, tlast);
    return *((float*)&value);
};

// this ignores tlast
float readincr(input_stream_float * in) {
    bool tlast;
    return readincr(in, tlast);
};

cint16 readincr(input_stream_cint16 * in, bool &tlast) {
  static_assert(sizeof(cint16) == 4, "cint16 is not a 32-bit type on this architecture");
  uint32 value  = readincr((input_stream_uint32 *)in, tlast);
  cint16 x ;
  memcpy(&x, &value, 4);
  return x;
};

// this ignores tlast
cint16 readincr(input_stream_cint16 * in) {
  bool tlast;
  return readincr(in, tlast);
}

cint32 readincr(input_stream_cint32 * in, bool &tlast ) {
  static_assert(sizeof(cint32) == 8, "cint32 is not a 64-bit type on this architecture");
  // Since cint32 is 64-bits, use input_stream_int64 to read the value
  uint64 value  = readincr((input_stream_uint64 *)in, tlast);
  cint32 x ;
  memcpy(&x, &value, 8);
  return x;
}

// this ignores tlast
cint32 readincr(input_stream_cint32 * in ) { 
  bool tlast;
  return readincr(in, tlast);
};

#if __AIE_ARCH__<=20
cfloat readincr(input_stream_cfloat * in, bool &tlast) {
    static_assert(sizeof(cfloat) == 8, "cfloat is not a 64-bit type on this architecture");
    // Since cfloat is 64-bits, use input_stream_uint64 to read the value
    uint64 value = readincr((input_stream_uint64 *)in, tlast);
    cfloat x;
    memcpy(&x, &value, 8);
    return x;
}

// this ignores tlast
cfloat readincr(input_stream_cfloat * in) {
    bool tlast;
    return readincr(in, tlast);
};
#endif //

// Writes------------------------------------------------------------

void writeincr(output_stream_uint32 * out, unsigned int value, bool tlast) { 
  static_assert(sizeof(uint32) == 4, "uint32 is not a 32-bit type on this architecture");
  MEStreamData64 scalar_value(value, 0, tlast, false);
  (*(out->fifo))->put(scalar_value);
};

// this puts out tlast as false
void writeincr(output_stream_uint32 * out, unsigned int value) { 
  writeincr(out, value, false);
};

void writeincr(output_stream_int32 * out, int value, bool tlast) { 
  writeincr((output_stream_uint32 *)out, (unsigned int)value, tlast);
};

// this puts out tlast as false
void writeincr(output_stream_int32 * out, int value) { 
  writeincr(out, value, false);
};

void writeincr(output_stream_uint64 * out, uint64 value, bool tlast) { 
  static_assert(sizeof(int64) == 8, "int64 is not a 64-bit type on this architecture");
  uint32 data[2];
  memcpy(data, &value, 8);
  MEStreamData64 scalar(data[0], data[1], tlast, true); 
  (*(out->fifo))->put(scalar);
};

// this puts out tlast as false
void writeincr(output_stream_uint64 * out, uint64 value) { 
  writeincr(out, value, false);
};

void writeincr(output_stream_int64 * out, int64 value, bool tlast) { 
  writeincr((output_stream_uint64 *)out, (uint64)value, tlast);
};

// this puts out tlast as false
void writeincr(output_stream_int64 * out, int64 value) { 
  writeincr(out, value, false);
};

void writeincr(output_stream_float * out, float value, bool tlast) {
static_assert(sizeof(uint32) == 4, "uint32 is not a 32-bit type on this architecture");
  MEStreamData64 scalar_value(*((unsigned int*)&value), 0, tlast, false);
  (*(out->fifo))->put(scalar_value);
//    writeincr((output_stream_uint32 *)out , *((unsigned int *)&value), tlast);
};

// this puts out tlast as false
void writeincr(output_stream_float * out, float value) {
    writeincr(out, value, false);
};

void writeincr(output_stream_cint16 * out, cint16 complex_value, bool tlast) { 
  static_assert(sizeof(cint16) == 4,"cint16 is not a 32-bit type on this architecture");
  uint32 x ;
  memcpy(&x, &complex_value, 4);
  writeincr((output_stream_uint32 *)out, x, tlast);
};

// this puts out tlast as false
void writeincr(output_stream_cint16 * out, cint16 value) { 
  writeincr(out, value, false);
};

void writeincr(output_stream_cint32 * out, cint32 value, bool tlast) { 
  static_assert(sizeof(cint32) == 8, "cint32 is not a 64-bit type on this architecture");
  uint64 x ;
  memcpy(&x, &value, 8);
  writeincr((output_stream_uint64 *)out, x, tlast);
}

// this puts out tlast as false
void writeincr(output_stream_cint32 * out, cint32 value) { 
  writeincr(out, value, false);
};

#if __AIE_ARCH__<=20
void writeincr(output_stream_cfloat * out, cfloat value, bool tlast) {
    static_assert(sizeof(cfloat) == 8, "cfloat is not a 64-bit type on this architecture");
    uint64 x;
    memcpy(&x, &value, 8);
    writeincr((output_stream_uint64 *)out, x, tlast);
}

// this puts out tlast as false
void writeincr(output_stream_cfloat * out, cfloat value) {
    writeincr(out, value, false);
};
#endif

////////////////////////////////////////////////////////////////////////////////////////
// Pkt Stream APIs
// only 32 bit API as of now

unsigned int readincr(input_pktstream * in, bool& tlast) { 
  static_assert(sizeof(uint32) == 4, "uint32 is not a 32-bit type on this architecture");
  MEStreamData64  sample;
  
  (*(in->fifo))->get(sample);
  tlast = sample.tlast;
  return sample.data[0];
};

void readincr(input_pktstream * in,float &value) {
  bool tlast;
  unsigned int val = readincr(in, tlast);
  value =  *((float *)&val);
};

// this ignores tlast
unsigned int readincr(input_pktstream * in) { 
  bool tlast;
  return readincr(in, tlast);
};

void writeincr(output_pktstream * out, unsigned int value, bool tlast) { 
  static_assert(sizeof(uint32) == 4, "uint32 is not a 32-bit type on this architecture");
  MEStreamData64 scalar_value(value, 0, tlast, false);
  (*(out->fifo))->put(scalar_value);
};

void writeincr(output_pktstream * out, float value, bool tlast) {
  writeincr((output_pktstream *)out, *((unsigned int*)&value), tlast);
};
void writeincr(output_pktstream * out, int32 value, bool tlast) {
  writeincr((output_pktstream *)out, *((unsigned int*)&value), tlast);
};

// this puts out tlast as false
void writeincr(output_pktstream * out, unsigned int value) { 
  writeincr((output_pktstream *)out, value, false);
};

uint32_t generateHeader(unsigned int pcktType, unsigned int srcCol, unsigned int srcRow, unsigned int ID)
{
  uint32_t header = ((srcCol & 0x7F) << 21) | ((srcRow & 0x1F) << 16) | ((pcktType & 0x7) << 12) | (ID & 0x1F);
    std::bitset<32> bitCounter(header);
    header = header | ((1 - (bitCounter.count() % 2)) << 31);
    return header;
}

uint32_t generateCtrlHeader(unsigned int returnID, unsigned int op, unsigned int numWords, unsigned int addr)
{
  uint32_t ctrlHeader = ((returnID & 0x1F) << 24) | ((op & 0x3) << 20) | ((numWords & 0x3) << 18) | (addr & 0x3FFFF);
    std::bitset<32> bitCounter(ctrlHeader);
    ctrlHeader = ctrlHeader | ((1 - (bitCounter.count() % 2)) << 31);
    return ctrlHeader;
}

uint32_t getPacketid(input_pktstream * in, int index) {
  //assert(index < in->pktIds.size(), "The index is greater than total number of packet ids assigned");
  return in->pktIds[index];
}

uint32_t getPacketid(output_pktstream * out, int index) {
  //assert(index < out->pktIds.size(), "The index is greater than total number of packet ids assigned");
  return out->pktIds[index];
}

#endif


