/*  (c) Copyright 1995 - 2018 AMD, Inc. All rights reserved.

 This file contains confidential and proprietary information
 of AMD, Inc. and is protected under U.S. and
 international copyright and other intellectual property
 laws.

 DISCLAIMER
 This disclaimer is not a license and does not grant any
 rights to the materials distributed herewith. Except as
 otherwise provided in a valid license issued to you by
 AMD, and to the maximum extent permitted by applicable
 law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
 WITH ALL FAULTS, AND AMD HEREBY DISCLAIMS ALL WARRANTIES
 AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
 INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
 (2) AMD shall not be liable (whether in contract or tort,
 including negligence, or under any other theory of
 liability) for any loss or damage of any kind or nature
 related to, arising under or in connection with these
 materials, including for any direct, or any indirect,
 special, incidental, or consequential loss or damage
 (including loss of data, profits, goodwill, or any type of
 loss or damage suffered as a result of any action brought
 by a third party) even if such damage or loss was
 reasonably foreseeable or AMD had been advised of the
 possibility of the same.

 CRITICAL APPLICATIONS
 AMD products are not designed or intended to be fail-
 safe, or for use in any application requiring fail-safe
 performance, such as life-support or safety devices or
 systems, Class III medical devices, nuclear facilities,
 applications related to the deployment of airbags, or any
 other applications that could lead to death, personal
 injury, or severe property or environmental damage
 (individually and collectively, "Critical
 Applications"). Customer assumes the sole risk and
 liability of any use of AMD products in Critical
 Applications, subject only to applicable laws and
 regulations governing limitations on product liability.

 THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
 PART OF THIS FILE AT ALL TIMES.                       */



#include "aie_extra_defines.h"
#include "ai_engine.h"
#include <sstream>

namespace cips_tlm {
    void __attribute__((weak)) export_simulation();
}

    ai_engine::ai_engine(sc_module_name nm, xsc::common_cpp::properties& me_properties)
       :me_core_clk("me_core_clk", 1.0/1250, SC_US),
        aie_cfg(true) 
    {
        check_aie_sim_options();
        process_AP_FT();
        if(cips_tlm::export_simulation) {
            cips_tlm::export_simulation();
        }
        aie_cfg.set_fast_pm_dm(
                me_properties.getBool("fast_pm_write"), 
                me_properties.getBool("fast_dm_write")); 

        if(std::getenv("AIE_WORK_DIR") && !std::getenv("COSIM_MACHINE_PATH")) {
            setenv("VITIS_EMU_DISABLE_AIE_NPI","true",1);
        }

        set_sim_config();
        aie_cfg.set_noc2aie_mm_cfg(1);

        //AXIS stream out ports width

        //AXIS stream in ports width

        for(unsigned int indx = 0; indx < s_axis_width_map.size(); indx++) {
            aie_cfg.set_pl2aie_stream_width(indx, s_axis_width_map.at(indx));
        }

        for(unsigned int indx = 0; indx < m_axis_width_map.size(); indx++) {
            aie_cfg.set_aie2pl_stream_width(indx,  m_axis_width_map.at(indx));
        }


        aie_logical_inst = new xsc::aie::aie_logical("aie_logical", aie_cfg);
        aie_logical_inst->clk(me_core_clk);

        //if( (getenv("AIE_WORK_DIR") != NULL) ) {        
        if(std::getenv("AIE_WORK_DIR") && !std::getenv("COSIM_MACHINE_PATH")) {
        S00_Aximm_wr_util = new xtlm::xtlm_aximm_target_wr_socket_util("S00_Aximm_wr_util", xtlm::aximm::TRANSACTION, 128); 
        S00_Aximm_rd_util = new xtlm::xtlm_aximm_target_rd_socket_util("S00_Aximm_rd_util", xtlm::aximm::TRANSACTION, 128); 
        S00_AXI_tlm_aximm_read_socket = new xtlm::xtlm_aximm_target_socket("S00_AXI_tlm_aximm_read_socket",128);
        S00_AXI_tlm_aximm_write_socket = new xtlm::xtlm_aximm_target_socket("S00_AXI_tlm_aximm_write_socket",128);
        S00_AXI_tlm_aximm_write_socket->bind(S00_Aximm_wr_util->wr_socket);
        S00_AXI_tlm_aximm_read_socket->bind(S00_Aximm_rd_util->rd_socket);
        m_aie_ps = new aie_ps("aie_ps");
        m_aie_ps->M0_AXI_rd_socket->bind(*aie_logical_inst->S_AXIMM_rd_socket[0]);
        m_aie_ps->M0_AXI_wr_socket->bind(*aie_logical_inst->S_AXIMM_wr_socket[0]);
        m_aie_ps->m0_axi_aclk.bind(s00_axi_aclk);
        m_aie_ps->m0_axi_aresetn(aie_ps_reset);
        } else {
        S00_AXI_tlm_aximm_read_socket =  aie_logical_inst->S_AXIMM_rd_socket[0];
        S00_AXI_tlm_aximm_write_socket = aie_logical_inst->S_AXIMM_wr_socket[0];
        m_aie_ps = 0;
        S00_Aximm_rd_util = 0;
        S00_Aximm_wr_util = 0;
        }

        //AXIS stream out ports

        //AXIS stream in ports



        //! Set NOC Stream Clock periods

        //! Set NOC Slave AXIMM Clock periods
        s00_axi_aclk_period = sc_time(1.0/1250000000, SC_SEC);

        //! Set NOC Master AXIMM Clock periods

        //! Register Clock Generation sc_methods
        SC_METHOD(s00_axi_aclk_gen);
        //if( (getenv("AIE_WORK_DIR") != NULL) ) {        
        if(std::getenv("AIE_WORK_DIR") && !std::getenv("COSIM_MACHINE_PATH")) {
            SC_METHOD(set_aie_ps_reset);        
        }
    }
    void ai_engine::set_aie_ps_reset() {
        aie_ps_reset.write(true);
    }    

    void ai_engine::set_sim_config()
    {
        aie_cfg.set_device_file(xsc::aie::env::get_device_file());
        aie_cfg.set_aie_shim_sol_file(xsc::aie::env::get_shim_sol_file());
        aie_cfg.set_vcd_trace(xsc::aie::env::is_vcd_trace_enabled());
        aie_cfg.set_debug_trace(xsc::aie::env::is_debug_trace_enabled());
        aie_cfg.set_aie_profiling(xsc::aie::env::is_aie_profiling_enabled());
    }

    //! NOC Stream Clock generation methods

    //! NOC Slave AXIMM Clock generation methods
     void ai_engine::s00_axi_aclk_gen()
     {
         s00_axi_aclk = !s00_axi_aclk;
         next_trigger(s00_axi_aclk_period);
     }

    //! NOC Master AXIMM Clock generation methods

    ai_engine::~ai_engine() {
        //if( (getenv("AIE_WORK_DIR") != NULL) ) {        
        if(std::getenv("AIE_WORK_DIR") && !std::getenv("COSIM_MACHINE_PATH")) {
            delete m_aie_ps;
        }
    }
    void ai_engine::process_AP_FT() {
        
        std::stringstream ap_m("M00_AXIS{AUTO_PIPELINE 0}");
        std::stringstream ap_s("S00_AXIS{AUTO_PIPELINE 0}");
        std::stringstream ft_m("M00_AXIS{FIFO_TYPE 0}");
        std::stringstream ft_s("S00_AXIS{FIFO_TYPE 0}");  
        map_AUTOPIPE_LINE_MI = new std::map<int,bool>;
        map_AUTOPIPE_LINE_SI = new std::map<int,bool>;
        map_FIFOTYPE_MI      = new std::map<int,int>;
        map_FIFOTYPE_SI      = new std::map<int,int>;
        map_is_registered_MI = new std::map<int,bool>;
        map_is_registered_SI = new std::map<int,bool>;
        int indx,value;

        int counter=0;
        //processing AUTO PIPE LINE for Master stream Interfaces
        while(counter < ap_m.str().size()) {
            ap_m.ignore(1,'M');
            ap_m >> indx;
            ap_m.ignore(20,' ');
            ap_m >> value;
            ap_m.ignore(2,':');
            (*map_AUTOPIPE_LINE_MI)[indx] = value == 0 ? false : true;
            counter +=26;
        }
        //processing AUTO PIPE LINE for Slave stream Interfaces
        counter = 0;
        while(counter <ap_s.str().size()) {
            ap_s.ignore(1,'S');
            ap_s >> indx;
            ap_s.ignore(20,' ');
            ap_s >> value;
            ap_s.ignore(2,':');
            (*map_AUTOPIPE_LINE_SI)[indx] = value == 0 ? false : true;
            counter+=26;
        }

        //processing FIFOTYPE for Master stream Interfaces
        counter = 0;
        while(counter <ft_m.str().size()) {
            ft_m.ignore(1,'M');
            ft_m >> indx;
            ft_m.ignore(16,' ');
            ft_m >> value;
            ft_m.ignore(2,':');
            (*map_FIFOTYPE_MI)[indx] = value;
            counter+=22;
        }
        //processing FIFOTYPE for Slave stream Interfaces
        counter = 0;
        while(counter <ft_s.str().size()) {
            ft_s.ignore(1,'S');
            ft_s >> indx;
            ft_s.ignore(16,' ');
            ft_s >> value;
            (*map_FIFOTYPE_SI)[indx] = value;
            ft_s.ignore(2,':');
            counter+=22;
        }
        //fetching BLI(IS_REGISTERED) Interface property


      aie_cfg.set_map_AUTOPIPE_LINE_MI(map_AUTOPIPE_LINE_MI);
      aie_cfg.set_map_AUTOPIPE_LINE_SI(map_AUTOPIPE_LINE_SI);
      aie_cfg.set_map_FIFOTYPE_MI(map_FIFOTYPE_MI);
      aie_cfg.set_map_FIFOTYPE_SI(map_FIFOTYPE_SI);
      aie_cfg.set_map_is_registered_MI(map_is_registered_MI);
      aie_cfg.set_map_is_registered_SI(map_is_registered_SI);

    }

    void ai_engine::check_aie_sim_options() {
        char* envar = getenv("AIESIM_OPTIONS");
        if ( envar == NULL )
            return;
        
        std::string file_path = envar;

        std::ifstream file(file_path);
        if (!file) {
           return;
        }
        std::string line;

        while (std::getline(file, line)) {
           std::istringstream linestream(line);
           std::string token;
           while (std::getline(linestream, token, '=')) {
              if (std::strcmp(token.c_str(),"MTMODEL") == 0) {
                 std::getline(linestream, token, '=');
                 if (std::strcmp(token.c_str(),"true") == 0)
                     aie_cfg.set_is_msm_en(true);
                 break;
              }
           }
        }
        file.close();
    }
