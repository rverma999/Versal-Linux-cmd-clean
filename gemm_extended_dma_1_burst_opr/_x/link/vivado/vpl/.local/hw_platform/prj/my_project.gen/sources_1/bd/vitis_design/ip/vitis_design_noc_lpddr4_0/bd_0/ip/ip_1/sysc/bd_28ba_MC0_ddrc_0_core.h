//**********************************************************************
// Copyright (c) 2016-2019 Xilinx Inc.  All Rights Reserved
//
//   TLM wrapper for NoC mc_ddr4.
//
//**********************************************************************
#ifndef bd_28ba_MC0_ddrc_0_core_h_
#define bd_28ba_MC0_ddrc_0_core_h_

#include "NOCDdrMcXtlm.h"
#include "properties.h"

class bd_28ba_MC0_ddrc_0_core : public NOCDdrMcXtlm
{
public:
  bd_28ba_MC0_ddrc_0_core( sc_core::sc_module_name nm, const xsc::common_cpp::properties& props )
  : NOCDdrMcXtlm(nm, props)
  {
  }

  virtual ~bd_28ba_MC0_ddrc_0_core()
  {
  }

public:  // stub pin-to-pin RTL interface

  sc_core::sc_in< bool >sys_clk_p;
  sc_core::sc_in< bool >sys_clk_n;
  sc_core::sc_out<sc_bv<16> >ch0_lpddr4_dq_a;
  sc_core::sc_out<sc_bv<2> >ch0_lpddr4_dqs_t_a;
  sc_core::sc_out<sc_bv<2> >ch0_lpddr4_dqs_c_a;
  sc_core::sc_out<sc_bv<6> >ch0_lpddr4_ca_a;
  sc_core::sc_out<sc_bv<1> >ch0_lpddr4_cs_a;
  sc_core::sc_out<sc_bv<1> >ch0_lpddr4_ck_t_a;
  sc_core::sc_out<sc_bv<1> >ch0_lpddr4_ck_c_a;
  sc_core::sc_out<sc_bv<1> >ch0_lpddr4_cke_a;
  sc_core::sc_out<sc_bv<2> >ch0_lpddr4_dmi_a;
  sc_core::sc_out<sc_bv<16> >ch0_lpddr4_dq_b;
  sc_core::sc_out<sc_bv<2> >ch0_lpddr4_dqs_t_b;
  sc_core::sc_out<sc_bv<2> >ch0_lpddr4_dqs_c_b;
  sc_core::sc_out<sc_bv<6> >ch0_lpddr4_ca_b;
  sc_core::sc_out<sc_bv<1> >ch0_lpddr4_cs_b;
  sc_core::sc_out<sc_bv<1> >ch0_lpddr4_ck_t_b;
  sc_core::sc_out<sc_bv<1> >ch0_lpddr4_ck_c_b;
  sc_core::sc_out<sc_bv<1> >ch0_lpddr4_cke_b;
  sc_core::sc_out<sc_bv<2> >ch0_lpddr4_dmi_b;
  sc_core::sc_out<sc_bv<1> >ch0_lpddr4_reset_n;
  sc_core::sc_out<sc_bv<16> >ch1_lpddr4_dq_a;
  sc_core::sc_out<sc_bv<2> >ch1_lpddr4_dqs_t_a;
  sc_core::sc_out<sc_bv<2> >ch1_lpddr4_dqs_c_a;
  sc_core::sc_out<sc_bv<6> >ch1_lpddr4_ca_a;
  sc_core::sc_out<sc_bv<1> >ch1_lpddr4_cs_a;
  sc_core::sc_out<sc_bv<1> >ch1_lpddr4_ck_t_a;
  sc_core::sc_out<sc_bv<1> >ch1_lpddr4_ck_c_a;
  sc_core::sc_out<sc_bv<1> >ch1_lpddr4_cke_a;
  sc_core::sc_out<sc_bv<2> >ch1_lpddr4_dmi_a;
  sc_core::sc_out<sc_bv<16> >ch1_lpddr4_dq_b;
  sc_core::sc_out<sc_bv<2> >ch1_lpddr4_dqs_t_b;
  sc_core::sc_out<sc_bv<2> >ch1_lpddr4_dqs_c_b;
  sc_core::sc_out<sc_bv<6> >ch1_lpddr4_ca_b;
  sc_core::sc_out<sc_bv<1> >ch1_lpddr4_cs_b;
  sc_core::sc_out<sc_bv<1> >ch1_lpddr4_ck_t_b;
  sc_core::sc_out<sc_bv<1> >ch1_lpddr4_ck_c_b;
  sc_core::sc_out<sc_bv<1> >ch1_lpddr4_cke_b;
  sc_core::sc_out<sc_bv<2> >ch1_lpddr4_dmi_b;
  sc_core::sc_out<sc_bv<1> >ch1_lpddr4_reset_n;
  sc_core::sc_in<sc_bv<8> >noc2dmc_valid_in_0;
  sc_core::sc_in<sc_bv<182> >noc2dmc_data_in_0;
  sc_core::sc_in< bool >noc2dmc_credit_rdy_0;
  sc_core::sc_out<sc_bv<8> >dmc2noc_credit_rtn_0;
  sc_core::sc_in<sc_bv<8> >noc2dmc_valid_in_1;
  sc_core::sc_in<sc_bv<182> >noc2dmc_data_in_1;
  sc_core::sc_in< bool >noc2dmc_credit_rdy_1;
  sc_core::sc_out<sc_bv<8> >dmc2noc_credit_rtn_1;
  sc_core::sc_in<sc_bv<8> >noc2dmc_valid_in_2;
  sc_core::sc_in<sc_bv<182> >noc2dmc_data_in_2;
  sc_core::sc_in< bool >noc2dmc_credit_rdy_2;
  sc_core::sc_out<sc_bv<8> >dmc2noc_credit_rtn_2;
  sc_core::sc_in<sc_bv<8> >noc2dmc_valid_in_3;
  sc_core::sc_in<sc_bv<182> >noc2dmc_data_in_3;
  sc_core::sc_in< bool >noc2dmc_credit_rdy_3;
  sc_core::sc_out<sc_bv<8> >dmc2noc_credit_rtn_3;
  sc_core::sc_out<sc_bv<8> >dmc2noc_valid_out_0;
  sc_core::sc_out<sc_bv<182> >dmc2noc_data_out_0;
  sc_core::sc_out< bool >dmc2noc_credit_rdy_0;
  sc_core::sc_in<sc_bv<8> >noc2dmc_credit_rtn_0;
  sc_core::sc_out<sc_bv<8> >dmc2noc_valid_out_1;
  sc_core::sc_out<sc_bv<182> >dmc2noc_data_out_1;
  sc_core::sc_out< bool >dmc2noc_credit_rdy_1;
  sc_core::sc_in<sc_bv<8> >noc2dmc_credit_rtn_1;
  sc_core::sc_out<sc_bv<8> >dmc2noc_valid_out_2;
  sc_core::sc_out<sc_bv<182> >dmc2noc_data_out_2;
  sc_core::sc_out< bool >dmc2noc_credit_rdy_2;
  sc_core::sc_in<sc_bv<8> >noc2dmc_credit_rtn_2;
  sc_core::sc_out<sc_bv<8> >dmc2noc_valid_out_3;
  sc_core::sc_out<sc_bv<182> >dmc2noc_data_out_3;
  sc_core::sc_out< bool >dmc2noc_credit_rdy_3;
  sc_core::sc_in<sc_bv<8> >noc2dmc_credit_rtn_3;
  sc_core::sc_in< bool >from_noc_0;
  sc_core::sc_in< bool >from_noc_1;
  sc_core::sc_in< bool >from_noc_2;
  sc_core::sc_in< bool >from_noc_3;
};

#endif
