# ==============================================================
# Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
# Tool Version Limit: 2024.05
# Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
# Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
# 
# ==============================================================
source -notrace "/tools/Xilinx/Vitis_HLS/2024.1/common/scripts/ipxhls.tcl"
set ip_dir "/home/wes_2025_r_verma/capstone_project/Versal-Linux-cmd-clean_0507/gemm_extended_dma_1_burst_opr/mm2s/hls/impl/ip"
set data_file "/home/wes_2025_r_verma/capstone_project/Versal-Linux-cmd-clean_0507/gemm_extended_dma_1_burst_opr/mm2s/hls/hls_data.json"
set ip_types "vitis sysgen"
if { [catch {::ipx::utils::package_hls_ip $ip_dir $data_file $ip_types } res] } {
  puts "Caught error:\n$::errorInfo"
  error $res
}
