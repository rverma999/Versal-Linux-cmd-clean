// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
/*  (c) Copyright 2020 - 2022 Xilinx, Inc. All rights reserved.

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

#ifndef __AIE_API_DETAIL_AIE2_MUL_REDUCE__HPP__
#define __AIE_API_DETAIL_AIE2_MUL_REDUCE__HPP__

#include "../interleave.hpp"

namespace aie::detail {

template <typename T, unsigned Elems>
struct mul_reduce_bits_impl<8, 32, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static T run(const vector_type &v)
    {
        T ret;

        if constexpr (Elems == 16 || Elems == 32) {
            vector_type tmp1 = v;

            for (unsigned s = Elems / 2; s > 0; s /= 2) {
                vector_type tmp2;

                std::tie(tmp1, tmp2) = interleave_unzip<T, Elems>::run(tmp1, vector_type(), s);

                tmp1 = mul<MulMacroOp::Mul, 32, T, T>::run(tmp1, tmp2).template to_vector<T>();
            }

            ret = tmp1[0];
        }
        else if constexpr (Elems == 64) {
            vector_type tmp1 = v;

            #pragma unroll
            for (unsigned s = Elems / 2; s > 0; s /= 2) {
                vector_type tmp2;

                std::tie(tmp1, tmp2) = interleave_unzip<T, Elems>::run(tmp1, vector_type(), s);

                tmp1 = mul<MulMacroOp::Mul, 32, T, T>::run(tmp1, tmp2).template to_vector<T>();
            }

            ret = tmp1[0];
        }
        else if constexpr (Elems == 128) {
            T a = mul_reduce<32, T, Elems / 2>::run(v.template extract<Elems / 2>(0));
            T b = mul_reduce<32, T, Elems / 2>::run(v.template extract<Elems / 2>(1));

            ret = a * b;
        }

        return ret;
    }
};

template <typename T, unsigned Elems>
struct mul_reduce_bits_impl<16, 32, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static T run(const vector_type &v)
    {
        T ret;

        if constexpr (Elems == 8 || Elems == 16) {
            vector_type tmp1 = v;

            for (unsigned s = Elems / 2; s > 0; s /= 2) {
                vector_type tmp2;

                std::tie(tmp1, tmp2) = interleave_unzip<T, Elems>::run(tmp1, vector_type(), s);

                tmp1 = mul<MulMacroOp::Mul, 32, T, T>::run(tmp1, tmp2).template to_vector<T>();
            }

            ret = tmp1[0];
        }
        else if constexpr (Elems == 32) {
            vector_type tmp1 = v;

            #pragma unroll
            for (unsigned s = Elems / 2; s > 0; s /= 2) {
                vector_type tmp2;

                std::tie(tmp1, tmp2) = interleave_unzip<T, Elems>::run(tmp1, vector_type(), s);

                tmp1 = mul<MulMacroOp::Mul, 32, T, T>::run(tmp1, tmp2).template to_vector<T>();
            }

            ret = tmp1[0];
        }
        else if constexpr (Elems == 64) {
            T a = mul_reduce<32, T, Elems / 2>::run(v.template extract<Elems / 2>(0));
            T b = mul_reduce<32, T, Elems / 2>::run(v.template extract<Elems / 2>(1));

            ret = a * b;
        }

        return ret;
    }
};

// Re-enable when emulated suppport for 32-bit x 32-bit mul is added
#if 0
template <typename T, unsigned Elems>
struct mul_reduce_bits_impl<32, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static T run(const vector_type &v)
    {
        T ret;

        if constexpr (Elems == 8) {
            vector_type tmp1 = v;

            for (unsigned s = 4; s > 0; s /= 2) {
                vector_type tmp2;

                std::tie(tmp1, tmp2) = interleave_unzip<T, 8>::run(tmp1, vector_type(), s);

                tmp1 = mul_bits_impl<32, T, 8>::run(tmp1, tmp2).to_vector();
            }

            ret = tmp1[0];
        }
        else if constexpr (Elems == 16) {
            vector<T, Elems / 2> tmp = mul_bits_impl<32, T, Elems / 2>::run(v.template extract<Elems / 2>(0),
                                                                            v.template extract<Elems / 2>(1)).to_vector();
            ret = mul_reduce_bits_impl<32, T, Elems / 2>::run(tmp);
        }
        else if constexpr (Elems == 32) {
            vector<T, Elems / 4> tmp1 = mul_bits_impl<32, T, Elems / 4>::run(v.template extract<Elems / 4>(0),
                                                                             v.template extract<Elems / 4>(1)).to_vector();
            vector<T, Elems / 4> tmp2 = mul_bits_impl<32, T, Elems / 4>::run(v.template extract<Elems / 4>(2),
                                                                             v.template extract<Elems / 4>(3)).to_vector();

            tmp1 = mul_bits_impl<32, T, Elems / 4>::run(tmp1, tmp2).to_vector();

            ret = mul_reduce_bits_impl<32, T, Elems / 4>::run(tmp1);
        }

        return ret;
    }
};
#endif

}

#endif
