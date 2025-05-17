

#---------------------------
# Constant blocks
#---------------------------

#---------------------------
# Platform Parameters for xilinx_vck190_base_202410_1
#---------------------------
set icn_ctrl_1 [get_bd_cell /icn_ctrl_1]
    
set_property -dict [ list \
  CONFIG.NUM_SI 1 \
  CONFIG.NUM_MI 9 \
  CONFIG.NUM_CLKS 3 \
  ] $icn_ctrl_1
set icn_ctrl_2 [get_bd_cell /icn_ctrl_2]
    
set_property -dict [ list \
  CONFIG.NUM_SI 1 \
  CONFIG.NUM_MI 1 \
  CONFIG.NUM_CLKS 1 \
  ] $icn_ctrl_2
set icn_ctrl_3 [get_bd_cell /icn_ctrl_3]
    
set_property -dict [ list \
  CONFIG.NUM_SI 1 \
  CONFIG.NUM_MI 1 \
  CONFIG.NUM_CLKS 1 \
  ] $icn_ctrl_3
set icn_ctrl_4 [get_bd_cell /icn_ctrl_4]
    
set_property -dict [ list \
  CONFIG.NUM_SI 1 \
  CONFIG.NUM_MI 1 \
  CONFIG.NUM_CLKS 1 \
  ] $icn_ctrl_4
set icn_ctrl_5 [get_bd_cell /icn_ctrl_5]
    
set_property -dict [ list \
  CONFIG.NUM_SI 1 \
  CONFIG.NUM_MI 1 \
  CONFIG.NUM_CLKS 1 \
  ] $icn_ctrl_5
set noc_ddr4 [get_bd_cell /noc_ddr4]
    
set_property -dict [ list \
  CONFIG.NUM_SI 3 \
  CONFIG.NUM_HBM_BLI 0 \
  CONFIG.NUM_MI 0 \
  ] $noc_ddr4
set noc_lpddr4 [get_bd_cell /noc_lpddr4]
    
set_property -dict [ list \
  CONFIG.NUM_SI 0 \
  CONFIG.NUM_HBM_BLI 0 \
  CONFIG.NUM_MI 0 \
  ] $noc_lpddr4

#---------------------------
# Registering ai_engine_0
#---------------------------
set ai_engine_0 [get_bd_cells /ai_engine_0]
  
set_property -dict [ list  \
  CONFIG.NUM_MI_AXIS {1} \
  CONFIG.NUM_SI_AXIS {2} \
  CONFIG.NUM_MI_AXI {0} \
  CONFIG.NUM_CLKS {1} \
  CONFIG.C_EN_EXT_RST {1}  ] $ai_engine_0

set_property -dict [ list  \
  CONFIG.TDATA_NUM_BYTES {16} \
  CONFIG.IS_REGISTERED {true} \
  HDL_ATTRIBUTE.ME_ANNOTATION {mygraph_A_0_} ] [ get_bd_intf_pins $ai_engine_0/S00_AXIS]

set_property -dict [ list  \
  CONFIG.TDATA_NUM_BYTES {16} \
  CONFIG.IS_REGISTERED {true} \
  HDL_ATTRIBUTE.ME_ANNOTATION {mygraph_B_0_} ] [ get_bd_intf_pins $ai_engine_0/S01_AXIS]

set_property -dict [ list  \
  CONFIG.TDATA_NUM_BYTES {16} \
  CONFIG.IS_REGISTERED {true} \
  HDL_ATTRIBUTE.ME_ANNOTATION {mygraph_C_0_} ] [ get_bd_intf_pins $ai_engine_0/M00_AXIS]

set_property -dict [ list  \
  CONFIG.ASSOCIATED_BUSIF {} ] [ get_bd_pins $ai_engine_0/aclk0]


#---------------------------
# Instantiating mm2s_1
#---------------------------
set mm2s_1 [create_bd_cell -type ip -vlnv xilinx.com:hls:mm2s:1.0 mm2s_1]
  


#---------------------------
# Instantiating mm2s_2
#---------------------------
set mm2s_2 [create_bd_cell -type ip -vlnv xilinx.com:hls:mm2s:1.0 mm2s_2]
  


#---------------------------
# Instantiating s2mm
#---------------------------
set s2mm [create_bd_cell -type ip -vlnv xilinx.com:hls:s2mm:1.0 s2mm]
  


#---------------------------
# Instantiating dwc_ai_engine_0_M00_AXIS
#---------------------------
set dwc_ai_engine_0_M00_AXIS [create_bd_cell -type ip -vlnv xilinx.com:ip:axis_dwidth_converter:1.1 dwc_ai_engine_0_M00_AXIS]
  
set_property -dict [ list  \
  CONFIG.M_TDATA_NUM_BYTES {4} \
  CONFIG.S_TDATA_NUM_BYTES {16}  ] $dwc_ai_engine_0_M00_AXIS

#---------------------------
# Instantiating dwc_mm2s_1_s
#---------------------------
set dwc_mm2s_1_s [create_bd_cell -type ip -vlnv xilinx.com:ip:axis_dwidth_converter:1.1 dwc_mm2s_1_s]
  
set_property -dict [ list  \
  CONFIG.M_TDATA_NUM_BYTES {16} \
  CONFIG.S_TDATA_NUM_BYTES {4}  ] $dwc_mm2s_1_s

#---------------------------
# Instantiating dwc_mm2s_2_s
#---------------------------
set dwc_mm2s_2_s [create_bd_cell -type ip -vlnv xilinx.com:ip:axis_dwidth_converter:1.1 dwc_mm2s_2_s]
  
set_property -dict [ list  \
  CONFIG.M_TDATA_NUM_BYTES {16} \
  CONFIG.S_TDATA_NUM_BYTES {4}  ] $dwc_mm2s_2_s

#---------------------------
# Instantiating axi_intc_cascaded_1_intr_1_interrupt_concat
#---------------------------
set axi_intc_cascaded_1_intr_1_interrupt_concat [create_bd_cell -type ip -vlnv xilinx.com:ip:xlconcat:2.1 axi_intc_cascaded_1_intr_1_interrupt_concat]
  
set_property -dict [ list  \
  CONFIG.NUM_PORTS {32}  ] $axi_intc_cascaded_1_intr_1_interrupt_concat

#---------------------------
# Instantiating irq_const_tieoff
#---------------------------
set irq_const_tieoff [create_bd_cell -type ip -vlnv xilinx.com:ip:xlconstant:1.1 irq_const_tieoff]
  
set_property -dict [ list  \
  CONFIG.CONST_WIDTH {1} \
  CONFIG.CONST_VAL {0}  ] $irq_const_tieoff

#---------------------------
# Enable NoC automation
#---------------------------

set v_enable_auto_connections_in_noc_state [get_param bd.enableAutoConnectionsInNoc]
set_param bd.enableAutoConnectionsInNoc 1


#---------------------------
# Connectivity Phase 1
#---------------------------
connect_bd_intf_net \
  [get_bd_intf_pins -auto_enable /icn_ctrl_1/M06_AXI] \
  [get_bd_intf_pins -auto_enable /mm2s_1/s_axi_control] \

connect_bd_intf_net \
  [get_bd_intf_pins -auto_enable /mm2s_1/m_axi_gmem] \
  [get_bd_intf_pins -auto_enable /noc_ddr4/S00_AXI] \

connect_bd_intf_net \
  [get_bd_intf_pins -auto_enable /icn_ctrl_1/M07_AXI] \
  [get_bd_intf_pins -auto_enable /mm2s_2/s_axi_control] \

connect_bd_intf_net \
  [get_bd_intf_pins -auto_enable /mm2s_2/m_axi_gmem] \
  [get_bd_intf_pins -auto_enable /noc_ddr4/S01_AXI] \

connect_bd_intf_net \
  [get_bd_intf_pins -auto_enable /icn_ctrl_1/M08_AXI] \
  [get_bd_intf_pins -auto_enable /s2mm/s_axi_control] \

connect_bd_intf_net \
  [get_bd_intf_pins -auto_enable /s2mm/m_axi_gmem] \
  [get_bd_intf_pins -auto_enable /noc_ddr4/S02_AXI] \

connect_bd_intf_net \
  [get_bd_intf_pins -auto_enable /ai_engine_0/M00_AXIS] \
  [get_bd_intf_pins -auto_enable /dwc_ai_engine_0_M00_AXIS/S_AXIS] \

connect_bd_intf_net \
  [get_bd_intf_pins -auto_enable /dwc_ai_engine_0_M00_AXIS/M_AXIS] \
  [get_bd_intf_pins -auto_enable /s2mm/s] \

connect_bd_intf_net \
  [get_bd_intf_pins -auto_enable /mm2s_1/s] \
  [get_bd_intf_pins -auto_enable /dwc_mm2s_1_s/S_AXIS] \

connect_bd_intf_net \
  [get_bd_intf_pins -auto_enable /dwc_mm2s_1_s/M_AXIS] \
  [get_bd_intf_pins -auto_enable /ai_engine_0/S00_AXIS] \

connect_bd_intf_net \
  [get_bd_intf_pins -auto_enable /mm2s_2/s] \
  [get_bd_intf_pins -auto_enable /dwc_mm2s_2_s/S_AXIS] \

connect_bd_intf_net \
  [get_bd_intf_pins -auto_enable /dwc_mm2s_2_s/M_AXIS] \
  [get_bd_intf_pins -auto_enable /ai_engine_0/S01_AXIS] \

connect_bd_net  \
  [get_bd_pins -auto_enable /clk_wizard_0/clk_out4_o1_o2] \
  [get_bd_pins -auto_enable /dwc_ai_engine_0_M00_AXIS/aclk] \
  [get_bd_pins -auto_enable /dwc_mm2s_1_s/aclk] \
  [get_bd_pins -auto_enable /dwc_mm2s_2_s/aclk] \
  [get_bd_pins -auto_enable /mm2s_1/ap_clk] \
  [get_bd_pins -auto_enable /mm2s_2/ap_clk] \
  [get_bd_pins -auto_enable /s2mm/ap_clk] \
  [get_bd_pins -auto_enable /icn_ctrl_1/aclk2] \
  [get_bd_pins -auto_enable /noc_ddr4/aclk0] \
  [get_bd_pins -auto_enable /ai_engine_0/aclk0] \

connect_bd_net  \
  [get_bd_pins -auto_enable /psr_312mhz/interconnect_aresetn] \
  [get_bd_pins -auto_enable /dwc_ai_engine_0_M00_AXIS/aresetn] \
  [get_bd_pins -auto_enable /dwc_mm2s_1_s/aresetn] \
  [get_bd_pins -auto_enable /dwc_mm2s_2_s/aresetn] \

connect_bd_net  \
  [get_bd_pins -auto_enable /psr_312mhz/peripheral_aresetn] \
  [get_bd_pins -auto_enable /mm2s_1/ap_rst_n] \
  [get_bd_pins -auto_enable /mm2s_2/ap_rst_n] \
  [get_bd_pins -auto_enable /s2mm/ap_rst_n] \
  [get_bd_pins -auto_enable /ai_engine_0/aresetn0] \

connect_bd_net  \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/dout] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1/intr] \

connect_bd_net  \
  [get_bd_pins -auto_enable /mm2s_1/interrupt] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In1] \

connect_bd_net  \
  [get_bd_pins -auto_enable /mm2s_2/interrupt] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In0] \

connect_bd_net  \
  [get_bd_pins -auto_enable /s2mm/interrupt] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In2] \

connect_bd_net  \
  [get_bd_pins -auto_enable /irq_const_tieoff/dout] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In3] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In4] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In5] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In6] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In7] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In8] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In9] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In10] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In11] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In12] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In13] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In14] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In15] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In16] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In17] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In18] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In19] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In20] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In21] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In22] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In23] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In24] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In25] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In26] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In27] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In28] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In29] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In30] \
  [get_bd_pins -auto_enable /axi_intc_cascaded_1_intr_1_interrupt_concat/In31] \
  [get_bd_pins -auto_enable /xlconcat_0/In0] \
  [get_bd_pins -auto_enable /xlconcat_0/In1] \
  [get_bd_pins -auto_enable /xlconcat_0/In2] \
  [get_bd_pins -auto_enable /xlconcat_0/In3] \
  [get_bd_pins -auto_enable /xlconcat_0/In4] \
  [get_bd_pins -auto_enable /xlconcat_0/In5] \
  [get_bd_pins -auto_enable /xlconcat_0/In6] \
  [get_bd_pins -auto_enable /xlconcat_0/In7] \
  [get_bd_pins -auto_enable /xlconcat_0/In8] \
  [get_bd_pins -auto_enable /xlconcat_0/In9] \
  [get_bd_pins -auto_enable /xlconcat_0/In10] \
  [get_bd_pins -auto_enable /xlconcat_0/In11] \
  [get_bd_pins -auto_enable /xlconcat_0/In12] \
  [get_bd_pins -auto_enable /xlconcat_0/In13] \
  [get_bd_pins -auto_enable /xlconcat_0/In14] \
  [get_bd_pins -auto_enable /xlconcat_0/In15] \
  [get_bd_pins -auto_enable /xlconcat_0/In16] \
  [get_bd_pins -auto_enable /xlconcat_0/In17] \
  [get_bd_pins -auto_enable /xlconcat_0/In18] \
  [get_bd_pins -auto_enable /xlconcat_0/In19] \
  [get_bd_pins -auto_enable /xlconcat_0/In20] \
  [get_bd_pins -auto_enable /xlconcat_0/In21] \
  [get_bd_pins -auto_enable /xlconcat_0/In22] \
  [get_bd_pins -auto_enable /xlconcat_0/In23] \
  [get_bd_pins -auto_enable /xlconcat_0/In24] \
  [get_bd_pins -auto_enable /xlconcat_0/In25] \
  [get_bd_pins -auto_enable /xlconcat_0/In26] \
  [get_bd_pins -auto_enable /xlconcat_0/In27] \
  [get_bd_pins -auto_enable /xlconcat_0/In28] \
  [get_bd_pins -auto_enable /xlconcat_0/In29] \
  [get_bd_pins -auto_enable /xlconcat_0/In30] \


#---------------------------
# Platform Interface Parameters for xilinx_vck190_base_202410_1
#---------------------------
set_property -dict [ list  \
  CONFIG.CONNECTIONS [dict create MC_1 [concat read_bw \{1192\} write_bw \{1192\} read_avg_burst \{8\} write_avg_burst \{8\}]] ] [ get_bd_intf_pins noc_ddr4/S00_AXI]

set_property -dict [ list  \
  CONFIG.CONNECTIONS [dict create MC_2 [concat read_bw \{1192\} write_bw \{1192\} read_avg_burst \{8\} write_avg_burst \{8\}]] ] [ get_bd_intf_pins noc_ddr4/S01_AXI]

set_property -dict [ list  \
  CONFIG.CONNECTIONS [dict create MC_3 [concat read_bw \{1192\} write_bw \{1192\} read_avg_burst \{8\} write_avg_burst \{8\}]] ] [ get_bd_intf_pins noc_ddr4/S02_AXI]


#---------------------------
# Disable NoC automation
#---------------------------

set_param bd.enableAutoConnectionsInNoc $v_enable_auto_connections_in_noc_state


#---------------------------
# Connectivity Phase 2
#---------------------------

#---------------------------
# Import AI Engine archive
#---------------------------


if {${uses_pr}} {
  set _reconfig_module_ [get_reconfig_modules -filter "MODULE_NAME == [current_bd_design]"]
  add_files -norecurse ${aie_archive} -of_objects ${_reconfig_module_}
  set _aie_file_local_ [get_files -all -of_objects ${_reconfig_module_} ${aie_archive}]
} else {
  add_files -norecurse ${aie_archive}
  set _aie_file_local_ [get_files -all -of_objects [get_fileset sources_1] ${aie_archive}]
}
set_property SCOPED_TO_REF [current_bd_design] ${_aie_file_local_}
set_property SCOPED_TO_CELLS { ai_engine_0 } ${_aie_file_local_}
set_property USED_IN_IMPLEMENTATION true ${_aie_file_local_}


#---------------------------
# Create Stream Map file
#---------------------------
set stream_subsystems [get_bd_cells * -hierarchical -quiet -filter {VLNV =~ "*:*:sdx_stream_subsystem:*"}]
if {[string length $stream_subsystems] > 0} {    
  set xmlFile $vpl_output_dir/qdma_stream_map.xml
  set fp [open ${xmlFile} w]
  puts $fp "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
  puts $fp "<xd:streamMap xmlns:xd=\"http://www.xilinx.com/xd\">"
  foreach streamSS [get_bd_cells * -hierarchical -quiet -filter {VLNV =~ "*:*:sdx_stream_subsystem:*"}] {
    set ssInstance [string trimleft $streamSS /]
    set ssRegion [get_property CONFIG.SLR_ASSIGNMENTS $streamSS]
    foreach ssIntf [get_bd_intf_pins $streamSS/* -quiet -filter {NAME=~"S??_AXIS"}] {
      set pinName [get_property NAME $ssIntf]
      set routeId [sdx_stream_subsystem::get_routeid $ssIntf]
      set flowId [sdx_stream_subsystem::get_flowid $ssIntf]
      puts $fp "  <xd:streamRoute xd:instanceRef=\"$ssInstance\" xd:portRef=\"$pinName\" xd:route=\"$routeId\" xd:flow=\"$flowId\" xd:region=\"$ssRegion\">"
      foreach connection [find_bd_objs -relation connected_to $ssIntf -thru_hier] {
        set connectedRegion [get_property CONFIG.SLR_ASSIGNMENTS [bd::utils::get_parent $connection]]
        set connectedPort [bd::utils::get_short_name $connection]
        set connectedInst [string trimleft [bd::utils::get_parent $connection] /]
        puts $fp "    <xd:connection xd:instanceRef=\"$connectedInst\" xd:portRef=\"$connectedPort\" xd:region=\"$connectedRegion\"/>"
      }
      puts $fp "  </xd:streamRoute>"
    }
    foreach ssIntf [get_bd_intf_pins $streamSS/* -quiet -filter {NAME=~"M??_AXIS"}] {
      set pinName [get_property NAME $ssIntf]
      set routeId [sdx_stream_subsystem::get_routeid $ssIntf]
      set flowId [sdx_stream_subsystem::get_flowid $ssIntf]
      puts $fp "  <xd:streamRoute xd:instanceRef=\"$ssInstance\" xd:portRef=\"$pinName\" xd:route=\"$routeId\" xd:flow=\"$flowId\" xd:region=\"$ssRegion\">"
      foreach connection [find_bd_objs -relation connected_to $ssIntf -thru_hier] {
        set connectedRegion [get_property CONFIG.SLR_ASSIGNMENTS [bd::utils::get_parent $connection]]
        set connectedPort [bd::utils::get_short_name $connection]
        set connectedInst [string trimleft [bd::utils::get_parent $connection] /]
        puts $fp "    <xd:connection xd:instanceRef=\"$connectedInst\" xd:portRef=\"$connectedPort\" xd:region=\"$connectedRegion\"/>"
      }
      puts $fp "  </xd:streamRoute>"
    }
  }
  puts $fp "</xd:streamMap>"
  close $fp
}


