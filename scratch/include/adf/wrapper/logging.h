// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
/*  (c) Copyright 2014 - 2016 Xilinx, Inc. All rights reserved.
   
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


#ifndef __LOGGING_H__
#define __LOGGING_H__

#include <systemc.h>

#include <boost/log/trivial.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>

typedef boost::log::sources::severity_channel_logger_mt<boost::log::trivial::severity_level>
    sc_logger_type;

BOOST_LOG_GLOBAL_LOGGER(sc_logger,sc_logger_type)

#define SC_LOG_IMPL(lvl)                                                         \
    BOOST_LOG_CHANNEL_SEV(sc_logger::get(),                                      \
                          std::string(name())+"."+__FUNCTION__,                  \
                          boost::log::trivial::lvl) << std::dec
#define NAME_LOG_IMPL(name,lvl)                                                  \
    BOOST_LOG_CHANNEL_SEV(sc_logger::get(),                                      \
                          std::string(name)+"."+__FUNCTION__,                    \
                          boost::log::trivial::lvl) << std::dec

#ifdef HAS_LOGGING
#  define SC_LOG(lvl)        SC_LOG_IMPL(lvl)
#  define NAME_LOG(name,lvl) NAME_LOG_IMPL(name,lvl)
#else
#  define SC_LOG(lvl)        while (false) SC_LOG_IMPL(lvl)
#  define NAME_LOG(name,lvl) while (false) NAME_LOG_IMPL(name,lvl)
#endif

#ifdef HAS_LOG_TRACE
#  define SC_LOG_TRACE         SC_LOG_IMPL(trace)
#  define NAME_LOG_TRACE(name) NAME_LOG_IMPL(name,trace)
#else
#  define SC_LOG_TRACE         while (false) SC_LOG_IMPL(trace)
#  define NAME_LOG_TRACE(name) while (false) NAME_LOG_IMPL(name,trace)
#endif

#ifdef HAS_LOG_DEBUG
#  define SC_LOG_DEBUG         SC_LOG_IMPL(debug)
#  define NAME_LOG_DEBUG(name) NAME_LOG_IMPL(name,debug)
#else
#  define SC_LOG_DEBUG         while (false) SC_LOG_IMPL(debug)
#  define NAME_LOG_DEBUG(name) while (false) NAME_LOG_IMPL(name,debug)
#endif

#endif //__LOGGING_H__
