// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// *****************************************************************************
// File: io_buffer_traits.h
// 
/// This file contains helper function for mapping the attributes of bufer_port
/// classes for use the the ADF front end.
// *****************************************************************************
#ifndef SRC_IO_BUFFER_IO_BUFFER_TRAITS_H_
#define SRC_IO_BUFFER_IO_BUFFER_TRAITS_H_

#include "io_buffer_types.h"
#include <type_traits>
#include <vector>

namespace adf {
namespace api_impl {

// Map io_buffer_dims to a std::vector<uint32_t>
template<typename>
struct MapBufferPortDims {
    operator std::vector<uint32_t>() const { return {}; }
};

template<uint32_t ...ds>
struct MapBufferPortDims<extents<ds...>>
{
    operator std::vector<uint32_t>() const { 
        return std::vector<uint32_t>{ds ...}; }
};

// Map data type
template<typename> constexpr param_type mapDataType() {return p_voidty;}
template<> constexpr param_type mapDataType<int8>() {return p_int8;}
template<> constexpr param_type mapDataType<int16>() {return p_int16;}
template<> constexpr param_type mapDataType<int32>() {return p_int32;}
template<> constexpr param_type mapDataType<int64>() {return p_int64;}
template<> constexpr param_type mapDataType<uint8>() {return p_uint8;}
template<> constexpr param_type mapDataType<uint16>() {return p_uint16;}
template<> constexpr param_type mapDataType<uint32>() {return p_uint32;}
template<> constexpr param_type mapDataType<uint64>() {return p_uint64;}
template<> constexpr param_type mapDataType<float>() {return p_float;}
template<> constexpr param_type mapDataType<cint16>() {return p_cint16;}
template<> constexpr param_type mapDataType<cint32>() {return p_cint32;}
template<> constexpr param_type mapDataType<cfloat>() {return p_cfloat;}
#if __AIE_ARCH__>=20
template<> constexpr param_type mapDataType<int4>() {return p_int4;}
template<> constexpr param_type mapDataType<uint4>() {return p_uint4;}
template<> constexpr param_type mapDataType<bfloat16>() {return p_bfloat16;}
#endif // __AIE_ARCH__<20
#if __AIE_ARCH__>=22
template<> constexpr param_type mapDataType<float16>() {return p_float16;}
template<> constexpr param_type mapDataType<bfloat8>() {return p_bfloat8;}
template<> constexpr param_type mapDataType<float8>() {return p_float8;}
#endif // __AIE_ARCH__>=22


// Map locking mode
template<typename> constexpr locking_mode mapBufferPortLockingMode() {return lm_none;}
template<> constexpr locking_mode mapBufferPortLockingMode<locking::sync>() {return lm_auto;}
template<> constexpr locking_mode mapBufferPortLockingMode<locking::async>() {return lm_user;}

template<typename> constexpr port_direction mapBufferPortDirection() {return dir_in;}
template<> constexpr port_direction mapBufferPortDirection<direction::out> () {return dir_out;}
template<> constexpr port_direction mapBufferPortDirection<direction::in> () {return dir_in;}

// Map all buffer port attributes for {async_,}{input,output}_buffer_{1,2,3}d.
// MapBufferPort is convertible to false if tpPortTy is not a buffer port.
// MapBufferPort is convertible to true if tpPortTy is a buffer port.
template<typename tpPortTy>
struct MapBufferPort: std::false_type {};

template<typename tpValueTy,
         typename tpDirection,
         typename tpConfig>
struct MapBufferPort<io_buffer<tpValueTy, tpDirection, tpConfig>>
    : std::true_type
{
    using dims_type = typename tpConfig::dims_type;

    static constexpr port_direction direction()
    {
        return mapBufferPortDirection<tpDirection>();
    }
    static constexpr param_type subPtype()
    {
        return mapDataType<tpValueTy>();
    }
    static constexpr locking_mode lockingMode()
    {
        return mapBufferPortLockingMode<typename tpConfig::locking_mode>();
    }
    static std::vector<uint32_t> dimensions()
    {
        return MapBufferPortDims<typename tpConfig::dims_type>();
    }
    static constexpr bool hasCyclicAddressing()
    {
        return std::is_same<typename tpConfig::addressing_mode, addressing::circular>::value;
    }
    static constexpr uint32_t margin()
    {
        return tpConfig::_margin;
    }
};


} //namespace api_impl
} // namespace adf

#endif // ifndef SRC_IO_BUFFER_IO_BUFFER_TRAITS_H_
