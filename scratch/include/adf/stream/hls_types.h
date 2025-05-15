// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef __HLS_TYPES_H__
#define __HLS_TYPES_H__

namespace hls
{
    template <typename __STREAM_T__, int DEPTH> class stream; //Vitis HLS. Cannot specify DEPTH=0 because if hls_stream.h coexist with adf.h, c++ standard does not allow default tempalte parameter value be redefined.
    //template <typename __STREAM_T__> class stream; //Vivado HLS
    template <typename T, size_t WUser, size_t WId, size_t WDest> struct axis;
}

template <int _AP_W> struct ap_int;
template <int _AP_W> struct ap_uint;

template <size_t WData, size_t WUser, size_t WId, size_t WDest>
using ap_axis = hls::axis<ap_int<WData>, WUser, WId, WDest>;

template <size_t WData, size_t WUser, size_t WId, size_t WDest>
using ap_axiu = hls::axis<ap_uint<WData>, WUser, WId, WDest>;

#endif 
