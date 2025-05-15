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

#ifndef __AIE_API_DETAIL_AIE2_ACCUMULATE__HPP__
#define __AIE_API_DETAIL_AIE2_ACCUMULATE__HPP__

namespace aie::detail {

template <bool WithInputAccum, Operation Op, typename Accum, unsigned CoeffBits, unsigned DataBits>
constexpr auto get_mul_op()
{
    if constexpr (Accum::value_class() == AccumClass::FP) {
        if constexpr (CoeffBits == 16 && DataBits == 16) {
            if      constexpr (!WithInputAccum)          return [](auto &&... params)  { return ::mul_elem_16_2(params...); };
            else if constexpr (Op == Operation::Acc_Add) return [](auto &&... params)  { return ::mac_elem_16_2(params...); };
            else if constexpr (Op == Operation::Acc_Sub) return [](auto &&... params)  { return ::msc_elem_16_2(params...); };
        }
        //TODO: FP32 accumulate
    }
    else {
        if      constexpr (Accum::accum_bits() == 32) {
            if      constexpr (CoeffBits == 8 && DataBits == 8) {
                if      constexpr (!WithInputAccum)          return [](auto &&... params)  { return ::mul_elem_32_2(params...); };
                else if constexpr (Op == Operation::Acc_Add) return [](auto &&... params)  { return ::mac_elem_32_2(params...); };
                else if constexpr (Op == Operation::Acc_Sub) return [](auto &&... params)  { return ::msc_elem_32_2(params...); };
            }
            else if constexpr (CoeffBits == 16 && DataBits == 16) {
                if      constexpr (!WithInputAccum)          return [](auto &&... params)  { return ::mul_elem_32(params...); };
                else if constexpr (Op == Operation::Acc_Add) return [](auto &&... params)  { return ::mac_elem_32(params...); };
                else if constexpr (Op == Operation::Acc_Sub) return [](auto &&... params)  { return ::msc_elem_32(params...); };
            }
        }
        else if constexpr (Accum::accum_bits() == 64) {
            if      constexpr (CoeffBits == 16 && DataBits == 16) {
                if      constexpr (!WithInputAccum)          return [](auto &&... params)  { return ::mul_elem_16_2(params...); };
                else if constexpr (Op == Operation::Acc_Add) return [](auto &&... params)  { return ::mac_elem_16_2(params...); };
                else if constexpr (Op == Operation::Acc_Sub) return [](auto &&... params)  { return ::msc_elem_16_2(params...); };
            }
            else if constexpr (CoeffBits == 32 || DataBits == 32) {
                if      constexpr (!WithInputAccum)          return [](auto &&... params)  { return ::mul_elem_8(params...); };
                else if constexpr (Op == Operation::Acc_Add) return [](auto &&... params)  { return ::mac_elem_8(params...); };
                else if constexpr (Op == Operation::Acc_Sub) return [](auto &&... params)  { return ::msc_elem_8(params...); };
            }
        }
    }
}

template <unsigned Lanes, typename T_Coeff, unsigned N_Coeff, typename T_Data, Operation Op, int Step>
struct consume_terms<32, Lanes, 4, T_Coeff, N_Coeff, 8, T_Data, Op, Step>
{
    using         accum_tag = accum_tag_for_mul_types<T_Coeff, T_Data, 32>;
    using        accum_type = accum<accum_tag, Lanes>;
    using coeff_vector_type = vector<T_Coeff, N_Coeff>;
    using  data_vector_type = vector<T_Data, Lanes>;

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type consume_2(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &x, const data_vector_type &y, const Acc &... acc)
    {
        return consume_terms<32, Lanes, 8, utils::get_next_integer_type_t<T_Coeff>, N_Coeff, 8, T_Data, Op, Step>::consume_2(coeff.unpack(), coeff_start, x, y, acc...);
    }

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type consume_1(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &v, const Acc &... acc)
    {
        return consume_terms<32, Lanes, 8, utils::get_next_integer_type_t<T_Coeff>, N_Coeff, 8, T_Data, Op, Step>::consume_1(coeff.unpack(), coeff_start, v, acc...);
    }
};

template <unsigned Lanes, typename T_Coeff, unsigned N_Coeff, typename T_Data, Operation Op, int Step>
struct consume_terms<32, Lanes, 8, T_Coeff, N_Coeff, 4, T_Data, Op, Step>
{
    using         accum_tag = accum_tag_for_mul_types<T_Coeff, T_Data, 32>;
    using        accum_type = accum<accum_tag, Lanes>;
    using coeff_vector_type = vector<T_Coeff, N_Coeff>;
    using  data_vector_type = vector<T_Data, Lanes>;

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type consume_2(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &x, const data_vector_type &y, const Acc &... acc)
    {
      return consume_terms<32, Lanes, 8, T_Coeff, N_Coeff, 8, utils::get_next_integer_type_t<T_Data>, Op, Step>::consume_2(coeff, coeff_start, x.unpack(), y.unpack(), acc...);

    }

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type consume_1(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &v, const Acc &... acc)
    {
      return consume_terms<32, Lanes, 8, T_Coeff, N_Coeff, 8, utils::get_next_integer_type_t<T_Data>, Op, Step>::consume_1(coeff, coeff_start, v.unpack(), acc...);
    }
};

template <unsigned Lanes, typename T_Coeff, unsigned N_Coeff, typename T_Data, Operation Op, int Step>
struct consume_terms<32, Lanes, 8, T_Coeff, N_Coeff, 8, T_Data, Op, Step>
{
    using accum_tag = accum_tag_for_mul_types<T_Coeff, T_Data, 32>;

    template <unsigned Elems = Lanes>
    using        accum_type = accum<accum_tag, Elems>;
    using coeff_vector_type = vector<T_Coeff, N_Coeff>;
    using  data_vector_type = vector<T_Data, Lanes>;

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<> consume_2(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &x, const data_vector_type &y, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<sizeof...(acc) == 1, Op, accum_type<>, 8, 8>();
        constexpr unsigned num_mul = Lanes < 64? 1 : Lanes / 32;

        vector<T_Coeff, 64> coef_v = concat_vector(broadcast<T_Coeff, 32>::run(coeff[coeff_start]), broadcast<T_Coeff, 32>::run(coeff[coeff_start + Step]));

        accum_type<> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const accum_type<32> tmp = mul_op( concat_vector(x.template grow_extract<32>(idx), y.template grow_extract<32>(idx)),
                                               coef_v,
                                               acc.template grow_extract<32>(idx)...);
            ret.insert(idx, tmp.template extract<(Lanes < 32? Lanes : 32)>(0));
        });

        return ret;
    }

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<> consume_1(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &v, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<sizeof...(acc) == 1, Op, accum_type<>, 8, 8>();
        constexpr unsigned num_mul = Lanes < 64? 1 : Lanes / 32;

        vector<T_Coeff, 64> coef_v = concat_vector(broadcast<T_Coeff, 32>::run(coeff[coeff_start]), zeros<T_Coeff, 32>::run());

        accum_type<> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const accum_type<32> tmp = mul_op( v.template grow_extract<32>(idx).template grow<64>(),
                                              coef_v,
                                              acc.template grow_extract<32>(idx)...);
            ret.insert(idx, tmp.template extract<(Lanes < 32? Lanes : 32)>(0));
        });

        return ret;
    }
};

template <unsigned Lanes, typename T_Coeff, unsigned N_Coeff, typename T_Data, Operation Op, int Step>
struct consume_terms<32, Lanes, 8, T_Coeff, N_Coeff, 16, T_Data, Op, Step>
{
    using         accum_tag = accum_tag_for_mul_types<T_Coeff, T_Data, 32>;
    using        accum_type = accum<accum_tag, Lanes>;
    using coeff_vector_type = vector<T_Coeff, N_Coeff>;
    using  data_vector_type = vector<T_Data, Lanes>;

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type consume_2(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &x, const data_vector_type &y, const Acc &... acc)
    {
        return consume_terms<32, Lanes, 16, utils::get_next_integer_type_t<T_Coeff>, N_Coeff, 16, T_Data, Op, Step>::consume_2(coeff.unpack(), coeff_start, x, y, acc...);
    }

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type consume_1(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &v, const Acc &... acc)
    {
        return consume_terms<32, Lanes, 16, utils::get_next_integer_type_t<T_Coeff>, N_Coeff, 16, T_Data, Op, Step>::consume_1(coeff.unpack(), coeff_start, v, acc...);
    }
};

template <unsigned Lanes, typename T_Coeff, unsigned N_Coeff, typename T_Data, Operation Op, int Step>
struct consume_terms<32, Lanes, 16, T_Coeff, N_Coeff, 8, T_Data, Op, Step>
{
    using         accum_tag = accum_tag_for_mul_types<T_Coeff, T_Data, 32>;
    using        accum_type = accum<accum_tag, Lanes>;
    using coeff_vector_type = vector<T_Coeff, N_Coeff>;
    using  data_vector_type = vector<T_Data, Lanes>;

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type consume_2(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &x, const data_vector_type &y, const Acc &... acc)
    {
      return consume_terms<32, Lanes, 16, T_Coeff, N_Coeff, 16, utils::get_next_integer_type_t<T_Data>, Op, Step>::consume_2(coeff, coeff_start, x.unpack(), y.unpack(), acc...);

    }

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type consume_1(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &v, const Acc &... acc)
    {
      return consume_terms<32, Lanes, 16, T_Coeff, N_Coeff, 16, utils::get_next_integer_type_t<T_Data>, Op, Step>::consume_1(coeff, coeff_start, v.unpack(), acc...);
    }
};

template <unsigned Lanes, typename T_Coeff, unsigned N_Coeff, typename T_Data, Operation Op, int Step>
struct consume_terms<32, Lanes, 16,  T_Coeff, N_Coeff, 16,  T_Data, Op, Step>
{
    using accum_tag = accum_tag_for_mul_types<T_Coeff, T_Data, 32>;

    template <unsigned Elems = Lanes>
    using        accum_type = accum<accum_tag, Elems>;
    using coeff_vector_type = vector<T_Coeff, N_Coeff>;
    using  data_vector_type = vector<T_Data, Lanes>;

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<> consume_2(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &x, const data_vector_type &y, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<sizeof...(acc) == 1, Op, accum_type<>, 16, 16>();
        constexpr auto mac_op = get_mul_op<true,                Op, accum_type<>, 16, 16>();
        constexpr unsigned num_mul = Lanes < 64? 1 : Lanes / 32;

        vector<T_Coeff, 32> c0 = broadcast<T_Coeff, 32>::run(coeff[coeff_start]);
        vector<T_Coeff, 32> c1 = broadcast<T_Coeff, 32>::run(coeff[coeff_start + Step]);

        accum_type<> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            accum_type<32> tmp = mul_op(  x.template grow_extract<32>(idx),
                                         c0,
                                        acc.template grow_extract<32>(idx)...);
                           tmp = mac_op(  y.template grow_extract<32>(idx),
                                         c1,
                                        tmp);
            ret.insert(idx, tmp.template extract<(Lanes < 32? Lanes : 32)>(0));
        });

        return ret;
    }

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<> consume_1(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &v, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<sizeof...(acc) == 1, Op, accum_type<>, 16, 16>();
        constexpr unsigned num_mul = Lanes < 64? 1 : Lanes / 32;

        vector<T_Coeff, 32> c0 = broadcast<T_Coeff, 32>::run(coeff[coeff_start]);

        accum_type<> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const accum_type<32> tmp = mul_op(  v.template grow_extract<32>(idx),
                                               c0,
                                              acc.template grow_extract<32>(idx)...);
            ret.insert(idx, tmp.template extract<(Lanes < 32? Lanes : 32)>(0));
        });

        return ret;
    }
};

template <unsigned Lanes, unsigned N_Coeff, Operation Op, int Step>
struct consume_terms<32, Lanes, 16, bfloat16, N_Coeff, 16, bfloat16, Op, Step>
{
    using T_Coeff = bfloat16;
    using T_Data  = bfloat16;

    using accum_tag = accum_tag_for_mul_types<T_Coeff, T_Data, 32>;

    template <unsigned Elems = Lanes>
    using        accum_type = accum<accum_tag, Elems>;
    using coeff_vector_type = vector<T_Coeff, N_Coeff>;
    using  data_vector_type = vector<T_Data, Lanes>;

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<> consume_2(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &x, const data_vector_type &y, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<sizeof...(acc) == 1, Op, accum_type<>, 16, 16>();
        constexpr unsigned num_mul = Lanes < 32? 1 : Lanes / 16;

        vector<T_Coeff, 32> coef_v = concat_vector(broadcast<T_Coeff, 16>::run(coeff[coeff_start]), broadcast<T_Coeff, 16>::run(coeff[coeff_start + Step]));

        accum_type<> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const accum_type<16> tmp = mul_op( concat_vector(x.template grow_extract<16>(idx), y.template grow_extract<16>(idx)),
                                               coef_v,
                                               acc.template grow_extract<16>(idx)...);
            ret.insert(idx, tmp.template extract<(Lanes < 16? Lanes : 16)>(0));
        });

        return ret;
    }

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<> consume_1(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &v, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<sizeof...(acc) == 1, Op, accum_type<>, 16, 16>();
        constexpr unsigned num_mul = Lanes < 32? 1 : Lanes / 16;

        vector<T_Coeff, 32> coef_v = concat_vector(broadcast<T_Coeff, 16>::run(coeff[coeff_start]), zeros<T_Coeff, 16>::run());

        accum_type<> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const accum_type<16> tmp = mul_op( (v.template grow_extract<16>(idx)).template grow<32>(),
                                              coef_v,
                                              acc.template grow_extract<16>(idx)...);
            ret.insert(idx, tmp.template extract<(Lanes < 16? Lanes : 16)>(0));
        });

        return ret;
    }
};

template <unsigned Lanes, typename T_Coeff, unsigned N_Coeff, typename T_Data, Operation Op, int Step>
struct consume_terms<64, Lanes, 16, T_Coeff, N_Coeff, 16, T_Data, Op, Step>
{
    using accum_tag = accum_tag_for_mul_types<T_Coeff, T_Data, 64>;

    template <unsigned Elems = Lanes>
    using        accum_type = accum<accum_tag, Elems>;
    using coeff_vector_type = vector<T_Coeff, N_Coeff>;
    using  data_vector_type = vector<T_Data, Lanes>;

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<> consume_2(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &x, const data_vector_type &y, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<sizeof...(acc) == 1, Op, accum_type<>, 16, 16>();
        constexpr unsigned num_mul = Lanes < 32? 1 : Lanes / 16;

        vector<T_Coeff, 32> coef_v = concat_vector(broadcast<T_Coeff, 16>::run(coeff[coeff_start]), broadcast<T_Coeff, 16>::run(coeff[coeff_start + Step]));

        accum_type<> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const accum_type<16> tmp = mul_op( concat_vector(x.template grow_extract<16>(idx), y.template grow_extract<16>(idx)),
                                               coef_v,
                                               acc.template grow_extract<16>(idx)...);
            ret.insert(idx, tmp.template extract<(Lanes < 16? Lanes : 16)>(0));
        });

        return ret;
    }

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<> consume_1(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &v, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<sizeof...(acc) == 1, Op, accum_type<>, 16, 16>();
        constexpr unsigned num_mul = Lanes < 32? 1 : Lanes / 16;

        vector<T_Coeff, 32> coef_v = concat_vector(broadcast<T_Coeff, 16>::run(coeff[coeff_start]), zeros<T_Coeff, 16>::run());

        accum_type<> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            const accum_type<16> tmp = mul_op( (v.template grow_extract<16>(idx)).template grow<32>(),
                                              coef_v,
                                              acc.template grow_extract<16>(idx)...);
            ret.insert(idx, tmp.template extract<(Lanes < 16? Lanes : 16)>(0));
        });

        return ret;
    }
};

template <unsigned Lanes, typename T_Coeff, unsigned N_Coeff, Operation Op, int Step>
struct consume_terms<64, Lanes, 16,  T_Coeff, N_Coeff, 32,  int32, Op, Step>
{
    using T_Data = int32;

    using accum_tag = accum_tag_for_mul_types<T_Coeff, T_Data, 64>;

    template <unsigned Elems = Lanes>
    using        accum_type = accum<accum_tag, Elems>;
    using coeff_vector_type = vector<T_Coeff, N_Coeff>;
    using  data_vector_type = vector<T_Data, Lanes>;

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<> consume_2(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &x, const data_vector_type &y, const Acc &... acc)
    {
        accum_type<> ret;

        ret = consume_1(coeff, coeff_start,        x, acc...);
        ret = consume_1(coeff, coeff_start + Step, y, ret);

        return ret;
    }

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<> consume_1(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &v, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<sizeof...(acc) == 1, Op, accum_type<>, 16, 32>();
        constexpr unsigned num_mul = Lanes < 32? 1 : Lanes / 16;

        auto [t1, t2] = interleave_zip<int16, 8>::run(broadcast<int16, 8>::run(coeff[coeff_start]),
                                                      zeros<int16, 8>::run(),
                                                      1);

        vector<cint16, 8> coefs = concat_vector(t1, t2).template cast_to<cint16>();

        accum_type<> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            accum_type<16> tmp = (v16acc64) mul_op((v.template grow_extract<16>(idx)).template cast_to<cint32>(),
                                                   coefs.template grow<16>(),
                                                   (v8cacc64) acc.template grow_extract<16>(idx)...);
            ret.insert(idx, tmp.template extract<(Lanes < 16? Lanes : 16)>(0));
        });

        return ret;
    }
};

template <unsigned Lanes, unsigned N_Coeff, typename T_Data, Operation Op, int Step>
struct consume_terms<64, Lanes, 32,  int32, N_Coeff, 16,  T_Data, Op, Step>
{
    using T_Coeff = int32;

    using accum_tag = accum_tag_for_mul_types<T_Coeff, T_Data, 64>;

    template <unsigned Elems = Lanes>
    using        accum_type = accum<accum_tag, Elems>;
    using coeff_vector_type = vector<T_Coeff, N_Coeff>;
    using  data_vector_type = vector<T_Data, Lanes>;

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<> consume_2(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &x, const data_vector_type &y, const Acc &... acc)
    {
        accum_type<> ret;

        ret = consume_1(coeff, coeff_start,        x, acc...);
        ret = consume_1(coeff, coeff_start + Step, y, ret);

        return ret;
    }

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<> consume_1(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &v, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<sizeof...(acc) == 1, Op, accum_type<>, 32, 16>();
        constexpr unsigned num_mul = Lanes < 32? 1 : Lanes / 16;

        auto [t1, t2] = interleave_zip<int32, 8>::run(broadcast<int32, 8>::run(coeff[coeff_start]),
                                                      zeros<int32, 8>::run(),
                                                      1);
        vector<cint32, 8> coef_v = concat_vector(t1, t2).template cast_to<cint32>();

        accum_type<> ret;

        //This uses the intrinsics v8cint32*v16cint16 which lines up with what we need if we swap coef and data and cast to complex types
        //The imaginary part of the coefs is left zeroed so real/imaginary of the data cint16 are treated as separate int16 values
        //16 data int16 are selected (max we can process in one intrinsic call) and then grown to the necessary 512b, then casted to cint16
        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            accum_type<16> tmp = (v16acc64) mul_op(coef_v,
                                                   ((v.template grow_extract<16>(idx)).template grow<32>()).template cast_to<cint16>(),
                                                   (v8cacc64) acc.template grow_extract<16>(idx)...);

            ret.insert(idx, tmp.template extract<(Lanes < 16? Lanes : 16)>(0));
        });

        return ret;
    }
};

template <unsigned Lanes, unsigned N_Coeff, Operation Op, int Step>
struct consume_terms<64, Lanes, 32,  int32, N_Coeff, 32,  int32, Op, Step>
{
    using T_Data  = int32;
    using T_Coeff = int32;

    using accum_tag = accum_tag_for_mul_types<T_Coeff, T_Data, 64>;

    template <unsigned Elems = Lanes>
    using        accum_type = accum<accum_tag, Elems>;
    using coeff_vector_type = vector<T_Coeff, N_Coeff>;
    using  data_vector_type = vector<T_Data, Lanes>;

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<> consume_2(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &x, const data_vector_type &y, const Acc &... acc)
    {
        accum_type<> ret;

        ret = consume_1(coeff, coeff_start,        x, acc...);
        ret = consume_1(coeff, coeff_start + Step, y, ret);

        return ret;
    }

    template <typename... Acc> requires((is_accum_v<Acc> && ...))
    static accum_type<> consume_1(const coeff_vector_type &coeff, unsigned coeff_start, const data_vector_type &v, const Acc &... acc)
    {
        constexpr auto mul_op = get_mul_op<sizeof...(acc) == 1, Op, accum_type<>, 32, 32>();
        constexpr unsigned num_mul = Lanes < 32? 1 : Lanes / 16;

        auto [t1, t2] = interleave_zip<int32, 8>::run(broadcast<int32, 8>::run(coeff[coeff_start]),
                                                      zeros<int32, 8>::run(),
                                                      1);

        vector<cint32, 8> coefs = concat_vector(t1, t2).template cast_to<cint32>();

        accum_type<> ret;

        utils::unroll_times<num_mul>([&](auto idx) __aie_inline {
            accum_type<16> tmp = (v16acc64) mul_op(v.template grow_extract<16>(idx).template cast_to<cint32>(),
                                                   coefs,
                                                   (v8cacc64) acc.template grow_extract<16>(idx)...);
            ret.insert(idx, tmp.template extract<(Lanes < 16? Lanes : 16)>(0));
        });

        return ret;
    }
};
}

#endif
