// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// *****************************************************************************
// File: io_buffer_util.h
// 
/// This file contains the definition of the template function 
/// numElem_to_sizeInBytes.
// *****************************************************************************
#ifndef _IO_BUFFER_SRC_DETAIL_IO_BUFFER_UTIL_H_
#define _IO_BUFFER_SRC_DETAIL_IO_BUFFER_UTIL_H_

namespace adf {
namespace detail {

template<typename tpValueTy>
struct is_4_bit_type: public std::false_type {};
#if __AIE_ARCH__>=20
template<> struct is_4_bit_type<int4>: public std::true_type {};
template<> struct is_4_bit_type<uint4>: public std::true_type {};
#endif

//******************************************************************************
// Function numElem_to_sizeInBytes
//
// This function will convert the offset (in terms of number of elements)
// to size in bytes. Since the size of 4-bit types is 1, we divide the computed 
// size in bytes by 2.
//******************************************************************************
template<typename tpValueTy>
static constexpr uint32_t numElem_to_sizeInBytes(uint32_t offset)
{
    if constexpr (is_4_bit_type<tpValueTy>::value)
    {
        return (uint32_t) ((offset * sizeof(tpValueTy)) / 2);
    }
    else
    {
        return (uint32_t) (offset * sizeof(tpValueTy));
    }
}

template<typename tpValueTy>
static constexpr uint32_t sizeInBytes_to_numElem(uint32_t offset)
{
    if constexpr (is_4_bit_type<tpValueTy>::value)
    {
        return (uint32_t) ((offset * 2) / sizeof(tpValueTy));
    }
    else
    {
        return (uint32_t) (offset / sizeof(tpValueTy));
    }
}

template<typename value_type>
constexpr static inline value_type* addMargin(value_type *buf, 
                                             unsigned margin) 
{
    if constexpr (is_4_bit_type<value_type>::value)
        return buf + (margin/2);
    else
        return buf + margin;
}

} // namespace detail
} // namespace adf
#endif // ifndef _IO_BUFFER_SRC_DETAIL_IO_BUFFER_UTIL_H_
