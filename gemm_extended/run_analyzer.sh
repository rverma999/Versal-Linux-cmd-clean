source /tools/Xilinx/Vivado/2024.1/settings64.sh && source /opt/xilinx/xrt/setup.sh
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/xilinx/xrt/lib:/tools/Xilinx/Vitis/2024.1/aietools/lib/lnx64.o
#cd gemm_extended
make clean
make analyze mult_X=4 mult_Y=2 mult_Z=2 DEBUG_PRINTS=1 
# vitis_analyzer ./Work/graph.aiecompile_summary
