#include <adf.h>
#include "aie_api/aie.hpp"
#include "aie_api/aie_adf.hpp"
#include "include.h"


/*
 *  Matrices should be in blocked format in memory, in the following order:
 * 	 ____________________________
 * 	|  1 |  2 |  3 | ...
 * 	|____|____|____|
 * 	|  x | x+1| x+2| ...
 * 	|____|____|____|
 * 	|.
 * 	|.
 * 	|.
 *
 * 	Tile size is defined from the AI Engine APIs 
 *  check include.h file, dimensions named M_API, K_API, N_API
 *
 */

////// optimized matrix multiplication kernel - with reg double buffer 
////void gemm(input_window_int8 * __restrict matA, input_window_int8 * __restrict matB,
////						output_window_int32 * __restrict matC) {
////
////
////
////
////	// change M_API, K_API, N_API at include.h, based on AI Engine API
////	using MMUL = aie::mmul<M_API, K_API, N_API, int8, int8>;
////
////	// pointers of matrices
////	const int8* __restrict pA = (int8*) matA->ptr;
////	const int8* __restrict pB = (int8*) matB->ptr;
////	int32* __restrict pC = (int32*) matC->ptr;
////
////	// for profiling
////	unsigned long long cycle_num[2];
////	aie::tile tile = aie::tile::current();
////	cycle_num[0] = tile.cycles();
////
////	// printf("Starting...");
////	// unroll the loops for more optimization
////	for (unsigned i = 0; i < (single_M/M_API); i+=2)
//////		chess_prepare_for_pipelining
////		chess_flatten_loop
////
////	{
////
////		int32 * __restrict pC1 = pC + (i * (single_N/N_API)) * MMUL::size_C;
////		int32 * __restrict pC2 = pC + ((i+1) * (single_N/N_API)) * MMUL::size_C;
////
////		for (unsigned j = 0; j < (single_N/N_API); j+=2)
////		chess_flatten_loop
//////		chess_prepare_for_pipelining
//////		Just write it this way, don't question it, or it won't scheudle at every clk.
////
////		{
////                        // Double buffer vectors
////                        aie::vector<int8, MMUL::size_A> A0_buf[2], A1_buf[2];
////                        aie::vector<int8, MMUL::size_B> B0_buf[2], B1_buf[2];
////
////			const int8 * __restrict pA1 = pA + ( i * (single_K/K_API) + 0) * MMUL::size_A;
////			const int8 * __restrict pA2 = pA + ( (i+1) * (single_K/K_API) + 0) * MMUL::size_A;
////
////			const int8 * __restrict pB1 = pB + ( 0 * (single_N/N_API) + j) * MMUL::size_B;
////			const int8 * __restrict pB2 = pB + ( 0 * (single_N/N_API) + (j+1)) * MMUL::size_B;
////
////
////			//ORG  aie::vector<int8, MMUL::size_A> A0 = aie::load_v<MMUL::size_A>(pA1); pA1 += MMUL::size_A;
////			//ORG  aie::vector<int8, MMUL::size_A> A1 = aie::load_v<MMUL::size_A>(pA2); pA2 += MMUL::size_A;
////
////			//ORG  aie::vector<int8, MMUL::size_B> B0 = aie::load_v<MMUL::size_B>(pB1); pB1 += MMUL::size_B * (single_N/N_API);
////			//ORG  aie::vector<int8, MMUL::size_B> B1 = aie::load_v<MMUL::size_B>(pB2); pB2 += MMUL::size_B * (single_N/N_API);
////
////                        A0_buf[0] = aie::load_v<MMUL::size_A>(pA1); pA1 += MMUL::size_A;
////                        A1_buf[0] = aie::load_v<MMUL::size_A>(pA2); pA2 += MMUL::size_A;
////                        B0_buf[0] = aie::load_v<MMUL::size_B>(pB1); pB1 += MMUL::size_B * (single_N/N_API);
////                        B1_buf[0] = aie::load_v<MMUL::size_B>(pB2); pB2 += MMUL::size_B * (single_N/N_API);
////
////
////			MMUL C00;
////			MMUL C01;
////			MMUL C10;
////			MMUL C11;
////
////			//ORG // matrix multiply by initializing to 0
////			//ORG C00.mul(A0, B0);
////			//ORG C01.mul(A0, B1);
////			//ORG C10.mul(A1, B0);
////			//ORG C11.mul(A1, B1);
////			C00.mul(A0_buf[0], B0_buf[0]);
////			C01.mul(A0_buf[0], B1_buf[0]);
////			C10.mul(A1_buf[0], B0_buf[0]);
////			C11.mul(A1_buf[0], B1_buf[0]);
////
////			////for (unsigned k =0; k < (single_K/K_API)-1; k++)
////			//for (unsigned k = 1; k < (single_K/K_API); k++)
//////			//chess_prepare_for_pipelining
////			//chess_flatten_loop
////			//{
////			//	A0 = aie::load_v<MMUL::size_A>(pA1); pA1 += MMUL::size_A;
////			//	A1 = aie::load_v<MMUL::size_A>(pA2); pA2 += MMUL::size_A;
////
////			//	B0 = aie::load_v<MMUL::size_B>(pB1); pB1 += MMUL::size_B * (single_N/N_API);
////			//	B1 = aie::load_v<MMUL::size_B>(pB2); pB2 += MMUL::size_B * (single_N/N_API);
////
////			//	// matrix multiply and adding partial blocks
////			//	C00.mac(A0, B0);
////			//	C01.mac(A0, B1);
////			//	C10.mac(A1, B0);
////			//	C11.mac(A1, B1);
////			//}
////                       
////                        unsigned next_buf ;//= k & 0x1 ;
////                        unsigned curr_buf ;//= next_buf^0x1;
////                        for (unsigned k = 1; k < (single_K/K_API); k++) 
////                            chess_flatten_loop
////                          {
////                            ////Issue with this approach is that next_buf is undeterministoc ?  
////                            //// Load the next buffers (for next iteration)
////                            ////unsigned next_buf = k % 2;
////                            ////unsigned curr_buf = 1 - next_buf;
////                           
////                            next_buf = k & 0x1 ;
////                            curr_buf = next_buf^0x1;
//// 
////                            A0_buf[next_buf] = aie::load_v<MMUL::size_A>(pA1); pA1 += MMUL::size_A;
////                            A1_buf[next_buf] = aie::load_v<MMUL::size_A>(pA2); pA2 += MMUL::size_A;
////                            
////                            // Perform MAC with current buffers while loading next B vectors
////                            C00.mac(A0_buf[curr_buf], B0_buf[curr_buf]);
////                            C01.mac(A0_buf[curr_buf], B1_buf[curr_buf]);
////                            
////                            B0_buf[next_buf] = aie::load_v<MMUL::size_B>(pB1); pB1 += MMUL::size_B * (single_N/N_API);
////                            B1_buf[next_buf] = aie::load_v<MMUL::size_B>(pB2); pB2 += MMUL::size_B * (single_N/N_API);
////                            
////                            C10.mac(A1_buf[curr_buf], B0_buf[curr_buf]);
////                            C11.mac(A1_buf[curr_buf], B1_buf[curr_buf]);
////                        }
////
////			aie::store_v(pC1, C00.template to_vector<int32>(SHIFT)); pC1 +=MMUL::size_C;
////			aie::store_v(pC1, C01.template to_vector<int32>(SHIFT)); pC1 +=MMUL::size_C;
////			aie::store_v(pC2, C10.template to_vector<int32>(SHIFT)); pC2 +=MMUL::size_C;
////			aie::store_v(pC2, C11.template to_vector<int32>(SHIFT)); pC2 +=MMUL::size_C;
////
////
////		}
////		// printf("chkpt %d\n", i);
////
////	}
////	cycle_num[1] = tile.cycles();
////	printf("start=%llu, end=%llu, Kernel clock cycles=%llu\n", cycle_num[0], cycle_num[1], (cycle_num[1] - cycle_num[0]));
////
////
////}


//DMA double buffer
void gemm(input_window_int8 * __restrict matA, input_window_int8 * __restrict matB,
                       output_window_int32 * __restrict matC) {
    // change M_API, K_API, N_API at include.h, based on AI Engine API
    using MMUL = aie::mmul<M_API, K_API, N_API, int8, int8>;

    // pointers of matrices
    const int8* __restrict pA = (int8*) matA->ptr;
    const int8* __restrict pB = (int8*) matB->ptr;
    int32* __restrict pC = (int32*) matC->ptr;

    // for profiling
    unsigned long long cycle_num[2];
    aie::tile tile = aie::tile::current();
    cycle_num[0] = tile.cycles();

    //// Double buffering for local memory
    //alignas(32) int8 local_A[2][MMUL::size_A * (single_K/K_API)];
    //alignas(32) int8 local_B[2][MMUL::size_B * (single_N/N_API)];
    
    // Initial data copy to buffer 0
    unsigned buf_idx = 0;
    
    // Copy first block of data manually - no special DMA API used
    for (int i = 0; i < MMUL::size_A * (single_K/K_API); i++) {
        local_A[buf_idx][i] = pA[i];
    }
    
    for (int i = 0; i < MMUL::size_B * (single_N/N_API); i++) {
        local_B[buf_idx][i] = pB[i];
    }

    // unroll the loops for more optimization
    for (unsigned i = 0; i < (single_M/M_API); i+=2)
    chess_flatten_loop {
        int32 * __restrict pC1 = pC + (i * (single_N/N_API)) * MMUL::size_C;
        int32 * __restrict pC2 = pC + ((i+1) * (single_N/N_API)) * MMUL::size_C;

        for (unsigned j = 0; j < (single_N/N_API); j+=2)
        chess_flatten_loop {
            // Calculate next indices
            unsigned next_i = i, next_j = j + 2;
            if (next_j >= (single_N/N_API)) {
                next_j = 0;
                next_i += 2;
            }
            
            // Start next data copy to alternate buffer if not at the last block
            if ((i < (single_M/M_API-2)) || (j < (single_N/N_API-2))) {
                unsigned next_buf = 1 - buf_idx;
                const int8* next_pA = pA + (next_i * (single_K/K_API)) * MMUL::size_A;
                const int8* next_pB = pB + (next_j) * MMUL::size_B;
                
                // Copy next data blocks
                for (int k = 0; k < MMUL::size_A * (single_K/K_API); k++) {
                    local_A[next_buf][k] = next_pA[k];
                }
                
                for (int k = 0; k < MMUL::size_B * (single_N/N_API); k++) {
                    local_B[next_buf][k] = next_pB[k];
                }
            }

            // Setup pointers for the current computation using local memory
            const int8 * __restrict pA1 = &local_A[buf_idx][0] + ( i * (single_K/K_API) + 0) * MMUL::size_A;
            const int8 * __restrict pA2 = &local_A[buf_idx][0] + ( (i+1) * (single_K/K_API) + 0) * MMUL::size_A;
            const int8 * __restrict pB1 = &local_B[buf_idx][0] + ( 0 * (single_N/N_API) + j) * MMUL::size_B;
            const int8 * __restrict pB2 = &local_B[buf_idx][0] + ( 0 * (single_N/N_API) + (j+1)) * MMUL::size_B;

            aie::vector<int8, MMUL::size_A> A0 = aie::load_v<MMUL::size_A>(pA1); pA1 += MMUL::size_A;
            aie::vector<int8, MMUL::size_A> A1 = aie::load_v<MMUL::size_A>(pA2); pA2 += MMUL::size_A;
            aie::vector<int8, MMUL::size_B> B0 = aie::load_v<MMUL::size_B>(pB1); pB1 += MMUL::size_B * (single_N/N_API);
            aie::vector<int8, MMUL::size_B> B1 = aie::load_v<MMUL::size_B>(pB2); pB2 += MMUL::size_B * (single_N/N_API);

            MMUL C00;
            MMUL C01;
            MMUL C10;
            MMUL C11;

            // matrix multiply by initializing to 0
            C00.mul(A0, B0);
            C01.mul(A0, B1);
            C10.mul(A1, B0);
            C11.mul(A1, B1);

            for (unsigned k = 0; k < (single_K/K_API)-1; k++)
            chess_flatten_loop {
                A0 = aie::load_v<MMUL::size_A>(pA1); pA1 += MMUL::size_A;
                A1 = aie::load_v<MMUL::size_A>(pA2); pA2 += MMUL::size_A;
                B0 = aie::load_v<MMUL::size_B>(pB1); pB1 += MMUL::size_B * (single_N/N_API);
                B1 = aie::load_v<MMUL::size_B>(pB2); pB2 += MMUL::size_B * (single_N/N_API);

                // matrix multiply and adding partial blocks
                C00.mac(A0, B0);
                C01.mac(A0, B1);
                C10.mac(A1, B0);
                C11.mac(A1, B1);
            }

            aie::store_v(pC1, C00.template to_vector<int32>(SHIFT)); pC1 += MMUL::size_C;
            aie::store_v(pC1, C01.template to_vector<int32>(SHIFT)); pC1 += MMUL::size_C;
            aie::store_v(pC2, C10.template to_vector<int32>(SHIFT)); pC2 += MMUL::size_C;
            aie::store_v(pC2, C11.template to_vector<int32>(SHIFT)); pC2 += MMUL::size_C;

            // Toggle buffer indices if needed
            if ((i < (single_M/M_API-2)) || (j < (single_N/N_API-2))) {
                buf_idx = 1 - buf_idx;
            }
        }
    }
    
    cycle_num[1] = tile.cycles();
    printf("start=%llu, end=%llu, Kernel clock cycles=%llu\n", cycle_num[0], cycle_num[1], (cycle_num[1] - cycle_num[0]));
}

 

//void vectorized_add(input_window_int32 * __restrict in_1, input_window_int32 * __restrict in_2,
//						output_window_int32 * __restrict out) {
//
////	// for profiling
////	unsigned long long cycle_num[2];
////	aie::tile tile = aie::tile::current();
////	cycle_num[0] = tile.cycles();
//
//	for (unsigned i=0; i<(single_M*single_N/8); i++)
////	chess_prepare_for_pipelining
//	chess_flatten_loop
//
//	{
//
//		// load
//		aie::vector<int32, 8> v_a = window_readincr_v<8>(in_1);
//		aie::vector<int32, 8> v_b = window_readincr_v<8>(in_2);
//
//
//		// compute
//		aie::vector<int32, 8> v_c = aie::add(v_a, v_b);
//
//		// store
//		window_writeincr(out, v_c);
//	}
//
////	cycle_num[1] = tile.cycles();
////	printf("start=%llu, end=%llu, Kernel clock cycles=%llu\n", cycle_num[0], cycle_num[1], (cycle_num[1] - cycle_num[0]));
//}
