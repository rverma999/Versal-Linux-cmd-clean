//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Command: generate_target bd_28ba_wrapper.bd
//Design : bd_28ba_wrapper
//Purpose: IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module bd_28ba_wrapper
   (CH0_LPDDR4_0_ca_a,
    CH0_LPDDR4_0_ca_b,
    CH0_LPDDR4_0_ck_c_a,
    CH0_LPDDR4_0_ck_c_b,
    CH0_LPDDR4_0_ck_t_a,
    CH0_LPDDR4_0_ck_t_b,
    CH0_LPDDR4_0_cke_a,
    CH0_LPDDR4_0_cke_b,
    CH0_LPDDR4_0_cs_a,
    CH0_LPDDR4_0_cs_b,
    CH0_LPDDR4_0_dmi_a,
    CH0_LPDDR4_0_dmi_b,
    CH0_LPDDR4_0_dq_a,
    CH0_LPDDR4_0_dq_b,
    CH0_LPDDR4_0_dqs_c_a,
    CH0_LPDDR4_0_dqs_c_b,
    CH0_LPDDR4_0_dqs_t_a,
    CH0_LPDDR4_0_dqs_t_b,
    CH0_LPDDR4_0_reset_n,
    CH0_LPDDR4_1_ca_a,
    CH0_LPDDR4_1_ca_b,
    CH0_LPDDR4_1_ck_c_a,
    CH0_LPDDR4_1_ck_c_b,
    CH0_LPDDR4_1_ck_t_a,
    CH0_LPDDR4_1_ck_t_b,
    CH0_LPDDR4_1_cke_a,
    CH0_LPDDR4_1_cke_b,
    CH0_LPDDR4_1_cs_a,
    CH0_LPDDR4_1_cs_b,
    CH0_LPDDR4_1_dmi_a,
    CH0_LPDDR4_1_dmi_b,
    CH0_LPDDR4_1_dq_a,
    CH0_LPDDR4_1_dq_b,
    CH0_LPDDR4_1_dqs_c_a,
    CH0_LPDDR4_1_dqs_c_b,
    CH0_LPDDR4_1_dqs_t_a,
    CH0_LPDDR4_1_dqs_t_b,
    CH0_LPDDR4_1_reset_n,
    CH1_LPDDR4_0_ca_a,
    CH1_LPDDR4_0_ca_b,
    CH1_LPDDR4_0_ck_c_a,
    CH1_LPDDR4_0_ck_c_b,
    CH1_LPDDR4_0_ck_t_a,
    CH1_LPDDR4_0_ck_t_b,
    CH1_LPDDR4_0_cke_a,
    CH1_LPDDR4_0_cke_b,
    CH1_LPDDR4_0_cs_a,
    CH1_LPDDR4_0_cs_b,
    CH1_LPDDR4_0_dmi_a,
    CH1_LPDDR4_0_dmi_b,
    CH1_LPDDR4_0_dq_a,
    CH1_LPDDR4_0_dq_b,
    CH1_LPDDR4_0_dqs_c_a,
    CH1_LPDDR4_0_dqs_c_b,
    CH1_LPDDR4_0_dqs_t_a,
    CH1_LPDDR4_0_dqs_t_b,
    CH1_LPDDR4_0_reset_n,
    CH1_LPDDR4_1_ca_a,
    CH1_LPDDR4_1_ca_b,
    CH1_LPDDR4_1_ck_c_a,
    CH1_LPDDR4_1_ck_c_b,
    CH1_LPDDR4_1_ck_t_a,
    CH1_LPDDR4_1_ck_t_b,
    CH1_LPDDR4_1_cke_a,
    CH1_LPDDR4_1_cke_b,
    CH1_LPDDR4_1_cs_a,
    CH1_LPDDR4_1_cs_b,
    CH1_LPDDR4_1_dmi_a,
    CH1_LPDDR4_1_dmi_b,
    CH1_LPDDR4_1_dq_a,
    CH1_LPDDR4_1_dq_b,
    CH1_LPDDR4_1_dqs_c_a,
    CH1_LPDDR4_1_dqs_c_b,
    CH1_LPDDR4_1_dqs_t_a,
    CH1_LPDDR4_1_dqs_t_b,
    CH1_LPDDR4_1_reset_n,
    S00_INI_internoc,
    S01_INI_internoc,
    S02_INI_internoc,
    S03_INI_internoc,
    sys_clk0_clk_n,
    sys_clk0_clk_p,
    sys_clk1_clk_n,
    sys_clk1_clk_p);
  output [5:0]CH0_LPDDR4_0_ca_a;
  output [5:0]CH0_LPDDR4_0_ca_b;
  output [0:0]CH0_LPDDR4_0_ck_c_a;
  output [0:0]CH0_LPDDR4_0_ck_c_b;
  output [0:0]CH0_LPDDR4_0_ck_t_a;
  output [0:0]CH0_LPDDR4_0_ck_t_b;
  output [0:0]CH0_LPDDR4_0_cke_a;
  output [0:0]CH0_LPDDR4_0_cke_b;
  output [0:0]CH0_LPDDR4_0_cs_a;
  output [0:0]CH0_LPDDR4_0_cs_b;
  inout [1:0]CH0_LPDDR4_0_dmi_a;
  inout [1:0]CH0_LPDDR4_0_dmi_b;
  inout [15:0]CH0_LPDDR4_0_dq_a;
  inout [15:0]CH0_LPDDR4_0_dq_b;
  inout [1:0]CH0_LPDDR4_0_dqs_c_a;
  inout [1:0]CH0_LPDDR4_0_dqs_c_b;
  inout [1:0]CH0_LPDDR4_0_dqs_t_a;
  inout [1:0]CH0_LPDDR4_0_dqs_t_b;
  output [0:0]CH0_LPDDR4_0_reset_n;
  output [5:0]CH0_LPDDR4_1_ca_a;
  output [5:0]CH0_LPDDR4_1_ca_b;
  output [0:0]CH0_LPDDR4_1_ck_c_a;
  output [0:0]CH0_LPDDR4_1_ck_c_b;
  output [0:0]CH0_LPDDR4_1_ck_t_a;
  output [0:0]CH0_LPDDR4_1_ck_t_b;
  output [0:0]CH0_LPDDR4_1_cke_a;
  output [0:0]CH0_LPDDR4_1_cke_b;
  output [0:0]CH0_LPDDR4_1_cs_a;
  output [0:0]CH0_LPDDR4_1_cs_b;
  inout [1:0]CH0_LPDDR4_1_dmi_a;
  inout [1:0]CH0_LPDDR4_1_dmi_b;
  inout [15:0]CH0_LPDDR4_1_dq_a;
  inout [15:0]CH0_LPDDR4_1_dq_b;
  inout [1:0]CH0_LPDDR4_1_dqs_c_a;
  inout [1:0]CH0_LPDDR4_1_dqs_c_b;
  inout [1:0]CH0_LPDDR4_1_dqs_t_a;
  inout [1:0]CH0_LPDDR4_1_dqs_t_b;
  output [0:0]CH0_LPDDR4_1_reset_n;
  output [5:0]CH1_LPDDR4_0_ca_a;
  output [5:0]CH1_LPDDR4_0_ca_b;
  output [0:0]CH1_LPDDR4_0_ck_c_a;
  output [0:0]CH1_LPDDR4_0_ck_c_b;
  output [0:0]CH1_LPDDR4_0_ck_t_a;
  output [0:0]CH1_LPDDR4_0_ck_t_b;
  output [0:0]CH1_LPDDR4_0_cke_a;
  output [0:0]CH1_LPDDR4_0_cke_b;
  output [0:0]CH1_LPDDR4_0_cs_a;
  output [0:0]CH1_LPDDR4_0_cs_b;
  inout [1:0]CH1_LPDDR4_0_dmi_a;
  inout [1:0]CH1_LPDDR4_0_dmi_b;
  inout [15:0]CH1_LPDDR4_0_dq_a;
  inout [15:0]CH1_LPDDR4_0_dq_b;
  inout [1:0]CH1_LPDDR4_0_dqs_c_a;
  inout [1:0]CH1_LPDDR4_0_dqs_c_b;
  inout [1:0]CH1_LPDDR4_0_dqs_t_a;
  inout [1:0]CH1_LPDDR4_0_dqs_t_b;
  output [0:0]CH1_LPDDR4_0_reset_n;
  output [5:0]CH1_LPDDR4_1_ca_a;
  output [5:0]CH1_LPDDR4_1_ca_b;
  output [0:0]CH1_LPDDR4_1_ck_c_a;
  output [0:0]CH1_LPDDR4_1_ck_c_b;
  output [0:0]CH1_LPDDR4_1_ck_t_a;
  output [0:0]CH1_LPDDR4_1_ck_t_b;
  output [0:0]CH1_LPDDR4_1_cke_a;
  output [0:0]CH1_LPDDR4_1_cke_b;
  output [0:0]CH1_LPDDR4_1_cs_a;
  output [0:0]CH1_LPDDR4_1_cs_b;
  inout [1:0]CH1_LPDDR4_1_dmi_a;
  inout [1:0]CH1_LPDDR4_1_dmi_b;
  inout [15:0]CH1_LPDDR4_1_dq_a;
  inout [15:0]CH1_LPDDR4_1_dq_b;
  inout [1:0]CH1_LPDDR4_1_dqs_c_a;
  inout [1:0]CH1_LPDDR4_1_dqs_c_b;
  inout [1:0]CH1_LPDDR4_1_dqs_t_a;
  inout [1:0]CH1_LPDDR4_1_dqs_t_b;
  output [0:0]CH1_LPDDR4_1_reset_n;
  input [0:0]S00_INI_internoc;
  input [0:0]S01_INI_internoc;
  input [0:0]S02_INI_internoc;
  input [0:0]S03_INI_internoc;
  input [0:0]sys_clk0_clk_n;
  input [0:0]sys_clk0_clk_p;
  input [0:0]sys_clk1_clk_n;
  input [0:0]sys_clk1_clk_p;

  wire [5:0]CH0_LPDDR4_0_ca_a;
  wire [5:0]CH0_LPDDR4_0_ca_b;
  wire [0:0]CH0_LPDDR4_0_ck_c_a;
  wire [0:0]CH0_LPDDR4_0_ck_c_b;
  wire [0:0]CH0_LPDDR4_0_ck_t_a;
  wire [0:0]CH0_LPDDR4_0_ck_t_b;
  wire [0:0]CH0_LPDDR4_0_cke_a;
  wire [0:0]CH0_LPDDR4_0_cke_b;
  wire [0:0]CH0_LPDDR4_0_cs_a;
  wire [0:0]CH0_LPDDR4_0_cs_b;
  wire [1:0]CH0_LPDDR4_0_dmi_a;
  wire [1:0]CH0_LPDDR4_0_dmi_b;
  wire [15:0]CH0_LPDDR4_0_dq_a;
  wire [15:0]CH0_LPDDR4_0_dq_b;
  wire [1:0]CH0_LPDDR4_0_dqs_c_a;
  wire [1:0]CH0_LPDDR4_0_dqs_c_b;
  wire [1:0]CH0_LPDDR4_0_dqs_t_a;
  wire [1:0]CH0_LPDDR4_0_dqs_t_b;
  wire [0:0]CH0_LPDDR4_0_reset_n;
  wire [5:0]CH0_LPDDR4_1_ca_a;
  wire [5:0]CH0_LPDDR4_1_ca_b;
  wire [0:0]CH0_LPDDR4_1_ck_c_a;
  wire [0:0]CH0_LPDDR4_1_ck_c_b;
  wire [0:0]CH0_LPDDR4_1_ck_t_a;
  wire [0:0]CH0_LPDDR4_1_ck_t_b;
  wire [0:0]CH0_LPDDR4_1_cke_a;
  wire [0:0]CH0_LPDDR4_1_cke_b;
  wire [0:0]CH0_LPDDR4_1_cs_a;
  wire [0:0]CH0_LPDDR4_1_cs_b;
  wire [1:0]CH0_LPDDR4_1_dmi_a;
  wire [1:0]CH0_LPDDR4_1_dmi_b;
  wire [15:0]CH0_LPDDR4_1_dq_a;
  wire [15:0]CH0_LPDDR4_1_dq_b;
  wire [1:0]CH0_LPDDR4_1_dqs_c_a;
  wire [1:0]CH0_LPDDR4_1_dqs_c_b;
  wire [1:0]CH0_LPDDR4_1_dqs_t_a;
  wire [1:0]CH0_LPDDR4_1_dqs_t_b;
  wire [0:0]CH0_LPDDR4_1_reset_n;
  wire [5:0]CH1_LPDDR4_0_ca_a;
  wire [5:0]CH1_LPDDR4_0_ca_b;
  wire [0:0]CH1_LPDDR4_0_ck_c_a;
  wire [0:0]CH1_LPDDR4_0_ck_c_b;
  wire [0:0]CH1_LPDDR4_0_ck_t_a;
  wire [0:0]CH1_LPDDR4_0_ck_t_b;
  wire [0:0]CH1_LPDDR4_0_cke_a;
  wire [0:0]CH1_LPDDR4_0_cke_b;
  wire [0:0]CH1_LPDDR4_0_cs_a;
  wire [0:0]CH1_LPDDR4_0_cs_b;
  wire [1:0]CH1_LPDDR4_0_dmi_a;
  wire [1:0]CH1_LPDDR4_0_dmi_b;
  wire [15:0]CH1_LPDDR4_0_dq_a;
  wire [15:0]CH1_LPDDR4_0_dq_b;
  wire [1:0]CH1_LPDDR4_0_dqs_c_a;
  wire [1:0]CH1_LPDDR4_0_dqs_c_b;
  wire [1:0]CH1_LPDDR4_0_dqs_t_a;
  wire [1:0]CH1_LPDDR4_0_dqs_t_b;
  wire [0:0]CH1_LPDDR4_0_reset_n;
  wire [5:0]CH1_LPDDR4_1_ca_a;
  wire [5:0]CH1_LPDDR4_1_ca_b;
  wire [0:0]CH1_LPDDR4_1_ck_c_a;
  wire [0:0]CH1_LPDDR4_1_ck_c_b;
  wire [0:0]CH1_LPDDR4_1_ck_t_a;
  wire [0:0]CH1_LPDDR4_1_ck_t_b;
  wire [0:0]CH1_LPDDR4_1_cke_a;
  wire [0:0]CH1_LPDDR4_1_cke_b;
  wire [0:0]CH1_LPDDR4_1_cs_a;
  wire [0:0]CH1_LPDDR4_1_cs_b;
  wire [1:0]CH1_LPDDR4_1_dmi_a;
  wire [1:0]CH1_LPDDR4_1_dmi_b;
  wire [15:0]CH1_LPDDR4_1_dq_a;
  wire [15:0]CH1_LPDDR4_1_dq_b;
  wire [1:0]CH1_LPDDR4_1_dqs_c_a;
  wire [1:0]CH1_LPDDR4_1_dqs_c_b;
  wire [1:0]CH1_LPDDR4_1_dqs_t_a;
  wire [1:0]CH1_LPDDR4_1_dqs_t_b;
  wire [0:0]CH1_LPDDR4_1_reset_n;
  wire [0:0]S00_INI_internoc;
  wire [0:0]S01_INI_internoc;
  wire [0:0]S02_INI_internoc;
  wire [0:0]S03_INI_internoc;
  wire [0:0]sys_clk0_clk_n;
  wire [0:0]sys_clk0_clk_p;
  wire [0:0]sys_clk1_clk_n;
  wire [0:0]sys_clk1_clk_p;

  bd_28ba bd_28ba_i
       (.CH0_LPDDR4_0_ca_a(CH0_LPDDR4_0_ca_a),
        .CH0_LPDDR4_0_ca_b(CH0_LPDDR4_0_ca_b),
        .CH0_LPDDR4_0_ck_c_a(CH0_LPDDR4_0_ck_c_a),
        .CH0_LPDDR4_0_ck_c_b(CH0_LPDDR4_0_ck_c_b),
        .CH0_LPDDR4_0_ck_t_a(CH0_LPDDR4_0_ck_t_a),
        .CH0_LPDDR4_0_ck_t_b(CH0_LPDDR4_0_ck_t_b),
        .CH0_LPDDR4_0_cke_a(CH0_LPDDR4_0_cke_a),
        .CH0_LPDDR4_0_cke_b(CH0_LPDDR4_0_cke_b),
        .CH0_LPDDR4_0_cs_a(CH0_LPDDR4_0_cs_a),
        .CH0_LPDDR4_0_cs_b(CH0_LPDDR4_0_cs_b),
        .CH0_LPDDR4_0_dmi_a(CH0_LPDDR4_0_dmi_a),
        .CH0_LPDDR4_0_dmi_b(CH0_LPDDR4_0_dmi_b),
        .CH0_LPDDR4_0_dq_a(CH0_LPDDR4_0_dq_a),
        .CH0_LPDDR4_0_dq_b(CH0_LPDDR4_0_dq_b),
        .CH0_LPDDR4_0_dqs_c_a(CH0_LPDDR4_0_dqs_c_a),
        .CH0_LPDDR4_0_dqs_c_b(CH0_LPDDR4_0_dqs_c_b),
        .CH0_LPDDR4_0_dqs_t_a(CH0_LPDDR4_0_dqs_t_a),
        .CH0_LPDDR4_0_dqs_t_b(CH0_LPDDR4_0_dqs_t_b),
        .CH0_LPDDR4_0_reset_n(CH0_LPDDR4_0_reset_n),
        .CH0_LPDDR4_1_ca_a(CH0_LPDDR4_1_ca_a),
        .CH0_LPDDR4_1_ca_b(CH0_LPDDR4_1_ca_b),
        .CH0_LPDDR4_1_ck_c_a(CH0_LPDDR4_1_ck_c_a),
        .CH0_LPDDR4_1_ck_c_b(CH0_LPDDR4_1_ck_c_b),
        .CH0_LPDDR4_1_ck_t_a(CH0_LPDDR4_1_ck_t_a),
        .CH0_LPDDR4_1_ck_t_b(CH0_LPDDR4_1_ck_t_b),
        .CH0_LPDDR4_1_cke_a(CH0_LPDDR4_1_cke_a),
        .CH0_LPDDR4_1_cke_b(CH0_LPDDR4_1_cke_b),
        .CH0_LPDDR4_1_cs_a(CH0_LPDDR4_1_cs_a),
        .CH0_LPDDR4_1_cs_b(CH0_LPDDR4_1_cs_b),
        .CH0_LPDDR4_1_dmi_a(CH0_LPDDR4_1_dmi_a),
        .CH0_LPDDR4_1_dmi_b(CH0_LPDDR4_1_dmi_b),
        .CH0_LPDDR4_1_dq_a(CH0_LPDDR4_1_dq_a),
        .CH0_LPDDR4_1_dq_b(CH0_LPDDR4_1_dq_b),
        .CH0_LPDDR4_1_dqs_c_a(CH0_LPDDR4_1_dqs_c_a),
        .CH0_LPDDR4_1_dqs_c_b(CH0_LPDDR4_1_dqs_c_b),
        .CH0_LPDDR4_1_dqs_t_a(CH0_LPDDR4_1_dqs_t_a),
        .CH0_LPDDR4_1_dqs_t_b(CH0_LPDDR4_1_dqs_t_b),
        .CH0_LPDDR4_1_reset_n(CH0_LPDDR4_1_reset_n),
        .CH1_LPDDR4_0_ca_a(CH1_LPDDR4_0_ca_a),
        .CH1_LPDDR4_0_ca_b(CH1_LPDDR4_0_ca_b),
        .CH1_LPDDR4_0_ck_c_a(CH1_LPDDR4_0_ck_c_a),
        .CH1_LPDDR4_0_ck_c_b(CH1_LPDDR4_0_ck_c_b),
        .CH1_LPDDR4_0_ck_t_a(CH1_LPDDR4_0_ck_t_a),
        .CH1_LPDDR4_0_ck_t_b(CH1_LPDDR4_0_ck_t_b),
        .CH1_LPDDR4_0_cke_a(CH1_LPDDR4_0_cke_a),
        .CH1_LPDDR4_0_cke_b(CH1_LPDDR4_0_cke_b),
        .CH1_LPDDR4_0_cs_a(CH1_LPDDR4_0_cs_a),
        .CH1_LPDDR4_0_cs_b(CH1_LPDDR4_0_cs_b),
        .CH1_LPDDR4_0_dmi_a(CH1_LPDDR4_0_dmi_a),
        .CH1_LPDDR4_0_dmi_b(CH1_LPDDR4_0_dmi_b),
        .CH1_LPDDR4_0_dq_a(CH1_LPDDR4_0_dq_a),
        .CH1_LPDDR4_0_dq_b(CH1_LPDDR4_0_dq_b),
        .CH1_LPDDR4_0_dqs_c_a(CH1_LPDDR4_0_dqs_c_a),
        .CH1_LPDDR4_0_dqs_c_b(CH1_LPDDR4_0_dqs_c_b),
        .CH1_LPDDR4_0_dqs_t_a(CH1_LPDDR4_0_dqs_t_a),
        .CH1_LPDDR4_0_dqs_t_b(CH1_LPDDR4_0_dqs_t_b),
        .CH1_LPDDR4_0_reset_n(CH1_LPDDR4_0_reset_n),
        .CH1_LPDDR4_1_ca_a(CH1_LPDDR4_1_ca_a),
        .CH1_LPDDR4_1_ca_b(CH1_LPDDR4_1_ca_b),
        .CH1_LPDDR4_1_ck_c_a(CH1_LPDDR4_1_ck_c_a),
        .CH1_LPDDR4_1_ck_c_b(CH1_LPDDR4_1_ck_c_b),
        .CH1_LPDDR4_1_ck_t_a(CH1_LPDDR4_1_ck_t_a),
        .CH1_LPDDR4_1_ck_t_b(CH1_LPDDR4_1_ck_t_b),
        .CH1_LPDDR4_1_cke_a(CH1_LPDDR4_1_cke_a),
        .CH1_LPDDR4_1_cke_b(CH1_LPDDR4_1_cke_b),
        .CH1_LPDDR4_1_cs_a(CH1_LPDDR4_1_cs_a),
        .CH1_LPDDR4_1_cs_b(CH1_LPDDR4_1_cs_b),
        .CH1_LPDDR4_1_dmi_a(CH1_LPDDR4_1_dmi_a),
        .CH1_LPDDR4_1_dmi_b(CH1_LPDDR4_1_dmi_b),
        .CH1_LPDDR4_1_dq_a(CH1_LPDDR4_1_dq_a),
        .CH1_LPDDR4_1_dq_b(CH1_LPDDR4_1_dq_b),
        .CH1_LPDDR4_1_dqs_c_a(CH1_LPDDR4_1_dqs_c_a),
        .CH1_LPDDR4_1_dqs_c_b(CH1_LPDDR4_1_dqs_c_b),
        .CH1_LPDDR4_1_dqs_t_a(CH1_LPDDR4_1_dqs_t_a),
        .CH1_LPDDR4_1_dqs_t_b(CH1_LPDDR4_1_dqs_t_b),
        .CH1_LPDDR4_1_reset_n(CH1_LPDDR4_1_reset_n),
        .S00_INI_internoc(S00_INI_internoc),
        .S01_INI_internoc(S01_INI_internoc),
        .S02_INI_internoc(S02_INI_internoc),
        .S03_INI_internoc(S03_INI_internoc),
        .sys_clk0_clk_n(sys_clk0_clk_n),
        .sys_clk0_clk_p(sys_clk0_clk_p),
        .sys_clk1_clk_n(sys_clk1_clk_n),
        .sys_clk1_clk_p(sys_clk1_clk_p));
endmodule
