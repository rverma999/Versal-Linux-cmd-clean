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

#ifndef __AIE_API_DETAIL_AIE2_FILTER__HPP__
#define __AIE_API_DETAIL_AIE2_FILTER__HPP__

#include "shuffle_mode.hpp"

#include "../utils.hpp"
#include "../vector.hpp"

namespace aie::detail {

template <typename T, unsigned Elems, FilterOp Op>
struct filter_bits_impl<4, T, Elems, Op>
{
    using vector_type = vector<T, Elems>;
    using result_type = vector<T, Elems / 2>;

    __aie_inline
    static result_type run(const vector_type &v, unsigned step)
    {
        using next_type   = utils::get_next_integer_type_t<T>;
        using filter_impl = filter_bits_impl<8, next_type, Elems / 2, Op>;

        REQUIRES_MSG(step > 1, "Sub-byte vector filter is not supported");
        return filter_impl::run(v.template cast_to<next_type>(), step / 2).template cast_to<T>();
    }
};

template <typename T, unsigned Elems>
struct filter_bits_impl<4, T, Elems, FilterOp::Dynamic>
{
    using vector_type = vector<T, Elems>;
    using result_type = vector<T, Elems / 2>;

    __aie_inline
    static result_type run(const vector_type &v, const filter_mode<4, Elems> &mode)
    {
        using next_type = utils::get_next_integer_type_t<T>;
        using filter_impl = filter_bits_impl<8, next_type, Elems / 2, FilterOp::Dynamic>;

        // filter_mode cannot be constructed with sub-byte steps, so we can
        // operate directly in int8 vectors
        filter_mode<8, Elems / 2> m{mode};
        return filter_impl::run(v.template cast_to<next_type>(), m).template cast_to<T>();
    }
};

template <unsigned TypeBits, typename T, unsigned Elems, FilterOp Op>
struct filter_bits_impl_common
{
    static constexpr unsigned native_elems = 512 / TypeBits;

    using vector_type = vector<T, Elems>;
    using result_type = vector<T, Elems / 2>;
    using  filter_tag = std::conditional_t<Op == FilterOp::Even, filter_even_tag, filter_odd_tag>;
    using   impl_type = filter_bits_impl_common<TypeBits, T, Elems, FilterOp::Dynamic>;

    __aie_inline
    static result_type run(const vector_type &v, unsigned step)
    {
        const filter_mode<TypeBits, Elems> f{step, filter_tag{}};
        return impl_type::run(v, f);
    }
};

template <unsigned TypeBits, typename T, unsigned Elems>
struct filter_bits_impl_common<TypeBits, T, Elems, FilterOp::Dynamic>
{
    static constexpr unsigned native_elems = 512 / TypeBits;
    using vector_type = vector<T, Elems>;
    using result_type = vector<T, Elems / 2>;

    __aie_inline
    static result_type run(const vector_type &v, const filter_mode<TypeBits, Elems> &filter)
    {
        result_type result;
        if constexpr (vector_type::bits() <= 512) {
            vector<T, native_elems> tmp = v.template grow<native_elems>();
            tmp = ::shuffle(tmp, tmp, filter.mode);

            result = tmp.template extract<Elems / 2>(0);
        }
        else if constexpr (vector_type::bits() == 1024) {
            result = ::shuffle(v.template extract<native_elems>(0),
                               v.template extract<native_elems>(1),
                               filter.mode);
        }
        return result;
    }
};


template <typename T, unsigned Elems, FilterOp Op> struct filter_bits_impl< 8, T, Elems, Op> : public filter_bits_impl_common< 8, T, Elems, Op> {};
template <typename T, unsigned Elems, FilterOp Op> struct filter_bits_impl<16, T, Elems, Op> : public filter_bits_impl_common<16, T, Elems, Op> {};
template <typename T, unsigned Elems, FilterOp Op> struct filter_bits_impl<32, T, Elems, Op> : public filter_bits_impl_common<32, T, Elems, Op> {};
template <typename T, unsigned Elems, FilterOp Op> struct filter_bits_impl<64, T, Elems, Op> : public filter_bits_impl_common<64, T, Elems, Op> {};

}

#endif
