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


// IP VLNV: xilinx.com:ip:axi_noc:1.1
// IP Revision: 0

`timescale 1ns/1ps

(* DowngradeIPIdentifiedWarnings = "yes" *)
module vitis_design_cips_noc_0 (
  S00_AXI_awaddr,
  S00_AXI_awlen,
  S00_AXI_awsize,
  S00_AXI_awburst,
  S00_AXI_awlock,
  S00_AXI_awcache,
  S00_AXI_awprot,
  S00_AXI_awregion,
  S00_AXI_awqos,
  S00_AXI_awvalid,
  S00_AXI_awready,
  S00_AXI_wdata,
  S00_AXI_wstrb,
  S00_AXI_wlast,
  S00_AXI_wvalid,
  S00_AXI_wready,
  S00_AXI_bresp,
  S00_AXI_bvalid,
  S00_AXI_bready,
  S00_AXI_araddr,
  S00_AXI_arlen,
  S00_AXI_arsize,
  S00_AXI_arburst,
  S00_AXI_arlock,
  S00_AXI_arcache,
  S00_AXI_arprot,
  S00_AXI_arregion,
  S00_AXI_arqos,
  S00_AXI_arvalid,
  S00_AXI_arready,
  S00_AXI_rdata,
  S00_AXI_rresp,
  S00_AXI_rlast,
  S00_AXI_rvalid,
  S00_AXI_rready,
  S01_AXI_awaddr,
  S01_AXI_awlen,
  S01_AXI_awsize,
  S01_AXI_awburst,
  S01_AXI_awlock,
  S01_AXI_awcache,
  S01_AXI_awprot,
  S01_AXI_awregion,
  S01_AXI_awqos,
  S01_AXI_awvalid,
  S01_AXI_awready,
  S01_AXI_wdata,
  S01_AXI_wstrb,
  S01_AXI_wlast,
  S01_AXI_wvalid,
  S01_AXI_wready,
  S01_AXI_bresp,
  S01_AXI_bvalid,
  S01_AXI_bready,
  S01_AXI_araddr,
  S01_AXI_arlen,
  S01_AXI_arsize,
  S01_AXI_arburst,
  S01_AXI_arlock,
  S01_AXI_arcache,
  S01_AXI_arprot,
  S01_AXI_arregion,
  S01_AXI_arqos,
  S01_AXI_arvalid,
  S01_AXI_arready,
  S01_AXI_rdata,
  S01_AXI_rresp,
  S01_AXI_rlast,
  S01_AXI_rvalid,
  S01_AXI_rready,
  S02_AXI_awaddr,
  S02_AXI_awlen,
  S02_AXI_awsize,
  S02_AXI_awburst,
  S02_AXI_awlock,
  S02_AXI_awcache,
  S02_AXI_awprot,
  S02_AXI_awregion,
  S02_AXI_awqos,
  S02_AXI_awvalid,
  S02_AXI_awready,
  S02_AXI_wdata,
  S02_AXI_wstrb,
  S02_AXI_wlast,
  S02_AXI_wvalid,
  S02_AXI_wready,
  S02_AXI_bresp,
  S02_AXI_bvalid,
  S02_AXI_bready,
  S02_AXI_araddr,
  S02_AXI_arlen,
  S02_AXI_arsize,
  S02_AXI_arburst,
  S02_AXI_arlock,
  S02_AXI_arcache,
  S02_AXI_arprot,
  S02_AXI_arregion,
  S02_AXI_arqos,
  S02_AXI_arvalid,
  S02_AXI_arready,
  S02_AXI_rdata,
  S02_AXI_rresp,
  S02_AXI_rlast,
  S02_AXI_rvalid,
  S02_AXI_rready,
  S03_AXI_awaddr,
  S03_AXI_awlen,
  S03_AXI_awsize,
  S03_AXI_awburst,
  S03_AXI_awlock,
  S03_AXI_awcache,
  S03_AXI_awprot,
  S03_AXI_awregion,
  S03_AXI_awqos,
  S03_AXI_awvalid,
  S03_AXI_awready,
  S03_AXI_wdata,
  S03_AXI_wstrb,
  S03_AXI_wlast,
  S03_AXI_wvalid,
  S03_AXI_wready,
  S03_AXI_bresp,
  S03_AXI_bvalid,
  S03_AXI_bready,
  S03_AXI_araddr,
  S03_AXI_arlen,
  S03_AXI_arsize,
  S03_AXI_arburst,
  S03_AXI_arlock,
  S03_AXI_arcache,
  S03_AXI_arprot,
  S03_AXI_arregion,
  S03_AXI_arqos,
  S03_AXI_arvalid,
  S03_AXI_arready,
  S03_AXI_rdata,
  S03_AXI_rresp,
  S03_AXI_rlast,
  S03_AXI_rvalid,
  S03_AXI_rready,
  S04_AXI_awaddr,
  S04_AXI_awlen,
  S04_AXI_awsize,
  S04_AXI_awburst,
  S04_AXI_awlock,
  S04_AXI_awcache,
  S04_AXI_awprot,
  S04_AXI_awregion,
  S04_AXI_awqos,
  S04_AXI_awvalid,
  S04_AXI_awready,
  S04_AXI_wdata,
  S04_AXI_wstrb,
  S04_AXI_wlast,
  S04_AXI_wvalid,
  S04_AXI_wready,
  S04_AXI_bresp,
  S04_AXI_bvalid,
  S04_AXI_bready,
  S04_AXI_araddr,
  S04_AXI_arlen,
  S04_AXI_arsize,
  S04_AXI_arburst,
  S04_AXI_arlock,
  S04_AXI_arcache,
  S04_AXI_arprot,
  S04_AXI_arregion,
  S04_AXI_arqos,
  S04_AXI_arvalid,
  S04_AXI_arready,
  S04_AXI_rdata,
  S04_AXI_rresp,
  S04_AXI_rlast,
  S04_AXI_rvalid,
  S04_AXI_rready,
  S05_AXI_awaddr,
  S05_AXI_awlen,
  S05_AXI_awsize,
  S05_AXI_awburst,
  S05_AXI_awlock,
  S05_AXI_awcache,
  S05_AXI_awprot,
  S05_AXI_awregion,
  S05_AXI_awqos,
  S05_AXI_awvalid,
  S05_AXI_awready,
  S05_AXI_wdata,
  S05_AXI_wstrb,
  S05_AXI_wlast,
  S05_AXI_wvalid,
  S05_AXI_wready,
  S05_AXI_bresp,
  S05_AXI_bvalid,
  S05_AXI_bready,
  S05_AXI_araddr,
  S05_AXI_arlen,
  S05_AXI_arsize,
  S05_AXI_arburst,
  S05_AXI_arlock,
  S05_AXI_arcache,
  S05_AXI_arprot,
  S05_AXI_arregion,
  S05_AXI_arqos,
  S05_AXI_arvalid,
  S05_AXI_arready,
  S05_AXI_rdata,
  S05_AXI_rresp,
  S05_AXI_rlast,
  S05_AXI_rvalid,
  S05_AXI_rready,
  S06_AXI_awaddr,
  S06_AXI_awlen,
  S06_AXI_awsize,
  S06_AXI_awburst,
  S06_AXI_awlock,
  S06_AXI_awcache,
  S06_AXI_awprot,
  S06_AXI_awregion,
  S06_AXI_awqos,
  S06_AXI_awvalid,
  S06_AXI_awready,
  S06_AXI_wdata,
  S06_AXI_wstrb,
  S06_AXI_wlast,
  S06_AXI_wvalid,
  S06_AXI_wready,
  S06_AXI_bresp,
  S06_AXI_bvalid,
  S06_AXI_bready,
  S06_AXI_araddr,
  S06_AXI_arlen,
  S06_AXI_arsize,
  S06_AXI_arburst,
  S06_AXI_arlock,
  S06_AXI_arcache,
  S06_AXI_arprot,
  S06_AXI_arregion,
  S06_AXI_arqos,
  S06_AXI_arvalid,
  S06_AXI_arready,
  S06_AXI_rdata,
  S06_AXI_rresp,
  S06_AXI_rlast,
  S06_AXI_rvalid,
  S06_AXI_rready,
  S07_AXI_awaddr,
  S07_AXI_awlen,
  S07_AXI_awsize,
  S07_AXI_awburst,
  S07_AXI_awlock,
  S07_AXI_awcache,
  S07_AXI_awprot,
  S07_AXI_awregion,
  S07_AXI_awqos,
  S07_AXI_awvalid,
  S07_AXI_awready,
  S07_AXI_wdata,
  S07_AXI_wstrb,
  S07_AXI_wlast,
  S07_AXI_wvalid,
  S07_AXI_wready,
  S07_AXI_bresp,
  S07_AXI_bvalid,
  S07_AXI_bready,
  S07_AXI_araddr,
  S07_AXI_arlen,
  S07_AXI_arsize,
  S07_AXI_arburst,
  S07_AXI_arlock,
  S07_AXI_arcache,
  S07_AXI_arprot,
  S07_AXI_arregion,
  S07_AXI_arqos,
  S07_AXI_arvalid,
  S07_AXI_arready,
  S07_AXI_rdata,
  S07_AXI_rresp,
  S07_AXI_rlast,
  S07_AXI_rvalid,
  S07_AXI_rready,
  M00_AXI_awaddr,
  M00_AXI_awlen,
  M00_AXI_awsize,
  M00_AXI_awburst,
  M00_AXI_awlock,
  M00_AXI_awcache,
  M00_AXI_awprot,
  M00_AXI_awregion,
  M00_AXI_awqos,
  M00_AXI_awvalid,
  M00_AXI_awready,
  M00_AXI_wdata,
  M00_AXI_wstrb,
  M00_AXI_wlast,
  M00_AXI_wvalid,
  M00_AXI_wready,
  M00_AXI_bresp,
  M00_AXI_bvalid,
  M00_AXI_bready,
  M00_AXI_araddr,
  M00_AXI_arlen,
  M00_AXI_arsize,
  M00_AXI_arburst,
  M00_AXI_arlock,
  M00_AXI_arcache,
  M00_AXI_arprot,
  M00_AXI_arregion,
  M00_AXI_arqos,
  M00_AXI_arvalid,
  M00_AXI_arready,
  M00_AXI_rdata,
  M00_AXI_rresp,
  M00_AXI_rlast,
  M00_AXI_rvalid,
  M00_AXI_rready,
  M00_INI_internoc,
  M01_INI_internoc,
  M02_INI_internoc,
  M03_INI_internoc,
  M04_INI_internoc,
  M05_INI_internoc,
  M06_INI_internoc,
  M07_INI_internoc,
  aclk0,
  aclk1,
  aclk2,
  aclk3,
  aclk4,
  aclk5,
  aclk6,
  aclk7,
  aclk8,
  aclk9,
  S07_AXI_arid,
  S07_AXI_aruser,
  S07_AXI_awid,
  S07_AXI_awuser,
  S07_AXI_bid,
  S07_AXI_buser,
  S07_AXI_rid,
  S07_AXI_ruser,
  S07_AXI_wuser,
  S06_AXI_arid,
  S06_AXI_aruser,
  S06_AXI_awid,
  S06_AXI_awuser,
  S06_AXI_bid,
  S06_AXI_rid,
  S06_AXI_ruser,
  S06_AXI_wuser,
  S01_AXI_arid,
  S01_AXI_aruser,
  S01_AXI_awid,
  S01_AXI_awuser,
  S01_AXI_bid,
  S01_AXI_rid,
  S01_AXI_ruser,
  S01_AXI_wuser,
  S03_AXI_arid,
  S03_AXI_aruser,
  S03_AXI_awid,
  S03_AXI_awuser,
  S03_AXI_bid,
  S03_AXI_rid,
  S03_AXI_ruser,
  S03_AXI_wuser,
  S05_AXI_arid,
  S05_AXI_aruser,
  S05_AXI_awid,
  S05_AXI_awuser,
  S05_AXI_bid,
  S05_AXI_rid,
  S05_AXI_ruser,
  S05_AXI_wuser,
  S00_AXI_arid,
  S00_AXI_aruser,
  S00_AXI_awid,
  S00_AXI_awuser,
  S00_AXI_bid,
  S00_AXI_rid,
  S00_AXI_ruser,
  S00_AXI_wuser,
  S02_AXI_arid,
  S02_AXI_aruser,
  S02_AXI_awid,
  S02_AXI_awuser,
  S02_AXI_bid,
  S02_AXI_rid,
  S02_AXI_ruser,
  S02_AXI_wuser,
  S04_AXI_arid,
  S04_AXI_aruser,
  S04_AXI_awid,
  S04_AXI_awuser,
  S04_AXI_bid,
  S04_AXI_rid,
  S04_AXI_ruser,
  S04_AXI_wuser,
  M00_AXI_arid,
  M00_AXI_awid,
  M00_AXI_bid,
  M00_AXI_rid,
  M00_AXI_ruser,
  M00_AXI_wuser
);

(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI AWADDR" *)
input wire [63 : 0] S00_AXI_awaddr;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI AWLEN" *)
input wire [7 : 0] S00_AXI_awlen;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI AWSIZE" *)
input wire [2 : 0] S00_AXI_awsize;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI AWBURST" *)
input wire [1 : 0] S00_AXI_awburst;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI AWLOCK" *)
input wire [0 : 0] S00_AXI_awlock;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI AWCACHE" *)
input wire [3 : 0] S00_AXI_awcache;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI AWPROT" *)
input wire [2 : 0] S00_AXI_awprot;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI AWREGION" *)
input wire [3 : 0] S00_AXI_awregion;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI AWQOS" *)
input wire [3 : 0] S00_AXI_awqos;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI AWVALID" *)
input wire [0 : 0] S00_AXI_awvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI AWREADY" *)
output wire [0 : 0] S00_AXI_awready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI WDATA" *)
input wire [127 : 0] S00_AXI_wdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI WSTRB" *)
input wire [15 : 0] S00_AXI_wstrb;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI WLAST" *)
input wire [0 : 0] S00_AXI_wlast;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI WVALID" *)
input wire [0 : 0] S00_AXI_wvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI WREADY" *)
output wire [0 : 0] S00_AXI_wready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI BRESP" *)
output wire [1 : 0] S00_AXI_bresp;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI BVALID" *)
output wire [0 : 0] S00_AXI_bvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI BREADY" *)
input wire [0 : 0] S00_AXI_bready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI ARADDR" *)
input wire [63 : 0] S00_AXI_araddr;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI ARLEN" *)
input wire [7 : 0] S00_AXI_arlen;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI ARSIZE" *)
input wire [2 : 0] S00_AXI_arsize;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI ARBURST" *)
input wire [1 : 0] S00_AXI_arburst;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI ARLOCK" *)
input wire [0 : 0] S00_AXI_arlock;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI ARCACHE" *)
input wire [3 : 0] S00_AXI_arcache;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI ARPROT" *)
input wire [2 : 0] S00_AXI_arprot;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI ARREGION" *)
input wire [3 : 0] S00_AXI_arregion;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI ARQOS" *)
input wire [3 : 0] S00_AXI_arqos;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI ARVALID" *)
input wire [0 : 0] S00_AXI_arvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI ARREADY" *)
output wire [0 : 0] S00_AXI_arready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI RDATA" *)
output wire [127 : 0] S00_AXI_rdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI RRESP" *)
output wire [1 : 0] S00_AXI_rresp;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI RLAST" *)
output wire [0 : 0] S00_AXI_rlast;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI RVALID" *)
output wire [0 : 0] S00_AXI_rvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI RREADY" *)
input wire [0 : 0] S00_AXI_rready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI AWADDR" *)
input wire [63 : 0] S01_AXI_awaddr;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI AWLEN" *)
input wire [7 : 0] S01_AXI_awlen;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI AWSIZE" *)
input wire [2 : 0] S01_AXI_awsize;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI AWBURST" *)
input wire [1 : 0] S01_AXI_awburst;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI AWLOCK" *)
input wire [0 : 0] S01_AXI_awlock;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI AWCACHE" *)
input wire [3 : 0] S01_AXI_awcache;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI AWPROT" *)
input wire [2 : 0] S01_AXI_awprot;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI AWREGION" *)
input wire [3 : 0] S01_AXI_awregion;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI AWQOS" *)
input wire [3 : 0] S01_AXI_awqos;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI AWVALID" *)
input wire [0 : 0] S01_AXI_awvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI AWREADY" *)
output wire [0 : 0] S01_AXI_awready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI WDATA" *)
input wire [127 : 0] S01_AXI_wdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI WSTRB" *)
input wire [15 : 0] S01_AXI_wstrb;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI WLAST" *)
input wire [0 : 0] S01_AXI_wlast;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI WVALID" *)
input wire [0 : 0] S01_AXI_wvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI WREADY" *)
output wire [0 : 0] S01_AXI_wready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI BRESP" *)
output wire [1 : 0] S01_AXI_bresp;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI BVALID" *)
output wire [0 : 0] S01_AXI_bvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI BREADY" *)
input wire [0 : 0] S01_AXI_bready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI ARADDR" *)
input wire [63 : 0] S01_AXI_araddr;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI ARLEN" *)
input wire [7 : 0] S01_AXI_arlen;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI ARSIZE" *)
input wire [2 : 0] S01_AXI_arsize;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI ARBURST" *)
input wire [1 : 0] S01_AXI_arburst;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI ARLOCK" *)
input wire [0 : 0] S01_AXI_arlock;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI ARCACHE" *)
input wire [3 : 0] S01_AXI_arcache;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI ARPROT" *)
input wire [2 : 0] S01_AXI_arprot;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI ARREGION" *)
input wire [3 : 0] S01_AXI_arregion;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI ARQOS" *)
input wire [3 : 0] S01_AXI_arqos;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI ARVALID" *)
input wire [0 : 0] S01_AXI_arvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI ARREADY" *)
output wire [0 : 0] S01_AXI_arready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI RDATA" *)
output wire [127 : 0] S01_AXI_rdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI RRESP" *)
output wire [1 : 0] S01_AXI_rresp;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI RLAST" *)
output wire [0 : 0] S01_AXI_rlast;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI RVALID" *)
output wire [0 : 0] S01_AXI_rvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI RREADY" *)
input wire [0 : 0] S01_AXI_rready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI AWADDR" *)
input wire [63 : 0] S02_AXI_awaddr;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI AWLEN" *)
input wire [7 : 0] S02_AXI_awlen;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI AWSIZE" *)
input wire [2 : 0] S02_AXI_awsize;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI AWBURST" *)
input wire [1 : 0] S02_AXI_awburst;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI AWLOCK" *)
input wire [0 : 0] S02_AXI_awlock;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI AWCACHE" *)
input wire [3 : 0] S02_AXI_awcache;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI AWPROT" *)
input wire [2 : 0] S02_AXI_awprot;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI AWREGION" *)
input wire [3 : 0] S02_AXI_awregion;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI AWQOS" *)
input wire [3 : 0] S02_AXI_awqos;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI AWVALID" *)
input wire [0 : 0] S02_AXI_awvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI AWREADY" *)
output wire [0 : 0] S02_AXI_awready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI WDATA" *)
input wire [127 : 0] S02_AXI_wdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI WSTRB" *)
input wire [15 : 0] S02_AXI_wstrb;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI WLAST" *)
input wire [0 : 0] S02_AXI_wlast;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI WVALID" *)
input wire [0 : 0] S02_AXI_wvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI WREADY" *)
output wire [0 : 0] S02_AXI_wready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI BRESP" *)
output wire [1 : 0] S02_AXI_bresp;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI BVALID" *)
output wire [0 : 0] S02_AXI_bvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI BREADY" *)
input wire [0 : 0] S02_AXI_bready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI ARADDR" *)
input wire [63 : 0] S02_AXI_araddr;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI ARLEN" *)
input wire [7 : 0] S02_AXI_arlen;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI ARSIZE" *)
input wire [2 : 0] S02_AXI_arsize;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI ARBURST" *)
input wire [1 : 0] S02_AXI_arburst;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI ARLOCK" *)
input wire [0 : 0] S02_AXI_arlock;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI ARCACHE" *)
input wire [3 : 0] S02_AXI_arcache;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI ARPROT" *)
input wire [2 : 0] S02_AXI_arprot;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI ARREGION" *)
input wire [3 : 0] S02_AXI_arregion;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI ARQOS" *)
input wire [3 : 0] S02_AXI_arqos;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI ARVALID" *)
input wire [0 : 0] S02_AXI_arvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI ARREADY" *)
output wire [0 : 0] S02_AXI_arready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI RDATA" *)
output wire [127 : 0] S02_AXI_rdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI RRESP" *)
output wire [1 : 0] S02_AXI_rresp;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI RLAST" *)
output wire [0 : 0] S02_AXI_rlast;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI RVALID" *)
output wire [0 : 0] S02_AXI_rvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI RREADY" *)
input wire [0 : 0] S02_AXI_rready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI AWADDR" *)
input wire [63 : 0] S03_AXI_awaddr;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI AWLEN" *)
input wire [7 : 0] S03_AXI_awlen;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI AWSIZE" *)
input wire [2 : 0] S03_AXI_awsize;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI AWBURST" *)
input wire [1 : 0] S03_AXI_awburst;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI AWLOCK" *)
input wire [0 : 0] S03_AXI_awlock;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI AWCACHE" *)
input wire [3 : 0] S03_AXI_awcache;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI AWPROT" *)
input wire [2 : 0] S03_AXI_awprot;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI AWREGION" *)
input wire [3 : 0] S03_AXI_awregion;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI AWQOS" *)
input wire [3 : 0] S03_AXI_awqos;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI AWVALID" *)
input wire [0 : 0] S03_AXI_awvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI AWREADY" *)
output wire [0 : 0] S03_AXI_awready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI WDATA" *)
input wire [127 : 0] S03_AXI_wdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI WSTRB" *)
input wire [15 : 0] S03_AXI_wstrb;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI WLAST" *)
input wire [0 : 0] S03_AXI_wlast;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI WVALID" *)
input wire [0 : 0] S03_AXI_wvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI WREADY" *)
output wire [0 : 0] S03_AXI_wready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI BRESP" *)
output wire [1 : 0] S03_AXI_bresp;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI BVALID" *)
output wire [0 : 0] S03_AXI_bvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI BREADY" *)
input wire [0 : 0] S03_AXI_bready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI ARADDR" *)
input wire [63 : 0] S03_AXI_araddr;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI ARLEN" *)
input wire [7 : 0] S03_AXI_arlen;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI ARSIZE" *)
input wire [2 : 0] S03_AXI_arsize;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI ARBURST" *)
input wire [1 : 0] S03_AXI_arburst;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI ARLOCK" *)
input wire [0 : 0] S03_AXI_arlock;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI ARCACHE" *)
input wire [3 : 0] S03_AXI_arcache;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI ARPROT" *)
input wire [2 : 0] S03_AXI_arprot;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI ARREGION" *)
input wire [3 : 0] S03_AXI_arregion;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI ARQOS" *)
input wire [3 : 0] S03_AXI_arqos;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI ARVALID" *)
input wire [0 : 0] S03_AXI_arvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI ARREADY" *)
output wire [0 : 0] S03_AXI_arready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI RDATA" *)
output wire [127 : 0] S03_AXI_rdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI RRESP" *)
output wire [1 : 0] S03_AXI_rresp;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI RLAST" *)
output wire [0 : 0] S03_AXI_rlast;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI RVALID" *)
output wire [0 : 0] S03_AXI_rvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI RREADY" *)
input wire [0 : 0] S03_AXI_rready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI AWADDR" *)
input wire [63 : 0] S04_AXI_awaddr;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI AWLEN" *)
input wire [7 : 0] S04_AXI_awlen;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI AWSIZE" *)
input wire [2 : 0] S04_AXI_awsize;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI AWBURST" *)
input wire [1 : 0] S04_AXI_awburst;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI AWLOCK" *)
input wire [0 : 0] S04_AXI_awlock;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI AWCACHE" *)
input wire [3 : 0] S04_AXI_awcache;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI AWPROT" *)
input wire [2 : 0] S04_AXI_awprot;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI AWREGION" *)
input wire [3 : 0] S04_AXI_awregion;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI AWQOS" *)
input wire [3 : 0] S04_AXI_awqos;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI AWVALID" *)
input wire [0 : 0] S04_AXI_awvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI AWREADY" *)
output wire [0 : 0] S04_AXI_awready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI WDATA" *)
input wire [127 : 0] S04_AXI_wdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI WSTRB" *)
input wire [15 : 0] S04_AXI_wstrb;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI WLAST" *)
input wire [0 : 0] S04_AXI_wlast;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI WVALID" *)
input wire [0 : 0] S04_AXI_wvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI WREADY" *)
output wire [0 : 0] S04_AXI_wready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI BRESP" *)
output wire [1 : 0] S04_AXI_bresp;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI BVALID" *)
output wire [0 : 0] S04_AXI_bvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI BREADY" *)
input wire [0 : 0] S04_AXI_bready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI ARADDR" *)
input wire [63 : 0] S04_AXI_araddr;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI ARLEN" *)
input wire [7 : 0] S04_AXI_arlen;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI ARSIZE" *)
input wire [2 : 0] S04_AXI_arsize;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI ARBURST" *)
input wire [1 : 0] S04_AXI_arburst;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI ARLOCK" *)
input wire [0 : 0] S04_AXI_arlock;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI ARCACHE" *)
input wire [3 : 0] S04_AXI_arcache;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI ARPROT" *)
input wire [2 : 0] S04_AXI_arprot;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI ARREGION" *)
input wire [3 : 0] S04_AXI_arregion;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI ARQOS" *)
input wire [3 : 0] S04_AXI_arqos;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI ARVALID" *)
input wire [0 : 0] S04_AXI_arvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI ARREADY" *)
output wire [0 : 0] S04_AXI_arready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI RDATA" *)
output wire [127 : 0] S04_AXI_rdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI RRESP" *)
output wire [1 : 0] S04_AXI_rresp;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI RLAST" *)
output wire [0 : 0] S04_AXI_rlast;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI RVALID" *)
output wire [0 : 0] S04_AXI_rvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI RREADY" *)
input wire [0 : 0] S04_AXI_rready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI AWADDR" *)
input wire [63 : 0] S05_AXI_awaddr;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI AWLEN" *)
input wire [7 : 0] S05_AXI_awlen;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI AWSIZE" *)
input wire [2 : 0] S05_AXI_awsize;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI AWBURST" *)
input wire [1 : 0] S05_AXI_awburst;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI AWLOCK" *)
input wire [0 : 0] S05_AXI_awlock;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI AWCACHE" *)
input wire [3 : 0] S05_AXI_awcache;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI AWPROT" *)
input wire [2 : 0] S05_AXI_awprot;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI AWREGION" *)
input wire [3 : 0] S05_AXI_awregion;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI AWQOS" *)
input wire [3 : 0] S05_AXI_awqos;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI AWVALID" *)
input wire [0 : 0] S05_AXI_awvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI AWREADY" *)
output wire [0 : 0] S05_AXI_awready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI WDATA" *)
input wire [127 : 0] S05_AXI_wdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI WSTRB" *)
input wire [15 : 0] S05_AXI_wstrb;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI WLAST" *)
input wire [0 : 0] S05_AXI_wlast;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI WVALID" *)
input wire [0 : 0] S05_AXI_wvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI WREADY" *)
output wire [0 : 0] S05_AXI_wready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI BRESP" *)
output wire [1 : 0] S05_AXI_bresp;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI BVALID" *)
output wire [0 : 0] S05_AXI_bvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI BREADY" *)
input wire [0 : 0] S05_AXI_bready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI ARADDR" *)
input wire [63 : 0] S05_AXI_araddr;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI ARLEN" *)
input wire [7 : 0] S05_AXI_arlen;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI ARSIZE" *)
input wire [2 : 0] S05_AXI_arsize;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI ARBURST" *)
input wire [1 : 0] S05_AXI_arburst;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI ARLOCK" *)
input wire [0 : 0] S05_AXI_arlock;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI ARCACHE" *)
input wire [3 : 0] S05_AXI_arcache;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI ARPROT" *)
input wire [2 : 0] S05_AXI_arprot;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI ARREGION" *)
input wire [3 : 0] S05_AXI_arregion;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI ARQOS" *)
input wire [3 : 0] S05_AXI_arqos;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI ARVALID" *)
input wire [0 : 0] S05_AXI_arvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI ARREADY" *)
output wire [0 : 0] S05_AXI_arready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI RDATA" *)
output wire [127 : 0] S05_AXI_rdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI RRESP" *)
output wire [1 : 0] S05_AXI_rresp;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI RLAST" *)
output wire [0 : 0] S05_AXI_rlast;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI RVALID" *)
output wire [0 : 0] S05_AXI_rvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI RREADY" *)
input wire [0 : 0] S05_AXI_rready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI AWADDR" *)
input wire [63 : 0] S06_AXI_awaddr;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI AWLEN" *)
input wire [7 : 0] S06_AXI_awlen;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI AWSIZE" *)
input wire [2 : 0] S06_AXI_awsize;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI AWBURST" *)
input wire [1 : 0] S06_AXI_awburst;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI AWLOCK" *)
input wire [0 : 0] S06_AXI_awlock;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI AWCACHE" *)
input wire [3 : 0] S06_AXI_awcache;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI AWPROT" *)
input wire [2 : 0] S06_AXI_awprot;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI AWREGION" *)
input wire [3 : 0] S06_AXI_awregion;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI AWQOS" *)
input wire [3 : 0] S06_AXI_awqos;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI AWVALID" *)
input wire [0 : 0] S06_AXI_awvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI AWREADY" *)
output wire [0 : 0] S06_AXI_awready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI WDATA" *)
input wire [127 : 0] S06_AXI_wdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI WSTRB" *)
input wire [15 : 0] S06_AXI_wstrb;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI WLAST" *)
input wire [0 : 0] S06_AXI_wlast;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI WVALID" *)
input wire [0 : 0] S06_AXI_wvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI WREADY" *)
output wire [0 : 0] S06_AXI_wready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI BRESP" *)
output wire [1 : 0] S06_AXI_bresp;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI BVALID" *)
output wire [0 : 0] S06_AXI_bvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI BREADY" *)
input wire [0 : 0] S06_AXI_bready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI ARADDR" *)
input wire [63 : 0] S06_AXI_araddr;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI ARLEN" *)
input wire [7 : 0] S06_AXI_arlen;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI ARSIZE" *)
input wire [2 : 0] S06_AXI_arsize;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI ARBURST" *)
input wire [1 : 0] S06_AXI_arburst;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI ARLOCK" *)
input wire [0 : 0] S06_AXI_arlock;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI ARCACHE" *)
input wire [3 : 0] S06_AXI_arcache;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI ARPROT" *)
input wire [2 : 0] S06_AXI_arprot;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI ARREGION" *)
input wire [3 : 0] S06_AXI_arregion;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI ARQOS" *)
input wire [3 : 0] S06_AXI_arqos;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI ARVALID" *)
input wire [0 : 0] S06_AXI_arvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI ARREADY" *)
output wire [0 : 0] S06_AXI_arready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI RDATA" *)
output wire [127 : 0] S06_AXI_rdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI RRESP" *)
output wire [1 : 0] S06_AXI_rresp;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI RLAST" *)
output wire [0 : 0] S06_AXI_rlast;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI RVALID" *)
output wire [0 : 0] S06_AXI_rvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI RREADY" *)
input wire [0 : 0] S06_AXI_rready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI AWADDR" *)
input wire [63 : 0] S07_AXI_awaddr;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI AWLEN" *)
input wire [7 : 0] S07_AXI_awlen;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI AWSIZE" *)
input wire [2 : 0] S07_AXI_awsize;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI AWBURST" *)
input wire [1 : 0] S07_AXI_awburst;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI AWLOCK" *)
input wire [0 : 0] S07_AXI_awlock;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI AWCACHE" *)
input wire [3 : 0] S07_AXI_awcache;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI AWPROT" *)
input wire [2 : 0] S07_AXI_awprot;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI AWREGION" *)
input wire [3 : 0] S07_AXI_awregion;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI AWQOS" *)
input wire [3 : 0] S07_AXI_awqos;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI AWVALID" *)
input wire [0 : 0] S07_AXI_awvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI AWREADY" *)
output wire [0 : 0] S07_AXI_awready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI WDATA" *)
input wire [127 : 0] S07_AXI_wdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI WSTRB" *)
input wire [15 : 0] S07_AXI_wstrb;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI WLAST" *)
input wire [0 : 0] S07_AXI_wlast;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI WVALID" *)
input wire [0 : 0] S07_AXI_wvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI WREADY" *)
output wire [0 : 0] S07_AXI_wready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI BRESP" *)
output wire [1 : 0] S07_AXI_bresp;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI BVALID" *)
output wire [0 : 0] S07_AXI_bvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI BREADY" *)
input wire [0 : 0] S07_AXI_bready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI ARADDR" *)
input wire [63 : 0] S07_AXI_araddr;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI ARLEN" *)
input wire [7 : 0] S07_AXI_arlen;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI ARSIZE" *)
input wire [2 : 0] S07_AXI_arsize;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI ARBURST" *)
input wire [1 : 0] S07_AXI_arburst;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI ARLOCK" *)
input wire [0 : 0] S07_AXI_arlock;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI ARCACHE" *)
input wire [3 : 0] S07_AXI_arcache;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI ARPROT" *)
input wire [2 : 0] S07_AXI_arprot;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI ARREGION" *)
input wire [3 : 0] S07_AXI_arregion;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI ARQOS" *)
input wire [3 : 0] S07_AXI_arqos;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI ARVALID" *)
input wire [0 : 0] S07_AXI_arvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI ARREADY" *)
output wire [0 : 0] S07_AXI_arready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI RDATA" *)
output wire [127 : 0] S07_AXI_rdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI RRESP" *)
output wire [1 : 0] S07_AXI_rresp;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI RLAST" *)
output wire [0 : 0] S07_AXI_rlast;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI RVALID" *)
output wire [0 : 0] S07_AXI_rvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI RREADY" *)
input wire [0 : 0] S07_AXI_rready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI AWADDR" *)
output wire [63 : 0] M00_AXI_awaddr;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI AWLEN" *)
output wire [7 : 0] M00_AXI_awlen;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI AWSIZE" *)
output wire [2 : 0] M00_AXI_awsize;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI AWBURST" *)
output wire [1 : 0] M00_AXI_awburst;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI AWLOCK" *)
output wire [0 : 0] M00_AXI_awlock;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI AWCACHE" *)
output wire [3 : 0] M00_AXI_awcache;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI AWPROT" *)
output wire [2 : 0] M00_AXI_awprot;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI AWREGION" *)
output wire [3 : 0] M00_AXI_awregion;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI AWQOS" *)
output wire [3 : 0] M00_AXI_awqos;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI AWVALID" *)
output wire [0 : 0] M00_AXI_awvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI AWREADY" *)
input wire [0 : 0] M00_AXI_awready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI WDATA" *)
output wire [127 : 0] M00_AXI_wdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI WSTRB" *)
output wire [15 : 0] M00_AXI_wstrb;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI WLAST" *)
output wire [0 : 0] M00_AXI_wlast;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI WVALID" *)
output wire [0 : 0] M00_AXI_wvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI WREADY" *)
input wire [0 : 0] M00_AXI_wready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI BRESP" *)
input wire [1 : 0] M00_AXI_bresp;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI BVALID" *)
input wire [0 : 0] M00_AXI_bvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI BREADY" *)
output wire [0 : 0] M00_AXI_bready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI ARADDR" *)
output wire [63 : 0] M00_AXI_araddr;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI ARLEN" *)
output wire [7 : 0] M00_AXI_arlen;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI ARSIZE" *)
output wire [2 : 0] M00_AXI_arsize;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI ARBURST" *)
output wire [1 : 0] M00_AXI_arburst;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI ARLOCK" *)
output wire [0 : 0] M00_AXI_arlock;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI ARCACHE" *)
output wire [3 : 0] M00_AXI_arcache;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI ARPROT" *)
output wire [2 : 0] M00_AXI_arprot;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI ARREGION" *)
output wire [3 : 0] M00_AXI_arregion;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI ARQOS" *)
output wire [3 : 0] M00_AXI_arqos;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI ARVALID" *)
output wire [0 : 0] M00_AXI_arvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI ARREADY" *)
input wire [0 : 0] M00_AXI_arready;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI RDATA" *)
input wire [127 : 0] M00_AXI_rdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI RRESP" *)
input wire [1 : 0] M00_AXI_rresp;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI RLAST" *)
input wire [0 : 0] M00_AXI_rlast;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI RVALID" *)
input wire [0 : 0] M00_AXI_rvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI RREADY" *)
output wire [0 : 0] M00_AXI_rready;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME M00_INI, ADDR_WIDTH 64, INI_STRATEGY auto, COMPUTED_STRATEGY load, WRITE_BUFFER_SIZE 80, NOC_ID -1, MY_CATEGORY pl" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:inimm:1.0 M00_INI INTERNOC" *)
output wire [0 : 0] M00_INI_internoc;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME M01_INI, ADDR_WIDTH 64, INI_STRATEGY auto, COMPUTED_STRATEGY load, WRITE_BUFFER_SIZE 80, NOC_ID -1, MY_CATEGORY pl" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:inimm:1.0 M01_INI INTERNOC" *)
output wire [0 : 0] M01_INI_internoc;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME M02_INI, ADDR_WIDTH 64, INI_STRATEGY auto, COMPUTED_STRATEGY load, WRITE_BUFFER_SIZE 80, NOC_ID -1, MY_CATEGORY pl" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:inimm:1.0 M02_INI INTERNOC" *)
output wire [0 : 0] M02_INI_internoc;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME M03_INI, ADDR_WIDTH 64, INI_STRATEGY auto, COMPUTED_STRATEGY load, WRITE_BUFFER_SIZE 80, NOC_ID -1, MY_CATEGORY pl" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:inimm:1.0 M03_INI INTERNOC" *)
output wire [0 : 0] M03_INI_internoc;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME M04_INI, ADDR_WIDTH 64, INI_STRATEGY auto, COMPUTED_STRATEGY load, WRITE_BUFFER_SIZE 80, NOC_ID -1, MY_CATEGORY pl" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:inimm:1.0 M04_INI INTERNOC" *)
output wire [0 : 0] M04_INI_internoc;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME M05_INI, ADDR_WIDTH 64, INI_STRATEGY auto, COMPUTED_STRATEGY load, WRITE_BUFFER_SIZE 80, NOC_ID -1, MY_CATEGORY pl" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:inimm:1.0 M05_INI INTERNOC" *)
output wire [0 : 0] M05_INI_internoc;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME M06_INI, ADDR_WIDTH 64, INI_STRATEGY auto, COMPUTED_STRATEGY load, WRITE_BUFFER_SIZE 80, NOC_ID -1, MY_CATEGORY pl" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:inimm:1.0 M06_INI INTERNOC" *)
output wire [0 : 0] M06_INI_internoc;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME M07_INI, ADDR_WIDTH 64, INI_STRATEGY auto, COMPUTED_STRATEGY load, WRITE_BUFFER_SIZE 80, NOC_ID -1, MY_CATEGORY pl" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:inimm:1.0 M07_INI INTERNOC" *)
output wire [0 : 0] M07_INI_internoc;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.aclk0, FREQ_HZ 104166666, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN /clk_wizard_0_clk_out1, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.aclk0 CLK" *)
input wire aclk0;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.aclk1, FREQ_HZ 824999939, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN bd_57a1_pspmc_0_0_fpd_cci_noc_axi0_clk, ASSOCIATED_BUSIF S00_AXI, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.aclk1 CLK" *)
input wire aclk1;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.aclk2, FREQ_HZ 824999939, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN bd_57a1_pspmc_0_0_fpd_cci_noc_axi1_clk, ASSOCIATED_BUSIF S01_AXI, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.aclk2 CLK" *)
input wire aclk2;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.aclk3, FREQ_HZ 824999939, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN bd_57a1_pspmc_0_0_fpd_cci_noc_axi2_clk, ASSOCIATED_BUSIF S02_AXI, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.aclk3 CLK" *)
input wire aclk3;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.aclk4, FREQ_HZ 824999939, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN bd_57a1_pspmc_0_0_fpd_cci_noc_axi3_clk, ASSOCIATED_BUSIF S03_AXI, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.aclk4 CLK" *)
input wire aclk4;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.aclk5, FREQ_HZ 824999939, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN bd_57a1_pspmc_0_0_fpd_axi_noc_axi0_clk, ASSOCIATED_BUSIF S04_AXI, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.aclk5 CLK" *)
input wire aclk5;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.aclk6, FREQ_HZ 824999939, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN bd_57a1_pspmc_0_0_fpd_axi_noc_axi1_clk, ASSOCIATED_BUSIF S05_AXI, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.aclk6 CLK" *)
input wire aclk6;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.aclk7, FREQ_HZ 600000000, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN bd_57a1_pspmc_0_0_lpd_axi_noc_clk, ASSOCIATED_BUSIF S06_AXI, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.aclk7 CLK" *)
input wire aclk7;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.aclk8, FREQ_HZ 400000000, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN bd_57a1_pspmc_0_0_pmc_axi_noc_axi0_clk, ASSOCIATED_BUSIF S07_AXI, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.aclk8 CLK" *)
input wire aclk8;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.aclk9, FREQ_HZ 1250000000, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN bd_05a5_noc_ai_mm_0_0_s_axi_aclk, ASSOCIATED_BUSIF M00_AXI, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.aclk9 CLK" *)
input wire aclk9;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI ARID" *)
input wire [15 : 0] S07_AXI_arid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI ARUSER" *)
input wire [17 : 0] S07_AXI_aruser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI AWID" *)
input wire [15 : 0] S07_AXI_awid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI AWUSER" *)
input wire [17 : 0] S07_AXI_awuser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI BID" *)
output wire [15 : 0] S07_AXI_bid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI BUSER" *)
output wire [15 : 0] S07_AXI_buser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI RID" *)
output wire [15 : 0] S07_AXI_rid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI RUSER" *)
output wire [16 : 0] S07_AXI_ruser;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S07_AXI, DATA_WIDTH 128, PROTOCOL AXI4, FREQ_HZ 400000000, ID_WIDTH 16, ADDR_WIDTH 64, AWUSER_WIDTH 18, ARUSER_WIDTH 18, WUSER_WIDTH 17, RUSER_WIDTH 17, BUSER_WIDTH 16, READ_WRITE_MODE READ_WRITE, HAS_BURST 1, HAS_LOCK 1, HAS_PROT 1, HAS_CACHE 1, HAS_QOS 1, HAS_REGION 1, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, SUPPORTS_NARROW_BURST 1, NUM_READ_OUTSTANDING 64, NUM_WRITE_OUTSTANDING 64, MAX_BURST_LENGTH 256, PHASE 0.0, CLK_DOMAIN bd_57a1_pspmc_0_0_pmc_axi_noc_axi0_clk, NUM_READ_TH\
READS 1, NUM_WRITE_THREADS 1, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0, INSERT_VIP 0, R_TRAFFIC_CLASS BEST_EFFORT, W_TRAFFIC_CLASS BEST_EFFORT, R_LATENCY 300, R_RATE_LIMITER 10, W_RATE_LIMITER 10, R_MAX_BURST_LENGTH 256, W_MAX_BURST_LENGTH 256, CONNECTIONS  M00_INI { read_bw {5} write_bw {5}} M04_INI { read_bw {5} write_bw {5}} M00_AXI { read_bw {5} write_bw {5} read_avg_burst {4} write_avg_burst {4}}, DEST_IDS M00_AXI:0x0, WRITE_BUFFER_SIZE 80, MY_CATEGORY noc, CATEGORY ps_pmc" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S07_AXI WUSER" *)
input wire [16 : 0] S07_AXI_wuser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI ARID" *)
input wire [15 : 0] S06_AXI_arid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI ARUSER" *)
input wire [17 : 0] S06_AXI_aruser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI AWID" *)
input wire [15 : 0] S06_AXI_awid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI AWUSER" *)
input wire [17 : 0] S06_AXI_awuser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI BID" *)
output wire [15 : 0] S06_AXI_bid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI RID" *)
output wire [15 : 0] S06_AXI_rid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI RUSER" *)
output wire [16 : 0] S06_AXI_ruser;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S06_AXI, DATA_WIDTH 128, PROTOCOL AXI4, FREQ_HZ 600000000, ID_WIDTH 16, ADDR_WIDTH 64, AWUSER_WIDTH 18, ARUSER_WIDTH 18, WUSER_WIDTH 17, RUSER_WIDTH 17, BUSER_WIDTH 0, READ_WRITE_MODE READ_WRITE, HAS_BURST 1, HAS_LOCK 1, HAS_PROT 1, HAS_CACHE 1, HAS_QOS 1, HAS_REGION 0, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, SUPPORTS_NARROW_BURST 1, NUM_READ_OUTSTANDING 64, NUM_WRITE_OUTSTANDING 64, MAX_BURST_LENGTH 256, PHASE 0.0, CLK_DOMAIN bd_57a1_pspmc_0_0_lpd_axi_noc_clk, NUM_READ_THREADS \
1, NUM_WRITE_THREADS 1, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0, INSERT_VIP 0, R_TRAFFIC_CLASS BEST_EFFORT, W_TRAFFIC_CLASS BEST_EFFORT, R_LATENCY 300, R_RATE_LIMITER 10, W_RATE_LIMITER 10, R_MAX_BURST_LENGTH 256, W_MAX_BURST_LENGTH 256, CONNECTIONS  M00_INI { read_bw {5} write_bw {5}} , WRITE_BUFFER_SIZE 80, MY_CATEGORY noc, CATEGORY ps_rpu" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S06_AXI WUSER" *)
input wire [16 : 0] S06_AXI_wuser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI ARID" *)
input wire [15 : 0] S01_AXI_arid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI ARUSER" *)
input wire [17 : 0] S01_AXI_aruser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI AWID" *)
input wire [15 : 0] S01_AXI_awid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI AWUSER" *)
input wire [17 : 0] S01_AXI_awuser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI BID" *)
output wire [15 : 0] S01_AXI_bid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI RID" *)
output wire [15 : 0] S01_AXI_rid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI RUSER" *)
output wire [16 : 0] S01_AXI_ruser;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S01_AXI, DATA_WIDTH 128, PROTOCOL AXI4, FREQ_HZ 824999939, ID_WIDTH 16, ADDR_WIDTH 64, AWUSER_WIDTH 18, ARUSER_WIDTH 18, WUSER_WIDTH 17, RUSER_WIDTH 17, BUSER_WIDTH 0, READ_WRITE_MODE READ_WRITE, HAS_BURST 1, HAS_LOCK 1, HAS_PROT 1, HAS_CACHE 1, HAS_QOS 1, HAS_REGION 0, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, SUPPORTS_NARROW_BURST 1, NUM_READ_OUTSTANDING 64, NUM_WRITE_OUTSTANDING 64, MAX_BURST_LENGTH 256, PHASE 0.0, CLK_DOMAIN bd_57a1_pspmc_0_0_fpd_cci_noc_axi1_clk, NUM_READ_THR\
EADS 1, NUM_WRITE_THREADS 1, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0, INSERT_VIP 0, R_TRAFFIC_CLASS BEST_EFFORT, W_TRAFFIC_CLASS BEST_EFFORT, R_LATENCY 300, R_RATE_LIMITER 10, W_RATE_LIMITER 10, R_MAX_BURST_LENGTH 256, W_MAX_BURST_LENGTH 256, CONNECTIONS  M01_INI { read_bw {128} write_bw {128}} M05_INI { read_bw {128} write_bw {128}} M00_AXI { read_bw {5} write_bw {5} read_avg_burst {4} write_avg_burst {4}}, DEST_IDS M00_AXI:0x0, WRITE_BUFFER_SIZE 80, MY_CATEGORY noc, CATEGORY ps_cci" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S01_AXI WUSER" *)
input wire [16 : 0] S01_AXI_wuser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI ARID" *)
input wire [15 : 0] S03_AXI_arid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI ARUSER" *)
input wire [17 : 0] S03_AXI_aruser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI AWID" *)
input wire [15 : 0] S03_AXI_awid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI AWUSER" *)
input wire [17 : 0] S03_AXI_awuser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI BID" *)
output wire [15 : 0] S03_AXI_bid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI RID" *)
output wire [15 : 0] S03_AXI_rid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI RUSER" *)
output wire [16 : 0] S03_AXI_ruser;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S03_AXI, DATA_WIDTH 128, PROTOCOL AXI4, FREQ_HZ 824999939, ID_WIDTH 16, ADDR_WIDTH 64, AWUSER_WIDTH 18, ARUSER_WIDTH 18, WUSER_WIDTH 17, RUSER_WIDTH 17, BUSER_WIDTH 0, READ_WRITE_MODE READ_WRITE, HAS_BURST 1, HAS_LOCK 1, HAS_PROT 1, HAS_CACHE 1, HAS_QOS 1, HAS_REGION 0, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, SUPPORTS_NARROW_BURST 1, NUM_READ_OUTSTANDING 64, NUM_WRITE_OUTSTANDING 64, MAX_BURST_LENGTH 256, PHASE 0.0, CLK_DOMAIN bd_57a1_pspmc_0_0_fpd_cci_noc_axi3_clk, NUM_READ_THR\
EADS 1, NUM_WRITE_THREADS 1, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0, INSERT_VIP 0, R_TRAFFIC_CLASS BEST_EFFORT, W_TRAFFIC_CLASS BEST_EFFORT, R_LATENCY 300, R_RATE_LIMITER 10, W_RATE_LIMITER 10, R_MAX_BURST_LENGTH 256, W_MAX_BURST_LENGTH 256, CONNECTIONS  M07_INI { read_bw {128} write_bw {128}} M03_INI { read_bw {128} write_bw {128}} M00_AXI { read_bw {5} write_bw {5} read_avg_burst {4} write_avg_burst {4}} , DEST_IDS M00_AXI:0x0, WRITE_BUFFER_SIZE 80, MY_CATEGORY noc, CATEGORY ps_cci" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S03_AXI WUSER" *)
input wire [16 : 0] S03_AXI_wuser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI ARID" *)
input wire [15 : 0] S05_AXI_arid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI ARUSER" *)
input wire [17 : 0] S05_AXI_aruser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI AWID" *)
input wire [15 : 0] S05_AXI_awid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI AWUSER" *)
input wire [17 : 0] S05_AXI_awuser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI BID" *)
output wire [15 : 0] S05_AXI_bid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI RID" *)
output wire [15 : 0] S05_AXI_rid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI RUSER" *)
output wire [16 : 0] S05_AXI_ruser;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S05_AXI, DATA_WIDTH 128, PROTOCOL AXI4, FREQ_HZ 824999939, ID_WIDTH 16, ADDR_WIDTH 64, AWUSER_WIDTH 18, ARUSER_WIDTH 18, WUSER_WIDTH 17, RUSER_WIDTH 17, BUSER_WIDTH 0, READ_WRITE_MODE READ_WRITE, HAS_BURST 1, HAS_LOCK 1, HAS_PROT 1, HAS_CACHE 1, HAS_QOS 1, HAS_REGION 0, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, SUPPORTS_NARROW_BURST 1, NUM_READ_OUTSTANDING 64, NUM_WRITE_OUTSTANDING 64, MAX_BURST_LENGTH 256, PHASE 0.0, CLK_DOMAIN bd_57a1_pspmc_0_0_fpd_axi_noc_axi1_clk, NUM_READ_THR\
EADS 1, NUM_WRITE_THREADS 1, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0, INSERT_VIP 0, R_TRAFFIC_CLASS BEST_EFFORT, W_TRAFFIC_CLASS BEST_EFFORT, R_LATENCY 300, R_RATE_LIMITER 10, W_RATE_LIMITER 10, R_MAX_BURST_LENGTH 256, W_MAX_BURST_LENGTH 256, CONNECTIONS  M00_INI { read_bw {5} write_bw {5}} , WRITE_BUFFER_SIZE 80, MY_CATEGORY noc, CATEGORY ps_nci" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S05_AXI WUSER" *)
input wire [16 : 0] S05_AXI_wuser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI ARID" *)
input wire [15 : 0] S00_AXI_arid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI ARUSER" *)
input wire [17 : 0] S00_AXI_aruser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI AWID" *)
input wire [15 : 0] S00_AXI_awid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI AWUSER" *)
input wire [17 : 0] S00_AXI_awuser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI BID" *)
output wire [15 : 0] S00_AXI_bid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI RID" *)
output wire [15 : 0] S00_AXI_rid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI RUSER" *)
output wire [16 : 0] S00_AXI_ruser;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S00_AXI, DATA_WIDTH 128, PROTOCOL AXI4, FREQ_HZ 824999939, ID_WIDTH 16, ADDR_WIDTH 64, AWUSER_WIDTH 18, ARUSER_WIDTH 18, WUSER_WIDTH 17, RUSER_WIDTH 17, BUSER_WIDTH 0, READ_WRITE_MODE READ_WRITE, HAS_BURST 1, HAS_LOCK 1, HAS_PROT 1, HAS_CACHE 1, HAS_QOS 1, HAS_REGION 0, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, SUPPORTS_NARROW_BURST 1, NUM_READ_OUTSTANDING 64, NUM_WRITE_OUTSTANDING 64, MAX_BURST_LENGTH 256, PHASE 0.0, CLK_DOMAIN bd_57a1_pspmc_0_0_fpd_cci_noc_axi0_clk, NUM_READ_THR\
EADS 1, NUM_WRITE_THREADS 1, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0, INSERT_VIP 0, R_TRAFFIC_CLASS BEST_EFFORT, W_TRAFFIC_CLASS BEST_EFFORT, R_LATENCY 300, R_RATE_LIMITER 10, W_RATE_LIMITER 10, R_MAX_BURST_LENGTH 256, W_MAX_BURST_LENGTH 256, CONNECTIONS  M04_INI { read_bw {128} write_bw {128}} M00_INI { read_bw {128} write_bw {128}} M00_AXI { read_bw {5} write_bw {5} read_avg_burst {4} write_avg_burst {4}} , DEST_IDS M00_AXI:0x0, WRITE_BUFFER_SIZE 80, MY_CATEGORY noc, CATEGORY ps_cci" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S00_AXI WUSER" *)
input wire [16 : 0] S00_AXI_wuser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI ARID" *)
input wire [15 : 0] S02_AXI_arid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI ARUSER" *)
input wire [17 : 0] S02_AXI_aruser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI AWID" *)
input wire [15 : 0] S02_AXI_awid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI AWUSER" *)
input wire [17 : 0] S02_AXI_awuser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI BID" *)
output wire [15 : 0] S02_AXI_bid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI RID" *)
output wire [15 : 0] S02_AXI_rid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI RUSER" *)
output wire [16 : 0] S02_AXI_ruser;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S02_AXI, DATA_WIDTH 128, PROTOCOL AXI4, FREQ_HZ 824999939, ID_WIDTH 16, ADDR_WIDTH 64, AWUSER_WIDTH 18, ARUSER_WIDTH 18, WUSER_WIDTH 17, RUSER_WIDTH 17, BUSER_WIDTH 0, READ_WRITE_MODE READ_WRITE, HAS_BURST 1, HAS_LOCK 1, HAS_PROT 1, HAS_CACHE 1, HAS_QOS 1, HAS_REGION 0, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, SUPPORTS_NARROW_BURST 1, NUM_READ_OUTSTANDING 64, NUM_WRITE_OUTSTANDING 64, MAX_BURST_LENGTH 256, PHASE 0.0, CLK_DOMAIN bd_57a1_pspmc_0_0_fpd_cci_noc_axi2_clk, NUM_READ_THR\
EADS 1, NUM_WRITE_THREADS 1, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0, INSERT_VIP 0, R_TRAFFIC_CLASS BEST_EFFORT, W_TRAFFIC_CLASS BEST_EFFORT, R_LATENCY 300, R_RATE_LIMITER 10, W_RATE_LIMITER 10, R_MAX_BURST_LENGTH 256, W_MAX_BURST_LENGTH 256, CONNECTIONS  M02_INI { read_bw {128} write_bw {128}} M06_INI { read_bw {128} write_bw {128}} M00_AXI { read_bw {5} write_bw {5} read_avg_burst {4} write_avg_burst {4}}, DEST_IDS M00_AXI:0x0, WRITE_BUFFER_SIZE 80, MY_CATEGORY noc, CATEGORY ps_cci" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S02_AXI WUSER" *)
input wire [16 : 0] S02_AXI_wuser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI ARID" *)
input wire [15 : 0] S04_AXI_arid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI ARUSER" *)
input wire [17 : 0] S04_AXI_aruser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI AWID" *)
input wire [15 : 0] S04_AXI_awid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI AWUSER" *)
input wire [17 : 0] S04_AXI_awuser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI BID" *)
output wire [15 : 0] S04_AXI_bid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI RID" *)
output wire [15 : 0] S04_AXI_rid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI RUSER" *)
output wire [16 : 0] S04_AXI_ruser;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S04_AXI, DATA_WIDTH 128, PROTOCOL AXI4, FREQ_HZ 824999939, ID_WIDTH 16, ADDR_WIDTH 64, AWUSER_WIDTH 18, ARUSER_WIDTH 18, WUSER_WIDTH 17, RUSER_WIDTH 17, BUSER_WIDTH 0, READ_WRITE_MODE READ_WRITE, HAS_BURST 1, HAS_LOCK 1, HAS_PROT 1, HAS_CACHE 1, HAS_QOS 1, HAS_REGION 0, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, SUPPORTS_NARROW_BURST 1, NUM_READ_OUTSTANDING 64, NUM_WRITE_OUTSTANDING 64, MAX_BURST_LENGTH 256, PHASE 0.0, CLK_DOMAIN bd_57a1_pspmc_0_0_fpd_axi_noc_axi0_clk, NUM_READ_THR\
EADS 1, NUM_WRITE_THREADS 1, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0, INSERT_VIP 0, R_TRAFFIC_CLASS BEST_EFFORT, W_TRAFFIC_CLASS BEST_EFFORT, R_LATENCY 300, R_RATE_LIMITER 10, W_RATE_LIMITER 10, R_MAX_BURST_LENGTH 256, W_MAX_BURST_LENGTH 256, CONNECTIONS  M00_INI { read_bw {5} write_bw {5}} , WRITE_BUFFER_SIZE 80, MY_CATEGORY noc, CATEGORY ps_nci" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S04_AXI WUSER" *)
input wire [16 : 0] S04_AXI_wuser;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI ARID" *)
output wire [1 : 0] M00_AXI_arid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI AWID" *)
output wire [1 : 0] M00_AXI_awid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI BID" *)
input wire [1 : 0] M00_AXI_bid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI RID" *)
input wire [1 : 0] M00_AXI_rid;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI RUSER" *)
input wire [16 : 0] M00_AXI_ruser;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME M00_AXI, DATA_WIDTH 128, PROTOCOL AXI4, FREQ_HZ 1250000000, ID_WIDTH 2, ADDR_WIDTH 64, AWUSER_WIDTH 0, ARUSER_WIDTH 0, WUSER_WIDTH 17, RUSER_WIDTH 17, BUSER_WIDTH 0, READ_WRITE_MODE READ_WRITE, HAS_BURST 1, HAS_LOCK 1, HAS_PROT 1, HAS_CACHE 1, HAS_QOS 1, HAS_REGION 1, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, SUPPORTS_NARROW_BURST 1, NUM_READ_OUTSTANDING 32, NUM_WRITE_OUTSTANDING 32, MAX_BURST_LENGTH 256, PHASE 0.0, CLK_DOMAIN bd_05a5_noc_ai_mm_0_0_s_axi_aclk, NUM_READ_THREADS 4, \
NUM_WRITE_THREADS 4, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0, INSERT_VIP 0, REGION 768, WRITE_BUFFER_SIZE 80, NOC_ID -1, MY_CATEGORY noc, CATEGORY aie" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M00_AXI WUSER" *)
output wire [16 : 0] M00_AXI_wuser;

  bd_27ec inst (
    .S00_AXI_awaddr(S00_AXI_awaddr),
    .S00_AXI_awlen(S00_AXI_awlen),
    .S00_AXI_awsize(S00_AXI_awsize),
    .S00_AXI_awburst(S00_AXI_awburst),
    .S00_AXI_awlock(S00_AXI_awlock),
    .S00_AXI_awcache(S00_AXI_awcache),
    .S00_AXI_awprot(S00_AXI_awprot),
    .S00_AXI_awregion(S00_AXI_awregion),
    .S00_AXI_awqos(S00_AXI_awqos),
    .S00_AXI_awvalid(S00_AXI_awvalid),
    .S00_AXI_awready(S00_AXI_awready),
    .S00_AXI_wdata(S00_AXI_wdata),
    .S00_AXI_wstrb(S00_AXI_wstrb),
    .S00_AXI_wlast(S00_AXI_wlast),
    .S00_AXI_wvalid(S00_AXI_wvalid),
    .S00_AXI_wready(S00_AXI_wready),
    .S00_AXI_bresp(S00_AXI_bresp),
    .S00_AXI_bvalid(S00_AXI_bvalid),
    .S00_AXI_bready(S00_AXI_bready),
    .S00_AXI_araddr(S00_AXI_araddr),
    .S00_AXI_arlen(S00_AXI_arlen),
    .S00_AXI_arsize(S00_AXI_arsize),
    .S00_AXI_arburst(S00_AXI_arburst),
    .S00_AXI_arlock(S00_AXI_arlock),
    .S00_AXI_arcache(S00_AXI_arcache),
    .S00_AXI_arprot(S00_AXI_arprot),
    .S00_AXI_arregion(S00_AXI_arregion),
    .S00_AXI_arqos(S00_AXI_arqos),
    .S00_AXI_arvalid(S00_AXI_arvalid),
    .S00_AXI_arready(S00_AXI_arready),
    .S00_AXI_rdata(S00_AXI_rdata),
    .S00_AXI_rresp(S00_AXI_rresp),
    .S00_AXI_rlast(S00_AXI_rlast),
    .S00_AXI_rvalid(S00_AXI_rvalid),
    .S00_AXI_rready(S00_AXI_rready),
    .S01_AXI_awaddr(S01_AXI_awaddr),
    .S01_AXI_awlen(S01_AXI_awlen),
    .S01_AXI_awsize(S01_AXI_awsize),
    .S01_AXI_awburst(S01_AXI_awburst),
    .S01_AXI_awlock(S01_AXI_awlock),
    .S01_AXI_awcache(S01_AXI_awcache),
    .S01_AXI_awprot(S01_AXI_awprot),
    .S01_AXI_awregion(S01_AXI_awregion),
    .S01_AXI_awqos(S01_AXI_awqos),
    .S01_AXI_awvalid(S01_AXI_awvalid),
    .S01_AXI_awready(S01_AXI_awready),
    .S01_AXI_wdata(S01_AXI_wdata),
    .S01_AXI_wstrb(S01_AXI_wstrb),
    .S01_AXI_wlast(S01_AXI_wlast),
    .S01_AXI_wvalid(S01_AXI_wvalid),
    .S01_AXI_wready(S01_AXI_wready),
    .S01_AXI_bresp(S01_AXI_bresp),
    .S01_AXI_bvalid(S01_AXI_bvalid),
    .S01_AXI_bready(S01_AXI_bready),
    .S01_AXI_araddr(S01_AXI_araddr),
    .S01_AXI_arlen(S01_AXI_arlen),
    .S01_AXI_arsize(S01_AXI_arsize),
    .S01_AXI_arburst(S01_AXI_arburst),
    .S01_AXI_arlock(S01_AXI_arlock),
    .S01_AXI_arcache(S01_AXI_arcache),
    .S01_AXI_arprot(S01_AXI_arprot),
    .S01_AXI_arregion(S01_AXI_arregion),
    .S01_AXI_arqos(S01_AXI_arqos),
    .S01_AXI_arvalid(S01_AXI_arvalid),
    .S01_AXI_arready(S01_AXI_arready),
    .S01_AXI_rdata(S01_AXI_rdata),
    .S01_AXI_rresp(S01_AXI_rresp),
    .S01_AXI_rlast(S01_AXI_rlast),
    .S01_AXI_rvalid(S01_AXI_rvalid),
    .S01_AXI_rready(S01_AXI_rready),
    .S02_AXI_awaddr(S02_AXI_awaddr),
    .S02_AXI_awlen(S02_AXI_awlen),
    .S02_AXI_awsize(S02_AXI_awsize),
    .S02_AXI_awburst(S02_AXI_awburst),
    .S02_AXI_awlock(S02_AXI_awlock),
    .S02_AXI_awcache(S02_AXI_awcache),
    .S02_AXI_awprot(S02_AXI_awprot),
    .S02_AXI_awregion(S02_AXI_awregion),
    .S02_AXI_awqos(S02_AXI_awqos),
    .S02_AXI_awvalid(S02_AXI_awvalid),
    .S02_AXI_awready(S02_AXI_awready),
    .S02_AXI_wdata(S02_AXI_wdata),
    .S02_AXI_wstrb(S02_AXI_wstrb),
    .S02_AXI_wlast(S02_AXI_wlast),
    .S02_AXI_wvalid(S02_AXI_wvalid),
    .S02_AXI_wready(S02_AXI_wready),
    .S02_AXI_bresp(S02_AXI_bresp),
    .S02_AXI_bvalid(S02_AXI_bvalid),
    .S02_AXI_bready(S02_AXI_bready),
    .S02_AXI_araddr(S02_AXI_araddr),
    .S02_AXI_arlen(S02_AXI_arlen),
    .S02_AXI_arsize(S02_AXI_arsize),
    .S02_AXI_arburst(S02_AXI_arburst),
    .S02_AXI_arlock(S02_AXI_arlock),
    .S02_AXI_arcache(S02_AXI_arcache),
    .S02_AXI_arprot(S02_AXI_arprot),
    .S02_AXI_arregion(S02_AXI_arregion),
    .S02_AXI_arqos(S02_AXI_arqos),
    .S02_AXI_arvalid(S02_AXI_arvalid),
    .S02_AXI_arready(S02_AXI_arready),
    .S02_AXI_rdata(S02_AXI_rdata),
    .S02_AXI_rresp(S02_AXI_rresp),
    .S02_AXI_rlast(S02_AXI_rlast),
    .S02_AXI_rvalid(S02_AXI_rvalid),
    .S02_AXI_rready(S02_AXI_rready),
    .S03_AXI_awaddr(S03_AXI_awaddr),
    .S03_AXI_awlen(S03_AXI_awlen),
    .S03_AXI_awsize(S03_AXI_awsize),
    .S03_AXI_awburst(S03_AXI_awburst),
    .S03_AXI_awlock(S03_AXI_awlock),
    .S03_AXI_awcache(S03_AXI_awcache),
    .S03_AXI_awprot(S03_AXI_awprot),
    .S03_AXI_awregion(S03_AXI_awregion),
    .S03_AXI_awqos(S03_AXI_awqos),
    .S03_AXI_awvalid(S03_AXI_awvalid),
    .S03_AXI_awready(S03_AXI_awready),
    .S03_AXI_wdata(S03_AXI_wdata),
    .S03_AXI_wstrb(S03_AXI_wstrb),
    .S03_AXI_wlast(S03_AXI_wlast),
    .S03_AXI_wvalid(S03_AXI_wvalid),
    .S03_AXI_wready(S03_AXI_wready),
    .S03_AXI_bresp(S03_AXI_bresp),
    .S03_AXI_bvalid(S03_AXI_bvalid),
    .S03_AXI_bready(S03_AXI_bready),
    .S03_AXI_araddr(S03_AXI_araddr),
    .S03_AXI_arlen(S03_AXI_arlen),
    .S03_AXI_arsize(S03_AXI_arsize),
    .S03_AXI_arburst(S03_AXI_arburst),
    .S03_AXI_arlock(S03_AXI_arlock),
    .S03_AXI_arcache(S03_AXI_arcache),
    .S03_AXI_arprot(S03_AXI_arprot),
    .S03_AXI_arregion(S03_AXI_arregion),
    .S03_AXI_arqos(S03_AXI_arqos),
    .S03_AXI_arvalid(S03_AXI_arvalid),
    .S03_AXI_arready(S03_AXI_arready),
    .S03_AXI_rdata(S03_AXI_rdata),
    .S03_AXI_rresp(S03_AXI_rresp),
    .S03_AXI_rlast(S03_AXI_rlast),
    .S03_AXI_rvalid(S03_AXI_rvalid),
    .S03_AXI_rready(S03_AXI_rready),
    .S04_AXI_awaddr(S04_AXI_awaddr),
    .S04_AXI_awlen(S04_AXI_awlen),
    .S04_AXI_awsize(S04_AXI_awsize),
    .S04_AXI_awburst(S04_AXI_awburst),
    .S04_AXI_awlock(S04_AXI_awlock),
    .S04_AXI_awcache(S04_AXI_awcache),
    .S04_AXI_awprot(S04_AXI_awprot),
    .S04_AXI_awregion(S04_AXI_awregion),
    .S04_AXI_awqos(S04_AXI_awqos),
    .S04_AXI_awvalid(S04_AXI_awvalid),
    .S04_AXI_awready(S04_AXI_awready),
    .S04_AXI_wdata(S04_AXI_wdata),
    .S04_AXI_wstrb(S04_AXI_wstrb),
    .S04_AXI_wlast(S04_AXI_wlast),
    .S04_AXI_wvalid(S04_AXI_wvalid),
    .S04_AXI_wready(S04_AXI_wready),
    .S04_AXI_bresp(S04_AXI_bresp),
    .S04_AXI_bvalid(S04_AXI_bvalid),
    .S04_AXI_bready(S04_AXI_bready),
    .S04_AXI_araddr(S04_AXI_araddr),
    .S04_AXI_arlen(S04_AXI_arlen),
    .S04_AXI_arsize(S04_AXI_arsize),
    .S04_AXI_arburst(S04_AXI_arburst),
    .S04_AXI_arlock(S04_AXI_arlock),
    .S04_AXI_arcache(S04_AXI_arcache),
    .S04_AXI_arprot(S04_AXI_arprot),
    .S04_AXI_arregion(S04_AXI_arregion),
    .S04_AXI_arqos(S04_AXI_arqos),
    .S04_AXI_arvalid(S04_AXI_arvalid),
    .S04_AXI_arready(S04_AXI_arready),
    .S04_AXI_rdata(S04_AXI_rdata),
    .S04_AXI_rresp(S04_AXI_rresp),
    .S04_AXI_rlast(S04_AXI_rlast),
    .S04_AXI_rvalid(S04_AXI_rvalid),
    .S04_AXI_rready(S04_AXI_rready),
    .S05_AXI_awaddr(S05_AXI_awaddr),
    .S05_AXI_awlen(S05_AXI_awlen),
    .S05_AXI_awsize(S05_AXI_awsize),
    .S05_AXI_awburst(S05_AXI_awburst),
    .S05_AXI_awlock(S05_AXI_awlock),
    .S05_AXI_awcache(S05_AXI_awcache),
    .S05_AXI_awprot(S05_AXI_awprot),
    .S05_AXI_awregion(S05_AXI_awregion),
    .S05_AXI_awqos(S05_AXI_awqos),
    .S05_AXI_awvalid(S05_AXI_awvalid),
    .S05_AXI_awready(S05_AXI_awready),
    .S05_AXI_wdata(S05_AXI_wdata),
    .S05_AXI_wstrb(S05_AXI_wstrb),
    .S05_AXI_wlast(S05_AXI_wlast),
    .S05_AXI_wvalid(S05_AXI_wvalid),
    .S05_AXI_wready(S05_AXI_wready),
    .S05_AXI_bresp(S05_AXI_bresp),
    .S05_AXI_bvalid(S05_AXI_bvalid),
    .S05_AXI_bready(S05_AXI_bready),
    .S05_AXI_araddr(S05_AXI_araddr),
    .S05_AXI_arlen(S05_AXI_arlen),
    .S05_AXI_arsize(S05_AXI_arsize),
    .S05_AXI_arburst(S05_AXI_arburst),
    .S05_AXI_arlock(S05_AXI_arlock),
    .S05_AXI_arcache(S05_AXI_arcache),
    .S05_AXI_arprot(S05_AXI_arprot),
    .S05_AXI_arregion(S05_AXI_arregion),
    .S05_AXI_arqos(S05_AXI_arqos),
    .S05_AXI_arvalid(S05_AXI_arvalid),
    .S05_AXI_arready(S05_AXI_arready),
    .S05_AXI_rdata(S05_AXI_rdata),
    .S05_AXI_rresp(S05_AXI_rresp),
    .S05_AXI_rlast(S05_AXI_rlast),
    .S05_AXI_rvalid(S05_AXI_rvalid),
    .S05_AXI_rready(S05_AXI_rready),
    .S06_AXI_awaddr(S06_AXI_awaddr),
    .S06_AXI_awlen(S06_AXI_awlen),
    .S06_AXI_awsize(S06_AXI_awsize),
    .S06_AXI_awburst(S06_AXI_awburst),
    .S06_AXI_awlock(S06_AXI_awlock),
    .S06_AXI_awcache(S06_AXI_awcache),
    .S06_AXI_awprot(S06_AXI_awprot),
    .S06_AXI_awregion(S06_AXI_awregion),
    .S06_AXI_awqos(S06_AXI_awqos),
    .S06_AXI_awvalid(S06_AXI_awvalid),
    .S06_AXI_awready(S06_AXI_awready),
    .S06_AXI_wdata(S06_AXI_wdata),
    .S06_AXI_wstrb(S06_AXI_wstrb),
    .S06_AXI_wlast(S06_AXI_wlast),
    .S06_AXI_wvalid(S06_AXI_wvalid),
    .S06_AXI_wready(S06_AXI_wready),
    .S06_AXI_bresp(S06_AXI_bresp),
    .S06_AXI_bvalid(S06_AXI_bvalid),
    .S06_AXI_bready(S06_AXI_bready),
    .S06_AXI_araddr(S06_AXI_araddr),
    .S06_AXI_arlen(S06_AXI_arlen),
    .S06_AXI_arsize(S06_AXI_arsize),
    .S06_AXI_arburst(S06_AXI_arburst),
    .S06_AXI_arlock(S06_AXI_arlock),
    .S06_AXI_arcache(S06_AXI_arcache),
    .S06_AXI_arprot(S06_AXI_arprot),
    .S06_AXI_arregion(S06_AXI_arregion),
    .S06_AXI_arqos(S06_AXI_arqos),
    .S06_AXI_arvalid(S06_AXI_arvalid),
    .S06_AXI_arready(S06_AXI_arready),
    .S06_AXI_rdata(S06_AXI_rdata),
    .S06_AXI_rresp(S06_AXI_rresp),
    .S06_AXI_rlast(S06_AXI_rlast),
    .S06_AXI_rvalid(S06_AXI_rvalid),
    .S06_AXI_rready(S06_AXI_rready),
    .S07_AXI_awaddr(S07_AXI_awaddr),
    .S07_AXI_awlen(S07_AXI_awlen),
    .S07_AXI_awsize(S07_AXI_awsize),
    .S07_AXI_awburst(S07_AXI_awburst),
    .S07_AXI_awlock(S07_AXI_awlock),
    .S07_AXI_awcache(S07_AXI_awcache),
    .S07_AXI_awprot(S07_AXI_awprot),
    .S07_AXI_awregion(S07_AXI_awregion),
    .S07_AXI_awqos(S07_AXI_awqos),
    .S07_AXI_awvalid(S07_AXI_awvalid),
    .S07_AXI_awready(S07_AXI_awready),
    .S07_AXI_wdata(S07_AXI_wdata),
    .S07_AXI_wstrb(S07_AXI_wstrb),
    .S07_AXI_wlast(S07_AXI_wlast),
    .S07_AXI_wvalid(S07_AXI_wvalid),
    .S07_AXI_wready(S07_AXI_wready),
    .S07_AXI_bresp(S07_AXI_bresp),
    .S07_AXI_bvalid(S07_AXI_bvalid),
    .S07_AXI_bready(S07_AXI_bready),
    .S07_AXI_araddr(S07_AXI_araddr),
    .S07_AXI_arlen(S07_AXI_arlen),
    .S07_AXI_arsize(S07_AXI_arsize),
    .S07_AXI_arburst(S07_AXI_arburst),
    .S07_AXI_arlock(S07_AXI_arlock),
    .S07_AXI_arcache(S07_AXI_arcache),
    .S07_AXI_arprot(S07_AXI_arprot),
    .S07_AXI_arregion(S07_AXI_arregion),
    .S07_AXI_arqos(S07_AXI_arqos),
    .S07_AXI_arvalid(S07_AXI_arvalid),
    .S07_AXI_arready(S07_AXI_arready),
    .S07_AXI_rdata(S07_AXI_rdata),
    .S07_AXI_rresp(S07_AXI_rresp),
    .S07_AXI_rlast(S07_AXI_rlast),
    .S07_AXI_rvalid(S07_AXI_rvalid),
    .S07_AXI_rready(S07_AXI_rready),
    .M00_AXI_awaddr(M00_AXI_awaddr),
    .M00_AXI_awlen(M00_AXI_awlen),
    .M00_AXI_awsize(M00_AXI_awsize),
    .M00_AXI_awburst(M00_AXI_awburst),
    .M00_AXI_awlock(M00_AXI_awlock),
    .M00_AXI_awcache(M00_AXI_awcache),
    .M00_AXI_awprot(M00_AXI_awprot),
    .M00_AXI_awregion(M00_AXI_awregion),
    .M00_AXI_awqos(M00_AXI_awqos),
    .M00_AXI_awvalid(M00_AXI_awvalid),
    .M00_AXI_awready(M00_AXI_awready),
    .M00_AXI_wdata(M00_AXI_wdata),
    .M00_AXI_wstrb(M00_AXI_wstrb),
    .M00_AXI_wlast(M00_AXI_wlast),
    .M00_AXI_wvalid(M00_AXI_wvalid),
    .M00_AXI_wready(M00_AXI_wready),
    .M00_AXI_bresp(M00_AXI_bresp),
    .M00_AXI_bvalid(M00_AXI_bvalid),
    .M00_AXI_bready(M00_AXI_bready),
    .M00_AXI_araddr(M00_AXI_araddr),
    .M00_AXI_arlen(M00_AXI_arlen),
    .M00_AXI_arsize(M00_AXI_arsize),
    .M00_AXI_arburst(M00_AXI_arburst),
    .M00_AXI_arlock(M00_AXI_arlock),
    .M00_AXI_arcache(M00_AXI_arcache),
    .M00_AXI_arprot(M00_AXI_arprot),
    .M00_AXI_arregion(M00_AXI_arregion),
    .M00_AXI_arqos(M00_AXI_arqos),
    .M00_AXI_arvalid(M00_AXI_arvalid),
    .M00_AXI_arready(M00_AXI_arready),
    .M00_AXI_rdata(M00_AXI_rdata),
    .M00_AXI_rresp(M00_AXI_rresp),
    .M00_AXI_rlast(M00_AXI_rlast),
    .M00_AXI_rvalid(M00_AXI_rvalid),
    .M00_AXI_rready(M00_AXI_rready),
    .M00_INI_internoc(M00_INI_internoc),
    .M01_INI_internoc(M01_INI_internoc),
    .M02_INI_internoc(M02_INI_internoc),
    .M03_INI_internoc(M03_INI_internoc),
    .M04_INI_internoc(M04_INI_internoc),
    .M05_INI_internoc(M05_INI_internoc),
    .M06_INI_internoc(M06_INI_internoc),
    .M07_INI_internoc(M07_INI_internoc),
    .aclk0(aclk0),
    .aclk1(aclk1),
    .aclk2(aclk2),
    .aclk3(aclk3),
    .aclk4(aclk4),
    .aclk5(aclk5),
    .aclk6(aclk6),
    .aclk7(aclk7),
    .aclk8(aclk8),
    .aclk9(aclk9),
    .S07_AXI_arid(S07_AXI_arid),
    .S07_AXI_aruser(S07_AXI_aruser),
    .S07_AXI_awid(S07_AXI_awid),
    .S07_AXI_awuser(S07_AXI_awuser),
    .S07_AXI_bid(S07_AXI_bid),
    .S07_AXI_buser(S07_AXI_buser),
    .S07_AXI_rid(S07_AXI_rid),
    .S07_AXI_ruser(S07_AXI_ruser),
    .S07_AXI_wuser(S07_AXI_wuser),
    .S06_AXI_arid(S06_AXI_arid),
    .S06_AXI_aruser(S06_AXI_aruser),
    .S06_AXI_awid(S06_AXI_awid),
    .S06_AXI_awuser(S06_AXI_awuser),
    .S06_AXI_bid(S06_AXI_bid),
    .S06_AXI_rid(S06_AXI_rid),
    .S06_AXI_ruser(S06_AXI_ruser),
    .S06_AXI_wuser(S06_AXI_wuser),
    .S01_AXI_arid(S01_AXI_arid),
    .S01_AXI_aruser(S01_AXI_aruser),
    .S01_AXI_awid(S01_AXI_awid),
    .S01_AXI_awuser(S01_AXI_awuser),
    .S01_AXI_bid(S01_AXI_bid),
    .S01_AXI_rid(S01_AXI_rid),
    .S01_AXI_ruser(S01_AXI_ruser),
    .S01_AXI_wuser(S01_AXI_wuser),
    .S03_AXI_arid(S03_AXI_arid),
    .S03_AXI_aruser(S03_AXI_aruser),
    .S03_AXI_awid(S03_AXI_awid),
    .S03_AXI_awuser(S03_AXI_awuser),
    .S03_AXI_bid(S03_AXI_bid),
    .S03_AXI_rid(S03_AXI_rid),
    .S03_AXI_ruser(S03_AXI_ruser),
    .S03_AXI_wuser(S03_AXI_wuser),
    .S05_AXI_arid(S05_AXI_arid),
    .S05_AXI_aruser(S05_AXI_aruser),
    .S05_AXI_awid(S05_AXI_awid),
    .S05_AXI_awuser(S05_AXI_awuser),
    .S05_AXI_bid(S05_AXI_bid),
    .S05_AXI_rid(S05_AXI_rid),
    .S05_AXI_ruser(S05_AXI_ruser),
    .S05_AXI_wuser(S05_AXI_wuser),
    .S00_AXI_arid(S00_AXI_arid),
    .S00_AXI_aruser(S00_AXI_aruser),
    .S00_AXI_awid(S00_AXI_awid),
    .S00_AXI_awuser(S00_AXI_awuser),
    .S00_AXI_bid(S00_AXI_bid),
    .S00_AXI_rid(S00_AXI_rid),
    .S00_AXI_ruser(S00_AXI_ruser),
    .S00_AXI_wuser(S00_AXI_wuser),
    .S02_AXI_arid(S02_AXI_arid),
    .S02_AXI_aruser(S02_AXI_aruser),
    .S02_AXI_awid(S02_AXI_awid),
    .S02_AXI_awuser(S02_AXI_awuser),
    .S02_AXI_bid(S02_AXI_bid),
    .S02_AXI_rid(S02_AXI_rid),
    .S02_AXI_ruser(S02_AXI_ruser),
    .S02_AXI_wuser(S02_AXI_wuser),
    .S04_AXI_arid(S04_AXI_arid),
    .S04_AXI_aruser(S04_AXI_aruser),
    .S04_AXI_awid(S04_AXI_awid),
    .S04_AXI_awuser(S04_AXI_awuser),
    .S04_AXI_bid(S04_AXI_bid),
    .S04_AXI_rid(S04_AXI_rid),
    .S04_AXI_ruser(S04_AXI_ruser),
    .S04_AXI_wuser(S04_AXI_wuser),
    .M00_AXI_arid(M00_AXI_arid),
    .M00_AXI_awid(M00_AXI_awid),
    .M00_AXI_bid(M00_AXI_bid),
    .M00_AXI_rid(M00_AXI_rid),
    .M00_AXI_ruser(M00_AXI_ruser),
    .M00_AXI_wuser(M00_AXI_wuser)
  );
endmodule
