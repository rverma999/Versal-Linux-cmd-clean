/*
Copyright (C) 2023, Advanced Micro Devices, Inc. All rights reserved.
SPDX-License-Identifier: X11
*/


#include <ap_int.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>


extern "C" {

void mm2s(ap_int<32>* mem, hls::stream<ap_axis<32, 0, 0, 0>  >& s, int size) {
#pragma HLS INTERFACE m_axi port=mem offset=slave bundle=gmem
//#pragma HLS INTERFACE m_axi port=mem offset=slave bundle=gmem \
//        max_read_burst_length=32 max_write_burst_length=32 \
//        num_read_outstanding=8 num_write_outstanding=8 \
//        latency=32 data_width=256

#pragma HLS interface axis port=s

#pragma HLS INTERFACE s_axilite port=mem bundle=control
#pragma HLS INTERFACE s_axilite port=size bundle=control
#pragma HLS interface s_axilite port=return bundle=control

	for(int i = 0; i < size; i++) {
#pragma HLS PIPELINE II=1
		ap_axis<32, 0, 0, 0> x;
		x.data = mem[i]; // from shim DMA memory to to AIE engine ?
		s.write(x);  //write to output stream 
	}
	}
	}
/*
1. Given Parameters
   - Data type: `ap_int<32>` (32-bit integers)
   - NoC data width: 256 bits (32 bytes)
   - Memory controller optimal burst: 32 transfers
   - Total data size: `size` elements of 32-bit each

2. 
   ```
   Burst Size = 256 bits = 32 bytes = 8 elements of 32-bit each
   ```

3. Burst Length Calculation:
   ```
   Optimal Burst Length = min(
       32 (memory controller optimal),
       size/8 (data elements per burst)
   )


        ap_int<32> local_buffer[32];
        $printf("mm2s: size=i'd%d 'h%0h",size,size);
        #pragma HLS ARRAY_PARTITION variable=local_buffer cyclic factor=8 dim=1
        //Now 32 elements per burst
	for(int i = 0; i < size; i+=32) {
          if ((i + 32) > size) {
              burst_size = size - i;
          } else {
              burst_size = 32;
          }
	}
         
        //$printf("mm2s: burst_size=i'd%d 'h%0h", burst_size,burst_size);

        //local mem to local buffer 
	for(int i = 0; i < burst_size; i+=32) {
        //To be udpated
        }
        //Write to  
	s.write(x);
}

}
*/
