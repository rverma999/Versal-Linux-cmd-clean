// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// (c) Copyright(C) 2018 - 2019 by Xilinx, Inc. All rights reserved.
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

#include "common_layer/adf_api_config.h"
#ifndef __AIECOMPILER_BACKEND__
#include "adf/new_frontend/adf.h"
#include "cardano_api_dynlink.h"
#endif

#include <map>

namespace adf
{
    typedef graph_config GraphConfig;
    typedef rtp_config RTPConfig;
    typedef gmio_config GMIOConfig;
    typedef kernel_config KernelConfig;
    typedef dma_config DMAConfig;
    typedef plio_config PLIOConfig;
    typedef trace_unit_config TraceUnitConfig;
    typedef dma_channel_config DMAChannelConfig;
    typedef shared_buffer_config SharedBufferConfig;
    typedef external_buffer_config ExternalBufferConfig;
    typedef dma_channel_bd_config DMAChannelBDConfig;

#ifndef __AIECOMPILER_BACKEND__
    CARDANO_API_EXPORT void initializeConfigurations(void* pDevTileInst, size_t numColumns, size_t numAIERows, size_t numMemRows,
        const GraphConfig* pGraphConfig, size_t GraphConfigSize,
        const RTPConfig* pRTPConfig, size_t RTPConfigSize,
        const KernelConfig* pKernelConfig, size_t KernelConfigSize,
        const DMAConfig* pDMAConfig, size_t DMAConfigSize,
        const DMAChannelConfig* pDMAChConfig, size_t DMAChConfigSize,
        const DMAChannelBDConfig* pDMAChBDConfig, size_t DMAChBDConfigSize,
        const SharedBufferConfig* pSharedBufferConfig, size_t SharedBufferConfigSize,
        const ExternalBufferConfig* pExternalBufferConfig, size_t ExternalBufferConfigSize,
        const GMIOConfig* pGMIOConfig, size_t GMIOConfigSize,
        const PLIOConfig* pPLIOConfig, size_t PLIOConfigSize,
        const TraceUnitConfig* pTraceUnitConfig, size_t TraceUnitConfigSize, int traceAieSimOption, adf::return_code(*traceGraphInitFunc)(),
        bool aiesim_debug, bool exclude_pl_control, bool enable_ecc_scrubbing, return_code(*broadcastConfigForCoreEnableFunc)(), bool broadcast_config_for_core_enable, unsigned adfApiLogLevel);

	CARDANO_API_EXPORT void initializeEventTrace(int graphId, event::graph_tracing_option option);
	CARDANO_API_EXPORT void initializeEventTraceMemTile(int graphId, event::graph_tracing_MemTile_option option);
    CARDANO_API_EXPORT bool reserveBroadcastchannelForEnablingCores();
    CARDANO_API_EXPORT bool dumpEventTraceConfig(std::string traceConfigFile);
    CARDANO_API_EXPORT bool generateEventTraceConfigsForRuntime(std::map<event::graph_tracing_option, std::string> traceConfigOptionToFilePathMap);
    CARDANO_API_EXPORT bool generateMemTileEventTraceConfigsForRuntime(std::map<event::graph_tracing_MemTile_option, std::string> traceConfigOptionToFilePathMap);
    CARDANO_API_EXPORT void setWorkDirectory(std::string workDir);


#endif
}
