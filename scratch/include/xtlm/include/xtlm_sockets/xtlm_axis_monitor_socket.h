
// (c) Copyright 2013 - 2019 Xilinx, Inc. All rights reserved.
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
#ifndef XTLM_AXIS_MONITOR_SOCKET_H_
#define XTLM_AXIS_MONITOR_SOCKET_H_

#include "utils/xtlm_cmnhdr.h"

#ifdef XTLM_DLL
#define XTLM_AXIS_MONITOR_SOCKET_EXPORT XTLM_EXPORT
#else
#define XTLM_AXIS_MONITOR_SOCKET_EXPORT XTLM_IMPORT
#endif

#include "xtlm_generic_payload/axis_payload.h"
#include "xtlm_sockets/xtlm_axis_sockets_base.h"
#include "xtlm_interfaces/xtlm_axis_monitor_base.h"

namespace xtlm {
class xtlm_axis_monitor_socket_impl;
class xtlm_axis_initiator_socket;
class xtlm_axis_target_socket;
class xtlm_axis_simple_initiator_socket_tagged;
class xtlm_axis_passthrough_target_socket_tagged;
class XTLM_AXIS_MONITOR_SOCKET_EXPORT xtlm_axis_monitor_socket: public sc_core::sc_export<
		xtlm_axis_monitor_base>,
		public xtlm_axis_sockets_base {
public:
	typedef sc_core::sc_export<xtlm_axis_monitor_base> export_base_type;
	typedef sc_core::sc_port<xtlm_axis_monitor_base, 1, SC_ZERO_OR_MORE_BOUND> mon_port_type;

	const char* kind() const {
		return "xtlm_aximm_monitor_socket";
	}

	//xtlm_aximm_monitor_socket(const char* name, int width);

	//Special constructor to mark if it is getting used for hierarichal binding
	//Don't create mon_port for hierarichal binding
	xtlm_axis_monitor_socket(const char* name, int width, bool hier = false);

	void bind(xtlm_axis_monitor_socket& skt);
	void operator()(xtlm_axis_monitor_socket& s) {
		bind(s);
	}

	void bind(xtlm_axis_monitor_base& intf);
	void operator()(xtlm_axis_monitor_base& intf) {
		bind(intf);
	}

	void bind(xtlm_axis_initiator_socket& skt);
	void operator()(xtlm_axis_initiator_socket& skt) {
		bind(skt);
	}

	void bind(xtlm_axis_target_socket& skt);
	void operator()(xtlm_axis_target_socket& skt) {
		bind(skt);
	}

	void bind(xtlm_axis_simple_initiator_socket_tagged& skt);
	void operator()(xtlm_axis_simple_initiator_socket_tagged& skt) {
		bind(skt);
	}

	void bind(xtlm_axis_passthrough_target_socket_tagged& skt);
	void operator()(xtlm_axis_passthrough_target_socket_tagged& skt) {
		bind(skt);
	}

	void bind(mon_port_type& skt);
	void operator()(mon_port_type& skt) {
		bind(skt);
	}
private:
    xsc::common_cpp::report_handler m_logger;
	mon_port_type* mon_port;
	bool is_hier;
	void end_of_elaboration();
};
}

#endif /* XTLM_AXIS_MONITOR_SOCKET_H_ */
