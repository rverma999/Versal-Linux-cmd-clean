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

#ifndef __AIE_API_DETAIL_AIE1_SHUFFLE_REPLICATE_HPP__
#define __AIE_API_DETAIL_AIE1_SHUFFLE_REPLICATE_HPP__

#include "../vector.hpp"

namespace aie::detail {

template <typename T, unsigned Elems>
struct shuffle_up_replicate_bits_impl<8, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline static vector_type run(const vector_type &v, unsigned n)
    {
        if      constexpr (vector_type::bits() <= 512)  return shuffle_up_replicate<int16, Elems>::run(v.unpack(), n).template pack<T>();
        else if constexpr (vector_type::bits() == 1024) return shuffle_up_replicate_bits_impl_scalar<8, T, Elems>::run(v, n);
    }
};

template <typename T, unsigned Elems>
struct shuffle_down_replicate_bits_impl<8, T, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline static vector_type run(const vector_type &v, unsigned n)
    {
        if      constexpr (vector_type::bits() <= 512)  return shuffle_down_replicate<int16, Elems>::run(v.unpack(), n).template pack<T>();
        else if constexpr (vector_type::bits() == 1024) return shuffle_down_replicate_bits_impl_scalar<8, T, Elems>::run(v, n);
    }
};

template <typename T, unsigned Elems>
struct shuffle_up_replicate_bits_impl<16, T, Elems>
{
    using vector_type = vector<T, Elems>;

    template <unsigned Section>
    static constexpr unsigned compute_offsets(unsigned n)
    {
        unsigned ret = 0;

        for (unsigned i = std::max(n, Section * 8u); i < (Section + 1) * 8u; ++i)
            ret |= (int(i) - n) << ((4 * i) % 32);

        return ret;
    }

    __aie_inline static vector_type run(const vector_type &v, unsigned n)
    {
        if (chess_manifest(n % 2 == 1)) {
            vector_type ret = v;

            const T a = v.get(0);

            ret.push(a);

            if (n == 1)
                return ret;

            return vector_cast<T>(shuffle_up_replicate_bits_impl<32, int32, Elems / 2>::run(vector_cast<int32>(ret), n / 2));
        }
        else {
            vector_type ret;

            vector<int32, 8> one;

            one[0] = 1;

            // TODO: explore using select instead
            if constexpr (Elems == 8) {
                const vector<T, 16> tmp = ::srs(::mul16(v.template grow<32>(), 0, compute_offsets<0>(n),            0x00000000, one, 0, 0x00000000, 0x00000000), 0);
                ret = tmp.template extract<Elems>(0);
            }
            else if constexpr (Elems == 16) {
                const vector<T, 16> tmp = ::srs(::mul16(v.template grow<32>(), 0, compute_offsets<0>(n), compute_offsets<1>(n), one, 0, 0x00000000, 0x00000000), 0);
                ret = tmp.template extract<Elems>(0);
            }
            else if constexpr (Elems == 32) {
                vector<T, 16> tmp = ::srs(::mul16(v,     0, compute_offsets<0>(n), compute_offsets<1>(n), one, 0, 0x00000000, 0x00000000), 0);

                ret.insert(0, tmp);

                if (n >= 16) tmp = ::srs(::mul16(v,      0, compute_offsets<2>(n), compute_offsets<3>(n), one, 0, 0x00000000, 0x00000000), 0);
                else         tmp = ::srs(::mul16(v, 16 - n,            0x76543210,            0xfedcba98, one, 0, 0x00000000, 0x00000000), 0);

                ret.insert(1, tmp);
            }
            else if constexpr (Elems == 64) {
                vector<T, 16> tmp = ::srs(::mul16(v,     0, compute_offsets<0>(n), compute_offsets<1>(n), one, 0, 0x00000000, 0x00000000), 0);

                ret.insert(0, tmp);

                if (n >= 16) tmp = ::srs(::mul16(v,      0, compute_offsets<2>(n), compute_offsets<3>(n), one, 0, 0x00000000, 0x00000000), 0);
                else         tmp = ::srs(::mul16(v, 16 - n,            0x76543210,            0xfedcba98, one, 0, 0x00000000, 0x00000000), 0);

                ret.insert(1, tmp);

                if (n >= 32) tmp = ::srs(::mul16(v,      0, compute_offsets<4>(n), compute_offsets<5>(n), one, 0, 0x00000000, 0x00000000), 0);
                else         tmp = ::srs(::mul16(v, 32 - n,            0x76543210,            0xfedcba98, one, 0, 0x00000000, 0x00000000), 0);

                ret.insert(2, tmp);

                if (n >= 48) tmp = ::srs(::mul16(v,      0, compute_offsets<6>(n), compute_offsets<7>(n), one, 0, 0x00000000, 0x00000000), 0);
                else         tmp = ::srs(::mul16(v, 48 - n,            0x76543210,            0xfedcba98, one, 0, 0x00000000, 0x00000000), 0);

                ret.insert(3, tmp);
            }

            return ret;
        }
    }
};

template <typename T, unsigned Elems>
struct shuffle_down_replicate_bits_impl<16, T, Elems>
{
    using vector_type = vector<T, Elems>;

    template <unsigned Start, unsigned End = Start + 8, unsigned Offset = 0>
    static constexpr unsigned compute_offsets(unsigned n)
    {
        unsigned ret = 0;

        for (unsigned i = Start; i < std::min(End, Elems - Offset - n); ++i)
            ret |= (n + i) << ((4 * i) % 32);

        for (unsigned i = std::min(End, Elems - Offset - n); i < End; ++i)
            ret |= (Elems - Offset - 1) << ((4 * i) % 32);

        return ret;
    }


    __aie_inline static vector_type run(const vector_type &v, unsigned n)
    {
        {
            vector_type ret;

            vector<int32, 8> one;

            one[0] = 1;

            // TODO: explore using select instead
            if constexpr (Elems == 8) {
                const vector<T, 16> tmp = ::srs(::mul16(v.template grow<32>(), 0, compute_offsets<0, Elems>(n),            0x00000000, one, 0, 0x00000000, 0x00000000), 0);
                ret = tmp.template extract<Elems>(0);
            }
            else if constexpr (Elems == 16) {
                const vector<T, 16> tmp = ::srs(::mul16(v.template grow<32>(), 0, compute_offsets<0, 8>(n), compute_offsets<8, 16>(n), one, 0, 0x00000000, 0x00000000), 0);
                ret = tmp.template extract<Elems>(0);
            }
            else if constexpr (Elems == 32) {
                vector<T, 16> tmp1, tmp2;

                if (n >= 16) {
                    tmp1 = ::srs(::mul16(v,    16, compute_offsets<0, 8, 16>(n - 16), compute_offsets<8, 16, 16>(n - 16), one, 0, 0x00000000, 0x00000000), 0);
                    tmp2 = ::srs(::mul16(v,    16, 0xffffffff,                        0xffffffff,                         one, 0, 0x00000000, 0x00000000), 0);
                }
                else {
                    tmp1 = ::srs(::mul16(v,     n, 0x76543210,                        0xfedcba98,                    one, 0, 0x00000000, 0x00000000), 0);
                    tmp2 = ::srs(::mul16(v,    16, compute_offsets<0, 8, 16>(n),      compute_offsets<8, 16, 16>(n), one, 0, 0x00000000, 0x00000000), 0);
                }

                ret.insert(0, tmp1);
                ret.insert(1, tmp2);
            }
            else if constexpr (Elems == 64) {
                vector<T, 16> tmp1, tmp2, tmp3, tmp4;

                if (n > 48) {
                    tmp1 = ::srs(::mul16(v,    48, compute_offsets<0, 8, 48>(n - 48), compute_offsets<8, 16, 48>(n - 48), one, 0, 0x00000000, 0x00000000), 0);
                    tmp2 = ::srs(::mul16(v,    48, 0xffffffff,                        0xffffffff,                         one, 0, 0x00000000, 0x00000000), 0);
                    tmp3 = ::srs(::mul16(v,    48, 0xffffffff,                        0xffffffff,                         one, 0, 0x00000000, 0x00000000), 0);
                    tmp4 = ::srs(::mul16(v,    48, 0xffffffff,                        0xffffffff,                         one, 0, 0x00000000, 0x00000000), 0);
                }
                else if (n > 32) {
                    tmp1 = ::srs(::mul16(v,      n, 0x76543210,                        0xfedcba98,                         one, 0, 0x00000000, 0x00000000), 0);
                    tmp2 = ::srs(::mul16(v,     48, compute_offsets<0, 8, 48>(n - 32), compute_offsets<8, 16, 48>(n - 32), one, 0, 0x00000000, 0x00000000), 0);
                    tmp3 = ::srs(::mul16(v,     48, 0xffffffff,                        0xffffffff,                         one, 0, 0x00000000, 0x00000000), 0);
                    tmp4 = ::srs(::mul16(v,     48, 0xffffffff,                        0xffffffff,                         one, 0, 0x00000000, 0x00000000), 0);
                }
                else if (n > 16) {
                    tmp1 = ::srs(::mul16(v,      n, 0x76543210,                        0xfedcba98,                         one, 0, 0x00000000, 0x00000000), 0);
                    tmp2 = ::srs(::mul16(v, n + 16, 0x76543210,                        0xfedcba98,                         one, 0, 0x00000000, 0x00000000), 0);
                    tmp3 = ::srs(::mul16(v,     48, compute_offsets<0, 8, 48>(n - 16), compute_offsets<8, 16, 48>(n - 16), one, 0, 0x00000000, 0x00000000), 0);
                    tmp4 = ::srs(::mul16(v,     48, 0xffffffff,                        0xffffffff,                         one, 0, 0x00000000, 0x00000000), 0);
                }
                else {
                    tmp1 = ::srs(::mul16(v,      n, 0x76543210,                        0xfedcba98,                    one, 0, 0x00000000, 0x00000000), 0);
                    tmp2 = ::srs(::mul16(v, n + 16, 0x76543210,                        0xfedcba98,                    one, 0, 0x00000000, 0x00000000), 0);
                    tmp3 = ::srs(::mul16(v, n + 32, 0x76543210,                        0xfedcba98,                    one, 0, 0x00000000, 0x00000000), 0);
                    tmp4 = ::srs(::mul16(v,     48, compute_offsets<0, 8, 48>(n),      compute_offsets<8, 16, 48>(n), one, 0, 0x00000000, 0x00000000), 0);
                }

                ret.insert(0, tmp1);
                ret.insert(1, tmp2);
                ret.insert(2, tmp3);
                ret.insert(3, tmp4);
            }

            return ret;
        }
    }
};


template <typename T, unsigned Elems>
struct shuffle_up_replicate_bits_impl<32, T, Elems>
{
    using vector_type = vector<T, Elems>;

    template <unsigned Section>
    static constexpr unsigned compute_offsets(unsigned n)
    {
        unsigned ret = 0;

        for (unsigned i = std::max(n, Section * 8u); i < (Section + 1) * 8u; ++i)
            ret |= (int(i) - n) << ((4 * i) % 32);

        return ret;
    }

    static constexpr auto get_op()
    {
        if constexpr (std::is_same_v<T, float>) return [](auto &&... args) __aie_inline { return ::fpshuffle16(args...); };
        else                                    return [](auto &&... args) __aie_inline { return ::shuffle16(args...); };
    }

    __aie_inline static vector_type run(const vector_type &v, unsigned n)
    {
        vector_type ret;

        constexpr auto op = get_op();

        if constexpr (Elems <= 8) {
            const vector<T, 16> tmp = op(v.template grow<16>(), 0, compute_offsets<0>(n), 0);
            ret = tmp.template extract<Elems>(0);
        }
        else if constexpr (Elems == 16) {
            const vector<T, 16> tmp = op(v,  0, compute_offsets<0>(n), compute_offsets<1>(n));
            ret = tmp.template extract<Elems>(0);
        }
        else if constexpr (Elems == 32) {
            const vector<T, 16> tmp1 = op(v, 0, compute_offsets<0>(n), compute_offsets<1>(n));
            vector<T, 16> tmp2;

            if (n >= 16)
                tmp2 = op(v,      0, compute_offsets<2>(n), compute_offsets<3>(n));
            else
                tmp2 = op(v, 16 - n, 0x76543210, 0xfedcba98);

            ret.insert(0, tmp1);
            ret.insert(1, tmp2);
        }

        return ret;
    }
};

template <typename T, unsigned Elems>
struct shuffle_down_replicate_bits_impl<32, T, Elems>
{
    using vector_type = vector<T, Elems>;

    template <unsigned Start, unsigned End, unsigned Offset = 0>
    static constexpr unsigned compute_offsets(unsigned n)
    {
        unsigned ret = 0;

        for (unsigned i = Start; i < std::min(End, Elems - Offset - n); ++i)
            ret |= (n + i) << ((4 * i) % 32);

        for (unsigned i = std::min(End, Elems - Offset - n); i < End; ++i)
            ret |= (Elems - Offset - 1) << ((4 * i) % 32);

        return ret;
    }

    static constexpr auto get_op()
    {
        if constexpr (std::is_same_v<T, float>) return [](auto &&... args) __aie_inline { return ::fpshuffle16(args...); };
        else                                    return [](auto &&... args) __aie_inline { return ::shuffle16(args...); };
    }

    __aie_inline static vector_type run(const vector_type &v, unsigned n)
    {
        vector_type ret;

        constexpr auto op = get_op();

        if constexpr (Elems <= 8) {
            const vector<T, 16> tmp = op(v.template grow<16>(), 0, compute_offsets<0, Elems>(n), 0);
            ret = tmp.template extract<Elems>(0);
        }
        else if constexpr (Elems == 16) {
            const vector<T, 16> tmp = op(v,  0, compute_offsets<0, 8>(n), compute_offsets<8, 16>(n));
            ret = tmp.template extract<Elems>(0);
        }
        else if constexpr (Elems == 32) {
            vector<T, 16> tmp1;
            vector<T, 16> tmp2;

            if (n >= 16) {
                tmp1 = op(v, 16, compute_offsets<0, 8, 16>(n - 16), compute_offsets<8, 16, 16>(n - 16));
                tmp2 = op(v, 16, 0xffffffff, 0xffffffff);
            }
            else {
                tmp1 = op(v,  n, 0x76543210, 0xfedcba98);
                tmp2 = op(v, 16, compute_offsets<0, 8, 16>(n),      compute_offsets<8, 16, 16>(n));
            }

            ret.insert(0, tmp1);
            ret.insert(1, tmp2);
        }

        return ret;
    }
};

template <typename T, unsigned Elems>
struct shuffle_up_replicate_bits_impl<64, T, Elems>
{
    using vector_type = vector<T, Elems>;

    template <unsigned Section>
    static constexpr unsigned compute_offsets(unsigned n)
    {
        unsigned ret = 0;

        for (unsigned i = std::max(n, Section * 8u); i < (Section + 1) * 8u; ++i)
            ret |= (int(i) - n) << ((4 * i) % 32);

        return ret;
    }

    static constexpr auto get_op()
    {
        if constexpr (std::is_same_v<T, cfloat>) return [](auto &&... args) __aie_inline { return ::fpshuffle8(args...); };
        else                                     return [](auto &&... args) __aie_inline { return ::shuffle8(args...); };
    }

    __aie_inline static vector_type run(const vector_type &v, unsigned n)
    {
        vector_type ret;

        constexpr auto op = get_op();

        if constexpr (Elems <= 4) {
            const vector<T, 8> tmp = op(v.template grow<8>(), 0, compute_offsets<0>(n));
            ret = tmp.template extract<Elems>(0);
        }
        else if constexpr (Elems == 8) {
            const vector<T, 8> tmp = op(v,  0, compute_offsets<0>(n));
            ret = tmp.template extract<Elems>(0);
        }
        else if constexpr (Elems == 16) {
            const vector<T, 8> tmp1 = op(v, 0, compute_offsets<0>(n));
            vector<T, 8> tmp2;

            if (n >= 8)
                tmp2 = op(v,     0, compute_offsets<1>(n));
            else
                tmp2 = op(v, 8 - n, 0x76543210);

            ret.insert(0, tmp1);
            ret.insert(1, tmp2);
        }

        return ret;
    }
};

template <typename T, unsigned Elems>
struct shuffle_down_replicate_bits_impl<64, T, Elems>
{
    using vector_type = vector<T, Elems>;

    static constexpr unsigned compute_offsets(unsigned n)
    {
        unsigned ret = 0;

        for (unsigned i = 0; i < std::min(Elems, 8u) - n; ++i)
            ret |= (n + i) << ((4 * i) % 32);

        for (unsigned i = std::min(Elems, 8u) - n; i < std::min(Elems, 8u); ++i)
            ret |= (std::min(Elems, 8u) - 1) << ((4 * i) % 32);

        return ret;
    }

    static constexpr auto get_op()
    {
        if constexpr (std::is_same_v<T, cfloat>) return [](auto &&... args) __aie_inline { return ::fpshuffle8(args...); };
        else                                     return [](auto &&... args) __aie_inline { return ::shuffle8(args...); };
    }

    __aie_inline static vector_type run(const vector_type &v, unsigned n)
    {
        vector_type ret;

        constexpr auto op = get_op();

        if constexpr (Elems <= 4) {
            const vector<T, 8> tmp = op(v.template grow<8>(), 0, compute_offsets(n));
            ret = tmp.template extract<Elems>(0);
        }
        else if constexpr (Elems == 8) {
            const vector<T, 8> tmp = op(v,  0, compute_offsets(n));
            ret = tmp.template extract<Elems>(0);
        }
        else if constexpr (Elems == 16) {
            vector<T, 8> tmp1;
            vector<T, 8> tmp2;

            if (n >= 8) {
                tmp1 = op(v, 8, compute_offsets(n - 8));
                tmp2 = op(v, 8, 0x77777777);
            }
            else {
                tmp1 = op(v, n, 0x76543210);
                tmp2 = op(v, 8, compute_offsets(n));
            }

            ret.insert(0, tmp1);
            ret.insert(1, tmp2);
        }

        return ret;
    }
};

}

#endif
