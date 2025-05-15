// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689

#ifndef _BASIC_TYPES_H 
#define _BASIC_TYPES_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <string>

#ifndef __X86SIM_LIB__
#include "adf/window/types.h"
#include "adf/stream/types.h"
#endif
#include "adf/io_buffer/io_buffer_types.h"
#include "adf/stream/hls_types.h"

#define chess_storage(...) 
template <typename _XILINX_ADF_T, bool input> struct window_type {
  typedef _XILINX_ADF_T type;
};

template <typename _XILINX_ADF_T, bool input> struct stream_type {
  typedef _XILINX_ADF_T type;
};

template </* typename _XILINX_ADF_T, */bool input> struct cascade_type {
  //typedef _XILINX_ADF_T type;
};


namespace adf {

  enum return_code
    {
      ok = 0,
      user_error,
      aie_driver_error,
      xrt_error,
      internal_error,
      unsupported
    };

  enum io_attr_type {
    io_attr_fileio,
    io_attr_plio,
    io_attr_gmio,
  };

  enum plio_type {
    plio_32_bits,
    plio_64_bits,
    plio_128_bits
  };
  
  enum stream_type
  {
    adf = 1,
    hls = 2,
    none = -1
  };
  
  enum ss_channel_dir {
      ss_south = 1,
      ss_west = 2,
      ss_north = 3,
      ss_east = 4
  };

  enum tile_type {
      undefined_tile = -1,
      aie_tile,
      shim_tile,
      memory_tile
  };

  enum dma_channel_dir
  {
      dma_s2mm = 0,
      dma_mm2s
  };

  enum port_direction {
      dir_in = 0,
      dir_out = 1,
      dir_inout = 2
  };

  enum param_type {
    p_voidty, 
    p_int4, 
    p_int8, 
    p_int16, 
    p_int32, 
    p_uint4,
    p_uint8,
    p_uint16, 
    p_uint32, 
    p_cint8, 
    p_cint16, 
    p_cint32,
    p_cint64,
    p_int64,
    p_uint64,
    p_v2int64,
    p_anyScalar,
    p_window, 
    p_stream, 
    p_cascade,
    p_pktstream,
    p_pointer,
    p_array,
    p_cacc48,
    p_cacc80,
    p_caccfloat,
    p_acc48,
    p_acc80,
    p_accfloat,
    p_float,
    p_cfloat,
    p_ap_int,
    p_ap_uint,
    p_ap_axis,
    p_ap_axiu,
    p_hls_stream,
    p_acc32,
    p_cacc32,
    p_acc64,
    p_cacc64,
    p_bfloat16,
    p_float16,
    p_bfloat8,
    p_float8,
    p_buffer
  };

  enum port_type {
    port_stream = 5,
    port_memory = 6,
    port_runtime_param = 7,
    port_lookup_table = 8,
    port_cascade = 9,
    port_pktstream = 10,
    port_global_memory = 11,
    port_dma = 12,
    port_buffer = 13,
    port_blank = -1
  };

  enum element_type
  {
    et_voidty = 0,
    et_int4,
    et_int8,
    et_int16,
    et_int32,
    et_int64,
    et_uint4,
    et_uint8,
    et_uint16,
    et_uint32,
    et_uint64,
    et_cint16,
    et_cint32,
    et_float,
    et_cfloat,
    et_double,
    et_bfloat16,
    et_float16,
    et_bfloat8,
    et_float8,
    et_bool
  };

  enum DMA_MODE {
    simple_mode,
    A_B_1,
    A_B_2
  };
  
  enum locking_mode
  {
    lm_none = 0,
    lm_auto = 1,
    lm_user = 2,
  };

  enum finish_on_tlast_mode
  {
    FoT_disabled = 0,
    FoT_no_counts,
    FoT_counts_with_task_tokens,
    FoT_counts_from_mm_register
  };

  enum class enable_pkt_mode {
    automatic,
    disable
  };
 
  template <int _XILINX_ADF_SIZE, int _XILINX_ADF_MARGIN = 0>
  struct window {
    enum { winsz = _XILINX_ADF_SIZE, margin = _XILINX_ADF_MARGIN, porttype = port_type::port_memory } ; 
  };

  struct stream {
    enum { winsz = -1, margin = 0, porttype = port_type::port_stream } ; 
  };

  struct pktstream {
    enum { winsz = -1, margin = 0, porttype = port_type::port_pktstream } ;
  };

  /*struct constant {
    enum { winsz = -1, margin = 0 };
  };*/

  struct cascade {
    enum { winsz = -1, margin = 0, porttype = port_type::port_cascade };
  };
  
  struct blank {
    enum { winsz = -1, margin = 0, porttype = port_type::port_blank };
  };

  struct gmem {
    enum { winsz = -1, margin = 0, porttype = port_type::port_global_memory };
  };

  namespace direction {
    struct in { static const adf::port_direction dir = adf::port_direction::dir_in; };
    struct out { static const adf::port_direction dir = adf::port_direction::dir_out; };
    struct inout { static const adf::port_direction dir = adf::port_direction::dir_inout; };
  };
  using input = direction::in;
  using output = direction::out;
  using inout = direction::inout;

  struct ratio;

  /* buffer location constraint: template identifiers */
  struct buffer;
  struct stack;
  struct dma;
  struct interconnect;

  /* FIFO location constraint template identifier */
  struct fifo;

  /* Area group location constraint types */
  struct group
  {
      adf::tile_type tileType = adf::tile_type::undefined_tile;
      int column_min = -1;
      int row_min = -1;
      int column_max = -1;
      int row_max = -1;
  };

  struct area_group_parameters
  {
      std::vector<group> groups;
      bool contain_routing = false;
      bool exclusive_routing = false;
      bool exclusive_placement = false;
  };

  struct buffer_descriptor_parameters
  {
      /// Transaction length in 32bit word
      uint32_t length = 0;
      /// Offset in 32bit word w.r.t. buffer starting address
      uint32_t offset = 0;
      /// D0, D1, D2, D3(memory tile only) stepsize in 32-bit word
      std::vector<uint32_t> stepsize;
      /// D0, D1, D2(memory tile only)
      std::vector<uint32_t> wrap;
      /// D0, D1, D2 zero-before and zero-after in 32-bit word. MM2S only.
      std::vector<std::pair<uint32_t, uint32_t>> padding;
      /// Output port id of the connected pktsplit or the input port id of the connected pktmerge
      int packet_port_id = -1;
      /// Enable adding packet header at start of transfer. MM2S only. enable_pkt_mode::automatic enables packet when there is a connected pktsplit.
      enable_pkt_mode enable_packet = enable_pkt_mode::automatic;
      /// TLAST suppress. Memory tile only. MM2S only.
      bool tlast_suppress = false;
      /// Iteration stepsize in 32-bit word
      uint32_t iteration_stepsize = 0;
      /// Iteration wrap
      uint32_t iteration_wrap = 0;
      /// Iteration current
      uint32_t iteration_current = 0;
      /// Enable compression for MM2S or enable decompression for S2MM. AIE tile and memory tile only.
      bool enable_compression = false;
  };

  /// Traversing parameters.
  struct traversing_parameters
  {
      /// The dimension of the inter-tile traversing loop.
      uint32_t dimension = 0;
      /// stride represents the distance in terms of buffer element type between consecutive inter-tile traversal in the dimension
      uint32_t stride = 0;
      /// wrap represents the number of steps before wrapping the current traversing loop and incrementing to the next traversing loop.
      /// The traversal stops when the last wrap completes.
      uint32_t wrap = 0;

      bool operator==(const traversing_parameters& rhs) const
      {
          return (dimension == rhs.dimension && stride == rhs.stride && wrap == rhs.wrap);
      }
  };    

  /// Tiling parameters.
  struct tiling_parameters
  {
      /// Buffer dimensions in buffer element type. buffer_dimension[0] is the fast-moving dimension and is contiguous in memory.
      std::vector<uint32_t> buffer_dimension;
      /// Tiling dimensions in buffer element type.
      std::vector<uint32_t> tiling_dimension;
      /// Multi-dimensional offset w.r.t. buffer starting element. Assuming buffer dimension is specified.
      std::vector<int32_t> offset;
      /// Vector of traversing_parameters. tile_traversal[i] represents i-th loop of inter-tile traversal, where i=0 represents most inner loop and i=N-1 represents most outer loop.
      std::vector<traversing_parameters> tile_traversal;
      /// Output port id of the connected pktsplit or the input port id of the connected pktmerge. 
      int packet_port_id = -1;
      /// Number of repetitions of tiling traversal
      uint32_t repetition = 1;
      /// Real data boundary dimension for padding
      std::vector<uint32_t> boundary_dimension;
      /// Buffer object iteration
      uint32_t buffer_iteration = 0;
      /// Phase of tiling parameter resource sharing and execution
      uint32_t phase = 0;
  };

  class access_pattern
  {
  public:
      access_pattern(const buffer_descriptor_parameters& bdParams) : buffer_descriptor(bdParams) {}
      access_pattern(const tiling_parameters& tilingParams) : tiling(tilingParams) {}

      //std::variant<buffer_descriptor_parameters, tiling_parameters> pattern; //use std::variant when c++17 is supported
      buffer_descriptor_parameters buffer_descriptor;
      tiling_parameters tiling;
  };

  struct dma_buffer_descriptor
  {
      /// Address in 32bit word
      /// Memory tile: West 0x0_0000 - 0x7_FFFF (channel 0-3 only); Local 0x8_0000 - 0xF_FFFF; East 0x10_0000 - 0x17FFFF (channel 0-3 only)
      uint64_t address = 0;
      /// Transaction length in 32bit word
      uint32_t length = 0;
      /// D0, D1, D2, D3(memory tile only) stepsize in 32-bit word
      std::vector<uint32_t> stepsize;
      /// D0, D1, D2(memory tile only) wrap in 32-bit word
      std::vector<uint32_t> wrap;
      /// D0, D1, D2 zero-before and zero-after in 32-bit word. MM2S only.
      std::vector<std::pair<uint32_t, uint32_t>> padding;
      /// Enable adding packet header at start of transfer. MM2S only. enable_pkt_mode::automatic enables packet when there is a connected pktsplit.
      bool enable_packet = false;
      /// Packet id
      uint32_t packet_id = 0;
      /// Out of order BD ID. MM2S only.
      uint32_t out_of_order_bd_id = 0;
      /// TLAST suppress. Memory tile only. MM2S only.
      bool tlast_suppress = false;
      /// Iteration stepsize in 32-bit word
      uint32_t iteration_stepsize = 0;
      /// Iteration wrap
      uint32_t iteration_wrap = 0;
      /// Iteration current
      uint32_t iteration_current = 0;
      /// Enable compression for MM2S or enable decompression for S2MM. AIE tile and memory tile only.
      bool enable_compression = false;
      /// Enable lock acquire
      bool lock_acq_enable = false;
      /// Lock acquire value V (signed). V<0: acq_ge; V>=0: acq_eq.
      int32_t lock_acq_value = 0;
      /// ID of lock to acquire
      /// Memory tile: West 0-63 (channel 0-3 only); Local 64-127; East 128-191 (channel 0-3 only)
      uint32_t lock_acq_id = 0;
      /// Lock release value (signed). 0 = do not release a lock.
      int32_t lock_rel_value = 0;
      /// ID of lock to release.
      /// Memory tile: West 0-63 (channel 0-3 only); Local 64-127; East 128-191 (channel 0-3 only)
      uint32_t lock_rel_id = 0;
      /// Use next BD
      bool use_next_bd = false;
      /// Next BD ID
      uint32_t next_bd = 0;
  };

  struct dimension_range
  {
      uint32_t min_index = 0;
      uint32_t max_index = 0;
  };

  struct relative_coordinate
  {
      // default value of col_offset/row_offset implies it is unspecified
      int col_offset = std::numeric_limits<int>::lowest();
      int row_offset = std::numeric_limits<int>::lowest();
  };

  /* for specifying port direction for hls::stream in function signature */
  namespace dir
  {
      template <typename _XILINX_ADF_T> struct in {};
      template <typename _XILINX_ADF_T> struct out {};
  }
}

using adf::ratio;
using adf::output;
using adf::input;
using adf::inout;

#endif


