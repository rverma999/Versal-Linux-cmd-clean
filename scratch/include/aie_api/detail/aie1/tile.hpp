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

#ifndef __AIE_API_DETAIL_AIE1_TILE__HPP__
#define __AIE_API_DETAIL_AIE1_TILE__HPP__

#include "../../aie_types.hpp"

namespace aie::detail {

struct tile_id_hw
{
    union
    {
        int data;

        struct
        {
            unsigned row       : 5;
            unsigned reserved1 : 11;
            unsigned col       : 7;
            unsigned reserved2 : 9;
        } coord;
    };
};

class tile
{
private:
    static constexpr uint16_t compute_row_offset = 1;

    __aie_inline
    constexpr tile() {}

public:
    __aie_inline
    tile_id global_id() const
    {
        const tile_id_hw id_hw = { get_coreid() };
        const tile_id ret      = { uint16_t(id_hw.coord.row), uint16_t(id_hw.coord.col) };

        return ret;
    }

    __aie_inline
    tile_id id() const
    {
        const tile_id gid = global_id();
        const tile_id ret = { uint16_t(gid.row - compute_row_offset), gid.col };

        return ret;
    }

    __aie_inline
    uint64_t cycles() const
    {
        return ::get_cycles();
    }

    __aie_inline
    static tile current()
    {
        return tile();
    }

    __aie_inline
    void set_saturation(saturation_mode mode)
    {
        // CRVO-2774: create combined get_sat get_symsat intrinsic
        if (mode == saturation_mode::none) {
            ::clr_sat();
            ::clr_symsat();
        }
        else if (mode == saturation_mode::saturate) {
            ::set_sat();
        }
        else {
            ::set_sat();
            ::set_symsat();
        }
    }

    __aie_inline
    saturation_mode get_saturation() const
    {
        // CRVO-2774: create combined get_sat get_symsat intrinsic
        return (saturation_mode)((::get_symsat() << 1) | ::get_sat());
    }

    __aie_inline
    void set_rounding(rounding_mode mode)
    {
        ::set_rnd((unsigned)mode);
    }

    __aie_inline
    rounding_mode get_rounding() const
    {
        return (rounding_mode)::get_rnd();
    }
};

} // namespace aie::detail

#endif
