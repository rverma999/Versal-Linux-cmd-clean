source /tools/Xilinx/Vivado/2024.1/settings64.sh && source /opt/xilinx/xrt/setup.sh
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/xilinx/xrt/lib:/tools/Xilinx/Vitis/2024.1/aietools/lib/lnx64.o

#source /tools/Xilinx/Vivado/2024.1/settings64.sh 

source /home/wes_2025_r_verma/capstone_project/xilinx-versal-common-v2024.1/environment-setup-cortexa72-cortexa53-xilinx-linux 



#cd gemm_extended
make clean
#make -p Work
#make sim mult_X=2 mult_Y=2 mult_Z=1 DEBUG_PRINTS=1 
#make analyze  mult_X=1 mult_Y=1 mult_Z=1 DEBUG_PRINTS=1
#make analyze all VERBOSE=1  mult_X=1 mult_Y=1 mult_Z=1 DEBUG_PRINTS=1

#This is running 2 sims ,  first withoug dma and then simualted dma
#make run_sim all VERBOSE=1  mult_X=1 mult_Y=1 mult_Z=1 DEBUG_PRINTS=1

mv total.log total.log.last ;make clean ;  make TARGET=hw_emu golden kernels aie sim VERBOSE=1 | tee total.log
#mv total.log total.log.last ;make clean ;  make TARGET=hw_emu all VERBOSE=1 | tee total.log


# if there is an port issue try doing folowing :
#after all steps till package are done. 
#make run_emu TARGET=hw_emu


#mv total.log total.log.last ;make clean ;  make TARGET=hw_emu run VERBOSE=1 | tee total.log

# Linking
#v++ -l -t hw_emu --platform /tools/Xilinx/Vitis/2024.1/base_platforms/xilinx_vck190_base_202410_1/xilinx_vck190_base_202410_1.xpfm pl_kernels/s2mm.xo pl_kernels/mm2s.xo libadf.a --save-temps -g --config system.cfg -o tutorial.xsa || (echo "task: [xsa] failed error code: $?"; exit 1) 

# PAckage and hw_emu : 
# make host package run_emu TARGET=hw_emu

#in hw_emu see system diagram
# vitis_analyzer ./v++.package_summary
i
#for hw_emu vitis
#vitis_analyzer aiesimulator_output/default.aierun_summary &

# To view Summary 
# vitis_analyzer ./Work/graph.aiecompile_summary

#Debug
#mkdir -p ./traces
#aiesimulator --profile --dump-vcd=tutorial --pkg-dir=./Work

#--online option
# aiesimulator --profile --pkg-dir=./Work --output-dir=./traces --online --output-time-stamp=ns 
