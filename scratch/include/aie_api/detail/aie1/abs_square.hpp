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

#ifndef __AIE_API_DETAIL_AIE1_ABS_SQUARE__HPP__
#define __AIE_API_DETAIL_AIE1_ABS_SQUARE__HPP__

#include "../../accum.hpp"
#include "../../vector.hpp"

namespace aie::detail {

template <typename TR, unsigned Elems>
struct abs_square_bits_impl<cint16, TR, Elems>
{
    using vector_type = vector<cint16, Elems>;
    using comp_type   = vector<int16,  Elems * 2>;
    using return_type = vector<TR,     Elems>;

    template <unsigned Lanes>
    using  accum_type = accum<acc48, Lanes>;

    static return_type run(const vector_type &v, int shift)
    {
        comp_type tmp = v.template cast_to<int16>();

        if      constexpr (Elems < 32) {
            accum_type<16> acc = ::mul16(tmp.template grow<32>(), 0, 0x06040200, 0x0e0c0a08, 0x3210, 0, 0x06040200, 0x0e0c0a08, 0x3210);

            return (acc.template to_vector<TR>(shift)).template extract<Elems>(0);
        }
        else if constexpr (Elems == 32) {
            return_type res;

            accum_type<16> acc1 = ::mul16(tmp.template extract<32>(0), 0, 0x06040200, 0x0e0c0a08, 0x3210, 0, 0x06040200, 0x0e0c0a08, 0x3210);
            accum_type<16> acc2 = ::mul16(tmp.template extract<32>(1), 0, 0x06040200, 0x0e0c0a08, 0x3210, 0, 0x06040200, 0x0e0c0a08, 0x3210);

            res.insert(0, acc1.template to_vector<TR>(shift));
            res.insert(1, acc2.template to_vector<TR>(shift));
            return res;
        }
    }
};

template <typename TR, unsigned Elems>
struct abs_square_bits_impl<cint32, TR, Elems>
{
    using vector_type = vector<cint32, Elems>;
    using comp_type   = vector<int32,  Elems * 2>;
    using return_type = vector<TR,     Elems>;

    template <unsigned Lanes>
    using  accum_type = accum<acc80, Lanes>;

    static return_type run(const vector_type &v, int shift)
    {
        constexpr unsigned num_mul = Elems / 4;

        comp_type tmp = v.template cast_to<int32>();

        accum_type<Elems> res;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const accum_type<4> tmp_acc = ::lmul4(tmp.template grow_extract<16>(idx / 2),
                                                  (idx % 4) * 8, 0x6420, 1,
                                                  (idx % 4) * 8, 0x6420, 1);
            res.insert(idx, tmp_acc);
        });

        return res.template to_vector<TR>(shift);
    }
};

template <unsigned Elems>
struct abs_square_bits_impl<cfloat, float, Elems>
{
    using vector_type = vector<cfloat, Elems>;
    using comp_type   = vector<float,  Elems * 2>;
    using return_type = vector<float,  Elems>;

    template <unsigned Lanes>
    using  accum_type = accum<accfloat, Lanes>;

    static return_type run(const vector_type &v, int shift)
    {
        constexpr unsigned num_mul = Elems < 8? 1 : Elems / 8;

        comp_type tmp = v.template cast_to<float>();

        accum_type<Elems> res;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            accum_type<8> tmp_acc;

            tmp_acc = ::fpmul(tmp.template grow_extract<16>(idx),
                              0, 0xeca86420,
                              0, 0xeca86420);

            tmp_acc = ::fpmac(tmp_acc,
                              tmp.template grow_extract<16>(idx),
                              1, 0xeca86420,
                              1, 0xeca86420);

            res.insert(idx, tmp_acc.template extract<Elems < 8? Elems : 8>(0));
        });

        return res.template to_vector<float>();
    }
};

}

#endif
