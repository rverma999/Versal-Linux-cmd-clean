// (c) Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// (c) Copyright 2022-2024 Advanced Micro Devices, Inc. All rights reserved.
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
// Filename:    vitis_design_noc_ddr4_0_stub.sv
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
module vitis_design_noc_ddr4_0 (
  input bit [0 : 0] S00_INI_internoc,
  input bit [0 : 0] S01_INI_internoc,
  input bit [0 : 0] S02_INI_internoc,
  input bit [0 : 0] S03_INI_internoc,
  input bit [0 : 0] sys_clk0_clk_p,
  input bit [0 : 0] sys_clk0_clk_n,
  output bit [63 : 0] CH0_DDR4_0_dq,
  output bit [7 : 0] CH0_DDR4_0_dqs_t,
  output bit [7 : 0] CH0_DDR4_0_dqs_c,
  output bit [16 : 0] CH0_DDR4_0_adr,
  output bit [1 : 0] CH0_DDR4_0_ba,
  output bit [1 : 0] CH0_DDR4_0_bg,
  output bit [0 : 0] CH0_DDR4_0_act_n,
  output bit [0 : 0] CH0_DDR4_0_reset_n,
  output bit [0 : 0] CH0_DDR4_0_ck_t,
  output bit [0 : 0] CH0_DDR4_0_ck_c,
  output bit [0 : 0] CH0_DDR4_0_cke,
  output bit [0 : 0] CH0_DDR4_0_cs_n,
  output bit [7 : 0] CH0_DDR4_0_dm_n,
  output bit [0 : 0] CH0_DDR4_0_odt
);
endmodule
`endif

`ifdef XCELIUM
(* XMSC_MODULE_EXPORT *)
module vitis_design_noc_ddr4_0 (S00_INI_internoc,S01_INI_internoc,S02_INI_internoc,S03_INI_internoc,sys_clk0_clk_p,sys_clk0_clk_n,CH0_DDR4_0_dq,CH0_DDR4_0_dqs_t,CH0_DDR4_0_dqs_c,CH0_DDR4_0_adr,CH0_DDR4_0_ba,CH0_DDR4_0_bg,CH0_DDR4_0_act_n,CH0_DDR4_0_reset_n,CH0_DDR4_0_ck_t,CH0_DDR4_0_ck_c,CH0_DDR4_0_cke,CH0_DDR4_0_cs_n,CH0_DDR4_0_dm_n,CH0_DDR4_0_odt)
(* integer foreign = "SystemC";
*);
  input bit [0 : 0] S00_INI_internoc;
  input bit [0 : 0] S01_INI_internoc;
  input bit [0 : 0] S02_INI_internoc;
  input bit [0 : 0] S03_INI_internoc;
  input bit [0 : 0] sys_clk0_clk_p;
  input bit [0 : 0] sys_clk0_clk_n;
  inout wire [63 : 0] CH0_DDR4_0_dq;
  inout wire [7 : 0] CH0_DDR4_0_dqs_t;
  inout wire [7 : 0] CH0_DDR4_0_dqs_c;
  output wire [16 : 0] CH0_DDR4_0_adr;
  output wire [1 : 0] CH0_DDR4_0_ba;
  output wire [1 : 0] CH0_DDR4_0_bg;
  output wire [0 : 0] CH0_DDR4_0_act_n;
  output wire [0 : 0] CH0_DDR4_0_reset_n;
  output wire [0 : 0] CH0_DDR4_0_ck_t;
  output wire [0 : 0] CH0_DDR4_0_ck_c;
  output wire [0 : 0] CH0_DDR4_0_cke;
  output wire [0 : 0] CH0_DDR4_0_cs_n;
  inout wire [7 : 0] CH0_DDR4_0_dm_n;
  output wire [0 : 0] CH0_DDR4_0_odt;
endmodule
`endif
