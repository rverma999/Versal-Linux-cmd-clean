// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>

namespace adf
{
    enum plio_direction
    {
        pl2aie = 0,
        aie2pl
    };  

    enum stream_direction
    {
        st_input = 0,
        st_output
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



    /// core_info contains mapping information related to AIE tile
    /// @param tile Tile type: aie_tile, shim_tile, memory_tile
    /// @param column Column index
    /// @param row Row index w.r.t to tile type
    /// @param schedule Kernel schedule in a core program
    struct core_info {
        tile_type tile;
        uint32_t column = 0;
        uint32_t row = 0;
        uint32_t schedule = 0;
    };

    /// dma_info contains mapping information related to AIE tile, memory tile, shim tile DMA
    /// @param tile Tile type: aie_tile, shim_tile, memory_tile
    /// @param column Column index
    /// @param row Row index w.r.t to tile type
    /// @param direction Direction: s2mm, mm2s
    /// @param channel DMA channel ID
    /// @param buffer_descriptor BD allocation
    /// @param packet_id packet ID allocation 
    struct dma_info {
        tile_type tile;
        uint32_t column = 0;
        uint32_t row = 0;
        dma_channel_dir direction;
        uint32_t channel = 0;
        std::vector<uint32_t> buffer_descriptor; 
        std::vector<uint32_t> packet_id; 
    };

    /// plio_info contains mapping information related PLIOs
    /// @param tile Tile type: aie_tile, shim_tile, memory_tile
    /// @param column Column index
    /// @param direction Direction: pl2aie, aie2pl
    /// @param channel DMA channel ID
    struct plio_info {
        tile_type tile;
        uint32_t column = 0;
        plio_direction direction;
        uint32_t channel = 0;
    };

    /// buffer_info contains mapping information of buffers in sharedMemory, systemMemory, ports 
    /// @param generatedName compiler generated name for the buffers
    /// @param tile Tile type: aie_tile, shim_tile, memory_tile
    /// @param column Column index
    /// @param row Row index w.r.t to tile type
    /// @param offset Total offset
    /// @param size Size of buffer
    /// @param is_control_buffer True if it is a control buffer 
    /// @param lock_id Lock ID
    struct buffer_info {
        std::string generatedName; 
        tile_type tile;
        uint32_t column = 0;
        uint32_t row = 0;
        uint32_t offset = 0;
        uint32_t size = 0;
        bool is_control_buffer = false;
        std::vector<uint32_t> lock_id; 
    };

    /// graph_info contains mapping information of graphs 
    /// @param core_columns Number of columns 
    /// @param core_rows Number of rows 
    /// @param iter_mem_columns
    /// @param iter_mem_rows
    /// @param iter_mem_addrs 
    /// @param triggered 
    struct graph_info
    {
        std::vector<short> core_columns;
        std::vector<short> core_rows;
        std::vector<short> iter_mem_columns;
        std::vector<short> iter_mem_rows;
        std::vector<size_t> iter_mem_addrs;
        std::vector<bool> triggered;
    };

    /// aie_driver_config contains configuration information
    /// @param hw_gen 
    /// @param base_address 
    /// @param column_shift
    /// @param row_shift
    /// @param num_columns 
    /// @param num_rows 
    /// @param shim_row 
    /// @param mem_tile_row_start 
    /// @param mem_tile_num_rows 
    /// @param aie_tile_row_start 
    /// @param aie_tile_num_rows 
    struct aie_driver_config
    {
        uint32_t hw_gen = 0;
        uint64_t base_address = 0;
        uint64_t npi_address = 0;
        uint32_t column_shift = 0;
        uint32_t row_shift = 0;
        uint32_t num_columns = 0;
        uint32_t num_rows = 0;
        uint32_t shim_row = 0;
        uint32_t mem_tile_row_start = 0;
        uint32_t mem_tile_num_rows = 0;
        uint32_t aie_tile_row_start = 0;
        uint32_t aie_tile_num_rows = 0;
    };

    /// schedule_info contains scheduling information
    /// @param repetition_count  
    struct schedule_info
    {
        uint32_t repetition_count = 0;
    };

    /// stream_info contains mapping information of streams 
    /// @param direction Direction: in, out, inout
    /// @param channel Stream channel ID
    struct stream_info
    {
        stream_direction direction;
        uint32_t channel = 0;
    };

    // dma_fifo contains dmafifo attributes for specific fifo counter, row and column
    // @param netID: NetName for fifo counter
    // @param s2mm: S2MM channel of DMA FIFO
    // @param mm2s: MM2S channel of DMA FIFO
    struct dma_fifo
    {
	std::string netID;
	std::string s2mm;
	std::string mm2s;	
    };


    class document_manager;

    class compiler_report 
    {
    public:
        bool open(const std::string &fileName);
        void close();
        bool get_core_info(std::string qualifiedNodeName, core_info& coreInfo);
        bool get_dma_info(std::string qualifiedPortName, dma_info& dmaInfo);
        bool get_plio_info(std::string qualifiedPortName, plio_info& plioInfo);
        bool get_stream_info(std::string qualifiedPortName, stream_info& streamInfo);
        bool get_buffer_info(std::string qualifiedName, std::vector<buffer_info>& bufferInfo);
        bool get_graph_info(std::string qualifiedName, graph_info& graphInfo);
        bool get_schedule_info(std::string qualifiedName, schedule_info& scheduleInfo);
        bool get_driver_info(aie_driver_config& driverInfo);
        bool get_dmafifo_info(int row, int col, int fifo_counter, dma_fifo& dmafifo);
        int get_mem_tile_rows();
        int get_hw_gen();
        unsigned long long get_array_base_address();
        std::map<std::string, std::pair<std::string,std::string> > get_QualifiedPortMap(void);
        std::vector<std::pair< unsigned int, unsigned int>> getMemTileMapping(); // Returns MemTileInfoVec
        std::vector<unsigned int> getShimTileMapping(); // Returns ShimTileInfoVec
        compiler_report(); 
        virtual ~compiler_report(); 
    private:
        std::unique_ptr<document_manager> dm;
        std::map<std::string, std::string> nameMap;
        // mapQualifiedPortName
        // key  : portInstances
        // value: pair< qualifiedName, graphName>
        std::map<std::string,
            std::pair<std::string,std::string> > mapQualifiedPortName;
       // MemTileInfoVec for used memory tiles
       // value : pair<column, row>  
        std::vector<std::pair< unsigned int, unsigned int>> MemTileInfoVec;
       // ShimTileInfoVec for used shim tiles
       // value : vector<column>  
        std::vector<unsigned int> ShimTileInfoVec; 

        bool processInternalNameMap();

    };

}
