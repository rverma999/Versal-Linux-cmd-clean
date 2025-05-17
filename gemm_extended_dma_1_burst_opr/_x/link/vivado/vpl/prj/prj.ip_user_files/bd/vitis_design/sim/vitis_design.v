//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2024.1 (lin64) Build 5076996 Wed May 22 18:36:09 MDT 2024
//Date        : Sat May 17 12:56:54 2025
//Host        : waiter running 64-bit Ubuntu 22.04.5 LTS
//Command     : generate_target vitis_design.bd
//Design      : vitis_design
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module System_DPA_imp_LGC0DA
   (MON_AXIS1_tdata,
    MON_AXIS1_tkeep,
    MON_AXIS1_tlast,
    MON_AXIS1_tready,
    MON_AXIS1_tstrb,
    MON_AXIS1_tvalid,
    MON_AXIS2_tdata,
    MON_AXIS2_tkeep,
    MON_AXIS2_tlast,
    MON_AXIS2_tready,
    MON_AXIS2_tvalid,
    MON_AXIS_tdata,
    MON_AXIS_tkeep,
    MON_AXIS_tlast,
    MON_AXIS_tready,
    MON_AXIS_tstrb,
    MON_AXIS_tvalid,
    MON_M_AXI1_araddr,
    MON_M_AXI1_arburst,
    MON_M_AXI1_arcache,
    MON_M_AXI1_arid,
    MON_M_AXI1_arlen,
    MON_M_AXI1_arlock,
    MON_M_AXI1_arprot,
    MON_M_AXI1_arqos,
    MON_M_AXI1_arready,
    MON_M_AXI1_arregion,
    MON_M_AXI1_arsize,
    MON_M_AXI1_arvalid,
    MON_M_AXI1_awaddr,
    MON_M_AXI1_awburst,
    MON_M_AXI1_awcache,
    MON_M_AXI1_awid,
    MON_M_AXI1_awlen,
    MON_M_AXI1_awlock,
    MON_M_AXI1_awprot,
    MON_M_AXI1_awqos,
    MON_M_AXI1_awready,
    MON_M_AXI1_awregion,
    MON_M_AXI1_awsize,
    MON_M_AXI1_awvalid,
    MON_M_AXI1_bid,
    MON_M_AXI1_bready,
    MON_M_AXI1_bresp,
    MON_M_AXI1_bvalid,
    MON_M_AXI1_rdata,
    MON_M_AXI1_rid,
    MON_M_AXI1_rlast,
    MON_M_AXI1_rready,
    MON_M_AXI1_rresp,
    MON_M_AXI1_rvalid,
    MON_M_AXI1_wdata,
    MON_M_AXI1_wlast,
    MON_M_AXI1_wready,
    MON_M_AXI1_wstrb,
    MON_M_AXI1_wvalid,
    MON_M_AXI2_araddr,
    MON_M_AXI2_arburst,
    MON_M_AXI2_arcache,
    MON_M_AXI2_arid,
    MON_M_AXI2_arlen,
    MON_M_AXI2_arlock,
    MON_M_AXI2_arprot,
    MON_M_AXI2_arqos,
    MON_M_AXI2_arready,
    MON_M_AXI2_arregion,
    MON_M_AXI2_arsize,
    MON_M_AXI2_arvalid,
    MON_M_AXI2_awaddr,
    MON_M_AXI2_awburst,
    MON_M_AXI2_awcache,
    MON_M_AXI2_awid,
    MON_M_AXI2_awlen,
    MON_M_AXI2_awlock,
    MON_M_AXI2_awprot,
    MON_M_AXI2_awqos,
    MON_M_AXI2_awready,
    MON_M_AXI2_awregion,
    MON_M_AXI2_awsize,
    MON_M_AXI2_awvalid,
    MON_M_AXI2_bid,
    MON_M_AXI2_bready,
    MON_M_AXI2_bresp,
    MON_M_AXI2_bvalid,
    MON_M_AXI2_rdata,
    MON_M_AXI2_rid,
    MON_M_AXI2_rlast,
    MON_M_AXI2_rready,
    MON_M_AXI2_rresp,
    MON_M_AXI2_rvalid,
    MON_M_AXI2_wdata,
    MON_M_AXI2_wlast,
    MON_M_AXI2_wready,
    MON_M_AXI2_wstrb,
    MON_M_AXI2_wvalid,
    MON_M_AXI_araddr,
    MON_M_AXI_arburst,
    MON_M_AXI_arcache,
    MON_M_AXI_arid,
    MON_M_AXI_arlen,
    MON_M_AXI_arlock,
    MON_M_AXI_arprot,
    MON_M_AXI_arqos,
    MON_M_AXI_arready,
    MON_M_AXI_arregion,
    MON_M_AXI_arsize,
    MON_M_AXI_arvalid,
    MON_M_AXI_awaddr,
    MON_M_AXI_awburst,
    MON_M_AXI_awcache,
    MON_M_AXI_awid,
    MON_M_AXI_awlen,
    MON_M_AXI_awlock,
    MON_M_AXI_awprot,
    MON_M_AXI_awqos,
    MON_M_AXI_awready,
    MON_M_AXI_awregion,
    MON_M_AXI_awsize,
    MON_M_AXI_awvalid,
    MON_M_AXI_bid,
    MON_M_AXI_bready,
    MON_M_AXI_bresp,
    MON_M_AXI_bvalid,
    MON_M_AXI_rdata,
    MON_M_AXI_rid,
    MON_M_AXI_rlast,
    MON_M_AXI_rready,
    MON_M_AXI_rresp,
    MON_M_AXI_rvalid,
    MON_M_AXI_wdata,
    MON_M_AXI_wlast,
    MON_M_AXI_wready,
    MON_M_AXI_wstrb,
    MON_M_AXI_wvalid,
    MON_S_AXI1_araddr,
    MON_S_AXI1_arprot,
    MON_S_AXI1_arready,
    MON_S_AXI1_arvalid,
    MON_S_AXI1_awaddr,
    MON_S_AXI1_awprot,
    MON_S_AXI1_awready,
    MON_S_AXI1_awvalid,
    MON_S_AXI1_bready,
    MON_S_AXI1_bresp,
    MON_S_AXI1_bvalid,
    MON_S_AXI1_rdata,
    MON_S_AXI1_rready,
    MON_S_AXI1_rresp,
    MON_S_AXI1_rvalid,
    MON_S_AXI1_wdata,
    MON_S_AXI1_wready,
    MON_S_AXI1_wstrb,
    MON_S_AXI1_wvalid,
    MON_S_AXI2_araddr,
    MON_S_AXI2_arprot,
    MON_S_AXI2_arready,
    MON_S_AXI2_arvalid,
    MON_S_AXI2_awaddr,
    MON_S_AXI2_awprot,
    MON_S_AXI2_awready,
    MON_S_AXI2_awvalid,
    MON_S_AXI2_bready,
    MON_S_AXI2_bresp,
    MON_S_AXI2_bvalid,
    MON_S_AXI2_rdata,
    MON_S_AXI2_rready,
    MON_S_AXI2_rresp,
    MON_S_AXI2_rvalid,
    MON_S_AXI2_wdata,
    MON_S_AXI2_wready,
    MON_S_AXI2_wstrb,
    MON_S_AXI2_wvalid,
    MON_S_AXI_araddr,
    MON_S_AXI_arprot,
    MON_S_AXI_arready,
    MON_S_AXI_arvalid,
    MON_S_AXI_awaddr,
    MON_S_AXI_awprot,
    MON_S_AXI_awready,
    MON_S_AXI_awvalid,
    MON_S_AXI_bready,
    MON_S_AXI_bresp,
    MON_S_AXI_bvalid,
    MON_S_AXI_rdata,
    MON_S_AXI_rready,
    MON_S_AXI_rresp,
    MON_S_AXI_rvalid,
    MON_S_AXI_wdata,
    MON_S_AXI_wready,
    MON_S_AXI_wstrb,
    MON_S_AXI_wvalid,
    S00_AXI_araddr,
    S00_AXI_arburst,
    S00_AXI_arcache,
    S00_AXI_arid,
    S00_AXI_arlen,
    S00_AXI_arlock,
    S00_AXI_arprot,
    S00_AXI_arqos,
    S00_AXI_arready,
    S00_AXI_arsize,
    S00_AXI_aruser,
    S00_AXI_arvalid,
    S00_AXI_awaddr,
    S00_AXI_awburst,
    S00_AXI_awcache,
    S00_AXI_awid,
    S00_AXI_awlen,
    S00_AXI_awlock,
    S00_AXI_awprot,
    S00_AXI_awqos,
    S00_AXI_awready,
    S00_AXI_awsize,
    S00_AXI_awuser,
    S00_AXI_awvalid,
    S00_AXI_bid,
    S00_AXI_bready,
    S00_AXI_bresp,
    S00_AXI_bvalid,
    S00_AXI_rdata,
    S00_AXI_rid,
    S00_AXI_rlast,
    S00_AXI_rready,
    S00_AXI_rresp,
    S00_AXI_ruser,
    S00_AXI_rvalid,
    S00_AXI_wdata,
    S00_AXI_wlast,
    S00_AXI_wready,
    S00_AXI_wstrb,
    S00_AXI_wuser,
    S00_AXI_wvalid,
    S_AXIMM_araddr,
    S_AXIMM_arburst,
    S_AXIMM_arlen,
    S_AXIMM_arready,
    S_AXIMM_arsize,
    S_AXIMM_arvalid,
    S_AXIMM_awaddr,
    S_AXIMM_awburst,
    S_AXIMM_awlen,
    S_AXIMM_awready,
    S_AXIMM_awsize,
    S_AXIMM_awvalid,
    S_AXIMM_bready,
    S_AXIMM_bresp,
    S_AXIMM_bvalid,
    S_AXIMM_rdata,
    S_AXIMM_rlast,
    S_AXIMM_rready,
    S_AXIMM_rresp,
    S_AXIMM_rvalid,
    S_AXIMM_wdata,
    S_AXIMM_wlast,
    S_AXIMM_wready,
    S_AXIMM_wstrb,
    S_AXIMM_wvalid,
    mon_clk,
    mon_resetn);
  input [31:0]MON_AXIS1_tdata;
  input [3:0]MON_AXIS1_tkeep;
  input [0:0]MON_AXIS1_tlast;
  input MON_AXIS1_tready;
  input [3:0]MON_AXIS1_tstrb;
  input MON_AXIS1_tvalid;
  input [31:0]MON_AXIS2_tdata;
  input [3:0]MON_AXIS2_tkeep;
  input [0:0]MON_AXIS2_tlast;
  input MON_AXIS2_tready;
  input MON_AXIS2_tvalid;
  input [31:0]MON_AXIS_tdata;
  input [3:0]MON_AXIS_tkeep;
  input [0:0]MON_AXIS_tlast;
  input MON_AXIS_tready;
  input [3:0]MON_AXIS_tstrb;
  input MON_AXIS_tvalid;
  input [63:0]MON_M_AXI1_araddr;
  input [1:0]MON_M_AXI1_arburst;
  input [3:0]MON_M_AXI1_arcache;
  input [0:0]MON_M_AXI1_arid;
  input [7:0]MON_M_AXI1_arlen;
  input [1:0]MON_M_AXI1_arlock;
  input [2:0]MON_M_AXI1_arprot;
  input [3:0]MON_M_AXI1_arqos;
  input MON_M_AXI1_arready;
  input [3:0]MON_M_AXI1_arregion;
  input [2:0]MON_M_AXI1_arsize;
  input MON_M_AXI1_arvalid;
  input [63:0]MON_M_AXI1_awaddr;
  input [1:0]MON_M_AXI1_awburst;
  input [3:0]MON_M_AXI1_awcache;
  input [0:0]MON_M_AXI1_awid;
  input [7:0]MON_M_AXI1_awlen;
  input [1:0]MON_M_AXI1_awlock;
  input [2:0]MON_M_AXI1_awprot;
  input [3:0]MON_M_AXI1_awqos;
  input MON_M_AXI1_awready;
  input [3:0]MON_M_AXI1_awregion;
  input [2:0]MON_M_AXI1_awsize;
  input MON_M_AXI1_awvalid;
  input [0:0]MON_M_AXI1_bid;
  input MON_M_AXI1_bready;
  input [1:0]MON_M_AXI1_bresp;
  input MON_M_AXI1_bvalid;
  input [31:0]MON_M_AXI1_rdata;
  input [0:0]MON_M_AXI1_rid;
  input MON_M_AXI1_rlast;
  input MON_M_AXI1_rready;
  input [1:0]MON_M_AXI1_rresp;
  input MON_M_AXI1_rvalid;
  input [31:0]MON_M_AXI1_wdata;
  input MON_M_AXI1_wlast;
  input MON_M_AXI1_wready;
  input [3:0]MON_M_AXI1_wstrb;
  input MON_M_AXI1_wvalid;
  input [63:0]MON_M_AXI2_araddr;
  input [1:0]MON_M_AXI2_arburst;
  input [3:0]MON_M_AXI2_arcache;
  input [0:0]MON_M_AXI2_arid;
  input [7:0]MON_M_AXI2_arlen;
  input [1:0]MON_M_AXI2_arlock;
  input [2:0]MON_M_AXI2_arprot;
  input [3:0]MON_M_AXI2_arqos;
  input MON_M_AXI2_arready;
  input [3:0]MON_M_AXI2_arregion;
  input [2:0]MON_M_AXI2_arsize;
  input MON_M_AXI2_arvalid;
  input [63:0]MON_M_AXI2_awaddr;
  input [1:0]MON_M_AXI2_awburst;
  input [3:0]MON_M_AXI2_awcache;
  input [0:0]MON_M_AXI2_awid;
  input [7:0]MON_M_AXI2_awlen;
  input [1:0]MON_M_AXI2_awlock;
  input [2:0]MON_M_AXI2_awprot;
  input [3:0]MON_M_AXI2_awqos;
  input MON_M_AXI2_awready;
  input [3:0]MON_M_AXI2_awregion;
  input [2:0]MON_M_AXI2_awsize;
  input MON_M_AXI2_awvalid;
  input [0:0]MON_M_AXI2_bid;
  input MON_M_AXI2_bready;
  input [1:0]MON_M_AXI2_bresp;
  input MON_M_AXI2_bvalid;
  input [31:0]MON_M_AXI2_rdata;
  input [0:0]MON_M_AXI2_rid;
  input MON_M_AXI2_rlast;
  input MON_M_AXI2_rready;
  input [1:0]MON_M_AXI2_rresp;
  input MON_M_AXI2_rvalid;
  input [31:0]MON_M_AXI2_wdata;
  input MON_M_AXI2_wlast;
  input MON_M_AXI2_wready;
  input [3:0]MON_M_AXI2_wstrb;
  input MON_M_AXI2_wvalid;
  input [63:0]MON_M_AXI_araddr;
  input [1:0]MON_M_AXI_arburst;
  input [3:0]MON_M_AXI_arcache;
  input [0:0]MON_M_AXI_arid;
  input [7:0]MON_M_AXI_arlen;
  input [1:0]MON_M_AXI_arlock;
  input [2:0]MON_M_AXI_arprot;
  input [3:0]MON_M_AXI_arqos;
  input MON_M_AXI_arready;
  input [3:0]MON_M_AXI_arregion;
  input [2:0]MON_M_AXI_arsize;
  input MON_M_AXI_arvalid;
  input [63:0]MON_M_AXI_awaddr;
  input [1:0]MON_M_AXI_awburst;
  input [3:0]MON_M_AXI_awcache;
  input [0:0]MON_M_AXI_awid;
  input [7:0]MON_M_AXI_awlen;
  input [1:0]MON_M_AXI_awlock;
  input [2:0]MON_M_AXI_awprot;
  input [3:0]MON_M_AXI_awqos;
  input MON_M_AXI_awready;
  input [3:0]MON_M_AXI_awregion;
  input [2:0]MON_M_AXI_awsize;
  input MON_M_AXI_awvalid;
  input [0:0]MON_M_AXI_bid;
  input MON_M_AXI_bready;
  input [1:0]MON_M_AXI_bresp;
  input MON_M_AXI_bvalid;
  input [31:0]MON_M_AXI_rdata;
  input [0:0]MON_M_AXI_rid;
  input MON_M_AXI_rlast;
  input MON_M_AXI_rready;
  input [1:0]MON_M_AXI_rresp;
  input MON_M_AXI_rvalid;
  input [31:0]MON_M_AXI_wdata;
  input MON_M_AXI_wlast;
  input MON_M_AXI_wready;
  input [3:0]MON_M_AXI_wstrb;
  input MON_M_AXI_wvalid;
  input [5:0]MON_S_AXI1_araddr;
  input [2:0]MON_S_AXI1_arprot;
  input MON_S_AXI1_arready;
  input MON_S_AXI1_arvalid;
  input [5:0]MON_S_AXI1_awaddr;
  input [2:0]MON_S_AXI1_awprot;
  input MON_S_AXI1_awready;
  input MON_S_AXI1_awvalid;
  input MON_S_AXI1_bready;
  input [1:0]MON_S_AXI1_bresp;
  input MON_S_AXI1_bvalid;
  input [31:0]MON_S_AXI1_rdata;
  input MON_S_AXI1_rready;
  input [1:0]MON_S_AXI1_rresp;
  input MON_S_AXI1_rvalid;
  input [31:0]MON_S_AXI1_wdata;
  input MON_S_AXI1_wready;
  input [3:0]MON_S_AXI1_wstrb;
  input MON_S_AXI1_wvalid;
  input [5:0]MON_S_AXI2_araddr;
  input [2:0]MON_S_AXI2_arprot;
  input MON_S_AXI2_arready;
  input MON_S_AXI2_arvalid;
  input [5:0]MON_S_AXI2_awaddr;
  input [2:0]MON_S_AXI2_awprot;
  input MON_S_AXI2_awready;
  input MON_S_AXI2_awvalid;
  input MON_S_AXI2_bready;
  input [1:0]MON_S_AXI2_bresp;
  input MON_S_AXI2_bvalid;
  input [31:0]MON_S_AXI2_rdata;
  input MON_S_AXI2_rready;
  input [1:0]MON_S_AXI2_rresp;
  input MON_S_AXI2_rvalid;
  input [31:0]MON_S_AXI2_wdata;
  input MON_S_AXI2_wready;
  input [3:0]MON_S_AXI2_wstrb;
  input MON_S_AXI2_wvalid;
  input [5:0]MON_S_AXI_araddr;
  input [2:0]MON_S_AXI_arprot;
  input MON_S_AXI_arready;
  input MON_S_AXI_arvalid;
  input [5:0]MON_S_AXI_awaddr;
  input [2:0]MON_S_AXI_awprot;
  input MON_S_AXI_awready;
  input MON_S_AXI_awvalid;
  input MON_S_AXI_bready;
  input [1:0]MON_S_AXI_bresp;
  input MON_S_AXI_bvalid;
  input [31:0]MON_S_AXI_rdata;
  input MON_S_AXI_rready;
  input [1:0]MON_S_AXI_rresp;
  input MON_S_AXI_rvalid;
  input [31:0]MON_S_AXI_wdata;
  input MON_S_AXI_wready;
  input [3:0]MON_S_AXI_wstrb;
  input MON_S_AXI_wvalid;
  input [43:0]S00_AXI_araddr;
  input [1:0]S00_AXI_arburst;
  input [3:0]S00_AXI_arcache;
  input [0:0]S00_AXI_arid;
  input [7:0]S00_AXI_arlen;
  input [0:0]S00_AXI_arlock;
  input [2:0]S00_AXI_arprot;
  input [3:0]S00_AXI_arqos;
  output S00_AXI_arready;
  input [2:0]S00_AXI_arsize;
  input [113:0]S00_AXI_aruser;
  input S00_AXI_arvalid;
  input [43:0]S00_AXI_awaddr;
  input [1:0]S00_AXI_awburst;
  input [3:0]S00_AXI_awcache;
  input [0:0]S00_AXI_awid;
  input [7:0]S00_AXI_awlen;
  input [0:0]S00_AXI_awlock;
  input [2:0]S00_AXI_awprot;
  input [3:0]S00_AXI_awqos;
  output S00_AXI_awready;
  input [2:0]S00_AXI_awsize;
  input [113:0]S00_AXI_awuser;
  input S00_AXI_awvalid;
  output [0:0]S00_AXI_bid;
  input S00_AXI_bready;
  output [1:0]S00_AXI_bresp;
  output S00_AXI_bvalid;
  output [127:0]S00_AXI_rdata;
  output [0:0]S00_AXI_rid;
  output S00_AXI_rlast;
  input S00_AXI_rready;
  output [1:0]S00_AXI_rresp;
  output [13:0]S00_AXI_ruser;
  output S00_AXI_rvalid;
  input [127:0]S00_AXI_wdata;
  input S00_AXI_wlast;
  output S00_AXI_wready;
  input [15:0]S00_AXI_wstrb;
  input [13:0]S00_AXI_wuser;
  input S00_AXI_wvalid;
  input [31:0]S_AXIMM_araddr;
  input [1:0]S_AXIMM_arburst;
  input [7:0]S_AXIMM_arlen;
  output S_AXIMM_arready;
  input [2:0]S_AXIMM_arsize;
  input S_AXIMM_arvalid;
  input [31:0]S_AXIMM_awaddr;
  input [1:0]S_AXIMM_awburst;
  input [7:0]S_AXIMM_awlen;
  output S_AXIMM_awready;
  input [2:0]S_AXIMM_awsize;
  input S_AXIMM_awvalid;
  input S_AXIMM_bready;
  output [1:0]S_AXIMM_bresp;
  output S_AXIMM_bvalid;
  output [31:0]S_AXIMM_rdata;
  output S_AXIMM_rlast;
  input S_AXIMM_rready;
  output [1:0]S_AXIMM_rresp;
  output S_AXIMM_rvalid;
  input [31:0]S_AXIMM_wdata;
  input S_AXIMM_wlast;
  output S_AXIMM_wready;
  input [3:0]S_AXIMM_wstrb;
  input S_AXIMM_wvalid;
  input mon_clk;
  input mon_resetn;

  wire clk_wizard_0_clk_out4_o1_o2;
  wire [7:0]dpa_ctrl_interconnect_M00_AXI_ARADDR;
  wire dpa_ctrl_interconnect_M00_AXI_ARREADY;
  wire dpa_ctrl_interconnect_M00_AXI_ARVALID;
  wire [7:0]dpa_ctrl_interconnect_M00_AXI_AWADDR;
  wire dpa_ctrl_interconnect_M00_AXI_AWREADY;
  wire dpa_ctrl_interconnect_M00_AXI_AWVALID;
  wire dpa_ctrl_interconnect_M00_AXI_BREADY;
  wire [1:0]dpa_ctrl_interconnect_M00_AXI_BRESP;
  wire dpa_ctrl_interconnect_M00_AXI_BVALID;
  wire [31:0]dpa_ctrl_interconnect_M00_AXI_RDATA;
  wire dpa_ctrl_interconnect_M00_AXI_RREADY;
  wire [1:0]dpa_ctrl_interconnect_M00_AXI_RRESP;
  wire dpa_ctrl_interconnect_M00_AXI_RVALID;
  wire [31:0]dpa_ctrl_interconnect_M00_AXI_WDATA;
  wire dpa_ctrl_interconnect_M00_AXI_WREADY;
  wire [3:0]dpa_ctrl_interconnect_M00_AXI_WSTRB;
  wire dpa_ctrl_interconnect_M00_AXI_WVALID;
  wire [7:0]dpa_ctrl_interconnect_M01_AXI_ARADDR;
  wire dpa_ctrl_interconnect_M01_AXI_ARREADY;
  wire dpa_ctrl_interconnect_M01_AXI_ARVALID;
  wire [7:0]dpa_ctrl_interconnect_M01_AXI_AWADDR;
  wire dpa_ctrl_interconnect_M01_AXI_AWREADY;
  wire dpa_ctrl_interconnect_M01_AXI_AWVALID;
  wire dpa_ctrl_interconnect_M01_AXI_BREADY;
  wire [1:0]dpa_ctrl_interconnect_M01_AXI_BRESP;
  wire dpa_ctrl_interconnect_M01_AXI_BVALID;
  wire [31:0]dpa_ctrl_interconnect_M01_AXI_RDATA;
  wire dpa_ctrl_interconnect_M01_AXI_RREADY;
  wire [1:0]dpa_ctrl_interconnect_M01_AXI_RRESP;
  wire dpa_ctrl_interconnect_M01_AXI_RVALID;
  wire [31:0]dpa_ctrl_interconnect_M01_AXI_WDATA;
  wire dpa_ctrl_interconnect_M01_AXI_WREADY;
  wire [3:0]dpa_ctrl_interconnect_M01_AXI_WSTRB;
  wire dpa_ctrl_interconnect_M01_AXI_WVALID;
  wire [7:0]dpa_ctrl_interconnect_M02_AXI_ARADDR;
  wire dpa_ctrl_interconnect_M02_AXI_ARREADY;
  wire dpa_ctrl_interconnect_M02_AXI_ARVALID;
  wire [7:0]dpa_ctrl_interconnect_M02_AXI_AWADDR;
  wire dpa_ctrl_interconnect_M02_AXI_AWREADY;
  wire dpa_ctrl_interconnect_M02_AXI_AWVALID;
  wire dpa_ctrl_interconnect_M02_AXI_BREADY;
  wire [1:0]dpa_ctrl_interconnect_M02_AXI_BRESP;
  wire dpa_ctrl_interconnect_M02_AXI_BVALID;
  wire [31:0]dpa_ctrl_interconnect_M02_AXI_RDATA;
  wire dpa_ctrl_interconnect_M02_AXI_RREADY;
  wire [1:0]dpa_ctrl_interconnect_M02_AXI_RRESP;
  wire dpa_ctrl_interconnect_M02_AXI_RVALID;
  wire [31:0]dpa_ctrl_interconnect_M02_AXI_WDATA;
  wire dpa_ctrl_interconnect_M02_AXI_WREADY;
  wire [3:0]dpa_ctrl_interconnect_M02_AXI_WSTRB;
  wire dpa_ctrl_interconnect_M02_AXI_WVALID;
  wire [7:0]dpa_ctrl_interconnect_M03_AXI_ARADDR;
  wire dpa_ctrl_interconnect_M03_AXI_ARREADY;
  wire dpa_ctrl_interconnect_M03_AXI_ARVALID;
  wire [7:0]dpa_ctrl_interconnect_M03_AXI_AWADDR;
  wire dpa_ctrl_interconnect_M03_AXI_AWREADY;
  wire dpa_ctrl_interconnect_M03_AXI_AWVALID;
  wire dpa_ctrl_interconnect_M03_AXI_BREADY;
  wire [1:0]dpa_ctrl_interconnect_M03_AXI_BRESP;
  wire dpa_ctrl_interconnect_M03_AXI_BVALID;
  wire [31:0]dpa_ctrl_interconnect_M03_AXI_RDATA;
  wire dpa_ctrl_interconnect_M03_AXI_RREADY;
  wire [1:0]dpa_ctrl_interconnect_M03_AXI_RRESP;
  wire dpa_ctrl_interconnect_M03_AXI_RVALID;
  wire [31:0]dpa_ctrl_interconnect_M03_AXI_WDATA;
  wire dpa_ctrl_interconnect_M03_AXI_WREADY;
  wire [3:0]dpa_ctrl_interconnect_M03_AXI_WSTRB;
  wire dpa_ctrl_interconnect_M03_AXI_WVALID;
  wire [7:0]dpa_ctrl_interconnect_M04_AXI_ARADDR;
  wire dpa_ctrl_interconnect_M04_AXI_ARREADY;
  wire dpa_ctrl_interconnect_M04_AXI_ARVALID;
  wire [7:0]dpa_ctrl_interconnect_M04_AXI_AWADDR;
  wire dpa_ctrl_interconnect_M04_AXI_AWREADY;
  wire dpa_ctrl_interconnect_M04_AXI_AWVALID;
  wire dpa_ctrl_interconnect_M04_AXI_BREADY;
  wire [1:0]dpa_ctrl_interconnect_M04_AXI_BRESP;
  wire dpa_ctrl_interconnect_M04_AXI_BVALID;
  wire [31:0]dpa_ctrl_interconnect_M04_AXI_RDATA;
  wire dpa_ctrl_interconnect_M04_AXI_RREADY;
  wire [1:0]dpa_ctrl_interconnect_M04_AXI_RRESP;
  wire dpa_ctrl_interconnect_M04_AXI_RVALID;
  wire [31:0]dpa_ctrl_interconnect_M04_AXI_WDATA;
  wire dpa_ctrl_interconnect_M04_AXI_WREADY;
  wire [3:0]dpa_ctrl_interconnect_M04_AXI_WSTRB;
  wire dpa_ctrl_interconnect_M04_AXI_WVALID;
  wire [7:0]dpa_ctrl_interconnect_M05_AXI_ARADDR;
  wire dpa_ctrl_interconnect_M05_AXI_ARREADY;
  wire dpa_ctrl_interconnect_M05_AXI_ARVALID;
  wire [7:0]dpa_ctrl_interconnect_M05_AXI_AWADDR;
  wire dpa_ctrl_interconnect_M05_AXI_AWREADY;
  wire dpa_ctrl_interconnect_M05_AXI_AWVALID;
  wire dpa_ctrl_interconnect_M05_AXI_BREADY;
  wire [1:0]dpa_ctrl_interconnect_M05_AXI_BRESP;
  wire dpa_ctrl_interconnect_M05_AXI_BVALID;
  wire [31:0]dpa_ctrl_interconnect_M05_AXI_RDATA;
  wire dpa_ctrl_interconnect_M05_AXI_RREADY;
  wire [1:0]dpa_ctrl_interconnect_M05_AXI_RRESP;
  wire dpa_ctrl_interconnect_M05_AXI_RVALID;
  wire [31:0]dpa_ctrl_interconnect_M05_AXI_WDATA;
  wire dpa_ctrl_interconnect_M05_AXI_WREADY;
  wire [3:0]dpa_ctrl_interconnect_M05_AXI_WSTRB;
  wire dpa_ctrl_interconnect_M05_AXI_WVALID;
  wire [7:0]dpa_ctrl_interconnect_M06_AXI_ARADDR;
  wire dpa_ctrl_interconnect_M06_AXI_ARREADY;
  wire dpa_ctrl_interconnect_M06_AXI_ARVALID;
  wire [7:0]dpa_ctrl_interconnect_M06_AXI_AWADDR;
  wire dpa_ctrl_interconnect_M06_AXI_AWREADY;
  wire dpa_ctrl_interconnect_M06_AXI_AWVALID;
  wire dpa_ctrl_interconnect_M06_AXI_BREADY;
  wire [1:0]dpa_ctrl_interconnect_M06_AXI_BRESP;
  wire dpa_ctrl_interconnect_M06_AXI_BVALID;
  wire [31:0]dpa_ctrl_interconnect_M06_AXI_RDATA;
  wire dpa_ctrl_interconnect_M06_AXI_RREADY;
  wire [1:0]dpa_ctrl_interconnect_M06_AXI_RRESP;
  wire dpa_ctrl_interconnect_M06_AXI_RVALID;
  wire [31:0]dpa_ctrl_interconnect_M06_AXI_WDATA;
  wire dpa_ctrl_interconnect_M06_AXI_WREADY;
  wire [3:0]dpa_ctrl_interconnect_M06_AXI_WSTRB;
  wire dpa_ctrl_interconnect_M06_AXI_WVALID;
  wire [7:0]dpa_ctrl_interconnect_M07_AXI_ARADDR;
  wire dpa_ctrl_interconnect_M07_AXI_ARREADY;
  wire dpa_ctrl_interconnect_M07_AXI_ARVALID;
  wire [7:0]dpa_ctrl_interconnect_M07_AXI_AWADDR;
  wire dpa_ctrl_interconnect_M07_AXI_AWREADY;
  wire dpa_ctrl_interconnect_M07_AXI_AWVALID;
  wire dpa_ctrl_interconnect_M07_AXI_BREADY;
  wire [1:0]dpa_ctrl_interconnect_M07_AXI_BRESP;
  wire dpa_ctrl_interconnect_M07_AXI_BVALID;
  wire [31:0]dpa_ctrl_interconnect_M07_AXI_RDATA;
  wire dpa_ctrl_interconnect_M07_AXI_RREADY;
  wire [1:0]dpa_ctrl_interconnect_M07_AXI_RRESP;
  wire dpa_ctrl_interconnect_M07_AXI_RVALID;
  wire [31:0]dpa_ctrl_interconnect_M07_AXI_WDATA;
  wire dpa_ctrl_interconnect_M07_AXI_WREADY;
  wire [3:0]dpa_ctrl_interconnect_M07_AXI_WSTRB;
  wire dpa_ctrl_interconnect_M07_AXI_WVALID;
  wire [63:0]dpa_mon0_TRACE_OUT_0_TDATA;
  wire [7:0]dpa_mon0_TRACE_OUT_0_TDEST;
  wire [7:0]dpa_mon0_TRACE_OUT_0_TID;
  wire dpa_mon0_TRACE_OUT_0_TLAST;
  wire dpa_mon0_TRACE_OUT_0_TREADY;
  wire dpa_mon0_TRACE_OUT_0_TVALID;
  wire [63:0]dpa_mon0_TRACE_OUT_1_TDATA;
  wire [7:0]dpa_mon0_TRACE_OUT_1_TDEST;
  wire [7:0]dpa_mon0_TRACE_OUT_1_TID;
  wire dpa_mon0_TRACE_OUT_1_TLAST;
  wire dpa_mon0_TRACE_OUT_1_TREADY;
  wire dpa_mon0_TRACE_OUT_1_TVALID;
  wire [63:0]dpa_mon1_TRACE_OUT_TDATA;
  wire [7:0]dpa_mon1_TRACE_OUT_TDEST;
  wire [7:0]dpa_mon1_TRACE_OUT_TID;
  wire dpa_mon1_TRACE_OUT_TLAST;
  wire dpa_mon1_TRACE_OUT_TREADY;
  wire dpa_mon1_TRACE_OUT_TVALID;
  wire [63:0]dpa_mon2_TRACE_OUT_0_TDATA;
  wire [7:0]dpa_mon2_TRACE_OUT_0_TDEST;
  wire [7:0]dpa_mon2_TRACE_OUT_0_TID;
  wire dpa_mon2_TRACE_OUT_0_TLAST;
  wire dpa_mon2_TRACE_OUT_0_TREADY;
  wire dpa_mon2_TRACE_OUT_0_TVALID;
  wire [63:0]dpa_mon2_TRACE_OUT_1_TDATA;
  wire [7:0]dpa_mon2_TRACE_OUT_1_TDEST;
  wire [7:0]dpa_mon2_TRACE_OUT_1_TID;
  wire dpa_mon2_TRACE_OUT_1_TLAST;
  wire dpa_mon2_TRACE_OUT_1_TREADY;
  wire dpa_mon2_TRACE_OUT_1_TVALID;
  wire [63:0]dpa_mon3_TRACE_OUT_TDATA;
  wire [7:0]dpa_mon3_TRACE_OUT_TDEST;
  wire [7:0]dpa_mon3_TRACE_OUT_TID;
  wire dpa_mon3_TRACE_OUT_TLAST;
  wire dpa_mon3_TRACE_OUT_TREADY;
  wire dpa_mon3_TRACE_OUT_TVALID;
  wire [63:0]dpa_mon4_TRACE_OUT_0_TDATA;
  wire [7:0]dpa_mon4_TRACE_OUT_0_TDEST;
  wire [7:0]dpa_mon4_TRACE_OUT_0_TID;
  wire dpa_mon4_TRACE_OUT_0_TLAST;
  wire dpa_mon4_TRACE_OUT_0_TREADY;
  wire dpa_mon4_TRACE_OUT_0_TVALID;
  wire [63:0]dpa_mon4_TRACE_OUT_1_TDATA;
  wire [7:0]dpa_mon4_TRACE_OUT_1_TDEST;
  wire [7:0]dpa_mon4_TRACE_OUT_1_TID;
  wire dpa_mon4_TRACE_OUT_1_TLAST;
  wire dpa_mon4_TRACE_OUT_1_TREADY;
  wire dpa_mon4_TRACE_OUT_1_TVALID;
  wire [63:0]dpa_mon5_TRACE_OUT_TDATA;
  wire [7:0]dpa_mon5_TRACE_OUT_TDEST;
  wire [7:0]dpa_mon5_TRACE_OUT_TID;
  wire dpa_mon5_TRACE_OUT_TLAST;
  wire dpa_mon5_TRACE_OUT_TREADY;
  wire dpa_mon5_TRACE_OUT_TVALID;
  wire [31:0]dwc_ai_engine_0_M00_AXIS_M_AXIS_TDATA;
  wire [0:0]dwc_ai_engine_0_M00_AXIS_M_AXIS_TLAST;
  wire dwc_ai_engine_0_M00_AXIS_M_AXIS_TREADY;
  wire dwc_ai_engine_0_M00_AXIS_M_AXIS_TVALID;
  wire [5:0]icn_ctrl_1_M06_AXI_ARADDR;
  wire [2:0]icn_ctrl_1_M06_AXI_ARPROT;
  wire icn_ctrl_1_M06_AXI_ARREADY;
  wire icn_ctrl_1_M06_AXI_ARVALID;
  wire [5:0]icn_ctrl_1_M06_AXI_AWADDR;
  wire [2:0]icn_ctrl_1_M06_AXI_AWPROT;
  wire icn_ctrl_1_M06_AXI_AWREADY;
  wire icn_ctrl_1_M06_AXI_AWVALID;
  wire icn_ctrl_1_M06_AXI_BREADY;
  wire [1:0]icn_ctrl_1_M06_AXI_BRESP;
  wire icn_ctrl_1_M06_AXI_BVALID;
  wire [31:0]icn_ctrl_1_M06_AXI_RDATA;
  wire icn_ctrl_1_M06_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M06_AXI_RRESP;
  wire icn_ctrl_1_M06_AXI_RVALID;
  wire [31:0]icn_ctrl_1_M06_AXI_WDATA;
  wire icn_ctrl_1_M06_AXI_WREADY;
  wire [3:0]icn_ctrl_1_M06_AXI_WSTRB;
  wire icn_ctrl_1_M06_AXI_WVALID;
  wire [5:0]icn_ctrl_1_M07_AXI_ARADDR;
  wire [2:0]icn_ctrl_1_M07_AXI_ARPROT;
  wire icn_ctrl_1_M07_AXI_ARREADY;
  wire icn_ctrl_1_M07_AXI_ARVALID;
  wire [5:0]icn_ctrl_1_M07_AXI_AWADDR;
  wire [2:0]icn_ctrl_1_M07_AXI_AWPROT;
  wire icn_ctrl_1_M07_AXI_AWREADY;
  wire icn_ctrl_1_M07_AXI_AWVALID;
  wire icn_ctrl_1_M07_AXI_BREADY;
  wire [1:0]icn_ctrl_1_M07_AXI_BRESP;
  wire icn_ctrl_1_M07_AXI_BVALID;
  wire [31:0]icn_ctrl_1_M07_AXI_RDATA;
  wire icn_ctrl_1_M07_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M07_AXI_RRESP;
  wire icn_ctrl_1_M07_AXI_RVALID;
  wire [31:0]icn_ctrl_1_M07_AXI_WDATA;
  wire icn_ctrl_1_M07_AXI_WREADY;
  wire [3:0]icn_ctrl_1_M07_AXI_WSTRB;
  wire icn_ctrl_1_M07_AXI_WVALID;
  wire [5:0]icn_ctrl_1_M08_AXI_ARADDR;
  wire [2:0]icn_ctrl_1_M08_AXI_ARPROT;
  wire icn_ctrl_1_M08_AXI_ARREADY;
  wire icn_ctrl_1_M08_AXI_ARVALID;
  wire [5:0]icn_ctrl_1_M08_AXI_AWADDR;
  wire [2:0]icn_ctrl_1_M08_AXI_AWPROT;
  wire icn_ctrl_1_M08_AXI_AWREADY;
  wire icn_ctrl_1_M08_AXI_AWVALID;
  wire icn_ctrl_1_M08_AXI_BREADY;
  wire [1:0]icn_ctrl_1_M08_AXI_BRESP;
  wire icn_ctrl_1_M08_AXI_BVALID;
  wire [31:0]icn_ctrl_1_M08_AXI_RDATA;
  wire icn_ctrl_1_M08_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M08_AXI_RRESP;
  wire icn_ctrl_1_M08_AXI_RVALID;
  wire [31:0]icn_ctrl_1_M08_AXI_WDATA;
  wire icn_ctrl_1_M08_AXI_WREADY;
  wire [3:0]icn_ctrl_1_M08_AXI_WSTRB;
  wire icn_ctrl_1_M08_AXI_WVALID;
  wire [43:0]icn_ctrl_1_M09_AXI_ARADDR;
  wire [1:0]icn_ctrl_1_M09_AXI_ARBURST;
  wire [3:0]icn_ctrl_1_M09_AXI_ARCACHE;
  wire [0:0]icn_ctrl_1_M09_AXI_ARID;
  wire [7:0]icn_ctrl_1_M09_AXI_ARLEN;
  wire [0:0]icn_ctrl_1_M09_AXI_ARLOCK;
  wire [2:0]icn_ctrl_1_M09_AXI_ARPROT;
  wire [3:0]icn_ctrl_1_M09_AXI_ARQOS;
  wire icn_ctrl_1_M09_AXI_ARREADY;
  wire [2:0]icn_ctrl_1_M09_AXI_ARSIZE;
  wire [113:0]icn_ctrl_1_M09_AXI_ARUSER;
  wire icn_ctrl_1_M09_AXI_ARVALID;
  wire [43:0]icn_ctrl_1_M09_AXI_AWADDR;
  wire [1:0]icn_ctrl_1_M09_AXI_AWBURST;
  wire [3:0]icn_ctrl_1_M09_AXI_AWCACHE;
  wire [0:0]icn_ctrl_1_M09_AXI_AWID;
  wire [7:0]icn_ctrl_1_M09_AXI_AWLEN;
  wire [0:0]icn_ctrl_1_M09_AXI_AWLOCK;
  wire [2:0]icn_ctrl_1_M09_AXI_AWPROT;
  wire [3:0]icn_ctrl_1_M09_AXI_AWQOS;
  wire icn_ctrl_1_M09_AXI_AWREADY;
  wire [2:0]icn_ctrl_1_M09_AXI_AWSIZE;
  wire [113:0]icn_ctrl_1_M09_AXI_AWUSER;
  wire icn_ctrl_1_M09_AXI_AWVALID;
  wire [0:0]icn_ctrl_1_M09_AXI_BID;
  wire icn_ctrl_1_M09_AXI_BREADY;
  wire [1:0]icn_ctrl_1_M09_AXI_BRESP;
  wire icn_ctrl_1_M09_AXI_BVALID;
  wire [127:0]icn_ctrl_1_M09_AXI_RDATA;
  wire [0:0]icn_ctrl_1_M09_AXI_RID;
  wire icn_ctrl_1_M09_AXI_RLAST;
  wire icn_ctrl_1_M09_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M09_AXI_RRESP;
  wire [13:0]icn_ctrl_1_M09_AXI_RUSER;
  wire icn_ctrl_1_M09_AXI_RVALID;
  wire [127:0]icn_ctrl_1_M09_AXI_WDATA;
  wire icn_ctrl_1_M09_AXI_WLAST;
  wire icn_ctrl_1_M09_AXI_WREADY;
  wire [15:0]icn_ctrl_1_M09_AXI_WSTRB;
  wire [13:0]icn_ctrl_1_M09_AXI_WUSER;
  wire icn_ctrl_1_M09_AXI_WVALID;
  wire [31:0]icn_ctrl_1_M10_AXI_ARADDR;
  wire [1:0]icn_ctrl_1_M10_AXI_ARBURST;
  wire [7:0]icn_ctrl_1_M10_AXI_ARLEN;
  wire icn_ctrl_1_M10_AXI_ARREADY;
  wire [2:0]icn_ctrl_1_M10_AXI_ARSIZE;
  wire icn_ctrl_1_M10_AXI_ARVALID;
  wire [31:0]icn_ctrl_1_M10_AXI_AWADDR;
  wire [1:0]icn_ctrl_1_M10_AXI_AWBURST;
  wire [7:0]icn_ctrl_1_M10_AXI_AWLEN;
  wire icn_ctrl_1_M10_AXI_AWREADY;
  wire [2:0]icn_ctrl_1_M10_AXI_AWSIZE;
  wire icn_ctrl_1_M10_AXI_AWVALID;
  wire icn_ctrl_1_M10_AXI_BREADY;
  wire [1:0]icn_ctrl_1_M10_AXI_BRESP;
  wire icn_ctrl_1_M10_AXI_BVALID;
  wire [31:0]icn_ctrl_1_M10_AXI_RDATA;
  wire icn_ctrl_1_M10_AXI_RLAST;
  wire icn_ctrl_1_M10_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M10_AXI_RRESP;
  wire icn_ctrl_1_M10_AXI_RVALID;
  wire [31:0]icn_ctrl_1_M10_AXI_WDATA;
  wire icn_ctrl_1_M10_AXI_WLAST;
  wire icn_ctrl_1_M10_AXI_WREADY;
  wire [3:0]icn_ctrl_1_M10_AXI_WSTRB;
  wire icn_ctrl_1_M10_AXI_WVALID;
  wire [63:0]mm2s_1_m_axi_gmem_ARADDR;
  wire [1:0]mm2s_1_m_axi_gmem_ARBURST;
  wire [0:0]mm2s_1_m_axi_gmem_ARID;
  wire [7:0]mm2s_1_m_axi_gmem_ARLEN;
  wire mm2s_1_m_axi_gmem_ARREADY;
  wire [2:0]mm2s_1_m_axi_gmem_ARSIZE;
  wire mm2s_1_m_axi_gmem_ARVALID;
  wire [63:0]mm2s_1_m_axi_gmem_AWADDR;
  wire [1:0]mm2s_1_m_axi_gmem_AWBURST;
  wire [0:0]mm2s_1_m_axi_gmem_AWID;
  wire [7:0]mm2s_1_m_axi_gmem_AWLEN;
  wire mm2s_1_m_axi_gmem_AWREADY;
  wire [2:0]mm2s_1_m_axi_gmem_AWSIZE;
  wire mm2s_1_m_axi_gmem_AWVALID;
  wire [0:0]mm2s_1_m_axi_gmem_BID;
  wire mm2s_1_m_axi_gmem_BREADY;
  wire [1:0]mm2s_1_m_axi_gmem_BRESP;
  wire mm2s_1_m_axi_gmem_BVALID;
  wire [31:0]mm2s_1_m_axi_gmem_RDATA;
  wire [0:0]mm2s_1_m_axi_gmem_RID;
  wire mm2s_1_m_axi_gmem_RLAST;
  wire mm2s_1_m_axi_gmem_RREADY;
  wire [1:0]mm2s_1_m_axi_gmem_RRESP;
  wire mm2s_1_m_axi_gmem_RVALID;
  wire [31:0]mm2s_1_m_axi_gmem_WDATA;
  wire mm2s_1_m_axi_gmem_WLAST;
  wire mm2s_1_m_axi_gmem_WREADY;
  wire [3:0]mm2s_1_m_axi_gmem_WSTRB;
  wire mm2s_1_m_axi_gmem_WVALID;
  wire [31:0]mm2s_1_s_TDATA;
  wire [0:0]mm2s_1_s_TLAST;
  wire mm2s_1_s_TREADY;
  wire mm2s_1_s_TVALID;
  wire [63:0]mm2s_2_m_axi_gmem_ARADDR;
  wire [1:0]mm2s_2_m_axi_gmem_ARBURST;
  wire [0:0]mm2s_2_m_axi_gmem_ARID;
  wire [7:0]mm2s_2_m_axi_gmem_ARLEN;
  wire mm2s_2_m_axi_gmem_ARREADY;
  wire [2:0]mm2s_2_m_axi_gmem_ARSIZE;
  wire mm2s_2_m_axi_gmem_ARVALID;
  wire [63:0]mm2s_2_m_axi_gmem_AWADDR;
  wire [1:0]mm2s_2_m_axi_gmem_AWBURST;
  wire [0:0]mm2s_2_m_axi_gmem_AWID;
  wire [7:0]mm2s_2_m_axi_gmem_AWLEN;
  wire mm2s_2_m_axi_gmem_AWREADY;
  wire [2:0]mm2s_2_m_axi_gmem_AWSIZE;
  wire mm2s_2_m_axi_gmem_AWVALID;
  wire [0:0]mm2s_2_m_axi_gmem_BID;
  wire mm2s_2_m_axi_gmem_BREADY;
  wire [1:0]mm2s_2_m_axi_gmem_BRESP;
  wire mm2s_2_m_axi_gmem_BVALID;
  wire [31:0]mm2s_2_m_axi_gmem_RDATA;
  wire [0:0]mm2s_2_m_axi_gmem_RID;
  wire mm2s_2_m_axi_gmem_RLAST;
  wire mm2s_2_m_axi_gmem_RREADY;
  wire [1:0]mm2s_2_m_axi_gmem_RRESP;
  wire mm2s_2_m_axi_gmem_RVALID;
  wire [31:0]mm2s_2_m_axi_gmem_WDATA;
  wire mm2s_2_m_axi_gmem_WLAST;
  wire mm2s_2_m_axi_gmem_WREADY;
  wire [3:0]mm2s_2_m_axi_gmem_WSTRB;
  wire mm2s_2_m_axi_gmem_WVALID;
  wire [31:0]mm2s_2_s_TDATA;
  wire [0:0]mm2s_2_s_TLAST;
  wire mm2s_2_s_TREADY;
  wire mm2s_2_s_TVALID;
  wire psr_312mhz_peripheral_aresetn;
  wire [63:0]s2mm_m_axi_gmem_ARADDR;
  wire [1:0]s2mm_m_axi_gmem_ARBURST;
  wire [0:0]s2mm_m_axi_gmem_ARID;
  wire [7:0]s2mm_m_axi_gmem_ARLEN;
  wire s2mm_m_axi_gmem_ARREADY;
  wire [2:0]s2mm_m_axi_gmem_ARSIZE;
  wire s2mm_m_axi_gmem_ARVALID;
  wire [63:0]s2mm_m_axi_gmem_AWADDR;
  wire [1:0]s2mm_m_axi_gmem_AWBURST;
  wire [0:0]s2mm_m_axi_gmem_AWID;
  wire [7:0]s2mm_m_axi_gmem_AWLEN;
  wire s2mm_m_axi_gmem_AWREADY;
  wire [2:0]s2mm_m_axi_gmem_AWSIZE;
  wire s2mm_m_axi_gmem_AWVALID;
  wire [0:0]s2mm_m_axi_gmem_BID;
  wire s2mm_m_axi_gmem_BREADY;
  wire [1:0]s2mm_m_axi_gmem_BRESP;
  wire s2mm_m_axi_gmem_BVALID;
  wire [31:0]s2mm_m_axi_gmem_RDATA;
  wire [0:0]s2mm_m_axi_gmem_RID;
  wire s2mm_m_axi_gmem_RLAST;
  wire s2mm_m_axi_gmem_RREADY;
  wire [1:0]s2mm_m_axi_gmem_RRESP;
  wire s2mm_m_axi_gmem_RVALID;
  wire [31:0]s2mm_m_axi_gmem_WDATA;
  wire s2mm_m_axi_gmem_WLAST;
  wire s2mm_m_axi_gmem_WREADY;
  wire [3:0]s2mm_m_axi_gmem_WSTRB;
  wire s2mm_m_axi_gmem_WVALID;

  assign S00_AXI_arready = icn_ctrl_1_M09_AXI_ARREADY;
  assign S00_AXI_awready = icn_ctrl_1_M09_AXI_AWREADY;
  assign S00_AXI_bid[0] = icn_ctrl_1_M09_AXI_BID;
  assign S00_AXI_bresp[1:0] = icn_ctrl_1_M09_AXI_BRESP;
  assign S00_AXI_bvalid = icn_ctrl_1_M09_AXI_BVALID;
  assign S00_AXI_rdata[127:0] = icn_ctrl_1_M09_AXI_RDATA;
  assign S00_AXI_rid[0] = icn_ctrl_1_M09_AXI_RID;
  assign S00_AXI_rlast = icn_ctrl_1_M09_AXI_RLAST;
  assign S00_AXI_rresp[1:0] = icn_ctrl_1_M09_AXI_RRESP;
  assign S00_AXI_ruser[13:0] = icn_ctrl_1_M09_AXI_RUSER;
  assign S00_AXI_rvalid = icn_ctrl_1_M09_AXI_RVALID;
  assign S00_AXI_wready = icn_ctrl_1_M09_AXI_WREADY;
  assign S_AXIMM_arready = icn_ctrl_1_M10_AXI_ARREADY;
  assign S_AXIMM_awready = icn_ctrl_1_M10_AXI_AWREADY;
  assign S_AXIMM_bresp[1:0] = icn_ctrl_1_M10_AXI_BRESP;
  assign S_AXIMM_bvalid = icn_ctrl_1_M10_AXI_BVALID;
  assign S_AXIMM_rdata[31:0] = icn_ctrl_1_M10_AXI_RDATA;
  assign S_AXIMM_rlast = icn_ctrl_1_M10_AXI_RLAST;
  assign S_AXIMM_rresp[1:0] = icn_ctrl_1_M10_AXI_RRESP;
  assign S_AXIMM_rvalid = icn_ctrl_1_M10_AXI_RVALID;
  assign S_AXIMM_wready = icn_ctrl_1_M10_AXI_WREADY;
  assign clk_wizard_0_clk_out4_o1_o2 = mon_clk;
  assign dwc_ai_engine_0_M00_AXIS_M_AXIS_TDATA = MON_AXIS2_tdata[31:0];
  assign dwc_ai_engine_0_M00_AXIS_M_AXIS_TLAST = MON_AXIS2_tlast[0];
  assign dwc_ai_engine_0_M00_AXIS_M_AXIS_TREADY = MON_AXIS2_tready;
  assign dwc_ai_engine_0_M00_AXIS_M_AXIS_TVALID = MON_AXIS2_tvalid;
  assign icn_ctrl_1_M06_AXI_ARADDR = MON_S_AXI_araddr[5:0];
  assign icn_ctrl_1_M06_AXI_ARPROT = MON_S_AXI_arprot[2:0];
  assign icn_ctrl_1_M06_AXI_ARREADY = MON_S_AXI_arready;
  assign icn_ctrl_1_M06_AXI_ARVALID = MON_S_AXI_arvalid;
  assign icn_ctrl_1_M06_AXI_AWADDR = MON_S_AXI_awaddr[5:0];
  assign icn_ctrl_1_M06_AXI_AWPROT = MON_S_AXI_awprot[2:0];
  assign icn_ctrl_1_M06_AXI_AWREADY = MON_S_AXI_awready;
  assign icn_ctrl_1_M06_AXI_AWVALID = MON_S_AXI_awvalid;
  assign icn_ctrl_1_M06_AXI_BREADY = MON_S_AXI_bready;
  assign icn_ctrl_1_M06_AXI_BRESP = MON_S_AXI_bresp[1:0];
  assign icn_ctrl_1_M06_AXI_BVALID = MON_S_AXI_bvalid;
  assign icn_ctrl_1_M06_AXI_RDATA = MON_S_AXI_rdata[31:0];
  assign icn_ctrl_1_M06_AXI_RREADY = MON_S_AXI_rready;
  assign icn_ctrl_1_M06_AXI_RRESP = MON_S_AXI_rresp[1:0];
  assign icn_ctrl_1_M06_AXI_RVALID = MON_S_AXI_rvalid;
  assign icn_ctrl_1_M06_AXI_WDATA = MON_S_AXI_wdata[31:0];
  assign icn_ctrl_1_M06_AXI_WREADY = MON_S_AXI_wready;
  assign icn_ctrl_1_M06_AXI_WSTRB = MON_S_AXI_wstrb[3:0];
  assign icn_ctrl_1_M06_AXI_WVALID = MON_S_AXI_wvalid;
  assign icn_ctrl_1_M07_AXI_ARADDR = MON_S_AXI1_araddr[5:0];
  assign icn_ctrl_1_M07_AXI_ARPROT = MON_S_AXI1_arprot[2:0];
  assign icn_ctrl_1_M07_AXI_ARREADY = MON_S_AXI1_arready;
  assign icn_ctrl_1_M07_AXI_ARVALID = MON_S_AXI1_arvalid;
  assign icn_ctrl_1_M07_AXI_AWADDR = MON_S_AXI1_awaddr[5:0];
  assign icn_ctrl_1_M07_AXI_AWPROT = MON_S_AXI1_awprot[2:0];
  assign icn_ctrl_1_M07_AXI_AWREADY = MON_S_AXI1_awready;
  assign icn_ctrl_1_M07_AXI_AWVALID = MON_S_AXI1_awvalid;
  assign icn_ctrl_1_M07_AXI_BREADY = MON_S_AXI1_bready;
  assign icn_ctrl_1_M07_AXI_BRESP = MON_S_AXI1_bresp[1:0];
  assign icn_ctrl_1_M07_AXI_BVALID = MON_S_AXI1_bvalid;
  assign icn_ctrl_1_M07_AXI_RDATA = MON_S_AXI1_rdata[31:0];
  assign icn_ctrl_1_M07_AXI_RREADY = MON_S_AXI1_rready;
  assign icn_ctrl_1_M07_AXI_RRESP = MON_S_AXI1_rresp[1:0];
  assign icn_ctrl_1_M07_AXI_RVALID = MON_S_AXI1_rvalid;
  assign icn_ctrl_1_M07_AXI_WDATA = MON_S_AXI1_wdata[31:0];
  assign icn_ctrl_1_M07_AXI_WREADY = MON_S_AXI1_wready;
  assign icn_ctrl_1_M07_AXI_WSTRB = MON_S_AXI1_wstrb[3:0];
  assign icn_ctrl_1_M07_AXI_WVALID = MON_S_AXI1_wvalid;
  assign icn_ctrl_1_M08_AXI_ARADDR = MON_S_AXI2_araddr[5:0];
  assign icn_ctrl_1_M08_AXI_ARPROT = MON_S_AXI2_arprot[2:0];
  assign icn_ctrl_1_M08_AXI_ARREADY = MON_S_AXI2_arready;
  assign icn_ctrl_1_M08_AXI_ARVALID = MON_S_AXI2_arvalid;
  assign icn_ctrl_1_M08_AXI_AWADDR = MON_S_AXI2_awaddr[5:0];
  assign icn_ctrl_1_M08_AXI_AWPROT = MON_S_AXI2_awprot[2:0];
  assign icn_ctrl_1_M08_AXI_AWREADY = MON_S_AXI2_awready;
  assign icn_ctrl_1_M08_AXI_AWVALID = MON_S_AXI2_awvalid;
  assign icn_ctrl_1_M08_AXI_BREADY = MON_S_AXI2_bready;
  assign icn_ctrl_1_M08_AXI_BRESP = MON_S_AXI2_bresp[1:0];
  assign icn_ctrl_1_M08_AXI_BVALID = MON_S_AXI2_bvalid;
  assign icn_ctrl_1_M08_AXI_RDATA = MON_S_AXI2_rdata[31:0];
  assign icn_ctrl_1_M08_AXI_RREADY = MON_S_AXI2_rready;
  assign icn_ctrl_1_M08_AXI_RRESP = MON_S_AXI2_rresp[1:0];
  assign icn_ctrl_1_M08_AXI_RVALID = MON_S_AXI2_rvalid;
  assign icn_ctrl_1_M08_AXI_WDATA = MON_S_AXI2_wdata[31:0];
  assign icn_ctrl_1_M08_AXI_WREADY = MON_S_AXI2_wready;
  assign icn_ctrl_1_M08_AXI_WSTRB = MON_S_AXI2_wstrb[3:0];
  assign icn_ctrl_1_M08_AXI_WVALID = MON_S_AXI2_wvalid;
  assign icn_ctrl_1_M09_AXI_ARADDR = S00_AXI_araddr[43:0];
  assign icn_ctrl_1_M09_AXI_ARBURST = S00_AXI_arburst[1:0];
  assign icn_ctrl_1_M09_AXI_ARCACHE = S00_AXI_arcache[3:0];
  assign icn_ctrl_1_M09_AXI_ARID = S00_AXI_arid[0];
  assign icn_ctrl_1_M09_AXI_ARLEN = S00_AXI_arlen[7:0];
  assign icn_ctrl_1_M09_AXI_ARLOCK = S00_AXI_arlock[0];
  assign icn_ctrl_1_M09_AXI_ARPROT = S00_AXI_arprot[2:0];
  assign icn_ctrl_1_M09_AXI_ARQOS = S00_AXI_arqos[3:0];
  assign icn_ctrl_1_M09_AXI_ARSIZE = S00_AXI_arsize[2:0];
  assign icn_ctrl_1_M09_AXI_ARUSER = S00_AXI_aruser[113:0];
  assign icn_ctrl_1_M09_AXI_ARVALID = S00_AXI_arvalid;
  assign icn_ctrl_1_M09_AXI_AWADDR = S00_AXI_awaddr[43:0];
  assign icn_ctrl_1_M09_AXI_AWBURST = S00_AXI_awburst[1:0];
  assign icn_ctrl_1_M09_AXI_AWCACHE = S00_AXI_awcache[3:0];
  assign icn_ctrl_1_M09_AXI_AWID = S00_AXI_awid[0];
  assign icn_ctrl_1_M09_AXI_AWLEN = S00_AXI_awlen[7:0];
  assign icn_ctrl_1_M09_AXI_AWLOCK = S00_AXI_awlock[0];
  assign icn_ctrl_1_M09_AXI_AWPROT = S00_AXI_awprot[2:0];
  assign icn_ctrl_1_M09_AXI_AWQOS = S00_AXI_awqos[3:0];
  assign icn_ctrl_1_M09_AXI_AWSIZE = S00_AXI_awsize[2:0];
  assign icn_ctrl_1_M09_AXI_AWUSER = S00_AXI_awuser[113:0];
  assign icn_ctrl_1_M09_AXI_AWVALID = S00_AXI_awvalid;
  assign icn_ctrl_1_M09_AXI_BREADY = S00_AXI_bready;
  assign icn_ctrl_1_M09_AXI_RREADY = S00_AXI_rready;
  assign icn_ctrl_1_M09_AXI_WDATA = S00_AXI_wdata[127:0];
  assign icn_ctrl_1_M09_AXI_WLAST = S00_AXI_wlast;
  assign icn_ctrl_1_M09_AXI_WSTRB = S00_AXI_wstrb[15:0];
  assign icn_ctrl_1_M09_AXI_WUSER = S00_AXI_wuser[13:0];
  assign icn_ctrl_1_M09_AXI_WVALID = S00_AXI_wvalid;
  assign icn_ctrl_1_M10_AXI_ARADDR = S_AXIMM_araddr[31:0];
  assign icn_ctrl_1_M10_AXI_ARBURST = S_AXIMM_arburst[1:0];
  assign icn_ctrl_1_M10_AXI_ARLEN = S_AXIMM_arlen[7:0];
  assign icn_ctrl_1_M10_AXI_ARSIZE = S_AXIMM_arsize[2:0];
  assign icn_ctrl_1_M10_AXI_ARVALID = S_AXIMM_arvalid;
  assign icn_ctrl_1_M10_AXI_AWADDR = S_AXIMM_awaddr[31:0];
  assign icn_ctrl_1_M10_AXI_AWBURST = S_AXIMM_awburst[1:0];
  assign icn_ctrl_1_M10_AXI_AWLEN = S_AXIMM_awlen[7:0];
  assign icn_ctrl_1_M10_AXI_AWSIZE = S_AXIMM_awsize[2:0];
  assign icn_ctrl_1_M10_AXI_AWVALID = S_AXIMM_awvalid;
  assign icn_ctrl_1_M10_AXI_BREADY = S_AXIMM_bready;
  assign icn_ctrl_1_M10_AXI_RREADY = S_AXIMM_rready;
  assign icn_ctrl_1_M10_AXI_WDATA = S_AXIMM_wdata[31:0];
  assign icn_ctrl_1_M10_AXI_WLAST = S_AXIMM_wlast;
  assign icn_ctrl_1_M10_AXI_WSTRB = S_AXIMM_wstrb[3:0];
  assign icn_ctrl_1_M10_AXI_WVALID = S_AXIMM_wvalid;
  assign mm2s_1_m_axi_gmem_ARADDR = MON_M_AXI_araddr[63:0];
  assign mm2s_1_m_axi_gmem_ARBURST = MON_M_AXI_arburst[1:0];
  assign mm2s_1_m_axi_gmem_ARID = MON_M_AXI_arid[0];
  assign mm2s_1_m_axi_gmem_ARLEN = MON_M_AXI_arlen[7:0];
  assign mm2s_1_m_axi_gmem_ARREADY = MON_M_AXI_arready;
  assign mm2s_1_m_axi_gmem_ARSIZE = MON_M_AXI_arsize[2:0];
  assign mm2s_1_m_axi_gmem_ARVALID = MON_M_AXI_arvalid;
  assign mm2s_1_m_axi_gmem_AWADDR = MON_M_AXI_awaddr[63:0];
  assign mm2s_1_m_axi_gmem_AWBURST = MON_M_AXI_awburst[1:0];
  assign mm2s_1_m_axi_gmem_AWID = MON_M_AXI_awid[0];
  assign mm2s_1_m_axi_gmem_AWLEN = MON_M_AXI_awlen[7:0];
  assign mm2s_1_m_axi_gmem_AWREADY = MON_M_AXI_awready;
  assign mm2s_1_m_axi_gmem_AWSIZE = MON_M_AXI_awsize[2:0];
  assign mm2s_1_m_axi_gmem_AWVALID = MON_M_AXI_awvalid;
  assign mm2s_1_m_axi_gmem_BID = MON_M_AXI_bid[0];
  assign mm2s_1_m_axi_gmem_BREADY = MON_M_AXI_bready;
  assign mm2s_1_m_axi_gmem_BRESP = MON_M_AXI_bresp[1:0];
  assign mm2s_1_m_axi_gmem_BVALID = MON_M_AXI_bvalid;
  assign mm2s_1_m_axi_gmem_RDATA = MON_M_AXI_rdata[31:0];
  assign mm2s_1_m_axi_gmem_RID = MON_M_AXI_rid[0];
  assign mm2s_1_m_axi_gmem_RLAST = MON_M_AXI_rlast;
  assign mm2s_1_m_axi_gmem_RREADY = MON_M_AXI_rready;
  assign mm2s_1_m_axi_gmem_RRESP = MON_M_AXI_rresp[1:0];
  assign mm2s_1_m_axi_gmem_RVALID = MON_M_AXI_rvalid;
  assign mm2s_1_m_axi_gmem_WDATA = MON_M_AXI_wdata[31:0];
  assign mm2s_1_m_axi_gmem_WLAST = MON_M_AXI_wlast;
  assign mm2s_1_m_axi_gmem_WREADY = MON_M_AXI_wready;
  assign mm2s_1_m_axi_gmem_WSTRB = MON_M_AXI_wstrb[3:0];
  assign mm2s_1_m_axi_gmem_WVALID = MON_M_AXI_wvalid;
  assign mm2s_1_s_TDATA = MON_AXIS_tdata[31:0];
  assign mm2s_1_s_TLAST = MON_AXIS_tlast[0];
  assign mm2s_1_s_TREADY = MON_AXIS_tready;
  assign mm2s_1_s_TVALID = MON_AXIS_tvalid;
  assign mm2s_2_m_axi_gmem_ARADDR = MON_M_AXI1_araddr[63:0];
  assign mm2s_2_m_axi_gmem_ARBURST = MON_M_AXI1_arburst[1:0];
  assign mm2s_2_m_axi_gmem_ARID = MON_M_AXI1_arid[0];
  assign mm2s_2_m_axi_gmem_ARLEN = MON_M_AXI1_arlen[7:0];
  assign mm2s_2_m_axi_gmem_ARREADY = MON_M_AXI1_arready;
  assign mm2s_2_m_axi_gmem_ARSIZE = MON_M_AXI1_arsize[2:0];
  assign mm2s_2_m_axi_gmem_ARVALID = MON_M_AXI1_arvalid;
  assign mm2s_2_m_axi_gmem_AWADDR = MON_M_AXI1_awaddr[63:0];
  assign mm2s_2_m_axi_gmem_AWBURST = MON_M_AXI1_awburst[1:0];
  assign mm2s_2_m_axi_gmem_AWID = MON_M_AXI1_awid[0];
  assign mm2s_2_m_axi_gmem_AWLEN = MON_M_AXI1_awlen[7:0];
  assign mm2s_2_m_axi_gmem_AWREADY = MON_M_AXI1_awready;
  assign mm2s_2_m_axi_gmem_AWSIZE = MON_M_AXI1_awsize[2:0];
  assign mm2s_2_m_axi_gmem_AWVALID = MON_M_AXI1_awvalid;
  assign mm2s_2_m_axi_gmem_BID = MON_M_AXI1_bid[0];
  assign mm2s_2_m_axi_gmem_BREADY = MON_M_AXI1_bready;
  assign mm2s_2_m_axi_gmem_BRESP = MON_M_AXI1_bresp[1:0];
  assign mm2s_2_m_axi_gmem_BVALID = MON_M_AXI1_bvalid;
  assign mm2s_2_m_axi_gmem_RDATA = MON_M_AXI1_rdata[31:0];
  assign mm2s_2_m_axi_gmem_RID = MON_M_AXI1_rid[0];
  assign mm2s_2_m_axi_gmem_RLAST = MON_M_AXI1_rlast;
  assign mm2s_2_m_axi_gmem_RREADY = MON_M_AXI1_rready;
  assign mm2s_2_m_axi_gmem_RRESP = MON_M_AXI1_rresp[1:0];
  assign mm2s_2_m_axi_gmem_RVALID = MON_M_AXI1_rvalid;
  assign mm2s_2_m_axi_gmem_WDATA = MON_M_AXI1_wdata[31:0];
  assign mm2s_2_m_axi_gmem_WLAST = MON_M_AXI1_wlast;
  assign mm2s_2_m_axi_gmem_WREADY = MON_M_AXI1_wready;
  assign mm2s_2_m_axi_gmem_WSTRB = MON_M_AXI1_wstrb[3:0];
  assign mm2s_2_m_axi_gmem_WVALID = MON_M_AXI1_wvalid;
  assign mm2s_2_s_TDATA = MON_AXIS1_tdata[31:0];
  assign mm2s_2_s_TLAST = MON_AXIS1_tlast[0];
  assign mm2s_2_s_TREADY = MON_AXIS1_tready;
  assign mm2s_2_s_TVALID = MON_AXIS1_tvalid;
  assign psr_312mhz_peripheral_aresetn = mon_resetn;
  assign s2mm_m_axi_gmem_ARADDR = MON_M_AXI2_araddr[63:0];
  assign s2mm_m_axi_gmem_ARBURST = MON_M_AXI2_arburst[1:0];
  assign s2mm_m_axi_gmem_ARID = MON_M_AXI2_arid[0];
  assign s2mm_m_axi_gmem_ARLEN = MON_M_AXI2_arlen[7:0];
  assign s2mm_m_axi_gmem_ARREADY = MON_M_AXI2_arready;
  assign s2mm_m_axi_gmem_ARSIZE = MON_M_AXI2_arsize[2:0];
  assign s2mm_m_axi_gmem_ARVALID = MON_M_AXI2_arvalid;
  assign s2mm_m_axi_gmem_AWADDR = MON_M_AXI2_awaddr[63:0];
  assign s2mm_m_axi_gmem_AWBURST = MON_M_AXI2_awburst[1:0];
  assign s2mm_m_axi_gmem_AWID = MON_M_AXI2_awid[0];
  assign s2mm_m_axi_gmem_AWLEN = MON_M_AXI2_awlen[7:0];
  assign s2mm_m_axi_gmem_AWREADY = MON_M_AXI2_awready;
  assign s2mm_m_axi_gmem_AWSIZE = MON_M_AXI2_awsize[2:0];
  assign s2mm_m_axi_gmem_AWVALID = MON_M_AXI2_awvalid;
  assign s2mm_m_axi_gmem_BID = MON_M_AXI2_bid[0];
  assign s2mm_m_axi_gmem_BREADY = MON_M_AXI2_bready;
  assign s2mm_m_axi_gmem_BRESP = MON_M_AXI2_bresp[1:0];
  assign s2mm_m_axi_gmem_BVALID = MON_M_AXI2_bvalid;
  assign s2mm_m_axi_gmem_RDATA = MON_M_AXI2_rdata[31:0];
  assign s2mm_m_axi_gmem_RID = MON_M_AXI2_rid[0];
  assign s2mm_m_axi_gmem_RLAST = MON_M_AXI2_rlast;
  assign s2mm_m_axi_gmem_RREADY = MON_M_AXI2_rready;
  assign s2mm_m_axi_gmem_RRESP = MON_M_AXI2_rresp[1:0];
  assign s2mm_m_axi_gmem_RVALID = MON_M_AXI2_rvalid;
  assign s2mm_m_axi_gmem_WDATA = MON_M_AXI2_wdata[31:0];
  assign s2mm_m_axi_gmem_WLAST = MON_M_AXI2_wlast;
  assign s2mm_m_axi_gmem_WREADY = MON_M_AXI2_wready;
  assign s2mm_m_axi_gmem_WSTRB = MON_M_AXI2_wstrb[3:0];
  assign s2mm_m_axi_gmem_WVALID = MON_M_AXI2_wvalid;
  vitis_design_dpa_ctrl_interconnect_0 dpa_ctrl_interconnect
       (.M00_AXI_araddr(dpa_ctrl_interconnect_M00_AXI_ARADDR),
        .M00_AXI_arready(dpa_ctrl_interconnect_M00_AXI_ARREADY),
        .M00_AXI_arvalid(dpa_ctrl_interconnect_M00_AXI_ARVALID),
        .M00_AXI_awaddr(dpa_ctrl_interconnect_M00_AXI_AWADDR),
        .M00_AXI_awready(dpa_ctrl_interconnect_M00_AXI_AWREADY),
        .M00_AXI_awvalid(dpa_ctrl_interconnect_M00_AXI_AWVALID),
        .M00_AXI_bready(dpa_ctrl_interconnect_M00_AXI_BREADY),
        .M00_AXI_bresp(dpa_ctrl_interconnect_M00_AXI_BRESP),
        .M00_AXI_bvalid(dpa_ctrl_interconnect_M00_AXI_BVALID),
        .M00_AXI_rdata(dpa_ctrl_interconnect_M00_AXI_RDATA),
        .M00_AXI_rready(dpa_ctrl_interconnect_M00_AXI_RREADY),
        .M00_AXI_rresp(dpa_ctrl_interconnect_M00_AXI_RRESP),
        .M00_AXI_rvalid(dpa_ctrl_interconnect_M00_AXI_RVALID),
        .M00_AXI_wdata(dpa_ctrl_interconnect_M00_AXI_WDATA),
        .M00_AXI_wready(dpa_ctrl_interconnect_M00_AXI_WREADY),
        .M00_AXI_wstrb(dpa_ctrl_interconnect_M00_AXI_WSTRB),
        .M00_AXI_wvalid(dpa_ctrl_interconnect_M00_AXI_WVALID),
        .M01_AXI_araddr(dpa_ctrl_interconnect_M01_AXI_ARADDR),
        .M01_AXI_arready(dpa_ctrl_interconnect_M01_AXI_ARREADY),
        .M01_AXI_arvalid(dpa_ctrl_interconnect_M01_AXI_ARVALID),
        .M01_AXI_awaddr(dpa_ctrl_interconnect_M01_AXI_AWADDR),
        .M01_AXI_awready(dpa_ctrl_interconnect_M01_AXI_AWREADY),
        .M01_AXI_awvalid(dpa_ctrl_interconnect_M01_AXI_AWVALID),
        .M01_AXI_bready(dpa_ctrl_interconnect_M01_AXI_BREADY),
        .M01_AXI_bresp(dpa_ctrl_interconnect_M01_AXI_BRESP),
        .M01_AXI_bvalid(dpa_ctrl_interconnect_M01_AXI_BVALID),
        .M01_AXI_rdata(dpa_ctrl_interconnect_M01_AXI_RDATA),
        .M01_AXI_rready(dpa_ctrl_interconnect_M01_AXI_RREADY),
        .M01_AXI_rresp(dpa_ctrl_interconnect_M01_AXI_RRESP),
        .M01_AXI_rvalid(dpa_ctrl_interconnect_M01_AXI_RVALID),
        .M01_AXI_wdata(dpa_ctrl_interconnect_M01_AXI_WDATA),
        .M01_AXI_wready(dpa_ctrl_interconnect_M01_AXI_WREADY),
        .M01_AXI_wstrb(dpa_ctrl_interconnect_M01_AXI_WSTRB),
        .M01_AXI_wvalid(dpa_ctrl_interconnect_M01_AXI_WVALID),
        .M02_AXI_araddr(dpa_ctrl_interconnect_M02_AXI_ARADDR),
        .M02_AXI_arready(dpa_ctrl_interconnect_M02_AXI_ARREADY),
        .M02_AXI_arvalid(dpa_ctrl_interconnect_M02_AXI_ARVALID),
        .M02_AXI_awaddr(dpa_ctrl_interconnect_M02_AXI_AWADDR),
        .M02_AXI_awready(dpa_ctrl_interconnect_M02_AXI_AWREADY),
        .M02_AXI_awvalid(dpa_ctrl_interconnect_M02_AXI_AWVALID),
        .M02_AXI_bready(dpa_ctrl_interconnect_M02_AXI_BREADY),
        .M02_AXI_bresp(dpa_ctrl_interconnect_M02_AXI_BRESP),
        .M02_AXI_bvalid(dpa_ctrl_interconnect_M02_AXI_BVALID),
        .M02_AXI_rdata(dpa_ctrl_interconnect_M02_AXI_RDATA),
        .M02_AXI_rready(dpa_ctrl_interconnect_M02_AXI_RREADY),
        .M02_AXI_rresp(dpa_ctrl_interconnect_M02_AXI_RRESP),
        .M02_AXI_rvalid(dpa_ctrl_interconnect_M02_AXI_RVALID),
        .M02_AXI_wdata(dpa_ctrl_interconnect_M02_AXI_WDATA),
        .M02_AXI_wready(dpa_ctrl_interconnect_M02_AXI_WREADY),
        .M02_AXI_wstrb(dpa_ctrl_interconnect_M02_AXI_WSTRB),
        .M02_AXI_wvalid(dpa_ctrl_interconnect_M02_AXI_WVALID),
        .M03_AXI_araddr(dpa_ctrl_interconnect_M03_AXI_ARADDR),
        .M03_AXI_arready(dpa_ctrl_interconnect_M03_AXI_ARREADY),
        .M03_AXI_arvalid(dpa_ctrl_interconnect_M03_AXI_ARVALID),
        .M03_AXI_awaddr(dpa_ctrl_interconnect_M03_AXI_AWADDR),
        .M03_AXI_awready(dpa_ctrl_interconnect_M03_AXI_AWREADY),
        .M03_AXI_awvalid(dpa_ctrl_interconnect_M03_AXI_AWVALID),
        .M03_AXI_bready(dpa_ctrl_interconnect_M03_AXI_BREADY),
        .M03_AXI_bresp(dpa_ctrl_interconnect_M03_AXI_BRESP),
        .M03_AXI_bvalid(dpa_ctrl_interconnect_M03_AXI_BVALID),
        .M03_AXI_rdata(dpa_ctrl_interconnect_M03_AXI_RDATA),
        .M03_AXI_rready(dpa_ctrl_interconnect_M03_AXI_RREADY),
        .M03_AXI_rresp(dpa_ctrl_interconnect_M03_AXI_RRESP),
        .M03_AXI_rvalid(dpa_ctrl_interconnect_M03_AXI_RVALID),
        .M03_AXI_wdata(dpa_ctrl_interconnect_M03_AXI_WDATA),
        .M03_AXI_wready(dpa_ctrl_interconnect_M03_AXI_WREADY),
        .M03_AXI_wstrb(dpa_ctrl_interconnect_M03_AXI_WSTRB),
        .M03_AXI_wvalid(dpa_ctrl_interconnect_M03_AXI_WVALID),
        .M04_AXI_araddr(dpa_ctrl_interconnect_M04_AXI_ARADDR),
        .M04_AXI_arready(dpa_ctrl_interconnect_M04_AXI_ARREADY),
        .M04_AXI_arvalid(dpa_ctrl_interconnect_M04_AXI_ARVALID),
        .M04_AXI_awaddr(dpa_ctrl_interconnect_M04_AXI_AWADDR),
        .M04_AXI_awready(dpa_ctrl_interconnect_M04_AXI_AWREADY),
        .M04_AXI_awvalid(dpa_ctrl_interconnect_M04_AXI_AWVALID),
        .M04_AXI_bready(dpa_ctrl_interconnect_M04_AXI_BREADY),
        .M04_AXI_bresp(dpa_ctrl_interconnect_M04_AXI_BRESP),
        .M04_AXI_bvalid(dpa_ctrl_interconnect_M04_AXI_BVALID),
        .M04_AXI_rdata(dpa_ctrl_interconnect_M04_AXI_RDATA),
        .M04_AXI_rready(dpa_ctrl_interconnect_M04_AXI_RREADY),
        .M04_AXI_rresp(dpa_ctrl_interconnect_M04_AXI_RRESP),
        .M04_AXI_rvalid(dpa_ctrl_interconnect_M04_AXI_RVALID),
        .M04_AXI_wdata(dpa_ctrl_interconnect_M04_AXI_WDATA),
        .M04_AXI_wready(dpa_ctrl_interconnect_M04_AXI_WREADY),
        .M04_AXI_wstrb(dpa_ctrl_interconnect_M04_AXI_WSTRB),
        .M04_AXI_wvalid(dpa_ctrl_interconnect_M04_AXI_WVALID),
        .M05_AXI_araddr(dpa_ctrl_interconnect_M05_AXI_ARADDR),
        .M05_AXI_arready(dpa_ctrl_interconnect_M05_AXI_ARREADY),
        .M05_AXI_arvalid(dpa_ctrl_interconnect_M05_AXI_ARVALID),
        .M05_AXI_awaddr(dpa_ctrl_interconnect_M05_AXI_AWADDR),
        .M05_AXI_awready(dpa_ctrl_interconnect_M05_AXI_AWREADY),
        .M05_AXI_awvalid(dpa_ctrl_interconnect_M05_AXI_AWVALID),
        .M05_AXI_bready(dpa_ctrl_interconnect_M05_AXI_BREADY),
        .M05_AXI_bresp(dpa_ctrl_interconnect_M05_AXI_BRESP),
        .M05_AXI_bvalid(dpa_ctrl_interconnect_M05_AXI_BVALID),
        .M05_AXI_rdata(dpa_ctrl_interconnect_M05_AXI_RDATA),
        .M05_AXI_rready(dpa_ctrl_interconnect_M05_AXI_RREADY),
        .M05_AXI_rresp(dpa_ctrl_interconnect_M05_AXI_RRESP),
        .M05_AXI_rvalid(dpa_ctrl_interconnect_M05_AXI_RVALID),
        .M05_AXI_wdata(dpa_ctrl_interconnect_M05_AXI_WDATA),
        .M05_AXI_wready(dpa_ctrl_interconnect_M05_AXI_WREADY),
        .M05_AXI_wstrb(dpa_ctrl_interconnect_M05_AXI_WSTRB),
        .M05_AXI_wvalid(dpa_ctrl_interconnect_M05_AXI_WVALID),
        .M06_AXI_araddr(dpa_ctrl_interconnect_M06_AXI_ARADDR),
        .M06_AXI_arready(dpa_ctrl_interconnect_M06_AXI_ARREADY),
        .M06_AXI_arvalid(dpa_ctrl_interconnect_M06_AXI_ARVALID),
        .M06_AXI_awaddr(dpa_ctrl_interconnect_M06_AXI_AWADDR),
        .M06_AXI_awready(dpa_ctrl_interconnect_M06_AXI_AWREADY),
        .M06_AXI_awvalid(dpa_ctrl_interconnect_M06_AXI_AWVALID),
        .M06_AXI_bready(dpa_ctrl_interconnect_M06_AXI_BREADY),
        .M06_AXI_bresp(dpa_ctrl_interconnect_M06_AXI_BRESP),
        .M06_AXI_bvalid(dpa_ctrl_interconnect_M06_AXI_BVALID),
        .M06_AXI_rdata(dpa_ctrl_interconnect_M06_AXI_RDATA),
        .M06_AXI_rready(dpa_ctrl_interconnect_M06_AXI_RREADY),
        .M06_AXI_rresp(dpa_ctrl_interconnect_M06_AXI_RRESP),
        .M06_AXI_rvalid(dpa_ctrl_interconnect_M06_AXI_RVALID),
        .M06_AXI_wdata(dpa_ctrl_interconnect_M06_AXI_WDATA),
        .M06_AXI_wready(dpa_ctrl_interconnect_M06_AXI_WREADY),
        .M06_AXI_wstrb(dpa_ctrl_interconnect_M06_AXI_WSTRB),
        .M06_AXI_wvalid(dpa_ctrl_interconnect_M06_AXI_WVALID),
        .M07_AXI_araddr(dpa_ctrl_interconnect_M07_AXI_ARADDR),
        .M07_AXI_arready(dpa_ctrl_interconnect_M07_AXI_ARREADY),
        .M07_AXI_arvalid(dpa_ctrl_interconnect_M07_AXI_ARVALID),
        .M07_AXI_awaddr(dpa_ctrl_interconnect_M07_AXI_AWADDR),
        .M07_AXI_awready(dpa_ctrl_interconnect_M07_AXI_AWREADY),
        .M07_AXI_awvalid(dpa_ctrl_interconnect_M07_AXI_AWVALID),
        .M07_AXI_bready(dpa_ctrl_interconnect_M07_AXI_BREADY),
        .M07_AXI_bresp(dpa_ctrl_interconnect_M07_AXI_BRESP),
        .M07_AXI_bvalid(dpa_ctrl_interconnect_M07_AXI_BVALID),
        .M07_AXI_rdata(dpa_ctrl_interconnect_M07_AXI_RDATA),
        .M07_AXI_rready(dpa_ctrl_interconnect_M07_AXI_RREADY),
        .M07_AXI_rresp(dpa_ctrl_interconnect_M07_AXI_RRESP),
        .M07_AXI_rvalid(dpa_ctrl_interconnect_M07_AXI_RVALID),
        .M07_AXI_wdata(dpa_ctrl_interconnect_M07_AXI_WDATA),
        .M07_AXI_wready(dpa_ctrl_interconnect_M07_AXI_WREADY),
        .M07_AXI_wstrb(dpa_ctrl_interconnect_M07_AXI_WSTRB),
        .M07_AXI_wvalid(dpa_ctrl_interconnect_M07_AXI_WVALID),
        .S00_AXI_araddr(icn_ctrl_1_M09_AXI_ARADDR),
        .S00_AXI_arburst(icn_ctrl_1_M09_AXI_ARBURST),
        .S00_AXI_arcache(icn_ctrl_1_M09_AXI_ARCACHE),
        .S00_AXI_arid(icn_ctrl_1_M09_AXI_ARID),
        .S00_AXI_arlen(icn_ctrl_1_M09_AXI_ARLEN),
        .S00_AXI_arlock(icn_ctrl_1_M09_AXI_ARLOCK),
        .S00_AXI_arprot(icn_ctrl_1_M09_AXI_ARPROT),
        .S00_AXI_arqos(icn_ctrl_1_M09_AXI_ARQOS),
        .S00_AXI_arready(icn_ctrl_1_M09_AXI_ARREADY),
        .S00_AXI_arsize(icn_ctrl_1_M09_AXI_ARSIZE),
        .S00_AXI_aruser(icn_ctrl_1_M09_AXI_ARUSER),
        .S00_AXI_arvalid(icn_ctrl_1_M09_AXI_ARVALID),
        .S00_AXI_awaddr(icn_ctrl_1_M09_AXI_AWADDR),
        .S00_AXI_awburst(icn_ctrl_1_M09_AXI_AWBURST),
        .S00_AXI_awcache(icn_ctrl_1_M09_AXI_AWCACHE),
        .S00_AXI_awid(icn_ctrl_1_M09_AXI_AWID),
        .S00_AXI_awlen(icn_ctrl_1_M09_AXI_AWLEN),
        .S00_AXI_awlock(icn_ctrl_1_M09_AXI_AWLOCK),
        .S00_AXI_awprot(icn_ctrl_1_M09_AXI_AWPROT),
        .S00_AXI_awqos(icn_ctrl_1_M09_AXI_AWQOS),
        .S00_AXI_awready(icn_ctrl_1_M09_AXI_AWREADY),
        .S00_AXI_awsize(icn_ctrl_1_M09_AXI_AWSIZE),
        .S00_AXI_awuser(icn_ctrl_1_M09_AXI_AWUSER),
        .S00_AXI_awvalid(icn_ctrl_1_M09_AXI_AWVALID),
        .S00_AXI_bid(icn_ctrl_1_M09_AXI_BID),
        .S00_AXI_bready(icn_ctrl_1_M09_AXI_BREADY),
        .S00_AXI_bresp(icn_ctrl_1_M09_AXI_BRESP),
        .S00_AXI_bvalid(icn_ctrl_1_M09_AXI_BVALID),
        .S00_AXI_rdata(icn_ctrl_1_M09_AXI_RDATA),
        .S00_AXI_rid(icn_ctrl_1_M09_AXI_RID),
        .S00_AXI_rlast(icn_ctrl_1_M09_AXI_RLAST),
        .S00_AXI_rready(icn_ctrl_1_M09_AXI_RREADY),
        .S00_AXI_rresp(icn_ctrl_1_M09_AXI_RRESP),
        .S00_AXI_ruser(icn_ctrl_1_M09_AXI_RUSER),
        .S00_AXI_rvalid(icn_ctrl_1_M09_AXI_RVALID),
        .S00_AXI_wdata(icn_ctrl_1_M09_AXI_WDATA),
        .S00_AXI_wlast(icn_ctrl_1_M09_AXI_WLAST),
        .S00_AXI_wready(icn_ctrl_1_M09_AXI_WREADY),
        .S00_AXI_wstrb(icn_ctrl_1_M09_AXI_WSTRB),
        .S00_AXI_wuser(icn_ctrl_1_M09_AXI_WUSER),
        .S00_AXI_wvalid(icn_ctrl_1_M09_AXI_WVALID),
        .aclk(clk_wizard_0_clk_out4_o1_o2),
        .aclk1(clk_wizard_0_clk_out4_o1_o2),
        .aresetn(psr_312mhz_peripheral_aresetn));
  vitis_design_dpa_hub_0 dpa_hub
       (.axilite_aresetn(psr_312mhz_peripheral_aresetn),
        .axilite_clk(clk_wizard_0_clk_out4_o1_o2),
        .s_axi_araddr(dpa_ctrl_interconnect_M00_AXI_ARADDR),
        .s_axi_arready(dpa_ctrl_interconnect_M00_AXI_ARREADY),
        .s_axi_arvalid(dpa_ctrl_interconnect_M00_AXI_ARVALID),
        .s_axi_awaddr(dpa_ctrl_interconnect_M00_AXI_AWADDR),
        .s_axi_awready(dpa_ctrl_interconnect_M00_AXI_AWREADY),
        .s_axi_awvalid(dpa_ctrl_interconnect_M00_AXI_AWVALID),
        .s_axi_bready(dpa_ctrl_interconnect_M00_AXI_BREADY),
        .s_axi_bresp(dpa_ctrl_interconnect_M00_AXI_BRESP),
        .s_axi_bvalid(dpa_ctrl_interconnect_M00_AXI_BVALID),
        .s_axi_rdata(dpa_ctrl_interconnect_M00_AXI_RDATA),
        .s_axi_rready(dpa_ctrl_interconnect_M00_AXI_RREADY),
        .s_axi_rresp(dpa_ctrl_interconnect_M00_AXI_RRESP),
        .s_axi_rvalid(dpa_ctrl_interconnect_M00_AXI_RVALID),
        .s_axi_wdata(dpa_ctrl_interconnect_M00_AXI_WDATA),
        .s_axi_wready(dpa_ctrl_interconnect_M00_AXI_WREADY),
        .s_axi_wstrb(dpa_ctrl_interconnect_M00_AXI_WSTRB),
        .s_axi_wvalid(dpa_ctrl_interconnect_M00_AXI_WVALID),
        .s_axihub_araddr(dpa_ctrl_interconnect_M01_AXI_ARADDR),
        .s_axihub_arready(dpa_ctrl_interconnect_M01_AXI_ARREADY),
        .s_axihub_arvalid(dpa_ctrl_interconnect_M01_AXI_ARVALID),
        .s_axihub_awaddr(dpa_ctrl_interconnect_M01_AXI_AWADDR),
        .s_axihub_awready(dpa_ctrl_interconnect_M01_AXI_AWREADY),
        .s_axihub_awvalid(dpa_ctrl_interconnect_M01_AXI_AWVALID),
        .s_axihub_bready(dpa_ctrl_interconnect_M01_AXI_BREADY),
        .s_axihub_bresp(dpa_ctrl_interconnect_M01_AXI_BRESP),
        .s_axihub_bvalid(dpa_ctrl_interconnect_M01_AXI_BVALID),
        .s_axihub_rdata(dpa_ctrl_interconnect_M01_AXI_RDATA),
        .s_axihub_rready(dpa_ctrl_interconnect_M01_AXI_RREADY),
        .s_axihub_rresp(dpa_ctrl_interconnect_M01_AXI_RRESP),
        .s_axihub_rvalid(dpa_ctrl_interconnect_M01_AXI_RVALID),
        .s_axihub_wdata(dpa_ctrl_interconnect_M01_AXI_WDATA),
        .s_axihub_wready(dpa_ctrl_interconnect_M01_AXI_WREADY),
        .s_axihub_wstrb(dpa_ctrl_interconnect_M01_AXI_WSTRB),
        .s_axihub_wvalid(dpa_ctrl_interconnect_M01_AXI_WVALID),
        .s_aximm_araddr(icn_ctrl_1_M10_AXI_ARADDR),
        .s_aximm_arburst(icn_ctrl_1_M10_AXI_ARBURST),
        .s_aximm_aresetn(psr_312mhz_peripheral_aresetn),
        .s_aximm_arid(1'b0),
        .s_aximm_arlen(icn_ctrl_1_M10_AXI_ARLEN),
        .s_aximm_arready(icn_ctrl_1_M10_AXI_ARREADY),
        .s_aximm_arsize(icn_ctrl_1_M10_AXI_ARSIZE),
        .s_aximm_arvalid(icn_ctrl_1_M10_AXI_ARVALID),
        .s_aximm_awaddr(icn_ctrl_1_M10_AXI_AWADDR),
        .s_aximm_awburst(icn_ctrl_1_M10_AXI_AWBURST),
        .s_aximm_awid(1'b0),
        .s_aximm_awlen(icn_ctrl_1_M10_AXI_AWLEN),
        .s_aximm_awready(icn_ctrl_1_M10_AXI_AWREADY),
        .s_aximm_awsize(icn_ctrl_1_M10_AXI_AWSIZE),
        .s_aximm_awvalid(icn_ctrl_1_M10_AXI_AWVALID),
        .s_aximm_bready(icn_ctrl_1_M10_AXI_BREADY),
        .s_aximm_bresp(icn_ctrl_1_M10_AXI_BRESP),
        .s_aximm_bvalid(icn_ctrl_1_M10_AXI_BVALID),
        .s_aximm_clk(clk_wizard_0_clk_out4_o1_o2),
        .s_aximm_rdata(icn_ctrl_1_M10_AXI_RDATA),
        .s_aximm_rlast(icn_ctrl_1_M10_AXI_RLAST),
        .s_aximm_rready(icn_ctrl_1_M10_AXI_RREADY),
        .s_aximm_rresp(icn_ctrl_1_M10_AXI_RRESP),
        .s_aximm_rvalid(icn_ctrl_1_M10_AXI_RVALID),
        .s_aximm_wdata(icn_ctrl_1_M10_AXI_WDATA),
        .s_aximm_wlast(icn_ctrl_1_M10_AXI_WLAST),
        .s_aximm_wready(icn_ctrl_1_M10_AXI_WREADY),
        .s_aximm_wstrb(icn_ctrl_1_M10_AXI_WSTRB),
        .s_aximm_wvalid(icn_ctrl_1_M10_AXI_WVALID),
        .trace_aresetn(psr_312mhz_peripheral_aresetn),
        .trace_clk(clk_wizard_0_clk_out4_o1_o2),
        .trace_tdata0(dpa_mon0_TRACE_OUT_0_TDATA),
        .trace_tdata1(dpa_mon0_TRACE_OUT_1_TDATA),
        .trace_tdata2(dpa_mon1_TRACE_OUT_TDATA),
        .trace_tdata3(dpa_mon2_TRACE_OUT_0_TDATA),
        .trace_tdata4(dpa_mon2_TRACE_OUT_1_TDATA),
        .trace_tdata5(dpa_mon3_TRACE_OUT_TDATA),
        .trace_tdata6(dpa_mon4_TRACE_OUT_0_TDATA),
        .trace_tdata7(dpa_mon4_TRACE_OUT_1_TDATA),
        .trace_tdata8(dpa_mon5_TRACE_OUT_TDATA),
        .trace_tdest0(dpa_mon0_TRACE_OUT_0_TDEST),
        .trace_tdest1(dpa_mon0_TRACE_OUT_1_TDEST),
        .trace_tdest2(dpa_mon1_TRACE_OUT_TDEST),
        .trace_tdest3(dpa_mon2_TRACE_OUT_0_TDEST),
        .trace_tdest4(dpa_mon2_TRACE_OUT_1_TDEST),
        .trace_tdest5(dpa_mon3_TRACE_OUT_TDEST),
        .trace_tdest6(dpa_mon4_TRACE_OUT_0_TDEST),
        .trace_tdest7(dpa_mon4_TRACE_OUT_1_TDEST),
        .trace_tdest8(dpa_mon5_TRACE_OUT_TDEST),
        .trace_tid0(dpa_mon0_TRACE_OUT_0_TID),
        .trace_tid1(dpa_mon0_TRACE_OUT_1_TID),
        .trace_tid2(dpa_mon1_TRACE_OUT_TID),
        .trace_tid3(dpa_mon2_TRACE_OUT_0_TID),
        .trace_tid4(dpa_mon2_TRACE_OUT_1_TID),
        .trace_tid5(dpa_mon3_TRACE_OUT_TID),
        .trace_tid6(dpa_mon4_TRACE_OUT_0_TID),
        .trace_tid7(dpa_mon4_TRACE_OUT_1_TID),
        .trace_tid8(dpa_mon5_TRACE_OUT_TID),
        .trace_tlast0(dpa_mon0_TRACE_OUT_0_TLAST),
        .trace_tlast1(dpa_mon0_TRACE_OUT_1_TLAST),
        .trace_tlast2(dpa_mon1_TRACE_OUT_TLAST),
        .trace_tlast3(dpa_mon2_TRACE_OUT_0_TLAST),
        .trace_tlast4(dpa_mon2_TRACE_OUT_1_TLAST),
        .trace_tlast5(dpa_mon3_TRACE_OUT_TLAST),
        .trace_tlast6(dpa_mon4_TRACE_OUT_0_TLAST),
        .trace_tlast7(dpa_mon4_TRACE_OUT_1_TLAST),
        .trace_tlast8(dpa_mon5_TRACE_OUT_TLAST),
        .trace_tready0(dpa_mon0_TRACE_OUT_0_TREADY),
        .trace_tready1(dpa_mon0_TRACE_OUT_1_TREADY),
        .trace_tready2(dpa_mon1_TRACE_OUT_TREADY),
        .trace_tready3(dpa_mon2_TRACE_OUT_0_TREADY),
        .trace_tready4(dpa_mon2_TRACE_OUT_1_TREADY),
        .trace_tready5(dpa_mon3_TRACE_OUT_TREADY),
        .trace_tready6(dpa_mon4_TRACE_OUT_0_TREADY),
        .trace_tready7(dpa_mon4_TRACE_OUT_1_TREADY),
        .trace_tready8(dpa_mon5_TRACE_OUT_TREADY),
        .trace_tvalid0(dpa_mon0_TRACE_OUT_0_TVALID),
        .trace_tvalid1(dpa_mon0_TRACE_OUT_1_TVALID),
        .trace_tvalid2(dpa_mon1_TRACE_OUT_TVALID),
        .trace_tvalid3(dpa_mon2_TRACE_OUT_0_TVALID),
        .trace_tvalid4(dpa_mon2_TRACE_OUT_1_TVALID),
        .trace_tvalid5(dpa_mon3_TRACE_OUT_TVALID),
        .trace_tvalid6(dpa_mon4_TRACE_OUT_0_TVALID),
        .trace_tvalid7(dpa_mon4_TRACE_OUT_1_TVALID),
        .trace_tvalid8(dpa_mon5_TRACE_OUT_TVALID));
  (* DPA_IP_FULLNAME = "/mm2s_1/m_axi_gmem-DDR" *) 
  vitis_design_dpa_mon0_0 dpa_mon0
       (.m_axis_rd_tdata(dpa_mon0_TRACE_OUT_1_TDATA),
        .m_axis_rd_tdest(dpa_mon0_TRACE_OUT_1_TDEST),
        .m_axis_rd_tid(dpa_mon0_TRACE_OUT_1_TID),
        .m_axis_rd_tlast(dpa_mon0_TRACE_OUT_1_TLAST),
        .m_axis_rd_tready(dpa_mon0_TRACE_OUT_1_TREADY),
        .m_axis_rd_tvalid(dpa_mon0_TRACE_OUT_1_TVALID),
        .m_axis_wr_tdata(dpa_mon0_TRACE_OUT_0_TDATA),
        .m_axis_wr_tdest(dpa_mon0_TRACE_OUT_0_TDEST),
        .m_axis_wr_tid(dpa_mon0_TRACE_OUT_0_TID),
        .m_axis_wr_tlast(dpa_mon0_TRACE_OUT_0_TLAST),
        .m_axis_wr_tready(dpa_mon0_TRACE_OUT_0_TREADY),
        .m_axis_wr_tvalid(dpa_mon0_TRACE_OUT_0_TVALID),
        .mon_ARADDR(mm2s_1_m_axi_gmem_ARADDR),
        .mon_ARBURST(mm2s_1_m_axi_gmem_ARBURST),
        .mon_ARID(mm2s_1_m_axi_gmem_ARID),
        .mon_ARLEN(mm2s_1_m_axi_gmem_ARLEN),
        .mon_ARREADY(mm2s_1_m_axi_gmem_ARREADY),
        .mon_ARSIZE(mm2s_1_m_axi_gmem_ARSIZE),
        .mon_ARVALID(mm2s_1_m_axi_gmem_ARVALID),
        .mon_AWADDR(mm2s_1_m_axi_gmem_AWADDR),
        .mon_AWBURST(mm2s_1_m_axi_gmem_AWBURST),
        .mon_AWID(mm2s_1_m_axi_gmem_AWID),
        .mon_AWLEN(mm2s_1_m_axi_gmem_AWLEN),
        .mon_AWREADY(mm2s_1_m_axi_gmem_AWREADY),
        .mon_AWSIZE(mm2s_1_m_axi_gmem_AWSIZE),
        .mon_AWVALID(mm2s_1_m_axi_gmem_AWVALID),
        .mon_BID(mm2s_1_m_axi_gmem_BID),
        .mon_BREADY(mm2s_1_m_axi_gmem_BREADY),
        .mon_BRESP(mm2s_1_m_axi_gmem_BRESP),
        .mon_BVALID(mm2s_1_m_axi_gmem_BVALID),
        .mon_RDATA(mm2s_1_m_axi_gmem_RDATA),
        .mon_RID(mm2s_1_m_axi_gmem_RID),
        .mon_RLAST(mm2s_1_m_axi_gmem_RLAST),
        .mon_RREADY(mm2s_1_m_axi_gmem_RREADY),
        .mon_RRESP(mm2s_1_m_axi_gmem_RRESP),
        .mon_RVALID(mm2s_1_m_axi_gmem_RVALID),
        .mon_WDATA(mm2s_1_m_axi_gmem_WDATA),
        .mon_WLAST(mm2s_1_m_axi_gmem_WLAST),
        .mon_WREADY(mm2s_1_m_axi_gmem_WREADY),
        .mon_WSTRB(mm2s_1_m_axi_gmem_WSTRB),
        .mon_WVALID(mm2s_1_m_axi_gmem_WVALID),
        .mon_clk(clk_wizard_0_clk_out4_o1_o2),
        .mon_resetn(psr_312mhz_peripheral_aresetn),
        .s_axi_araddr(dpa_ctrl_interconnect_M02_AXI_ARADDR),
        .s_axi_araddr_mon({1'b0,1'b0,icn_ctrl_1_M06_AXI_ARADDR}),
        .s_axi_arprot_mon(icn_ctrl_1_M06_AXI_ARPROT),
        .s_axi_arready(dpa_ctrl_interconnect_M02_AXI_ARREADY),
        .s_axi_arready_mon(icn_ctrl_1_M06_AXI_ARREADY),
        .s_axi_arvalid(dpa_ctrl_interconnect_M02_AXI_ARVALID),
        .s_axi_arvalid_mon(icn_ctrl_1_M06_AXI_ARVALID),
        .s_axi_awaddr(dpa_ctrl_interconnect_M02_AXI_AWADDR),
        .s_axi_awaddr_mon({1'b0,1'b0,icn_ctrl_1_M06_AXI_AWADDR}),
        .s_axi_awprot_mon(icn_ctrl_1_M06_AXI_AWPROT),
        .s_axi_awready(dpa_ctrl_interconnect_M02_AXI_AWREADY),
        .s_axi_awready_mon(icn_ctrl_1_M06_AXI_AWREADY),
        .s_axi_awvalid(dpa_ctrl_interconnect_M02_AXI_AWVALID),
        .s_axi_awvalid_mon(icn_ctrl_1_M06_AXI_AWVALID),
        .s_axi_bready(dpa_ctrl_interconnect_M02_AXI_BREADY),
        .s_axi_bready_mon(icn_ctrl_1_M06_AXI_BREADY),
        .s_axi_bresp(dpa_ctrl_interconnect_M02_AXI_BRESP),
        .s_axi_bresp_mon(icn_ctrl_1_M06_AXI_BRESP),
        .s_axi_bvalid(dpa_ctrl_interconnect_M02_AXI_BVALID),
        .s_axi_bvalid_mon(icn_ctrl_1_M06_AXI_BVALID),
        .s_axi_rdata(dpa_ctrl_interconnect_M02_AXI_RDATA),
        .s_axi_rdata_mon(icn_ctrl_1_M06_AXI_RDATA),
        .s_axi_rready(dpa_ctrl_interconnect_M02_AXI_RREADY),
        .s_axi_rready_mon(icn_ctrl_1_M06_AXI_RREADY),
        .s_axi_rresp(dpa_ctrl_interconnect_M02_AXI_RRESP),
        .s_axi_rresp_mon(icn_ctrl_1_M06_AXI_RRESP),
        .s_axi_rvalid(dpa_ctrl_interconnect_M02_AXI_RVALID),
        .s_axi_rvalid_mon(icn_ctrl_1_M06_AXI_RVALID),
        .s_axi_wdata(dpa_ctrl_interconnect_M02_AXI_WDATA),
        .s_axi_wdata_mon(icn_ctrl_1_M06_AXI_WDATA),
        .s_axi_wready(dpa_ctrl_interconnect_M02_AXI_WREADY),
        .s_axi_wready_mon(icn_ctrl_1_M06_AXI_WREADY),
        .s_axi_wstrb(dpa_ctrl_interconnect_M02_AXI_WSTRB),
        .s_axi_wstrb_mon(icn_ctrl_1_M06_AXI_WSTRB),
        .s_axi_wvalid(dpa_ctrl_interconnect_M02_AXI_WVALID),
        .s_axi_wvalid_mon(icn_ctrl_1_M06_AXI_WVALID),
        .trace_clk(clk_wizard_0_clk_out4_o1_o2),
        .trace_rst(psr_312mhz_peripheral_aresetn));
  (* DPA_IP_FULLNAME = "mm2s_1/s-dwc_mm2s_1_s/S_AXIS" *) 
  vitis_design_dpa_mon1_0 dpa_mon1
       (.m_axis_tdata(dpa_mon1_TRACE_OUT_TDATA),
        .m_axis_tdest(dpa_mon1_TRACE_OUT_TDEST),
        .m_axis_tid(dpa_mon1_TRACE_OUT_TID),
        .m_axis_tlast(dpa_mon1_TRACE_OUT_TLAST),
        .m_axis_tready(dpa_mon1_TRACE_OUT_TREADY),
        .m_axis_tvalid(dpa_mon1_TRACE_OUT_TVALID),
        .mon_clk(clk_wizard_0_clk_out4_o1_o2),
        .mon_resetn(psr_312mhz_peripheral_aresetn),
        .s_axi_araddr(dpa_ctrl_interconnect_M03_AXI_ARADDR),
        .s_axi_arready(dpa_ctrl_interconnect_M03_AXI_ARREADY),
        .s_axi_arvalid(dpa_ctrl_interconnect_M03_AXI_ARVALID),
        .s_axi_awaddr(dpa_ctrl_interconnect_M03_AXI_AWADDR),
        .s_axi_awready(dpa_ctrl_interconnect_M03_AXI_AWREADY),
        .s_axi_awvalid(dpa_ctrl_interconnect_M03_AXI_AWVALID),
        .s_axi_bready(dpa_ctrl_interconnect_M03_AXI_BREADY),
        .s_axi_bresp(dpa_ctrl_interconnect_M03_AXI_BRESP),
        .s_axi_bvalid(dpa_ctrl_interconnect_M03_AXI_BVALID),
        .s_axi_rdata(dpa_ctrl_interconnect_M03_AXI_RDATA),
        .s_axi_rready(dpa_ctrl_interconnect_M03_AXI_RREADY),
        .s_axi_rresp(dpa_ctrl_interconnect_M03_AXI_RRESP),
        .s_axi_rvalid(dpa_ctrl_interconnect_M03_AXI_RVALID),
        .s_axi_wdata(dpa_ctrl_interconnect_M03_AXI_WDATA),
        .s_axi_wready(dpa_ctrl_interconnect_M03_AXI_WREADY),
        .s_axi_wstrb(dpa_ctrl_interconnect_M03_AXI_WSTRB),
        .s_axi_wvalid(dpa_ctrl_interconnect_M03_AXI_WVALID),
        .s_axis_mon_tdata(mm2s_1_s_TDATA),
        .s_axis_mon_tdest(1'b0),
        .s_axis_mon_tid(1'b0),
        .s_axis_mon_tlast(mm2s_1_s_TLAST),
        .s_axis_mon_tready(mm2s_1_s_TREADY),
        .s_axis_mon_tvalid(mm2s_1_s_TVALID),
        .trace_clk(clk_wizard_0_clk_out4_o1_o2),
        .trace_rst(psr_312mhz_peripheral_aresetn));
  (* DPA_IP_FULLNAME = "/mm2s_2/m_axi_gmem-DDR" *) 
  vitis_design_dpa_mon2_0 dpa_mon2
       (.m_axis_rd_tdata(dpa_mon2_TRACE_OUT_1_TDATA),
        .m_axis_rd_tdest(dpa_mon2_TRACE_OUT_1_TDEST),
        .m_axis_rd_tid(dpa_mon2_TRACE_OUT_1_TID),
        .m_axis_rd_tlast(dpa_mon2_TRACE_OUT_1_TLAST),
        .m_axis_rd_tready(dpa_mon2_TRACE_OUT_1_TREADY),
        .m_axis_rd_tvalid(dpa_mon2_TRACE_OUT_1_TVALID),
        .m_axis_wr_tdata(dpa_mon2_TRACE_OUT_0_TDATA),
        .m_axis_wr_tdest(dpa_mon2_TRACE_OUT_0_TDEST),
        .m_axis_wr_tid(dpa_mon2_TRACE_OUT_0_TID),
        .m_axis_wr_tlast(dpa_mon2_TRACE_OUT_0_TLAST),
        .m_axis_wr_tready(dpa_mon2_TRACE_OUT_0_TREADY),
        .m_axis_wr_tvalid(dpa_mon2_TRACE_OUT_0_TVALID),
        .mon_ARADDR(mm2s_2_m_axi_gmem_ARADDR),
        .mon_ARBURST(mm2s_2_m_axi_gmem_ARBURST),
        .mon_ARID(mm2s_2_m_axi_gmem_ARID),
        .mon_ARLEN(mm2s_2_m_axi_gmem_ARLEN),
        .mon_ARREADY(mm2s_2_m_axi_gmem_ARREADY),
        .mon_ARSIZE(mm2s_2_m_axi_gmem_ARSIZE),
        .mon_ARVALID(mm2s_2_m_axi_gmem_ARVALID),
        .mon_AWADDR(mm2s_2_m_axi_gmem_AWADDR),
        .mon_AWBURST(mm2s_2_m_axi_gmem_AWBURST),
        .mon_AWID(mm2s_2_m_axi_gmem_AWID),
        .mon_AWLEN(mm2s_2_m_axi_gmem_AWLEN),
        .mon_AWREADY(mm2s_2_m_axi_gmem_AWREADY),
        .mon_AWSIZE(mm2s_2_m_axi_gmem_AWSIZE),
        .mon_AWVALID(mm2s_2_m_axi_gmem_AWVALID),
        .mon_BID(mm2s_2_m_axi_gmem_BID),
        .mon_BREADY(mm2s_2_m_axi_gmem_BREADY),
        .mon_BRESP(mm2s_2_m_axi_gmem_BRESP),
        .mon_BVALID(mm2s_2_m_axi_gmem_BVALID),
        .mon_RDATA(mm2s_2_m_axi_gmem_RDATA),
        .mon_RID(mm2s_2_m_axi_gmem_RID),
        .mon_RLAST(mm2s_2_m_axi_gmem_RLAST),
        .mon_RREADY(mm2s_2_m_axi_gmem_RREADY),
        .mon_RRESP(mm2s_2_m_axi_gmem_RRESP),
        .mon_RVALID(mm2s_2_m_axi_gmem_RVALID),
        .mon_WDATA(mm2s_2_m_axi_gmem_WDATA),
        .mon_WLAST(mm2s_2_m_axi_gmem_WLAST),
        .mon_WREADY(mm2s_2_m_axi_gmem_WREADY),
        .mon_WSTRB(mm2s_2_m_axi_gmem_WSTRB),
        .mon_WVALID(mm2s_2_m_axi_gmem_WVALID),
        .mon_clk(clk_wizard_0_clk_out4_o1_o2),
        .mon_resetn(psr_312mhz_peripheral_aresetn),
        .s_axi_araddr(dpa_ctrl_interconnect_M04_AXI_ARADDR),
        .s_axi_araddr_mon({1'b0,1'b0,icn_ctrl_1_M07_AXI_ARADDR}),
        .s_axi_arprot_mon(icn_ctrl_1_M07_AXI_ARPROT),
        .s_axi_arready(dpa_ctrl_interconnect_M04_AXI_ARREADY),
        .s_axi_arready_mon(icn_ctrl_1_M07_AXI_ARREADY),
        .s_axi_arvalid(dpa_ctrl_interconnect_M04_AXI_ARVALID),
        .s_axi_arvalid_mon(icn_ctrl_1_M07_AXI_ARVALID),
        .s_axi_awaddr(dpa_ctrl_interconnect_M04_AXI_AWADDR),
        .s_axi_awaddr_mon({1'b0,1'b0,icn_ctrl_1_M07_AXI_AWADDR}),
        .s_axi_awprot_mon(icn_ctrl_1_M07_AXI_AWPROT),
        .s_axi_awready(dpa_ctrl_interconnect_M04_AXI_AWREADY),
        .s_axi_awready_mon(icn_ctrl_1_M07_AXI_AWREADY),
        .s_axi_awvalid(dpa_ctrl_interconnect_M04_AXI_AWVALID),
        .s_axi_awvalid_mon(icn_ctrl_1_M07_AXI_AWVALID),
        .s_axi_bready(dpa_ctrl_interconnect_M04_AXI_BREADY),
        .s_axi_bready_mon(icn_ctrl_1_M07_AXI_BREADY),
        .s_axi_bresp(dpa_ctrl_interconnect_M04_AXI_BRESP),
        .s_axi_bresp_mon(icn_ctrl_1_M07_AXI_BRESP),
        .s_axi_bvalid(dpa_ctrl_interconnect_M04_AXI_BVALID),
        .s_axi_bvalid_mon(icn_ctrl_1_M07_AXI_BVALID),
        .s_axi_rdata(dpa_ctrl_interconnect_M04_AXI_RDATA),
        .s_axi_rdata_mon(icn_ctrl_1_M07_AXI_RDATA),
        .s_axi_rready(dpa_ctrl_interconnect_M04_AXI_RREADY),
        .s_axi_rready_mon(icn_ctrl_1_M07_AXI_RREADY),
        .s_axi_rresp(dpa_ctrl_interconnect_M04_AXI_RRESP),
        .s_axi_rresp_mon(icn_ctrl_1_M07_AXI_RRESP),
        .s_axi_rvalid(dpa_ctrl_interconnect_M04_AXI_RVALID),
        .s_axi_rvalid_mon(icn_ctrl_1_M07_AXI_RVALID),
        .s_axi_wdata(dpa_ctrl_interconnect_M04_AXI_WDATA),
        .s_axi_wdata_mon(icn_ctrl_1_M07_AXI_WDATA),
        .s_axi_wready(dpa_ctrl_interconnect_M04_AXI_WREADY),
        .s_axi_wready_mon(icn_ctrl_1_M07_AXI_WREADY),
        .s_axi_wstrb(dpa_ctrl_interconnect_M04_AXI_WSTRB),
        .s_axi_wstrb_mon(icn_ctrl_1_M07_AXI_WSTRB),
        .s_axi_wvalid(dpa_ctrl_interconnect_M04_AXI_WVALID),
        .s_axi_wvalid_mon(icn_ctrl_1_M07_AXI_WVALID),
        .trace_clk(clk_wizard_0_clk_out4_o1_o2),
        .trace_rst(psr_312mhz_peripheral_aresetn));
  (* DPA_IP_FULLNAME = "mm2s_2/s-dwc_mm2s_2_s/S_AXIS" *) 
  vitis_design_dpa_mon3_0 dpa_mon3
       (.m_axis_tdata(dpa_mon3_TRACE_OUT_TDATA),
        .m_axis_tdest(dpa_mon3_TRACE_OUT_TDEST),
        .m_axis_tid(dpa_mon3_TRACE_OUT_TID),
        .m_axis_tlast(dpa_mon3_TRACE_OUT_TLAST),
        .m_axis_tready(dpa_mon3_TRACE_OUT_TREADY),
        .m_axis_tvalid(dpa_mon3_TRACE_OUT_TVALID),
        .mon_clk(clk_wizard_0_clk_out4_o1_o2),
        .mon_resetn(psr_312mhz_peripheral_aresetn),
        .s_axi_araddr(dpa_ctrl_interconnect_M05_AXI_ARADDR),
        .s_axi_arready(dpa_ctrl_interconnect_M05_AXI_ARREADY),
        .s_axi_arvalid(dpa_ctrl_interconnect_M05_AXI_ARVALID),
        .s_axi_awaddr(dpa_ctrl_interconnect_M05_AXI_AWADDR),
        .s_axi_awready(dpa_ctrl_interconnect_M05_AXI_AWREADY),
        .s_axi_awvalid(dpa_ctrl_interconnect_M05_AXI_AWVALID),
        .s_axi_bready(dpa_ctrl_interconnect_M05_AXI_BREADY),
        .s_axi_bresp(dpa_ctrl_interconnect_M05_AXI_BRESP),
        .s_axi_bvalid(dpa_ctrl_interconnect_M05_AXI_BVALID),
        .s_axi_rdata(dpa_ctrl_interconnect_M05_AXI_RDATA),
        .s_axi_rready(dpa_ctrl_interconnect_M05_AXI_RREADY),
        .s_axi_rresp(dpa_ctrl_interconnect_M05_AXI_RRESP),
        .s_axi_rvalid(dpa_ctrl_interconnect_M05_AXI_RVALID),
        .s_axi_wdata(dpa_ctrl_interconnect_M05_AXI_WDATA),
        .s_axi_wready(dpa_ctrl_interconnect_M05_AXI_WREADY),
        .s_axi_wstrb(dpa_ctrl_interconnect_M05_AXI_WSTRB),
        .s_axi_wvalid(dpa_ctrl_interconnect_M05_AXI_WVALID),
        .s_axis_mon_tdata(mm2s_2_s_TDATA),
        .s_axis_mon_tdest(1'b0),
        .s_axis_mon_tid(1'b0),
        .s_axis_mon_tlast(mm2s_2_s_TLAST),
        .s_axis_mon_tready(mm2s_2_s_TREADY),
        .s_axis_mon_tvalid(mm2s_2_s_TVALID),
        .trace_clk(clk_wizard_0_clk_out4_o1_o2),
        .trace_rst(psr_312mhz_peripheral_aresetn));
  (* DPA_IP_FULLNAME = "/s2mm/m_axi_gmem-DDR" *) 
  vitis_design_dpa_mon4_0 dpa_mon4
       (.m_axis_rd_tdata(dpa_mon4_TRACE_OUT_1_TDATA),
        .m_axis_rd_tdest(dpa_mon4_TRACE_OUT_1_TDEST),
        .m_axis_rd_tid(dpa_mon4_TRACE_OUT_1_TID),
        .m_axis_rd_tlast(dpa_mon4_TRACE_OUT_1_TLAST),
        .m_axis_rd_tready(dpa_mon4_TRACE_OUT_1_TREADY),
        .m_axis_rd_tvalid(dpa_mon4_TRACE_OUT_1_TVALID),
        .m_axis_wr_tdata(dpa_mon4_TRACE_OUT_0_TDATA),
        .m_axis_wr_tdest(dpa_mon4_TRACE_OUT_0_TDEST),
        .m_axis_wr_tid(dpa_mon4_TRACE_OUT_0_TID),
        .m_axis_wr_tlast(dpa_mon4_TRACE_OUT_0_TLAST),
        .m_axis_wr_tready(dpa_mon4_TRACE_OUT_0_TREADY),
        .m_axis_wr_tvalid(dpa_mon4_TRACE_OUT_0_TVALID),
        .mon_ARADDR(s2mm_m_axi_gmem_ARADDR),
        .mon_ARBURST(s2mm_m_axi_gmem_ARBURST),
        .mon_ARID(s2mm_m_axi_gmem_ARID),
        .mon_ARLEN(s2mm_m_axi_gmem_ARLEN),
        .mon_ARREADY(s2mm_m_axi_gmem_ARREADY),
        .mon_ARSIZE(s2mm_m_axi_gmem_ARSIZE),
        .mon_ARVALID(s2mm_m_axi_gmem_ARVALID),
        .mon_AWADDR(s2mm_m_axi_gmem_AWADDR),
        .mon_AWBURST(s2mm_m_axi_gmem_AWBURST),
        .mon_AWID(s2mm_m_axi_gmem_AWID),
        .mon_AWLEN(s2mm_m_axi_gmem_AWLEN),
        .mon_AWREADY(s2mm_m_axi_gmem_AWREADY),
        .mon_AWSIZE(s2mm_m_axi_gmem_AWSIZE),
        .mon_AWVALID(s2mm_m_axi_gmem_AWVALID),
        .mon_BID(s2mm_m_axi_gmem_BID),
        .mon_BREADY(s2mm_m_axi_gmem_BREADY),
        .mon_BRESP(s2mm_m_axi_gmem_BRESP),
        .mon_BVALID(s2mm_m_axi_gmem_BVALID),
        .mon_RDATA(s2mm_m_axi_gmem_RDATA),
        .mon_RID(s2mm_m_axi_gmem_RID),
        .mon_RLAST(s2mm_m_axi_gmem_RLAST),
        .mon_RREADY(s2mm_m_axi_gmem_RREADY),
        .mon_RRESP(s2mm_m_axi_gmem_RRESP),
        .mon_RVALID(s2mm_m_axi_gmem_RVALID),
        .mon_WDATA(s2mm_m_axi_gmem_WDATA),
        .mon_WLAST(s2mm_m_axi_gmem_WLAST),
        .mon_WREADY(s2mm_m_axi_gmem_WREADY),
        .mon_WSTRB(s2mm_m_axi_gmem_WSTRB),
        .mon_WVALID(s2mm_m_axi_gmem_WVALID),
        .mon_clk(clk_wizard_0_clk_out4_o1_o2),
        .mon_resetn(psr_312mhz_peripheral_aresetn),
        .s_axi_araddr(dpa_ctrl_interconnect_M06_AXI_ARADDR),
        .s_axi_araddr_mon({1'b0,1'b0,icn_ctrl_1_M08_AXI_ARADDR}),
        .s_axi_arprot_mon(icn_ctrl_1_M08_AXI_ARPROT),
        .s_axi_arready(dpa_ctrl_interconnect_M06_AXI_ARREADY),
        .s_axi_arready_mon(icn_ctrl_1_M08_AXI_ARREADY),
        .s_axi_arvalid(dpa_ctrl_interconnect_M06_AXI_ARVALID),
        .s_axi_arvalid_mon(icn_ctrl_1_M08_AXI_ARVALID),
        .s_axi_awaddr(dpa_ctrl_interconnect_M06_AXI_AWADDR),
        .s_axi_awaddr_mon({1'b0,1'b0,icn_ctrl_1_M08_AXI_AWADDR}),
        .s_axi_awprot_mon(icn_ctrl_1_M08_AXI_AWPROT),
        .s_axi_awready(dpa_ctrl_interconnect_M06_AXI_AWREADY),
        .s_axi_awready_mon(icn_ctrl_1_M08_AXI_AWREADY),
        .s_axi_awvalid(dpa_ctrl_interconnect_M06_AXI_AWVALID),
        .s_axi_awvalid_mon(icn_ctrl_1_M08_AXI_AWVALID),
        .s_axi_bready(dpa_ctrl_interconnect_M06_AXI_BREADY),
        .s_axi_bready_mon(icn_ctrl_1_M08_AXI_BREADY),
        .s_axi_bresp(dpa_ctrl_interconnect_M06_AXI_BRESP),
        .s_axi_bresp_mon(icn_ctrl_1_M08_AXI_BRESP),
        .s_axi_bvalid(dpa_ctrl_interconnect_M06_AXI_BVALID),
        .s_axi_bvalid_mon(icn_ctrl_1_M08_AXI_BVALID),
        .s_axi_rdata(dpa_ctrl_interconnect_M06_AXI_RDATA),
        .s_axi_rdata_mon(icn_ctrl_1_M08_AXI_RDATA),
        .s_axi_rready(dpa_ctrl_interconnect_M06_AXI_RREADY),
        .s_axi_rready_mon(icn_ctrl_1_M08_AXI_RREADY),
        .s_axi_rresp(dpa_ctrl_interconnect_M06_AXI_RRESP),
        .s_axi_rresp_mon(icn_ctrl_1_M08_AXI_RRESP),
        .s_axi_rvalid(dpa_ctrl_interconnect_M06_AXI_RVALID),
        .s_axi_rvalid_mon(icn_ctrl_1_M08_AXI_RVALID),
        .s_axi_wdata(dpa_ctrl_interconnect_M06_AXI_WDATA),
        .s_axi_wdata_mon(icn_ctrl_1_M08_AXI_WDATA),
        .s_axi_wready(dpa_ctrl_interconnect_M06_AXI_WREADY),
        .s_axi_wready_mon(icn_ctrl_1_M08_AXI_WREADY),
        .s_axi_wstrb(dpa_ctrl_interconnect_M06_AXI_WSTRB),
        .s_axi_wstrb_mon(icn_ctrl_1_M08_AXI_WSTRB),
        .s_axi_wvalid(dpa_ctrl_interconnect_M06_AXI_WVALID),
        .s_axi_wvalid_mon(icn_ctrl_1_M08_AXI_WVALID),
        .trace_clk(clk_wizard_0_clk_out4_o1_o2),
        .trace_rst(psr_312mhz_peripheral_aresetn));
  (* DPA_IP_FULLNAME = "dwc_ai_engine_0_M00_AXIS/M_AXIS-s2mm/s" *) 
  vitis_design_dpa_mon5_0 dpa_mon5
       (.m_axis_tdata(dpa_mon5_TRACE_OUT_TDATA),
        .m_axis_tdest(dpa_mon5_TRACE_OUT_TDEST),
        .m_axis_tid(dpa_mon5_TRACE_OUT_TID),
        .m_axis_tlast(dpa_mon5_TRACE_OUT_TLAST),
        .m_axis_tready(dpa_mon5_TRACE_OUT_TREADY),
        .m_axis_tvalid(dpa_mon5_TRACE_OUT_TVALID),
        .mon_clk(clk_wizard_0_clk_out4_o1_o2),
        .mon_resetn(psr_312mhz_peripheral_aresetn),
        .s_axi_araddr(dpa_ctrl_interconnect_M07_AXI_ARADDR),
        .s_axi_arready(dpa_ctrl_interconnect_M07_AXI_ARREADY),
        .s_axi_arvalid(dpa_ctrl_interconnect_M07_AXI_ARVALID),
        .s_axi_awaddr(dpa_ctrl_interconnect_M07_AXI_AWADDR),
        .s_axi_awready(dpa_ctrl_interconnect_M07_AXI_AWREADY),
        .s_axi_awvalid(dpa_ctrl_interconnect_M07_AXI_AWVALID),
        .s_axi_bready(dpa_ctrl_interconnect_M07_AXI_BREADY),
        .s_axi_bresp(dpa_ctrl_interconnect_M07_AXI_BRESP),
        .s_axi_bvalid(dpa_ctrl_interconnect_M07_AXI_BVALID),
        .s_axi_rdata(dpa_ctrl_interconnect_M07_AXI_RDATA),
        .s_axi_rready(dpa_ctrl_interconnect_M07_AXI_RREADY),
        .s_axi_rresp(dpa_ctrl_interconnect_M07_AXI_RRESP),
        .s_axi_rvalid(dpa_ctrl_interconnect_M07_AXI_RVALID),
        .s_axi_wdata(dpa_ctrl_interconnect_M07_AXI_WDATA),
        .s_axi_wready(dpa_ctrl_interconnect_M07_AXI_WREADY),
        .s_axi_wstrb(dpa_ctrl_interconnect_M07_AXI_WSTRB),
        .s_axi_wvalid(dpa_ctrl_interconnect_M07_AXI_WVALID),
        .s_axis_mon_tdata(dwc_ai_engine_0_M00_AXIS_M_AXIS_TDATA),
        .s_axis_mon_tdest(1'b0),
        .s_axis_mon_tid(1'b0),
        .s_axis_mon_tlast(dwc_ai_engine_0_M00_AXIS_M_AXIS_TLAST),
        .s_axis_mon_tready(dwc_ai_engine_0_M00_AXIS_M_AXIS_TREADY),
        .s_axis_mon_tvalid(dwc_ai_engine_0_M00_AXIS_M_AXIS_TVALID),
        .trace_clk(clk_wizard_0_clk_out4_o1_o2),
        .trace_rst(psr_312mhz_peripheral_aresetn));
endmodule

module VitisRegion_imp_9ASBXH
   (M_AXIS1_tdata,
    M_AXIS1_tkeep,
    M_AXIS1_tlast,
    M_AXIS1_tready,
    M_AXIS1_tvalid,
    M_AXIS_tdata,
    M_AXIS_tkeep,
    M_AXIS_tlast,
    M_AXIS_tready,
    M_AXIS_tvalid,
    S00_AXI_araddr,
    S00_AXI_arburst,
    S00_AXI_arcache,
    S00_AXI_arid,
    S00_AXI_arlen,
    S00_AXI_arlock,
    S00_AXI_arprot,
    S00_AXI_arqos,
    S00_AXI_arready,
    S00_AXI_arsize,
    S00_AXI_aruser,
    S00_AXI_arvalid,
    S00_AXI_awaddr,
    S00_AXI_awburst,
    S00_AXI_awcache,
    S00_AXI_awid,
    S00_AXI_awlen,
    S00_AXI_awlock,
    S00_AXI_awprot,
    S00_AXI_awqos,
    S00_AXI_awready,
    S00_AXI_awsize,
    S00_AXI_awuser,
    S00_AXI_awvalid,
    S00_AXI_bid,
    S00_AXI_bready,
    S00_AXI_bresp,
    S00_AXI_bvalid,
    S00_AXI_rdata,
    S00_AXI_rid,
    S00_AXI_rlast,
    S00_AXI_rready,
    S00_AXI_rresp,
    S00_AXI_ruser,
    S00_AXI_rvalid,
    S00_AXI_wdata,
    S00_AXI_wlast,
    S00_AXI_wready,
    S00_AXI_wstrb,
    S00_AXI_wuser,
    S00_AXI_wvalid,
    S_AXIMM_araddr,
    S_AXIMM_arburst,
    S_AXIMM_arlen,
    S_AXIMM_arready,
    S_AXIMM_arsize,
    S_AXIMM_arvalid,
    S_AXIMM_awaddr,
    S_AXIMM_awburst,
    S_AXIMM_awlen,
    S_AXIMM_awready,
    S_AXIMM_awsize,
    S_AXIMM_awvalid,
    S_AXIMM_bready,
    S_AXIMM_bresp,
    S_AXIMM_bvalid,
    S_AXIMM_rdata,
    S_AXIMM_rlast,
    S_AXIMM_rready,
    S_AXIMM_rresp,
    S_AXIMM_rvalid,
    S_AXIMM_wdata,
    S_AXIMM_wlast,
    S_AXIMM_wready,
    S_AXIMM_wstrb,
    S_AXIMM_wvalid,
    S_AXIS_tdata,
    S_AXIS_tkeep,
    S_AXIS_tlast,
    S_AXIS_tready,
    S_AXIS_tvalid,
    aclk,
    aclk_bypass_m,
    ap_rst_n,
    ap_rst_n_bypass_m,
    aresetn,
    dout,
    dout1,
    m_axi_gmem1_araddr,
    m_axi_gmem1_arburst,
    m_axi_gmem1_arcache,
    m_axi_gmem1_arid,
    m_axi_gmem1_arlen,
    m_axi_gmem1_arlock,
    m_axi_gmem1_arprot,
    m_axi_gmem1_arqos,
    m_axi_gmem1_arready,
    m_axi_gmem1_arregion,
    m_axi_gmem1_arsize,
    m_axi_gmem1_arvalid,
    m_axi_gmem1_awaddr,
    m_axi_gmem1_awburst,
    m_axi_gmem1_awcache,
    m_axi_gmem1_awid,
    m_axi_gmem1_awlen,
    m_axi_gmem1_awlock,
    m_axi_gmem1_awprot,
    m_axi_gmem1_awqos,
    m_axi_gmem1_awready,
    m_axi_gmem1_awregion,
    m_axi_gmem1_awsize,
    m_axi_gmem1_awvalid,
    m_axi_gmem1_bid,
    m_axi_gmem1_bready,
    m_axi_gmem1_bresp,
    m_axi_gmem1_bvalid,
    m_axi_gmem1_rdata,
    m_axi_gmem1_rid,
    m_axi_gmem1_rlast,
    m_axi_gmem1_rready,
    m_axi_gmem1_rresp,
    m_axi_gmem1_rvalid,
    m_axi_gmem1_wdata,
    m_axi_gmem1_wlast,
    m_axi_gmem1_wready,
    m_axi_gmem1_wstrb,
    m_axi_gmem1_wvalid,
    m_axi_gmem2_araddr,
    m_axi_gmem2_arburst,
    m_axi_gmem2_arcache,
    m_axi_gmem2_arid,
    m_axi_gmem2_arlen,
    m_axi_gmem2_arlock,
    m_axi_gmem2_arprot,
    m_axi_gmem2_arqos,
    m_axi_gmem2_arready,
    m_axi_gmem2_arregion,
    m_axi_gmem2_arsize,
    m_axi_gmem2_arvalid,
    m_axi_gmem2_awaddr,
    m_axi_gmem2_awburst,
    m_axi_gmem2_awcache,
    m_axi_gmem2_awid,
    m_axi_gmem2_awlen,
    m_axi_gmem2_awlock,
    m_axi_gmem2_awprot,
    m_axi_gmem2_awqos,
    m_axi_gmem2_awready,
    m_axi_gmem2_awregion,
    m_axi_gmem2_awsize,
    m_axi_gmem2_awvalid,
    m_axi_gmem2_bid,
    m_axi_gmem2_bready,
    m_axi_gmem2_bresp,
    m_axi_gmem2_bvalid,
    m_axi_gmem2_rdata,
    m_axi_gmem2_rid,
    m_axi_gmem2_rlast,
    m_axi_gmem2_rready,
    m_axi_gmem2_rresp,
    m_axi_gmem2_rvalid,
    m_axi_gmem2_wdata,
    m_axi_gmem2_wlast,
    m_axi_gmem2_wready,
    m_axi_gmem2_wstrb,
    m_axi_gmem2_wvalid,
    m_axi_gmem_araddr,
    m_axi_gmem_arburst,
    m_axi_gmem_arcache,
    m_axi_gmem_arid,
    m_axi_gmem_arlen,
    m_axi_gmem_arlock,
    m_axi_gmem_arprot,
    m_axi_gmem_arqos,
    m_axi_gmem_arready,
    m_axi_gmem_arregion,
    m_axi_gmem_arsize,
    m_axi_gmem_arvalid,
    m_axi_gmem_awaddr,
    m_axi_gmem_awburst,
    m_axi_gmem_awcache,
    m_axi_gmem_awid,
    m_axi_gmem_awlen,
    m_axi_gmem_awlock,
    m_axi_gmem_awprot,
    m_axi_gmem_awqos,
    m_axi_gmem_awready,
    m_axi_gmem_awregion,
    m_axi_gmem_awsize,
    m_axi_gmem_awvalid,
    m_axi_gmem_bid,
    m_axi_gmem_bready,
    m_axi_gmem_bresp,
    m_axi_gmem_bvalid,
    m_axi_gmem_rdata,
    m_axi_gmem_rid,
    m_axi_gmem_rlast,
    m_axi_gmem_rready,
    m_axi_gmem_rresp,
    m_axi_gmem_rvalid,
    m_axi_gmem_wdata,
    m_axi_gmem_wlast,
    m_axi_gmem_wready,
    m_axi_gmem_wstrb,
    m_axi_gmem_wvalid,
    s_axi_control1_araddr,
    s_axi_control1_arprot,
    s_axi_control1_arready,
    s_axi_control1_arvalid,
    s_axi_control1_awaddr,
    s_axi_control1_awprot,
    s_axi_control1_awready,
    s_axi_control1_awvalid,
    s_axi_control1_bready,
    s_axi_control1_bresp,
    s_axi_control1_bvalid,
    s_axi_control1_rdata,
    s_axi_control1_rready,
    s_axi_control1_rresp,
    s_axi_control1_rvalid,
    s_axi_control1_wdata,
    s_axi_control1_wready,
    s_axi_control1_wstrb,
    s_axi_control1_wvalid,
    s_axi_control2_araddr,
    s_axi_control2_arprot,
    s_axi_control2_arready,
    s_axi_control2_arvalid,
    s_axi_control2_awaddr,
    s_axi_control2_awprot,
    s_axi_control2_awready,
    s_axi_control2_awvalid,
    s_axi_control2_bready,
    s_axi_control2_bresp,
    s_axi_control2_bvalid,
    s_axi_control2_rdata,
    s_axi_control2_rready,
    s_axi_control2_rresp,
    s_axi_control2_rvalid,
    s_axi_control2_wdata,
    s_axi_control2_wready,
    s_axi_control2_wstrb,
    s_axi_control2_wvalid,
    s_axi_control_araddr,
    s_axi_control_arprot,
    s_axi_control_arready,
    s_axi_control_arvalid,
    s_axi_control_awaddr,
    s_axi_control_awprot,
    s_axi_control_awready,
    s_axi_control_awvalid,
    s_axi_control_bready,
    s_axi_control_bresp,
    s_axi_control_bvalid,
    s_axi_control_rdata,
    s_axi_control_rready,
    s_axi_control_rresp,
    s_axi_control_rvalid,
    s_axi_control_wdata,
    s_axi_control_wready,
    s_axi_control_wstrb,
    s_axi_control_wvalid);
  output [127:0]M_AXIS1_tdata;
  output [15:0]M_AXIS1_tkeep;
  output M_AXIS1_tlast;
  input M_AXIS1_tready;
  output M_AXIS1_tvalid;
  output [127:0]M_AXIS_tdata;
  output [15:0]M_AXIS_tkeep;
  output M_AXIS_tlast;
  input M_AXIS_tready;
  output M_AXIS_tvalid;
  input [43:0]S00_AXI_araddr;
  input [1:0]S00_AXI_arburst;
  input [3:0]S00_AXI_arcache;
  input [0:0]S00_AXI_arid;
  input [7:0]S00_AXI_arlen;
  input [0:0]S00_AXI_arlock;
  input [2:0]S00_AXI_arprot;
  input [3:0]S00_AXI_arqos;
  output S00_AXI_arready;
  input [2:0]S00_AXI_arsize;
  input [113:0]S00_AXI_aruser;
  input S00_AXI_arvalid;
  input [43:0]S00_AXI_awaddr;
  input [1:0]S00_AXI_awburst;
  input [3:0]S00_AXI_awcache;
  input [0:0]S00_AXI_awid;
  input [7:0]S00_AXI_awlen;
  input [0:0]S00_AXI_awlock;
  input [2:0]S00_AXI_awprot;
  input [3:0]S00_AXI_awqos;
  output S00_AXI_awready;
  input [2:0]S00_AXI_awsize;
  input [113:0]S00_AXI_awuser;
  input S00_AXI_awvalid;
  output [0:0]S00_AXI_bid;
  input S00_AXI_bready;
  output [1:0]S00_AXI_bresp;
  output S00_AXI_bvalid;
  output [127:0]S00_AXI_rdata;
  output [0:0]S00_AXI_rid;
  output S00_AXI_rlast;
  input S00_AXI_rready;
  output [1:0]S00_AXI_rresp;
  output [13:0]S00_AXI_ruser;
  output S00_AXI_rvalid;
  input [127:0]S00_AXI_wdata;
  input S00_AXI_wlast;
  output S00_AXI_wready;
  input [15:0]S00_AXI_wstrb;
  input [13:0]S00_AXI_wuser;
  input S00_AXI_wvalid;
  input [31:0]S_AXIMM_araddr;
  input [1:0]S_AXIMM_arburst;
  input [7:0]S_AXIMM_arlen;
  output S_AXIMM_arready;
  input [2:0]S_AXIMM_arsize;
  input S_AXIMM_arvalid;
  input [31:0]S_AXIMM_awaddr;
  input [1:0]S_AXIMM_awburst;
  input [7:0]S_AXIMM_awlen;
  output S_AXIMM_awready;
  input [2:0]S_AXIMM_awsize;
  input S_AXIMM_awvalid;
  input S_AXIMM_bready;
  output [1:0]S_AXIMM_bresp;
  output S_AXIMM_bvalid;
  output [31:0]S_AXIMM_rdata;
  output S_AXIMM_rlast;
  input S_AXIMM_rready;
  output [1:0]S_AXIMM_rresp;
  output S_AXIMM_rvalid;
  input [31:0]S_AXIMM_wdata;
  input S_AXIMM_wlast;
  output S_AXIMM_wready;
  input [3:0]S_AXIMM_wstrb;
  input S_AXIMM_wvalid;
  input [127:0]S_AXIS_tdata;
  input [15:0]S_AXIS_tkeep;
  input S_AXIS_tlast;
  output S_AXIS_tready;
  input S_AXIS_tvalid;
  input aclk;
  output aclk_bypass_m;
  input ap_rst_n;
  output ap_rst_n_bypass_m;
  input aresetn;
  output [0:0]dout;
  output [31:0]dout1;
  output [63:0]m_axi_gmem1_araddr;
  output [1:0]m_axi_gmem1_arburst;
  output [3:0]m_axi_gmem1_arcache;
  output [0:0]m_axi_gmem1_arid;
  output [7:0]m_axi_gmem1_arlen;
  output [1:0]m_axi_gmem1_arlock;
  output [2:0]m_axi_gmem1_arprot;
  output [3:0]m_axi_gmem1_arqos;
  input m_axi_gmem1_arready;
  output [3:0]m_axi_gmem1_arregion;
  output [2:0]m_axi_gmem1_arsize;
  output m_axi_gmem1_arvalid;
  output [63:0]m_axi_gmem1_awaddr;
  output [1:0]m_axi_gmem1_awburst;
  output [3:0]m_axi_gmem1_awcache;
  output [0:0]m_axi_gmem1_awid;
  output [7:0]m_axi_gmem1_awlen;
  output [1:0]m_axi_gmem1_awlock;
  output [2:0]m_axi_gmem1_awprot;
  output [3:0]m_axi_gmem1_awqos;
  input m_axi_gmem1_awready;
  output [3:0]m_axi_gmem1_awregion;
  output [2:0]m_axi_gmem1_awsize;
  output m_axi_gmem1_awvalid;
  input [0:0]m_axi_gmem1_bid;
  output m_axi_gmem1_bready;
  input [1:0]m_axi_gmem1_bresp;
  input m_axi_gmem1_bvalid;
  input [31:0]m_axi_gmem1_rdata;
  input [0:0]m_axi_gmem1_rid;
  input m_axi_gmem1_rlast;
  output m_axi_gmem1_rready;
  input [1:0]m_axi_gmem1_rresp;
  input m_axi_gmem1_rvalid;
  output [31:0]m_axi_gmem1_wdata;
  output m_axi_gmem1_wlast;
  input m_axi_gmem1_wready;
  output [3:0]m_axi_gmem1_wstrb;
  output m_axi_gmem1_wvalid;
  output [63:0]m_axi_gmem2_araddr;
  output [1:0]m_axi_gmem2_arburst;
  output [3:0]m_axi_gmem2_arcache;
  output [0:0]m_axi_gmem2_arid;
  output [7:0]m_axi_gmem2_arlen;
  output [1:0]m_axi_gmem2_arlock;
  output [2:0]m_axi_gmem2_arprot;
  output [3:0]m_axi_gmem2_arqos;
  input m_axi_gmem2_arready;
  output [3:0]m_axi_gmem2_arregion;
  output [2:0]m_axi_gmem2_arsize;
  output m_axi_gmem2_arvalid;
  output [63:0]m_axi_gmem2_awaddr;
  output [1:0]m_axi_gmem2_awburst;
  output [3:0]m_axi_gmem2_awcache;
  output [0:0]m_axi_gmem2_awid;
  output [7:0]m_axi_gmem2_awlen;
  output [1:0]m_axi_gmem2_awlock;
  output [2:0]m_axi_gmem2_awprot;
  output [3:0]m_axi_gmem2_awqos;
  input m_axi_gmem2_awready;
  output [3:0]m_axi_gmem2_awregion;
  output [2:0]m_axi_gmem2_awsize;
  output m_axi_gmem2_awvalid;
  input [0:0]m_axi_gmem2_bid;
  output m_axi_gmem2_bready;
  input [1:0]m_axi_gmem2_bresp;
  input m_axi_gmem2_bvalid;
  input [31:0]m_axi_gmem2_rdata;
  input [0:0]m_axi_gmem2_rid;
  input m_axi_gmem2_rlast;
  output m_axi_gmem2_rready;
  input [1:0]m_axi_gmem2_rresp;
  input m_axi_gmem2_rvalid;
  output [31:0]m_axi_gmem2_wdata;
  output m_axi_gmem2_wlast;
  input m_axi_gmem2_wready;
  output [3:0]m_axi_gmem2_wstrb;
  output m_axi_gmem2_wvalid;
  output [63:0]m_axi_gmem_araddr;
  output [1:0]m_axi_gmem_arburst;
  output [3:0]m_axi_gmem_arcache;
  output [0:0]m_axi_gmem_arid;
  output [7:0]m_axi_gmem_arlen;
  output [1:0]m_axi_gmem_arlock;
  output [2:0]m_axi_gmem_arprot;
  output [3:0]m_axi_gmem_arqos;
  input m_axi_gmem_arready;
  output [3:0]m_axi_gmem_arregion;
  output [2:0]m_axi_gmem_arsize;
  output m_axi_gmem_arvalid;
  output [63:0]m_axi_gmem_awaddr;
  output [1:0]m_axi_gmem_awburst;
  output [3:0]m_axi_gmem_awcache;
  output [0:0]m_axi_gmem_awid;
  output [7:0]m_axi_gmem_awlen;
  output [1:0]m_axi_gmem_awlock;
  output [2:0]m_axi_gmem_awprot;
  output [3:0]m_axi_gmem_awqos;
  input m_axi_gmem_awready;
  output [3:0]m_axi_gmem_awregion;
  output [2:0]m_axi_gmem_awsize;
  output m_axi_gmem_awvalid;
  input [0:0]m_axi_gmem_bid;
  output m_axi_gmem_bready;
  input [1:0]m_axi_gmem_bresp;
  input m_axi_gmem_bvalid;
  input [31:0]m_axi_gmem_rdata;
  input [0:0]m_axi_gmem_rid;
  input m_axi_gmem_rlast;
  output m_axi_gmem_rready;
  input [1:0]m_axi_gmem_rresp;
  input m_axi_gmem_rvalid;
  output [31:0]m_axi_gmem_wdata;
  output m_axi_gmem_wlast;
  input m_axi_gmem_wready;
  output [3:0]m_axi_gmem_wstrb;
  output m_axi_gmem_wvalid;
  input [5:0]s_axi_control1_araddr;
  input [2:0]s_axi_control1_arprot;
  output s_axi_control1_arready;
  input s_axi_control1_arvalid;
  input [5:0]s_axi_control1_awaddr;
  input [2:0]s_axi_control1_awprot;
  output s_axi_control1_awready;
  input s_axi_control1_awvalid;
  input s_axi_control1_bready;
  output [1:0]s_axi_control1_bresp;
  output s_axi_control1_bvalid;
  output [31:0]s_axi_control1_rdata;
  input s_axi_control1_rready;
  output [1:0]s_axi_control1_rresp;
  output s_axi_control1_rvalid;
  input [31:0]s_axi_control1_wdata;
  output s_axi_control1_wready;
  input [3:0]s_axi_control1_wstrb;
  input s_axi_control1_wvalid;
  input [5:0]s_axi_control2_araddr;
  input [2:0]s_axi_control2_arprot;
  output s_axi_control2_arready;
  input s_axi_control2_arvalid;
  input [5:0]s_axi_control2_awaddr;
  input [2:0]s_axi_control2_awprot;
  output s_axi_control2_awready;
  input s_axi_control2_awvalid;
  input s_axi_control2_bready;
  output [1:0]s_axi_control2_bresp;
  output s_axi_control2_bvalid;
  output [31:0]s_axi_control2_rdata;
  input s_axi_control2_rready;
  output [1:0]s_axi_control2_rresp;
  output s_axi_control2_rvalid;
  input [31:0]s_axi_control2_wdata;
  output s_axi_control2_wready;
  input [3:0]s_axi_control2_wstrb;
  input s_axi_control2_wvalid;
  input [5:0]s_axi_control_araddr;
  input [2:0]s_axi_control_arprot;
  output s_axi_control_arready;
  input s_axi_control_arvalid;
  input [5:0]s_axi_control_awaddr;
  input [2:0]s_axi_control_awprot;
  output s_axi_control_awready;
  input s_axi_control_awvalid;
  input s_axi_control_bready;
  output [1:0]s_axi_control_bresp;
  output s_axi_control_bvalid;
  output [31:0]s_axi_control_rdata;
  input s_axi_control_rready;
  output [1:0]s_axi_control_rresp;
  output s_axi_control_rvalid;
  input [31:0]s_axi_control_wdata;
  output s_axi_control_wready;
  input [3:0]s_axi_control_wstrb;
  input s_axi_control_wvalid;

  wire [127:0]ai_engine_0_M00_AXIS_TDATA;
  wire [15:0]ai_engine_0_M00_AXIS_TKEEP;
  wire ai_engine_0_M00_AXIS_TLAST;
  wire ai_engine_0_M00_AXIS_TREADY;
  wire ai_engine_0_M00_AXIS_TVALID;
  wire [31:0]axi_intc_cascaded_1_intr_1_interrupt_concat_dout;
  wire clk_wizard_0_clk_out4_o1_o2;
  wire [31:0]dwc_ai_engine_0_M00_AXIS_M_AXIS_TDATA;
  wire [3:0]dwc_ai_engine_0_M00_AXIS_M_AXIS_TKEEP;
  wire dwc_ai_engine_0_M00_AXIS_M_AXIS_TLAST;
  wire dwc_ai_engine_0_M00_AXIS_M_AXIS_TREADY;
  wire dwc_ai_engine_0_M00_AXIS_M_AXIS_TVALID;
  wire [127:0]dwc_mm2s_1_s_M_AXIS_TDATA;
  wire [15:0]dwc_mm2s_1_s_M_AXIS_TKEEP;
  wire dwc_mm2s_1_s_M_AXIS_TLAST;
  wire dwc_mm2s_1_s_M_AXIS_TREADY;
  wire dwc_mm2s_1_s_M_AXIS_TVALID;
  wire [127:0]dwc_mm2s_2_s_M_AXIS_TDATA;
  wire [15:0]dwc_mm2s_2_s_M_AXIS_TKEEP;
  wire dwc_mm2s_2_s_M_AXIS_TLAST;
  wire dwc_mm2s_2_s_M_AXIS_TREADY;
  wire dwc_mm2s_2_s_M_AXIS_TVALID;
  wire [5:0]icn_ctrl_1_M06_AXI_ARADDR;
  wire [2:0]icn_ctrl_1_M06_AXI_ARPROT;
  wire icn_ctrl_1_M06_AXI_ARREADY;
  wire icn_ctrl_1_M06_AXI_ARVALID;
  wire [5:0]icn_ctrl_1_M06_AXI_AWADDR;
  wire [2:0]icn_ctrl_1_M06_AXI_AWPROT;
  wire icn_ctrl_1_M06_AXI_AWREADY;
  wire icn_ctrl_1_M06_AXI_AWVALID;
  wire icn_ctrl_1_M06_AXI_BREADY;
  wire [1:0]icn_ctrl_1_M06_AXI_BRESP;
  wire icn_ctrl_1_M06_AXI_BVALID;
  wire [31:0]icn_ctrl_1_M06_AXI_RDATA;
  wire icn_ctrl_1_M06_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M06_AXI_RRESP;
  wire icn_ctrl_1_M06_AXI_RVALID;
  wire [31:0]icn_ctrl_1_M06_AXI_WDATA;
  wire icn_ctrl_1_M06_AXI_WREADY;
  wire [3:0]icn_ctrl_1_M06_AXI_WSTRB;
  wire icn_ctrl_1_M06_AXI_WVALID;
  wire [5:0]icn_ctrl_1_M07_AXI_ARADDR;
  wire [2:0]icn_ctrl_1_M07_AXI_ARPROT;
  wire icn_ctrl_1_M07_AXI_ARREADY;
  wire icn_ctrl_1_M07_AXI_ARVALID;
  wire [5:0]icn_ctrl_1_M07_AXI_AWADDR;
  wire [2:0]icn_ctrl_1_M07_AXI_AWPROT;
  wire icn_ctrl_1_M07_AXI_AWREADY;
  wire icn_ctrl_1_M07_AXI_AWVALID;
  wire icn_ctrl_1_M07_AXI_BREADY;
  wire [1:0]icn_ctrl_1_M07_AXI_BRESP;
  wire icn_ctrl_1_M07_AXI_BVALID;
  wire [31:0]icn_ctrl_1_M07_AXI_RDATA;
  wire icn_ctrl_1_M07_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M07_AXI_RRESP;
  wire icn_ctrl_1_M07_AXI_RVALID;
  wire [31:0]icn_ctrl_1_M07_AXI_WDATA;
  wire icn_ctrl_1_M07_AXI_WREADY;
  wire [3:0]icn_ctrl_1_M07_AXI_WSTRB;
  wire icn_ctrl_1_M07_AXI_WVALID;
  wire [5:0]icn_ctrl_1_M08_AXI_ARADDR;
  wire [2:0]icn_ctrl_1_M08_AXI_ARPROT;
  wire icn_ctrl_1_M08_AXI_ARREADY;
  wire icn_ctrl_1_M08_AXI_ARVALID;
  wire [5:0]icn_ctrl_1_M08_AXI_AWADDR;
  wire [2:0]icn_ctrl_1_M08_AXI_AWPROT;
  wire icn_ctrl_1_M08_AXI_AWREADY;
  wire icn_ctrl_1_M08_AXI_AWVALID;
  wire icn_ctrl_1_M08_AXI_BREADY;
  wire [1:0]icn_ctrl_1_M08_AXI_BRESP;
  wire icn_ctrl_1_M08_AXI_BVALID;
  wire [31:0]icn_ctrl_1_M08_AXI_RDATA;
  wire icn_ctrl_1_M08_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M08_AXI_RRESP;
  wire icn_ctrl_1_M08_AXI_RVALID;
  wire [31:0]icn_ctrl_1_M08_AXI_WDATA;
  wire icn_ctrl_1_M08_AXI_WREADY;
  wire [3:0]icn_ctrl_1_M08_AXI_WSTRB;
  wire icn_ctrl_1_M08_AXI_WVALID;
  wire [43:0]icn_ctrl_1_M09_AXI_ARADDR;
  wire [1:0]icn_ctrl_1_M09_AXI_ARBURST;
  wire [3:0]icn_ctrl_1_M09_AXI_ARCACHE;
  wire [0:0]icn_ctrl_1_M09_AXI_ARID;
  wire [7:0]icn_ctrl_1_M09_AXI_ARLEN;
  wire [0:0]icn_ctrl_1_M09_AXI_ARLOCK;
  wire [2:0]icn_ctrl_1_M09_AXI_ARPROT;
  wire [3:0]icn_ctrl_1_M09_AXI_ARQOS;
  wire icn_ctrl_1_M09_AXI_ARREADY;
  wire [2:0]icn_ctrl_1_M09_AXI_ARSIZE;
  wire [113:0]icn_ctrl_1_M09_AXI_ARUSER;
  wire icn_ctrl_1_M09_AXI_ARVALID;
  wire [43:0]icn_ctrl_1_M09_AXI_AWADDR;
  wire [1:0]icn_ctrl_1_M09_AXI_AWBURST;
  wire [3:0]icn_ctrl_1_M09_AXI_AWCACHE;
  wire [0:0]icn_ctrl_1_M09_AXI_AWID;
  wire [7:0]icn_ctrl_1_M09_AXI_AWLEN;
  wire [0:0]icn_ctrl_1_M09_AXI_AWLOCK;
  wire [2:0]icn_ctrl_1_M09_AXI_AWPROT;
  wire [3:0]icn_ctrl_1_M09_AXI_AWQOS;
  wire icn_ctrl_1_M09_AXI_AWREADY;
  wire [2:0]icn_ctrl_1_M09_AXI_AWSIZE;
  wire [113:0]icn_ctrl_1_M09_AXI_AWUSER;
  wire icn_ctrl_1_M09_AXI_AWVALID;
  wire [0:0]icn_ctrl_1_M09_AXI_BID;
  wire icn_ctrl_1_M09_AXI_BREADY;
  wire [1:0]icn_ctrl_1_M09_AXI_BRESP;
  wire icn_ctrl_1_M09_AXI_BVALID;
  wire [127:0]icn_ctrl_1_M09_AXI_RDATA;
  wire [0:0]icn_ctrl_1_M09_AXI_RID;
  wire icn_ctrl_1_M09_AXI_RLAST;
  wire icn_ctrl_1_M09_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M09_AXI_RRESP;
  wire [13:0]icn_ctrl_1_M09_AXI_RUSER;
  wire icn_ctrl_1_M09_AXI_RVALID;
  wire [127:0]icn_ctrl_1_M09_AXI_WDATA;
  wire icn_ctrl_1_M09_AXI_WLAST;
  wire icn_ctrl_1_M09_AXI_WREADY;
  wire [15:0]icn_ctrl_1_M09_AXI_WSTRB;
  wire [13:0]icn_ctrl_1_M09_AXI_WUSER;
  wire icn_ctrl_1_M09_AXI_WVALID;
  wire [31:0]icn_ctrl_1_M10_AXI_ARADDR;
  wire [1:0]icn_ctrl_1_M10_AXI_ARBURST;
  wire [7:0]icn_ctrl_1_M10_AXI_ARLEN;
  wire icn_ctrl_1_M10_AXI_ARREADY;
  wire [2:0]icn_ctrl_1_M10_AXI_ARSIZE;
  wire icn_ctrl_1_M10_AXI_ARVALID;
  wire [31:0]icn_ctrl_1_M10_AXI_AWADDR;
  wire [1:0]icn_ctrl_1_M10_AXI_AWBURST;
  wire [7:0]icn_ctrl_1_M10_AXI_AWLEN;
  wire icn_ctrl_1_M10_AXI_AWREADY;
  wire [2:0]icn_ctrl_1_M10_AXI_AWSIZE;
  wire icn_ctrl_1_M10_AXI_AWVALID;
  wire icn_ctrl_1_M10_AXI_BREADY;
  wire [1:0]icn_ctrl_1_M10_AXI_BRESP;
  wire icn_ctrl_1_M10_AXI_BVALID;
  wire [31:0]icn_ctrl_1_M10_AXI_RDATA;
  wire icn_ctrl_1_M10_AXI_RLAST;
  wire icn_ctrl_1_M10_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M10_AXI_RRESP;
  wire icn_ctrl_1_M10_AXI_RVALID;
  wire [31:0]icn_ctrl_1_M10_AXI_WDATA;
  wire icn_ctrl_1_M10_AXI_WLAST;
  wire icn_ctrl_1_M10_AXI_WREADY;
  wire [3:0]icn_ctrl_1_M10_AXI_WSTRB;
  wire icn_ctrl_1_M10_AXI_WVALID;
  wire [0:0]irq_const_tieoff_dout;
  wire mm2s_1_interrupt;
  wire [63:0]mm2s_1_m_axi_gmem_ARADDR;
  wire [1:0]mm2s_1_m_axi_gmem_ARBURST;
  wire [3:0]mm2s_1_m_axi_gmem_ARCACHE;
  wire [0:0]mm2s_1_m_axi_gmem_ARID;
  wire [7:0]mm2s_1_m_axi_gmem_ARLEN;
  wire [1:0]mm2s_1_m_axi_gmem_ARLOCK;
  wire [2:0]mm2s_1_m_axi_gmem_ARPROT;
  wire [3:0]mm2s_1_m_axi_gmem_ARQOS;
  wire mm2s_1_m_axi_gmem_ARREADY;
  wire [3:0]mm2s_1_m_axi_gmem_ARREGION;
  wire [2:0]mm2s_1_m_axi_gmem_ARSIZE;
  wire mm2s_1_m_axi_gmem_ARVALID;
  wire [63:0]mm2s_1_m_axi_gmem_AWADDR;
  wire [1:0]mm2s_1_m_axi_gmem_AWBURST;
  wire [3:0]mm2s_1_m_axi_gmem_AWCACHE;
  wire [0:0]mm2s_1_m_axi_gmem_AWID;
  wire [7:0]mm2s_1_m_axi_gmem_AWLEN;
  wire [1:0]mm2s_1_m_axi_gmem_AWLOCK;
  wire [2:0]mm2s_1_m_axi_gmem_AWPROT;
  wire [3:0]mm2s_1_m_axi_gmem_AWQOS;
  wire mm2s_1_m_axi_gmem_AWREADY;
  wire [3:0]mm2s_1_m_axi_gmem_AWREGION;
  wire [2:0]mm2s_1_m_axi_gmem_AWSIZE;
  wire mm2s_1_m_axi_gmem_AWVALID;
  wire [0:0]mm2s_1_m_axi_gmem_BID;
  wire mm2s_1_m_axi_gmem_BREADY;
  wire [1:0]mm2s_1_m_axi_gmem_BRESP;
  wire mm2s_1_m_axi_gmem_BVALID;
  wire [31:0]mm2s_1_m_axi_gmem_RDATA;
  wire [0:0]mm2s_1_m_axi_gmem_RID;
  wire mm2s_1_m_axi_gmem_RLAST;
  wire mm2s_1_m_axi_gmem_RREADY;
  wire [1:0]mm2s_1_m_axi_gmem_RRESP;
  wire mm2s_1_m_axi_gmem_RVALID;
  wire [31:0]mm2s_1_m_axi_gmem_WDATA;
  wire mm2s_1_m_axi_gmem_WLAST;
  wire mm2s_1_m_axi_gmem_WREADY;
  wire [3:0]mm2s_1_m_axi_gmem_WSTRB;
  wire mm2s_1_m_axi_gmem_WVALID;
  wire [31:0]mm2s_1_s_TDATA;
  wire [3:0]mm2s_1_s_TKEEP;
  wire [0:0]mm2s_1_s_TLAST;
  wire mm2s_1_s_TREADY;
  wire [3:0]mm2s_1_s_TSTRB;
  wire mm2s_1_s_TVALID;
  wire mm2s_2_interrupt;
  wire [63:0]mm2s_2_m_axi_gmem_ARADDR;
  wire [1:0]mm2s_2_m_axi_gmem_ARBURST;
  wire [3:0]mm2s_2_m_axi_gmem_ARCACHE;
  wire [0:0]mm2s_2_m_axi_gmem_ARID;
  wire [7:0]mm2s_2_m_axi_gmem_ARLEN;
  wire [1:0]mm2s_2_m_axi_gmem_ARLOCK;
  wire [2:0]mm2s_2_m_axi_gmem_ARPROT;
  wire [3:0]mm2s_2_m_axi_gmem_ARQOS;
  wire mm2s_2_m_axi_gmem_ARREADY;
  wire [3:0]mm2s_2_m_axi_gmem_ARREGION;
  wire [2:0]mm2s_2_m_axi_gmem_ARSIZE;
  wire mm2s_2_m_axi_gmem_ARVALID;
  wire [63:0]mm2s_2_m_axi_gmem_AWADDR;
  wire [1:0]mm2s_2_m_axi_gmem_AWBURST;
  wire [3:0]mm2s_2_m_axi_gmem_AWCACHE;
  wire [0:0]mm2s_2_m_axi_gmem_AWID;
  wire [7:0]mm2s_2_m_axi_gmem_AWLEN;
  wire [1:0]mm2s_2_m_axi_gmem_AWLOCK;
  wire [2:0]mm2s_2_m_axi_gmem_AWPROT;
  wire [3:0]mm2s_2_m_axi_gmem_AWQOS;
  wire mm2s_2_m_axi_gmem_AWREADY;
  wire [3:0]mm2s_2_m_axi_gmem_AWREGION;
  wire [2:0]mm2s_2_m_axi_gmem_AWSIZE;
  wire mm2s_2_m_axi_gmem_AWVALID;
  wire [0:0]mm2s_2_m_axi_gmem_BID;
  wire mm2s_2_m_axi_gmem_BREADY;
  wire [1:0]mm2s_2_m_axi_gmem_BRESP;
  wire mm2s_2_m_axi_gmem_BVALID;
  wire [31:0]mm2s_2_m_axi_gmem_RDATA;
  wire [0:0]mm2s_2_m_axi_gmem_RID;
  wire mm2s_2_m_axi_gmem_RLAST;
  wire mm2s_2_m_axi_gmem_RREADY;
  wire [1:0]mm2s_2_m_axi_gmem_RRESP;
  wire mm2s_2_m_axi_gmem_RVALID;
  wire [31:0]mm2s_2_m_axi_gmem_WDATA;
  wire mm2s_2_m_axi_gmem_WLAST;
  wire mm2s_2_m_axi_gmem_WREADY;
  wire [3:0]mm2s_2_m_axi_gmem_WSTRB;
  wire mm2s_2_m_axi_gmem_WVALID;
  wire [31:0]mm2s_2_s_TDATA;
  wire [3:0]mm2s_2_s_TKEEP;
  wire [0:0]mm2s_2_s_TLAST;
  wire mm2s_2_s_TREADY;
  wire [3:0]mm2s_2_s_TSTRB;
  wire mm2s_2_s_TVALID;
  wire psr_312mhz_interconnect_aresetn;
  wire psr_312mhz_peripheral_aresetn;
  wire s2mm_interrupt;
  wire [63:0]s2mm_m_axi_gmem_ARADDR;
  wire [1:0]s2mm_m_axi_gmem_ARBURST;
  wire [3:0]s2mm_m_axi_gmem_ARCACHE;
  wire [0:0]s2mm_m_axi_gmem_ARID;
  wire [7:0]s2mm_m_axi_gmem_ARLEN;
  wire [1:0]s2mm_m_axi_gmem_ARLOCK;
  wire [2:0]s2mm_m_axi_gmem_ARPROT;
  wire [3:0]s2mm_m_axi_gmem_ARQOS;
  wire s2mm_m_axi_gmem_ARREADY;
  wire [3:0]s2mm_m_axi_gmem_ARREGION;
  wire [2:0]s2mm_m_axi_gmem_ARSIZE;
  wire s2mm_m_axi_gmem_ARVALID;
  wire [63:0]s2mm_m_axi_gmem_AWADDR;
  wire [1:0]s2mm_m_axi_gmem_AWBURST;
  wire [3:0]s2mm_m_axi_gmem_AWCACHE;
  wire [0:0]s2mm_m_axi_gmem_AWID;
  wire [7:0]s2mm_m_axi_gmem_AWLEN;
  wire [1:0]s2mm_m_axi_gmem_AWLOCK;
  wire [2:0]s2mm_m_axi_gmem_AWPROT;
  wire [3:0]s2mm_m_axi_gmem_AWQOS;
  wire s2mm_m_axi_gmem_AWREADY;
  wire [3:0]s2mm_m_axi_gmem_AWREGION;
  wire [2:0]s2mm_m_axi_gmem_AWSIZE;
  wire s2mm_m_axi_gmem_AWVALID;
  wire [0:0]s2mm_m_axi_gmem_BID;
  wire s2mm_m_axi_gmem_BREADY;
  wire [1:0]s2mm_m_axi_gmem_BRESP;
  wire s2mm_m_axi_gmem_BVALID;
  wire [31:0]s2mm_m_axi_gmem_RDATA;
  wire [0:0]s2mm_m_axi_gmem_RID;
  wire s2mm_m_axi_gmem_RLAST;
  wire s2mm_m_axi_gmem_RREADY;
  wire [1:0]s2mm_m_axi_gmem_RRESP;
  wire s2mm_m_axi_gmem_RVALID;
  wire [31:0]s2mm_m_axi_gmem_WDATA;
  wire s2mm_m_axi_gmem_WLAST;
  wire s2mm_m_axi_gmem_WREADY;
  wire [3:0]s2mm_m_axi_gmem_WSTRB;
  wire s2mm_m_axi_gmem_WVALID;

  assign M_AXIS1_tdata[127:0] = dwc_mm2s_2_s_M_AXIS_TDATA;
  assign M_AXIS1_tkeep[15:0] = dwc_mm2s_2_s_M_AXIS_TKEEP;
  assign M_AXIS1_tlast = dwc_mm2s_2_s_M_AXIS_TLAST;
  assign M_AXIS1_tvalid = dwc_mm2s_2_s_M_AXIS_TVALID;
  assign M_AXIS_tdata[127:0] = dwc_mm2s_1_s_M_AXIS_TDATA;
  assign M_AXIS_tkeep[15:0] = dwc_mm2s_1_s_M_AXIS_TKEEP;
  assign M_AXIS_tlast = dwc_mm2s_1_s_M_AXIS_TLAST;
  assign M_AXIS_tvalid = dwc_mm2s_1_s_M_AXIS_TVALID;
  assign S00_AXI_arready = icn_ctrl_1_M09_AXI_ARREADY;
  assign S00_AXI_awready = icn_ctrl_1_M09_AXI_AWREADY;
  assign S00_AXI_bid[0] = icn_ctrl_1_M09_AXI_BID;
  assign S00_AXI_bresp[1:0] = icn_ctrl_1_M09_AXI_BRESP;
  assign S00_AXI_bvalid = icn_ctrl_1_M09_AXI_BVALID;
  assign S00_AXI_rdata[127:0] = icn_ctrl_1_M09_AXI_RDATA;
  assign S00_AXI_rid[0] = icn_ctrl_1_M09_AXI_RID;
  assign S00_AXI_rlast = icn_ctrl_1_M09_AXI_RLAST;
  assign S00_AXI_rresp[1:0] = icn_ctrl_1_M09_AXI_RRESP;
  assign S00_AXI_ruser[13:0] = icn_ctrl_1_M09_AXI_RUSER;
  assign S00_AXI_rvalid = icn_ctrl_1_M09_AXI_RVALID;
  assign S00_AXI_wready = icn_ctrl_1_M09_AXI_WREADY;
  assign S_AXIMM_arready = icn_ctrl_1_M10_AXI_ARREADY;
  assign S_AXIMM_awready = icn_ctrl_1_M10_AXI_AWREADY;
  assign S_AXIMM_bresp[1:0] = icn_ctrl_1_M10_AXI_BRESP;
  assign S_AXIMM_bvalid = icn_ctrl_1_M10_AXI_BVALID;
  assign S_AXIMM_rdata[31:0] = icn_ctrl_1_M10_AXI_RDATA;
  assign S_AXIMM_rlast = icn_ctrl_1_M10_AXI_RLAST;
  assign S_AXIMM_rresp[1:0] = icn_ctrl_1_M10_AXI_RRESP;
  assign S_AXIMM_rvalid = icn_ctrl_1_M10_AXI_RVALID;
  assign S_AXIMM_wready = icn_ctrl_1_M10_AXI_WREADY;
  assign S_AXIS_tready = ai_engine_0_M00_AXIS_TREADY;
  assign aclk_bypass_m = clk_wizard_0_clk_out4_o1_o2;
  assign ai_engine_0_M00_AXIS_TDATA = S_AXIS_tdata[127:0];
  assign ai_engine_0_M00_AXIS_TKEEP = S_AXIS_tkeep[15:0];
  assign ai_engine_0_M00_AXIS_TLAST = S_AXIS_tlast;
  assign ai_engine_0_M00_AXIS_TVALID = S_AXIS_tvalid;
  assign ap_rst_n_bypass_m = psr_312mhz_peripheral_aresetn;
  assign clk_wizard_0_clk_out4_o1_o2 = aclk;
  assign dout[0] = irq_const_tieoff_dout;
  assign dout1[31:0] = axi_intc_cascaded_1_intr_1_interrupt_concat_dout;
  assign dwc_mm2s_1_s_M_AXIS_TREADY = M_AXIS_tready;
  assign dwc_mm2s_2_s_M_AXIS_TREADY = M_AXIS1_tready;
  assign icn_ctrl_1_M06_AXI_ARADDR = s_axi_control_araddr[5:0];
  assign icn_ctrl_1_M06_AXI_ARPROT = s_axi_control_arprot[2:0];
  assign icn_ctrl_1_M06_AXI_ARVALID = s_axi_control_arvalid;
  assign icn_ctrl_1_M06_AXI_AWADDR = s_axi_control_awaddr[5:0];
  assign icn_ctrl_1_M06_AXI_AWPROT = s_axi_control_awprot[2:0];
  assign icn_ctrl_1_M06_AXI_AWVALID = s_axi_control_awvalid;
  assign icn_ctrl_1_M06_AXI_BREADY = s_axi_control_bready;
  assign icn_ctrl_1_M06_AXI_RREADY = s_axi_control_rready;
  assign icn_ctrl_1_M06_AXI_WDATA = s_axi_control_wdata[31:0];
  assign icn_ctrl_1_M06_AXI_WSTRB = s_axi_control_wstrb[3:0];
  assign icn_ctrl_1_M06_AXI_WVALID = s_axi_control_wvalid;
  assign icn_ctrl_1_M07_AXI_ARADDR = s_axi_control1_araddr[5:0];
  assign icn_ctrl_1_M07_AXI_ARPROT = s_axi_control1_arprot[2:0];
  assign icn_ctrl_1_M07_AXI_ARVALID = s_axi_control1_arvalid;
  assign icn_ctrl_1_M07_AXI_AWADDR = s_axi_control1_awaddr[5:0];
  assign icn_ctrl_1_M07_AXI_AWPROT = s_axi_control1_awprot[2:0];
  assign icn_ctrl_1_M07_AXI_AWVALID = s_axi_control1_awvalid;
  assign icn_ctrl_1_M07_AXI_BREADY = s_axi_control1_bready;
  assign icn_ctrl_1_M07_AXI_RREADY = s_axi_control1_rready;
  assign icn_ctrl_1_M07_AXI_WDATA = s_axi_control1_wdata[31:0];
  assign icn_ctrl_1_M07_AXI_WSTRB = s_axi_control1_wstrb[3:0];
  assign icn_ctrl_1_M07_AXI_WVALID = s_axi_control1_wvalid;
  assign icn_ctrl_1_M08_AXI_ARADDR = s_axi_control2_araddr[5:0];
  assign icn_ctrl_1_M08_AXI_ARPROT = s_axi_control2_arprot[2:0];
  assign icn_ctrl_1_M08_AXI_ARVALID = s_axi_control2_arvalid;
  assign icn_ctrl_1_M08_AXI_AWADDR = s_axi_control2_awaddr[5:0];
  assign icn_ctrl_1_M08_AXI_AWPROT = s_axi_control2_awprot[2:0];
  assign icn_ctrl_1_M08_AXI_AWVALID = s_axi_control2_awvalid;
  assign icn_ctrl_1_M08_AXI_BREADY = s_axi_control2_bready;
  assign icn_ctrl_1_M08_AXI_RREADY = s_axi_control2_rready;
  assign icn_ctrl_1_M08_AXI_WDATA = s_axi_control2_wdata[31:0];
  assign icn_ctrl_1_M08_AXI_WSTRB = s_axi_control2_wstrb[3:0];
  assign icn_ctrl_1_M08_AXI_WVALID = s_axi_control2_wvalid;
  assign icn_ctrl_1_M09_AXI_ARADDR = S00_AXI_araddr[43:0];
  assign icn_ctrl_1_M09_AXI_ARBURST = S00_AXI_arburst[1:0];
  assign icn_ctrl_1_M09_AXI_ARCACHE = S00_AXI_arcache[3:0];
  assign icn_ctrl_1_M09_AXI_ARID = S00_AXI_arid[0];
  assign icn_ctrl_1_M09_AXI_ARLEN = S00_AXI_arlen[7:0];
  assign icn_ctrl_1_M09_AXI_ARLOCK = S00_AXI_arlock[0];
  assign icn_ctrl_1_M09_AXI_ARPROT = S00_AXI_arprot[2:0];
  assign icn_ctrl_1_M09_AXI_ARQOS = S00_AXI_arqos[3:0];
  assign icn_ctrl_1_M09_AXI_ARSIZE = S00_AXI_arsize[2:0];
  assign icn_ctrl_1_M09_AXI_ARUSER = S00_AXI_aruser[113:0];
  assign icn_ctrl_1_M09_AXI_ARVALID = S00_AXI_arvalid;
  assign icn_ctrl_1_M09_AXI_AWADDR = S00_AXI_awaddr[43:0];
  assign icn_ctrl_1_M09_AXI_AWBURST = S00_AXI_awburst[1:0];
  assign icn_ctrl_1_M09_AXI_AWCACHE = S00_AXI_awcache[3:0];
  assign icn_ctrl_1_M09_AXI_AWID = S00_AXI_awid[0];
  assign icn_ctrl_1_M09_AXI_AWLEN = S00_AXI_awlen[7:0];
  assign icn_ctrl_1_M09_AXI_AWLOCK = S00_AXI_awlock[0];
  assign icn_ctrl_1_M09_AXI_AWPROT = S00_AXI_awprot[2:0];
  assign icn_ctrl_1_M09_AXI_AWQOS = S00_AXI_awqos[3:0];
  assign icn_ctrl_1_M09_AXI_AWSIZE = S00_AXI_awsize[2:0];
  assign icn_ctrl_1_M09_AXI_AWUSER = S00_AXI_awuser[113:0];
  assign icn_ctrl_1_M09_AXI_AWVALID = S00_AXI_awvalid;
  assign icn_ctrl_1_M09_AXI_BREADY = S00_AXI_bready;
  assign icn_ctrl_1_M09_AXI_RREADY = S00_AXI_rready;
  assign icn_ctrl_1_M09_AXI_WDATA = S00_AXI_wdata[127:0];
  assign icn_ctrl_1_M09_AXI_WLAST = S00_AXI_wlast;
  assign icn_ctrl_1_M09_AXI_WSTRB = S00_AXI_wstrb[15:0];
  assign icn_ctrl_1_M09_AXI_WUSER = S00_AXI_wuser[13:0];
  assign icn_ctrl_1_M09_AXI_WVALID = S00_AXI_wvalid;
  assign icn_ctrl_1_M10_AXI_ARADDR = S_AXIMM_araddr[31:0];
  assign icn_ctrl_1_M10_AXI_ARBURST = S_AXIMM_arburst[1:0];
  assign icn_ctrl_1_M10_AXI_ARLEN = S_AXIMM_arlen[7:0];
  assign icn_ctrl_1_M10_AXI_ARSIZE = S_AXIMM_arsize[2:0];
  assign icn_ctrl_1_M10_AXI_ARVALID = S_AXIMM_arvalid;
  assign icn_ctrl_1_M10_AXI_AWADDR = S_AXIMM_awaddr[31:0];
  assign icn_ctrl_1_M10_AXI_AWBURST = S_AXIMM_awburst[1:0];
  assign icn_ctrl_1_M10_AXI_AWLEN = S_AXIMM_awlen[7:0];
  assign icn_ctrl_1_M10_AXI_AWSIZE = S_AXIMM_awsize[2:0];
  assign icn_ctrl_1_M10_AXI_AWVALID = S_AXIMM_awvalid;
  assign icn_ctrl_1_M10_AXI_BREADY = S_AXIMM_bready;
  assign icn_ctrl_1_M10_AXI_RREADY = S_AXIMM_rready;
  assign icn_ctrl_1_M10_AXI_WDATA = S_AXIMM_wdata[31:0];
  assign icn_ctrl_1_M10_AXI_WLAST = S_AXIMM_wlast;
  assign icn_ctrl_1_M10_AXI_WSTRB = S_AXIMM_wstrb[3:0];
  assign icn_ctrl_1_M10_AXI_WVALID = S_AXIMM_wvalid;
  assign m_axi_gmem1_araddr[63:0] = mm2s_2_m_axi_gmem_ARADDR;
  assign m_axi_gmem1_arburst[1:0] = mm2s_2_m_axi_gmem_ARBURST;
  assign m_axi_gmem1_arcache[3:0] = mm2s_2_m_axi_gmem_ARCACHE;
  assign m_axi_gmem1_arid[0] = mm2s_2_m_axi_gmem_ARID;
  assign m_axi_gmem1_arlen[7:0] = mm2s_2_m_axi_gmem_ARLEN;
  assign m_axi_gmem1_arlock[1:0] = mm2s_2_m_axi_gmem_ARLOCK;
  assign m_axi_gmem1_arprot[2:0] = mm2s_2_m_axi_gmem_ARPROT;
  assign m_axi_gmem1_arqos[3:0] = mm2s_2_m_axi_gmem_ARQOS;
  assign m_axi_gmem1_arregion[3:0] = mm2s_2_m_axi_gmem_ARREGION;
  assign m_axi_gmem1_arsize[2:0] = mm2s_2_m_axi_gmem_ARSIZE;
  assign m_axi_gmem1_arvalid = mm2s_2_m_axi_gmem_ARVALID;
  assign m_axi_gmem1_awaddr[63:0] = mm2s_2_m_axi_gmem_AWADDR;
  assign m_axi_gmem1_awburst[1:0] = mm2s_2_m_axi_gmem_AWBURST;
  assign m_axi_gmem1_awcache[3:0] = mm2s_2_m_axi_gmem_AWCACHE;
  assign m_axi_gmem1_awid[0] = mm2s_2_m_axi_gmem_AWID;
  assign m_axi_gmem1_awlen[7:0] = mm2s_2_m_axi_gmem_AWLEN;
  assign m_axi_gmem1_awlock[1:0] = mm2s_2_m_axi_gmem_AWLOCK;
  assign m_axi_gmem1_awprot[2:0] = mm2s_2_m_axi_gmem_AWPROT;
  assign m_axi_gmem1_awqos[3:0] = mm2s_2_m_axi_gmem_AWQOS;
  assign m_axi_gmem1_awregion[3:0] = mm2s_2_m_axi_gmem_AWREGION;
  assign m_axi_gmem1_awsize[2:0] = mm2s_2_m_axi_gmem_AWSIZE;
  assign m_axi_gmem1_awvalid = mm2s_2_m_axi_gmem_AWVALID;
  assign m_axi_gmem1_bready = mm2s_2_m_axi_gmem_BREADY;
  assign m_axi_gmem1_rready = mm2s_2_m_axi_gmem_RREADY;
  assign m_axi_gmem1_wdata[31:0] = mm2s_2_m_axi_gmem_WDATA;
  assign m_axi_gmem1_wlast = mm2s_2_m_axi_gmem_WLAST;
  assign m_axi_gmem1_wstrb[3:0] = mm2s_2_m_axi_gmem_WSTRB;
  assign m_axi_gmem1_wvalid = mm2s_2_m_axi_gmem_WVALID;
  assign m_axi_gmem2_araddr[63:0] = s2mm_m_axi_gmem_ARADDR;
  assign m_axi_gmem2_arburst[1:0] = s2mm_m_axi_gmem_ARBURST;
  assign m_axi_gmem2_arcache[3:0] = s2mm_m_axi_gmem_ARCACHE;
  assign m_axi_gmem2_arid[0] = s2mm_m_axi_gmem_ARID;
  assign m_axi_gmem2_arlen[7:0] = s2mm_m_axi_gmem_ARLEN;
  assign m_axi_gmem2_arlock[1:0] = s2mm_m_axi_gmem_ARLOCK;
  assign m_axi_gmem2_arprot[2:0] = s2mm_m_axi_gmem_ARPROT;
  assign m_axi_gmem2_arqos[3:0] = s2mm_m_axi_gmem_ARQOS;
  assign m_axi_gmem2_arregion[3:0] = s2mm_m_axi_gmem_ARREGION;
  assign m_axi_gmem2_arsize[2:0] = s2mm_m_axi_gmem_ARSIZE;
  assign m_axi_gmem2_arvalid = s2mm_m_axi_gmem_ARVALID;
  assign m_axi_gmem2_awaddr[63:0] = s2mm_m_axi_gmem_AWADDR;
  assign m_axi_gmem2_awburst[1:0] = s2mm_m_axi_gmem_AWBURST;
  assign m_axi_gmem2_awcache[3:0] = s2mm_m_axi_gmem_AWCACHE;
  assign m_axi_gmem2_awid[0] = s2mm_m_axi_gmem_AWID;
  assign m_axi_gmem2_awlen[7:0] = s2mm_m_axi_gmem_AWLEN;
  assign m_axi_gmem2_awlock[1:0] = s2mm_m_axi_gmem_AWLOCK;
  assign m_axi_gmem2_awprot[2:0] = s2mm_m_axi_gmem_AWPROT;
  assign m_axi_gmem2_awqos[3:0] = s2mm_m_axi_gmem_AWQOS;
  assign m_axi_gmem2_awregion[3:0] = s2mm_m_axi_gmem_AWREGION;
  assign m_axi_gmem2_awsize[2:0] = s2mm_m_axi_gmem_AWSIZE;
  assign m_axi_gmem2_awvalid = s2mm_m_axi_gmem_AWVALID;
  assign m_axi_gmem2_bready = s2mm_m_axi_gmem_BREADY;
  assign m_axi_gmem2_rready = s2mm_m_axi_gmem_RREADY;
  assign m_axi_gmem2_wdata[31:0] = s2mm_m_axi_gmem_WDATA;
  assign m_axi_gmem2_wlast = s2mm_m_axi_gmem_WLAST;
  assign m_axi_gmem2_wstrb[3:0] = s2mm_m_axi_gmem_WSTRB;
  assign m_axi_gmem2_wvalid = s2mm_m_axi_gmem_WVALID;
  assign m_axi_gmem_araddr[63:0] = mm2s_1_m_axi_gmem_ARADDR;
  assign m_axi_gmem_arburst[1:0] = mm2s_1_m_axi_gmem_ARBURST;
  assign m_axi_gmem_arcache[3:0] = mm2s_1_m_axi_gmem_ARCACHE;
  assign m_axi_gmem_arid[0] = mm2s_1_m_axi_gmem_ARID;
  assign m_axi_gmem_arlen[7:0] = mm2s_1_m_axi_gmem_ARLEN;
  assign m_axi_gmem_arlock[1:0] = mm2s_1_m_axi_gmem_ARLOCK;
  assign m_axi_gmem_arprot[2:0] = mm2s_1_m_axi_gmem_ARPROT;
  assign m_axi_gmem_arqos[3:0] = mm2s_1_m_axi_gmem_ARQOS;
  assign m_axi_gmem_arregion[3:0] = mm2s_1_m_axi_gmem_ARREGION;
  assign m_axi_gmem_arsize[2:0] = mm2s_1_m_axi_gmem_ARSIZE;
  assign m_axi_gmem_arvalid = mm2s_1_m_axi_gmem_ARVALID;
  assign m_axi_gmem_awaddr[63:0] = mm2s_1_m_axi_gmem_AWADDR;
  assign m_axi_gmem_awburst[1:0] = mm2s_1_m_axi_gmem_AWBURST;
  assign m_axi_gmem_awcache[3:0] = mm2s_1_m_axi_gmem_AWCACHE;
  assign m_axi_gmem_awid[0] = mm2s_1_m_axi_gmem_AWID;
  assign m_axi_gmem_awlen[7:0] = mm2s_1_m_axi_gmem_AWLEN;
  assign m_axi_gmem_awlock[1:0] = mm2s_1_m_axi_gmem_AWLOCK;
  assign m_axi_gmem_awprot[2:0] = mm2s_1_m_axi_gmem_AWPROT;
  assign m_axi_gmem_awqos[3:0] = mm2s_1_m_axi_gmem_AWQOS;
  assign m_axi_gmem_awregion[3:0] = mm2s_1_m_axi_gmem_AWREGION;
  assign m_axi_gmem_awsize[2:0] = mm2s_1_m_axi_gmem_AWSIZE;
  assign m_axi_gmem_awvalid = mm2s_1_m_axi_gmem_AWVALID;
  assign m_axi_gmem_bready = mm2s_1_m_axi_gmem_BREADY;
  assign m_axi_gmem_rready = mm2s_1_m_axi_gmem_RREADY;
  assign m_axi_gmem_wdata[31:0] = mm2s_1_m_axi_gmem_WDATA;
  assign m_axi_gmem_wlast = mm2s_1_m_axi_gmem_WLAST;
  assign m_axi_gmem_wstrb[3:0] = mm2s_1_m_axi_gmem_WSTRB;
  assign m_axi_gmem_wvalid = mm2s_1_m_axi_gmem_WVALID;
  assign mm2s_1_m_axi_gmem_ARREADY = m_axi_gmem_arready;
  assign mm2s_1_m_axi_gmem_AWREADY = m_axi_gmem_awready;
  assign mm2s_1_m_axi_gmem_BID = m_axi_gmem_bid[0];
  assign mm2s_1_m_axi_gmem_BRESP = m_axi_gmem_bresp[1:0];
  assign mm2s_1_m_axi_gmem_BVALID = m_axi_gmem_bvalid;
  assign mm2s_1_m_axi_gmem_RDATA = m_axi_gmem_rdata[31:0];
  assign mm2s_1_m_axi_gmem_RID = m_axi_gmem_rid[0];
  assign mm2s_1_m_axi_gmem_RLAST = m_axi_gmem_rlast;
  assign mm2s_1_m_axi_gmem_RRESP = m_axi_gmem_rresp[1:0];
  assign mm2s_1_m_axi_gmem_RVALID = m_axi_gmem_rvalid;
  assign mm2s_1_m_axi_gmem_WREADY = m_axi_gmem_wready;
  assign mm2s_2_m_axi_gmem_ARREADY = m_axi_gmem1_arready;
  assign mm2s_2_m_axi_gmem_AWREADY = m_axi_gmem1_awready;
  assign mm2s_2_m_axi_gmem_BID = m_axi_gmem1_bid[0];
  assign mm2s_2_m_axi_gmem_BRESP = m_axi_gmem1_bresp[1:0];
  assign mm2s_2_m_axi_gmem_BVALID = m_axi_gmem1_bvalid;
  assign mm2s_2_m_axi_gmem_RDATA = m_axi_gmem1_rdata[31:0];
  assign mm2s_2_m_axi_gmem_RID = m_axi_gmem1_rid[0];
  assign mm2s_2_m_axi_gmem_RLAST = m_axi_gmem1_rlast;
  assign mm2s_2_m_axi_gmem_RRESP = m_axi_gmem1_rresp[1:0];
  assign mm2s_2_m_axi_gmem_RVALID = m_axi_gmem1_rvalid;
  assign mm2s_2_m_axi_gmem_WREADY = m_axi_gmem1_wready;
  assign psr_312mhz_interconnect_aresetn = aresetn;
  assign psr_312mhz_peripheral_aresetn = ap_rst_n;
  assign s2mm_m_axi_gmem_ARREADY = m_axi_gmem2_arready;
  assign s2mm_m_axi_gmem_AWREADY = m_axi_gmem2_awready;
  assign s2mm_m_axi_gmem_BID = m_axi_gmem2_bid[0];
  assign s2mm_m_axi_gmem_BRESP = m_axi_gmem2_bresp[1:0];
  assign s2mm_m_axi_gmem_BVALID = m_axi_gmem2_bvalid;
  assign s2mm_m_axi_gmem_RDATA = m_axi_gmem2_rdata[31:0];
  assign s2mm_m_axi_gmem_RID = m_axi_gmem2_rid[0];
  assign s2mm_m_axi_gmem_RLAST = m_axi_gmem2_rlast;
  assign s2mm_m_axi_gmem_RRESP = m_axi_gmem2_rresp[1:0];
  assign s2mm_m_axi_gmem_RVALID = m_axi_gmem2_rvalid;
  assign s2mm_m_axi_gmem_WREADY = m_axi_gmem2_wready;
  assign s_axi_control1_arready = icn_ctrl_1_M07_AXI_ARREADY;
  assign s_axi_control1_awready = icn_ctrl_1_M07_AXI_AWREADY;
  assign s_axi_control1_bresp[1:0] = icn_ctrl_1_M07_AXI_BRESP;
  assign s_axi_control1_bvalid = icn_ctrl_1_M07_AXI_BVALID;
  assign s_axi_control1_rdata[31:0] = icn_ctrl_1_M07_AXI_RDATA;
  assign s_axi_control1_rresp[1:0] = icn_ctrl_1_M07_AXI_RRESP;
  assign s_axi_control1_rvalid = icn_ctrl_1_M07_AXI_RVALID;
  assign s_axi_control1_wready = icn_ctrl_1_M07_AXI_WREADY;
  assign s_axi_control2_arready = icn_ctrl_1_M08_AXI_ARREADY;
  assign s_axi_control2_awready = icn_ctrl_1_M08_AXI_AWREADY;
  assign s_axi_control2_bresp[1:0] = icn_ctrl_1_M08_AXI_BRESP;
  assign s_axi_control2_bvalid = icn_ctrl_1_M08_AXI_BVALID;
  assign s_axi_control2_rdata[31:0] = icn_ctrl_1_M08_AXI_RDATA;
  assign s_axi_control2_rresp[1:0] = icn_ctrl_1_M08_AXI_RRESP;
  assign s_axi_control2_rvalid = icn_ctrl_1_M08_AXI_RVALID;
  assign s_axi_control2_wready = icn_ctrl_1_M08_AXI_WREADY;
  assign s_axi_control_arready = icn_ctrl_1_M06_AXI_ARREADY;
  assign s_axi_control_awready = icn_ctrl_1_M06_AXI_AWREADY;
  assign s_axi_control_bresp[1:0] = icn_ctrl_1_M06_AXI_BRESP;
  assign s_axi_control_bvalid = icn_ctrl_1_M06_AXI_BVALID;
  assign s_axi_control_rdata[31:0] = icn_ctrl_1_M06_AXI_RDATA;
  assign s_axi_control_rresp[1:0] = icn_ctrl_1_M06_AXI_RRESP;
  assign s_axi_control_rvalid = icn_ctrl_1_M06_AXI_RVALID;
  assign s_axi_control_wready = icn_ctrl_1_M06_AXI_WREADY;
  System_DPA_imp_LGC0DA System_DPA
       (.MON_AXIS1_tdata(mm2s_2_s_TDATA),
        .MON_AXIS1_tkeep(mm2s_2_s_TKEEP),
        .MON_AXIS1_tlast(mm2s_2_s_TLAST),
        .MON_AXIS1_tready(mm2s_2_s_TREADY),
        .MON_AXIS1_tstrb(mm2s_2_s_TSTRB),
        .MON_AXIS1_tvalid(mm2s_2_s_TVALID),
        .MON_AXIS2_tdata(dwc_ai_engine_0_M00_AXIS_M_AXIS_TDATA),
        .MON_AXIS2_tkeep(dwc_ai_engine_0_M00_AXIS_M_AXIS_TKEEP),
        .MON_AXIS2_tlast(dwc_ai_engine_0_M00_AXIS_M_AXIS_TLAST),
        .MON_AXIS2_tready(dwc_ai_engine_0_M00_AXIS_M_AXIS_TREADY),
        .MON_AXIS2_tvalid(dwc_ai_engine_0_M00_AXIS_M_AXIS_TVALID),
        .MON_AXIS_tdata(mm2s_1_s_TDATA),
        .MON_AXIS_tkeep(mm2s_1_s_TKEEP),
        .MON_AXIS_tlast(mm2s_1_s_TLAST),
        .MON_AXIS_tready(mm2s_1_s_TREADY),
        .MON_AXIS_tstrb(mm2s_1_s_TSTRB),
        .MON_AXIS_tvalid(mm2s_1_s_TVALID),
        .MON_M_AXI1_araddr(mm2s_2_m_axi_gmem_ARADDR),
        .MON_M_AXI1_arburst(mm2s_2_m_axi_gmem_ARBURST),
        .MON_M_AXI1_arcache(mm2s_2_m_axi_gmem_ARCACHE),
        .MON_M_AXI1_arid(mm2s_2_m_axi_gmem_ARID),
        .MON_M_AXI1_arlen(mm2s_2_m_axi_gmem_ARLEN),
        .MON_M_AXI1_arlock(mm2s_2_m_axi_gmem_ARLOCK),
        .MON_M_AXI1_arprot(mm2s_2_m_axi_gmem_ARPROT),
        .MON_M_AXI1_arqos(mm2s_2_m_axi_gmem_ARQOS),
        .MON_M_AXI1_arready(mm2s_2_m_axi_gmem_ARREADY),
        .MON_M_AXI1_arregion(mm2s_2_m_axi_gmem_ARREGION),
        .MON_M_AXI1_arsize(mm2s_2_m_axi_gmem_ARSIZE),
        .MON_M_AXI1_arvalid(mm2s_2_m_axi_gmem_ARVALID),
        .MON_M_AXI1_awaddr(mm2s_2_m_axi_gmem_AWADDR),
        .MON_M_AXI1_awburst(mm2s_2_m_axi_gmem_AWBURST),
        .MON_M_AXI1_awcache(mm2s_2_m_axi_gmem_AWCACHE),
        .MON_M_AXI1_awid(mm2s_2_m_axi_gmem_AWID),
        .MON_M_AXI1_awlen(mm2s_2_m_axi_gmem_AWLEN),
        .MON_M_AXI1_awlock(mm2s_2_m_axi_gmem_AWLOCK),
        .MON_M_AXI1_awprot(mm2s_2_m_axi_gmem_AWPROT),
        .MON_M_AXI1_awqos(mm2s_2_m_axi_gmem_AWQOS),
        .MON_M_AXI1_awready(mm2s_2_m_axi_gmem_AWREADY),
        .MON_M_AXI1_awregion(mm2s_2_m_axi_gmem_AWREGION),
        .MON_M_AXI1_awsize(mm2s_2_m_axi_gmem_AWSIZE),
        .MON_M_AXI1_awvalid(mm2s_2_m_axi_gmem_AWVALID),
        .MON_M_AXI1_bid(mm2s_2_m_axi_gmem_BID),
        .MON_M_AXI1_bready(mm2s_2_m_axi_gmem_BREADY),
        .MON_M_AXI1_bresp(mm2s_2_m_axi_gmem_BRESP),
        .MON_M_AXI1_bvalid(mm2s_2_m_axi_gmem_BVALID),
        .MON_M_AXI1_rdata(mm2s_2_m_axi_gmem_RDATA),
        .MON_M_AXI1_rid(mm2s_2_m_axi_gmem_RID),
        .MON_M_AXI1_rlast(mm2s_2_m_axi_gmem_RLAST),
        .MON_M_AXI1_rready(mm2s_2_m_axi_gmem_RREADY),
        .MON_M_AXI1_rresp(mm2s_2_m_axi_gmem_RRESP),
        .MON_M_AXI1_rvalid(mm2s_2_m_axi_gmem_RVALID),
        .MON_M_AXI1_wdata(mm2s_2_m_axi_gmem_WDATA),
        .MON_M_AXI1_wlast(mm2s_2_m_axi_gmem_WLAST),
        .MON_M_AXI1_wready(mm2s_2_m_axi_gmem_WREADY),
        .MON_M_AXI1_wstrb(mm2s_2_m_axi_gmem_WSTRB),
        .MON_M_AXI1_wvalid(mm2s_2_m_axi_gmem_WVALID),
        .MON_M_AXI2_araddr(s2mm_m_axi_gmem_ARADDR),
        .MON_M_AXI2_arburst(s2mm_m_axi_gmem_ARBURST),
        .MON_M_AXI2_arcache(s2mm_m_axi_gmem_ARCACHE),
        .MON_M_AXI2_arid(s2mm_m_axi_gmem_ARID),
        .MON_M_AXI2_arlen(s2mm_m_axi_gmem_ARLEN),
        .MON_M_AXI2_arlock(s2mm_m_axi_gmem_ARLOCK),
        .MON_M_AXI2_arprot(s2mm_m_axi_gmem_ARPROT),
        .MON_M_AXI2_arqos(s2mm_m_axi_gmem_ARQOS),
        .MON_M_AXI2_arready(s2mm_m_axi_gmem_ARREADY),
        .MON_M_AXI2_arregion(s2mm_m_axi_gmem_ARREGION),
        .MON_M_AXI2_arsize(s2mm_m_axi_gmem_ARSIZE),
        .MON_M_AXI2_arvalid(s2mm_m_axi_gmem_ARVALID),
        .MON_M_AXI2_awaddr(s2mm_m_axi_gmem_AWADDR),
        .MON_M_AXI2_awburst(s2mm_m_axi_gmem_AWBURST),
        .MON_M_AXI2_awcache(s2mm_m_axi_gmem_AWCACHE),
        .MON_M_AXI2_awid(s2mm_m_axi_gmem_AWID),
        .MON_M_AXI2_awlen(s2mm_m_axi_gmem_AWLEN),
        .MON_M_AXI2_awlock(s2mm_m_axi_gmem_AWLOCK),
        .MON_M_AXI2_awprot(s2mm_m_axi_gmem_AWPROT),
        .MON_M_AXI2_awqos(s2mm_m_axi_gmem_AWQOS),
        .MON_M_AXI2_awready(s2mm_m_axi_gmem_AWREADY),
        .MON_M_AXI2_awregion(s2mm_m_axi_gmem_AWREGION),
        .MON_M_AXI2_awsize(s2mm_m_axi_gmem_AWSIZE),
        .MON_M_AXI2_awvalid(s2mm_m_axi_gmem_AWVALID),
        .MON_M_AXI2_bid(s2mm_m_axi_gmem_BID),
        .MON_M_AXI2_bready(s2mm_m_axi_gmem_BREADY),
        .MON_M_AXI2_bresp(s2mm_m_axi_gmem_BRESP),
        .MON_M_AXI2_bvalid(s2mm_m_axi_gmem_BVALID),
        .MON_M_AXI2_rdata(s2mm_m_axi_gmem_RDATA),
        .MON_M_AXI2_rid(s2mm_m_axi_gmem_RID),
        .MON_M_AXI2_rlast(s2mm_m_axi_gmem_RLAST),
        .MON_M_AXI2_rready(s2mm_m_axi_gmem_RREADY),
        .MON_M_AXI2_rresp(s2mm_m_axi_gmem_RRESP),
        .MON_M_AXI2_rvalid(s2mm_m_axi_gmem_RVALID),
        .MON_M_AXI2_wdata(s2mm_m_axi_gmem_WDATA),
        .MON_M_AXI2_wlast(s2mm_m_axi_gmem_WLAST),
        .MON_M_AXI2_wready(s2mm_m_axi_gmem_WREADY),
        .MON_M_AXI2_wstrb(s2mm_m_axi_gmem_WSTRB),
        .MON_M_AXI2_wvalid(s2mm_m_axi_gmem_WVALID),
        .MON_M_AXI_araddr(mm2s_1_m_axi_gmem_ARADDR),
        .MON_M_AXI_arburst(mm2s_1_m_axi_gmem_ARBURST),
        .MON_M_AXI_arcache(mm2s_1_m_axi_gmem_ARCACHE),
        .MON_M_AXI_arid(mm2s_1_m_axi_gmem_ARID),
        .MON_M_AXI_arlen(mm2s_1_m_axi_gmem_ARLEN),
        .MON_M_AXI_arlock(mm2s_1_m_axi_gmem_ARLOCK),
        .MON_M_AXI_arprot(mm2s_1_m_axi_gmem_ARPROT),
        .MON_M_AXI_arqos(mm2s_1_m_axi_gmem_ARQOS),
        .MON_M_AXI_arready(mm2s_1_m_axi_gmem_ARREADY),
        .MON_M_AXI_arregion(mm2s_1_m_axi_gmem_ARREGION),
        .MON_M_AXI_arsize(mm2s_1_m_axi_gmem_ARSIZE),
        .MON_M_AXI_arvalid(mm2s_1_m_axi_gmem_ARVALID),
        .MON_M_AXI_awaddr(mm2s_1_m_axi_gmem_AWADDR),
        .MON_M_AXI_awburst(mm2s_1_m_axi_gmem_AWBURST),
        .MON_M_AXI_awcache(mm2s_1_m_axi_gmem_AWCACHE),
        .MON_M_AXI_awid(mm2s_1_m_axi_gmem_AWID),
        .MON_M_AXI_awlen(mm2s_1_m_axi_gmem_AWLEN),
        .MON_M_AXI_awlock(mm2s_1_m_axi_gmem_AWLOCK),
        .MON_M_AXI_awprot(mm2s_1_m_axi_gmem_AWPROT),
        .MON_M_AXI_awqos(mm2s_1_m_axi_gmem_AWQOS),
        .MON_M_AXI_awready(mm2s_1_m_axi_gmem_AWREADY),
        .MON_M_AXI_awregion(mm2s_1_m_axi_gmem_AWREGION),
        .MON_M_AXI_awsize(mm2s_1_m_axi_gmem_AWSIZE),
        .MON_M_AXI_awvalid(mm2s_1_m_axi_gmem_AWVALID),
        .MON_M_AXI_bid(mm2s_1_m_axi_gmem_BID),
        .MON_M_AXI_bready(mm2s_1_m_axi_gmem_BREADY),
        .MON_M_AXI_bresp(mm2s_1_m_axi_gmem_BRESP),
        .MON_M_AXI_bvalid(mm2s_1_m_axi_gmem_BVALID),
        .MON_M_AXI_rdata(mm2s_1_m_axi_gmem_RDATA),
        .MON_M_AXI_rid(mm2s_1_m_axi_gmem_RID),
        .MON_M_AXI_rlast(mm2s_1_m_axi_gmem_RLAST),
        .MON_M_AXI_rready(mm2s_1_m_axi_gmem_RREADY),
        .MON_M_AXI_rresp(mm2s_1_m_axi_gmem_RRESP),
        .MON_M_AXI_rvalid(mm2s_1_m_axi_gmem_RVALID),
        .MON_M_AXI_wdata(mm2s_1_m_axi_gmem_WDATA),
        .MON_M_AXI_wlast(mm2s_1_m_axi_gmem_WLAST),
        .MON_M_AXI_wready(mm2s_1_m_axi_gmem_WREADY),
        .MON_M_AXI_wstrb(mm2s_1_m_axi_gmem_WSTRB),
        .MON_M_AXI_wvalid(mm2s_1_m_axi_gmem_WVALID),
        .MON_S_AXI1_araddr(icn_ctrl_1_M07_AXI_ARADDR),
        .MON_S_AXI1_arprot(icn_ctrl_1_M07_AXI_ARPROT),
        .MON_S_AXI1_arready(icn_ctrl_1_M07_AXI_ARREADY),
        .MON_S_AXI1_arvalid(icn_ctrl_1_M07_AXI_ARVALID),
        .MON_S_AXI1_awaddr(icn_ctrl_1_M07_AXI_AWADDR),
        .MON_S_AXI1_awprot(icn_ctrl_1_M07_AXI_AWPROT),
        .MON_S_AXI1_awready(icn_ctrl_1_M07_AXI_AWREADY),
        .MON_S_AXI1_awvalid(icn_ctrl_1_M07_AXI_AWVALID),
        .MON_S_AXI1_bready(icn_ctrl_1_M07_AXI_BREADY),
        .MON_S_AXI1_bresp(icn_ctrl_1_M07_AXI_BRESP),
        .MON_S_AXI1_bvalid(icn_ctrl_1_M07_AXI_BVALID),
        .MON_S_AXI1_rdata(icn_ctrl_1_M07_AXI_RDATA),
        .MON_S_AXI1_rready(icn_ctrl_1_M07_AXI_RREADY),
        .MON_S_AXI1_rresp(icn_ctrl_1_M07_AXI_RRESP),
        .MON_S_AXI1_rvalid(icn_ctrl_1_M07_AXI_RVALID),
        .MON_S_AXI1_wdata(icn_ctrl_1_M07_AXI_WDATA),
        .MON_S_AXI1_wready(icn_ctrl_1_M07_AXI_WREADY),
        .MON_S_AXI1_wstrb(icn_ctrl_1_M07_AXI_WSTRB),
        .MON_S_AXI1_wvalid(icn_ctrl_1_M07_AXI_WVALID),
        .MON_S_AXI2_araddr(icn_ctrl_1_M08_AXI_ARADDR),
        .MON_S_AXI2_arprot(icn_ctrl_1_M08_AXI_ARPROT),
        .MON_S_AXI2_arready(icn_ctrl_1_M08_AXI_ARREADY),
        .MON_S_AXI2_arvalid(icn_ctrl_1_M08_AXI_ARVALID),
        .MON_S_AXI2_awaddr(icn_ctrl_1_M08_AXI_AWADDR),
        .MON_S_AXI2_awprot(icn_ctrl_1_M08_AXI_AWPROT),
        .MON_S_AXI2_awready(icn_ctrl_1_M08_AXI_AWREADY),
        .MON_S_AXI2_awvalid(icn_ctrl_1_M08_AXI_AWVALID),
        .MON_S_AXI2_bready(icn_ctrl_1_M08_AXI_BREADY),
        .MON_S_AXI2_bresp(icn_ctrl_1_M08_AXI_BRESP),
        .MON_S_AXI2_bvalid(icn_ctrl_1_M08_AXI_BVALID),
        .MON_S_AXI2_rdata(icn_ctrl_1_M08_AXI_RDATA),
        .MON_S_AXI2_rready(icn_ctrl_1_M08_AXI_RREADY),
        .MON_S_AXI2_rresp(icn_ctrl_1_M08_AXI_RRESP),
        .MON_S_AXI2_rvalid(icn_ctrl_1_M08_AXI_RVALID),
        .MON_S_AXI2_wdata(icn_ctrl_1_M08_AXI_WDATA),
        .MON_S_AXI2_wready(icn_ctrl_1_M08_AXI_WREADY),
        .MON_S_AXI2_wstrb(icn_ctrl_1_M08_AXI_WSTRB),
        .MON_S_AXI2_wvalid(icn_ctrl_1_M08_AXI_WVALID),
        .MON_S_AXI_araddr(icn_ctrl_1_M06_AXI_ARADDR),
        .MON_S_AXI_arprot(icn_ctrl_1_M06_AXI_ARPROT),
        .MON_S_AXI_arready(icn_ctrl_1_M06_AXI_ARREADY),
        .MON_S_AXI_arvalid(icn_ctrl_1_M06_AXI_ARVALID),
        .MON_S_AXI_awaddr(icn_ctrl_1_M06_AXI_AWADDR),
        .MON_S_AXI_awprot(icn_ctrl_1_M06_AXI_AWPROT),
        .MON_S_AXI_awready(icn_ctrl_1_M06_AXI_AWREADY),
        .MON_S_AXI_awvalid(icn_ctrl_1_M06_AXI_AWVALID),
        .MON_S_AXI_bready(icn_ctrl_1_M06_AXI_BREADY),
        .MON_S_AXI_bresp(icn_ctrl_1_M06_AXI_BRESP),
        .MON_S_AXI_bvalid(icn_ctrl_1_M06_AXI_BVALID),
        .MON_S_AXI_rdata(icn_ctrl_1_M06_AXI_RDATA),
        .MON_S_AXI_rready(icn_ctrl_1_M06_AXI_RREADY),
        .MON_S_AXI_rresp(icn_ctrl_1_M06_AXI_RRESP),
        .MON_S_AXI_rvalid(icn_ctrl_1_M06_AXI_RVALID),
        .MON_S_AXI_wdata(icn_ctrl_1_M06_AXI_WDATA),
        .MON_S_AXI_wready(icn_ctrl_1_M06_AXI_WREADY),
        .MON_S_AXI_wstrb(icn_ctrl_1_M06_AXI_WSTRB),
        .MON_S_AXI_wvalid(icn_ctrl_1_M06_AXI_WVALID),
        .S00_AXI_araddr(icn_ctrl_1_M09_AXI_ARADDR),
        .S00_AXI_arburst(icn_ctrl_1_M09_AXI_ARBURST),
        .S00_AXI_arcache(icn_ctrl_1_M09_AXI_ARCACHE),
        .S00_AXI_arid(icn_ctrl_1_M09_AXI_ARID),
        .S00_AXI_arlen(icn_ctrl_1_M09_AXI_ARLEN),
        .S00_AXI_arlock(icn_ctrl_1_M09_AXI_ARLOCK),
        .S00_AXI_arprot(icn_ctrl_1_M09_AXI_ARPROT),
        .S00_AXI_arqos(icn_ctrl_1_M09_AXI_ARQOS),
        .S00_AXI_arready(icn_ctrl_1_M09_AXI_ARREADY),
        .S00_AXI_arsize(icn_ctrl_1_M09_AXI_ARSIZE),
        .S00_AXI_aruser(icn_ctrl_1_M09_AXI_ARUSER),
        .S00_AXI_arvalid(icn_ctrl_1_M09_AXI_ARVALID),
        .S00_AXI_awaddr(icn_ctrl_1_M09_AXI_AWADDR),
        .S00_AXI_awburst(icn_ctrl_1_M09_AXI_AWBURST),
        .S00_AXI_awcache(icn_ctrl_1_M09_AXI_AWCACHE),
        .S00_AXI_awid(icn_ctrl_1_M09_AXI_AWID),
        .S00_AXI_awlen(icn_ctrl_1_M09_AXI_AWLEN),
        .S00_AXI_awlock(icn_ctrl_1_M09_AXI_AWLOCK),
        .S00_AXI_awprot(icn_ctrl_1_M09_AXI_AWPROT),
        .S00_AXI_awqos(icn_ctrl_1_M09_AXI_AWQOS),
        .S00_AXI_awready(icn_ctrl_1_M09_AXI_AWREADY),
        .S00_AXI_awsize(icn_ctrl_1_M09_AXI_AWSIZE),
        .S00_AXI_awuser(icn_ctrl_1_M09_AXI_AWUSER),
        .S00_AXI_awvalid(icn_ctrl_1_M09_AXI_AWVALID),
        .S00_AXI_bid(icn_ctrl_1_M09_AXI_BID),
        .S00_AXI_bready(icn_ctrl_1_M09_AXI_BREADY),
        .S00_AXI_bresp(icn_ctrl_1_M09_AXI_BRESP),
        .S00_AXI_bvalid(icn_ctrl_1_M09_AXI_BVALID),
        .S00_AXI_rdata(icn_ctrl_1_M09_AXI_RDATA),
        .S00_AXI_rid(icn_ctrl_1_M09_AXI_RID),
        .S00_AXI_rlast(icn_ctrl_1_M09_AXI_RLAST),
        .S00_AXI_rready(icn_ctrl_1_M09_AXI_RREADY),
        .S00_AXI_rresp(icn_ctrl_1_M09_AXI_RRESP),
        .S00_AXI_ruser(icn_ctrl_1_M09_AXI_RUSER),
        .S00_AXI_rvalid(icn_ctrl_1_M09_AXI_RVALID),
        .S00_AXI_wdata(icn_ctrl_1_M09_AXI_WDATA),
        .S00_AXI_wlast(icn_ctrl_1_M09_AXI_WLAST),
        .S00_AXI_wready(icn_ctrl_1_M09_AXI_WREADY),
        .S00_AXI_wstrb(icn_ctrl_1_M09_AXI_WSTRB),
        .S00_AXI_wuser(icn_ctrl_1_M09_AXI_WUSER),
        .S00_AXI_wvalid(icn_ctrl_1_M09_AXI_WVALID),
        .S_AXIMM_araddr(icn_ctrl_1_M10_AXI_ARADDR),
        .S_AXIMM_arburst(icn_ctrl_1_M10_AXI_ARBURST),
        .S_AXIMM_arlen(icn_ctrl_1_M10_AXI_ARLEN),
        .S_AXIMM_arready(icn_ctrl_1_M10_AXI_ARREADY),
        .S_AXIMM_arsize(icn_ctrl_1_M10_AXI_ARSIZE),
        .S_AXIMM_arvalid(icn_ctrl_1_M10_AXI_ARVALID),
        .S_AXIMM_awaddr(icn_ctrl_1_M10_AXI_AWADDR),
        .S_AXIMM_awburst(icn_ctrl_1_M10_AXI_AWBURST),
        .S_AXIMM_awlen(icn_ctrl_1_M10_AXI_AWLEN),
        .S_AXIMM_awready(icn_ctrl_1_M10_AXI_AWREADY),
        .S_AXIMM_awsize(icn_ctrl_1_M10_AXI_AWSIZE),
        .S_AXIMM_awvalid(icn_ctrl_1_M10_AXI_AWVALID),
        .S_AXIMM_bready(icn_ctrl_1_M10_AXI_BREADY),
        .S_AXIMM_bresp(icn_ctrl_1_M10_AXI_BRESP),
        .S_AXIMM_bvalid(icn_ctrl_1_M10_AXI_BVALID),
        .S_AXIMM_rdata(icn_ctrl_1_M10_AXI_RDATA),
        .S_AXIMM_rlast(icn_ctrl_1_M10_AXI_RLAST),
        .S_AXIMM_rready(icn_ctrl_1_M10_AXI_RREADY),
        .S_AXIMM_rresp(icn_ctrl_1_M10_AXI_RRESP),
        .S_AXIMM_rvalid(icn_ctrl_1_M10_AXI_RVALID),
        .S_AXIMM_wdata(icn_ctrl_1_M10_AXI_WDATA),
        .S_AXIMM_wlast(icn_ctrl_1_M10_AXI_WLAST),
        .S_AXIMM_wready(icn_ctrl_1_M10_AXI_WREADY),
        .S_AXIMM_wstrb(icn_ctrl_1_M10_AXI_WSTRB),
        .S_AXIMM_wvalid(icn_ctrl_1_M10_AXI_WVALID),
        .mon_clk(clk_wizard_0_clk_out4_o1_o2),
        .mon_resetn(psr_312mhz_peripheral_aresetn));
  vitis_design_axi_intc_cascaded_1_intr_1_interrupt_concat_0 axi_intc_cascaded_1_intr_1_interrupt_concat
       (.In0(mm2s_2_interrupt),
        .In1(mm2s_1_interrupt),
        .In10(irq_const_tieoff_dout),
        .In11(irq_const_tieoff_dout),
        .In12(irq_const_tieoff_dout),
        .In13(irq_const_tieoff_dout),
        .In14(irq_const_tieoff_dout),
        .In15(irq_const_tieoff_dout),
        .In16(irq_const_tieoff_dout),
        .In17(irq_const_tieoff_dout),
        .In18(irq_const_tieoff_dout),
        .In19(irq_const_tieoff_dout),
        .In2(s2mm_interrupt),
        .In20(irq_const_tieoff_dout),
        .In21(irq_const_tieoff_dout),
        .In22(irq_const_tieoff_dout),
        .In23(irq_const_tieoff_dout),
        .In24(irq_const_tieoff_dout),
        .In25(irq_const_tieoff_dout),
        .In26(irq_const_tieoff_dout),
        .In27(irq_const_tieoff_dout),
        .In28(irq_const_tieoff_dout),
        .In29(irq_const_tieoff_dout),
        .In3(irq_const_tieoff_dout),
        .In30(irq_const_tieoff_dout),
        .In31(irq_const_tieoff_dout),
        .In4(irq_const_tieoff_dout),
        .In5(irq_const_tieoff_dout),
        .In6(irq_const_tieoff_dout),
        .In7(irq_const_tieoff_dout),
        .In8(irq_const_tieoff_dout),
        .In9(irq_const_tieoff_dout),
        .dout(axi_intc_cascaded_1_intr_1_interrupt_concat_dout));
  vitis_design_dwc_ai_engine_0_M00_AXIS_0 dwc_ai_engine_0_M00_AXIS
       (.aclk(clk_wizard_0_clk_out4_o1_o2),
        .aresetn(psr_312mhz_interconnect_aresetn),
        .m_axis_tdata(dwc_ai_engine_0_M00_AXIS_M_AXIS_TDATA),
        .m_axis_tkeep(dwc_ai_engine_0_M00_AXIS_M_AXIS_TKEEP),
        .m_axis_tlast(dwc_ai_engine_0_M00_AXIS_M_AXIS_TLAST),
        .m_axis_tready(dwc_ai_engine_0_M00_AXIS_M_AXIS_TREADY),
        .m_axis_tvalid(dwc_ai_engine_0_M00_AXIS_M_AXIS_TVALID),
        .s_axis_tdata(ai_engine_0_M00_AXIS_TDATA),
        .s_axis_tkeep(ai_engine_0_M00_AXIS_TKEEP),
        .s_axis_tlast(ai_engine_0_M00_AXIS_TLAST),
        .s_axis_tready(ai_engine_0_M00_AXIS_TREADY),
        .s_axis_tvalid(ai_engine_0_M00_AXIS_TVALID));
  vitis_design_dwc_mm2s_1_s_0 dwc_mm2s_1_s
       (.aclk(clk_wizard_0_clk_out4_o1_o2),
        .aresetn(psr_312mhz_interconnect_aresetn),
        .m_axis_tdata(dwc_mm2s_1_s_M_AXIS_TDATA),
        .m_axis_tkeep(dwc_mm2s_1_s_M_AXIS_TKEEP),
        .m_axis_tlast(dwc_mm2s_1_s_M_AXIS_TLAST),
        .m_axis_tready(dwc_mm2s_1_s_M_AXIS_TREADY),
        .m_axis_tvalid(dwc_mm2s_1_s_M_AXIS_TVALID),
        .s_axis_tdata(mm2s_1_s_TDATA),
        .s_axis_tkeep(mm2s_1_s_TKEEP),
        .s_axis_tlast(mm2s_1_s_TLAST),
        .s_axis_tready(mm2s_1_s_TREADY),
        .s_axis_tstrb(mm2s_1_s_TSTRB),
        .s_axis_tvalid(mm2s_1_s_TVALID));
  vitis_design_dwc_mm2s_2_s_0 dwc_mm2s_2_s
       (.aclk(clk_wizard_0_clk_out4_o1_o2),
        .aresetn(psr_312mhz_interconnect_aresetn),
        .m_axis_tdata(dwc_mm2s_2_s_M_AXIS_TDATA),
        .m_axis_tkeep(dwc_mm2s_2_s_M_AXIS_TKEEP),
        .m_axis_tlast(dwc_mm2s_2_s_M_AXIS_TLAST),
        .m_axis_tready(dwc_mm2s_2_s_M_AXIS_TREADY),
        .m_axis_tvalid(dwc_mm2s_2_s_M_AXIS_TVALID),
        .s_axis_tdata(mm2s_2_s_TDATA),
        .s_axis_tkeep(mm2s_2_s_TKEEP),
        .s_axis_tlast(mm2s_2_s_TLAST),
        .s_axis_tready(mm2s_2_s_TREADY),
        .s_axis_tstrb(mm2s_2_s_TSTRB),
        .s_axis_tvalid(mm2s_2_s_TVALID));
  vitis_design_irq_const_tieoff_0 irq_const_tieoff
       (.dout(irq_const_tieoff_dout));
  vitis_design_mm2s_1_0 mm2s_1
       (.ap_clk(clk_wizard_0_clk_out4_o1_o2),
        .ap_rst_n(psr_312mhz_peripheral_aresetn),
        .interrupt(mm2s_1_interrupt),
        .m_axi_gmem_ARADDR(mm2s_1_m_axi_gmem_ARADDR),
        .m_axi_gmem_ARBURST(mm2s_1_m_axi_gmem_ARBURST),
        .m_axi_gmem_ARCACHE(mm2s_1_m_axi_gmem_ARCACHE),
        .m_axi_gmem_ARID(mm2s_1_m_axi_gmem_ARID),
        .m_axi_gmem_ARLEN(mm2s_1_m_axi_gmem_ARLEN),
        .m_axi_gmem_ARLOCK(mm2s_1_m_axi_gmem_ARLOCK),
        .m_axi_gmem_ARPROT(mm2s_1_m_axi_gmem_ARPROT),
        .m_axi_gmem_ARQOS(mm2s_1_m_axi_gmem_ARQOS),
        .m_axi_gmem_ARREADY(mm2s_1_m_axi_gmem_ARREADY),
        .m_axi_gmem_ARREGION(mm2s_1_m_axi_gmem_ARREGION),
        .m_axi_gmem_ARSIZE(mm2s_1_m_axi_gmem_ARSIZE),
        .m_axi_gmem_ARVALID(mm2s_1_m_axi_gmem_ARVALID),
        .m_axi_gmem_AWADDR(mm2s_1_m_axi_gmem_AWADDR),
        .m_axi_gmem_AWBURST(mm2s_1_m_axi_gmem_AWBURST),
        .m_axi_gmem_AWCACHE(mm2s_1_m_axi_gmem_AWCACHE),
        .m_axi_gmem_AWID(mm2s_1_m_axi_gmem_AWID),
        .m_axi_gmem_AWLEN(mm2s_1_m_axi_gmem_AWLEN),
        .m_axi_gmem_AWLOCK(mm2s_1_m_axi_gmem_AWLOCK),
        .m_axi_gmem_AWPROT(mm2s_1_m_axi_gmem_AWPROT),
        .m_axi_gmem_AWQOS(mm2s_1_m_axi_gmem_AWQOS),
        .m_axi_gmem_AWREADY(mm2s_1_m_axi_gmem_AWREADY),
        .m_axi_gmem_AWREGION(mm2s_1_m_axi_gmem_AWREGION),
        .m_axi_gmem_AWSIZE(mm2s_1_m_axi_gmem_AWSIZE),
        .m_axi_gmem_AWVALID(mm2s_1_m_axi_gmem_AWVALID),
        .m_axi_gmem_BID(mm2s_1_m_axi_gmem_BID),
        .m_axi_gmem_BREADY(mm2s_1_m_axi_gmem_BREADY),
        .m_axi_gmem_BRESP(mm2s_1_m_axi_gmem_BRESP),
        .m_axi_gmem_BVALID(mm2s_1_m_axi_gmem_BVALID),
        .m_axi_gmem_RDATA(mm2s_1_m_axi_gmem_RDATA),
        .m_axi_gmem_RID(mm2s_1_m_axi_gmem_RID),
        .m_axi_gmem_RLAST(mm2s_1_m_axi_gmem_RLAST),
        .m_axi_gmem_RREADY(mm2s_1_m_axi_gmem_RREADY),
        .m_axi_gmem_RRESP(mm2s_1_m_axi_gmem_RRESP),
        .m_axi_gmem_RVALID(mm2s_1_m_axi_gmem_RVALID),
        .m_axi_gmem_WDATA(mm2s_1_m_axi_gmem_WDATA),
        .m_axi_gmem_WLAST(mm2s_1_m_axi_gmem_WLAST),
        .m_axi_gmem_WREADY(mm2s_1_m_axi_gmem_WREADY),
        .m_axi_gmem_WSTRB(mm2s_1_m_axi_gmem_WSTRB),
        .m_axi_gmem_WVALID(mm2s_1_m_axi_gmem_WVALID),
        .s_TDATA(mm2s_1_s_TDATA),
        .s_TKEEP(mm2s_1_s_TKEEP),
        .s_TLAST(mm2s_1_s_TLAST),
        .s_TREADY(mm2s_1_s_TREADY),
        .s_TSTRB(mm2s_1_s_TSTRB),
        .s_TVALID(mm2s_1_s_TVALID),
        .s_axi_control_ARADDR(icn_ctrl_1_M06_AXI_ARADDR),
        .s_axi_control_ARREADY(icn_ctrl_1_M06_AXI_ARREADY),
        .s_axi_control_ARVALID(icn_ctrl_1_M06_AXI_ARVALID),
        .s_axi_control_AWADDR(icn_ctrl_1_M06_AXI_AWADDR),
        .s_axi_control_AWREADY(icn_ctrl_1_M06_AXI_AWREADY),
        .s_axi_control_AWVALID(icn_ctrl_1_M06_AXI_AWVALID),
        .s_axi_control_BREADY(icn_ctrl_1_M06_AXI_BREADY),
        .s_axi_control_BRESP(icn_ctrl_1_M06_AXI_BRESP),
        .s_axi_control_BVALID(icn_ctrl_1_M06_AXI_BVALID),
        .s_axi_control_RDATA(icn_ctrl_1_M06_AXI_RDATA),
        .s_axi_control_RREADY(icn_ctrl_1_M06_AXI_RREADY),
        .s_axi_control_RRESP(icn_ctrl_1_M06_AXI_RRESP),
        .s_axi_control_RVALID(icn_ctrl_1_M06_AXI_RVALID),
        .s_axi_control_WDATA(icn_ctrl_1_M06_AXI_WDATA),
        .s_axi_control_WREADY(icn_ctrl_1_M06_AXI_WREADY),
        .s_axi_control_WSTRB(icn_ctrl_1_M06_AXI_WSTRB),
        .s_axi_control_WVALID(icn_ctrl_1_M06_AXI_WVALID));
  vitis_design_mm2s_2_0 mm2s_2
       (.ap_clk(clk_wizard_0_clk_out4_o1_o2),
        .ap_rst_n(psr_312mhz_peripheral_aresetn),
        .interrupt(mm2s_2_interrupt),
        .m_axi_gmem_ARADDR(mm2s_2_m_axi_gmem_ARADDR),
        .m_axi_gmem_ARBURST(mm2s_2_m_axi_gmem_ARBURST),
        .m_axi_gmem_ARCACHE(mm2s_2_m_axi_gmem_ARCACHE),
        .m_axi_gmem_ARID(mm2s_2_m_axi_gmem_ARID),
        .m_axi_gmem_ARLEN(mm2s_2_m_axi_gmem_ARLEN),
        .m_axi_gmem_ARLOCK(mm2s_2_m_axi_gmem_ARLOCK),
        .m_axi_gmem_ARPROT(mm2s_2_m_axi_gmem_ARPROT),
        .m_axi_gmem_ARQOS(mm2s_2_m_axi_gmem_ARQOS),
        .m_axi_gmem_ARREADY(mm2s_2_m_axi_gmem_ARREADY),
        .m_axi_gmem_ARREGION(mm2s_2_m_axi_gmem_ARREGION),
        .m_axi_gmem_ARSIZE(mm2s_2_m_axi_gmem_ARSIZE),
        .m_axi_gmem_ARVALID(mm2s_2_m_axi_gmem_ARVALID),
        .m_axi_gmem_AWADDR(mm2s_2_m_axi_gmem_AWADDR),
        .m_axi_gmem_AWBURST(mm2s_2_m_axi_gmem_AWBURST),
        .m_axi_gmem_AWCACHE(mm2s_2_m_axi_gmem_AWCACHE),
        .m_axi_gmem_AWID(mm2s_2_m_axi_gmem_AWID),
        .m_axi_gmem_AWLEN(mm2s_2_m_axi_gmem_AWLEN),
        .m_axi_gmem_AWLOCK(mm2s_2_m_axi_gmem_AWLOCK),
        .m_axi_gmem_AWPROT(mm2s_2_m_axi_gmem_AWPROT),
        .m_axi_gmem_AWQOS(mm2s_2_m_axi_gmem_AWQOS),
        .m_axi_gmem_AWREADY(mm2s_2_m_axi_gmem_AWREADY),
        .m_axi_gmem_AWREGION(mm2s_2_m_axi_gmem_AWREGION),
        .m_axi_gmem_AWSIZE(mm2s_2_m_axi_gmem_AWSIZE),
        .m_axi_gmem_AWVALID(mm2s_2_m_axi_gmem_AWVALID),
        .m_axi_gmem_BID(mm2s_2_m_axi_gmem_BID),
        .m_axi_gmem_BREADY(mm2s_2_m_axi_gmem_BREADY),
        .m_axi_gmem_BRESP(mm2s_2_m_axi_gmem_BRESP),
        .m_axi_gmem_BVALID(mm2s_2_m_axi_gmem_BVALID),
        .m_axi_gmem_RDATA(mm2s_2_m_axi_gmem_RDATA),
        .m_axi_gmem_RID(mm2s_2_m_axi_gmem_RID),
        .m_axi_gmem_RLAST(mm2s_2_m_axi_gmem_RLAST),
        .m_axi_gmem_RREADY(mm2s_2_m_axi_gmem_RREADY),
        .m_axi_gmem_RRESP(mm2s_2_m_axi_gmem_RRESP),
        .m_axi_gmem_RVALID(mm2s_2_m_axi_gmem_RVALID),
        .m_axi_gmem_WDATA(mm2s_2_m_axi_gmem_WDATA),
        .m_axi_gmem_WLAST(mm2s_2_m_axi_gmem_WLAST),
        .m_axi_gmem_WREADY(mm2s_2_m_axi_gmem_WREADY),
        .m_axi_gmem_WSTRB(mm2s_2_m_axi_gmem_WSTRB),
        .m_axi_gmem_WVALID(mm2s_2_m_axi_gmem_WVALID),
        .s_TDATA(mm2s_2_s_TDATA),
        .s_TKEEP(mm2s_2_s_TKEEP),
        .s_TLAST(mm2s_2_s_TLAST),
        .s_TREADY(mm2s_2_s_TREADY),
        .s_TSTRB(mm2s_2_s_TSTRB),
        .s_TVALID(mm2s_2_s_TVALID),
        .s_axi_control_ARADDR(icn_ctrl_1_M07_AXI_ARADDR),
        .s_axi_control_ARREADY(icn_ctrl_1_M07_AXI_ARREADY),
        .s_axi_control_ARVALID(icn_ctrl_1_M07_AXI_ARVALID),
        .s_axi_control_AWADDR(icn_ctrl_1_M07_AXI_AWADDR),
        .s_axi_control_AWREADY(icn_ctrl_1_M07_AXI_AWREADY),
        .s_axi_control_AWVALID(icn_ctrl_1_M07_AXI_AWVALID),
        .s_axi_control_BREADY(icn_ctrl_1_M07_AXI_BREADY),
        .s_axi_control_BRESP(icn_ctrl_1_M07_AXI_BRESP),
        .s_axi_control_BVALID(icn_ctrl_1_M07_AXI_BVALID),
        .s_axi_control_RDATA(icn_ctrl_1_M07_AXI_RDATA),
        .s_axi_control_RREADY(icn_ctrl_1_M07_AXI_RREADY),
        .s_axi_control_RRESP(icn_ctrl_1_M07_AXI_RRESP),
        .s_axi_control_RVALID(icn_ctrl_1_M07_AXI_RVALID),
        .s_axi_control_WDATA(icn_ctrl_1_M07_AXI_WDATA),
        .s_axi_control_WREADY(icn_ctrl_1_M07_AXI_WREADY),
        .s_axi_control_WSTRB(icn_ctrl_1_M07_AXI_WSTRB),
        .s_axi_control_WVALID(icn_ctrl_1_M07_AXI_WVALID));
  vitis_design_s2mm_0 s2mm
       (.ap_clk(clk_wizard_0_clk_out4_o1_o2),
        .ap_rst_n(psr_312mhz_peripheral_aresetn),
        .interrupt(s2mm_interrupt),
        .m_axi_gmem_ARADDR(s2mm_m_axi_gmem_ARADDR),
        .m_axi_gmem_ARBURST(s2mm_m_axi_gmem_ARBURST),
        .m_axi_gmem_ARCACHE(s2mm_m_axi_gmem_ARCACHE),
        .m_axi_gmem_ARID(s2mm_m_axi_gmem_ARID),
        .m_axi_gmem_ARLEN(s2mm_m_axi_gmem_ARLEN),
        .m_axi_gmem_ARLOCK(s2mm_m_axi_gmem_ARLOCK),
        .m_axi_gmem_ARPROT(s2mm_m_axi_gmem_ARPROT),
        .m_axi_gmem_ARQOS(s2mm_m_axi_gmem_ARQOS),
        .m_axi_gmem_ARREADY(s2mm_m_axi_gmem_ARREADY),
        .m_axi_gmem_ARREGION(s2mm_m_axi_gmem_ARREGION),
        .m_axi_gmem_ARSIZE(s2mm_m_axi_gmem_ARSIZE),
        .m_axi_gmem_ARVALID(s2mm_m_axi_gmem_ARVALID),
        .m_axi_gmem_AWADDR(s2mm_m_axi_gmem_AWADDR),
        .m_axi_gmem_AWBURST(s2mm_m_axi_gmem_AWBURST),
        .m_axi_gmem_AWCACHE(s2mm_m_axi_gmem_AWCACHE),
        .m_axi_gmem_AWID(s2mm_m_axi_gmem_AWID),
        .m_axi_gmem_AWLEN(s2mm_m_axi_gmem_AWLEN),
        .m_axi_gmem_AWLOCK(s2mm_m_axi_gmem_AWLOCK),
        .m_axi_gmem_AWPROT(s2mm_m_axi_gmem_AWPROT),
        .m_axi_gmem_AWQOS(s2mm_m_axi_gmem_AWQOS),
        .m_axi_gmem_AWREADY(s2mm_m_axi_gmem_AWREADY),
        .m_axi_gmem_AWREGION(s2mm_m_axi_gmem_AWREGION),
        .m_axi_gmem_AWSIZE(s2mm_m_axi_gmem_AWSIZE),
        .m_axi_gmem_AWVALID(s2mm_m_axi_gmem_AWVALID),
        .m_axi_gmem_BID(s2mm_m_axi_gmem_BID),
        .m_axi_gmem_BREADY(s2mm_m_axi_gmem_BREADY),
        .m_axi_gmem_BRESP(s2mm_m_axi_gmem_BRESP),
        .m_axi_gmem_BVALID(s2mm_m_axi_gmem_BVALID),
        .m_axi_gmem_RDATA(s2mm_m_axi_gmem_RDATA),
        .m_axi_gmem_RID(s2mm_m_axi_gmem_RID),
        .m_axi_gmem_RLAST(s2mm_m_axi_gmem_RLAST),
        .m_axi_gmem_RREADY(s2mm_m_axi_gmem_RREADY),
        .m_axi_gmem_RRESP(s2mm_m_axi_gmem_RRESP),
        .m_axi_gmem_RVALID(s2mm_m_axi_gmem_RVALID),
        .m_axi_gmem_WDATA(s2mm_m_axi_gmem_WDATA),
        .m_axi_gmem_WLAST(s2mm_m_axi_gmem_WLAST),
        .m_axi_gmem_WREADY(s2mm_m_axi_gmem_WREADY),
        .m_axi_gmem_WSTRB(s2mm_m_axi_gmem_WSTRB),
        .m_axi_gmem_WVALID(s2mm_m_axi_gmem_WVALID),
        .s_TDATA(dwc_ai_engine_0_M00_AXIS_M_AXIS_TDATA),
        .s_TKEEP(dwc_ai_engine_0_M00_AXIS_M_AXIS_TKEEP),
        .s_TLAST(dwc_ai_engine_0_M00_AXIS_M_AXIS_TLAST),
        .s_TREADY(dwc_ai_engine_0_M00_AXIS_M_AXIS_TREADY),
        .s_TSTRB({1'b1,1'b1,1'b1,1'b1}),
        .s_TVALID(dwc_ai_engine_0_M00_AXIS_M_AXIS_TVALID),
        .s_axi_control_ARADDR(icn_ctrl_1_M08_AXI_ARADDR),
        .s_axi_control_ARREADY(icn_ctrl_1_M08_AXI_ARREADY),
        .s_axi_control_ARVALID(icn_ctrl_1_M08_AXI_ARVALID),
        .s_axi_control_AWADDR(icn_ctrl_1_M08_AXI_AWADDR),
        .s_axi_control_AWREADY(icn_ctrl_1_M08_AXI_AWREADY),
        .s_axi_control_AWVALID(icn_ctrl_1_M08_AXI_AWVALID),
        .s_axi_control_BREADY(icn_ctrl_1_M08_AXI_BREADY),
        .s_axi_control_BRESP(icn_ctrl_1_M08_AXI_BRESP),
        .s_axi_control_BVALID(icn_ctrl_1_M08_AXI_BVALID),
        .s_axi_control_RDATA(icn_ctrl_1_M08_AXI_RDATA),
        .s_axi_control_RREADY(icn_ctrl_1_M08_AXI_RREADY),
        .s_axi_control_RRESP(icn_ctrl_1_M08_AXI_RRESP),
        .s_axi_control_RVALID(icn_ctrl_1_M08_AXI_RVALID),
        .s_axi_control_WDATA(icn_ctrl_1_M08_AXI_WDATA),
        .s_axi_control_WREADY(icn_ctrl_1_M08_AXI_WREADY),
        .s_axi_control_WSTRB(icn_ctrl_1_M08_AXI_WSTRB),
        .s_axi_control_WVALID(icn_ctrl_1_M08_AXI_WVALID));
endmodule

(* CORE_GENERATION_INFO = "vitis_design,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=vitis_design,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=44,numReposBlks=42,numNonXlnxBlks=0,numHierBlks=2,maxHierDepth=2,numSysgenBlks=0,numHlsBlks=3,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=Vitis,synth_mode=None}" *) (* HW_HANDOFF = "vitis_design.hwdef" *) 
module vitis_design
   (ch0_lpddr4_c0_ca_a,
    ch0_lpddr4_c0_ca_b,
    ch0_lpddr4_c0_ck_c_a,
    ch0_lpddr4_c0_ck_c_b,
    ch0_lpddr4_c0_ck_t_a,
    ch0_lpddr4_c0_ck_t_b,
    ch0_lpddr4_c0_cke_a,
    ch0_lpddr4_c0_cke_b,
    ch0_lpddr4_c0_cs_a,
    ch0_lpddr4_c0_cs_b,
    ch0_lpddr4_c0_dmi_a,
    ch0_lpddr4_c0_dmi_b,
    ch0_lpddr4_c0_dq_a,
    ch0_lpddr4_c0_dq_b,
    ch0_lpddr4_c0_dqs_c_a,
    ch0_lpddr4_c0_dqs_c_b,
    ch0_lpddr4_c0_dqs_t_a,
    ch0_lpddr4_c0_dqs_t_b,
    ch0_lpddr4_c0_reset_n,
    ch0_lpddr4_c1_ca_a,
    ch0_lpddr4_c1_ca_b,
    ch0_lpddr4_c1_ck_c_a,
    ch0_lpddr4_c1_ck_c_b,
    ch0_lpddr4_c1_ck_t_a,
    ch0_lpddr4_c1_ck_t_b,
    ch0_lpddr4_c1_cke_a,
    ch0_lpddr4_c1_cke_b,
    ch0_lpddr4_c1_cs_a,
    ch0_lpddr4_c1_cs_b,
    ch0_lpddr4_c1_dmi_a,
    ch0_lpddr4_c1_dmi_b,
    ch0_lpddr4_c1_dq_a,
    ch0_lpddr4_c1_dq_b,
    ch0_lpddr4_c1_dqs_c_a,
    ch0_lpddr4_c1_dqs_c_b,
    ch0_lpddr4_c1_dqs_t_a,
    ch0_lpddr4_c1_dqs_t_b,
    ch0_lpddr4_c1_reset_n,
    ch1_lpddr4_c0_ca_a,
    ch1_lpddr4_c0_ca_b,
    ch1_lpddr4_c0_ck_c_a,
    ch1_lpddr4_c0_ck_c_b,
    ch1_lpddr4_c0_ck_t_a,
    ch1_lpddr4_c0_ck_t_b,
    ch1_lpddr4_c0_cke_a,
    ch1_lpddr4_c0_cke_b,
    ch1_lpddr4_c0_cs_a,
    ch1_lpddr4_c0_cs_b,
    ch1_lpddr4_c0_dmi_a,
    ch1_lpddr4_c0_dmi_b,
    ch1_lpddr4_c0_dq_a,
    ch1_lpddr4_c0_dq_b,
    ch1_lpddr4_c0_dqs_c_a,
    ch1_lpddr4_c0_dqs_c_b,
    ch1_lpddr4_c0_dqs_t_a,
    ch1_lpddr4_c0_dqs_t_b,
    ch1_lpddr4_c0_reset_n,
    ch1_lpddr4_c1_ca_a,
    ch1_lpddr4_c1_ca_b,
    ch1_lpddr4_c1_ck_c_a,
    ch1_lpddr4_c1_ck_c_b,
    ch1_lpddr4_c1_ck_t_a,
    ch1_lpddr4_c1_ck_t_b,
    ch1_lpddr4_c1_cke_a,
    ch1_lpddr4_c1_cke_b,
    ch1_lpddr4_c1_cs_a,
    ch1_lpddr4_c1_cs_b,
    ch1_lpddr4_c1_dmi_a,
    ch1_lpddr4_c1_dmi_b,
    ch1_lpddr4_c1_dq_a,
    ch1_lpddr4_c1_dq_b,
    ch1_lpddr4_c1_dqs_c_a,
    ch1_lpddr4_c1_dqs_c_b,
    ch1_lpddr4_c1_dqs_t_a,
    ch1_lpddr4_c1_dqs_t_b,
    ch1_lpddr4_c1_reset_n,
    ddr4_dimm1_act_n,
    ddr4_dimm1_adr,
    ddr4_dimm1_ba,
    ddr4_dimm1_bg,
    ddr4_dimm1_ck_c,
    ddr4_dimm1_ck_t,
    ddr4_dimm1_cke,
    ddr4_dimm1_cs_n,
    ddr4_dimm1_dm_n,
    ddr4_dimm1_dq,
    ddr4_dimm1_dqs_c,
    ddr4_dimm1_dqs_t,
    ddr4_dimm1_odt,
    ddr4_dimm1_reset_n,
    ddr4_dimm1_sma_clk_clk_n,
    ddr4_dimm1_sma_clk_clk_p,
    lpddr4_sma_clk1_clk_n,
    lpddr4_sma_clk1_clk_p,
    lpddr4_sma_clk2_clk_n,
    lpddr4_sma_clk2_clk_p);
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c0 CA_A" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME ch0_lpddr4_c0, CAN_DEBUG false" *) output [5:0]ch0_lpddr4_c0_ca_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c0 CA_B" *) output [5:0]ch0_lpddr4_c0_ca_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c0 CK_C_A" *) output ch0_lpddr4_c0_ck_c_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c0 CK_C_B" *) output ch0_lpddr4_c0_ck_c_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c0 CK_T_A" *) output ch0_lpddr4_c0_ck_t_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c0 CK_T_B" *) output ch0_lpddr4_c0_ck_t_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c0 CKE_A" *) output ch0_lpddr4_c0_cke_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c0 CKE_B" *) output ch0_lpddr4_c0_cke_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c0 CS_A" *) output ch0_lpddr4_c0_cs_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c0 CS_B" *) output ch0_lpddr4_c0_cs_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c0 DMI_A" *) inout [1:0]ch0_lpddr4_c0_dmi_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c0 DMI_B" *) inout [1:0]ch0_lpddr4_c0_dmi_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c0 DQ_A" *) inout [15:0]ch0_lpddr4_c0_dq_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c0 DQ_B" *) inout [15:0]ch0_lpddr4_c0_dq_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c0 DQS_C_A" *) inout [1:0]ch0_lpddr4_c0_dqs_c_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c0 DQS_C_B" *) inout [1:0]ch0_lpddr4_c0_dqs_c_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c0 DQS_T_A" *) inout [1:0]ch0_lpddr4_c0_dqs_t_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c0 DQS_T_B" *) inout [1:0]ch0_lpddr4_c0_dqs_t_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c0 RESET_N" *) output ch0_lpddr4_c0_reset_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c1 CA_A" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME ch0_lpddr4_c1, CAN_DEBUG false" *) output [5:0]ch0_lpddr4_c1_ca_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c1 CA_B" *) output [5:0]ch0_lpddr4_c1_ca_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c1 CK_C_A" *) output ch0_lpddr4_c1_ck_c_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c1 CK_C_B" *) output ch0_lpddr4_c1_ck_c_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c1 CK_T_A" *) output ch0_lpddr4_c1_ck_t_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c1 CK_T_B" *) output ch0_lpddr4_c1_ck_t_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c1 CKE_A" *) output ch0_lpddr4_c1_cke_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c1 CKE_B" *) output ch0_lpddr4_c1_cke_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c1 CS_A" *) output ch0_lpddr4_c1_cs_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c1 CS_B" *) output ch0_lpddr4_c1_cs_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c1 DMI_A" *) inout [1:0]ch0_lpddr4_c1_dmi_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c1 DMI_B" *) inout [1:0]ch0_lpddr4_c1_dmi_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c1 DQ_A" *) inout [15:0]ch0_lpddr4_c1_dq_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c1 DQ_B" *) inout [15:0]ch0_lpddr4_c1_dq_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c1 DQS_C_A" *) inout [1:0]ch0_lpddr4_c1_dqs_c_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c1 DQS_C_B" *) inout [1:0]ch0_lpddr4_c1_dqs_c_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c1 DQS_T_A" *) inout [1:0]ch0_lpddr4_c1_dqs_t_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c1 DQS_T_B" *) inout [1:0]ch0_lpddr4_c1_dqs_t_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch0_lpddr4_c1 RESET_N" *) output ch0_lpddr4_c1_reset_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c0 CA_A" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME ch1_lpddr4_c0, CAN_DEBUG false" *) output [5:0]ch1_lpddr4_c0_ca_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c0 CA_B" *) output [5:0]ch1_lpddr4_c0_ca_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c0 CK_C_A" *) output ch1_lpddr4_c0_ck_c_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c0 CK_C_B" *) output ch1_lpddr4_c0_ck_c_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c0 CK_T_A" *) output ch1_lpddr4_c0_ck_t_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c0 CK_T_B" *) output ch1_lpddr4_c0_ck_t_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c0 CKE_A" *) output ch1_lpddr4_c0_cke_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c0 CKE_B" *) output ch1_lpddr4_c0_cke_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c0 CS_A" *) output ch1_lpddr4_c0_cs_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c0 CS_B" *) output ch1_lpddr4_c0_cs_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c0 DMI_A" *) inout [1:0]ch1_lpddr4_c0_dmi_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c0 DMI_B" *) inout [1:0]ch1_lpddr4_c0_dmi_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c0 DQ_A" *) inout [15:0]ch1_lpddr4_c0_dq_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c0 DQ_B" *) inout [15:0]ch1_lpddr4_c0_dq_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c0 DQS_C_A" *) inout [1:0]ch1_lpddr4_c0_dqs_c_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c0 DQS_C_B" *) inout [1:0]ch1_lpddr4_c0_dqs_c_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c0 DQS_T_A" *) inout [1:0]ch1_lpddr4_c0_dqs_t_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c0 DQS_T_B" *) inout [1:0]ch1_lpddr4_c0_dqs_t_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c0 RESET_N" *) output ch1_lpddr4_c0_reset_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c1 CA_A" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME ch1_lpddr4_c1, CAN_DEBUG false" *) output [5:0]ch1_lpddr4_c1_ca_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c1 CA_B" *) output [5:0]ch1_lpddr4_c1_ca_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c1 CK_C_A" *) output ch1_lpddr4_c1_ck_c_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c1 CK_C_B" *) output ch1_lpddr4_c1_ck_c_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c1 CK_T_A" *) output ch1_lpddr4_c1_ck_t_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c1 CK_T_B" *) output ch1_lpddr4_c1_ck_t_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c1 CKE_A" *) output ch1_lpddr4_c1_cke_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c1 CKE_B" *) output ch1_lpddr4_c1_cke_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c1 CS_A" *) output ch1_lpddr4_c1_cs_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c1 CS_B" *) output ch1_lpddr4_c1_cs_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c1 DMI_A" *) inout [1:0]ch1_lpddr4_c1_dmi_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c1 DMI_B" *) inout [1:0]ch1_lpddr4_c1_dmi_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c1 DQ_A" *) inout [15:0]ch1_lpddr4_c1_dq_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c1 DQ_B" *) inout [15:0]ch1_lpddr4_c1_dq_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c1 DQS_C_A" *) inout [1:0]ch1_lpddr4_c1_dqs_c_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c1 DQS_C_B" *) inout [1:0]ch1_lpddr4_c1_dqs_c_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c1 DQS_T_A" *) inout [1:0]ch1_lpddr4_c1_dqs_t_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c1 DQS_T_B" *) inout [1:0]ch1_lpddr4_c1_dqs_t_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 ch1_lpddr4_c1 RESET_N" *) output ch1_lpddr4_c1_reset_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 ddr4_dimm1 ACT_N" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME ddr4_dimm1, AXI_ARBITRATION_SCHEME TDM, BURST_LENGTH 8, CAN_DEBUG false, CAS_LATENCY 11, CAS_WRITE_LATENCY 11, CS_ENABLED true, DATA_MASK_ENABLED true, DATA_WIDTH 8, MEMORY_TYPE COMPONENTS, MEM_ADDR_MAP ROW_COLUMN_BANK, SLOT Single, TIMEPERIOD_PS 1250" *) output ddr4_dimm1_act_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 ddr4_dimm1 ADR" *) output [16:0]ddr4_dimm1_adr;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 ddr4_dimm1 BA" *) output [1:0]ddr4_dimm1_ba;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 ddr4_dimm1 BG" *) output [1:0]ddr4_dimm1_bg;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 ddr4_dimm1 CK_C" *) output ddr4_dimm1_ck_c;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 ddr4_dimm1 CK_T" *) output ddr4_dimm1_ck_t;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 ddr4_dimm1 CKE" *) output ddr4_dimm1_cke;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 ddr4_dimm1 CS_N" *) output ddr4_dimm1_cs_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 ddr4_dimm1 DM_N" *) inout [7:0]ddr4_dimm1_dm_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 ddr4_dimm1 DQ" *) inout [63:0]ddr4_dimm1_dq;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 ddr4_dimm1 DQS_C" *) inout [7:0]ddr4_dimm1_dqs_c;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 ddr4_dimm1 DQS_T" *) inout [7:0]ddr4_dimm1_dqs_t;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 ddr4_dimm1 ODT" *) output ddr4_dimm1_odt;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 ddr4_dimm1 RESET_N" *) output ddr4_dimm1_reset_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:diff_clock:1.0 ddr4_dimm1_sma_clk CLK_N" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME ddr4_dimm1_sma_clk, CAN_DEBUG false, FREQ_HZ 200000000" *) input ddr4_dimm1_sma_clk_clk_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:diff_clock:1.0 ddr4_dimm1_sma_clk CLK_P" *) input ddr4_dimm1_sma_clk_clk_p;
  (* X_INTERFACE_INFO = "xilinx.com:interface:diff_clock:1.0 lpddr4_sma_clk1 CLK_N" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME lpddr4_sma_clk1, CAN_DEBUG false, FREQ_HZ 200000000" *) input lpddr4_sma_clk1_clk_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:diff_clock:1.0 lpddr4_sma_clk1 CLK_P" *) input lpddr4_sma_clk1_clk_p;
  (* X_INTERFACE_INFO = "xilinx.com:interface:diff_clock:1.0 lpddr4_sma_clk2 CLK_N" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME lpddr4_sma_clk2, CAN_DEBUG false, FREQ_HZ 200000000" *) input lpddr4_sma_clk2_clk_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:diff_clock:1.0 lpddr4_sma_clk2 CLK_P" *) input lpddr4_sma_clk2_clk_p;

  (* HARD_CONN = "true" *) wire [63:0]CIPS_0_IF_PMC_NOC_AXI_0_ARADDR;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PMC_NOC_AXI_0_ARBURST;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PMC_NOC_AXI_0_ARCACHE;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PMC_NOC_AXI_0_ARID;
  (* HARD_CONN = "true" *) wire [7:0]CIPS_0_IF_PMC_NOC_AXI_0_ARLEN;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PMC_NOC_AXI_0_ARLOCK;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PMC_NOC_AXI_0_ARPROT;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PMC_NOC_AXI_0_ARQOS;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PMC_NOC_AXI_0_ARREADY;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PMC_NOC_AXI_0_ARREGION;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PMC_NOC_AXI_0_ARSIZE;
  (* HARD_CONN = "true" *) wire [17:0]CIPS_0_IF_PMC_NOC_AXI_0_ARUSER;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PMC_NOC_AXI_0_ARVALID;
  (* HARD_CONN = "true" *) wire [63:0]CIPS_0_IF_PMC_NOC_AXI_0_AWADDR;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PMC_NOC_AXI_0_AWBURST;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PMC_NOC_AXI_0_AWCACHE;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PMC_NOC_AXI_0_AWID;
  (* HARD_CONN = "true" *) wire [7:0]CIPS_0_IF_PMC_NOC_AXI_0_AWLEN;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PMC_NOC_AXI_0_AWLOCK;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PMC_NOC_AXI_0_AWPROT;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PMC_NOC_AXI_0_AWQOS;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PMC_NOC_AXI_0_AWREADY;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PMC_NOC_AXI_0_AWREGION;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PMC_NOC_AXI_0_AWSIZE;
  (* HARD_CONN = "true" *) wire [17:0]CIPS_0_IF_PMC_NOC_AXI_0_AWUSER;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PMC_NOC_AXI_0_AWVALID;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PMC_NOC_AXI_0_BID;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PMC_NOC_AXI_0_BREADY;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PMC_NOC_AXI_0_BRESP;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PMC_NOC_AXI_0_BUSER;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PMC_NOC_AXI_0_BVALID;
  (* HARD_CONN = "true" *) wire [127:0]CIPS_0_IF_PMC_NOC_AXI_0_RDATA;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PMC_NOC_AXI_0_RID;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PMC_NOC_AXI_0_RLAST;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PMC_NOC_AXI_0_RREADY;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PMC_NOC_AXI_0_RRESP;
  (* HARD_CONN = "true" *) wire [16:0]CIPS_0_IF_PMC_NOC_AXI_0_RUSER;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PMC_NOC_AXI_0_RVALID;
  (* HARD_CONN = "true" *) wire [127:0]CIPS_0_IF_PMC_NOC_AXI_0_WDATA;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PMC_NOC_AXI_0_WLAST;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PMC_NOC_AXI_0_WREADY;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PMC_NOC_AXI_0_WSTRB;
  (* HARD_CONN = "true" *) wire [16:0]CIPS_0_IF_PMC_NOC_AXI_0_WUSER;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PMC_NOC_AXI_0_WVALID;
  (* HARD_CONN = "true" *) wire [63:0]CIPS_0_IF_PS_NOC_CCI_0_ARADDR;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_CCI_0_ARBURST;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_CCI_0_ARCACHE;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_CCI_0_ARID;
  (* HARD_CONN = "true" *) wire [7:0]CIPS_0_IF_PS_NOC_CCI_0_ARLEN;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_0_ARLOCK;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_CCI_0_ARPROT;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_CCI_0_ARQOS;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_0_ARREADY;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_CCI_0_ARSIZE;
  (* HARD_CONN = "true" *) wire [17:0]CIPS_0_IF_PS_NOC_CCI_0_ARUSER;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_0_ARVALID;
  (* HARD_CONN = "true" *) wire [63:0]CIPS_0_IF_PS_NOC_CCI_0_AWADDR;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_CCI_0_AWBURST;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_CCI_0_AWCACHE;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_CCI_0_AWID;
  (* HARD_CONN = "true" *) wire [7:0]CIPS_0_IF_PS_NOC_CCI_0_AWLEN;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_0_AWLOCK;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_CCI_0_AWPROT;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_CCI_0_AWQOS;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_0_AWREADY;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_CCI_0_AWSIZE;
  (* HARD_CONN = "true" *) wire [17:0]CIPS_0_IF_PS_NOC_CCI_0_AWUSER;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_0_AWVALID;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_CCI_0_BID;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_0_BREADY;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_CCI_0_BRESP;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_0_BVALID;
  (* HARD_CONN = "true" *) wire [127:0]CIPS_0_IF_PS_NOC_CCI_0_RDATA;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_CCI_0_RID;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_0_RLAST;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_0_RREADY;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_CCI_0_RRESP;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_0_RVALID;
  (* HARD_CONN = "true" *) wire [127:0]CIPS_0_IF_PS_NOC_CCI_0_WDATA;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_0_WLAST;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_0_WREADY;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_CCI_0_WSTRB;
  (* HARD_CONN = "true" *) wire [16:0]CIPS_0_IF_PS_NOC_CCI_0_WUSER;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_0_WVALID;
  (* HARD_CONN = "true" *) wire [63:0]CIPS_0_IF_PS_NOC_CCI_1_ARADDR;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_CCI_1_ARBURST;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_CCI_1_ARCACHE;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_CCI_1_ARID;
  (* HARD_CONN = "true" *) wire [7:0]CIPS_0_IF_PS_NOC_CCI_1_ARLEN;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_1_ARLOCK;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_CCI_1_ARPROT;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_CCI_1_ARQOS;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_1_ARREADY;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_CCI_1_ARSIZE;
  (* HARD_CONN = "true" *) wire [17:0]CIPS_0_IF_PS_NOC_CCI_1_ARUSER;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_1_ARVALID;
  (* HARD_CONN = "true" *) wire [63:0]CIPS_0_IF_PS_NOC_CCI_1_AWADDR;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_CCI_1_AWBURST;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_CCI_1_AWCACHE;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_CCI_1_AWID;
  (* HARD_CONN = "true" *) wire [7:0]CIPS_0_IF_PS_NOC_CCI_1_AWLEN;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_1_AWLOCK;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_CCI_1_AWPROT;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_CCI_1_AWQOS;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_1_AWREADY;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_CCI_1_AWSIZE;
  (* HARD_CONN = "true" *) wire [17:0]CIPS_0_IF_PS_NOC_CCI_1_AWUSER;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_1_AWVALID;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_CCI_1_BID;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_1_BREADY;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_CCI_1_BRESP;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_1_BVALID;
  (* HARD_CONN = "true" *) wire [127:0]CIPS_0_IF_PS_NOC_CCI_1_RDATA;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_CCI_1_RID;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_1_RLAST;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_1_RREADY;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_CCI_1_RRESP;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_1_RVALID;
  (* HARD_CONN = "true" *) wire [127:0]CIPS_0_IF_PS_NOC_CCI_1_WDATA;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_1_WLAST;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_1_WREADY;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_CCI_1_WSTRB;
  (* HARD_CONN = "true" *) wire [16:0]CIPS_0_IF_PS_NOC_CCI_1_WUSER;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_1_WVALID;
  (* HARD_CONN = "true" *) wire [63:0]CIPS_0_IF_PS_NOC_CCI_2_ARADDR;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_CCI_2_ARBURST;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_CCI_2_ARCACHE;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_CCI_2_ARID;
  (* HARD_CONN = "true" *) wire [7:0]CIPS_0_IF_PS_NOC_CCI_2_ARLEN;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_2_ARLOCK;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_CCI_2_ARPROT;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_CCI_2_ARQOS;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_2_ARREADY;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_CCI_2_ARSIZE;
  (* HARD_CONN = "true" *) wire [17:0]CIPS_0_IF_PS_NOC_CCI_2_ARUSER;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_2_ARVALID;
  (* HARD_CONN = "true" *) wire [63:0]CIPS_0_IF_PS_NOC_CCI_2_AWADDR;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_CCI_2_AWBURST;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_CCI_2_AWCACHE;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_CCI_2_AWID;
  (* HARD_CONN = "true" *) wire [7:0]CIPS_0_IF_PS_NOC_CCI_2_AWLEN;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_2_AWLOCK;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_CCI_2_AWPROT;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_CCI_2_AWQOS;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_2_AWREADY;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_CCI_2_AWSIZE;
  (* HARD_CONN = "true" *) wire [17:0]CIPS_0_IF_PS_NOC_CCI_2_AWUSER;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_2_AWVALID;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_CCI_2_BID;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_2_BREADY;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_CCI_2_BRESP;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_2_BVALID;
  (* HARD_CONN = "true" *) wire [127:0]CIPS_0_IF_PS_NOC_CCI_2_RDATA;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_CCI_2_RID;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_2_RLAST;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_2_RREADY;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_CCI_2_RRESP;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_2_RVALID;
  (* HARD_CONN = "true" *) wire [127:0]CIPS_0_IF_PS_NOC_CCI_2_WDATA;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_2_WLAST;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_2_WREADY;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_CCI_2_WSTRB;
  (* HARD_CONN = "true" *) wire [16:0]CIPS_0_IF_PS_NOC_CCI_2_WUSER;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_2_WVALID;
  (* HARD_CONN = "true" *) wire [63:0]CIPS_0_IF_PS_NOC_CCI_3_ARADDR;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_CCI_3_ARBURST;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_CCI_3_ARCACHE;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_CCI_3_ARID;
  (* HARD_CONN = "true" *) wire [7:0]CIPS_0_IF_PS_NOC_CCI_3_ARLEN;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_3_ARLOCK;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_CCI_3_ARPROT;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_CCI_3_ARQOS;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_3_ARREADY;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_CCI_3_ARSIZE;
  (* HARD_CONN = "true" *) wire [17:0]CIPS_0_IF_PS_NOC_CCI_3_ARUSER;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_3_ARVALID;
  (* HARD_CONN = "true" *) wire [63:0]CIPS_0_IF_PS_NOC_CCI_3_AWADDR;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_CCI_3_AWBURST;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_CCI_3_AWCACHE;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_CCI_3_AWID;
  (* HARD_CONN = "true" *) wire [7:0]CIPS_0_IF_PS_NOC_CCI_3_AWLEN;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_3_AWLOCK;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_CCI_3_AWPROT;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_CCI_3_AWQOS;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_3_AWREADY;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_CCI_3_AWSIZE;
  (* HARD_CONN = "true" *) wire [17:0]CIPS_0_IF_PS_NOC_CCI_3_AWUSER;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_3_AWVALID;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_CCI_3_BID;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_3_BREADY;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_CCI_3_BRESP;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_3_BVALID;
  (* HARD_CONN = "true" *) wire [127:0]CIPS_0_IF_PS_NOC_CCI_3_RDATA;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_CCI_3_RID;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_3_RLAST;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_3_RREADY;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_CCI_3_RRESP;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_3_RVALID;
  (* HARD_CONN = "true" *) wire [127:0]CIPS_0_IF_PS_NOC_CCI_3_WDATA;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_3_WLAST;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_CCI_3_WREADY;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_CCI_3_WSTRB;
  (* HARD_CONN = "true" *) wire [16:0]CIPS_0_IF_PS_NOC_CCI_3_WUSER;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_CCI_3_WVALID;
  (* HARD_CONN = "true" *) wire [63:0]CIPS_0_IF_PS_NOC_NCI_0_ARADDR;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_NCI_0_ARBURST;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_NCI_0_ARCACHE;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_NCI_0_ARID;
  (* HARD_CONN = "true" *) wire [7:0]CIPS_0_IF_PS_NOC_NCI_0_ARLEN;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_NCI_0_ARLOCK;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_NCI_0_ARPROT;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_NCI_0_ARQOS;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_NCI_0_ARREADY;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_NCI_0_ARSIZE;
  (* HARD_CONN = "true" *) wire [17:0]CIPS_0_IF_PS_NOC_NCI_0_ARUSER;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_NCI_0_ARVALID;
  (* HARD_CONN = "true" *) wire [63:0]CIPS_0_IF_PS_NOC_NCI_0_AWADDR;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_NCI_0_AWBURST;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_NCI_0_AWCACHE;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_NCI_0_AWID;
  (* HARD_CONN = "true" *) wire [7:0]CIPS_0_IF_PS_NOC_NCI_0_AWLEN;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_NCI_0_AWLOCK;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_NCI_0_AWPROT;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_NCI_0_AWQOS;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_NCI_0_AWREADY;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_NCI_0_AWSIZE;
  (* HARD_CONN = "true" *) wire [17:0]CIPS_0_IF_PS_NOC_NCI_0_AWUSER;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_NCI_0_AWVALID;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_NCI_0_BID;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_NCI_0_BREADY;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_NCI_0_BRESP;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_NCI_0_BVALID;
  (* HARD_CONN = "true" *) wire [127:0]CIPS_0_IF_PS_NOC_NCI_0_RDATA;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_NCI_0_RID;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_NCI_0_RLAST;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_NCI_0_RREADY;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_NCI_0_RRESP;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_NCI_0_RVALID;
  (* HARD_CONN = "true" *) wire [127:0]CIPS_0_IF_PS_NOC_NCI_0_WDATA;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_NCI_0_WLAST;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_NCI_0_WREADY;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_NCI_0_WSTRB;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_NCI_0_WVALID;
  (* HARD_CONN = "true" *) wire [63:0]CIPS_0_IF_PS_NOC_NCI_1_ARADDR;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_NCI_1_ARBURST;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_NCI_1_ARCACHE;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_NCI_1_ARID;
  (* HARD_CONN = "true" *) wire [7:0]CIPS_0_IF_PS_NOC_NCI_1_ARLEN;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_NCI_1_ARLOCK;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_NCI_1_ARPROT;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_NCI_1_ARQOS;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_NCI_1_ARREADY;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_NCI_1_ARSIZE;
  (* HARD_CONN = "true" *) wire [17:0]CIPS_0_IF_PS_NOC_NCI_1_ARUSER;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_NCI_1_ARVALID;
  (* HARD_CONN = "true" *) wire [63:0]CIPS_0_IF_PS_NOC_NCI_1_AWADDR;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_NCI_1_AWBURST;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_NCI_1_AWCACHE;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_NCI_1_AWID;
  (* HARD_CONN = "true" *) wire [7:0]CIPS_0_IF_PS_NOC_NCI_1_AWLEN;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_NCI_1_AWLOCK;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_NCI_1_AWPROT;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_NCI_1_AWQOS;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_NCI_1_AWREADY;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_NCI_1_AWSIZE;
  (* HARD_CONN = "true" *) wire [17:0]CIPS_0_IF_PS_NOC_NCI_1_AWUSER;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_NCI_1_AWVALID;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_NCI_1_BID;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_NCI_1_BREADY;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_NCI_1_BRESP;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_NCI_1_BVALID;
  (* HARD_CONN = "true" *) wire [127:0]CIPS_0_IF_PS_NOC_NCI_1_RDATA;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_NCI_1_RID;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_NCI_1_RLAST;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_NCI_1_RREADY;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_NCI_1_RRESP;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_NCI_1_RVALID;
  (* HARD_CONN = "true" *) wire [127:0]CIPS_0_IF_PS_NOC_NCI_1_WDATA;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_NCI_1_WLAST;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_NCI_1_WREADY;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_NCI_1_WSTRB;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_NCI_1_WVALID;
  (* HARD_CONN = "true" *) wire [63:0]CIPS_0_IF_PS_NOC_RPU_0_ARADDR;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_RPU_0_ARBURST;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_RPU_0_ARCACHE;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_RPU_0_ARID;
  (* HARD_CONN = "true" *) wire [7:0]CIPS_0_IF_PS_NOC_RPU_0_ARLEN;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_RPU_0_ARLOCK;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_RPU_0_ARPROT;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_RPU_0_ARQOS;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_RPU_0_ARREADY;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_RPU_0_ARSIZE;
  (* HARD_CONN = "true" *) wire [17:0]CIPS_0_IF_PS_NOC_RPU_0_ARUSER;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_RPU_0_ARVALID;
  (* HARD_CONN = "true" *) wire [63:0]CIPS_0_IF_PS_NOC_RPU_0_AWADDR;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_RPU_0_AWBURST;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_RPU_0_AWCACHE;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_RPU_0_AWID;
  (* HARD_CONN = "true" *) wire [7:0]CIPS_0_IF_PS_NOC_RPU_0_AWLEN;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_RPU_0_AWLOCK;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_RPU_0_AWPROT;
  (* HARD_CONN = "true" *) wire [3:0]CIPS_0_IF_PS_NOC_RPU_0_AWQOS;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_RPU_0_AWREADY;
  (* HARD_CONN = "true" *) wire [2:0]CIPS_0_IF_PS_NOC_RPU_0_AWSIZE;
  (* HARD_CONN = "true" *) wire [17:0]CIPS_0_IF_PS_NOC_RPU_0_AWUSER;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_RPU_0_AWVALID;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_RPU_0_BID;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_RPU_0_BREADY;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_RPU_0_BRESP;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_RPU_0_BVALID;
  (* HARD_CONN = "true" *) wire [127:0]CIPS_0_IF_PS_NOC_RPU_0_RDATA;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_RPU_0_RID;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_RPU_0_RLAST;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_RPU_0_RREADY;
  (* HARD_CONN = "true" *) wire [1:0]CIPS_0_IF_PS_NOC_RPU_0_RRESP;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_RPU_0_RVALID;
  (* HARD_CONN = "true" *) wire [127:0]CIPS_0_IF_PS_NOC_RPU_0_WDATA;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_RPU_0_WLAST;
  (* HARD_CONN = "true" *) wire [0:0]CIPS_0_IF_PS_NOC_RPU_0_WREADY;
  (* HARD_CONN = "true" *) wire [15:0]CIPS_0_IF_PS_NOC_RPU_0_WSTRB;
  (* HARD_CONN = "true" *) wire CIPS_0_IF_PS_NOC_RPU_0_WVALID;
  wire [43:0]CIPS_0_M_AXI_GP0_ARADDR;
  wire [1:0]CIPS_0_M_AXI_GP0_ARBURST;
  wire [3:0]CIPS_0_M_AXI_GP0_ARCACHE;
  wire [15:0]CIPS_0_M_AXI_GP0_ARID;
  wire [7:0]CIPS_0_M_AXI_GP0_ARLEN;
  wire CIPS_0_M_AXI_GP0_ARLOCK;
  wire [2:0]CIPS_0_M_AXI_GP0_ARPROT;
  wire [3:0]CIPS_0_M_AXI_GP0_ARQOS;
  wire CIPS_0_M_AXI_GP0_ARREADY;
  wire [2:0]CIPS_0_M_AXI_GP0_ARSIZE;
  wire [15:0]CIPS_0_M_AXI_GP0_ARUSER;
  wire CIPS_0_M_AXI_GP0_ARVALID;
  wire [43:0]CIPS_0_M_AXI_GP0_AWADDR;
  wire [1:0]CIPS_0_M_AXI_GP0_AWBURST;
  wire [3:0]CIPS_0_M_AXI_GP0_AWCACHE;
  wire [15:0]CIPS_0_M_AXI_GP0_AWID;
  wire [7:0]CIPS_0_M_AXI_GP0_AWLEN;
  wire CIPS_0_M_AXI_GP0_AWLOCK;
  wire [2:0]CIPS_0_M_AXI_GP0_AWPROT;
  wire [3:0]CIPS_0_M_AXI_GP0_AWQOS;
  wire CIPS_0_M_AXI_GP0_AWREADY;
  wire [2:0]CIPS_0_M_AXI_GP0_AWSIZE;
  wire [15:0]CIPS_0_M_AXI_GP0_AWUSER;
  wire CIPS_0_M_AXI_GP0_AWVALID;
  wire [15:0]CIPS_0_M_AXI_GP0_BID;
  wire CIPS_0_M_AXI_GP0_BREADY;
  wire [1:0]CIPS_0_M_AXI_GP0_BRESP;
  wire CIPS_0_M_AXI_GP0_BVALID;
  wire [127:0]CIPS_0_M_AXI_GP0_RDATA;
  wire [15:0]CIPS_0_M_AXI_GP0_RID;
  wire CIPS_0_M_AXI_GP0_RLAST;
  wire CIPS_0_M_AXI_GP0_RREADY;
  wire [1:0]CIPS_0_M_AXI_GP0_RRESP;
  wire CIPS_0_M_AXI_GP0_RVALID;
  wire [127:0]CIPS_0_M_AXI_GP0_WDATA;
  wire CIPS_0_M_AXI_GP0_WLAST;
  wire CIPS_0_M_AXI_GP0_WREADY;
  wire [15:0]CIPS_0_M_AXI_GP0_WSTRB;
  wire CIPS_0_M_AXI_GP0_WVALID;
  wire CIPS_0_pl_clk0;
  wire CIPS_0_pl_resetn1;
  (* HARD_CONN = "true" *) wire CIPS_0_ps_pmc_noc_axi0_clk;
  (* HARD_CONN = "true" *) wire CIPS_0_ps_ps_noc_cci_axi0_clk;
  (* HARD_CONN = "true" *) wire CIPS_0_ps_ps_noc_cci_axi1_clk;
  (* HARD_CONN = "true" *) wire CIPS_0_ps_ps_noc_cci_axi2_clk;
  (* HARD_CONN = "true" *) wire CIPS_0_ps_ps_noc_cci_axi3_clk;
  (* HARD_CONN = "true" *) wire CIPS_0_ps_ps_noc_nci_axi0_clk;
  (* HARD_CONN = "true" *) wire CIPS_0_ps_ps_noc_nci_axi1_clk;
  (* HARD_CONN = "true" *) wire CIPS_0_ps_ps_noc_rpu_axi0_clk;
  wire VitisRegion_aclk_bypass_m;
  wire VitisRegion_ap_rst_n_bypass_m;
  wire [127:0]ai_engine_0_M00_AXIS_TDATA;
  wire [15:0]ai_engine_0_M00_AXIS_TKEEP;
  wire [0:0]ai_engine_0_M00_AXIS_TLAST;
  wire ai_engine_0_M00_AXIS_TREADY;
  wire [0:0]ai_engine_0_M00_AXIS_TVALID;
  (* HARD_CONN = "true" *) wire ai_engine_0_s00_axi_aclk;
  wire axi_intc_3_irq;
  wire [31:0]axi_intc_cascaded_1_intr_1_interrupt_concat_dout;
  wire axi_intc_cascaded_1_irq;
  wire [5:0]axi_noc_0_CH0_LPDDR4_0_CA_A;
  wire [5:0]axi_noc_0_CH0_LPDDR4_0_CA_B;
  wire [0:0]axi_noc_0_CH0_LPDDR4_0_CKE_A;
  wire [0:0]axi_noc_0_CH0_LPDDR4_0_CKE_B;
  wire [0:0]axi_noc_0_CH0_LPDDR4_0_CK_C_A;
  wire [0:0]axi_noc_0_CH0_LPDDR4_0_CK_C_B;
  wire [0:0]axi_noc_0_CH0_LPDDR4_0_CK_T_A;
  wire [0:0]axi_noc_0_CH0_LPDDR4_0_CK_T_B;
  wire [0:0]axi_noc_0_CH0_LPDDR4_0_CS_A;
  wire [0:0]axi_noc_0_CH0_LPDDR4_0_CS_B;
  wire [1:0]axi_noc_0_CH0_LPDDR4_0_DMI_A;
  wire [1:0]axi_noc_0_CH0_LPDDR4_0_DMI_B;
  wire [1:0]axi_noc_0_CH0_LPDDR4_0_DQS_C_A;
  wire [1:0]axi_noc_0_CH0_LPDDR4_0_DQS_C_B;
  wire [1:0]axi_noc_0_CH0_LPDDR4_0_DQS_T_A;
  wire [1:0]axi_noc_0_CH0_LPDDR4_0_DQS_T_B;
  wire [15:0]axi_noc_0_CH0_LPDDR4_0_DQ_A;
  wire [15:0]axi_noc_0_CH0_LPDDR4_0_DQ_B;
  wire [0:0]axi_noc_0_CH0_LPDDR4_0_RESET_N;
  wire [5:0]axi_noc_0_CH0_LPDDR4_1_CA_A;
  wire [5:0]axi_noc_0_CH0_LPDDR4_1_CA_B;
  wire [0:0]axi_noc_0_CH0_LPDDR4_1_CKE_A;
  wire [0:0]axi_noc_0_CH0_LPDDR4_1_CKE_B;
  wire [0:0]axi_noc_0_CH0_LPDDR4_1_CK_C_A;
  wire [0:0]axi_noc_0_CH0_LPDDR4_1_CK_C_B;
  wire [0:0]axi_noc_0_CH0_LPDDR4_1_CK_T_A;
  wire [0:0]axi_noc_0_CH0_LPDDR4_1_CK_T_B;
  wire [0:0]axi_noc_0_CH0_LPDDR4_1_CS_A;
  wire [0:0]axi_noc_0_CH0_LPDDR4_1_CS_B;
  wire [1:0]axi_noc_0_CH0_LPDDR4_1_DMI_A;
  wire [1:0]axi_noc_0_CH0_LPDDR4_1_DMI_B;
  wire [1:0]axi_noc_0_CH0_LPDDR4_1_DQS_C_A;
  wire [1:0]axi_noc_0_CH0_LPDDR4_1_DQS_C_B;
  wire [1:0]axi_noc_0_CH0_LPDDR4_1_DQS_T_A;
  wire [1:0]axi_noc_0_CH0_LPDDR4_1_DQS_T_B;
  wire [15:0]axi_noc_0_CH0_LPDDR4_1_DQ_A;
  wire [15:0]axi_noc_0_CH0_LPDDR4_1_DQ_B;
  wire [0:0]axi_noc_0_CH0_LPDDR4_1_RESET_N;
  wire [5:0]axi_noc_0_CH1_LPDDR4_0_CA_A;
  wire [5:0]axi_noc_0_CH1_LPDDR4_0_CA_B;
  wire [0:0]axi_noc_0_CH1_LPDDR4_0_CKE_A;
  wire [0:0]axi_noc_0_CH1_LPDDR4_0_CKE_B;
  wire [0:0]axi_noc_0_CH1_LPDDR4_0_CK_C_A;
  wire [0:0]axi_noc_0_CH1_LPDDR4_0_CK_C_B;
  wire [0:0]axi_noc_0_CH1_LPDDR4_0_CK_T_A;
  wire [0:0]axi_noc_0_CH1_LPDDR4_0_CK_T_B;
  wire [0:0]axi_noc_0_CH1_LPDDR4_0_CS_A;
  wire [0:0]axi_noc_0_CH1_LPDDR4_0_CS_B;
  wire [1:0]axi_noc_0_CH1_LPDDR4_0_DMI_A;
  wire [1:0]axi_noc_0_CH1_LPDDR4_0_DMI_B;
  wire [1:0]axi_noc_0_CH1_LPDDR4_0_DQS_C_A;
  wire [1:0]axi_noc_0_CH1_LPDDR4_0_DQS_C_B;
  wire [1:0]axi_noc_0_CH1_LPDDR4_0_DQS_T_A;
  wire [1:0]axi_noc_0_CH1_LPDDR4_0_DQS_T_B;
  wire [15:0]axi_noc_0_CH1_LPDDR4_0_DQ_A;
  wire [15:0]axi_noc_0_CH1_LPDDR4_0_DQ_B;
  wire [0:0]axi_noc_0_CH1_LPDDR4_0_RESET_N;
  wire [5:0]axi_noc_0_CH1_LPDDR4_1_CA_A;
  wire [5:0]axi_noc_0_CH1_LPDDR4_1_CA_B;
  wire [0:0]axi_noc_0_CH1_LPDDR4_1_CKE_A;
  wire [0:0]axi_noc_0_CH1_LPDDR4_1_CKE_B;
  wire [0:0]axi_noc_0_CH1_LPDDR4_1_CK_C_A;
  wire [0:0]axi_noc_0_CH1_LPDDR4_1_CK_C_B;
  wire [0:0]axi_noc_0_CH1_LPDDR4_1_CK_T_A;
  wire [0:0]axi_noc_0_CH1_LPDDR4_1_CK_T_B;
  wire [0:0]axi_noc_0_CH1_LPDDR4_1_CS_A;
  wire [0:0]axi_noc_0_CH1_LPDDR4_1_CS_B;
  wire [1:0]axi_noc_0_CH1_LPDDR4_1_DMI_A;
  wire [1:0]axi_noc_0_CH1_LPDDR4_1_DMI_B;
  wire [1:0]axi_noc_0_CH1_LPDDR4_1_DQS_C_A;
  wire [1:0]axi_noc_0_CH1_LPDDR4_1_DQS_C_B;
  wire [1:0]axi_noc_0_CH1_LPDDR4_1_DQS_T_A;
  wire [1:0]axi_noc_0_CH1_LPDDR4_1_DQS_T_B;
  wire [15:0]axi_noc_0_CH1_LPDDR4_1_DQ_A;
  wire [15:0]axi_noc_0_CH1_LPDDR4_1_DQ_B;
  wire [0:0]axi_noc_0_CH1_LPDDR4_1_RESET_N;
  (* HARD_CONN = "true" *) wire [63:0]cips_noc_M00_AXI_ARADDR;
  (* HARD_CONN = "true" *) wire [1:0]cips_noc_M00_AXI_ARBURST;
  (* HARD_CONN = "true" *) wire [3:0]cips_noc_M00_AXI_ARCACHE;
  (* HARD_CONN = "true" *) wire [1:0]cips_noc_M00_AXI_ARID;
  (* HARD_CONN = "true" *) wire [7:0]cips_noc_M00_AXI_ARLEN;
  (* HARD_CONN = "true" *) wire [0:0]cips_noc_M00_AXI_ARLOCK;
  (* HARD_CONN = "true" *) wire [2:0]cips_noc_M00_AXI_ARPROT;
  (* HARD_CONN = "true" *) wire [3:0]cips_noc_M00_AXI_ARQOS;
  (* HARD_CONN = "true" *) wire [0:0]cips_noc_M00_AXI_ARREADY;
  (* HARD_CONN = "true" *) wire [3:0]cips_noc_M00_AXI_ARREGION;
  (* HARD_CONN = "true" *) wire [2:0]cips_noc_M00_AXI_ARSIZE;
  (* HARD_CONN = "true" *) wire [0:0]cips_noc_M00_AXI_ARVALID;
  (* HARD_CONN = "true" *) wire [63:0]cips_noc_M00_AXI_AWADDR;
  (* HARD_CONN = "true" *) wire [1:0]cips_noc_M00_AXI_AWBURST;
  (* HARD_CONN = "true" *) wire [3:0]cips_noc_M00_AXI_AWCACHE;
  (* HARD_CONN = "true" *) wire [1:0]cips_noc_M00_AXI_AWID;
  (* HARD_CONN = "true" *) wire [7:0]cips_noc_M00_AXI_AWLEN;
  (* HARD_CONN = "true" *) wire [0:0]cips_noc_M00_AXI_AWLOCK;
  (* HARD_CONN = "true" *) wire [2:0]cips_noc_M00_AXI_AWPROT;
  (* HARD_CONN = "true" *) wire [3:0]cips_noc_M00_AXI_AWQOS;
  (* HARD_CONN = "true" *) wire [0:0]cips_noc_M00_AXI_AWREADY;
  (* HARD_CONN = "true" *) wire [3:0]cips_noc_M00_AXI_AWREGION;
  (* HARD_CONN = "true" *) wire [2:0]cips_noc_M00_AXI_AWSIZE;
  (* HARD_CONN = "true" *) wire [0:0]cips_noc_M00_AXI_AWVALID;
  (* HARD_CONN = "true" *) wire [15:0]cips_noc_M00_AXI_BID;
  (* HARD_CONN = "true" *) wire [0:0]cips_noc_M00_AXI_BREADY;
  (* HARD_CONN = "true" *) wire [1:0]cips_noc_M00_AXI_BRESP;
  (* HARD_CONN = "true" *) wire [0:0]cips_noc_M00_AXI_BVALID;
  (* HARD_CONN = "true" *) wire [127:0]cips_noc_M00_AXI_RDATA;
  (* HARD_CONN = "true" *) wire [15:0]cips_noc_M00_AXI_RID;
  (* HARD_CONN = "true" *) wire [0:0]cips_noc_M00_AXI_RLAST;
  (* HARD_CONN = "true" *) wire [0:0]cips_noc_M00_AXI_RREADY;
  (* HARD_CONN = "true" *) wire [1:0]cips_noc_M00_AXI_RRESP;
  (* HARD_CONN = "true" *) wire [16:0]cips_noc_M00_AXI_RUSER;
  (* HARD_CONN = "true" *) wire [0:0]cips_noc_M00_AXI_RVALID;
  (* HARD_CONN = "true" *) wire [127:0]cips_noc_M00_AXI_WDATA;
  (* HARD_CONN = "true" *) wire [0:0]cips_noc_M00_AXI_WLAST;
  (* HARD_CONN = "true" *) wire [0:0]cips_noc_M00_AXI_WREADY;
  (* HARD_CONN = "true" *) wire [15:0]cips_noc_M00_AXI_WSTRB;
  (* HARD_CONN = "true" *) wire [16:0]cips_noc_M00_AXI_WUSER;
  (* HARD_CONN = "true" *) wire [0:0]cips_noc_M00_AXI_WVALID;
  wire [0:0]cips_noc_M00_INI_INTERNOC;
  wire [0:0]cips_noc_M01_INI_INTERNOC;
  wire [0:0]cips_noc_M02_INI_INTERNOC;
  wire [0:0]cips_noc_M03_INI_INTERNOC;
  wire [0:0]cips_noc_M04_INI_INTERNOC;
  wire [0:0]cips_noc_M05_INI_INTERNOC;
  wire [0:0]cips_noc_M06_INI_INTERNOC;
  wire [0:0]cips_noc_M07_INI_INTERNOC;
  wire clk_wizard_0_clk_out1;
  wire clk_wizard_0_clk_out2;
  wire clk_wizard_0_clk_out3;
  wire clk_wizard_0_clk_out4_o1_o1;
  wire clk_wizard_0_clk_out4_o1_o2;
  wire clk_wizard_0_clk_out4_o1_o3;
  wire clk_wizard_0_clk_out4_o1_o4;
  wire clk_wizard_0_locked;
  wire ddr4_dimm1_sma_clk_1_CLK_N;
  wire ddr4_dimm1_sma_clk_1_CLK_P;
  wire [127:0]dwc_mm2s_1_s_M_AXIS_TDATA;
  wire [15:0]dwc_mm2s_1_s_M_AXIS_TKEEP;
  wire dwc_mm2s_1_s_M_AXIS_TLAST;
  wire [0:0]dwc_mm2s_1_s_M_AXIS_TREADY;
  wire dwc_mm2s_1_s_M_AXIS_TVALID;
  wire [127:0]dwc_mm2s_2_s_M_AXIS_TDATA;
  wire [15:0]dwc_mm2s_2_s_M_AXIS_TKEEP;
  wire dwc_mm2s_2_s_M_AXIS_TLAST;
  wire [0:0]dwc_mm2s_2_s_M_AXIS_TREADY;
  wire dwc_mm2s_2_s_M_AXIS_TVALID;
  wire [8:0]icn_ctrl_1_M00_AXI_ARADDR;
  wire icn_ctrl_1_M00_AXI_ARREADY;
  wire icn_ctrl_1_M00_AXI_ARVALID;
  wire [8:0]icn_ctrl_1_M00_AXI_AWADDR;
  wire icn_ctrl_1_M00_AXI_AWREADY;
  wire icn_ctrl_1_M00_AXI_AWVALID;
  wire icn_ctrl_1_M00_AXI_BREADY;
  wire [1:0]icn_ctrl_1_M00_AXI_BRESP;
  wire icn_ctrl_1_M00_AXI_BVALID;
  wire [31:0]icn_ctrl_1_M00_AXI_RDATA;
  wire icn_ctrl_1_M00_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M00_AXI_RRESP;
  wire icn_ctrl_1_M00_AXI_RVALID;
  wire [31:0]icn_ctrl_1_M00_AXI_WDATA;
  wire icn_ctrl_1_M00_AXI_WREADY;
  wire [3:0]icn_ctrl_1_M00_AXI_WSTRB;
  wire icn_ctrl_1_M00_AXI_WVALID;
  wire [8:0]icn_ctrl_1_M01_AXI_ARADDR;
  wire icn_ctrl_1_M01_AXI_ARREADY;
  wire icn_ctrl_1_M01_AXI_ARVALID;
  wire [8:0]icn_ctrl_1_M01_AXI_AWADDR;
  wire icn_ctrl_1_M01_AXI_AWREADY;
  wire icn_ctrl_1_M01_AXI_AWVALID;
  wire icn_ctrl_1_M01_AXI_BREADY;
  wire [1:0]icn_ctrl_1_M01_AXI_BRESP;
  wire icn_ctrl_1_M01_AXI_BVALID;
  wire [31:0]icn_ctrl_1_M01_AXI_RDATA;
  wire icn_ctrl_1_M01_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M01_AXI_RRESP;
  wire icn_ctrl_1_M01_AXI_RVALID;
  wire [31:0]icn_ctrl_1_M01_AXI_WDATA;
  wire icn_ctrl_1_M01_AXI_WREADY;
  wire [3:0]icn_ctrl_1_M01_AXI_WSTRB;
  wire icn_ctrl_1_M01_AXI_WVALID;
  wire [43:0]icn_ctrl_1_M02_AXI_ARADDR;
  wire [1:0]icn_ctrl_1_M02_AXI_ARBURST;
  wire [3:0]icn_ctrl_1_M02_AXI_ARCACHE;
  wire [0:0]icn_ctrl_1_M02_AXI_ARID;
  wire [7:0]icn_ctrl_1_M02_AXI_ARLEN;
  wire [0:0]icn_ctrl_1_M02_AXI_ARLOCK;
  wire [2:0]icn_ctrl_1_M02_AXI_ARPROT;
  wire [3:0]icn_ctrl_1_M02_AXI_ARQOS;
  wire icn_ctrl_1_M02_AXI_ARREADY;
  wire [2:0]icn_ctrl_1_M02_AXI_ARSIZE;
  wire [113:0]icn_ctrl_1_M02_AXI_ARUSER;
  wire icn_ctrl_1_M02_AXI_ARVALID;
  wire [43:0]icn_ctrl_1_M02_AXI_AWADDR;
  wire [1:0]icn_ctrl_1_M02_AXI_AWBURST;
  wire [3:0]icn_ctrl_1_M02_AXI_AWCACHE;
  wire [0:0]icn_ctrl_1_M02_AXI_AWID;
  wire [7:0]icn_ctrl_1_M02_AXI_AWLEN;
  wire [0:0]icn_ctrl_1_M02_AXI_AWLOCK;
  wire [2:0]icn_ctrl_1_M02_AXI_AWPROT;
  wire [3:0]icn_ctrl_1_M02_AXI_AWQOS;
  wire icn_ctrl_1_M02_AXI_AWREADY;
  wire [2:0]icn_ctrl_1_M02_AXI_AWSIZE;
  wire [113:0]icn_ctrl_1_M02_AXI_AWUSER;
  wire icn_ctrl_1_M02_AXI_AWVALID;
  wire [0:0]icn_ctrl_1_M02_AXI_BID;
  wire icn_ctrl_1_M02_AXI_BREADY;
  wire [1:0]icn_ctrl_1_M02_AXI_BRESP;
  wire icn_ctrl_1_M02_AXI_BVALID;
  wire [127:0]icn_ctrl_1_M02_AXI_RDATA;
  wire [0:0]icn_ctrl_1_M02_AXI_RID;
  wire icn_ctrl_1_M02_AXI_RLAST;
  wire icn_ctrl_1_M02_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M02_AXI_RRESP;
  wire [13:0]icn_ctrl_1_M02_AXI_RUSER;
  wire icn_ctrl_1_M02_AXI_RVALID;
  wire [127:0]icn_ctrl_1_M02_AXI_WDATA;
  wire icn_ctrl_1_M02_AXI_WLAST;
  wire icn_ctrl_1_M02_AXI_WREADY;
  wire [15:0]icn_ctrl_1_M02_AXI_WSTRB;
  wire [13:0]icn_ctrl_1_M02_AXI_WUSER;
  wire icn_ctrl_1_M02_AXI_WVALID;
  wire [43:0]icn_ctrl_1_M03_AXI_ARADDR;
  wire [1:0]icn_ctrl_1_M03_AXI_ARBURST;
  wire [3:0]icn_ctrl_1_M03_AXI_ARCACHE;
  wire [0:0]icn_ctrl_1_M03_AXI_ARID;
  wire [7:0]icn_ctrl_1_M03_AXI_ARLEN;
  wire [0:0]icn_ctrl_1_M03_AXI_ARLOCK;
  wire [2:0]icn_ctrl_1_M03_AXI_ARPROT;
  wire [3:0]icn_ctrl_1_M03_AXI_ARQOS;
  wire icn_ctrl_1_M03_AXI_ARREADY;
  wire [2:0]icn_ctrl_1_M03_AXI_ARSIZE;
  wire [113:0]icn_ctrl_1_M03_AXI_ARUSER;
  wire icn_ctrl_1_M03_AXI_ARVALID;
  wire [43:0]icn_ctrl_1_M03_AXI_AWADDR;
  wire [1:0]icn_ctrl_1_M03_AXI_AWBURST;
  wire [3:0]icn_ctrl_1_M03_AXI_AWCACHE;
  wire [0:0]icn_ctrl_1_M03_AXI_AWID;
  wire [7:0]icn_ctrl_1_M03_AXI_AWLEN;
  wire [0:0]icn_ctrl_1_M03_AXI_AWLOCK;
  wire [2:0]icn_ctrl_1_M03_AXI_AWPROT;
  wire [3:0]icn_ctrl_1_M03_AXI_AWQOS;
  wire icn_ctrl_1_M03_AXI_AWREADY;
  wire [2:0]icn_ctrl_1_M03_AXI_AWSIZE;
  wire [113:0]icn_ctrl_1_M03_AXI_AWUSER;
  wire icn_ctrl_1_M03_AXI_AWVALID;
  wire [0:0]icn_ctrl_1_M03_AXI_BID;
  wire icn_ctrl_1_M03_AXI_BREADY;
  wire [1:0]icn_ctrl_1_M03_AXI_BRESP;
  wire icn_ctrl_1_M03_AXI_BVALID;
  wire [127:0]icn_ctrl_1_M03_AXI_RDATA;
  wire [0:0]icn_ctrl_1_M03_AXI_RID;
  wire icn_ctrl_1_M03_AXI_RLAST;
  wire icn_ctrl_1_M03_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M03_AXI_RRESP;
  wire [13:0]icn_ctrl_1_M03_AXI_RUSER;
  wire icn_ctrl_1_M03_AXI_RVALID;
  wire [127:0]icn_ctrl_1_M03_AXI_WDATA;
  wire icn_ctrl_1_M03_AXI_WLAST;
  wire icn_ctrl_1_M03_AXI_WREADY;
  wire [15:0]icn_ctrl_1_M03_AXI_WSTRB;
  wire [13:0]icn_ctrl_1_M03_AXI_WUSER;
  wire icn_ctrl_1_M03_AXI_WVALID;
  wire [43:0]icn_ctrl_1_M04_AXI_ARADDR;
  wire [1:0]icn_ctrl_1_M04_AXI_ARBURST;
  wire [3:0]icn_ctrl_1_M04_AXI_ARCACHE;
  wire [0:0]icn_ctrl_1_M04_AXI_ARID;
  wire [7:0]icn_ctrl_1_M04_AXI_ARLEN;
  wire [0:0]icn_ctrl_1_M04_AXI_ARLOCK;
  wire [2:0]icn_ctrl_1_M04_AXI_ARPROT;
  wire [3:0]icn_ctrl_1_M04_AXI_ARQOS;
  wire icn_ctrl_1_M04_AXI_ARREADY;
  wire [2:0]icn_ctrl_1_M04_AXI_ARSIZE;
  wire [113:0]icn_ctrl_1_M04_AXI_ARUSER;
  wire icn_ctrl_1_M04_AXI_ARVALID;
  wire [43:0]icn_ctrl_1_M04_AXI_AWADDR;
  wire [1:0]icn_ctrl_1_M04_AXI_AWBURST;
  wire [3:0]icn_ctrl_1_M04_AXI_AWCACHE;
  wire [0:0]icn_ctrl_1_M04_AXI_AWID;
  wire [7:0]icn_ctrl_1_M04_AXI_AWLEN;
  wire [0:0]icn_ctrl_1_M04_AXI_AWLOCK;
  wire [2:0]icn_ctrl_1_M04_AXI_AWPROT;
  wire [3:0]icn_ctrl_1_M04_AXI_AWQOS;
  wire icn_ctrl_1_M04_AXI_AWREADY;
  wire [2:0]icn_ctrl_1_M04_AXI_AWSIZE;
  wire [113:0]icn_ctrl_1_M04_AXI_AWUSER;
  wire icn_ctrl_1_M04_AXI_AWVALID;
  wire [0:0]icn_ctrl_1_M04_AXI_BID;
  wire icn_ctrl_1_M04_AXI_BREADY;
  wire [1:0]icn_ctrl_1_M04_AXI_BRESP;
  wire icn_ctrl_1_M04_AXI_BVALID;
  wire [127:0]icn_ctrl_1_M04_AXI_RDATA;
  wire [0:0]icn_ctrl_1_M04_AXI_RID;
  wire icn_ctrl_1_M04_AXI_RLAST;
  wire icn_ctrl_1_M04_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M04_AXI_RRESP;
  wire [13:0]icn_ctrl_1_M04_AXI_RUSER;
  wire icn_ctrl_1_M04_AXI_RVALID;
  wire [127:0]icn_ctrl_1_M04_AXI_WDATA;
  wire icn_ctrl_1_M04_AXI_WLAST;
  wire icn_ctrl_1_M04_AXI_WREADY;
  wire [15:0]icn_ctrl_1_M04_AXI_WSTRB;
  wire [13:0]icn_ctrl_1_M04_AXI_WUSER;
  wire icn_ctrl_1_M04_AXI_WVALID;
  wire [43:0]icn_ctrl_1_M05_AXI_ARADDR;
  wire [1:0]icn_ctrl_1_M05_AXI_ARBURST;
  wire [3:0]icn_ctrl_1_M05_AXI_ARCACHE;
  wire [0:0]icn_ctrl_1_M05_AXI_ARID;
  wire [7:0]icn_ctrl_1_M05_AXI_ARLEN;
  wire [0:0]icn_ctrl_1_M05_AXI_ARLOCK;
  wire [2:0]icn_ctrl_1_M05_AXI_ARPROT;
  wire [3:0]icn_ctrl_1_M05_AXI_ARQOS;
  wire icn_ctrl_1_M05_AXI_ARREADY;
  wire [2:0]icn_ctrl_1_M05_AXI_ARSIZE;
  wire [113:0]icn_ctrl_1_M05_AXI_ARUSER;
  wire icn_ctrl_1_M05_AXI_ARVALID;
  wire [43:0]icn_ctrl_1_M05_AXI_AWADDR;
  wire [1:0]icn_ctrl_1_M05_AXI_AWBURST;
  wire [3:0]icn_ctrl_1_M05_AXI_AWCACHE;
  wire [0:0]icn_ctrl_1_M05_AXI_AWID;
  wire [7:0]icn_ctrl_1_M05_AXI_AWLEN;
  wire [0:0]icn_ctrl_1_M05_AXI_AWLOCK;
  wire [2:0]icn_ctrl_1_M05_AXI_AWPROT;
  wire [3:0]icn_ctrl_1_M05_AXI_AWQOS;
  wire icn_ctrl_1_M05_AXI_AWREADY;
  wire [2:0]icn_ctrl_1_M05_AXI_AWSIZE;
  wire [113:0]icn_ctrl_1_M05_AXI_AWUSER;
  wire icn_ctrl_1_M05_AXI_AWVALID;
  wire [0:0]icn_ctrl_1_M05_AXI_BID;
  wire icn_ctrl_1_M05_AXI_BREADY;
  wire [1:0]icn_ctrl_1_M05_AXI_BRESP;
  wire icn_ctrl_1_M05_AXI_BVALID;
  wire [127:0]icn_ctrl_1_M05_AXI_RDATA;
  wire [0:0]icn_ctrl_1_M05_AXI_RID;
  wire icn_ctrl_1_M05_AXI_RLAST;
  wire icn_ctrl_1_M05_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M05_AXI_RRESP;
  wire [13:0]icn_ctrl_1_M05_AXI_RUSER;
  wire icn_ctrl_1_M05_AXI_RVALID;
  wire [127:0]icn_ctrl_1_M05_AXI_WDATA;
  wire icn_ctrl_1_M05_AXI_WLAST;
  wire icn_ctrl_1_M05_AXI_WREADY;
  wire [15:0]icn_ctrl_1_M05_AXI_WSTRB;
  wire [13:0]icn_ctrl_1_M05_AXI_WUSER;
  wire icn_ctrl_1_M05_AXI_WVALID;
  wire [5:0]icn_ctrl_1_M06_AXI_ARADDR;
  wire [2:0]icn_ctrl_1_M06_AXI_ARPROT;
  wire icn_ctrl_1_M06_AXI_ARREADY;
  wire icn_ctrl_1_M06_AXI_ARVALID;
  wire [5:0]icn_ctrl_1_M06_AXI_AWADDR;
  wire [2:0]icn_ctrl_1_M06_AXI_AWPROT;
  wire icn_ctrl_1_M06_AXI_AWREADY;
  wire icn_ctrl_1_M06_AXI_AWVALID;
  wire icn_ctrl_1_M06_AXI_BREADY;
  wire [1:0]icn_ctrl_1_M06_AXI_BRESP;
  wire icn_ctrl_1_M06_AXI_BVALID;
  wire [31:0]icn_ctrl_1_M06_AXI_RDATA;
  wire icn_ctrl_1_M06_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M06_AXI_RRESP;
  wire icn_ctrl_1_M06_AXI_RVALID;
  wire [31:0]icn_ctrl_1_M06_AXI_WDATA;
  wire icn_ctrl_1_M06_AXI_WREADY;
  wire [3:0]icn_ctrl_1_M06_AXI_WSTRB;
  wire icn_ctrl_1_M06_AXI_WVALID;
  wire [5:0]icn_ctrl_1_M07_AXI_ARADDR;
  wire [2:0]icn_ctrl_1_M07_AXI_ARPROT;
  wire icn_ctrl_1_M07_AXI_ARREADY;
  wire icn_ctrl_1_M07_AXI_ARVALID;
  wire [5:0]icn_ctrl_1_M07_AXI_AWADDR;
  wire [2:0]icn_ctrl_1_M07_AXI_AWPROT;
  wire icn_ctrl_1_M07_AXI_AWREADY;
  wire icn_ctrl_1_M07_AXI_AWVALID;
  wire icn_ctrl_1_M07_AXI_BREADY;
  wire [1:0]icn_ctrl_1_M07_AXI_BRESP;
  wire icn_ctrl_1_M07_AXI_BVALID;
  wire [31:0]icn_ctrl_1_M07_AXI_RDATA;
  wire icn_ctrl_1_M07_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M07_AXI_RRESP;
  wire icn_ctrl_1_M07_AXI_RVALID;
  wire [31:0]icn_ctrl_1_M07_AXI_WDATA;
  wire icn_ctrl_1_M07_AXI_WREADY;
  wire [3:0]icn_ctrl_1_M07_AXI_WSTRB;
  wire icn_ctrl_1_M07_AXI_WVALID;
  wire [5:0]icn_ctrl_1_M08_AXI_ARADDR;
  wire [2:0]icn_ctrl_1_M08_AXI_ARPROT;
  wire icn_ctrl_1_M08_AXI_ARREADY;
  wire icn_ctrl_1_M08_AXI_ARVALID;
  wire [5:0]icn_ctrl_1_M08_AXI_AWADDR;
  wire [2:0]icn_ctrl_1_M08_AXI_AWPROT;
  wire icn_ctrl_1_M08_AXI_AWREADY;
  wire icn_ctrl_1_M08_AXI_AWVALID;
  wire icn_ctrl_1_M08_AXI_BREADY;
  wire [1:0]icn_ctrl_1_M08_AXI_BRESP;
  wire icn_ctrl_1_M08_AXI_BVALID;
  wire [31:0]icn_ctrl_1_M08_AXI_RDATA;
  wire icn_ctrl_1_M08_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M08_AXI_RRESP;
  wire icn_ctrl_1_M08_AXI_RVALID;
  wire [31:0]icn_ctrl_1_M08_AXI_WDATA;
  wire icn_ctrl_1_M08_AXI_WREADY;
  wire [3:0]icn_ctrl_1_M08_AXI_WSTRB;
  wire icn_ctrl_1_M08_AXI_WVALID;
  wire [43:0]icn_ctrl_1_M09_AXI_ARADDR;
  wire [1:0]icn_ctrl_1_M09_AXI_ARBURST;
  wire [3:0]icn_ctrl_1_M09_AXI_ARCACHE;
  wire [0:0]icn_ctrl_1_M09_AXI_ARID;
  wire [7:0]icn_ctrl_1_M09_AXI_ARLEN;
  wire [0:0]icn_ctrl_1_M09_AXI_ARLOCK;
  wire [2:0]icn_ctrl_1_M09_AXI_ARPROT;
  wire [3:0]icn_ctrl_1_M09_AXI_ARQOS;
  wire icn_ctrl_1_M09_AXI_ARREADY;
  wire [2:0]icn_ctrl_1_M09_AXI_ARSIZE;
  wire [113:0]icn_ctrl_1_M09_AXI_ARUSER;
  wire icn_ctrl_1_M09_AXI_ARVALID;
  wire [43:0]icn_ctrl_1_M09_AXI_AWADDR;
  wire [1:0]icn_ctrl_1_M09_AXI_AWBURST;
  wire [3:0]icn_ctrl_1_M09_AXI_AWCACHE;
  wire [0:0]icn_ctrl_1_M09_AXI_AWID;
  wire [7:0]icn_ctrl_1_M09_AXI_AWLEN;
  wire [0:0]icn_ctrl_1_M09_AXI_AWLOCK;
  wire [2:0]icn_ctrl_1_M09_AXI_AWPROT;
  wire [3:0]icn_ctrl_1_M09_AXI_AWQOS;
  wire icn_ctrl_1_M09_AXI_AWREADY;
  wire [2:0]icn_ctrl_1_M09_AXI_AWSIZE;
  wire [113:0]icn_ctrl_1_M09_AXI_AWUSER;
  wire icn_ctrl_1_M09_AXI_AWVALID;
  wire [0:0]icn_ctrl_1_M09_AXI_BID;
  wire icn_ctrl_1_M09_AXI_BREADY;
  wire [1:0]icn_ctrl_1_M09_AXI_BRESP;
  wire icn_ctrl_1_M09_AXI_BVALID;
  wire [127:0]icn_ctrl_1_M09_AXI_RDATA;
  wire [0:0]icn_ctrl_1_M09_AXI_RID;
  wire icn_ctrl_1_M09_AXI_RLAST;
  wire icn_ctrl_1_M09_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M09_AXI_RRESP;
  wire [13:0]icn_ctrl_1_M09_AXI_RUSER;
  wire icn_ctrl_1_M09_AXI_RVALID;
  wire [127:0]icn_ctrl_1_M09_AXI_WDATA;
  wire icn_ctrl_1_M09_AXI_WLAST;
  wire icn_ctrl_1_M09_AXI_WREADY;
  wire [15:0]icn_ctrl_1_M09_AXI_WSTRB;
  wire [13:0]icn_ctrl_1_M09_AXI_WUSER;
  wire icn_ctrl_1_M09_AXI_WVALID;
  wire [31:0]icn_ctrl_1_M10_AXI_ARADDR;
  wire [1:0]icn_ctrl_1_M10_AXI_ARBURST;
  wire [7:0]icn_ctrl_1_M10_AXI_ARLEN;
  wire icn_ctrl_1_M10_AXI_ARREADY;
  wire [2:0]icn_ctrl_1_M10_AXI_ARSIZE;
  wire icn_ctrl_1_M10_AXI_ARVALID;
  wire [31:0]icn_ctrl_1_M10_AXI_AWADDR;
  wire [1:0]icn_ctrl_1_M10_AXI_AWBURST;
  wire [7:0]icn_ctrl_1_M10_AXI_AWLEN;
  wire icn_ctrl_1_M10_AXI_AWREADY;
  wire [2:0]icn_ctrl_1_M10_AXI_AWSIZE;
  wire icn_ctrl_1_M10_AXI_AWVALID;
  wire icn_ctrl_1_M10_AXI_BREADY;
  wire [1:0]icn_ctrl_1_M10_AXI_BRESP;
  wire icn_ctrl_1_M10_AXI_BVALID;
  wire [31:0]icn_ctrl_1_M10_AXI_RDATA;
  wire icn_ctrl_1_M10_AXI_RLAST;
  wire icn_ctrl_1_M10_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M10_AXI_RRESP;
  wire icn_ctrl_1_M10_AXI_RVALID;
  wire [31:0]icn_ctrl_1_M10_AXI_WDATA;
  wire icn_ctrl_1_M10_AXI_WLAST;
  wire icn_ctrl_1_M10_AXI_WREADY;
  wire [3:0]icn_ctrl_1_M10_AXI_WSTRB;
  wire icn_ctrl_1_M10_AXI_WVALID;
  wire [31:0]icn_ctrl_2_M00_AXI_ARADDR;
  wire [2:0]icn_ctrl_2_M00_AXI_ARPROT;
  wire icn_ctrl_2_M00_AXI_ARREADY;
  wire icn_ctrl_2_M00_AXI_ARVALID;
  wire [31:0]icn_ctrl_2_M00_AXI_AWADDR;
  wire [2:0]icn_ctrl_2_M00_AXI_AWPROT;
  wire icn_ctrl_2_M00_AXI_AWREADY;
  wire icn_ctrl_2_M00_AXI_AWVALID;
  wire icn_ctrl_2_M00_AXI_BREADY;
  wire [1:0]icn_ctrl_2_M00_AXI_BRESP;
  wire icn_ctrl_2_M00_AXI_BVALID;
  wire [31:0]icn_ctrl_2_M00_AXI_RDATA;
  wire icn_ctrl_2_M00_AXI_RREADY;
  wire [1:0]icn_ctrl_2_M00_AXI_RRESP;
  wire icn_ctrl_2_M00_AXI_RVALID;
  wire [31:0]icn_ctrl_2_M00_AXI_WDATA;
  wire icn_ctrl_2_M00_AXI_WREADY;
  wire [3:0]icn_ctrl_2_M00_AXI_WSTRB;
  wire icn_ctrl_2_M00_AXI_WVALID;
  wire [31:0]icn_ctrl_3_M00_AXI_ARADDR;
  wire [2:0]icn_ctrl_3_M00_AXI_ARPROT;
  wire icn_ctrl_3_M00_AXI_ARREADY;
  wire icn_ctrl_3_M00_AXI_ARVALID;
  wire [31:0]icn_ctrl_3_M00_AXI_AWADDR;
  wire [2:0]icn_ctrl_3_M00_AXI_AWPROT;
  wire icn_ctrl_3_M00_AXI_AWREADY;
  wire icn_ctrl_3_M00_AXI_AWVALID;
  wire icn_ctrl_3_M00_AXI_BREADY;
  wire [1:0]icn_ctrl_3_M00_AXI_BRESP;
  wire icn_ctrl_3_M00_AXI_BVALID;
  wire [31:0]icn_ctrl_3_M00_AXI_RDATA;
  wire icn_ctrl_3_M00_AXI_RREADY;
  wire [1:0]icn_ctrl_3_M00_AXI_RRESP;
  wire icn_ctrl_3_M00_AXI_RVALID;
  wire [31:0]icn_ctrl_3_M00_AXI_WDATA;
  wire icn_ctrl_3_M00_AXI_WREADY;
  wire [3:0]icn_ctrl_3_M00_AXI_WSTRB;
  wire icn_ctrl_3_M00_AXI_WVALID;
  wire [31:0]icn_ctrl_4_M00_AXI_ARADDR;
  wire [2:0]icn_ctrl_4_M00_AXI_ARPROT;
  wire icn_ctrl_4_M00_AXI_ARREADY;
  wire icn_ctrl_4_M00_AXI_ARVALID;
  wire [31:0]icn_ctrl_4_M00_AXI_AWADDR;
  wire [2:0]icn_ctrl_4_M00_AXI_AWPROT;
  wire icn_ctrl_4_M00_AXI_AWREADY;
  wire icn_ctrl_4_M00_AXI_AWVALID;
  wire icn_ctrl_4_M00_AXI_BREADY;
  wire [1:0]icn_ctrl_4_M00_AXI_BRESP;
  wire icn_ctrl_4_M00_AXI_BVALID;
  wire [31:0]icn_ctrl_4_M00_AXI_RDATA;
  wire icn_ctrl_4_M00_AXI_RREADY;
  wire [1:0]icn_ctrl_4_M00_AXI_RRESP;
  wire icn_ctrl_4_M00_AXI_RVALID;
  wire [31:0]icn_ctrl_4_M00_AXI_WDATA;
  wire icn_ctrl_4_M00_AXI_WREADY;
  wire [3:0]icn_ctrl_4_M00_AXI_WSTRB;
  wire icn_ctrl_4_M00_AXI_WVALID;
  wire [31:0]icn_ctrl_5_M00_AXI_ARADDR;
  wire [2:0]icn_ctrl_5_M00_AXI_ARPROT;
  wire icn_ctrl_5_M00_AXI_ARREADY;
  wire icn_ctrl_5_M00_AXI_ARVALID;
  wire [31:0]icn_ctrl_5_M00_AXI_AWADDR;
  wire [2:0]icn_ctrl_5_M00_AXI_AWPROT;
  wire icn_ctrl_5_M00_AXI_AWREADY;
  wire icn_ctrl_5_M00_AXI_AWVALID;
  wire icn_ctrl_5_M00_AXI_BREADY;
  wire [1:0]icn_ctrl_5_M00_AXI_BRESP;
  wire icn_ctrl_5_M00_AXI_BVALID;
  wire [31:0]icn_ctrl_5_M00_AXI_RDATA;
  wire icn_ctrl_5_M00_AXI_RREADY;
  wire [1:0]icn_ctrl_5_M00_AXI_RRESP;
  wire icn_ctrl_5_M00_AXI_RVALID;
  wire [31:0]icn_ctrl_5_M00_AXI_WDATA;
  wire icn_ctrl_5_M00_AXI_WREADY;
  wire [3:0]icn_ctrl_5_M00_AXI_WSTRB;
  wire icn_ctrl_5_M00_AXI_WVALID;
  wire [0:0]irq_const_tieoff_dout;
  wire lpddr4_sma_clk1_1_CLK_N;
  wire lpddr4_sma_clk1_1_CLK_P;
  wire lpddr4_sma_clk2_1_CLK_N;
  wire lpddr4_sma_clk2_1_CLK_P;
  wire [63:0]mm2s_1_m_axi_gmem_ARADDR;
  wire [1:0]mm2s_1_m_axi_gmem_ARBURST;
  wire [3:0]mm2s_1_m_axi_gmem_ARCACHE;
  wire [0:0]mm2s_1_m_axi_gmem_ARID;
  wire [7:0]mm2s_1_m_axi_gmem_ARLEN;
  wire [1:0]mm2s_1_m_axi_gmem_ARLOCK;
  wire [2:0]mm2s_1_m_axi_gmem_ARPROT;
  wire [3:0]mm2s_1_m_axi_gmem_ARQOS;
  wire [0:0]mm2s_1_m_axi_gmem_ARREADY;
  wire [3:0]mm2s_1_m_axi_gmem_ARREGION;
  wire [2:0]mm2s_1_m_axi_gmem_ARSIZE;
  wire mm2s_1_m_axi_gmem_ARVALID;
  wire [63:0]mm2s_1_m_axi_gmem_AWADDR;
  wire [1:0]mm2s_1_m_axi_gmem_AWBURST;
  wire [3:0]mm2s_1_m_axi_gmem_AWCACHE;
  wire [0:0]mm2s_1_m_axi_gmem_AWID;
  wire [7:0]mm2s_1_m_axi_gmem_AWLEN;
  wire [1:0]mm2s_1_m_axi_gmem_AWLOCK;
  wire [2:0]mm2s_1_m_axi_gmem_AWPROT;
  wire [3:0]mm2s_1_m_axi_gmem_AWQOS;
  wire [0:0]mm2s_1_m_axi_gmem_AWREADY;
  wire [3:0]mm2s_1_m_axi_gmem_AWREGION;
  wire [2:0]mm2s_1_m_axi_gmem_AWSIZE;
  wire mm2s_1_m_axi_gmem_AWVALID;
  wire [0:0]mm2s_1_m_axi_gmem_BID;
  wire mm2s_1_m_axi_gmem_BREADY;
  wire [1:0]mm2s_1_m_axi_gmem_BRESP;
  wire [0:0]mm2s_1_m_axi_gmem_BVALID;
  wire [31:0]mm2s_1_m_axi_gmem_RDATA;
  wire [0:0]mm2s_1_m_axi_gmem_RID;
  wire [0:0]mm2s_1_m_axi_gmem_RLAST;
  wire mm2s_1_m_axi_gmem_RREADY;
  wire [1:0]mm2s_1_m_axi_gmem_RRESP;
  wire [0:0]mm2s_1_m_axi_gmem_RVALID;
  wire [31:0]mm2s_1_m_axi_gmem_WDATA;
  wire mm2s_1_m_axi_gmem_WLAST;
  wire [0:0]mm2s_1_m_axi_gmem_WREADY;
  wire [3:0]mm2s_1_m_axi_gmem_WSTRB;
  wire mm2s_1_m_axi_gmem_WVALID;
  wire [63:0]mm2s_2_m_axi_gmem_ARADDR;
  wire [1:0]mm2s_2_m_axi_gmem_ARBURST;
  wire [3:0]mm2s_2_m_axi_gmem_ARCACHE;
  wire [0:0]mm2s_2_m_axi_gmem_ARID;
  wire [7:0]mm2s_2_m_axi_gmem_ARLEN;
  wire [1:0]mm2s_2_m_axi_gmem_ARLOCK;
  wire [2:0]mm2s_2_m_axi_gmem_ARPROT;
  wire [3:0]mm2s_2_m_axi_gmem_ARQOS;
  wire [0:0]mm2s_2_m_axi_gmem_ARREADY;
  wire [3:0]mm2s_2_m_axi_gmem_ARREGION;
  wire [2:0]mm2s_2_m_axi_gmem_ARSIZE;
  wire mm2s_2_m_axi_gmem_ARVALID;
  wire [63:0]mm2s_2_m_axi_gmem_AWADDR;
  wire [1:0]mm2s_2_m_axi_gmem_AWBURST;
  wire [3:0]mm2s_2_m_axi_gmem_AWCACHE;
  wire [0:0]mm2s_2_m_axi_gmem_AWID;
  wire [7:0]mm2s_2_m_axi_gmem_AWLEN;
  wire [1:0]mm2s_2_m_axi_gmem_AWLOCK;
  wire [2:0]mm2s_2_m_axi_gmem_AWPROT;
  wire [3:0]mm2s_2_m_axi_gmem_AWQOS;
  wire [0:0]mm2s_2_m_axi_gmem_AWREADY;
  wire [3:0]mm2s_2_m_axi_gmem_AWREGION;
  wire [2:0]mm2s_2_m_axi_gmem_AWSIZE;
  wire mm2s_2_m_axi_gmem_AWVALID;
  wire [0:0]mm2s_2_m_axi_gmem_BID;
  wire mm2s_2_m_axi_gmem_BREADY;
  wire [1:0]mm2s_2_m_axi_gmem_BRESP;
  wire [0:0]mm2s_2_m_axi_gmem_BVALID;
  wire [31:0]mm2s_2_m_axi_gmem_RDATA;
  wire [0:0]mm2s_2_m_axi_gmem_RID;
  wire [0:0]mm2s_2_m_axi_gmem_RLAST;
  wire mm2s_2_m_axi_gmem_RREADY;
  wire [1:0]mm2s_2_m_axi_gmem_RRESP;
  wire [0:0]mm2s_2_m_axi_gmem_RVALID;
  wire [31:0]mm2s_2_m_axi_gmem_WDATA;
  wire mm2s_2_m_axi_gmem_WLAST;
  wire [0:0]mm2s_2_m_axi_gmem_WREADY;
  wire [3:0]mm2s_2_m_axi_gmem_WSTRB;
  wire mm2s_2_m_axi_gmem_WVALID;
  wire [0:0]noc_ddr4_CH0_DDR4_0_ACT_N;
  wire [16:0]noc_ddr4_CH0_DDR4_0_ADR;
  wire [1:0]noc_ddr4_CH0_DDR4_0_BA;
  wire [1:0]noc_ddr4_CH0_DDR4_0_BG;
  wire [0:0]noc_ddr4_CH0_DDR4_0_CKE;
  wire [0:0]noc_ddr4_CH0_DDR4_0_CK_C;
  wire [0:0]noc_ddr4_CH0_DDR4_0_CK_T;
  wire [0:0]noc_ddr4_CH0_DDR4_0_CS_N;
  wire [7:0]noc_ddr4_CH0_DDR4_0_DM_N;
  wire [63:0]noc_ddr4_CH0_DDR4_0_DQ;
  wire [7:0]noc_ddr4_CH0_DDR4_0_DQS_C;
  wire [7:0]noc_ddr4_CH0_DDR4_0_DQS_T;
  wire [0:0]noc_ddr4_CH0_DDR4_0_ODT;
  wire [0:0]noc_ddr4_CH0_DDR4_0_RESET_N;
  wire [0:0]psr_104mhz_peripheral_aresetn;
  wire [0:0]psr_312mhz_interconnect_aresetn;
  wire [0:0]psr_312mhz_peripheral_aresetn;
  wire [63:0]s2mm_m_axi_gmem_ARADDR;
  wire [1:0]s2mm_m_axi_gmem_ARBURST;
  wire [3:0]s2mm_m_axi_gmem_ARCACHE;
  wire [0:0]s2mm_m_axi_gmem_ARID;
  wire [7:0]s2mm_m_axi_gmem_ARLEN;
  wire [1:0]s2mm_m_axi_gmem_ARLOCK;
  wire [2:0]s2mm_m_axi_gmem_ARPROT;
  wire [3:0]s2mm_m_axi_gmem_ARQOS;
  wire [0:0]s2mm_m_axi_gmem_ARREADY;
  wire [3:0]s2mm_m_axi_gmem_ARREGION;
  wire [2:0]s2mm_m_axi_gmem_ARSIZE;
  wire s2mm_m_axi_gmem_ARVALID;
  wire [63:0]s2mm_m_axi_gmem_AWADDR;
  wire [1:0]s2mm_m_axi_gmem_AWBURST;
  wire [3:0]s2mm_m_axi_gmem_AWCACHE;
  wire [0:0]s2mm_m_axi_gmem_AWID;
  wire [7:0]s2mm_m_axi_gmem_AWLEN;
  wire [1:0]s2mm_m_axi_gmem_AWLOCK;
  wire [2:0]s2mm_m_axi_gmem_AWPROT;
  wire [3:0]s2mm_m_axi_gmem_AWQOS;
  wire [0:0]s2mm_m_axi_gmem_AWREADY;
  wire [3:0]s2mm_m_axi_gmem_AWREGION;
  wire [2:0]s2mm_m_axi_gmem_AWSIZE;
  wire s2mm_m_axi_gmem_AWVALID;
  wire [0:0]s2mm_m_axi_gmem_BID;
  wire s2mm_m_axi_gmem_BREADY;
  wire [1:0]s2mm_m_axi_gmem_BRESP;
  wire [0:0]s2mm_m_axi_gmem_BVALID;
  wire [31:0]s2mm_m_axi_gmem_RDATA;
  wire [0:0]s2mm_m_axi_gmem_RID;
  wire [0:0]s2mm_m_axi_gmem_RLAST;
  wire s2mm_m_axi_gmem_RREADY;
  wire [1:0]s2mm_m_axi_gmem_RRESP;
  wire [0:0]s2mm_m_axi_gmem_RVALID;
  wire [31:0]s2mm_m_axi_gmem_WDATA;
  wire s2mm_m_axi_gmem_WLAST;
  wire [0:0]s2mm_m_axi_gmem_WREADY;
  wire [3:0]s2mm_m_axi_gmem_WSTRB;
  wire s2mm_m_axi_gmem_WVALID;
  wire [31:0]xlconcat_0_dout;
  wire [0:0]xlconstant_0_dout;

  assign ch0_lpddr4_c0_ca_a[5:0] = axi_noc_0_CH0_LPDDR4_0_CA_A;
  assign ch0_lpddr4_c0_ca_b[5:0] = axi_noc_0_CH0_LPDDR4_0_CA_B;
  assign ch0_lpddr4_c0_ck_c_a = axi_noc_0_CH0_LPDDR4_0_CK_C_A;
  assign ch0_lpddr4_c0_ck_c_b = axi_noc_0_CH0_LPDDR4_0_CK_C_B;
  assign ch0_lpddr4_c0_ck_t_a = axi_noc_0_CH0_LPDDR4_0_CK_T_A;
  assign ch0_lpddr4_c0_ck_t_b = axi_noc_0_CH0_LPDDR4_0_CK_T_B;
  assign ch0_lpddr4_c0_cke_a = axi_noc_0_CH0_LPDDR4_0_CKE_A;
  assign ch0_lpddr4_c0_cke_b = axi_noc_0_CH0_LPDDR4_0_CKE_B;
  assign ch0_lpddr4_c0_cs_a = axi_noc_0_CH0_LPDDR4_0_CS_A;
  assign ch0_lpddr4_c0_cs_b = axi_noc_0_CH0_LPDDR4_0_CS_B;
  assign ch0_lpddr4_c0_reset_n = axi_noc_0_CH0_LPDDR4_0_RESET_N;
  assign ch0_lpddr4_c1_ca_a[5:0] = axi_noc_0_CH0_LPDDR4_1_CA_A;
  assign ch0_lpddr4_c1_ca_b[5:0] = axi_noc_0_CH0_LPDDR4_1_CA_B;
  assign ch0_lpddr4_c1_ck_c_a = axi_noc_0_CH0_LPDDR4_1_CK_C_A;
  assign ch0_lpddr4_c1_ck_c_b = axi_noc_0_CH0_LPDDR4_1_CK_C_B;
  assign ch0_lpddr4_c1_ck_t_a = axi_noc_0_CH0_LPDDR4_1_CK_T_A;
  assign ch0_lpddr4_c1_ck_t_b = axi_noc_0_CH0_LPDDR4_1_CK_T_B;
  assign ch0_lpddr4_c1_cke_a = axi_noc_0_CH0_LPDDR4_1_CKE_A;
  assign ch0_lpddr4_c1_cke_b = axi_noc_0_CH0_LPDDR4_1_CKE_B;
  assign ch0_lpddr4_c1_cs_a = axi_noc_0_CH0_LPDDR4_1_CS_A;
  assign ch0_lpddr4_c1_cs_b = axi_noc_0_CH0_LPDDR4_1_CS_B;
  assign ch0_lpddr4_c1_reset_n = axi_noc_0_CH0_LPDDR4_1_RESET_N;
  assign ch1_lpddr4_c0_ca_a[5:0] = axi_noc_0_CH1_LPDDR4_0_CA_A;
  assign ch1_lpddr4_c0_ca_b[5:0] = axi_noc_0_CH1_LPDDR4_0_CA_B;
  assign ch1_lpddr4_c0_ck_c_a = axi_noc_0_CH1_LPDDR4_0_CK_C_A;
  assign ch1_lpddr4_c0_ck_c_b = axi_noc_0_CH1_LPDDR4_0_CK_C_B;
  assign ch1_lpddr4_c0_ck_t_a = axi_noc_0_CH1_LPDDR4_0_CK_T_A;
  assign ch1_lpddr4_c0_ck_t_b = axi_noc_0_CH1_LPDDR4_0_CK_T_B;
  assign ch1_lpddr4_c0_cke_a = axi_noc_0_CH1_LPDDR4_0_CKE_A;
  assign ch1_lpddr4_c0_cke_b = axi_noc_0_CH1_LPDDR4_0_CKE_B;
  assign ch1_lpddr4_c0_cs_a = axi_noc_0_CH1_LPDDR4_0_CS_A;
  assign ch1_lpddr4_c0_cs_b = axi_noc_0_CH1_LPDDR4_0_CS_B;
  assign ch1_lpddr4_c0_reset_n = axi_noc_0_CH1_LPDDR4_0_RESET_N;
  assign ch1_lpddr4_c1_ca_a[5:0] = axi_noc_0_CH1_LPDDR4_1_CA_A;
  assign ch1_lpddr4_c1_ca_b[5:0] = axi_noc_0_CH1_LPDDR4_1_CA_B;
  assign ch1_lpddr4_c1_ck_c_a = axi_noc_0_CH1_LPDDR4_1_CK_C_A;
  assign ch1_lpddr4_c1_ck_c_b = axi_noc_0_CH1_LPDDR4_1_CK_C_B;
  assign ch1_lpddr4_c1_ck_t_a = axi_noc_0_CH1_LPDDR4_1_CK_T_A;
  assign ch1_lpddr4_c1_ck_t_b = axi_noc_0_CH1_LPDDR4_1_CK_T_B;
  assign ch1_lpddr4_c1_cke_a = axi_noc_0_CH1_LPDDR4_1_CKE_A;
  assign ch1_lpddr4_c1_cke_b = axi_noc_0_CH1_LPDDR4_1_CKE_B;
  assign ch1_lpddr4_c1_cs_a = axi_noc_0_CH1_LPDDR4_1_CS_A;
  assign ch1_lpddr4_c1_cs_b = axi_noc_0_CH1_LPDDR4_1_CS_B;
  assign ch1_lpddr4_c1_reset_n = axi_noc_0_CH1_LPDDR4_1_RESET_N;
  assign ddr4_dimm1_act_n = noc_ddr4_CH0_DDR4_0_ACT_N;
  assign ddr4_dimm1_adr[16:0] = noc_ddr4_CH0_DDR4_0_ADR;
  assign ddr4_dimm1_ba[1:0] = noc_ddr4_CH0_DDR4_0_BA;
  assign ddr4_dimm1_bg[1:0] = noc_ddr4_CH0_DDR4_0_BG;
  assign ddr4_dimm1_ck_c = noc_ddr4_CH0_DDR4_0_CK_C;
  assign ddr4_dimm1_ck_t = noc_ddr4_CH0_DDR4_0_CK_T;
  assign ddr4_dimm1_cke = noc_ddr4_CH0_DDR4_0_CKE;
  assign ddr4_dimm1_cs_n = noc_ddr4_CH0_DDR4_0_CS_N;
  assign ddr4_dimm1_odt = noc_ddr4_CH0_DDR4_0_ODT;
  assign ddr4_dimm1_reset_n = noc_ddr4_CH0_DDR4_0_RESET_N;
  assign ddr4_dimm1_sma_clk_1_CLK_N = ddr4_dimm1_sma_clk_clk_n;
  assign ddr4_dimm1_sma_clk_1_CLK_P = ddr4_dimm1_sma_clk_clk_p;
  assign lpddr4_sma_clk1_1_CLK_N = lpddr4_sma_clk1_clk_n;
  assign lpddr4_sma_clk1_1_CLK_P = lpddr4_sma_clk1_clk_p;
  assign lpddr4_sma_clk2_1_CLK_N = lpddr4_sma_clk2_clk_n;
  assign lpddr4_sma_clk2_1_CLK_P = lpddr4_sma_clk2_clk_p;
  vitis_design_CIPS_0_0 CIPS_0
       (.FPD_AXI_NOC_0_araddr(CIPS_0_IF_PS_NOC_NCI_0_ARADDR),
        .FPD_AXI_NOC_0_arburst(CIPS_0_IF_PS_NOC_NCI_0_ARBURST),
        .FPD_AXI_NOC_0_arcache(CIPS_0_IF_PS_NOC_NCI_0_ARCACHE),
        .FPD_AXI_NOC_0_arid(CIPS_0_IF_PS_NOC_NCI_0_ARID),
        .FPD_AXI_NOC_0_arlen(CIPS_0_IF_PS_NOC_NCI_0_ARLEN),
        .FPD_AXI_NOC_0_arlock(CIPS_0_IF_PS_NOC_NCI_0_ARLOCK),
        .FPD_AXI_NOC_0_arprot(CIPS_0_IF_PS_NOC_NCI_0_ARPROT),
        .FPD_AXI_NOC_0_arqos(CIPS_0_IF_PS_NOC_NCI_0_ARQOS),
        .FPD_AXI_NOC_0_arready(CIPS_0_IF_PS_NOC_NCI_0_ARREADY),
        .FPD_AXI_NOC_0_arsize(CIPS_0_IF_PS_NOC_NCI_0_ARSIZE),
        .FPD_AXI_NOC_0_aruser(CIPS_0_IF_PS_NOC_NCI_0_ARUSER),
        .FPD_AXI_NOC_0_arvalid(CIPS_0_IF_PS_NOC_NCI_0_ARVALID),
        .FPD_AXI_NOC_0_awaddr(CIPS_0_IF_PS_NOC_NCI_0_AWADDR),
        .FPD_AXI_NOC_0_awburst(CIPS_0_IF_PS_NOC_NCI_0_AWBURST),
        .FPD_AXI_NOC_0_awcache(CIPS_0_IF_PS_NOC_NCI_0_AWCACHE),
        .FPD_AXI_NOC_0_awid(CIPS_0_IF_PS_NOC_NCI_0_AWID),
        .FPD_AXI_NOC_0_awlen(CIPS_0_IF_PS_NOC_NCI_0_AWLEN),
        .FPD_AXI_NOC_0_awlock(CIPS_0_IF_PS_NOC_NCI_0_AWLOCK),
        .FPD_AXI_NOC_0_awprot(CIPS_0_IF_PS_NOC_NCI_0_AWPROT),
        .FPD_AXI_NOC_0_awqos(CIPS_0_IF_PS_NOC_NCI_0_AWQOS),
        .FPD_AXI_NOC_0_awready(CIPS_0_IF_PS_NOC_NCI_0_AWREADY),
        .FPD_AXI_NOC_0_awsize(CIPS_0_IF_PS_NOC_NCI_0_AWSIZE),
        .FPD_AXI_NOC_0_awuser(CIPS_0_IF_PS_NOC_NCI_0_AWUSER),
        .FPD_AXI_NOC_0_awvalid(CIPS_0_IF_PS_NOC_NCI_0_AWVALID),
        .FPD_AXI_NOC_0_bid(CIPS_0_IF_PS_NOC_NCI_0_BID),
        .FPD_AXI_NOC_0_bready(CIPS_0_IF_PS_NOC_NCI_0_BREADY),
        .FPD_AXI_NOC_0_bresp(CIPS_0_IF_PS_NOC_NCI_0_BRESP),
        .FPD_AXI_NOC_0_bvalid(CIPS_0_IF_PS_NOC_NCI_0_BVALID),
        .FPD_AXI_NOC_0_rdata(CIPS_0_IF_PS_NOC_NCI_0_RDATA),
        .FPD_AXI_NOC_0_rid(CIPS_0_IF_PS_NOC_NCI_0_RID),
        .FPD_AXI_NOC_0_rlast(CIPS_0_IF_PS_NOC_NCI_0_RLAST),
        .FPD_AXI_NOC_0_rready(CIPS_0_IF_PS_NOC_NCI_0_RREADY),
        .FPD_AXI_NOC_0_rresp(CIPS_0_IF_PS_NOC_NCI_0_RRESP),
        .FPD_AXI_NOC_0_rvalid(CIPS_0_IF_PS_NOC_NCI_0_RVALID),
        .FPD_AXI_NOC_0_wdata(CIPS_0_IF_PS_NOC_NCI_0_WDATA),
        .FPD_AXI_NOC_0_wlast(CIPS_0_IF_PS_NOC_NCI_0_WLAST),
        .FPD_AXI_NOC_0_wready(CIPS_0_IF_PS_NOC_NCI_0_WREADY),
        .FPD_AXI_NOC_0_wstrb(CIPS_0_IF_PS_NOC_NCI_0_WSTRB),
        .FPD_AXI_NOC_0_wvalid(CIPS_0_IF_PS_NOC_NCI_0_WVALID),
        .FPD_AXI_NOC_1_araddr(CIPS_0_IF_PS_NOC_NCI_1_ARADDR),
        .FPD_AXI_NOC_1_arburst(CIPS_0_IF_PS_NOC_NCI_1_ARBURST),
        .FPD_AXI_NOC_1_arcache(CIPS_0_IF_PS_NOC_NCI_1_ARCACHE),
        .FPD_AXI_NOC_1_arid(CIPS_0_IF_PS_NOC_NCI_1_ARID),
        .FPD_AXI_NOC_1_arlen(CIPS_0_IF_PS_NOC_NCI_1_ARLEN),
        .FPD_AXI_NOC_1_arlock(CIPS_0_IF_PS_NOC_NCI_1_ARLOCK),
        .FPD_AXI_NOC_1_arprot(CIPS_0_IF_PS_NOC_NCI_1_ARPROT),
        .FPD_AXI_NOC_1_arqos(CIPS_0_IF_PS_NOC_NCI_1_ARQOS),
        .FPD_AXI_NOC_1_arready(CIPS_0_IF_PS_NOC_NCI_1_ARREADY),
        .FPD_AXI_NOC_1_arsize(CIPS_0_IF_PS_NOC_NCI_1_ARSIZE),
        .FPD_AXI_NOC_1_aruser(CIPS_0_IF_PS_NOC_NCI_1_ARUSER),
        .FPD_AXI_NOC_1_arvalid(CIPS_0_IF_PS_NOC_NCI_1_ARVALID),
        .FPD_AXI_NOC_1_awaddr(CIPS_0_IF_PS_NOC_NCI_1_AWADDR),
        .FPD_AXI_NOC_1_awburst(CIPS_0_IF_PS_NOC_NCI_1_AWBURST),
        .FPD_AXI_NOC_1_awcache(CIPS_0_IF_PS_NOC_NCI_1_AWCACHE),
        .FPD_AXI_NOC_1_awid(CIPS_0_IF_PS_NOC_NCI_1_AWID),
        .FPD_AXI_NOC_1_awlen(CIPS_0_IF_PS_NOC_NCI_1_AWLEN),
        .FPD_AXI_NOC_1_awlock(CIPS_0_IF_PS_NOC_NCI_1_AWLOCK),
        .FPD_AXI_NOC_1_awprot(CIPS_0_IF_PS_NOC_NCI_1_AWPROT),
        .FPD_AXI_NOC_1_awqos(CIPS_0_IF_PS_NOC_NCI_1_AWQOS),
        .FPD_AXI_NOC_1_awready(CIPS_0_IF_PS_NOC_NCI_1_AWREADY),
        .FPD_AXI_NOC_1_awsize(CIPS_0_IF_PS_NOC_NCI_1_AWSIZE),
        .FPD_AXI_NOC_1_awuser(CIPS_0_IF_PS_NOC_NCI_1_AWUSER),
        .FPD_AXI_NOC_1_awvalid(CIPS_0_IF_PS_NOC_NCI_1_AWVALID),
        .FPD_AXI_NOC_1_bid(CIPS_0_IF_PS_NOC_NCI_1_BID),
        .FPD_AXI_NOC_1_bready(CIPS_0_IF_PS_NOC_NCI_1_BREADY),
        .FPD_AXI_NOC_1_bresp(CIPS_0_IF_PS_NOC_NCI_1_BRESP),
        .FPD_AXI_NOC_1_bvalid(CIPS_0_IF_PS_NOC_NCI_1_BVALID),
        .FPD_AXI_NOC_1_rdata(CIPS_0_IF_PS_NOC_NCI_1_RDATA),
        .FPD_AXI_NOC_1_rid(CIPS_0_IF_PS_NOC_NCI_1_RID),
        .FPD_AXI_NOC_1_rlast(CIPS_0_IF_PS_NOC_NCI_1_RLAST),
        .FPD_AXI_NOC_1_rready(CIPS_0_IF_PS_NOC_NCI_1_RREADY),
        .FPD_AXI_NOC_1_rresp(CIPS_0_IF_PS_NOC_NCI_1_RRESP),
        .FPD_AXI_NOC_1_rvalid(CIPS_0_IF_PS_NOC_NCI_1_RVALID),
        .FPD_AXI_NOC_1_wdata(CIPS_0_IF_PS_NOC_NCI_1_WDATA),
        .FPD_AXI_NOC_1_wlast(CIPS_0_IF_PS_NOC_NCI_1_WLAST),
        .FPD_AXI_NOC_1_wready(CIPS_0_IF_PS_NOC_NCI_1_WREADY),
        .FPD_AXI_NOC_1_wstrb(CIPS_0_IF_PS_NOC_NCI_1_WSTRB),
        .FPD_AXI_NOC_1_wvalid(CIPS_0_IF_PS_NOC_NCI_1_WVALID),
        .FPD_CCI_NOC_0_araddr(CIPS_0_IF_PS_NOC_CCI_0_ARADDR),
        .FPD_CCI_NOC_0_arburst(CIPS_0_IF_PS_NOC_CCI_0_ARBURST),
        .FPD_CCI_NOC_0_arcache(CIPS_0_IF_PS_NOC_CCI_0_ARCACHE),
        .FPD_CCI_NOC_0_arid(CIPS_0_IF_PS_NOC_CCI_0_ARID),
        .FPD_CCI_NOC_0_arlen(CIPS_0_IF_PS_NOC_CCI_0_ARLEN),
        .FPD_CCI_NOC_0_arlock(CIPS_0_IF_PS_NOC_CCI_0_ARLOCK),
        .FPD_CCI_NOC_0_arprot(CIPS_0_IF_PS_NOC_CCI_0_ARPROT),
        .FPD_CCI_NOC_0_arqos(CIPS_0_IF_PS_NOC_CCI_0_ARQOS),
        .FPD_CCI_NOC_0_arready(CIPS_0_IF_PS_NOC_CCI_0_ARREADY),
        .FPD_CCI_NOC_0_arsize(CIPS_0_IF_PS_NOC_CCI_0_ARSIZE),
        .FPD_CCI_NOC_0_aruser(CIPS_0_IF_PS_NOC_CCI_0_ARUSER),
        .FPD_CCI_NOC_0_arvalid(CIPS_0_IF_PS_NOC_CCI_0_ARVALID),
        .FPD_CCI_NOC_0_awaddr(CIPS_0_IF_PS_NOC_CCI_0_AWADDR),
        .FPD_CCI_NOC_0_awburst(CIPS_0_IF_PS_NOC_CCI_0_AWBURST),
        .FPD_CCI_NOC_0_awcache(CIPS_0_IF_PS_NOC_CCI_0_AWCACHE),
        .FPD_CCI_NOC_0_awid(CIPS_0_IF_PS_NOC_CCI_0_AWID),
        .FPD_CCI_NOC_0_awlen(CIPS_0_IF_PS_NOC_CCI_0_AWLEN),
        .FPD_CCI_NOC_0_awlock(CIPS_0_IF_PS_NOC_CCI_0_AWLOCK),
        .FPD_CCI_NOC_0_awprot(CIPS_0_IF_PS_NOC_CCI_0_AWPROT),
        .FPD_CCI_NOC_0_awqos(CIPS_0_IF_PS_NOC_CCI_0_AWQOS),
        .FPD_CCI_NOC_0_awready(CIPS_0_IF_PS_NOC_CCI_0_AWREADY),
        .FPD_CCI_NOC_0_awsize(CIPS_0_IF_PS_NOC_CCI_0_AWSIZE),
        .FPD_CCI_NOC_0_awuser(CIPS_0_IF_PS_NOC_CCI_0_AWUSER),
        .FPD_CCI_NOC_0_awvalid(CIPS_0_IF_PS_NOC_CCI_0_AWVALID),
        .FPD_CCI_NOC_0_bid(CIPS_0_IF_PS_NOC_CCI_0_BID),
        .FPD_CCI_NOC_0_bready(CIPS_0_IF_PS_NOC_CCI_0_BREADY),
        .FPD_CCI_NOC_0_bresp(CIPS_0_IF_PS_NOC_CCI_0_BRESP),
        .FPD_CCI_NOC_0_bvalid(CIPS_0_IF_PS_NOC_CCI_0_BVALID),
        .FPD_CCI_NOC_0_rdata(CIPS_0_IF_PS_NOC_CCI_0_RDATA),
        .FPD_CCI_NOC_0_rid(CIPS_0_IF_PS_NOC_CCI_0_RID),
        .FPD_CCI_NOC_0_rlast(CIPS_0_IF_PS_NOC_CCI_0_RLAST),
        .FPD_CCI_NOC_0_rready(CIPS_0_IF_PS_NOC_CCI_0_RREADY),
        .FPD_CCI_NOC_0_rresp(CIPS_0_IF_PS_NOC_CCI_0_RRESP),
        .FPD_CCI_NOC_0_rvalid(CIPS_0_IF_PS_NOC_CCI_0_RVALID),
        .FPD_CCI_NOC_0_wdata(CIPS_0_IF_PS_NOC_CCI_0_WDATA),
        .FPD_CCI_NOC_0_wlast(CIPS_0_IF_PS_NOC_CCI_0_WLAST),
        .FPD_CCI_NOC_0_wready(CIPS_0_IF_PS_NOC_CCI_0_WREADY),
        .FPD_CCI_NOC_0_wstrb(CIPS_0_IF_PS_NOC_CCI_0_WSTRB),
        .FPD_CCI_NOC_0_wuser(CIPS_0_IF_PS_NOC_CCI_0_WUSER),
        .FPD_CCI_NOC_0_wvalid(CIPS_0_IF_PS_NOC_CCI_0_WVALID),
        .FPD_CCI_NOC_1_araddr(CIPS_0_IF_PS_NOC_CCI_1_ARADDR),
        .FPD_CCI_NOC_1_arburst(CIPS_0_IF_PS_NOC_CCI_1_ARBURST),
        .FPD_CCI_NOC_1_arcache(CIPS_0_IF_PS_NOC_CCI_1_ARCACHE),
        .FPD_CCI_NOC_1_arid(CIPS_0_IF_PS_NOC_CCI_1_ARID),
        .FPD_CCI_NOC_1_arlen(CIPS_0_IF_PS_NOC_CCI_1_ARLEN),
        .FPD_CCI_NOC_1_arlock(CIPS_0_IF_PS_NOC_CCI_1_ARLOCK),
        .FPD_CCI_NOC_1_arprot(CIPS_0_IF_PS_NOC_CCI_1_ARPROT),
        .FPD_CCI_NOC_1_arqos(CIPS_0_IF_PS_NOC_CCI_1_ARQOS),
        .FPD_CCI_NOC_1_arready(CIPS_0_IF_PS_NOC_CCI_1_ARREADY),
        .FPD_CCI_NOC_1_arsize(CIPS_0_IF_PS_NOC_CCI_1_ARSIZE),
        .FPD_CCI_NOC_1_aruser(CIPS_0_IF_PS_NOC_CCI_1_ARUSER),
        .FPD_CCI_NOC_1_arvalid(CIPS_0_IF_PS_NOC_CCI_1_ARVALID),
        .FPD_CCI_NOC_1_awaddr(CIPS_0_IF_PS_NOC_CCI_1_AWADDR),
        .FPD_CCI_NOC_1_awburst(CIPS_0_IF_PS_NOC_CCI_1_AWBURST),
        .FPD_CCI_NOC_1_awcache(CIPS_0_IF_PS_NOC_CCI_1_AWCACHE),
        .FPD_CCI_NOC_1_awid(CIPS_0_IF_PS_NOC_CCI_1_AWID),
        .FPD_CCI_NOC_1_awlen(CIPS_0_IF_PS_NOC_CCI_1_AWLEN),
        .FPD_CCI_NOC_1_awlock(CIPS_0_IF_PS_NOC_CCI_1_AWLOCK),
        .FPD_CCI_NOC_1_awprot(CIPS_0_IF_PS_NOC_CCI_1_AWPROT),
        .FPD_CCI_NOC_1_awqos(CIPS_0_IF_PS_NOC_CCI_1_AWQOS),
        .FPD_CCI_NOC_1_awready(CIPS_0_IF_PS_NOC_CCI_1_AWREADY),
        .FPD_CCI_NOC_1_awsize(CIPS_0_IF_PS_NOC_CCI_1_AWSIZE),
        .FPD_CCI_NOC_1_awuser(CIPS_0_IF_PS_NOC_CCI_1_AWUSER),
        .FPD_CCI_NOC_1_awvalid(CIPS_0_IF_PS_NOC_CCI_1_AWVALID),
        .FPD_CCI_NOC_1_bid(CIPS_0_IF_PS_NOC_CCI_1_BID),
        .FPD_CCI_NOC_1_bready(CIPS_0_IF_PS_NOC_CCI_1_BREADY),
        .FPD_CCI_NOC_1_bresp(CIPS_0_IF_PS_NOC_CCI_1_BRESP),
        .FPD_CCI_NOC_1_bvalid(CIPS_0_IF_PS_NOC_CCI_1_BVALID),
        .FPD_CCI_NOC_1_rdata(CIPS_0_IF_PS_NOC_CCI_1_RDATA),
        .FPD_CCI_NOC_1_rid(CIPS_0_IF_PS_NOC_CCI_1_RID),
        .FPD_CCI_NOC_1_rlast(CIPS_0_IF_PS_NOC_CCI_1_RLAST),
        .FPD_CCI_NOC_1_rready(CIPS_0_IF_PS_NOC_CCI_1_RREADY),
        .FPD_CCI_NOC_1_rresp(CIPS_0_IF_PS_NOC_CCI_1_RRESP),
        .FPD_CCI_NOC_1_rvalid(CIPS_0_IF_PS_NOC_CCI_1_RVALID),
        .FPD_CCI_NOC_1_wdata(CIPS_0_IF_PS_NOC_CCI_1_WDATA),
        .FPD_CCI_NOC_1_wlast(CIPS_0_IF_PS_NOC_CCI_1_WLAST),
        .FPD_CCI_NOC_1_wready(CIPS_0_IF_PS_NOC_CCI_1_WREADY),
        .FPD_CCI_NOC_1_wstrb(CIPS_0_IF_PS_NOC_CCI_1_WSTRB),
        .FPD_CCI_NOC_1_wuser(CIPS_0_IF_PS_NOC_CCI_1_WUSER),
        .FPD_CCI_NOC_1_wvalid(CIPS_0_IF_PS_NOC_CCI_1_WVALID),
        .FPD_CCI_NOC_2_araddr(CIPS_0_IF_PS_NOC_CCI_2_ARADDR),
        .FPD_CCI_NOC_2_arburst(CIPS_0_IF_PS_NOC_CCI_2_ARBURST),
        .FPD_CCI_NOC_2_arcache(CIPS_0_IF_PS_NOC_CCI_2_ARCACHE),
        .FPD_CCI_NOC_2_arid(CIPS_0_IF_PS_NOC_CCI_2_ARID),
        .FPD_CCI_NOC_2_arlen(CIPS_0_IF_PS_NOC_CCI_2_ARLEN),
        .FPD_CCI_NOC_2_arlock(CIPS_0_IF_PS_NOC_CCI_2_ARLOCK),
        .FPD_CCI_NOC_2_arprot(CIPS_0_IF_PS_NOC_CCI_2_ARPROT),
        .FPD_CCI_NOC_2_arqos(CIPS_0_IF_PS_NOC_CCI_2_ARQOS),
        .FPD_CCI_NOC_2_arready(CIPS_0_IF_PS_NOC_CCI_2_ARREADY),
        .FPD_CCI_NOC_2_arsize(CIPS_0_IF_PS_NOC_CCI_2_ARSIZE),
        .FPD_CCI_NOC_2_aruser(CIPS_0_IF_PS_NOC_CCI_2_ARUSER),
        .FPD_CCI_NOC_2_arvalid(CIPS_0_IF_PS_NOC_CCI_2_ARVALID),
        .FPD_CCI_NOC_2_awaddr(CIPS_0_IF_PS_NOC_CCI_2_AWADDR),
        .FPD_CCI_NOC_2_awburst(CIPS_0_IF_PS_NOC_CCI_2_AWBURST),
        .FPD_CCI_NOC_2_awcache(CIPS_0_IF_PS_NOC_CCI_2_AWCACHE),
        .FPD_CCI_NOC_2_awid(CIPS_0_IF_PS_NOC_CCI_2_AWID),
        .FPD_CCI_NOC_2_awlen(CIPS_0_IF_PS_NOC_CCI_2_AWLEN),
        .FPD_CCI_NOC_2_awlock(CIPS_0_IF_PS_NOC_CCI_2_AWLOCK),
        .FPD_CCI_NOC_2_awprot(CIPS_0_IF_PS_NOC_CCI_2_AWPROT),
        .FPD_CCI_NOC_2_awqos(CIPS_0_IF_PS_NOC_CCI_2_AWQOS),
        .FPD_CCI_NOC_2_awready(CIPS_0_IF_PS_NOC_CCI_2_AWREADY),
        .FPD_CCI_NOC_2_awsize(CIPS_0_IF_PS_NOC_CCI_2_AWSIZE),
        .FPD_CCI_NOC_2_awuser(CIPS_0_IF_PS_NOC_CCI_2_AWUSER),
        .FPD_CCI_NOC_2_awvalid(CIPS_0_IF_PS_NOC_CCI_2_AWVALID),
        .FPD_CCI_NOC_2_bid(CIPS_0_IF_PS_NOC_CCI_2_BID),
        .FPD_CCI_NOC_2_bready(CIPS_0_IF_PS_NOC_CCI_2_BREADY),
        .FPD_CCI_NOC_2_bresp(CIPS_0_IF_PS_NOC_CCI_2_BRESP),
        .FPD_CCI_NOC_2_bvalid(CIPS_0_IF_PS_NOC_CCI_2_BVALID),
        .FPD_CCI_NOC_2_rdata(CIPS_0_IF_PS_NOC_CCI_2_RDATA),
        .FPD_CCI_NOC_2_rid(CIPS_0_IF_PS_NOC_CCI_2_RID),
        .FPD_CCI_NOC_2_rlast(CIPS_0_IF_PS_NOC_CCI_2_RLAST),
        .FPD_CCI_NOC_2_rready(CIPS_0_IF_PS_NOC_CCI_2_RREADY),
        .FPD_CCI_NOC_2_rresp(CIPS_0_IF_PS_NOC_CCI_2_RRESP),
        .FPD_CCI_NOC_2_rvalid(CIPS_0_IF_PS_NOC_CCI_2_RVALID),
        .FPD_CCI_NOC_2_wdata(CIPS_0_IF_PS_NOC_CCI_2_WDATA),
        .FPD_CCI_NOC_2_wlast(CIPS_0_IF_PS_NOC_CCI_2_WLAST),
        .FPD_CCI_NOC_2_wready(CIPS_0_IF_PS_NOC_CCI_2_WREADY),
        .FPD_CCI_NOC_2_wstrb(CIPS_0_IF_PS_NOC_CCI_2_WSTRB),
        .FPD_CCI_NOC_2_wuser(CIPS_0_IF_PS_NOC_CCI_2_WUSER),
        .FPD_CCI_NOC_2_wvalid(CIPS_0_IF_PS_NOC_CCI_2_WVALID),
        .FPD_CCI_NOC_3_araddr(CIPS_0_IF_PS_NOC_CCI_3_ARADDR),
        .FPD_CCI_NOC_3_arburst(CIPS_0_IF_PS_NOC_CCI_3_ARBURST),
        .FPD_CCI_NOC_3_arcache(CIPS_0_IF_PS_NOC_CCI_3_ARCACHE),
        .FPD_CCI_NOC_3_arid(CIPS_0_IF_PS_NOC_CCI_3_ARID),
        .FPD_CCI_NOC_3_arlen(CIPS_0_IF_PS_NOC_CCI_3_ARLEN),
        .FPD_CCI_NOC_3_arlock(CIPS_0_IF_PS_NOC_CCI_3_ARLOCK),
        .FPD_CCI_NOC_3_arprot(CIPS_0_IF_PS_NOC_CCI_3_ARPROT),
        .FPD_CCI_NOC_3_arqos(CIPS_0_IF_PS_NOC_CCI_3_ARQOS),
        .FPD_CCI_NOC_3_arready(CIPS_0_IF_PS_NOC_CCI_3_ARREADY),
        .FPD_CCI_NOC_3_arsize(CIPS_0_IF_PS_NOC_CCI_3_ARSIZE),
        .FPD_CCI_NOC_3_aruser(CIPS_0_IF_PS_NOC_CCI_3_ARUSER),
        .FPD_CCI_NOC_3_arvalid(CIPS_0_IF_PS_NOC_CCI_3_ARVALID),
        .FPD_CCI_NOC_3_awaddr(CIPS_0_IF_PS_NOC_CCI_3_AWADDR),
        .FPD_CCI_NOC_3_awburst(CIPS_0_IF_PS_NOC_CCI_3_AWBURST),
        .FPD_CCI_NOC_3_awcache(CIPS_0_IF_PS_NOC_CCI_3_AWCACHE),
        .FPD_CCI_NOC_3_awid(CIPS_0_IF_PS_NOC_CCI_3_AWID),
        .FPD_CCI_NOC_3_awlen(CIPS_0_IF_PS_NOC_CCI_3_AWLEN),
        .FPD_CCI_NOC_3_awlock(CIPS_0_IF_PS_NOC_CCI_3_AWLOCK),
        .FPD_CCI_NOC_3_awprot(CIPS_0_IF_PS_NOC_CCI_3_AWPROT),
        .FPD_CCI_NOC_3_awqos(CIPS_0_IF_PS_NOC_CCI_3_AWQOS),
        .FPD_CCI_NOC_3_awready(CIPS_0_IF_PS_NOC_CCI_3_AWREADY),
        .FPD_CCI_NOC_3_awsize(CIPS_0_IF_PS_NOC_CCI_3_AWSIZE),
        .FPD_CCI_NOC_3_awuser(CIPS_0_IF_PS_NOC_CCI_3_AWUSER),
        .FPD_CCI_NOC_3_awvalid(CIPS_0_IF_PS_NOC_CCI_3_AWVALID),
        .FPD_CCI_NOC_3_bid(CIPS_0_IF_PS_NOC_CCI_3_BID),
        .FPD_CCI_NOC_3_bready(CIPS_0_IF_PS_NOC_CCI_3_BREADY),
        .FPD_CCI_NOC_3_bresp(CIPS_0_IF_PS_NOC_CCI_3_BRESP),
        .FPD_CCI_NOC_3_bvalid(CIPS_0_IF_PS_NOC_CCI_3_BVALID),
        .FPD_CCI_NOC_3_rdata(CIPS_0_IF_PS_NOC_CCI_3_RDATA),
        .FPD_CCI_NOC_3_rid(CIPS_0_IF_PS_NOC_CCI_3_RID),
        .FPD_CCI_NOC_3_rlast(CIPS_0_IF_PS_NOC_CCI_3_RLAST),
        .FPD_CCI_NOC_3_rready(CIPS_0_IF_PS_NOC_CCI_3_RREADY),
        .FPD_CCI_NOC_3_rresp(CIPS_0_IF_PS_NOC_CCI_3_RRESP),
        .FPD_CCI_NOC_3_rvalid(CIPS_0_IF_PS_NOC_CCI_3_RVALID),
        .FPD_CCI_NOC_3_wdata(CIPS_0_IF_PS_NOC_CCI_3_WDATA),
        .FPD_CCI_NOC_3_wlast(CIPS_0_IF_PS_NOC_CCI_3_WLAST),
        .FPD_CCI_NOC_3_wready(CIPS_0_IF_PS_NOC_CCI_3_WREADY),
        .FPD_CCI_NOC_3_wstrb(CIPS_0_IF_PS_NOC_CCI_3_WSTRB),
        .FPD_CCI_NOC_3_wuser(CIPS_0_IF_PS_NOC_CCI_3_WUSER),
        .FPD_CCI_NOC_3_wvalid(CIPS_0_IF_PS_NOC_CCI_3_WVALID),
        .LPD_AXI_NOC_0_araddr(CIPS_0_IF_PS_NOC_RPU_0_ARADDR),
        .LPD_AXI_NOC_0_arburst(CIPS_0_IF_PS_NOC_RPU_0_ARBURST),
        .LPD_AXI_NOC_0_arcache(CIPS_0_IF_PS_NOC_RPU_0_ARCACHE),
        .LPD_AXI_NOC_0_arid(CIPS_0_IF_PS_NOC_RPU_0_ARID),
        .LPD_AXI_NOC_0_arlen(CIPS_0_IF_PS_NOC_RPU_0_ARLEN),
        .LPD_AXI_NOC_0_arlock(CIPS_0_IF_PS_NOC_RPU_0_ARLOCK),
        .LPD_AXI_NOC_0_arprot(CIPS_0_IF_PS_NOC_RPU_0_ARPROT),
        .LPD_AXI_NOC_0_arqos(CIPS_0_IF_PS_NOC_RPU_0_ARQOS),
        .LPD_AXI_NOC_0_arready(CIPS_0_IF_PS_NOC_RPU_0_ARREADY),
        .LPD_AXI_NOC_0_arsize(CIPS_0_IF_PS_NOC_RPU_0_ARSIZE),
        .LPD_AXI_NOC_0_aruser(CIPS_0_IF_PS_NOC_RPU_0_ARUSER),
        .LPD_AXI_NOC_0_arvalid(CIPS_0_IF_PS_NOC_RPU_0_ARVALID),
        .LPD_AXI_NOC_0_awaddr(CIPS_0_IF_PS_NOC_RPU_0_AWADDR),
        .LPD_AXI_NOC_0_awburst(CIPS_0_IF_PS_NOC_RPU_0_AWBURST),
        .LPD_AXI_NOC_0_awcache(CIPS_0_IF_PS_NOC_RPU_0_AWCACHE),
        .LPD_AXI_NOC_0_awid(CIPS_0_IF_PS_NOC_RPU_0_AWID),
        .LPD_AXI_NOC_0_awlen(CIPS_0_IF_PS_NOC_RPU_0_AWLEN),
        .LPD_AXI_NOC_0_awlock(CIPS_0_IF_PS_NOC_RPU_0_AWLOCK),
        .LPD_AXI_NOC_0_awprot(CIPS_0_IF_PS_NOC_RPU_0_AWPROT),
        .LPD_AXI_NOC_0_awqos(CIPS_0_IF_PS_NOC_RPU_0_AWQOS),
        .LPD_AXI_NOC_0_awready(CIPS_0_IF_PS_NOC_RPU_0_AWREADY),
        .LPD_AXI_NOC_0_awsize(CIPS_0_IF_PS_NOC_RPU_0_AWSIZE),
        .LPD_AXI_NOC_0_awuser(CIPS_0_IF_PS_NOC_RPU_0_AWUSER),
        .LPD_AXI_NOC_0_awvalid(CIPS_0_IF_PS_NOC_RPU_0_AWVALID),
        .LPD_AXI_NOC_0_bid(CIPS_0_IF_PS_NOC_RPU_0_BID),
        .LPD_AXI_NOC_0_bready(CIPS_0_IF_PS_NOC_RPU_0_BREADY),
        .LPD_AXI_NOC_0_bresp(CIPS_0_IF_PS_NOC_RPU_0_BRESP),
        .LPD_AXI_NOC_0_bvalid(CIPS_0_IF_PS_NOC_RPU_0_BVALID),
        .LPD_AXI_NOC_0_rdata(CIPS_0_IF_PS_NOC_RPU_0_RDATA),
        .LPD_AXI_NOC_0_rid(CIPS_0_IF_PS_NOC_RPU_0_RID),
        .LPD_AXI_NOC_0_rlast(CIPS_0_IF_PS_NOC_RPU_0_RLAST),
        .LPD_AXI_NOC_0_rready(CIPS_0_IF_PS_NOC_RPU_0_RREADY),
        .LPD_AXI_NOC_0_rresp(CIPS_0_IF_PS_NOC_RPU_0_RRESP),
        .LPD_AXI_NOC_0_rvalid(CIPS_0_IF_PS_NOC_RPU_0_RVALID),
        .LPD_AXI_NOC_0_wdata(CIPS_0_IF_PS_NOC_RPU_0_WDATA),
        .LPD_AXI_NOC_0_wlast(CIPS_0_IF_PS_NOC_RPU_0_WLAST),
        .LPD_AXI_NOC_0_wready(CIPS_0_IF_PS_NOC_RPU_0_WREADY),
        .LPD_AXI_NOC_0_wstrb(CIPS_0_IF_PS_NOC_RPU_0_WSTRB),
        .LPD_AXI_NOC_0_wvalid(CIPS_0_IF_PS_NOC_RPU_0_WVALID),
        .M_AXI_FPD_araddr(CIPS_0_M_AXI_GP0_ARADDR),
        .M_AXI_FPD_arburst(CIPS_0_M_AXI_GP0_ARBURST),
        .M_AXI_FPD_arcache(CIPS_0_M_AXI_GP0_ARCACHE),
        .M_AXI_FPD_arid(CIPS_0_M_AXI_GP0_ARID),
        .M_AXI_FPD_arlen(CIPS_0_M_AXI_GP0_ARLEN),
        .M_AXI_FPD_arlock(CIPS_0_M_AXI_GP0_ARLOCK),
        .M_AXI_FPD_arprot(CIPS_0_M_AXI_GP0_ARPROT),
        .M_AXI_FPD_arqos(CIPS_0_M_AXI_GP0_ARQOS),
        .M_AXI_FPD_arready(CIPS_0_M_AXI_GP0_ARREADY),
        .M_AXI_FPD_arsize(CIPS_0_M_AXI_GP0_ARSIZE),
        .M_AXI_FPD_aruser(CIPS_0_M_AXI_GP0_ARUSER),
        .M_AXI_FPD_arvalid(CIPS_0_M_AXI_GP0_ARVALID),
        .M_AXI_FPD_awaddr(CIPS_0_M_AXI_GP0_AWADDR),
        .M_AXI_FPD_awburst(CIPS_0_M_AXI_GP0_AWBURST),
        .M_AXI_FPD_awcache(CIPS_0_M_AXI_GP0_AWCACHE),
        .M_AXI_FPD_awid(CIPS_0_M_AXI_GP0_AWID),
        .M_AXI_FPD_awlen(CIPS_0_M_AXI_GP0_AWLEN),
        .M_AXI_FPD_awlock(CIPS_0_M_AXI_GP0_AWLOCK),
        .M_AXI_FPD_awprot(CIPS_0_M_AXI_GP0_AWPROT),
        .M_AXI_FPD_awqos(CIPS_0_M_AXI_GP0_AWQOS),
        .M_AXI_FPD_awready(CIPS_0_M_AXI_GP0_AWREADY),
        .M_AXI_FPD_awsize(CIPS_0_M_AXI_GP0_AWSIZE),
        .M_AXI_FPD_awuser(CIPS_0_M_AXI_GP0_AWUSER),
        .M_AXI_FPD_awvalid(CIPS_0_M_AXI_GP0_AWVALID),
        .M_AXI_FPD_bid(CIPS_0_M_AXI_GP0_BID),
        .M_AXI_FPD_bready(CIPS_0_M_AXI_GP0_BREADY),
        .M_AXI_FPD_bresp(CIPS_0_M_AXI_GP0_BRESP),
        .M_AXI_FPD_bvalid(CIPS_0_M_AXI_GP0_BVALID),
        .M_AXI_FPD_rdata(CIPS_0_M_AXI_GP0_RDATA),
        .M_AXI_FPD_rid(CIPS_0_M_AXI_GP0_RID),
        .M_AXI_FPD_rlast(CIPS_0_M_AXI_GP0_RLAST),
        .M_AXI_FPD_rready(CIPS_0_M_AXI_GP0_RREADY),
        .M_AXI_FPD_rresp(CIPS_0_M_AXI_GP0_RRESP),
        .M_AXI_FPD_rvalid(CIPS_0_M_AXI_GP0_RVALID),
        .M_AXI_FPD_wdata(CIPS_0_M_AXI_GP0_WDATA),
        .M_AXI_FPD_wlast(CIPS_0_M_AXI_GP0_WLAST),
        .M_AXI_FPD_wready(CIPS_0_M_AXI_GP0_WREADY),
        .M_AXI_FPD_wstrb(CIPS_0_M_AXI_GP0_WSTRB),
        .M_AXI_FPD_wvalid(CIPS_0_M_AXI_GP0_WVALID),
        .PMC_NOC_AXI_0_araddr(CIPS_0_IF_PMC_NOC_AXI_0_ARADDR),
        .PMC_NOC_AXI_0_arburst(CIPS_0_IF_PMC_NOC_AXI_0_ARBURST),
        .PMC_NOC_AXI_0_arcache(CIPS_0_IF_PMC_NOC_AXI_0_ARCACHE),
        .PMC_NOC_AXI_0_arid(CIPS_0_IF_PMC_NOC_AXI_0_ARID),
        .PMC_NOC_AXI_0_arlen(CIPS_0_IF_PMC_NOC_AXI_0_ARLEN),
        .PMC_NOC_AXI_0_arlock(CIPS_0_IF_PMC_NOC_AXI_0_ARLOCK),
        .PMC_NOC_AXI_0_arprot(CIPS_0_IF_PMC_NOC_AXI_0_ARPROT),
        .PMC_NOC_AXI_0_arqos(CIPS_0_IF_PMC_NOC_AXI_0_ARQOS),
        .PMC_NOC_AXI_0_arready(CIPS_0_IF_PMC_NOC_AXI_0_ARREADY),
        .PMC_NOC_AXI_0_arregion(CIPS_0_IF_PMC_NOC_AXI_0_ARREGION),
        .PMC_NOC_AXI_0_arsize(CIPS_0_IF_PMC_NOC_AXI_0_ARSIZE),
        .PMC_NOC_AXI_0_aruser(CIPS_0_IF_PMC_NOC_AXI_0_ARUSER),
        .PMC_NOC_AXI_0_arvalid(CIPS_0_IF_PMC_NOC_AXI_0_ARVALID),
        .PMC_NOC_AXI_0_awaddr(CIPS_0_IF_PMC_NOC_AXI_0_AWADDR),
        .PMC_NOC_AXI_0_awburst(CIPS_0_IF_PMC_NOC_AXI_0_AWBURST),
        .PMC_NOC_AXI_0_awcache(CIPS_0_IF_PMC_NOC_AXI_0_AWCACHE),
        .PMC_NOC_AXI_0_awid(CIPS_0_IF_PMC_NOC_AXI_0_AWID),
        .PMC_NOC_AXI_0_awlen(CIPS_0_IF_PMC_NOC_AXI_0_AWLEN),
        .PMC_NOC_AXI_0_awlock(CIPS_0_IF_PMC_NOC_AXI_0_AWLOCK),
        .PMC_NOC_AXI_0_awprot(CIPS_0_IF_PMC_NOC_AXI_0_AWPROT),
        .PMC_NOC_AXI_0_awqos(CIPS_0_IF_PMC_NOC_AXI_0_AWQOS),
        .PMC_NOC_AXI_0_awready(CIPS_0_IF_PMC_NOC_AXI_0_AWREADY),
        .PMC_NOC_AXI_0_awregion(CIPS_0_IF_PMC_NOC_AXI_0_AWREGION),
        .PMC_NOC_AXI_0_awsize(CIPS_0_IF_PMC_NOC_AXI_0_AWSIZE),
        .PMC_NOC_AXI_0_awuser(CIPS_0_IF_PMC_NOC_AXI_0_AWUSER),
        .PMC_NOC_AXI_0_awvalid(CIPS_0_IF_PMC_NOC_AXI_0_AWVALID),
        .PMC_NOC_AXI_0_bid(CIPS_0_IF_PMC_NOC_AXI_0_BID),
        .PMC_NOC_AXI_0_bready(CIPS_0_IF_PMC_NOC_AXI_0_BREADY),
        .PMC_NOC_AXI_0_bresp(CIPS_0_IF_PMC_NOC_AXI_0_BRESP),
        .PMC_NOC_AXI_0_buser(CIPS_0_IF_PMC_NOC_AXI_0_BUSER),
        .PMC_NOC_AXI_0_bvalid(CIPS_0_IF_PMC_NOC_AXI_0_BVALID),
        .PMC_NOC_AXI_0_rdata(CIPS_0_IF_PMC_NOC_AXI_0_RDATA),
        .PMC_NOC_AXI_0_rid(CIPS_0_IF_PMC_NOC_AXI_0_RID),
        .PMC_NOC_AXI_0_rlast(CIPS_0_IF_PMC_NOC_AXI_0_RLAST),
        .PMC_NOC_AXI_0_rready(CIPS_0_IF_PMC_NOC_AXI_0_RREADY),
        .PMC_NOC_AXI_0_rresp(CIPS_0_IF_PMC_NOC_AXI_0_RRESP),
        .PMC_NOC_AXI_0_ruser(CIPS_0_IF_PMC_NOC_AXI_0_RUSER),
        .PMC_NOC_AXI_0_rvalid(CIPS_0_IF_PMC_NOC_AXI_0_RVALID),
        .PMC_NOC_AXI_0_wdata(CIPS_0_IF_PMC_NOC_AXI_0_WDATA),
        .PMC_NOC_AXI_0_wlast(CIPS_0_IF_PMC_NOC_AXI_0_WLAST),
        .PMC_NOC_AXI_0_wready(CIPS_0_IF_PMC_NOC_AXI_0_WREADY),
        .PMC_NOC_AXI_0_wstrb(CIPS_0_IF_PMC_NOC_AXI_0_WSTRB),
        .PMC_NOC_AXI_0_wuser(CIPS_0_IF_PMC_NOC_AXI_0_WUSER),
        .PMC_NOC_AXI_0_wvalid(CIPS_0_IF_PMC_NOC_AXI_0_WVALID),
        .fpd_axi_noc_axi0_clk(CIPS_0_ps_ps_noc_nci_axi0_clk),
        .fpd_axi_noc_axi1_clk(CIPS_0_ps_ps_noc_nci_axi1_clk),
        .fpd_cci_noc_axi0_clk(CIPS_0_ps_ps_noc_cci_axi0_clk),
        .fpd_cci_noc_axi1_clk(CIPS_0_ps_ps_noc_cci_axi1_clk),
        .fpd_cci_noc_axi2_clk(CIPS_0_ps_ps_noc_cci_axi2_clk),
        .fpd_cci_noc_axi3_clk(CIPS_0_ps_ps_noc_cci_axi3_clk),
        .lpd_axi_noc_clk(CIPS_0_ps_ps_noc_rpu_axi0_clk),
        .m_axi_fpd_aclk(clk_wizard_0_clk_out1),
        .pl0_ref_clk(CIPS_0_pl_clk0),
        .pl0_resetn(CIPS_0_pl_resetn1),
        .pl_ps_irq0(axi_intc_3_irq),
        .pmc_axi_noc_axi0_clk(CIPS_0_ps_pmc_noc_axi0_clk));
  VitisRegion_imp_9ASBXH VitisRegion
       (.M_AXIS1_tdata(dwc_mm2s_2_s_M_AXIS_TDATA),
        .M_AXIS1_tkeep(dwc_mm2s_2_s_M_AXIS_TKEEP),
        .M_AXIS1_tlast(dwc_mm2s_2_s_M_AXIS_TLAST),
        .M_AXIS1_tready(dwc_mm2s_2_s_M_AXIS_TREADY),
        .M_AXIS1_tvalid(dwc_mm2s_2_s_M_AXIS_TVALID),
        .M_AXIS_tdata(dwc_mm2s_1_s_M_AXIS_TDATA),
        .M_AXIS_tkeep(dwc_mm2s_1_s_M_AXIS_TKEEP),
        .M_AXIS_tlast(dwc_mm2s_1_s_M_AXIS_TLAST),
        .M_AXIS_tready(dwc_mm2s_1_s_M_AXIS_TREADY),
        .M_AXIS_tvalid(dwc_mm2s_1_s_M_AXIS_TVALID),
        .S00_AXI_araddr(icn_ctrl_1_M09_AXI_ARADDR),
        .S00_AXI_arburst(icn_ctrl_1_M09_AXI_ARBURST),
        .S00_AXI_arcache(icn_ctrl_1_M09_AXI_ARCACHE),
        .S00_AXI_arid(icn_ctrl_1_M09_AXI_ARID),
        .S00_AXI_arlen(icn_ctrl_1_M09_AXI_ARLEN),
        .S00_AXI_arlock(icn_ctrl_1_M09_AXI_ARLOCK),
        .S00_AXI_arprot(icn_ctrl_1_M09_AXI_ARPROT),
        .S00_AXI_arqos(icn_ctrl_1_M09_AXI_ARQOS),
        .S00_AXI_arready(icn_ctrl_1_M09_AXI_ARREADY),
        .S00_AXI_arsize(icn_ctrl_1_M09_AXI_ARSIZE),
        .S00_AXI_aruser(icn_ctrl_1_M09_AXI_ARUSER),
        .S00_AXI_arvalid(icn_ctrl_1_M09_AXI_ARVALID),
        .S00_AXI_awaddr(icn_ctrl_1_M09_AXI_AWADDR),
        .S00_AXI_awburst(icn_ctrl_1_M09_AXI_AWBURST),
        .S00_AXI_awcache(icn_ctrl_1_M09_AXI_AWCACHE),
        .S00_AXI_awid(icn_ctrl_1_M09_AXI_AWID),
        .S00_AXI_awlen(icn_ctrl_1_M09_AXI_AWLEN),
        .S00_AXI_awlock(icn_ctrl_1_M09_AXI_AWLOCK),
        .S00_AXI_awprot(icn_ctrl_1_M09_AXI_AWPROT),
        .S00_AXI_awqos(icn_ctrl_1_M09_AXI_AWQOS),
        .S00_AXI_awready(icn_ctrl_1_M09_AXI_AWREADY),
        .S00_AXI_awsize(icn_ctrl_1_M09_AXI_AWSIZE),
        .S00_AXI_awuser(icn_ctrl_1_M09_AXI_AWUSER),
        .S00_AXI_awvalid(icn_ctrl_1_M09_AXI_AWVALID),
        .S00_AXI_bid(icn_ctrl_1_M09_AXI_BID),
        .S00_AXI_bready(icn_ctrl_1_M09_AXI_BREADY),
        .S00_AXI_bresp(icn_ctrl_1_M09_AXI_BRESP),
        .S00_AXI_bvalid(icn_ctrl_1_M09_AXI_BVALID),
        .S00_AXI_rdata(icn_ctrl_1_M09_AXI_RDATA),
        .S00_AXI_rid(icn_ctrl_1_M09_AXI_RID),
        .S00_AXI_rlast(icn_ctrl_1_M09_AXI_RLAST),
        .S00_AXI_rready(icn_ctrl_1_M09_AXI_RREADY),
        .S00_AXI_rresp(icn_ctrl_1_M09_AXI_RRESP),
        .S00_AXI_ruser(icn_ctrl_1_M09_AXI_RUSER),
        .S00_AXI_rvalid(icn_ctrl_1_M09_AXI_RVALID),
        .S00_AXI_wdata(icn_ctrl_1_M09_AXI_WDATA),
        .S00_AXI_wlast(icn_ctrl_1_M09_AXI_WLAST),
        .S00_AXI_wready(icn_ctrl_1_M09_AXI_WREADY),
        .S00_AXI_wstrb(icn_ctrl_1_M09_AXI_WSTRB),
        .S00_AXI_wuser(icn_ctrl_1_M09_AXI_WUSER),
        .S00_AXI_wvalid(icn_ctrl_1_M09_AXI_WVALID),
        .S_AXIMM_araddr(icn_ctrl_1_M10_AXI_ARADDR),
        .S_AXIMM_arburst(icn_ctrl_1_M10_AXI_ARBURST),
        .S_AXIMM_arlen(icn_ctrl_1_M10_AXI_ARLEN),
        .S_AXIMM_arready(icn_ctrl_1_M10_AXI_ARREADY),
        .S_AXIMM_arsize(icn_ctrl_1_M10_AXI_ARSIZE),
        .S_AXIMM_arvalid(icn_ctrl_1_M10_AXI_ARVALID),
        .S_AXIMM_awaddr(icn_ctrl_1_M10_AXI_AWADDR),
        .S_AXIMM_awburst(icn_ctrl_1_M10_AXI_AWBURST),
        .S_AXIMM_awlen(icn_ctrl_1_M10_AXI_AWLEN),
        .S_AXIMM_awready(icn_ctrl_1_M10_AXI_AWREADY),
        .S_AXIMM_awsize(icn_ctrl_1_M10_AXI_AWSIZE),
        .S_AXIMM_awvalid(icn_ctrl_1_M10_AXI_AWVALID),
        .S_AXIMM_bready(icn_ctrl_1_M10_AXI_BREADY),
        .S_AXIMM_bresp(icn_ctrl_1_M10_AXI_BRESP),
        .S_AXIMM_bvalid(icn_ctrl_1_M10_AXI_BVALID),
        .S_AXIMM_rdata(icn_ctrl_1_M10_AXI_RDATA),
        .S_AXIMM_rlast(icn_ctrl_1_M10_AXI_RLAST),
        .S_AXIMM_rready(icn_ctrl_1_M10_AXI_RREADY),
        .S_AXIMM_rresp(icn_ctrl_1_M10_AXI_RRESP),
        .S_AXIMM_rvalid(icn_ctrl_1_M10_AXI_RVALID),
        .S_AXIMM_wdata(icn_ctrl_1_M10_AXI_WDATA),
        .S_AXIMM_wlast(icn_ctrl_1_M10_AXI_WLAST),
        .S_AXIMM_wready(icn_ctrl_1_M10_AXI_WREADY),
        .S_AXIMM_wstrb(icn_ctrl_1_M10_AXI_WSTRB),
        .S_AXIMM_wvalid(icn_ctrl_1_M10_AXI_WVALID),
        .S_AXIS_tdata(ai_engine_0_M00_AXIS_TDATA),
        .S_AXIS_tkeep(ai_engine_0_M00_AXIS_TKEEP),
        .S_AXIS_tlast(ai_engine_0_M00_AXIS_TLAST),
        .S_AXIS_tready(ai_engine_0_M00_AXIS_TREADY),
        .S_AXIS_tvalid(ai_engine_0_M00_AXIS_TVALID),
        .aclk(clk_wizard_0_clk_out4_o1_o2),
        .aclk_bypass_m(VitisRegion_aclk_bypass_m),
        .ap_rst_n(psr_312mhz_peripheral_aresetn),
        .ap_rst_n_bypass_m(VitisRegion_ap_rst_n_bypass_m),
        .aresetn(psr_312mhz_interconnect_aresetn),
        .dout(irq_const_tieoff_dout),
        .dout1(axi_intc_cascaded_1_intr_1_interrupt_concat_dout),
        .m_axi_gmem1_araddr(mm2s_2_m_axi_gmem_ARADDR),
        .m_axi_gmem1_arburst(mm2s_2_m_axi_gmem_ARBURST),
        .m_axi_gmem1_arcache(mm2s_2_m_axi_gmem_ARCACHE),
        .m_axi_gmem1_arid(mm2s_2_m_axi_gmem_ARID),
        .m_axi_gmem1_arlen(mm2s_2_m_axi_gmem_ARLEN),
        .m_axi_gmem1_arlock(mm2s_2_m_axi_gmem_ARLOCK),
        .m_axi_gmem1_arprot(mm2s_2_m_axi_gmem_ARPROT),
        .m_axi_gmem1_arqos(mm2s_2_m_axi_gmem_ARQOS),
        .m_axi_gmem1_arready(mm2s_2_m_axi_gmem_ARREADY),
        .m_axi_gmem1_arregion(mm2s_2_m_axi_gmem_ARREGION),
        .m_axi_gmem1_arsize(mm2s_2_m_axi_gmem_ARSIZE),
        .m_axi_gmem1_arvalid(mm2s_2_m_axi_gmem_ARVALID),
        .m_axi_gmem1_awaddr(mm2s_2_m_axi_gmem_AWADDR),
        .m_axi_gmem1_awburst(mm2s_2_m_axi_gmem_AWBURST),
        .m_axi_gmem1_awcache(mm2s_2_m_axi_gmem_AWCACHE),
        .m_axi_gmem1_awid(mm2s_2_m_axi_gmem_AWID),
        .m_axi_gmem1_awlen(mm2s_2_m_axi_gmem_AWLEN),
        .m_axi_gmem1_awlock(mm2s_2_m_axi_gmem_AWLOCK),
        .m_axi_gmem1_awprot(mm2s_2_m_axi_gmem_AWPROT),
        .m_axi_gmem1_awqos(mm2s_2_m_axi_gmem_AWQOS),
        .m_axi_gmem1_awready(mm2s_2_m_axi_gmem_AWREADY),
        .m_axi_gmem1_awregion(mm2s_2_m_axi_gmem_AWREGION),
        .m_axi_gmem1_awsize(mm2s_2_m_axi_gmem_AWSIZE),
        .m_axi_gmem1_awvalid(mm2s_2_m_axi_gmem_AWVALID),
        .m_axi_gmem1_bid(mm2s_2_m_axi_gmem_BID),
        .m_axi_gmem1_bready(mm2s_2_m_axi_gmem_BREADY),
        .m_axi_gmem1_bresp(mm2s_2_m_axi_gmem_BRESP),
        .m_axi_gmem1_bvalid(mm2s_2_m_axi_gmem_BVALID),
        .m_axi_gmem1_rdata(mm2s_2_m_axi_gmem_RDATA),
        .m_axi_gmem1_rid(mm2s_2_m_axi_gmem_RID),
        .m_axi_gmem1_rlast(mm2s_2_m_axi_gmem_RLAST),
        .m_axi_gmem1_rready(mm2s_2_m_axi_gmem_RREADY),
        .m_axi_gmem1_rresp(mm2s_2_m_axi_gmem_RRESP),
        .m_axi_gmem1_rvalid(mm2s_2_m_axi_gmem_RVALID),
        .m_axi_gmem1_wdata(mm2s_2_m_axi_gmem_WDATA),
        .m_axi_gmem1_wlast(mm2s_2_m_axi_gmem_WLAST),
        .m_axi_gmem1_wready(mm2s_2_m_axi_gmem_WREADY),
        .m_axi_gmem1_wstrb(mm2s_2_m_axi_gmem_WSTRB),
        .m_axi_gmem1_wvalid(mm2s_2_m_axi_gmem_WVALID),
        .m_axi_gmem2_araddr(s2mm_m_axi_gmem_ARADDR),
        .m_axi_gmem2_arburst(s2mm_m_axi_gmem_ARBURST),
        .m_axi_gmem2_arcache(s2mm_m_axi_gmem_ARCACHE),
        .m_axi_gmem2_arid(s2mm_m_axi_gmem_ARID),
        .m_axi_gmem2_arlen(s2mm_m_axi_gmem_ARLEN),
        .m_axi_gmem2_arlock(s2mm_m_axi_gmem_ARLOCK),
        .m_axi_gmem2_arprot(s2mm_m_axi_gmem_ARPROT),
        .m_axi_gmem2_arqos(s2mm_m_axi_gmem_ARQOS),
        .m_axi_gmem2_arready(s2mm_m_axi_gmem_ARREADY),
        .m_axi_gmem2_arregion(s2mm_m_axi_gmem_ARREGION),
        .m_axi_gmem2_arsize(s2mm_m_axi_gmem_ARSIZE),
        .m_axi_gmem2_arvalid(s2mm_m_axi_gmem_ARVALID),
        .m_axi_gmem2_awaddr(s2mm_m_axi_gmem_AWADDR),
        .m_axi_gmem2_awburst(s2mm_m_axi_gmem_AWBURST),
        .m_axi_gmem2_awcache(s2mm_m_axi_gmem_AWCACHE),
        .m_axi_gmem2_awid(s2mm_m_axi_gmem_AWID),
        .m_axi_gmem2_awlen(s2mm_m_axi_gmem_AWLEN),
        .m_axi_gmem2_awlock(s2mm_m_axi_gmem_AWLOCK),
        .m_axi_gmem2_awprot(s2mm_m_axi_gmem_AWPROT),
        .m_axi_gmem2_awqos(s2mm_m_axi_gmem_AWQOS),
        .m_axi_gmem2_awready(s2mm_m_axi_gmem_AWREADY),
        .m_axi_gmem2_awregion(s2mm_m_axi_gmem_AWREGION),
        .m_axi_gmem2_awsize(s2mm_m_axi_gmem_AWSIZE),
        .m_axi_gmem2_awvalid(s2mm_m_axi_gmem_AWVALID),
        .m_axi_gmem2_bid(s2mm_m_axi_gmem_BID),
        .m_axi_gmem2_bready(s2mm_m_axi_gmem_BREADY),
        .m_axi_gmem2_bresp(s2mm_m_axi_gmem_BRESP),
        .m_axi_gmem2_bvalid(s2mm_m_axi_gmem_BVALID),
        .m_axi_gmem2_rdata(s2mm_m_axi_gmem_RDATA),
        .m_axi_gmem2_rid(s2mm_m_axi_gmem_RID),
        .m_axi_gmem2_rlast(s2mm_m_axi_gmem_RLAST),
        .m_axi_gmem2_rready(s2mm_m_axi_gmem_RREADY),
        .m_axi_gmem2_rresp(s2mm_m_axi_gmem_RRESP),
        .m_axi_gmem2_rvalid(s2mm_m_axi_gmem_RVALID),
        .m_axi_gmem2_wdata(s2mm_m_axi_gmem_WDATA),
        .m_axi_gmem2_wlast(s2mm_m_axi_gmem_WLAST),
        .m_axi_gmem2_wready(s2mm_m_axi_gmem_WREADY),
        .m_axi_gmem2_wstrb(s2mm_m_axi_gmem_WSTRB),
        .m_axi_gmem2_wvalid(s2mm_m_axi_gmem_WVALID),
        .m_axi_gmem_araddr(mm2s_1_m_axi_gmem_ARADDR),
        .m_axi_gmem_arburst(mm2s_1_m_axi_gmem_ARBURST),
        .m_axi_gmem_arcache(mm2s_1_m_axi_gmem_ARCACHE),
        .m_axi_gmem_arid(mm2s_1_m_axi_gmem_ARID),
        .m_axi_gmem_arlen(mm2s_1_m_axi_gmem_ARLEN),
        .m_axi_gmem_arlock(mm2s_1_m_axi_gmem_ARLOCK),
        .m_axi_gmem_arprot(mm2s_1_m_axi_gmem_ARPROT),
        .m_axi_gmem_arqos(mm2s_1_m_axi_gmem_ARQOS),
        .m_axi_gmem_arready(mm2s_1_m_axi_gmem_ARREADY),
        .m_axi_gmem_arregion(mm2s_1_m_axi_gmem_ARREGION),
        .m_axi_gmem_arsize(mm2s_1_m_axi_gmem_ARSIZE),
        .m_axi_gmem_arvalid(mm2s_1_m_axi_gmem_ARVALID),
        .m_axi_gmem_awaddr(mm2s_1_m_axi_gmem_AWADDR),
        .m_axi_gmem_awburst(mm2s_1_m_axi_gmem_AWBURST),
        .m_axi_gmem_awcache(mm2s_1_m_axi_gmem_AWCACHE),
        .m_axi_gmem_awid(mm2s_1_m_axi_gmem_AWID),
        .m_axi_gmem_awlen(mm2s_1_m_axi_gmem_AWLEN),
        .m_axi_gmem_awlock(mm2s_1_m_axi_gmem_AWLOCK),
        .m_axi_gmem_awprot(mm2s_1_m_axi_gmem_AWPROT),
        .m_axi_gmem_awqos(mm2s_1_m_axi_gmem_AWQOS),
        .m_axi_gmem_awready(mm2s_1_m_axi_gmem_AWREADY),
        .m_axi_gmem_awregion(mm2s_1_m_axi_gmem_AWREGION),
        .m_axi_gmem_awsize(mm2s_1_m_axi_gmem_AWSIZE),
        .m_axi_gmem_awvalid(mm2s_1_m_axi_gmem_AWVALID),
        .m_axi_gmem_bid(mm2s_1_m_axi_gmem_BID),
        .m_axi_gmem_bready(mm2s_1_m_axi_gmem_BREADY),
        .m_axi_gmem_bresp(mm2s_1_m_axi_gmem_BRESP),
        .m_axi_gmem_bvalid(mm2s_1_m_axi_gmem_BVALID),
        .m_axi_gmem_rdata(mm2s_1_m_axi_gmem_RDATA),
        .m_axi_gmem_rid(mm2s_1_m_axi_gmem_RID),
        .m_axi_gmem_rlast(mm2s_1_m_axi_gmem_RLAST),
        .m_axi_gmem_rready(mm2s_1_m_axi_gmem_RREADY),
        .m_axi_gmem_rresp(mm2s_1_m_axi_gmem_RRESP),
        .m_axi_gmem_rvalid(mm2s_1_m_axi_gmem_RVALID),
        .m_axi_gmem_wdata(mm2s_1_m_axi_gmem_WDATA),
        .m_axi_gmem_wlast(mm2s_1_m_axi_gmem_WLAST),
        .m_axi_gmem_wready(mm2s_1_m_axi_gmem_WREADY),
        .m_axi_gmem_wstrb(mm2s_1_m_axi_gmem_WSTRB),
        .m_axi_gmem_wvalid(mm2s_1_m_axi_gmem_WVALID),
        .s_axi_control1_araddr(icn_ctrl_1_M07_AXI_ARADDR),
        .s_axi_control1_arprot(icn_ctrl_1_M07_AXI_ARPROT),
        .s_axi_control1_arready(icn_ctrl_1_M07_AXI_ARREADY),
        .s_axi_control1_arvalid(icn_ctrl_1_M07_AXI_ARVALID),
        .s_axi_control1_awaddr(icn_ctrl_1_M07_AXI_AWADDR),
        .s_axi_control1_awprot(icn_ctrl_1_M07_AXI_AWPROT),
        .s_axi_control1_awready(icn_ctrl_1_M07_AXI_AWREADY),
        .s_axi_control1_awvalid(icn_ctrl_1_M07_AXI_AWVALID),
        .s_axi_control1_bready(icn_ctrl_1_M07_AXI_BREADY),
        .s_axi_control1_bresp(icn_ctrl_1_M07_AXI_BRESP),
        .s_axi_control1_bvalid(icn_ctrl_1_M07_AXI_BVALID),
        .s_axi_control1_rdata(icn_ctrl_1_M07_AXI_RDATA),
        .s_axi_control1_rready(icn_ctrl_1_M07_AXI_RREADY),
        .s_axi_control1_rresp(icn_ctrl_1_M07_AXI_RRESP),
        .s_axi_control1_rvalid(icn_ctrl_1_M07_AXI_RVALID),
        .s_axi_control1_wdata(icn_ctrl_1_M07_AXI_WDATA),
        .s_axi_control1_wready(icn_ctrl_1_M07_AXI_WREADY),
        .s_axi_control1_wstrb(icn_ctrl_1_M07_AXI_WSTRB),
        .s_axi_control1_wvalid(icn_ctrl_1_M07_AXI_WVALID),
        .s_axi_control2_araddr(icn_ctrl_1_M08_AXI_ARADDR),
        .s_axi_control2_arprot(icn_ctrl_1_M08_AXI_ARPROT),
        .s_axi_control2_arready(icn_ctrl_1_M08_AXI_ARREADY),
        .s_axi_control2_arvalid(icn_ctrl_1_M08_AXI_ARVALID),
        .s_axi_control2_awaddr(icn_ctrl_1_M08_AXI_AWADDR),
        .s_axi_control2_awprot(icn_ctrl_1_M08_AXI_AWPROT),
        .s_axi_control2_awready(icn_ctrl_1_M08_AXI_AWREADY),
        .s_axi_control2_awvalid(icn_ctrl_1_M08_AXI_AWVALID),
        .s_axi_control2_bready(icn_ctrl_1_M08_AXI_BREADY),
        .s_axi_control2_bresp(icn_ctrl_1_M08_AXI_BRESP),
        .s_axi_control2_bvalid(icn_ctrl_1_M08_AXI_BVALID),
        .s_axi_control2_rdata(icn_ctrl_1_M08_AXI_RDATA),
        .s_axi_control2_rready(icn_ctrl_1_M08_AXI_RREADY),
        .s_axi_control2_rresp(icn_ctrl_1_M08_AXI_RRESP),
        .s_axi_control2_rvalid(icn_ctrl_1_M08_AXI_RVALID),
        .s_axi_control2_wdata(icn_ctrl_1_M08_AXI_WDATA),
        .s_axi_control2_wready(icn_ctrl_1_M08_AXI_WREADY),
        .s_axi_control2_wstrb(icn_ctrl_1_M08_AXI_WSTRB),
        .s_axi_control2_wvalid(icn_ctrl_1_M08_AXI_WVALID),
        .s_axi_control_araddr(icn_ctrl_1_M06_AXI_ARADDR),
        .s_axi_control_arprot(icn_ctrl_1_M06_AXI_ARPROT),
        .s_axi_control_arready(icn_ctrl_1_M06_AXI_ARREADY),
        .s_axi_control_arvalid(icn_ctrl_1_M06_AXI_ARVALID),
        .s_axi_control_awaddr(icn_ctrl_1_M06_AXI_AWADDR),
        .s_axi_control_awprot(icn_ctrl_1_M06_AXI_AWPROT),
        .s_axi_control_awready(icn_ctrl_1_M06_AXI_AWREADY),
        .s_axi_control_awvalid(icn_ctrl_1_M06_AXI_AWVALID),
        .s_axi_control_bready(icn_ctrl_1_M06_AXI_BREADY),
        .s_axi_control_bresp(icn_ctrl_1_M06_AXI_BRESP),
        .s_axi_control_bvalid(icn_ctrl_1_M06_AXI_BVALID),
        .s_axi_control_rdata(icn_ctrl_1_M06_AXI_RDATA),
        .s_axi_control_rready(icn_ctrl_1_M06_AXI_RREADY),
        .s_axi_control_rresp(icn_ctrl_1_M06_AXI_RRESP),
        .s_axi_control_rvalid(icn_ctrl_1_M06_AXI_RVALID),
        .s_axi_control_wdata(icn_ctrl_1_M06_AXI_WDATA),
        .s_axi_control_wready(icn_ctrl_1_M06_AXI_WREADY),
        .s_axi_control_wstrb(icn_ctrl_1_M06_AXI_WSTRB),
        .s_axi_control_wvalid(icn_ctrl_1_M06_AXI_WVALID));
  vitis_design_ai_engine_0_0 ai_engine_0
       (.M00_AXIS_tdata(ai_engine_0_M00_AXIS_TDATA),
        .M00_AXIS_tkeep(ai_engine_0_M00_AXIS_TKEEP),
        .M00_AXIS_tlast(ai_engine_0_M00_AXIS_TLAST),
        .M00_AXIS_tready(ai_engine_0_M00_AXIS_TREADY),
        .M00_AXIS_tvalid(ai_engine_0_M00_AXIS_TVALID),
        .S00_AXIS_tdata(dwc_mm2s_1_s_M_AXIS_TDATA),
        .S00_AXIS_tkeep(dwc_mm2s_1_s_M_AXIS_TKEEP),
        .S00_AXIS_tlast(dwc_mm2s_1_s_M_AXIS_TLAST),
        .S00_AXIS_tready(dwc_mm2s_1_s_M_AXIS_TREADY),
        .S00_AXIS_tvalid(dwc_mm2s_1_s_M_AXIS_TVALID),
        .S00_AXI_araddr(cips_noc_M00_AXI_ARADDR[33:0]),
        .S00_AXI_arburst(cips_noc_M00_AXI_ARBURST),
        .S00_AXI_arcache(cips_noc_M00_AXI_ARCACHE),
        .S00_AXI_arid({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,cips_noc_M00_AXI_ARID}),
        .S00_AXI_arlen(cips_noc_M00_AXI_ARLEN),
        .S00_AXI_arlock(cips_noc_M00_AXI_ARLOCK),
        .S00_AXI_arprot(cips_noc_M00_AXI_ARPROT),
        .S00_AXI_arqos(cips_noc_M00_AXI_ARQOS),
        .S00_AXI_arready(cips_noc_M00_AXI_ARREADY),
        .S00_AXI_arregion(cips_noc_M00_AXI_ARREGION),
        .S00_AXI_arsize(cips_noc_M00_AXI_ARSIZE),
        .S00_AXI_arvalid(cips_noc_M00_AXI_ARVALID),
        .S00_AXI_awaddr(cips_noc_M00_AXI_AWADDR[33:0]),
        .S00_AXI_awburst(cips_noc_M00_AXI_AWBURST),
        .S00_AXI_awcache(cips_noc_M00_AXI_AWCACHE),
        .S00_AXI_awid({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,cips_noc_M00_AXI_AWID}),
        .S00_AXI_awlen(cips_noc_M00_AXI_AWLEN),
        .S00_AXI_awlock(cips_noc_M00_AXI_AWLOCK),
        .S00_AXI_awprot(cips_noc_M00_AXI_AWPROT),
        .S00_AXI_awqos(cips_noc_M00_AXI_AWQOS),
        .S00_AXI_awready(cips_noc_M00_AXI_AWREADY),
        .S00_AXI_awregion(cips_noc_M00_AXI_AWREGION),
        .S00_AXI_awsize(cips_noc_M00_AXI_AWSIZE),
        .S00_AXI_awvalid(cips_noc_M00_AXI_AWVALID),
        .S00_AXI_bid(cips_noc_M00_AXI_BID),
        .S00_AXI_bready(cips_noc_M00_AXI_BREADY),
        .S00_AXI_bresp(cips_noc_M00_AXI_BRESP),
        .S00_AXI_bvalid(cips_noc_M00_AXI_BVALID),
        .S00_AXI_rdata(cips_noc_M00_AXI_RDATA),
        .S00_AXI_rid(cips_noc_M00_AXI_RID),
        .S00_AXI_rlast(cips_noc_M00_AXI_RLAST),
        .S00_AXI_rready(cips_noc_M00_AXI_RREADY),
        .S00_AXI_rresp(cips_noc_M00_AXI_RRESP),
        .S00_AXI_ruser(cips_noc_M00_AXI_RUSER),
        .S00_AXI_rvalid(cips_noc_M00_AXI_RVALID),
        .S00_AXI_wdata(cips_noc_M00_AXI_WDATA),
        .S00_AXI_wlast(cips_noc_M00_AXI_WLAST),
        .S00_AXI_wready(cips_noc_M00_AXI_WREADY),
        .S00_AXI_wstrb(cips_noc_M00_AXI_WSTRB),
        .S00_AXI_wuser(cips_noc_M00_AXI_WUSER),
        .S00_AXI_wvalid(cips_noc_M00_AXI_WVALID),
        .S01_AXIS_tdata(dwc_mm2s_2_s_M_AXIS_TDATA),
        .S01_AXIS_tkeep(dwc_mm2s_2_s_M_AXIS_TKEEP),
        .S01_AXIS_tlast(dwc_mm2s_2_s_M_AXIS_TLAST),
        .S01_AXIS_tready(dwc_mm2s_2_s_M_AXIS_TREADY),
        .S01_AXIS_tvalid(dwc_mm2s_2_s_M_AXIS_TVALID),
        .aclk0(VitisRegion_aclk_bypass_m),
        .aresetn0(VitisRegion_ap_rst_n_bypass_m),
        .s00_axi_aclk(ai_engine_0_s00_axi_aclk));
  vitis_design_axi_intc_cascaded_1_0 axi_intc_cascaded_1
       (.intr(axi_intc_cascaded_1_intr_1_interrupt_concat_dout),
        .irq(axi_intc_cascaded_1_irq),
        .s_axi_aclk(clk_wizard_0_clk_out1),
        .s_axi_araddr(icn_ctrl_1_M00_AXI_ARADDR),
        .s_axi_aresetn(psr_104mhz_peripheral_aresetn),
        .s_axi_arready(icn_ctrl_1_M00_AXI_ARREADY),
        .s_axi_arvalid(icn_ctrl_1_M00_AXI_ARVALID),
        .s_axi_awaddr(icn_ctrl_1_M00_AXI_AWADDR),
        .s_axi_awready(icn_ctrl_1_M00_AXI_AWREADY),
        .s_axi_awvalid(icn_ctrl_1_M00_AXI_AWVALID),
        .s_axi_bready(icn_ctrl_1_M00_AXI_BREADY),
        .s_axi_bresp(icn_ctrl_1_M00_AXI_BRESP),
        .s_axi_bvalid(icn_ctrl_1_M00_AXI_BVALID),
        .s_axi_rdata(icn_ctrl_1_M00_AXI_RDATA),
        .s_axi_rready(icn_ctrl_1_M00_AXI_RREADY),
        .s_axi_rresp(icn_ctrl_1_M00_AXI_RRESP),
        .s_axi_rvalid(icn_ctrl_1_M00_AXI_RVALID),
        .s_axi_wdata(icn_ctrl_1_M00_AXI_WDATA),
        .s_axi_wready(icn_ctrl_1_M00_AXI_WREADY),
        .s_axi_wstrb(icn_ctrl_1_M00_AXI_WSTRB),
        .s_axi_wvalid(icn_ctrl_1_M00_AXI_WVALID));
  vitis_design_axi_intc_parent_0 axi_intc_parent
       (.intr(xlconcat_0_dout),
        .irq(axi_intc_3_irq),
        .s_axi_aclk(clk_wizard_0_clk_out1),
        .s_axi_araddr(icn_ctrl_1_M01_AXI_ARADDR),
        .s_axi_aresetn(psr_104mhz_peripheral_aresetn),
        .s_axi_arready(icn_ctrl_1_M01_AXI_ARREADY),
        .s_axi_arvalid(icn_ctrl_1_M01_AXI_ARVALID),
        .s_axi_awaddr(icn_ctrl_1_M01_AXI_AWADDR),
        .s_axi_awready(icn_ctrl_1_M01_AXI_AWREADY),
        .s_axi_awvalid(icn_ctrl_1_M01_AXI_AWVALID),
        .s_axi_bready(icn_ctrl_1_M01_AXI_BREADY),
        .s_axi_bresp(icn_ctrl_1_M01_AXI_BRESP),
        .s_axi_bvalid(icn_ctrl_1_M01_AXI_BVALID),
        .s_axi_rdata(icn_ctrl_1_M01_AXI_RDATA),
        .s_axi_rready(icn_ctrl_1_M01_AXI_RREADY),
        .s_axi_rresp(icn_ctrl_1_M01_AXI_RRESP),
        .s_axi_rvalid(icn_ctrl_1_M01_AXI_RVALID),
        .s_axi_wdata(icn_ctrl_1_M01_AXI_WDATA),
        .s_axi_wready(icn_ctrl_1_M01_AXI_WREADY),
        .s_axi_wstrb(icn_ctrl_1_M01_AXI_WSTRB),
        .s_axi_wvalid(icn_ctrl_1_M01_AXI_WVALID));
  vitis_design_cips_noc_0 cips_noc
       (.M00_AXI_araddr(cips_noc_M00_AXI_ARADDR),
        .M00_AXI_arburst(cips_noc_M00_AXI_ARBURST),
        .M00_AXI_arcache(cips_noc_M00_AXI_ARCACHE),
        .M00_AXI_arid(cips_noc_M00_AXI_ARID),
        .M00_AXI_arlen(cips_noc_M00_AXI_ARLEN),
        .M00_AXI_arlock(cips_noc_M00_AXI_ARLOCK),
        .M00_AXI_arprot(cips_noc_M00_AXI_ARPROT),
        .M00_AXI_arqos(cips_noc_M00_AXI_ARQOS),
        .M00_AXI_arready(cips_noc_M00_AXI_ARREADY),
        .M00_AXI_arregion(cips_noc_M00_AXI_ARREGION),
        .M00_AXI_arsize(cips_noc_M00_AXI_ARSIZE),
        .M00_AXI_arvalid(cips_noc_M00_AXI_ARVALID),
        .M00_AXI_awaddr(cips_noc_M00_AXI_AWADDR),
        .M00_AXI_awburst(cips_noc_M00_AXI_AWBURST),
        .M00_AXI_awcache(cips_noc_M00_AXI_AWCACHE),
        .M00_AXI_awid(cips_noc_M00_AXI_AWID),
        .M00_AXI_awlen(cips_noc_M00_AXI_AWLEN),
        .M00_AXI_awlock(cips_noc_M00_AXI_AWLOCK),
        .M00_AXI_awprot(cips_noc_M00_AXI_AWPROT),
        .M00_AXI_awqos(cips_noc_M00_AXI_AWQOS),
        .M00_AXI_awready(cips_noc_M00_AXI_AWREADY),
        .M00_AXI_awregion(cips_noc_M00_AXI_AWREGION),
        .M00_AXI_awsize(cips_noc_M00_AXI_AWSIZE),
        .M00_AXI_awvalid(cips_noc_M00_AXI_AWVALID),
        .M00_AXI_bid(cips_noc_M00_AXI_BID[1:0]),
        .M00_AXI_bready(cips_noc_M00_AXI_BREADY),
        .M00_AXI_bresp(cips_noc_M00_AXI_BRESP),
        .M00_AXI_bvalid(cips_noc_M00_AXI_BVALID),
        .M00_AXI_rdata(cips_noc_M00_AXI_RDATA),
        .M00_AXI_rid(cips_noc_M00_AXI_RID[1:0]),
        .M00_AXI_rlast(cips_noc_M00_AXI_RLAST),
        .M00_AXI_rready(cips_noc_M00_AXI_RREADY),
        .M00_AXI_rresp(cips_noc_M00_AXI_RRESP),
        .M00_AXI_ruser(cips_noc_M00_AXI_RUSER),
        .M00_AXI_rvalid(cips_noc_M00_AXI_RVALID),
        .M00_AXI_wdata(cips_noc_M00_AXI_WDATA),
        .M00_AXI_wlast(cips_noc_M00_AXI_WLAST),
        .M00_AXI_wready(cips_noc_M00_AXI_WREADY),
        .M00_AXI_wstrb(cips_noc_M00_AXI_WSTRB),
        .M00_AXI_wuser(cips_noc_M00_AXI_WUSER),
        .M00_AXI_wvalid(cips_noc_M00_AXI_WVALID),
        .M00_INI_internoc(cips_noc_M00_INI_INTERNOC),
        .M01_INI_internoc(cips_noc_M01_INI_INTERNOC),
        .M02_INI_internoc(cips_noc_M02_INI_INTERNOC),
        .M03_INI_internoc(cips_noc_M03_INI_INTERNOC),
        .M04_INI_internoc(cips_noc_M04_INI_INTERNOC),
        .M05_INI_internoc(cips_noc_M05_INI_INTERNOC),
        .M06_INI_internoc(cips_noc_M06_INI_INTERNOC),
        .M07_INI_internoc(cips_noc_M07_INI_INTERNOC),
        .S00_AXI_araddr(CIPS_0_IF_PS_NOC_CCI_0_ARADDR),
        .S00_AXI_arburst(CIPS_0_IF_PS_NOC_CCI_0_ARBURST),
        .S00_AXI_arcache(CIPS_0_IF_PS_NOC_CCI_0_ARCACHE),
        .S00_AXI_arid(CIPS_0_IF_PS_NOC_CCI_0_ARID),
        .S00_AXI_arlen(CIPS_0_IF_PS_NOC_CCI_0_ARLEN),
        .S00_AXI_arlock(CIPS_0_IF_PS_NOC_CCI_0_ARLOCK),
        .S00_AXI_arprot(CIPS_0_IF_PS_NOC_CCI_0_ARPROT),
        .S00_AXI_arqos(CIPS_0_IF_PS_NOC_CCI_0_ARQOS),
        .S00_AXI_arready(CIPS_0_IF_PS_NOC_CCI_0_ARREADY),
        .S00_AXI_arregion({1'b0,1'b0,1'b0,1'b0}),
        .S00_AXI_arsize(CIPS_0_IF_PS_NOC_CCI_0_ARSIZE),
        .S00_AXI_aruser(CIPS_0_IF_PS_NOC_CCI_0_ARUSER),
        .S00_AXI_arvalid(CIPS_0_IF_PS_NOC_CCI_0_ARVALID),
        .S00_AXI_awaddr(CIPS_0_IF_PS_NOC_CCI_0_AWADDR),
        .S00_AXI_awburst(CIPS_0_IF_PS_NOC_CCI_0_AWBURST),
        .S00_AXI_awcache(CIPS_0_IF_PS_NOC_CCI_0_AWCACHE),
        .S00_AXI_awid(CIPS_0_IF_PS_NOC_CCI_0_AWID),
        .S00_AXI_awlen(CIPS_0_IF_PS_NOC_CCI_0_AWLEN),
        .S00_AXI_awlock(CIPS_0_IF_PS_NOC_CCI_0_AWLOCK),
        .S00_AXI_awprot(CIPS_0_IF_PS_NOC_CCI_0_AWPROT),
        .S00_AXI_awqos(CIPS_0_IF_PS_NOC_CCI_0_AWQOS),
        .S00_AXI_awready(CIPS_0_IF_PS_NOC_CCI_0_AWREADY),
        .S00_AXI_awregion({1'b0,1'b0,1'b0,1'b0}),
        .S00_AXI_awsize(CIPS_0_IF_PS_NOC_CCI_0_AWSIZE),
        .S00_AXI_awuser(CIPS_0_IF_PS_NOC_CCI_0_AWUSER),
        .S00_AXI_awvalid(CIPS_0_IF_PS_NOC_CCI_0_AWVALID),
        .S00_AXI_bid(CIPS_0_IF_PS_NOC_CCI_0_BID),
        .S00_AXI_bready(CIPS_0_IF_PS_NOC_CCI_0_BREADY),
        .S00_AXI_bresp(CIPS_0_IF_PS_NOC_CCI_0_BRESP),
        .S00_AXI_bvalid(CIPS_0_IF_PS_NOC_CCI_0_BVALID),
        .S00_AXI_rdata(CIPS_0_IF_PS_NOC_CCI_0_RDATA),
        .S00_AXI_rid(CIPS_0_IF_PS_NOC_CCI_0_RID),
        .S00_AXI_rlast(CIPS_0_IF_PS_NOC_CCI_0_RLAST),
        .S00_AXI_rready(CIPS_0_IF_PS_NOC_CCI_0_RREADY),
        .S00_AXI_rresp(CIPS_0_IF_PS_NOC_CCI_0_RRESP),
        .S00_AXI_rvalid(CIPS_0_IF_PS_NOC_CCI_0_RVALID),
        .S00_AXI_wdata(CIPS_0_IF_PS_NOC_CCI_0_WDATA),
        .S00_AXI_wlast(CIPS_0_IF_PS_NOC_CCI_0_WLAST),
        .S00_AXI_wready(CIPS_0_IF_PS_NOC_CCI_0_WREADY),
        .S00_AXI_wstrb(CIPS_0_IF_PS_NOC_CCI_0_WSTRB),
        .S00_AXI_wuser(CIPS_0_IF_PS_NOC_CCI_0_WUSER),
        .S00_AXI_wvalid(CIPS_0_IF_PS_NOC_CCI_0_WVALID),
        .S01_AXI_araddr(CIPS_0_IF_PS_NOC_CCI_1_ARADDR),
        .S01_AXI_arburst(CIPS_0_IF_PS_NOC_CCI_1_ARBURST),
        .S01_AXI_arcache(CIPS_0_IF_PS_NOC_CCI_1_ARCACHE),
        .S01_AXI_arid(CIPS_0_IF_PS_NOC_CCI_1_ARID),
        .S01_AXI_arlen(CIPS_0_IF_PS_NOC_CCI_1_ARLEN),
        .S01_AXI_arlock(CIPS_0_IF_PS_NOC_CCI_1_ARLOCK),
        .S01_AXI_arprot(CIPS_0_IF_PS_NOC_CCI_1_ARPROT),
        .S01_AXI_arqos(CIPS_0_IF_PS_NOC_CCI_1_ARQOS),
        .S01_AXI_arready(CIPS_0_IF_PS_NOC_CCI_1_ARREADY),
        .S01_AXI_arregion({1'b0,1'b0,1'b0,1'b0}),
        .S01_AXI_arsize(CIPS_0_IF_PS_NOC_CCI_1_ARSIZE),
        .S01_AXI_aruser(CIPS_0_IF_PS_NOC_CCI_1_ARUSER),
        .S01_AXI_arvalid(CIPS_0_IF_PS_NOC_CCI_1_ARVALID),
        .S01_AXI_awaddr(CIPS_0_IF_PS_NOC_CCI_1_AWADDR),
        .S01_AXI_awburst(CIPS_0_IF_PS_NOC_CCI_1_AWBURST),
        .S01_AXI_awcache(CIPS_0_IF_PS_NOC_CCI_1_AWCACHE),
        .S01_AXI_awid(CIPS_0_IF_PS_NOC_CCI_1_AWID),
        .S01_AXI_awlen(CIPS_0_IF_PS_NOC_CCI_1_AWLEN),
        .S01_AXI_awlock(CIPS_0_IF_PS_NOC_CCI_1_AWLOCK),
        .S01_AXI_awprot(CIPS_0_IF_PS_NOC_CCI_1_AWPROT),
        .S01_AXI_awqos(CIPS_0_IF_PS_NOC_CCI_1_AWQOS),
        .S01_AXI_awready(CIPS_0_IF_PS_NOC_CCI_1_AWREADY),
        .S01_AXI_awregion({1'b0,1'b0,1'b0,1'b0}),
        .S01_AXI_awsize(CIPS_0_IF_PS_NOC_CCI_1_AWSIZE),
        .S01_AXI_awuser(CIPS_0_IF_PS_NOC_CCI_1_AWUSER),
        .S01_AXI_awvalid(CIPS_0_IF_PS_NOC_CCI_1_AWVALID),
        .S01_AXI_bid(CIPS_0_IF_PS_NOC_CCI_1_BID),
        .S01_AXI_bready(CIPS_0_IF_PS_NOC_CCI_1_BREADY),
        .S01_AXI_bresp(CIPS_0_IF_PS_NOC_CCI_1_BRESP),
        .S01_AXI_bvalid(CIPS_0_IF_PS_NOC_CCI_1_BVALID),
        .S01_AXI_rdata(CIPS_0_IF_PS_NOC_CCI_1_RDATA),
        .S01_AXI_rid(CIPS_0_IF_PS_NOC_CCI_1_RID),
        .S01_AXI_rlast(CIPS_0_IF_PS_NOC_CCI_1_RLAST),
        .S01_AXI_rready(CIPS_0_IF_PS_NOC_CCI_1_RREADY),
        .S01_AXI_rresp(CIPS_0_IF_PS_NOC_CCI_1_RRESP),
        .S01_AXI_rvalid(CIPS_0_IF_PS_NOC_CCI_1_RVALID),
        .S01_AXI_wdata(CIPS_0_IF_PS_NOC_CCI_1_WDATA),
        .S01_AXI_wlast(CIPS_0_IF_PS_NOC_CCI_1_WLAST),
        .S01_AXI_wready(CIPS_0_IF_PS_NOC_CCI_1_WREADY),
        .S01_AXI_wstrb(CIPS_0_IF_PS_NOC_CCI_1_WSTRB),
        .S01_AXI_wuser(CIPS_0_IF_PS_NOC_CCI_1_WUSER),
        .S01_AXI_wvalid(CIPS_0_IF_PS_NOC_CCI_1_WVALID),
        .S02_AXI_araddr(CIPS_0_IF_PS_NOC_CCI_2_ARADDR),
        .S02_AXI_arburst(CIPS_0_IF_PS_NOC_CCI_2_ARBURST),
        .S02_AXI_arcache(CIPS_0_IF_PS_NOC_CCI_2_ARCACHE),
        .S02_AXI_arid(CIPS_0_IF_PS_NOC_CCI_2_ARID),
        .S02_AXI_arlen(CIPS_0_IF_PS_NOC_CCI_2_ARLEN),
        .S02_AXI_arlock(CIPS_0_IF_PS_NOC_CCI_2_ARLOCK),
        .S02_AXI_arprot(CIPS_0_IF_PS_NOC_CCI_2_ARPROT),
        .S02_AXI_arqos(CIPS_0_IF_PS_NOC_CCI_2_ARQOS),
        .S02_AXI_arready(CIPS_0_IF_PS_NOC_CCI_2_ARREADY),
        .S02_AXI_arregion({1'b0,1'b0,1'b0,1'b0}),
        .S02_AXI_arsize(CIPS_0_IF_PS_NOC_CCI_2_ARSIZE),
        .S02_AXI_aruser(CIPS_0_IF_PS_NOC_CCI_2_ARUSER),
        .S02_AXI_arvalid(CIPS_0_IF_PS_NOC_CCI_2_ARVALID),
        .S02_AXI_awaddr(CIPS_0_IF_PS_NOC_CCI_2_AWADDR),
        .S02_AXI_awburst(CIPS_0_IF_PS_NOC_CCI_2_AWBURST),
        .S02_AXI_awcache(CIPS_0_IF_PS_NOC_CCI_2_AWCACHE),
        .S02_AXI_awid(CIPS_0_IF_PS_NOC_CCI_2_AWID),
        .S02_AXI_awlen(CIPS_0_IF_PS_NOC_CCI_2_AWLEN),
        .S02_AXI_awlock(CIPS_0_IF_PS_NOC_CCI_2_AWLOCK),
        .S02_AXI_awprot(CIPS_0_IF_PS_NOC_CCI_2_AWPROT),
        .S02_AXI_awqos(CIPS_0_IF_PS_NOC_CCI_2_AWQOS),
        .S02_AXI_awready(CIPS_0_IF_PS_NOC_CCI_2_AWREADY),
        .S02_AXI_awregion({1'b0,1'b0,1'b0,1'b0}),
        .S02_AXI_awsize(CIPS_0_IF_PS_NOC_CCI_2_AWSIZE),
        .S02_AXI_awuser(CIPS_0_IF_PS_NOC_CCI_2_AWUSER),
        .S02_AXI_awvalid(CIPS_0_IF_PS_NOC_CCI_2_AWVALID),
        .S02_AXI_bid(CIPS_0_IF_PS_NOC_CCI_2_BID),
        .S02_AXI_bready(CIPS_0_IF_PS_NOC_CCI_2_BREADY),
        .S02_AXI_bresp(CIPS_0_IF_PS_NOC_CCI_2_BRESP),
        .S02_AXI_bvalid(CIPS_0_IF_PS_NOC_CCI_2_BVALID),
        .S02_AXI_rdata(CIPS_0_IF_PS_NOC_CCI_2_RDATA),
        .S02_AXI_rid(CIPS_0_IF_PS_NOC_CCI_2_RID),
        .S02_AXI_rlast(CIPS_0_IF_PS_NOC_CCI_2_RLAST),
        .S02_AXI_rready(CIPS_0_IF_PS_NOC_CCI_2_RREADY),
        .S02_AXI_rresp(CIPS_0_IF_PS_NOC_CCI_2_RRESP),
        .S02_AXI_rvalid(CIPS_0_IF_PS_NOC_CCI_2_RVALID),
        .S02_AXI_wdata(CIPS_0_IF_PS_NOC_CCI_2_WDATA),
        .S02_AXI_wlast(CIPS_0_IF_PS_NOC_CCI_2_WLAST),
        .S02_AXI_wready(CIPS_0_IF_PS_NOC_CCI_2_WREADY),
        .S02_AXI_wstrb(CIPS_0_IF_PS_NOC_CCI_2_WSTRB),
        .S02_AXI_wuser(CIPS_0_IF_PS_NOC_CCI_2_WUSER),
        .S02_AXI_wvalid(CIPS_0_IF_PS_NOC_CCI_2_WVALID),
        .S03_AXI_araddr(CIPS_0_IF_PS_NOC_CCI_3_ARADDR),
        .S03_AXI_arburst(CIPS_0_IF_PS_NOC_CCI_3_ARBURST),
        .S03_AXI_arcache(CIPS_0_IF_PS_NOC_CCI_3_ARCACHE),
        .S03_AXI_arid(CIPS_0_IF_PS_NOC_CCI_3_ARID),
        .S03_AXI_arlen(CIPS_0_IF_PS_NOC_CCI_3_ARLEN),
        .S03_AXI_arlock(CIPS_0_IF_PS_NOC_CCI_3_ARLOCK),
        .S03_AXI_arprot(CIPS_0_IF_PS_NOC_CCI_3_ARPROT),
        .S03_AXI_arqos(CIPS_0_IF_PS_NOC_CCI_3_ARQOS),
        .S03_AXI_arready(CIPS_0_IF_PS_NOC_CCI_3_ARREADY),
        .S03_AXI_arregion({1'b0,1'b0,1'b0,1'b0}),
        .S03_AXI_arsize(CIPS_0_IF_PS_NOC_CCI_3_ARSIZE),
        .S03_AXI_aruser(CIPS_0_IF_PS_NOC_CCI_3_ARUSER),
        .S03_AXI_arvalid(CIPS_0_IF_PS_NOC_CCI_3_ARVALID),
        .S03_AXI_awaddr(CIPS_0_IF_PS_NOC_CCI_3_AWADDR),
        .S03_AXI_awburst(CIPS_0_IF_PS_NOC_CCI_3_AWBURST),
        .S03_AXI_awcache(CIPS_0_IF_PS_NOC_CCI_3_AWCACHE),
        .S03_AXI_awid(CIPS_0_IF_PS_NOC_CCI_3_AWID),
        .S03_AXI_awlen(CIPS_0_IF_PS_NOC_CCI_3_AWLEN),
        .S03_AXI_awlock(CIPS_0_IF_PS_NOC_CCI_3_AWLOCK),
        .S03_AXI_awprot(CIPS_0_IF_PS_NOC_CCI_3_AWPROT),
        .S03_AXI_awqos(CIPS_0_IF_PS_NOC_CCI_3_AWQOS),
        .S03_AXI_awready(CIPS_0_IF_PS_NOC_CCI_3_AWREADY),
        .S03_AXI_awregion({1'b0,1'b0,1'b0,1'b0}),
        .S03_AXI_awsize(CIPS_0_IF_PS_NOC_CCI_3_AWSIZE),
        .S03_AXI_awuser(CIPS_0_IF_PS_NOC_CCI_3_AWUSER),
        .S03_AXI_awvalid(CIPS_0_IF_PS_NOC_CCI_3_AWVALID),
        .S03_AXI_bid(CIPS_0_IF_PS_NOC_CCI_3_BID),
        .S03_AXI_bready(CIPS_0_IF_PS_NOC_CCI_3_BREADY),
        .S03_AXI_bresp(CIPS_0_IF_PS_NOC_CCI_3_BRESP),
        .S03_AXI_bvalid(CIPS_0_IF_PS_NOC_CCI_3_BVALID),
        .S03_AXI_rdata(CIPS_0_IF_PS_NOC_CCI_3_RDATA),
        .S03_AXI_rid(CIPS_0_IF_PS_NOC_CCI_3_RID),
        .S03_AXI_rlast(CIPS_0_IF_PS_NOC_CCI_3_RLAST),
        .S03_AXI_rready(CIPS_0_IF_PS_NOC_CCI_3_RREADY),
        .S03_AXI_rresp(CIPS_0_IF_PS_NOC_CCI_3_RRESP),
        .S03_AXI_rvalid(CIPS_0_IF_PS_NOC_CCI_3_RVALID),
        .S03_AXI_wdata(CIPS_0_IF_PS_NOC_CCI_3_WDATA),
        .S03_AXI_wlast(CIPS_0_IF_PS_NOC_CCI_3_WLAST),
        .S03_AXI_wready(CIPS_0_IF_PS_NOC_CCI_3_WREADY),
        .S03_AXI_wstrb(CIPS_0_IF_PS_NOC_CCI_3_WSTRB),
        .S03_AXI_wuser(CIPS_0_IF_PS_NOC_CCI_3_WUSER),
        .S03_AXI_wvalid(CIPS_0_IF_PS_NOC_CCI_3_WVALID),
        .S04_AXI_araddr(CIPS_0_IF_PS_NOC_NCI_0_ARADDR),
        .S04_AXI_arburst(CIPS_0_IF_PS_NOC_NCI_0_ARBURST),
        .S04_AXI_arcache(CIPS_0_IF_PS_NOC_NCI_0_ARCACHE),
        .S04_AXI_arid(CIPS_0_IF_PS_NOC_NCI_0_ARID),
        .S04_AXI_arlen(CIPS_0_IF_PS_NOC_NCI_0_ARLEN),
        .S04_AXI_arlock(CIPS_0_IF_PS_NOC_NCI_0_ARLOCK),
        .S04_AXI_arprot(CIPS_0_IF_PS_NOC_NCI_0_ARPROT),
        .S04_AXI_arqos(CIPS_0_IF_PS_NOC_NCI_0_ARQOS),
        .S04_AXI_arready(CIPS_0_IF_PS_NOC_NCI_0_ARREADY),
        .S04_AXI_arregion({1'b0,1'b0,1'b0,1'b0}),
        .S04_AXI_arsize(CIPS_0_IF_PS_NOC_NCI_0_ARSIZE),
        .S04_AXI_aruser(CIPS_0_IF_PS_NOC_NCI_0_ARUSER),
        .S04_AXI_arvalid(CIPS_0_IF_PS_NOC_NCI_0_ARVALID),
        .S04_AXI_awaddr(CIPS_0_IF_PS_NOC_NCI_0_AWADDR),
        .S04_AXI_awburst(CIPS_0_IF_PS_NOC_NCI_0_AWBURST),
        .S04_AXI_awcache(CIPS_0_IF_PS_NOC_NCI_0_AWCACHE),
        .S04_AXI_awid(CIPS_0_IF_PS_NOC_NCI_0_AWID),
        .S04_AXI_awlen(CIPS_0_IF_PS_NOC_NCI_0_AWLEN),
        .S04_AXI_awlock(CIPS_0_IF_PS_NOC_NCI_0_AWLOCK),
        .S04_AXI_awprot(CIPS_0_IF_PS_NOC_NCI_0_AWPROT),
        .S04_AXI_awqos(CIPS_0_IF_PS_NOC_NCI_0_AWQOS),
        .S04_AXI_awready(CIPS_0_IF_PS_NOC_NCI_0_AWREADY),
        .S04_AXI_awregion({1'b0,1'b0,1'b0,1'b0}),
        .S04_AXI_awsize(CIPS_0_IF_PS_NOC_NCI_0_AWSIZE),
        .S04_AXI_awuser(CIPS_0_IF_PS_NOC_NCI_0_AWUSER),
        .S04_AXI_awvalid(CIPS_0_IF_PS_NOC_NCI_0_AWVALID),
        .S04_AXI_bid(CIPS_0_IF_PS_NOC_NCI_0_BID),
        .S04_AXI_bready(CIPS_0_IF_PS_NOC_NCI_0_BREADY),
        .S04_AXI_bresp(CIPS_0_IF_PS_NOC_NCI_0_BRESP),
        .S04_AXI_bvalid(CIPS_0_IF_PS_NOC_NCI_0_BVALID),
        .S04_AXI_rdata(CIPS_0_IF_PS_NOC_NCI_0_RDATA),
        .S04_AXI_rid(CIPS_0_IF_PS_NOC_NCI_0_RID),
        .S04_AXI_rlast(CIPS_0_IF_PS_NOC_NCI_0_RLAST),
        .S04_AXI_rready(CIPS_0_IF_PS_NOC_NCI_0_RREADY),
        .S04_AXI_rresp(CIPS_0_IF_PS_NOC_NCI_0_RRESP),
        .S04_AXI_rvalid(CIPS_0_IF_PS_NOC_NCI_0_RVALID),
        .S04_AXI_wdata(CIPS_0_IF_PS_NOC_NCI_0_WDATA),
        .S04_AXI_wlast(CIPS_0_IF_PS_NOC_NCI_0_WLAST),
        .S04_AXI_wready(CIPS_0_IF_PS_NOC_NCI_0_WREADY),
        .S04_AXI_wstrb(CIPS_0_IF_PS_NOC_NCI_0_WSTRB),
        .S04_AXI_wuser({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .S04_AXI_wvalid(CIPS_0_IF_PS_NOC_NCI_0_WVALID),
        .S05_AXI_araddr(CIPS_0_IF_PS_NOC_NCI_1_ARADDR),
        .S05_AXI_arburst(CIPS_0_IF_PS_NOC_NCI_1_ARBURST),
        .S05_AXI_arcache(CIPS_0_IF_PS_NOC_NCI_1_ARCACHE),
        .S05_AXI_arid(CIPS_0_IF_PS_NOC_NCI_1_ARID),
        .S05_AXI_arlen(CIPS_0_IF_PS_NOC_NCI_1_ARLEN),
        .S05_AXI_arlock(CIPS_0_IF_PS_NOC_NCI_1_ARLOCK),
        .S05_AXI_arprot(CIPS_0_IF_PS_NOC_NCI_1_ARPROT),
        .S05_AXI_arqos(CIPS_0_IF_PS_NOC_NCI_1_ARQOS),
        .S05_AXI_arready(CIPS_0_IF_PS_NOC_NCI_1_ARREADY),
        .S05_AXI_arregion({1'b0,1'b0,1'b0,1'b0}),
        .S05_AXI_arsize(CIPS_0_IF_PS_NOC_NCI_1_ARSIZE),
        .S05_AXI_aruser(CIPS_0_IF_PS_NOC_NCI_1_ARUSER),
        .S05_AXI_arvalid(CIPS_0_IF_PS_NOC_NCI_1_ARVALID),
        .S05_AXI_awaddr(CIPS_0_IF_PS_NOC_NCI_1_AWADDR),
        .S05_AXI_awburst(CIPS_0_IF_PS_NOC_NCI_1_AWBURST),
        .S05_AXI_awcache(CIPS_0_IF_PS_NOC_NCI_1_AWCACHE),
        .S05_AXI_awid(CIPS_0_IF_PS_NOC_NCI_1_AWID),
        .S05_AXI_awlen(CIPS_0_IF_PS_NOC_NCI_1_AWLEN),
        .S05_AXI_awlock(CIPS_0_IF_PS_NOC_NCI_1_AWLOCK),
        .S05_AXI_awprot(CIPS_0_IF_PS_NOC_NCI_1_AWPROT),
        .S05_AXI_awqos(CIPS_0_IF_PS_NOC_NCI_1_AWQOS),
        .S05_AXI_awready(CIPS_0_IF_PS_NOC_NCI_1_AWREADY),
        .S05_AXI_awregion({1'b0,1'b0,1'b0,1'b0}),
        .S05_AXI_awsize(CIPS_0_IF_PS_NOC_NCI_1_AWSIZE),
        .S05_AXI_awuser(CIPS_0_IF_PS_NOC_NCI_1_AWUSER),
        .S05_AXI_awvalid(CIPS_0_IF_PS_NOC_NCI_1_AWVALID),
        .S05_AXI_bid(CIPS_0_IF_PS_NOC_NCI_1_BID),
        .S05_AXI_bready(CIPS_0_IF_PS_NOC_NCI_1_BREADY),
        .S05_AXI_bresp(CIPS_0_IF_PS_NOC_NCI_1_BRESP),
        .S05_AXI_bvalid(CIPS_0_IF_PS_NOC_NCI_1_BVALID),
        .S05_AXI_rdata(CIPS_0_IF_PS_NOC_NCI_1_RDATA),
        .S05_AXI_rid(CIPS_0_IF_PS_NOC_NCI_1_RID),
        .S05_AXI_rlast(CIPS_0_IF_PS_NOC_NCI_1_RLAST),
        .S05_AXI_rready(CIPS_0_IF_PS_NOC_NCI_1_RREADY),
        .S05_AXI_rresp(CIPS_0_IF_PS_NOC_NCI_1_RRESP),
        .S05_AXI_rvalid(CIPS_0_IF_PS_NOC_NCI_1_RVALID),
        .S05_AXI_wdata(CIPS_0_IF_PS_NOC_NCI_1_WDATA),
        .S05_AXI_wlast(CIPS_0_IF_PS_NOC_NCI_1_WLAST),
        .S05_AXI_wready(CIPS_0_IF_PS_NOC_NCI_1_WREADY),
        .S05_AXI_wstrb(CIPS_0_IF_PS_NOC_NCI_1_WSTRB),
        .S05_AXI_wuser({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .S05_AXI_wvalid(CIPS_0_IF_PS_NOC_NCI_1_WVALID),
        .S06_AXI_araddr(CIPS_0_IF_PS_NOC_RPU_0_ARADDR),
        .S06_AXI_arburst(CIPS_0_IF_PS_NOC_RPU_0_ARBURST),
        .S06_AXI_arcache(CIPS_0_IF_PS_NOC_RPU_0_ARCACHE),
        .S06_AXI_arid(CIPS_0_IF_PS_NOC_RPU_0_ARID),
        .S06_AXI_arlen(CIPS_0_IF_PS_NOC_RPU_0_ARLEN),
        .S06_AXI_arlock(CIPS_0_IF_PS_NOC_RPU_0_ARLOCK),
        .S06_AXI_arprot(CIPS_0_IF_PS_NOC_RPU_0_ARPROT),
        .S06_AXI_arqos(CIPS_0_IF_PS_NOC_RPU_0_ARQOS),
        .S06_AXI_arready(CIPS_0_IF_PS_NOC_RPU_0_ARREADY),
        .S06_AXI_arregion({1'b0,1'b0,1'b0,1'b0}),
        .S06_AXI_arsize(CIPS_0_IF_PS_NOC_RPU_0_ARSIZE),
        .S06_AXI_aruser(CIPS_0_IF_PS_NOC_RPU_0_ARUSER),
        .S06_AXI_arvalid(CIPS_0_IF_PS_NOC_RPU_0_ARVALID),
        .S06_AXI_awaddr(CIPS_0_IF_PS_NOC_RPU_0_AWADDR),
        .S06_AXI_awburst(CIPS_0_IF_PS_NOC_RPU_0_AWBURST),
        .S06_AXI_awcache(CIPS_0_IF_PS_NOC_RPU_0_AWCACHE),
        .S06_AXI_awid(CIPS_0_IF_PS_NOC_RPU_0_AWID),
        .S06_AXI_awlen(CIPS_0_IF_PS_NOC_RPU_0_AWLEN),
        .S06_AXI_awlock(CIPS_0_IF_PS_NOC_RPU_0_AWLOCK),
        .S06_AXI_awprot(CIPS_0_IF_PS_NOC_RPU_0_AWPROT),
        .S06_AXI_awqos(CIPS_0_IF_PS_NOC_RPU_0_AWQOS),
        .S06_AXI_awready(CIPS_0_IF_PS_NOC_RPU_0_AWREADY),
        .S06_AXI_awregion({1'b0,1'b0,1'b0,1'b0}),
        .S06_AXI_awsize(CIPS_0_IF_PS_NOC_RPU_0_AWSIZE),
        .S06_AXI_awuser(CIPS_0_IF_PS_NOC_RPU_0_AWUSER),
        .S06_AXI_awvalid(CIPS_0_IF_PS_NOC_RPU_0_AWVALID),
        .S06_AXI_bid(CIPS_0_IF_PS_NOC_RPU_0_BID),
        .S06_AXI_bready(CIPS_0_IF_PS_NOC_RPU_0_BREADY),
        .S06_AXI_bresp(CIPS_0_IF_PS_NOC_RPU_0_BRESP),
        .S06_AXI_bvalid(CIPS_0_IF_PS_NOC_RPU_0_BVALID),
        .S06_AXI_rdata(CIPS_0_IF_PS_NOC_RPU_0_RDATA),
        .S06_AXI_rid(CIPS_0_IF_PS_NOC_RPU_0_RID),
        .S06_AXI_rlast(CIPS_0_IF_PS_NOC_RPU_0_RLAST),
        .S06_AXI_rready(CIPS_0_IF_PS_NOC_RPU_0_RREADY),
        .S06_AXI_rresp(CIPS_0_IF_PS_NOC_RPU_0_RRESP),
        .S06_AXI_rvalid(CIPS_0_IF_PS_NOC_RPU_0_RVALID),
        .S06_AXI_wdata(CIPS_0_IF_PS_NOC_RPU_0_WDATA),
        .S06_AXI_wlast(CIPS_0_IF_PS_NOC_RPU_0_WLAST),
        .S06_AXI_wready(CIPS_0_IF_PS_NOC_RPU_0_WREADY),
        .S06_AXI_wstrb(CIPS_0_IF_PS_NOC_RPU_0_WSTRB),
        .S06_AXI_wuser({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .S06_AXI_wvalid(CIPS_0_IF_PS_NOC_RPU_0_WVALID),
        .S07_AXI_araddr(CIPS_0_IF_PMC_NOC_AXI_0_ARADDR),
        .S07_AXI_arburst(CIPS_0_IF_PMC_NOC_AXI_0_ARBURST),
        .S07_AXI_arcache(CIPS_0_IF_PMC_NOC_AXI_0_ARCACHE),
        .S07_AXI_arid(CIPS_0_IF_PMC_NOC_AXI_0_ARID),
        .S07_AXI_arlen(CIPS_0_IF_PMC_NOC_AXI_0_ARLEN),
        .S07_AXI_arlock(CIPS_0_IF_PMC_NOC_AXI_0_ARLOCK),
        .S07_AXI_arprot(CIPS_0_IF_PMC_NOC_AXI_0_ARPROT),
        .S07_AXI_arqos(CIPS_0_IF_PMC_NOC_AXI_0_ARQOS),
        .S07_AXI_arready(CIPS_0_IF_PMC_NOC_AXI_0_ARREADY),
        .S07_AXI_arregion(CIPS_0_IF_PMC_NOC_AXI_0_ARREGION),
        .S07_AXI_arsize(CIPS_0_IF_PMC_NOC_AXI_0_ARSIZE),
        .S07_AXI_aruser(CIPS_0_IF_PMC_NOC_AXI_0_ARUSER),
        .S07_AXI_arvalid(CIPS_0_IF_PMC_NOC_AXI_0_ARVALID),
        .S07_AXI_awaddr(CIPS_0_IF_PMC_NOC_AXI_0_AWADDR),
        .S07_AXI_awburst(CIPS_0_IF_PMC_NOC_AXI_0_AWBURST),
        .S07_AXI_awcache(CIPS_0_IF_PMC_NOC_AXI_0_AWCACHE),
        .S07_AXI_awid(CIPS_0_IF_PMC_NOC_AXI_0_AWID),
        .S07_AXI_awlen(CIPS_0_IF_PMC_NOC_AXI_0_AWLEN),
        .S07_AXI_awlock(CIPS_0_IF_PMC_NOC_AXI_0_AWLOCK),
        .S07_AXI_awprot(CIPS_0_IF_PMC_NOC_AXI_0_AWPROT),
        .S07_AXI_awqos(CIPS_0_IF_PMC_NOC_AXI_0_AWQOS),
        .S07_AXI_awready(CIPS_0_IF_PMC_NOC_AXI_0_AWREADY),
        .S07_AXI_awregion(CIPS_0_IF_PMC_NOC_AXI_0_AWREGION),
        .S07_AXI_awsize(CIPS_0_IF_PMC_NOC_AXI_0_AWSIZE),
        .S07_AXI_awuser(CIPS_0_IF_PMC_NOC_AXI_0_AWUSER),
        .S07_AXI_awvalid(CIPS_0_IF_PMC_NOC_AXI_0_AWVALID),
        .S07_AXI_bid(CIPS_0_IF_PMC_NOC_AXI_0_BID),
        .S07_AXI_bready(CIPS_0_IF_PMC_NOC_AXI_0_BREADY),
        .S07_AXI_bresp(CIPS_0_IF_PMC_NOC_AXI_0_BRESP),
        .S07_AXI_buser(CIPS_0_IF_PMC_NOC_AXI_0_BUSER),
        .S07_AXI_bvalid(CIPS_0_IF_PMC_NOC_AXI_0_BVALID),
        .S07_AXI_rdata(CIPS_0_IF_PMC_NOC_AXI_0_RDATA),
        .S07_AXI_rid(CIPS_0_IF_PMC_NOC_AXI_0_RID),
        .S07_AXI_rlast(CIPS_0_IF_PMC_NOC_AXI_0_RLAST),
        .S07_AXI_rready(CIPS_0_IF_PMC_NOC_AXI_0_RREADY),
        .S07_AXI_rresp(CIPS_0_IF_PMC_NOC_AXI_0_RRESP),
        .S07_AXI_ruser(CIPS_0_IF_PMC_NOC_AXI_0_RUSER),
        .S07_AXI_rvalid(CIPS_0_IF_PMC_NOC_AXI_0_RVALID),
        .S07_AXI_wdata(CIPS_0_IF_PMC_NOC_AXI_0_WDATA),
        .S07_AXI_wlast(CIPS_0_IF_PMC_NOC_AXI_0_WLAST),
        .S07_AXI_wready(CIPS_0_IF_PMC_NOC_AXI_0_WREADY),
        .S07_AXI_wstrb(CIPS_0_IF_PMC_NOC_AXI_0_WSTRB),
        .S07_AXI_wuser(CIPS_0_IF_PMC_NOC_AXI_0_WUSER),
        .S07_AXI_wvalid(CIPS_0_IF_PMC_NOC_AXI_0_WVALID),
        .aclk0(clk_wizard_0_clk_out1),
        .aclk1(CIPS_0_ps_ps_noc_cci_axi0_clk),
        .aclk2(CIPS_0_ps_ps_noc_cci_axi1_clk),
        .aclk3(CIPS_0_ps_ps_noc_cci_axi2_clk),
        .aclk4(CIPS_0_ps_ps_noc_cci_axi3_clk),
        .aclk5(CIPS_0_ps_ps_noc_nci_axi0_clk),
        .aclk6(CIPS_0_ps_ps_noc_nci_axi1_clk),
        .aclk7(CIPS_0_ps_ps_noc_rpu_axi0_clk),
        .aclk8(CIPS_0_ps_pmc_noc_axi0_clk),
        .aclk9(ai_engine_0_s00_axi_aclk));
  vitis_design_clk_wizard_0_0 clk_wizard_0
       (.clk_in1(CIPS_0_pl_clk0),
        .clk_out1(clk_wizard_0_clk_out1),
        .clk_out2(clk_wizard_0_clk_out2),
        .clk_out3(clk_wizard_0_clk_out3),
        .clk_out4_o1_ce(xlconstant_0_dout),
        .clk_out4_o1_clr_n(xlconstant_0_dout),
        .clk_out4_o1_o1(clk_wizard_0_clk_out4_o1_o1),
        .clk_out4_o1_o2(clk_wizard_0_clk_out4_o1_o2),
        .clk_out4_o1_o3(clk_wizard_0_clk_out4_o1_o3),
        .clk_out4_o1_o4(clk_wizard_0_clk_out4_o1_o4),
        .locked(clk_wizard_0_locked),
        .resetn(CIPS_0_pl_resetn1));
  vitis_design_dummy_slave_0_0 dummy_slave_0
       (.aclk(clk_wizard_0_clk_out1),
        .aresetn(psr_104mhz_peripheral_aresetn),
        .s_axi_araddr(icn_ctrl_2_M00_AXI_ARADDR),
        .s_axi_arprot(icn_ctrl_2_M00_AXI_ARPROT),
        .s_axi_arready(icn_ctrl_2_M00_AXI_ARREADY),
        .s_axi_arvalid(icn_ctrl_2_M00_AXI_ARVALID),
        .s_axi_awaddr(icn_ctrl_2_M00_AXI_AWADDR),
        .s_axi_awprot(icn_ctrl_2_M00_AXI_AWPROT),
        .s_axi_awready(icn_ctrl_2_M00_AXI_AWREADY),
        .s_axi_awvalid(icn_ctrl_2_M00_AXI_AWVALID),
        .s_axi_bready(icn_ctrl_2_M00_AXI_BREADY),
        .s_axi_bresp(icn_ctrl_2_M00_AXI_BRESP),
        .s_axi_bvalid(icn_ctrl_2_M00_AXI_BVALID),
        .s_axi_rdata(icn_ctrl_2_M00_AXI_RDATA),
        .s_axi_rready(icn_ctrl_2_M00_AXI_RREADY),
        .s_axi_rresp(icn_ctrl_2_M00_AXI_RRESP),
        .s_axi_rvalid(icn_ctrl_2_M00_AXI_RVALID),
        .s_axi_wdata(icn_ctrl_2_M00_AXI_WDATA),
        .s_axi_wready(icn_ctrl_2_M00_AXI_WREADY),
        .s_axi_wstrb(icn_ctrl_2_M00_AXI_WSTRB),
        .s_axi_wvalid(icn_ctrl_2_M00_AXI_WVALID));
  vitis_design_dummy_slave_1_0 dummy_slave_1
       (.aclk(clk_wizard_0_clk_out1),
        .aresetn(psr_104mhz_peripheral_aresetn),
        .s_axi_araddr(icn_ctrl_3_M00_AXI_ARADDR),
        .s_axi_arprot(icn_ctrl_3_M00_AXI_ARPROT),
        .s_axi_arready(icn_ctrl_3_M00_AXI_ARREADY),
        .s_axi_arvalid(icn_ctrl_3_M00_AXI_ARVALID),
        .s_axi_awaddr(icn_ctrl_3_M00_AXI_AWADDR),
        .s_axi_awprot(icn_ctrl_3_M00_AXI_AWPROT),
        .s_axi_awready(icn_ctrl_3_M00_AXI_AWREADY),
        .s_axi_awvalid(icn_ctrl_3_M00_AXI_AWVALID),
        .s_axi_bready(icn_ctrl_3_M00_AXI_BREADY),
        .s_axi_bresp(icn_ctrl_3_M00_AXI_BRESP),
        .s_axi_bvalid(icn_ctrl_3_M00_AXI_BVALID),
        .s_axi_rdata(icn_ctrl_3_M00_AXI_RDATA),
        .s_axi_rready(icn_ctrl_3_M00_AXI_RREADY),
        .s_axi_rresp(icn_ctrl_3_M00_AXI_RRESP),
        .s_axi_rvalid(icn_ctrl_3_M00_AXI_RVALID),
        .s_axi_wdata(icn_ctrl_3_M00_AXI_WDATA),
        .s_axi_wready(icn_ctrl_3_M00_AXI_WREADY),
        .s_axi_wstrb(icn_ctrl_3_M00_AXI_WSTRB),
        .s_axi_wvalid(icn_ctrl_3_M00_AXI_WVALID));
  vitis_design_dummy_slave_2_0 dummy_slave_2
       (.aclk(clk_wizard_0_clk_out1),
        .aresetn(psr_104mhz_peripheral_aresetn),
        .s_axi_araddr(icn_ctrl_4_M00_AXI_ARADDR),
        .s_axi_arprot(icn_ctrl_4_M00_AXI_ARPROT),
        .s_axi_arready(icn_ctrl_4_M00_AXI_ARREADY),
        .s_axi_arvalid(icn_ctrl_4_M00_AXI_ARVALID),
        .s_axi_awaddr(icn_ctrl_4_M00_AXI_AWADDR),
        .s_axi_awprot(icn_ctrl_4_M00_AXI_AWPROT),
        .s_axi_awready(icn_ctrl_4_M00_AXI_AWREADY),
        .s_axi_awvalid(icn_ctrl_4_M00_AXI_AWVALID),
        .s_axi_bready(icn_ctrl_4_M00_AXI_BREADY),
        .s_axi_bresp(icn_ctrl_4_M00_AXI_BRESP),
        .s_axi_bvalid(icn_ctrl_4_M00_AXI_BVALID),
        .s_axi_rdata(icn_ctrl_4_M00_AXI_RDATA),
        .s_axi_rready(icn_ctrl_4_M00_AXI_RREADY),
        .s_axi_rresp(icn_ctrl_4_M00_AXI_RRESP),
        .s_axi_rvalid(icn_ctrl_4_M00_AXI_RVALID),
        .s_axi_wdata(icn_ctrl_4_M00_AXI_WDATA),
        .s_axi_wready(icn_ctrl_4_M00_AXI_WREADY),
        .s_axi_wstrb(icn_ctrl_4_M00_AXI_WSTRB),
        .s_axi_wvalid(icn_ctrl_4_M00_AXI_WVALID));
  vitis_design_dummy_slave_3_0 dummy_slave_3
       (.aclk(clk_wizard_0_clk_out1),
        .aresetn(psr_104mhz_peripheral_aresetn),
        .s_axi_araddr(icn_ctrl_5_M00_AXI_ARADDR),
        .s_axi_arprot(icn_ctrl_5_M00_AXI_ARPROT),
        .s_axi_arready(icn_ctrl_5_M00_AXI_ARREADY),
        .s_axi_arvalid(icn_ctrl_5_M00_AXI_ARVALID),
        .s_axi_awaddr(icn_ctrl_5_M00_AXI_AWADDR),
        .s_axi_awprot(icn_ctrl_5_M00_AXI_AWPROT),
        .s_axi_awready(icn_ctrl_5_M00_AXI_AWREADY),
        .s_axi_awvalid(icn_ctrl_5_M00_AXI_AWVALID),
        .s_axi_bready(icn_ctrl_5_M00_AXI_BREADY),
        .s_axi_bresp(icn_ctrl_5_M00_AXI_BRESP),
        .s_axi_bvalid(icn_ctrl_5_M00_AXI_BVALID),
        .s_axi_rdata(icn_ctrl_5_M00_AXI_RDATA),
        .s_axi_rready(icn_ctrl_5_M00_AXI_RREADY),
        .s_axi_rresp(icn_ctrl_5_M00_AXI_RRESP),
        .s_axi_rvalid(icn_ctrl_5_M00_AXI_RVALID),
        .s_axi_wdata(icn_ctrl_5_M00_AXI_WDATA),
        .s_axi_wready(icn_ctrl_5_M00_AXI_WREADY),
        .s_axi_wstrb(icn_ctrl_5_M00_AXI_WSTRB),
        .s_axi_wvalid(icn_ctrl_5_M00_AXI_WVALID));
  vitis_design_icn_ctrl_1_0 icn_ctrl_1
       (.M00_AXI_araddr(icn_ctrl_1_M00_AXI_ARADDR),
        .M00_AXI_arready(icn_ctrl_1_M00_AXI_ARREADY),
        .M00_AXI_arvalid(icn_ctrl_1_M00_AXI_ARVALID),
        .M00_AXI_awaddr(icn_ctrl_1_M00_AXI_AWADDR),
        .M00_AXI_awready(icn_ctrl_1_M00_AXI_AWREADY),
        .M00_AXI_awvalid(icn_ctrl_1_M00_AXI_AWVALID),
        .M00_AXI_bready(icn_ctrl_1_M00_AXI_BREADY),
        .M00_AXI_bresp(icn_ctrl_1_M00_AXI_BRESP),
        .M00_AXI_bvalid(icn_ctrl_1_M00_AXI_BVALID),
        .M00_AXI_rdata(icn_ctrl_1_M00_AXI_RDATA),
        .M00_AXI_rready(icn_ctrl_1_M00_AXI_RREADY),
        .M00_AXI_rresp(icn_ctrl_1_M00_AXI_RRESP),
        .M00_AXI_rvalid(icn_ctrl_1_M00_AXI_RVALID),
        .M00_AXI_wdata(icn_ctrl_1_M00_AXI_WDATA),
        .M00_AXI_wready(icn_ctrl_1_M00_AXI_WREADY),
        .M00_AXI_wstrb(icn_ctrl_1_M00_AXI_WSTRB),
        .M00_AXI_wvalid(icn_ctrl_1_M00_AXI_WVALID),
        .M01_AXI_araddr(icn_ctrl_1_M01_AXI_ARADDR),
        .M01_AXI_arready(icn_ctrl_1_M01_AXI_ARREADY),
        .M01_AXI_arvalid(icn_ctrl_1_M01_AXI_ARVALID),
        .M01_AXI_awaddr(icn_ctrl_1_M01_AXI_AWADDR),
        .M01_AXI_awready(icn_ctrl_1_M01_AXI_AWREADY),
        .M01_AXI_awvalid(icn_ctrl_1_M01_AXI_AWVALID),
        .M01_AXI_bready(icn_ctrl_1_M01_AXI_BREADY),
        .M01_AXI_bresp(icn_ctrl_1_M01_AXI_BRESP),
        .M01_AXI_bvalid(icn_ctrl_1_M01_AXI_BVALID),
        .M01_AXI_rdata(icn_ctrl_1_M01_AXI_RDATA),
        .M01_AXI_rready(icn_ctrl_1_M01_AXI_RREADY),
        .M01_AXI_rresp(icn_ctrl_1_M01_AXI_RRESP),
        .M01_AXI_rvalid(icn_ctrl_1_M01_AXI_RVALID),
        .M01_AXI_wdata(icn_ctrl_1_M01_AXI_WDATA),
        .M01_AXI_wready(icn_ctrl_1_M01_AXI_WREADY),
        .M01_AXI_wstrb(icn_ctrl_1_M01_AXI_WSTRB),
        .M01_AXI_wvalid(icn_ctrl_1_M01_AXI_WVALID),
        .M02_AXI_araddr(icn_ctrl_1_M02_AXI_ARADDR),
        .M02_AXI_arburst(icn_ctrl_1_M02_AXI_ARBURST),
        .M02_AXI_arcache(icn_ctrl_1_M02_AXI_ARCACHE),
        .M02_AXI_arid(icn_ctrl_1_M02_AXI_ARID),
        .M02_AXI_arlen(icn_ctrl_1_M02_AXI_ARLEN),
        .M02_AXI_arlock(icn_ctrl_1_M02_AXI_ARLOCK),
        .M02_AXI_arprot(icn_ctrl_1_M02_AXI_ARPROT),
        .M02_AXI_arqos(icn_ctrl_1_M02_AXI_ARQOS),
        .M02_AXI_arready(icn_ctrl_1_M02_AXI_ARREADY),
        .M02_AXI_arsize(icn_ctrl_1_M02_AXI_ARSIZE),
        .M02_AXI_aruser(icn_ctrl_1_M02_AXI_ARUSER),
        .M02_AXI_arvalid(icn_ctrl_1_M02_AXI_ARVALID),
        .M02_AXI_awaddr(icn_ctrl_1_M02_AXI_AWADDR),
        .M02_AXI_awburst(icn_ctrl_1_M02_AXI_AWBURST),
        .M02_AXI_awcache(icn_ctrl_1_M02_AXI_AWCACHE),
        .M02_AXI_awid(icn_ctrl_1_M02_AXI_AWID),
        .M02_AXI_awlen(icn_ctrl_1_M02_AXI_AWLEN),
        .M02_AXI_awlock(icn_ctrl_1_M02_AXI_AWLOCK),
        .M02_AXI_awprot(icn_ctrl_1_M02_AXI_AWPROT),
        .M02_AXI_awqos(icn_ctrl_1_M02_AXI_AWQOS),
        .M02_AXI_awready(icn_ctrl_1_M02_AXI_AWREADY),
        .M02_AXI_awsize(icn_ctrl_1_M02_AXI_AWSIZE),
        .M02_AXI_awuser(icn_ctrl_1_M02_AXI_AWUSER),
        .M02_AXI_awvalid(icn_ctrl_1_M02_AXI_AWVALID),
        .M02_AXI_bid(icn_ctrl_1_M02_AXI_BID),
        .M02_AXI_bready(icn_ctrl_1_M02_AXI_BREADY),
        .M02_AXI_bresp(icn_ctrl_1_M02_AXI_BRESP),
        .M02_AXI_bvalid(icn_ctrl_1_M02_AXI_BVALID),
        .M02_AXI_rdata(icn_ctrl_1_M02_AXI_RDATA),
        .M02_AXI_rid(icn_ctrl_1_M02_AXI_RID),
        .M02_AXI_rlast(icn_ctrl_1_M02_AXI_RLAST),
        .M02_AXI_rready(icn_ctrl_1_M02_AXI_RREADY),
        .M02_AXI_rresp(icn_ctrl_1_M02_AXI_RRESP),
        .M02_AXI_ruser(icn_ctrl_1_M02_AXI_RUSER),
        .M02_AXI_rvalid(icn_ctrl_1_M02_AXI_RVALID),
        .M02_AXI_wdata(icn_ctrl_1_M02_AXI_WDATA),
        .M02_AXI_wlast(icn_ctrl_1_M02_AXI_WLAST),
        .M02_AXI_wready(icn_ctrl_1_M02_AXI_WREADY),
        .M02_AXI_wstrb(icn_ctrl_1_M02_AXI_WSTRB),
        .M02_AXI_wuser(icn_ctrl_1_M02_AXI_WUSER),
        .M02_AXI_wvalid(icn_ctrl_1_M02_AXI_WVALID),
        .M03_AXI_araddr(icn_ctrl_1_M03_AXI_ARADDR),
        .M03_AXI_arburst(icn_ctrl_1_M03_AXI_ARBURST),
        .M03_AXI_arcache(icn_ctrl_1_M03_AXI_ARCACHE),
        .M03_AXI_arid(icn_ctrl_1_M03_AXI_ARID),
        .M03_AXI_arlen(icn_ctrl_1_M03_AXI_ARLEN),
        .M03_AXI_arlock(icn_ctrl_1_M03_AXI_ARLOCK),
        .M03_AXI_arprot(icn_ctrl_1_M03_AXI_ARPROT),
        .M03_AXI_arqos(icn_ctrl_1_M03_AXI_ARQOS),
        .M03_AXI_arready(icn_ctrl_1_M03_AXI_ARREADY),
        .M03_AXI_arsize(icn_ctrl_1_M03_AXI_ARSIZE),
        .M03_AXI_aruser(icn_ctrl_1_M03_AXI_ARUSER),
        .M03_AXI_arvalid(icn_ctrl_1_M03_AXI_ARVALID),
        .M03_AXI_awaddr(icn_ctrl_1_M03_AXI_AWADDR),
        .M03_AXI_awburst(icn_ctrl_1_M03_AXI_AWBURST),
        .M03_AXI_awcache(icn_ctrl_1_M03_AXI_AWCACHE),
        .M03_AXI_awid(icn_ctrl_1_M03_AXI_AWID),
        .M03_AXI_awlen(icn_ctrl_1_M03_AXI_AWLEN),
        .M03_AXI_awlock(icn_ctrl_1_M03_AXI_AWLOCK),
        .M03_AXI_awprot(icn_ctrl_1_M03_AXI_AWPROT),
        .M03_AXI_awqos(icn_ctrl_1_M03_AXI_AWQOS),
        .M03_AXI_awready(icn_ctrl_1_M03_AXI_AWREADY),
        .M03_AXI_awsize(icn_ctrl_1_M03_AXI_AWSIZE),
        .M03_AXI_awuser(icn_ctrl_1_M03_AXI_AWUSER),
        .M03_AXI_awvalid(icn_ctrl_1_M03_AXI_AWVALID),
        .M03_AXI_bid(icn_ctrl_1_M03_AXI_BID),
        .M03_AXI_bready(icn_ctrl_1_M03_AXI_BREADY),
        .M03_AXI_bresp(icn_ctrl_1_M03_AXI_BRESP),
        .M03_AXI_bvalid(icn_ctrl_1_M03_AXI_BVALID),
        .M03_AXI_rdata(icn_ctrl_1_M03_AXI_RDATA),
        .M03_AXI_rid(icn_ctrl_1_M03_AXI_RID),
        .M03_AXI_rlast(icn_ctrl_1_M03_AXI_RLAST),
        .M03_AXI_rready(icn_ctrl_1_M03_AXI_RREADY),
        .M03_AXI_rresp(icn_ctrl_1_M03_AXI_RRESP),
        .M03_AXI_ruser(icn_ctrl_1_M03_AXI_RUSER),
        .M03_AXI_rvalid(icn_ctrl_1_M03_AXI_RVALID),
        .M03_AXI_wdata(icn_ctrl_1_M03_AXI_WDATA),
        .M03_AXI_wlast(icn_ctrl_1_M03_AXI_WLAST),
        .M03_AXI_wready(icn_ctrl_1_M03_AXI_WREADY),
        .M03_AXI_wstrb(icn_ctrl_1_M03_AXI_WSTRB),
        .M03_AXI_wuser(icn_ctrl_1_M03_AXI_WUSER),
        .M03_AXI_wvalid(icn_ctrl_1_M03_AXI_WVALID),
        .M04_AXI_araddr(icn_ctrl_1_M04_AXI_ARADDR),
        .M04_AXI_arburst(icn_ctrl_1_M04_AXI_ARBURST),
        .M04_AXI_arcache(icn_ctrl_1_M04_AXI_ARCACHE),
        .M04_AXI_arid(icn_ctrl_1_M04_AXI_ARID),
        .M04_AXI_arlen(icn_ctrl_1_M04_AXI_ARLEN),
        .M04_AXI_arlock(icn_ctrl_1_M04_AXI_ARLOCK),
        .M04_AXI_arprot(icn_ctrl_1_M04_AXI_ARPROT),
        .M04_AXI_arqos(icn_ctrl_1_M04_AXI_ARQOS),
        .M04_AXI_arready(icn_ctrl_1_M04_AXI_ARREADY),
        .M04_AXI_arsize(icn_ctrl_1_M04_AXI_ARSIZE),
        .M04_AXI_aruser(icn_ctrl_1_M04_AXI_ARUSER),
        .M04_AXI_arvalid(icn_ctrl_1_M04_AXI_ARVALID),
        .M04_AXI_awaddr(icn_ctrl_1_M04_AXI_AWADDR),
        .M04_AXI_awburst(icn_ctrl_1_M04_AXI_AWBURST),
        .M04_AXI_awcache(icn_ctrl_1_M04_AXI_AWCACHE),
        .M04_AXI_awid(icn_ctrl_1_M04_AXI_AWID),
        .M04_AXI_awlen(icn_ctrl_1_M04_AXI_AWLEN),
        .M04_AXI_awlock(icn_ctrl_1_M04_AXI_AWLOCK),
        .M04_AXI_awprot(icn_ctrl_1_M04_AXI_AWPROT),
        .M04_AXI_awqos(icn_ctrl_1_M04_AXI_AWQOS),
        .M04_AXI_awready(icn_ctrl_1_M04_AXI_AWREADY),
        .M04_AXI_awsize(icn_ctrl_1_M04_AXI_AWSIZE),
        .M04_AXI_awuser(icn_ctrl_1_M04_AXI_AWUSER),
        .M04_AXI_awvalid(icn_ctrl_1_M04_AXI_AWVALID),
        .M04_AXI_bid(icn_ctrl_1_M04_AXI_BID),
        .M04_AXI_bready(icn_ctrl_1_M04_AXI_BREADY),
        .M04_AXI_bresp(icn_ctrl_1_M04_AXI_BRESP),
        .M04_AXI_bvalid(icn_ctrl_1_M04_AXI_BVALID),
        .M04_AXI_rdata(icn_ctrl_1_M04_AXI_RDATA),
        .M04_AXI_rid(icn_ctrl_1_M04_AXI_RID),
        .M04_AXI_rlast(icn_ctrl_1_M04_AXI_RLAST),
        .M04_AXI_rready(icn_ctrl_1_M04_AXI_RREADY),
        .M04_AXI_rresp(icn_ctrl_1_M04_AXI_RRESP),
        .M04_AXI_ruser(icn_ctrl_1_M04_AXI_RUSER),
        .M04_AXI_rvalid(icn_ctrl_1_M04_AXI_RVALID),
        .M04_AXI_wdata(icn_ctrl_1_M04_AXI_WDATA),
        .M04_AXI_wlast(icn_ctrl_1_M04_AXI_WLAST),
        .M04_AXI_wready(icn_ctrl_1_M04_AXI_WREADY),
        .M04_AXI_wstrb(icn_ctrl_1_M04_AXI_WSTRB),
        .M04_AXI_wuser(icn_ctrl_1_M04_AXI_WUSER),
        .M04_AXI_wvalid(icn_ctrl_1_M04_AXI_WVALID),
        .M05_AXI_araddr(icn_ctrl_1_M05_AXI_ARADDR),
        .M05_AXI_arburst(icn_ctrl_1_M05_AXI_ARBURST),
        .M05_AXI_arcache(icn_ctrl_1_M05_AXI_ARCACHE),
        .M05_AXI_arid(icn_ctrl_1_M05_AXI_ARID),
        .M05_AXI_arlen(icn_ctrl_1_M05_AXI_ARLEN),
        .M05_AXI_arlock(icn_ctrl_1_M05_AXI_ARLOCK),
        .M05_AXI_arprot(icn_ctrl_1_M05_AXI_ARPROT),
        .M05_AXI_arqos(icn_ctrl_1_M05_AXI_ARQOS),
        .M05_AXI_arready(icn_ctrl_1_M05_AXI_ARREADY),
        .M05_AXI_arsize(icn_ctrl_1_M05_AXI_ARSIZE),
        .M05_AXI_aruser(icn_ctrl_1_M05_AXI_ARUSER),
        .M05_AXI_arvalid(icn_ctrl_1_M05_AXI_ARVALID),
        .M05_AXI_awaddr(icn_ctrl_1_M05_AXI_AWADDR),
        .M05_AXI_awburst(icn_ctrl_1_M05_AXI_AWBURST),
        .M05_AXI_awcache(icn_ctrl_1_M05_AXI_AWCACHE),
        .M05_AXI_awid(icn_ctrl_1_M05_AXI_AWID),
        .M05_AXI_awlen(icn_ctrl_1_M05_AXI_AWLEN),
        .M05_AXI_awlock(icn_ctrl_1_M05_AXI_AWLOCK),
        .M05_AXI_awprot(icn_ctrl_1_M05_AXI_AWPROT),
        .M05_AXI_awqos(icn_ctrl_1_M05_AXI_AWQOS),
        .M05_AXI_awready(icn_ctrl_1_M05_AXI_AWREADY),
        .M05_AXI_awsize(icn_ctrl_1_M05_AXI_AWSIZE),
        .M05_AXI_awuser(icn_ctrl_1_M05_AXI_AWUSER),
        .M05_AXI_awvalid(icn_ctrl_1_M05_AXI_AWVALID),
        .M05_AXI_bid(icn_ctrl_1_M05_AXI_BID),
        .M05_AXI_bready(icn_ctrl_1_M05_AXI_BREADY),
        .M05_AXI_bresp(icn_ctrl_1_M05_AXI_BRESP),
        .M05_AXI_bvalid(icn_ctrl_1_M05_AXI_BVALID),
        .M05_AXI_rdata(icn_ctrl_1_M05_AXI_RDATA),
        .M05_AXI_rid(icn_ctrl_1_M05_AXI_RID),
        .M05_AXI_rlast(icn_ctrl_1_M05_AXI_RLAST),
        .M05_AXI_rready(icn_ctrl_1_M05_AXI_RREADY),
        .M05_AXI_rresp(icn_ctrl_1_M05_AXI_RRESP),
        .M05_AXI_ruser(icn_ctrl_1_M05_AXI_RUSER),
        .M05_AXI_rvalid(icn_ctrl_1_M05_AXI_RVALID),
        .M05_AXI_wdata(icn_ctrl_1_M05_AXI_WDATA),
        .M05_AXI_wlast(icn_ctrl_1_M05_AXI_WLAST),
        .M05_AXI_wready(icn_ctrl_1_M05_AXI_WREADY),
        .M05_AXI_wstrb(icn_ctrl_1_M05_AXI_WSTRB),
        .M05_AXI_wuser(icn_ctrl_1_M05_AXI_WUSER),
        .M05_AXI_wvalid(icn_ctrl_1_M05_AXI_WVALID),
        .M06_AXI_araddr(icn_ctrl_1_M06_AXI_ARADDR),
        .M06_AXI_arprot(icn_ctrl_1_M06_AXI_ARPROT),
        .M06_AXI_arready(icn_ctrl_1_M06_AXI_ARREADY),
        .M06_AXI_arvalid(icn_ctrl_1_M06_AXI_ARVALID),
        .M06_AXI_awaddr(icn_ctrl_1_M06_AXI_AWADDR),
        .M06_AXI_awprot(icn_ctrl_1_M06_AXI_AWPROT),
        .M06_AXI_awready(icn_ctrl_1_M06_AXI_AWREADY),
        .M06_AXI_awvalid(icn_ctrl_1_M06_AXI_AWVALID),
        .M06_AXI_bready(icn_ctrl_1_M06_AXI_BREADY),
        .M06_AXI_bresp(icn_ctrl_1_M06_AXI_BRESP),
        .M06_AXI_bvalid(icn_ctrl_1_M06_AXI_BVALID),
        .M06_AXI_rdata(icn_ctrl_1_M06_AXI_RDATA),
        .M06_AXI_rready(icn_ctrl_1_M06_AXI_RREADY),
        .M06_AXI_rresp(icn_ctrl_1_M06_AXI_RRESP),
        .M06_AXI_rvalid(icn_ctrl_1_M06_AXI_RVALID),
        .M06_AXI_wdata(icn_ctrl_1_M06_AXI_WDATA),
        .M06_AXI_wready(icn_ctrl_1_M06_AXI_WREADY),
        .M06_AXI_wstrb(icn_ctrl_1_M06_AXI_WSTRB),
        .M06_AXI_wvalid(icn_ctrl_1_M06_AXI_WVALID),
        .M07_AXI_araddr(icn_ctrl_1_M07_AXI_ARADDR),
        .M07_AXI_arprot(icn_ctrl_1_M07_AXI_ARPROT),
        .M07_AXI_arready(icn_ctrl_1_M07_AXI_ARREADY),
        .M07_AXI_arvalid(icn_ctrl_1_M07_AXI_ARVALID),
        .M07_AXI_awaddr(icn_ctrl_1_M07_AXI_AWADDR),
        .M07_AXI_awprot(icn_ctrl_1_M07_AXI_AWPROT),
        .M07_AXI_awready(icn_ctrl_1_M07_AXI_AWREADY),
        .M07_AXI_awvalid(icn_ctrl_1_M07_AXI_AWVALID),
        .M07_AXI_bready(icn_ctrl_1_M07_AXI_BREADY),
        .M07_AXI_bresp(icn_ctrl_1_M07_AXI_BRESP),
        .M07_AXI_bvalid(icn_ctrl_1_M07_AXI_BVALID),
        .M07_AXI_rdata(icn_ctrl_1_M07_AXI_RDATA),
        .M07_AXI_rready(icn_ctrl_1_M07_AXI_RREADY),
        .M07_AXI_rresp(icn_ctrl_1_M07_AXI_RRESP),
        .M07_AXI_rvalid(icn_ctrl_1_M07_AXI_RVALID),
        .M07_AXI_wdata(icn_ctrl_1_M07_AXI_WDATA),
        .M07_AXI_wready(icn_ctrl_1_M07_AXI_WREADY),
        .M07_AXI_wstrb(icn_ctrl_1_M07_AXI_WSTRB),
        .M07_AXI_wvalid(icn_ctrl_1_M07_AXI_WVALID),
        .M08_AXI_araddr(icn_ctrl_1_M08_AXI_ARADDR),
        .M08_AXI_arprot(icn_ctrl_1_M08_AXI_ARPROT),
        .M08_AXI_arready(icn_ctrl_1_M08_AXI_ARREADY),
        .M08_AXI_arvalid(icn_ctrl_1_M08_AXI_ARVALID),
        .M08_AXI_awaddr(icn_ctrl_1_M08_AXI_AWADDR),
        .M08_AXI_awprot(icn_ctrl_1_M08_AXI_AWPROT),
        .M08_AXI_awready(icn_ctrl_1_M08_AXI_AWREADY),
        .M08_AXI_awvalid(icn_ctrl_1_M08_AXI_AWVALID),
        .M08_AXI_bready(icn_ctrl_1_M08_AXI_BREADY),
        .M08_AXI_bresp(icn_ctrl_1_M08_AXI_BRESP),
        .M08_AXI_bvalid(icn_ctrl_1_M08_AXI_BVALID),
        .M08_AXI_rdata(icn_ctrl_1_M08_AXI_RDATA),
        .M08_AXI_rready(icn_ctrl_1_M08_AXI_RREADY),
        .M08_AXI_rresp(icn_ctrl_1_M08_AXI_RRESP),
        .M08_AXI_rvalid(icn_ctrl_1_M08_AXI_RVALID),
        .M08_AXI_wdata(icn_ctrl_1_M08_AXI_WDATA),
        .M08_AXI_wready(icn_ctrl_1_M08_AXI_WREADY),
        .M08_AXI_wstrb(icn_ctrl_1_M08_AXI_WSTRB),
        .M08_AXI_wvalid(icn_ctrl_1_M08_AXI_WVALID),
        .M09_AXI_araddr(icn_ctrl_1_M09_AXI_ARADDR),
        .M09_AXI_arburst(icn_ctrl_1_M09_AXI_ARBURST),
        .M09_AXI_arcache(icn_ctrl_1_M09_AXI_ARCACHE),
        .M09_AXI_arid(icn_ctrl_1_M09_AXI_ARID),
        .M09_AXI_arlen(icn_ctrl_1_M09_AXI_ARLEN),
        .M09_AXI_arlock(icn_ctrl_1_M09_AXI_ARLOCK),
        .M09_AXI_arprot(icn_ctrl_1_M09_AXI_ARPROT),
        .M09_AXI_arqos(icn_ctrl_1_M09_AXI_ARQOS),
        .M09_AXI_arready(icn_ctrl_1_M09_AXI_ARREADY),
        .M09_AXI_arsize(icn_ctrl_1_M09_AXI_ARSIZE),
        .M09_AXI_aruser(icn_ctrl_1_M09_AXI_ARUSER),
        .M09_AXI_arvalid(icn_ctrl_1_M09_AXI_ARVALID),
        .M09_AXI_awaddr(icn_ctrl_1_M09_AXI_AWADDR),
        .M09_AXI_awburst(icn_ctrl_1_M09_AXI_AWBURST),
        .M09_AXI_awcache(icn_ctrl_1_M09_AXI_AWCACHE),
        .M09_AXI_awid(icn_ctrl_1_M09_AXI_AWID),
        .M09_AXI_awlen(icn_ctrl_1_M09_AXI_AWLEN),
        .M09_AXI_awlock(icn_ctrl_1_M09_AXI_AWLOCK),
        .M09_AXI_awprot(icn_ctrl_1_M09_AXI_AWPROT),
        .M09_AXI_awqos(icn_ctrl_1_M09_AXI_AWQOS),
        .M09_AXI_awready(icn_ctrl_1_M09_AXI_AWREADY),
        .M09_AXI_awsize(icn_ctrl_1_M09_AXI_AWSIZE),
        .M09_AXI_awuser(icn_ctrl_1_M09_AXI_AWUSER),
        .M09_AXI_awvalid(icn_ctrl_1_M09_AXI_AWVALID),
        .M09_AXI_bid(icn_ctrl_1_M09_AXI_BID),
        .M09_AXI_bready(icn_ctrl_1_M09_AXI_BREADY),
        .M09_AXI_bresp(icn_ctrl_1_M09_AXI_BRESP),
        .M09_AXI_bvalid(icn_ctrl_1_M09_AXI_BVALID),
        .M09_AXI_rdata(icn_ctrl_1_M09_AXI_RDATA),
        .M09_AXI_rid(icn_ctrl_1_M09_AXI_RID),
        .M09_AXI_rlast(icn_ctrl_1_M09_AXI_RLAST),
        .M09_AXI_rready(icn_ctrl_1_M09_AXI_RREADY),
        .M09_AXI_rresp(icn_ctrl_1_M09_AXI_RRESP),
        .M09_AXI_ruser(icn_ctrl_1_M09_AXI_RUSER),
        .M09_AXI_rvalid(icn_ctrl_1_M09_AXI_RVALID),
        .M09_AXI_wdata(icn_ctrl_1_M09_AXI_WDATA),
        .M09_AXI_wlast(icn_ctrl_1_M09_AXI_WLAST),
        .M09_AXI_wready(icn_ctrl_1_M09_AXI_WREADY),
        .M09_AXI_wstrb(icn_ctrl_1_M09_AXI_WSTRB),
        .M09_AXI_wuser(icn_ctrl_1_M09_AXI_WUSER),
        .M09_AXI_wvalid(icn_ctrl_1_M09_AXI_WVALID),
        .M10_AXI_araddr(icn_ctrl_1_M10_AXI_ARADDR),
        .M10_AXI_arburst(icn_ctrl_1_M10_AXI_ARBURST),
        .M10_AXI_arlen(icn_ctrl_1_M10_AXI_ARLEN),
        .M10_AXI_arready(icn_ctrl_1_M10_AXI_ARREADY),
        .M10_AXI_arsize(icn_ctrl_1_M10_AXI_ARSIZE),
        .M10_AXI_arvalid(icn_ctrl_1_M10_AXI_ARVALID),
        .M10_AXI_awaddr(icn_ctrl_1_M10_AXI_AWADDR),
        .M10_AXI_awburst(icn_ctrl_1_M10_AXI_AWBURST),
        .M10_AXI_awlen(icn_ctrl_1_M10_AXI_AWLEN),
        .M10_AXI_awready(icn_ctrl_1_M10_AXI_AWREADY),
        .M10_AXI_awsize(icn_ctrl_1_M10_AXI_AWSIZE),
        .M10_AXI_awvalid(icn_ctrl_1_M10_AXI_AWVALID),
        .M10_AXI_bready(icn_ctrl_1_M10_AXI_BREADY),
        .M10_AXI_bresp(icn_ctrl_1_M10_AXI_BRESP),
        .M10_AXI_bvalid(icn_ctrl_1_M10_AXI_BVALID),
        .M10_AXI_rdata(icn_ctrl_1_M10_AXI_RDATA),
        .M10_AXI_rlast(icn_ctrl_1_M10_AXI_RLAST),
        .M10_AXI_rready(icn_ctrl_1_M10_AXI_RREADY),
        .M10_AXI_rresp(icn_ctrl_1_M10_AXI_RRESP),
        .M10_AXI_rvalid(icn_ctrl_1_M10_AXI_RVALID),
        .M10_AXI_wdata(icn_ctrl_1_M10_AXI_WDATA),
        .M10_AXI_wlast(icn_ctrl_1_M10_AXI_WLAST),
        .M10_AXI_wready(icn_ctrl_1_M10_AXI_WREADY),
        .M10_AXI_wstrb(icn_ctrl_1_M10_AXI_WSTRB),
        .M10_AXI_wvalid(icn_ctrl_1_M10_AXI_WVALID),
        .S00_AXI_araddr(CIPS_0_M_AXI_GP0_ARADDR),
        .S00_AXI_arburst(CIPS_0_M_AXI_GP0_ARBURST),
        .S00_AXI_arcache(CIPS_0_M_AXI_GP0_ARCACHE),
        .S00_AXI_arid(CIPS_0_M_AXI_GP0_ARID),
        .S00_AXI_arlen(CIPS_0_M_AXI_GP0_ARLEN),
        .S00_AXI_arlock(CIPS_0_M_AXI_GP0_ARLOCK),
        .S00_AXI_arprot(CIPS_0_M_AXI_GP0_ARPROT),
        .S00_AXI_arqos(CIPS_0_M_AXI_GP0_ARQOS),
        .S00_AXI_arready(CIPS_0_M_AXI_GP0_ARREADY),
        .S00_AXI_arsize(CIPS_0_M_AXI_GP0_ARSIZE),
        .S00_AXI_aruser(CIPS_0_M_AXI_GP0_ARUSER),
        .S00_AXI_arvalid(CIPS_0_M_AXI_GP0_ARVALID),
        .S00_AXI_awaddr(CIPS_0_M_AXI_GP0_AWADDR),
        .S00_AXI_awburst(CIPS_0_M_AXI_GP0_AWBURST),
        .S00_AXI_awcache(CIPS_0_M_AXI_GP0_AWCACHE),
        .S00_AXI_awid(CIPS_0_M_AXI_GP0_AWID),
        .S00_AXI_awlen(CIPS_0_M_AXI_GP0_AWLEN),
        .S00_AXI_awlock(CIPS_0_M_AXI_GP0_AWLOCK),
        .S00_AXI_awprot(CIPS_0_M_AXI_GP0_AWPROT),
        .S00_AXI_awqos(CIPS_0_M_AXI_GP0_AWQOS),
        .S00_AXI_awready(CIPS_0_M_AXI_GP0_AWREADY),
        .S00_AXI_awsize(CIPS_0_M_AXI_GP0_AWSIZE),
        .S00_AXI_awuser(CIPS_0_M_AXI_GP0_AWUSER),
        .S00_AXI_awvalid(CIPS_0_M_AXI_GP0_AWVALID),
        .S00_AXI_bid(CIPS_0_M_AXI_GP0_BID),
        .S00_AXI_bready(CIPS_0_M_AXI_GP0_BREADY),
        .S00_AXI_bresp(CIPS_0_M_AXI_GP0_BRESP),
        .S00_AXI_bvalid(CIPS_0_M_AXI_GP0_BVALID),
        .S00_AXI_rdata(CIPS_0_M_AXI_GP0_RDATA),
        .S00_AXI_rid(CIPS_0_M_AXI_GP0_RID),
        .S00_AXI_rlast(CIPS_0_M_AXI_GP0_RLAST),
        .S00_AXI_rready(CIPS_0_M_AXI_GP0_RREADY),
        .S00_AXI_rresp(CIPS_0_M_AXI_GP0_RRESP),
        .S00_AXI_rvalid(CIPS_0_M_AXI_GP0_RVALID),
        .S00_AXI_wdata(CIPS_0_M_AXI_GP0_WDATA),
        .S00_AXI_wlast(CIPS_0_M_AXI_GP0_WLAST),
        .S00_AXI_wready(CIPS_0_M_AXI_GP0_WREADY),
        .S00_AXI_wstrb(CIPS_0_M_AXI_GP0_WSTRB),
        .S00_AXI_wvalid(CIPS_0_M_AXI_GP0_WVALID),
        .aclk(clk_wizard_0_clk_out1),
        .aclk1(clk_wizard_0_clk_out1),
        .aclk2(VitisRegion_aclk_bypass_m),
        .aresetn(psr_104mhz_peripheral_aresetn));
  vitis_design_icn_ctrl_2_0 icn_ctrl_2
       (.M00_AXI_araddr(icn_ctrl_2_M00_AXI_ARADDR),
        .M00_AXI_arprot(icn_ctrl_2_M00_AXI_ARPROT),
        .M00_AXI_arready(icn_ctrl_2_M00_AXI_ARREADY),
        .M00_AXI_arvalid(icn_ctrl_2_M00_AXI_ARVALID),
        .M00_AXI_awaddr(icn_ctrl_2_M00_AXI_AWADDR),
        .M00_AXI_awprot(icn_ctrl_2_M00_AXI_AWPROT),
        .M00_AXI_awready(icn_ctrl_2_M00_AXI_AWREADY),
        .M00_AXI_awvalid(icn_ctrl_2_M00_AXI_AWVALID),
        .M00_AXI_bready(icn_ctrl_2_M00_AXI_BREADY),
        .M00_AXI_bresp(icn_ctrl_2_M00_AXI_BRESP),
        .M00_AXI_bvalid(icn_ctrl_2_M00_AXI_BVALID),
        .M00_AXI_rdata(icn_ctrl_2_M00_AXI_RDATA),
        .M00_AXI_rready(icn_ctrl_2_M00_AXI_RREADY),
        .M00_AXI_rresp(icn_ctrl_2_M00_AXI_RRESP),
        .M00_AXI_rvalid(icn_ctrl_2_M00_AXI_RVALID),
        .M00_AXI_wdata(icn_ctrl_2_M00_AXI_WDATA),
        .M00_AXI_wready(icn_ctrl_2_M00_AXI_WREADY),
        .M00_AXI_wstrb(icn_ctrl_2_M00_AXI_WSTRB),
        .M00_AXI_wvalid(icn_ctrl_2_M00_AXI_WVALID),
        .S00_AXI_araddr(icn_ctrl_1_M02_AXI_ARADDR),
        .S00_AXI_arburst(icn_ctrl_1_M02_AXI_ARBURST),
        .S00_AXI_arcache(icn_ctrl_1_M02_AXI_ARCACHE),
        .S00_AXI_arid(icn_ctrl_1_M02_AXI_ARID),
        .S00_AXI_arlen(icn_ctrl_1_M02_AXI_ARLEN),
        .S00_AXI_arlock(icn_ctrl_1_M02_AXI_ARLOCK),
        .S00_AXI_arprot(icn_ctrl_1_M02_AXI_ARPROT),
        .S00_AXI_arqos(icn_ctrl_1_M02_AXI_ARQOS),
        .S00_AXI_arready(icn_ctrl_1_M02_AXI_ARREADY),
        .S00_AXI_arsize(icn_ctrl_1_M02_AXI_ARSIZE),
        .S00_AXI_aruser(icn_ctrl_1_M02_AXI_ARUSER),
        .S00_AXI_arvalid(icn_ctrl_1_M02_AXI_ARVALID),
        .S00_AXI_awaddr(icn_ctrl_1_M02_AXI_AWADDR),
        .S00_AXI_awburst(icn_ctrl_1_M02_AXI_AWBURST),
        .S00_AXI_awcache(icn_ctrl_1_M02_AXI_AWCACHE),
        .S00_AXI_awid(icn_ctrl_1_M02_AXI_AWID),
        .S00_AXI_awlen(icn_ctrl_1_M02_AXI_AWLEN),
        .S00_AXI_awlock(icn_ctrl_1_M02_AXI_AWLOCK),
        .S00_AXI_awprot(icn_ctrl_1_M02_AXI_AWPROT),
        .S00_AXI_awqos(icn_ctrl_1_M02_AXI_AWQOS),
        .S00_AXI_awready(icn_ctrl_1_M02_AXI_AWREADY),
        .S00_AXI_awsize(icn_ctrl_1_M02_AXI_AWSIZE),
        .S00_AXI_awuser(icn_ctrl_1_M02_AXI_AWUSER),
        .S00_AXI_awvalid(icn_ctrl_1_M02_AXI_AWVALID),
        .S00_AXI_bid(icn_ctrl_1_M02_AXI_BID),
        .S00_AXI_bready(icn_ctrl_1_M02_AXI_BREADY),
        .S00_AXI_bresp(icn_ctrl_1_M02_AXI_BRESP),
        .S00_AXI_bvalid(icn_ctrl_1_M02_AXI_BVALID),
        .S00_AXI_rdata(icn_ctrl_1_M02_AXI_RDATA),
        .S00_AXI_rid(icn_ctrl_1_M02_AXI_RID),
        .S00_AXI_rlast(icn_ctrl_1_M02_AXI_RLAST),
        .S00_AXI_rready(icn_ctrl_1_M02_AXI_RREADY),
        .S00_AXI_rresp(icn_ctrl_1_M02_AXI_RRESP),
        .S00_AXI_ruser(icn_ctrl_1_M02_AXI_RUSER),
        .S00_AXI_rvalid(icn_ctrl_1_M02_AXI_RVALID),
        .S00_AXI_wdata(icn_ctrl_1_M02_AXI_WDATA),
        .S00_AXI_wlast(icn_ctrl_1_M02_AXI_WLAST),
        .S00_AXI_wready(icn_ctrl_1_M02_AXI_WREADY),
        .S00_AXI_wstrb(icn_ctrl_1_M02_AXI_WSTRB),
        .S00_AXI_wuser(icn_ctrl_1_M02_AXI_WUSER),
        .S00_AXI_wvalid(icn_ctrl_1_M02_AXI_WVALID),
        .aclk(clk_wizard_0_clk_out1),
        .aresetn(psr_104mhz_peripheral_aresetn));
  vitis_design_icn_ctrl_3_0 icn_ctrl_3
       (.M00_AXI_araddr(icn_ctrl_3_M00_AXI_ARADDR),
        .M00_AXI_arprot(icn_ctrl_3_M00_AXI_ARPROT),
        .M00_AXI_arready(icn_ctrl_3_M00_AXI_ARREADY),
        .M00_AXI_arvalid(icn_ctrl_3_M00_AXI_ARVALID),
        .M00_AXI_awaddr(icn_ctrl_3_M00_AXI_AWADDR),
        .M00_AXI_awprot(icn_ctrl_3_M00_AXI_AWPROT),
        .M00_AXI_awready(icn_ctrl_3_M00_AXI_AWREADY),
        .M00_AXI_awvalid(icn_ctrl_3_M00_AXI_AWVALID),
        .M00_AXI_bready(icn_ctrl_3_M00_AXI_BREADY),
        .M00_AXI_bresp(icn_ctrl_3_M00_AXI_BRESP),
        .M00_AXI_bvalid(icn_ctrl_3_M00_AXI_BVALID),
        .M00_AXI_rdata(icn_ctrl_3_M00_AXI_RDATA),
        .M00_AXI_rready(icn_ctrl_3_M00_AXI_RREADY),
        .M00_AXI_rresp(icn_ctrl_3_M00_AXI_RRESP),
        .M00_AXI_rvalid(icn_ctrl_3_M00_AXI_RVALID),
        .M00_AXI_wdata(icn_ctrl_3_M00_AXI_WDATA),
        .M00_AXI_wready(icn_ctrl_3_M00_AXI_WREADY),
        .M00_AXI_wstrb(icn_ctrl_3_M00_AXI_WSTRB),
        .M00_AXI_wvalid(icn_ctrl_3_M00_AXI_WVALID),
        .S00_AXI_araddr(icn_ctrl_1_M03_AXI_ARADDR),
        .S00_AXI_arburst(icn_ctrl_1_M03_AXI_ARBURST),
        .S00_AXI_arcache(icn_ctrl_1_M03_AXI_ARCACHE),
        .S00_AXI_arid(icn_ctrl_1_M03_AXI_ARID),
        .S00_AXI_arlen(icn_ctrl_1_M03_AXI_ARLEN),
        .S00_AXI_arlock(icn_ctrl_1_M03_AXI_ARLOCK),
        .S00_AXI_arprot(icn_ctrl_1_M03_AXI_ARPROT),
        .S00_AXI_arqos(icn_ctrl_1_M03_AXI_ARQOS),
        .S00_AXI_arready(icn_ctrl_1_M03_AXI_ARREADY),
        .S00_AXI_arsize(icn_ctrl_1_M03_AXI_ARSIZE),
        .S00_AXI_aruser(icn_ctrl_1_M03_AXI_ARUSER),
        .S00_AXI_arvalid(icn_ctrl_1_M03_AXI_ARVALID),
        .S00_AXI_awaddr(icn_ctrl_1_M03_AXI_AWADDR),
        .S00_AXI_awburst(icn_ctrl_1_M03_AXI_AWBURST),
        .S00_AXI_awcache(icn_ctrl_1_M03_AXI_AWCACHE),
        .S00_AXI_awid(icn_ctrl_1_M03_AXI_AWID),
        .S00_AXI_awlen(icn_ctrl_1_M03_AXI_AWLEN),
        .S00_AXI_awlock(icn_ctrl_1_M03_AXI_AWLOCK),
        .S00_AXI_awprot(icn_ctrl_1_M03_AXI_AWPROT),
        .S00_AXI_awqos(icn_ctrl_1_M03_AXI_AWQOS),
        .S00_AXI_awready(icn_ctrl_1_M03_AXI_AWREADY),
        .S00_AXI_awsize(icn_ctrl_1_M03_AXI_AWSIZE),
        .S00_AXI_awuser(icn_ctrl_1_M03_AXI_AWUSER),
        .S00_AXI_awvalid(icn_ctrl_1_M03_AXI_AWVALID),
        .S00_AXI_bid(icn_ctrl_1_M03_AXI_BID),
        .S00_AXI_bready(icn_ctrl_1_M03_AXI_BREADY),
        .S00_AXI_bresp(icn_ctrl_1_M03_AXI_BRESP),
        .S00_AXI_bvalid(icn_ctrl_1_M03_AXI_BVALID),
        .S00_AXI_rdata(icn_ctrl_1_M03_AXI_RDATA),
        .S00_AXI_rid(icn_ctrl_1_M03_AXI_RID),
        .S00_AXI_rlast(icn_ctrl_1_M03_AXI_RLAST),
        .S00_AXI_rready(icn_ctrl_1_M03_AXI_RREADY),
        .S00_AXI_rresp(icn_ctrl_1_M03_AXI_RRESP),
        .S00_AXI_ruser(icn_ctrl_1_M03_AXI_RUSER),
        .S00_AXI_rvalid(icn_ctrl_1_M03_AXI_RVALID),
        .S00_AXI_wdata(icn_ctrl_1_M03_AXI_WDATA),
        .S00_AXI_wlast(icn_ctrl_1_M03_AXI_WLAST),
        .S00_AXI_wready(icn_ctrl_1_M03_AXI_WREADY),
        .S00_AXI_wstrb(icn_ctrl_1_M03_AXI_WSTRB),
        .S00_AXI_wuser(icn_ctrl_1_M03_AXI_WUSER),
        .S00_AXI_wvalid(icn_ctrl_1_M03_AXI_WVALID),
        .aclk(clk_wizard_0_clk_out1),
        .aresetn(psr_104mhz_peripheral_aresetn));
  vitis_design_icn_ctrl_4_0 icn_ctrl_4
       (.M00_AXI_araddr(icn_ctrl_4_M00_AXI_ARADDR),
        .M00_AXI_arprot(icn_ctrl_4_M00_AXI_ARPROT),
        .M00_AXI_arready(icn_ctrl_4_M00_AXI_ARREADY),
        .M00_AXI_arvalid(icn_ctrl_4_M00_AXI_ARVALID),
        .M00_AXI_awaddr(icn_ctrl_4_M00_AXI_AWADDR),
        .M00_AXI_awprot(icn_ctrl_4_M00_AXI_AWPROT),
        .M00_AXI_awready(icn_ctrl_4_M00_AXI_AWREADY),
        .M00_AXI_awvalid(icn_ctrl_4_M00_AXI_AWVALID),
        .M00_AXI_bready(icn_ctrl_4_M00_AXI_BREADY),
        .M00_AXI_bresp(icn_ctrl_4_M00_AXI_BRESP),
        .M00_AXI_bvalid(icn_ctrl_4_M00_AXI_BVALID),
        .M00_AXI_rdata(icn_ctrl_4_M00_AXI_RDATA),
        .M00_AXI_rready(icn_ctrl_4_M00_AXI_RREADY),
        .M00_AXI_rresp(icn_ctrl_4_M00_AXI_RRESP),
        .M00_AXI_rvalid(icn_ctrl_4_M00_AXI_RVALID),
        .M00_AXI_wdata(icn_ctrl_4_M00_AXI_WDATA),
        .M00_AXI_wready(icn_ctrl_4_M00_AXI_WREADY),
        .M00_AXI_wstrb(icn_ctrl_4_M00_AXI_WSTRB),
        .M00_AXI_wvalid(icn_ctrl_4_M00_AXI_WVALID),
        .S00_AXI_araddr(icn_ctrl_1_M04_AXI_ARADDR),
        .S00_AXI_arburst(icn_ctrl_1_M04_AXI_ARBURST),
        .S00_AXI_arcache(icn_ctrl_1_M04_AXI_ARCACHE),
        .S00_AXI_arid(icn_ctrl_1_M04_AXI_ARID),
        .S00_AXI_arlen(icn_ctrl_1_M04_AXI_ARLEN),
        .S00_AXI_arlock(icn_ctrl_1_M04_AXI_ARLOCK),
        .S00_AXI_arprot(icn_ctrl_1_M04_AXI_ARPROT),
        .S00_AXI_arqos(icn_ctrl_1_M04_AXI_ARQOS),
        .S00_AXI_arready(icn_ctrl_1_M04_AXI_ARREADY),
        .S00_AXI_arsize(icn_ctrl_1_M04_AXI_ARSIZE),
        .S00_AXI_aruser(icn_ctrl_1_M04_AXI_ARUSER),
        .S00_AXI_arvalid(icn_ctrl_1_M04_AXI_ARVALID),
        .S00_AXI_awaddr(icn_ctrl_1_M04_AXI_AWADDR),
        .S00_AXI_awburst(icn_ctrl_1_M04_AXI_AWBURST),
        .S00_AXI_awcache(icn_ctrl_1_M04_AXI_AWCACHE),
        .S00_AXI_awid(icn_ctrl_1_M04_AXI_AWID),
        .S00_AXI_awlen(icn_ctrl_1_M04_AXI_AWLEN),
        .S00_AXI_awlock(icn_ctrl_1_M04_AXI_AWLOCK),
        .S00_AXI_awprot(icn_ctrl_1_M04_AXI_AWPROT),
        .S00_AXI_awqos(icn_ctrl_1_M04_AXI_AWQOS),
        .S00_AXI_awready(icn_ctrl_1_M04_AXI_AWREADY),
        .S00_AXI_awsize(icn_ctrl_1_M04_AXI_AWSIZE),
        .S00_AXI_awuser(icn_ctrl_1_M04_AXI_AWUSER),
        .S00_AXI_awvalid(icn_ctrl_1_M04_AXI_AWVALID),
        .S00_AXI_bid(icn_ctrl_1_M04_AXI_BID),
        .S00_AXI_bready(icn_ctrl_1_M04_AXI_BREADY),
        .S00_AXI_bresp(icn_ctrl_1_M04_AXI_BRESP),
        .S00_AXI_bvalid(icn_ctrl_1_M04_AXI_BVALID),
        .S00_AXI_rdata(icn_ctrl_1_M04_AXI_RDATA),
        .S00_AXI_rid(icn_ctrl_1_M04_AXI_RID),
        .S00_AXI_rlast(icn_ctrl_1_M04_AXI_RLAST),
        .S00_AXI_rready(icn_ctrl_1_M04_AXI_RREADY),
        .S00_AXI_rresp(icn_ctrl_1_M04_AXI_RRESP),
        .S00_AXI_ruser(icn_ctrl_1_M04_AXI_RUSER),
        .S00_AXI_rvalid(icn_ctrl_1_M04_AXI_RVALID),
        .S00_AXI_wdata(icn_ctrl_1_M04_AXI_WDATA),
        .S00_AXI_wlast(icn_ctrl_1_M04_AXI_WLAST),
        .S00_AXI_wready(icn_ctrl_1_M04_AXI_WREADY),
        .S00_AXI_wstrb(icn_ctrl_1_M04_AXI_WSTRB),
        .S00_AXI_wuser(icn_ctrl_1_M04_AXI_WUSER),
        .S00_AXI_wvalid(icn_ctrl_1_M04_AXI_WVALID),
        .aclk(clk_wizard_0_clk_out1),
        .aresetn(psr_104mhz_peripheral_aresetn));
  vitis_design_icn_ctrl_5_0 icn_ctrl_5
       (.M00_AXI_araddr(icn_ctrl_5_M00_AXI_ARADDR),
        .M00_AXI_arprot(icn_ctrl_5_M00_AXI_ARPROT),
        .M00_AXI_arready(icn_ctrl_5_M00_AXI_ARREADY),
        .M00_AXI_arvalid(icn_ctrl_5_M00_AXI_ARVALID),
        .M00_AXI_awaddr(icn_ctrl_5_M00_AXI_AWADDR),
        .M00_AXI_awprot(icn_ctrl_5_M00_AXI_AWPROT),
        .M00_AXI_awready(icn_ctrl_5_M00_AXI_AWREADY),
        .M00_AXI_awvalid(icn_ctrl_5_M00_AXI_AWVALID),
        .M00_AXI_bready(icn_ctrl_5_M00_AXI_BREADY),
        .M00_AXI_bresp(icn_ctrl_5_M00_AXI_BRESP),
        .M00_AXI_bvalid(icn_ctrl_5_M00_AXI_BVALID),
        .M00_AXI_rdata(icn_ctrl_5_M00_AXI_RDATA),
        .M00_AXI_rready(icn_ctrl_5_M00_AXI_RREADY),
        .M00_AXI_rresp(icn_ctrl_5_M00_AXI_RRESP),
        .M00_AXI_rvalid(icn_ctrl_5_M00_AXI_RVALID),
        .M00_AXI_wdata(icn_ctrl_5_M00_AXI_WDATA),
        .M00_AXI_wready(icn_ctrl_5_M00_AXI_WREADY),
        .M00_AXI_wstrb(icn_ctrl_5_M00_AXI_WSTRB),
        .M00_AXI_wvalid(icn_ctrl_5_M00_AXI_WVALID),
        .S00_AXI_araddr(icn_ctrl_1_M05_AXI_ARADDR),
        .S00_AXI_arburst(icn_ctrl_1_M05_AXI_ARBURST),
        .S00_AXI_arcache(icn_ctrl_1_M05_AXI_ARCACHE),
        .S00_AXI_arid(icn_ctrl_1_M05_AXI_ARID),
        .S00_AXI_arlen(icn_ctrl_1_M05_AXI_ARLEN),
        .S00_AXI_arlock(icn_ctrl_1_M05_AXI_ARLOCK),
        .S00_AXI_arprot(icn_ctrl_1_M05_AXI_ARPROT),
        .S00_AXI_arqos(icn_ctrl_1_M05_AXI_ARQOS),
        .S00_AXI_arready(icn_ctrl_1_M05_AXI_ARREADY),
        .S00_AXI_arsize(icn_ctrl_1_M05_AXI_ARSIZE),
        .S00_AXI_aruser(icn_ctrl_1_M05_AXI_ARUSER),
        .S00_AXI_arvalid(icn_ctrl_1_M05_AXI_ARVALID),
        .S00_AXI_awaddr(icn_ctrl_1_M05_AXI_AWADDR),
        .S00_AXI_awburst(icn_ctrl_1_M05_AXI_AWBURST),
        .S00_AXI_awcache(icn_ctrl_1_M05_AXI_AWCACHE),
        .S00_AXI_awid(icn_ctrl_1_M05_AXI_AWID),
        .S00_AXI_awlen(icn_ctrl_1_M05_AXI_AWLEN),
        .S00_AXI_awlock(icn_ctrl_1_M05_AXI_AWLOCK),
        .S00_AXI_awprot(icn_ctrl_1_M05_AXI_AWPROT),
        .S00_AXI_awqos(icn_ctrl_1_M05_AXI_AWQOS),
        .S00_AXI_awready(icn_ctrl_1_M05_AXI_AWREADY),
        .S00_AXI_awsize(icn_ctrl_1_M05_AXI_AWSIZE),
        .S00_AXI_awuser(icn_ctrl_1_M05_AXI_AWUSER),
        .S00_AXI_awvalid(icn_ctrl_1_M05_AXI_AWVALID),
        .S00_AXI_bid(icn_ctrl_1_M05_AXI_BID),
        .S00_AXI_bready(icn_ctrl_1_M05_AXI_BREADY),
        .S00_AXI_bresp(icn_ctrl_1_M05_AXI_BRESP),
        .S00_AXI_bvalid(icn_ctrl_1_M05_AXI_BVALID),
        .S00_AXI_rdata(icn_ctrl_1_M05_AXI_RDATA),
        .S00_AXI_rid(icn_ctrl_1_M05_AXI_RID),
        .S00_AXI_rlast(icn_ctrl_1_M05_AXI_RLAST),
        .S00_AXI_rready(icn_ctrl_1_M05_AXI_RREADY),
        .S00_AXI_rresp(icn_ctrl_1_M05_AXI_RRESP),
        .S00_AXI_ruser(icn_ctrl_1_M05_AXI_RUSER),
        .S00_AXI_rvalid(icn_ctrl_1_M05_AXI_RVALID),
        .S00_AXI_wdata(icn_ctrl_1_M05_AXI_WDATA),
        .S00_AXI_wlast(icn_ctrl_1_M05_AXI_WLAST),
        .S00_AXI_wready(icn_ctrl_1_M05_AXI_WREADY),
        .S00_AXI_wstrb(icn_ctrl_1_M05_AXI_WSTRB),
        .S00_AXI_wuser(icn_ctrl_1_M05_AXI_WUSER),
        .S00_AXI_wvalid(icn_ctrl_1_M05_AXI_WVALID),
        .aclk(clk_wizard_0_clk_out1),
        .aresetn(psr_104mhz_peripheral_aresetn));
  vitis_design_noc_ddr4_0 noc_ddr4
       (.CH0_DDR4_0_act_n(noc_ddr4_CH0_DDR4_0_ACT_N),
        .CH0_DDR4_0_adr(noc_ddr4_CH0_DDR4_0_ADR),
        .CH0_DDR4_0_ba(noc_ddr4_CH0_DDR4_0_BA),
        .CH0_DDR4_0_bg(noc_ddr4_CH0_DDR4_0_BG),
        .CH0_DDR4_0_ck_c(noc_ddr4_CH0_DDR4_0_CK_C),
        .CH0_DDR4_0_ck_t(noc_ddr4_CH0_DDR4_0_CK_T),
        .CH0_DDR4_0_cke(noc_ddr4_CH0_DDR4_0_CKE),
        .CH0_DDR4_0_cs_n(noc_ddr4_CH0_DDR4_0_CS_N),
        .CH0_DDR4_0_dm_n(ddr4_dimm1_dm_n[7:0]),
        .CH0_DDR4_0_dq(ddr4_dimm1_dq[63:0]),
        .CH0_DDR4_0_dqs_c(ddr4_dimm1_dqs_c[7:0]),
        .CH0_DDR4_0_dqs_t(ddr4_dimm1_dqs_t[7:0]),
        .CH0_DDR4_0_odt(noc_ddr4_CH0_DDR4_0_ODT),
        .CH0_DDR4_0_reset_n(noc_ddr4_CH0_DDR4_0_RESET_N),
        .S00_AXI_araddr(mm2s_1_m_axi_gmem_ARADDR),
        .S00_AXI_arburst(mm2s_1_m_axi_gmem_ARBURST),
        .S00_AXI_arcache(mm2s_1_m_axi_gmem_ARCACHE),
        .S00_AXI_arid(mm2s_1_m_axi_gmem_ARID),
        .S00_AXI_arlen(mm2s_1_m_axi_gmem_ARLEN),
        .S00_AXI_arlock(mm2s_1_m_axi_gmem_ARLOCK[0]),
        .S00_AXI_arprot(mm2s_1_m_axi_gmem_ARPROT),
        .S00_AXI_arqos(mm2s_1_m_axi_gmem_ARQOS),
        .S00_AXI_arready(mm2s_1_m_axi_gmem_ARREADY),
        .S00_AXI_arregion(mm2s_1_m_axi_gmem_ARREGION),
        .S00_AXI_arsize(mm2s_1_m_axi_gmem_ARSIZE),
        .S00_AXI_arvalid(mm2s_1_m_axi_gmem_ARVALID),
        .S00_AXI_awaddr(mm2s_1_m_axi_gmem_AWADDR),
        .S00_AXI_awburst(mm2s_1_m_axi_gmem_AWBURST),
        .S00_AXI_awcache(mm2s_1_m_axi_gmem_AWCACHE),
        .S00_AXI_awid(mm2s_1_m_axi_gmem_AWID),
        .S00_AXI_awlen(mm2s_1_m_axi_gmem_AWLEN),
        .S00_AXI_awlock(mm2s_1_m_axi_gmem_AWLOCK[0]),
        .S00_AXI_awprot(mm2s_1_m_axi_gmem_AWPROT),
        .S00_AXI_awqos(mm2s_1_m_axi_gmem_AWQOS),
        .S00_AXI_awready(mm2s_1_m_axi_gmem_AWREADY),
        .S00_AXI_awregion(mm2s_1_m_axi_gmem_AWREGION),
        .S00_AXI_awsize(mm2s_1_m_axi_gmem_AWSIZE),
        .S00_AXI_awvalid(mm2s_1_m_axi_gmem_AWVALID),
        .S00_AXI_bid(mm2s_1_m_axi_gmem_BID),
        .S00_AXI_bready(mm2s_1_m_axi_gmem_BREADY),
        .S00_AXI_bresp(mm2s_1_m_axi_gmem_BRESP),
        .S00_AXI_bvalid(mm2s_1_m_axi_gmem_BVALID),
        .S00_AXI_rdata(mm2s_1_m_axi_gmem_RDATA),
        .S00_AXI_rid(mm2s_1_m_axi_gmem_RID),
        .S00_AXI_rlast(mm2s_1_m_axi_gmem_RLAST),
        .S00_AXI_rready(mm2s_1_m_axi_gmem_RREADY),
        .S00_AXI_rresp(mm2s_1_m_axi_gmem_RRESP),
        .S00_AXI_rvalid(mm2s_1_m_axi_gmem_RVALID),
        .S00_AXI_wdata(mm2s_1_m_axi_gmem_WDATA),
        .S00_AXI_wlast(mm2s_1_m_axi_gmem_WLAST),
        .S00_AXI_wready(mm2s_1_m_axi_gmem_WREADY),
        .S00_AXI_wstrb(mm2s_1_m_axi_gmem_WSTRB),
        .S00_AXI_wvalid(mm2s_1_m_axi_gmem_WVALID),
        .S00_INI_internoc(cips_noc_M00_INI_INTERNOC),
        .S01_AXI_araddr(mm2s_2_m_axi_gmem_ARADDR),
        .S01_AXI_arburst(mm2s_2_m_axi_gmem_ARBURST),
        .S01_AXI_arcache(mm2s_2_m_axi_gmem_ARCACHE),
        .S01_AXI_arid(mm2s_2_m_axi_gmem_ARID),
        .S01_AXI_arlen(mm2s_2_m_axi_gmem_ARLEN),
        .S01_AXI_arlock(mm2s_2_m_axi_gmem_ARLOCK[0]),
        .S01_AXI_arprot(mm2s_2_m_axi_gmem_ARPROT),
        .S01_AXI_arqos(mm2s_2_m_axi_gmem_ARQOS),
        .S01_AXI_arready(mm2s_2_m_axi_gmem_ARREADY),
        .S01_AXI_arregion(mm2s_2_m_axi_gmem_ARREGION),
        .S01_AXI_arsize(mm2s_2_m_axi_gmem_ARSIZE),
        .S01_AXI_arvalid(mm2s_2_m_axi_gmem_ARVALID),
        .S01_AXI_awaddr(mm2s_2_m_axi_gmem_AWADDR),
        .S01_AXI_awburst(mm2s_2_m_axi_gmem_AWBURST),
        .S01_AXI_awcache(mm2s_2_m_axi_gmem_AWCACHE),
        .S01_AXI_awid(mm2s_2_m_axi_gmem_AWID),
        .S01_AXI_awlen(mm2s_2_m_axi_gmem_AWLEN),
        .S01_AXI_awlock(mm2s_2_m_axi_gmem_AWLOCK[0]),
        .S01_AXI_awprot(mm2s_2_m_axi_gmem_AWPROT),
        .S01_AXI_awqos(mm2s_2_m_axi_gmem_AWQOS),
        .S01_AXI_awready(mm2s_2_m_axi_gmem_AWREADY),
        .S01_AXI_awregion(mm2s_2_m_axi_gmem_AWREGION),
        .S01_AXI_awsize(mm2s_2_m_axi_gmem_AWSIZE),
        .S01_AXI_awvalid(mm2s_2_m_axi_gmem_AWVALID),
        .S01_AXI_bid(mm2s_2_m_axi_gmem_BID),
        .S01_AXI_bready(mm2s_2_m_axi_gmem_BREADY),
        .S01_AXI_bresp(mm2s_2_m_axi_gmem_BRESP),
        .S01_AXI_bvalid(mm2s_2_m_axi_gmem_BVALID),
        .S01_AXI_rdata(mm2s_2_m_axi_gmem_RDATA),
        .S01_AXI_rid(mm2s_2_m_axi_gmem_RID),
        .S01_AXI_rlast(mm2s_2_m_axi_gmem_RLAST),
        .S01_AXI_rready(mm2s_2_m_axi_gmem_RREADY),
        .S01_AXI_rresp(mm2s_2_m_axi_gmem_RRESP),
        .S01_AXI_rvalid(mm2s_2_m_axi_gmem_RVALID),
        .S01_AXI_wdata(mm2s_2_m_axi_gmem_WDATA),
        .S01_AXI_wlast(mm2s_2_m_axi_gmem_WLAST),
        .S01_AXI_wready(mm2s_2_m_axi_gmem_WREADY),
        .S01_AXI_wstrb(mm2s_2_m_axi_gmem_WSTRB),
        .S01_AXI_wvalid(mm2s_2_m_axi_gmem_WVALID),
        .S01_INI_internoc(cips_noc_M01_INI_INTERNOC),
        .S02_AXI_araddr(s2mm_m_axi_gmem_ARADDR),
        .S02_AXI_arburst(s2mm_m_axi_gmem_ARBURST),
        .S02_AXI_arcache(s2mm_m_axi_gmem_ARCACHE),
        .S02_AXI_arid(s2mm_m_axi_gmem_ARID),
        .S02_AXI_arlen(s2mm_m_axi_gmem_ARLEN),
        .S02_AXI_arlock(s2mm_m_axi_gmem_ARLOCK[0]),
        .S02_AXI_arprot(s2mm_m_axi_gmem_ARPROT),
        .S02_AXI_arqos(s2mm_m_axi_gmem_ARQOS),
        .S02_AXI_arready(s2mm_m_axi_gmem_ARREADY),
        .S02_AXI_arregion(s2mm_m_axi_gmem_ARREGION),
        .S02_AXI_arsize(s2mm_m_axi_gmem_ARSIZE),
        .S02_AXI_arvalid(s2mm_m_axi_gmem_ARVALID),
        .S02_AXI_awaddr(s2mm_m_axi_gmem_AWADDR),
        .S02_AXI_awburst(s2mm_m_axi_gmem_AWBURST),
        .S02_AXI_awcache(s2mm_m_axi_gmem_AWCACHE),
        .S02_AXI_awid(s2mm_m_axi_gmem_AWID),
        .S02_AXI_awlen(s2mm_m_axi_gmem_AWLEN),
        .S02_AXI_awlock(s2mm_m_axi_gmem_AWLOCK[0]),
        .S02_AXI_awprot(s2mm_m_axi_gmem_AWPROT),
        .S02_AXI_awqos(s2mm_m_axi_gmem_AWQOS),
        .S02_AXI_awready(s2mm_m_axi_gmem_AWREADY),
        .S02_AXI_awregion(s2mm_m_axi_gmem_AWREGION),
        .S02_AXI_awsize(s2mm_m_axi_gmem_AWSIZE),
        .S02_AXI_awvalid(s2mm_m_axi_gmem_AWVALID),
        .S02_AXI_bid(s2mm_m_axi_gmem_BID),
        .S02_AXI_bready(s2mm_m_axi_gmem_BREADY),
        .S02_AXI_bresp(s2mm_m_axi_gmem_BRESP),
        .S02_AXI_bvalid(s2mm_m_axi_gmem_BVALID),
        .S02_AXI_rdata(s2mm_m_axi_gmem_RDATA),
        .S02_AXI_rid(s2mm_m_axi_gmem_RID),
        .S02_AXI_rlast(s2mm_m_axi_gmem_RLAST),
        .S02_AXI_rready(s2mm_m_axi_gmem_RREADY),
        .S02_AXI_rresp(s2mm_m_axi_gmem_RRESP),
        .S02_AXI_rvalid(s2mm_m_axi_gmem_RVALID),
        .S02_AXI_wdata(s2mm_m_axi_gmem_WDATA),
        .S02_AXI_wlast(s2mm_m_axi_gmem_WLAST),
        .S02_AXI_wready(s2mm_m_axi_gmem_WREADY),
        .S02_AXI_wstrb(s2mm_m_axi_gmem_WSTRB),
        .S02_AXI_wvalid(s2mm_m_axi_gmem_WVALID),
        .S02_INI_internoc(cips_noc_M02_INI_INTERNOC),
        .S03_INI_internoc(cips_noc_M03_INI_INTERNOC),
        .aclk0(VitisRegion_aclk_bypass_m),
        .sys_clk0_clk_n(ddr4_dimm1_sma_clk_1_CLK_N),
        .sys_clk0_clk_p(ddr4_dimm1_sma_clk_1_CLK_P));
  vitis_design_noc_lpddr4_0 noc_lpddr4
       (.CH0_LPDDR4_0_ca_a(axi_noc_0_CH0_LPDDR4_0_CA_A),
        .CH0_LPDDR4_0_ca_b(axi_noc_0_CH0_LPDDR4_0_CA_B),
        .CH0_LPDDR4_0_ck_c_a(axi_noc_0_CH0_LPDDR4_0_CK_C_A),
        .CH0_LPDDR4_0_ck_c_b(axi_noc_0_CH0_LPDDR4_0_CK_C_B),
        .CH0_LPDDR4_0_ck_t_a(axi_noc_0_CH0_LPDDR4_0_CK_T_A),
        .CH0_LPDDR4_0_ck_t_b(axi_noc_0_CH0_LPDDR4_0_CK_T_B),
        .CH0_LPDDR4_0_cke_a(axi_noc_0_CH0_LPDDR4_0_CKE_A),
        .CH0_LPDDR4_0_cke_b(axi_noc_0_CH0_LPDDR4_0_CKE_B),
        .CH0_LPDDR4_0_cs_a(axi_noc_0_CH0_LPDDR4_0_CS_A),
        .CH0_LPDDR4_0_cs_b(axi_noc_0_CH0_LPDDR4_0_CS_B),
        .CH0_LPDDR4_0_dmi_a(ch0_lpddr4_c0_dmi_a[1:0]),
        .CH0_LPDDR4_0_dmi_b(ch0_lpddr4_c0_dmi_b[1:0]),
        .CH0_LPDDR4_0_dq_a(ch0_lpddr4_c0_dq_a[15:0]),
        .CH0_LPDDR4_0_dq_b(ch0_lpddr4_c0_dq_b[15:0]),
        .CH0_LPDDR4_0_dqs_c_a(ch0_lpddr4_c0_dqs_c_a[1:0]),
        .CH0_LPDDR4_0_dqs_c_b(ch0_lpddr4_c0_dqs_c_b[1:0]),
        .CH0_LPDDR4_0_dqs_t_a(ch0_lpddr4_c0_dqs_t_a[1:0]),
        .CH0_LPDDR4_0_dqs_t_b(ch0_lpddr4_c0_dqs_t_b[1:0]),
        .CH0_LPDDR4_0_reset_n(axi_noc_0_CH0_LPDDR4_0_RESET_N),
        .CH0_LPDDR4_1_ca_a(axi_noc_0_CH0_LPDDR4_1_CA_A),
        .CH0_LPDDR4_1_ca_b(axi_noc_0_CH0_LPDDR4_1_CA_B),
        .CH0_LPDDR4_1_ck_c_a(axi_noc_0_CH0_LPDDR4_1_CK_C_A),
        .CH0_LPDDR4_1_ck_c_b(axi_noc_0_CH0_LPDDR4_1_CK_C_B),
        .CH0_LPDDR4_1_ck_t_a(axi_noc_0_CH0_LPDDR4_1_CK_T_A),
        .CH0_LPDDR4_1_ck_t_b(axi_noc_0_CH0_LPDDR4_1_CK_T_B),
        .CH0_LPDDR4_1_cke_a(axi_noc_0_CH0_LPDDR4_1_CKE_A),
        .CH0_LPDDR4_1_cke_b(axi_noc_0_CH0_LPDDR4_1_CKE_B),
        .CH0_LPDDR4_1_cs_a(axi_noc_0_CH0_LPDDR4_1_CS_A),
        .CH0_LPDDR4_1_cs_b(axi_noc_0_CH0_LPDDR4_1_CS_B),
        .CH0_LPDDR4_1_dmi_a(ch0_lpddr4_c1_dmi_a[1:0]),
        .CH0_LPDDR4_1_dmi_b(ch0_lpddr4_c1_dmi_b[1:0]),
        .CH0_LPDDR4_1_dq_a(ch0_lpddr4_c1_dq_a[15:0]),
        .CH0_LPDDR4_1_dq_b(ch0_lpddr4_c1_dq_b[15:0]),
        .CH0_LPDDR4_1_dqs_c_a(ch0_lpddr4_c1_dqs_c_a[1:0]),
        .CH0_LPDDR4_1_dqs_c_b(ch0_lpddr4_c1_dqs_c_b[1:0]),
        .CH0_LPDDR4_1_dqs_t_a(ch0_lpddr4_c1_dqs_t_a[1:0]),
        .CH0_LPDDR4_1_dqs_t_b(ch0_lpddr4_c1_dqs_t_b[1:0]),
        .CH0_LPDDR4_1_reset_n(axi_noc_0_CH0_LPDDR4_1_RESET_N),
        .CH1_LPDDR4_0_ca_a(axi_noc_0_CH1_LPDDR4_0_CA_A),
        .CH1_LPDDR4_0_ca_b(axi_noc_0_CH1_LPDDR4_0_CA_B),
        .CH1_LPDDR4_0_ck_c_a(axi_noc_0_CH1_LPDDR4_0_CK_C_A),
        .CH1_LPDDR4_0_ck_c_b(axi_noc_0_CH1_LPDDR4_0_CK_C_B),
        .CH1_LPDDR4_0_ck_t_a(axi_noc_0_CH1_LPDDR4_0_CK_T_A),
        .CH1_LPDDR4_0_ck_t_b(axi_noc_0_CH1_LPDDR4_0_CK_T_B),
        .CH1_LPDDR4_0_cke_a(axi_noc_0_CH1_LPDDR4_0_CKE_A),
        .CH1_LPDDR4_0_cke_b(axi_noc_0_CH1_LPDDR4_0_CKE_B),
        .CH1_LPDDR4_0_cs_a(axi_noc_0_CH1_LPDDR4_0_CS_A),
        .CH1_LPDDR4_0_cs_b(axi_noc_0_CH1_LPDDR4_0_CS_B),
        .CH1_LPDDR4_0_dmi_a(ch1_lpddr4_c0_dmi_a[1:0]),
        .CH1_LPDDR4_0_dmi_b(ch1_lpddr4_c0_dmi_b[1:0]),
        .CH1_LPDDR4_0_dq_a(ch1_lpddr4_c0_dq_a[15:0]),
        .CH1_LPDDR4_0_dq_b(ch1_lpddr4_c0_dq_b[15:0]),
        .CH1_LPDDR4_0_dqs_c_a(ch1_lpddr4_c0_dqs_c_a[1:0]),
        .CH1_LPDDR4_0_dqs_c_b(ch1_lpddr4_c0_dqs_c_b[1:0]),
        .CH1_LPDDR4_0_dqs_t_a(ch1_lpddr4_c0_dqs_t_a[1:0]),
        .CH1_LPDDR4_0_dqs_t_b(ch1_lpddr4_c0_dqs_t_b[1:0]),
        .CH1_LPDDR4_0_reset_n(axi_noc_0_CH1_LPDDR4_0_RESET_N),
        .CH1_LPDDR4_1_ca_a(axi_noc_0_CH1_LPDDR4_1_CA_A),
        .CH1_LPDDR4_1_ca_b(axi_noc_0_CH1_LPDDR4_1_CA_B),
        .CH1_LPDDR4_1_ck_c_a(axi_noc_0_CH1_LPDDR4_1_CK_C_A),
        .CH1_LPDDR4_1_ck_c_b(axi_noc_0_CH1_LPDDR4_1_CK_C_B),
        .CH1_LPDDR4_1_ck_t_a(axi_noc_0_CH1_LPDDR4_1_CK_T_A),
        .CH1_LPDDR4_1_ck_t_b(axi_noc_0_CH1_LPDDR4_1_CK_T_B),
        .CH1_LPDDR4_1_cke_a(axi_noc_0_CH1_LPDDR4_1_CKE_A),
        .CH1_LPDDR4_1_cke_b(axi_noc_0_CH1_LPDDR4_1_CKE_B),
        .CH1_LPDDR4_1_cs_a(axi_noc_0_CH1_LPDDR4_1_CS_A),
        .CH1_LPDDR4_1_cs_b(axi_noc_0_CH1_LPDDR4_1_CS_B),
        .CH1_LPDDR4_1_dmi_a(ch1_lpddr4_c1_dmi_a[1:0]),
        .CH1_LPDDR4_1_dmi_b(ch1_lpddr4_c1_dmi_b[1:0]),
        .CH1_LPDDR4_1_dq_a(ch1_lpddr4_c1_dq_a[15:0]),
        .CH1_LPDDR4_1_dq_b(ch1_lpddr4_c1_dq_b[15:0]),
        .CH1_LPDDR4_1_dqs_c_a(ch1_lpddr4_c1_dqs_c_a[1:0]),
        .CH1_LPDDR4_1_dqs_c_b(ch1_lpddr4_c1_dqs_c_b[1:0]),
        .CH1_LPDDR4_1_dqs_t_a(ch1_lpddr4_c1_dqs_t_a[1:0]),
        .CH1_LPDDR4_1_dqs_t_b(ch1_lpddr4_c1_dqs_t_b[1:0]),
        .CH1_LPDDR4_1_reset_n(axi_noc_0_CH1_LPDDR4_1_RESET_N),
        .S00_INI_internoc(cips_noc_M04_INI_INTERNOC),
        .S01_INI_internoc(cips_noc_M05_INI_INTERNOC),
        .S02_INI_internoc(cips_noc_M06_INI_INTERNOC),
        .S03_INI_internoc(cips_noc_M07_INI_INTERNOC),
        .sys_clk0_clk_n(lpddr4_sma_clk1_1_CLK_N),
        .sys_clk0_clk_p(lpddr4_sma_clk1_1_CLK_P),
        .sys_clk1_clk_n(lpddr4_sma_clk2_1_CLK_N),
        .sys_clk1_clk_p(lpddr4_sma_clk2_1_CLK_P));
  vitis_design_psr_104mhz_0 psr_104mhz
       (.aux_reset_in(1'b1),
        .dcm_locked(clk_wizard_0_locked),
        .ext_reset_in(CIPS_0_pl_resetn1),
        .mb_debug_sys_rst(1'b0),
        .peripheral_aresetn(psr_104mhz_peripheral_aresetn),
        .slowest_sync_clk(clk_wizard_0_clk_out1));
  vitis_design_psr_156mhz_0 psr_156mhz
       (.aux_reset_in(1'b1),
        .dcm_locked(clk_wizard_0_locked),
        .ext_reset_in(CIPS_0_pl_resetn1),
        .mb_debug_sys_rst(1'b0),
        .slowest_sync_clk(clk_wizard_0_clk_out4_o1_o3));
  vitis_design_psr_208mhz_0 psr_208mhz
       (.aux_reset_in(1'b1),
        .dcm_locked(clk_wizard_0_locked),
        .ext_reset_in(CIPS_0_pl_resetn1),
        .mb_debug_sys_rst(1'b0),
        .slowest_sync_clk(clk_wizard_0_clk_out2));
  vitis_design_psr_312mhz_0 psr_312mhz
       (.aux_reset_in(1'b1),
        .dcm_locked(clk_wizard_0_locked),
        .ext_reset_in(CIPS_0_pl_resetn1),
        .interconnect_aresetn(psr_312mhz_interconnect_aresetn),
        .mb_debug_sys_rst(1'b0),
        .peripheral_aresetn(psr_312mhz_peripheral_aresetn),
        .slowest_sync_clk(clk_wizard_0_clk_out4_o1_o2));
  vitis_design_psr_416mhz_0 psr_416mhz
       (.aux_reset_in(1'b1),
        .dcm_locked(clk_wizard_0_locked),
        .ext_reset_in(CIPS_0_pl_resetn1),
        .mb_debug_sys_rst(1'b0),
        .slowest_sync_clk(clk_wizard_0_clk_out3));
  vitis_design_psr_625mhz_0 psr_625mhz
       (.aux_reset_in(1'b1),
        .dcm_locked(clk_wizard_0_locked),
        .ext_reset_in(CIPS_0_pl_resetn1),
        .mb_debug_sys_rst(1'b0),
        .slowest_sync_clk(clk_wizard_0_clk_out4_o1_o1));
  vitis_design_psr_78mhz_0 psr_78mhz
       (.aux_reset_in(1'b1),
        .dcm_locked(clk_wizard_0_locked),
        .ext_reset_in(CIPS_0_pl_resetn1),
        .mb_debug_sys_rst(1'b0),
        .slowest_sync_clk(clk_wizard_0_clk_out4_o1_o4));
  vitis_design_sci vitis_design_sci_inst
       ();
  vitis_design_xlconcat_0_0 xlconcat_0
       (.In0(irq_const_tieoff_dout),
        .In1(irq_const_tieoff_dout),
        .In10(irq_const_tieoff_dout),
        .In11(irq_const_tieoff_dout),
        .In12(irq_const_tieoff_dout),
        .In13(irq_const_tieoff_dout),
        .In14(irq_const_tieoff_dout),
        .In15(irq_const_tieoff_dout),
        .In16(irq_const_tieoff_dout),
        .In17(irq_const_tieoff_dout),
        .In18(irq_const_tieoff_dout),
        .In19(irq_const_tieoff_dout),
        .In2(irq_const_tieoff_dout),
        .In20(irq_const_tieoff_dout),
        .In21(irq_const_tieoff_dout),
        .In22(irq_const_tieoff_dout),
        .In23(irq_const_tieoff_dout),
        .In24(irq_const_tieoff_dout),
        .In25(irq_const_tieoff_dout),
        .In26(irq_const_tieoff_dout),
        .In27(irq_const_tieoff_dout),
        .In28(irq_const_tieoff_dout),
        .In29(irq_const_tieoff_dout),
        .In3(irq_const_tieoff_dout),
        .In30(irq_const_tieoff_dout),
        .In31(axi_intc_cascaded_1_irq),
        .In4(irq_const_tieoff_dout),
        .In5(irq_const_tieoff_dout),
        .In6(irq_const_tieoff_dout),
        .In7(irq_const_tieoff_dout),
        .In8(irq_const_tieoff_dout),
        .In9(irq_const_tieoff_dout),
        .dout(xlconcat_0_dout));
  vitis_design_xlconstant_0_0 xlconstant_0
       (.dout(xlconstant_0_dout));
endmodule
