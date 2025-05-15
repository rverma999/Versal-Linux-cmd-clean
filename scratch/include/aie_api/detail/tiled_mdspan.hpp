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

#ifndef __AIE_API_DETAIL_TILED_MDSPAN__HPP__
#define __AIE_API_DETAIL_TILED_MDSPAN__HPP__

#include "mdspan.hpp"
#include "utils.hpp"

#include "../iterator.hpp"

#include <array>

#include <cstdio>

namespace aie::detail {

template <typename SpanExtents>
struct tiled_span_indexer
{
    using index_type = ptrdiff_t;

    template <unsigned DimIndex, typename... Indices>
    static constexpr index_type offset_helper(const SpanExtents &extents, index_type idx, Indices &&... indices)
    {
        if constexpr (sizeof...(Indices) == 0) {
            static_assert(DimIndex == 0);

            return extents.tile_offsets_[DimIndex] * idx;
        }
        else {
            return extents.tile_offsets_[DimIndex] * idx + tiled_span_indexer::offset_helper<DimIndex - 1>(extents, std::forward<Indices>(indices)...);
        }
    }

    template <typename... Indices>
    static constexpr index_type offset(const SpanExtents &extents, Indices &&... indices)
    {
        return offset_helper<SpanExtents::tile_rank() - 1>(extents, std::forward<Indices>(indices)...);
    }
};

template <typename TiledSpan>
class tile_iterator
{
public:
    using        value_type = typename TiledSpan::value_type;
    using         reference = typename TiledSpan::reference;
    using           pointer = typename TiledSpan::pointer;
    using iterator_category = std::random_access_iterator_tag;
    using   difference_type = ptrdiff_t;

    constexpr tile_iterator(pointer ptr, difference_type stride) :
        ptr_(ptr),
        stride_(stride)
    {}

    constexpr tile_iterator operator++()
    {
        *this += 1;
        return *this;
    }

    constexpr tile_iterator operator++(int)
    {
        tile_iterator it = *this;
        ++(*this);
        return it;
    }

    constexpr tile_iterator operator--()
    {
        *this -= 1;
        return *this;
    }

    constexpr tile_iterator operator--(int)
    {
        tile_iterator it = *this;
        --(*this);
        return it;
    }

    constexpr tile_iterator operator+(int a) const
    {
        tile_iterator it = *this;
        it += a;
        return it;
    }

    constexpr tile_iterator operator-(int a) const
    {
        tile_iterator it = *this;
        it -= a;
        return it;
    }

    constexpr tile_iterator operator+=(int a)
    {
        ptr_ += a * stride_;
        return *this;
    }

    constexpr tile_iterator operator-=(int a)
    {
        ptr_ -= a * stride_;
        return *this;
    }

    constexpr reference operator[](int a)
    {
        return *(*this + a);
    }

    constexpr reference operator*()                          { return *ptr_;            }
    constexpr pointer   operator->()                         { return ptr_;             }
    constexpr bool      operator==(const tile_iterator& rhs) { return ptr_ == rhs.ptr_; }
    constexpr bool      operator!=(const tile_iterator& rhs) { return ptr_ != rhs.ptr_; }

private:
    pointer ptr_;
    difference_type stride_;
};

template <typename TiledSpan>
class const_tile_iterator
{
public:
    using        value_type = typename TiledSpan::value_type;
    using         reference = typename TiledSpan::reference;
    using           pointer = typename TiledSpan::pointer;
    using iterator_category = std::random_access_iterator_tag;
    using   difference_type = ptrdiff_t;

    constexpr const_tile_iterator(pointer ptr, difference_type stride) :
        ptr_(ptr),
        stride_(stride)
    {}

    constexpr const_tile_iterator operator++()
    {
        *this += 1;
        return *this;
    }

    constexpr const_tile_iterator operator++(int)
    {
        const_tile_iterator i = *this;
        ++(*this);
        return i;
    }

    constexpr const_tile_iterator operator--()
    {
        *this -= 1;
        return *this;
    }

    constexpr const_tile_iterator operator--(int)
    {
        const_tile_iterator it = *this;
        --(*this);
        return it;
    }

    constexpr const_tile_iterator operator+(int a) const
    {
        const_tile_iterator it = *this;
        it += a;
        return it;
    }

    constexpr const_tile_iterator operator-(int a) const
    {
        const_tile_iterator it = *this;
        it -= a;
        return it;
    }

    constexpr const_tile_iterator operator+=(int a)
    {
        ptr_ += a * stride_;
        return *this;
    }

    constexpr const_tile_iterator operator-=(int a)
    {
        ptr_ -= a * stride_;
        return *this;
    }

    constexpr reference operator[](int a) const
    {
        return *(*this + a);
    }

    constexpr reference operator*()                                { return *ptr_;            }
    constexpr pointer   operator->()                               { return ptr_;             }
    constexpr bool      operator==(const const_tile_iterator& rhs) { return ptr_ == rhs.ptr_; }
    constexpr bool      operator!=(const const_tile_iterator& rhs) { return ptr_ != rhs.ptr_; }

private:
    pointer ptr_;
    difference_type stride_;
};


template <typename TileExtents, typename Extents>
struct tiled_span_extents_common;

template <size_t... TileExtents, size_t... Extents>
struct tiled_span_extents_common<extents<TileExtents...>, extents<Extents...>>
{
    using index_type = ptrdiff_t;

    static constexpr size_t tile_rank()
    {
        return sizeof...(TileExtents);
    }

    static constexpr size_t rank()
    {
        return sizeof...(Extents);
    }

    static constexpr size_t rank_dynamic()
    {
        return (... + int(Extents == dynamic_extent));
    }

    static constexpr size_t rank_static()
    {
        return (... + int(Extents != dynamic_extent));
    }

    static constexpr bool is_static()
    {
        return rank_dynamic() == 0;
    }

    static constexpr size_t tile_elems_static()
    {
        return (... * TileExtents);
    }

    static constexpr size_t elems_static()
    {
        return (... * Extents);
    }

    static constexpr size_t tile_extent(size_t index)
    {
        constexpr std::array<index_type, tile_rank()> ext = {TileExtents...};
        return ext[index];
    }
};

template <bool IsStatic, typename TileExtents, typename Extents>
struct tiled_span_extents;

template <size_t... TileExtents, typename Extents>
struct tiled_span_extents<false, extents<TileExtents...>, Extents> : public tiled_span_extents_common<extents<TileExtents...>, Extents>
{
    using parent = tiled_span_extents_common<extents<TileExtents...>, Extents>;

    using index_type = typename parent::index_type;

    template <typename... DynamicExtents>
    constexpr tiled_span_extents(DynamicExtents... ext) :
        ext_{ext / TileExtents...}
    {
        index_type offset = parent::tile_elems_static();
        tile_offsets_[0] = offset;

        for (unsigned i = 1; i < parent::tile_rank(); ++i) {
            offset *= ext_[parent::tile_rank() - i];
            tile_offsets_[i] = offset;
        }
    }

    constexpr size_t extent(size_t index) const
    {
        return ext_[index];
    }

    dyn_extents<parent::rank()> ext_;
    std::array<index_type, parent::rank()> tile_offsets_;
};

template <size_t... TileExtents, size_t... Extents>
struct tiled_span_extents<true, extents<TileExtents...>, extents<Extents...>> : public tiled_span_extents_common<extents<TileExtents...>, extents<Extents...>>
{
    using parent = tiled_span_extents_common<extents<TileExtents...>, extents<Extents...>>;

    using index_type = typename parent::index_type;

    static constexpr std::array<index_type, parent::rank()> compute_offsets()
    {
        constexpr std::array<index_type, parent::tile_rank()> ext = {(Extents / TileExtents)...};
        std::array<index_type, parent::tile_rank()> ret{};

        index_type offset = parent::tile_elems_static();
        ret[0] = offset;

        for (unsigned i = 1; i < parent::tile_rank(); ++i) {
            offset *= ext[parent::tile_rank() - i];
            ret[i] = offset;
        }

        return ret;
    }

    constexpr size_t extent(size_t index) const
    {
        constexpr std::array<index_type, parent::tile_rank()> ext = {(Extents / TileExtents)...};
        return ext[index];
    }

    static constexpr std::array<index_type, parent::tile_rank()> tile_offsets_ = compute_offsets();
};

template <typename T, typename TileExtents, typename Extents, typename LayoutPolicy, typename AccessorPolicy>
class basic_tiled_mdspan;

template <typename T, size_t... TileExtents, size_t... Extents, typename LayoutPolicy, typename AccessorPolicy>
class basic_tiled_mdspan<T, extents<TileExtents...>, extents<Extents...>, LayoutPolicy, AccessorPolicy> :
    public tiled_span_extents<(... && (Extents != dynamic_extent)), extents<TileExtents...>, extents<Extents...>>
{
    basic_tiled_mdspan() = delete;

public:
    using        extents_type = tiled_span_extents<(... && (Extents != dynamic_extent)), extents<TileExtents...>, extents<Extents...>>;
    using         layout_type = LayoutPolicy;
    using       accessor_type = AccessorPolicy;
    using          index_type = typename extents_type::index_type;
    using        indexer_type = tiled_span_indexer<extents_type>;

    using          value_type = T;

    using             pointer = typename accessor_type::pointer;
    using           reference = typename accessor_type::reference;

    using       tile_iterator = tile_iterator<basic_tiled_mdspan>;
    using const_tile_iterator = const_tile_iterator<basic_tiled_mdspan>;

    template <typename... DynamicExtents>
    constexpr basic_tiled_mdspan(T *data, DynamicExtents... ext) :
        extents_type(size_t(ext)...),
        data_(data)
    {
        static_assert(sizeof...(DynamicExtents) == extents_type::rank_dynamic(), "Constructor needs to specify all dynamic extents");
    }

    template <typename... Indices>
    constexpr reference tiles(Indices &&... indices)
    {
        static_assert(sizeof...(indices) == basic_tiled_mdspan::rank(),
                      "The number of given indices must match the array's rank");

        const auto off = indexer_type::offset(*this, std::forward<Indices>(indices)...);
        return acc_.access(data_, off);
    }

    template <typename... Indices>
    constexpr reference tiles(Indices &&... indices) const
    {
        static_assert(sizeof...(indices) == basic_tiled_mdspan::rank(),
                      "The number of given indices must match the array's rank");

        const auto off = indexer_type::offset(*this, std::forward<Indices>(indices)...);
        return acc_.access(data_, off);
    }

    template <size_t DimIndex, typename... Indices>
    constexpr tile_iterator begin_dim(Indices &&... indices)
    {
        // Fix tile_offsets_ indirection for rank > 2
        tile_iterator ret(&tiles(indices...), DimIndex == 0? extents_type::tile_elems_static() : this->tile_offsets_[DimIndex]);

        return ret;
    }

    template <size_t DimIndex, typename... Indices>
    constexpr const_tile_iterator begin_dim(Indices &&... indices) const
    {
        // Fix tile_offsets_ indirection for rank > 2
        const_tile_iterator ret(&tiles(indices...), DimIndex == 0? extents_type::tile_elems_static() : this->tile_offsets_[DimIndex]);

        return ret;
    }

    template <size_t DimIndex, typename... Indices>
    constexpr auto begin_vector_dim(Indices &&... indices)
    {
        if constexpr (DimIndex == basic_tiled_mdspan::rank() - 1)
            return vector_iterator<T, extents_type::tile_elems_static(), dynamic_extent>(&tiles(indices...), 1);
        else
            return vector_iterator<T, extents_type::tile_elems_static(), dynamic_extent>(&tiles(indices...), this->tile_offsets_[extents_type::rank() - DimIndex - 1] / extents_type::tile_elems_static());
    }

    template <size_t DimIndex, typename... Indices>
    constexpr auto begin_vector_dim(Indices &&... indices) const
    {
        return cbegin_vector_dim<DimIndex>(std::forward<Indices>(indices)...);
    }

    template <size_t DimIndex, typename... Indices>
    constexpr auto cbegin_vector_dim(Indices &&... indices) const
    {
        if constexpr (DimIndex == basic_tiled_mdspan::rank() - 1)
            return vector_iterator<std::add_const_t<T>, extents_type::tile_elems_static(), dynamic_extent>(&tiles(indices...), 1);
        else
            return vector_iterator<std::add_const_t<T>, extents_type::tile_elems_static(), dynamic_extent>(&tiles(indices...), this->tile_offsets_[extents_type::rank() - DimIndex - 1] / extents_type::tile_elems_static());
    }

private:
    pointer data_;
    [[no_unique_address]] accessor_type acc_;

    static_assert((... && (Extents != 0)),                                             "Static span dimensions must be larger than zero");
    static_assert(!extents_type::is_static() || (... && (Extents % TileExtents == 0)), "Span dimensions must be a multiple of the tile size");
    static_assert((... && (TileExtents != dynamic_extent)),                            "Tile extents must all be static");
    static_assert(extents_type::tile_rank() <= extents_type::rank());
};

} // namespace aie::detail

#endif
