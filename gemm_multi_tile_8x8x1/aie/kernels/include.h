#ifndef FUNCTION_INCLUDES_H
#define FUNCTION_INCLUDES_H


// define shift right for output values after matrix mult
#define SHIFT 0


//// multiple AIE parameters (XxYxZ on manuscript)
//#define mult_X 1
//#define mult_Y 1 // Has to be 4 for pattern 1, 3 for pattern 2
//#define mult_Z 1
//// In include.h

#ifndef mult_X
#define mult_X 2  // Default if not provided
#endif

#ifndef mult_Y
#define mult_Y 2
#endif

#ifndef mult_Z
#define mult_Z 1
#endif

#ifndef DEBUG_PRINTS
#define DEBUG_PRINTS 1
#endif
// single kernel dimensions (MxKxN on manuscript)
#define single_M (16*1)
#define single_K (32*1)
#define single_N (16*1)


// AI Engine API dimensions
#define M_API 4
#define K_API 8
#define N_API 4

// INT8 sizes
// 4x8x4
// 4x16x4
// 8x8x4
// 2x8x8
// 4x8x8
// 2x16x8
// 4x16x8

#endif
