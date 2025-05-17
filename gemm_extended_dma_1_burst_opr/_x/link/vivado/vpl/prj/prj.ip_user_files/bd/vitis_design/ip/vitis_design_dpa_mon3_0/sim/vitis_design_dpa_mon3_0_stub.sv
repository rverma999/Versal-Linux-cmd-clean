// (c) Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// (c) Copyright 2022-2025 Advanced Micro Devices, Inc. All rights reserved.
// 
// This file contains confidential and proprietary information
// of AMD and is protected under U.S. and international copyright
// and other intellectual property laws.
// 
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// AMD, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND AMD HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) AMD shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or AMD had been advised of the
// possibility of the same.
// 
// CRITICAL APPLICATIONS
// AMD products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of AMD products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
// 
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
// 
// DO NOT MODIFY THIS FILE.


//------------------------------------------------------------------------------------
// Filename:    vitis_design_dpa_mon3_0_stub.sv
// Description: This HDL file is intended to be used with following simulators only:
//
//   Vivado Simulator (XSim)
//   Cadence Xcelium Simulator
//
//------------------------------------------------------------------------------------
`timescale 1ps/1ps

`ifdef XILINX_SIMULATOR

`ifndef XILINX_SIMULATOR_BITASBOOL
`define XILINX_SIMULATOR_BITASBOOL
typedef bit bit_as_bool;
`endif

(* SC_MODULE_EXPORT *)
module vitis_design_dpa_mon3_0 (
  input bit_as_bool mon_clk,
  input bit_as_bool mon_resetn,
  input bit_as_bool trace_clk,
  input bit_as_bool trace_rst,
  input bit [7 : 0] s_axi_awaddr,
  input bit_as_bool s_axi_awvalid,
  output bit_as_bool s_axi_awready,
  input bit [31 : 0] s_axi_wdata,
  input bit [3 : 0] s_axi_wstrb,
  input bit_as_bool s_axi_wvalid,
  output bit_as_bool s_axi_wready,
  output bit_as_bool s_axi_bvalid,
  input bit_as_bool s_axi_bready,
  output bit [1 : 0] s_axi_bresp,
  input bit [7 : 0] s_axi_araddr,
  input bit_as_bool s_axi_arvalid,
  output bit_as_bool s_axi_arready,
  output bit [31 : 0] s_axi_rdata,
  output bit [1 : 0] s_axi_rresp,
  output bit_as_bool s_axi_rvalid,
  input bit_as_bool s_axi_rready,
  input bit [0 : 0] m_axis_tready,
  output bit [63 : 0] m_axis_tdata,
  output bit_as_bool m_axis_tlast,
  output bit [7 : 0] m_axis_tid,
  output bit [7 : 0] m_axis_tdest,
  output bit_as_bool m_axis_tvalid,
  input bit [0 : 0] s_axis_mon_tready,
  input bit [31 : 0] s_axis_mon_tdata,
  input bit_as_bool s_axis_mon_tlast,
  input bit [0 : 0] s_axis_mon_tid,
  input bit [0 : 0] s_axis_mon_tdest,
  input bit_as_bool s_axis_mon_tvalid
);
endmodule
`endif

`ifdef XCELIUM
(* XMSC_MODULE_EXPORT *)
module vitis_design_dpa_mon3_0 (mon_clk,mon_resetn,trace_clk,trace_rst,s_axi_awaddr,s_axi_awvalid,s_axi_awready,s_axi_wdata,s_axi_wstrb,s_axi_wvalid,s_axi_wready,s_axi_bvalid,s_axi_bready,s_axi_bresp,s_axi_araddr,s_axi_arvalid,s_axi_arready,s_axi_rdata,s_axi_rresp,s_axi_rvalid,s_axi_rready,m_axis_tready,m_axis_tdata,m_axis_tlast,m_axis_tid,m_axis_tdest,m_axis_tvalid,s_axis_mon_tready,s_axis_mon_tdata,s_axis_mon_tlast,s_axis_mon_tid,s_axis_mon_tdest,s_axis_mon_tvalid)
(* integer foreign = "SystemC";
*);
  input bit mon_clk;
  input bit mon_resetn;
  input bit trace_clk;
  input bit trace_rst;
  input bit [7 : 0] s_axi_awaddr;
  input bit s_axi_awvalid;
  output wire s_axi_awready;
  input bit [31 : 0] s_axi_wdata;
  input bit [3 : 0] s_axi_wstrb;
  input bit s_axi_wvalid;
  output wire s_axi_wready;
  output wire s_axi_bvalid;
  input bit s_axi_bready;
  output wire [1 : 0] s_axi_bresp;
  input bit [7 : 0] s_axi_araddr;
  input bit s_axi_arvalid;
  output wire s_axi_arready;
  output wire [31 : 0] s_axi_rdata;
  output wire [1 : 0] s_axi_rresp;
  output wire s_axi_rvalid;
  input bit s_axi_rready;
  input bit [0 : 0] m_axis_tready;
  output wire [63 : 0] m_axis_tdata;
  output wire m_axis_tlast;
  output wire [7 : 0] m_axis_tid;
  output wire [7 : 0] m_axis_tdest;
  output wire m_axis_tvalid;
  input bit [0 : 0] s_axis_mon_tready;
  input bit [31 : 0] s_axis_mon_tdata;
  input bit s_axis_mon_tlast;
  input bit [0 : 0] s_axis_mon_tid;
  input bit [0 : 0] s_axis_mon_tdest;
  input bit s_axis_mon_tvalid;
endmodule
`endif
