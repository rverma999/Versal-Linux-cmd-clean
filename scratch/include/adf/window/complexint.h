// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef __COMPLEXINT_H__
#define __COMPLEXINT_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif
#if (!defined(__AIENGINE__)) || defined(__PL_KERNEL__)
struct cint16
{
  short real;
  short imag;
};
struct cint32
{
  int real;
  int imag;
};
struct cfloat
{
  float real;
  float imag;
};
#endif

#if defined(__AIENGINE__) && !defined(__X86SIM__)
#define COMPLEX_TYPE(type)			\
  typedef struct				\
  {						\
    type chess_storage(%(sizeof(type)*2)) real;	\
    type imag;					\
  } c##type
#else
#define COMPLEX_TYPE(type)			\
  typedef struct				\
  {						\
    type real;					\
    type imag;					\
  } c##type
#endif

#define COMPLEX_TYPEDEF(type) \
  typedef c ## type ## _t c ## type ;

#if !defined(__AIE__) || __AIE_MODEL_VERSION__ < 10800
  COMPLEX_TYPE(int8_t);
  COMPLEX_TYPE(int64_t);

  COMPLEX_TYPEDEF(int8)
  COMPLEX_TYPEDEF(int64)

#else
  typedef cint8  cint8_t ;
  typedef cint16 cint16_t;
  typedef cint64 cint64_t;
#endif

  typedef cint16 cint16_t ;
  typedef cint32 cint32_t ;
#if __AIE_ARCH__<=20
  typedef cfloat cfloat_t ;
#endif

  COMPLEX_TYPE(uint8_t);
  COMPLEX_TYPE(uint16_t);
  COMPLEX_TYPE(uint32_t);
  COMPLEX_TYPE(uint64_t);

  COMPLEX_TYPEDEF(uint8)
  COMPLEX_TYPEDEF(uint16)
  COMPLEX_TYPEDEF(uint32)
  COMPLEX_TYPEDEF(uint64)

#undef COMPLEX_TYPE
#undef COMPLEX_TYPEDEF

#ifdef __cplusplus
};
#endif
inline int as_int(cuint16_t v)
{
  return *(int *)&v;
}
#endif // __COMPLEXINT_H__



