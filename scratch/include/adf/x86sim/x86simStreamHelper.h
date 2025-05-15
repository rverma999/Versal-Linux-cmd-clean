// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// *****************************************************************************
// For reading and writing to HLS Stream: x86simStreamHelper.h
// 
/// This file contains the definition of the  class.
// *****************************************************************************

#ifndef _SRC_X86SIM_INCLUDE_X86SIM_STREAM_HELPER_H_
#define _SRC_X86SIM_INCLUDE_X86SIM_STREAM_HELPER_H_

#include <complex>
#include "nodeInterfaces.h"

namespace x86sim
{
// *****************************************************************************
// struct StreamHelperBase
// 
/// This is the StreamHelperBase class. It is an interface that provides apis
/// for reading/writing a datum from/to a HLS Stream.
// *****************************************************************************
struct StreamHelperBase
{
   StreamHelperBase()
      {}
   StreamHelperBase(StreamHelperBase const &other)
      {}
   virtual ~StreamHelperBase() = default;

   virtual void read(void *stream, void *data, bool &tlast) = 0;
   virtual void write(void *stream, void const *data, bool tlast) = 0;

   static std::unique_ptr<StreamHelperBase>
   make(PlatformStreamDataType type, int dataWidth, int user, int id, int dest);
};

// *****************************************************************************
// struct streamHelper
// 
/// This is the StreamHelper class, which implements the StreamHelperBase
/// interface for HLS Types.
// *****************************************************************************
template<typename StreamTy, typename Enable=void>
struct StreamHelper : public StreamHelperBase
{
   StreamHelper()
      :StreamHelperBase()
      {
      }
   StreamHelper(StreamHelper const &other)
      :StreamHelperBase(other)
      {
      }
   virtual ~StreamHelper() = default;

   virtual void read(void *stream, void *data, bool &tlast) override;
   virtual void write(void *stream, void const *data, bool tlast) override;
};

// *****************************************************************************
// struct streamHelper
// 
/// This is partial specialization of StreamHelper class for type int,
/// float , std::complex<int> and std::complex<float>.
// *****************************************************************************
template<typename StreamTy>
using StandType = typename std::enable_if<std::is_same<StreamTy,int>::value ||
                              std::is_same<StreamTy,float>::value ||
                              std::is_same<StreamTy,std::complex<int>>::value ||
                              std::is_same<StreamTy,std::complex<int16_t>>::value ||
                              std::is_same<StreamTy,std::complex<float>>::value > ::type;

template<typename StreamTy>
struct StreamHelper<StreamTy, StandType<StreamTy>>
    : public StreamHelperBase
{
   StreamHelper()
      :StreamHelperBase()
      {
      }
   StreamHelper(StreamHelper const &other)
      :StreamHelperBase(other)
      {
      }
   virtual ~StreamHelper() = default;

   virtual void read(void *stream, void *data, bool &tlast) override;
   virtual void write(void *stream, void const *data, bool tlast) override;
};


} // namespace x86sim

#endif // #ifndef _SRC_X86SIM_INCLUDE_X86SIM_STREAM_HELPER_H_
