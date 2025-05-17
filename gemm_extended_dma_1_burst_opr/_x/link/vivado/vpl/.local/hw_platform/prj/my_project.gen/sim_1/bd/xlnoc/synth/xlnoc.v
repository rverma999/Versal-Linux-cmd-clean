//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2024.1 (lin64) Build 5076211 Wed May 22 01:37:59 MDT 2024
//Date        : Wed May 22 12:43:41 2024
//Host        : xcolinlocbld22 running 64-bit CentOS Linux release 7.4.1708 (Core)
//Command     : generate_target xlnoc.bd
//Design      : xlnoc
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "xlnoc,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=xlnoc,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=1,numReposBlks=1,numNonXlnxBlks=0,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=IPI,synth_mode=None}" *) (* HW_HANDOFF = "xlnoc.hwdef" *) 
module xlnoc
   (noc_clk,
    noc_rst_n);
  (* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.NOC_CLK CLK" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.NOC_CLK, CLK_DOMAIN xlnoc_noc_clk, FREQ_HZ 100000000, FREQ_TOLERANCE_HZ 0, INSERT_VIP 0, PHASE 0.0" *) input noc_clk;
  (* X_INTERFACE_INFO = "xilinx.com:signal:reset:1.0 RST.NOC_RST_N RST" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME RST.NOC_RST_N, INSERT_VIP 0, POLARITY ACTIVE_LOW" *) input noc_rst_n;


endmodule
