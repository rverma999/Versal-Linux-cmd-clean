
// (c) Copyright(C) 2013 - 2018 by Xilinx, Inc. All rights reserved.
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

#ifndef __XTLM_AXIMM_TARGET_STUB__
#define __XTLM_AXIMM_TARGET_STUB__

#include "xtlm_interfaces/xtlm_aximm_target_base.h"
#include "xtlm_sockets/xtlm_aximm_target_socket.h"
#include "xtlm_generic_payload/xtlm_aximm_phases.h"
#include "utils/xtlm_cmnhdr.h"

namespace xtlm {

class xtlm_aximm_target_stub: public sc_core::sc_module,
		public xtlm_aximm_target_base {
public:
	xtlm_aximm_target_stub(sc_core::sc_module_name name, int width) :
			sc_module(name), xtlm::xtlm_aximm_target_base("target_base"), target_socket(
					"target_socket", width) {
		target_socket(*this);
	}

	//! TLM farward interface implementation
	tlm::tlm_sync_enum nb_transport_fw(xtlm::aximm_payload& trans,
			tlm::tlm_phase& phase, sc_core::sc_time& delay) {
		SC_REPORT_WARNING(this->name(),
				"Ignoring Transaction received at stub model");
		return tlm::TLM_ACCEPTED;
	}

    void bind(xtlm_aximm_initiator_socket &s)
    {
        target_socket.bind(s);
    }

    void operator()(xtlm_aximm_initiator_socket& s)
    {
        bind(s);
    }
    
	//!target socket for stubbing initiator
	xtlm_aximm_target_socket target_socket;
};

}
#endif


