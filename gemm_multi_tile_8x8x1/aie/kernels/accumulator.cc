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
