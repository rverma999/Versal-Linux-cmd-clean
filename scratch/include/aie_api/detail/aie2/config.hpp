// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
/*  (c) Copyright 2020 - 2022 Xilinx, Inc. All rights reserved.

    This file contains confidential and proprietary information
    of Xilinx, Inc. and is protected under U.S. and
    international copyright and other intellectual property
    laws.

    DISCLAIMER
    This disclaimer is not a license and does not grant any
    rights to the materials distributed herewith. Except as
    otherwise provided in a valid license issued to you by
    Xilinx, and to the maximum extent permitted by applicable
    law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
    WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
    AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
    BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
    INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
    (2) Xilinx shall not be liable (whether in contract or tort,
    including negligence, or under any other theory of
    liability) for any loss or damage of any kind or nature
    related to, arising under or in connection with these
    materials, including for any direct, or any indirect,
    special, incidental, or consequential loss or damage
    (including loss of data, profits, goodwill, or any type of
    loss or damage suffered as a result of any action brought
    by a third party) even if such damage or loss was
    reasonably foreseeable or Xilinx had been advised of the
    possibility of the same.

    CRITICAL APPLICATIONS
    Xilinx products are not designed or intended to be fail-
    safe, or for use in any application requiring fail-safe
    performance, such as life-support or safety devices or
    systems, Class III medical devices, nuclear facilities,
    applications related to the deployment of airbags, or any
    other applications that could lead to death, personal
    injury, or severe property or environmental damage
    (individually and collectively, "Critical
    Applications"). Customer assumes the sole risk and
    liability of any use of Xilinx products in Critical
    Applications, subject only to applicable laws and
    regulations governing limitations on product liability.

    THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
    PART OF THIS FILE AT ALL TIMES.                       */


#ifndef __AIE_API_DETAIL_AIE2_CONFIG__HPP__
#define __AIE_API_DETAIL_AIE2_CONFIG__HPP__

#define AIE_API_PLATFORM_VERSION 200
#define AIE_API_ML_VERSION       200
#define AIE_API_MATH_VERSION     0

#define __AIE_API_REGISTER_ATTR_DEFINED__           0

#define __AIE_API_SCALAR_TYPES_CONSTEXPR__          (__AIE_MODEL_VERSION__ >= 2500)

#define __AIE_API_COMPR_CONST_PTR__                 0

#define __AIE_API_MUL_CONJUGATE_INTRINSICS__        (__AIE_MODEL_VERSION__ >= 3000)

#define __AIE_API_MUL_CONJUGATE_32BIT_INTRINSICS__  (__AIE_MODEL_VERSION__ >= 10200)

#define __AIE_API_SHIFT_BYTES__                     (__AIE_MODEL_VERSION__ >= 3000)

#define __AIE_API_FP32_EMULATION__                  (__AIE_MODEL_VERSION__ >= 3000)

#define __AIE_API_TERM_NEG_COMPLEX_DEFINES__        (__AIE_MODEL_VERSION__ >= 10200)

#define __AIE_API_128_BIT_INSERT_CONCAT__           (__AIE_MODEL_VERSION__ >= 2700)

#define __AIE_API_32ELEM_FLOAT_SRS_UPS__            (__AIE_MODEL_VERSION__ >= 10300)

#define __AIE_API_COMPOUND_DM_RESOURCE__            (__AIE_MODEL_VERSION__ >= 10300)

#define __AIE_API_CONSTEXPR_BFLOAT16__              0

#define __AIE_API_COMPLEX_FP32_EMULATION__          (__AIE_MODEL_VERSION__ >= 10300)

#define __AIE_API_NATIVE_FIFO__                     1

#define __AIE_API_SUPPORTED_FRIEND_CONCEPTS__       (__AIE_MODEL_VERSION__ <= 10300)

#define __AIE_API_EMULATED_FP32_ZEROIZATION__       (__AIE_MODEL_VERSION__ >= 10400)

#define __AIE_API_CFP_TO_FP_CONVERSIONS__           (__AIE_MODEL_VERSION__ >= 10400)

#endif
