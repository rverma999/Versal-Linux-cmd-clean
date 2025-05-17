//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Command: generate_target bd_28ba.bd
//Design : bd_28ba
//Purpose: IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "bd_28ba,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=bd_28ba,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=2,numReposBlks=2,numNonXlnxBlks=0,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=SBD,synth_mode=None}" *) (* HW_HANDOFF = "vitis_design_noc_lpddr4_0.hwdef" *) 
module bd_28ba
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
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 CA_A" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CH0_LPDDR4_0, CAN_DEBUG false, MY_CATEGORY pl, NOC_ID -1, WRITE_BUFFER_SIZE 80" *) output [5:0]CH0_LPDDR4_0_ca_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 CA_B" *) output [5:0]CH0_LPDDR4_0_ca_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 CK_C_A" *) output [0:0]CH0_LPDDR4_0_ck_c_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 CK_C_B" *) output [0:0]CH0_LPDDR4_0_ck_c_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 CK_T_A" *) output [0:0]CH0_LPDDR4_0_ck_t_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 CK_T_B" *) output [0:0]CH0_LPDDR4_0_ck_t_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 CKE_A" *) output [0:0]CH0_LPDDR4_0_cke_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 CKE_B" *) output [0:0]CH0_LPDDR4_0_cke_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 CS_A" *) output [0:0]CH0_LPDDR4_0_cs_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 CS_B" *) output [0:0]CH0_LPDDR4_0_cs_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 DMI_A" *) inout [1:0]CH0_LPDDR4_0_dmi_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 DMI_B" *) inout [1:0]CH0_LPDDR4_0_dmi_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 DQ_A" *) inout [15:0]CH0_LPDDR4_0_dq_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 DQ_B" *) inout [15:0]CH0_LPDDR4_0_dq_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 DQS_C_A" *) inout [1:0]CH0_LPDDR4_0_dqs_c_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 DQS_C_B" *) inout [1:0]CH0_LPDDR4_0_dqs_c_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 DQS_T_A" *) inout [1:0]CH0_LPDDR4_0_dqs_t_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 DQS_T_B" *) inout [1:0]CH0_LPDDR4_0_dqs_t_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 RESET_N" *) output [0:0]CH0_LPDDR4_0_reset_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 CA_A" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CH0_LPDDR4_1, CAN_DEBUG false, MY_CATEGORY pl, NOC_ID -1, WRITE_BUFFER_SIZE 80" *) output [5:0]CH0_LPDDR4_1_ca_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 CA_B" *) output [5:0]CH0_LPDDR4_1_ca_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 CK_C_A" *) output [0:0]CH0_LPDDR4_1_ck_c_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 CK_C_B" *) output [0:0]CH0_LPDDR4_1_ck_c_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 CK_T_A" *) output [0:0]CH0_LPDDR4_1_ck_t_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 CK_T_B" *) output [0:0]CH0_LPDDR4_1_ck_t_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 CKE_A" *) output [0:0]CH0_LPDDR4_1_cke_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 CKE_B" *) output [0:0]CH0_LPDDR4_1_cke_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 CS_A" *) output [0:0]CH0_LPDDR4_1_cs_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 CS_B" *) output [0:0]CH0_LPDDR4_1_cs_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 DMI_A" *) inout [1:0]CH0_LPDDR4_1_dmi_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 DMI_B" *) inout [1:0]CH0_LPDDR4_1_dmi_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 DQ_A" *) inout [15:0]CH0_LPDDR4_1_dq_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 DQ_B" *) inout [15:0]CH0_LPDDR4_1_dq_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 DQS_C_A" *) inout [1:0]CH0_LPDDR4_1_dqs_c_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 DQS_C_B" *) inout [1:0]CH0_LPDDR4_1_dqs_c_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 DQS_T_A" *) inout [1:0]CH0_LPDDR4_1_dqs_t_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 DQS_T_B" *) inout [1:0]CH0_LPDDR4_1_dqs_t_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 RESET_N" *) output [0:0]CH0_LPDDR4_1_reset_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 CA_A" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CH1_LPDDR4_0, CAN_DEBUG false, MY_CATEGORY pl, NOC_ID -1, WRITE_BUFFER_SIZE 80" *) output [5:0]CH1_LPDDR4_0_ca_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 CA_B" *) output [5:0]CH1_LPDDR4_0_ca_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 CK_C_A" *) output [0:0]CH1_LPDDR4_0_ck_c_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 CK_C_B" *) output [0:0]CH1_LPDDR4_0_ck_c_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 CK_T_A" *) output [0:0]CH1_LPDDR4_0_ck_t_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 CK_T_B" *) output [0:0]CH1_LPDDR4_0_ck_t_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 CKE_A" *) output [0:0]CH1_LPDDR4_0_cke_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 CKE_B" *) output [0:0]CH1_LPDDR4_0_cke_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 CS_A" *) output [0:0]CH1_LPDDR4_0_cs_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 CS_B" *) output [0:0]CH1_LPDDR4_0_cs_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 DMI_A" *) inout [1:0]CH1_LPDDR4_0_dmi_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 DMI_B" *) inout [1:0]CH1_LPDDR4_0_dmi_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 DQ_A" *) inout [15:0]CH1_LPDDR4_0_dq_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 DQ_B" *) inout [15:0]CH1_LPDDR4_0_dq_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 DQS_C_A" *) inout [1:0]CH1_LPDDR4_0_dqs_c_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 DQS_C_B" *) inout [1:0]CH1_LPDDR4_0_dqs_c_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 DQS_T_A" *) inout [1:0]CH1_LPDDR4_0_dqs_t_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 DQS_T_B" *) inout [1:0]CH1_LPDDR4_0_dqs_t_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 RESET_N" *) output [0:0]CH1_LPDDR4_0_reset_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 CA_A" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CH1_LPDDR4_1, CAN_DEBUG false, MY_CATEGORY pl, NOC_ID -1, WRITE_BUFFER_SIZE 80" *) output [5:0]CH1_LPDDR4_1_ca_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 CA_B" *) output [5:0]CH1_LPDDR4_1_ca_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 CK_C_A" *) output [0:0]CH1_LPDDR4_1_ck_c_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 CK_C_B" *) output [0:0]CH1_LPDDR4_1_ck_c_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 CK_T_A" *) output [0:0]CH1_LPDDR4_1_ck_t_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 CK_T_B" *) output [0:0]CH1_LPDDR4_1_ck_t_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 CKE_A" *) output [0:0]CH1_LPDDR4_1_cke_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 CKE_B" *) output [0:0]CH1_LPDDR4_1_cke_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 CS_A" *) output [0:0]CH1_LPDDR4_1_cs_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 CS_B" *) output [0:0]CH1_LPDDR4_1_cs_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 DMI_A" *) inout [1:0]CH1_LPDDR4_1_dmi_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 DMI_B" *) inout [1:0]CH1_LPDDR4_1_dmi_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 DQ_A" *) inout [15:0]CH1_LPDDR4_1_dq_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 DQ_B" *) inout [15:0]CH1_LPDDR4_1_dq_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 DQS_C_A" *) inout [1:0]CH1_LPDDR4_1_dqs_c_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 DQS_C_B" *) inout [1:0]CH1_LPDDR4_1_dqs_c_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 DQS_T_A" *) inout [1:0]CH1_LPDDR4_1_dqs_t_a;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 DQS_T_B" *) inout [1:0]CH1_LPDDR4_1_dqs_t_b;
  (* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 RESET_N" *) output [0:0]CH1_LPDDR4_1_reset_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:inimm:1.0 S00_INI INTERNOC" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S00_INI, ADDR_WIDTH 64, COMPUTED_STRATEGY load, CONNECTIONS MC_0 { read_bw {128} write_bw {128} read_avg_burst {4} write_avg_burst {4}} , INI_STRATEGY auto, MY_CATEGORY pl, R_LATENCY 300, R_MAX_BURST_LENGTH 256, R_RATE_LIMITER 10, R_TRAFFIC_CLASS BEST_EFFORT, WRITE_BUFFER_SIZE 80, W_MAX_BURST_LENGTH 256, W_RATE_LIMITER 10, W_TRAFFIC_CLASS BEST_EFFORT" *) input [0:0]S00_INI_internoc;
  (* X_INTERFACE_INFO = "xilinx.com:interface:inimm:1.0 S01_INI INTERNOC" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S01_INI, ADDR_WIDTH 64, COMPUTED_STRATEGY load, CONNECTIONS MC_1 { read_bw {5} write_bw {5} read_avg_burst {4} write_avg_burst {4}} , INI_STRATEGY auto, MY_CATEGORY pl, R_LATENCY 300, R_MAX_BURST_LENGTH 256, R_RATE_LIMITER 10, R_TRAFFIC_CLASS BEST_EFFORT, WRITE_BUFFER_SIZE 80, W_MAX_BURST_LENGTH 256, W_RATE_LIMITER 10, W_TRAFFIC_CLASS BEST_EFFORT" *) input [0:0]S01_INI_internoc;
  (* X_INTERFACE_INFO = "xilinx.com:interface:inimm:1.0 S02_INI INTERNOC" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S02_INI, ADDR_WIDTH 64, COMPUTED_STRATEGY load, CONNECTIONS MC_2 { read_bw {5} write_bw {5} read_avg_burst {4} write_avg_burst {4}} , INI_STRATEGY auto, MY_CATEGORY pl, R_LATENCY 300, R_MAX_BURST_LENGTH 256, R_RATE_LIMITER 10, R_TRAFFIC_CLASS BEST_EFFORT, WRITE_BUFFER_SIZE 80, W_MAX_BURST_LENGTH 256, W_RATE_LIMITER 10, W_TRAFFIC_CLASS BEST_EFFORT" *) input [0:0]S02_INI_internoc;
  (* X_INTERFACE_INFO = "xilinx.com:interface:inimm:1.0 S03_INI INTERNOC" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S03_INI, ADDR_WIDTH 64, COMPUTED_STRATEGY load, CONNECTIONS MC_3 { read_bw {5} write_bw {5} read_avg_burst {4} write_avg_burst {4}} , INI_STRATEGY auto, MY_CATEGORY pl, R_LATENCY 300, R_MAX_BURST_LENGTH 256, R_RATE_LIMITER 10, R_TRAFFIC_CLASS BEST_EFFORT, WRITE_BUFFER_SIZE 80, W_MAX_BURST_LENGTH 256, W_RATE_LIMITER 10, W_TRAFFIC_CLASS BEST_EFFORT" *) input [0:0]S03_INI_internoc;
  (* X_INTERFACE_INFO = "xilinx.com:interface:diff_clock:1.0 sys_clk0 CLK_N" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME sys_clk0, CAN_DEBUG false, FREQ_HZ 200000000" *) input [0:0]sys_clk0_clk_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:diff_clock:1.0 sys_clk0 CLK_P" *) input [0:0]sys_clk0_clk_p;
  (* X_INTERFACE_INFO = "xilinx.com:interface:diff_clock:1.0 sys_clk1 CLK_N" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME sys_clk1, CAN_DEBUG false, FREQ_HZ 200000000" *) input [0:0]sys_clk1_clk_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:diff_clock:1.0 sys_clk1 CLK_P" *) input [0:0]sys_clk1_clk_p;

  wire [5:0]MC0_ddrc_CH0_LPDDR4_CA_A;
  wire [5:0]MC0_ddrc_CH0_LPDDR4_CA_B;
  wire [0:0]MC0_ddrc_CH0_LPDDR4_CKE_A;
  wire [0:0]MC0_ddrc_CH0_LPDDR4_CKE_B;
  wire [0:0]MC0_ddrc_CH0_LPDDR4_CK_C_A;
  wire [0:0]MC0_ddrc_CH0_LPDDR4_CK_C_B;
  wire [0:0]MC0_ddrc_CH0_LPDDR4_CK_T_A;
  wire [0:0]MC0_ddrc_CH0_LPDDR4_CK_T_B;
  wire [0:0]MC0_ddrc_CH0_LPDDR4_CS_A;
  wire [0:0]MC0_ddrc_CH0_LPDDR4_CS_B;
  wire [1:0]MC0_ddrc_CH0_LPDDR4_DMI_A;
  wire [1:0]MC0_ddrc_CH0_LPDDR4_DMI_B;
  wire [1:0]MC0_ddrc_CH0_LPDDR4_DQS_C_A;
  wire [1:0]MC0_ddrc_CH0_LPDDR4_DQS_C_B;
  wire [1:0]MC0_ddrc_CH0_LPDDR4_DQS_T_A;
  wire [1:0]MC0_ddrc_CH0_LPDDR4_DQS_T_B;
  wire [15:0]MC0_ddrc_CH0_LPDDR4_DQ_A;
  wire [15:0]MC0_ddrc_CH0_LPDDR4_DQ_B;
  wire [0:0]MC0_ddrc_CH0_LPDDR4_RESET_N;
  wire [5:0]MC0_ddrc_CH1_LPDDR4_CA_A;
  wire [5:0]MC0_ddrc_CH1_LPDDR4_CA_B;
  wire [0:0]MC0_ddrc_CH1_LPDDR4_CKE_A;
  wire [0:0]MC0_ddrc_CH1_LPDDR4_CKE_B;
  wire [0:0]MC0_ddrc_CH1_LPDDR4_CK_C_A;
  wire [0:0]MC0_ddrc_CH1_LPDDR4_CK_C_B;
  wire [0:0]MC0_ddrc_CH1_LPDDR4_CK_T_A;
  wire [0:0]MC0_ddrc_CH1_LPDDR4_CK_T_B;
  wire [0:0]MC0_ddrc_CH1_LPDDR4_CS_A;
  wire [0:0]MC0_ddrc_CH1_LPDDR4_CS_B;
  wire [1:0]MC0_ddrc_CH1_LPDDR4_DMI_A;
  wire [1:0]MC0_ddrc_CH1_LPDDR4_DMI_B;
  wire [1:0]MC0_ddrc_CH1_LPDDR4_DQS_C_A;
  wire [1:0]MC0_ddrc_CH1_LPDDR4_DQS_C_B;
  wire [1:0]MC0_ddrc_CH1_LPDDR4_DQS_T_A;
  wire [1:0]MC0_ddrc_CH1_LPDDR4_DQS_T_B;
  wire [15:0]MC0_ddrc_CH1_LPDDR4_DQ_A;
  wire [15:0]MC0_ddrc_CH1_LPDDR4_DQ_B;
  wire [0:0]MC0_ddrc_CH1_LPDDR4_RESET_N;
  wire [5:0]MC1_ddrc_CH0_LPDDR4_CA_A;
  wire [5:0]MC1_ddrc_CH0_LPDDR4_CA_B;
  wire [0:0]MC1_ddrc_CH0_LPDDR4_CKE_A;
  wire [0:0]MC1_ddrc_CH0_LPDDR4_CKE_B;
  wire [0:0]MC1_ddrc_CH0_LPDDR4_CK_C_A;
  wire [0:0]MC1_ddrc_CH0_LPDDR4_CK_C_B;
  wire [0:0]MC1_ddrc_CH0_LPDDR4_CK_T_A;
  wire [0:0]MC1_ddrc_CH0_LPDDR4_CK_T_B;
  wire [0:0]MC1_ddrc_CH0_LPDDR4_CS_A;
  wire [0:0]MC1_ddrc_CH0_LPDDR4_CS_B;
  wire [1:0]MC1_ddrc_CH0_LPDDR4_DMI_A;
  wire [1:0]MC1_ddrc_CH0_LPDDR4_DMI_B;
  wire [1:0]MC1_ddrc_CH0_LPDDR4_DQS_C_A;
  wire [1:0]MC1_ddrc_CH0_LPDDR4_DQS_C_B;
  wire [1:0]MC1_ddrc_CH0_LPDDR4_DQS_T_A;
  wire [1:0]MC1_ddrc_CH0_LPDDR4_DQS_T_B;
  wire [15:0]MC1_ddrc_CH0_LPDDR4_DQ_A;
  wire [15:0]MC1_ddrc_CH0_LPDDR4_DQ_B;
  wire [0:0]MC1_ddrc_CH0_LPDDR4_RESET_N;
  wire [5:0]MC1_ddrc_CH1_LPDDR4_CA_A;
  wire [5:0]MC1_ddrc_CH1_LPDDR4_CA_B;
  wire [0:0]MC1_ddrc_CH1_LPDDR4_CKE_A;
  wire [0:0]MC1_ddrc_CH1_LPDDR4_CKE_B;
  wire [0:0]MC1_ddrc_CH1_LPDDR4_CK_C_A;
  wire [0:0]MC1_ddrc_CH1_LPDDR4_CK_C_B;
  wire [0:0]MC1_ddrc_CH1_LPDDR4_CK_T_A;
  wire [0:0]MC1_ddrc_CH1_LPDDR4_CK_T_B;
  wire [0:0]MC1_ddrc_CH1_LPDDR4_CS_A;
  wire [0:0]MC1_ddrc_CH1_LPDDR4_CS_B;
  wire [1:0]MC1_ddrc_CH1_LPDDR4_DMI_A;
  wire [1:0]MC1_ddrc_CH1_LPDDR4_DMI_B;
  wire [1:0]MC1_ddrc_CH1_LPDDR4_DQS_C_A;
  wire [1:0]MC1_ddrc_CH1_LPDDR4_DQS_C_B;
  wire [1:0]MC1_ddrc_CH1_LPDDR4_DQS_T_A;
  wire [1:0]MC1_ddrc_CH1_LPDDR4_DQS_T_B;
  wire [15:0]MC1_ddrc_CH1_LPDDR4_DQ_A;
  wire [15:0]MC1_ddrc_CH1_LPDDR4_DQ_B;
  wire [0:0]MC1_ddrc_CH1_LPDDR4_RESET_N;
  wire [0:0]sys_clk0_1_CLK_N;
  wire [0:0]sys_clk0_1_CLK_P;
  wire [0:0]sys_clk1_1_CLK_N;
  wire [0:0]sys_clk1_1_CLK_P;

  assign CH0_LPDDR4_0_ca_a[5:0] = MC0_ddrc_CH0_LPDDR4_CA_A;
  assign CH0_LPDDR4_0_ca_b[5:0] = MC0_ddrc_CH0_LPDDR4_CA_B;
  assign CH0_LPDDR4_0_ck_c_a[0] = MC0_ddrc_CH0_LPDDR4_CK_C_A;
  assign CH0_LPDDR4_0_ck_c_b[0] = MC0_ddrc_CH0_LPDDR4_CK_C_B;
  assign CH0_LPDDR4_0_ck_t_a[0] = MC0_ddrc_CH0_LPDDR4_CK_T_A;
  assign CH0_LPDDR4_0_ck_t_b[0] = MC0_ddrc_CH0_LPDDR4_CK_T_B;
  assign CH0_LPDDR4_0_cke_a[0] = MC0_ddrc_CH0_LPDDR4_CKE_A;
  assign CH0_LPDDR4_0_cke_b[0] = MC0_ddrc_CH0_LPDDR4_CKE_B;
  assign CH0_LPDDR4_0_cs_a[0] = MC0_ddrc_CH0_LPDDR4_CS_A;
  assign CH0_LPDDR4_0_cs_b[0] = MC0_ddrc_CH0_LPDDR4_CS_B;
  assign CH0_LPDDR4_0_reset_n[0] = MC0_ddrc_CH0_LPDDR4_RESET_N;
  assign CH0_LPDDR4_1_ca_a[5:0] = MC1_ddrc_CH0_LPDDR4_CA_A;
  assign CH0_LPDDR4_1_ca_b[5:0] = MC1_ddrc_CH0_LPDDR4_CA_B;
  assign CH0_LPDDR4_1_ck_c_a[0] = MC1_ddrc_CH0_LPDDR4_CK_C_A;
  assign CH0_LPDDR4_1_ck_c_b[0] = MC1_ddrc_CH0_LPDDR4_CK_C_B;
  assign CH0_LPDDR4_1_ck_t_a[0] = MC1_ddrc_CH0_LPDDR4_CK_T_A;
  assign CH0_LPDDR4_1_ck_t_b[0] = MC1_ddrc_CH0_LPDDR4_CK_T_B;
  assign CH0_LPDDR4_1_cke_a[0] = MC1_ddrc_CH0_LPDDR4_CKE_A;
  assign CH0_LPDDR4_1_cke_b[0] = MC1_ddrc_CH0_LPDDR4_CKE_B;
  assign CH0_LPDDR4_1_cs_a[0] = MC1_ddrc_CH0_LPDDR4_CS_A;
  assign CH0_LPDDR4_1_cs_b[0] = MC1_ddrc_CH0_LPDDR4_CS_B;
  assign CH0_LPDDR4_1_reset_n[0] = MC1_ddrc_CH0_LPDDR4_RESET_N;
  assign CH1_LPDDR4_0_ca_a[5:0] = MC0_ddrc_CH1_LPDDR4_CA_A;
  assign CH1_LPDDR4_0_ca_b[5:0] = MC0_ddrc_CH1_LPDDR4_CA_B;
  assign CH1_LPDDR4_0_ck_c_a[0] = MC0_ddrc_CH1_LPDDR4_CK_C_A;
  assign CH1_LPDDR4_0_ck_c_b[0] = MC0_ddrc_CH1_LPDDR4_CK_C_B;
  assign CH1_LPDDR4_0_ck_t_a[0] = MC0_ddrc_CH1_LPDDR4_CK_T_A;
  assign CH1_LPDDR4_0_ck_t_b[0] = MC0_ddrc_CH1_LPDDR4_CK_T_B;
  assign CH1_LPDDR4_0_cke_a[0] = MC0_ddrc_CH1_LPDDR4_CKE_A;
  assign CH1_LPDDR4_0_cke_b[0] = MC0_ddrc_CH1_LPDDR4_CKE_B;
  assign CH1_LPDDR4_0_cs_a[0] = MC0_ddrc_CH1_LPDDR4_CS_A;
  assign CH1_LPDDR4_0_cs_b[0] = MC0_ddrc_CH1_LPDDR4_CS_B;
  assign CH1_LPDDR4_0_reset_n[0] = MC0_ddrc_CH1_LPDDR4_RESET_N;
  assign CH1_LPDDR4_1_ca_a[5:0] = MC1_ddrc_CH1_LPDDR4_CA_A;
  assign CH1_LPDDR4_1_ca_b[5:0] = MC1_ddrc_CH1_LPDDR4_CA_B;
  assign CH1_LPDDR4_1_ck_c_a[0] = MC1_ddrc_CH1_LPDDR4_CK_C_A;
  assign CH1_LPDDR4_1_ck_c_b[0] = MC1_ddrc_CH1_LPDDR4_CK_C_B;
  assign CH1_LPDDR4_1_ck_t_a[0] = MC1_ddrc_CH1_LPDDR4_CK_T_A;
  assign CH1_LPDDR4_1_ck_t_b[0] = MC1_ddrc_CH1_LPDDR4_CK_T_B;
  assign CH1_LPDDR4_1_cke_a[0] = MC1_ddrc_CH1_LPDDR4_CKE_A;
  assign CH1_LPDDR4_1_cke_b[0] = MC1_ddrc_CH1_LPDDR4_CKE_B;
  assign CH1_LPDDR4_1_cs_a[0] = MC1_ddrc_CH1_LPDDR4_CS_A;
  assign CH1_LPDDR4_1_cs_b[0] = MC1_ddrc_CH1_LPDDR4_CS_B;
  assign CH1_LPDDR4_1_reset_n[0] = MC1_ddrc_CH1_LPDDR4_RESET_N;
  assign sys_clk0_1_CLK_N = sys_clk0_clk_n[0];
  assign sys_clk0_1_CLK_P = sys_clk0_clk_p[0];
  assign sys_clk1_1_CLK_N = sys_clk1_clk_n[0];
  assign sys_clk1_1_CLK_P = sys_clk1_clk_p[0];
  (* DONT_TOUCH *) 
  bd_28ba_MC0_ddrc_0 MC0_ddrc
       (.ch0_lpddr4_ca_a(MC0_ddrc_CH0_LPDDR4_CA_A),
        .ch0_lpddr4_ca_b(MC0_ddrc_CH0_LPDDR4_CA_B),
        .ch0_lpddr4_ck_c_a(MC0_ddrc_CH0_LPDDR4_CK_C_A),
        .ch0_lpddr4_ck_c_b(MC0_ddrc_CH0_LPDDR4_CK_C_B),
        .ch0_lpddr4_ck_t_a(MC0_ddrc_CH0_LPDDR4_CK_T_A),
        .ch0_lpddr4_ck_t_b(MC0_ddrc_CH0_LPDDR4_CK_T_B),
        .ch0_lpddr4_cke_a(MC0_ddrc_CH0_LPDDR4_CKE_A),
        .ch0_lpddr4_cke_b(MC0_ddrc_CH0_LPDDR4_CKE_B),
        .ch0_lpddr4_cs_a(MC0_ddrc_CH0_LPDDR4_CS_A),
        .ch0_lpddr4_cs_b(MC0_ddrc_CH0_LPDDR4_CS_B),
        .ch0_lpddr4_dmi_a(CH0_LPDDR4_0_dmi_a[1:0]),
        .ch0_lpddr4_dmi_b(CH0_LPDDR4_0_dmi_b[1:0]),
        .ch0_lpddr4_dq_a(CH0_LPDDR4_0_dq_a[15:0]),
        .ch0_lpddr4_dq_b(CH0_LPDDR4_0_dq_b[15:0]),
        .ch0_lpddr4_dqs_c_a(CH0_LPDDR4_0_dqs_c_a[1:0]),
        .ch0_lpddr4_dqs_c_b(CH0_LPDDR4_0_dqs_c_b[1:0]),
        .ch0_lpddr4_dqs_t_a(CH0_LPDDR4_0_dqs_t_a[1:0]),
        .ch0_lpddr4_dqs_t_b(CH0_LPDDR4_0_dqs_t_b[1:0]),
        .ch0_lpddr4_reset_n(MC0_ddrc_CH0_LPDDR4_RESET_N),
        .ch1_lpddr4_ca_a(MC0_ddrc_CH1_LPDDR4_CA_A),
        .ch1_lpddr4_ca_b(MC0_ddrc_CH1_LPDDR4_CA_B),
        .ch1_lpddr4_ck_c_a(MC0_ddrc_CH1_LPDDR4_CK_C_A),
        .ch1_lpddr4_ck_c_b(MC0_ddrc_CH1_LPDDR4_CK_C_B),
        .ch1_lpddr4_ck_t_a(MC0_ddrc_CH1_LPDDR4_CK_T_A),
        .ch1_lpddr4_ck_t_b(MC0_ddrc_CH1_LPDDR4_CK_T_B),
        .ch1_lpddr4_cke_a(MC0_ddrc_CH1_LPDDR4_CKE_A),
        .ch1_lpddr4_cke_b(MC0_ddrc_CH1_LPDDR4_CKE_B),
        .ch1_lpddr4_cs_a(MC0_ddrc_CH1_LPDDR4_CS_A),
        .ch1_lpddr4_cs_b(MC0_ddrc_CH1_LPDDR4_CS_B),
        .ch1_lpddr4_dmi_a(CH1_LPDDR4_0_dmi_a[1:0]),
        .ch1_lpddr4_dmi_b(CH1_LPDDR4_0_dmi_b[1:0]),
        .ch1_lpddr4_dq_a(CH1_LPDDR4_0_dq_a[15:0]),
        .ch1_lpddr4_dq_b(CH1_LPDDR4_0_dq_b[15:0]),
        .ch1_lpddr4_dqs_c_a(CH1_LPDDR4_0_dqs_c_a[1:0]),
        .ch1_lpddr4_dqs_c_b(CH1_LPDDR4_0_dqs_c_b[1:0]),
        .ch1_lpddr4_dqs_t_a(CH1_LPDDR4_0_dqs_t_a[1:0]),
        .ch1_lpddr4_dqs_t_b(CH1_LPDDR4_0_dqs_t_b[1:0]),
        .ch1_lpddr4_reset_n(MC0_ddrc_CH1_LPDDR4_RESET_N),
        .from_noc_0(1'b0),
        .from_noc_1(1'b0),
        .from_noc_2(1'b0),
        .from_noc_3(1'b0),
        .sys_clk_n(sys_clk0_1_CLK_N),
        .sys_clk_p(sys_clk0_1_CLK_P));
  (* DONT_TOUCH *) 
  bd_28ba_MC1_ddrc_0 MC1_ddrc
       (.ch0_lpddr4_ca_a(MC1_ddrc_CH0_LPDDR4_CA_A),
        .ch0_lpddr4_ca_b(MC1_ddrc_CH0_LPDDR4_CA_B),
        .ch0_lpddr4_ck_c_a(MC1_ddrc_CH0_LPDDR4_CK_C_A),
        .ch0_lpddr4_ck_c_b(MC1_ddrc_CH0_LPDDR4_CK_C_B),
        .ch0_lpddr4_ck_t_a(MC1_ddrc_CH0_LPDDR4_CK_T_A),
        .ch0_lpddr4_ck_t_b(MC1_ddrc_CH0_LPDDR4_CK_T_B),
        .ch0_lpddr4_cke_a(MC1_ddrc_CH0_LPDDR4_CKE_A),
        .ch0_lpddr4_cke_b(MC1_ddrc_CH0_LPDDR4_CKE_B),
        .ch0_lpddr4_cs_a(MC1_ddrc_CH0_LPDDR4_CS_A),
        .ch0_lpddr4_cs_b(MC1_ddrc_CH0_LPDDR4_CS_B),
        .ch0_lpddr4_dmi_a(CH0_LPDDR4_1_dmi_a[1:0]),
        .ch0_lpddr4_dmi_b(CH0_LPDDR4_1_dmi_b[1:0]),
        .ch0_lpddr4_dq_a(CH0_LPDDR4_1_dq_a[15:0]),
        .ch0_lpddr4_dq_b(CH0_LPDDR4_1_dq_b[15:0]),
        .ch0_lpddr4_dqs_c_a(CH0_LPDDR4_1_dqs_c_a[1:0]),
        .ch0_lpddr4_dqs_c_b(CH0_LPDDR4_1_dqs_c_b[1:0]),
        .ch0_lpddr4_dqs_t_a(CH0_LPDDR4_1_dqs_t_a[1:0]),
        .ch0_lpddr4_dqs_t_b(CH0_LPDDR4_1_dqs_t_b[1:0]),
        .ch0_lpddr4_reset_n(MC1_ddrc_CH0_LPDDR4_RESET_N),
        .ch1_lpddr4_ca_a(MC1_ddrc_CH1_LPDDR4_CA_A),
        .ch1_lpddr4_ca_b(MC1_ddrc_CH1_LPDDR4_CA_B),
        .ch1_lpddr4_ck_c_a(MC1_ddrc_CH1_LPDDR4_CK_C_A),
        .ch1_lpddr4_ck_c_b(MC1_ddrc_CH1_LPDDR4_CK_C_B),
        .ch1_lpddr4_ck_t_a(MC1_ddrc_CH1_LPDDR4_CK_T_A),
        .ch1_lpddr4_ck_t_b(MC1_ddrc_CH1_LPDDR4_CK_T_B),
        .ch1_lpddr4_cke_a(MC1_ddrc_CH1_LPDDR4_CKE_A),
        .ch1_lpddr4_cke_b(MC1_ddrc_CH1_LPDDR4_CKE_B),
        .ch1_lpddr4_cs_a(MC1_ddrc_CH1_LPDDR4_CS_A),
        .ch1_lpddr4_cs_b(MC1_ddrc_CH1_LPDDR4_CS_B),
        .ch1_lpddr4_dmi_a(CH1_LPDDR4_1_dmi_a[1:0]),
        .ch1_lpddr4_dmi_b(CH1_LPDDR4_1_dmi_b[1:0]),
        .ch1_lpddr4_dq_a(CH1_LPDDR4_1_dq_a[15:0]),
        .ch1_lpddr4_dq_b(CH1_LPDDR4_1_dq_b[15:0]),
        .ch1_lpddr4_dqs_c_a(CH1_LPDDR4_1_dqs_c_a[1:0]),
        .ch1_lpddr4_dqs_c_b(CH1_LPDDR4_1_dqs_c_b[1:0]),
        .ch1_lpddr4_dqs_t_a(CH1_LPDDR4_1_dqs_t_a[1:0]),
        .ch1_lpddr4_dqs_t_b(CH1_LPDDR4_1_dqs_t_b[1:0]),
        .ch1_lpddr4_reset_n(MC1_ddrc_CH1_LPDDR4_RESET_N),
        .from_noc_0(1'b0),
        .from_noc_1(1'b0),
        .from_noc_2(1'b0),
        .from_noc_3(1'b0),
        .sys_clk_n(sys_clk1_1_CLK_N),
        .sys_clk_p(sys_clk1_1_CLK_P));
endmodule
