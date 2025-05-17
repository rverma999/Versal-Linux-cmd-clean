//////////////////////////////////////////////////////////////////////////////
// Proprietary Note:
// XILINX CONFIDENTIAL
//
// Copyright 2019 Xilinx, Inc. All rights reserved.
// This file contains confidential and proprietary information of Xilinx, Inc.
// and is protected under U.S. and international copyright and other
// intellectual property laws.
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
//
// 
//
//
//////////////////////////////////////////////////////////////////////////////

// <-------- controller#0 defines (config_UVC generated) -------->

#ifndef _CAL_CONFIG_DEFINES_0_H_
#define _CAL_CONFIG_DEFINES_0_H_

 



   #define                                LPDDR4 

   #define                              LPDDR4X        0
 // LPDDR4

   #define DQ_BITS                     64 
   #define DQS_BITS                    8
   #define RANKS                       1
   #define SLOTS                       1
   #define PINOUT_SELECT               26
   #define SI_REVISION                 NA
   #define S80_DEVICE                  1
   #define IBUF_DISABLE                 0                                    
 
   #define DIS_MEM_FILL                 1                                    
 
   // Frequency set 0
   #define F0_TCK  512
   #define F0_QTR_DLY                   (F0_TCK / 8) 
    
   #define F0_MR1                       0x0074
   #define F0_MR2                       0x003F
   #define F0_MR3                       0x0031
   #define F0_MR4                       0x03
   #define F0_MR5                       0x00
   #define F0_MR11                      0x0055
   #define F0_MR12                      0x004D
   #define F0_MR13                      0x0000
   #define F0_MR14                      0x001E
   #define F0_MR15                      0x0055
   #define F0_MR16                      0x0000
   #define F0_MR17                      0x0000
   #define F0_MR20                      0x0055
   #define F0_MR22                      {0x0006}

   #define F0_MR23                      0x003F

   #define XPLL_F0_CLKFBOUT_LT          0x27
   #define XPLL_F0_CLKFBOUT_HT          0x27
   #define XPLL_F0_DIVCLK_LT            0x02
   #define XPLL_F0_DIVCLK_HT            0x02
   #define XPLL_SYSCLK_TP               4992

   #define F0_ADD_CMD_DELAY             0 
   #define F0_ADD_CMD_DELAY_EN          0


   #define XPIO_VREF_DEFAULT            0xAA  
   // Frequency set 1
   #define F1_TCK                       512 
   #define F1_QTR_DLY                   (F1_TCK / 8)
   #define F1_MR1                       0x0074                       
   #define F1_MR2                       0x003F
   #define F1_MR3                       0x0031
   #define F1_MR4                       0x03
   #define F1_MR5                       0x00
   #define F1_MR11                      0x0055
   #define F1_MR12                      0x004D
   #define F1_MR13                      0x00C0
   #define F1_MR14                      0x001E
   #define F1_MR15                      0x0055
   #define F1_MR16                      0x0000
   #define F1_MR17                      0x0000
   #define F1_MR20                      0x0055
   #define F1_MR22                      {0x0006}
   #define F1_MR23                      0x003F

   #define XPLL_F1_CLKFBOUT_LT          0x27
   #define XPLL_F1_CLKFBOUT_HT          0x27
   #define XPLL_F1_DIVCLK_LT            0x02
   #define XPLL_F1_DIVCLK_HT            0x02

   #define F1_ADD_CMD_DELAY             0 
   #define F1_ADD_CMD_DELAY_EN          0 
   #define DDRMC_LOC                   NONE
#define F0_MODE_DQS_GATE_CAL          CAL_EN
#define F0_MODE_READ_DQ_CAL           CAL_EN
#define F0_MODE_WRITE_LEVELING        CAL_EN
#define F0_MODE_WRITE_DQ_DBI_CAL      CAL_EN
#define F0_MODE_WRITE_LATENCY_CAL     CAL_EN
#define F0_MODE_PRBS_READ             CAL_SKIP
#define F0_MODE_PRBS_WRITE            CAL_SKIP
#define F0_MODE_READ_DBI_CAL CAL_SKIP                     
#define F0_MODE_READ_DQ_DBI_CAL_COMPLEX CAL_EN
#define F0_MODE_WRITE_DQ_DBI_CAL_COMPLEX CAL_EN


#define MIN_VLD_CNT_CTRL false

//MC Registers

#define F0_REG_CONFIG1		0x00000006
#define F1_REG_CONFIG1		0x00000000
#define F0_REG_CONFIG2		0x00000000
#define F1_REG_CONFIG2		0x00000000
#define F0_REG_SCRUB2		0x00000005
#define F1_REG_SCRUB2		0x00000000
#define F0_REG_MRS_2		0x00000003
#define F1_REG_MRS_2		0x00000000


#endif // _CAL_CONFIG_DEFINES_0_H_