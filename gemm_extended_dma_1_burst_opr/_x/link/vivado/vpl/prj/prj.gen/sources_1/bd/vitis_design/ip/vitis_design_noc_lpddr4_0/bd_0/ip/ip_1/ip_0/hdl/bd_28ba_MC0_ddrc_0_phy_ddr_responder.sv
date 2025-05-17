/******************************************************************************
// (c) Copyright 2017 - 2018 Xilinx, Inc. All rights reserved.
//
// This file contains confidential and proprietary information
// of Xilinx, Inc. and is protected under U.S. and
// international copyright and other intellectual property
// laws.
//
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// Xilinx, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) Xilinx shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or Xilinx had been advised of the
// possibility of the same.
//
// CRITICAL APPLICATIONS
// Xilinx products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of Xilinx products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
//
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
/******************************************************************************/
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor             : Xilinx
// \   \   \/     Version            : 1.0
//  \   \         Application        : DDR4
//  /   /         Filename           : lpddr_model_wrapper.sv
// /___/   /\     Date Last Modified : $Date: 2016/03/07 $
// \   \  /  \    Date Created       : March 7 2016
//  \___\/\___\
//
// Device           : Versal
// Design Name      : MC (Memory Controller)
// Purpose          : Memory Model
// 
// Reference        :
// Revision History :
//*****************************************************************************
`timescale 1ps/1ps

module bd_28ba_MC0_ddrc_0_phy_ddr_responder (
    input  [0 : 0] lpddr4_reset_n  
    ,inout   [15 : 0]   lpddr4_dq_a
    ,inout   [1 : 0]  lpddr4_dqs_t_a
    ,inout   [1 : 0]  lpddr4_dqs_c_a
    ,input  [5 : 0]   lpddr4_ca_a
    ,input  [0 : 0]   lpddr4_cs_a
    ,input  [0 : 0]  lpddr4_ck_t_a
    ,input  [0 : 0]  lpddr4_ck_c_a
    ,input  [0 : 0]  lpddr4_cke_a
    ,inout   [1 : 0]  lpddr4_dmi_a
    ,inout   [15 : 0]   lpddr4_dq_b
    ,inout   [1 : 0]  lpddr4_dqs_t_b
    ,inout   [1 : 0]  lpddr4_dqs_c_b
    ,input  [5 : 0]   lpddr4_ca_b
    ,input  [0 : 0]   lpddr4_cs_b
    ,input  [0 : 0]  lpddr4_ck_t_b
    ,input  [0 : 0]  lpddr4_ck_c_b
    ,input  [0 : 0]  lpddr4_cke_b
    ,inout   [1 : 0]  lpddr4_dmi_b
);






 



lpddr_model_wrapper #(
      .WL                (23) 
     ,.RL                (46) 
     ,.ROW_WIDTH         (16)
     ,.BA_WIDTH          (3)
     ,.COL_WIDTH         (10)
     ,.VERBOSITY_EN      (0 )
     ,.CKE_A_WIDTH       (1)
     ,.CS_A_WIDTH        (1)
     ,.CA_A_WIDTH        (6)
     ,.CK_A_WIDTH        (1)
     ,.DM_A_WIDTH        (2)
     ,.DQ_A_WIDTH        (16)
     ,.DQS_A_WIDTH       (2)
     ,.CKE_B_WIDTH       (1)
     ,.CS_B_WIDTH        (1)
     ,.CA_B_WIDTH        (6)
     ,.CK_B_WIDTH        (1)
     ,.DM_B_WIDTH        (2)
     ,.DQ_B_WIDTH        (16)
     ,.DQS_B_WIDTH       (2)
     ,.RESETN_WIDTH      (1) 
     ,.DM_ENABLE         ("DM_NO_DBI")
) inst (
.lpddr4_reset_n(lpddr4_reset_n)
,.lpddr4_dq_a(lpddr4_dq_a)      
,.lpddr4_dqs_t_a(lpddr4_dqs_t_a)
,.lpddr4_dqs_c_a(lpddr4_dqs_c_a)
,.lpddr4_ca_a(lpddr4_ca_a)
,.lpddr4_cs_a(lpddr4_cs_a)
,.lpddr4_ck_t_a(lpddr4_ck_t_a)
,.lpddr4_ck_c_a(lpddr4_ck_c_a)
,.lpddr4_cke_a(lpddr4_cke_a)
,.lpddr4_dmi_a(lpddr4_dmi_a)
,.lpddr4_dq_b(lpddr4_dq_b)      
,.lpddr4_dqs_t_b(lpddr4_dqs_t_b)
,.lpddr4_dqs_c_b(lpddr4_dqs_c_b)
,.lpddr4_ca_b(lpddr4_ca_b)
,.lpddr4_cs_b(lpddr4_cs_b)
,.lpddr4_ck_t_b(lpddr4_ck_t_b)
,.lpddr4_ck_c_b(lpddr4_ck_c_b)
,.lpddr4_cke_b(lpddr4_cke_b)
,.lpddr4_dmi_b(lpddr4_dmi_b)
);

endmodule
