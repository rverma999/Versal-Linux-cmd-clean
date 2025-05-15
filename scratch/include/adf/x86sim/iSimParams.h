// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef _SRC_X86SIM_INCLUDE_ISIMULATION_PARAMS_H_
#define _SRC_X86SIM_INCLUDE_ISIMULATION_PARAMS_H_

#include "symbolVisibility.h"

namespace x86sim
{

class X86SIM_EXPORT ISimulationParams
{
public:
    unsigned long simTimeout;
    unsigned long plWaitTime;
    long meKernelIters;

public:
    ISimulationParams() { }

    ISimulationParams(unsigned long sT, unsigned long plW, long meKI)
	: simTimeout(sT), 
	  plWaitTime(plW),
	  meKernelIters(meKI) { }

    virtual ~ISimulationParams() { }

    virtual bool populate() = 0;
};  //end of class


X86SIM_EXPORT ISimulationParams* createSimParams();

}  // end of namespace x86sim

#endif   // ifndef _SRC_X86SIM_INCLUDE_ISIMULATION_PARAMS_H_
