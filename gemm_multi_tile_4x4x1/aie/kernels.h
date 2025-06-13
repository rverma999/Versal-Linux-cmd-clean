
#ifndef FUNCTION_KERNELS_H
#define FUNCTION_KERNELS_H

	void gemm(input_window_int8 * __restrict matA, input_window_int8 * __restrict matB,
						output_window_int32 * __restrict matC);

	void vectorized_add(input_window_int32 * __restrict in_1, input_window_int32 * __restrict in_2,
							output_window_int32 * __restrict out);

        void vectorized_add_8plio(input_window_int32 * __restrict in_1,
                                         input_window_int32 * __restrict in_2,
                                         input_window_int32 * __restrict in_3,
                                         input_window_int32 * __restrict in_4,
                                         input_window_int32 * __restrict in_5,
                                         input_window_int32 * __restrict in_6,
                                         input_window_int32 * __restrict in_7,
                                         input_window_int32 * __restrict in_8,
                                         output_window_int32 * __restrict out); 

void vectorized_add_4plio(input_window_int32 * __restrict in_1,
                      input_window_int32 * __restrict in_2,
                      input_window_int32 * __restrict in_3,
                      input_window_int32 * __restrict in_4,
                      output_window_int32 * __restrict out) ;

#endif
