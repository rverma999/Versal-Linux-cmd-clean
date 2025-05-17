# aclk {FREQ_HZ 104166666 CLK_DOMAIN /clk_wizard_0_clk_out1 PHASE 0.0} aclk1 {FREQ_HZ 104166666 CLK_DOMAIN /clk_wizard_0_clk_out1 PHASE 0.0} aclk2 {FREQ_HZ 312500000 CLK_DOMAIN /clk_wizard_0_clk_out1 PHASE 0.0}
# Clock Domain: /clk_wizard_0_clk_out1
create_clock -name aclk -period 9.600 [get_ports aclk]
# Generated clocks
create_generated_clock -name aclk1 -source [get_ports aclk] -divide_by 1 [get_ports aclk1]
create_generated_clock -name aclk2 -source [get_ports aclk] -multiply_by 156250000 -divide_by 52083333 [get_ports aclk2]
