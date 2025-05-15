// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// *****************************************************************************
// File: io_buffer_dims.h
// 
/// This file contains the definition of the bufer_port_dims class.
// *****************************************************************************
#ifndef SRC_IO_BUFFER_IO_BUFFER_DIMS_H_
#define SRC_IO_BUFFER_IO_BUFFER_DIMS_H_

#pragma once

#include <cstdint>
#include <limits>
#include <utility>
#include "detail/io_buffer_macros.h"

namespace adf {

//******************************************************************************
// inherited_extent indicates that the cardinality of a dimension will be inferred
// from the context, e.g., it may be specified in the graph, or it may be
// inferred from the characteristics of a port connected to given port.
//******************************************************************************
constexpr std::uint32_t inherited_extent = std::numeric_limits<uint32_t>::max();

//******************************************************************************
/// The class extents specifies compile-time information about the
/// dimensions of a io_buffer. It has the information about all dimensions. A
/// io_buffer must have at least 1 dimension. A dimension can be fixed in
/// size, or else it can be inherited, which means that the attributes about
/// this dimension will be determined later from the port bindings.
//******************************************************************************
template<uint32_t ...tpDims>
class extents {
public:
    using index_type = uint32_t;

    // returns the dimension with specified index
    static constexpr
    index_type dim(uint32_t n) noexcept {
        return _dim_impl(n, _ADF_MAKE_INDEX_SEQUENCE(sizeof...(tpDims)){});
    }

    // Returns true if any dimension is inherited
    static constexpr
    bool inherited() noexcept {
        return _ADF_FOLD_OR((tpDims == inherited_extent) /* || ...*/);
    }

    // Returns true if specified dimension is inherited
    static constexpr
    bool inherited(uint32_t n) noexcept {
        return (dim(n) == inherited_extent);
    }

    // Returns the number of dimensions
    static constexpr
    uint32_t num_dims() noexcept {
        return sizeof...(tpDims);
    }

    // Returns the number of dimensions that are inherited.
    static constexpr
    uint32_t num_inherited_dims() noexcept {
        return _ADF_FOLD_ADD(((tpDims == inherited_extent) ? 1 : 0));
    }

    // Returns the product of all dimensions of inherited size if any dimension
    // is inherited
    static constexpr
    index_type size() noexcept {
        return inherited() ? inherited_extent
            : (num_dims() ? (_ADF_FOLD_TIMES(tpDims)): 0);
    }

    // Returns the product of all dimensions of all non-inherited dimensions
    static constexpr
    index_type fixed_size() noexcept {
        return num_dims()
            ? (_ADF_FOLD_TIMES((tpDims == inherited_extent) ? 1 : tpDims))
            : 0;
    }

    // Returns the number of inherited dimensions amongst dimensions [0,ind)
    static constexpr
    index_type inherited_dim_rank(uint32_t ind) noexcept {
        return _inheritedDimRank_impl(ind, _ADF_MAKE_INDEX_SEQUENCE(sizeof...(tpDims)){});
    }

private:
    template <uint32_t... Idxs>
    static constexpr
    index_type _dim_impl
    (uint32_t n, _ADF_INDEX_SEQUENCE(Idxs...)) noexcept {
        return _ADF_FOLD_ADD((Idxs == n) ? tpDims : 0);
    }
    template <uint32_t... Idxs>
    static constexpr
    index_type _inheritedDimRank_impl
    (uint32_t n, _ADF_INDEX_SEQUENCE(Idxs...)) noexcept {
        return _ADF_FOLD_ADD((Idxs < n
                              && (tpDims == inherited_extent)) ? 1 : 0);
    }
    template <uint32_t... Idxs>
    static constexpr
    index_type _num_inherited_dims_impl
    (uint32_t n, _ADF_INDEX_SEQUENCE(Idxs...)) noexcept {
        return _ADF_FOLD_ADD((Idxs < n
                              && (tpDims == inherited_extent)) ? 1 : 0);
    }
};

using default_extents = extents<inherited_extent>;

//******************************************************************************
// Struct DimsTraits is a helper for sake of making Dims::numInheritedDims
//******************************************************************************
template<typename tpT>
struct extents_traits {
    static constexpr uint32_t num_dims() {return 0;}
    static constexpr uint32_t num_inherited_dims() {return 0;}
};

template<uint32_t ...tpDims>
struct extents_traits<extents<tpDims...>> {
    static constexpr uint32_t num_dims()
    {
        return extents<tpDims...>::num_dims();
    }
    static constexpr uint32_t num_inherited_dims()
    {
        return extents<tpDims...>::num_inherited_dims();
    }
    static constexpr bool inherited()
    {
        return extents<tpDims...>::inherited();
    }
};

} // namespace adf

#endif // ifndef SRC_IO_BUFFER_IO_BUFFER_DIMS_H_
