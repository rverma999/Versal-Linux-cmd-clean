/******************************************************************************
* Copyright (C) 2020 - 2022 Xilinx, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/


/*****************************************************************************/
/**
* @file xaie_io.c
* @{
*
* This file contains the data structures and routines for low level IO
* operations.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who     Date     Changes
* ----- ------  -------- -----------------------------------------------------
* 1.0   Tejus   06/09/2020 Initial creation.
* 1.1   Tejus   06/10/2020 Add helper function to get backend pointer.
* </pre>
*
******************************************************************************/
#ifndef XAIE_IO_H
#define XAIE_IO_H

/***************************** Include Files *********************************/
#include "xaiegbl.h"
/***************************** Macro Definitions *****************************/
#define XAIE_RSC_MGR_CONTIG_FLAG	0x1U
/****************************** Type Definitions *****************************/

/*
 * Typedef for enum to capture backend function code
 */
typedef enum {
	XAIE_BACKEND_OP_NPIWR32,
	XAIE_BACKEND_OP_NPIMASKPOLL32,
	XAIE_BACKEND_OP_RST_PART,
	XAIE_BACKEND_OP_ASSERT_SHIMRST,
	XAIE_BACKEND_OP_SET_PROTREG,
	XAIE_BACKEND_OP_CONFIG_SHIMDMABD,
	XAIE_BACKEND_OP_REQUEST_TILES,
	XAIE_BACKEND_OP_RELEASE_TILES,
	XAIE_BACKEND_OP_PARTITION_INITIALIZE,
	XAIE_BACKEND_OP_PARTITION_TEARDOWN,
	XAIE_BACKEND_OP_PARTITION_CLEAR_CONTEXT,
	XAIE_BACKEND_OP_UPDATE_NPI_ADDR,
	XAIE_BACKEND_OP_SET_COLUMN_CLOCK,
	XAIE_BACKEND_OP_PERFORMANCE_UTILIZATION,
} XAie_BackendOpCode;

/*
 * Typedef for structure for NPI write 32bit structure
 */
typedef struct XAie_BackendNpiWrReq {
	u32 NpiRegOff;
	u32 Val;
} XAie_BackendNpiWrReq;

/*
 * Typedef for structure for NPI Mask Poll structure
 */
typedef struct XAie_BackendNpiMaskPollReq {
	u32 NpiRegOff;
	u32 Mask;
	u32 Val;
	u32 TimeOutUs;
} XAie_BackendNpiMaskPollReq;

/*
 * Typedef for structure for tiles array
 */
typedef struct XAie_BackendTilesArray {
	XAie_LocType *Locs;
	u32 NumTiles;
} XAie_BackendTilesArray;

/*
 * Typedef for structure for columns
 */
typedef struct XAie_BackendColumnReq {
	u32 StartCol;
	u32 NumCols;
	u8 Enable;
} XAie_BackendColumnReq;

/* Typedef to capture shimdma Bd arguments */
typedef struct XAie_ShimDmaBdArgs {
	XAie_MemInst *MemInst;
	u8 NumBdWords;
	u32 *BdWords;
	XAie_LocType Loc;
	u64 VAddr;
	u32 BdNum;
	u64 Addr;
} XAie_ShimDmaBdArgs;

/*
 * Typdef to capture all the backend IO operations
 * Init        : Backend specific initialization function. Init should attach
 *               private data to DevInst which is later used by other ops.
 * Finish      : Backend specific IO finish function. Backend specific cleanup
 *               should be part of this function.
 * Write32     : IO operation to write 32-bit data.
 * Read32      : IO operation to read 32-bit data.
 * MaskWrite32 : IO operation to write masked 32-bit data.
 * MaskPoll    : IO operation to mask poll an address for a value.
 * BlockWrite32: IO operation to write a block of data at 32-bit granularity.
 * BlockSet32  : IO operation to initialize a chunk of aie address space with a
 *               a specified value at 32-bit granularity.
 * CmdWrite32  : This IO operation is required only in simulation mode. Other
 *               backends should have a no-op.
 * RunOp       : Run operation specified by the operation code
 * MemAllocate : Backend operation to allocate memory for the user. In addition
 *		 to that, the operation is expected to allocate memory for
 *		 MemInst and populate Size, virtual address and device address..
 * MemFree     : Backend operation to free allocated memory, MemInst allocated
 *		 by the MemAllocate api.
 * MemSyncForCPU: Backend operation to prepare memory for CPU access.
 * MemSyncForDev: Backend operation to prepare memory for Device access.
 * MemAttach    : Backend operation to attach memory to AI engine device.
 * MemDetach    : Backend operation to detach memory from AI engine device
 * GetTid	: Backend operation to get unique thread id.
 * GetPartFd   : Backend operation to get unique partition fd.
 * SubmitTxn	: Backend operation to submit transaction.
 */
typedef struct XAie_BackendOps {
	AieRC (*Init)(XAie_DevInst *DevInst);
	AieRC (*Finish)(void *IOInst);
	AieRC (*Write32)(void *IOInst, u64 RegOff, u32 Value);
	AieRC (*Read32)(void *IOInst,  u64 RegOff, u32 *Data);
	AieRC (*MaskWrite32)(void *IOInst, u64 RegOff, u32 Mask, u32 Value);
	AieRC (*MaskPoll)(void *IOInst, u64 RegOff, u32 Mask, u32 Value,
			u32 TimeOutUs);
	AieRC (*BlockWrite32)(void *IOInst, u64 RegOff, const u32 *Data, u32 Size);
	AieRC (*BlockSet32)(void *IOInst, u64 RegOff, u32 Data, u32 Size);
	AieRC (*CmdWrite)(void *IOInst, u8 Col, u8 Row, u8 Command, u32 CmdWd0,
			u32 CmdWd1, const char *CmdStr);
	AieRC (*RunOp)(void *IOInst, XAie_DevInst *DevInst,
		     XAie_BackendOpCode Op, void *Arg);
	XAie_MemInst* (*MemAllocate)(XAie_DevInst *DevInst, u64 Size,
			XAie_MemCacheProp Cache);
	AieRC (*MemFree)(XAie_MemInst *MemInst);
	AieRC (*MemSyncForCPU)(XAie_MemInst *MemInst);
	AieRC (*MemSyncForDev)(XAie_MemInst *MemInst);
	AieRC (*MemAttach)(XAie_MemInst *MemInst, u64 MemHandle);
	AieRC (*MemDetach)(XAie_MemInst *MemInst);
	u64 (*GetTid)(void);
	int (*GetPartFd)(void *IOInst);
	AieRC (*SubmitTxn)(void *IOInst, XAie_TxnInst *TxnInst);
	void* (*GetShimDmaBdConfig)(XAie_ShimDmaBdArgs *Args);
} XAie_BackendOps;

/* Typedef to capture all backend information */
struct XAie_Backend {
	XAie_BackendType Type;
	XAie_BackendOps Ops;
};

/************************** Function Prototypes  *****************************/
AieRC XAie_IOInit(XAie_DevInst *DevInst);

#endif	/* End of protection macro */

/** @} */
