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

#ifndef __AIE_API_MASK__HPP__
#define __AIE_API_MASK__HPP__

#include "detail/utils.hpp"

#include <array>

namespace aie {

template <unsigned Elems>
class mask
{
    template <unsigned Elems2>
    friend class mask;

    using underlying_type = unsigned;

    static constexpr unsigned bits_per_word = sizeof(underlying_type) * 8;
    static constexpr unsigned num_words = (Elems + (bits_per_word - 1)) / bits_per_word;

    static constexpr unsigned bits_remainder = Elems % bits_per_word == 0?          0 : bits_per_word - Elems % bits_per_word;
    static constexpr unsigned last_word_mask = Elems % bits_per_word == 0? 0xffffffff : (1 << (bits_per_word - bits_remainder)) - 1;

    std::array<unsigned, num_words> data_;

    __aie_inline
    static constexpr unsigned get_word_index(unsigned i)
    {
        return i / bits_per_word;
    }

    __aie_inline
    static constexpr unsigned get_bit_index(unsigned i)
    {
        return i % bits_per_word;
    }

    template <unsigned Index, typename... T>
    __aie_inline
    constexpr void init_from_words32(unsigned word, T &&... next_words)
    {
        data_[Index] = word;

        if constexpr (sizeof...(next_words) > 0) {
            init_from_words32<Index + 1>(std::forward<T>(next_words)...);
        }
        else {
            if constexpr (bits_remainder > 0)
                data_[num_words - 1] &= last_word_mask;
        }
    }

    template <unsigned Index, typename... T>
    __aie_inline
    constexpr void init_from_words64(uint64_t word, T &&... next_words)
    {
        static_assert(bits_remainder == 0);

        const auto tmp = __builtin_bit_cast(std::array<unsigned, 2>, word);

        data_[Index * 2]     = tmp[0];
        data_[Index * 2 + 1] = tmp[1];

        if constexpr (sizeof...(next_words) > 0)
            init_from_words64<Index + 1>(std::forward<T>(next_words)...);
    }

    template <unsigned Index, unsigned E, unsigned... Es>
    __aie_inline
    constexpr void init_from_masks(const mask<E> &m, const mask<Es> &... next_masks)
    {
        for (unsigned i = 0; i < m.num_words; ++i) chess_unroll_loop()
            data_[Index * m.num_words + i] = m.data_[i];

        if constexpr (sizeof...(next_masks) > 0)
            init_from_masks<Index + 1>(next_masks...);
    }

    __aie_inline
    static constexpr unsigned count_word(unsigned n)
    {
        unsigned count;

        n     = n - ((n >> 1) & 0x55555555);                    // reuse input as temporary
        n     = (n & 0x33333333) + ((n >> 2) & 0x33333333);     // temp
        count = ((n + (n >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; // count

        return count;
    }

public:
    /**
     * Returns the number of elements in the mask
     */
    static constexpr unsigned size()
    {
        return Elems;
    }

    /**
     * Creates a mask
     *
     * @param initial_set If true, the mask is initialized with 1s, otherise it is initialized with 0s.
     */
    __aie_inline
    constexpr explicit mask(bool initial_set = false) : data_()
    {
        if (initial_set) {
            for (unsigned i = 0; i < num_words - 1; ++i) chess_unroll_loop()
                data_[i] = 0xffffffff;

            data_[num_words - 1] = last_word_mask;
        }
        else {
            for (unsigned i = 0; i < num_words; ++i) chess_unroll_loop()
                data_[i] = 0;
        }
    }

    /**
     * Construct from unsigned (32b) words. Each bit in the input words is used to initialize one of the elements in the
     * mask.
     *
     * @param w     First word used to initialize the mask.
     * @param words Rest of words used to initialize the mask.
     */
    template <typename... T>
    [[deprecated("Use from_uint32 / from_uint64 / from_masks static methods instead")]]
    constexpr explicit mask(unsigned w, T &&... words) : data_()
    {
        static_assert(sizeof...(words) + 1 == num_words);

        init_from_words32<0>(w, std::forward<T>(words)...);
    }

    /**
     * Construct from unsigned (32b) words. Each bit in the input words is used to initialize one of the elements in the
     * mask.
     *
     * @param w     First word used to initialize the mask.
     * @param words Rest of words used to initialize the mask.
     */
    template <typename... T>
    __aie_inline
    constexpr static mask<Elems> from_uint32(unsigned w, T &&... words)
    {
        static_assert(sizeof...(words) + 1 == num_words);

        mask<Elems> ret;

        ret.init_from_words32<0>(w, std::forward<T>(words)...);

        return ret;
    }

    /**
     * Construct from unsigned (64b) words. Each bit in the input words is used to initialize one of the elements in the
     * mask.
     *
     * @param w     First word used to initialize the mask.
     * @param words Rest of words used to initialize the mask.
     */
    template <typename... T>
    __aie_inline
    constexpr static mask<Elems> from_uint64(uint64_t w, T &&... words)
    {
        static_assert(sizeof...(words) + 1 == num_words / 2);

        mask<Elems> ret;

        ret.init_from_words64<0>(w, std::forward<T>(words)...);

        return ret;
    }

    /**
     * Construct from concatenating multiple smaller masks.
     *
     * @param m     First mask used to initialize least significant elements in the new mask.
     * @param masks Other masks used to initialize the rest of the elements.
     */
    template <unsigned E, unsigned... Es>
        requires(Elems == (E + (Es + ...)) && ((E == Es) && ...))
    __aie_inline
    constexpr static mask<Elems> from_masks(const mask<E> &m, const mask<Es>&... masks)
    {
        mask<Elems> ret;
        ret.init_from_masks<0>(m, masks...);

        return ret;
    }

    /**
     * Returns the value of the element in the given index.
     *
     * @param i Element index.
     */
    __aie_inline
    constexpr bool test(unsigned i) const
    {
        return (data_[get_word_index(i)] & (1 << get_bit_index(i))) != 0;
    }

    /**
     * Sets the value of the element in the given index to 1.
     *
     * @param i Element index.
     */
    __aie_inline
    constexpr void set(unsigned i)
    {
        data_[get_word_index(i)] |= (1 << get_bit_index(i));
    }

    /**
     * Sets the value of the element in the given index to 0.
     *
     * @param i Element index.
     */
    __aie_inline
    constexpr void clear(unsigned i)
    {
        data_[get_word_index(i)] &= ~(1 << get_bit_index(i));
    }

    /**
     * Compares whether two masks are equal.
     *
     * @param a Mask to compare against.
     */
    __aie_inline
    constexpr bool operator==(const mask &a) const
    {
        bool ret = true;

        for (unsigned i = 0; i < num_words; ++i) chess_unroll_loop()
            ret = ret && (data_[i] == a.data_[i]);

        return ret;
    }

    /**
     * Returns the result of merging the current and the given masks using the AND operation.
     *
     * @param a Mask to merge with.
     */
    __aie_inline
    constexpr mask operator&(const mask &a) const
    {
        mask ret;

        for (unsigned i = 0; i < num_words; ++i) chess_unroll_loop()
            ret.data_[i] = data_[i] & a.data_[i];

        return ret;
    }

    /**
     * Updates the mask with the result of merging the current with the given masks using the AND operation. Returns
     * a reference to the updated mask.
     *
     * @param a Mask to merge with.
     */
    __aie_inline
    constexpr mask &operator&=(const mask &a)
    {
        for (unsigned i = 0; i < num_words; ++i) chess_unroll_loop()
            data_[i] &= a.data_[i];

        return *this;
    }

    /**
     * Returns the result of merging the current and the given masks using the OR operation.
     *
     * @param a Mask to merge with.
     */
    __aie_inline
    constexpr mask operator|(const mask &a) const
    {
        mask ret;

        for (unsigned i = 0; i < num_words; ++i) chess_unroll_loop()
            ret.data_[i] = data_[i] | a.data_[i];

        return ret;
    }

    /**
     * Updates the mask with the result of merging the current and the given masks using the OR operation. Returns
     * a reference to the updated mask.
     *
     * @param a Mask to merge with.
     */
    __aie_inline
    constexpr mask &operator|=(const mask &a)
    {
        for (unsigned i = 0; i < num_words; ++i) chess_unroll_loop()
            data_[i] |= a.data_[i];

        return *this;
    }

    /**
     * Returns a mask that contains the negation of the values of all the elements in the mask (0->1, 1->0).
     */
    __aie_inline
    constexpr mask operator~() const
    {
        mask ret;

        for (unsigned i = 0; i < num_words - 1; ++i) chess_unroll_loop()
            ret.data_[i] = ~data_[i];

        ret.data_[num_words - 1] = (~data_[num_words - 1]) & last_word_mask;

        return ret;
    }

    /**
     * Returns the result of a binary left shift of the mask. Returns a reference to the updated mask.
     *
     * @param shift Number of positions to shift the mask.
     */
    constexpr mask &operator<<=(unsigned shift)
    {
        if constexpr (Elems <= bits_per_word) {
            if (shift >= Elems)
                data_[0] = 0;
            else
                data_[0] <<= shift;
        } else {
            const int split_index = (shift >= Elems) ? num_words : shift / bits_per_word;
            const unsigned bits_from_low_word  = shift % bits_per_word;
            const unsigned bits_from_high_word = bits_per_word - bits_from_low_word;
                  unsigned high_word_index     = get_word_index(num_words * bits_per_word - 1 - shift);
            for (int i = num_words - 1; i >= split_index; --i, --high_word_index) {
                const unsigned high_word    = data_[high_word_index];
                const unsigned next_index   = high_word_index + (high_word_index == 0);
                const unsigned low_word_tmp = data_[next_index - 1];
                const unsigned low_word     = high_word_index ? low_word_tmp : 0;
                data_[i] = (bits_from_high_word == bits_per_word)
                                ? high_word
                                : (high_word << bits_from_low_word) |
                                        (low_word >> bits_from_high_word);
            }
            for (int i = split_index - 1; i >= 0; --i) {
                data_[i] = 0;
            }
        }
        // Unset any bits shifted outside the Elems-sized window on the underlying type
        if constexpr (bits_remainder > 0) {
            data_[num_words - 1] &= last_word_mask;
        }
        return *this;
    }

    /**
     * Returns the result of a binary left shift of the mask.
     *
     * @param shift Number of positions to shift the mask.
     */
    __aie_inline
    constexpr mask operator<<(unsigned shift) const
    {
        mask ret{*this};
        ret <<= shift;
        return ret;
    }

    /**
     * Returns the result of a binary right shift of the mask. Returns a reference to the updated mask.
     *
     * @param shift Number of positions to shift the mask.
     */
    constexpr mask &operator>>=(unsigned shift)
    {
        if constexpr (Elems <= bits_per_word) {
            if (shift >= Elems)
                data_[0] = 0;
            else
                data_[0] >>= shift;
        } else {
            const int split_index = (shift >= Elems) ? 0 : (Elems - shift - 1) / bits_per_word + 1;
            const unsigned bits_from_high_word = shift % bits_per_word;
            const unsigned bits_from_low_word  = bits_per_word - bits_from_high_word;
                  unsigned low_word_index      = get_word_index(shift);
            for (int i = 0; i < split_index; ++i, ++low_word_index) {
                const unsigned low_word      = data_[low_word_index];
                const unsigned next_index    = low_word_index - (low_word_index == (num_words - 1));
                const unsigned high_word_tmp = data_[next_index + 1];
                const unsigned high_word     = ((low_word_index + 1) < num_words) ? high_word_tmp : 0;
                data_[i] = (bits_from_low_word == bits_per_word)
                                ? low_word
                                : (low_word >> bits_from_high_word) |
                                        (high_word << bits_from_low_word);
            }
            for (unsigned i = split_index; i < num_words; ++i) {
                data_[i] = 0;
            }
        }
        return *this;
    }

    /**
     * Returns the result of a binary right shift of the mask.
     *
     * @param shift Number of positions to shift the mask.
     */
    __aie_inline
    constexpr mask operator>>(unsigned shift) const
    {
        mask ret{*this};
        ret >>= shift;
        return ret;
    }

    /**
     * Returns the count of elements whose value is 1.
     */
    __aie_inline
    constexpr unsigned count() const
    {
        unsigned count = 0;

        for (unsigned i = 0; i < num_words; ++i) chess_unroll_loop()
            count += count_word(data_[i]);

        return count;
    }

    /**
     * \deprecated Use alternative functions to access the elements of a mask.
     * \sa to_uint32, to_uint64, get_submask
     */
    [[deprecated("Use to_uint32 / to_uint64 / get_submask methods instead")]]
    __aie_inline
    constexpr const std::array<unsigned, num_words> &data() const
    {
        return data_;
    }

    /**
     * Returns the contents of a section of the mask in a 32b unsigned integer
     *
     * @param i Index of the section within the mask (in chunks of 32 elements)
     */
    __aie_inline
    constexpr unsigned to_uint32(unsigned i) const
    {
        return data_[i];
    }

    /**
     * Returns the contents of the mask in a 32b unsigned integer
     */
    template <unsigned Elems2 = Elems>
    __aie_inline
    constexpr unsigned to_uint32() const requires(Elems2 <= 32)
    {
        return data_[0];
    }

    /**
     * Returns the contents of a section of the mask in a 64b unsigned integer
     *
     * @param i Index of the section within th mask (in chunks of 64 elements)
     */
    __aie_inline
    constexpr uint64_t to_uint64(unsigned i) const
    {
        const auto tmp = __builtin_bit_cast(std::array<uint64_t, num_words / 2>, data_);
        return tmp[i];
    }

    /**
     * Returns the contents of the mask in a 64b unsigned integer
     */
    template <unsigned Elems2 = Elems>
    __aie_inline
    constexpr uint64_t to_uint64() const requires(Elems2 == 64)
    {
        const auto tmp = __builtin_bit_cast(std::array<uint64_t, num_words / 2>, data_);
        return tmp[0];
    }

    /**
     * Returns the contents of a section of the mask into a smaller mask
     *
     * @tparam ElemsOut Size of the returned mask
     *
     * @param i Index of the section within th mask (in chunks of ElemsOut elements)
     */
    template <unsigned ElemsOut>
    __aie_inline
    constexpr mask<ElemsOut> get_submask(unsigned i) const
    {
        static_assert(ElemsOut <= Elems);
        REQUIRES(i * ElemsOut < Elems);

        mask<ElemsOut> ret;

        for (unsigned j = 0; j < mask<ElemsOut>::num_words; ++j)
            ret.data_[j] = data_[mask<ElemsOut>::num_words * i + j];

        return ret;
    }

    /**
     * Returns the count of consecutive elements, starting at the high part of the mask, whose value is 0.
     */
    __aie_inline
    constexpr unsigned clz() const
    {
        unsigned ret = ::clb(data_[num_words - 1]);
        bool counting = (ret == bits_per_word);

        for (int i = num_words - 2; i >= 0; --i) chess_unroll_loop() {
            unsigned local = ::clb(data_[i]);
            unsigned inc = counting ? local : 0;
            ret += inc;
            counting &= (local == bits_per_word);
        }

        if constexpr (bits_remainder > 0)
            ret -= bits_remainder;

        return ret;
    }

    /**
     * Returns a bool that says whether the value of all the elements in the mask is 0.
     */
    __aie_inline
    constexpr bool empty() const
    {
        bool ret = true;
        for (unsigned i = 0; i < num_words; ++i) chess_unroll_loop()
            ret = ret && (data_[i] == 0);

        return ret;
    }

    /**
     * Returns a bool that says whether the value of all the elements in the mask is 1.
     */
    __aie_inline
    constexpr bool full() const
    {
        bool ret = true;
        for (unsigned i = 0; i < num_words - 1; ++i) chess_unroll_loop()
            ret = ret && (data_[i] == 0xffffffff);

        ret = ret && ((data_[num_words - 1] & last_word_mask) == last_word_mask);

        return ret;
    }
};

namespace detail {

template <typename T>
struct is_mask
{
    static constexpr bool value = false;
};

template <unsigned Elems>
struct is_mask<::aie::mask<Elems>>
{
    static constexpr bool value = true;
};

} // namespace detail
} // namespace aie

#endif // __AIE_API_MASK__HPP__
