// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// *****************************************************************************
// File: x86simStreamHelper.hpp
// 
/// This file contains the definition of the StreamHelperBase class for 
/// x86sim targets libsim.so
// *****************************************************************************
#include "x86simStreamHelper.h"
#define HLS_STREAM_THREAD_SAFE
#include "hls_stream.h"
#include "ap_axi_sdata.h"
#include <complex>

namespace x86sim
{
// *****************************************************************************
// struct StreamHelperDataTraits
// 
// This is the StreamHelperDataTraits class, which returns the number of 32bit
// words for a given StreamTy.
// *****************************************************************************
template<typename StreamTy>
struct StreamHelperDataTraits 
{
};

// *****************************************************************************
// struct StreamHelperDataTraits
// 
// This is partial specialization of StreamHelperDataTraits for ap_axis.
// *****************************************************************************
template<int DataWidth>
struct StreamHelperDataTraits< hls::axis<ap_int<DataWidth>,0,0,0> >
{
    static_assert( DataWidth==32 || DataWidth==64 || DataWidth==128 , 
        "Error : StreamHelperDataTraits doesnot support data width other than"
         " 32 , 64 and 128.");

    static const int numWords = DataWidth / 32; 
};

// *****************************************************************************
// struct StreamHelperDataTraits
// 
// This is partial specialization of StreamHelperDataTraits for ap_axiu.
// *****************************************************************************
template<int DataWidth>
struct StreamHelperDataTraits< hls::axis<ap_uint<DataWidth>,0,0,0> >
{
    static_assert( DataWidth==32 || DataWidth==64 || DataWidth==128 , 
        "Error : StreamHelperDataTraits does not support data width other than"
         " 32 , 64 and 128."); 

    static const int numWords = DataWidth / 32;
};

template<typename StreamTy, typename Enable>
void StreamHelper<StreamTy, Enable>::read(void *stream, void *data, bool &tlast) 
{
    hls::stream<StreamTy> *hlsStream = (hls::stream<StreamTy> *) stream;
    StreamTy x = hlsStream->read();

    for (int ind = 0; ind < StreamHelperDataTraits<StreamTy>::numWords; ind++)
        *((int32_t*) data + ind) = x.data.range(32 * (ind + 1) -1, 32 * ind);

    tlast = x.last;
}

template<typename StreamTy, typename Enable>
void StreamHelper<StreamTy, Enable>::write(void *stream, void const *data, bool tlast)
{
    hls::stream<StreamTy> *hlsStream = (hls::stream<StreamTy> *) stream;
    StreamTy x ;

    for (int ind = 0; ind < StreamHelperDataTraits<StreamTy>::numWords; ind++)
        x.data.range(32 * (ind + 1) -1, 32 * ind) = *((int32_t*) data + ind);

    hlsStream->write(x);
    x.last = tlast;
}

template<typename StreamTy>
void StreamHelper<StreamTy, StandType<StreamTy>>::read(void *stream, void *data, bool &tlast) 
{
    hls::stream<StreamTy> *hlsStream = (hls::stream<StreamTy> *) stream;
    StreamTy x = hlsStream->read();

    *((StreamTy*) data) = x;
}

template<typename StreamTy>
void StreamHelper<StreamTy, StandType<StreamTy>>::write(void *stream, void const *data, bool tlast)
{
    hls::stream<StreamTy> *hlsStream = (hls::stream<StreamTy> *) stream;
    StreamTy x = *((StreamTy*) data);

    hlsStream->write(x);
}

std::unique_ptr<StreamHelperBase>
StreamHelperBase::make(PlatformStreamDataType type, int dataWidth, int user, int id, int dest)
{
    if (!(user == 0 && id == 0 && dest == 0))
    {
        fprintf(stderr, "Assertion failure '%s' at %s:%d\n", 
                "StreamHelperBase::make: (user != 0 || id != 0 || dest != 0)",
                __FILE__, __LINE__);
        std::exit(1); 
        return nullptr;
    }

    switch (type)
    {
    case PlatformStreamDataType::kAxis :
       switch (dataWidth)
       {
         case 32: return std::make_unique<StreamHelper< hls::axis<ap_int<32>,0,0,0> > >();
         case 64: return std::make_unique<StreamHelper< hls::axis<ap_int<64>,0,0,0> > >();
         case 128: return std::make_unique<StreamHelper< hls::axis<ap_int<128>,0,0,0> > >();
         default : return std::unique_ptr<StreamHelperBase>();
       }
    case PlatformStreamDataType::kAxiu :
       switch (dataWidth)
       {
         case 32: return std::make_unique<StreamHelper< hls::axis<ap_uint<32>,0,0,0> > >();
         case 64: return std::make_unique<StreamHelper< hls::axis<ap_uint<64>,0,0,0> > >();
         case 128: return std::make_unique<StreamHelper< hls::axis<ap_uint<128>,0,0,0> > >();
         default : return std::unique_ptr<StreamHelperBase>();
       }
    case PlatformStreamDataType::kInt :
       switch (dataWidth)
       {
         case 32: return std::make_unique<StreamHelper< int > >();
         default : return std::unique_ptr<StreamHelperBase>();
       }
    case PlatformStreamDataType::kFloat :
       switch (dataWidth)
       {
         case 32: return std::make_unique<StreamHelper< float > >();
         default : return std::unique_ptr<StreamHelperBase>();
       }
    case PlatformStreamDataType::kCint :
       switch (dataWidth)
       {
         case 32: return std::make_unique<StreamHelper< std::complex<int16_t> > >();
         case 64: return std::make_unique<StreamHelper< std::complex<int> > >();
         default : return std::unique_ptr<StreamHelperBase>();
       }
    case PlatformStreamDataType::kCfloat :
       switch (dataWidth)
       {
         case 64: return std::make_unique<StreamHelper< std::complex<float> > >();
         default : return std::unique_ptr<StreamHelperBase>();
       }

     default: return std::unique_ptr<StreamHelperBase>();
    }
}

}//end of x86sim
