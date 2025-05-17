transcript off
onbreak {quit -force}
onerror {quit -force}
transcript on

vlib work
vlib riviera/xilinx_vip
vlib riviera/xpm
vlib riviera/xil_defaultlib

vmap xilinx_vip riviera/xilinx_vip
vmap xpm riviera/xpm
vmap xil_defaultlib riviera/xil_defaultlib

vlog -work xilinx_vip  -incr -l cpm5_v1_0_16 -l cpm4_v1_0_16 -l axi_vip_v1_1_17 -l smartconnect_v1_0 -l ai_pl -l noc_nsu_sim_v1_0_0 -l noc_hbm_nmu_sim_v1_0_0 -l noc_nmu_sim_v1_0_0 -l versal_cips_ps_vip_v1_0_9 "+incdir+/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/include" -l xilinx_vip -l xpm -l xil_defaultlib \
"/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
"/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
"/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
"/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
"/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
"/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
"/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/hdl/axi_vip_if.sv" \
"/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/hdl/clk_vip_if.sv" \
"/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/hdl/rst_vip_if.sv" \

vlog -work xpm  -incr -l cpm5_v1_0_16 -l cpm4_v1_0_16 -l axi_vip_v1_1_17 -l smartconnect_v1_0 -l ai_pl -l noc_nsu_sim_v1_0_0 -l noc_hbm_nmu_sim_v1_0_0 -l noc_nmu_sim_v1_0_0 -l versal_cips_ps_vip_v1_0_9 "+incdir+/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/include" -l xilinx_vip -l xpm -l xil_defaultlib \
"/tools/Xilinx/Vivado/2024.1/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
"/tools/Xilinx/Vivado/2024.1/data/ip/xpm/xpm_fifo/hdl/xpm_fifo.sv" \
"/tools/Xilinx/Vivado/2024.1/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \

vcom -work xpm -93  -incr \
"/tools/Xilinx/Vivado/2024.1/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work xil_defaultlib  -incr -l cpm5_v1_0_16 -l cpm4_v1_0_16 -l axi_vip_v1_1_17 -l smartconnect_v1_0 -l ai_pl -l noc_nsu_sim_v1_0_0 -l noc_hbm_nmu_sim_v1_0_0 -l noc_nmu_sim_v1_0_0 -l versal_cips_ps_vip_v1_0_9 "+incdir+/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/include" -l xilinx_vip -l xpm -l xil_defaultlib \
"../../../bd/xlnoc/ip/xlnoc_snoc_sysc_inst_0/sim/xlnoc_snoc_sysc_inst_0_stub.sv" \

vlog -work xil_defaultlib  -incr -v2k5 "+incdir+/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/include" -l xilinx_vip -l xpm -l xil_defaultlib \
"../../../bd/xlnoc/sim/xlnoc.v" \

ccomp -sc -visibility -std=c++11 -DSC_INCLUDE_DYNAMIC_PROCESSES -DRIVIERA -o lib_prj  -L "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/noc_sc_v1_0_0" -lnoc_sc_v1_0_0 -L "/tools/Xilinx/Vivado/2024.1/data/simmodels/xsim/2024.1/lnx64/9.3.0/ext/protobuf" -lprotobuf -L "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/sim_qdma_cpp_v1_0" -lsim_qdma_cpp_v1_0 -L "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/axi_tlm_ext_v1_0" -laxi_tlm_ext_v1_0 -L "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/remote_port_c_v4" -lremote_port_c_v4 -L "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/xtlm_ipc_v1_0" -lxtlm_ipc_v1_0 -L "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/sim_qdma_sc_v1_0" -lsim_qdma_sc_v1_0 -L "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/xtlm_ap_ctrl_v1_0" -lxtlm_ap_ctrl_v1_0 -L "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/xtlm_simple_interconnect_v1_0" -lxtlm_simple_interconnect_v1_0 -L "/tools/Xilinx/Vivado/2024.1/data/simmodels/xcelium/23.09.001/lnx64/9.3.0/ext/utils/protobuf" -lprotobuf -L "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/common_cpp_v1_0" -lcommon_cpp_v1_0 -L "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/debug_tcp_server_v1" -ldebug_tcp_server_v1 -L "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/common_rpc_v1" -lcommon_rpc_v1 -L "/tools/Xilinx/Vivado/2024.1/data/simmodels/xsim/2024.1/lnx64/9.3.0/systemc/protected/noc_v1_0_0" -lnoc_v1_0_0 -L "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/xtlm" -lxtlm -L "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/aie_ps_v1_0" -laie_ps_v1_0 -L "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/remote_port_sc_v4" -lremote_port_sc_v4 -L "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/pl_fileio_v1_0_0" -lpl_fileio_v1_0_0 -L "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/aie_xtlm_v1_0_0" -laie_xtlm_v1_0_0 -L "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/rwd_tlmmodel_v1" -lrwd_tlmmodel_v1 -L "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/emu_perf_common_v1_0" -lemu_perf_common_v1_0 -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_CIPS_0_0/sim_tlm" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_CIPS_0_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_0/sysc" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_1/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_2/sysc" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_2/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_3/sysc" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_3/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_4/sysc" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_4/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_5/sysc" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_5/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_6/sysc" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_6/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_7/sysc" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_7/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_8/sysc" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_8/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_9/sysc" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_9/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/bd_0/ip/ip_0/sysc" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/bd_0/ip/ip_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/bd_0/ip/ip_1/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/bd_0/ip/ip_2/sysc" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/bd_0/ip/ip_2/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/bd_0/ip/ip_3/sysc" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/bd_0/ip/ip_3/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/bd_0/ip/ip_4/sysc" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/bd_0/ip/ip_4/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/bd_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_lpddr4_0/bd_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_lpddr4_0/bd_0/ip/ip_0/sysc" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_lpddr4_0/bd_0/ip/ip_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_lpddr4_0/bd_0/ip/ip_1/sysc" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_lpddr4_0/bd_0/ip/ip_1/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_lpddr4_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_ai_engine_0_0/sim_tlm" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_ai_engine_0_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_xlconcat_0_0/sysc" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_xlconcat_0_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_icn_ctrl_1_0/xtlm" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_icn_ctrl_1_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_icn_ctrl_2_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dummy_slave_0_0/sysc" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dummy_slave_0_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dummy_slave_1_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dummy_slave_2_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dummy_slave_3_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_icn_ctrl_3_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_icn_ctrl_4_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_icn_ctrl_5_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_xlconstant_0_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_axi_intc_cascaded_1_intr_1_interrupt_concat_0/sysc" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_axi_intc_cascaded_1_intr_1_interrupt_concat_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_irq_const_tieoff_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_ctrl_interconnect_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_hub_0/src" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_hub_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon0_0/src" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon0_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon1_0/src" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon1_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon2_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon3_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon4_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon5_0/sim" -I "../../../../prj.gen/sources_1/bd/vitis_design/sim" -I "/tools/Xilinx/Vivado/2024.1/tps/boost_1_72_0" -I "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/noc_sc_v1_0_0/include" -I "/tools/Xilinx/Vivado/2024.1/data/simmodels/xsim/2024.1/lnx64/9.3.0/ext/protobuf/include" -I "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/sim_qdma_cpp_v1_0/include" -I "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/axi_tlm_ext_v1_0/include" -I "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/remote_port_c_v4/include" -I "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/xtlm_ipc_v1_0/include" -I "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/sim_qdma_sc_v1_0/include" -I "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/xtlm_ap_ctrl_v1_0/include" -I "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/xtlm_simple_interconnect_v1_0/include" -I "/tools/Xilinx/Vivado/2024.1/data/simmodels/xcelium/23.09.001/lnx64/9.3.0/ext/utils/protobuf/include" -I "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/common_cpp_v1_0/include" -I "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/debug_tcp_server_v1/include" -I "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/common_rpc_v1/include" -I "/tools/Xilinx/Vivado/2024.1/data/simmodels/xsim/2024.1/lnx64/9.3.0/systemc/protected/noc_v1_0_0/include" -I "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/xtlm/include" -I "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/aie_ps_v1_0/include" -I "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/remote_port_sc_v4/include" -I "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/pl_fileio_v1_0_0/include" -I "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/aie_xtlm_v1_0_0/include" -I "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/rwd_tlmmodel_v1/include" -I "/tools/Xilinx/Vivado/2024.1/data/xsim/ip/emu_perf_common_v1_0/include" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_CIPS_0_0/sim_tlm/versal_cips_v3_4_2_tlm.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_CIPS_0_0/sim_tlm/xilinx_versal_vitis.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_CIPS_0_0/sim/vitis_design_CIPS_0_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_CIPS_0_0/sim/vitis_design_CIPS_0_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/sim/bd_27ec_sci.cxx" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/sim/bd_27ec.cxx" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_0/sim/bd_27ec_S07_AXI_nmu_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_0/sim/bd_27ec_S07_AXI_nmu_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_1/sim/bd_27ec_const_0_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_2/sim/bd_27ec_S04_AXI_nmu_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_2/sim/bd_27ec_S04_AXI_nmu_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_3/sim/bd_27ec_S03_AXI_nmu_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_3/sim/bd_27ec_S03_AXI_nmu_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_4/sim/bd_27ec_S06_AXI_rpu_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_4/sim/bd_27ec_S06_AXI_rpu_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_5/sim/bd_27ec_S02_AXI_nmu_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_5/sim/bd_27ec_S02_AXI_nmu_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_6/sim/bd_27ec_S05_AXI_nmu_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_6/sim/bd_27ec_S05_AXI_nmu_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_7/sim/bd_27ec_S01_AXI_nmu_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_7/sim/bd_27ec_S01_AXI_nmu_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_8/sim/bd_27ec_S00_AXI_nmu_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_8/sim/bd_27ec_S00_AXI_nmu_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_9/sim/bd_27ec_M00_AXI_nsu_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/bd_0/ip/ip_9/sim/bd_27ec_M00_AXI_nsu_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/sim/vitis_design_cips_noc_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_cips_noc_0/sim/vitis_design_cips_noc_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/bd_0/ip/ip_0/sim/bd_90d1_S02_AXI_nmu_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/bd_0/ip/ip_0/sim/bd_90d1_S02_AXI_nmu_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/bd_0/ip/ip_1/sim/bd_90d1_const_0_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/bd_0/ip/ip_2/sim/bd_90d1_S01_AXI_nmu_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/bd_0/ip/ip_2/sim/bd_90d1_S01_AXI_nmu_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/bd_0/ip/ip_3/sim/bd_90d1_S00_AXI_nmu_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/bd_0/ip/ip_3/sim/bd_90d1_S00_AXI_nmu_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/bd_0/ip/ip_4/sim/bd_90d1_MC0_ddrc_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/bd_0/ip/ip_4/sim/bd_90d1_MC0_ddrc_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/bd_0/sim/bd_90d1_sci.cxx" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/bd_0/sim/bd_90d1.cxx" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/sim/vitis_design_noc_ddr4_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_ddr4_0/sim/vitis_design_noc_ddr4_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_lpddr4_0/bd_0/sim/bd_28ba_sci.cxx" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_lpddr4_0/bd_0/sim/bd_28ba.cxx" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_lpddr4_0/bd_0/ip/ip_0/sim/bd_28ba_MC1_ddrc_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_lpddr4_0/bd_0/ip/ip_0/sim/bd_28ba_MC1_ddrc_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_lpddr4_0/bd_0/ip/ip_1/sim/bd_28ba_MC0_ddrc_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_lpddr4_0/bd_0/ip/ip_1/sim/bd_28ba_MC0_ddrc_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_lpddr4_0/sim/vitis_design_noc_lpddr4_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_noc_lpddr4_0/sim/vitis_design_noc_lpddr4_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_ai_engine_0_0/sim_tlm/ai_engine.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_ai_engine_0_0/sim/vitis_design_ai_engine_0_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_ai_engine_0_0/sim/vitis_design_ai_engine_0_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_xlconcat_0_0/sim/vitis_design_xlconcat_0_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_xlconcat_0_0/sim/vitis_design_xlconcat_0_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_icn_ctrl_1_0/xtlm/smartconnect.cxx" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_icn_ctrl_1_0/xtlm/smartconnect_xtlm.cxx" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_icn_ctrl_1_0/xtlm/smartconnect_xtlm_impl.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_icn_ctrl_1_0/sim/vitis_design_icn_ctrl_1_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_icn_ctrl_1_0/sim/vitis_design_icn_ctrl_1_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_icn_ctrl_2_0/sim/vitis_design_icn_ctrl_2_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_icn_ctrl_2_0/sim/vitis_design_icn_ctrl_2_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dummy_slave_0_0/sysc/axi_vip.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dummy_slave_0_0/sysc/sim_ipc_aximm_master.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dummy_slave_0_0/sysc/sim_ipc_aximm_slave.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dummy_slave_0_0/sim/vitis_design_dummy_slave_0_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dummy_slave_0_0/sim/vitis_design_dummy_slave_0_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dummy_slave_1_0/sim/vitis_design_dummy_slave_1_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dummy_slave_1_0/sim/vitis_design_dummy_slave_1_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dummy_slave_2_0/sim/vitis_design_dummy_slave_2_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dummy_slave_2_0/sim/vitis_design_dummy_slave_2_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dummy_slave_3_0/sim/vitis_design_dummy_slave_3_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dummy_slave_3_0/sim/vitis_design_dummy_slave_3_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_icn_ctrl_3_0/sim/vitis_design_icn_ctrl_3_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_icn_ctrl_3_0/sim/vitis_design_icn_ctrl_3_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_icn_ctrl_4_0/sim/vitis_design_icn_ctrl_4_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_icn_ctrl_4_0/sim/vitis_design_icn_ctrl_4_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_icn_ctrl_5_0/sim/vitis_design_icn_ctrl_5_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_icn_ctrl_5_0/sim/vitis_design_icn_ctrl_5_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_xlconstant_0_0/sim/vitis_design_xlconstant_0_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_axi_intc_cascaded_1_intr_1_interrupt_concat_0/sim/vitis_design_axi_intc_cascaded_1_intr_1_interrupt_concat_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_axi_intc_cascaded_1_intr_1_interrupt_concat_0/sim/vitis_design_axi_intc_cascaded_1_intr_1_interrupt_concat_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_irq_const_tieoff_0/sim/vitis_design_irq_const_tieoff_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_ctrl_interconnect_0/sim/vitis_design_dpa_ctrl_interconnect_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_ctrl_interconnect_0/sim/vitis_design_dpa_ctrl_interconnect_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_hub_0/src/emulation_profiler_core.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_hub_0/sim/vitis_design_dpa_hub_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_hub_0/sim/vitis_design_dpa_hub_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon0_0/src/sim_aximm_perf_mon_v1_0_axilite.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon0_0/src/sim_aximm_perf_mon_v1_0_rd.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon0_0/src/sim_aximm_perf_mon_v1_0_wr.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon0_0/sim/vitis_design_dpa_mon0_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon0_0/sim/vitis_design_dpa_mon0_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon1_0/src/sim_axis_perf_mon_v1_rdwr.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon1_0/src/sim_axis_perf_mon_v1_axilite.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon1_0/sim/vitis_design_dpa_mon1_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon1_0/sim/vitis_design_dpa_mon1_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon2_0/sim/vitis_design_dpa_mon2_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon2_0/sim/vitis_design_dpa_mon2_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon3_0/sim/vitis_design_dpa_mon3_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon3_0/sim/vitis_design_dpa_mon3_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon4_0/sim/vitis_design_dpa_mon4_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon4_0/sim/vitis_design_dpa_mon4_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon5_0/sim/vitis_design_dpa_mon5_0_sc.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/ip/vitis_design_dpa_mon5_0/sim/vitis_design_dpa_mon5_0.cpp" \
"../../../../prj.gen/sources_1/bd/vitis_design/sim/vitis_design_sci.cxx" \

addsc -work xil_defaultlib lib_prj

vlog -work xil_defaultlib \
"glbl.v"

