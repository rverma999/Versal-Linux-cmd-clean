// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// *****************************************************************************
// File: dummyStreamHelper.hpp
// 
/// This file contains the dummy declaration of the StreamHelperBase class for 
//  x86sim targets sim.out and libxcmsim.so
// *****************************************************************************
#include "x86simStreamHelper.h"

namespace x86sim
{
template<typename StreamTy, typename Enable>
void StreamHelper<StreamTy, Enable>::read(void *stream, void *data, bool &tlast) 
{
    //Dummy Implementation
    fprintf(stderr, "Assertion failure '0' at %s:%d\n", __FILE__, __LINE__);
    std::exit(1);
    return;
}

template<typename StreamTy, typename Enable>
void StreamHelper<StreamTy, Enable>::write(void *stream, void const *data, bool tlast)
{
    //Dummy Implementation
    fprintf(stderr, "Assertion failure '0' at %s:%d\n", __FILE__, __LINE__);
    std::exit(1);
    return;
}

template<typename StreamTy>
void StreamHelper<StreamTy, StandType<StreamTy>>::read(void *stream, void *data, bool &tlast) 
{
    //Dummy Implementation
    fprintf(stderr, "Assertion failure '0' at %s:%d\n", __FILE__, __LINE__);
    std::exit(1);
    return;
}

template<typename StreamTy>
void StreamHelper<StreamTy, StandType<StreamTy>>::write(void *stream, void const *data, bool tlast)
{
    //Dummy Implementation
    fprintf(stderr, "Assertion failure '0' at %s:%d\n", __FILE__, __LINE__);
    std::exit(1);
    return;
}

std::unique_ptr<StreamHelperBase>
StreamHelperBase::make(PlatformStreamDataType type, int dataWidth, int user, int id, int dest)
{
    //Dummy Implementation
    fprintf(stderr, "Assertion failure '0' at %s:%d\n", __FILE__, __LINE__);
    std::exit(1);
    return nullptr;
}

}//end of x86sim
