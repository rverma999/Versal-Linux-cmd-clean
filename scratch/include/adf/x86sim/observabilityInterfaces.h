// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// *****************************************************************************
// File: observabilityInterfaces.h
// 
/// This file contains the definition of the EventTrace class.
// *****************************************************************************
#ifndef _SRC_X86SIM_INCLUDE_OBSERVABILITY_INTERFACES_H_
#define _SRC_X86SIM_INCLUDE_OBSERVABILITY_INTERFACES_H_

#include <memory>
#include "symbolVisibility.h"
#include "simulatorInterfaces.h"

typedef int8_t window_datatype;

namespace x86sim
{

// *****************************************************************************
// class EventTrace 
// 
/// EventTrace::record adds an event with given kind and value to the event
/// trace when running the simulatrion with x86simulator --trace. This should
/// be used via the X86SIM_RECORD_EVENT macro in x86simDebug.h. For more
/// information on usage refer to x86simDebug.h
///
/// EventTrace::getKernelName() returns that fully qualified name of the current
/// kernel. This should be used via the X86SIM_KERNEL_NAME macro defined in
/// x86simDebug.h. For more information on usage refer to x86simDebug.h
// *****************************************************************************
class X86SIM_EXPORT EventTrace {
public:
   static void record(int kind, int value);
   static char const *getKernelName();
};

// *****************************************************************************
// class checkPtrAlignment
//
/// This function checks that a vector access via a window api is properly
/// aligned.
// *****************************************************************************
X86SIM_EXPORT inline void checkPtrAlignment(window_datatype *ptr,
                                            char const *api)
{
    uintptr_t vecAlignment;
#if __AIE_ARCH__>=20
    vecAlignment = 31;
#else
    vecAlignment = 15;
#endif

    auto ptrAddr = reinterpret_cast<uintptr_t>(ptr); 

    if ((ptrAddr & vecAlignment) != 0)
    {
        fprintf(stderr, "Error: The data pointer of '%s' in Kernel '%s' is not "
        "aligned to the %d-byte boundary which is needed for Vector load/store. \n",
        api, EventTrace::getKernelName(), (int)vecAlignment + 1);

        ISimulator::initiateTermination();
        // needed if called from non-kernel thread.
        std::exit(1);
    }
}

} // namespace x86sim



#endif // ifndef _SRC_X86SIM_INCLUDE_OBSERVABILITY_INTERFACES_H_
