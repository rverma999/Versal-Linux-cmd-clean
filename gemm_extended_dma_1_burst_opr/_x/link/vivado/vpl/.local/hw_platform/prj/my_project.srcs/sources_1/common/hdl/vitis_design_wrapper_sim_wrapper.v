//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Design : vitis_design_wrapper_sim_wrapper
//Purpose: Everest Simulation Wrapper netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module vitis_design_wrapper_sim_wrapper
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

  wire [5:0]ch0_lpddr4_c0_ca_a_net;
  wire [5:0]ch0_lpddr4_c0_ca_b_net;
  wire ch0_lpddr4_c0_ck_c_a_net;
  wire ch0_lpddr4_c0_ck_c_b_net;
  wire ch0_lpddr4_c0_ck_t_a_net;
  wire ch0_lpddr4_c0_ck_t_b_net;
  wire ch0_lpddr4_c0_cke_a_net;
  wire ch0_lpddr4_c0_cke_b_net;
  wire ch0_lpddr4_c0_cs_a_net;
  wire ch0_lpddr4_c0_cs_b_net;
  wire [1:0]ch0_lpddr4_c0_dmi_a_net;
  wire [1:0]ch0_lpddr4_c0_dmi_b_net;
  wire [15:0]ch0_lpddr4_c0_dq_a_net;
  wire [15:0]ch0_lpddr4_c0_dq_b_net;
  wire [1:0]ch0_lpddr4_c0_dqs_c_a_net;
  wire [1:0]ch0_lpddr4_c0_dqs_c_b_net;
  wire [1:0]ch0_lpddr4_c0_dqs_t_a_net;
  wire [1:0]ch0_lpddr4_c0_dqs_t_b_net;
  wire ch0_lpddr4_c0_reset_n_net;
  wire [5:0]ch0_lpddr4_c1_ca_a_net;
  wire [5:0]ch0_lpddr4_c1_ca_b_net;
  wire ch0_lpddr4_c1_ck_c_a_net;
  wire ch0_lpddr4_c1_ck_c_b_net;
  wire ch0_lpddr4_c1_ck_t_a_net;
  wire ch0_lpddr4_c1_ck_t_b_net;
  wire ch0_lpddr4_c1_cke_a_net;
  wire ch0_lpddr4_c1_cke_b_net;
  wire ch0_lpddr4_c1_cs_a_net;
  wire ch0_lpddr4_c1_cs_b_net;
  wire [1:0]ch0_lpddr4_c1_dmi_a_net;
  wire [1:0]ch0_lpddr4_c1_dmi_b_net;
  wire [15:0]ch0_lpddr4_c1_dq_a_net;
  wire [15:0]ch0_lpddr4_c1_dq_b_net;
  wire [1:0]ch0_lpddr4_c1_dqs_c_a_net;
  wire [1:0]ch0_lpddr4_c1_dqs_c_b_net;
  wire [1:0]ch0_lpddr4_c1_dqs_t_a_net;
  wire [1:0]ch0_lpddr4_c1_dqs_t_b_net;
  wire ch0_lpddr4_c1_reset_n_net;
  wire [5:0]ch1_lpddr4_c0_ca_a_net;
  wire [5:0]ch1_lpddr4_c0_ca_b_net;
  wire ch1_lpddr4_c0_ck_c_a_net;
  wire ch1_lpddr4_c0_ck_c_b_net;
  wire ch1_lpddr4_c0_ck_t_a_net;
  wire ch1_lpddr4_c0_ck_t_b_net;
  wire ch1_lpddr4_c0_cke_a_net;
  wire ch1_lpddr4_c0_cke_b_net;
  wire ch1_lpddr4_c0_cs_a_net;
  wire ch1_lpddr4_c0_cs_b_net;
  wire [1:0]ch1_lpddr4_c0_dmi_a_net;
  wire [1:0]ch1_lpddr4_c0_dmi_b_net;
  wire [15:0]ch1_lpddr4_c0_dq_a_net;
  wire [15:0]ch1_lpddr4_c0_dq_b_net;
  wire [1:0]ch1_lpddr4_c0_dqs_c_a_net;
  wire [1:0]ch1_lpddr4_c0_dqs_c_b_net;
  wire [1:0]ch1_lpddr4_c0_dqs_t_a_net;
  wire [1:0]ch1_lpddr4_c0_dqs_t_b_net;
  wire ch1_lpddr4_c0_reset_n_net;
  wire [5:0]ch1_lpddr4_c1_ca_a_net;
  wire [5:0]ch1_lpddr4_c1_ca_b_net;
  wire ch1_lpddr4_c1_ck_c_a_net;
  wire ch1_lpddr4_c1_ck_c_b_net;
  wire ch1_lpddr4_c1_ck_t_a_net;
  wire ch1_lpddr4_c1_ck_t_b_net;
  wire ch1_lpddr4_c1_cke_a_net;
  wire ch1_lpddr4_c1_cke_b_net;
  wire ch1_lpddr4_c1_cs_a_net;
  wire ch1_lpddr4_c1_cs_b_net;
  wire [1:0]ch1_lpddr4_c1_dmi_a_net;
  wire [1:0]ch1_lpddr4_c1_dmi_b_net;
  wire [15:0]ch1_lpddr4_c1_dq_a_net;
  wire [15:0]ch1_lpddr4_c1_dq_b_net;
  wire [1:0]ch1_lpddr4_c1_dqs_c_a_net;
  wire [1:0]ch1_lpddr4_c1_dqs_c_b_net;
  wire [1:0]ch1_lpddr4_c1_dqs_t_a_net;
  wire [1:0]ch1_lpddr4_c1_dqs_t_b_net;
  wire ch1_lpddr4_c1_reset_n_net;
  wire ddr4_dimm1_act_n_net;
  wire [16:0]ddr4_dimm1_adr_net;
  wire [1:0]ddr4_dimm1_ba_net;
  wire [1:0]ddr4_dimm1_bg_net;
  wire ddr4_dimm1_ck_c_net;
  wire ddr4_dimm1_ck_t_net;
  wire ddr4_dimm1_cke_net;
  wire ddr4_dimm1_cs_n_net;
  wire [7:0]ddr4_dimm1_dm_n_net;
  wire [63:0]ddr4_dimm1_dq_net;
  wire [7:0]ddr4_dimm1_dqs_c_net;
  wire [7:0]ddr4_dimm1_dqs_t_net;
  wire ddr4_dimm1_odt_net;
  wire ddr4_dimm1_reset_n_net;
  wire ddr4_dimm1_sma_clk_clk_n_net;
  wire ddr4_dimm1_sma_clk_clk_p_net;
  wire lpddr4_sma_clk1_clk_n_net;
  wire lpddr4_sma_clk1_clk_p_net;
  wire lpddr4_sma_clk2_clk_n_net;
  wire lpddr4_sma_clk2_clk_p_net;
  wire noc_clk_net;
  wire noc_rst_n_net;

  assign ch0_lpddr4_c0_ca_a[5:0] = ch0_lpddr4_c0_ca_a_net;
  assign ch0_lpddr4_c0_ca_b[5:0] = ch0_lpddr4_c0_ca_b_net;
  assign ch0_lpddr4_c0_ck_c_a = ch0_lpddr4_c0_ck_c_a_net;
  assign ch0_lpddr4_c0_ck_c_b = ch0_lpddr4_c0_ck_c_b_net;
  assign ch0_lpddr4_c0_ck_t_a = ch0_lpddr4_c0_ck_t_a_net;
  assign ch0_lpddr4_c0_ck_t_b = ch0_lpddr4_c0_ck_t_b_net;
  assign ch0_lpddr4_c0_cke_a = ch0_lpddr4_c0_cke_a_net;
  assign ch0_lpddr4_c0_cke_b = ch0_lpddr4_c0_cke_b_net;
  assign ch0_lpddr4_c0_cs_a = ch0_lpddr4_c0_cs_a_net;
  assign ch0_lpddr4_c0_cs_b = ch0_lpddr4_c0_cs_b_net;
  assign ch0_lpddr4_c0_reset_n = ch0_lpddr4_c0_reset_n_net;
  assign ch0_lpddr4_c1_ca_a[5:0] = ch0_lpddr4_c1_ca_a_net;
  assign ch0_lpddr4_c1_ca_b[5:0] = ch0_lpddr4_c1_ca_b_net;
  assign ch0_lpddr4_c1_ck_c_a = ch0_lpddr4_c1_ck_c_a_net;
  assign ch0_lpddr4_c1_ck_c_b = ch0_lpddr4_c1_ck_c_b_net;
  assign ch0_lpddr4_c1_ck_t_a = ch0_lpddr4_c1_ck_t_a_net;
  assign ch0_lpddr4_c1_ck_t_b = ch0_lpddr4_c1_ck_t_b_net;
  assign ch0_lpddr4_c1_cke_a = ch0_lpddr4_c1_cke_a_net;
  assign ch0_lpddr4_c1_cke_b = ch0_lpddr4_c1_cke_b_net;
  assign ch0_lpddr4_c1_cs_a = ch0_lpddr4_c1_cs_a_net;
  assign ch0_lpddr4_c1_cs_b = ch0_lpddr4_c1_cs_b_net;
  assign ch0_lpddr4_c1_reset_n = ch0_lpddr4_c1_reset_n_net;
  assign ch1_lpddr4_c0_ca_a[5:0] = ch1_lpddr4_c0_ca_a_net;
  assign ch1_lpddr4_c0_ca_b[5:0] = ch1_lpddr4_c0_ca_b_net;
  assign ch1_lpddr4_c0_ck_c_a = ch1_lpddr4_c0_ck_c_a_net;
  assign ch1_lpddr4_c0_ck_c_b = ch1_lpddr4_c0_ck_c_b_net;
  assign ch1_lpddr4_c0_ck_t_a = ch1_lpddr4_c0_ck_t_a_net;
  assign ch1_lpddr4_c0_ck_t_b = ch1_lpddr4_c0_ck_t_b_net;
  assign ch1_lpddr4_c0_cke_a = ch1_lpddr4_c0_cke_a_net;
  assign ch1_lpddr4_c0_cke_b = ch1_lpddr4_c0_cke_b_net;
  assign ch1_lpddr4_c0_cs_a = ch1_lpddr4_c0_cs_a_net;
  assign ch1_lpddr4_c0_cs_b = ch1_lpddr4_c0_cs_b_net;
  assign ch1_lpddr4_c0_reset_n = ch1_lpddr4_c0_reset_n_net;
  assign ch1_lpddr4_c1_ca_a[5:0] = ch1_lpddr4_c1_ca_a_net;
  assign ch1_lpddr4_c1_ca_b[5:0] = ch1_lpddr4_c1_ca_b_net;
  assign ch1_lpddr4_c1_ck_c_a = ch1_lpddr4_c1_ck_c_a_net;
  assign ch1_lpddr4_c1_ck_c_b = ch1_lpddr4_c1_ck_c_b_net;
  assign ch1_lpddr4_c1_ck_t_a = ch1_lpddr4_c1_ck_t_a_net;
  assign ch1_lpddr4_c1_ck_t_b = ch1_lpddr4_c1_ck_t_b_net;
  assign ch1_lpddr4_c1_cke_a = ch1_lpddr4_c1_cke_a_net;
  assign ch1_lpddr4_c1_cke_b = ch1_lpddr4_c1_cke_b_net;
  assign ch1_lpddr4_c1_cs_a = ch1_lpddr4_c1_cs_a_net;
  assign ch1_lpddr4_c1_cs_b = ch1_lpddr4_c1_cs_b_net;
  assign ch1_lpddr4_c1_reset_n = ch1_lpddr4_c1_reset_n_net;
  assign ddr4_dimm1_act_n = ddr4_dimm1_act_n_net;
  assign ddr4_dimm1_adr[16:0] = ddr4_dimm1_adr_net;
  assign ddr4_dimm1_ba[1:0] = ddr4_dimm1_ba_net;
  assign ddr4_dimm1_bg[1:0] = ddr4_dimm1_bg_net;
  assign ddr4_dimm1_ck_c = ddr4_dimm1_ck_c_net;
  assign ddr4_dimm1_ck_t = ddr4_dimm1_ck_t_net;
  assign ddr4_dimm1_cke = ddr4_dimm1_cke_net;
  assign ddr4_dimm1_cs_n = ddr4_dimm1_cs_n_net;
  assign ddr4_dimm1_odt = ddr4_dimm1_odt_net;
  assign ddr4_dimm1_reset_n = ddr4_dimm1_reset_n_net;
  assign ddr4_dimm1_sma_clk_clk_n_net = ddr4_dimm1_sma_clk_clk_n;
  assign ddr4_dimm1_sma_clk_clk_p_net = ddr4_dimm1_sma_clk_clk_p;
  assign lpddr4_sma_clk1_clk_n_net = lpddr4_sma_clk1_clk_n;
  assign lpddr4_sma_clk1_clk_p_net = lpddr4_sma_clk1_clk_p;
  assign lpddr4_sma_clk2_clk_n_net = lpddr4_sma_clk2_clk_n;
  assign lpddr4_sma_clk2_clk_p_net = lpddr4_sma_clk2_clk_p;
  vitis_design_wrapper vitis_design_wrapper_i
       (.ch0_lpddr4_c0_ca_a(ch0_lpddr4_c0_ca_a_net),
        .ch0_lpddr4_c0_ca_b(ch0_lpddr4_c0_ca_b_net),
        .ch0_lpddr4_c0_ck_c_a(ch0_lpddr4_c0_ck_c_a_net),
        .ch0_lpddr4_c0_ck_c_b(ch0_lpddr4_c0_ck_c_b_net),
        .ch0_lpddr4_c0_ck_t_a(ch0_lpddr4_c0_ck_t_a_net),
        .ch0_lpddr4_c0_ck_t_b(ch0_lpddr4_c0_ck_t_b_net),
        .ch0_lpddr4_c0_cke_a(ch0_lpddr4_c0_cke_a_net),
        .ch0_lpddr4_c0_cke_b(ch0_lpddr4_c0_cke_b_net),
        .ch0_lpddr4_c0_cs_a(ch0_lpddr4_c0_cs_a_net),
        .ch0_lpddr4_c0_cs_b(ch0_lpddr4_c0_cs_b_net),
        .ch0_lpddr4_c0_dmi_a(ch0_lpddr4_c0_dmi_a[1:0]),
        .ch0_lpddr4_c0_dmi_b(ch0_lpddr4_c0_dmi_b[1:0]),
        .ch0_lpddr4_c0_dq_a(ch0_lpddr4_c0_dq_a[15:0]),
        .ch0_lpddr4_c0_dq_b(ch0_lpddr4_c0_dq_b[15:0]),
        .ch0_lpddr4_c0_dqs_c_a(ch0_lpddr4_c0_dqs_c_a[1:0]),
        .ch0_lpddr4_c0_dqs_c_b(ch0_lpddr4_c0_dqs_c_b[1:0]),
        .ch0_lpddr4_c0_dqs_t_a(ch0_lpddr4_c0_dqs_t_a[1:0]),
        .ch0_lpddr4_c0_dqs_t_b(ch0_lpddr4_c0_dqs_t_b[1:0]),
        .ch0_lpddr4_c0_reset_n(ch0_lpddr4_c0_reset_n_net),
        .ch0_lpddr4_c1_ca_a(ch0_lpddr4_c1_ca_a_net),
        .ch0_lpddr4_c1_ca_b(ch0_lpddr4_c1_ca_b_net),
        .ch0_lpddr4_c1_ck_c_a(ch0_lpddr4_c1_ck_c_a_net),
        .ch0_lpddr4_c1_ck_c_b(ch0_lpddr4_c1_ck_c_b_net),
        .ch0_lpddr4_c1_ck_t_a(ch0_lpddr4_c1_ck_t_a_net),
        .ch0_lpddr4_c1_ck_t_b(ch0_lpddr4_c1_ck_t_b_net),
        .ch0_lpddr4_c1_cke_a(ch0_lpddr4_c1_cke_a_net),
        .ch0_lpddr4_c1_cke_b(ch0_lpddr4_c1_cke_b_net),
        .ch0_lpddr4_c1_cs_a(ch0_lpddr4_c1_cs_a_net),
        .ch0_lpddr4_c1_cs_b(ch0_lpddr4_c1_cs_b_net),
        .ch0_lpddr4_c1_dmi_a(ch0_lpddr4_c1_dmi_a[1:0]),
        .ch0_lpddr4_c1_dmi_b(ch0_lpddr4_c1_dmi_b[1:0]),
        .ch0_lpddr4_c1_dq_a(ch0_lpddr4_c1_dq_a[15:0]),
        .ch0_lpddr4_c1_dq_b(ch0_lpddr4_c1_dq_b[15:0]),
        .ch0_lpddr4_c1_dqs_c_a(ch0_lpddr4_c1_dqs_c_a[1:0]),
        .ch0_lpddr4_c1_dqs_c_b(ch0_lpddr4_c1_dqs_c_b[1:0]),
        .ch0_lpddr4_c1_dqs_t_a(ch0_lpddr4_c1_dqs_t_a[1:0]),
        .ch0_lpddr4_c1_dqs_t_b(ch0_lpddr4_c1_dqs_t_b[1:0]),
        .ch0_lpddr4_c1_reset_n(ch0_lpddr4_c1_reset_n_net),
        .ch1_lpddr4_c0_ca_a(ch1_lpddr4_c0_ca_a_net),
        .ch1_lpddr4_c0_ca_b(ch1_lpddr4_c0_ca_b_net),
        .ch1_lpddr4_c0_ck_c_a(ch1_lpddr4_c0_ck_c_a_net),
        .ch1_lpddr4_c0_ck_c_b(ch1_lpddr4_c0_ck_c_b_net),
        .ch1_lpddr4_c0_ck_t_a(ch1_lpddr4_c0_ck_t_a_net),
        .ch1_lpddr4_c0_ck_t_b(ch1_lpddr4_c0_ck_t_b_net),
        .ch1_lpddr4_c0_cke_a(ch1_lpddr4_c0_cke_a_net),
        .ch1_lpddr4_c0_cke_b(ch1_lpddr4_c0_cke_b_net),
        .ch1_lpddr4_c0_cs_a(ch1_lpddr4_c0_cs_a_net),
        .ch1_lpddr4_c0_cs_b(ch1_lpddr4_c0_cs_b_net),
        .ch1_lpddr4_c0_dmi_a(ch1_lpddr4_c0_dmi_a[1:0]),
        .ch1_lpddr4_c0_dmi_b(ch1_lpddr4_c0_dmi_b[1:0]),
        .ch1_lpddr4_c0_dq_a(ch1_lpddr4_c0_dq_a[15:0]),
        .ch1_lpddr4_c0_dq_b(ch1_lpddr4_c0_dq_b[15:0]),
        .ch1_lpddr4_c0_dqs_c_a(ch1_lpddr4_c0_dqs_c_a[1:0]),
        .ch1_lpddr4_c0_dqs_c_b(ch1_lpddr4_c0_dqs_c_b[1:0]),
        .ch1_lpddr4_c0_dqs_t_a(ch1_lpddr4_c0_dqs_t_a[1:0]),
        .ch1_lpddr4_c0_dqs_t_b(ch1_lpddr4_c0_dqs_t_b[1:0]),
        .ch1_lpddr4_c0_reset_n(ch1_lpddr4_c0_reset_n_net),
        .ch1_lpddr4_c1_ca_a(ch1_lpddr4_c1_ca_a_net),
        .ch1_lpddr4_c1_ca_b(ch1_lpddr4_c1_ca_b_net),
        .ch1_lpddr4_c1_ck_c_a(ch1_lpddr4_c1_ck_c_a_net),
        .ch1_lpddr4_c1_ck_c_b(ch1_lpddr4_c1_ck_c_b_net),
        .ch1_lpddr4_c1_ck_t_a(ch1_lpddr4_c1_ck_t_a_net),
        .ch1_lpddr4_c1_ck_t_b(ch1_lpddr4_c1_ck_t_b_net),
        .ch1_lpddr4_c1_cke_a(ch1_lpddr4_c1_cke_a_net),
        .ch1_lpddr4_c1_cke_b(ch1_lpddr4_c1_cke_b_net),
        .ch1_lpddr4_c1_cs_a(ch1_lpddr4_c1_cs_a_net),
        .ch1_lpddr4_c1_cs_b(ch1_lpddr4_c1_cs_b_net),
        .ch1_lpddr4_c1_dmi_a(ch1_lpddr4_c1_dmi_a[1:0]),
        .ch1_lpddr4_c1_dmi_b(ch1_lpddr4_c1_dmi_b[1:0]),
        .ch1_lpddr4_c1_dq_a(ch1_lpddr4_c1_dq_a[15:0]),
        .ch1_lpddr4_c1_dq_b(ch1_lpddr4_c1_dq_b[15:0]),
        .ch1_lpddr4_c1_dqs_c_a(ch1_lpddr4_c1_dqs_c_a[1:0]),
        .ch1_lpddr4_c1_dqs_c_b(ch1_lpddr4_c1_dqs_c_b[1:0]),
        .ch1_lpddr4_c1_dqs_t_a(ch1_lpddr4_c1_dqs_t_a[1:0]),
        .ch1_lpddr4_c1_dqs_t_b(ch1_lpddr4_c1_dqs_t_b[1:0]),
        .ch1_lpddr4_c1_reset_n(ch1_lpddr4_c1_reset_n_net),
        .ddr4_dimm1_act_n(ddr4_dimm1_act_n_net),
        .ddr4_dimm1_adr(ddr4_dimm1_adr_net),
        .ddr4_dimm1_ba(ddr4_dimm1_ba_net),
        .ddr4_dimm1_bg(ddr4_dimm1_bg_net),
        .ddr4_dimm1_ck_c(ddr4_dimm1_ck_c_net),
        .ddr4_dimm1_ck_t(ddr4_dimm1_ck_t_net),
        .ddr4_dimm1_cke(ddr4_dimm1_cke_net),
        .ddr4_dimm1_cs_n(ddr4_dimm1_cs_n_net),
        .ddr4_dimm1_dm_n(ddr4_dimm1_dm_n[7:0]),
        .ddr4_dimm1_dq(ddr4_dimm1_dq[63:0]),
        .ddr4_dimm1_dqs_c(ddr4_dimm1_dqs_c[7:0]),
        .ddr4_dimm1_dqs_t(ddr4_dimm1_dqs_t[7:0]),
        .ddr4_dimm1_odt(ddr4_dimm1_odt_net),
        .ddr4_dimm1_reset_n(ddr4_dimm1_reset_n_net),
        .ddr4_dimm1_sma_clk_clk_n(ddr4_dimm1_sma_clk_clk_n_net),
        .ddr4_dimm1_sma_clk_clk_p(ddr4_dimm1_sma_clk_clk_p_net),
        .lpddr4_sma_clk1_clk_n(lpddr4_sma_clk1_clk_n_net),
        .lpddr4_sma_clk1_clk_p(lpddr4_sma_clk1_clk_p_net),
        .lpddr4_sma_clk2_clk_n(lpddr4_sma_clk2_clk_n_net),
        .lpddr4_sma_clk2_clk_p(lpddr4_sma_clk2_clk_p_net));
  xlnoc xlnoc_i
       (.noc_clk(noc_clk_net),
        .noc_rst_n(noc_rst_n_net));
endmodule
