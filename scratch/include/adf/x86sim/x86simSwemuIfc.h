// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// *****************************************************************************
// File: x86simSwemuIfc.h
// 
/// This file contains the declaration of the interface of the libsim.so
/// produced by aiecompiler -target=x86sim.
// *****************************************************************************
#ifndef _SRC_X86SIM_INCLUDE_X86SIM_SWEMU_IFC_H_
#define _SRC_X86SIM_INCLUDE_X86SIM_SWEMU_IFC_H_

#include <string>
#include <cstddef>
#include "symbolVisibility.h"

extern "C" {

X86SIM_EXPORT void *__xlnx_swemu_x86sim_createSimulator();
X86SIM_EXPORT bool __xlnx_swemu_x86sim_connectPLIO(void *sim,
                                       std::string const &portName,
                                       void * stream,
                                       int dataWidth,
                                       int user,
                                       int id,
                                       int dest,
                                       std::string const &streamType);
X86SIM_EXPORT bool __xlnx_swemu_x86sim_graphUpdateRTP(void *sim, 
                                       std::string const &graphName, 
                                       std::string const &portName,
                                       void const *sourcePtr,
                                       size_t size);
X86SIM_EXPORT bool __xlnx_swemu_x86sim_graphReadRTP(void *sim, 
                                     std::string const &graphName, 
                                     std::string const &portName,
                                     void *dstPtr,
                                     size_t size);
X86SIM_EXPORT bool __xlnx_swemu_x86sim_graphInit(void *sim, 
                                     std::string const &graphName);
X86SIM_EXPORT bool __xlnx_swemu_x86sim_graphWait(void *sim, 
                                     std::string const &graphName);
X86SIM_EXPORT bool __xlnx_swemu_x86sim_graphTimedWait(void *sim, 
                                    std::string const &graphName,  
                                    unsigned long long cycle_timeout);
X86SIM_EXPORT bool __xlnx_swemu_x86sim_graphResume(void *sim, 
                                    std::string const &graphName);
X86SIM_EXPORT bool __xlnx_swemu_x86sim_graphRun(void *sim, 
                                    std::string const &graphName);
X86SIM_EXPORT bool __xlnx_swemu_x86sim_graphRunItr(void *sim, 
                                    std::string const &graphName, 
                                    int iter);
X86SIM_EXPORT bool __xlnx_swemu_x86sim_graphEnd(void *sim, 
                                    std::string const &graphName);
X86SIM_EXPORT bool __xlnx_swemu_x86sim_graphTimedEnd(void *sim, 
                                    std::string const &graphName, 
                                    unsigned long long cycle_timeout);
X86SIM_EXPORT bool __xlnx_swemu_x86sim_SyncBOAIENB(void *sim, 
                                    std::string const &graphName, 
                                    std::string const &gmioName,
                                    std::string const &direction, 
                                    void* buffAddr, 
                                    size_t numBytes);
X86SIM_EXPORT bool __xlnx_swemu_x86sim_GmioWait(void *sim, 
                                    std::string const &graphName, 
                                    std::string const &gmioName);
X86SIM_EXPORT void __xlnx_swemu_x86sim_generateSummary(void *sim,
                                    bool initSummary, 
                                    unsigned long long startTime,
                                    int pid,
                                    unsigned long long finishTime,
                                    bool runStatus);
X86SIM_EXPORT bool __xlnx_swemu_x86sim_setAddress(void *sim,
                                    std::string const &graphName,
                                    std::string const &bufferName,
                                    void* buffAddr);
} // extern "C"


#endif // ifndef _SRC_X86SIM_INCLUDE_X86SIM_SWEMU_IFC_H_
