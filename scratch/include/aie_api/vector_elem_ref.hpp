// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
/*  (c) Copyright 2020 - 2023 Xilinx, Inc. All rights reserved.

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

#ifndef __AIE_API_VECTOR_ELEM_REF__HPP__
#define __AIE_API_VECTOR_ELEM_REF__HPP__

#include "detail/utils.hpp"
#include "concepts.hpp"

#include <tuple>

namespace aie {

template <ElemBaseType T, unsigned N>
class vector;

template <ElemBaseType T, unsigned N>
class vector_elem_ref;

template <ElemBaseType T, unsigned N>
class vector_elem_const_ref
{
public:
    using vector_type = vector<T, N>;
    using parent_type = vector_type;
    using  value_type = T;

    constexpr vector_elem_const_ref(const vector_elem_ref<T, N> &ref) :
        parent(ref.parent),
        offset(ref.offset)
    {
    }

    value_type get() const
    {
        return parent.get(offset);
    }

    operator value_type() const
    {
        return get();
    }

    template <typename T2>
    constexpr bool operator==(T2 v) const
    {
        return (value_type)*this == (value_type)v;
    }

    template <typename T2>
    constexpr bool operator!=(T2 v) const
    {
        return (value_type)*this != (value_type)v;
    }

    template <typename T2>
    constexpr bool operator<=(T v) const
    {
        return (value_type)*this <= (value_type)v;
    }

    template <typename T2>
    constexpr bool operator>=(T2 v) const
    {
        return (value_type)*this >= (value_type)v;
    }

    template <typename T2>
    constexpr bool operator<(T2 v) const
    {
        return (value_type)*this < (value_type)v;
    }

    template <typename T2>
    constexpr bool operator>(T2 v) const
    {
        return (value_type)*this > (value_type)v;
    }

    const vector_type &parent;
    unsigned offset;

private:
    constexpr vector_elem_const_ref(const vector_type &v, unsigned idx) :
        parent(v),
        offset(idx)
    {
    }

    friend vector_type;
    friend vector_elem_ref<T, N>;
};

template <ElemBaseType T, unsigned N>
class vector_elem_ref
{
public:
    using vector_type = vector<T, N>;
    using parent_type = vector_type;
    using  value_type = T;

    value_type get() const
    {
        return parent.get(offset);
    }

    operator value_type() const
    {
        return get();
    }

    vector_elem_ref &operator=(const value_type &v)
    {
        parent.set(v, offset);
        return *this;
    }

    vector_elem_ref &operator=(const vector_elem_ref<T, N> &v)
    {
        parent.set(v.get(), offset);
        return *this;
    }

    vector_elem_ref &operator=(const vector_elem_const_ref<T, N> &v)
    {
        parent.set(v.get(), offset);
        return *this;
    }

    template <typename T2>
    constexpr bool operator==(T2 v) const
    {
        return (value_type)*this == (value_type)v;
    }

    template <typename T2>
    constexpr bool operator!=(T2 v) const
    {
        return (value_type)*this != (value_type)v;
    }

    template <typename T2>
    constexpr bool operator<=(T v) const
    {
        return (value_type)*this <= (value_type)v;
    }

    template <typename T2>
    constexpr bool operator>=(T2 v) const
    {
        return (value_type)*this >= (value_type)v;
    }

    template <typename T2>
    constexpr bool operator<(T2 v) const
    {
        return (value_type)*this < (value_type)v;
    }

    template <typename T2>
    constexpr bool operator>(T2 v) const
    {
        return (value_type)*this > (value_type)v;
    }

    vector_type &parent;
    unsigned offset;

private:
    constexpr vector_elem_ref(vector_type &v, unsigned idx) :
        parent(v),
        offset(idx)
    {
    }

    friend vector_type;
};

template <typename T, unsigned Elems, aie_dm_resource Resource>
class vector_ref
{
public:
    using         elem_type = aie_dm_resource_remove_t<T>;
    using       vector_type = vector<std::remove_const_t<elem_type>, Elems>;

    using        value_type = typename vector_type::value_type;

    static constexpr unsigned size()
    {
        return vector_type::size();
    }

    __aie_inline
    constexpr vector_ref(T *ptr) :
        ptr_(ptr)
    {}

    __aie_inline
    constexpr operator vector_type() const
    {
        vector_type ret;

        ret.template load<Elems, Resource>(ptr_);

        return ret;
    }

    __aie_inline
    constexpr vector_ref &operator=(const vector_type &v) requires(std::is_const_v<T>)
    {
        vector_type dst(v);

        dst.template store<Elems, Resource>(ptr_);

        return *this;
    }

private:
    T *ptr_;
};

template <typename T, unsigned Elems, aie_dm_resource Resource>
class unaligned_vector_ref
{
public:
    using         elem_type = aie_dm_resource_remove_t<T>;
    using       vector_type = vector<std::remove_const_t<elem_type>, Elems>;

    using        value_type = typename vector_type::value_type;

    static constexpr unsigned size()
    {
        return vector_type::size();
    }

    __aie_inline
    constexpr unaligned_vector_ref(T *ptr, unsigned alignment = 1) :
        ptr_(ptr),
        alignment_(alignment)
    {}

    __aie_inline
    constexpr operator vector_type() const
    {
        vector_type ret;

        ret.template load_unaligned<Resource>(ptr_, alignment_);

        return ret;
    }

    __aie_inline
    constexpr unaligned_vector_ref &operator=(const vector_type &v) requires(!std::is_const_v<T>)
    {
        vector_type dst(v);

        dst.template store_unaligned<Resource>(ptr_, alignment_);

        return *this;
    }

private:
    T *ptr_;
    unsigned alignment_;
};

namespace detail {

template <typename DstT, typename SrcT, unsigned SrcElems>
auto vector_cast(const vector<SrcT, SrcElems> &v)
{
    return v.template cast_to<DstT>();
}

template <typename T, unsigned Elems>
struct concat_vector_helper
{
    template <typename... Vectors>
    static auto run(Vectors && ...vectors)
    {
        static_assert(sizeof...(vectors) > 1);
        static_assert((std::is_same_v<vector<T, Elems>, utils::remove_all_t<Vectors>> && ...));

        using out_vector_type = vector<T, Elems * sizeof...(vectors)>;

        static_assert(out_vector_type::bits() <= 1024);

        out_vector_type ret;

        ret.upd_all(std::forward<Vectors>(vectors)...);

        return ret;
    }
};

template <typename... Vectors>
auto concat_vector(Vectors && ...vectors)
{
    using first_type = std::tuple_element_t<0, std::tuple<utils::remove_all_t<Vectors>...>>;

    return concat_vector_helper<typename first_type::value_type, first_type::size()>::run(std::forward<Vectors>(vectors)...);
}

template <typename T>
struct is_vector_elem_ref
{
    static constexpr bool value = false;
};

template <ElemBaseType T, unsigned Elems>
struct is_vector_elem_ref<vector_elem_const_ref<T, Elems>>
{
    static constexpr bool value = true;
};

template <ElemBaseType T, unsigned Elems>
struct is_vector_elem_ref<vector_elem_ref<T, Elems>>
{
    static constexpr bool value = true;
};

template <typename T>
struct is_vector
{
    static constexpr bool value = false;
};

template <typename T, unsigned Elems>
struct is_vector<vector<T, Elems>>
{
    static constexpr bool value = true;
};

template <typename T>
struct is_vector_ref
{
    static constexpr bool value = false;
};

template <typename T, unsigned Elems, aie_dm_resource Resource>
struct is_vector_ref<vector_ref<T, Elems, Resource>>
{
    static constexpr bool value = true;
};


template <typename T, unsigned Elems, aie_dm_resource Resource>
struct is_vector_ref<unaligned_vector_ref<T, Elems, Resource>>
{
    static constexpr bool value = true;
};

} // namespace detail

template <typename T1, typename T2> requires(detail::is_vector_elem_ref_v<T1> || detail::is_vector_elem_ref_v<T2>)
constexpr auto operator+(T1 v1, T2 v2)
{
    if      constexpr (detail::is_vector_elem_ref_v<T1> && detail::is_vector_elem_ref_v<T2>)
        return v1.get() + v2.get();
    else if constexpr (detail::is_vector_elem_ref_v<T1>)
        return v1.get() + v2;
    else if constexpr (detail::is_vector_elem_ref_v<T2>)
        return v1       + v2.get();
}

template <typename T1, typename T2> requires(detail::is_vector_elem_ref_v<T1> || detail::is_vector_elem_ref_v<T2>)
constexpr auto operator-(T1 v1, T2 v2)
{
    if      constexpr (detail::is_vector_elem_ref_v<T1> && detail::is_vector_elem_ref_v<T2>)
        return v1.get() - v2.get();
    else if constexpr (detail::is_vector_elem_ref_v<T1>)
        return v1.get() - v2;
    else if constexpr (detail::is_vector_elem_ref_v<T2>)
        return v1       - v2.get();
}

template <typename T1, typename T2> requires(detail::is_vector_elem_ref_v<T1> || detail::is_vector_elem_ref_v<T2>)
constexpr auto operator&(T1 v1, T2 v2)
{
    if      constexpr (detail::is_vector_elem_ref_v<T1> && detail::is_vector_elem_ref_v<T2>)
        return v1.get() & v2.get();
    else if constexpr (detail::is_vector_elem_ref_v<T1>)
        return v1.get() & v2;
    else if constexpr (detail::is_vector_elem_ref_v<T2>)
        return v1       & v2.get();
}

template <typename T1, typename T2> requires(detail::is_vector_elem_ref_v<T1> || detail::is_vector_elem_ref_v<T2>)
constexpr auto operator|(T1 v1, T2 v2)
{
    if      constexpr (detail::is_vector_elem_ref_v<T1> && detail::is_vector_elem_ref_v<T2>)
        return v1.get() | v2.get();
    else if constexpr (detail::is_vector_elem_ref_v<T1>)
        return v1.get() | v2;
    else if constexpr (detail::is_vector_elem_ref_v<T2>)
        return v1       | v2.get();
}

template <typename T1, typename T2> requires(detail::is_vector_elem_ref_v<T1> || detail::is_vector_elem_ref_v<T2>)
constexpr auto operator^(T1 v1, T2 v2)
{
    if      constexpr (detail::is_vector_elem_ref_v<T1> && detail::is_vector_elem_ref_v<T2>)
        return v1.get() ^ v2.get();
    else if constexpr (detail::is_vector_elem_ref_v<T1>)
        return v1.get() ^ v2;
    else if constexpr (detail::is_vector_elem_ref_v<T2>)
        return v1       ^ v2.get();
}

template <typename T> requires(detail::is_vector_elem_ref_v<T>)
constexpr auto operator<<(T v, int n) -> typename T::value_type
{
    return v.get() << n;
}

template <typename T> requires(detail::is_vector_elem_ref_v<T>)
constexpr auto operator<<(T v, unsigned n) -> typename T::value_type
{
    return v.get() << n;
}

template <typename T> requires(detail::is_vector_elem_ref_v<T>)
constexpr auto operator>>(T v, int n) -> typename T::value_type
{
    return v.get() >> n;
}

template <typename T> requires(detail::is_vector_elem_ref_v<T>)
constexpr auto operator>>(T v, unsigned n) -> typename T::value_type
{
    return v.get() >> n;
}

template <typename T> requires(detail::is_vector_elem_ref_v<T>)
constexpr auto operator~(T v)
{
    return ~v.get();
}

} // namespace aie

#endif // __AIE_API_VECTOR_ELEM_REF__HPP__
