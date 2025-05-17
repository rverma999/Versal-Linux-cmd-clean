//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Command: generate_target bd_90d1.bd
//Design : bd_90d1
//Purpose: IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "bd_90d1,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=bd_90d1,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=1,numReposBlks=1,numNonXlnxBlks=0,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=SBD,synth_mode=None}" *) (* HW_HANDOFF = "vitis_design_noc_ddr4_0.hwdef" *) 
module bd_90d1
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
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 CH0_DDR4_0 ACT_N" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CH0_DDR4_0, AXI_ARBITRATION_SCHEME TDM, BURST_LENGTH 8, CAN_DEBUG false, CAS_LATENCY 11, CAS_WRITE_LATENCY 11, CS_ENABLED true, DATA_MASK_ENABLED true, DATA_WIDTH 8, MEMORY_TYPE COMPONENTS, MEM_ADDR_MAP ROW_COLUMN_BANK, MY_CATEGORY pl, NOC_ID -1, SLOT Single, TIMEPERIOD_PS 1250, WRITE_BUFFER_SIZE 80" *) output [0:0]CH0_DDR4_0_act_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 CH0_DDR4_0 ADR" *) output [16:0]CH0_DDR4_0_adr;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 CH0_DDR4_0 BA" *) output [1:0]CH0_DDR4_0_ba;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 CH0_DDR4_0 BG" *) output [1:0]CH0_DDR4_0_bg;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 CH0_DDR4_0 CK_C" *) output [0:0]CH0_DDR4_0_ck_c;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 CH0_DDR4_0 CK_T" *) output [0:0]CH0_DDR4_0_ck_t;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 CH0_DDR4_0 CKE" *) output [0:0]CH0_DDR4_0_cke;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 CH0_DDR4_0 CS_N" *) output [0:0]CH0_DDR4_0_cs_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 CH0_DDR4_0 DM_N" *) inout [7:0]CH0_DDR4_0_dm_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 CH0_DDR4_0 DQ" *) inout [63:0]CH0_DDR4_0_dq;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 CH0_DDR4_0 DQS_C" *) inout [7:0]CH0_DDR4_0_dqs_c;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 CH0_DDR4_0 DQS_T" *) inout [7:0]CH0_DDR4_0_dqs_t;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 CH0_DDR4_0 ODT" *) output [0:0]CH0_DDR4_0_odt;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddr4:1.0 CH0_DDR4_0 RESET_N" *) output [0:0]CH0_DDR4_0_reset_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:inimm:1.0 S00_INI INTERNOC" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S00_INI, ADDR_WIDTH 64, COMPUTED_STRATEGY load, CONNECTIONS MC_0 { read_bw {5} write_bw {5} read_avg_burst {4} write_avg_burst {4}} , INI_STRATEGY auto, MY_CATEGORY pl, R_LATENCY 300, R_MAX_BURST_LENGTH 256, R_RATE_LIMITER 10, R_TRAFFIC_CLASS BEST_EFFORT, WRITE_BUFFER_SIZE 80, W_MAX_BURST_LENGTH 256, W_RATE_LIMITER 10, W_TRAFFIC_CLASS BEST_EFFORT" *) input [0:0]S00_INI_internoc;
  (* X_INTERFACE_INFO = "xilinx.com:interface:inimm:1.0 S01_INI INTERNOC" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S01_INI, ADDR_WIDTH 64, COMPUTED_STRATEGY load, CONNECTIONS MC_1 { read_bw {5} write_bw {5} read_avg_burst {4} write_avg_burst {4}} , INI_STRATEGY auto, MY_CATEGORY pl, R_LATENCY 300, R_MAX_BURST_LENGTH 256, R_RATE_LIMITER 10, R_TRAFFIC_CLASS BEST_EFFORT, WRITE_BUFFER_SIZE 80, W_MAX_BURST_LENGTH 256, W_RATE_LIMITER 10, W_TRAFFIC_CLASS BEST_EFFORT" *) input [0:0]S01_INI_internoc;
  (* X_INTERFACE_INFO = "xilinx.com:interface:inimm:1.0 S02_INI INTERNOC" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S02_INI, ADDR_WIDTH 64, COMPUTED_STRATEGY load, CONNECTIONS MC_2 { read_bw {5} write_bw {5} read_avg_burst {4} write_avg_burst {4}} , INI_STRATEGY auto, MY_CATEGORY pl, R_LATENCY 300, R_MAX_BURST_LENGTH 256, R_RATE_LIMITER 10, R_TRAFFIC_CLASS BEST_EFFORT, WRITE_BUFFER_SIZE 80, W_MAX_BURST_LENGTH 256, W_RATE_LIMITER 10, W_TRAFFIC_CLASS BEST_EFFORT" *) input [0:0]S02_INI_internoc;
  (* X_INTERFACE_INFO = "xilinx.com:interface:inimm:1.0 S03_INI INTERNOC" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S03_INI, ADDR_WIDTH 64, COMPUTED_STRATEGY load, CONNECTIONS MC_3 { read_bw {5} write_bw {5} read_avg_burst {4} write_avg_burst {4}} , INI_STRATEGY auto, MY_CATEGORY pl, R_LATENCY 300, R_MAX_BURST_LENGTH 256, R_RATE_LIMITER 10, R_TRAFFIC_CLASS BEST_EFFORT, WRITE_BUFFER_SIZE 80, W_MAX_BURST_LENGTH 256, W_RATE_LIMITER 10, W_TRAFFIC_CLASS BEST_EFFORT" *) input [0:0]S03_INI_internoc;
  (* X_INTERFACE_INFO = "xilinx.com:interface:diff_clock:1.0 sys_clk0 CLK_N" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME sys_clk0, CAN_DEBUG false, FREQ_HZ 200000000" *) input [0:0]sys_clk0_clk_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:diff_clock:1.0 sys_clk0 CLK_P" *) input [0:0]sys_clk0_clk_p;

  wire MC0_ddrc_CH0_DDR4_ACT_N;
  wire [16:0]MC0_ddrc_CH0_DDR4_ADR;
  wire [1:0]MC0_ddrc_CH0_DDR4_BA;
  wire [1:0]MC0_ddrc_CH0_DDR4_BG;
  wire [0:0]MC0_ddrc_CH0_DDR4_CKE;
  wire [0:0]MC0_ddrc_CH0_DDR4_CK_C;
  wire [0:0]MC0_ddrc_CH0_DDR4_CK_T;
  wire [0:0]MC0_ddrc_CH0_DDR4_CS_N;
  wire [7:0]MC0_ddrc_CH0_DDR4_DM_N;
  wire [63:0]MC0_ddrc_CH0_DDR4_DQ;
  wire [7:0]MC0_ddrc_CH0_DDR4_DQS_C;
  wire [7:0]MC0_ddrc_CH0_DDR4_DQS_T;
  wire [0:0]MC0_ddrc_CH0_DDR4_ODT;
  wire MC0_ddrc_CH0_DDR4_RESET_N;
  wire [0:0]sys_clk0_1_CLK_N;
  wire [0:0]sys_clk0_1_CLK_P;

  assign CH0_DDR4_0_act_n[0] = MC0_ddrc_CH0_DDR4_ACT_N;
  assign CH0_DDR4_0_adr[16:0] = MC0_ddrc_CH0_DDR4_ADR;
  assign CH0_DDR4_0_ba[1:0] = MC0_ddrc_CH0_DDR4_BA;
  assign CH0_DDR4_0_bg[1:0] = MC0_ddrc_CH0_DDR4_BG;
  assign CH0_DDR4_0_ck_c[0] = MC0_ddrc_CH0_DDR4_CK_C;
  assign CH0_DDR4_0_ck_t[0] = MC0_ddrc_CH0_DDR4_CK_T;
  assign CH0_DDR4_0_cke[0] = MC0_ddrc_CH0_DDR4_CKE;
  assign CH0_DDR4_0_cs_n[0] = MC0_ddrc_CH0_DDR4_CS_N;
  assign CH0_DDR4_0_odt[0] = MC0_ddrc_CH0_DDR4_ODT;
  assign CH0_DDR4_0_reset_n[0] = MC0_ddrc_CH0_DDR4_RESET_N;
  assign sys_clk0_1_CLK_N = sys_clk0_clk_n[0];
  assign sys_clk0_1_CLK_P = sys_clk0_clk_p[0];
  (* DONT_TOUCH *) 
  bd_90d1_MC0_ddrc_0 MC0_ddrc
       (.ch0_ddr4_act_n(MC0_ddrc_CH0_DDR4_ACT_N),
        .ch0_ddr4_adr(MC0_ddrc_CH0_DDR4_ADR),
        .ch0_ddr4_ba(MC0_ddrc_CH0_DDR4_BA),
        .ch0_ddr4_bg(MC0_ddrc_CH0_DDR4_BG),
        .ch0_ddr4_ck_c(MC0_ddrc_CH0_DDR4_CK_C),
        .ch0_ddr4_ck_t(MC0_ddrc_CH0_DDR4_CK_T),
        .ch0_ddr4_cke(MC0_ddrc_CH0_DDR4_CKE),
        .ch0_ddr4_cs_n(MC0_ddrc_CH0_DDR4_CS_N),
        .ch0_ddr4_dm_dbi_n(CH0_DDR4_0_dm_n[7:0]),
        .ch0_ddr4_dq(CH0_DDR4_0_dq[63:0]),
        .ch0_ddr4_dqs_c(CH0_DDR4_0_dqs_c[7:0]),
        .ch0_ddr4_dqs_t(CH0_DDR4_0_dqs_t[7:0]),
        .ch0_ddr4_odt(MC0_ddrc_CH0_DDR4_ODT),
        .ch0_ddr4_reset_n(MC0_ddrc_CH0_DDR4_RESET_N),
        .from_noc_0(1'b0),
        .from_noc_1(1'b0),
        .from_noc_2(1'b0),
        .from_noc_3(1'b0),
        .sys_clk_n(sys_clk0_1_CLK_N),
        .sys_clk_p(sys_clk0_1_CLK_P));
endmodule
