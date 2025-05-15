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

#ifndef __AIE_API_DETAIL_AIE2_SYNC_BUFFER__HPP__
#define __AIE_API_DETAIL_AIE2_SYNC_BUFFER__HPP__

#include "../lock.hpp"
#include "../vector.hpp"
#include "../mdspan.hpp"

namespace aie::detail::sync {

template <unsigned NumBuffers>
class sync_data_index
{
    addr_t idx_ = 0;

public:
    constexpr unsigned get_index() const
    {
        return (unsigned)idx_;
    }

    constexpr unsigned operator++()
    {
        if constexpr (NumBuffers == 2)
            idx_ = 1 - idx_;
        else if constexpr (NumBuffers > 2)
            ::add_2d_ptr((char *)uintptr_t(0), -int(NumBuffers - 1), NumBuffers - 1, idx_, 1);

        return idx_;
    }
};

template <>
class sync_data_index<1>
{
public:
    constexpr unsigned get_index() const
    {
        return 0;
    }

    constexpr unsigned operator++()
    {
        return 0;
    }
};

template <direction Direction, typename Span, unsigned NumBuffers, unsigned NumReaders, unsigned NumWriters, size_t... Is>
class sync_data_impl<Direction, Span, NumBuffers, NumReaders, NumWriters, std::index_sequence<Is...>>
{
    static_assert(NumBuffers > 0);
    static_assert(NumReaders > 0);
    static_assert(NumWriters > 0);

    using   span_type = Span;
    using           T = typename span_type::value_type;
    using  mutex_type = std::conditional_t<(Direction == direction::Input), aie::detail::consumer_sem<NumReaders, NumWriters>,
                                                                            aie::detail::producer_sem<NumReaders, NumWriters>>;

    template <size_t>
    using   buffer_ptr = T *;

public:
    using value_type = T;

    static constexpr unsigned num_buffers = NumBuffers;
    static constexpr unsigned num_readers = NumReaders;
    static constexpr unsigned num_writers = NumWriters;

    template <typename... DynamicExtents>
    constexpr sync_data_impl(buffer_ptr<Is>  ...ptrs,
                             mutex_type        &mutexes,
                             DynamicExtents  ...ext) :
        buffers_{Span(ptrs, ext...)...},
        locks_{mutexes}
    {
        static_assert(sizeof...(ptrs) == num_buffers);
        static_assert(sizeof...(ext)  == Span::rank_dynamic());
    }

    Span &acquire()
    {
        this->locks_.lock();

        return this->buffers_[index_.get_index()];
    }

    void release()
    {
        this->locks_.unlock();

        ++index_;
    }

    constexpr unsigned current_index() const
    {
        return index_.get_index();
    }

    constexpr size_t size() const
    {
        return buffers_[0].size();
    }

    constexpr size_t bytes() const
    {
        return size() * type_bits_v<T>;
    }

private:
    Span buffers_[NumBuffers];
    mutex_type &locks_;
    [[no_unique_address]] sync_data_index<NumBuffers> index_;
};

template <direction Direction, typename T, unsigned NumBuffers, unsigned NumReaders, unsigned NumWriters, size_t... Is>
class sync_data_impl<Direction, T *, NumBuffers, NumReaders, NumWriters, std::index_sequence<Is...>>
{
    static_assert(NumBuffers > 0);
    static_assert(NumReaders > 0);
    static_assert(NumWriters > 0);

    using mutex_type = std::conditional_t<(Direction == direction::Input), aie::detail::consumer_sem<NumReaders, NumWriters>,
                                                                           aie::detail::producer_sem<NumReaders, NumWriters>>;

    template <size_t>
    using buffer_ptr = T *;

public:
    using value_type = T;

    static constexpr unsigned num_buffers = NumBuffers;
    static constexpr unsigned num_readers = NumReaders;
    static constexpr unsigned num_writers = NumWriters;

    constexpr sync_data_impl(buffer_ptr<Is> ...ptrs,
                             mutex_type       &mutexes,
                             size_t            size) :
        buffers_{ptrs...},
        locks_{mutexes},
        size_(size)
    {
        static_assert(sizeof...(ptrs) == num_buffers);
    }

    value_type *acquire()
    {
        this->locks_.lock();

        return this->buffers_[index_.get_index()];
    }

    void release()
    {
        this->locks_.unlock();

        ++index_;
    }

    constexpr unsigned current_index() const
    {
        return index_.get_index();
    }

    constexpr size_t size() const
    {
        return size_;
    }

    constexpr size_t bytes() const
    {
        return size() * type_bits_v<T>;
    }

private:
    T *buffers_[NumBuffers];
    mutex_type &locks_;
    size_t size_;
    [[no_unique_address]] sync_data_index<NumBuffers> index_;
};

template <direction Direction, typename T, size_t Elems, unsigned NumBuffers, unsigned NumReaders, unsigned NumWriters, size_t... Is>
class sync_data_impl<Direction, T[Elems], NumBuffers, NumReaders, NumWriters, std::index_sequence<Is...>>
{
    static_assert(NumBuffers > 0);
    static_assert(NumReaders > 0);
    static_assert(NumWriters > 0);

    using mutex_type = std::conditional_t<(Direction == direction::Input), aie::detail::consumer_sem<NumReaders, NumWriters>,
                                                                           aie::detail::producer_sem<NumReaders, NumWriters>>;

    template <size_t>
    using buffer_ptr = T *;

public:
    using value_type = T;

    static constexpr unsigned num_buffers = NumBuffers;
    static constexpr unsigned num_readers = NumReaders;
    static constexpr unsigned num_writers = NumWriters;

    constexpr sync_data_impl(buffer_ptr<Is> ...ptrs,
                             mutex_type       &mutexes) :
        buffers_{ptrs...},
        locks_{mutexes}
    {
        static_assert(sizeof...(ptrs) == num_buffers);
    }

    value_type *acquire()
    {
        this->locks_.lock();

        return this->buffers_[index_.get_index()];
    }

    void release()
    {
        this->locks_.unlock();

        ++index_;
    }

    constexpr unsigned current_index() const
    {
        return index_.get_index();
    }

    constexpr size_t size() const
    {
        return Elems;
    }

    constexpr size_t bytes() const
    {
        return size() * type_bits_v<T>;
    }

private:
    T *buffers_[NumBuffers];
    mutex_type &locks_;
    [[no_unique_address]] sync_data_index<NumBuffers> index_;
};

}

#endif
