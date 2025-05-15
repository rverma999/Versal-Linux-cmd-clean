// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// *****************************************************************************
// File: x86simDebug.h
// 
/// This file contains the definitions of macros for instrumenting kernel
/// code for x86simulator.
// *****************************************************************************
#ifndef _SRC_X86SIM_INCLUDE_X86SIM_DEBUG_H_
#define _SRC_X86SIM_INCLUDE_X86SIM_DEBUG_H_

#ifdef __X86SIM__
#include <adf/x86sim/observabilityInterfaces.h>
#endif

// *****************************************************************************
// macro X86SIM_RECORD_EVENT(KIND, VALUE)
//
/// Use the macro in kernel code to record a user-defined event for
/// x86simulator. The event will be incorporated in  x86sim_event_trace and
/// decorated with a time stamp and the kernel name. Kind should be an integer
/// in the range 1..127; value should be an integer. The event will show up as
/// <TIME_STAMP> <KERNEL> USER_<KIND> <VALUE>.
/// If the kernel code is compiled for aiesimulator, this macro expands to the
/// empty token.
///
/// Usage example:
/// #include <adf/x86sim/x86simDebug.h>
/// #include <stdio.h>
/// void myKernel(..)
/// {
///   ..
///   int v = readincr(in); 
///   X86SIM_RECORD_EVENT(10, v);
///   ..
/// }
///
/// The instrumentation will produce events like the one below in the 
/// x86sim event trace (assuming that the kernel path is mygraph.first):
///
///  4257160 mygraph.first USER_10 100
// *****************************************************************************
#ifdef __X86SIM__
#define X86SIM_RECORD_EVENT(KIND, VALUE) \
x86sim::EventTrace::record((KIND),(VALUE))
#else
#define X86SIM_RECORD_EVENT(KIND, VALUE) 
#endif

// *****************************************************************************
// macro X86SIM_KERNEL_NAME
//
/// This macro returns the qualified path of the kernel executing as a
/// char const* for use in printf instrumentation of kernel code for
/// x86simulator. When the code is compiled for aiesimulator, the macro expands
/// to __FUNCTION__.
///
/// Usage example:
/// #include <adf/x86sim/x86simDebug.h>
/// #include <stdio.h>
/// void myKernel(input_stream_int32 * in, ..)
/// {
///   int v = readincr(in); 
///   printf("%s %d\n", X86SIM_KERNEL_NAME, v);
///   ..
/// }
// *****************************************************************************
#ifdef __X86SIM__
#define X86SIM_KERNEL_NAME \
x86sim::EventTrace::getKernelName()
#else
#define X86SIM_KERNEL_NAME \
__FUNCTION__
#endif


#endif // ifndef _SRC_X86SIM_INCLUDE_X86SIM_DEBUG_H_
