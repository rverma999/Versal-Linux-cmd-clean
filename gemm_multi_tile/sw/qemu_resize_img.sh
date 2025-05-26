#!/bin/bash
echo "sourcing qemu env script."
source /tools/Xilinx/Vitis/2024.1/data/emulation/qemu/comp/qemu/environment-setup-x86_64-petalinux-linux
unset LD_LIBRARY_PATH
echo "qemu settings done."
/tools/Xilinx/Vitis/2024.1/data/emulation/qemu/comp/qemu/sysroots/x86_64-petalinux-linux/usr/bin/qemu-img resize -f raw /home/wes_2025_r_verma/capstone_project/Versal-Linux-cmd-clean_0507/gemm_extended_dma_1_burst_opr/sw/sd_card.img 4294967296
