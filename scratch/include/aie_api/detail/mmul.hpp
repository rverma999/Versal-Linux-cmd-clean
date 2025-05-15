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


#pragma once

#ifndef __AIE_API_DETAIL_MMUL__HPP__
#define __AIE_API_DETAIL_MMUL__HPP__

#include "vector.hpp"
#include "accum.hpp"

/**
 * @ingroup group_mmul
 * @page group_mmul_page_supported_modes Matrix Multiplication Modes
 *
 * The following matrix multiplication shapes are supported.
 *
 * @paragraph group_mmul_page_supported_regular_modes Supported Matrix Multiplication Modes
 *
 * <table>
 * <caption>Matrix multiplication modes for real types</caption>
 * <tr><th>Arch.<th>8b x 4b<th>8b x 8b<th>16b x 8b<th>8b x 16b<th>16b x 16b<th>32b x 16b<th>16b x 32b<th>32b x 32b<th>bfloat16 x bfloat16<th>float x float
 * <tr><td style="white-space: nowrap;">
 *         AIE
 *     <td style="vertical-align:top">
 *     <td style="vertical-align:top">
 *         4x8x4<br/> 4x16x4<sup>a</sup><br/> 8x8x4<sup>a</sup><br/> 2x8x8<br/> 4x8x8<sup>a</sup><br/> 1x16x8<br/> 2x16x8<sup>a</sup><br/> 4x16x8<sup>a</sup>
 *     <td style="vertical-align:top">
 *         4x4x4<br/> 8x4x4<sup>a</sup><br/>  4x8x4<sup>a</sup><br/> 4x4x8<sup>a</sup>
 *     <td style="vertical-align:top">
 *         4x4x8<sup>a</sup><br/> 4x4x4<sup>a</sup><br/> 8x8x1<sup>ab</sup>
 *     <td style="vertical-align:top">
 *         4x4x4<sup>a</sup><br/> 2x4x8<sup>a</sup><br/> 4x4x8<sup>a</sup><br/> 4x2x8<sup>a</sup><br/> 8x8x1<sup>ab</sup>
 *     <td style="vertical-align:top">
 *         2x4x8<sup>a</sup><br/> 4x4x4<sup>a</sup><br/> 4x2x4<sup>a</sup><br/> 2x2x4<br/> 2x4x4<sup>a</sup><br/> 4x4x2<sup>a</sup><br/> 2x2x8<sup>a</sup>
 *     <td style="vertical-align:top">
 *         4x2x2<br/> 2x4x8<sup>a</sup><br/> 4x4x4<sup>a</sup>
 *     <td style="vertical-align:top">
 *         4x2x4<sup>a</sup><br/> 2x2x2<br/> 2x4x2<sup>a</sup><br/> 2x8x2<sup>a</sup><br/> 4x2x2<sup>a</sup><br/> 4x4x2<sup>a</sup><br/> 2x4x4<sup>a</sup><br/> 4x4x1<sup>a</sup>
 *     <td style="vertical-align:top">
 *     <td style="vertical-align:top">
 *         4x2x4<sup>a</sup><br/> 2x2x2<sup>a</sup><br/> 2x4x2<sup>ab</sup><br/> 2x8x2<sup>ab</sup><br/> 4x2x2<sup>a</sup><br/> 4x4x2<sup>a</sup><br/> 2x4x4<sup>a</sup><br/> 4x4x1<sup>ab</sup>
 * <tr><td style="white-space: nowrap;">
 *         AIE-ML
 *     <td style="vertical-align:top">
 *         4x16x8<br/>8x16x8<sup>a</sup><br/>4x32x8<sup>ab</sup>
 *     <td style="vertical-align:top">
 *         4x8x4<sup>ab</sup><br/> 4x16x4<sup>ab</sup><br/> 8x8x4<sup>ab</sup><br/> 2x8x8<br/> 4x8x8<br/> 8x8x8<sup>a</sup><br/> 1x16x8<sup>ab</sup><br/> 2x16x8<sup>ab</sup><br/> 4x16x8<sup>ab</sup>
 *     <td style="vertical-align:top">
 *         4x4x4<sup>ab</sup><br/> 8x4x4<sup>ab</sup><br/>  4x8x4<br/> 4x4x8 <br/> 8x4x8<sup>ab</sup><br/> 2x8x8
 *     <td style="vertical-align:top">
 *         4x4x8<sup>ab</sup><br/> 4x4x4<sup>ab</sup>
 *     <td style="vertical-align:top">
 *         4x4x4<br/> 2x4x8<br/> 4x4x8<sup>ab</sup><br/> 4x2x8<br/> 8x2x8<sup>a</sup><br/> 8x1x8<sup>ab</sup>
 *     <td style="vertical-align:top">
 *         2x4x8<br/> 4x4x8<sup>ab</sup><br/> 4x4x4<br/> 4x2x4<br/> 4x1x8<sup>ab</sup>
 *     <td style="vertical-align:top">
 *         2x4x8<br/> 4x4x4
 *     <td style="vertical-align:top">
 *         4x2x4<sup>a</sup><br/> 4x4x4<sup>ab</sup><br/> 8x2x4<sup>a</sup><br/> 4x1x8<sup>ab</sup><br/> 8x1x8<sup>ab</sup>
 *     <td style="vertical-align:top">
 *         4x8x4<br/> 8x8x4<sup>a</sup><br/> 4x16x8<sup>ab</sup>
 *     <td style="vertical-align:top">
 *         4x8x4<br/> 4x1x4<sup>b</sup><br/> 4x1x8<sup>ab</sup>
 * </table>
 *
 * <table>
 * <caption>Matrix multiplication modes for complex types (c16b/c32b/cfloat represent complex types)</caption>
 * <tr><th>Arch.<th>16b x c16b<th>16b x c32b<th>c16b x 16b<th>c16b x c16b<th>c16b x 32b
 *     <th>c16b x c32b<th>32b x c16b<th>32b x c32b<th>c32b x 16b<th>c32b x c16b
 *     <th>c32b x 32b<th>c32b x c32b
 *     <th>float x cfloat<th>cfloat x float<th>cfloat x cfloat
 * <tr><td style="white-space: nowrap;">
 *         AIE
 *     <td style="vertical-align:top">
 *         4x2x2<br/> 4x4x4<sup>a</sup><br/> 4x4x1
 *     <td style="vertical-align:top">
 *         2x4x2<sup>a</sup><br/> 2x4x4<sup>a</sup><br/> 2x8x2<sup>a</sup><br/> 4x4x2<sup>a</sup><br/> 4x4x1<sup>a</sup>
 *     <td style="vertical-align:top">
 *         2x2x4<br/> 2x2x8<sup>a</sup><br/> 2x4x4<sup>a</sup><br/> 2x4x8<sup>a</sup><br/> 4x2x4<sup>a</sup><br/> 4x4x2<sup>a</sup><br/> 4x4x4<sup>a</sup>
 *     <td style="vertical-align:top">
 *         2x2x2<br/> 2x4x2<sup>a</sup><br/> 2x8x2<sup>a</sup><br/> 2x4x4<sup>a</sup><br/> 4x2x2<sup>a</sup><br/> 4x4x2<sup>a</sup><br/> 4x2x4<sup>a</sup><br/> 4x4x1<sup>a</sup>
 *     <td style="vertical-align:top">
 *         2x2x2<br/> 2x4x2<sup>a</sup><br/> 2x8x2<sup>a</sup><br/> 2x4x4<sup>a</sup><br/> 4x2x2<sup>a</sup><br/> 4x4x2<sup>a</sup><br/> 4x2x4<sup>a</sup><br/> 4x4x1<sup>a</sup>
 *     <td style="vertical-align:top">
 *         2x2x2<sup>a</sup><br/> 2x4x2<sup>a</sup><br/> 4x2x1<sup>a</sup>
 *     <td style="vertical-align:top">
 *         2x2x2<br/> 2x4x2<sup>a</sup><br/> 2x8x2<sup>a</sup><br/> 2x4x4<sup>a</sup><br/> 4x2x2<sup>a</sup><br/> 4x4x2<sup>a</sup><br/> 4x2x4<sup>a</sup><br/> 4x4x1<sup>a</sup>
 *     <td style="vertical-align:top">
 *         2x2x2<sup>a</sup><br/> 2x4x2<sup>a</sup><br/> 4x2x1<sup>a</sup>
 *     <td style="vertical-align:top">
 *         2x4x2<sup>a</sup><br/> 2x8x2<sup>a</sup><br/> 2x4x4<sup>a</sup><br/> 4x4x2<sup>a</sup>
 *     <td style="vertical-align:top">
 *         2x2x2<sup>a</sup><br/> 2x4x2<sup>a</sup><br/> 4x4x1<sup>a</sup>
 *     <td style="vertical-align:top">
 *         1x2x2<br/> 2x2x2<sup>a</sup><br/> 2x4x2<sup>a</sup><br/> 4x4x1<sup>a</sup>
 *     <td style="vertical-align:top">
 *         1x2x2<sup>a</sup><br/> 2x2x1<sup>a</sup><br/> 2x2x1
 *     <td style="vertical-align:top">
 *         2x2x2<sup>a</sup><br/> 2x4x2<sup>a</sup><br/> 4x2x1<sup>a</sup>
 *     <td style="vertical-align:top">
 *         2x2x2<sup>a</sup><br/> 2x4x2<sup>a</sup><br/> 4x4x1<sup>a</sup><br/> 2x4x1<sup>ab</sup>
 *     <td style="vertical-align:top">
 *         2x2x2<sup>a</sup><br/> 2x2x4<sup>a</sup><br/> 2x4x2<sup>a</sup><br/> 4x2x2<sup>a</sup><br/> 4x2x1<sup>a</sup>
 * <tr><td style="white-space: nowrap;">
 *         AIE-ML
 *     <td style="vertical-align:top">
 *     <td style="vertical-align:top">
 *     <td style="vertical-align:top">
 *         2x4x8<sup>ab</sup><br/> 4x4x4<sup>ab</sup>
 *     <td style="vertical-align:top">
 *         1x4x8<sup>ab</sup><br/> 2x4x8<sup>ab</sup>
 *     <td style="vertical-align:top">
 *     <td style="vertical-align:top">
 *     <td style="vertical-align:top">
 *     <td style="vertical-align:top">
 *     <td style="vertical-align:top">
 *     <td style="vertical-align:top">
 *         1x2x4<sup>ab</sup><br/> 1x2x8<sup>ab</sup><br/> 2x2x8<sup>ab</sup><br/> 1x4x8<sup>ab</sup><br/> 2x4x8<sup>ab</sup>
 *     <td style="vertical-align:top">
 *     <td style="vertical-align:top">
 *         1x2x8<sup>ab</sup>
 *     <td style="vertical-align:top">
 *     <td style="vertical-align:top">
 *     <td style="vertical-align:top">
 * </table>
 *
 * \note
 * <sup>a</sup> - Emulated using multiple intrinsic calls.<br/>
 * <sup>b</sup> - Require additional data manipulation.<br/>
 *
 * @paragraph group_mmul_page_multidim_gemm GEMM leveraging multidimensional addressing
 *
 * \note Multi-dimensional addressing and the corresponding tensor buffer streams were introduced with AIE-ML
 *
 * Below is an example of an optimized bfloat16 GEMM kernel in which both input matrices, A and B, are addressed in the following 4D patterns:
 *
 * \image html tensor_desc/mmul.png width=50%
 *
 * It is assumed that the data for both input matrices are pre-tiled and that the tiles are laid out in column-major order in memory.
 *
 * @code
 * void gemm_bf16xbf16(bfloat16 * matA, bfloat16 * matB, bfloat16 *__restrict matC,
 *                     int rowsA, int inner, int colsB)
 * {
 *     using MMUL = aie::mmul<4, 8, 4, bfloat16, bfloat16, accauto>;
 *
 *     auto a_desc =  aie::make_tensor_descriptor<bfloat16, 32>(
 *                                                aie::tensor_dim(rowsA / 4 / 4, 4),
 *                                                aie::tensor_dim(colsB / 4 / 4, 0),
 *                                                aie::tensor_dim(inner / 8, rowsA / 4),
 *                                                aie::tensor_dim(4u, 1));
 *
 *     auto b_desc = aie::make_tensor_descriptor<bfloat16, 32>(
 *                                                aie::tensor_dim(colsB / 4 / 4, 0),
 *                                                aie::tensor_dim(colsB / 4 / 4, inner / 8 * 4),
 *                                                aie::tensor_dim(inner / 8, 1),
 *                                                aie::tensor_dim(4u, inner / 8));
 *
 *     auto c_desc = aie::make_tensor_descriptor<bfloat16, 16>(
 *                                                aie::tensor_dim(rowsA / 4 / 4, 4),
 *                                                aie::tensor_dim(colsB / 4, rowsA / 4),
 *                                                aie::tensor_dim(4u, 1));
 *
 *     auto tsA = aie::make_tensor_buffer_stream(matA, a_desc);
 *     auto tsB = aie::make_tensor_buffer_stream(matB, b_desc);
 *     auto tsC = aie::make_restrict_tensor_buffer_stream(matC, c_desc);
 *
 *     for (int j = 0; j < rowsA * colsB / (16 * 16); ++j)
 *     {
 *         MMUL C00, C01, C02, C03;
 *         MMUL C10, C11, C12, C13;
 *         MMUL C20, C21, C22, C23;
 *         MMUL C30, C31, C32, C33;
 *
 *         for (int i = 0; i < inner / 8; ++i)
 *         {
 *             // The following pop calls are required to access the inner leaf stream.
 *             // As tsA and tsB are 4D streams, the returned inner stream will be 1D.
 *             //
 *             // Note that these calls advance the outer stream
 *             auto tsA_inner = tsA.pop();
 *             auto tsB_inner = tsB.pop();
 *
 *             aie::vector<bfloat16,32> Xbuff0, Xbuff1, Xbuff2, Xbuff3;
 *             tsA_inner >> Xbuff0 >> Xbuff1 >> Xbuff2 >> Xbuff3;
 *
 *             aie::vector<bfloat16,32> Ybuff0, Ybuff1;
 *             tsB_inner >> Ybuff0 >> Ybuff1;
 *
 *             C00.mac(Xbuff0, Ybuff0); C01.mac(Xbuff0, Ybuff1);
 *             C10.mac(Xbuff1, Ybuff0); C11.mac(Xbuff1, Ybuff1);
 *             C20.mac(Xbuff2, Ybuff0); C21.mac(Xbuff2, Ybuff1);
 *             C30.mac(Xbuff3, Ybuff0); C31.mac(Xbuff3, Ybuff1);
 *
 *             tsB_inner >> Ybuff0 >> Ybuff1;
 *
 *             C02.mac(Xbuff0, Ybuff0); C03.mac(Xbuff0, Ybuff1);
 *             C12.mac(Xbuff1, Ybuff0); C13.mac(Xbuff1, Ybuff1);
 *             C22.mac(Xbuff2, Ybuff0); C23.mac(Xbuff2, Ybuff1);
 *             C32.mac(Xbuff3, Ybuff0); C33.mac(Xbuff3, Ybuff1);
 *         }
 *
 *         tsC << C00.to_vector<bfloat16>() << C10.to_vector<bfloat16>() << C20.to_vector<bfloat16>() << C30.to_vector<bfloat16>()
 *             << C01.to_vector<bfloat16>() << C11.to_vector<bfloat16>() << C21.to_vector<bfloat16>() << C31.to_vector<bfloat16>()
 *             << C02.to_vector<bfloat16>() << C12.to_vector<bfloat16>() << C22.to_vector<bfloat16>() << C32.to_vector<bfloat16>()
 *             << C03.to_vector<bfloat16>() << C13.to_vector<bfloat16>() << C23.to_vector<bfloat16>() << C33.to_vector<bfloat16>();
 *     }
 * }
 * @endcode
 *
 * @paragraph group_mmul_page_supported_sparse_modes Supported Sparse Matrix Multiplication Modes
 *
 * AIE-ML introduced hardware support for sparse matrix multiplication. For an M x K x N matrix multiplication with
 * A being M x K, B being K x N, and C being M x N, a sparse B matrix may be stored in memory using a data layout
 * which avoids storing zero values.
 *
 * \note Sparse matrix multiplications require that the sparse data be stored in column major layout.
 * An internal transpose of the partially decompressed data is required by the underlying intrinsics
 * and is carried out automatically by the API.
 *
 * <table>
 * <caption>Matrix multiplication modes for real types (sparse B matrix)</caption>
 * <tr><th>Arch.<th>8b x 4b<th>8b x 8b<th>16b x 8b<th>16b x 16b<th>bfloat16 x bfloat16
 * <tr><td style="white-space: nowrap;">
 *         AIE-ML
 *     <td style="vertical-align:top">
 *         4x32x8
 *     <td style="vertical-align:top">
 *         4x16x8<br/> 8x16x8<sup>a</sup><br/> 4x16x16<sup>ab</sup>
 *     <td style="vertical-align:top">
 *         2x16x8<br/> 4x16x8<sup>a</sup>
 *     <td style="vertical-align:top">
 *         2x8x8<br/> 4x8x8<sup>a</sup><br/> 2x8x16<sup>ab</sup>
 *     <td style="vertical-align:top">
 *         4x16x4<br/> 4x16x8<sup>ab</sup>
 * </table>
 *
 * \note
 * <sup>a</sup> - Emulated using multiple intrinsic calls <br/>
 * <sup>b</sup> - Require additional data manipulation
 *
 * The following example shows an optimized `int8 * sparse int8` GEMM:
 *
 * @code
 * void gemm_int8xint8_sparse(int8 * matA, int8 * matB, int8 *__restrict matC,
 *                            int rowsA, int inner, int colsB)
 * {
 *     using MMUL = aie::mmul<4, 16, 8, int8, int8, accauto>;
 *
 *     auto a_desc = aie::make_tensor_descriptor<int8, 64>(aie::tensor_dim(rowsA / 4 / 4, 2),
 *                                                         aie::tensor_dim(colsB / 4 / 4, 0),
 *                                                         aie::tensor_dim(inner / 8, rowsA / 8),
 *                                                         aie::tensor_dim(2u, 1));
 *
 *     auto c_desc = aie::make_tensor_descriptor<int8, 32>(aie::tensor_dim(rowsA / 4 / 4, 4),
 *                                                         aie::tensor_dim(colsB / 8, rowsA / 4),
 *                                                         aie::tensor_dim(4u, 1));
 *
 *     auto tsA = aie::make_tensor_buffer_stream<aie_dm_resource::a>(matA, a_desc);
 *     auto tsC = aie::make_restrict_tensor_buffer_stream(matC, c_desc);
 *
 *     for (int j = 0; j < rowsA / 16; j++)
 *         chess_loop_range(2,)
 *     {
 *         auto tsB = aie::sparse_vector_input_buffer_stream<int8, 128, aie_dm_resource::a>(matB);
 *
 *         for (int b = 0; b < colsB / 16; b++)
 *             chess_prepare_for_pipelining
 *             chess_loop_range(2,)
 *         {
 *             MMUL C00, C01;
 *             MMUL C10, C11;
 *             MMUL C20, C21;
 *             MMUL C30, C31;
 *
 *             for (int i = 0; i < inner / 16; i++)
 *                 chess_prepare_for_pipelining
 *                 chess_loop_range(4,)
 *             {
 *                 aie::vector<int8,64> Sbuff0, Sbuff1, Sbuff2, Sbuff3;
 *                 tsA.pop() >> Sbuff0 >> Sbuff1;
 *                 tsA.pop() >> Sbuff2 >> Sbuff3;
 *
 *                 auto [Xbuff0, Xbuff1] = aie::interleave_zip(Sbuff0, Sbuff2, 8);
 *                 auto [Xbuff2, Xbuff3] = aie::interleave_zip(Sbuff1, Sbuff3, 8);
 *
 *                 aie::sparse_vector<int8,128> Ybuff0, Ybuff1;
 *                 tsB >> Ybuff0 >> Ybuff1;
 *
 *                 C00.mac(Xbuff0, Ybuff0); C01.mac(Xbuff0, Ybuff1);
 *                 C10.mac(Xbuff1, Ybuff0); C11.mac(Xbuff1, Ybuff1);
 *                 C20.mac(Xbuff2, Ybuff0); C21.mac(Xbuff2, Ybuff1);
 *                 C30.mac(Xbuff3, Ybuff0); C31.mac(Xbuff3, Ybuff1);
 *             }
 *
 *             tsC << C00.to_vector<int8>() << C10.to_vector<int8>() << C20.to_vector<int8>() << C30.to_vector<int8>()
 *                 << C01.to_vector<int8>() << C11.to_vector<int8>() << C21.to_vector<int8>() << C31.to_vector<int8>();
 *         }
 *     }
 * }
 * @endcode
 */

namespace aie::detail {

template <typename TypeA, typename TypeB>
struct compute_C_type;

template <> struct compute_C_type<int8,  int8>  { using type = int8; };
template <> struct compute_C_type<int8,  uint8> { using type = int8; };
template <> struct compute_C_type<uint8, int8>  { using type = int8; };
template <> struct compute_C_type<uint8, uint8> { using type = uint8; };

template <typename TypeA, typename TypeB>
using compute_C_type_t = typename compute_C_type<TypeA, TypeB>::type;

template <unsigned M, unsigned K, unsigned N, typename TypeA, typename TypeB, unsigned AccumBits>
struct mmul;

template <typename TypeA, typename TypeB, unsigned AccumBits, unsigned Elems, unsigned NumAccum>
struct C_block;

template <typename TypeA, typename TypeB, unsigned AccumBits, unsigned Elems>
struct C_block<TypeA, TypeB, AccumBits, Elems, 1>
{
    using  accum_tag = accum_tag_for_mul_types<TypeA, TypeB, AccumBits>;
    using accum_type = accum<accum_tag, Elems>;

    accum_type data;
    bool       zero;

    __aie_inline
    C_block() : zero(true)
    {}

    __aie_inline
    C_block(const accum_type &acc, bool to_zero = false) : data(acc), zero(to_zero)
    {}

    template <typename T>
    __aie_inline
    C_block(const vector<T, Elems> &v, int shift = 0) : C_block(accum_type(v, shift))
    {}

    __aie_inline
    accum_type to_accum() const
    {
        return data;
    }

    __aie_inline
    operator accum_type() const
    {
        return to_accum();
    }

    template <typename T>
    __aie_inline
    auto to_vector_sign(bool v_sign, int shift = 0) const
    {
        return data.template to_vector_sign<T>(v_sign, shift);
    }

    template <typename T>
    __aie_inline
    auto to_vector(int shift = 0) const
    {
        return to_vector_sign<T>(is_signed_v<T>, shift);
    }
};

template <typename TypeA, typename TypeB, unsigned AccumBits, unsigned Elems, unsigned NumAccums>
    requires (NumAccums > 1)
struct C_block<TypeA, TypeB, AccumBits, Elems, NumAccums>
{
    using           accum_tag = accum_tag_for_mul_types<TypeA, TypeB, AccumBits>;
    using          accum_type = accum<accum_tag, Elems>;
    using internal_accum_type = accum<accum_tag, Elems / NumAccums>;

    std::array<internal_accum_type, NumAccums> data;
    bool       zero;

    __aie_inline
    C_block() : zero(true)
    {}

    __aie_inline
    C_block(const accum_type &acc, bool to_zero = false) : zero(to_zero)
    {
        utils::unroll_times<NumAccums>([&](unsigned idx){ ;
            data[idx] = acc.template extract<Elems / NumAccums>(idx);
        });
    }

    template <typename T>
    __aie_inline
    C_block(const vector<T, Elems> &v, int shift = 0) : C_block(accum_type(v, shift))
    {
    }

    __aie_inline
    accum_type to_accum() const
    {
        return utils::apply_tuple([](auto&&... ts) __aie_inline {
            return concat_accum(std::forward<decltype(ts)>(ts)...);
        }, data);
    }

    __aie_inline
    operator accum_type() const
    {
        return to_accum();
    }

    template <typename T>
    __aie_inline
    auto to_vector_sign(bool v_sign, int shift = 0) const
    {
        return to_accum().template to_vector_sign<T>(v_sign, shift);
    }

    template <typename T>
    __aie_inline
    auto to_vector(int shift = 0) const
    {
        return to_vector_sign<T>(is_signed_v<T>, shift);
    }
};

template <typename TypeA, typename TypeB, unsigned AccumBits, unsigned Elems, unsigned Ratio>
struct C_block_larger_internal
{
    using           accum_tag = accum_tag_for_mul_types<TypeA, TypeB, AccumBits>;
    using          accum_type = accum<accum_tag, Elems>;
    using internal_accum_type = accum<accum_tag, Elems * Ratio>;

    internal_accum_type data;
    bool       zero;

    __aie_inline
    C_block_larger_internal() : zero(true)
    {}

    __aie_inline
    C_block_larger_internal(const accum_type &acc, bool to_zero = false) : data(acc.template grow<Elems * Ratio>()), zero(to_zero)
    {}

    template <typename T>
    __aie_inline
    C_block_larger_internal(const vector<T, Elems> &v, int shift = 0) : C_block_larger_internal(accum_type(v, shift))
    {}

    __aie_inline
    accum_type to_accum() const
    {
        return data.template extract<Elems>(0);
    }

    __aie_inline
    operator accum_type() const
    {
        return to_accum();
    }

    template <typename T>
    __aie_inline
    vector<T, Elems> to_vector_sign(bool v_sign, int shift = 0) const
    {
        return data.template extract<Elems>(0).template to_vector_sign<T>(v_sign, shift);
    }

    template <typename T>
    __aie_inline
    vector<T, Elems> to_vector(int shift = 0) const
    {
        return to_vector_sign<T>(is_signed_v<T>, shift);
    }
};

#if __AIE_ARCH__ == 20
// C_block_interleave_cols implementation requires accumulator shuffles
// which aren't supported on AIE1 due to loss of precision

template <typename TypeA, typename TypeB, unsigned AccumBits, unsigned Elems, unsigned NumCols>
struct C_block_interleave_cols
{
    using           accum_tag = accum_tag_for_mul_types<TypeA, TypeB, AccumBits>;
    using          accum_type = accum<accum_tag, Elems>;
    using internal_accum_type = accum<accum_tag, Elems / 2>;

    internal_accum_type data[2];
    bool                zero;

    __aie_inline
    C_block_interleave_cols() : zero(true)
    {}

    __aie_inline
    C_block_interleave_cols(const accum_type &acc, bool to_zero = false)
    {
        accum_type ret;
        zero = to_zero;

        constexpr unsigned factor = AccumBits == 64 ? 2 : 1; 

        const auto [tmp1, tmp2] = interleave_unzip<interleave_t, Elems / 2>::run(acc_to_vec::run(acc.template extract<Elems / 2>(0)),
                                                                                 acc_to_vec::run(acc.template extract<Elems / 2>(1)),
                                                                                 (NumCols / 2) * factor);

        data[0] = vector_to_accum_cast<accum_tag, interleave_t, Elems / 2>::run(tmp1);
        data[1] = vector_to_accum_cast<accum_tag, interleave_t, Elems / 2>::run(tmp2);
    }

    template <typename T>
    __aie_inline
    C_block_interleave_cols(const vector<T, Elems> &v, int shift = 0)
    {
        accum_type ret;

        const auto [tmp1, tmp2] = interleave_unzip<T, Elems / 2>::run(v.template extract<Elems / 2>(0),
                                                                      v.template extract<Elems / 2>(1),
                                                                      NumCols / 2);

        data[0].from_vector(tmp1, shift);
        data[1].from_vector(tmp2, shift);
        zero = false;
    }

    __aie_inline
    accum_type to_accum() const
    {
        accum_type ret;

        const auto [tmp1, tmp2] = interleave_zip<interleave_t, Elems / 2>::run(acc_to_vec::run(data[0]),
                                                                               acc_to_vec::run(data[1]),
                                                                               NumCols / 2);

        ret.insert(0, vec_to_acc::run(tmp1));
        ret.insert(1, vec_to_acc::run(tmp2));

        return ret;
    }

    __aie_inline
    operator accum_type() const
    {
        return to_accum();
    }

    template <typename T>
    __aie_inline
    vector<T, Elems> to_vector_sign(bool v_sign, int shift = 0) const
    {
        return to_accum().template to_vector_sign<T>(v_sign, shift);
    }

    template <typename T>
    __aie_inline
    vector<T, Elems> to_vector(int shift = 0) const
    {
        return to_vector_sign<T>(is_signed_v<T>, shift);
    }

private:
    using interleave_t = int32;
    using acc_to_vec   = accum_to_vector_cast<interleave_t, accum_tag,    Elems / 2>;
    using vec_to_acc   = vector_to_accum_cast<accum_tag,    interleave_t, Elems / 2>;
};

#endif //__AIE_ARCH__ == 20

}

#if __AIE_ARCH__ == 10

#include "aie1/mmul.hpp"

#elif __AIE_ARCH__ == 20

#include "aie2/mmul.hpp"

#endif

#endif
