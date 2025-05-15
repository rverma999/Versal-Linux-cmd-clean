// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// *****************************************************************************
// File: io_buffer_types.h
// 
/// This file contains the definitions of the types associated with buffer
/// ports that are needed on adf graph code.
// *****************************************************************************
#ifndef SRC_IO_BUFFER_IO_BUFFER_TYPES_H_
#define SRC_IO_BUFFER_IO_BUFFER_TYPES_H_

#include <cstdint>
#include <limits>
#include "io_buffer_extents.h"

namespace adf {

namespace addressing {
struct linear {};
struct circular {};
}

namespace locking {
struct sync {};
struct async {};
}

template<uint32_t tpMargin = 0>
struct margin {
    static const uint32_t _margin = tpMargin;
};

namespace direction {
struct in;
struct out;
}

template<typename>
struct is_extents_class : std::false_type { };

template<uint32_t ...T>
struct is_extents_class<adf::extents<T...>> : std::true_type { };

template<typename>
struct is_margin_class : std::false_type { };

template<uint32_t T>
struct is_margin_class<adf::margin<T>> : std::true_type { };

constexpr std::uint32_t inherited_margin = std::numeric_limits<uint32_t>::max();

template<typename tpDims = extents<inherited_extent>,
         typename tpLocking = locking::sync,
         typename tpAddressing = addressing::linear,
         typename tpMargin = margin<0>>
struct io_buffer_config
{
    static_assert(std::is_same<locking::sync, tpLocking>::value || 
                  std::is_same<locking::async, tpLocking>::value, 
                  "Template argument for template parameter 'tpLocking' must be either adf::locking::sync or adf::locking::async");

    static_assert(std::is_same<addressing::linear, tpAddressing>::value || 
                  std::is_same<addressing::circular, tpAddressing>::value,
                  "Template argument for template parameter 'tpAddressing' must be either adf::addressing::linear or adf::addressing::circular");
    
    static_assert(is_margin_class<tpMargin>::value, 
                  "Template argument for template parameter 'tpMargin' must be of type adf::margin<uint32_t MARGIN>");

    static_assert(is_extents_class<tpDims>::value, 
                  "Template argument for template parameter 'tpDims' must be of type adf::extents<uint32_t ...EXTENTS>");

    using dims_type = tpDims;
    using locking_mode = tpLocking;
    using addressing_mode = tpAddressing;
    using margin_type = tpMargin;
    static uint32_t const _margin = tpMargin::_margin;
};

using bpc_sync_1d = io_buffer_config<extents<inherited_extent>,
                                        locking::sync>;
using bpc_async_1d = io_buffer_config<extents<inherited_extent>,
                                        locking::async>;

//******************************************************************************
/// class io_buffer
//
/// All buffer ports are instances of the io_buffer template. Partial
/// specializations are defined in io_buffer_main.h
//******************************************************************************
template<typename tpValueTy,
         typename tpDirection,
         typename tpConfig>
class io_buffer;

//******************************************************************************
/// Below are the definitions of the port types for kernel authors. 
///
/// input_buffer
/// input_circular_buffer
/// input_async_buffer
/// input_async_circular_buffer
//
//******************************************************************************
template<typename tpValueTy, typename tpExtents = extents<inherited_extent>, typename tpMargin = margin<0>>
using input_buffer
=io_buffer<tpValueTy,
               direction::in,
               io_buffer_config<tpExtents,
                                   locking::sync,
                                   addressing::linear,
                                   tpMargin>
                >;

template<typename tpValueTy, typename tpExtents = extents<inherited_extent>, typename tpMargin = margin<0>>
using input_async_buffer
= io_buffer<tpValueTy,
               direction::in,
               io_buffer_config<tpExtents,
                                   locking::async,
                                   addressing::linear,
                                   tpMargin>
              >;

template<typename tpValueTy, typename tpExtents = extents<inherited_extent>, typename tpMargin = margin<0>>
using input_circular_buffer
= io_buffer<tpValueTy,
               direction::in,
               io_buffer_config<tpExtents,
                                   locking::sync,
                                   addressing::circular,
                                   tpMargin>
              >;

template<typename tpValueTy, typename tpExtents = extents<inherited_extent>, typename tpMargin = margin<0>>
using input_async_circular_buffer
= io_buffer<tpValueTy,
               direction::in,
               io_buffer_config<tpExtents,
                                   locking::async,
                                   addressing::circular,
                                   tpMargin>
              >;

template<typename tpValueTy, typename tpExtents = extents<inherited_extent>, typename tpMargin = margin<0>>
using output_buffer
= io_buffer<tpValueTy,
               direction::out,
               io_buffer_config<tpExtents,
                                   locking::sync,
                                   addressing::linear,
                                   tpMargin>
              >;

template<typename tpValueTy, typename tpExtents = extents<inherited_extent>, typename tpMargin = margin<0>>
using output_async_buffer
= io_buffer<tpValueTy,
               direction::out,
               io_buffer_config<tpExtents,
                                   locking::async,
                                   addressing::linear,
                                   tpMargin>
              >;

template<typename tpValueTy, typename tpExtents = extents<inherited_extent>, typename tpMargin = margin<inherited_margin>>
using output_circular_buffer
= io_buffer<tpValueTy,
               direction::out,
               io_buffer_config<tpExtents,
                                   locking::sync,
                                   addressing::circular,
                                   tpMargin>
              >;

template<typename tpValueTy, typename tpExtents = extents<inherited_extent>, typename tpMargin = margin<inherited_margin>>
using output_async_circular_buffer
= io_buffer<tpValueTy,
               direction::out,
               io_buffer_config<tpExtents,
                                   locking::async,
                                   addressing::circular,
                                   tpMargin>
              >;

template<typename tpValueTy, typename tpConfig>
using input_buffer_conf
= io_buffer<tpValueTy, direction::in, tpConfig>;

template<typename tpValueTy, typename tpConfig>
using output_buffer_conf
= io_buffer<tpValueTy, direction::out, tpConfig>;



} // namespace adf

#endif // ifndef SRC_IO_BUFFER_IO_BUFFER_TYPES_H_

