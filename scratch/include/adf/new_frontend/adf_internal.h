// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// The contents of this file are for internal use ONLY.

#pragma once

#include <vector>
#include "adf_api_dynlink.h"

namespace adf {
  inline access_pattern buffer_descriptor(const buffer_descriptor_parameters& bdParams) { return access_pattern(bdParams); }

  constraint<int> task_repetition(adf::port<adf::input>& p);
  constraint<int> task_repetition(adf::port<adf::output>& p);

  template <typename _XILINX_ADF_T = adf::finish_on_tlast_mode>
    constraint<_XILINX_ADF_T> finish_on_tlast(adf::input_port& p);

  void disable_out_of_order_mode(adf::port<adf::input>& p);

  /// Execution Order Constraint
  ADF_API_EXPORT void execution_order(adf::kernel& predecessor, adf::kernel& successor);
  ADF_API_EXPORT void execution_order(adf::shared_buffer_base& sb1, adf::shared_buffer_base& sb2);
  ADF_API_EXPORT void execution_order(adf::external_buffer_base& eb, adf::shared_buffer_base& sb);
  ADF_API_EXPORT void execution_order(adf::shared_buffer_base& sb, adf::external_buffer_base& eb);
  ADF_API_EXPORT void execution_order(const std::vector<adf::input_port*>& ports1, const std::vector<adf::input_port*>& ports2);

  /// Register sub-graphs as independent control graphs for multi-layer flow
  void dedicated_controller(const adf::graph& gr);

  /// function to specify fragment buffer location
  location_constraint fragment_address(const std::vector<adf::dimension_range>& fragment, int column, int row, int offset);

  class microcontroller {
  public:
    adf::vector<adf::port<adf::input>> in; //using vector to be consistent with pktcontrol and other pkt nodes, also future proof. Even though uC currently has only 1-in 1-out.
    adf::vector<adf::port<adf::output>> out;
  
    microcontroller() { api_impl::createMicroController(impl); }
  
    //numInput and numOutput can only be 0 or 1. Use int instead of bool to be future proof. Open to change it to bool if arch team can confirm it will always be 1-in 1-out.
    static adf::microcontroller create(int numInput, int numOutput) {
      adf::microcontroller x;
      api_impl::createMicroController(x.impl, x.in, x.out, numInput, numOutput);
      return x;
    }
  
    microcontroller& operator=(const microcontroller& from) { api_impl::assignmentMicroController(impl, in, out, from.impl, from.in, from.out); return *this; }
    std::shared_ptr<MicroControllerImpl> impl;
  };

  /* microcontroller node location constraint */
  template<typename _XILINX_ADF_T=adf::microcontroller>
   ADF_API_EXPORT location_constraint location (adf::microcontroller &k);

}
