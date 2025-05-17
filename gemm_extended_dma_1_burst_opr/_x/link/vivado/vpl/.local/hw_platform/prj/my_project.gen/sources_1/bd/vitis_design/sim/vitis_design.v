//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2024.1 (lin64) Build 5076211 Wed May 22 01:37:59 MDT 2024
//Date        : Wed May 22 12:39:20 2024
//Host        : xcolinlocbld22 running 64-bit CentOS Linux release 7.4.1708 (Core)
//Command     : generate_target vitis_design.bd
//Design      : vitis_design
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "vitis_design,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=vitis_design,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=26,numReposBlks=26,numNonXlnxBlks=0,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=USER,synth_mode=Hierarchical}" *) (* HW_HANDOFF = "vitis_design.hwdef" *) 
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
  (* HARD_CONN = "true" *) wire ai_engine_0_s00_axi_aclk;
  wire axi_intc_3_irq;
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
  wire [31:0]icn_ctrl_1_M02_AXI_RDATA;
  wire [0:0]icn_ctrl_1_M02_AXI_RID;
  wire icn_ctrl_1_M02_AXI_RLAST;
  wire icn_ctrl_1_M02_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M02_AXI_RRESP;
  wire [13:0]icn_ctrl_1_M02_AXI_RUSER;
  wire icn_ctrl_1_M02_AXI_RVALID;
  wire [31:0]icn_ctrl_1_M02_AXI_WDATA;
  wire icn_ctrl_1_M02_AXI_WLAST;
  wire icn_ctrl_1_M02_AXI_WREADY;
  wire [3:0]icn_ctrl_1_M02_AXI_WSTRB;
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
  wire [31:0]icn_ctrl_1_M03_AXI_RDATA;
  wire [0:0]icn_ctrl_1_M03_AXI_RID;
  wire icn_ctrl_1_M03_AXI_RLAST;
  wire icn_ctrl_1_M03_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M03_AXI_RRESP;
  wire [13:0]icn_ctrl_1_M03_AXI_RUSER;
  wire icn_ctrl_1_M03_AXI_RVALID;
  wire [31:0]icn_ctrl_1_M03_AXI_WDATA;
  wire icn_ctrl_1_M03_AXI_WLAST;
  wire icn_ctrl_1_M03_AXI_WREADY;
  wire [3:0]icn_ctrl_1_M03_AXI_WSTRB;
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
  wire [31:0]icn_ctrl_1_M04_AXI_RDATA;
  wire [0:0]icn_ctrl_1_M04_AXI_RID;
  wire icn_ctrl_1_M04_AXI_RLAST;
  wire icn_ctrl_1_M04_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M04_AXI_RRESP;
  wire [13:0]icn_ctrl_1_M04_AXI_RUSER;
  wire icn_ctrl_1_M04_AXI_RVALID;
  wire [31:0]icn_ctrl_1_M04_AXI_WDATA;
  wire icn_ctrl_1_M04_AXI_WLAST;
  wire icn_ctrl_1_M04_AXI_WREADY;
  wire [3:0]icn_ctrl_1_M04_AXI_WSTRB;
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
  wire [31:0]icn_ctrl_1_M05_AXI_RDATA;
  wire [0:0]icn_ctrl_1_M05_AXI_RID;
  wire icn_ctrl_1_M05_AXI_RLAST;
  wire icn_ctrl_1_M05_AXI_RREADY;
  wire [1:0]icn_ctrl_1_M05_AXI_RRESP;
  wire [13:0]icn_ctrl_1_M05_AXI_RUSER;
  wire icn_ctrl_1_M05_AXI_RVALID;
  wire [31:0]icn_ctrl_1_M05_AXI_WDATA;
  wire icn_ctrl_1_M05_AXI_WLAST;
  wire icn_ctrl_1_M05_AXI_WREADY;
  wire [3:0]icn_ctrl_1_M05_AXI_WSTRB;
  wire [13:0]icn_ctrl_1_M05_AXI_WUSER;
  wire icn_ctrl_1_M05_AXI_WVALID;
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
  wire lpddr4_sma_clk1_1_CLK_N;
  wire lpddr4_sma_clk1_1_CLK_P;
  wire lpddr4_sma_clk2_1_CLK_N;
  wire lpddr4_sma_clk2_1_CLK_P;
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
  vitis_design_ai_engine_0_0 ai_engine_0
       (.S00_AXI_araddr(cips_noc_M00_AXI_ARADDR[33:0]),
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
        .s00_axi_aclk(ai_engine_0_s00_axi_aclk));
  vitis_design_axi_intc_cascaded_1_0 axi_intc_cascaded_1
       (.intr(1'b0),
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
        .S00_INI_internoc(cips_noc_M00_INI_INTERNOC),
        .S01_INI_internoc(cips_noc_M01_INI_INTERNOC),
        .S02_INI_internoc(cips_noc_M02_INI_INTERNOC),
        .S03_INI_internoc(cips_noc_M03_INI_INTERNOC),
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
        .mb_debug_sys_rst(1'b0),
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
  vitis_design_xlconcat_0_0 xlconcat_0
       (.In0(1'b0),
        .In1(1'b0),
        .In10(1'b0),
        .In11(1'b0),
        .In12(1'b0),
        .In13(1'b0),
        .In14(1'b0),
        .In15(1'b0),
        .In16(1'b0),
        .In17(1'b0),
        .In18(1'b0),
        .In19(1'b0),
        .In2(1'b0),
        .In20(1'b0),
        .In21(1'b0),
        .In22(1'b0),
        .In23(1'b0),
        .In24(1'b0),
        .In25(1'b0),
        .In26(1'b0),
        .In27(1'b0),
        .In28(1'b0),
        .In29(1'b0),
        .In3(1'b0),
        .In30(1'b0),
        .In31(axi_intc_cascaded_1_irq),
        .In4(1'b0),
        .In5(1'b0),
        .In6(1'b0),
        .In7(1'b0),
        .In8(1'b0),
        .In9(1'b0),
        .dout(xlconcat_0_dout));
  vitis_design_xlconstant_0_0 xlconstant_0
       (.dout(xlconstant_0_dout));
endmodule
