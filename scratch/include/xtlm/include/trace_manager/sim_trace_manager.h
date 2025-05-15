
/*  (c) Copyright 2014 - 2016 Xilinx, Inc. All rights reserved.
   
    This file contains confidential and proprietary information
    of Xilinx, Inc. and is protected under U.S. and
    international copyright and other intellectual property
    laws.
   
    DISCLAIMER
    This disclaimer is not a license and does not grant any
    rights to the materials distributed herewith. Except as
    otherwise provided in a valid license issued to you by
    Xilinx, and to the maximum extent permitted by applicable
    law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
    WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
    AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
    BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
    INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
    (2) Xilinx shall not be liable (whether in contract or tort,
    including negligence, or under any other theory of
    liability) for any loss or damage of any kind or nature
    related to, arising under or in connection with these
    materials, including for any direct, or any indirect,
    special, incidental, or consequential loss or damage
    (including loss of data, profits, goodwill, or any type of
    loss or damage suffered as a result of any action brought
    by a third party) even if such damage or loss was
    reasonably foreseeable or Xilinx had been advised of the
    possibility of the same.
   
    CRITICAL APPLICATIONS
    Xilinx products are not designed or intended to be fail-
    safe, or for use in any application requiring fail-safe
    performance, such as life-support or safety devices or
    systems, Class III medical devices, nuclear facilities,
    applications related to the deployment of airbags, or any
    other applications that could lead to death, personal
    injury, or severe property or environmental damage
    (individually and collectively, "Critical
    Applications"). Customer assumes the sole risk and
    liability of any use of Xilinx products in Critical
    Applications, subject only to applicable laws and
    regulations governing limitations on product liability.
   
    THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
    PART OF THIS FILE AT ALL TIMES.                       */

#ifndef XSC_SIM_TRACE_MANAGER_H
#define XSC_SIM_TRACE_MANAGER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

namespace aie_sim {

    class sim_trace_manager {
    public:
        static sim_trace_manager& get_instance();
    
        /*API to register callbacks corresponding to event name*/
        void register_callback(std::string name, std::function<void(int, int, std::string)> callback);
        void register_callback(std::string name, std::function<void(std::string)> callback);    

        /*Trigger API's to dump L1 Memory*/
        void requestL1MemDumpAt(int col, int row, std::string label);
        void requestL1MemDump(std::string label);

        /*Trigger API's to dump L2 Memory*/
        void requestL2MemDumpAt(int col, int row, std::string label);
        void requestL2MemDump(std::string label);

        /*Trigger API's to dump L3 Memory*/
        void requestL3MemDump(std::string label);

        /*Update AIE sim trace manager config*/
        void updateArrayConfig(int total_cols, int total_rows, int mem_rows);

    private:
        int max_rows = 11;
        int max_cols = 38;
        int num_mem_rows = 2;

        sim_trace_manager(){};
        sim_trace_manager(const sim_trace_manager&) = delete;
        sim_trace_manager& operator=(const sim_trace_manager&) = delete;
        ~sim_trace_manager() = default;
    
        std::unordered_map<std::string, std::function<void(int, int, std::string)>> events_tile;
        std::unordered_map<std::string, std::function<void(std::string)>> events_l3;
    };
}
#endif // XSC_SIM_TRACE_MANAGER_H
