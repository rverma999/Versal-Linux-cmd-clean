#ifndef __TILE_CONTROL_API_H__
#define __TILE_CONTROL_API_H__

/* 
Following APIs are used to: 
    - configure AIE2 tile registers through processor bus. --enable-core-processor-bus needs to be set in aiecompiler option in order to use the APIs in this header.
    - to generate core program layer control parameters in aiecompiler backend.
*/

#ifdef __GNUC__
 #define NOINLINE_ATTR  __attribute__((noinline))
#endif
#ifdef _MSC_VER
 #define NOINLINE_ATTR  __declspec(noinline)
#endif

#if (defined(__AIENGINE__) && (__AIE_ARCH__ >= 20)) || defined(__AIECOMPILER_BACKEND__)

#define TILE_CONTROL_DBG false

#ifdef __AIECOMPILER_BACKEND__
// forward declare
namespace adf
{
    struct reg_val;
}
    void write_aiecompiler_backend(adf::reg_val rv); //defined in MainMakerMultiLayer.cpp
#endif

namespace adf
{
    //FIXME: define it in a separate file
    enum layer_control_params_opcode { RUN_CODE_BLOCK = 0x66660001, END_OF_LAYER, END_OF_GRAPH_ITERATION, PADDING };
    
    /// @param address: Base Address in 32-bit words.
    /// @param length: Transaction length in 32-bit words.
    /// @param enable_packet: Enable adding packet header at start of transfer (MM2S only).
    /// @param out_of_order_bd: Value of Inserted out of order BD ID field in packet header (MM2S only).
    /// @param stepsize: DMA step sizes, in 32-bit words. Range [1:8k].
    /// @param wrap: DMA wraps, in 32bit word.
    /// @param packet_id: Value of inserted Packet ID field in packet header (MM2S only).
    /// @param iteration_stepsize: Offset each execution of this BD (number of 32-bit words); Range [1:128k].
    /// @param iteration_wrap: Wrap when iteration_current is equal. Range [1:64].
    /// @param iteration_current: Current iteration step. Field incremented after BD loaded.
    /// @param lock_acq_enable: Enable lock acquire. 0 = do not acquire a lock.
    /// @param lock_acq_value: Lock acquire value V (signed). Vɘ: acq_ge; V>=0: acq_eq.
    /// @param lock_acq_id: ID of lock to acquire
    /// @param lock_rel_value: Lock release value (signed). 0 = do not release a lock.
    /// @param lock_rel_id: ID of lock to release.
    /// @param use_next_bd: Continue with next BD after completion of current BD or stop. 0 = do not use next bd.
    /// @param next_bd: Next BD ID to continue with.
    struct buffer_descriptor
    {
        uint32 address = 0;
        uint32 length = 0;
        bool enable_packet = false;
        uint32 out_of_order_bd = 0;
        uint32 packet_id = 0;
        uint32 stepsize[3] = { 1, 1, 1 };
        uint32 wrap[2] = { 0, 0 };
        uint32 iteration_current = 0;
        uint32 iteration_wrap = 1;
        uint32 iteration_stepsize = 1;
        bool lock_acq_enable = false;
        int32 lock_acq_value = 0;
        uint32 lock_acq_id = 0;
        int32 lock_rel_value = 0;
        uint32 lock_rel_id = 0;
        bool use_next_bd = false;
        uint32 next_bd = 0;
        
    };

    /// @param port_ptr: Kernel port pointer.
    /// @param channel: DMA channel number - 0:S2MM0, 1:S2MM1, 2:MM2S0, 3:MM2S1.
    /// @param pkt_id: Packet ID field in packet header (MM2S only).
    /// @param out_of_order_bd: Out of order BD ID feild in packet header (MM2S only). 
    /// @param bd_ids: BD IDs.
    /// @param num_bd: Number of elements in bd_ids array.
    /// @param locks: Lock IDs.
    /// @param num_lock: Number of elements in locks array.
    /// @param buffer_offsets: Buffer offset addresses (in bytes).
    /// @param num_buffer: Number of elements in buffer_offsets array.
    struct core_dma_config
    {
        void* port_ptr = nullptr;
        short channel = -1;
        short pkt_id = -1;
        short out_of_order_bd = -1;
        short* bd_ids = nullptr;
        short num_bd = 0;
        short* locks = nullptr;
        short num_lock = 0;
        size_t* buffer_offsets = nullptr;
        short num_buffer = 0;
    };
    
    struct reg_val
    {
        uint32 reg;
        uint32 val;
    };

    // Constant offset of 0x80000 (512KB) between tile memory mapped registers (XRegDB) and the requests made via the core processor bus
    constexpr uint32 TM_address_space_start_addr = 0x80000;
    constexpr uint32 Core_DM_Offset = 0x70000; //0x40000-0x7FFFF (256K)
    
#ifdef __AIENGINE__
    // Tile Memory-Mapped (TM) register linkage
    static volatile uint32 chess_storage(TM:TM_address_space_start_addr) TM_Address_Space_Start;
#endif

    //Register offsets from XRegDB
    constexpr uint32 DMA_BD0_0_offset = 0x1D000;
    constexpr uint32 DMA_S2MM_0_Ctrl_offset = 0x1DE00;
    constexpr uint32 DMA_S2MM_0_Start_Queue_offset = 0x1DE04;
    constexpr uint32 Lock0_value_offset = 0x1F000;
    constexpr uint32 DMA_S2MM_Status_0_offset = 0x1DF00;
    constexpr uint32 DMA_MM2S_Status_0_offset = 0x1DF10;
    
    // Constant address strides in bytes
    constexpr short DMA_BD_Stride = 32; // (DMA_BD1_0 - DMA_BD0_0)
    constexpr short DMA_Intra_BD_Stride = 4; // (DMA_BD0_1 - DMA_BD0_0)
    constexpr short DMA_Ch_Ctrl_Stride = 8; // (DMA_S2MM_1_Ctrl - DMA_S2MM_0_Ctrl)
    constexpr short DMA_Start_Queue_Stride = 8; // (DMA_S2MM_1_Start_Queue - DMA_S2MM_0_Start_Queue)
    constexpr short Lock_value_stride = 16; // (Lock1_value - Lock0_value)
    constexpr short DMA_Status_Stride = 4; // (DMA_S2MM_Status_1 - DMA_S2MM_Status_0)

    // Masks
    constexpr uint32 DMA_BD_LOCK_ACQ_VALUE_MASK = 0x00000FE0;
    constexpr uint32 DMA_BD_LOCK_REL_VALUE_MASK = 0x01FC0000;
    constexpr uint32 DMA_STATUS_CHANNEL_RUNNING_MASK = 0x000700003; //0x00070003F; //0x00080000;

    // inline variable allows the following namespace scope variables to be declared in this header file, included in multiple translation units, and instruct linker to result in only one instance of the variable
    inline struct core_dma_config* core_dma_config_ptr = nullptr;
    inline short NUM_DMA_CONFIG;
    
    
    ///////////////////// Low level register APIs ///////////////////////
    
    constexpr uint32 LockX_value_offset(uint32 x)
    { 
        return (Lock0_value_offset + x * Lock_value_stride); 
    }
    
    constexpr uint32 DMA_BDX_Y_offset(uint32 x, uint32 y)
    { 
        return (DMA_BD0_0_offset + x * DMA_BD_Stride + y * DMA_Intra_BD_Stride);
    }
    
    constexpr uint32 DMA_Ch_X_Ctrl_offset(uint32 x) 
    { 
        return (DMA_S2MM_0_Ctrl_offset + x * DMA_Ch_Ctrl_Stride);
    }
    
    constexpr uint32 DMA_X_Start_Queue_offset(uint32 x) 
    { 
        return (DMA_S2MM_0_Start_Queue_offset + x * DMA_Start_Queue_Stride);
    }

    constexpr uint32 DMA_Status_X_offset(uint32 x)
    {
        if (x < 2)
            return (DMA_S2MM_Status_0_offset + x * DMA_Status_Stride);
        else
            return (DMA_MM2S_Status_0_offset + (x-2) * DMA_Status_Stride);
    }

    constexpr reg_val LockX_value(uint32 lock_id, uint32 value)
    {
        return {LockX_value_offset(lock_id), value};
    }
    
    constexpr reg_val DMA_BDX_0(uint32 bd_id, uint32 address, uint32 length)
    {
        return {DMA_BDX_Y_offset(bd_id, 0), (length | (address << 14))};
    }
    
    constexpr reg_val DMA_BDX_1(uint32 bd_id, uint32 packet_id, uint32 out_of_order_bd, bool enable_packet, uint32 packet_type = 0, bool enable_compression = false)
    {
        return {DMA_BDX_Y_offset(bd_id, 1), ((packet_type << 16) | (packet_id << 19) | (out_of_order_bd << 24) | ((uint32)enable_packet << 30) | ((uint32)enable_compression << 31))};
    }
    
    constexpr reg_val DMA_BDX_2(uint32 bd_id, uint32 stepsize0, uint32 stepsize1)
    {
        return {DMA_BDX_Y_offset(bd_id, 2), ((stepsize0 - 1) | ((stepsize1 - 1) << 13))};
    }
    
    constexpr reg_val DMA_BDX_3(uint32 bd_id, uint32 stepsize2, uint32 wrap0, uint32 wrap1)
    {
        return {DMA_BDX_Y_offset(bd_id, 3), ((stepsize2 - 1) | (wrap0 << 13) | (wrap1 << 21))};
    }
    
    constexpr reg_val DMA_BDX_4(uint32 bd_id, uint32 iteration_stepsize, uint32 iteration_wrap, uint32 iteration_current)
    {
        return {DMA_BDX_Y_offset(bd_id, 4), ((iteration_stepsize - 1) | ((iteration_wrap - 1) << 13) | (iteration_current << 19))};
    }
    
    constexpr reg_val DMA_BDX_5(uint32 bd_id, uint32 lock_acq_id, int32 lock_acq_value, bool lock_acq_enable, uint32 lock_rel_id, int32 lock_rel_value, bool valid_bd = true, bool use_next_bd = false, uint32 next_bd = 0, bool tlast_suppress = false)
    {
        return {DMA_BDX_Y_offset(bd_id, 5), (lock_acq_id | ((lock_acq_value << 5) & DMA_BD_LOCK_ACQ_VALUE_MASK) | ((uint32)lock_acq_enable << 12) | (lock_rel_id << 13) | ((lock_rel_value << 18) & DMA_BD_LOCK_REL_VALUE_MASK) | ((uint32)valid_bd << 25) | ((uint32)use_next_bd << 26) | (next_bd << 27) | ((uint32)tlast_suppress << 31))};
    }
    
    /// @param channel: 0:S2MM0, 1:S2MM1, 2:MM2S0, 3:MM2S1.
    constexpr reg_val DMA_X_Start_Queue(uint32 channel, uint32 start_bd, uint32 repeat_count, bool enable_task_complete_token)
    {
        return {DMA_X_Start_Queue_offset(channel), (start_bd | ((repeat_count - 1) << 16) | ((uint32)(enable_task_complete_token) << 31))};
    }
    
    /// @param channel: 0:S2MM0, 1:S2MM1.
    constexpr reg_val DMA_S2MM_X_Ctrl (uint32 channel, bool reset, bool enable_out_of_order_mode, bool decompression_enable, uint32 controller_id, uint32 fot_mode)
    {
        return {DMA_Ch_X_Ctrl_offset(channel), (((uint32)(reset) << 1) | ((uint32)(enable_out_of_order_mode) << 3) | ((uint32)(decompression_enable) << 4) | (controller_id << 8) | (fot_mode << 16))};
    }
    
    /// @param channel: 2:MM2S0, 3:MM2S1.
    constexpr reg_val DMA_MM2S_X_Ctrl (uint32 channel, bool reset, bool compression_enable, uint32 controller_id)
    {
        return {DMA_Ch_X_Ctrl_offset(channel), (((uint32)(reset) << 1) | ((uint32)(compression_enable) << 4) | (controller_id << 8))};
    }

    ///////////////////////// Read/Write APIs ///////////////////////////

    constexpr uint32 read(const uint32 reg)
    {
#ifdef __AIENGINE__

#if TILE_CONTROL_DBG
        printf("r %p\n", (&TM_Address_Space_Start + reg / 4));
#endif
#if defined(__AIECC__) && !defined(__AIECC__DISABLE_READ_WRITE_TM)
        return read_tm(reg);
#else
        return *(&TM_Address_Space_Start + reg / 4);
#endif

#else
        return 0;
#endif
    }
    
    inline void write(const reg_val rv)
    {
#ifdef __AIENGINE__

#if TILE_CONTROL_DBG
        printf("%u\n%u\n\n", (&TM_Address_Space_Start + rv.reg / 4), rv.val);
#endif
#if defined(__AIECC__) && !defined(__AIECC__DISABLE_READ_WRITE_TM)
        write_tm(rv.val, rv.reg);
#else
        *(&TM_Address_Space_Start + rv.reg / 4) = rv.val;
#endif
#endif

#ifdef __AIECOMPILER_BACKEND__
        write_aiecompiler_backend(rv);
#endif
    }
    
    inline void NOINLINE_ATTR block_write(const reg_val* rv, size_t size)
    {
#if TILE_CONTROL_DBG
        printf("block_write size:%zu\n", size);
#endif
        for(int i = 0; i < size; i++) write(rv[i]);
    }
    
    inline void NOINLINE_ATTR block_write_bd_1d(const uint32* val, size_t size)
    {
#if TILE_CONTROL_DBG
        printf("block_write_bd_1d size:%zu\n", size);
#endif
        //Considering each BD config takes 5 words where first word is an address.
        for(int i = 0; i < size/5; ++i)
        {
            int startIdx = i*5;
            uint32_t startAddr = val[startIdx];
            write({startAddr, val[startIdx + 1]});
            write({startAddr + 4, val[startIdx + 2]});
            write({startAddr + 8, 0});
            write({startAddr + 12, 0});
            write({startAddr + 16, val[startIdx + 3]});
            write({startAddr + 20, val[startIdx + 4]});
        }
    }
    
    /////////////////////////////////////////////////////////////////////

    inline void initialize_tile_control_config(core_dma_config* config_ptr, short num_config)
    {
        core_dma_config_ptr = config_ptr;
        NUM_DMA_CONFIG = num_config;
    }


    /// API to get core dma config information.
    /// @param port_ptr: Kernel port pointer.
    /// @return If found, pointer to core DMA config struct else nullptr.
    inline const core_dma_config* get_core_dma_config(void* port_ptr)
    {
        for (int i = 0; i < NUM_DMA_CONFIG; i++)
            if (core_dma_config_ptr[i].port_ptr == port_ptr) return &core_dma_config_ptr[i];
        return nullptr;
    }

    /// API to set the lock value.
    /// @param lock_id: Lock ID. Range [0:15].
    /// @param value: Lock value to set.
    inline void initialize_lock(uint32 lock_id, uint32 value)
    {
#if TILE_CONTROL_DBG
        printf("initialize_lock lock=%d val=%d\n", lock_id, value);
#endif

        write(LockX_value(lock_id, value));
    }
    
    /// API to configure tile DMA buffer descriptor.
    /// @param bd_id: BD number.
    /// @param bd_parameters: BD parameters.
    static void configure_bd(uint32 bd_id, const buffer_descriptor& bd_parameters)
    {
#if TILE_CONTROL_DBG
        printf("configure_bd: bd=%d\n", bd_id);
#endif

        // BDZ_0
        write(DMA_BDX_0(bd_id, bd_parameters.address, bd_parameters.length));
        
        // BDZ_1
        write(DMA_BDX_1(bd_id, bd_parameters.packet_id, bd_parameters.out_of_order_bd, bd_parameters.enable_packet));

        // BDZ_2
        write(DMA_BDX_2(bd_id, bd_parameters.stepsize[0], bd_parameters.stepsize[1]));

        // BDZ_3
        write(DMA_BDX_3(bd_id, bd_parameters.stepsize[2], bd_parameters.wrap[0], bd_parameters.wrap[1]));
    
        // BDZ_4
        write(DMA_BDX_4(bd_id, bd_parameters.iteration_stepsize, bd_parameters.iteration_wrap, bd_parameters.iteration_current));

        // BDZ_5
        write(DMA_BDX_5(bd_id, bd_parameters.lock_acq_id, bd_parameters.lock_acq_value, bd_parameters.lock_acq_enable, bd_parameters.lock_rel_id, bd_parameters.lock_rel_value, true, bd_parameters.use_next_bd, bd_parameters.next_bd));
    }

    
    /// API to control DMA channel.
    /// @param channel: 0:S2MM0, 1:S2MM1, 2:MM2S0, 3:MM2S1.
    /// @param reset: reset channel.
    /// @param enable_out_of_order_mode: Enable out of order mode (S2MM only).
    /// @param enable_compression_decompression: Enable compression(MM2S)/decompression(S2MM).
    /// @param controller_id: Task-complete-token controller ID.
    /// @param fot_mode: Finish on TLAST mode (S2MM only).
    inline void dma_ch_ctrl(uint32 channel, bool reset, bool enable_out_of_order_mode, bool enable_compression_decompression, uint32 controller_id, uint32 fot_mode)
    {
#if TILE_CONTROL_DBG    
        printf("dma_ch_ctrl: ch=%d\n", channel);
#endif
        if(channel < 2) //S2MM
            write(DMA_S2MM_X_Ctrl (channel, reset, enable_out_of_order_mode, enable_compression_decompression, controller_id, fot_mode));
        else //MM2S
            write(DMA_MM2S_X_Ctrl (channel, reset, enable_compression_decompression, controller_id));
    }
    
    /// API to enqueue task to tile DMA.
    /// @param channel: 0:S2MM0, 1:S2MM1, 2:MM2S0, 3:MM2S1.
    /// @param start_bd: Start bd.
    /// @param repeat_count: Task repeat count.
    /// @param enable_task_complete_token: Enable task complete token.
    inline void enqueue_task(uint32 channel, uint32 start_bd, uint32 repeat_count, bool enable_task_complete_token)
    {
#if TILE_CONTROL_DBG    
        printf("enqueue_task: ch=%d start_bd=%d\n", channel, start_bd);
#endif
        write(DMA_X_Start_Queue(channel, start_bd, repeat_count, enable_task_complete_token));
    }

    /// API to configure buffer descriptor and enqueue task to tile DMA.
    /// @param channel: 0:S2MM0, 1:S2MM1, 2:MM2S0, 3:MM2S1.
    /// @param start_bd: start bd.
    /// @param repeat_count: Task repeat count.
    /// @param enable_task_complete_token: Enable task complete token.
    /// @param bd_parameters: BD struct.
    inline void enqueue_task(uint32 channel, uint32 start_bd, uint32 repeat_count, bool enable_task_complete_token, const buffer_descriptor& bd_parameters)
    {
        configure_bd(start_bd, bd_parameters);
        enqueue_task(channel, start_bd, repeat_count, enable_task_complete_token);
    }
    
    /// API to wait for tile DMA channel done.
    /// @param channel: 0:S2MM0, 1:S2MM1, 2:MM2S0, 3:MM2S1.
    inline void wait_dma_channel_done(uint32 channel)
    {
#if TILE_CONTROL_DBG    
        printf("wait_dma_channel_done: ch=%d \n", channel);
#endif
        uint32 reg = DMA_Status_X_offset(channel);
        while ((read(reg) & DMA_STATUS_CHANNEL_RUNNING_MASK) != 0) {}
    }
    
    constexpr uint32 core_to_dma_address(size_t core_addr)
    {
        return (core_addr - Core_DM_Offset)/4;
    }
} // namespace adf

#endif
#endif // end __TILE_CONTROL_API_H__
