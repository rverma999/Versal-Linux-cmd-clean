// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
/*  (c) Copyright 2021 - 2022 Xilinx, Inc. All rights reserved.

    This file contains confidential and proprietary information
    of Xilinx, Inc. and is protected under U.S. and
    international copyright and other intellectual property
    laws.

    DISCLAIMER
    This disclaimer is not a license and does not grant any
    rights to the materials distributed herewith. Except as
    otherwise provided in a valid license issued to you by
    Xilinx, and to the maximum extent permitted by applicable
    law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
    WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
    AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
    BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
    INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
    (2) Xilinx shall not be liable (whether in contract or tort,
    including negligence, or under any other theory of
    liability) for any loss or damage of any kind or nature
    related to, arising under or in connection with these
    materials, including for any direct, or any indirect,
    special, incidental, or consequential loss or damage
    (including loss of data, profits, goodwill, or any type of
    loss or damage suffered as a result of any action brought
    by a third party) even if such damage or loss was
    reasonably foreseeable or Xilinx had been advised of the
    possibility of the same.

    CRITICAL APPLICATIONS
    Xilinx products are not designed or intended to be fail-
    safe, or for use in any application requiring fail-safe
    performance, such as life-support or safety devices or
    systems, Class III medical devices, nuclear facilities,
    applications related to the deployment of airbags, or any
    other applications that could lead to death, personal
    injury, or severe property or environmental damage
    (individually and collectively, "Critical
    Applications"). Customer assumes the sole risk and
    liability of any use of Xilinx products in Critical
    Applications, subject only to applicable laws and
    regulations governing limitations on product liability.

    THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
    PART OF THIS FILE AT ALL TIMES.                       */


#pragma once

#ifndef __AIE_API_DETAIL_AIE1_FFT_DIT_HPP__
#define __AIE_API_DETAIL_AIE1_FFT_DIT_HPP__

namespace aie::detail {

    template <unsigned Vectorization, typename Input, typename Output, typename Twiddle>
    struct fft_dit_stage<2, Vectorization, Input, Output, Twiddle>
    {
        static constexpr unsigned radix = 2;

        __aie_inline
        static void run(const Input * __restrict x,
                        const Twiddle * __restrict tw0,
                        unsigned n, unsigned shift_tw, unsigned shift, bool inv, Output * __restrict out)
        {
            using FFT = fft_dit<Vectorization, fft_get_stage<Vectorization, radix, Input, Output, Twiddle>(), radix, Input, Output, Twiddle>;
            using iterator = restrict_vector_iterator<Output, FFT::out_vector_size, 1, aie_dm_resource::none>;

            FFT fft(shift_tw, shift, inv);

            int block_size = FFT::block_size(n);

            auto it_stage = fft.begin_stage(x, tw0);
            auto it_out0  = iterator(out);
            auto it_out1  = iterator(out + n / radix);

            for (int j = 0; j < block_size; ++j)
                chess_prepare_for_pipelining
                chess_loop_range(1,)
            {
                const auto out = fft.dit(*it_stage++);
                *it_out0++ = out[0];
                *it_out1++ = out[1];
            }
        }
    };

    template <unsigned Vectorization, typename Input, typename Output, typename Twiddle>
    struct fft_dit_stage<3, Vectorization, Input, Output, Twiddle>
    {
        static constexpr unsigned radix = 3;
        static constexpr unsigned one_third_Q15 = 10923;

        __aie_inline
        static void run(const Input * __restrict x,
                        const Twiddle * __restrict tw0,
                        const Twiddle * __restrict tw1,
                        unsigned n, unsigned shift_tw, unsigned shift, bool inv, Output * __restrict out)
        {
            using FFT = fft_dit<Vectorization, fft_get_stage<Vectorization, radix, Input, Output, Twiddle>(), radix, Input, Output, Twiddle>;
            using iterator = restrict_vector_iterator<Output, FFT::out_vector_size, 1, aie_dm_resource::none>;

            FFT fft(shift_tw, shift, inv);

            //Output locations are separated by n / Radix elements
            unsigned n_div_3 = (n * one_third_Q15) >> 15; 
            int block_size   = FFT::block_size(n);

            auto it_stage = fft.begin_stage(x, tw0, tw1);
            auto it_out0  = iterator(out);
            auto it_out1  = iterator(out +     n_div_3);
            auto it_out2  = iterator(out + 2 * n_div_3);

            for (int j = 0; j < block_size; ++j)
                chess_prepare_for_pipelining
                chess_loop_range(1,)
            {
                const auto out = fft.dit(*it_stage++);
                *it_out0++ = out[0];
                *it_out1++ = out[1];
                *it_out2++ = out[2];
            }
        }
    };

    template <unsigned Vectorization, typename Input, typename Output, typename Twiddle>
    struct fft_dit_stage<4, Vectorization, Input, Output, Twiddle>
    {
        static constexpr unsigned radix = 4;

        __aie_inline
        static void run(const Input * __restrict x,
                        const Twiddle * __restrict tw0,
                        const Twiddle * __restrict tw1,
                        const Twiddle * __restrict /*tw2*/,
                        unsigned n, unsigned shift_tw, unsigned shift, bool inv, Output * out)
        {
            using FFT = fft_dit<Vectorization, fft_get_stage<Vectorization, radix, Input, Output, Twiddle>(), radix, Input, Output, Twiddle>;
            using iterator = restrict_vector_iterator<Output, FFT::out_vector_size, 1, aie_dm_resource::none>;

            FFT fft(shift_tw, shift, inv);

            int block_size = FFT::block_size(n);

            auto it_stage  = fft.begin_stage(x, tw0, tw1);
            
            if constexpr (Vectorization == 1) {
                auto it_out0  = iterator(out);
                auto it_out1  = iterator(out +     n / radix);
                auto it_out2  = iterator(out + 2 * n / radix);
                auto it_out3  = iterator(out + 3 * n / radix);

                for (int j = 0; j < block_size; ++j)
                    chess_prepare_for_pipelining
                    chess_loop_range(1,)
                {
                    const auto out = fft.dit(*it_stage++);
                    *it_out0++ = out[0];
                    *it_out1++ = out[1];
                    *it_out2++ = out[2];
                    *it_out3++ = out[3];
                }
            }
            else { //Currently worse performance if using the 4 pointer version on Vectorization > 1
                auto it_out0  = iterator(out);
                auto it_out1  = iterator(out + 2 * n / radix);

                for (int j = 0; j < block_size; ++j)
                    chess_prepare_for_pipelining
                    chess_loop_range(1,)
                {
                    const auto out = fft.dit(*it_stage++);
                    *it_out0 = out[0]; it_out0 +=  block_size;
                    *it_out0 = out[1]; it_out0 += -block_size + 1;
                    *it_out1 = out[2]; it_out1 +=  block_size;
                    *it_out1 = out[3]; it_out1 += -block_size + 1;
                }
            }
        }
    };

    template <unsigned Vectorization, typename Input, typename Output, typename Twiddle>
    struct fft_dit_stage<5, Vectorization, Input, Output, Twiddle>
    {
        static constexpr unsigned radix = 5;

        __aie_inline
        static void run(const Input * __restrict x,
                        const Twiddle * __restrict tw0,
                        const Twiddle * __restrict tw1,
                        const Twiddle * __restrict tw2,
                        const Twiddle * __restrict tw3,
                        unsigned n, unsigned shift_tw, unsigned shift, bool inv, Output * __restrict out)
        {
            using FFT = fft_dit<Vectorization, fft_get_stage<Vectorization, radix, Input, Output, Twiddle>(), radix, Input, Output, Twiddle>;
            using iterator = restrict_vector_iterator<Output, FFT::out_vector_size, 1, aie_dm_resource::none>;

            FFT fft(shift_tw, shift, inv);

            //Output locations are separated by n / Radix elements, divide by the vector size used by the iterator
            int block_size = FFT::block_size(n);

            auto it_stage = fft.begin_stage(x, tw0, tw1, tw2, tw3);
            auto it_out  = iterator(out);

            for (int j = 0; j < block_size; ++j)
                chess_prepare_for_pipelining
                chess_loop_range(1,)
            {
                const auto out = fft.dit(*it_stage++);
                *it_out = out[0]; it_out +=    block_size;
                *it_out = out[1]; it_out +=    block_size;
                *it_out = out[2]; it_out +=    block_size;
                *it_out = out[3]; it_out +=    block_size;
                *it_out = out[4]; it_out += -4*block_size + 1;
            }
        }
    };
}

#include "fft_dit_acc48.hpp"
#include "fft_dit_acc80.hpp"
#include "fft_dit_acc32_fp.hpp"

#endif
