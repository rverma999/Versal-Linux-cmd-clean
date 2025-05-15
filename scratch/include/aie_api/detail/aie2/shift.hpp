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

#ifndef __AIE_API_DETAIL_AIE2_SHIFT__HPP__
#define __AIE_API_DETAIL_AIE2_SHIFT__HPP__

#include "../vector.hpp"

namespace aie::detail {

template<typename T, unsigned Elems>
struct shift_bits_impl<T, 4, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, unsigned upshift, unsigned downshift)
    {
        using next_type = utils::get_next_integer_type_t<T>;

        vector_type ret;

        if constexpr (Elems < 256) {
            ret = shift_bits_impl<next_type, 8, Elems>::run(v.template unpack(), upshift, downshift).pack();
        }
        else {
            const auto tmp1 = v.template extract<128>(0).unpack();
            const auto tmp2 = v.template extract<128>(1).unpack();

            ret = concat_vector(shift_bits_impl<next_type, 8, Elems / 2>::run(tmp1, upshift, downshift).pack(),
                                shift_bits_impl<next_type, 8, Elems / 2>::run(tmp2, upshift, downshift).pack());
        }

        return ret;
    }
};

template<typename T, unsigned TypeBits, unsigned Elems>
struct shift_bits_impl_common
{
    using vector_type = vector<T, Elems>;

    static constexpr auto get_ups_op()
    {
        if      constexpr (type_bits_v<T> < 32)       { return [](auto &&... args) __aie_inline { return ::sups(args...);  }; }
        else                                          { return [](auto &&... args) __aie_inline { return ::lups(args...);  }; }
    }

    static constexpr auto get_srs_op()
    {
        if      constexpr (std::is_same_v<T, uint8>)  { return [](auto &&... args) __aie_inline { return ::ussrs(args...); }; }
        else if constexpr (std::is_same_v<T, int8>)   { return [](auto &&... args) __aie_inline { return ::ssrs(args...);  }; }
        else if constexpr (std::is_same_v<T, uint16>) { return [](auto &&... args) __aie_inline { return ::ulsrs(args...); }; }
        else if constexpr (std::is_same_v<T, int16>)  { return [](auto &&... args) __aie_inline { return ::lsrs(args...);  }; }
        else if constexpr (std::is_same_v<T, uint32>) { return [](auto &&... args) __aie_inline { return ::ulsrs(args...); }; }
        else if constexpr (std::is_same_v<T, int32>)  { return [](auto &&... args) __aie_inline { return ::lsrs(args...);  }; }
        else if constexpr (std::is_same_v<T, cint16>) { return [](auto &&... args) __aie_inline { return ::ssrs(args...);  }; }
        else if constexpr (std::is_same_v<T, cint32>) { return [](auto &&... args) __aie_inline { return ::lsrs(args...);  }; }
    }

    static constexpr auto get_op_elems()
    {
        if      constexpr (utils::is_one_of_v<T, int8, uint8>)   { return 32; }
        else if constexpr (utils::is_one_of_v<T, int16, uint16>) {
            if     constexpr (Elems <= 16)                       { return 16; }
            else                                                 { return 32; }
        }
        else if constexpr (utils::is_one_of_v<T, int32, uint32>) { return 16; }
        else if constexpr (std::is_same_v<T, cint16>)            { return 8;  }
        else if constexpr (std::is_same_v<T, cint32>) {
            if     constexpr (Elems <= 4)                        { return 4;  }
            else                                                 { return 8;  }
        }
    }

    __aie_inline
    static vector_type run(const vector_type &v, unsigned upshift, unsigned downshift)
    {
        vector_type ret;

        constexpr auto srs_op = get_srs_op();
        constexpr auto ups_op = get_ups_op();

        constexpr unsigned op_elems   = get_op_elems(); 
        constexpr unsigned iter       = std::max(1u, Elems / op_elems);
        constexpr unsigned iter_elems = std::min(Elems, op_elems);

        utils::unroll_times<iter>([&](auto idx) __aie_inline {
            vector<T, op_elems> tmp = srs_op(ups_op(v.template grow_extract<op_elems>(idx), upshift), downshift);
            ret.template insert<iter_elems>(idx, tmp.template extract<iter_elems>(0));
        });

        return ret;
    }
};

template <typename T, unsigned Elems> struct shift_bits_impl<T,      8,  Elems> : public shift_bits_impl_common<T,      8,  Elems> {};
template <typename T, unsigned Elems> struct shift_bits_impl<T,      16, Elems> : public shift_bits_impl_common<T,      16, Elems> {};
template <typename T, unsigned Elems> struct shift_bits_impl<T,      32, Elems> : public shift_bits_impl_common<T,      32, Elems> {};
template <            unsigned Elems> struct shift_bits_impl<cint16, 32, Elems> : public shift_bits_impl_common<cint16, 32, Elems> {};
template <            unsigned Elems> struct shift_bits_impl<cint32, 64, Elems> : public shift_bits_impl_common<cint32, 64, Elems> {};

}

#endif
