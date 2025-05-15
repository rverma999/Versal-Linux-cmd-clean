// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// *****************************************************************************
// File: io_buffer_main.h
// 
/// This file contains the definition of the io_buffer class.
// *****************************************************************************
#ifndef SRC_IO_BUFFER_IO_BUFFER_MAIN_H_
#define SRC_IO_BUFFER_IO_BUFFER_MAIN_H_

#include <cstddef>
#include <cstdint>
#include <limits>
#include <type_traits>
#include "io_buffer_types.h"
#include "io_buffer_internal.h"
#include "detail/io_buffer_impl.h"
#include "io_buffer_internal.h"

namespace adf {


// *****************************************************************************
// class io_buffer
// 
/// 
// *****************************************************************************
template<typename tpValueTy,
         typename tpDirection,
         typename tpDims,
         typename tpLockingMode,
         typename tpAddressingMode,
         typename tpMargin>
class io_buffer<tpValueTy, tpDirection,
                  io_buffer_config<tpDims, tpLockingMode, tpAddressingMode,
                                     tpMargin>>
     : public io_buffer_internal,
       protected detail::io_buffer_base<tpValueTy, tpLockingMode>,
       protected detail::io_buffer_sizes<tpDims>,
       protected detail::io_buffer_margin<tpValueTy, tpLockingMode, tpMargin>
{
private:
    using base_type1 = detail::io_buffer_base<tpValueTy, tpLockingMode>;
    using base_type2 = detail::io_buffer_sizes<tpDims>;
    using base_type3
    =  detail::io_buffer_margin<tpValueTy, tpLockingMode, tpMargin>;
public:
    using value_type = tpValueTy;
    using dims_type = tpDims;
    using config_type = io_buffer_config<tpDims,
                                           tpLockingMode,
                                           tpAddressingMode,
                                           tpMargin>;
    friend struct adf::io_buffer_access;
public:
    /**
     * @ingroup group_basic_types
     *
     * Constructor for the case where the compiler takes care of locking.
     * This is provided for use in test benches only.
     *
     * @param data0 The base address of the buffer
     * @param size The number of elements excluding margin
     * @param margin The margin in number of elements
     * @param sizes... The sizes of the inherited dimensions in number of elements.
     */
    template<typename tpLockingMode2 = tpLockingMode,
             typename ... tpSizes >    
    inline io_buffer
    (std::enable_if_t<std::is_same_v<tpLockingMode2, locking::sync>,
                      value_type> *data0,
     uint32_t    size,
     uint32_t    margin,
     tpSizes ... sizes)
        :   base_type1 { detail::addMargin(data0, ((config_type::_margin == 0) ? margin : 0)) },
            base_type2 { sizes ... },
            base_type3 ( size, margin, data0,
                      std::is_same_v<tpDirection,direction::out>)
    {
    }

    /**
     * @ingroup group_basic_types
     *
     * Constructor for the case where the buffer port has user-controlled
     * locking. This is provided for use in test benches only.
     *
     * @param data0 The base address of the ping buffer
     * @param lockId0 The first lock. For AIE1 this is the lock of the ping buffer. For aie_ml this is the producer lock
     * @param data1 The base address of the pong buffer
     * @param lockId1 For AIE1 this is the lock of the ping buffer. For aie_ml this is the consumer lock
     * @param size The number of elements excluding margin
     * @param margin The margin in number of elements
     * @param sizes... The sizes of the inherited dimensions in number of elements.
     */
    template<typename tpLockingMode2 = tpLockingMode,
             typename ... tpSizes >
    inline io_buffer
    (std::enable_if_t<std::is_same_v<tpLockingMode2, locking::async>,
                      value_type> *data0,
                       unsigned    lockId0,
                       value_type *data1,
                       unsigned    lockId1,
                       uint32_t    size,
                       uint32_t    margin,
                       tpSizes ... sizes)
        :   base_type1 { detail::addMargin(data0, ((config_type::_margin == 0) ? margin : 0)), lockId0,
                         detail::addMargin(data1, ((config_type::_margin == 0) ? margin : 0)), lockId1 },
            base_type2 { sizes ... },
            base_type3 ( size, margin, data0, data1,
                      std::is_same_v<tpDirection,direction::out>)
    {
    }

    /**
     * @ingroup group_basic_types
     *
     * Returns the start of the content of the buffer
     *
     * @param e Vector or element to which the operation is performed. The type
     * must meet ComplexVector or ComplexElem.
     */
    inline value_type * __restrict data() const
    {
        if constexpr (config_type::_margin == 0)
            return this->_base;
        else
            return this->_head;
    }

    /**
     * @ingroup group_basic_types
     *
     * Returns the base address of the buffer associated with this 
     *
     * @param e Vector or element to which the operation is performed. The type
     * must meet ComplexVector or ComplexElem.
     */
    inline value_type * __restrict base() const
    {
        return this->_base;
    }

    /**
     * @ingroup group_basic_types
     *
     * Returns the size in number of elements of the dimension specified in index
     *
     * @param index The index of the dimension for which the size is requested
     */
    constexpr inline uint32_t size(uint32_t const index) const
    {
        return base_type2::size(index);
    }

    /**
     * @ingroup group_basic_types
     *
     * Returns the total size of the buffer port in number of elements
     */
    constexpr inline uint32_t size() const
    {
        return base_type2::size();
    }

    /**
     * @ingroup group_basic_types
     *
     * Returns the number of dimensions as specified 
     * in the type of this buffer port. 
     *
     */
    constexpr static inline uint32_t num_dims()
    {
        return dims_type::num_dims();
    }

    /**
     * @ingroup group_basic_types
     *
     * Returns the number of elements of the dimension specified in index as
     * specified in the type of this buffer port. 
     *
     * @param index The index of the dimension for which the size is requested
     */
    constexpr static inline uint32_t dim(uint32_t index)
    {
        return dims_type::dim(index);
    }
    
    /**
     * @ingroup group_basic_types
     *
     * Returns the number of total number of elements of the buffer including
     * the optional margin.
     */
    inline constexpr uint32_t size_incl_margin() const
    {
        if constexpr (config_type::_margin == 0)
            return base_type2::size();
        else
            return this->_sizeInclMargin;
    }

    /**
     * @ingroup group_basic_types
     *
     * Acquires the lock associated with this buffer port.
     */
    template<typename tpLockingMode2 = tpLockingMode>
    inline 
    std::enable_if_t<std::is_same_v<tpLockingMode2, locking::async>> acquire()
    {
#ifndef __X86SIM__
        if constexpr (config_type::_margin != 0)
        {
            this->_head = (tpValueTy *) select(this->_currentBufId, this->_heads[1], this->_heads[0]);
        }
        this->_base = (tpValueTy *) select(this->_currentBufId, this->_bufs[1], this->_bufs[0]);

#if defined(__LOCK_FENCE_MODE__) && __LOCK_FENCE_MODE__==2
        if constexpr (config_type::_margin == 0)
        {
            io_buffer::acquire_(this->base(), this->_lockIds[0], this->_lockIds[1],
                                this->_currentBufId);
        }
        else
        {
            io_buffer::acquire_(this->_lockIds[0], this->_lockIds[1],
                                this->_currentBufId);
        }
#elif defined(__LOCK_FENCE_MODE__) && __LOCK_FENCE_MODE__==3
        io_buffer::acquire_(this->base(), this->_lockIds[0], this->_lockIds[1],
                                this->_currentBufId);
#else
        io_buffer::acquire_(this->_lockIds[0], this->_lockIds[1],
                            this->_currentBufId);
#endif
#else
        bool isInput = (std::is_same_v<tpDirection, direction::in>);
        unsigned forRead = 1;
        unsigned forWrite = 0;
        x86sim::acquireBufferPort(this->_iConn, isInput ? forRead: forWrite);
#endif      
    }
    
    /**
     * @ingroup group_basic_types
     *
     * Releases the lock associated with this buffer port and switches between
     * ping and pong if the port is double buffered.
     */
    template<typename tpLockingMode2 = tpLockingMode>
    inline 
    std::enable_if_t<std::is_same_v<tpLockingMode2, locking::async>> release()
    {
#ifndef __X86SIM__
        // need margin copy.
        if constexpr (config_type::_margin != 0
                      && (std::is_same_v<tpDirection, direction::in>)) {
            detail::bufferPortMarginCopy
                ((tpValueTy *) select(this->_currentBufId, this->_bufs[0], this->_bufs[1]),
                 (tpValueTy *) select(this->_currentBufId, this->_bufs[1], this->_bufs[0]),
                 size(), config_type::_margin);
        }
#if defined(__LOCK_FENCE_MODE__) && __LOCK_FENCE_MODE__==2
        if constexpr (config_type::_margin == 0)
        {
            io_buffer::release_(this->base(), this->_lockIds[0], this->_lockIds[1],
                                this->_currentBufId);
        }
        else
        {
            io_buffer::release_(this->_lockIds[0], this->_lockIds[1],
                                this->_currentBufId);
        }
#elif defined(__LOCK_FENCE_MODE__) && __LOCK_FENCE_MODE__==3
            io_buffer::release_(this->base(), this->_lockIds[0], this->_lockIds[1],
                                this->_currentBufId);
#else
            io_buffer::release_(this->_lockIds[0], this->_lockIds[1],
                                this->_currentBufId);
#endif
        this->_currentBufId = 1 - this->_currentBufId;
#else
        bool isInput = (std::is_same_v<tpDirection, direction::in>);
        unsigned forRead = 1;
        unsigned forWrite = 0;
        // Margin copy is done inside releaseBufferPort.
        x86sim::releaseBufferPort(this->_iConn,isInput ? forWrite: forRead);
#endif
    }
    
protected:
    static inline void acquire_(unsigned lockId0,
                                unsigned lockId1,
                                int bufId)
    {
#if defined(__AIENGINE__)
        constexpr bool isOut = std::is_same_v<tpDirection,direction::out>;
#if (__AIE_ARCH__>=20)
        ::acquire_greater_equal(isOut ? lockId0: lockId1, 1);
#else
        ::acquire(bufId ? lockId1: lockId0, isOut ? ACQ_WRITE: ACQ_READ);
#endif
#endif
    }
        
    static inline void release_(unsigned lockId0,
                                unsigned lockId1,
                                int bufId)
    {
#if defined(__AIENGINE__)
        constexpr bool isOut = std::is_same_v<tpDirection,direction::out>;
#if (__AIE_ARCH__>=20)
        ::release(isOut ? lockId1: lockId0, 1);
#else
        ::release(bufId ? lockId1: lockId0, isOut ? REL_READ: REL_WRITE);
#endif
#endif
    }

    static inline void acquire_(void *base,
                                unsigned lockId0,
                                unsigned lockId1,
                                int bufId)
    {
#if defined(__AIENGINE__)
        constexpr bool isOut = std::is_same_v<tpDirection,direction::out>;
#if (__AIE_ARCH__==20)
        ::acquire_greater_equal(base, isOut ? lockId0: lockId1, 1);
        chess_separator_scheduler();
#elif (__AIE_ARCH__>20)
        ::acquire_greater_equal(isOut ? lockId0: lockId1, 1);
#else
        ::acquire(bufId ? lockId1: lockId0, isOut ? ACQ_WRITE: ACQ_READ);
#endif
#endif
    }
        
    static inline void release_(void *base,
                                unsigned lockId0,
                                unsigned lockId1,
                                int bufId)
    {
#if defined(__AIENGINE__)
        constexpr bool isOut = std::is_same_v<tpDirection,direction::out>;
#if (__AIE_ARCH__==20)
        ::release(base, isOut ? lockId1: lockId0, 1);
#elif (__AIE_ARCH__>20)
        ::release(isOut ? lockId1: lockId0, 1);
#else
        ::release(bufId ? lockId1: lockId0, isOut ? REL_READ: REL_WRITE);
#endif
#endif
    }
};


} // namespace adf
 
#endif // ifndef SRC_IO_BUFFER_IO_BUFFER_MAIN_H_
