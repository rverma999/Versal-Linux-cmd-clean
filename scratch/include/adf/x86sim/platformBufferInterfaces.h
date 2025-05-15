// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// *****************************************************************************
// File: platformBufferInterfaces.h
// 
/// This file contains the definition of the IPlatformBuffer class.
// *****************************************************************************
#ifndef _SRC_X86SIM_INCLUDE_PLATFORM_BUFFER_INTERFACES_H_
#define _SRC_X86SIM_INCLUDE_PLATFORM_BUFFER_INTERFACES_H_

#include <string>
#include <cstddef>
#include "symbolVisibility.h"

namespace x86sim {

class ISimulator;
class IRtpConnector;

class X86SIM_EXPORT IPlatformBuffer {
public:
    enum class Direction {
        kIn,
        kOut
    };
    
   IPlatformBuffer();
   virtual ~IPlatformBuffer();
   virtual void notify() = 0;
};

// *****************************************************************************
// class PlatformBufferFactory
// 
/// This is the PlatformBufferFactory class. PlatformBuffers can only be created
/// in a IXmcSImulator and they need to be created in order. The first
/// inputBuffer 
// *****************************************************************************
class X86SIM_EXPORT PlatformBufferFactory {
public:
    static IPlatformBuffer* inputBuffer(ISimulator        *sim,
                                        std::string const &label,
                                        size_t             capacity);
    static IPlatformBuffer* outputBuffer(ISimulator        *sim,
                                         std::string const &label,
                                         size_t             capacity);
    static IPlatformBuffer* asyncOutBuffer(ISimulator        *sim,
                                           std::string const &label,
                                           size_t             capacity);
};

} // namespace x86sim

#endif // ifndef _SRC_X86SIM_INCLUDE_PLATFORM_BUFFER_INTERFACES_H_
