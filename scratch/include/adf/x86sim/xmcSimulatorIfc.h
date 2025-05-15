// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// *****************************************************************************
// File: SimulatorIfc.h
// 
/// This file contains the declarations of the Simulator functions exported
/// in libsim.so. All of these APIs are implemented in libXmcx86sim.so
/// except for xmcSimInit.
// *****************************************************************************
#ifndef _SRC_X86SIM_INCLUDE_XMC_SIMULATOR_IFC_H_
#define _SRC_X86SIM_INCLUDE_XMC_SIMULATOR_IFC_H_

#include <cstddef>
#include "symbolVisibility.h"


extern "C" {
   X86SIM_EXPORT void * xmcSimInit(char const *);

   X86SIM_EXPORT void xmcSimStart(void *sim);
   X86SIM_EXPORT void xmcSimEnd(void *sim);
   
   X86SIM_EXPORT void xmcSimConfigWindow(void *sim,
					 int   dir,
					 int   index,
					 int   size,
					 int   margin,
					 bool  sync);
   X86SIM_EXPORT void xmcSimConfigRtp(void *sim,
				      int   dir,
				      int   index,
				      bool  sync);
   X86SIM_EXPORT void xmcSimConfigKernelClassObject(void *sim,
                                                    void *argv[]);
   X86SIM_EXPORT void xmcSimConfigEnd(void *sim);

   X86SIM_EXPORT void xmcSimWriteInputsBegin(void *sim);
   X86SIM_EXPORT void xmcSimWriteInputsEnd(void *sim);

   X86SIM_EXPORT void xmcSimReadOutputsBegin(void *sim);
   X86SIM_EXPORT void xmcSimReadOutputsEnd(void *sim);
   
   X86SIM_EXPORT size_t xmcSimWriteInput(void       *sim,
					 int         index,
					 size_t      size,
					 void const *data);
   X86SIM_EXPORT size_t xmcSimReadOutput(void   *sim,
					 int     index,
					 size_t  size,
					 void   *data);
   X86SIM_EXPORT size_t xmcSimReadOutputSize(void *sim,
					     int   index);
} // extern "C"


#endif // ifndef _SRC_X86SIM_INCLUDE_XMC_SIMULATOR_IFC_H_
