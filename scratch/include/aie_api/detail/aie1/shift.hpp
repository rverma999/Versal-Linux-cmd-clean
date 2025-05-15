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

#ifndef __AIE_API_DETAIL_AIE1_SHIFT__HPP__
#define __AIE_API_DETAIL_AIE1_SHIFT__HPP__

#include "../vector.hpp"

namespace aie::detail {

template <typename T, unsigned Elems>
static constexpr auto get_ups_op()
{
    if      constexpr (std::is_same_v<T, uint8>)                { return [](auto &&... args) __aie_inline { return ::ups(args...);  }; }
    else if constexpr (std::is_same_v<T, int8>)                 { return [](auto &&... args) __aie_inline { return ::ups(args...);  }; }
    else if constexpr (std::is_same_v<T, int16>)                { return [](auto &&... args) __aie_inline { return ::ups(args...);  }; }
    else if constexpr (std::is_same_v<T, int32> && Elems == 4)  { return [](auto &&... args) __aie_inline { return ::lups(args...); }; }
    else if constexpr (std::is_same_v<T, int32>)                { return [](auto &&... args) __aie_inline { return ::ups(args...);  }; }
    else if constexpr (std::is_same_v<T, cint16>)               { return [](auto &&... args) __aie_inline { return ::ups(args...);  }; }
    else if constexpr (std::is_same_v<T, cint32> && Elems == 2) { return [](auto &&... args) __aie_inline { return ::lups(args...); }; }
    else if constexpr (std::is_same_v<T, cint32>)               { return [](auto &&... args) __aie_inline { return ::ups(args...);  }; }
}

template <typename T, unsigned Elems>
static constexpr auto get_srs_op()
{
    if      constexpr (std::is_same_v<T, uint8>)                { return [](auto &&... args) __aie_inline { return ::ubsrs(args...); }; }
    else if constexpr (std::is_same_v<T, int8>)                 { return [](auto &&... args) __aie_inline { return ::bsrs(args...);  }; }
    else if constexpr (std::is_same_v<T, int16>)                { return [](auto &&... args) __aie_inline { return ::srs(args...);   }; }
    else if constexpr (std::is_same_v<T, int32>  && Elems == 4) { return [](auto &&... args) __aie_inline { return ::srs(args...);   }; }
    else if constexpr (std::is_same_v<T, int32>)                { return [](auto &&... args) __aie_inline { return ::lsrs(args...);  }; }
    else if constexpr (std::is_same_v<T, cint16>)               { return [](auto &&... args) __aie_inline { return ::srs(args...);   }; }
    else if constexpr (std::is_same_v<T, cint32> && Elems == 2) { return [](auto &&... args) __aie_inline { return ::srs(args...);   }; }
    else if constexpr (std::is_same_v<T, cint32> )              { return [](auto &&... args) __aie_inline { return ::lsrs(args...);  }; }

}

template<typename T, unsigned Elems>
struct shift_bits_impl<T, 8, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, unsigned upshift, unsigned downshift)
    {
        vector_type ret;

        constexpr auto srs_op = get_srs_op<T, Elems>();
        constexpr auto ups_op = get_ups_op<T, Elems>();

        utils::unroll_times<Elems / 16>([&](auto idx) __aie_inline {
            auto tmp = srs_op(ups_op(v.template extract<16>(idx), upshift), downshift);
            ret.template insert<16>(idx, tmp);
        });

        return ret;
    }
};

template<unsigned Elems>
struct shift_bits_impl<int16, 16, Elems>
{
    using vector_type = vector<int16, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, unsigned upshift, unsigned downshift)
    {
        vector_type ret;

        constexpr auto srs_op = get_srs_op<int16, Elems>();
        constexpr auto ups_op = get_ups_op<int16, Elems>();

        constexpr unsigned iter = std::max(Elems / 16u, 1u);
        constexpr unsigned iter_elems = std::min(Elems, 16u);

        utils::unroll_times<iter>([&](auto idx) __aie_inline {
            auto tmp = srs_op(ups_op(v.template extract<iter_elems>(idx), upshift), downshift);
            ret.template insert<iter_elems>(idx, tmp);
        });

        return ret;
    }
};

template<typename T, unsigned Elems>
struct shift_bits_impl<T, 32, Elems>
{
    using vector_type = vector<T, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, unsigned upshift, unsigned downshift)
    {
        vector_type ret;

        constexpr auto srs_op = get_srs_op<T, Elems>();
        constexpr auto ups_op = get_ups_op<T, Elems>();

        constexpr unsigned iter = std::max(Elems / 8u, 1u);
        constexpr unsigned iter_elems = std::min(Elems, 8u);

        utils::unroll_times<iter>([&](auto idx) __aie_inline {
            auto tmp = srs_op(ups_op(v.template extract<iter_elems>(idx), upshift), downshift);
            ret.template insert<iter_elems>(idx, tmp);
        });

        return ret;
    }
};

template<unsigned Elems>
struct shift_bits_impl<cint32, 64, Elems>
{
    using vector_type = vector<cint32, Elems>;

    __aie_inline
    static vector_type run(const vector_type &v, unsigned upshift, unsigned downshift)
    {
        vector_type ret;

        constexpr auto srs_op = get_srs_op<cint32, Elems>();
        constexpr auto ups_op = get_ups_op<cint32, Elems>();

        constexpr unsigned iter = std::max(Elems / 4u, 1u);
        constexpr unsigned iter_elems = std::min(Elems, 4u);

        utils::unroll_times<iter>([&](auto idx) __aie_inline {
            auto tmp = srs_op(ups_op(v.template extract<iter_elems>(idx), upshift), downshift);
            ret.template insert<iter_elems>(idx, tmp);
        });

        return ret;
    }
};

}

#endif
