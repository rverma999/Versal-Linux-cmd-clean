//**********************************************************************
// Copyright (c) 2016-2018 Xilinx Inc.  All Rights Reserved
//**********************************************************************
//
//   TLM wrapper for NoC core. Excludes instances of agents (NMU/NSU/DDRMC)
//   Provides a sc_module anchor with a clock and connects to functional NoC
//
//**********************************************************************
#ifndef _SNOCCoreXtlm_h_
#define _SNOCCoreXtlm_h_


#include <memory>
#include "NOCCoreXtlm.h"
#include "properties.h"

class SNOCCoreXtlm : public NOCCoreXtlm
{
public:
  SNOCCoreXtlm( sc_core::sc_module_name nm, const xsc::common_cpp::properties& props )
    : NOCCoreXtlm( nm, props ) {}
};

#endif
