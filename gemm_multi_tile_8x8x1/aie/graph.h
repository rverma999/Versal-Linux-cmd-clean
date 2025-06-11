#include <vector>

#include <adf.h>
#include "kernels.h"
#include "kernels/include.h"

#if DEBUG_PRINTS
#define DEBUG_PRINTF(...) printf(__VA_ARGS__)
#else
#define DEBUG_PRINTF(...) 
#endif

using namespace adf;

class simpleGraph : public adf::graph {
private:
  kernel mat_mul_k[mult_Y * mult_X * mult_Z];
  kernel acc[mult_Y];  //2

public:
  input_plio  A[mult_X * mult_Y]; //4
  input_plio  B[mult_Y * mult_Z]; //2
  //output_plio C[mult_X * mult_Z]; //2
  //output_plio C[mult_X * mult_Y]; //4
  output_plio C[mult_X * mult_Z]; //2

  simpleGraph(){
    DEBUG_PRINTF("Creating kernels with mult_X=%d, mult_Y=%d, mult_Z=%d\n",mult_X, mult_Y, mult_Z);

    // input and output PLIOs creation below
    for (int i = 0; i < mult_X * mult_Y; i++){
      A[i] = input_plio::create(plio_128_bits, "data/matA" + std::to_string(i) + ".txt");
    }

    for (int i = 0; i < mult_Y * mult_Z; i++){
      B[i] = input_plio::create(plio_128_bits, "data/matB" + std::to_string(i) + ".txt");
    }

    for (int i = 0; i < mult_X * mult_Z; i++){
      C[i] = output_plio::create(plio_128_bits, "data/matC" + std::to_string(i) + ".txt");
    }

    // Create accumulator kernels
    for (int i = 0; i < mult_Y; i++) {
        acc[i] = kernel::create(vectorized_add);
        source(acc[i]) = "kernels/accumulator.cc";
        runtime<ratio>(acc[i]) = 1.0;
        // Place accumulators on separate tiles
        location<kernel>(acc[i]) = tile(2,i); // Place after compute tiles
       //Final accumualator output to outside of AIE 
       connect<window<single_M*single_N*4>>(acc[i].out[0], C[i].in[0]);
      }
     // for (int i = 0; i < mult_Y; i++) {
     //  //Final accumualator output to outside of AIE 
     //  connect<window<single_M*single_N*4>>(acc[i].out[0], C[i].in[0]);
     // }
    
    // Create a 2x2 tile configuration
    //for(int i=0; i<mult_Y; i++) {
    //  for(int j=0; j<mult_X; j++) {
    //    int krn_indx = i*mult_X+j;
    for(int j=0; j<mult_X; j++) {
      for(int i=0; i<mult_Y; i++) {
        int krn_indx = j*mult_X+i;
        //krn_indx -0,1,2,3 
        // Create the kernel
        mat_mul_k[krn_indx] = kernel::create(gemm);
        source(mat_mul_k[krn_indx]) = "kernels/kernels.cc";
        
        // Place the kernel on the appropriate tile
        location<kernel>(mat_mul_k[krn_indx]) = tile(i, j);
        
        // Connect inputs and outputs
        //connect<window<WINDOW SIZE >>(source, destination);
        connect<window<single_M*single_K*1>>(A[krn_indx].out[0], mat_mul_k[krn_indx].in[0]);
        //connect<window<single_K*single_N*1>>(B[krn_indx].out[0], mat_mul_k[krn_indx].in[1]);
        //THIS WAS giving wrong C0,C1 output, 
        //C0-> A0B0 + A3B1 XXX
        //connect<window<single_K*single_N*1>>(B[j].out[0], mat_mul_k[krn_indx].in[1]);
        //C0-> A0B0 + A1B1 , C1= A2B0 + A3B1
        //connect<window<single_K*single_N*1>>(B[j*mult_Y+i].out[0], mat_mul_k[krn_indx].in[1]);
        connect<window<single_K*single_N*1>>(B[krn_indx % mult_Y].out[0], mat_mul_k[krn_indx].in[1]);


        //connect<window<single_M*single_N*4>>(mat_mul_k[krn_indx].out[0], C[krn_indx].in[0]);
        //connect<window<single_M*single_N*4>>(mat_mul_k[krn_indx].out[0], C[j].in[0]);
        //connect<window<single_M*single_N*4>>(mat_mul_k[krn_indx].out[0], C[krn_indx].in[0]);
        //connect<window<single_M*single_N*4>>(mat_mul_k[krn_indx].out[0], C[j].in[0]);

       ////// Connect outputs to accumulators based on column position
       ////// Kernels in column j go to accumulator j
       ////// kernels 0,2 -> acc[0], kernels 1,3 -> acc[1]
       ////int acc_idx = j ;  // j determines which accumulator
       ////
       ////if (i == 0) {
       ////    // First row kernels connect to first input of accumulator
       ////    connect<window<single_M*single_N*4>>(mat_mul_k[krn_indx].out[0], acc[acc_idx].in[0]);
       ////} else {
       ////    // Second row kernels connect to second input of accumulator
       ////    connect<window<single_M*single_N*4>>(mat_mul_k[krn_indx].out[0], acc[acc_idx].in[1]);
       ////}
       // C0  A0×B0 + A1×B1 (kernels 0,1)
       // C1 : A2×B0 + A3×B1 (kernels 2,3)

       ////int acc_idx;
       ////int input_idx;
       ////
       ////if (krn_indx < 2) {
       ////    // Kernels 0,1 go to accumulator 0
       ////    acc_idx = 0;
       ////    input_idx = krn_indx;  // kernel 0→input 0, kernel 1→input 1
       ////} else {
       ////    // Kernels 2,3 go to accumulator 1  
       ////    acc_idx = 1;
       ////    input_idx = krn_indx - 2;  // kernel 2→input 0, kernel 3→input 1
       ////}

       ////connect<window<single_M*single_N*4>>(mat_mul_k[krn_indx].out[0], acc[acc_idx].in[input_idx]);
       connect<window<single_M*single_N*4>>(mat_mul_k[krn_indx].out[0], acc[j].in[i]);


       //Final accumualator output to outside of AIE 
       //connect<window<single_M*single_N*4>>(acc[i].out[0], C[i].in[0]);
        
        // Optimize buffer placement
        not_equal(location<buffer>(mat_mul_k[krn_indx].in[0]), location<buffer>(mat_mul_k[krn_indx].in[1]));
        
        // Calculate work for this tile using the helper
        //int64_t tile_work = multi_tile::get_tile_work(i, j, single_M * mult_Y, single_K, single_N * mult_X, mult_Y, mult_X);
        
        // Set runtime ratio based on work calculation
        runtime<ratio>(mat_mul_k[krn_indx]) = 1.0; // Minimum ratio of 0.1
        //float ratio = static_cast<float>(tile_work) / (single_M * single_K * single_N);
        //runtime<ratio>(mat_mul_k[krn_indx]) = ratio > 0.1 ? ratio : 0.1; // Minimum ratio of 0.1
        
        //DEBUG_PRINTF("Tile[%d,%d]: Work=%lld, Ratio=%f\n", i, j, tile_work, ratio);
      }
    }
  }

  };
