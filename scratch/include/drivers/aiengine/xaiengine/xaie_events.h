/******************************************************************************
* Copyright (C) 2019 - 2022 Xilinx, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/


/*****************************************************************************/
/**
* @file xaie_events.h
* @{
*
* Header file for AIE events module.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who      Date     Changes
* ----- ------   -------- -----------------------------------------------------
* 1.0   Dishita  11/21/2019  Initial creation
* 1.1   Nishad   06/02/2020  Move event files under events directory
* 1.2   Nishad   06/02/2020  Remove unused included header files
* 1.3   Nishad   07/06/2020  Add APIs to configure stream switch port event
*			     selection, event generation, and combo event
*			     registers.
* 1.4   Nishad   07/12/2020  Add APIs to configure event broadcast, PC event,
*			     and group event registers.
* 1.5   Nishad  07/14/2020  Add APIs to reset individual stream switch port
*			    event selection ID and combo event.
* 1.6   Nishad   07/23/2020  Add API to block brodcast signals using bitmap.
* </pre>
*
******************************************************************************/
#ifndef XAIE_EVENTS_H
#define XAIE_EVENTS_H

/***************************** Include Files *********************************/
#include "xaiegbl.h"

/***************************** Macro Definitions *****************************/
#define XAIE_EVENT_INVALID		255U

/**************************** Type Definitions *******************************/
/*
 * This enum contains all the Events for all modules: Core, Memory of AIE tile
 * MEM tile and PL tile
 */
typedef enum {
	/* All core module events of aie tile */
	XAIE_EVENT_NONE_CORE,
	XAIE_EVENT_TRUE_CORE,
	XAIE_EVENT_GROUP_0_CORE,
	XAIE_EVENT_TIMER_SYNC_CORE,
	XAIE_EVENT_TIMER_VALUE_REACHED_CORE,
	XAIE_EVENT_PERF_CNT_0_CORE,
	XAIE_EVENT_PERF_CNT_1_CORE,
	XAIE_EVENT_PERF_CNT_2_CORE,
	XAIE_EVENT_PERF_CNT_3_CORE,
	XAIE_EVENT_COMBO_EVENT_0_CORE,
	XAIE_EVENT_COMBO_EVENT_1_CORE,
	XAIE_EVENT_COMBO_EVENT_2_CORE,
	XAIE_EVENT_COMBO_EVENT_3_CORE,
	XAIE_EVENT_GROUP_PC_EVENT_CORE,
	XAIE_EVENT_PC_0_CORE,
	XAIE_EVENT_PC_1_CORE,
	XAIE_EVENT_PC_2_CORE,
	XAIE_EVENT_PC_3_CORE,
	XAIE_EVENT_PC_RANGE_0_1_CORE,
	XAIE_EVENT_PC_RANGE_2_3_CORE,
	XAIE_EVENT_GROUP_CORE_STALL_CORE,
	XAIE_EVENT_MEMORY_STALL_CORE,
	XAIE_EVENT_STREAM_STALL_CORE,
	XAIE_EVENT_CASCADE_STALL_CORE,
	XAIE_EVENT_LOCK_STALL_CORE,
	XAIE_EVENT_DEBUG_HALTED_CORE,
	XAIE_EVENT_ACTIVE_CORE,
	XAIE_EVENT_DISABLED_CORE,
	XAIE_EVENT_ECC_ERROR_STALL_CORE,
	XAIE_EVENT_ECC_SCRUBBING_STALL_CORE,
	XAIE_EVENT_GROUP_CORE_PROGRAM_FLOW_CORE,
	XAIE_EVENT_INSTR_EVENT_0_CORE,
	XAIE_EVENT_INSTR_EVENT_1_CORE,
	XAIE_EVENT_INSTR_CALL_CORE,
	XAIE_EVENT_INSTR_RETURN_CORE,
	XAIE_EVENT_INSTR_VECTOR_CORE,
	XAIE_EVENT_INSTR_LOAD_CORE,
	XAIE_EVENT_INSTR_STORE_CORE,
	XAIE_EVENT_INSTR_STREAM_GET_CORE,
	XAIE_EVENT_INSTR_STREAM_PUT_CORE,
	XAIE_EVENT_INSTR_CASCADE_GET_CORE,
	XAIE_EVENT_INSTR_CASCADE_PUT_CORE,
	XAIE_EVENT_INSTR_LOCK_ACQUIRE_REQ_CORE,
	XAIE_EVENT_INSTR_LOCK_RELEASE_REQ_CORE,
	XAIE_EVENT_GROUP_ERRORS_0_CORE,
	XAIE_EVENT_GROUP_ERRORS_1_CORE,
	XAIE_EVENT_SRS_SATURATE_CORE,
	XAIE_EVENT_UPS_SATURATE_CORE,
	XAIE_EVENT_FP_OVERFLOW_CORE,
	XAIE_EVENT_FP_UNDERFLOW_CORE,
	XAIE_EVENT_FP_INVALID_CORE,
	XAIE_EVENT_FP_DIV_BY_ZERO_CORE,
	XAIE_EVENT_TLAST_IN_WSS_WORDS_0_2_CORE,
	XAIE_EVENT_PM_REG_ACCESS_FAILURE_CORE,
	XAIE_EVENT_STREAM_PKT_PARITY_ERROR_CORE,
	XAIE_EVENT_CONTROL_PKT_ERROR_CORE,
	XAIE_EVENT_AXI_MM_SLAVE_ERROR_CORE,
	XAIE_EVENT_INSTR_DECOMPRSN_ERROR_CORE,
	XAIE_EVENT_DM_ADDRESS_OUT_OF_RANGE_CORE,
	XAIE_EVENT_PM_ECC_ERROR_SCRUB_CORRECTED_CORE,
	XAIE_EVENT_PM_ECC_ERROR_SCRUB_2BIT_CORE,
	XAIE_EVENT_PM_ECC_ERROR_1BIT_CORE,
	XAIE_EVENT_PM_ECC_ERROR_2BIT_CORE,
	XAIE_EVENT_PM_ADDRESS_OUT_OF_RANGE_CORE,
	XAIE_EVENT_DM_ACCESS_TO_UNAVAILABLE_CORE,
	XAIE_EVENT_LOCK_ACCESS_TO_UNAVAILABLE_CORE,
	XAIE_EVENT_INSTR_EVENT_2,
	XAIE_EVENT_INSTR_EVENT_3,
	XAIE_EVENT_GROUP_STREAM_SWITCH_CORE,
	XAIE_EVENT_PORT_IDLE_0_CORE,
	XAIE_EVENT_PORT_RUNNING_0_CORE,
	XAIE_EVENT_PORT_STALLED_0_CORE,
	XAIE_EVENT_PORT_TLAST_0_CORE,
	XAIE_EVENT_PORT_IDLE_1_CORE,
	XAIE_EVENT_PORT_RUNNING_1_CORE,
	XAIE_EVENT_PORT_STALLED_1_CORE,
	XAIE_EVENT_PORT_TLAST_1_CORE,
	XAIE_EVENT_PORT_IDLE_2_CORE,
	XAIE_EVENT_PORT_RUNNING_2_CORE,
	XAIE_EVENT_PORT_STALLED_2_CORE,
	XAIE_EVENT_PORT_TLAST_2_CORE,
	XAIE_EVENT_PORT_IDLE_3_CORE,
	XAIE_EVENT_PORT_RUNNING_3_CORE,
	XAIE_EVENT_PORT_STALLED_3_CORE,
	XAIE_EVENT_PORT_TLAST_3_CORE,
	XAIE_EVENT_PORT_IDLE_4_CORE,
	XAIE_EVENT_PORT_RUNNING_4_CORE,
	XAIE_EVENT_PORT_STALLED_4_CORE,
	XAIE_EVENT_PORT_TLAST_4_CORE,
	XAIE_EVENT_PORT_IDLE_5_CORE,
	XAIE_EVENT_PORT_RUNNING_5_CORE,
	XAIE_EVENT_PORT_STALLED_5_CORE,
	XAIE_EVENT_PORT_TLAST_5_CORE,
	XAIE_EVENT_PORT_IDLE_6_CORE,
	XAIE_EVENT_PORT_RUNNING_6_CORE,
	XAIE_EVENT_PORT_STALLED_6_CORE,
	XAIE_EVENT_PORT_TLAST_6_CORE,
	XAIE_EVENT_PORT_IDLE_7_CORE,
	XAIE_EVENT_PORT_RUNNING_7_CORE,
	XAIE_EVENT_PORT_STALLED_7_CORE,
	XAIE_EVENT_PORT_TLAST_7_CORE,
	XAIE_EVENT_GROUP_BROADCAST_CORE,
	XAIE_EVENT_BROADCAST_0_CORE,
	XAIE_EVENT_BROADCAST_1_CORE,
	XAIE_EVENT_BROADCAST_2_CORE,
	XAIE_EVENT_BROADCAST_3_CORE,
	XAIE_EVENT_BROADCAST_4_CORE,
	XAIE_EVENT_BROADCAST_5_CORE,
	XAIE_EVENT_BROADCAST_6_CORE,
	XAIE_EVENT_BROADCAST_7_CORE,
	XAIE_EVENT_BROADCAST_8_CORE,
	XAIE_EVENT_BROADCAST_9_CORE,
	XAIE_EVENT_BROADCAST_10_CORE,
	XAIE_EVENT_BROADCAST_11_CORE,
	XAIE_EVENT_BROADCAST_12_CORE,
	XAIE_EVENT_BROADCAST_13_CORE,
	XAIE_EVENT_BROADCAST_14_CORE,
	XAIE_EVENT_BROADCAST_15_CORE,
	XAIE_EVENT_GROUP_USER_EVENT_CORE,
	XAIE_EVENT_USER_EVENT_0_CORE,
	XAIE_EVENT_USER_EVENT_1_CORE,
	XAIE_EVENT_USER_EVENT_2_CORE,
	XAIE_EVENT_USER_EVENT_3_CORE,
	XAIE_EVENT_EDGE_DETECTION_EVENT_0_CORE,
	XAIE_EVENT_EDGE_DETECTION_EVENT_1_CORE,
	XAIE_EVENT_FP_HUGE_CORE,
	XAIE_EVENT_INT_FP_0_CORE,
	XAIE_EVENT_FP_INF_CORE,
	XAIE_EVENT_INSTR_WARNING_CORE,
	XAIE_EVENT_INSTR_ERROR_CORE,
	XAIE_EVENT_DECOMPRESSION_UNDERFLOW_CORE,
	XAIE_EVENT_STREAM_SWITCH_PORT_PARITY_ERROR_CORE,
	XAIE_EVENT_PROCESSOR_BUS_ERROR_CORE,

	/* All memory module events of aie tile */
	XAIE_EVENT_NONE_MEM = 1000U,
	XAIE_EVENT_TRUE_MEM,
	XAIE_EVENT_GROUP_0_MEM,
	XAIE_EVENT_TIMER_SYNC_MEM,
	XAIE_EVENT_TIMER_VALUE_REACHED_MEM,
	XAIE_EVENT_PERF_CNT_0_MEM,
	XAIE_EVENT_PERF_CNT_1_MEM,
	XAIE_EVENT_COMBO_EVENT_0_MEM,
	XAIE_EVENT_COMBO_EVENT_1_MEM,
	XAIE_EVENT_COMBO_EVENT_2_MEM,
	XAIE_EVENT_COMBO_EVENT_3_MEM,
	XAIE_EVENT_GROUP_WATCHPOINT_MEM,
	XAIE_EVENT_WATCHPOINT_0_MEM,
	XAIE_EVENT_WATCHPOINT_1_MEM,
	XAIE_EVENT_GROUP_DMA_ACTIVITY_MEM,
	XAIE_EVENT_DMA_S2MM_0_START_BD_MEM,
	XAIE_EVENT_DMA_S2MM_1_START_BD_MEM,
	XAIE_EVENT_DMA_MM2S_0_START_BD_MEM,
	XAIE_EVENT_DMA_MM2S_1_START_BD_MEM,
	XAIE_EVENT_DMA_S2MM_0_FINISHED_BD_MEM,
	XAIE_EVENT_DMA_S2MM_1_FINISHED_BD_MEM,
	XAIE_EVENT_DMA_MM2S_0_FINISHED_BD_MEM,
	XAIE_EVENT_DMA_MM2S_1_FINISHED_BD_MEM,
	XAIE_EVENT_DMA_S2MM_0_GO_TO_IDLE_MEM,
	XAIE_EVENT_DMA_S2MM_1_GO_TO_IDLE_MEM,
	XAIE_EVENT_DMA_MM2S_0_GO_TO_IDLE_MEM,
	XAIE_EVENT_DMA_MM2S_1_GO_TO_IDLE_MEM,
	XAIE_EVENT_DMA_S2MM_0_STALLED_LOCK_ACQUIRE_MEM,
	XAIE_EVENT_DMA_S2MM_1_STALLED_LOCK_ACQUIRE_MEM,
	XAIE_EVENT_DMA_MM2S_0_STALLED_LOCK_ACQUIRE_MEM,
	XAIE_EVENT_DMA_MM2S_1_STALLED_LOCK_ACQUIRE_MEM,
	XAIE_EVENT_DMA_S2MM_0_MEMORY_CONFLICT_MEM,
	XAIE_EVENT_DMA_S2MM_1_MEMORY_CONFLICT_MEM,
	XAIE_EVENT_DMA_MM2S_0_MEMORY_CONFLICT_MEM,
	XAIE_EVENT_DMA_MM2S_1_MEMORY_CONFLICT_MEM,
	XAIE_EVENT_GROUP_LOCK_MEM,
	XAIE_EVENT_LOCK_0_ACQ_MEM,
	XAIE_EVENT_LOCK_0_REL_MEM,
	XAIE_EVENT_LOCK_1_ACQ_MEM,
	XAIE_EVENT_LOCK_1_REL_MEM,
	XAIE_EVENT_LOCK_2_ACQ_MEM,
	XAIE_EVENT_LOCK_2_REL_MEM,
	XAIE_EVENT_LOCK_3_ACQ_MEM,
	XAIE_EVENT_LOCK_3_REL_MEM,
	XAIE_EVENT_LOCK_4_ACQ_MEM,
	XAIE_EVENT_LOCK_4_REL_MEM,
	XAIE_EVENT_LOCK_5_ACQ_MEM,
	XAIE_EVENT_LOCK_5_REL_MEM,
	XAIE_EVENT_LOCK_6_ACQ_MEM,
	XAIE_EVENT_LOCK_6_REL_MEM,
	XAIE_EVENT_LOCK_7_ACQ_MEM,
	XAIE_EVENT_LOCK_7_REL_MEM,
	XAIE_EVENT_LOCK_8_ACQ_MEM,
	XAIE_EVENT_LOCK_8_REL_MEM,
	XAIE_EVENT_LOCK_9_ACQ_MEM,
	XAIE_EVENT_LOCK_9_REL_MEM,
	XAIE_EVENT_LOCK_10_ACQ_MEM,
	XAIE_EVENT_LOCK_10_REL_MEM,
	XAIE_EVENT_LOCK_11_ACQ_MEM,
	XAIE_EVENT_LOCK_11_REL_MEM,
	XAIE_EVENT_LOCK_12_ACQ_MEM,
	XAIE_EVENT_LOCK_12_REL_MEM,
	XAIE_EVENT_LOCK_13_ACQ_MEM,
	XAIE_EVENT_LOCK_13_REL_MEM,
	XAIE_EVENT_LOCK_14_ACQ_MEM,
	XAIE_EVENT_LOCK_14_REL_MEM,
	XAIE_EVENT_LOCK_15_ACQ_MEM,
	XAIE_EVENT_LOCK_15_REL_MEM,
	XAIE_EVENT_GROUP_MEMORY_CONFLICT_MEM,
	XAIE_EVENT_CONFLICT_DM_BANK_0_MEM,
	XAIE_EVENT_CONFLICT_DM_BANK_1_MEM,
	XAIE_EVENT_CONFLICT_DM_BANK_2_MEM,
	XAIE_EVENT_CONFLICT_DM_BANK_3_MEM,
	XAIE_EVENT_CONFLICT_DM_BANK_4_MEM,
	XAIE_EVENT_CONFLICT_DM_BANK_5_MEM,
	XAIE_EVENT_CONFLICT_DM_BANK_6_MEM,
	XAIE_EVENT_CONFLICT_DM_BANK_7_MEM,
	XAIE_EVENT_GROUP_ERRORS_MEM,
	XAIE_EVENT_DM_ECC_ERROR_SCRUB_CORRECTED_MEM,
	XAIE_EVENT_DM_ECC_ERROR_SCRUB_2BIT_MEM,
	XAIE_EVENT_DM_ECC_ERROR_1BIT_MEM,
	XAIE_EVENT_DM_ECC_ERROR_2BIT_MEM,
	XAIE_EVENT_DM_PARITY_ERROR_BANK_2_MEM,
	XAIE_EVENT_DM_PARITY_ERROR_BANK_3_MEM,
	XAIE_EVENT_DM_PARITY_ERROR_BANK_4_MEM,
	XAIE_EVENT_DM_PARITY_ERROR_BANK_5_MEM,
	XAIE_EVENT_DM_PARITY_ERROR_BANK_6_MEM,
	XAIE_EVENT_DM_PARITY_ERROR_BANK_7_MEM,
	XAIE_EVENT_DMA_S2MM_0_ERROR_MEM,
	XAIE_EVENT_DMA_S2MM_1_ERROR_MEM,
	XAIE_EVENT_DMA_MM2S_0_ERROR_MEM,
	XAIE_EVENT_DMA_MM2S_1_ERROR_MEM,
	XAIE_EVENT_GROUP_BROADCAST_MEM,
	XAIE_EVENT_BROADCAST_0_MEM,
	XAIE_EVENT_BROADCAST_1_MEM,
	XAIE_EVENT_BROADCAST_2_MEM,
	XAIE_EVENT_BROADCAST_3_MEM,
	XAIE_EVENT_BROADCAST_4_MEM,
	XAIE_EVENT_BROADCAST_5_MEM,
	XAIE_EVENT_BROADCAST_6_MEM,
	XAIE_EVENT_BROADCAST_7_MEM,
	XAIE_EVENT_BROADCAST_8_MEM,
	XAIE_EVENT_BROADCAST_9_MEM,
	XAIE_EVENT_BROADCAST_10_MEM,
	XAIE_EVENT_BROADCAST_11_MEM,
	XAIE_EVENT_BROADCAST_12_MEM,
	XAIE_EVENT_BROADCAST_13_MEM,
	XAIE_EVENT_BROADCAST_14_MEM,
	XAIE_EVENT_BROADCAST_15_MEM,
	XAIE_EVENT_GROUP_USER_EVENT_MEM,
	XAIE_EVENT_USER_EVENT_0_MEM,
	XAIE_EVENT_USER_EVENT_1_MEM,
	XAIE_EVENT_USER_EVENT_2_MEM,
	XAIE_EVENT_USER_EVENT_3_MEM,
	XAIE_EVENT_EDGE_DETECTION_EVENT_0_MEM,
	XAIE_EVENT_EDGE_DETECTION_EVENT_1_MEM,
	XAIE_EVENT_DMA_S2MM_0_START_TASK_MEM,
	XAIE_EVENT_DMA_S2MM_1_START_TASK_MEM,
	XAIE_EVENT_DMA_MM2S_0_START_TASK_MEM,
	XAIE_EVENT_DMA_MM2S_1_START_TASK_MEM,
	XAIE_EVENT_DMA_S2MM_0_FINISHED_TASK_MEM,
	XAIE_EVENT_DMA_S2MM_1_FINISHED_TASK_MEM,
	XAIE_EVENT_DMA_MM2S_0_FINISHED_TASK_MEM,
	XAIE_EVENT_DMA_MM2S_1_FINISHED_TASK_MEM,
	XAIE_EVENT_DMA_S2MM_0_STALLED_LOCK_MEM,
	XAIE_EVENT_DMA_S2MM_1_STALLED_LOCK_MEM,
	XAIE_EVENT_DMA_MM2S_0_STALLED_LOCK_MEM,
	XAIE_EVENT_DMA_MM2S_1_STALLED_LOCK_MEM,
	XAIE_EVENT_DMA_S2MM_0_STREAM_STARVATION_MEM,
	XAIE_EVENT_DMA_S2MM_1_STREAM_STARVATION_MEM,
	XAIE_EVENT_DMA_MM2S_0_STREAM_BACKPRESSURE_MEM,
	XAIE_EVENT_DMA_MM2S_1_STREAM_BACKPRESSURE_MEM,
	XAIE_EVENT_DMA_S2MM_0_MEMORY_BACKPRESSURE_MEM,
	XAIE_EVENT_DMA_S2MM_1_MEMORY_BACKPRESSURE_MEM,
	XAIE_EVENT_DMA_MM2S_0_MEMORY_STARVATION_MEM,
	XAIE_EVENT_DMA_MM2S_1_MEMORY_STARVATION_MEM,
	XAIE_EVENT_LOCK_SEL0_ACQ_EQ_MEM,
	XAIE_EVENT_LOCK_SEL0_ACQ_GE_MEM,
	XAIE_EVENT_LOCK_SEL0_EQUAL_TO_VALUE_MEM,
	XAIE_EVENT_LOCK_SEL1_ACQ_EQ_MEM,
	XAIE_EVENT_LOCK_SEL1_ACQ_GE_MEM,
	XAIE_EVENT_LOCK_SEL1_EQUAL_TO_VALUE_MEM,
	XAIE_EVENT_LOCK_SEL2_ACQ_EQ_MEM,
	XAIE_EVENT_LOCK_SEL2_ACQ_GE_MEM,
	XAIE_EVENT_LOCK_SEL2_EQUAL_TO_VALUE_MEM,
	XAIE_EVENT_LOCK_SEL3_ACQ_EQ_MEM,
	XAIE_EVENT_LOCK_SEL3_ACQ_GE_MEM,
	XAIE_EVENT_LOCK_SEL3_EQUAL_TO_VALUE_MEM,
	XAIE_EVENT_LOCK_SEL4_ACQ_EQ_MEM,
	XAIE_EVENT_LOCK_SEL4_ACQ_GE_MEM,
	XAIE_EVENT_LOCK_SEL4_EQUAL_TO_VALUE_MEM,
	XAIE_EVENT_LOCK_SEL5_ACQ_EQ_MEM,
	XAIE_EVENT_LOCK_SEL5_ACQ_GE_MEM,
	XAIE_EVENT_LOCK_SEL5_EQUAL_TO_VALUE_MEM,
	XAIE_EVENT_LOCK_SEL6_ACQ_EQ_MEM,
	XAIE_EVENT_LOCK_SEL6_ACQ_GE_MEM,
	XAIE_EVENT_LOCK_SEL6_EQUAL_TO_VALUE_MEM,
	XAIE_EVENT_LOCK_SEL7_ACQ_EQ_MEM,
	XAIE_EVENT_LOCK_SEL7_ACQ_GE_MEM,
	XAIE_EVENT_LOCK_SEL7_EQUAL_TO_VALUE_MEM,
	XAIE_EVENT_LOCK_ERROR_MEM,
	XAIE_EVENT_DMA_TASK_TOKEN_STALL_MEM,

	/* All PL/Noc module events */
	XAIE_EVENT_NONE_PL = 2000U,
	XAIE_EVENT_TRUE_PL,
	XAIE_EVENT_GROUP_0_PL,
	XAIE_EVENT_TIMER_SYNC_PL,
	XAIE_EVENT_TIMER_VALUE_REACHED_PL,
	XAIE_EVENT_PERF_CNT_0_PL,
	XAIE_EVENT_PERF_CNT_1_PL,
	XAIE_EVENT_COMBO_EVENT_0_PL,
	XAIE_EVENT_COMBO_EVENT_1_PL,
	XAIE_EVENT_COMBO_EVENT_2_PL,
	XAIE_EVENT_COMBO_EVENT_3_PL,
	XAIE_EVENT_GROUP_DMA_ACTIVITY_PL,
	XAIE_EVENT_DMA_S2MM_0_START_BD_PL,
	XAIE_EVENT_DMA_S2MM_1_START_BD_PL,
	XAIE_EVENT_DMA_MM2S_0_START_BD_PL,
	XAIE_EVENT_DMA_MM2S_1_START_BD_PL,
	XAIE_EVENT_DMA_S2MM_0_FINISHED_BD_PL,
	XAIE_EVENT_DMA_S2MM_1_FINISHED_BD_PL,
	XAIE_EVENT_DMA_MM2S_0_FINISHED_BD_PL,
	XAIE_EVENT_DMA_MM2S_1_FINISHED_BD_PL,
	XAIE_EVENT_DMA_S2MM_0_GO_TO_IDLE_PL,
	XAIE_EVENT_DMA_S2MM_1_GO_TO_IDLE_PL,
	XAIE_EVENT_DMA_MM2S_0_GO_TO_IDLE_PL,
	XAIE_EVENT_DMA_MM2S_1_GO_TO_IDLE_PL,
	XAIE_EVENT_DMA_S2MM_0_STALLED_LOCK_ACQUIRE_PL,
	XAIE_EVENT_DMA_S2MM_1_STALLED_LOCK_ACQUIRE_PL,
	XAIE_EVENT_DMA_MM2S_0_STALLED_LOCK_ACQUIRE_PL,
	XAIE_EVENT_DMA_MM2S_1_STALLED_LOCK_ACQUIRE_PL,
	XAIE_EVENT_GROUP_LOCK_PL,
	XAIE_EVENT_LOCK_0_ACQUIRED_PL,
	XAIE_EVENT_LOCK_0_RELEASED_PL,
	XAIE_EVENT_LOCK_1_ACQUIRED_PL,
	XAIE_EVENT_LOCK_1_RELEASED_PL,
	XAIE_EVENT_LOCK_2_ACQUIRED_PL,
	XAIE_EVENT_LOCK_2_RELEASED_PL,
	XAIE_EVENT_LOCK_3_ACQUIRED_PL,
	XAIE_EVENT_LOCK_3_RELEASED_PL,
	XAIE_EVENT_LOCK_4_ACQUIRED_PL,
	XAIE_EVENT_LOCK_4_RELEASED_PL,
	XAIE_EVENT_LOCK_5_ACQUIRED_PL,
	XAIE_EVENT_LOCK_5_RELEASED_PL,
	XAIE_EVENT_LOCK_6_ACQUIRED_PL,
	XAIE_EVENT_LOCK_6_RELEASED_PL,
	XAIE_EVENT_LOCK_7_ACQUIRED_PL,
	XAIE_EVENT_LOCK_7_RELEASED_PL,
	XAIE_EVENT_LOCK_8_ACQUIRED_PL,
	XAIE_EVENT_LOCK_8_RELEASED_PL,
	XAIE_EVENT_LOCK_9_ACQUIRED_PL,
	XAIE_EVENT_LOCK_9_RELEASED_PL,
	XAIE_EVENT_LOCK_10_ACQUIRED_PL,
	XAIE_EVENT_LOCK_10_RELEASED_PL,
	XAIE_EVENT_LOCK_11_ACQUIRED_PL,
	XAIE_EVENT_LOCK_11_RELEASED_PL,
	XAIE_EVENT_LOCK_12_ACQUIRED_PL,
	XAIE_EVENT_LOCK_12_RELEASED_PL,
	XAIE_EVENT_LOCK_13_ACQUIRED_PL,
	XAIE_EVENT_LOCK_13_RELEASED_PL,
	XAIE_EVENT_LOCK_14_ACQUIRED_PL,
	XAIE_EVENT_LOCK_14_RELEASED_PL,
	XAIE_EVENT_LOCK_15_ACQUIRED_PL,
	XAIE_EVENT_LOCK_15_RELEASED_PL,
	XAIE_EVENT_GROUP_ERRORS_PL,
	XAIE_EVENT_AXI_MM_SLAVE_TILE_ERROR_PL,
	XAIE_EVENT_CONTROL_PKT_ERROR_PL,
	XAIE_EVENT_AXI_MM_DECODE_NSU_ERROR_PL,
	XAIE_EVENT_AXI_MM_SLAVE_NSU_ERROR_PL,
	XAIE_EVENT_AXI_MM_UNSUPPORTED_TRAFFIC_PL,
	XAIE_EVENT_AXI_MM_UNSECURE_ACCESS_IN_SECURE_MODE_PL,
	XAIE_EVENT_AXI_MM_BYTE_STROBE_ERROR_PL,
	XAIE_EVENT_DMA_S2MM_0_ERROR_PL,
	XAIE_EVENT_DMA_S2MM_1_ERROR_PL,
	XAIE_EVENT_DMA_MM2S_0_ERROR_PL,
	XAIE_EVENT_DMA_MM2S_1_ERROR_PL,
	XAIE_EVENT_GROUP_STREAM_SWITCH_PL,
	XAIE_EVENT_PORT_IDLE_0_PL,
	XAIE_EVENT_PORT_RUNNING_0_PL,
	XAIE_EVENT_PORT_STALLED_0_PL,
	XAIE_EVENT_PORT_TLAST_0_PL,
	XAIE_EVENT_PORT_IDLE_1_PL,
	XAIE_EVENT_PORT_RUNNING_1_PL,
	XAIE_EVENT_PORT_STALLED_1_PL,
	XAIE_EVENT_PORT_TLAST_1_PL,
	XAIE_EVENT_PORT_IDLE_2_PL,
	XAIE_EVENT_PORT_RUNNING_2_PL,
	XAIE_EVENT_PORT_STALLED_2_PL,
	XAIE_EVENT_PORT_TLAST_2_PL,
	XAIE_EVENT_PORT_IDLE_3_PL,
	XAIE_EVENT_PORT_RUNNING_3_PL,
	XAIE_EVENT_PORT_STALLED_3_PL,
	XAIE_EVENT_PORT_TLAST_3_PL,
	XAIE_EVENT_PORT_IDLE_4_PL,
	XAIE_EVENT_PORT_RUNNING_4_PL,
	XAIE_EVENT_PORT_STALLED_4_PL,
	XAIE_EVENT_PORT_TLAST_4_PL,
	XAIE_EVENT_PORT_IDLE_5_PL,
	XAIE_EVENT_PORT_RUNNING_5_PL,
	XAIE_EVENT_PORT_STALLED_5_PL,
	XAIE_EVENT_PORT_TLAST_5_PL,
	XAIE_EVENT_PORT_IDLE_6_PL,
	XAIE_EVENT_PORT_RUNNING_6_PL,
	XAIE_EVENT_PORT_STALLED_6_PL,
	XAIE_EVENT_PORT_TLAST_6_PL,
	XAIE_EVENT_PORT_IDLE_7_PL,
	XAIE_EVENT_PORT_RUNNING_7_PL,
	XAIE_EVENT_PORT_STALLED_7_PL,
	XAIE_EVENT_PORT_TLAST_7_PL,
	XAIE_EVENT_GROUP_BROADCAST_A_PL,
	XAIE_EVENT_BROADCAST_A_0_PL,
	XAIE_EVENT_BROADCAST_A_1_PL,
	XAIE_EVENT_BROADCAST_A_2_PL,
	XAIE_EVENT_BROADCAST_A_3_PL,
	XAIE_EVENT_BROADCAST_A_4_PL,
	XAIE_EVENT_BROADCAST_A_5_PL,
	XAIE_EVENT_BROADCAST_A_6_PL,
	XAIE_EVENT_BROADCAST_A_7_PL,
	XAIE_EVENT_BROADCAST_A_8_PL,
	XAIE_EVENT_BROADCAST_A_9_PL,
	XAIE_EVENT_BROADCAST_A_10_PL,
	XAIE_EVENT_BROADCAST_A_11_PL,
	XAIE_EVENT_BROADCAST_A_12_PL,
	XAIE_EVENT_BROADCAST_A_13_PL,
	XAIE_EVENT_BROADCAST_A_14_PL,
	XAIE_EVENT_BROADCAST_A_15_PL,
	XAIE_EVENT_GROUP_USER_EVENT_PL,
	XAIE_EVENT_USER_EVENT_0_PL,
	XAIE_EVENT_USER_EVENT_1_PL,
	XAIE_EVENT_USER_EVENT_2_PL,
	XAIE_EVENT_USER_EVENT_3_PL,
	XAIE_EVENT_EDGE_DETECTION_EVENT_0_PL,
	XAIE_EVENT_EDGE_DETECTION_EVENT_1_PL,
	XAIE_EVENT_DMA_S2MM_0_START_TASK_PL,
	XAIE_EVENT_DMA_S2MM_1_START_TASK_PL,
	XAIE_EVENT_DMA_MM2S_0_START_TASK_PL,
	XAIE_EVENT_DMA_MM2S_1_START_TASK_PL,
	XAIE_EVENT_DMA_S2MM_0_FINISHED_TASK_PL,
	XAIE_EVENT_DMA_S2MM_1_FINISHED_TASK_PL,
	XAIE_EVENT_DMA_MM2S_0_FINISHED_TASK_PL,
	XAIE_EVENT_DMA_MM2S_1_FINISHED_TASK_PL,
	XAIE_EVENT_DMA_S2MM_0_STALLED_LOCK_PL,
	XAIE_EVENT_DMA_S2MM_1_STALLED_LOCK_PL,
	XAIE_EVENT_DMA_MM2S_0_STALLED_LOCK_PL,
	XAIE_EVENT_DMA_MM2S_1_STALLED_LOCK_PL,
	XAIE_EVENT_DMA_S2MM_0_STREAM_STARVATION_PL,
	XAIE_EVENT_DMA_S2MM_1_STREAM_STARVATION_PL,
	XAIE_EVENT_DMA_MM2S_0_STREAM_BACKPRESSURE_PL,
	XAIE_EVENT_DMA_MM2S_1_STREAM_BACKPRESSURE_PL,
	XAIE_EVENT_DMA_S2MM_0_MEMORY_BACKPRESSURE_PL,
	XAIE_EVENT_DMA_S2MM_1_MEMORY_BACKPRESSURE_PL,
	XAIE_EVENT_DMA_MM2S_0_MEMORY_STARVATION_PL,
	XAIE_EVENT_DMA_MM2S_1_MEMORY_STARVATION_PL,
	XAIE_EVENT_LOCK_0_ACQ_EQ_PL,
	XAIE_EVENT_LOCK_0_ACQ_GE_PL,
	XAIE_EVENT_LOCK_0_EQUAL_TO_VALUE_PL,
	XAIE_EVENT_LOCK_1_ACQ_EQ_PL,
	XAIE_EVENT_LOCK_1_ACQ_GE_PL,
	XAIE_EVENT_LOCK_1_EQUAL_TO_VALUE_PL,
	XAIE_EVENT_LOCK_2_ACQ_EQ_PL,
	XAIE_EVENT_LOCK_2_ACQ_GE_PL,
	XAIE_EVENT_LOCK_2_EQUAL_TO_VALUE_PL,
	XAIE_EVENT_LOCK_3_ACQ_EQ_PL,
	XAIE_EVENT_LOCK_3_ACQ_GE_PL,
	XAIE_EVENT_LOCK_3_EQUAL_TO_VALUE_PL,
	XAIE_EVENT_LOCK_4_ACQ_EQ_PL,
	XAIE_EVENT_LOCK_4_ACQ_GE_PL,
	XAIE_EVENT_LOCK_4_EQUAL_TO_VALUE_PL,
	XAIE_EVENT_LOCK_5_ACQ_EQ_PL,
	XAIE_EVENT_LOCK_5_ACQ_GE_PL,
	XAIE_EVENT_LOCK_5_EQUAL_TO_VALUE_PL,
	XAIE_EVENT_STREAM_SWITCH_PARITY_ERROR_PL,
	XAIE_EVENT_DMA_S2MM_ERROR_PL,
	XAIE_EVENT_DMA_MM2S_ERROR_PL,
	XAIE_EVENT_LOCK_ERROR_PL,
	XAIE_EVENT_DMA_TASK_TOKEN_STALL_PL,

	/* All Mem Tile events */
	XAIE_EVENT_NONE_MEM_TILE = 3000U,
	XAIE_EVENT_TRUE_MEM_TILE,
	XAIE_EVENT_GROUP_0_MEM_TILE,
	XAIE_EVENT_TIMER_SYNC_MEM_TILE,
	XAIE_EVENT_TIMER_VALUE_REACHED_MEM_TILE,
	XAIE_EVENT_PERF_CNT0_EVENT_MEM_TILE,
	XAIE_EVENT_PERF_CNT1_EVENT_MEM_TILE,
	XAIE_EVENT_PERF_CNT2_EVENT_MEM_TILE,
	XAIE_EVENT_PERF_CNT3_EVENT_MEM_TILE,
	XAIE_EVENT_COMBO_EVENT_0_MEM_TILE,
	XAIE_EVENT_COMBO_EVENT_1_MEM_TILE,
	XAIE_EVENT_COMBO_EVENT_2_MEM_TILE,
	XAIE_EVENT_COMBO_EVENT_3_MEM_TILE,
	XAIE_EVENT_EDGE_DETECTION_EVENT_0_MEM_TILE,
	XAIE_EVENT_EDGE_DETECTION_EVENT_1_MEM_TILE,
	XAIE_EVENT_GROUP_WATCHPOINT_MEM_TILE,
	XAIE_EVENT_WATCHPOINT_0_MEM_TILE,
	XAIE_EVENT_WATCHPOINT_1_MEM_TILE,
	XAIE_EVENT_WATCHPOINT_2_MEM_TILE,
	XAIE_EVENT_WATCHPOINT_3_MEM_TILE,
	XAIE_EVENT_GROUP_DMA_ACTIVITY_MEM_TILE,
	XAIE_EVENT_DMA_S2MM_SEL0_START_TASK_MEM_TILE,
	XAIE_EVENT_DMA_S2MM_SEL1_START_TASK_MEM_TILE,
	XAIE_EVENT_DMA_MM2S_SEL0_START_TASK_MEM_TILE,
	XAIE_EVENT_DMA_MM2S_SEL1_START_TASK_MEM_TILE,
	XAIE_EVENT_DMA_S2MM_SEL0_FINISHED_BD_MEM_TILE,
	XAIE_EVENT_DMA_S2MM_SEL1_FINISHED_BD_MEM_TILE,
	XAIE_EVENT_DMA_MM2S_SEL0_FINISHED_BD_MEM_TILE,
	XAIE_EVENT_DMA_MM2S_SEL1_FINISHED_BD_MEM_TILE,
	XAIE_EVENT_DMA_S2MM_SEL0_FINISHED_TASK_MEM_TILE,
	XAIE_EVENT_DMA_S2MM_SEL1_FINISHED_TASK_MEM_TILE,
	XAIE_EVENT_DMA_MM2S_SEL0_FINISHED_TASK_MEM_TILE,
	XAIE_EVENT_DMA_MM2S_SEL1_FINISHED_TASK_MEM_TILE,
	XAIE_EVENT_DMA_S2MM_SEL0_STALLED_LOCK_ACQUIRE_MEM_TILE,
	XAIE_EVENT_DMA_S2MM_SEL1_STALLED_LOCK_ACQUIRE_MEM_TILE,
	XAIE_EVENT_DMA_MM2S_SEL0_STALLED_LOCK_ACQUIRE_MEM_TILE,
	XAIE_EVENT_DMA_MM2S_SEL1_STALLED_LOCK_ACQUIRE_MEM_TILE,
	XAIE_EVENT_DMA_S2MM_SEL0_STREAM_STARVATION_MEM_TILE,
	XAIE_EVENT_DMA_S2MM_SEL1_STREAM_STARVATION_MEM_TILE,
	XAIE_EVENT_DMA_MM2S_SEL0_STREAM_BACKPRESSURE_MEM_TILE,
	XAIE_EVENT_DMA_MM2S_SEL1_STREAM_BACKPRESSURE_MEM_TILE,
	XAIE_EVENT_DMA_S2MM_SEL0_MEMORY_BACKPRESSURE_MEM_TILE,
	XAIE_EVENT_DMA_S2MM_SEL1_MEMORY_BACKPRESSURE_MEM_TILE,
	XAIE_EVENT_DMA_MM2S_SEL0_MEMORY_STARVATION_MEM_TILE,
	XAIE_EVENT_DMA_MM2S_SEL1_MEMORY_STARVATION_MEM_TILE,
	XAIE_EVENT_GROUP_LOCK_MEM_TILE,
	XAIE_EVENT_LOCK_SEL0_ACQ_EQ_MEM_TILE,
	XAIE_EVENT_LOCK_SEL0_ACQ_GE_MEM_TILE,
	XAIE_EVENT_LOCK_SEL0_REL_MEM_TILE,
	XAIE_EVENT_LOCK_SEL0_EQUAL_TO_VALUE_MEM_TILE,
	XAIE_EVENT_LOCK_SEL1_ACQ_EQ_MEM_TILE,
	XAIE_EVENT_LOCK_SEL1_ACQ_GE_MEM_TILE,
	XAIE_EVENT_LOCK_SEL1_REL_MEM_TILE,
	XAIE_EVENT_LOCK_SEL1_EQUAL_TO_VALUE_MEM_TILE,
	XAIE_EVENT_LOCK_SEL2_ACQ_EQ_MEM_TILE,
	XAIE_EVENT_LOCK_SEL2_ACQ_GE_MEM_TILE,
	XAIE_EVENT_LOCK_SEL2_REL_MEM_TILE,
	XAIE_EVENT_LOCK_SEL2_EQUAL_TO_VALUE_MEM_TILE,
	XAIE_EVENT_LOCK_SEL3_ACQ_EQ_MEM_TILE,
	XAIE_EVENT_LOCK_SEL3_ACQ_GE_MEM_TILE,
	XAIE_EVENT_LOCK_SEL3_REL_MEM_TILE,
	XAIE_EVENT_LOCK_SEL3_EQUAL_TO_VALUE_MEM_TILE,
	XAIE_EVENT_LOCK_SEL4_ACQ_EQ_MEM_TILE,
	XAIE_EVENT_LOCK_SEL4_ACQ_GE_MEM_TILE,
	XAIE_EVENT_LOCK_SEL4_REL_MEM_TILE,
	XAIE_EVENT_LOCK_SEL4_EQUAL_TO_VALUE_MEM_TILE,
	XAIE_EVENT_LOCK_SEL5_ACQ_EQ_MEM_TILE,
	XAIE_EVENT_LOCK_SEL5_ACQ_GE_MEM_TILE,
	XAIE_EVENT_LOCK_SEL5_REL_MEM_TILE,
	XAIE_EVENT_LOCK_SEL5_EQUAL_TO_VALUE_MEM_TILE,
	XAIE_EVENT_LOCK_SEL6_ACQ_EQ_MEM_TILE,
	XAIE_EVENT_LOCK_SEL6_ACQ_GE_MEM_TILE,
	XAIE_EVENT_LOCK_SEL6_REL_MEM_TILE,
	XAIE_EVENT_LOCK_SEL6_EQUAL_TO_VALUE_MEM_TILE,
	XAIE_EVENT_LOCK_SEL7_ACQ_EQ_MEM_TILE,
	XAIE_EVENT_LOCK_SEL7_ACQ_GE_MEM_TILE,
	XAIE_EVENT_LOCK_SEL7_REL_MEM_TILE,
	XAIE_EVENT_LOCK_SEL7_EQUAL_TO_VALUE_MEM_TILE,
	XAIE_EVENT_GROUP_STREAM_SWITCH_MEM_TILE,
	XAIE_EVENT_PORT_IDLE_0_MEM_TILE,
	XAIE_EVENT_PORT_RUNNING_0_MEM_TILE,
	XAIE_EVENT_PORT_STALLED_0_MEM_TILE,
	XAIE_EVENT_PORT_TLAST_0_MEM_TILE,
	XAIE_EVENT_PORT_IDLE_1_MEM_TILE,
	XAIE_EVENT_PORT_RUNNING_1_MEM_TILE,
	XAIE_EVENT_PORT_STALLED_1_MEM_TILE,
	XAIE_EVENT_PORT_TLAST_1_MEM_TILE,
	XAIE_EVENT_PORT_IDLE_2_MEM_TILE,
	XAIE_EVENT_PORT_RUNNING_2_MEM_TILE,
	XAIE_EVENT_PORT_STALLED_2_MEM_TILE,
	XAIE_EVENT_PORT_TLAST_2_MEM_TILE,
	XAIE_EVENT_PORT_IDLE_3_MEM_TILE,
	XAIE_EVENT_PORT_RUNNING_3_MEM_TILE,
	XAIE_EVENT_PORT_STALLED_3_MEM_TILE,
	XAIE_EVENT_PORT_TLAST_3_MEM_TILE,
	XAIE_EVENT_PORT_IDLE_4_MEM_TILE,
	XAIE_EVENT_PORT_RUNNING_4_MEM_TILE,
	XAIE_EVENT_PORT_STALLED_4_MEM_TILE,
	XAIE_EVENT_PORT_TLAST_4_MEM_TILE,
	XAIE_EVENT_PORT_IDLE_5_MEM_TILE,
	XAIE_EVENT_PORT_RUNNING_5_MEM_TILE,
	XAIE_EVENT_PORT_STALLED_5_MEM_TILE,
	XAIE_EVENT_PORT_TLAST_5_MEM_TILE,
	XAIE_EVENT_PORT_IDLE_6_MEM_TILE,
	XAIE_EVENT_PORT_RUNNING_6_MEM_TILE,
	XAIE_EVENT_PORT_STALLED_6_MEM_TILE,
	XAIE_EVENT_PORT_TLAST_6_MEM_TILE,
	XAIE_EVENT_PORT_IDLE_7_MEM_TILE,
	XAIE_EVENT_PORT_RUNNING_7_MEM_TILE,
	XAIE_EVENT_PORT_STALLED_7_MEM_TILE,
	XAIE_EVENT_PORT_TLAST_7_MEM_TILE,
	XAIE_EVENT_GROUP_MEMORY_CONFLICT_MEM_TILE,
	XAIE_EVENT_CONFLICT_DM_BANK_0_MEM_TILE,
	XAIE_EVENT_CONFLICT_DM_BANK_1_MEM_TILE,
	XAIE_EVENT_CONFLICT_DM_BANK_2_MEM_TILE,
	XAIE_EVENT_CONFLICT_DM_BANK_3_MEM_TILE,
	XAIE_EVENT_CONFLICT_DM_BANK_4_MEM_TILE,
	XAIE_EVENT_CONFLICT_DM_BANK_5_MEM_TILE,
	XAIE_EVENT_CONFLICT_DM_BANK_6_MEM_TILE,
	XAIE_EVENT_CONFLICT_DM_BANK_7_MEM_TILE,
	XAIE_EVENT_CONFLICT_DM_BANK_8_MEM_TILE,
	XAIE_EVENT_CONFLICT_DM_BANK_9_MEM_TILE,
	XAIE_EVENT_CONFLICT_DM_BANK_10_MEM_TILE,
	XAIE_EVENT_CONFLICT_DM_BANK_11_MEM_TILE,
	XAIE_EVENT_CONFLICT_DM_BANK_12_MEM_TILE,
	XAIE_EVENT_CONFLICT_DM_BANK_13_MEM_TILE,
	XAIE_EVENT_CONFLICT_DM_BANK_14_MEM_TILE,
	XAIE_EVENT_CONFLICT_DM_BANK_15_MEM_TILE,
	XAIE_EVENT_GROUP_ERRORS_MEM_TILE,
	XAIE_EVENT_DM_ECC_ERROR_SCRUB_CORRECTED_MEM_TILE,
	XAIE_EVENT_DM_ECC_ERROR_SCRUB_2BIT_MEM_TILE,
	XAIE_EVENT_DM_ECC_ERROR_1BIT_MEM_TILE,
	XAIE_EVENT_DM_ECC_ERROR_2BIT_MEM_TILE,
	XAIE_EVENT_DMA_S2MM_ERROR_MEM_TILE,
	XAIE_EVENT_DMA_MM2S_ERROR_MEM_TILE,
	XAIE_EVENT_STREAM_SWITCH_PARITY_ERROR_MEM_TILE,
	XAIE_EVENT_STREAM_PKT_ERROR_MEM_TILE,
	XAIE_EVENT_CONTROL_PKT_ERROR_MEM_TILE,
	XAIE_EVENT_AXI_MM_SLAVE_ERROR_MEM_TILE,
	XAIE_EVENT_LOCK_ERROR_MEM_TILE,
	XAIE_EVENT_DMA_TASK_TOKEN_STALL_MEM_TILE,
	XAIE_EVENT_GROUP_BROADCAST_MEM_TILE,
	XAIE_EVENT_BROADCAST_0_MEM_TILE,
	XAIE_EVENT_BROADCAST_1_MEM_TILE,
	XAIE_EVENT_BROADCAST_2_MEM_TILE,
	XAIE_EVENT_BROADCAST_3_MEM_TILE,
	XAIE_EVENT_BROADCAST_4_MEM_TILE,
	XAIE_EVENT_BROADCAST_5_MEM_TILE,
	XAIE_EVENT_BROADCAST_6_MEM_TILE,
	XAIE_EVENT_BROADCAST_7_MEM_TILE,
	XAIE_EVENT_BROADCAST_8_MEM_TILE,
	XAIE_EVENT_BROADCAST_9_MEM_TILE,
	XAIE_EVENT_BROADCAST_10_MEM_TILE,
	XAIE_EVENT_BROADCAST_11_MEM_TILE,
	XAIE_EVENT_BROADCAST_12_MEM_TILE,
	XAIE_EVENT_BROADCAST_13_MEM_TILE,
	XAIE_EVENT_BROADCAST_14_MEM_TILE,
	XAIE_EVENT_BROADCAST_15_MEM_TILE,
	XAIE_EVENT_GROUP_USER_EVENT_MEM_TILE,
	XAIE_EVENT_USER_EVENT_0_MEM_TILE,
	XAIE_EVENT_USER_EVENT_1_MEM_TILE,
} XAie_Events;

/* Enum to capture stream switch port interface */
typedef enum {
	XAIE_STRMSW_SLAVE,
	XAIE_STRMSW_MASTER,
} XAie_StrmPortIntf;

/* Enum to capture different event combo operations */
typedef enum {
	XAIE_EVENT_COMBO_E1_AND_E2,
	XAIE_EVENT_COMBO_E1_AND_NOTE2,
	XAIE_EVENT_COMBO_E1_OR_E2,
	XAIE_EVENT_COMBO_E1_OR_NOTE2
} XAie_EventComboOps;

/* Enum to capture different event combo configs */
typedef enum {
	XAIE_EVENT_COMBO0,
	XAIE_EVENT_COMBO1,
	XAIE_EVENT_COMBO2,
} XAie_EventComboId;

/* Enum to capture event broadcast directions */
typedef enum {
	XAIE_EVENT_BROADCAST_SOUTH = 0b0001U,
	XAIE_EVENT_BROADCAST_WEST  = 0b0010U,
	XAIE_EVENT_BROADCAST_NORTH = 0b0100U,
	XAIE_EVENT_BROADCAST_EAST  = 0b1000U,
	XAIE_EVENT_BROADCAST_ALL   = 0b1111U,
} XAie_BroadcastDir;

/* Enum to capture edge event config */
typedef enum {
	XAIE_EDGE_EVENT_RISING  = 0b0001U,
	XAIE_EDGE_EVENT_FALLING = 0b0010U,
} XAie_EdgeEventTrig;

/************************** Function Prototypes  *****************************/
AieRC XAie_EventGenerate(XAie_DevInst *DevInst, XAie_LocType Loc,
		XAie_ModuleType Module, XAie_Events Event);
AieRC XAie_EventComboConfig(XAie_DevInst *DevInst, XAie_LocType Loc,
		XAie_ModuleType Module, XAie_EventComboId ComboId,
		XAie_EventComboOps Op, XAie_Events Event1, XAie_Events Event2);
AieRC XAie_EventGetComboEventBase(XAie_DevInst *DevInst, XAie_LocType Loc,
		XAie_ModuleType Module, XAie_Events *Event);
AieRC XAie_EventComboReset(XAie_DevInst *DevInst, XAie_LocType Loc,
		XAie_ModuleType Module, XAie_EventComboId ComboId);
AieRC XAie_EventSelectStrmPort(XAie_DevInst *DevInst, XAie_LocType Loc,
		u8 SelectId, XAie_StrmPortIntf PortIntf, StrmSwPortType Port,
		u8 PortNum);
AieRC XAie_EventSelectStrmPortReset(XAie_DevInst *DevInst, XAie_LocType Loc,
		u8 SelectId);
AieRC XAie_EventSelectDmaChannel(XAie_DevInst *DevInst, XAie_LocType Loc,
		u8 SelectId, XAie_DmaDirection DmaDir, u8 ChannelNum);
AieRC XAie_EventSelectDmaChannelReset(XAie_DevInst *DevInst, XAie_LocType Loc,
		u8 SelectId, XAie_DmaDirection DmaDir);
AieRC XAie_EventGetIdlePortEventBase(XAie_DevInst *DevInst, XAie_LocType Loc,
		XAie_ModuleType Module, XAie_Events *Event);
AieRC XAie_EventBroadcast(XAie_DevInst *DevInst, XAie_LocType Loc,
		XAie_ModuleType Module, u8 BroadcastId, XAie_Events Event);
AieRC XAie_EventBroadcastReset(XAie_DevInst *DevInst, XAie_LocType Loc,
		XAie_ModuleType Module, u8 BroadcastId);
AieRC XAie_EventBroadcastBlockDir(XAie_DevInst *DevInst, XAie_LocType Loc,
		XAie_ModuleType Module, XAie_BroadcastSw Switch, u8 BroadcastId,
		u8 Dir);
AieRC XAie_EventBroadcastBlockMapDir(XAie_DevInst *DevInst, XAie_LocType Loc,
		XAie_ModuleType Module, XAie_BroadcastSw Switch,
		u32 ChannelBitMap, u8 Dir);
AieRC XAie_EventBroadcastUnblockDir(XAie_DevInst *DevInst, XAie_LocType Loc,
		XAie_ModuleType Module, XAie_BroadcastSw Switch, u8 BroadcastId,
		u8 Dir);
AieRC XAie_EventGroupControl(XAie_DevInst *DevInst, XAie_LocType Loc,
		XAie_ModuleType Module, XAie_Events GroupEvent, u32 GroupBitMap);
AieRC XAie_EventGroupReset(XAie_DevInst *DevInst, XAie_LocType Loc,
		XAie_ModuleType Module, XAie_Events GroupEvent);
AieRC XAie_EventEdgeControl(XAie_DevInst *DevInst, XAie_LocType Loc,
		XAie_ModuleType Module, u8 SelectId, XAie_Events Event,
		u8 Trigger);
AieRC XAie_EventPCEnable(XAie_DevInst *DevInst, XAie_LocType Loc,
		u8 PCEventId, u16 PCAddr);
AieRC XAie_EventPCDisable(XAie_DevInst *DevInst, XAie_LocType Loc,
		u8 PCEventId);
AieRC XAie_EventPCReset(XAie_DevInst *DevInst, XAie_LocType Loc,
		u8 PCEventId);
AieRC XAie_EventPhysicalToLogicalConv(XAie_DevInst *DevInst, XAie_LocType Loc,
		XAie_ModuleType Module, u8 HwEvent, XAie_Events *EnumEvent);
AieRC XAie_EventLogicalToPhysicalConv(XAie_DevInst *DevInst, XAie_LocType Loc,
		XAie_ModuleType Module, XAie_Events Event, u8 *HwEvent);
AieRC XAie_EventReadStatus(XAie_DevInst *DevInst, XAie_LocType Loc,
		XAie_ModuleType Module, XAie_Events Events, u8 *Status);
AieRC XAie_EventGetUserEventBase(XAie_DevInst *DevInst, XAie_LocType Loc,
	XAie_ModuleType Module, XAie_Events *Event);
AieRC XAie_EventRegStatus(XAie_DevInst *DevInst, XAie_LocType Loc,
		XAie_ModuleType Module, u8 EventRegNo, u32 *Status);

#endif		/* end of protection macro */
