// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#pragma once

#include "adf/new_frontend/types.h"
#include <functional>
#include <fstream>

# ifdef _MSC_VER
#  ifdef RT_CTRL_API_SOURCE
#   define RT_CTRL_API_EXPORT __declspec(dllexport)
#  else
#   define RT_CTRL_API_EXPORT __declspec(dllimport)
#  endif  
# endif
# ifdef __GNUC__
#  ifdef RT_CTRL_API_SOURCE
#   define RT_CTRL_API_EXPORT __attribute__ ((visibility("default")))
#  else
#   define RT_CTRL_API_EXPORT
#  endif
# endif

namespace adf
{
    ////////////////////////////////////////////////////////////////////////
    // Runtime control APIs implemented using AIE driver for AIE simulation, runtime control microcode generation, and control packet generation
    ////////////////////////////////////////////////////////////////////////
    
    RT_CTRL_API_EXPORT void configureBufferDescriptor(adf::tile_type tileType, uint32_t column, uint32_t row, uint32_t bdId, const adf::dma_buffer_descriptor& bd);
    RT_CTRL_API_EXPORT void enqueueTask(tile_type tileType, uint32_t column, uint32_t row, adf::dma_channel_dir dir, uint32_t channel, uint32_t startBD, uint32_t repeatCount, bool enableTaskCompleteToken);
    RT_CTRL_API_EXPORT void waitDMAChannelTaskQueue(tile_type tileType, uint32_t column, uint32_t row, adf::dma_channel_dir dir, uint32_t channel);
    RT_CTRL_API_EXPORT void waitDMAChannelDone(tile_type tileType, uint32_t column, uint32_t row, adf::dma_channel_dir dir, uint32_t channel);
    RT_CTRL_API_EXPORT void initializeLock(tile_type tileType, uint32_t column, uint32_t row, uint32_t lockId, int32_t initVal);
    RT_CTRL_API_EXPORT void acquireLock(tile_type tileType, uint32_t column, uint32_t row, uint32_t lockId, int32_t acqVal);
    RT_CTRL_API_EXPORT void releaseLock(tile_type tileType, uint32_t column, uint32_t row, uint32_t lockId, int32_t relVal);
    RT_CTRL_API_EXPORT void updateBufferDescriptorAddress(adf::tile_type tileType, uint32_t column, uint32_t row, uint32_t bdId, uint64_t address);

    struct LayerParamsLocation
    {
        uint32_t column;
        uint32_t row;
        uint32_t address;
        std::string path;
        uint32_t acqLockId;
        int32_t acqVal;
        uint32_t relLockId;
        int32_t relVal;
    };
    RT_CTRL_API_EXPORT void writeLayerParams(const std::vector<LayerParamsLocation>& LayerParamsLocs);
    RT_CTRL_API_EXPORT void writeLayerControlParams(uint32_t column, uint32_t row, uint32_t address, std::string path);
    

    ////////////////////////////////////////////////////////////////////////
    // Special APIs (e.g., synchronization, multi-threaded control execution) for AIE simulation and runtime control microcode generation
    ////////////////////////////////////////////////////////////////////////
    
    RT_CTRL_API_EXPORT void waitTaskCompleteToken(tile_type tileType, uint32_t column, uint32_t row, adf::dma_channel_dir dir, uint32_t channel, uint32_t numTokens);
    RT_CTRL_API_EXPORT void waitLayerParams();
    RT_CTRL_API_EXPORT void spawn(std::function<void()> schedule);
    // currently the driver automatically creates the first page
    // per control code file. remove isFirstPage when the driver 
    // requires explicit creation for the first page per control code file
    RT_CTRL_API_EXPORT void runPage(std::function<void()> page, bool isFirstPage = false);
    

    ////////////////////////////////////////////////////////////////////////
    // APIs for accessing external buffer address and syncheonizing external buffers in AIE simulation model
    ////////////////////////////////////////////////////////////////////////

    RT_CTRL_API_EXPORT uint64_t getExternalBufferAddress(uint32_t externalBufferId);

#ifdef __AIESIM__
    RT_CTRL_API_EXPORT void syncPSToGM();
    RT_CTRL_API_EXPORT void syncPSFromGM();
#endif


    ////////////////////////////////////////////////////////////////////////
    // Profiling and debugging APIs for AIE simulation and microcode generation
    ////////////////////////////////////////////////////////////////////////

    RT_CTRL_API_EXPORT void recordTimer(uint64_t id);

    struct MemorySegment
    {
        tile_type tileType;
        uint32_t column;
        uint32_t row;
        uint32_t address;
        uint32_t size;
    };
    RT_CTRL_API_EXPORT void readAieMemory(const std::vector<MemorySegment>& memSegments, std::string bufferObjName);


    ////////////////////////////////////////////////////////////////////////
    // APIs for control packet generation and for accessing control packet buffer in AIE Simulation
    ////////////////////////////////////////////////////////////////////////
    
    RT_CTRL_API_EXPORT void setControlPacketAddress(const void* ptr);
    RT_CTRL_API_EXPORT uint64_t getControlPacketAddress();

    RT_CTRL_API_EXPORT void generateControlPacket(std::ofstream& binaryFileStream, uint32_t packetId, uint32_t alignmentWords, uint32_t payloadWords, std::function<void()> scheduleElement);
}
