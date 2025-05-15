// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// *****************************************************************************
// File: io_buffer_macros.h
// 
/// This file contains the definitions of macros that allow us to swtich between
/// implementations depending on the language standard (c++11, c++14, c++17).
// *****************************************************************************
#ifndef SRC_IO_BUFFER_DETAIL_IO_BUFFER_MACROS_H_
#define SRC_IO_BUFFER_DETAIL_IO_BUFFER_MACROS_H_

#pragma once
#include <utility>

#if defined(__cplusplus) && __cplusplus >= 201402L
#define _ADF_IO_BUFFER_USE_INTEGER_SEQUENCE 1
#endif

#if !defined(_ADF_IO_BUFFER_USE_INTEGER_SEQUENCE) || !_ADF_IO_BUFFER_USE_INTEGER_SEQUENCE

namespace adf {

template <uint32_t... tpInds>
struct index_sequence {
   static constexpr std::uint32_t size() noexcept { return sizeof...(tpInds); }
};

template <uint32_t ptNum, uint32_t tpInd, class tpResult>
struct _make_index_sequence_impl;

template <uint32_t ptNum, uint32_t... tpInds>
struct _make_index_sequence_impl<ptNum, ptNum, index_sequence<tpInds...>>
{
   using type = index_sequence<tpInds...>;
};

template <uint32_t ptNum, uint32_t tpInd, uint32_t... tpInds>
struct _make_index_sequence_impl<ptNum, tpInd, index_sequence<tpInds...>
> : _make_index_sequence_impl<ptNum, tpInd + 1,
                               index_sequence<tpInds..., tpInd>>
{ };

template <uint32_t tpNum>
using make_index_sequence
    = typename _make_index_sequence_impl<tpNum, 0, index_sequence<>>::type;

} // namesapce adf

#define _ADF_MAKE_INDEX_SEQUENCE(NUM) \
adf::make_index_sequence<NUM>

#define _ADF_INDEX_SEQUENCE(INDS) \
adf::index_sequence<INDS>

#else // #if !defined(_ADF_IO_BUFFER_USE_INTEGER_SEQUENCE) || !_ADF_IO_BUFFER_USE_INTEGER_SEQUENCE
#define _ADF_MAKE_INDEX_SEQUENCE(NUM) \
std::make_integer_sequence<uint32_t, NUM>

#define _ADF_INDEX_SEQUENCE(INDS) \
std::integer_sequence<uint32_t, INDS>

#endif // #if !defined(_ADF_IO_BUFFER_USE_INTEGER_SEQUENCE) || !_ADF_IO_BUFFER_USE_INTEGER_SEQUENCE



#if defined(__cplusplus) && __cplusplus >= 201703L
#define _ADF_IO_BUFFER_USE_FOLD_EXPR 1
#endif

#if !defined(_ADF_IO_BUFFER_USE_FOLD_EXPR) || !_ADF_IO_BUFFER_USE_FOLD_EXPR
namespace adf {

constexpr bool _fold_or_impl()
{
    return false;
}

template<typename tpArg0, typename ...tpArgs>
constexpr bool _fold_or_impl(tpArg0 && arg0, tpArgs &&...args)
{
    return ((tpArg0 &&)arg0) || _fold_or_impl((tpArgs&&)args...);
}

constexpr uint32_t _fold_add_impl()
{
    return 0;
}

template<typename tpArg0, typename ...tpArgs>
constexpr uint32_t _fold_add_impl(tpArg0 && arg0, tpArgs &&...args)
{
    return ((tpArg0 &&)arg0) + _fold_add_impl((tpArgs&&)args...);
}

constexpr uint32_t _fold_times_impl()
{
    return 1;
}

template<typename tpArg0, typename ...tpArgs>
constexpr uint32_t _fold_times_impl(tpArg0 && arg0, tpArgs &&...args)
{
    return ((tpArg0 &&)arg0) * _fold_times_impl((tpArgs&&)args...);
}

#define _ADF_FOLD_OR(...) _fold_or_impl((__VA_ARGS__)...)
#define _ADF_FOLD_ADD(...) _fold_add_impl((__VA_ARGS__)...)
#define _ADF_FOLD_TIMES(...) _fold_times_impl((__VA_ARGS__)...)
} // namespace adf

#else //#if !defined(_ADF_IO_BUFFER_USE_FOLD_EXPR) || !_ADF_IO_BUFFER_USE_FOLD_EXPR

#define _ADF_FOLD_OR(...) ((__VA_ARGS__) || ...)
#define _ADF_FOLD_ADD(...) (0 + ...+ (__VA_ARGS__))
#define _ADF_FOLD_TIMES(...) (1 * ... * (__VA_ARGS__))

#endif //#if !defined(_ADF_IO_BUFFER_USE_FOLD_EXPR) || !_ADF_IO_BUFFER_USE_FOLD_EXPR

#endif // ifndef SRC_IO_BUFFER_DETAIL_IO_BUFFER_MACROS_H_
