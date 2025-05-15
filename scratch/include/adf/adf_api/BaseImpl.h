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

#include <stdlib.h>
#include <string>
#include "adf/new_frontend/adf.h"

namespace adf
{
    class SharedBufferImpl;

    class ObjectImpl
    {
    public:
        virtual ~ObjectImpl() {}

        enum object_type { obj_invalid, obj_graph, obj_kernel, obj_port, obj_connect, obj_parameter, obj_plio, obj_gmio, obj_fileio, obj_pktmerge, obj_pktorderedmerge, obj_pktsplit, obj_pktcontrol, obj_microcontroller, obj_bypass, obj_platform, obj_shared_buffer, obj_external_buffer, obj_operator };
        
        virtual object_type getObjectType() const = 0;
        int getId() const { return id; }

    protected:
        int id;

        ObjectImpl();
    };

    class GraphImpl : public ObjectImpl
    {
    public:
        GraphImpl();
        GraphImpl(int identifier);

        object_type getObjectType() const override { return obj_graph; }

        enum graph_type { g_graph, g_interface, g_alternative };
        
        virtual void setGraphType(graph_type t) {}
        virtual void registerAlternatives(std::vector<GraphImpl*> altGraphs) {}

        virtual return_code init() { return return_code::unsupported; }
        virtual return_code run() { return return_code::unsupported; }
        virtual return_code run(int test_iter) { return return_code::unsupported; }
        virtual return_code wait() { return return_code::unsupported; }
        virtual return_code wait(unsigned long long cycle_timeout) { return return_code::unsupported; }
        virtual return_code resume() { return return_code::unsupported; }
        virtual return_code end() { return return_code::unsupported; }
        virtual return_code end(unsigned long long cycle_timeout) { return return_code::unsupported; }
        virtual return_code update(PortImpl*, const void*, size_t, element_type) { return return_code::unsupported; }
        virtual return_code read(PortImpl*, void*, size_t, element_type) { return return_code::unsupported; }

    public:
        static std::shared_ptr<GraphImpl> create();
        static int registerGraph();
    private:
        static int nextId;
    };

    class PortImpl : public ObjectImpl
    {
    public:
        PortImpl();
        PortImpl(int identifier);

        object_type getObjectType() const { return obj_port; }

        virtual void setNegateProperty() {}
        virtual void setSyncProperty() {}
        virtual void setAsyncProperty() {}

    public:
        ///create function for graph port
        static std::shared_ptr<PortImpl> create(adf::port_direction dir);
        ///create function for kernel, pktmerge, pktorderedmerge, pktsplit, pktcontrol, input/output_plio, input/output_gmio port
        static std::shared_ptr<PortImpl> create(api_impl::port_info portInfo, ObjectImpl* pObject);
        ///create function for bypass port
        static std::shared_ptr<PortImpl> create(bool isBypassControl, PortImpl* pKernelPort, BypassImpl* pBypass);
        static int registerPort();
    private:
        static int nextId;
    };

    class KernelImpl : public ObjectImpl
    {
    public:
        KernelImpl();
        KernelImpl(int identifier);

        object_type getObjectType() const { return obj_kernel; }

        virtual void assignFrom(KernelImpl* spFrom) {}
      
        virtual void setClassName(std::string className) {}
        virtual void setConstructorParams(const std::vector<api_impl::variant>& params) {}
        virtual void registerFunction(std::string funcName, std::string loc) {}

    public:
        static std::shared_ptr<KernelImpl> create(bool isFromKernelCreate);
        static int registerKernel();
    private:
        static int nextId;
    };

    class ParameterImpl : public ObjectImpl
    {
    public:
        ParameterImpl();
        ParameterImpl(int identifier);

        object_type getObjectType() const { return obj_parameter; }

        virtual void assignFrom(ParameterImpl* pFrom) {}

    public:
        /// This API is to declare adf::parameter or to create/return adf::parameter from adf::parameter::array
        static std::shared_ptr<ParameterImpl> create(bool isFromParameterArray, api_impl::param_info paramInfo = api_impl::param_info());
        /// This API is to REGISTER_PARAMETER in registerKernelClass for array reference member variables in kernel class
        static std::shared_ptr<ParameterImpl> create(api_impl::param_info paramInfo, std::string varName, KernelImpl* pKernel, std::string loc = std::string());
        static int registerParameter();
    private:
        static int nextId;
    };

    class ConnectImpl : public ObjectImpl
    {
    public:
        ConnectImpl();

        object_type getObjectType() const { return obj_connect; }

    public:
        static std::shared_ptr<ConnectImpl> create(PortImpl* portL, PortImpl* portR, api_impl::ConnectTemplateParameter paramL, api_impl::ConnectTemplateParameter paramR);
        static std::shared_ptr<ConnectImpl> create(ParameterImpl* pParameter, KernelImpl* pKernel);
        static int registerConnect();
    private:
        static int nextId;
    };

    class PktBaseImpl : public ObjectImpl
    {
    };

    class PktMergeImpl : public PktBaseImpl
    {
    public:
        PktMergeImpl();
        PktMergeImpl(int identifier);

        object_type getObjectType() const { return obj_pktmerge; }

        virtual void assignFrom(PktMergeImpl* pFrom) {}

    public:
        static std::shared_ptr<PktMergeImpl> create(bool isFromCreateFunction);
    private:
        static int nextId;
    };

    class PktOrderedMergeImpl : public PktBaseImpl
    {
    public:
        PktOrderedMergeImpl();
        PktOrderedMergeImpl(int identifier);

        object_type getObjectType() const { return obj_pktorderedmerge; }

        virtual void assignFrom(PktOrderedMergeImpl* pFrom) {}

    public:
        static std::shared_ptr<PktOrderedMergeImpl> create(bool isFromCreateFunction);
    private:
        static int nextId;
    };

    class PktSplitImpl : public PktBaseImpl
    {
    public:
        PktSplitImpl();
        PktSplitImpl(int identifier);

        object_type getObjectType() const { return obj_pktsplit; }

        virtual void assignFrom(PktSplitImpl* pFrom) {}
        
    public:
        static std::shared_ptr<PktSplitImpl> create(bool isFromCreateFunction);
    private:
        static int nextId;
    };

    class PktControlImpl : public PktBaseImpl
    {
    public:
        PktControlImpl();
        PktControlImpl(int identifier);

        object_type getObjectType() const { return obj_pktcontrol; }

        virtual void assignFrom(PktControlImpl* pFrom) {}
        
    public:
        static std::shared_ptr<PktControlImpl> create(bool isFromCreateFunction);
    private:
        static int nextId;
    };

    class MicroControllerImpl : public ObjectImpl
    {
    public:
        MicroControllerImpl();
        MicroControllerImpl(int identifier);

        object_type getObjectType() const { return obj_microcontroller; }

        virtual void assignFrom(MicroControllerImpl* pFrom) {}
        
    public:
        static std::shared_ptr<MicroControllerImpl> create(bool isFromCreateFunction);
    private:
        static int nextId;
    };

    class BypassImpl : public ObjectImpl
    {
    public:
        BypassImpl();
        BypassImpl(int identifier);

        object_type getObjectType() const { return obj_bypass; }

        virtual void assignFrom(BypassImpl* pFrom) {}

    public:
        static std::shared_ptr<BypassImpl> create(KernelImpl* kernelImpl);
        //static std::shared_ptr<BypassImpl> create(KernelImpl* kernelImpl, std::vector<std::shared_ptr<PortImpl>>& inImpls, std::vector<std::shared_ptr<PortImpl>>& outImpls, std::vector<std::shared_ptr<PortImpl>>& inoutImpls, std::shared_ptr<PortImpl>& bpImpl);
    private:
        static int nextId;
    };

    class ConstraintImpl
    {
    public:
        ConstraintImpl() {}

        virtual void assignFrom(float) {}
        virtual void assignFrom(int) {}
        virtual void assignFrom(bool) {}
        virtual void assignFrom(double) {}
        virtual void assignFrom(uint64_t) {}
        virtual void assignFrom(std::vector<int>) {}
        virtual void assignFrom(std::string) {}
        virtual void assignFrom(std::vector<std::string>) {}
        virtual void assignFrom(const ConstraintImpl&) {}
        virtual void assignFrom(adf::DMA_MODE) {}
        virtual void assignFrom(api_impl::variant) {}
        virtual void assignFrom(adf::access_pattern value) {}
        virtual void assignFrom(std::vector<adf::access_pattern> value) {}
        virtual void assignFrom(adf::finish_on_tlast_mode) {}
        virtual void assignFrom(uint32_t) {}
        virtual void assignFrom(const std::vector<uint32_t>&) {}
        //FIXME change above std::vector to const &

    public:
        enum constraint_type
        {
            c_invalid,
            c_runtime_ratio,
            c_source,
            c_shared_lib,
            c_systemc_lib,
            c_headers,
            c_init_function,
            c_fabric_fpga,
            c_fabric_pl,
            c_fabric_aiengine,
            c_utilization,
            c_fifo_depth,
            c_dma_mode,
            c_single_buffer,
            c_initial_value,
            c_pl_axi_lite,
            c_pl_freq,
            c_stack_size,
            c_heap_size,
            c_access_pattern,
            c_repetition_count,
            c_enable_task_complete_token,
            c_task_repetition,
            c_finish_on_tlast,
            c_enable_compression,
            c_num_buffers,
            c_disable_dma_autostart,
            c_disable_out_of_order_mode,
            c_async_repetition,
            c_storage_size,
            c_samples_per_iteration,
            c_dimensions,
            c_execution_order,
            c_dedicated_controller,
            c_attribute
        };

    public:
        static std::shared_ptr<ConstraintImpl> create(constraint_type type, KernelImpl* pKernel);
        static std::shared_ptr<ConstraintImpl> create(constraint_type type, PortImpl* pPort);
        static std::shared_ptr<ConstraintImpl> create(constraint_type type, ConnectImpl* pConnect);
        static std::shared_ptr<ConstraintImpl> create(constraint_type type, SharedBufferImpl* pSharedBuffer);
        static std::shared_ptr<ConstraintImpl> create(constraint_type type, KernelImpl* pKernel1, KernelImpl* pKernel2);
        static std::shared_ptr<ConstraintImpl> create(constraint_type type, SharedBufferImpl* pSharedBuffer1, SharedBufferImpl* pSharedBuffer2);
        static std::shared_ptr<ConstraintImpl> create(constraint_type type, ExternalBufferImpl* pExternalBuffer, SharedBufferImpl* pSharedBuffer);
        static std::shared_ptr<ConstraintImpl> create(constraint_type type, SharedBufferImpl* pSharedBuffer, ExternalBufferImpl* pExternalBuffer);
        static std::shared_ptr<ConstraintImpl> create(constraint_type type, const std::vector<PortImpl*>& portImpls1, const std::vector<PortImpl*>& portImpls2);
        static std::shared_ptr<ConstraintImpl> create(constraint_type type, GraphImpl* pGraph);
        static std::shared_ptr<ConstraintImpl> create(constraint_type type, OperatorImpl* oOp, std::string attributeName);
        static std::shared_ptr<ConstraintImpl> create(constraint_type type, PortImpl* pPort, std::string attributeName);
    };

    class LocationConstraintImpl
    {
    public:
        LocationConstraintImpl() {}

        virtual void assignFrom(LocationConstraintImpl*) {}
        virtual void assignFrom(std::vector<LocationConstraintImpl*>&) {}
        virtual void assignFrom(std::vector<std::vector<LocationConstraintImpl*>>&) {}
        virtual void notEqual(LocationConstraintImpl*) {}
        virtual void stampAsReferenceGraph() {}
        virtual bool isValidLHS() { return false; }

    public:
        enum location_constraint_type
        {
            c_invalid,
            c_kernel_location,
            c_stack_location,
            c_buffer_location,
            c_parameter_location,
            c_parameter_buffer_location,
            c_stream_location,
            c_graph_location,
            c_pktcontrol_location,
            c_microcontroller_location,
            c_dma_location,
            c_shared_buffer_location,
            c_fifo_location,
            c_plio_location,
            c_gmio_location,
            c_tile_value,
            c_address_value,
            c_bank_value,
            c_channel_value,
            c_relative_channel_value,
            c_bounding_box_value,
            c_offset_value,
            c_program_memory_value,
            c_dma_fifo_value,
            c_ss_fifo_value,
            c_dma_fifo_type_value,
            c_ss_fifo_type_value,
            c_area_group_value,
            c_shim_col_value,
            c_shim_col_ch_value,
            c_dma_ch_value,
            c_fragment_address_value,
            c_relative_offset_value,
            c_kernel_relative_offset_value,
            c_plio_relative_offset_value,
            c_gmio_relative_offset_value,
            c_shared_buffer_relative_offset_value
        };

    public:
        static std::shared_ptr<LocationConstraintImpl> create(location_constraint_type type, KernelImpl* spKernel);
        static std::shared_ptr<LocationConstraintImpl> create(location_constraint_type type, PortImpl* pPort);
        static std::shared_ptr<LocationConstraintImpl> create(location_constraint_type type, GraphImpl* pGraph);
        static std::shared_ptr<LocationConstraintImpl> create(location_constraint_type type, ParameterImpl* pParameter);
        static std::shared_ptr<LocationConstraintImpl> create(location_constraint_type type, PktControlImpl* pPktControl);
        static std::shared_ptr<LocationConstraintImpl> create(location_constraint_type type, MicroControllerImpl* pMicroController);
        static std::shared_ptr<LocationConstraintImpl> create(location_constraint_type type, SharedBufferImpl* pSharedBuffer);
        static std::shared_ptr<LocationConstraintImpl> create(location_constraint_type type, IoAttrImpl* pIO);
        static std::shared_ptr<LocationConstraintImpl> create(location_constraint_type type, int val0 = 0, int val1 = 0, int val2 = 0, int val3 = 0, int val4 =0);
        static std::shared_ptr<LocationConstraintImpl> create(location_constraint_type type, std::vector<std::string> constrVec);
        static std::shared_ptr<LocationConstraintImpl> create(location_constraint_type type, ConnectImpl* pConnect);
        static std::shared_ptr<LocationConstraintImpl> create(location_constraint_type type, adf::area_group_parameters ag_params);
        static std::shared_ptr<LocationConstraintImpl> create(location_constraint_type type, const std::vector<adf::dimension_range>& fragment, int column, int row, int offset);
        static std::shared_ptr<LocationConstraintImpl> addLocationConstraints(LocationConstraintImpl* constraint1, LocationConstraintImpl* constraint2);
    };

    class PlatformImpl : public ObjectImpl
    {
    public:
        PlatformImpl();

        object_type getObjectType() const { return obj_platform; }

        static std::shared_ptr<PlatformImpl> create(std::vector<PortImpl*>& spPorts, std::vector<IoAttrImpl*>& spIOs);

    private:
        static int nextId;
    };

    class IoAttrImpl : public ObjectImpl
    {
        public:
            virtual void assignFrom(IoAttrImpl* pFrom) {}
    };

    class GMIOImpl : public IoAttrImpl
    {
    public:
        GMIOImpl();
        GMIOImpl(int identifier);

        object_type getObjectType() const { return obj_gmio; }

        virtual return_code gm2aie_nb(const void* address, size_t transaction_size) { return return_code::unsupported; }
        virtual return_code gm2aie_nb(const void* address, const std::vector<dma_buffer_descriptor>& buffer_descriptors, const std::vector<uint32_t>& bd_ids, uint32_t repeat_count, bool enable_task_complete_token) { return return_code::unsupported; }
        virtual return_code aie2gm_nb(void* address, size_t transaction_size) { return return_code::unsupported; }
        virtual return_code aie2gm_nb(void* address, const std::vector<dma_buffer_descriptor>& buffer_descriptors, const std::vector<uint32_t>& bd_ids, uint32_t repeat_count, bool enable_task_complete_token) { return return_code::unsupported; }
        virtual return_code wait() { return return_code::unsupported; }
        virtual return_code pl_gm(void* address, size_t total_size) { return return_code::unsupported; }

    public:
        static std::shared_ptr<GMIOImpl> create(std::string logicalName, size_t burst_size, size_t band_width);
        static std::shared_ptr<GMIOImpl> create(bool isFromCreateFunction, std::string logicalName = std::string(), size_t burst_size = 0, size_t band_width = 0);
        static int registerGMIO();
    private:
        static int nextId;
    };

    class GMIOStaticImpl
    {
    public:
        virtual void* malloc(size_t size) { return nullptr; }
        virtual void free(void* address) {}

    public:
        static GMIOStaticImpl* getInstance() { return s_pInstance; }

    private:
        static GMIOStaticImpl* s_pInstance;
    };


    class PLIOImpl : public IoAttrImpl
    {
    public:
        PLIOImpl();
        PLIOImpl(int identifier);

        object_type getObjectType() const { return obj_plio; }
        
    public:
        static std::shared_ptr<PLIOImpl> create(std::string logicalName, plio_type type = plio_32_bits, std::string traceFileName = "", double frequency = 0, bool binary = false, bool hex = false);
        static std::shared_ptr<PLIOImpl> create(bool isFromCreateFunction, std::string logicalName = std::string(), plio_type type = plio_32_bits, std::string traceFileName = std::string(), double frequency = 0.0, bool hex = false);
        static int registerPLIO();
    private:
        static int nextId;
    };

    class FileIOImpl : public IoAttrImpl
    {
    public:
        FileIOImpl();

        object_type getObjectType() const { return obj_fileio; }

    public:
        static std::shared_ptr<FileIOImpl> create(std::string logicalName, std::string fileName);
    private:
        static int nextId;
    };

    class EventImpl
    {
    public:
        /// Enumeration for profiling options available for kernel objects
        enum kernel_profiling_option
        {
            kernel_between_pc_cycles /// Number of accumulated cycles between two specified program counters for a kernel object
        };

        enum graph_profiling_option
        {
          aie_heat_map,                                    /// non-event trace test cases
          aie_heat_map_with_event_trace                    /// Used only for unified view 
        };
        
        enum io_tracing_option
        {
          io_stream_events,                               /// io_stream_events: stream switch port idle, running, stalled, TLAST events
          io_dma_events                                   /// io_dma_events: DMA channel start-BD, finished-BD, go-to-idle, and stalled-lock-acquire events
        };

        enum kernel_tracing_option
        {
          kernel_pc_range /// program counter range event
        };
        
        enum tile_module_option
        {
          core_module,
          memory_module, 
          shim_tile_module 
        };

        enum event_trace_mode
        {
          time_mode,
          pc_mode,
          execution_mode
        };
        
    public:
        virtual event::handle start_profiling(ObjectImpl* io, event::io_profiling_option option, uint32 value = 0) { return event::invalid_handle; }
        virtual event::handle start_profiling(ObjectImpl* io1, ObjectImpl* io2, event::io_profiling_option option, uint32 value = 0) { return event::invalid_handle; }
        virtual event::handle start_profiling(KernelImpl* kernelImpl, kernel_profiling_option option, uint16 pc1, uint16 pc2) { return event::invalid_handle; }
        virtual event::handle start_profiling(GraphImpl* g, graph_profiling_option option) { return event::invalid_handle; }
        virtual long long read_profiling(event::handle handle) { return 0; }
        virtual void stop_profiling(event::handle handle) {}
        
        virtual event::handle start_tracing(int col, int row, tile_module_option module, event_trace_mode mode, std::vector<uint8> eventIds, uint8 start_event=1, uint8 stop_event=0) 
        { 
          return event::invalid_handle; 
        }
        virtual event::handle start_tracing(ObjectImpl* io, io_tracing_option option) { return event::invalid_handle; }
        virtual event::handle start_tracing(KernelImpl* kernel, kernel_tracing_option option, uint16 pc1, uint16 pc2) { return event::invalid_handle; }
        virtual event::handle start_tracing(GraphImpl* g, event::graph_tracing_option option) { return event::invalid_handle; }
        virtual event::handle start_tracing_MemTile(GraphImpl* g, event::graph_tracing_MemTile_option option) { return event::invalid_handle; }
        virtual void stop_tracing(event::handle handle) {}

    public:
        static EventImpl* getInstance() { return s_pInstance; }

    private:
        static EventImpl* s_pInstance;
    };

    class SharedBufferImpl : public ObjectImpl
    {
    public:
        SharedBufferImpl();
        SharedBufferImpl(int identifier);

        object_type getObjectType() const { return obj_shared_buffer; }

        virtual void assignFrom(SharedBufferImpl* pFrom) {}

    public:
        static std::shared_ptr<SharedBufferImpl> create(bool isFromCreateFunction, element_type elemType = et_voidty, const std::vector<uint32_t>& dimensions = {});

        virtual return_code enqueue_task(PortImpl* portImpl, const std::vector<dma_buffer_descriptor>& buffer_descriptors, const std::vector<uint32_t>& bd_ids, uint32_t repeat_count, bool enable_task_complete_token) { return return_code::unsupported; }
        
        virtual return_code wait(PortImpl* portImpl) { return return_code::unsupported; }
        
    private:
        static int nextId;
    };

    class ExternalBufferImpl : public ObjectImpl
    {
    public:
        ExternalBufferImpl();
        ExternalBufferImpl(int identifier);

        object_type getObjectType() const { return obj_external_buffer; }

        virtual void assignFrom(ExternalBufferImpl* pFrom) {}

        static std::shared_ptr<ExternalBufferImpl> create(bool isFromCreateFunction, element_type elemType = et_voidty, const std::vector<uint32_t>& dimensions = {});
        
        virtual void setAddress(const void* ptr) {}

        virtual return_code wait(PortImpl* portImpl) { return return_code::unsupported; }
        
        virtual return_code gm2aie_nb(PortImpl* portImpl) { return return_code::unsupported; }
        
        virtual return_code aie2gm_nb(PortImpl* portImpl) { return return_code::unsupported; }
        
    private:
        static int nextId;
    };

    class OperatorImpl : public ObjectImpl
    {
    public:
        OperatorImpl();
        OperatorImpl(int identifier);

        object_type getObjectType() const { return obj_operator; }

        virtual void assignFrom(OperatorImpl* pFrom) {}

        static std::shared_ptr<OperatorImpl> create(bool isFromCreateFunction, std::string operatorName = "");

    private:
        static int nextId;
    };
}


