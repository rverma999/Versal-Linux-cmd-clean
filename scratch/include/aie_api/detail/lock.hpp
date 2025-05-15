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

#ifndef __AIE_API_DETAIL_LOCK__HPP__
#define __AIE_API_DETAIL_LOCK__HPP__

#include "utils.hpp"

#include <cstddef>
#include <tuple>
#include <utility>

namespace aie::detail {

struct adopt_lock_t {};

// Forward declaration for classes implemented in the architecture backends
class          mutex;
template <unsigned NumReaders, unsigned NumWriters>
class producer_sem;
template <unsigned NumReaders, unsigned NumWriters>
class consumer_sem;

}

#if __AIE_ARCH__ == 10

#include "aie1/lock.hpp"

#elif __AIE_ARCH__ == 20

#include "aie2/lock.hpp"

#endif

namespace aie::detail {

template <typename MutexType>
class scoped_lock_impl {
    using  mutex_type = MutexType;

    mutex_type *m_;

private:
    // Not copy-constructible and not copy-assignable
    scoped_lock_impl(const scoped_lock_impl &)            = delete;
    scoped_lock_impl &operator=(const scoped_lock_impl &) = delete;

    void lock()
    {
        m_->lock();
    }

    void unlock()
    {
        if (m_)
            m_->unlock();
    }

public:
    explicit scoped_lock_impl(mutex_type &m) :
        m_(&m)
    {
        lock();
    }

    explicit scoped_lock_impl(adopt_lock_t, mutex_type &m) :
        m_(&m)
    {
    }

    ~scoped_lock_impl()
    {
        unlock();
    }

    scoped_lock_impl(scoped_lock_impl && l)
    {
        unlock();

        m_    = l->m_;
        l->m_ = nullptr;
    }

    scoped_lock_impl &operator=(scoped_lock_impl && l)
    {
        unlock(*m_);

        m_    = l->m_;
        l->m_ = nullptr;

        return *this;
    }
};

template <size_t... Indices, typename... MutexTypes>
void unlock_reverse_helper(const std::index_sequence<Indices...> &, MutexTypes && ...mutexes)
{
    const auto t = std::forward_as_tuple(std::forward<MutexTypes>(mutexes)...);

    (std::get<Indices>(t).unlock(), ...);
}

template <typename Fn, typename... MutexTypes>
void locked(Fn fn, MutexTypes & ...mutexes)
{
    (mutexes.lock(), ...);

    fn();

    unlock_reverse_helper(utils::make_reverse_index_sequence<sizeof...(MutexTypes)>{}, std::forward<MutexTypes>(mutexes)...);
}

using   scoped_lock = scoped_lock_impl<mutex>;

template <unsigned NumReaders, unsigned NumWriters>
using producer_lock = scoped_lock_impl<producer_sem<NumReaders, NumWriters>>;
template <unsigned NumReaders, unsigned NumWriters>
using consumer_lock = scoped_lock_impl<consumer_sem<NumReaders, NumWriters>>;

}

#endif
