// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// *****************************************************************************
// File: io_buffer_access.h
// 
/// This file provides access to the internals of async io buffers.
// *****************************************************************************
#ifndef SRC_IO_BUFFER_IO_BUFFER_ACCESS_H_
#define SRC_IO_BUFFER_IO_BUFFER_ACCESS_H_

#include <type_traits>

namespace adf {
/**
 * This struct provides access to internal of io_buffer class.
 * 
 */
struct io_buffer_access {
    template<typename T = void, typename Dir=void, typename Config = void>
    static constexpr uint32_t currentBufId(const io_buffer<T,Dir,Config> &port)
    {
        static_assert(std::is_same_v<typename Config::locking_mode, locking::async>,
                      "CurrentBufId is only available for asynchronus io buffers");
#ifndef __X86SIM__
        return port._currentBufId;
#else
        return port._iGetCurrentBufId();
#endif
    } 
  
    template<typename T = void, typename Dir=void, typename Config = void>
    static constexpr T* getBuf(const io_buffer<T,Dir,Config> &port, unsigned id)
    {
        static_assert(std::is_same_v<typename Config::locking_mode, locking::async>,
                      "CurrentBufId is only available for asynchronus io buffers");
#ifndef __X86SIM__
        return port._bufs[id];
#else
        // TODO: add support for this in x86sim.
        return  (T*) port._iGetBuf(id);
#endif
    }
}; // struct io_buffer_access

} // namespace adf

#endif // ifndef SRC_IO_BUFFER_IO_BUFFER_ACCESS_H_
