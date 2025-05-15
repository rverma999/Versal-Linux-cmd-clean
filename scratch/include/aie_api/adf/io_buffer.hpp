// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
/*  (c) Copyright 2022 - 2022 Xilinx, Inc. All rights reserved.

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

#ifndef __AIE_API_AIE_ADF_IO_BUFFER_HPP__
#define __AIE_API_AIE_ADF_IO_BUFFER_HPP__

#include <adf.h>
#include "../aie.hpp"
#include "../iterator.hpp"


namespace aie {

template <aie_dm_resource Resource, typename T>
constexpr auto begin(T *, size_t n);

template <aie_dm_resource Resource, typename T>
constexpr auto cbegin(const T *, size_t n);

/**
 * @ingroup group_adf
 *
 * Returns a foward iterator over given io buffer. Requires given io buffer
 * to have linear addressing mode.
 *
 * @tparam Resource
 * @param port The io buffer
 */
template<aie_dm_resource Resource = aie_dm_resource::none,
         typename T,
         typename Dir,
         typename Config>
__aie_inline
constexpr auto begin(adf::io_buffer<T, Dir, Config> &port)
{
    static_assert(std::is_same<typename Config::addressing_mode, adf::addressing::linear>::value);
    return begin<Resource>(port.data(), 0);
}

/**
 * @ingroup group_adf
 *
 * Returns a foward const iterator over given io buffer. Requires given buffer
 * port to have linear addressing mode.
 *
 * @tparam Resource
 * @param port The io buffer
 */
template<aie_dm_resource Resource = aie_dm_resource::none,
         typename T,
         typename Dir,
         typename Config>
__aie_inline
constexpr auto begin(const adf::io_buffer<T, Dir, Config> &port)
{
    static_assert(std::is_same<typename Config::addressing_mode, adf::addressing::linear>::value);
    return cbegin<Resource>(port.data(), 0);
}

/**
 * @ingroup group_adf
 *
 * Returns a foward const iterator over given io buffer. Requires given buffer
 * port to have linear addressing mode.
 *
 * @tparam Resource
 * @param port The io buffer
 */
template<aie_dm_resource Resource = aie_dm_resource::none,
         typename T,
         typename Dir,
         typename Config>
__aie_inline
constexpr auto cbegin(const adf::io_buffer<T, Dir, Config> &port)
{
    return begin<Resource>(port);
}


/**
 * @ingroup group_adf
 *
 * Returns a foward circular iterator over given io buffer.
 *
 * @tparam Resource
 * @param port The io buffer
 */
template<aie_dm_resource Resource = aie_dm_resource::none,
         typename T,
         typename Dir,
         typename Config>
__aie_inline
constexpr auto begin_circular(adf::io_buffer<T, Dir, Config> &port)
{
    if constexpr (Config::dims_type::inherited() || Config::_margin == adf::inherited_margin) {
        return circular_iterator<T, aie::dynamic_extent, Resource>
            (port.data(), port.base(), port.size_incl_margin());
    }
    else {
        constexpr unsigned sizeInclMargin = Config::dims_type::size() + Config::_margin;
        return circular_iterator<T, sizeInclMargin, Resource>
            (port.data(), port.base());
    }
}

/**
 * @ingroup group_adf
 *
 * Returns a const foward circular iterator over given io buffer.
 *
 * @tparam Resource
 * @param port The io buffer
 */
template<aie_dm_resource Resource = aie_dm_resource::none,
         typename T,
         typename Dir,
         typename Config>
__aie_inline
constexpr auto begin_circular(const adf::io_buffer<T, Dir, Config> &port)
{
    if constexpr (Config::dims_type::inherited() || Config::_margin == adf::inherited_margin) {
        return const_circular_iterator<T, aie::dynamic_extent, Resource>
            (port.data(), port.base(), port.size_incl_margin());
    }
    else {
        constexpr unsigned sizeInclMargin = Config::dims_type::size() + Config::_margin;
        return const_circular_iterator<T, sizeInclMargin, Resource>
            (port.data(), port.base());
    }
}

/**
 * @ingroup group_adf
 *
 * Returns a const foward iterator over given io buffer.
 *
 * @tparam Resource
 * @param port The io buffer
 */
template<aie_dm_resource Resource = aie_dm_resource::none,
         typename T,
         typename Dir,
         typename Config>
__aie_inline
constexpr auto cbegin_circular(const adf::io_buffer<T, Dir, Config> &port)
{
    return begin_circular<Resource>(port);
}

/**
 * @ingroup group_adf
 *
 * Returns a random iterator over given io buffer. If the port has circular
 * addressing the iterator is a circular random iterator.
 *
 * @tparam Resource
 * @param port The io buffer
 */
template<aie_dm_resource Resource = aie_dm_resource::none,
         typename T,
         typename Dir,
         typename Config>
__aie_inline
constexpr auto begin_random_circular(adf::io_buffer<T, Dir, Config> &port)
{
    if constexpr (Config::dims_type::inherited() || Config::_margin == adf::inherited_margin) {
        return detail::random_circular_iterator<T, aie::dynamic_extent, 1, Resource>
            (port.data(), port.base(), port.size_incl_margin());
    }
    else {
        constexpr unsigned sizeInclMargin = Config::dims_type::size() + Config::_margin;
        return detail::random_circular_iterator<T, sizeInclMargin, 1, Resource>
            (port.data(), port.base());
    }
}

/**
 * @ingroup group_adf
 *
 * Returns a random const iterator over given io buffer. If the port has circular
 * addressing the iterator is a circular random const iterator.
 *
 * @tparam Resource
 * @param port The io buffer
 */
template<aie_dm_resource Resource = aie_dm_resource::none,
         typename T,
         typename Dir,
         typename Config>
__aie_inline
constexpr auto begin_random_circular(const adf::io_buffer<T, Dir, Config> &port)
{
    if constexpr (Config::dims_type::inherited() || Config::_margin == adf::inherited_margin) {
        return const_random_circular_iterator<T, aie::dynamic_extent, Resource>
            (port.data(), port.base(), port.size_incl_margin());
    }
    else {
        constexpr unsigned sizeInclMargin = Config::dims_type::size() + Config::_margin;
        return const_random_circular_iterator<T, sizeInclMargin, Resource>
            (port.data(), port.base());
    }
}

/**
 * @ingroup group_adf
 *
 * Returns a random const iterator over given io buffer. If the port has circular
 * addressing the iterator is a circular random const iterator.
 *
 * @tparam Resource
 * @param port The io buffer
 */
template<aie_dm_resource Resource = aie_dm_resource::none,
         typename T,
         typename Dir,
         typename Config>
__aie_inline
constexpr auto cbegin_random_circular(const adf::io_buffer<T, Dir, Config> &port)
{
    return begin_random_circular<Resource>(port);
}

/**
 * @ingroup group_adf
 *
 * Returns a vector iterator over given io buffer. Requires given io buffer
 * to have linear addressing mode.
 *
 * @tparam Elems The size of the vector
 * @tparam Resource Bank annotation
 * @param port The io buffer
 */
template<unsigned Elems,
         aie_dm_resource Resource = aie_dm_resource::none,
         typename T,
         typename Dir,
         typename Config>
__aie_inline
constexpr auto begin_vector(adf::io_buffer<T, Dir, Config> &port)
{
    static_assert(std::is_same<typename Config::addressing_mode, adf::addressing::linear>::value);
    return vector_iterator<T, Elems, Resource>(port.data());
}

/**
 * @ingroup group_adf
 *
 * Returns a const vector iterator over given io buffer. Requires given buffer
 * port to have linear addressing mode.
 *
 * @tparam Elems The size of the vector
 * @tparam Resource Bank annotation
 * @param port The io buffer
 */
template<unsigned Elems,
         aie_dm_resource Resource = aie_dm_resource::none,
         typename T,
         typename Dir,
         typename Config>
__aie_inline
constexpr auto begin_vector(const adf::io_buffer<T, Dir, Config> &port)
{
    static_assert(std::is_same<typename Config::addressing_mode, adf::addressing::linear>::value);
    return const_vector_iterator<T, Elems, Resource>(port.data());
}

/**
 * @ingroup group_adf
 *
 * Returns a const vector iterator over given io buffer. Requires given buffer
 * port to have linear addressing mode.
 *
 * @tparam Elems The size of the vector
 * @tparam Resource Bank annotation
 * @param port The io buffer
 */
template<unsigned Elems,
         aie_dm_resource Resource = aie_dm_resource::none,
         typename T,
         typename Dir,
         typename Config>
__aie_inline
constexpr auto cbegin_vector(const adf::io_buffer<T, Dir, Config> &port)
{
    return begin_vector<Elems, Resource>(port);
}

/**
 * @ingroup group_adf
 *
 * Returns a restrict vector iterator over given io buffer.
 * Requires given io buffer to have linear addressing mode.
 *
 * @tparam Elems The size of the vector
 * @tparam Resource Bank annotation
 * @param port The io buffer
 */
template<unsigned Elems,
         aie_dm_resource Resource = aie_dm_resource::none,
         typename T,
         typename Dir,
         typename Config>
__aie_inline
constexpr auto begin_restrict_vector(adf::io_buffer<T, Dir, Config> &port)
{
    static_assert(std::is_same<typename Config::addressing_mode, adf::addressing::linear>::value);
    return restrict_vector_iterator<T, Elems, Resource>(port.data());
}

/**
 * @ingroup group_adf
 *
 * Returns a const restrict vector iterator over given io buffer.
 * Requires given buffer port to have linear addressing mode.
 *
 * @tparam Elems The size of the vector
 * @tparam Resource Bank annotation
 * @param port The io buffer
 */
template<unsigned Elems,
         aie_dm_resource Resource = aie_dm_resource::none,
         typename T,
         typename Dir,
         typename Config>
__aie_inline
constexpr auto begin_restrict_vector(const adf::io_buffer<T, Dir, Config> &port)
{
    static_assert(std::is_same<typename Config::addressing_mode, adf::addressing::linear>::value);
    return const_restrict_vector_iterator<T, Elems, Resource>(port.data());
}

/**
 * @ingroup group_adf
 *
 * Returns a const restrict vector iterator over given io buffer.
 * Requires given buffer port to have linear addressing mode.
 *
 * @tparam Elems The size of the vector
 * @tparam Resource Bank annotation
 * @param port The io buffer
 */
template<unsigned Elems,
         aie_dm_resource Resource = aie_dm_resource::none,
         typename T,
         typename Dir,
         typename Config>
__aie_inline
constexpr auto cbegin_restrict_vector(const adf::io_buffer<T, Dir, Config> &port)
{
    return begin_restrict_vector<Elems, Resource>(port);
}

/**
 * @ingroup group_adf
 *
 * Returns a vector circular iterator over given io buffer.
 *
 * @tparam Elems The size of the vector
 * @tparam Resource Bank annotation
 * @param port The io buffer
 */
template<unsigned Elems,
         aie_dm_resource Resource = aie_dm_resource::none,
         typename T,
         typename Dir,
         typename Config>
__aie_inline
constexpr auto begin_vector_circular(adf::io_buffer<T, Dir, Config> &port)
{
    if constexpr (Config::dims_type::inherited() || Config::_margin == adf::inherited_margin) {
        return aie::vector_circular_iterator
            <T, Elems, aie::dynamic_extent, Resource>(port.data(), port.base(), port.size_incl_margin());
    }
    else {
        constexpr unsigned sizeInclMargin = Config::dims_type::size() + Config::_margin;
        return aie::vector_circular_iterator
            <T, Elems, sizeInclMargin, Resource>(port.data(), port.base());
    }
}

/**
 * @ingroup group_adf
 *
 * Returns a const vector circular iterator over given io buffer.
 *
 * @tparam Elems The size of the vector
 * @tparam Resource Bank annotation
 * @param port The io buffer
 */
template<unsigned Elems,
         aie_dm_resource Resource = aie_dm_resource::none,
         typename T,
         typename Dir,
         typename Config>
__aie_inline
constexpr auto begin_vector_circular(const adf::io_buffer<T, Dir, Config> &port)
{
    if constexpr (Config::dims_type::inherited() || Config::_margin == adf::inherited_margin) {
        return aie::const_vector_circular_iterator
            <T, Elems, aie::dynamic_extent, Resource>(port.data(), port.base(), port.size_incl_margin());
    }
    else {
        constexpr unsigned sizeInclMargin = Config::dims_type::size() + Config::_margin;
        return aie::const_vector_circular_iterator
            <T, Elems, sizeInclMargin, Resource>(port.data(), port.base());
    }
}

/**
 * @ingroup group_adf
 *
 * Returns a const vector circular iterator over given io buffer.
 *
 * @tparam Elems The size of the vector
 * @tparam Resource Bank annotation
 * @param port The io buffer
 */
template<unsigned Elems,
         aie_dm_resource Resource = aie_dm_resource::none,
         typename T,
         typename Dir,
         typename Config>
__aie_inline
constexpr auto cbegin_vector_circular(const adf::io_buffer<T, Dir, Config> &port)
{
    return begin_vector_circular<Elems, Resource>(port);
}

/**
 * @ingroup group_adf
 *
 * Returns a vector random circular iterator over given io buffer.
 *
 * @tparam Elems The size of the vector
 * @tparam Resource Bank annotation
 * @param port The io buffer
 */
template<unsigned Elems,
         aie_dm_resource Resource = aie_dm_resource::none,
         typename T,
         typename Dir,
         typename Config>
__aie_inline
constexpr auto begin_vector_random_circular(adf::io_buffer<T, Dir, Config> &port)
{
    if constexpr (Config::dims_type::inherited() || Config::_margin == adf::inherited_margin) {
        return aie::detail::vector_random_circular_iterator
            <T, Elems, aie::dynamic_extent, 1, Resource>(port.data(), port.base(), port.size_incl_margin());
    }
    else {
        constexpr unsigned sizeInclMargin = Config::dims_type::size() + Config::_margin;
        return aie::detail::vector_random_circular_iterator
            <T, Elems, sizeInclMargin, 1, Resource>(port.data(), port.base());
    }
}

/**
 * @ingroup group_adf
 *
 * Returns a const vector random circular iterator over given io buffer.
 *
 * @tparam Elems The size of the vector
 * @tparam Resource Bank annotation
 * @param port The io buffer
 */
template<unsigned Elems,
         aie_dm_resource Resource = aie_dm_resource::none,
         typename T,
         typename Dir,
         typename Config>
__aie_inline
constexpr auto begin_vector_random_circular(const adf::io_buffer<T, Dir, Config> &port)
{
    if constexpr (Config::dims_type::inherited() || Config::_margin == adf::inherited_margin) {
        return aie::const_vector_random_circular_iterator
            <T, Elems, aie::dynamic_extent, Resource>(port.data(), port.base(), port.size_incl_margin());
    }
    else {
        constexpr unsigned sizeInclMargin = Config::dims_type::size() + Config::_margin;
        return aie::const_vector_random_circular_iterator
            <T, Elems, sizeInclMargin, Resource>(port.data(), port.base());
    }
}

/**
 * @ingroup group_adf
 *
 * Returns a const vector random circular iterator over given io buffer.
 *
 * @tparam Elems The size of the vector
 * @tparam Resource Bank annotation
 * @param port The io buffer
 */
template<unsigned Elems,
         aie_dm_resource Resource = aie_dm_resource::none,
         typename T,
         typename Dir,
         typename Config>
__aie_inline
constexpr auto cbegin_vector_random_circular(const adf::io_buffer<T, Dir, Config> &port)
{
    return begin_vector_random_circular<Elems, Resource>(port);
}

} // namespace aie

#endif
