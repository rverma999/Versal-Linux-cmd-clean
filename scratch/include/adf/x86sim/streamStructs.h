// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef _SRC_X86SIM_INCLUDE_STREAM_STRUCTS_H_
#define _SRC_X86SIM_INCLUDE_STREAM_STRUCTS_H_

#include "symbolVisibility.h"
#include <vector>
#include "streamUtils.h"

namespace x86sim {
struct stream_internal;
struct casc48_internal;
struct StreamConnectorBase;
struct CascadeStreamConnector;

X86SIM_EXPORT x86sim::StreamConnectorBase * 
    get_stream_connector(x86sim::stream_internal* strm);
X86SIM_EXPORT const int *
    get_pktstream_pktIds(x86sim::stream_internal* strm);
}

template<typename T>
struct input_stream {
    x86sim::StreamConnectorBase *con;
    unsigned channel; 
    input_stream(x86sim::stream_internal *str, unsigned ch) 
    : con(get_stream_connector(str)),channel(ch) {};
};

template<typename T>
struct output_stream {
    x86sim::StreamConnectorBase *con;
    unsigned channel; 
    output_stream(x86sim::stream_internal *str, unsigned ch) 
    : con(get_stream_connector(str)),channel(ch) {};
};


struct input_pktstream {
    x86sim::StreamConnectorBase *con;
    unsigned channel;
    const int *pktIds; 
    input_pktstream(x86sim::stream_internal *str, unsigned ch) 
    : con(get_stream_connector(str)),
      channel(ch), pktIds(get_pktstream_pktIds(str)) {};
};

struct output_pktstream {
    x86sim::StreamConnectorBase *con;
    unsigned channel; 
    const int *pktIds;
    output_pktstream(x86sim::stream_internal *str, unsigned ch) 
    : con(get_stream_connector(str)),
      channel(ch), pktIds(get_pktstream_pktIds(str)) {};
};

template<>
struct input_stream<accfloat>{
   x86sim::CascadeStreamConnector *con;
};

template<>
struct output_stream<accfloat>{
   x86sim::CascadeStreamConnector *con;
};

#if __AIE_ARCH__ < 20

template<>
struct input_stream<acc48>{
   x86sim::CascadeStreamConnector *con;
};

template<>
struct input_stream<acc80>{
   x86sim::CascadeStreamConnector *con;
};

template<>
struct input_stream<cacc48>{
   x86sim::CascadeStreamConnector *con;
};

template<>
struct input_stream<cacc80>{
   x86sim::CascadeStreamConnector *con;
};

template<>
struct input_stream<caccfloat>{
   x86sim::CascadeStreamConnector *con;
};

template<>
struct output_stream<acc48>{
   x86sim::CascadeStreamConnector *con;
};

template<>
struct output_stream<acc80>{
   x86sim::CascadeStreamConnector *con;
};

template<>
struct output_stream<cacc48>{
   x86sim::CascadeStreamConnector *con;
};

template<>
struct output_stream<cacc80>{
   x86sim::CascadeStreamConnector *con;
};

template<>
struct output_stream<caccfloat>{
   x86sim::CascadeStreamConnector *con;
};

#endif // if __AIE_ARCH__<20

#if __AIE_ARCH__ >= 20

template<>
struct input_stream<acc32>{
   x86sim::CascadeStreamConnector *con;
};

template<>
struct input_stream<acc64>{
   x86sim::CascadeStreamConnector *con;
};

template<>
struct output_stream<acc32>{
   x86sim::CascadeStreamConnector *con;
};

template<>
struct output_stream<acc64>{
   x86sim::CascadeStreamConnector *con;
};

#endif // if __AIE_ARCH__ == 20

template<typename Ty>
struct input_cascade<Ty, typename std::enable_if<x86sim::is_one_of<Ty, 
                                                   acc48, cacc48, acc32, cacc32,
                                                   acc64, cacc64, accfloat, int8,
                                                   int16, int32, int64, uint8, uint16, 
                                                   cint16, cint32, float
#if __AIE_ARCH__<20
                                                   ,acc80, cacc80
#endif
#if __AIE_ARCH__<=20
                                                   , cfloat, caccfloat
#endif
#if __AIE_ARCH__ >= 20
                                                   , int4, uint4, bfloat16
#endif
#if __AIE_ARCH__ == 22
                                                   , float16, bfloat8, float8
#endif
                                                   >>::type> { };

template<typename Ty>
struct output_cascade<Ty, typename std::enable_if<x86sim::is_one_of<Ty, 
                                                   acc48, cacc48, acc32, cacc32,
                                                   acc64, cacc64, accfloat, int8,
                                                   int16, int32, int64, uint8, uint16, 
                                                   cint16, cint32, float
#if __AIE_ARCH__<20
                                                   ,acc80, cacc80
#endif
#if __AIE_ARCH__ <=20
                                                   , cfloat, caccfloat
#endif
#if __AIE_ARCH__ >= 20
                                                   , int4, uint4, bfloat16
#endif
#if __AIE_ARCH__ == 22
                                                   , float16, bfloat8, float8
#endif
                                                   >>::type> { };

#endif // _SRC_X86SIM_INCLUDE_STREAM_STRUCTS_H
