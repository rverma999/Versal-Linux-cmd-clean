onbreak {quit -f}
onerror {quit -f}

vsim  -lib xil_defaultlib xlnoc_opt

set NumericStdNoWarnings 1
set StdArithNoWarnings 1

if { [file exists vitis_params.tcl] } {
  source vitis_params.tcl
}

if { [info exists ::env(USER_PRE_SIM_SCRIPT)] } {
  if { [catch {source $::env(USER_PRE_SIM_SCRIPT)} msg] } {
    puts $msg
  }
}

do {wave.do}

view wave
view structure
view signals

do {xlnoc.udo}

puts "We are running simulator for infinite time. Added some default signals in the waveform. You can pause simulation and add signals and then resume the simulation again."
puts ""
puts "Stopping at breakpoint in simulator also stops the host code execution"
puts ""
if { [info exists ::env(VITIS_LAUNCH_WAVEFORM_GUI) ] } {
  run 1ns
} else {
  run 1000ns
}

if { [info exists ::env(VITIS_LAUNCH_WAVEFORM_BATCH) ] } {
  if { [info exists ::env(USER_POST_SIM_SCRIPT) ] } {
    if { [catch {source $::env(USER_POST_SIM_SCRIPT)} msg] } {
      puts $msg
    }
  }
  quit -force
}
