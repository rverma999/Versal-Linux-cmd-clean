//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2024.1 (lin64) Build 5076996 Wed May 22 18:36:09 MDT 2024
//Date        : Sat May 17 12:56:54 2025
//Host        : waiter running 64-bit Ubuntu 22.04.5 LTS
//Command     : generate_target vitis_design_wrapper.bd
//Design      : vitis_design_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module vitis_design_wrapper
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
  output [5:0]ch0_lpddr4_c0_ca_a;
  output [5:0]ch0_lpddr4_c0_ca_b;
  output ch0_lpddr4_c0_ck_c_a;
  output ch0_lpddr4_c0_ck_c_b;
  output ch0_lpddr4_c0_ck_t_a;
  output ch0_lpddr4_c0_ck_t_b;
  output ch0_lpddr4_c0_cke_a;
  output ch0_lpddr4_c0_cke_b;
  output ch0_lpddr4_c0_cs_a;
  output ch0_lpddr4_c0_cs_b;
  inout [1:0]ch0_lpddr4_c0_dmi_a;
  inout [1:0]ch0_lpddr4_c0_dmi_b;
  inout [15:0]ch0_lpddr4_c0_dq_a;
  inout [15:0]ch0_lpddr4_c0_dq_b;
  inout [1:0]ch0_lpddr4_c0_dqs_c_a;
  inout [1:0]ch0_lpddr4_c0_dqs_c_b;
  inout [1:0]ch0_lpddr4_c0_dqs_t_a;
  inout [1:0]ch0_lpddr4_c0_dqs_t_b;
  output ch0_lpddr4_c0_reset_n;
  output [5:0]ch0_lpddr4_c1_ca_a;
  output [5:0]ch0_lpddr4_c1_ca_b;
  output ch0_lpddr4_c1_ck_c_a;
  output ch0_lpddr4_c1_ck_c_b;
  output ch0_lpddr4_c1_ck_t_a;
  output ch0_lpddr4_c1_ck_t_b;
  output ch0_lpddr4_c1_cke_a;
  output ch0_lpddr4_c1_cke_b;
  output ch0_lpddr4_c1_cs_a;
  output ch0_lpddr4_c1_cs_b;
  inout [1:0]ch0_lpddr4_c1_dmi_a;
  inout [1:0]ch0_lpddr4_c1_dmi_b;
  inout [15:0]ch0_lpddr4_c1_dq_a;
  inout [15:0]ch0_lpddr4_c1_dq_b;
  inout [1:0]ch0_lpddr4_c1_dqs_c_a;
  inout [1:0]ch0_lpddr4_c1_dqs_c_b;
  inout [1:0]ch0_lpddr4_c1_dqs_t_a;
  inout [1:0]ch0_lpddr4_c1_dqs_t_b;
  output ch0_lpddr4_c1_reset_n;
  output [5:0]ch1_lpddr4_c0_ca_a;
  output [5:0]ch1_lpddr4_c0_ca_b;
  output ch1_lpddr4_c0_ck_c_a;
  output ch1_lpddr4_c0_ck_c_b;
  output ch1_lpddr4_c0_ck_t_a;
  output ch1_lpddr4_c0_ck_t_b;
  output ch1_lpddr4_c0_cke_a;
  output ch1_lpddr4_c0_cke_b;
  output ch1_lpddr4_c0_cs_a;
  output ch1_lpddr4_c0_cs_b;
  inout [1:0]ch1_lpddr4_c0_dmi_a;
  inout [1:0]ch1_lpddr4_c0_dmi_b;
  inout [15:0]ch1_lpddr4_c0_dq_a;
  inout [15:0]ch1_lpddr4_c0_dq_b;
  inout [1:0]ch1_lpddr4_c0_dqs_c_a;
  inout [1:0]ch1_lpddr4_c0_dqs_c_b;
  inout [1:0]ch1_lpddr4_c0_dqs_t_a;
  inout [1:0]ch1_lpddr4_c0_dqs_t_b;
  output ch1_lpddr4_c0_reset_n;
  output [5:0]ch1_lpddr4_c1_ca_a;
  output [5:0]ch1_lpddr4_c1_ca_b;
  output ch1_lpddr4_c1_ck_c_a;
  output ch1_lpddr4_c1_ck_c_b;
  output ch1_lpddr4_c1_ck_t_a;
  output ch1_lpddr4_c1_ck_t_b;
  output ch1_lpddr4_c1_cke_a;
  output ch1_lpddr4_c1_cke_b;
  output ch1_lpddr4_c1_cs_a;
  output ch1_lpddr4_c1_cs_b;
  inout [1:0]ch1_lpddr4_c1_dmi_a;
  inout [1:0]ch1_lpddr4_c1_dmi_b;
  inout [15:0]ch1_lpddr4_c1_dq_a;
  inout [15:0]ch1_lpddr4_c1_dq_b;
  inout [1:0]ch1_lpddr4_c1_dqs_c_a;
  inout [1:0]ch1_lpddr4_c1_dqs_c_b;
  inout [1:0]ch1_lpddr4_c1_dqs_t_a;
  inout [1:0]ch1_lpddr4_c1_dqs_t_b;
  output ch1_lpddr4_c1_reset_n;
  output ddr4_dimm1_act_n;
  output [16:0]ddr4_dimm1_adr;
  output [1:0]ddr4_dimm1_ba;
  output [1:0]ddr4_dimm1_bg;
  output ddr4_dimm1_ck_c;
  output ddr4_dimm1_ck_t;
  output ddr4_dimm1_cke;
  output ddr4_dimm1_cs_n;
  inout [7:0]ddr4_dimm1_dm_n;
  inout [63:0]ddr4_dimm1_dq;
  inout [7:0]ddr4_dimm1_dqs_c;
  inout [7:0]ddr4_dimm1_dqs_t;
  output ddr4_dimm1_odt;
  output ddr4_dimm1_reset_n;
  input ddr4_dimm1_sma_clk_clk_n;
  input ddr4_dimm1_sma_clk_clk_p;
  input lpddr4_sma_clk1_clk_n;
  input lpddr4_sma_clk1_clk_p;
  input lpddr4_sma_clk2_clk_n;
  input lpddr4_sma_clk2_clk_p;

  wire [5:0]ch0_lpddr4_c0_ca_a;
  wire [5:0]ch0_lpddr4_c0_ca_b;
  wire ch0_lpddr4_c0_ck_c_a;
  wire ch0_lpddr4_c0_ck_c_b;
  wire ch0_lpddr4_c0_ck_t_a;
  wire ch0_lpddr4_c0_ck_t_b;
  wire ch0_lpddr4_c0_cke_a;
  wire ch0_lpddr4_c0_cke_b;
  wire ch0_lpddr4_c0_cs_a;
  wire ch0_lpddr4_c0_cs_b;
  wire [1:0]ch0_lpddr4_c0_dmi_a;
  wire [1:0]ch0_lpddr4_c0_dmi_b;
  wire [15:0]ch0_lpddr4_c0_dq_a;
  wire [15:0]ch0_lpddr4_c0_dq_b;
  wire [1:0]ch0_lpddr4_c0_dqs_c_a;
  wire [1:0]ch0_lpddr4_c0_dqs_c_b;
  wire [1:0]ch0_lpddr4_c0_dqs_t_a;
  wire [1:0]ch0_lpddr4_c0_dqs_t_b;
  wire ch0_lpddr4_c0_reset_n;
  wire [5:0]ch0_lpddr4_c1_ca_a;
  wire [5:0]ch0_lpddr4_c1_ca_b;
  wire ch0_lpddr4_c1_ck_c_a;
  wire ch0_lpddr4_c1_ck_c_b;
  wire ch0_lpddr4_c1_ck_t_a;
  wire ch0_lpddr4_c1_ck_t_b;
  wire ch0_lpddr4_c1_cke_a;
  wire ch0_lpddr4_c1_cke_b;
  wire ch0_lpddr4_c1_cs_a;
  wire ch0_lpddr4_c1_cs_b;
  wire [1:0]ch0_lpddr4_c1_dmi_a;
  wire [1:0]ch0_lpddr4_c1_dmi_b;
  wire [15:0]ch0_lpddr4_c1_dq_a;
  wire [15:0]ch0_lpddr4_c1_dq_b;
  wire [1:0]ch0_lpddr4_c1_dqs_c_a;
  wire [1:0]ch0_lpddr4_c1_dqs_c_b;
  wire [1:0]ch0_lpddr4_c1_dqs_t_a;
  wire [1:0]ch0_lpddr4_c1_dqs_t_b;
  wire ch0_lpddr4_c1_reset_n;
  wire [5:0]ch1_lpddr4_c0_ca_a;
  wire [5:0]ch1_lpddr4_c0_ca_b;
  wire ch1_lpddr4_c0_ck_c_a;
  wire ch1_lpddr4_c0_ck_c_b;
  wire ch1_lpddr4_c0_ck_t_a;
  wire ch1_lpddr4_c0_ck_t_b;
  wire ch1_lpddr4_c0_cke_a;
  wire ch1_lpddr4_c0_cke_b;
  wire ch1_lpddr4_c0_cs_a;
  wire ch1_lpddr4_c0_cs_b;
  wire [1:0]ch1_lpddr4_c0_dmi_a;
  wire [1:0]ch1_lpddr4_c0_dmi_b;
  wire [15:0]ch1_lpddr4_c0_dq_a;
  wire [15:0]ch1_lpddr4_c0_dq_b;
  wire [1:0]ch1_lpddr4_c0_dqs_c_a;
  wire [1:0]ch1_lpddr4_c0_dqs_c_b;
  wire [1:0]ch1_lpddr4_c0_dqs_t_a;
  wire [1:0]ch1_lpddr4_c0_dqs_t_b;
  wire ch1_lpddr4_c0_reset_n;
  wire [5:0]ch1_lpddr4_c1_ca_a;
  wire [5:0]ch1_lpddr4_c1_ca_b;
  wire ch1_lpddr4_c1_ck_c_a;
  wire ch1_lpddr4_c1_ck_c_b;
  wire ch1_lpddr4_c1_ck_t_a;
  wire ch1_lpddr4_c1_ck_t_b;
  wire ch1_lpddr4_c1_cke_a;
  wire ch1_lpddr4_c1_cke_b;
  wire ch1_lpddr4_c1_cs_a;
  wire ch1_lpddr4_c1_cs_b;
  wire [1:0]ch1_lpddr4_c1_dmi_a;
  wire [1:0]ch1_lpddr4_c1_dmi_b;
  wire [15:0]ch1_lpddr4_c1_dq_a;
  wire [15:0]ch1_lpddr4_c1_dq_b;
  wire [1:0]ch1_lpddr4_c1_dqs_c_a;
  wire [1:0]ch1_lpddr4_c1_dqs_c_b;
  wire [1:0]ch1_lpddr4_c1_dqs_t_a;
  wire [1:0]ch1_lpddr4_c1_dqs_t_b;
  wire ch1_lpddr4_c1_reset_n;
  wire ddr4_dimm1_act_n;
  wire [16:0]ddr4_dimm1_adr;
  wire [1:0]ddr4_dimm1_ba;
  wire [1:0]ddr4_dimm1_bg;
  wire ddr4_dimm1_ck_c;
  wire ddr4_dimm1_ck_t;
  wire ddr4_dimm1_cke;
  wire ddr4_dimm1_cs_n;
  wire [7:0]ddr4_dimm1_dm_n;
  wire [63:0]ddr4_dimm1_dq;
  wire [7:0]ddr4_dimm1_dqs_c;
  wire [7:0]ddr4_dimm1_dqs_t;
  wire ddr4_dimm1_odt;
  wire ddr4_dimm1_reset_n;
  wire ddr4_dimm1_sma_clk_clk_n;
  wire ddr4_dimm1_sma_clk_clk_p;
  wire lpddr4_sma_clk1_clk_n;
  wire lpddr4_sma_clk1_clk_p;
  wire lpddr4_sma_clk2_clk_n;
  wire lpddr4_sma_clk2_clk_p;

  vitis_design vitis_design_i
       (.ch0_lpddr4_c0_ca_a(ch0_lpddr4_c0_ca_a),
        .ch0_lpddr4_c0_ca_b(ch0_lpddr4_c0_ca_b),
        .ch0_lpddr4_c0_ck_c_a(ch0_lpddr4_c0_ck_c_a),
        .ch0_lpddr4_c0_ck_c_b(ch0_lpddr4_c0_ck_c_b),
        .ch0_lpddr4_c0_ck_t_a(ch0_lpddr4_c0_ck_t_a),
        .ch0_lpddr4_c0_ck_t_b(ch0_lpddr4_c0_ck_t_b),
        .ch0_lpddr4_c0_cke_a(ch0_lpddr4_c0_cke_a),
        .ch0_lpddr4_c0_cke_b(ch0_lpddr4_c0_cke_b),
        .ch0_lpddr4_c0_cs_a(ch0_lpddr4_c0_cs_a),
        .ch0_lpddr4_c0_cs_b(ch0_lpddr4_c0_cs_b),
        .ch0_lpddr4_c0_dmi_a(ch0_lpddr4_c0_dmi_a),
        .ch0_lpddr4_c0_dmi_b(ch0_lpddr4_c0_dmi_b),
        .ch0_lpddr4_c0_dq_a(ch0_lpddr4_c0_dq_a),
        .ch0_lpddr4_c0_dq_b(ch0_lpddr4_c0_dq_b),
        .ch0_lpddr4_c0_dqs_c_a(ch0_lpddr4_c0_dqs_c_a),
        .ch0_lpddr4_c0_dqs_c_b(ch0_lpddr4_c0_dqs_c_b),
        .ch0_lpddr4_c0_dqs_t_a(ch0_lpddr4_c0_dqs_t_a),
        .ch0_lpddr4_c0_dqs_t_b(ch0_lpddr4_c0_dqs_t_b),
        .ch0_lpddr4_c0_reset_n(ch0_lpddr4_c0_reset_n),
        .ch0_lpddr4_c1_ca_a(ch0_lpddr4_c1_ca_a),
        .ch0_lpddr4_c1_ca_b(ch0_lpddr4_c1_ca_b),
        .ch0_lpddr4_c1_ck_c_a(ch0_lpddr4_c1_ck_c_a),
        .ch0_lpddr4_c1_ck_c_b(ch0_lpddr4_c1_ck_c_b),
        .ch0_lpddr4_c1_ck_t_a(ch0_lpddr4_c1_ck_t_a),
        .ch0_lpddr4_c1_ck_t_b(ch0_lpddr4_c1_ck_t_b),
        .ch0_lpddr4_c1_cke_a(ch0_lpddr4_c1_cke_a),
        .ch0_lpddr4_c1_cke_b(ch0_lpddr4_c1_cke_b),
        .ch0_lpddr4_c1_cs_a(ch0_lpddr4_c1_cs_a),
        .ch0_lpddr4_c1_cs_b(ch0_lpddr4_c1_cs_b),
        .ch0_lpddr4_c1_dmi_a(ch0_lpddr4_c1_dmi_a),
        .ch0_lpddr4_c1_dmi_b(ch0_lpddr4_c1_dmi_b),
        .ch0_lpddr4_c1_dq_a(ch0_lpddr4_c1_dq_a),
        .ch0_lpddr4_c1_dq_b(ch0_lpddr4_c1_dq_b),
        .ch0_lpddr4_c1_dqs_c_a(ch0_lpddr4_c1_dqs_c_a),
        .ch0_lpddr4_c1_dqs_c_b(ch0_lpddr4_c1_dqs_c_b),
        .ch0_lpddr4_c1_dqs_t_a(ch0_lpddr4_c1_dqs_t_a),
        .ch0_lpddr4_c1_dqs_t_b(ch0_lpddr4_c1_dqs_t_b),
        .ch0_lpddr4_c1_reset_n(ch0_lpddr4_c1_reset_n),
        .ch1_lpddr4_c0_ca_a(ch1_lpddr4_c0_ca_a),
        .ch1_lpddr4_c0_ca_b(ch1_lpddr4_c0_ca_b),
        .ch1_lpddr4_c0_ck_c_a(ch1_lpddr4_c0_ck_c_a),
        .ch1_lpddr4_c0_ck_c_b(ch1_lpddr4_c0_ck_c_b),
        .ch1_lpddr4_c0_ck_t_a(ch1_lpddr4_c0_ck_t_a),
        .ch1_lpddr4_c0_ck_t_b(ch1_lpddr4_c0_ck_t_b),
        .ch1_lpddr4_c0_cke_a(ch1_lpddr4_c0_cke_a),
        .ch1_lpddr4_c0_cke_b(ch1_lpddr4_c0_cke_b),
        .ch1_lpddr4_c0_cs_a(ch1_lpddr4_c0_cs_a),
        .ch1_lpddr4_c0_cs_b(ch1_lpddr4_c0_cs_b),
        .ch1_lpddr4_c0_dmi_a(ch1_lpddr4_c0_dmi_a),
        .ch1_lpddr4_c0_dmi_b(ch1_lpddr4_c0_dmi_b),
        .ch1_lpddr4_c0_dq_a(ch1_lpddr4_c0_dq_a),
        .ch1_lpddr4_c0_dq_b(ch1_lpddr4_c0_dq_b),
        .ch1_lpddr4_c0_dqs_c_a(ch1_lpddr4_c0_dqs_c_a),
        .ch1_lpddr4_c0_dqs_c_b(ch1_lpddr4_c0_dqs_c_b),
        .ch1_lpddr4_c0_dqs_t_a(ch1_lpddr4_c0_dqs_t_a),
        .ch1_lpddr4_c0_dqs_t_b(ch1_lpddr4_c0_dqs_t_b),
        .ch1_lpddr4_c0_reset_n(ch1_lpddr4_c0_reset_n),
        .ch1_lpddr4_c1_ca_a(ch1_lpddr4_c1_ca_a),
        .ch1_lpddr4_c1_ca_b(ch1_lpddr4_c1_ca_b),
        .ch1_lpddr4_c1_ck_c_a(ch1_lpddr4_c1_ck_c_a),
        .ch1_lpddr4_c1_ck_c_b(ch1_lpddr4_c1_ck_c_b),
        .ch1_lpddr4_c1_ck_t_a(ch1_lpddr4_c1_ck_t_a),
        .ch1_lpddr4_c1_ck_t_b(ch1_lpddr4_c1_ck_t_b),
        .ch1_lpddr4_c1_cke_a(ch1_lpddr4_c1_cke_a),
        .ch1_lpddr4_c1_cke_b(ch1_lpddr4_c1_cke_b),
        .ch1_lpddr4_c1_cs_a(ch1_lpddr4_c1_cs_a),
        .ch1_lpddr4_c1_cs_b(ch1_lpddr4_c1_cs_b),
        .ch1_lpddr4_c1_dmi_a(ch1_lpddr4_c1_dmi_a),
        .ch1_lpddr4_c1_dmi_b(ch1_lpddr4_c1_dmi_b),
        .ch1_lpddr4_c1_dq_a(ch1_lpddr4_c1_dq_a),
        .ch1_lpddr4_c1_dq_b(ch1_lpddr4_c1_dq_b),
        .ch1_lpddr4_c1_dqs_c_a(ch1_lpddr4_c1_dqs_c_a),
        .ch1_lpddr4_c1_dqs_c_b(ch1_lpddr4_c1_dqs_c_b),
        .ch1_lpddr4_c1_dqs_t_a(ch1_lpddr4_c1_dqs_t_a),
        .ch1_lpddr4_c1_dqs_t_b(ch1_lpddr4_c1_dqs_t_b),
        .ch1_lpddr4_c1_reset_n(ch1_lpddr4_c1_reset_n),
        .ddr4_dimm1_act_n(ddr4_dimm1_act_n),
        .ddr4_dimm1_adr(ddr4_dimm1_adr),
        .ddr4_dimm1_ba(ddr4_dimm1_ba),
        .ddr4_dimm1_bg(ddr4_dimm1_bg),
        .ddr4_dimm1_ck_c(ddr4_dimm1_ck_c),
        .ddr4_dimm1_ck_t(ddr4_dimm1_ck_t),
        .ddr4_dimm1_cke(ddr4_dimm1_cke),
        .ddr4_dimm1_cs_n(ddr4_dimm1_cs_n),
        .ddr4_dimm1_dm_n(ddr4_dimm1_dm_n),
        .ddr4_dimm1_dq(ddr4_dimm1_dq),
        .ddr4_dimm1_dqs_c(ddr4_dimm1_dqs_c),
        .ddr4_dimm1_dqs_t(ddr4_dimm1_dqs_t),
        .ddr4_dimm1_odt(ddr4_dimm1_odt),
        .ddr4_dimm1_reset_n(ddr4_dimm1_reset_n),
        .ddr4_dimm1_sma_clk_clk_n(ddr4_dimm1_sma_clk_clk_n),
        .ddr4_dimm1_sma_clk_clk_p(ddr4_dimm1_sma_clk_clk_p),
        .lpddr4_sma_clk1_clk_n(lpddr4_sma_clk1_clk_n),
        .lpddr4_sma_clk1_clk_p(lpddr4_sma_clk1_clk_p),
        .lpddr4_sma_clk2_clk_n(lpddr4_sma_clk2_clk_n),
        .lpddr4_sma_clk2_clk_p(lpddr4_sma_clk2_clk_p));
endmodule
