#ifndef IP_VITIS_DESIGN_NOC_LPDDR4_0_H_
#define IP_VITIS_DESIGN_NOC_LPDDR4_0_H_

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


#ifndef XTLM
#include "xtlm.h"
#endif
#ifndef SYSTEMC_INCLUDED
#include <systemc>
#endif

#if defined(_MSC_VER)
#define DllExport __declspec(dllexport)
#elif defined(__GNUC__)
#define DllExport __attribute__ ((visibility("default")))
#else
#define DllExport
#endif

#include "vitis_design_noc_lpddr4_0_sc.h"




#ifdef XILINX_SIMULATOR
class DllExport vitis_design_noc_lpddr4_0 : public vitis_design_noc_lpddr4_0_sc
{
public:

  vitis_design_noc_lpddr4_0(const sc_core::sc_module_name& nm);
  virtual ~vitis_design_noc_lpddr4_0();

  // module pin-to-pin RTL interface

  sc_core::sc_in< sc_dt::sc_bv<1> > S00_INI_internoc;
  sc_core::sc_in< sc_dt::sc_bv<1> > S01_INI_internoc;
  sc_core::sc_in< sc_dt::sc_bv<1> > S02_INI_internoc;
  sc_core::sc_in< sc_dt::sc_bv<1> > S03_INI_internoc;
  sc_core::sc_in< sc_dt::sc_bv<1> > sys_clk0_clk_p;
  sc_core::sc_in< sc_dt::sc_bv<1> > sys_clk0_clk_n;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH0_LPDDR4_0_dq_a;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH0_LPDDR4_0_dq_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dqs_t_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dqs_t_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dqs_c_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dqs_c_b;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH0_LPDDR4_0_ca_a;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH0_LPDDR4_0_ca_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_cs_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_cs_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_ck_t_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_ck_t_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_ck_c_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_ck_c_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_cke_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_cke_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dmi_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dmi_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_reset_n;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH1_LPDDR4_0_dq_a;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH1_LPDDR4_0_dq_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dqs_t_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dqs_t_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dqs_c_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dqs_c_b;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH1_LPDDR4_0_ca_a;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH1_LPDDR4_0_ca_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_cs_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_cs_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_ck_t_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_ck_t_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_ck_c_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_ck_c_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_cke_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_cke_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dmi_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dmi_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_reset_n;
  sc_core::sc_in< sc_dt::sc_bv<1> > sys_clk1_clk_p;
  sc_core::sc_in< sc_dt::sc_bv<1> > sys_clk1_clk_n;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH0_LPDDR4_1_dq_a;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH0_LPDDR4_1_dq_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dqs_t_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dqs_t_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dqs_c_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dqs_c_b;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH0_LPDDR4_1_ca_a;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH0_LPDDR4_1_ca_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_cs_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_cs_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_ck_t_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_ck_t_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_ck_c_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_ck_c_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_cke_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_cke_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dmi_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dmi_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_reset_n;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH1_LPDDR4_1_dq_a;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH1_LPDDR4_1_dq_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dqs_t_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dqs_t_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dqs_c_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dqs_c_b;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH1_LPDDR4_1_ca_a;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH1_LPDDR4_1_ca_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_cs_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_cs_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_ck_t_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_ck_t_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_ck_c_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_ck_c_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_cke_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_cke_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dmi_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dmi_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_reset_n;

  // Dummy Signals for IP Ports


protected:

  virtual void before_end_of_elaboration();

private:


};
#endif // XILINX_SIMULATOR




#ifdef XM_SYSTEMC
class DllExport vitis_design_noc_lpddr4_0 : public vitis_design_noc_lpddr4_0_sc
{
public:

  vitis_design_noc_lpddr4_0(const sc_core::sc_module_name& nm);
  virtual ~vitis_design_noc_lpddr4_0();

  // module pin-to-pin RTL interface

  sc_core::sc_in< sc_dt::sc_bv<1> > S00_INI_internoc;
  sc_core::sc_in< sc_dt::sc_bv<1> > S01_INI_internoc;
  sc_core::sc_in< sc_dt::sc_bv<1> > S02_INI_internoc;
  sc_core::sc_in< sc_dt::sc_bv<1> > S03_INI_internoc;
  sc_core::sc_in< sc_dt::sc_bv<1> > sys_clk0_clk_p;
  sc_core::sc_in< sc_dt::sc_bv<1> > sys_clk0_clk_n;
  sc_core::sc_inout< sc_dt::sc_bv<16> > CH0_LPDDR4_0_dq_a;
  sc_core::sc_inout< sc_dt::sc_bv<16> > CH0_LPDDR4_0_dq_b;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dqs_t_a;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dqs_t_b;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dqs_c_a;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dqs_c_b;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH0_LPDDR4_0_ca_a;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH0_LPDDR4_0_ca_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_cs_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_cs_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_ck_t_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_ck_t_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_ck_c_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_ck_c_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_cke_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_cke_b;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dmi_a;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dmi_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_reset_n;
  sc_core::sc_inout< sc_dt::sc_bv<16> > CH1_LPDDR4_0_dq_a;
  sc_core::sc_inout< sc_dt::sc_bv<16> > CH1_LPDDR4_0_dq_b;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dqs_t_a;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dqs_t_b;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dqs_c_a;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dqs_c_b;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH1_LPDDR4_0_ca_a;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH1_LPDDR4_0_ca_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_cs_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_cs_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_ck_t_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_ck_t_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_ck_c_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_ck_c_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_cke_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_cke_b;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dmi_a;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dmi_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_reset_n;
  sc_core::sc_in< sc_dt::sc_bv<1> > sys_clk1_clk_p;
  sc_core::sc_in< sc_dt::sc_bv<1> > sys_clk1_clk_n;
  sc_core::sc_inout< sc_dt::sc_bv<16> > CH0_LPDDR4_1_dq_a;
  sc_core::sc_inout< sc_dt::sc_bv<16> > CH0_LPDDR4_1_dq_b;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dqs_t_a;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dqs_t_b;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dqs_c_a;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dqs_c_b;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH0_LPDDR4_1_ca_a;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH0_LPDDR4_1_ca_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_cs_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_cs_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_ck_t_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_ck_t_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_ck_c_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_ck_c_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_cke_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_cke_b;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dmi_a;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dmi_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_reset_n;
  sc_core::sc_inout< sc_dt::sc_bv<16> > CH1_LPDDR4_1_dq_a;
  sc_core::sc_inout< sc_dt::sc_bv<16> > CH1_LPDDR4_1_dq_b;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dqs_t_a;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dqs_t_b;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dqs_c_a;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dqs_c_b;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH1_LPDDR4_1_ca_a;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH1_LPDDR4_1_ca_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_cs_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_cs_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_ck_t_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_ck_t_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_ck_c_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_ck_c_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_cke_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_cke_b;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dmi_a;
  sc_core::sc_inout< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dmi_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_reset_n;

  // Dummy Signals for IP Ports


protected:

  virtual void before_end_of_elaboration();

private:


};
#endif // XM_SYSTEMC




#ifdef RIVIERA
class DllExport vitis_design_noc_lpddr4_0 : public vitis_design_noc_lpddr4_0_sc
{
public:

  vitis_design_noc_lpddr4_0(const sc_core::sc_module_name& nm);
  virtual ~vitis_design_noc_lpddr4_0();

  // module pin-to-pin RTL interface

  sc_core::sc_in< sc_dt::sc_bv<1> > S00_INI_internoc;
  sc_core::sc_in< sc_dt::sc_bv<1> > S01_INI_internoc;
  sc_core::sc_in< sc_dt::sc_bv<1> > S02_INI_internoc;
  sc_core::sc_in< sc_dt::sc_bv<1> > S03_INI_internoc;
  sc_core::sc_in< sc_dt::sc_bv<1> > sys_clk0_clk_p;
  sc_core::sc_in< sc_dt::sc_bv<1> > sys_clk0_clk_n;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH0_LPDDR4_0_dq_a;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH0_LPDDR4_0_dq_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dqs_t_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dqs_t_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dqs_c_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dqs_c_b;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH0_LPDDR4_0_ca_a;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH0_LPDDR4_0_ca_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_cs_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_cs_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_ck_t_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_ck_t_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_ck_c_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_ck_c_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_cke_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_cke_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dmi_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dmi_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_reset_n;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH1_LPDDR4_0_dq_a;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH1_LPDDR4_0_dq_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dqs_t_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dqs_t_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dqs_c_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dqs_c_b;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH1_LPDDR4_0_ca_a;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH1_LPDDR4_0_ca_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_cs_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_cs_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_ck_t_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_ck_t_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_ck_c_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_ck_c_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_cke_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_cke_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dmi_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dmi_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_reset_n;
  sc_core::sc_in< sc_dt::sc_bv<1> > sys_clk1_clk_p;
  sc_core::sc_in< sc_dt::sc_bv<1> > sys_clk1_clk_n;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH0_LPDDR4_1_dq_a;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH0_LPDDR4_1_dq_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dqs_t_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dqs_t_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dqs_c_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dqs_c_b;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH0_LPDDR4_1_ca_a;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH0_LPDDR4_1_ca_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_cs_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_cs_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_ck_t_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_ck_t_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_ck_c_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_ck_c_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_cke_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_cke_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dmi_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dmi_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_reset_n;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH1_LPDDR4_1_dq_a;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH1_LPDDR4_1_dq_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dqs_t_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dqs_t_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dqs_c_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dqs_c_b;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH1_LPDDR4_1_ca_a;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH1_LPDDR4_1_ca_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_cs_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_cs_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_ck_t_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_ck_t_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_ck_c_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_ck_c_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_cke_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_cke_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dmi_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dmi_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_reset_n;

  // Dummy Signals for IP Ports


protected:

  virtual void before_end_of_elaboration();

private:


};
#endif // RIVIERA




#ifdef VCSSYSTEMC
class DllExport vitis_design_noc_lpddr4_0 : public vitis_design_noc_lpddr4_0_sc
{
public:

  vitis_design_noc_lpddr4_0(const sc_core::sc_module_name& nm);
  virtual ~vitis_design_noc_lpddr4_0();

  // module pin-to-pin RTL interface

  sc_core::sc_in< sc_dt::sc_bv<1> > S00_INI_internoc;
  sc_core::sc_in< sc_dt::sc_bv<1> > S01_INI_internoc;
  sc_core::sc_in< sc_dt::sc_bv<1> > S02_INI_internoc;
  sc_core::sc_in< sc_dt::sc_bv<1> > S03_INI_internoc;
  sc_core::sc_in< sc_dt::sc_bv<1> > sys_clk0_clk_p;
  sc_core::sc_in< sc_dt::sc_bv<1> > sys_clk0_clk_n;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH0_LPDDR4_0_dq_a;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH0_LPDDR4_0_dq_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dqs_t_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dqs_t_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dqs_c_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dqs_c_b;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH0_LPDDR4_0_ca_a;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH0_LPDDR4_0_ca_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_cs_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_cs_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_ck_t_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_ck_t_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_ck_c_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_ck_c_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_cke_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_cke_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dmi_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dmi_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_reset_n;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH1_LPDDR4_0_dq_a;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH1_LPDDR4_0_dq_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dqs_t_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dqs_t_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dqs_c_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dqs_c_b;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH1_LPDDR4_0_ca_a;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH1_LPDDR4_0_ca_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_cs_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_cs_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_ck_t_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_ck_t_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_ck_c_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_ck_c_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_cke_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_cke_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dmi_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dmi_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_reset_n;
  sc_core::sc_in< sc_dt::sc_bv<1> > sys_clk1_clk_p;
  sc_core::sc_in< sc_dt::sc_bv<1> > sys_clk1_clk_n;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH0_LPDDR4_1_dq_a;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH0_LPDDR4_1_dq_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dqs_t_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dqs_t_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dqs_c_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dqs_c_b;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH0_LPDDR4_1_ca_a;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH0_LPDDR4_1_ca_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_cs_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_cs_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_ck_t_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_ck_t_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_ck_c_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_ck_c_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_cke_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_cke_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dmi_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dmi_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_reset_n;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH1_LPDDR4_1_dq_a;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH1_LPDDR4_1_dq_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dqs_t_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dqs_t_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dqs_c_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dqs_c_b;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH1_LPDDR4_1_ca_a;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH1_LPDDR4_1_ca_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_cs_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_cs_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_ck_t_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_ck_t_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_ck_c_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_ck_c_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_cke_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_cke_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dmi_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dmi_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_reset_n;

  // Dummy Signals for IP Ports


protected:

  virtual void before_end_of_elaboration();

private:


  // Transactor stubs

  // Socket stubs

};
#endif // VCSSYSTEMC




#ifdef MTI_SYSTEMC
class DllExport vitis_design_noc_lpddr4_0 : public vitis_design_noc_lpddr4_0_sc
{
public:

  vitis_design_noc_lpddr4_0(const sc_core::sc_module_name& nm);
  virtual ~vitis_design_noc_lpddr4_0();

  // module pin-to-pin RTL interface

  sc_core::sc_in< sc_dt::sc_bv<1> > S00_INI_internoc;
  sc_core::sc_in< sc_dt::sc_bv<1> > S01_INI_internoc;
  sc_core::sc_in< sc_dt::sc_bv<1> > S02_INI_internoc;
  sc_core::sc_in< sc_dt::sc_bv<1> > S03_INI_internoc;
  sc_core::sc_in< sc_dt::sc_bv<1> > sys_clk0_clk_p;
  sc_core::sc_in< sc_dt::sc_bv<1> > sys_clk0_clk_n;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH0_LPDDR4_0_dq_a;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH0_LPDDR4_0_dq_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dqs_t_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dqs_t_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dqs_c_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dqs_c_b;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH0_LPDDR4_0_ca_a;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH0_LPDDR4_0_ca_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_cs_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_cs_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_ck_t_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_ck_t_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_ck_c_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_ck_c_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_cke_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_cke_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dmi_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_0_dmi_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_0_reset_n;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH1_LPDDR4_0_dq_a;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH1_LPDDR4_0_dq_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dqs_t_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dqs_t_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dqs_c_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dqs_c_b;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH1_LPDDR4_0_ca_a;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH1_LPDDR4_0_ca_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_cs_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_cs_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_ck_t_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_ck_t_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_ck_c_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_ck_c_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_cke_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_cke_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dmi_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_0_dmi_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_0_reset_n;
  sc_core::sc_in< sc_dt::sc_bv<1> > sys_clk1_clk_p;
  sc_core::sc_in< sc_dt::sc_bv<1> > sys_clk1_clk_n;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH0_LPDDR4_1_dq_a;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH0_LPDDR4_1_dq_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dqs_t_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dqs_t_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dqs_c_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dqs_c_b;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH0_LPDDR4_1_ca_a;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH0_LPDDR4_1_ca_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_cs_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_cs_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_ck_t_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_ck_t_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_ck_c_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_ck_c_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_cke_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_cke_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dmi_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH0_LPDDR4_1_dmi_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH0_LPDDR4_1_reset_n;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH1_LPDDR4_1_dq_a;
  sc_core::sc_out< sc_dt::sc_bv<16> > CH1_LPDDR4_1_dq_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dqs_t_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dqs_t_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dqs_c_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dqs_c_b;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH1_LPDDR4_1_ca_a;
  sc_core::sc_out< sc_dt::sc_bv<6> > CH1_LPDDR4_1_ca_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_cs_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_cs_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_ck_t_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_ck_t_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_ck_c_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_ck_c_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_cke_a;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_cke_b;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dmi_a;
  sc_core::sc_out< sc_dt::sc_bv<2> > CH1_LPDDR4_1_dmi_b;
  sc_core::sc_out< sc_dt::sc_bv<1> > CH1_LPDDR4_1_reset_n;

  // Dummy Signals for IP Ports


protected:

  virtual void before_end_of_elaboration();

private:


  // Transactor stubs

  // Socket stubs

};
#endif // MTI_SYSTEMC
#endif // IP_VITIS_DESIGN_NOC_LPDDR4_0_H_
