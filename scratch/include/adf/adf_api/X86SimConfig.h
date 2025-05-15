// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// (c) Copyright(C) 2021 by Xilinx, Inc. All rights reserved.
//
// This file contains confidential and proprietary information
// of Xilinx, Inc. and is protected under U.S. and
// international copyright and other intellectual property
// laws.
//
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// Xilinx, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) Xilinx shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or Xilinx had been advised of the
// possibility of the same.
//
// CRITICAL APPLICATIONS
// Xilinx products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of Xilinx products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
//
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.

#pragma once

#include <string>
#include <vector>

namespace x86sim
{
    class DFGraph;
    class IGMIO;
    class IRtpConnector;
    class ISharedBuffer; 
}

namespace adf
{
    struct X86SimGraphConfig
    {
        int id;
        std::string name;
        int runForIter;
#ifdef __AIECOMPILER_BACKEND__
        std::string x86SimPtr;
        std::vector<std::string> plKernelInstanceNames;
#else
        x86sim::DFGraph* x86SimPtr;
#endif
    };

    struct X86SimGMIOConfig
    {
        enum GMIOType { gm2aie, aie2gm, gm2pl, pl2gm };

        int id;
        /// GMIO variable name
        std::string name;
        /// GMIO loginal name
        std::string logicalName;
        /// GMIO type
        GMIOType type;
#ifdef __AIECOMPILER_BACKEND__
        std::string x86SimPtr;
#else
        x86sim::IGMIO* x86SimPtr;
#endif
    };
 
    struct X86SimRTPConfig
    {
       // enum should be consistent with adf::element_type
        enum elementType
        {
            et_voidty = 0,
            et_int4,
            et_int8,
            et_int16,
            et_int32,
            et_int64,
            et_uint4,
            et_uint8,
            et_uint16,
            et_uint32,
            et_uint64,
            et_cint16,
            et_cint32,
            et_float,
            et_cfloat,
            et_double,
            et_bfloat16,
            et_float16,
            et_bfloat8,
            et_float8
        };

        int portId;
        int aliasId;
        std::string portName;
        std::string aliasName;
        int graphId;
        bool isInput;
        bool isAsync;
        bool isConnected;
        elementType elemType;
        size_t numBytes;
#ifdef __AIECOMPILER_BACKEND__
        std::string x86SimPtr;
#else
        x86sim::IRtpConnector* x86SimPtr;
#endif
    };
  
    struct X86SimPLIOConfig
    {
        /// PLIO object id
        int id;
        /// PLIO variable name
        std::string name;
        /// PLIO loginal name
        std::string logicalName;
    };

    struct X86SimSharedBufferConfig
    {
        /// Shared buffer instance ID
        int id;
        /// Shared buffer name
        std::string name;
        /// external buffer
        bool extBuffer;
        /// x86sim pointer
#ifdef __AIECOMPILER_BACKEND__
        std::string x86SimPtr;
#else
        x86sim::ISharedBuffer* x86SimPtr;
#endif          
    };

    struct X86SimExternalBufferPortConfig
    {
        /// Port instance id
        int portId;
        /// Port name
        std::string portName;
        /// Parent id
        int parentId;
        /// Is input port
        bool isInput; 
        /// x86sim port index
        int x86simPortIdx;
    };

    void initializeX86SimConfigurations(
        const X86SimGraphConfig* pX86SimGraphConfig, 
        size_t X86SimGraphConfigSize, 
        const X86SimRTPConfig* pX86SimRTPConfig, 
        size_t X86SimRTPConfigSize, 
        const X86SimGMIOConfig* pX86SimGMIOConfig, 
        size_t X86SimGMIOConfigSize,
        const X86SimPLIOConfig* pX86SimPLIOConfig,
        size_t X86SimPLIOConfigSize,
        const X86SimSharedBufferConfig* pX86SimSharedBufferConfig,
        size_t X86SimSharedBufferConfigSize,
        const X86SimExternalBufferPortConfig* pX86SimExternalBufferPortConfig,
        size_t X86SimExternalBufferPortConfigSize);
                                  
}

