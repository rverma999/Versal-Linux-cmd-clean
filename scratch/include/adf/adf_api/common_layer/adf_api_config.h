// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
/**
* Copyright (C) 2021 Xilinx, Inc
*
* Licensed under the Apache License, Version 2.0 (the "License"). You may
* not use this file except in compliance with the License. A copy of the
* License is located at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
* WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
* License for the specific language governing permissions and limitations
* under the License.
*/

#pragma once

#include <string>
#include <vector>

#include "adf/new_frontend/types.h" //for adf::buffer_descriptor_parameters

namespace adf
{

struct driver_config
{
    uint8_t hw_gen;
    uint64_t base_address;
    uint8_t column_shift;
    uint8_t row_shift;
    uint8_t num_columns;
    uint8_t num_rows;
    uint8_t shim_row;
    uint8_t reserved_row_start;
    uint8_t reserved_num_rows;
    uint8_t aie_tile_row_start;
    uint8_t aie_tile_num_rows;
    uint8_t partition_num_cols;
    std::vector<short> partition_overlay_start_cols;
};

struct aiecompiler_options
{
    bool broadcast_enable_core;
    std::string event_trace;
};

struct graph_config
{
#ifndef __XRT__
    enum plAxiLiteMode
    {
        pl_no_axi_lite = 0,
        pl_axi_lite,
        pl_axi_lite_auto_restart
    };
#endif

    int id;
    std::string name;

#ifndef __XRT__
#ifdef __AIECOMPILER_BACKEND__
    std::string graphLoadElfFunc;
    std::string graphInitFunc;
    std::string graphDebugHaltFunc;
#else
    bool(*graphLoadElfFunc)(const std::string&, std::vector<std::string>&);
    adf::return_code(*graphInitFunc)(const std::string&);
    void(*graphDebugHaltFunc)();
#endif
#endif

    std::vector<short> coreColumns;
    std::vector<short> coreRows;
    /// Core iteration memory address
    std::vector<short> iterMemColumns;
    std::vector<short> iterMemRows;
    std::vector<size_t> iterMemAddrs;
    std::vector<bool> triggered;

#ifndef __XRT__
    std::vector<std::string> plKernelInstanceNames;
    std::vector<plAxiLiteMode> plAxiLiteModes;
#ifdef __AIECOMPILER_BACKEND__
    std::vector<std::string> plDriverStartIPFuncs;
    std::vector<std::string> plDriverCheckIPDoneFuncs;
#else
    std::vector<void(*)()> plDriverStartIPFuncs;
    std::vector<bool(*)()> plDriverCheckIPDoneFuncs;
#endif
#ifndef __XRT__
    std::vector<bool> hasLargeKernels;
#endif
#endif
};

struct rtp_config
{
#ifndef __XRT__
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
#endif

    int portId;
    int aliasId;
    std::string portName;
    std::string aliasName;
    int graphId;
    bool isInput;
    bool isAsync;
    bool isConnect;
#ifndef __XRT__
    elementType elemType;
#endif
    size_t numBytes;
    bool isPL;
    //for graph::update to connected async input RTP, if the connection is within a core, there may not be a lock
    bool hasLock;
    short selectorColumn;
    short selectorRow;
    size_t selectorAddr;
    unsigned short selectorLockId;
    short pingColumn;
    short pingRow;
    size_t pingAddr;
    unsigned short pingLockId;
    short pongColumn;
    short pongRow;
    size_t pongAddr;
    unsigned short pongLockId;

#ifndef __XRT__
    std::string plKernelInstanceName;
    int plParameterIndex;
#ifdef __AIECOMPILER_BACKEND__
    std::string plDriverWriteRTP;
    std::string plDriverReadRTP;
#else
    void(*plDriverWriteRTP)(const void*, size_t);
    void(*plDriverReadRTP)(void*, size_t);
#endif
#endif
};

struct gmio_config
{
    enum gmio_type { gm2aie, aie2gm, gm2pl, pl2gm };

    /// GMIO object id
    int id;
    /// GMIO variable name
    std::string name;
    /// GMIO loginal name
    std::string logicalName;
    /// GMIO type
    gmio_type type;
    /// Shim tile column to where the GMIO is mapped
    short shimColumn;
    /// Channel number (0-S2MM0,1-S2MM1,2-MM2S0,3-MM2S1).
    short channelNum;
    /// Shim stream switch port id (slave: gm-->me, master: me-->gm)
    short streamId;
    /// For type == gm2aie or type == aie2gm, burstLength is the burst length for the AXI-MM transfer
    /// (4 or 8 or 16 in C_RTS API). The burst length in bytes is burstLength * 16 bytes (128-bit aligned).
    /// For type == gm2pl or type == pl2gm, burstLength is the burst length in bytes.
    short burstLength;

#ifndef __XRT__
    // Does this gmio use packet switching?
    bool isPacketSwitch;
    // Map packet split output port id to packet id
    std::vector<unsigned short> packetIDs;
    /// PL kernel instance name
    std::string plKernelInstanceName;
    /// PL parameter index
    int plParameterIndex;
    /// PL IP Id for AIESIM (for type == gm2pl or type == pl2gm)
    int plId;
#ifdef __AIECOMPILER_BACKEND__
    std::string plDriverSetAxiMMAddr;
#else
    /// Driver function pointer to set PL m_axi port address (for aiesimulator and hardware) and size (for aiesimulator only)
    void(*plDriverSetAxiMMAddr)(unsigned long long, unsigned int);
#endif
#endif
};

struct kernel_config
{
    ///Kernel object id
    int id;
    std::vector<int> hierarchicalGraphIds;
    short column;
    short row;
};

struct dma_config
{
    ///DMA object
    short column;
    short row;
    std::vector<int> hierarchicalGraphIds;
    std::vector<int> channel;
};

struct plio_config
{
    /// PLIO object id
    int id;
    /// PLIO variable name
    std::string name;
    /// PLIO loginal name
    std::string logicalName;
    /// Shim tile column to where the GMIO is mapped
    short shimColumn;
    /// slave or master. 0:slave, 1:master
    short slaveOrMaster;
    /// Shim stream switch port id
    short streamId;
};

struct trace_unit_config
{
    /// tile column
    short column;
    /// tile row
    short row;
    /// Tile type aie_tile 0 , shim_tile 1 , memory_tile 2 
    int tileType;
    /// core module 0, memory module 1, shim pl module 2
    short module;
    /// packet id
    short packetId;
};

#ifndef __XRT__

struct shared_buffer_config
{
    /// Shared buffer instance ID
    short id;
    /// Shared buffer name
    std::string name;
};

struct dma_channel_config
{
    /// Port instance id
    int portId;
    /// Port name
    std::string portName;
    /// Parent id
    int parentId;
    /// Tile type
    int tileType;
    /// DMA channel column
    short column;
    /// DMA channel row relative to tileType
    short row;
    /// S2MM or MM2S. 0:S2MM, 1:MM2S. Should resemble the XAie_DmaDirection driver enum.
    int S2MMOrMM2S;
    /// DMA channel number
    short channel;
};

struct external_buffer_config
{
    /// External buffer instance ID
    short id;
    /// External buffer name
    std::string name;
};

//Currently adf::task_parameters (defined in adf_api_config.h) uses adf::buffer_descriptor_parameters while MeIrUtils::task_parameters uses MeIrUtils::buffer_descriptor_parameters.
struct task_parameters
{
    uint32_t repetition;
    bool enable_task_complete_token;
    std::vector<adf::buffer_descriptor_parameters> bdParams;
};

struct dma_channel_bd_config : dma_channel_config
{
    // Map packet split output port id to packet id
    std::vector<unsigned short> packetIds;
    
    std::vector<adf::task_parameters> tasks;
};

#endif

}
