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
  //kernel acc[mult_Y];  //4

  kernel acc_l1[mult_X * 2];  // 8 L1 accumulators (2 per output)
  kernel acc_l2[mult_X];      // 4 L2 accumulators (1 per output)

public:
  input_plio  A[mult_X * mult_Y]; //16
  input_plio  B[mult_Y * mult_Z]; //4
  output_plio C[mult_X * mult_Z]; //4

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

    //L1 accumulator
    for (int i = 0; i < mult_X * 2; i++) {
        acc_l1[i] = kernel::create(vectorized_add);
        source(acc_l1[i]) = "kernels/accumulator.cc";
        runtime<ratio>(acc_l1[i]) = 1.0;
    }

    // L2 : accumulator kernels
    for (int i = 0; i < mult_X; i++) {
        //acc[i] = kernel::create(vectorized_add);
        //source(acc[i]) = "kernels/accumulator.cc";
        //runtime<ratio>(acc[i]) = 1.0;
        //// Place accumulators on separate tiles
        ////location<kernel>(acc[i]) = tile(8+i,0); // Opposite of MAtrix convention : its actually cols,row  
        ////Final accumualator output to outside of AIE 
        //connect<window<single_M*single_N*4>>(acc[i].out[0], C[i].in[0]);

        acc_l2[i] = kernel::create(vectorized_add);
        source(acc_l2[i]) = "kernels/accumulator.cc";
        runtime<ratio>(acc_l2[i]) = 1.0;
        // Final accumulator output to outside of AIE 
        connect<window<single_M*single_N*4>>(acc_l2[i].out[0], C[i].in[0]);

      }


    // Create a 4x4 tile configuration
    for(int j=0; j<mult_X; j++) { //4 column 
      for(int i=0; i<mult_Y; i++) { //4 row
        int krn_indx = j*mult_X+i;
        //krn_indx -0,1,2,3 
        // Create the kernel
        mat_mul_k[krn_indx] = kernel::create(gemm);
        source(mat_mul_k[krn_indx]) = "kernels/kernels.cc";
        
        // Place the kernel on the appropriate tile
        //location<kernel>(mat_mul_k[krn_indx]) = tile(i, j);
        
        // Connect inputs and outputs
        //connect<window<WINDOW SIZE >>(source, destination);
        connect<window<single_M*single_K*1>>(A[krn_indx].out[0], mat_mul_k[krn_indx].in[0]);
        connect<window<single_K*single_N*1>>(B[krn_indx % mult_Y].out[0], mat_mul_k[krn_indx].in[1]);


	//connect<window<single_M*single_N*4>>(mat_mul_k[krn_indx].out[0], acc[j].in[i]);

        // Connect to L1 accumulators in pairs
        if (i < 2) {
            // First pair (i==0,1) goes to acc_l1[j*2]
            connect<window<single_M*single_N*4>>(mat_mul_k[krn_indx].out[0], acc_l1[j*2].in[i]);
        } else {
            // Second pair (=i=2,3) goes to acc_l1[j*2+1]  
            connect<window<single_M*single_N*4>>(mat_mul_k[krn_indx].out[0], acc_l1[j*2+1].in[i-2]);
        }

        // Connect L1 to L2 accumulators
        connect<window<single_M*single_N*4>>(acc_l1[j*2].out[0], acc_l2[j].in[0]);
        connect<window<single_M*single_N*4>>(acc_l1[j*2+1].out[0], acc_l2[j].in[1]);

        // Optimize buffer placement
        not_equal(location<buffer>(mat_mul_k[krn_indx].in[0]), location<buffer>(mat_mul_k[krn_indx].in[1]));
        
        
        // Set runtime ratio based on 
        runtime<ratio>(mat_mul_k[krn_indx]) = 1.0; // Minimum ratio of 0.1
        
        //DEBUG_PRINTF("Tile[%d,%d]: Work=%lld, Ratio=%f\n", i, j, tile_work, ratio);
      }
    }
  }

  };
