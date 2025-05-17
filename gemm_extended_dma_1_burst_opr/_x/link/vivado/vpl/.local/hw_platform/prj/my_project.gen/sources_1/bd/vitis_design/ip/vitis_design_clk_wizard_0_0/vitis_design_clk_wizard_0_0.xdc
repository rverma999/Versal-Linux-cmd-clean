# file: vitis_design_clk_wizard_0_0.xdc

# Input clock periods. These duplicate the values entered for the
# input clocks. You can use these to time your system. If required
# commented constraints can be used in the top level xdc 
#----------------------------------------------------------------
#
#
set_property PHASESHIFT_MODE LATENCY [get_cells -hierarchical MMCME5*]
set_false_path -from [get_cells  -hier {*ce_dly_reg_reg*} -filter {is_sequential}]
