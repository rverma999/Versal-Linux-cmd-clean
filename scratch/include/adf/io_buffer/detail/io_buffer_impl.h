// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// *****************************************************************************
// File: io_buffer_impl.h
// 
/// This file contains the implementation details of the io_buffer class.
// *****************************************************************************
#ifndef _IO_BUFFER_SRC_DETAIL_IO_BUFFER_IMPL_H_
#define _IO_BUFFER_SRC_DETAIL_IO_BUFFER_IMPL_H_

#pragma once
#include <cstddef>
#include <cstdint>
#include <limits>
#include <type_traits>
#include "io_buffer_util.h"

namespace adf {

struct io_buffer_access;

namespace detail {

//******************************************************************************
// class io_buffer_sizes
//
// This represents the actual sizes of each of the dimensions of a buffer. For
// dimensions for which the size is fixed and known at place of declaration, the
// size is encoded in the tpExtents type. For dimensions that are inherited
// (fixed and not known at place of declaration), the actual size of the
// dimension is stored in the io_buffer_sizes object.
//******************************************************************************
template<typename tpExtents, typename Enable = void>
struct io_buffer_sizes_storage;

template<typename tpExtents>
struct io_buffer_sizes_storage<tpExtents,
                                typename std::enable_if<extents_traits<tpExtents>
                                                        ::inherited()==false>::type>
{
    constexpr inline io_buffer_sizes_storage()
    {
    }
};

template<typename tpExtents>
struct io_buffer_sizes_storage<tpExtents,
                                typename std::enable_if<extents_traits<tpExtents>
                                                        ::inherited()==true>::type>
{
    template<typename ... tpSizes >
    inline io_buffer_sizes_storage(tpSizes ... sizes)
        : _sizes{sizes...}
    {
    }
    
    template <uint32_t... Idxs>
	inline
        uint32_t _variableSizeImpl(_ADF_INDEX_SEQUENCE(Idxs...)) const
        {
            return _ADF_FOLD_TIMES(_sizes[Idxs]);
        }
    
    uint32_t _sizes[tpExtents::num_inherited_dims()];
};

template<typename tpExtents>
class io_buffer_sizes: private io_buffer_sizes_storage<tpExtents>
{
public:
    using dims_type = tpExtents;

    template<typename ... tpSizes >
    inline io_buffer_sizes(tpSizes ... sizes)
        : io_buffer_sizes_storage<tpExtents>{(uint32_t)sizes...}
    {
    }

    constexpr inline uint32_t size(uint32_t const index) const
    {
        if constexpr (dims_type::inherited())
        {
            if (dims_type::inherited(index))
                return this->_sizes[dims_type::inherited_dim_rank(index)];
            else
                return dims_type::dim(index);
        }
            else
        {
            return dims_type::dim(index);
        }
    }

    constexpr inline uint32_t size() const
    {
        if constexpr (dims_type::inherited())
        {
            return dims_type::fixed_size()
            * this->_variableSizeImpl
            (_ADF_MAKE_INDEX_SEQUENCE(dims_type::num_inherited_dims()){});
        }
        else
        {
            return dims_type::size();
        }
    }

    constexpr static inline uint32_t dim(uint32_t index)
    {
        return dims_type::dim(index);
    }

    constexpr inline uint32_t getVariableSizeFactor() const
    {
        if constexpr (dims_type::inherited())
        {
            return this->_variableSizeImpl
                (_ADF_MAKE_INDEX_SEQUENCE(dims_type::num_inherited_dims()){});
        }
        else
        {
            return 1;
        }
    }
};

// *****************************************************************************
// class io_buffer_margin
// 
/// This is the io_buffer_margin class which is the data structure for
/// bookkeeping margin in buffer ports that have margin.
// *****************************************************************************
template<typename tpValueTy,
         typename tpLockingMode,
         typename tpMargin,
         typename Enable=void>
struct io_buffer_margin;

template<typename tpValueTy,
         typename tpLockingMode>
struct io_buffer_margin<tpValueTy, tpLockingMode, margin<0>, void>
{
    inline io_buffer_margin(uint32_t, uint32_t, tpValueTy *,bool)
    {
    }
    inline io_buffer_margin(uint32_t, uint32_t, tpValueTy *,tpValueTy *, bool)
    {
    }
};

template<typename tpValueTy, uint32_t tpMargin> 
struct io_buffer_margin<tpValueTy, locking::sync,
                           margin<tpMargin>, std::enable_if_t<tpMargin !=0>>
{
    inline io_buffer_margin(uint32_t size,
                               uint32_t margin,
                               tpValueTy *data0,
                               bool addMargin)
        :_head { detail::addMargin(data0, (addMargin ? margin : 0)) },
         _sizeInclMargin { size + margin }
    {
    }
    
    tpValueTy * __restrict _head;
    uint32_t               _sizeInclMargin;
};

template<typename tpValueTy, uint32_t tpMargin>
struct io_buffer_margin<tpValueTy, locking::async,
                                  margin<tpMargin>, std::enable_if_t<tpMargin !=0>>
{
    inline io_buffer_margin(uint32_t size,
                               uint32_t margin,
                               tpValueTy *data0,
                               tpValueTy *data1,
                               bool addMargin)
        :_heads { detail::addMargin(data0, (addMargin ? margin : 0)),
                  detail::addMargin(data1, (addMargin ? margin : 0))},
         _head {  detail::addMargin(data0, (addMargin ? margin : 0)) },
         _sizeInclMargin { size + margin }
    {
    }
    
    tpValueTy * __restrict _heads[2];
    tpValueTy * __restrict _head;
    uint32_t               _sizeInclMargin;
};

// *****************************************************************************
// class io_buffer_base
// 
/// This is the io_buffer_base class. 
// *****************************************************************************
template<typename tpValueTy,
         typename tpLockingMode>
struct io_buffer_base;

template<typename tpValueTy>
struct io_buffer_base<tpValueTy, locking::sync>
{
    inline io_buffer_base(tpValueTy *buf0)
        : _base(buf0)
    {
    }
    
    tpValueTy * __restrict _base;
};

template<typename tpValueTy>
struct io_buffer_base<tpValueTy, locking::async>
{
    inline io_buffer_base(tpValueTy *buf0,
                            uint32_t lockId0,
                            tpValueTy *buf1,
                            uint32_t lockId1)
        : _base { buf0 },
          _bufs { buf0, buf1 },
          _currentBufId { 0 },
          _lockIds { lockId0, lockId1 }
    {
    }
    
    tpValueTy *       __restrict _base;
    tpValueTy * const __restrict _bufs[2];
    uint32_t                     _currentBufId;
    uint32_t const               _lockIds[2];
};


template<typename tpValueTy>
static inline void bufferPortMarginCopy(tpValueTy * __restrict dstBuf,
                                        tpValueTy * __restrict srcBuf,
                                        unsigned int size,
                                        unsigned int margin)
{
#ifdef __AIENGINE__
  {
      int8_t * __restrict dst = (int8_t * __restrict) dstBuf;
      int8_t * __restrict src = (int8_t * __restrict) srcBuf;
      src += numElem_to_sizeInBytes<tpValueTy>(size);
    
      for (unsigned int k = 0; k < (numElem_to_sizeInBytes<tpValueTy>(margin))/32; ++k)
        chess_flatten_loop
        {
            *(v8int32 * __restrict )dst = *(v8int32 * __restrict )src;
            dst += 32;
            src += 32;
        }
  }
#else
  for (unsigned int k = 0; k < margin; ++k)
      dstBuf[k] = srcBuf[k + size];
#endif
}

} // namespace detail
} // namespace adf

#endif // ifndef _IO_BUFFER_SRC_DETAIL_IO_BUFFER_IMPL_H_
