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

#ifndef __AIE_API_DETAIL_AIE2_TRANSPOSE__HPP__
#define __AIE_API_DETAIL_AIE2_TRANSPOSE__HPP__

#include "../vector.hpp"
#include "../utils.hpp"

namespace aie::detail {

template <typename T, unsigned Elems>
struct transpose_bits_impl<4, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, unsigned row, unsigned col)
    {
        using next_type = utils::get_next_integer_type_t<T>;

        if constexpr (Elems <= 128)
            return transpose<next_type, Elems>::run(v.unpack(), row, col).template pack<T>();
        else
            return transpose_bits_scalar<4, T, Elems>::run(v, row, col);
    }
};

template <typename T>
struct transpose_bits_impl<8, T, 128>
{
    static constexpr unsigned Elems = 128;
    using vector_type = vector<T, Elems>;

    static constexpr unsigned  shuffle_modes[8][2] = {
           { T512_1x2_lo,  T512_1x2_lo },
           { T8_2x64_lo,  T512_1x2_lo },
           { T128_4x2_lo, T8_4x16     }, // 4x32 emulated
           { T64_8x2_lo,  T8_8x8      }, // 8x16 emulated
           { T32_16x2_lo, T8_16x4     }, // 16x8 emulated
           { T8_64x2_lo,  T8_64x2_lo  }, // 32x4 emulated, considered as special row (different order of shuffles to others)
           { T8_64x2_lo,  T512_1x2_lo },
           { T512_1x2_lo, T512_1x2_lo }
    };

    static constexpr unsigned special_rows = 32;

    __aie_inline
    static vector_type run(const vector_type &v, unsigned row, unsigned col)
    {
        vector_type ret;

        const unsigned index = utils::ffs(row);

        vector<T, 64> tmp1, tmp2, tmp3, out0, out1;

        // First shuffle with 1024b (hilo) modes used in all cases, bypassed with T512_1x2_lo
        tmp1 = ::shuffle(v.template extract<64>(0), v.template extract<64>(1), shuffle_modes[index][0]);
        tmp2 = ::shuffle(v.template extract<64>(0), v.template extract<64>(1), shuffle_modes[index][0] + 1);

        // Non emulated variants are done now if we can determine the rows at compile time
        if (chess_manifest((row == 2) || (row == 64))) {
            out0 = tmp1;
            out1 = tmp2;
        }
        else {
            //Select input for second shuffle
            int is_special = row == special_rows;
            if (chess_manifest(row)) {
                if   (is_special) tmp3 = tmp1;
                else              tmp3 = tmp2;
            }
            else {
                tmp3 = ::shuffle(tmp2, tmp1, T512_1x2_lo + is_special );
            }

            //Final shuffle with 512b modes (where second vector is ignored) or 1024b (hilo) modes when is_special, bypassed in non emulated modes
            out0 = ::shuffle( tmp1, tmp2, shuffle_modes[index][1]);
            out1 = ::shuffle( tmp3, tmp2, shuffle_modes[index][1] + is_special);
        }

        ret.insert(0, out0);
        ret.insert(1, out1);

        return ret;
    }
};

// 64 and 32 Elems
template <typename T, unsigned Elems>
struct transpose_bits_impl<8, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static constexpr auto shuffle_modes = []{
        if      constexpr (Elems == 64) { return std::array<std::array<unsigned, 2>, 7> { { { T512_1x2_lo, T512_1x2_lo },
                                                                                            { T8_16x4,     T8_8x8      },      //2x32 emulated
                                                                                            { T8_4x16,     T512_1x2_lo },
                                                                                            { T8_8x8,      T512_1x2_lo },
                                                                                            { T8_16x4,     T512_1x2_lo },
                                                                                            { T8_8x8,      T8_4x16     },      //32x2 emulated
                                                                                            { T512_1x2_lo, T512_1x2_lo } } };
        }
        else if constexpr (Elems == 32) { return std::array<std::array<unsigned, 2>, 6> { { { T512_1x2_lo, T512_1x2_lo },
                                                                                            { T8_8x4,      T8_8x4      },      //2x16 emulated
                                                                                            { T8_4x8,      T512_1x2_lo },
                                                                                            { T8_8x4,      T512_1x2_lo },
                                                                                            { T8_4x8,      T8_4x8      },      //16x2 emulated
                                                                                            { T512_1x2_lo, T512_1x2_lo } } };
        }
    }();

    __aie_inline
    static vector_type run(const vector_type &v, unsigned row, unsigned col)
    {
        aie::vector<T, 64> tmp;

        const unsigned index = utils::ffs(row);

        tmp = ::shuffle(v.template grow<64>(), shuffle_modes[index][0]);

        if (chess_manifest(row == 2 || row == Elems / 2) || !chess_const(row)) {
            // Only do the additional operations needed if doing an emulated operation or row cannot be determined
            tmp = ::shuffle(tmp, shuffle_modes[index][1]);
        }


        return tmp.template extract<Elems>(0);
    }
};

template <typename T>
struct transpose_bits_impl<8, T, 16>
{
    static constexpr unsigned Elems = 16;
    using vector_type = vector<T, Elems>;

    static constexpr unsigned shuffle_modes[5][2] = { { T512_1x2_lo, T512_1x2_lo },
                                                      { T8_8x8,      T16_8x4     },   //2x8 emulated
                                                      { T32_4x4,     T8_4x16     },   //4x4 emulated
                                                      { T16_4x8,     T8_8x8      },   //8x2 emulated
                                                      { T512_1x2_lo, T512_1x2_lo } };

    __aie_inline
    static vector_type run(const vector_type &v, unsigned row, unsigned col)
    {
        vector<T, 64>  tmp;

        const unsigned index = utils::ffs(row);

        tmp = ::shuffle(v.template grow<64>(), shuffle_modes[index][0]);
        tmp = ::shuffle(tmp,                   shuffle_modes[index][1]);

        return tmp.template extract<16>(0);
    }
};

template <typename T>
struct transpose_bits_impl<16, T, 64>
{
    static constexpr unsigned Elems = 64;
    using vector_type = vector<T, Elems>;

    static constexpr unsigned shuffle_modes[7][2] = { { T512_1x2_lo, T512_1x2_lo },
                                                      { T16_2x32_lo, T512_1x2_lo },
                                                      { T16_4x16_lo, T512_1x2_lo },
                                                      { T32_8x4_lo,  T16_8x2     },      //8x8 emulated
                                                      { T16_16x4_lo, T512_1x2_lo },
                                                      { T16_32x2_lo, T512_1x2_lo },
                                                      { T512_1x2_lo, T512_1x2_lo } };

    __aie_inline
    static vector_type run(const vector_type &v, unsigned row, unsigned col)
    {
        vector<T, 32> tmp1, tmp2;

        const unsigned index = utils::ffs(row);

        //numerical values of _lo and _hi modes for lower/upper 512b in 1024 transposes are separated by +1
        tmp1 = ::shuffle(v.template extract<32>(0), v.template extract<32>(1), shuffle_modes[index][0]);
        tmp2 = ::shuffle(v.template extract<32>(0), v.template extract<32>(1), shuffle_modes[index][0] + 1);

        if (chess_manifest(row == 8) || !chess_const(row)) {
            // Only do the additional operations needed if doing an emulated 8x8 or row cannot be determined
            // at compile time
            tmp1 = ::shuffle(tmp1, tmp1, shuffle_modes[index][1]);
            tmp2 = ::shuffle(tmp2, tmp2, shuffle_modes[index][1]);
        }

        return concat_vector(tmp1, tmp2);
    }
};

//Elems 32, 16 and 8
template <typename T, unsigned Elems>
struct transpose_bits_impl<16, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static constexpr auto shuffle_modes = []{
        if      constexpr (Elems == 32) return std::array<unsigned, 6>{ T512_1x2_lo, T16_2x16, T16_4x8, T16_8x4, T16_16x2, T512_1x2_lo };
        else if constexpr (Elems == 16) return std::array<unsigned, 5>{ T512_1x2_lo, T16_2x8,  T16_4x4, T16_8x2,           T512_1x2_lo };
        else if constexpr (Elems == 8)  return std::array<unsigned, 4>{ T512_1x2_lo, T16_2x4,  T16_4x2,                    T512_1x2_lo };
    }();

    __aie_inline
    static vector_type run(const vector_type &v, unsigned row, unsigned col)
    {
        vector<T, 32>  tmp;

        const unsigned index = utils::ffs(row);

        tmp = ::shuffle(v.template grow<32>(), shuffle_modes[index]);

        return tmp.template extract<Elems>(0);
    }
};

template <typename T>
struct transpose_bits_impl<32, T, 32>
{
    static constexpr unsigned Elems = 32;
    using vector_type = vector<T, Elems>;

    static constexpr unsigned shuffle_modes[6] = { T512_1x2_lo,
                                                   T32_2x16_lo,
                                                   T32_4x8_lo,
                                                   T32_8x4_lo,
                                                   T32_16x2_lo,
                                                   T512_1x2_lo };

    __aie_inline
    static vector_type run(const vector_type &v, unsigned row, unsigned col)
    {
        vector_type ret;

        const unsigned index = utils::ffs(row);

        vector<T, 16> tmp1, tmp2;

        tmp1 = ::shuffle(v.template extract<16>(0), v.template extract<16>(1), shuffle_modes[index]);
        tmp2 = ::shuffle(v.template extract<16>(0), v.template extract<16>(1), shuffle_modes[index]+1),

        ret.insert(0, tmp1);
        ret.insert(1, tmp2);

        return ret;
    }
};

template <typename T>
struct transpose_bits_impl<32, T, 16>
{
    static constexpr unsigned Elems = 16;

    using vector_type = vector<T, Elems>;

    static constexpr unsigned shuffle_modes[5][2] = { { T512_1x2_lo, T512_1x2_lo },
                                                      { T16_8x2,     T16_4x8     },  // 2x8 emulated
                                                      { T32_4x4,     T512_1x2_lo },
                                                      { T16_8x4,     T16_2x8     },  // 8x2 emulated
                                                      { T512_1x2_lo, T512_1x2_lo } };

    __aie_inline
    static vector_type run(const vector_type &v, unsigned row, unsigned col)
    {
        vector_type ret;

        const unsigned index = utils::ffs(row);

        ret = ::shuffle(v, shuffle_modes[index][0]);

        if (chess_manifest(row != 4) || !chess_const(row))
            ret = ::shuffle(ret, shuffle_modes[index][1]);

        return ret;
    }
};

//Elems 8 and 4
template <typename T, unsigned Elems>
struct transpose_bits_impl<32, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static constexpr auto shuffle_modes = []{
        if      constexpr (Elems == 8) return std::array<std::array<unsigned, 2>, 4>{ { { T512_1x2_lo, T512_1x2_lo }, { T16_4x2, T16_4x4 }, { T16_4x4, T16_2x4 }, { T512_1x2_lo, T512_1x2_lo } } };
        else if constexpr (Elems == 4) return std::array<std::array<unsigned, 2>, 3>{ { { T512_1x2_lo, T512_1x2_lo }, { T16_8x4, T16_8x2 },                       { T512_1x2_lo, T512_1x2_lo } } };
    }();

    __aie_inline
    static vector_type run(const vector_type &v, unsigned row, unsigned col)
    {
        aie::vector<T, 16> tmp;

        const unsigned index = utils::ffs(row);

        tmp = ::shuffle(v.template grow<16>(),   shuffle_modes[index][0]);
        tmp = ::shuffle(tmp,                     shuffle_modes[index][1]);
        if constexpr (Elems == 4) //Additional shuffle needed to emulate 2x2 for 4 elems
            tmp = ::shuffle(tmp , shuffle_modes[index][0]);

        return  tmp.template extract<Elems>(0);
    }
};

template <typename T>
struct transpose_bits_impl<64, T, 16>
{
    static constexpr unsigned Elems = 16;

    using vector_type = vector<T, Elems>;

    static constexpr unsigned shuffle_modes[5][2] = { { T512_1x2_lo, T512_1x2_lo },
                                                      { T64_2x8_lo,  T512_1x2_lo },
                                                      { T16_4x16_lo, T16_4x4     }, // 4x4 emulated
                                                      { T64_8x2_lo,  T512_1x2_lo },
                                                      { T512_1x2_lo, T512_1x2_lo } };

    __aie_inline
    static vector_type run(const vector_type &v, unsigned row, unsigned col)
    {
        vector_type ret;
        vector<T, 8> tmp1, tmp2;

        const unsigned index = utils::ffs(row);

        //numerical values of _lo and _hi modes for lower/upper 512b in 1024 transposes are separated by +1
        tmp1 = ::shuffle(v.template extract<8>(0), v.template extract<8>(1), shuffle_modes[index][0]);
        tmp2 = ::shuffle(v.template extract<8>(0), v.template extract<8>(1), shuffle_modes[index][0] + 1);

        //If row can be determined at compile time we can only do the additional operations needed if doing an emulated 4x4
        if (chess_manifest(row == 4) || !chess_const(row)) {
            // Only do the additional operations needed if doing an emulated 4x4 or row cannot be determined
            // at compile time
            tmp1 = ::shuffle(tmp1, tmp1, shuffle_modes[index][1]);
            tmp2 = ::shuffle(tmp2, tmp2, shuffle_modes[index][1]);
        }

        ret.insert(0, tmp1);
        ret.insert(1, tmp2);

        return ret;
    }
};

//Elems 8 and 4
template <typename T, unsigned Elems>
struct transpose_bits_impl<64, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static constexpr auto shuffle_modes = []{
        if      constexpr (Elems == 8) return std::array<std::array<unsigned, 2>, 4>{ { { T512_1x2_lo, T512_1x2_lo}, {T16_4x4, T16_8x4}, {T16_4x8, T16_4x4}, {T512_1x2_lo, T512_1x2_lo} } };
        else if constexpr (Elems == 4) return std::array<std::array<unsigned, 2>, 3>{ { { T512_1x2_lo, T512_1x2_lo}, {T16_2x8, T16_4x2}                    , {T512_1x2_lo, T512_1x2_lo} } };
    }();

    __aie_inline
    static vector_type run(const vector_type &v, unsigned row, unsigned col)
    {
        aie::vector<T, 8> tmp;

        const unsigned index = utils::ffs(row);

        tmp = ::shuffle(v.template grow<8>(), shuffle_modes[index][0]);
        tmp = ::shuffle(tmp,                  shuffle_modes[index][1]);

        return  tmp.template extract<Elems>(0);
    }
};

}

#endif
