/*  (c) Copyright 2020 - 2024 Xilinx, Inc. All rights reserved.

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

#ifndef __AIE_API_TILE__HPP__
#define __AIE_API_TILE__HPP__

#include "aie_types.hpp"

#if __AIE_ARCH__ == 10

#include "detail/aie1/tile.hpp"

#elif __AIE_ARCH__ == 20

#include "detail/aie2/tile.hpp"

#endif


namespace aie {

class tile : private detail::tile
{
private:
    using base_type = detail::tile;

    tile(const base_type &t) : detail::tile(t) {}
public:
    /** \brief Return the global tile id */
    __aie_inline
    tile_id global_id() const { return base_type::global_id(); }

    /** \brief Return the tile id */
    __aie_inline
    tile_id id() const { return base_type::id(); }

    /** \brief Return the elapsed number of cycles */
    __aie_inline
    uint64_t cycles() const { return base_type::cycles(); }

    /** \brief Return an instance of \ref tile representing the current tile. */
    __aie_inline
    static tile current() { return base_type::current(); }

    /** \brief Changes saturation mode */
    __aie_inline
    void set_saturation(saturation_mode mode) { base_type::set_saturation(mode); }

    /** \brief Returns current saturation mode */
    __aie_inline
    saturation_mode get_saturation() const { return base_type::get_saturation(); }

    /** \brief Changes rounding mode */
    __aie_inline
    void set_rounding(rounding_mode mode) { base_type::set_rounding(mode);
    }

    /** \brief Returns current rounding mode */
    __aie_inline
    rounding_mode get_rounding() const { return base_type::get_rounding(); }
};

}

#endif // __AIE_API_TILE__HPP__
