#include <adf.h>
#include "aie_api/aie.hpp"
#include "aie_api/aie_adf.hpp"
#include "include.h"



void vectorized_add(input_window_int32 * __restrict in_1, input_window_int32 * __restrict in_2,
						output_window_int32 * __restrict out) {

//	//// for profiling
	//unsigned long long cycle_num[2];
	//aie::tile tile = aie::tile::current();
	//cycle_num[0] = tile.cycles();

	for (unsigned i=0; i<(single_M*single_N/8); i++)
//	chess_prepare_for_pipelining
	chess_flatten_loop

	{

		// load
		aie::vector<int32, 8> v_a = window_readincr_v<8>(in_1);
		aie::vector<int32, 8> v_b = window_readincr_v<8>(in_2);


		// compute
		aie::vector<int32, 8> v_c = aie::add(v_a, v_b);

		// store
		window_writeincr(out, v_c);
	}

//	cycle_num[1] = tile.cycles();
//	printf("start=%llu, end=%llu, Kernel clock cycles=%llu\n", cycle_num[0], cycle_num[1], (cycle_num[1] - cycle_num[0]));
}




// 8-input accumulator (reduces hardware )
void vectorized_add_8plio(input_window_int32 * __restrict in_1,
                      input_window_int32 * __restrict in_2,
                      input_window_int32 * __restrict in_3,
                      input_window_int32 * __restrict in_4,
                      input_window_int32 * __restrict in_5,
                      input_window_int32 * __restrict in_6,
                      input_window_int32 * __restrict in_7,
                      input_window_int32 * __restrict in_8,
                      output_window_int32 * __restrict out) {

    for (unsigned i=0; i<(single_M*single_N/8); i++)
    chess_flatten_loop
    {
        // Load 8 vectors
        aie::vector<int32, 8> v1 = window_readincr_v<8>(in_1);
        aie::vector<int32, 8> v2 = window_readincr_v<8>(in_2);
        aie::vector<int32, 8> v3 = window_readincr_v<8>(in_3);
        aie::vector<int32, 8> v4 = window_readincr_v<8>(in_4);
        aie::vector<int32, 8> v5 = window_readincr_v<8>(in_5);
        aie::vector<int32, 8> v6 = window_readincr_v<8>(in_6);
        aie::vector<int32, 8> v7 = window_readincr_v<8>(in_7);
        aie::vector<int32, 8> v8 = window_readincr_v<8>(in_8);

        // Compute in tree fashion: ((1+2)+(3+4)) + ((5+6)+(7+8))
        aie::vector<int32, 8> sum12 = aie::add(v1, v2);
        aie::vector<int32, 8> sum34 = aie::add(v3, v4);
        aie::vector<int32, 8> sum56 = aie::add(v5, v6);
        aie::vector<int32, 8> sum78 = aie::add(v7, v8);
        
        aie::vector<int32, 8> sum1234 = aie::add(sum12, sum34);
        aie::vector<int32, 8> sum5678 = aie::add(sum56, sum78);
        
        aie::vector<int32, 8> final_sum = aie::add(sum1234, sum5678);

        // Store
        window_writeincr(out, final_sum);
    }
}



// 4-input accumulator for 4x4x1 configuration
void vectorized_add_4plio(input_window_int32 * __restrict in_1,
                      input_window_int32 * __restrict in_2,
                      input_window_int32 * __restrict in_3,
                      input_window_int32 * __restrict in_4,
                      output_window_int32 * __restrict out) {

    for (unsigned i=0; i<(single_M*single_N/8); i++)
    chess_flatten_loop
    {
        // Load 4 vectors
        aie::vector<int32, 8> v1 = window_readincr_v<8>(in_1);
        aie::vector<int32, 8> v2 = window_readincr_v<8>(in_2);
        aie::vector<int32, 8> v3 = window_readincr_v<8>(in_3);
        aie::vector<int32, 8> v4 = window_readincr_v<8>(in_4);

        // Compute in tree fashion: (1+2)+(3+4)
        aie::vector<int32, 8> sum12 = aie::add(v1, v2);
        aie::vector<int32, 8> sum34 = aie::add(v3, v4);
        
        aie::vector<int32, 8> final_sum = aie::add(sum12, sum34);

        // Store
        window_writeincr(out, final_sum);
    }
}  
