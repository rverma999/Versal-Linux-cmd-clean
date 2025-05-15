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

#ifndef __AIE_API_DETAIL_AIE1_TRANSPOSE__HPP__
#define __AIE_API_DETAIL_AIE1_TRANSPOSE__HPP__

namespace aie::detail {

template <typename T, unsigned Elems>
struct transpose_bits_impl<32, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static constexpr auto get_shuffle_op()
    {
        if constexpr (std::is_same_v<T, float>) return [](auto &&... args) __aie_inline { return ::fpshuffle16(args...); };
        else                                    return [](auto &&... args) __aie_inline { return ::shuffle16(args...); };
    }

    static constexpr auto get_select_op()
    {
        if constexpr (std::is_same_v<T, float>) return [](auto &&... args) __aie_inline { return ::fpselect16(args...); };
        else                                    return [](auto &&... args) __aie_inline { return ::select16(args...); };
    }

    __aie_inline
    static vector_type run(const vector_type &v, unsigned row, unsigned col)
    {
        vector_type ret;

        constexpr auto op     = get_shuffle_op();
        constexpr auto op_sel = get_select_op();

        if constexpr (Elems == 4) {
            vector<T, 16> tmp;

            // 0x3210 if row == 1 or row == 4
            // 0x3120 if row == 2
            const unsigned offset = 0x3210 - 0x78 * (row & 0x2);

            tmp = op(v.template grow<16>(), 0, offset, 0x0);

            return tmp.template extract<4>(0);
        }
        else if constexpr (Elems == 8) {
            vector<T, 16> tmp;

            unsigned mask = row == 2 ? 0x73625140
                          : row == 4 ? 0x75316420
                                     : 0x76543210;

            tmp = op(v.template grow<16>(), 0, mask, 0x0);

            return tmp.template extract<8>(0);
        }
        else if constexpr (Elems == 16) {
            auto [mask1, mask2] = row == 2 ? std::array{0xb3a29180u, 0xf7e6d5c4u} :
                                  row == 4 ? std::array{0xd951c840u, 0xfb73ea62u} :
                                  row == 8 ? std::array{0xeca86420u, 0xfdb97531u} :
                                             std::array{0x76543210u, 0xfedcba98u};

            return op(v, 0, mask1, mask2);
        }
        else if constexpr (Elems == 32) {
            vector<T, 32> tmp;

            if (row == 2) {
                tmp.template insert<16>(0, op_sel(0xaaaa,
                                                  v.template extract<16>(0), 0, 0x03020100, 0x07060504,
                                                  v.template extract<16>(1), 0, 0x30201000, 0x70605040));
                tmp.template insert<16>(1, op_sel(0xaaaa,
                                                  v.template extract<16>(0), 8, 0x03020100, 0x07060504,
                                                  v.template extract<16>(1), 8, 0x30201000, 0x70605040));
                return tmp;
            }
            else if (row == 4) {
                tmp.template insert<16>(0, op_sel(0xcccc,
                                                  v.template extract<16>(0), 0, 0x00910080, 0x00b300a2,
                                                  v.template extract<16>(1), 0, 0x91008000, 0xb300a200));
                tmp.template insert<16>(1, op_sel(0xcccc,
                                                  v.template extract<16>(0), 4, 0x00910080, 0x00b300a2,
                                                  v.template extract<16>(1), 4, 0x91008000, 0xb300a200));
                return tmp;
            }
            else if (row == 8) {
                tmp.template insert<16>(0, op_sel(0xf0f0,
                                                  v.template extract<16>(0), 0, 0x0000c840, 0x0000d951,
                                                  v.template extract<16>(1), 0, 0xc8400000, 0xd9510000));
                tmp.template insert<16>(1, op_sel(0xf0f0,
                                                  v.template extract<16>(0), 2, 0x0000c840, 0x0000d951,
                                                  v.template extract<16>(1), 2, 0xc8400000, 0xd9510000));
                return tmp;
            }
            else if (row == 16) {
                tmp.template insert<16>(0, op_sel(0xff00,
                                                  v.template extract<16>(0), 0, 0xeca86420, 0x00000000,
                                                  v.template extract<16>(1), 0, 0x00000000, 0xeca86420));
                tmp.template insert<16>(1, op_sel(0xff00,
                                                  v.template extract<16>(0), 1, 0xeca86420, 0x00000000,
                                                  v.template extract<16>(1), 1, 0x00000000, 0xeca86420));
                return tmp;
            }
            else {
                return v;
            }
        }

    }
};

template <typename T, unsigned Elems>
struct transpose_bits_impl<64, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static constexpr auto get_shuffle_op()
    {
        if constexpr (std::is_same_v<T, cfloat>) return [](auto &&... args) __aie_inline { return ::fpshuffle8(args...); };
        else                                     return [](auto &&... args) __aie_inline { return ::shuffle8(args...); };
    }

    static constexpr auto get_select_op()
    {
        if constexpr (std::is_same_v<T, cfloat>) return [](auto &&... args) __aie_inline { return ::fpselect8(args...); };
        else                                     return [](auto &&... args) __aie_inline { return ::select8(args...); };
    }

    __aie_inline
    static vector_type run(const vector_type &v, unsigned row, unsigned col)
    {
        vector_type ret;

        constexpr auto op     = get_shuffle_op();
        constexpr auto op_sel = get_select_op();

        if constexpr (Elems == 2) {
            return v;
        }
        else if constexpr (Elems == 4) {
            vector<T, 8> tmp;

            if (row == 2) {
                tmp = op(v.template grow<8>(), 0, 0x3120);
                return tmp.template extract<4>(0);
            }
            else {
                return v;
            }
        }
        else if constexpr (Elems == 8) {
            vector<T, 8> tmp;

            if (row == 2) {
                tmp = op(v, 0, 0x73625140);
                return tmp;
            }
            else if (row == 4) {
                tmp = op(v, 0, 0x75316420);
                return tmp;
            }
            else {
                return v;
            }
        }
        else if constexpr (Elems == 16) {
            vector<T, 16> tmp;

            if (row == 2) {
                tmp.template insert<8>(0, op_sel(0xaa,
                                                 v.template extract<8>(0), 0, 0x03020100,
                                                 v.template extract<8>(1), 0, 0x30201000));
                tmp.template insert<8>(1, op_sel(0xaa,
                                                 v.template extract<8>(0), 4, 0x03020100,
                                                 v.template extract<8>(1), 4, 0x30201000));
                return tmp;
            }
            else if (row == 4) {
                tmp.template insert<8>(0, op_sel(0xcc,
                                                 v.template extract<8>(0), 0, 0x00510040,
                                                 v.template extract<8>(1), 0, 0x51004000));
                tmp.template insert<8>(1, op_sel(0xcc,
                                                 v.template extract<8>(0), 2, 0x00510040,
                                                 v.template extract<8>(1), 2, 0x51004000));
                return tmp;
            }
            else if (row == 8) {
                tmp.template insert<8>(0, op_sel(0xf0,
                                                 v.template extract<8>(0), 0, 0x00006420,
                                                 v.template extract<8>(1), 0, 0x64200000));

                tmp.template insert<8>(1, op_sel(0xf0,
                                                 v.template extract<8>(0), 1, 0x00006420,
                                                 v.template extract<8>(1), 1, 0x64200000));
                return tmp;
            }
            else {
                return v;
            }
        }
    }
};


}

#endif
