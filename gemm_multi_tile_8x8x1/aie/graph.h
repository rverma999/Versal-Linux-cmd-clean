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
  kernel acc[mult_Y];  //8

public:
  input_plio  A[mult_X * mult_Y]; //64
  input_plio  B[mult_Y * mult_Z]; //8
  output_plio C[mult_X * mult_Z]; //8

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
        acc[i] = kernel::create(vectorized_add_8plio);
        source(acc[i]) = "kernels/accumulator.cc";
        runtime<ratio>(acc[i]) = 1.0;
        // Place accumulators on separate tiles
        location<kernel>(acc[i]) = tile(8+i,0); // Opposite of MAtrix convention : its actually cols,row  
       //Final accumualator output to outside of AIE 
       connect<window<single_M*single_N*4>>(acc[i].out[0], C[i].in[0]);
      }

    // Create a 8x8 tile configuration
    for(int j=0; j<mult_X; j++) { //8 column 8
      for(int i=0; i<mult_Y; i++) { //8i row
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
        connect<window<single_K*single_N*1>>(B[krn_indx % mult_Y].out[0], mat_mul_k[krn_indx].in[1]);


       connect<window<single_M*single_N*4>>(mat_mul_k[krn_indx].out[0], acc[j].in[i]);

        // Optimize buffer placement
        not_equal(location<buffer>(mat_mul_k[krn_indx].in[0]), location<buffer>(mat_mul_k[krn_indx].in[1]));
        
        
        // Set runtime ratio based on 
        runtime<ratio>(mat_mul_k[krn_indx]) = 1.0; // Minimum ratio of 0.1
        
        //DEBUG_PRINTF("Tile[%d,%d]: Work=%lld, Ratio=%f\n", i, j, tile_work, ratio);
      }
    }
  }

  };
