source /tools/Xilinx/Vivado/2024.1/settings64.sh && source /opt/xilinx/xrt/setup.sh
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/xilinx/xrt/lib:/tools/Xilinx/Vitis/2024.1/aietools/lib/lnx64.o
#cd gemm_extended
make clean
make -p Work
#make sim mult_X=2 mult_Y=2 mult_Z=1 DEBUG_PRINTS=1 
#make run_sim mult_X=1 mult_Y=1 mult_Z=1 DEBUG_PRINTS=1 

#mv total.log total.log.last ; make clean; make run_sim mult_X=2 | tee total.log
mv total.log total.log.last ; make clean; make run_sim | tee total.log

#make analyze mult_X=2 mult_Y=2 mult_Z=1 DEBUG_PRINTS=1 
# vitis_analyzer ./Work/graph.aiecompile_summary
