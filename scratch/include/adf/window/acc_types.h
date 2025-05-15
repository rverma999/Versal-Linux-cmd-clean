// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef __ACC_TYPES_H__
#define __ACC_TYPES_H__

#if __AIE_ARCH__<20
// XXX Why is this needed ?

#if defined(__AIENGINE__) || \
    (defined(__X86SIM__) && defined(__AIENGINE__) && !defined(__PL_KERNEL__))
typedef acc48 acc48_t;
typedef cacc48 cacc48_t;
typedef acc80 acc80_t;
typedef cacc80 cacc80_t;
typedef accfloat accfloat_t;
typedef caccfloat caccfloat_t;
#endif // if def __AIENGINE__ || (__X86SIM__ && __AIENGINE__ && !__PL_KERNEL__)
#endif // #if __AIE_ARCH__<20

#if !defined(__AIENGINE__) || defined(__PL_KERNEL__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
struct acc48 {}; 
struct cacc48 {}; 
struct acc80 {}; 
struct cacc80 {}; 
struct accfloat {}; 
struct caccfloat {};
 
// For x86sim, acc32 acc64 and accfloat are defined in 
// aietools/data/aie_ml/lib/isg/me_chess_types.h
struct acc32 {};
struct cacc32 {};
struct acc64 {};
struct cacc64 {};
#pragma clang diagnostic pop
typedef acc48 acc48_t;
typedef cacc48 cacc48_t;
typedef acc80 acc80_t;
typedef cacc80 cacc80_t;
typedef accfloat accfloat_t;
typedef caccfloat caccfloat_t;
#endif

#endif //__ACC_TYPES_H__
