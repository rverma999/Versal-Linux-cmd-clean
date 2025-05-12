source /tools/Xilinx/Vivado/2024.1/settings64.sh && source /opt/xilinx/xrt/setup.sh
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/xilinx/xrt/lib:/tools/Xilinx/Vitis/2024.1/aietools/lib/lnx64.o
#cd gemm_extended
make clean
#make -p Work
#make sim mult_X=2 mult_Y=2 mult_Z=1 DEBUG_PRINTS=1 
#make analyze  mult_X=1 mult_Y=1 mult_Z=1 DEBUG_PRINTS=1
#make analyze all VERBOSE=1  mult_X=1 mult_Y=1 mult_Z=1 DEBUG_PRINTS=1

#This is running 2 sims ,  first withoug dma and then simualted dma
#make run_sim all VERBOSE=1  mult_X=1 mult_Y=1 mult_Z=1 DEBUG_PRINTS=1

make TARGET=hw_emu all VERBOSE=1 | tee total.log

#v++ -l -t hw_emu --platform /tools/Xilinx/Vitis/2024.1/base_platforms/xilinx_vck190_base_202410_1/xilinx_vck190_base_202410_1.xpfm pl_kernels/s2mm.xo pl_kernels/mm2s.xo libadf.a --save-temps -g --config system.cfg -o tutorial.xsa || (echo "task: [xsa] failed error code: $?"; exit 1) 
# vitis_analyzer ./Work/graph.aiecompile_summary
