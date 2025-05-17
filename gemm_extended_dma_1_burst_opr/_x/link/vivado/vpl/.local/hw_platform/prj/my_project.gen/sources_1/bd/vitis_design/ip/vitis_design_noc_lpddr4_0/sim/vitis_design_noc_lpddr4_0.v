// (c) Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// (c) Copyright 2022-2024 Advanced Micro Devices, Inc. All rights reserved.
// 
// This file contains confidential and proprietary information
// of AMD and is protected under U.S. and international copyright
// and other intellectual property laws.
// 
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// AMD, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND AMD HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) AMD shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or AMD had been advised of the
// possibility of the same.
// 
// CRITICAL APPLICATIONS
// AMD products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of AMD products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
// 
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
// 
// DO NOT MODIFY THIS FILE.


// IP VLNV: xilinx.com:ip:axi_noc:1.1
// IP Revision: 0

`timescale 1ns/1ps

(* DowngradeIPIdentifiedWarnings = "yes" *)
module vitis_design_noc_lpddr4_0 (
  S00_INI_internoc,
  S01_INI_internoc,
  S02_INI_internoc,
  S03_INI_internoc,
  sys_clk0_clk_p,
  sys_clk0_clk_n,
  CH0_LPDDR4_0_dq_a,
  CH0_LPDDR4_0_dq_b,
  CH0_LPDDR4_0_dqs_t_a,
  CH0_LPDDR4_0_dqs_t_b,
  CH0_LPDDR4_0_dqs_c_a,
  CH0_LPDDR4_0_dqs_c_b,
  CH0_LPDDR4_0_ca_a,
  CH0_LPDDR4_0_ca_b,
  CH0_LPDDR4_0_cs_a,
  CH0_LPDDR4_0_cs_b,
  CH0_LPDDR4_0_ck_t_a,
  CH0_LPDDR4_0_ck_t_b,
  CH0_LPDDR4_0_ck_c_a,
  CH0_LPDDR4_0_ck_c_b,
  CH0_LPDDR4_0_cke_a,
  CH0_LPDDR4_0_cke_b,
  CH0_LPDDR4_0_dmi_a,
  CH0_LPDDR4_0_dmi_b,
  CH0_LPDDR4_0_reset_n,
  CH1_LPDDR4_0_dq_a,
  CH1_LPDDR4_0_dq_b,
  CH1_LPDDR4_0_dqs_t_a,
  CH1_LPDDR4_0_dqs_t_b,
  CH1_LPDDR4_0_dqs_c_a,
  CH1_LPDDR4_0_dqs_c_b,
  CH1_LPDDR4_0_ca_a,
  CH1_LPDDR4_0_ca_b,
  CH1_LPDDR4_0_cs_a,
  CH1_LPDDR4_0_cs_b,
  CH1_LPDDR4_0_ck_t_a,
  CH1_LPDDR4_0_ck_t_b,
  CH1_LPDDR4_0_ck_c_a,
  CH1_LPDDR4_0_ck_c_b,
  CH1_LPDDR4_0_cke_a,
  CH1_LPDDR4_0_cke_b,
  CH1_LPDDR4_0_dmi_a,
  CH1_LPDDR4_0_dmi_b,
  CH1_LPDDR4_0_reset_n,
  sys_clk1_clk_p,
  sys_clk1_clk_n,
  CH0_LPDDR4_1_dq_a,
  CH0_LPDDR4_1_dq_b,
  CH0_LPDDR4_1_dqs_t_a,
  CH0_LPDDR4_1_dqs_t_b,
  CH0_LPDDR4_1_dqs_c_a,
  CH0_LPDDR4_1_dqs_c_b,
  CH0_LPDDR4_1_ca_a,
  CH0_LPDDR4_1_ca_b,
  CH0_LPDDR4_1_cs_a,
  CH0_LPDDR4_1_cs_b,
  CH0_LPDDR4_1_ck_t_a,
  CH0_LPDDR4_1_ck_t_b,
  CH0_LPDDR4_1_ck_c_a,
  CH0_LPDDR4_1_ck_c_b,
  CH0_LPDDR4_1_cke_a,
  CH0_LPDDR4_1_cke_b,
  CH0_LPDDR4_1_dmi_a,
  CH0_LPDDR4_1_dmi_b,
  CH0_LPDDR4_1_reset_n,
  CH1_LPDDR4_1_dq_a,
  CH1_LPDDR4_1_dq_b,
  CH1_LPDDR4_1_dqs_t_a,
  CH1_LPDDR4_1_dqs_t_b,
  CH1_LPDDR4_1_dqs_c_a,
  CH1_LPDDR4_1_dqs_c_b,
  CH1_LPDDR4_1_ca_a,
  CH1_LPDDR4_1_ca_b,
  CH1_LPDDR4_1_cs_a,
  CH1_LPDDR4_1_cs_b,
  CH1_LPDDR4_1_ck_t_a,
  CH1_LPDDR4_1_ck_t_b,
  CH1_LPDDR4_1_ck_c_a,
  CH1_LPDDR4_1_ck_c_b,
  CH1_LPDDR4_1_cke_a,
  CH1_LPDDR4_1_cke_b,
  CH1_LPDDR4_1_dmi_a,
  CH1_LPDDR4_1_dmi_b,
  CH1_LPDDR4_1_reset_n
);

(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S00_INI, ADDR_WIDTH 64, INI_STRATEGY auto, COMPUTED_STRATEGY load, R_TRAFFIC_CLASS BEST_EFFORT, W_TRAFFIC_CLASS BEST_EFFORT, R_LATENCY 300, R_RATE_LIMITER 10, W_RATE_LIMITER 10, R_MAX_BURST_LENGTH 256, W_MAX_BURST_LENGTH 256, CONNECTIONS MC_0 { read_bw {128} write_bw {128} read_avg_burst {4} write_avg_burst {4}} , WRITE_BUFFER_SIZE 80, MY_CATEGORY pl" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:inimm:1.0 S00_INI INTERNOC" *)
input wire [0 : 0] S00_INI_internoc;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S01_INI, ADDR_WIDTH 64, INI_STRATEGY auto, COMPUTED_STRATEGY load, R_TRAFFIC_CLASS BEST_EFFORT, W_TRAFFIC_CLASS BEST_EFFORT, R_LATENCY 300, R_RATE_LIMITER 10, W_RATE_LIMITER 10, R_MAX_BURST_LENGTH 256, W_MAX_BURST_LENGTH 256, CONNECTIONS MC_1 { read_bw {5} write_bw {5} read_avg_burst {4} write_avg_burst {4}} , WRITE_BUFFER_SIZE 80, MY_CATEGORY pl" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:inimm:1.0 S01_INI INTERNOC" *)
input wire [0 : 0] S01_INI_internoc;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S02_INI, ADDR_WIDTH 64, INI_STRATEGY auto, COMPUTED_STRATEGY load, R_TRAFFIC_CLASS BEST_EFFORT, W_TRAFFIC_CLASS BEST_EFFORT, R_LATENCY 300, R_RATE_LIMITER 10, W_RATE_LIMITER 10, R_MAX_BURST_LENGTH 256, W_MAX_BURST_LENGTH 256, CONNECTIONS MC_2 { read_bw {5} write_bw {5} read_avg_burst {4} write_avg_burst {4}} , WRITE_BUFFER_SIZE 80, MY_CATEGORY pl" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:inimm:1.0 S02_INI INTERNOC" *)
input wire [0 : 0] S02_INI_internoc;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S03_INI, ADDR_WIDTH 64, INI_STRATEGY auto, COMPUTED_STRATEGY load, R_TRAFFIC_CLASS BEST_EFFORT, W_TRAFFIC_CLASS BEST_EFFORT, R_LATENCY 300, R_RATE_LIMITER 10, W_RATE_LIMITER 10, R_MAX_BURST_LENGTH 256, W_MAX_BURST_LENGTH 256, CONNECTIONS MC_3 { read_bw {5} write_bw {5} read_avg_burst {4} write_avg_burst {4}} , WRITE_BUFFER_SIZE 80, MY_CATEGORY pl" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:inimm:1.0 S03_INI INTERNOC" *)
input wire [0 : 0] S03_INI_internoc;
(* X_INTERFACE_INFO = "xilinx.com:interface:diff_clock:1.0 sys_clk0 CLK_P" *)
input wire [0 : 0] sys_clk0_clk_p;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME sys_clk0, CAN_DEBUG false, FREQ_HZ 200000000, BOARD.ASSOCIATED_PARAM sys_clk0_BOARD_INTERFACE" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:diff_clock:1.0 sys_clk0 CLK_N" *)
input wire [0 : 0] sys_clk0_clk_n;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 DQ_A" *)
inout wire [15 : 0] CH0_LPDDR4_0_dq_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 DQ_B" *)
inout wire [15 : 0] CH0_LPDDR4_0_dq_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 DQS_T_A" *)
inout wire [1 : 0] CH0_LPDDR4_0_dqs_t_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 DQS_T_B" *)
inout wire [1 : 0] CH0_LPDDR4_0_dqs_t_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 DQS_C_A" *)
inout wire [1 : 0] CH0_LPDDR4_0_dqs_c_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 DQS_C_B" *)
inout wire [1 : 0] CH0_LPDDR4_0_dqs_c_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 CA_A" *)
output wire [5 : 0] CH0_LPDDR4_0_ca_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 CA_B" *)
output wire [5 : 0] CH0_LPDDR4_0_ca_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 CS_A" *)
output wire [0 : 0] CH0_LPDDR4_0_cs_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 CS_B" *)
output wire [0 : 0] CH0_LPDDR4_0_cs_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 CK_T_A" *)
output wire [0 : 0] CH0_LPDDR4_0_ck_t_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 CK_T_B" *)
output wire [0 : 0] CH0_LPDDR4_0_ck_t_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 CK_C_A" *)
output wire [0 : 0] CH0_LPDDR4_0_ck_c_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 CK_C_B" *)
output wire [0 : 0] CH0_LPDDR4_0_ck_c_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 CKE_A" *)
output wire [0 : 0] CH0_LPDDR4_0_cke_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 CKE_B" *)
output wire [0 : 0] CH0_LPDDR4_0_cke_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 DMI_A" *)
inout wire [1 : 0] CH0_LPDDR4_0_dmi_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 DMI_B" *)
inout wire [1 : 0] CH0_LPDDR4_0_dmi_b;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CH0_LPDDR4_0, CAN_DEBUG false, WRITE_BUFFER_SIZE 80, NOC_ID -1, MY_CATEGORY pl, BOARD.ASSOCIATED_PARAM CH0_LPDDR4_0_BOARD_INTERFACE" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_0 RESET_N" *)
output wire [0 : 0] CH0_LPDDR4_0_reset_n;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 DQ_A" *)
inout wire [15 : 0] CH1_LPDDR4_0_dq_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 DQ_B" *)
inout wire [15 : 0] CH1_LPDDR4_0_dq_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 DQS_T_A" *)
inout wire [1 : 0] CH1_LPDDR4_0_dqs_t_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 DQS_T_B" *)
inout wire [1 : 0] CH1_LPDDR4_0_dqs_t_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 DQS_C_A" *)
inout wire [1 : 0] CH1_LPDDR4_0_dqs_c_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 DQS_C_B" *)
inout wire [1 : 0] CH1_LPDDR4_0_dqs_c_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 CA_A" *)
output wire [5 : 0] CH1_LPDDR4_0_ca_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 CA_B" *)
output wire [5 : 0] CH1_LPDDR4_0_ca_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 CS_A" *)
output wire [0 : 0] CH1_LPDDR4_0_cs_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 CS_B" *)
output wire [0 : 0] CH1_LPDDR4_0_cs_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 CK_T_A" *)
output wire [0 : 0] CH1_LPDDR4_0_ck_t_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 CK_T_B" *)
output wire [0 : 0] CH1_LPDDR4_0_ck_t_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 CK_C_A" *)
output wire [0 : 0] CH1_LPDDR4_0_ck_c_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 CK_C_B" *)
output wire [0 : 0] CH1_LPDDR4_0_ck_c_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 CKE_A" *)
output wire [0 : 0] CH1_LPDDR4_0_cke_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 CKE_B" *)
output wire [0 : 0] CH1_LPDDR4_0_cke_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 DMI_A" *)
inout wire [1 : 0] CH1_LPDDR4_0_dmi_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 DMI_B" *)
inout wire [1 : 0] CH1_LPDDR4_0_dmi_b;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CH1_LPDDR4_0, CAN_DEBUG false, WRITE_BUFFER_SIZE 80, NOC_ID -1, MY_CATEGORY pl, BOARD.ASSOCIATED_PARAM CH1_LPDDR4_0_BOARD_INTERFACE" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_0 RESET_N" *)
output wire [0 : 0] CH1_LPDDR4_0_reset_n;
(* X_INTERFACE_INFO = "xilinx.com:interface:diff_clock:1.0 sys_clk1 CLK_P" *)
input wire [0 : 0] sys_clk1_clk_p;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME sys_clk1, CAN_DEBUG false, FREQ_HZ 200000000, BOARD.ASSOCIATED_PARAM sys_clk1_BOARD_INTERFACE" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:diff_clock:1.0 sys_clk1 CLK_N" *)
input wire [0 : 0] sys_clk1_clk_n;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 DQ_A" *)
inout wire [15 : 0] CH0_LPDDR4_1_dq_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 DQ_B" *)
inout wire [15 : 0] CH0_LPDDR4_1_dq_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 DQS_T_A" *)
inout wire [1 : 0] CH0_LPDDR4_1_dqs_t_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 DQS_T_B" *)
inout wire [1 : 0] CH0_LPDDR4_1_dqs_t_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 DQS_C_A" *)
inout wire [1 : 0] CH0_LPDDR4_1_dqs_c_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 DQS_C_B" *)
inout wire [1 : 0] CH0_LPDDR4_1_dqs_c_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 CA_A" *)
output wire [5 : 0] CH0_LPDDR4_1_ca_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 CA_B" *)
output wire [5 : 0] CH0_LPDDR4_1_ca_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 CS_A" *)
output wire [0 : 0] CH0_LPDDR4_1_cs_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 CS_B" *)
output wire [0 : 0] CH0_LPDDR4_1_cs_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 CK_T_A" *)
output wire [0 : 0] CH0_LPDDR4_1_ck_t_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 CK_T_B" *)
output wire [0 : 0] CH0_LPDDR4_1_ck_t_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 CK_C_A" *)
output wire [0 : 0] CH0_LPDDR4_1_ck_c_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 CK_C_B" *)
output wire [0 : 0] CH0_LPDDR4_1_ck_c_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 CKE_A" *)
output wire [0 : 0] CH0_LPDDR4_1_cke_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 CKE_B" *)
output wire [0 : 0] CH0_LPDDR4_1_cke_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 DMI_A" *)
inout wire [1 : 0] CH0_LPDDR4_1_dmi_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 DMI_B" *)
inout wire [1 : 0] CH0_LPDDR4_1_dmi_b;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CH0_LPDDR4_1, CAN_DEBUG false, WRITE_BUFFER_SIZE 80, NOC_ID -1, MY_CATEGORY pl, BOARD.ASSOCIATED_PARAM CH0_LPDDR4_1_BOARD_INTERFACE" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH0_LPDDR4_1 RESET_N" *)
output wire [0 : 0] CH0_LPDDR4_1_reset_n;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 DQ_A" *)
inout wire [15 : 0] CH1_LPDDR4_1_dq_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 DQ_B" *)
inout wire [15 : 0] CH1_LPDDR4_1_dq_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 DQS_T_A" *)
inout wire [1 : 0] CH1_LPDDR4_1_dqs_t_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 DQS_T_B" *)
inout wire [1 : 0] CH1_LPDDR4_1_dqs_t_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 DQS_C_A" *)
inout wire [1 : 0] CH1_LPDDR4_1_dqs_c_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 DQS_C_B" *)
inout wire [1 : 0] CH1_LPDDR4_1_dqs_c_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 CA_A" *)
output wire [5 : 0] CH1_LPDDR4_1_ca_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 CA_B" *)
output wire [5 : 0] CH1_LPDDR4_1_ca_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 CS_A" *)
output wire [0 : 0] CH1_LPDDR4_1_cs_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 CS_B" *)
output wire [0 : 0] CH1_LPDDR4_1_cs_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 CK_T_A" *)
output wire [0 : 0] CH1_LPDDR4_1_ck_t_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 CK_T_B" *)
output wire [0 : 0] CH1_LPDDR4_1_ck_t_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 CK_C_A" *)
output wire [0 : 0] CH1_LPDDR4_1_ck_c_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 CK_C_B" *)
output wire [0 : 0] CH1_LPDDR4_1_ck_c_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 CKE_A" *)
output wire [0 : 0] CH1_LPDDR4_1_cke_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 CKE_B" *)
output wire [0 : 0] CH1_LPDDR4_1_cke_b;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 DMI_A" *)
inout wire [1 : 0] CH1_LPDDR4_1_dmi_a;
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 DMI_B" *)
inout wire [1 : 0] CH1_LPDDR4_1_dmi_b;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CH1_LPDDR4_1, CAN_DEBUG false, WRITE_BUFFER_SIZE 80, NOC_ID -1, MY_CATEGORY pl, BOARD.ASSOCIATED_PARAM CH1_LPDDR4_1_BOARD_INTERFACE" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:lpddr4:1.0 CH1_LPDDR4_1 RESET_N" *)
output wire [0 : 0] CH1_LPDDR4_1_reset_n;

  bd_28ba inst (
    .S00_INI_internoc(S00_INI_internoc),
    .S01_INI_internoc(S01_INI_internoc),
    .S02_INI_internoc(S02_INI_internoc),
    .S03_INI_internoc(S03_INI_internoc),
    .sys_clk0_clk_p(sys_clk0_clk_p),
    .sys_clk0_clk_n(sys_clk0_clk_n),
    .CH0_LPDDR4_0_dq_a(CH0_LPDDR4_0_dq_a),
    .CH0_LPDDR4_0_dq_b(CH0_LPDDR4_0_dq_b),
    .CH0_LPDDR4_0_dqs_t_a(CH0_LPDDR4_0_dqs_t_a),
    .CH0_LPDDR4_0_dqs_t_b(CH0_LPDDR4_0_dqs_t_b),
    .CH0_LPDDR4_0_dqs_c_a(CH0_LPDDR4_0_dqs_c_a),
    .CH0_LPDDR4_0_dqs_c_b(CH0_LPDDR4_0_dqs_c_b),
    .CH0_LPDDR4_0_ca_a(CH0_LPDDR4_0_ca_a),
    .CH0_LPDDR4_0_ca_b(CH0_LPDDR4_0_ca_b),
    .CH0_LPDDR4_0_cs_a(CH0_LPDDR4_0_cs_a),
    .CH0_LPDDR4_0_cs_b(CH0_LPDDR4_0_cs_b),
    .CH0_LPDDR4_0_ck_t_a(CH0_LPDDR4_0_ck_t_a),
    .CH0_LPDDR4_0_ck_t_b(CH0_LPDDR4_0_ck_t_b),
    .CH0_LPDDR4_0_ck_c_a(CH0_LPDDR4_0_ck_c_a),
    .CH0_LPDDR4_0_ck_c_b(CH0_LPDDR4_0_ck_c_b),
    .CH0_LPDDR4_0_cke_a(CH0_LPDDR4_0_cke_a),
    .CH0_LPDDR4_0_cke_b(CH0_LPDDR4_0_cke_b),
    .CH0_LPDDR4_0_dmi_a(CH0_LPDDR4_0_dmi_a),
    .CH0_LPDDR4_0_dmi_b(CH0_LPDDR4_0_dmi_b),
    .CH0_LPDDR4_0_reset_n(CH0_LPDDR4_0_reset_n),
    .CH1_LPDDR4_0_dq_a(CH1_LPDDR4_0_dq_a),
    .CH1_LPDDR4_0_dq_b(CH1_LPDDR4_0_dq_b),
    .CH1_LPDDR4_0_dqs_t_a(CH1_LPDDR4_0_dqs_t_a),
    .CH1_LPDDR4_0_dqs_t_b(CH1_LPDDR4_0_dqs_t_b),
    .CH1_LPDDR4_0_dqs_c_a(CH1_LPDDR4_0_dqs_c_a),
    .CH1_LPDDR4_0_dqs_c_b(CH1_LPDDR4_0_dqs_c_b),
    .CH1_LPDDR4_0_ca_a(CH1_LPDDR4_0_ca_a),
    .CH1_LPDDR4_0_ca_b(CH1_LPDDR4_0_ca_b),
    .CH1_LPDDR4_0_cs_a(CH1_LPDDR4_0_cs_a),
    .CH1_LPDDR4_0_cs_b(CH1_LPDDR4_0_cs_b),
    .CH1_LPDDR4_0_ck_t_a(CH1_LPDDR4_0_ck_t_a),
    .CH1_LPDDR4_0_ck_t_b(CH1_LPDDR4_0_ck_t_b),
    .CH1_LPDDR4_0_ck_c_a(CH1_LPDDR4_0_ck_c_a),
    .CH1_LPDDR4_0_ck_c_b(CH1_LPDDR4_0_ck_c_b),
    .CH1_LPDDR4_0_cke_a(CH1_LPDDR4_0_cke_a),
    .CH1_LPDDR4_0_cke_b(CH1_LPDDR4_0_cke_b),
    .CH1_LPDDR4_0_dmi_a(CH1_LPDDR4_0_dmi_a),
    .CH1_LPDDR4_0_dmi_b(CH1_LPDDR4_0_dmi_b),
    .CH1_LPDDR4_0_reset_n(CH1_LPDDR4_0_reset_n),
    .sys_clk1_clk_p(sys_clk1_clk_p),
    .sys_clk1_clk_n(sys_clk1_clk_n),
    .CH0_LPDDR4_1_dq_a(CH0_LPDDR4_1_dq_a),
    .CH0_LPDDR4_1_dq_b(CH0_LPDDR4_1_dq_b),
    .CH0_LPDDR4_1_dqs_t_a(CH0_LPDDR4_1_dqs_t_a),
    .CH0_LPDDR4_1_dqs_t_b(CH0_LPDDR4_1_dqs_t_b),
    .CH0_LPDDR4_1_dqs_c_a(CH0_LPDDR4_1_dqs_c_a),
    .CH0_LPDDR4_1_dqs_c_b(CH0_LPDDR4_1_dqs_c_b),
    .CH0_LPDDR4_1_ca_a(CH0_LPDDR4_1_ca_a),
    .CH0_LPDDR4_1_ca_b(CH0_LPDDR4_1_ca_b),
    .CH0_LPDDR4_1_cs_a(CH0_LPDDR4_1_cs_a),
    .CH0_LPDDR4_1_cs_b(CH0_LPDDR4_1_cs_b),
    .CH0_LPDDR4_1_ck_t_a(CH0_LPDDR4_1_ck_t_a),
    .CH0_LPDDR4_1_ck_t_b(CH0_LPDDR4_1_ck_t_b),
    .CH0_LPDDR4_1_ck_c_a(CH0_LPDDR4_1_ck_c_a),
    .CH0_LPDDR4_1_ck_c_b(CH0_LPDDR4_1_ck_c_b),
    .CH0_LPDDR4_1_cke_a(CH0_LPDDR4_1_cke_a),
    .CH0_LPDDR4_1_cke_b(CH0_LPDDR4_1_cke_b),
    .CH0_LPDDR4_1_dmi_a(CH0_LPDDR4_1_dmi_a),
    .CH0_LPDDR4_1_dmi_b(CH0_LPDDR4_1_dmi_b),
    .CH0_LPDDR4_1_reset_n(CH0_LPDDR4_1_reset_n),
    .CH1_LPDDR4_1_dq_a(CH1_LPDDR4_1_dq_a),
    .CH1_LPDDR4_1_dq_b(CH1_LPDDR4_1_dq_b),
    .CH1_LPDDR4_1_dqs_t_a(CH1_LPDDR4_1_dqs_t_a),
    .CH1_LPDDR4_1_dqs_t_b(CH1_LPDDR4_1_dqs_t_b),
    .CH1_LPDDR4_1_dqs_c_a(CH1_LPDDR4_1_dqs_c_a),
    .CH1_LPDDR4_1_dqs_c_b(CH1_LPDDR4_1_dqs_c_b),
    .CH1_LPDDR4_1_ca_a(CH1_LPDDR4_1_ca_a),
    .CH1_LPDDR4_1_ca_b(CH1_LPDDR4_1_ca_b),
    .CH1_LPDDR4_1_cs_a(CH1_LPDDR4_1_cs_a),
    .CH1_LPDDR4_1_cs_b(CH1_LPDDR4_1_cs_b),
    .CH1_LPDDR4_1_ck_t_a(CH1_LPDDR4_1_ck_t_a),
    .CH1_LPDDR4_1_ck_t_b(CH1_LPDDR4_1_ck_t_b),
    .CH1_LPDDR4_1_ck_c_a(CH1_LPDDR4_1_ck_c_a),
    .CH1_LPDDR4_1_ck_c_b(CH1_LPDDR4_1_ck_c_b),
    .CH1_LPDDR4_1_cke_a(CH1_LPDDR4_1_cke_a),
    .CH1_LPDDR4_1_cke_b(CH1_LPDDR4_1_cke_b),
    .CH1_LPDDR4_1_dmi_a(CH1_LPDDR4_1_dmi_a),
    .CH1_LPDDR4_1_dmi_b(CH1_LPDDR4_1_dmi_b),
    .CH1_LPDDR4_1_reset_n(CH1_LPDDR4_1_reset_n)
  );
endmodule
