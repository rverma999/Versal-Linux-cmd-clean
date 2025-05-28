#ifndef MULTI_TILE_HELPER_H
#define MULTI_TILE_HELPER_H

#include <adf.h>
#include "kernels/include.h"

namespace multi_tile {
    // Helper structure to manage matrix partition info
    struct MatrixPartition {
        int start_row;
        int end_row;
        int start_col;
        int end_col;
        int rows;
        int cols;
    };

    // Calculate partition for a specific tile
    inline MatrixPartition get_partition(int tile_row, int tile_col, 
                                 int total_rows, int total_cols,
                                 int num_tile_rows, int num_tile_cols) {
        MatrixPartition partition;
        
        // Calculate partition dimensions
        int rows_per_tile = (total_rows + num_tile_rows - 1) / num_tile_rows;
        int cols_per_tile = (total_cols + num_tile_cols - 1) / num_tile_cols;
        
        // Calculate start and end indices
        partition.start_row = tile_row * rows_per_tile;
        partition.end_row = std::min(partition.start_row + rows_per_tile, total_rows);
        partition.start_col = tile_col * cols_per_tile;
        partition.end_col = std::min(partition.start_col + cols_per_tile, total_cols);
        
        // Calculate actual dimensions
        partition.rows = partition.end_row - partition.start_row;
        partition.cols = partition.end_col - partition.start_col;
        
        return partition;
    }
    
    // Get total work for a specific tile (in terms of operations)
    inline int64_t get_tile_work(int tile_row, int tile_col, 
                        int M, int K, int N,
                        int num_tile_rows, int num_tile_cols) {
        auto p_a = get_partition(tile_row, 0, M, K, num_tile_rows, 1);
        auto p_b = get_partition(0, tile_col, K, N, 1, num_tile_cols);
        
        // Work is proportional to output matrix size and K dimension
        return p_a.rows * p_b.cols * K;
    }
    
    ////// Calculate input A data range for a specific tile
    ////inline std::pair<int, int> get_input_A_range(int tile_row, int tile_col, 
    ////                                    int M, int K,
    ////                                    int num_tile_rows, int num_tile_cols) {
    ////    auto partition = get_partition(tile_row, 0, M, K, num_tile_rows, 1);
    ////    return {partition.start_row * K, (partition.end_row * K) - 1};
    ////}
    ////
    ////// Calculate input B data range for a specific tile
    ////inline std::pair<int, int> get_input_B_range(int tile_row, int tile_col, 
    ////                                    int K, int N,
    ////                                    int num_tile_rows, int num_tile_cols) {
    ////    auto partition = get_partition(0, tile_col, K, N, 1, num_tile_cols);
    ////    return {partition.start_col, partition.end_col - 1};
    ////}
    ////
    ////// Calculate output data range for a specific tile
    ////inline std::pair<int, int> get_output_C_range(int tile_row, int tile_col, 
    ////                                     int M, int N, int K,
    ////                                     int num_tile_rows, int num_tile_cols) {
    ////    auto p_a = get_partition(tile_row, 0, M, K, num_tile_rows, 1);
    ////    auto p_b = get_partition(0, tile_col, K, N, 1, num_tile_cols);
    ////    
    ////    int start_idx = p_a.start_row * N + p_b.start_col;
    ////    int end_idx = (p_a.end_row - 1) * N + (p_b.end_col - 1);
    ////    
    ////    return {start_idx, end_idx};
    ////}
}

#endif // MULTI_TILE_HELPER_H
