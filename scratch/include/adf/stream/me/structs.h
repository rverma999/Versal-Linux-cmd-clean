// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#include "adf/stream/types.h"
#include<type_traits>

#ifndef __STREAM_ME_CONCRETE_TYPES_H__
#define __STREAM_ME_CONCRETE_TYPES_H__

template<typename T> struct input_stream;
template<typename T> struct output_stream;

#if __AIE_ARCH__<20
#define INPUT_STREAM_BODY                                      \
    union {                                                    \
        unsigned channel;                                      \
        me_primitive::ss_idx_t  restrict channel_ss;           \
        me_primitive::ss0_idx_t restrict channel_ss0;          \
        me_primitive::ss1_idx_t restrict channel_ss1;          \
        me_primitive::ss_tlast_idx_t restrict channel_sst;     \
        me_primitive::ss0_tlast_idx_t restrict channel_sst0;   \
        me_primitive::ss1_tlast_idx_t restrict channel_sst1;   \
        me_primitive::wss_idx_t  restrict channel_wss;         \
        me_primitive::wss0_idx_t restrict channel_wss0;        \
        me_primitive::wss1_idx_t restrict channel_wss1;        \
        me_primitive::wss_tlast_idx_t restrict channel_wsst;   \
        me_primitive::wss0_tlast_idx_t restrict channel_wsst0; \
        me_primitive::wss1_tlast_idx_t restrict channel_wsst1; \
    };                                                         \
    input_stream(unsigned ch) : channel(ch) {}

#define OUTPUT_STREAM_BODY                                     \
    union {                                                    \
        unsigned channel;                                      \
        me_primitive::ms_idx_t  restrict channel_ms;           \
        me_primitive::ms0_idx_t restrict channel_ms0;          \
        me_primitive::ms1_idx_t restrict channel_ms1;          \
        me_primitive::wms_idx_t  restrict channel_wms;         \
        me_primitive::wms0_idx_t restrict channel_wms0;        \
        me_primitive::wms1_idx_t restrict channel_wms1;        \
    };                                                         \
    output_stream(unsigned ch) : channel(ch) {}

template<> struct input_stream<int8> { INPUT_STREAM_BODY; };
template<> struct input_stream<int16> { INPUT_STREAM_BODY; };
template<> struct input_stream<int32> { INPUT_STREAM_BODY; };
template<> struct input_stream<int64> { INPUT_STREAM_BODY; };
template<> struct input_stream<uint8> { INPUT_STREAM_BODY; };
template<> struct input_stream<uint16> { INPUT_STREAM_BODY; };
template<> struct input_stream<uint32> { INPUT_STREAM_BODY; };
template<> struct input_stream<uint64> { INPUT_STREAM_BODY; };
template<> struct input_stream<float> { INPUT_STREAM_BODY; };

template<> struct output_stream<int8> { OUTPUT_STREAM_BODY; };
template<> struct output_stream<int16> { OUTPUT_STREAM_BODY; };
template<> struct output_stream<int32> { OUTPUT_STREAM_BODY; };
template<> struct output_stream<int64> { OUTPUT_STREAM_BODY; };
template<> struct output_stream<uint8> { OUTPUT_STREAM_BODY; };
template<> struct output_stream<uint16> { OUTPUT_STREAM_BODY; };
template<> struct output_stream<uint32> { OUTPUT_STREAM_BODY; };
template<> struct output_stream<uint64> { OUTPUT_STREAM_BODY; };
template<> struct output_stream<float> { OUTPUT_STREAM_BODY; };
#else
template<> struct input_stream<int4> { unsigned channel; input_stream(unsigned ch) : channel(ch) {}; };
template<> struct input_stream<uint4> { unsigned channel; input_stream(unsigned ch) : channel(ch) {}; };
template<> struct input_stream<int8> { unsigned channel; input_stream(unsigned ch) : channel(ch) {}; };
template<> struct input_stream<int16> { unsigned channel; input_stream(unsigned ch) : channel(ch) {}; };
template<> struct input_stream<int32> { unsigned channel; input_stream(unsigned ch) : channel(ch) {}; };
template<> struct input_stream<int64> { unsigned channel; input_stream(unsigned ch) : channel(ch) {}; };
template<> struct input_stream<uint8> { unsigned channel; input_stream(unsigned ch) : channel(ch) {}; };
template<> struct input_stream<uint16> { unsigned channel; input_stream(unsigned ch) : channel(ch) {}; };
template<> struct input_stream<bfloat16> { unsigned channel; input_stream(unsigned ch) : channel(ch) {}; };
template<> struct input_stream<uint32> { unsigned channel; input_stream(unsigned ch) : channel(ch) {}; };
template<> struct input_stream<uint64> { unsigned channel; input_stream(unsigned ch) : channel(ch) {}; };
template<> struct input_stream<float> { unsigned channel; input_stream(unsigned ch) : channel(ch) {}; };
#if __AIE_ARCH__>=22
template<> struct input_stream<float16> { unsigned channel; input_stream(unsigned ch) : channel(ch) {}; };
template<> struct input_stream<bfloat8> { unsigned channel; input_stream(unsigned ch) : channel(ch) {}; };
template<> struct input_stream<float8> { unsigned channel; input_stream(unsigned ch) : channel(ch) {}; };
#endif

template<> struct output_stream<int4> { unsigned channel; output_stream(unsigned ch) : channel(ch) {}; };
template<> struct output_stream<uint4> { unsigned channel; output_stream(unsigned ch) : channel(ch) {}; };
template<> struct output_stream<int8> { unsigned channel; output_stream(unsigned ch) : channel(ch) {}; };
template<> struct output_stream<int16> { unsigned channel; output_stream(unsigned ch) : channel(ch) {}; };
template<> struct output_stream<int32> { unsigned channel; output_stream(unsigned ch) : channel(ch) {}; };
template<> struct output_stream<int64> { unsigned channel; output_stream(unsigned ch) : channel(ch) {}; };
template<> struct output_stream<uint8> { unsigned channel; output_stream(unsigned ch) : channel(ch) {}; };
template<> struct output_stream<uint16> { unsigned channel; output_stream(unsigned ch) : channel(ch) {}; };
template<> struct output_stream<bfloat16> { unsigned channel; output_stream(unsigned ch) : channel(ch) {}; };
template<> struct output_stream<uint32> { unsigned channel; output_stream(unsigned ch) : channel(ch) {}; };
template<> struct output_stream<uint64> { unsigned channel; output_stream(unsigned ch) : channel(ch) {}; };
template<> struct output_stream<float> { unsigned channel; output_stream(unsigned ch) : channel(ch) {}; };
#if __AIE_ARCH__>=22
template<> struct output_stream<float16> { unsigned channel; output_stream(unsigned ch) : channel(ch) {}; };
template<> struct output_stream<bfloat8> { unsigned channel; output_stream(unsigned ch) : channel(ch) {}; };
template<> struct output_stream<float8> { unsigned channel; output_stream(unsigned ch) : channel(ch) {}; };
#endif
#endif

#if __AIE_ARCH__<20
template<> struct input_stream<cint16> { INPUT_STREAM_BODY; };
template<> struct input_stream<cint32> { INPUT_STREAM_BODY; };
template<> struct input_stream<cfloat> { INPUT_STREAM_BODY; };
template<> struct output_stream<cint16> { OUTPUT_STREAM_BODY; };
template<> struct output_stream<cint32> { OUTPUT_STREAM_BODY; };
template<> struct output_stream<cfloat> { OUTPUT_STREAM_BODY; };
template<> struct input_stream<cacc48> { };
template<> struct output_stream<cacc48>  { };
template<> struct input_stream<cacc80>  { };
template<> struct output_stream<cacc80>  { };
template<> struct input_stream<caccfloat>  { };
template<> struct output_stream<caccfloat>  { };
#else //for aie-ml
template<> struct input_stream<cint16> { unsigned channel; input_stream(unsigned ch) : channel(ch) {}; };
template<> struct input_stream<cint32> { unsigned channel; input_stream(unsigned ch) : channel(ch) {}; };
template<> struct output_stream<cint16> { unsigned channel; output_stream(unsigned ch) : channel(ch) {}; };
template<> struct output_stream<cint32> { unsigned channel; output_stream(unsigned ch) : channel(ch) {}; };
#endif
#if __AIE_ARCH__==20
template<> struct input_stream<cfloat> { unsigned channel; input_stream(unsigned ch) : channel(ch) {}; };
template<> struct output_stream<cfloat> { unsigned channel; output_stream(unsigned ch) : channel(ch) {}; };
#endif // if __AIE_ARCH__==20

//Why declare unsigned dummy?
#if __AIE_ARCH__<20
template<> struct input_stream<acc48> { };
template<> struct output_stream<acc48> { };
template<> struct input_stream<acc80> { };
template<> struct output_stream<acc80> { };
template<> struct input_stream<accfloat> { };
template<> struct output_stream<accfloat> { };
#else
template<> struct input_stream<acc32> { unsigned dummy; input_stream() {}; };
template<> struct input_stream<acc64> { unsigned dummy; input_stream() {}; };
template<> struct input_stream<cacc64> { unsigned dummy; input_stream() {}; };
#ifndef __AIECC__
template<> struct input_stream<accfloat> { unsigned dummy; input_stream() {}; };
#endif
template<> struct output_stream<acc32> { unsigned dummy; output_stream() {}; };
template<> struct output_stream<acc64> { unsigned dummy; output_stream() {}; };
template<> struct output_stream<cacc64> { unsigned dummy; output_stream() {}; };
#ifndef __AIECC__
template<> struct output_stream<accfloat> { unsigned dummy; output_stream() {}; };
#endif
#endif


template<typename Ty>
struct input_cascade<Ty, typename std::enable_if<(
                     std::is_same_v<Ty, acc48> || std::is_same_v<Ty, cacc48> ||
                     std::is_same_v<Ty, acc32> || std::is_same_v<Ty, cacc32> ||
                     std::is_same_v<Ty, acc64> || std::is_same_v<Ty, cacc64> ||
                     std::is_same_v<Ty, accfloat> ||
                     std::is_same_v<Ty, int8>  || std::is_same_v<Ty, int16> ||
                     std::is_same_v<Ty, int32> || std::is_same_v<Ty, int64> ||
                     std::is_same_v<Ty, uint8> || std::is_same_v<Ty, uint16> ||
                     std::is_same_v<Ty, cint32> || std::is_same_v<Ty, cint16> ||
                     std::is_same_v<Ty, float> || std::is_same_v<Ty, cfloat>
#if __AIE_ARCH__<=20
                     || std::is_same_v<Ty, caccfloat> 
#endif
#if __AIE_ARCH__<20
                     || std::is_same_v<Ty, acc80> || std::is_same_v<Ty, cacc80> 
#else 
									   || std::is_same_v<Ty, int4>
                     || std::is_same_v<Ty, uint4> || std::is_same_v<Ty, bfloat16>
#endif
#if __AIE_ARCH__>=22
                     || std::is_same_v<Ty, float16> || std::is_same_v<Ty, bfloat8>
                     || std::is_same_v<Ty, float8>
#endif
                                                   )>::type> { };

template<typename Ty>
struct output_cascade<Ty, typename std::enable_if<(
                     std::is_same_v<Ty, acc48> || std::is_same_v<Ty, cacc48> ||
                     std::is_same_v<Ty, acc32> || std::is_same_v<Ty, cacc32> ||
                     std::is_same_v<Ty, acc64> || std::is_same_v<Ty, cacc64> ||
                     std::is_same_v<Ty, accfloat> ||
                     std::is_same_v<Ty, int8>  || std::is_same_v<Ty, int16> ||
                     std::is_same_v<Ty, int32> || std::is_same_v<Ty, int64> ||
                     std::is_same_v<Ty, uint8> || std::is_same_v<Ty, uint16> ||
                     std::is_same_v<Ty, cint32> || std::is_same_v<Ty, cint16> ||
                     std::is_same_v<Ty, float> || std::is_same_v<Ty, cfloat>
#if __AIE_ARCH__<=20
                     || std::is_same_v<Ty, caccfloat> 
#endif
#if __AIE_ARCH__<20
                     || std::is_same_v<Ty, acc80> || std::is_same_v<Ty, cacc80> 
#else 
                     || std::is_same_v<Ty, int4>
                     || std::is_same_v<Ty, uint4> || std::is_same_v<Ty, bfloat16>
#endif
#if __AIE_ARCH__>=22
                     || std::is_same_v<Ty, float16> || std::is_same_v<Ty, bfloat8>
                     || std::is_same_v<Ty, float8>
#endif
                                                   )>::type> { };

struct input_pktstream { unsigned channel; int *pktIds; input_pktstream(unsigned ch, int *pids) : channel(ch), pktIds(pids) {}; };
struct output_pktstream { unsigned channel; int *pktIds; output_pktstream(unsigned ch, int *pids) : channel(ch), pktIds(pids) {}; };

# undef INPUT_STREAM_BODY
# undef OUTPUT_STREAM_BODY

#endif



