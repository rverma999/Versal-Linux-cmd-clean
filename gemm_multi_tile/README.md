# Multi-Tile GEMM on AMD Versal AI Engine 

 "Journey of a Thousand Matrix Multiplications Begins with a Single Tile" 
 
 This project implementsGeneral Matrix Multiplication (GEMM) on AMD VCK190's AI Engine, demonstrating how multiple AIE tiles can work together to accelerate matrix computations.

##  What This Project Does

Ever wondered how to make matrix multiplication blazingly fast on specialized hardware? This project shows you exactly that! We take large matrix multiplications and split them across multiple AI Engine tiles, with each tile handling a piece of the puzzle. The magic happens when all tiles work together to produce the final result.

Current Implementation:
- Matrix Size: 32×32 (16×16 per tile)
- Data Type: INT8 (because AI loves efficiency!)
- Tiles Used: 6 AIE tiles (4 compute + 2 accumulator)
- Performance: Optimized for VCK190's 400-tile AI Engine array

### The Mathematics Magic 
Our 2×2 tiling strategy breaks down a large matrix multiplication C = A × B into:

- C0 = A0×B0 + A1×B1 (Accumulator 0 combines kernels 0,1)
- C1 = A2×B0 + A3×B1 (Accumulator 1 combines kernels 2,3)

Each kernel performs a 16×32 × 32×16 = 16×16 matrix multiplication in parallel!

##  Project Structure

```
gemm_multi_tile/
├── aie/                          # AI Engine Implementation
│   ├── graph.h                   # Main ADF graph definition
│   ├── graph.cpp                 # Graph instantiation
│   ├── kernels/
│   │   ├── kernels.cc            # GEMM kernel implementation
│   │   ├── accumulator.cc        # Vector addition for reduction
│   │   ├── concatenator.cc       # Alternative tile combination
│   │   └── include.h             # Configuration parameters
├── pl_kernels/                   # PL Data Movement
│   ├── mm2s/                     # Memory-to-stream kernel
│   └── s2mm/                     # Stream-to-memory kernel
├── data/                         # Test Matrices
│   ├── matA.txt                 # Input matrix A tiles
│   ├── matB.txt                 # Input matrix B tiles
│   └── matC.txt                 # Golden reference outputs
├── Makefile                      # Build system
└── README.md                     # You are here!
```

## Getting Started

### Prerequisites
- AMD Vitis 2024.1 or later
- VCK190 Evaluation Board
- Xilinx Runtime (XRT)
- Basic understanding of matrix multiplication 

### Quick Start 

1. Clone and Navigate
   cd gemm_multi_tile

2. source ./run_analyzer 
   #This will generate golden data, then simulate
 
3. 🎉 Marvel at Your Success!
   You should see: `Success: Outputs match for C0` and `Success: Outputs match for C1`

## Build Targets

| `make golden` | Generate reference data 
| `make aie` | Compile AI Engine graph 
| `make kernels` | Compile PL kernels 
| `make sim` | Run AIE simulation 
| `make host` | Compile ARM application 
| `make all` | Build everything 

## Configuration Parameters

In `aie/kernels/include.h` 

| Parameter | Current | Description | Impact |
|-----------|---------|-------------|---------|
| `mult_X` | 2 | Output columns | More columns = more output matrices |
| `mult_Y` | 2 | Reduction depth | More depth = more parallelism |
| `mult_Z` | 1 | Output depth | Currently single depth |
| `single_M` | 16 | Matrix rows per tile | Bigger = more computation per tile |
| `single_K` | 32 | Inner dimension | Must match across A and B |
| `single_N` | 16 | Matrix cols per tile | Bigger = wider output |

#define single_M (16*1)  // Matrix rows per tile - each A matrix is 16 rows tall
#define single_K (32*1)  // Inner dimension - A width (32) = B height (32) for multiplication  
#define single_N (16*1)  // Matrix cols per tile - each B matrix is 16 columns wide

#define M_API 4          // AIE vector rows processed per cycle (4×8×4 vector block)
#define K_API 8          // AIE vector inner dimension processed per cycle  
#define N_API 4          // AIE vector columns processed per cycle (4×8×4 vector block)

### The Great Index Mix-up of 2024
Initially, our B matrix connections were all wrong! Kernel 1 was trying to access `B[2]` when only `B[0]` and `B[1]` existed. The fix? A simple modulo operation: `B[krn_indx % mult_Y]`.

Lesson Learned: Always check your array bounds in multi-dimensional indexing!

### The Accumulator Confusion Saga  
We discovered that our beautiful 2×2 GEMM wasn't producing the golden values. After extensive debugging  found that kernels were connecting to the wrong accumulators.

The Fix: Proper kernel-to-accumulator mapping based on the golden data generation pattern.


##  Performance Insights

Our current 6-tile implementation demonstrates:
- Parallel Execution: 4 GEMM operations running simultaneously
- Efficient Reduction: Hardware-accelerated accumulation
- Scalability: Easy extension to larger tile arrays

Scaling Potential on VCK190:
- Current: 6 tiles (1.5% of total AIE)
- Next Step: 20 tiles (4×4 configuration)

## Contributing & Extending

### Want to Add More Tiles?
1. Update `mult_X` and `mult_Y` in `include.h`
2. Ensure your tile placement doesn't conflict
3. Update data generation for larger matrices
4. Test, test, test!



## Learning Resources

- [AMD AI Engine Architecture Manual](https://docs.amd.com/r/en-US/am009-versal-ai-engine)
- [Versal ACAP AI Engine Programming Guide](https://docs.amd.com/r/en-US/ug1079-ai-engine-kernel-coding)
- [PP4FPGAS AIE Tutorial](https://pp4fpgas.readthedocs.io/en/latest/project_aie.html)

This project is part of AMD's Vitis tutorial collection and follows the X11 license.

---


Happy Matrix Multiplying! 

