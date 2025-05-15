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

#ifndef __AIE_API_DETAIL_AIE2_ACCUM__HPP__
#define __AIE_API_DETAIL_AIE2_ACCUM__HPP__

#include "accum_native_types.hpp"

#include "../utils.hpp"
#include "../../vector.hpp"

namespace aie::detail {

template <AccumClass Class, unsigned MinBits>
static constexpr unsigned to_native_accum_bits()
{
    if constexpr (Class == AccumClass::FP || Class == AccumClass::CFP) {
        static_assert(MinBits <= 32);

        return 32;
    }
    else {
        static_assert(MinBits <= 64);

        if constexpr (MinBits <= 32 && Class == AccumClass::Int)
            return 32;
        else if constexpr (MinBits <= 64)
            return 64;
    }
}

template <typename AccumTag>
static constexpr unsigned to_native_accum_bits()
{
    return to_native_accum_bits<accum_class_for_tag_v<AccumTag>, accum_bits_for_tag_v<AccumTag>>();
}

template <typename AccumTag>
static constexpr unsigned to_native_value_bits()
{
  if constexpr (accum_class_for_tag_v<AccumTag> == AccumClass::CInt || accum_class_for_tag_v<AccumTag> == AccumClass::CFP)
      return 2 * to_native_accum_bits<AccumTag>();
  else
      return to_native_accum_bits<AccumTag>();
}

template <AccumClass Class, unsigned Bits, unsigned DstElems, typename T>
static __aie_inline accum_storage_t<Class, Bits, DstElems> accum_cast_helper(T &&from)
{
    if constexpr (Class == AccumClass::Int) {
        if constexpr (Bits == 32 && DstElems == 8)   return v8acc32(from);
        if constexpr (Bits == 32 && DstElems == 16)  return v16acc32(from);
        if constexpr (Bits == 32 && DstElems == 32)  return v32acc32(from);
        if constexpr (Bits == 32 && DstElems == 64)  return { v32acc32(from[0]), v32acc32(from[1]) };
        if constexpr (Bits == 32 && DstElems == 128) return { v32acc32(from[0]), v32acc32(from[1]), v32acc32(from[2]), v32acc32(from[3])  };

        if constexpr (Bits == 64 && DstElems == 4)   return v4acc64(from);
        if constexpr (Bits == 64 && DstElems == 8)   return v8acc64(from);
        if constexpr (Bits == 64 && DstElems == 16)  return v16acc64(from);
        if constexpr (Bits == 64 && DstElems == 32)  return { v16acc64(from[0]), v16acc64(from[1]) };
        if constexpr (Bits == 64 && DstElems == 64)  return { v16acc64(from[0]), v16acc64(from[1]), v16acc64(from[2]), v16acc64(from[3]) };
    }
    else if constexpr (Class == AccumClass::FP) {
        if constexpr (DstElems == 4)                 return v8accfloat(from);
        if constexpr (DstElems == 8)                 return v8accfloat(from);
        if constexpr (DstElems == 16)                return v16accfloat(from);
        if constexpr (DstElems == 32)                return v32accfloat(from);
        if constexpr (DstElems == 64)                return { v32accfloat(from[0]), v32accfloat(from[1]) };
        if constexpr (DstElems == 128)               return { v32accfloat(from[0]), v32accfloat(from[1]), v32accfloat(from[2]), v32accfloat(from[3]) };
    }
    else if constexpr (Class == AccumClass::CInt) {
        if constexpr (DstElems == 2)                 return v2cacc64(from);
        if constexpr (DstElems == 4)                 return v4cacc64(from);
        if constexpr (DstElems == 8)                 return v8cacc64(from);
        if constexpr (DstElems == 16)                return { v8cacc64(from[0]), v8cacc64(from[1]) };
        if constexpr (DstElems == 32)                return { v8cacc64(from[0]), v8cacc64(from[1]), v8cacc64(from[2]), v8cacc64(from[3]) };
    }
#if __AIE_API_COMPLEX_FP32_EMULATION__
    else if constexpr (Class == AccumClass::CFP) {
        if constexpr (DstElems == 2)                 return v4caccfloat(from);
        if constexpr (DstElems == 4)                 return v4caccfloat(from);
        if constexpr (DstElems == 8)                 return v8caccfloat(from);
        if constexpr (DstElems == 16)                return v16caccfloat(from);
        if constexpr (DstElems == 32)                return { v16caccfloat(from[0]), v16caccfloat(from[1]) };
        if constexpr (DstElems == 64)                return { v16caccfloat(from[0]), v16caccfloat(from[1]), v16caccfloat(from[2]), v16caccfloat(from[3]) };
    }
#endif
}

template <AccumClass Class, unsigned Bits, unsigned DstElems, typename Acc>
static __aie_inline auto extract_helper(const Acc & acc, unsigned idx)
{
    // Note: we use 256b native accumulators for floating point 128b accumulators
    if constexpr (Class == AccumClass::FP) {
        if      constexpr (DstElems == 4)      return ::extract_v8accfloat(acc, idx / 2);
        else if constexpr (DstElems == 8)      return ::extract_v8accfloat(acc, idx);
        else if constexpr (DstElems == 16)     return ::extract_v16accfloat(acc, idx);
    }
#if __AIE_API_COMPLEX_FP32_EMULATION__
    else if constexpr (Class == AccumClass::CFP) {
        if      constexpr (DstElems == 2)      return ::extract_v4caccfloat(acc, idx / 2);
        else if constexpr (DstElems == 4)      return ::extract_v4caccfloat(acc, idx);
        else if constexpr (DstElems == 8)      return ::extract_v8caccfloat(acc, idx);
    }
#endif
    else if constexpr (Class == AccumClass::CInt) {
        if constexpr (Bits == 64) {
            if      constexpr (DstElems == 2)  return ::extract_v2cacc64(acc, idx);
            else if constexpr (DstElems == 4)  return ::extract_v4cacc64(acc, idx);
        }
    }
    else {
        if constexpr (Bits == 32) {
            if      constexpr (DstElems == 8)  return ::extract_v8acc32(acc, idx);
            else if constexpr (DstElems == 16) return ::extract_v16acc32(acc, idx);
        }
        else if constexpr (Bits == 64) {
            if      constexpr (DstElems == 4)  return ::extract_v4acc64(acc, idx);
            else if constexpr (DstElems == 8)  return ::extract_v8acc64(acc, idx);
        }
    }
}

template <AccumClass Class, unsigned MinBits, unsigned Elems>
class accum_base
{
    static constexpr unsigned Bits = to_native_accum_bits<Class, MinBits>();

    using storage_type = accum_storage<Class, Bits, Elems>;

    template <AccumClass C2, unsigned MN2, unsigned E2>
    friend class accum_base;

public:
    using value_type = accum_tag_t<Class, MinBits>;
    using storage_t  = accum_storage_t<Class, Bits, Elems>;

    static constexpr AccumClass value_class()
    {
        return Class;
    }

    static constexpr unsigned accum_bits()
    {
        return Bits;
    }

    static constexpr unsigned accum_min_bits()
    {
        return MinBits;
    }

    static constexpr unsigned value_bits()
    {
        if constexpr (is_complex())
            return accum_bits() * 2;
        else
            return accum_bits();
    }

    static constexpr unsigned memory_bits()
    {
        constexpr unsigned v = value_bits();

        if constexpr (utils::is_powerof2(v)) {
            return v;
        }
        else {
            return 1u << (utils::fls(v) + 1);
        }
    }

    static constexpr unsigned size()
    {
        return Elems;
    }

    static constexpr unsigned bits()
    {
        if constexpr (is_complex())
            return 2 * Bits * size();
        else
            return Bits * size();
    }

    static constexpr bool is_complex()
    {
        return (Class == AccumClass::CInt)
#if __AIE_API_COMPLEX_FP32_EMULATION__
            || (Class == AccumClass::CFP)
#endif
            ;
    }

    static constexpr bool is_real()
    {
        return !is_complex();
    }

    static constexpr bool is_floating_point()
    {
        return (Class == AccumClass::FP)
#if __AIE_API_COMPLEX_FP32_EMULATION__
            || (Class == AccumClass::CFP)
#endif
            ;
    }

    __aie_inline
    accum_base() :
        data(storage_type::undef())
    {
    }

    template <unsigned MinBits2> requires(accum_base<Class, MinBits2, Elems>::accum_bits() == accum_bits())
    __aie_inline
    accum_base(const accum_base<Class, MinBits2, Elems> &acc) :
        data(acc.data)
    {
    }

    __aie_inline
    accum_base(storage_t data) :
        data(data)
    {
        // Input is taken by value to avoid losing chess_storage qualifiers
    }

    template <typename T>
    __aie_inline
    explicit accum_base(const vector<T, Elems> &v, int shift = 0)
    {
        from_vector(v, shift);
    }

    __aie_inline
    operator storage_t() const
    {
        return data;
    }

    __aie_inline
    auto to_native() const
    {
        static_assert(utils::num_elems_v<storage_t> == 1);

        return data;
    }

    template <typename DstTag>
    __aie_inline
    auto cast_to() const
    {
        constexpr unsigned DstSize  = to_native_value_bits<DstTag>();
        constexpr unsigned DstElems = (DstSize <= value_bits())? Elems * (value_bits() / DstSize) :
                                                                 Elems / (     DstSize / value_bits());

        constexpr AccumClass DstClass  = accum_class_for_tag_v<DstTag>;

        constexpr unsigned RealDstSize = to_native_accum_bits<DstTag>();

        accum_base<DstClass, RealDstSize, DstElems> ret;
        ret = accum_cast_helper<DstClass, RealDstSize, DstElems>(data);

        return ret;
    }

    template <unsigned ElemsOut>
    __aie_inline
    accum_base<Class, MinBits, ElemsOut> grow() const
    {
        static_assert(ElemsOut >= size());

        using storage_out_t = accum_storage_t<Class, Bits, ElemsOut>;

        constexpr unsigned num_accums_out = utils::num_elems_v<storage_out_t>;
        accum_base<Class, MinBits, ElemsOut> ret;

        //Special case with no v4accfloat, which we represent with a v8accfloat internally for the storage type
        constexpr unsigned elem_ratio = []() { if      constexpr (Class == AccumClass::FP  && Elems == 4) return ElemsOut / (2 * Elems) ;
#if __AIE_API_COMPLEX_FP32_EMULATION__
                                               else if constexpr (Class == AccumClass::CFP && Elems == 2) return ElemsOut / (2 * Elems) ;
#endif
                                               else                                                       return ElemsOut / Elems;
                                             }();

        if constexpr (ElemsOut == size()) {
            ret = *this;
        }
        else if constexpr (num_accums_out == 1) {
            if constexpr (elem_ratio == 1 )
                ret = data;
            else if constexpr (elem_ratio == 2)
                ret = ::concat(data, storage_type::undef());
            else if constexpr (elem_ratio == 4)
                ret = ::concat(data, storage_type::undef(), storage_type::undef(), storage_type::undef());
        }
        else if constexpr (num_accums_out == 2) {
            if constexpr (elem_ratio == 2) {
                ret = storage_out_t{ data,
                                    storage_type::undef() };
            }
            else if constexpr (elem_ratio == 4) {
                using storage_double_type = accum_storage<Class, Bits, Elems * 2>;

                ret = storage_out_t{ ::concat(data, storage_type::undef()),
                                     storage_double_type::undef() };
            }
        }
        else if constexpr (num_accums_out == 4) {
            if constexpr (elem_ratio == 2) {
                using storage_half_type = accum_storage<Class, Bits, Elems / 2>;

                ret =  storage_out_t{ data[0],
                                      data[1],
                                      storage_half_type::undef(),
                                      storage_half_type::undef() };
            }
            else if constexpr (elem_ratio == 4) {
                ret =  storage_out_t{ data,
                                      storage_type::undef(),
                                      storage_type::undef(),
                                      storage_type::undef() };
            }
            else if constexpr (elem_ratio == 8) {
                using storage_double_type = accum_storage<Class, Bits, Elems * 2>;

                ret =  storage_out_t{ ::concat(data),
                                      storage_double_type::undef(),
                                      storage_double_type::undef(),
                                      storage_double_type::undef() };
            }
        }

        return ret;
    }

    template <unsigned ElemsOut>
    __aie_inline
    accum_base<Class, MinBits, ElemsOut> extract(unsigned idx) const
    {
        static_assert(ElemsOut <= size());

        using storage_out_t = accum_storage_t<Class, Bits, ElemsOut>;

        constexpr unsigned num_subaccums     = utils::num_elems_v<storage_t>;
        constexpr unsigned num_subaccums_out = utils::num_elems_v<storage_out_t>;

        if constexpr (ElemsOut == size()) {
            return *this;
        }
        else {
            constexpr unsigned out_elems_per_subaccum = ElemsOut / num_subaccums_out;
            constexpr unsigned elems_per_subaccum     = Elems  / num_subaccums;

            accum_base<Class, MinBits, ElemsOut> ret;

            if constexpr (num_subaccums_out == 1) {
                if constexpr (elems_per_subaccum == out_elems_per_subaccum) {
                    ret = data[idx];
                    return ret;
                }
                else if constexpr (num_subaccums == 1) {
                    ret = extract_helper<Class, Bits, ElemsOut>(data, idx);
                    return ret;
                }
                else {
                    ret = extract_helper<Class, Bits, ElemsOut>(data[idx / (elems_per_subaccum / out_elems_per_subaccum)],
                                                                idx % (elems_per_subaccum / out_elems_per_subaccum));
                    return ret;
                }
            }
            else if constexpr (num_subaccums_out == 2) {
                ret = storage_out_t{data[idx * 2], data[idx * 2 + 1]};

                return ret;
            }
            else {
                UNREACHABLE_MSG("Unhandled case\n");
            }
        }
    }

    template <unsigned ElemsOut>
    __aie_inline
    accum_base<Class, MinBits, ElemsOut> grow_extract(unsigned idx) const
    {
        if constexpr (ElemsOut > Elems)
            return grow<ElemsOut>();
        else
            return extract<ElemsOut>(idx);
    }

    template <unsigned ElemsIn, unsigned Bits2>
    __aie_inline
    accum_base &insert(unsigned idx, const accum_base<Class, Bits2, ElemsIn> &acc)
    {
        static_assert(ElemsIn <= Elems);
        static_assert(to_native_accum_bits<Class, Bits2>() == Bits);

        constexpr unsigned in_num_subaccums = utils::num_elems_v<accum_storage_t<Class, Bits, ElemsIn>>;
        constexpr unsigned    num_subaccums = utils::num_elems_v<accum_storage_t<Class, Bits, Elems>>;

        static_assert(in_num_subaccums <= num_subaccums);

        if constexpr (ElemsIn == Elems) {
            data = acc.data;

            return *this;
        }
        else {
            constexpr unsigned in_elems_per_subaccum = ElemsIn / in_num_subaccums;
            constexpr unsigned    elems_per_subaccum = Elems  / num_subaccums;
            static_assert(in_elems_per_subaccum <= elems_per_subaccum);

            if constexpr (in_num_subaccums == 1) {
                if constexpr (in_elems_per_subaccum == elems_per_subaccum) {
                    data[idx] = acc.data;

                    return *this;
                }
                else if constexpr (num_subaccums == 1) {
                    data = ::insert(data, idx, acc.data);

                    return *this;
                }
                else {
                    constexpr unsigned ratio = elems_per_subaccum / in_elems_per_subaccum;
                    data[idx / ratio] = ::insert(data[idx / ratio], idx % ratio, acc.data);

                    return *this;
                }
            }
            else {
                #pragma unroll
                for (unsigned i = 0; i < in_num_subaccums; ++i)
                    data[i + in_num_subaccums * idx] = acc.data[i];

                return *this;
            }
        }
    }

    template <unsigned ElemsIn>
    __aie_inline
    accum_base &insert(unsigned idx, typename accum_base<Class, MinBits, ElemsIn>::storage_t acc)
    {
        const accum_base<Class, MinBits, ElemsIn> in = acc;

        return insert(idx, in);
    }

    template <typename T>
    __aie_inline
    vector<T, Elems> to_vector_sign(bool v_sign, int shift = 0) const //TODO: What order of params do we want with the shift having a default?
    {
        if constexpr (utils::is_one_of_v<T, int4, uint4>) {
            return to_vector_sign<utils::get_next_integer_type_t<T>>(v_sign, shift).pack_sign(v_sign);
        }
        else {
            constexpr auto fn = get_srs<T>();

            vector<T, Elems> ret;

            if constexpr (utils::num_elems_v<vector_storage_t<T, Elems>> == 1) {
                if constexpr (utils::num_elems_v<storage_t> == 1) {
                    ret = fn(data, shift, v_sign);
                    return ret;
                }
                else if constexpr (utils::num_elems_v<storage_t> == 2) {
                    ret = ::concat(fn(data[0], shift, v_sign),
                                   fn(data[1], shift, v_sign));
                    return ret;
                }
                else if constexpr (utils::num_elems_v<storage_t> == 4) {
                    ret = ::concat(fn(data[0], shift, v_sign),
                                   fn(data[1], shift, v_sign),
                                   fn(data[2], shift, v_sign),
                                   fn(data[3], shift, v_sign));
                    return ret;
                }
            }
            else if constexpr (utils::num_elems_v<vector_storage_t<T, Elems>> == 2) {
                if constexpr (utils::num_elems_v<storage_t> == 1) {
                    ret.insert(0, extract<Elems / 2>(0).template to_vector_sign<T>(v_sign, shift));
                    ret.insert(1, extract<Elems / 2>(1).template to_vector_sign<T>(v_sign, shift));
                    return ret;
                }
                else if constexpr (utils::num_elems_v<storage_t> == 2) {
                    const vector<T, Elems / 2> tmp1 = fn(data[0], shift, v_sign); ret.insert(0, tmp1);
                    const vector<T, Elems / 2> tmp2 = fn(data[1], shift, v_sign); ret.insert(1, tmp2);
                    return ret;
                }
                else if constexpr (utils::num_elems_v<storage_t> == 4) {
                    const vector<T, Elems / 4> tmp1 = fn(data[0], shift, v_sign); ret.insert(0, tmp1);
                    const vector<T, Elems / 4> tmp2 = fn(data[1], shift, v_sign); ret.insert(1, tmp2);
                    const vector<T, Elems / 4> tmp3 = fn(data[2], shift, v_sign); ret.insert(2, tmp3);
                    const vector<T, Elems / 4> tmp4 = fn(data[3], shift, v_sign); ret.insert(3, tmp4);
                    return ret;
                }
            }
        }
    }

    template <typename T>
    __aie_inline
    vector<T, Elems> to_vector(int shift = 0) const
    {
        return to_vector_sign<T>(is_signed_v<T>, shift);
    }

    template <typename T>
    __aie_inline
    void from_vector_sign(const vector<T, Elems> &v, bool v_sign, int shift = 0)
    {
        if constexpr (utils::is_one_of_v<T, int4, uint4>) {
            // Elems maximum value is 128, so 1024b int4/uint4 vectors are not allowed
            from_vector_sign(v.unpack_sign(v_sign), v_sign, shift);
        }
        else if constexpr (utils::is_one_of_v<T, int8, uint8> && Bits > 32) {
            from_vector_sign(v.unpack_sign(v_sign), v_sign, shift);
        }
        else {
            if constexpr (utils::num_elems_v<storage_t> == 1) {
                if constexpr (utils::num_elems_v<typename vector<T, Elems>::storage_t> == 1) {
                    constexpr auto fn = get_ups<T, Elems>();

                    if constexpr (vector<T, Elems>::bits() == 128)
                        data = fn(v.template grow<Elems * 2>(), shift, v_sign);
                    else
                        data = fn(v, shift, v_sign);
                }
                else if constexpr (utils::num_elems_v<typename vector<T, Elems>::storage_t> == 2) {
                    constexpr auto fn = get_ups<T, Elems / 2>();

                    this->insert<Elems / 2>(0, fn(v.template extract<Elems / 2>(0), shift, v_sign));
                    this->insert<Elems / 2>(1, fn(v.template extract<Elems / 2>(1), shift, v_sign));
                }
            }
            else if constexpr (utils::num_elems_v<storage_t> == 2) {
                constexpr auto fn = get_ups<T, Elems / 2>();

                data[0] = fn(v.template extract<Elems / 2>(0), shift, v_sign);
                data[1] = fn(v.template extract<Elems / 2>(1), shift, v_sign);
            }
            else if constexpr (utils::num_elems_v<storage_t> == 4) {
                constexpr auto fn = get_ups<T, Elems / 4>();

                data[0] = fn(v.template extract<Elems / 4>(0), shift, v_sign);
                data[1] = fn(v.template extract<Elems / 4>(1), shift, v_sign);
                data[2] = fn(v.template extract<Elems / 4>(2), shift, v_sign);
                data[3] = fn(v.template extract<Elems / 4>(3), shift, v_sign);
            }
            else {
                UNREACHABLE_MSG("Unhandled case\n");
            }
        }
    }

    template <typename T>
    __aie_inline
    void from_vector(const vector<T, Elems> &v, int shift = 0)
    {
        from_vector_sign(v, is_signed_v<T>, shift);
    }

    template <unsigned E2, unsigned... Es>
        requires(Elems == (E2 + (Es + ...)) && ((Elems / E2 == Elems / Es) && ...))
    __aie_inline
    void upd_all(const accum_base<Class, MinBits, E2> &subacc, const accum_base<Class, MinBits, Es> & ...subaccums)
    {
        constexpr unsigned num_subaccums  = 1 + sizeof...(Es);
        constexpr unsigned num_storage_slots = utils::num_elems_v<storage_t>;

        if constexpr (num_storage_slots == 1) {
            data = ::concat(subacc, subaccums...);
        }
        else if constexpr (num_storage_slots == num_subaccums) {
            data = { subacc, subaccums... };
        }
        else if constexpr (num_storage_slots > num_subaccums) {
            constexpr unsigned ratio = num_storage_slots / num_subaccums;

            const std::array t = {subacc, subaccums...};
            utils::unroll_times<num_storage_slots>([&](auto i) __aie_inline {
                unsigned sub_idx = i / ratio;
                unsigned sub_chunk = i % ratio;
                data[i] = t[sub_idx].template extract<Elems / num_storage_slots>(sub_chunk);
            });
        } else { // num_storage_slots < num_subaccums
            static_assert(num_subaccums % num_storage_slots == 0);

            const std::array t = {subacc, subaccums...};
            if constexpr (num_subaccums / num_storage_slots == 2) {
                utils::unroll_times<num_storage_slots>([&](auto i) __aie_inline {
                    data[i] = ::concat(t[i * 2], t[i * 2 + 1]);
                });
            }
            else if constexpr (num_subaccums / num_storage_slots == 4) {
                utils::unroll_times<num_storage_slots>([&](auto i) __aie_inline {
                    data[i] = ::concat(t[i * 4], t[i * 4 + 1], t[i * 4 + 2], t[i * 4 + 3]);
                });
            }
            else {
                UNREACHABLE_MSG("Unhandled case\n");
            }
        }
    }

private:
    template <typename T, unsigned Elems2>
    static constexpr auto get_ups()
    {
        if constexpr (std::is_same_v<T, bfloat16>) {
            if constexpr      (Elems2 == 8)
                return [](const auto &v, auto shift_dummy, auto sign_dummy) __aie_inline { return ::extract_v8accfloat(::ups_to_v16accfloat(v), 0); };
            else if constexpr (Elems2 == 16)
                return [](const auto &v, auto shift_dummy, auto sign_dummy) __aie_inline { return ::ups_to_v16accfloat(v); };
            else
#if __AIE_API_32ELEM_FLOAT_SRS_UPS__
                return [](const auto &v, auto shift_dummy, auto sign_dummy) __aie_inline { return ::ups_to_v32accfloat(v); };
#else
                return [](const auto &v, auto shift_dummy, auto sign_dummy) __aie_inline { return ::concat(::ups_to_v16accfloat(::extract_v16bfloat16(v, 0)), ::ups_to_v16accfloat(::extract_v16bfloat16(v, 1))); };
#endif
        }
        else if constexpr (std::is_same_v<T, float>) {
            if constexpr      (Elems == 4 || Elems2 == 8)
                return [](const auto &v, auto shift_dummy, auto sign_dummy) __aie_inline { return (v8accfloat)(v); };
            else if constexpr (Elems2 == 16)
                return [](const auto &v, auto shift_dummy, auto sign_dummy) __aie_inline { return (v16accfloat)(v); };
            else
                return [](const auto &v, auto shift_dummy, auto sign_dummy) __aie_inline { return (v32accfloat)(v); };
        }
#if __AIE_API_COMPLEX_FP32_EMULATION__
        else if constexpr (std::is_same_v<T, cfloat>) {
            if constexpr      (Elems == 2 || Elems2 == 4)
                return [](const auto &v, auto shift_dummy, auto sign_dummy) __aie_inline { return (v4caccfloat)(v);  };
            else if constexpr (Elems2 == 8)
                return [](const auto &v, auto shift_dummy, auto sign_dummy) __aie_inline { return (v8caccfloat)(v);  };
            else
                return [](const auto &v, auto shift_dummy, auto sign_dummy) __aie_inline { return (v16caccfloat)(v); };
        }
#endif
        else if constexpr (utils::is_one_of_v<T, int8, uint8>) {
            if constexpr (Elems2 == 16)
                return [](const auto &v, int shift, bool sign) __aie_inline { return ::extract_v16acc32(::ups_to_v32acc32(v.template grow<32>(), shift, sign), 0); };
            else
                return [](const auto &v, int shift, bool sign) __aie_inline { return ::ups_to_v32acc32(v, shift, sign); };
        }
        else if constexpr (utils::is_one_of_v<T, int16, uint16>) {
            if constexpr (Bits == 32) {
                if constexpr (Elems2 == 8)
                    return [](const auto &v, int shift, bool sign) __aie_inline { return ::extract_v8acc32(::ups_to_v16acc32(v, shift, sign), 0); };
                else if constexpr (Elems2 == 16)
                    return [](const auto &v, int shift, bool sign) __aie_inline { return ::ups_to_v16acc32(v, shift, sign); };
                else
                    return [](const auto &v, int shift, bool sign) __aie_inline { return ::ups_to_v32acc32(v, shift, sign); };
            }
            else if constexpr (Bits == 64) {
                if constexpr (Elems2 == 8)
                    return [](const auto &v, int shift, bool sign) __aie_inline { return ::extract_v8acc64(::ups_to_v16acc64(v, shift, sign), 0); };
                else
                    return [](const auto &v, int shift, bool sign) __aie_inline { return ::ups_to_v16acc64(v, shift, sign); };
            }
        }
        else if constexpr (utils::is_one_of_v<T, int32, uint32>) {
            if constexpr (Bits == 64) {
                if constexpr (Elems2 == 4)
                    return [](const auto &v, int shift, bool sign) __aie_inline { return ::extract_v4acc64(::ups_to_v8acc64(v, shift, sign), 0); };
                else if constexpr (Elems2 == 8)
                    return [](const auto &v, int shift, bool sign) __aie_inline { return ::ups_to_v8acc64(v, shift, sign); };
                else
                    return [](const auto &v, int shift, bool sign) __aie_inline { return ::ups_to_v16acc64(v, shift, sign); };
            }
            else if constexpr (Bits == 32 && std::is_same_v<int32, T>) {
                // TODO: should we add support for shift != 0 in this scenario?
                if      constexpr (Elems2 == 8)
                    return [](const auto &v, int shift, bool sign) __aie_inline { REQUIRES(shift == 0); return (v8acc32)v; };
                else if constexpr (Elems2 == 16)
                    return [](const auto &v, int shift, bool sign) __aie_inline { REQUIRES(shift == 0); return (v16acc32)v; };
            }
        }
        else if constexpr (utils::is_one_of_v<T, cint16>) {
            if constexpr (Bits == 64) {
                if constexpr (Elems2 == 4)
                    return [](const auto &v, int shift, bool sign) __aie_inline { return ::extract_v4cacc64(::ups_to_v8cacc64(v, shift, sign), 0); };
                else
                    return [](const auto &v, int shift, bool sign) __aie_inline { return ::ups_to_v8cacc64(v, shift, sign);  };
            }
        }
        else if constexpr (utils::is_one_of_v<T, cint32>) {
            if constexpr (Elems2 == 2)
                return [](const auto &v, int shift, bool sign) __aie_inline { return ::extract_v2cacc64(::ups_to_v4cacc64(v, shift, sign), 0); };
            else if constexpr (Elems2 == 4)
                return [](const auto &v, int shift, bool sign) __aie_inline { return ::ups_to_v4cacc64(v, shift, sign);  };
            else
                return [](const auto &v, int shift, bool sign) __aie_inline { return ::ups_to_v8cacc64(v, shift, sign);  };
        }
    }

    template <typename T>
    static constexpr auto get_srs()
    {
        if constexpr (std::is_same_v<T, bfloat16>) {
            if constexpr (Elems == 8)
                return [](const auto &acc, auto shift_dummy, auto sign_dummy) __aie_inline { return ::extract_v8bfloat16(::to_v16bfloat16(::set_v16accfloat(0, acc)), 0); };
            else if constexpr (Elems == 16)
                return [](const auto &acc, auto shift_dummy, auto sign_dummy) __aie_inline { return ::to_v16bfloat16(acc); };
            else
#if __AIE_API_32ELEM_FLOAT_SRS_UPS__
                return [](const auto &acc, auto shift_dummy, auto sign_dummy) __aie_inline { return ::to_v32bfloat16(acc); };
#else
                return [](const auto &acc, auto shift_dummy, auto sign_dummy) __aie_inline { return ::concat(::to_v16bfloat16(::extract_v16accfloat(acc, 0)), ::to_v16bfloat16(::extract_v16accfloat(acc, 1))); };
#endif
        }
        else if constexpr (std::is_same_v<T, float>) {
            if constexpr (Elems == 4)
                return [](const auto &acc, auto shift_dummy, auto sign_dummy) __aie_inline { return ::extract_v4float((v8float) acc, 0); };
            if constexpr (Elems == 8)
                return [](const auto &acc, auto shift_dummy, auto sign_dummy) __aie_inline { return (v8float) acc;  };
            else if constexpr (Elems == 16)
                return [](const auto &acc, auto shift_dummy, auto sign_dummy) __aie_inline { return (v16float) acc; };
            else if constexpr (Elems == 32)
                return [](const auto &acc, auto shift_dummy, auto sign_dummy) __aie_inline { return (v32float) acc; };
        }
#if __AIE_API_COMPLEX_FP32_EMULATION__
        else if constexpr (std::is_same_v<T, cfloat>) {
            if constexpr (Elems == 2)
                return [](const auto &acc, auto shift_dummy, auto sign_dummy) __aie_inline { return ::extract_v2cfloat((v4cfloat) acc, 0); };
            if constexpr (Elems == 4)
                return [](const auto &acc, auto shift_dummy, auto sign_dummy) __aie_inline { return (v4cfloat) acc;  };
            else if constexpr (Elems == 8)
                return [](const auto &acc, auto shift_dummy, auto sign_dummy) __aie_inline { return (v8cfloat) acc;  };
            else if constexpr (Elems == 16)
                return [](const auto &acc, auto shift_dummy, auto sign_dummy) __aie_inline { return (v16cfloat) acc; };
        }
#endif
        else if constexpr (std::is_same_v<T, int8>) {
            if constexpr (Bits == 32) {
                if constexpr (Elems == 16)
                    return [](const auto &acc, int shift, bool sign) __aie_inline { return vector_extract<16>(::srs_to_v32int8(::set_v32acc32(0, acc), shift, sign), 0); };
                else
                    return [](const auto &acc, int shift, bool sign) __aie_inline { return ::srs_to_v32int8(acc, shift, sign); };
            }
            else if constexpr (Bits == 64) {
                return [](const auto &acc, int shift, bool sign) __aie_inline { return ::extract_v16int8(::pack(::set_v32int16(0,::srs_to_v16int16(acc, shift, sign)), sign), 0); };
            }
        }
        else if constexpr (std::is_same_v<T, uint8>) {
            if constexpr (Bits == 32) {
                if constexpr (Elems == 16)
                    return [](const auto &acc, int shift, bool sign) __aie_inline { return vector_extract<16>(::srs_to_v32uint8(::set_v32acc32(0, acc), shift, sign), 0); };
                else
                    return [](const auto &acc, int shift, bool sign) __aie_inline { return ::srs_to_v32uint8(acc, shift, sign);  };
            }
            else if constexpr (Bits == 64) {
                return [](const auto &acc, int shift, bool sign) __aie_inline { return ::extract_v16uint8(::pack(::set_v32uint16(0,::srs_to_v16uint16(acc, shift, sign)), sign), 0); };
            }
        }
        else if constexpr (std::is_same_v<T, int16>) {
            if constexpr (Bits == 32) {
                if constexpr (Elems == 8)
                    return [](const auto &acc, int shift, bool sign) __aie_inline { return vector_extract<8>(::srs_to_v16int16(::set_v16acc32(0, acc), shift, sign), 0); };
                else if constexpr (Elems == 16)
                    return [](const auto &acc, int shift, bool sign) __aie_inline { return ::srs_to_v16int16(acc, shift, sign);  };
                else
                    return [](const auto &acc, int shift, bool sign) __aie_inline { return ::srs_to_v32int16(acc, shift, sign);  };
            }
            else if constexpr (Bits == 64) {
                if constexpr (Elems == 8)
                    return [](const auto &acc, int shift, bool sign) __aie_inline { return vector_extract<8>(::srs_to_v16int16(::set_v16acc64(0, acc), shift, sign), 0); };
                else
                    return [](const auto &acc, int shift, bool sign) __aie_inline { return ::srs_to_v16int16(acc, shift, sign); };
            }
        }
        else if constexpr (std::is_same_v<T, uint16>) {
            if constexpr (Bits == 32) {
                if constexpr (Elems == 8)
                    return [](const auto &acc, int shift, bool sign) __aie_inline { return vector_extract<8>(::srs_to_v16uint16(::set_v16acc32(0, acc), shift, sign), 0); };
                else if constexpr (Elems == 16)
                    return [](const auto &acc, int shift, bool sign) __aie_inline { return ::srs_to_v16uint16(acc, shift, sign);  };
                else
                    return [](const auto &acc, int shift, bool sign) __aie_inline { return ::srs_to_v32uint16(acc, shift, sign);  };
            }
            else if constexpr (Bits == 64) {
                if constexpr (Elems == 8)
                    return [](const auto &acc, int shift, bool sign) __aie_inline { return vector_extract<8>(::srs_to_v16uint16(::set_v16acc64(0, acc), shift, sign), 0); };
                else
                    return [](const auto &acc, int shift, bool sign) __aie_inline { return ::srs_to_v16uint16(acc, shift, sign); };
            }
        }
        else if constexpr (std::is_same_v<T, int32>) {
            if constexpr (Bits == 32) {
                if constexpr (Elems == 8)
                    return [](const auto &acc, int shift, bool sign) __aie_inline { return (v8int32) acc; };
                else if constexpr (Elems == 16)
                    return [](const auto &acc, int shift, bool sign) __aie_inline { return (v16int32) acc; };
                else if constexpr (Elems == 32)
                    return [](const auto &acc, int shift, bool sign) __aie_inline {
                        vector<int32, 32> ret;
                        ret.insert<16>(0, (v16int32)acc.template extract<16>(0)); //TODO: Handle dynamic sign with extract
                        ret.insert<16>(1, (v16int32)acc.template extract<16>(1));

                        return ret;
                    };
            }
            else if constexpr (Bits == 64) {
                if constexpr (Elems == 4)
                    return [](const auto &acc, int shift, bool sign) __aie_inline { return vector_extract<4>(::srs_to_v8int32(::set_v8acc64(0, acc), shift, sign), 0);  };
                else if constexpr (Elems == 8)
                    return [](const auto &acc, int shift, bool sign) __aie_inline { return ::srs_to_v8int32(acc, shift, sign);  };
                else
                    return [](const auto &acc, int shift, bool sign) __aie_inline { return ::srs_to_v16int32(acc, shift, sign);  };
            }
        }
        else if constexpr (std::is_same_v<T, uint32>) {
            if constexpr (Elems == 4)
                return [](const auto &acc, int shift, bool sign) __aie_inline { return vector_extract<4>(::srs_to_v8uint32(::set_v8acc64(0, acc), shift, sign), 0);  };
            else if constexpr (Elems == 8)
                return [](const auto &acc, int shift, bool sign) __aie_inline { return ::srs_to_v8uint32(acc, shift, sign);  };
            else
                return [](const auto &acc, int shift, bool sign) __aie_inline { return ::srs_to_v16uint32(acc, shift, sign);  };
        }
        else if constexpr (std::is_same_v<T, cint16>) {
            if constexpr (Bits == 64) {
                if constexpr (Elems == 4)
                    return [](const auto &acc, int shift, bool sign) __aie_inline { return vector_extract<4>(::srs_to_v8cint16(::set_v8cacc64(0, acc), shift, sign), 0); };
                else
                    return [](const auto &acc, int shift, bool sign) __aie_inline { return ::srs_to_v8cint16(acc, shift, sign); };
            }
        }
        else if constexpr (std::is_same_v<T, cint32>) {
            if constexpr (Elems == 2)
                return [](const auto &acc, int shift, bool sign) __aie_inline { return vector_extract<2>(::srs_to_v4cint32(::set_v4cacc64(0, acc), shift, sign), 0);  };
            else if constexpr (Elems == 4)
                return [](const auto &acc, int shift, bool sign) __aie_inline { return ::srs_to_v4cint32(acc, shift, sign);  };
            else
                return [](const auto &acc, int shift, bool sign) __aie_inline { return ::srs_to_v8cint32(acc, shift, sign);  };
        }
    }

#ifdef AIE_API_EMULATION
    // TODO: floating point
    std::array<uint64_t, Elems> data;
#else
    storage_t data;
#endif
};

}

#endif
