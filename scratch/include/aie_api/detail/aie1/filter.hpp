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

#ifndef __AIE_API_DETAIL_AIE1_FILTER__HPP__
#define __AIE_API_DETAIL_AIE1_FILTER__HPP__

#include "../vector.hpp"

namespace aie::detail {

template <typename T, unsigned Elems, FilterOp Op>
struct filter_bits_impl<8, T, Elems, Op>
{
    using        vector_type = vector<T, Elems>;
    using return_vector_type = vector<T, Elems / 2>;

    static return_vector_type run(const vector_type &v, unsigned step)
    {
        if (step > 1) {
            return filter_bits_impl<16, int16, Elems / 2, Op>::run(vector_cast<int16>(v), step / 2).template cast_to<T>();
        }
        else {
            if constexpr (Elems <= 64) {
                return filter_bits_impl<16, int16, Elems, Op>::run(v.unpack(), step).template pack<T>();
            }
            else {
                return_vector_type ret;

                ret.insert(0, filter_bits_impl<16, int16, Elems / 2, Op>::run(v.template extract<64>(0).unpack(), step).template pack<T>());
                ret.insert(1, filter_bits_impl<16, int16, Elems / 2, Op>::run(v.template extract<64>(1).unpack(), step).template pack<T>());

                return ret;
            }
        }
    }
};

template <typename T, unsigned Elems, FilterOp Op>
struct filter_bits_impl<16, T, Elems, Op>
{
    using        vector_type = vector<T, Elems>;
    using return_vector_type = vector<T, Elems / 2>;

    static constexpr unsigned get_start(unsigned step)
    {
        if constexpr (Op == FilterOp::Even) return 0;
        if constexpr (Op == FilterOp::Odd)  return step;
    }

    static constexpr unsigned get_offset(unsigned step)
    {
        unsigned offset = 0;
        unsigned v = 0;

        for (unsigned i = 0; i < 8; ) {
            for (unsigned j = 0; j < std::min(step, 8u); ++j)
                offset |= (v++ << (i++ * 4));

            v += std::min(step, 8u);
        }

        return offset;
    }

    static return_vector_type run(const vector_type &v, unsigned step)
    {
        if (step > 1)
            return filter_bits_impl<32, int32, Elems / 2, Op>::run(vector_cast<int32>(v), step / 2).template cast_to<T>();

        constexpr unsigned square1 = Op == FilterOp::Even? 0x0020 : 0x0031;
        constexpr unsigned square2 = Op == FilterOp::Even? 0x2000 : 0x3100;

        if constexpr (Elems <= 32) {
            const vector<T, 32> tmp = ::select32(0xcccccccc, v.template grow<32>(), 0, 0x0c080400, 0x00000000, square1,
                                                                                    4, 0x0c080400, 0x00000000, square2);

            return tmp.template extract<Elems / 2>(0);
        }
        else if constexpr (Elems == 64) {
            return_vector_type ret;
            vector<T, 32> tmp ;

            tmp = ::select32(0xcccccccc, v.template extract<32>(0), 0, 0x0c080400, 0x00000000, square1,
                                                                    4, 0x0c080400, 0x00000000, square2);
            ret.insert(0, tmp.template extract<16>(0));
            tmp = ::select32(0xcccccccc, v.template extract<32>(1), 0, 0x0c080400, 0x00000000, square1,
                                                                    4, 0x0c080400, 0x00000000, square2);
            ret.insert(1, tmp.template extract<16>(0));

            return ret;
        }
    }
};

template <typename T, unsigned Elems, FilterOp Op>
struct filter_bits_impl<32, T, Elems, Op>
{
    using        vector_type = vector<T, Elems>;
    using return_vector_type = vector<T, Elems / 2>;

    static constexpr auto get_op()
    {
        if constexpr (vector_type::is_floating_point()) return [](auto &&...params) { return ::fpshuffle16(params...); };
        else                                            return [](auto &&...params) { return ::shuffle16(params...); };
    }

    static constexpr unsigned get_start(unsigned step)
    {
        if constexpr (Op == FilterOp::Even) return 0;
        if constexpr (Op == FilterOp::Odd)  return step;
    }

    static constexpr unsigned get_offset(unsigned step)
    {
        unsigned offset = 0;
        unsigned v = 0;

        for (unsigned i = 0; i < 8; ) {
            for (unsigned j = 0; j < std::min(step, 8u); ++j)
                offset |= (v++ << (i++ * 4));

            v += std::min(step, 8u);
        }

        return offset;
    }

    static return_vector_type run(const vector_type &v, unsigned step)
    {
        constexpr auto op = get_op();

        const unsigned  start = get_start(step);
        const unsigned offset = get_offset(step);

        if constexpr (Elems <= 16) {
            const vector<T, 16> tmp = op(v.template grow<16>(), start, offset, 0x00000000);

            return tmp.template extract<Elems / 2>(0);
        }
        else if constexpr (Elems == 32) {
            if (step == 16) {
                if constexpr (Op == FilterOp::Even) return v.template extract<16>(0);
                if constexpr (Op == FilterOp::Odd)  return v.template extract<16>(1);
            }

            return_vector_type ret;

            vector<T, 16> tmp;

            tmp = op(v.template extract<16>(0), start, offset, 0x00000000);
            ret.template insert<8>(0, tmp.template extract<8>(0));
            tmp = op(v.template extract<16>(1), start, offset, 0x00000000);
            ret.template insert<8>(1, tmp.template extract<8>(0));

            return ret;
        }
    }
};

template <typename T, unsigned Elems, FilterOp Op>
struct filter_bits_impl<64, T, Elems, Op>
{
    using        vector_type = vector<T, Elems>;
    using return_vector_type = vector<T, Elems / 2>;

    static constexpr auto get_op()
    {
        if constexpr (vector_type::is_floating_point()) return [](auto &&...params) { return ::fpshuffle8(params...); };
        else                                            return [](auto &&...params) { return ::shuffle8(params...); };
    }

    static constexpr unsigned get_start(unsigned step)
    {
        if constexpr (Op == FilterOp::Even) return 0;
        if constexpr (Op == FilterOp::Odd)  return step;
    }

    static constexpr unsigned get_offset(unsigned step)
    {
        unsigned offset = 0;
        unsigned v = 0;

        for (unsigned i = 0; i < 8; ) {
            for (unsigned j = 0; j < std::min(step, 8u); ++j)
                offset |= (v++ << (i++ * 4));

            v += std::min(step, 8u);
        }

        return offset;
    }

    static return_vector_type run(const vector_type &v, unsigned step)
    {
        constexpr auto op = get_op();

        const unsigned  start = get_start(step);
        const unsigned offset = get_offset(step);

        if constexpr (Elems <= 8) {
            const vector<T, 8> tmp = op(v.template grow<8>(), start, offset);

            return tmp.template extract<Elems / 2>(0);
        }
        else if constexpr (Elems == 16) {
            if (step == 8) {
                if constexpr (Op == FilterOp::Even) return v.template extract<8>(0);
                if constexpr (Op == FilterOp::Odd)  return v.template extract<8>(1);
            }

            return_vector_type ret;

            vector<T, 8> tmp;

            tmp = op(v.template extract<8>(0), start, offset);
            ret.template insert<4>(0, tmp.template extract<4>(0));
            tmp = op(v.template extract<8>(1), start, offset);
            ret.template insert<4>(1, tmp.template extract<4>(0));

            return ret;
        }
    }
};

}

#endif
