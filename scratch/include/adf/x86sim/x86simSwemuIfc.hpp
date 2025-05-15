// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// *****************************************************************************
// File: x86simSwemuIfc.hpp
// 
/// This file contains the declaration of the interface to x86sim for the
/// software emulation flow.
// *****************************************************************************
#include "symbolVisibility.h"

extern "C" {


#ifdef NDEBUG
#define _IFC_LOG(X) \
fprintf(stderr, "%s %s at %s:%d\n", __FUNCTION__, X, __FILE__, __LINE__)
#else
#define _IFC_LOG(X) 
#endif
    
X86SIM_EXPORT void * __xlnx_swemu_x86sim_createSimulator()
{
    _IFC_LOG("BEGIN");
    auto result = x86sim::createSwemuSimulatorInstance();
    _IFC_LOG("END");
    return result;
}
    
X86SIM_EXPORT bool __xlnx_swemu_x86sim_connectPLIO(void *sim,
                                            std::string const &portName,
                                            void *stream,
                                            int dataWidth,
                                            int user,
                                            int id,
                                            int dest,
                                            std::string const &streamType)
{
    _IFC_LOG("BEGIN");
    auto result = reinterpret_cast<x86sim::ISwemuSimulator*>(sim)
                  ->connectHlsStream(portName, stream, dataWidth, 
                                     user, id, dest, streamType);
    _IFC_LOG("END");
    return result;
}
X86SIM_EXPORT bool __xlnx_swemu_x86sim_graphUpdateRTP(void *sim,
                                            std::string const &graphName,
                                            std::string const &portName,
                                            void const *sourcePtr,
                                            size_t size)
{
    _IFC_LOG("BEGIN");
    auto result = reinterpret_cast<x86sim::ISwemuSimulator*>(sim)
                  ->updateRtp(graphName, portName, sourcePtr, size);
    _IFC_LOG("END");
    return result;
}
X86SIM_EXPORT bool __xlnx_swemu_x86sim_graphReadRTP(void *sim,
                                            std::string const &graphName,
                                            std::string const &portName,
                                            void* dstPtr,
                                            size_t size)
{
    _IFC_LOG("BEGIN");
    auto result = reinterpret_cast<x86sim::ISwemuSimulator*>(sim)
                  ->readRtp(graphName, portName, dstPtr, size);
    _IFC_LOG("END");
    return result;
}
X86SIM_EXPORT bool __xlnx_swemu_x86sim_graphInit(void *sim, 
                                            std::string const &graphName)
{
    _IFC_LOG("BEGIN");    
    bool result = false;
    if (auto _graph = reinterpret_cast<x86sim::ISwemuSimulator*>(sim)
        ->getGraph(graphName)) {
        _graph->init();
        result = true;
    }
    _IFC_LOG("END");
    return result;
}
X86SIM_EXPORT bool __xlnx_swemu_x86sim_graphWait(void *sim, 
                                            std::string const &graphName)
{
    _IFC_LOG("BEGIN");
    bool result = false;
    if (auto _graph = reinterpret_cast<x86sim::ISwemuSimulator*>(sim)
        ->getGraph(graphName)) {
        _graph->wait();
        result = true;
    }
    _IFC_LOG("END");
    return result;
}
X86SIM_EXPORT bool __xlnx_swemu_x86sim_graphTimedWait(void *sim, 
                                            std::string const &graphName,
                                            unsigned long long cycle_timeout)
{
    _IFC_LOG("BEGIN");
    bool result = false;
    if (auto _graph = reinterpret_cast<x86sim::ISwemuSimulator*>(sim)
        ->getGraph(graphName)) {
        _graph->wait(cycle_timeout);
        result = true;
    }
    _IFC_LOG("END");
    return result;
}
X86SIM_EXPORT bool __xlnx_swemu_x86sim_graphResume(void *sim, 
                                            std::string const &graphName)
{
    _IFC_LOG("BEGIN");
    bool result = false;
    if (auto _graph = reinterpret_cast<x86sim::ISwemuSimulator*>(sim)
        ->getGraph(graphName)) {
        _graph->resume();
        result = true;
    }
    _IFC_LOG("END");
    return result;
}
X86SIM_EXPORT bool __xlnx_swemu_x86sim_graphRun(void *sim, 
                                            std::string const &graphName)
{
    _IFC_LOG("BEGIN");
    auto _sim = reinterpret_cast<x86sim::ISwemuSimulator*>(sim);
    long _iter = _sim->getIter();
    bool result = false;
    if (auto _graph = _sim->getGraph(graphName)) {
        _graph->runFor(_iter);
        result = true;
    }
    _IFC_LOG("END");
    return result;
}
X86SIM_EXPORT bool __xlnx_swemu_x86sim_graphRunItr(void *sim, 
                                            std::string const &graphName,
                                            int iter)
{
    _IFC_LOG("BEGIN");
    bool result = false;
    if (auto _graph = reinterpret_cast<x86sim::ISwemuSimulator*>(sim)
        ->getGraph(graphName)) {
        _graph->runFor(iter);
        result = true;
    }
    _IFC_LOG("END");
    return result;
}
X86SIM_EXPORT bool __xlnx_swemu_x86sim_graphEnd(void *sim, 
                                            std::string const &graphName)
{
    _IFC_LOG("BEGIN");
    bool result = false;
    if (auto _graph = reinterpret_cast<x86sim::ISwemuSimulator*>(sim)
        ->getGraph(graphName)) {
        _graph->finish();
        result = true;
    }
    _IFC_LOG("END");
    return result;
}
X86SIM_EXPORT bool __xlnx_swemu_x86sim_graphTimedEnd(void *sim, 
                                            std::string const &graphName,
                                            unsigned long long cycle_timeout)
{
    _IFC_LOG("BEGIN");
    bool result = false;
    if (auto _graph = reinterpret_cast<x86sim::ISwemuSimulator*>(sim)
        ->getGraph(graphName)) {
        _graph->finish(cycle_timeout);
        result = true;
    }
    _IFC_LOG("END");
    return result;
}  
X86SIM_EXPORT bool getGmioType(adf::X86SimGMIOConfig::GMIOType &type, 
                                            std::string const &text)
{
    bool result = true;
    if (text == "gm2aie")
        type = adf::X86SimGMIOConfig::GMIOType::gm2aie;
    else if (text == "aie2gm")
        type = adf::X86SimGMIOConfig::GMIOType::aie2gm;
    else
        result = false;
    return result;
}
X86SIM_EXPORT bool __xlnx_swemu_x86sim_SyncBOAIENB(void *sim, 
                                            std::string const &graphName,
                                            std::string const &gmioName,
                                            std::string const &direction,
                                            void* buffAddr,
                                            size_t numBytes)
{
    _IFC_LOG("BEGIN");
    bool result = false;
    adf::X86SimGMIOConfig::GMIOType type;
    if (getGmioType(type, direction))
        result = reinterpret_cast<x86sim::ISwemuSimulator*>(sim)
                 ->gmioApi(gmioName, type, buffAddr, numBytes);
    _IFC_LOG("END");
    return result;
}
X86SIM_EXPORT bool __xlnx_swemu_x86sim_GmioWait(void *sim, 
                                            std::string const &graphName,
                                            std::string const &gmioName)
{
    _IFC_LOG("BEGIN");
    auto result = reinterpret_cast<x86sim::ISwemuSimulator*>(sim)->wait(gmioName); 
    _IFC_LOG("END");
    return result;
}
X86SIM_EXPORT void __xlnx_swemu_x86sim_generateSummary(void *sim,
                                    bool initSummary,
                                    unsigned long long startTime,
                                    int pid,
                                    unsigned long long finishTime,
                                    bool runStatus)
{
    _IFC_LOG("BEGIN");
    reinterpret_cast<x86sim::ISwemuSimulator*>(sim)
        ->generateSummaryFile(initSummary, startTime, pid, finishTime, runStatus); 
    _IFC_LOG("END");
}
X86SIM_EXPORT bool __xlnx_swemu_x86sim_setAddress(void *sim,
                              std::string const &graphName,
                              std::string const &bufferName,
                              void* buffAddr)
{
    _IFC_LOG("BEGIN");
    auto result = reinterpret_cast<x86sim::ISwemuSimulator*>(sim)
        ->setAddress(bufferName, buffAddr);
    _IFC_LOG("END");
    return result;
}
#undef _IFC_LOG
    
} // extern "C"
