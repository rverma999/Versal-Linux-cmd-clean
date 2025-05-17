# Monitor points

# Platform options
set_property HDL_ATTRIBUTE.DPA_AXILITE_MASTER true [get_bd_intf_pins /icn_ctrl_1/M09_AXI]
set_property HDL_ATTRIBUTE.DPA_TRACE_MASTER true [get_bd_intf_pins /icn_ctrl_1/M10_AXI]

#Trace Dictionaries
set default_trace [dict create \
  DEPTH 8192 \
  MEM_SPACE FIFO \
  MEM_INDEX 0 \
  MASTER /icn_ctrl_1/M10_AXI \
  CLK_SRC /mm2s_1/ap_clk \
  RST_SRC /mm2s_1/ap_rst_n \
  SLR SLR0 \
  DEDICATED 1 \
];


# Call debug/profiling automation
set dpa_dict [list \
              [get_bd_intf_pins s2mm/s]  {TYPE data DETAIL all CLK_SRC /s2mm/ap_clk RST_SRC /s2mm/ap_rst_n MEMORY Stream PRINTABLE_KEY {[get_bd_intf_pins s2mm/s]} INS_MODE auto} \
              [get_bd_intf_pins mm2s_1/m_axi_gmem]  {TYPE data DETAIL all CLK_SRC /mm2s_1/ap_clk RST_SRC /mm2s_1/ap_rst_n MEMORY DDR PRINTABLE_KEY {[get_bd_intf_pins mm2s_1/m_axi_gmem]} INS_MODE auto} \
              [get_bd_intf_pins mm2s_1/s]  {TYPE data DETAIL all CLK_SRC /mm2s_1/ap_clk RST_SRC /mm2s_1/ap_rst_n MEMORY Stream PRINTABLE_KEY {[get_bd_intf_pins mm2s_1/s]} INS_MODE auto} \
              [get_bd_intf_pins mm2s_2/m_axi_gmem]  {TYPE data DETAIL all CLK_SRC /mm2s_2/ap_clk RST_SRC /mm2s_2/ap_rst_n MEMORY DDR PRINTABLE_KEY {[get_bd_intf_pins mm2s_2/m_axi_gmem]} INS_MODE auto} \
              [get_bd_intf_pins mm2s_2/s]  {TYPE data DETAIL all CLK_SRC /mm2s_2/ap_clk RST_SRC /mm2s_2/ap_rst_n MEMORY Stream PRINTABLE_KEY {[get_bd_intf_pins mm2s_2/s]} INS_MODE auto} \
              [get_bd_intf_pins s2mm/m_axi_gmem]  {TYPE data DETAIL all CLK_SRC /s2mm/ap_clk RST_SRC /s2mm/ap_rst_n MEMORY DDR PRINTABLE_KEY {[get_bd_intf_pins s2mm/m_axi_gmem]} INS_MODE auto} \
             ]
set dpa_opts [list \
              SETTINGS  {HW_EMU true IS_EMBEDDED true VERSAL_DFX 0} \
              AIE_TRACE  {FIFO_DEPTH 4096 PACKET_RATE 100 CLK_SELECT default PROFILE_STREAMS false MEM_TYPE DDR MEM_SPACE DDR MEM_INDEX 0} \
              SYSTEM_DEADLOCK  {DEADLOCK_OPTION disable} \
              AXILITE  {MASTER /icn_ctrl_1/M09_AXI CLK_SRC /mm2s_1/ap_clk RST_SRC /mm2s_1/ap_rst_n} \
              TRACE_OFFLOAD  $default_trace \
             ]

set_param bd.enable_dpa 1
set_param bd.debug_profile.script /home/wes_2025_r_verma/capstone_project/Versal-Linux-cmd-clean_0507/gemm_extended_dma_1_burst_opr/_x/link/vivado/vpl/.local/debug_profile_automation.tcl
apply_bd_automation -rule xilinx.com:bd_rule:debug_profile -opts $dpa_opts -dict $dpa_dict

# Write debug_ip_layout
debug_profile::write_debug_ip_layout true "xilinx.com:xd:xilinx_vck190_base_202410_1:202410.1" "/home/wes_2025_r_verma/capstone_project/Versal-Linux-cmd-clean_0507/gemm_extended_dma_1_burst_opr/_x/link/int"
