//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Command: generate_target bd_90d1_wrapper.bd
//Design : bd_90d1_wrapper
//Purpose: IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module bd_90d1_wrapper
   (CH0_DDR4_0_act_n,
    CH0_DDR4_0_adr,
    CH0_DDR4_0_ba,
    CH0_DDR4_0_bg,
    CH0_DDR4_0_ck_c,
    CH0_DDR4_0_ck_t,
    CH0_DDR4_0_cke,
    CH0_DDR4_0_cs_n,
    CH0_DDR4_0_dm_n,
    CH0_DDR4_0_dq,
    CH0_DDR4_0_dqs_c,
    CH0_DDR4_0_dqs_t,
    CH0_DDR4_0_odt,
    CH0_DDR4_0_reset_n,
    S00_INI_internoc,
    S01_INI_internoc,
    S02_INI_internoc,
    S03_INI_internoc,
    sys_clk0_clk_n,
    sys_clk0_clk_p);
  output [0:0]CH0_DDR4_0_act_n;
  output [16:0]CH0_DDR4_0_adr;
  output [1:0]CH0_DDR4_0_ba;
  output [1:0]CH0_DDR4_0_bg;
  output [0:0]CH0_DDR4_0_ck_c;
  output [0:0]CH0_DDR4_0_ck_t;
  output [0:0]CH0_DDR4_0_cke;
  output [0:0]CH0_DDR4_0_cs_n;
  inout [7:0]CH0_DDR4_0_dm_n;
  inout [63:0]CH0_DDR4_0_dq;
  inout [7:0]CH0_DDR4_0_dqs_c;
  inout [7:0]CH0_DDR4_0_dqs_t;
  output [0:0]CH0_DDR4_0_odt;
  output [0:0]CH0_DDR4_0_reset_n;
  input [0:0]S00_INI_internoc;
  input [0:0]S01_INI_internoc;
  input [0:0]S02_INI_internoc;
  input [0:0]S03_INI_internoc;
  input [0:0]sys_clk0_clk_n;
  input [0:0]sys_clk0_clk_p;

  wire [0:0]CH0_DDR4_0_act_n;
  wire [16:0]CH0_DDR4_0_adr;
  wire [1:0]CH0_DDR4_0_ba;
  wire [1:0]CH0_DDR4_0_bg;
  wire [0:0]CH0_DDR4_0_ck_c;
  wire [0:0]CH0_DDR4_0_ck_t;
  wire [0:0]CH0_DDR4_0_cke;
  wire [0:0]CH0_DDR4_0_cs_n;
  wire [7:0]CH0_DDR4_0_dm_n;
  wire [63:0]CH0_DDR4_0_dq;
  wire [7:0]CH0_DDR4_0_dqs_c;
  wire [7:0]CH0_DDR4_0_dqs_t;
  wire [0:0]CH0_DDR4_0_odt;
  wire [0:0]CH0_DDR4_0_reset_n;
  wire [0:0]S00_INI_internoc;
  wire [0:0]S01_INI_internoc;
  wire [0:0]S02_INI_internoc;
  wire [0:0]S03_INI_internoc;
  wire [0:0]sys_clk0_clk_n;
  wire [0:0]sys_clk0_clk_p;

  bd_90d1 bd_90d1_i
       (.CH0_DDR4_0_act_n(CH0_DDR4_0_act_n),
        .CH0_DDR4_0_adr(CH0_DDR4_0_adr),
        .CH0_DDR4_0_ba(CH0_DDR4_0_ba),
        .CH0_DDR4_0_bg(CH0_DDR4_0_bg),
        .CH0_DDR4_0_ck_c(CH0_DDR4_0_ck_c),
        .CH0_DDR4_0_ck_t(CH0_DDR4_0_ck_t),
        .CH0_DDR4_0_cke(CH0_DDR4_0_cke),
        .CH0_DDR4_0_cs_n(CH0_DDR4_0_cs_n),
        .CH0_DDR4_0_dm_n(CH0_DDR4_0_dm_n),
        .CH0_DDR4_0_dq(CH0_DDR4_0_dq),
        .CH0_DDR4_0_dqs_c(CH0_DDR4_0_dqs_c),
        .CH0_DDR4_0_dqs_t(CH0_DDR4_0_dqs_t),
        .CH0_DDR4_0_odt(CH0_DDR4_0_odt),
        .CH0_DDR4_0_reset_n(CH0_DDR4_0_reset_n),
        .S00_INI_internoc(S00_INI_internoc),
        .S01_INI_internoc(S01_INI_internoc),
        .S02_INI_internoc(S02_INI_internoc),
        .S03_INI_internoc(S03_INI_internoc),
        .sys_clk0_clk_n(sys_clk0_clk_n),
        .sys_clk0_clk_p(sys_clk0_clk_p));
endmodule
