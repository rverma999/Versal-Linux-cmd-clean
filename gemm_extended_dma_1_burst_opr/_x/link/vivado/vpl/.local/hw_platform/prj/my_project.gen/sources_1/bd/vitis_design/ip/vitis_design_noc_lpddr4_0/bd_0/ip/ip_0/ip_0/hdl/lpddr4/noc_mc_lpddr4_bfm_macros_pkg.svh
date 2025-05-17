`ifndef __NOC_MC_LPDDR4_V1_0_LPDDR4_BFM_MACROS_PKG_SVH__
`define __NOC_MC_LPDDR4_V1_0_LPDDR4_BFM_MACROS_PKG_SVH__

package noc_mc_lpddr4_v1_0_lpddr4_bfm_macros_pkg;


`define lp4_bfm_info(TAG, VERBOSITY_ENABLE, VERBOSITY_LEVEL, MSG, MSG_LEVEL) \
  if(VERBOSITY_ENABLE) begin \
    if(MSG_LEVEL <= VERBOSITY_LEVEL) begin \
      $display("INFO: [%s] (%m) %0t : %s", TAG, $time, MSG); \
    end \
  end

`define lp4_bfm_warning(TAG, VERBOSITY_DISABLE_WARNING, MSG) \
  if(!VERBOSITY_DISABLE_WARNING) begin \
    $warning("[%s] (%m) %0t : WARNING: %s", TAG, $time, MSG); \
  end

`define lp4_bfm_error(TAG, VERBOSITY_ERR_TO_WARN, VERBOSITY_DISABLE_WARNING, MSG) \
  if(VERBOSITY_ERR_TO_WARN) begin \
    `lp4_bfm_warning(TAG, VERBOSITY_DISABLE_WARNING, MSG) \
  end \
  else begin \
    $error("[%s] (%m) %0t : ERROR: %s", TAG, $time, MSG); \
  end

`define lp4_bfm_fatal(TAG, VERBOSITY_FATAL_TO_WARN, VERBOSITY_DISABLE_WARNING, MSG) \
  if(VERBOSITY_FATAL_TO_WARN) begin \
    `lp4_bfm_warning(TAG, VERBOSITY_DISABLE_WARNING, MSG) \
  end \
  else begin \
    $fatal(1,"[%s] (%m) %0t : ERROR: %s", TAG, $time, MSG); \
  end



`define lpddr4_info(MSG, LEVEL) \
  `lp4_bfm_info(TAG, verbosity_en, verbosity_level, $sformatf(MSG), LEVEL)

`define lpddr4_warning(MSG) \
  `lp4_bfm_warning(TAG, ignore_warning, MSG)

`define lpddr4_error(MSG) \
  `lp4_bfm_error(TAG, verbosity_err_to_warn, ignore_warning, MSG)

`define lpddr4_fatal(MSG) \
  `lp4_bfm_fatal(TAG, verbosity_fatal_to_warn, ignore_warning, MSG)

endpackage
  

`endif 
