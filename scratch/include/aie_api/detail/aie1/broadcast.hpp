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

#ifndef __AIE_API_DETAIL_AIE1_BROADCAST__HPP__
#define __AIE_API_DETAIL_AIE1_BROADCAST__HPP__

#include "../vector.hpp"

namespace aie::detail {

template <typename T, unsigned Elems>
struct broadcast_bits_impl<8, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static vector_type run(const T &a)
    {
        const utils::pack2<T> p(a, a);
        return vector_cast<T>(broadcast_bits_impl<16, int16, Elems / 2>::run(p.template as<int16>()));
    }

    template <unsigned Elems2>
    static vector_type run(vector_elem_const_ref<T, Elems2> a)
    {
        return run(a.get());
    }
};

template <typename T, unsigned Elems>
struct broadcast_bits_impl<16, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static vector_type run(const T &a)
    {
        constexpr unsigned native_broadcast_elems = 32;
        using native_broadcast_type = broadcast_bits_impl<16, T, native_broadcast_elems>;

        vector_type ret;

        if constexpr (Elems == 8) {
            ret = native_broadcast_type::run(a).template extract<Elems>(0);
        }
        else if constexpr (Elems == 16) {
            ret = native_broadcast_type::run(a).template extract<Elems>(0);
        }
        else if constexpr (Elems == 32) {
            const vector_type tmp(a);
            ret = run<Elems>(tmp[0]);
        }
        else if constexpr (Elems == 64) {
            const auto tmp = native_broadcast_type::run(a);
            ret = concat_vector(tmp, tmp);
        }

        return ret;
    }

    template <unsigned Elems2>
    static vector_type run(vector_elem_const_ref<T, Elems2> a)
    {
        if constexpr (Elems2 == 64) {
            if (__builtin_constant_p(a.offset)) {
                vector<T, 32> tmp;

                if (a.offset < 32)
                    tmp = broadcast_bits_impl<16, T, 32>::run(a.parent.template extract<32>(0)[a.offset]);
                else
                    tmp = broadcast_bits_impl<16, T, 32>::run(a.parent.template extract<32>(1)[a.offset - 32]);

                return concat_vector(tmp, tmp);
            }
            else {
                return run(a.get());
            }
        }
        else {
            const unsigned odd = a.offset & 0x1;
            const int offset = a.offset - odd;
            const int square = 0x1111 * odd;

            const vector<T, 32> tmp = ::shuffle32(a.parent.template grow<32>(), offset, 0x00000000, 0x00000000, square);

            return tmp.template extract<Elems>(0);
        }
    }
};

template <typename T, unsigned Elems>
struct broadcast_bits_impl<32, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static vector_type run(const T &a)
    {
        constexpr unsigned native_broadcast_elems = 16;
        using native_broadcast_type = broadcast_bits_impl<32, T, native_broadcast_elems>;

        vector_type ret;

        if constexpr (Elems == 4) {
            ret = native_broadcast_type::run(a).template extract<Elems>(0);
        }
        else if constexpr (Elems == 8) {
            ret = native_broadcast_type::run(a).template extract<Elems>(0);
        }
        else if constexpr (Elems == 16) {
            const vector_type tmp(a);
            ret = run<Elems>(tmp[0]);
        }
        else if constexpr (Elems == 32) {
            const auto tmp = native_broadcast_type::run(a);
            ret = concat_vector(tmp, tmp);
        }

        return ret;
    }

    template <unsigned Elems2>
    static vector_type run(vector_elem_const_ref<T, Elems2> a)
    {
        if constexpr (Elems2 == 32) {
            if (__builtin_constant_p(a.offset)) {
                vector<T, 16> tmp;

                if (a.offset < 16)
                    tmp = broadcast_bits_impl<32, T, 16>::run(a.parent.template extract<16>(0)[a.offset]);
                else
                    tmp = broadcast_bits_impl<32, T, 16>::run(a.parent.template extract<16>(1)[a.offset - 16]);

                return concat_vector(tmp, tmp);
            }
            else {
                return run(a.get());
            }
        }
        else {
            vector<T, 16> tmp;

            if constexpr (vector_type::is_floating_point())
                tmp = ::fpshuffle16(a.parent.template grow<16>(), a.offset, 0x00000000, 0x00000000);
            else
                tmp = ::shuffle16(  a.parent.template grow<16>(), a.offset, 0x00000000, 0x00000000);

            return tmp.template extract<Elems>(0);
        }
    }
};

template <typename T, unsigned Elems>
struct broadcast_bits_impl<64, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static vector_type run(const T &a)
    {
        constexpr unsigned native_broadcast_elems = 8;
        using native_broadcast_type = broadcast_bits_impl<64, T, native_broadcast_elems>;

        vector_type ret;

        if constexpr (Elems == 2) {
            ret = native_broadcast_type::run(a).template extract<Elems>(0);
        }
        else if constexpr (Elems == 4) {
            ret = native_broadcast_type::run(a).template extract<Elems>(0);
        }
        else if constexpr (Elems == 8) {
            const vector_type tmp(a);
            ret = run<Elems>(tmp[0]);
        }
        else if constexpr (Elems == 16) {
            const auto tmp = native_broadcast_type::run(a);
            ret = concat_vector(tmp, tmp);
        }

        return ret;
    }

    template <unsigned Elems2>
    static vector_type run(vector_elem_const_ref<T, Elems2> a)
    {
        if constexpr (Elems2 == 16) {
            if (__builtin_constant_p(a.offset)) {
                vector<T, 8> tmp;

                if (a.offset < 8)
                    tmp = broadcast_bits_impl<64, T, 8>::run(a.parent.template extract<8>(0)[a.offset]);
                else
                    tmp = broadcast_bits_impl<64, T, 8>::run(a.parent.template extract<8>(1)[a.offset - 8]);

                return concat_vector(tmp, tmp);
            }
            else {
                return run(a.get());
            }
        }
        else {
            vector<T, 8> tmp;

            if constexpr (vector_type::is_floating_point())
                tmp = ::fpshuffle8(a.parent.template grow<8>(), a.offset, 0x00000000);
            else
                tmp = ::shuffle8(  a.parent.template grow<8>(), a.offset, 0x00000000);

            return tmp.template extract<Elems>(0);
        }
    }
};


}

#endif
