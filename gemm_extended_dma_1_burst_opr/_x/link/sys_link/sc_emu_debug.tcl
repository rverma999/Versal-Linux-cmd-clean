set trace_signals(kernel_group) {
  ai_engine_0 { \
    S00_AXIS*TDATA \
    S00_AXIS*TLAST \
    S00_AXIS*TVALID \
    S00_AXIS*TREADY \
    S01_AXIS*TDATA \
    S01_AXIS*TLAST \
    S01_AXIS*TVALID \
    S01_AXIS*TREADY \
    M00_AXIS*TDATA \
    M00_AXIS*TLAST \
    M00_AXIS*TVALID \
    M00_AXIS*TREADY \
  } {}

  mm2s_1 { \
    s_axi_control*ARADDR \
    s_axi_control*RDATA \
    s_axi_control*RVALID \
    s_axi_control*RREADY \
    s_axi_control*AWADDR \
    s_axi_control*WDATA \
    s_axi_control*WVALID \
    s_axi_control*WREADY \
    m_axi_gmem*ARADDR \
    m_axi_gmem*RDATA \
    m_axi_gmem*RVALID \
    m_axi_gmem*RREADY \
    m_axi_gmem*AWADDR \
    m_axi_gmem*WDATA \
    m_axi_gmem*WVALID \
    m_axi_gmem*WREADY \
    s*TDATA \
    s*TLAST \
    s*TVALID \
    s*TREADY \
  } {}

  mm2s_2 { \
    s_axi_control*ARADDR \
    s_axi_control*RDATA \
    s_axi_control*RVALID \
    s_axi_control*RREADY \
    s_axi_control*AWADDR \
    s_axi_control*WDATA \
    s_axi_control*WVALID \
    s_axi_control*WREADY \
    m_axi_gmem*ARADDR \
    m_axi_gmem*RDATA \
    m_axi_gmem*RVALID \
    m_axi_gmem*RREADY \
    m_axi_gmem*AWADDR \
    m_axi_gmem*WDATA \
    m_axi_gmem*WVALID \
    m_axi_gmem*WREADY \
    s*TDATA \
    s*TLAST \
    s*TVALID \
    s*TREADY \
  } {}

  s2mm { \
    s_axi_control*ARADDR \
    s_axi_control*RDATA \
    s_axi_control*RVALID \
    s_axi_control*RREADY \
    s_axi_control*AWADDR \
    s_axi_control*WDATA \
    s_axi_control*WVALID \
    s_axi_control*WREADY \
    m_axi_gmem*ARADDR \
    m_axi_gmem*RDATA \
    m_axi_gmem*RVALID \
    m_axi_gmem*RREADY \
    m_axi_gmem*AWADDR \
    m_axi_gmem*WDATA \
    m_axi_gmem*WVALID \
    m_axi_gmem*WREADY \
    s*TDATA \
    s*TLAST \
    s*TVALID \
    s*TREADY \
  } {}

}

set trace_signals(kernel) {
  ap_start ap_ready ap_done
}

set trace_signals(adapter) {
  *axis_*tdata *axis_*tvalid *axis_*tready S*WADDR S*WDATA S*ARADDR S*RDATA
}

set trace_signals(datamover) {
  stream_t* reg_bus_awaddr reg_bus_wdata
}
