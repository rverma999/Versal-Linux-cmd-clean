puts "Checking aie shim placement"
set _golden_bels_ [get_bels [list AIE_PL_X22Y0/AIE_PL_S_AXIS_4 AIE_PL_X22Y0/AIE_PL_S_AXIS_5 AIE_PL_X22Y0/AIE_PL_S_AXIS_0 AIE_PL_X22Y0/AIE_PL_S_AXIS_1 AIE_PL_X22Y0/AIE_PL_M_AXIS_0 AIE_PL_X22Y0/AIE_PL_M_AXIS_1]]
set _shim_valid_ 1
foreach x $_golden_bels_ {
  if {[get_property IS_USED $x] != 1} {
    puts "$x should be placed, but isn't"
    set _shim_valid_ 0
  }
}
if {$_shim_valid_ == 1} {
  puts "AIE shim valid"
} else {
  set _used_bels_ [get_bels -of_objects [get_sites -filter {SITE_TYPE==AIE_NOC || SITE_TYPE==AIE_PL || SITE_TYPE==AIE_ML_NOC || SITE_TYPE==AIE_ML_PL}] -filter {(TYPE==AIE_PL_S_AXIS || TYPE==AIE_PL_M_AXIS || TYPE==AIE_NOC_M_AXI || TYPE==AIE_ML_PL_S_AXIS || TYPE==AIE_ML_PL_M_AXIS || TYPE==AIE_ML_NOC_M_AXI) && IS_USED==1}]
  puts "AIE shim validation failed"
  puts "Searching for $_golden_bels_"
  puts "Found $_used_bels_"
  send_msg_id Aie_Shim_Validation-1 ERROR "AIE shim validation failed, check vivado.log for additional information"
}
