vlib modelsim_lib/work
vlib modelsim_lib/msim

vlib modelsim_lib/msim/xilinx_vip
vlib modelsim_lib/msim/xpm
vlib modelsim_lib/msim/xil_defaultlib

vmap xilinx_vip modelsim_lib/msim/xilinx_vip
vmap xpm modelsim_lib/msim/xpm
vmap xil_defaultlib modelsim_lib/msim/xil_defaultlib

vlog -work xilinx_vip -64 -incr -mfcu  -sv -L cpm5_v1_0_16 -L cpm4_v1_0_16 -L axi_vip_v1_1_17 -L smartconnect_v1_0 -L ai_pl -L noc_nsu_sim_v1_0_0 -L noc_hbm_nmu_sim_v1_0_0 -L noc_nmu_sim_v1_0_0 -L versal_cips_ps_vip_v1_0_9 -L xilinx_vip "+incdir+/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/include" \
"/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
"/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
"/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
"/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
"/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
"/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
"/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/hdl/axi_vip_if.sv" \
"/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/hdl/clk_vip_if.sv" \
"/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/hdl/rst_vip_if.sv" \

vlog -work xpm -64 -incr -mfcu  -sv -L cpm5_v1_0_16 -L cpm4_v1_0_16 -L axi_vip_v1_1_17 -L smartconnect_v1_0 -L ai_pl -L noc_nsu_sim_v1_0_0 -L noc_hbm_nmu_sim_v1_0_0 -L noc_nmu_sim_v1_0_0 -L versal_cips_ps_vip_v1_0_9 -L xilinx_vip "+incdir+/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/include" \
"/tools/Xilinx/Vivado/2024.1/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
"/tools/Xilinx/Vivado/2024.1/data/ip/xpm/xpm_fifo/hdl/xpm_fifo.sv" \
"/tools/Xilinx/Vivado/2024.1/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \

vcom -work xpm -64 -93  \
"/tools/Xilinx/Vivado/2024.1/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work xil_defaultlib -64 -incr -mfcu  -sv -L cpm5_v1_0_16 -L cpm4_v1_0_16 -L axi_vip_v1_1_17 -L smartconnect_v1_0 -L ai_pl -L noc_nsu_sim_v1_0_0 -L noc_hbm_nmu_sim_v1_0_0 -L noc_nmu_sim_v1_0_0 -L versal_cips_ps_vip_v1_0_9 -L xilinx_vip "+incdir+/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/include" \
"../../../bd/xlnoc/ip/xlnoc_snoc_sysc_inst_0/sim/xlnoc_snoc_sysc_inst_0_stub.sv" \

vlog -work xil_defaultlib -64 -incr -mfcu  "+incdir+/tools/Xilinx/Vivado/2024.1/data/xilinx_vip/include" \
"../../../bd/xlnoc/sim/xlnoc.v" \

vlog -work xil_defaultlib \
"glbl.v"

