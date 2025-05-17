//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2024.1 (lin64) Build 5076996 Wed May 22 18:36:09 MDT 2024
//Date        : Sat May 17 12:57:57 2025
//Host        : waiter running 64-bit Ubuntu 22.04.5 LTS
//Command     : generate_target xlnoc_wrapper.bd
//Design      : xlnoc_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module xlnoc_wrapper
   (noc_clk,
    noc_rst_n);
  input noc_clk;
  input noc_rst_n;

  wire noc_clk;
  wire noc_rst_n;

  xlnoc xlnoc_i
       (.noc_clk(noc_clk),
        .noc_rst_n(noc_rst_n));
endmodule
