// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef __WINDOW_H__
#define __WINDOW_H__
#include <stdio.h>
#include <assert.h>
#include <type_traits>

#include "adf/intrinsics.h"
#include "adf/window/types.h"
#include "window_internal.h"

#ifdef __X86SIM__
#include "adf/x86sim/observabilityInterfaces.h"

#define X86SIM_CHECK_PTR_ALIGNMENT(PTR, FUNC_NAME) x86sim::checkPtrAlignment(PTR, FUNC_NAME) 
#else  // !  __X86SIM__
#define X86SIM_CHECK_PTR_ALIGNMENT(PTR, FUNC_NAME) 
#endif // !  __X86SIM__

#define ROUND_TO_8(x) ((x+7)/8)*8
#define W_SIZE(taps,sz)              (sz + ROUND_TO_8(taps-1))
#define W_SIZE_INTERPOLATOR(taps,sz) (sz + ROUND_TO_8((taps-1)/2))

// window_datatype defined in window_internal.h
// cyclic_add defined in window_internal.h

#define WINDOW_DATATYPE_SIZE   (sizeof (window_datatype))

#ifdef __X86SIM__
template<typename T>
T *select(bool sel, T *val1, T *val2)
{
    return sel ? val1 : val2;
}
#endif // #ifdef __X86SIM__

#pragma pack()
template<typename T> struct input_window
{
    unsigned int current_bufid;
    unsigned int instanceId;
    window_datatype* restrict ptr;
    window_datatype* restrict head;
    window_datatype* restrict heads[2];
    window_datatype* restrict buffer;
    window_datatype* restrict buffers[2];
    unsigned int size;
    unsigned int winsize;
#ifdef __X86SIM__
    x86sim::IWindowConnector *conn;
#else //!__X86SIM__
    unsigned int lockids[2];
#endif
};

#pragma pack()
template<typename T> struct output_window
{
    unsigned int current_bufid;
    unsigned int instanceId;
    window_datatype* restrict ptr;
    window_datatype* restrict head;
    window_datatype* restrict heads[2];
    window_datatype* restrict buffer;
    window_datatype* restrict buffers[2];
    unsigned int size;
    unsigned int winsize;
#ifdef __X86SIM__
    x86sim::IWindowConnector *conn;
#else //!__X86SIM__
    unsigned int lockids[2];
#endif
};

typedef input_window<int8> input_window_int8;
typedef input_window<uint8> input_window_uint8;
typedef input_window<int16> input_window_int16;
typedef input_window<uint16> input_window_uint16;
typedef input_window<int32> input_window_int32;
typedef input_window<uint32> input_window_uint32;
typedef input_window<int64> input_window_int64;
typedef input_window<uint64> input_window_uint64;
typedef input_window<float> input_window_float;

typedef output_window<int8> output_window_int8;
typedef output_window<uint8> output_window_uint8;
typedef output_window<int16> output_window_int16;
typedef output_window<uint16> output_window_uint16;
typedef output_window<int32> output_window_int32;
typedef output_window<uint32> output_window_uint32;
typedef output_window<int64> output_window_int64;
typedef output_window<uint64> output_window_uint64;
typedef output_window<float> output_window_float;

typedef input_window<cint16> input_window_cint16;
typedef input_window<cint32> input_window_cint32;
#if __AIE_ARCH__<20
typedef input_window<cfloat> input_window_cfloat;
#endif
typedef output_window<cint16> output_window_cint16;
typedef output_window<cint32> output_window_cint32;
#if __AIE_ARCH__<20
typedef output_window<cfloat> output_window_cfloat;
#endif

template<typename tpDataType>
struct is_window_data_type: public std::false_type {};
template<> struct is_window_data_type<int8>: public std::true_type {};
template<> struct is_window_data_type<uint8>: public std::true_type {};
template<> struct is_window_data_type<int16>: public std::true_type {};
template<> struct is_window_data_type<uint16>: public std::true_type {};
template<> struct is_window_data_type<int32>: public std::true_type {};
template<> struct is_window_data_type<uint32>: public std::true_type {};
template<> struct is_window_data_type<int64>: public std::true_type {};
template<> struct is_window_data_type<uint64>: public std::true_type {};
template<> struct is_window_data_type<float>: public std::true_type {};
template<> struct is_window_data_type<cint16>: public std::true_type {};
template<> struct is_window_data_type<cint32>: public std::true_type {};
#if __AIE_ARCH__<20
template<> struct is_window_data_type<cfloat>: public std::true_type {};
#endif


#define CAST_TYPES( direction, element_type )  \
  static inline  direction ## _window_ ## element_type *  get_ ## direction ## _async_window_ ## element_type(window_internal * wind ) { \
    direction ## _window_ ## element_type * toReturn = ( direction ## _window_ ## element_type *)wind; \
      return toReturn; \
  }
CAST_TYPES(input, int8)
CAST_TYPES(input, uint8)
CAST_TYPES(input, int16)
CAST_TYPES(input, uint16)
CAST_TYPES(input, int32)
CAST_TYPES(input, uint32)
CAST_TYPES(input, int64)
CAST_TYPES(input, uint64)
CAST_TYPES(input, float)
CAST_TYPES(output, int8)
CAST_TYPES(output, uint8)
CAST_TYPES(output, int16)
CAST_TYPES(output, uint16)
CAST_TYPES(output, int32)
CAST_TYPES(output, uint32)
CAST_TYPES(output, int64)
CAST_TYPES(output, uint64)
CAST_TYPES(output, float)

CAST_TYPES(input, cint16)
CAST_TYPES(input, cint32)
#if __AIE_ARCH__<20
CAST_TYPES(input, cfloat)
#endif
CAST_TYPES(output, cint16)
CAST_TYPES(output, cint32)
#if __AIE_ARCH__<20
CAST_TYPES(output, cfloat)
#endif

#undef CAST_TYPES

#define CAST_TYPES( direction, element_type )  \
  static inline  direction ## _window_ ## element_type *  get_ ## direction ## _window_ ## element_type(window_internal * wind ) { \
    direction ## _window_ ## element_type * toReturn = ( direction ## _window_ ## element_type *)wind; \
      toReturn->ptr = wind->head;\
      return toReturn; \
  }

CAST_TYPES(input, int8)
CAST_TYPES(input, uint8)
CAST_TYPES(input, int16)
CAST_TYPES(input, uint16)
CAST_TYPES(input, int32)
CAST_TYPES(input, uint32)
CAST_TYPES(input, int64)
CAST_TYPES(input, uint64)
CAST_TYPES(input, float)

CAST_TYPES(output, int8)
CAST_TYPES(output, uint8)
CAST_TYPES(output, int16)
CAST_TYPES(output, uint16)
CAST_TYPES(output, int32)
CAST_TYPES(output, uint32)
CAST_TYPES(output, int64)
CAST_TYPES(output, uint64)
CAST_TYPES(output, float)

CAST_TYPES(input, cint16)
CAST_TYPES(input, cint32)
#if __AIE_ARCH__<20
CAST_TYPES(input, cfloat)
#endif
CAST_TYPES(output, cint16)
CAST_TYPES(output, cint32)
#if __AIE_ARCH__<20
CAST_TYPES(output, cfloat)
#endif

#undef CAST_TYPES

#define COPY_TYPES( direction, element_type ) \
  static inline void window_copy(direction ## _window_ ## element_type *dst, direction ## _window_ ## element_type *src) { \
    dst->ptr    = chess_copy(src->ptr); \
    dst->head   = chess_copy(src->head); \
    dst->buffer = chess_copy(src->buffer); \
    dst->size   = chess_copy(src->size); \
    dst->winsize= chess_copy(src->winsize); \
  }
COPY_TYPES(input, int8)
COPY_TYPES(input, uint8)
COPY_TYPES(input, int16)
COPY_TYPES(input, uint16)
COPY_TYPES(input, int32)
COPY_TYPES(input, uint32)
COPY_TYPES(input, int64)
COPY_TYPES(input, uint64)
COPY_TYPES(input, float)

COPY_TYPES(output, int8)
COPY_TYPES(output, uint8)
COPY_TYPES(output, int16)
COPY_TYPES(output, uint16)
COPY_TYPES(output, int32)
COPY_TYPES(output, uint32)
COPY_TYPES(output, int64)
COPY_TYPES(output, uint64)
COPY_TYPES(output, float)

COPY_TYPES(input, cint16)
COPY_TYPES(input, cint32)
#if __AIE_ARCH__<20
COPY_TYPES(input, cfloat)
#endif
COPY_TYPES(output, cint16)
COPY_TYPES(output, cint32)
#if __AIE_ARCH__<20
COPY_TYPES(output, cfloat)
#endif

#undef COPY_TYPES


// window_init() defined in window_internal.h

#define W_CTOR(type)                                                     \
  static inline void window_init(window_internal *w, int const channels, \
				   type *buffer_ping, unsigned int lockid_ping,	\
				   type *buffer_pong, unsigned int lockid_pong,	\
				   int const size, int const winsize)	\
  {\
    int s = (sizeof(type))/sizeof(window_datatype);									\
    int const sz = (size *s ); \
    int const winsz =  (winsize * s); \
    window_init(w,channels, (window_datatype *)buffer_ping, lockid_ping, (window_datatype *)buffer_pong, lockid_pong, sz, winsz); \
  }									\
  static inline void window_init(window_internal *w, int const channels, \
				   type *restrict buffer_ping, unsigned int lockid_ping,	\
				   type *restrict buffer_pong, unsigned int lockid_pong,	\
				   int const size)			\
  {									\
    int const sz = (size * sizeof(type))/sizeof(window_datatype);       \
    window_init (w, channels, buffer_ping, lockid_ping, buffer_pong, lockid_pong, sz, sz); \
  }     \
static inline void window_init(window_internal *w, int const channels, \
                                   type *buffer_ping,                        \
                                   int const size, int const winsize)   \
  {                                                                     \
    int s = (sizeof(type))/sizeof(window_datatype);                                                                     \
    int const sz = (size *s ); \
    int const winsz =  (winsize * s); \
    window_init(w,channels, (window_datatype *)buffer_ping, 0, (window_datatype *)buffer_ping, 0,sz, winsz); \
  }                                                                     \
  static inline void window_init(window_internal *w, int const channels, \
                                   type *buffer_ping,       \
                                   int const size)                      \
  {                                                                     \
    int const sz = (size * sizeof(type))/sizeof(window_datatype);       \
    window_init (w, channels, (window_datatype *)buffer_ping, 0, (window_datatype *)buffer_ping, 0, sz, sz); \
  }

/* First handle scalars. */
//W_CTOR(int8) -- This is default so no reason to handle again..
W_CTOR(uint8)
W_CTOR(int16)
W_CTOR(uint16)
W_CTOR(int32)
W_CTOR(uint32)
W_CTOR(int64)
W_CTOR(uint64)
W_CTOR(float)

#if __AIE_ARCH__<20
/* 128 Bit Vectors.  */
W_CTOR(v16int8)
W_CTOR(v16uint8)
W_CTOR(v4int32)
W_CTOR(v8int16)
W_CTOR(v4float)

/* 256 Bit Vectors.  */
W_CTOR(v4int64)
W_CTOR(v8float)

/* 512 bit vectors.  */
W_CTOR(v8int64)
W_CTOR(v16float)

/* 1024 bit vectors.  */
W_CTOR(v32float)
#endif

/* 256 Bit Vectors.  */
//W_CTOR(v2int128)
W_CTOR(v32int8)
W_CTOR(v32uint8)
W_CTOR(v16int16)
W_CTOR(v8int32)

/* 512 bit vectors.  */
W_CTOR(v64int8)
W_CTOR(v64uint8)
W_CTOR(v16int32)
W_CTOR(v32int16)

/* 1024 bit vectors.  */
W_CTOR(v128int8)
W_CTOR(v128uint8)
W_CTOR(v64int16)
W_CTOR(v32int32)

/* complex vectors */
W_CTOR(cint16)
W_CTOR(cint32)
#if __AIE_ARCH__<20
W_CTOR(cfloat)
#endif

#if __AIE_ARCH__<20  //AIE2 doesn't support 128-bit support yet
W_CTOR(v2cint32)
W_CTOR(v4cint16)
W_CTOR(v2cfloat)
#endif

//W_CTOR(v1cint128)    
//W_CTOR(v2cint64)
W_CTOR(v4cint32)
W_CTOR(v8cint16)
#if __AIE_ARCH__<20
W_CTOR(v4cfloat)
#endif

W_CTOR(v8cint32)
W_CTOR(v16cint16)
//W_CTOR(v4cint64)
#if __AIE_ARCH__<20
W_CTOR(v8cfloat)
#endif

#if __AIE_ARCH__<20  //AIE2 doesn't support 128-bit support yet
W_CTOR(v16cint32)
W_CTOR(v32cint16)
W_CTOR(v16cfloat)
#endif

#undef W_CTOR

// set_window_size() defined in window_internal.h
// window_size() defined in window_internal.h

#define WINSIZE(type)                                                     \
  static inline void set_window_size(input_window_ ## type *w, int const size)  \
  {                                                                      \
    set_window_size((window_internal *)w,size*(sizeof(type)/sizeof(window_datatype))); 		 \
  }                                                                      \
  static inline void set_window_size(output_window_ ## type *w, int const size)  \
  {                                                                      \
    set_window_size((window_internal *)w,size*(sizeof(type)/sizeof(window_datatype))); 		 \
  }                                                                      \
  static inline unsigned window_size(input_window_ ## type *w) 		 \
  {                                                                      \
    return window_size((window_internal *)w)/(sizeof(type)/sizeof(window_datatype));		 \
  }                                                                      \
  static inline unsigned window_size(output_window_ ## type *w) 	 \
  {                                                                      \
    return window_size((window_internal *)w)/(sizeof(type)/sizeof(window_datatype));	         \
  }                                                                      

WINSIZE(int8)
WINSIZE(uint8) 
WINSIZE(int16)
WINSIZE(uint16)
WINSIZE(int32)
WINSIZE(uint32)
WINSIZE(int64)
WINSIZE(uint64)
WINSIZE(float)

WINSIZE(cint16)
WINSIZE(cint32)
#if __AIE_ARCH__<20
WINSIZE(cfloat)
#endif

static inline void window_copy(window_internal *dst, window_internal *src,
                               int const channels)
{
    for (int i = 0; i < channels; ++i)
    {
      dst[i].head   = chess_copy(src[i].head); 
      dst[i].ptr    = chess_copy(src[i].ptr); 
      dst[i].buffer = chess_copy(src[i].buffer); 
      dst[i].size   = chess_copy(src[i].size); 
      dst[i].winsize = chess_copy(src[i].winsize);  
    } 
} 

// Compiler-Inserted Window Operations

// buffer has a specific allocated amount of memory which starts at w->buffer and is of w->size in bytes

// window_incr_pingpong(...) defined in window_internal.h
// window_incr(...) defined in window_internal.h

#define COMPILER_INCR_DECR_OPS( type )				   \
  static inline void window_incr_ ## type(window_internal * w, int count) { \
    count *= sizeof(type) / sizeof(window_datatype);			   \
    w->head = cyclic_add(w->head, count, w->buffer, w->size);	  \
  }								  \
  static inline void window_decr_ ## type (window_internal * w, int count) { \
    window_incr_ ## type (w, -count);				  \
  }

#if __AIE_ARCH__<20
/* 128 Bit Vectors.  */
COMPILER_INCR_DECR_OPS(v16int8)
COMPILER_INCR_DECR_OPS(v16uint8)
COMPILER_INCR_DECR_OPS(v4int32)
COMPILER_INCR_DECR_OPS(v8int16)
COMPILER_INCR_DECR_OPS(v4float)

/* 256 Bit Vectors.  */
COMPILER_INCR_DECR_OPS(v4int64)
COMPILER_INCR_DECR_OPS(v8float)

/* 512 bit vectors.  */
COMPILER_INCR_DECR_OPS(v8int64)
COMPILER_INCR_DECR_OPS(v16float)

/* 1024 bit vectors.  */
COMPILER_INCR_DECR_OPS(v32float)
#endif

/* 256 Bit Vectors.  */
COMPILER_INCR_DECR_OPS(v16int16)
//COMPILER_INCR_DECR_OPS(v2int128)  
COMPILER_INCR_DECR_OPS(v32int8)
COMPILER_INCR_DECR_OPS(v32uint8)
COMPILER_INCR_DECR_OPS(v8int32)

/* 512 bit vectors.  */
COMPILER_INCR_DECR_OPS(v16int32)
COMPILER_INCR_DECR_OPS(v32int16)
COMPILER_INCR_DECR_OPS(v64int8)
COMPILER_INCR_DECR_OPS(v64uint8)


/* 1024 bit vectors.  */
COMPILER_INCR_DECR_OPS(v128int8)
COMPILER_INCR_DECR_OPS(v128uint8)
COMPILER_INCR_DECR_OPS(v32int32)
COMPILER_INCR_DECR_OPS(v64int16)

#if __AIE_ARCH__<20 //AIE2 doesn't support 128-bit support yet
COMPILER_INCR_DECR_OPS(v2cint32)
COMPILER_INCR_DECR_OPS(v4cint16)
COMPILER_INCR_DECR_OPS(v2cfloat)
#endif

//COMPILER_INCR_DECR_OPS(v1cint128)    
//COMPILER_INCR_DECR_OPS(v2cint64) 
COMPILER_INCR_DECR_OPS(v4cint32)
COMPILER_INCR_DECR_OPS(v8cint16)
#if __AIE_ARCH__<20
COMPILER_INCR_DECR_OPS(v4cfloat)
#endif

COMPILER_INCR_DECR_OPS(v8cint32)
COMPILER_INCR_DECR_OPS(v16cint16)
//COMPILER_INCR_DECR_OPS(v4cint64)
#if __AIE_ARCH__<20
COMPILER_INCR_DECR_OPS(v8cfloat)
#endif

#if __AIE_ARCH__<20 //AIE2 doesn't support 128-bit support yet
COMPILER_INCR_DECR_OPS(v16cint32)
COMPILER_INCR_DECR_OPS(v32cint16)
COMPILER_INCR_DECR_OPS(v16cfloat)
#endif

// Customer-Facing Window Operations

#define INCR_SCALAR_OPS(direction, type)				      \
  static inline void window_incr(direction ## _window_ ## type * w, int count) { \
    count *= sizeof(type) / sizeof(window_datatype);  		      \
    w->ptr = cyclic_add(w->ptr, count, w->buffer, w->size);           \
  }

 #define DECR_SCALAR_OPS(direction, type)			      \
    static inline void window_decr(direction ## _window_ ## type * w, int count) { \
    window_incr(w, -count);  \
  } 


  INCR_SCALAR_OPS(input, int8)    
  INCR_SCALAR_OPS(input, uint8)   
  INCR_SCALAR_OPS(input, int16)   
  INCR_SCALAR_OPS(input, uint16)  
  INCR_SCALAR_OPS(input, int32)   
  INCR_SCALAR_OPS(input, uint32)  
  INCR_SCALAR_OPS(input, float)   
  INCR_SCALAR_OPS(input, int64)   
  INCR_SCALAR_OPS(input, uint64)  

  INCR_SCALAR_OPS(output, int8)   
  INCR_SCALAR_OPS(output, uint8)  
  INCR_SCALAR_OPS(output, int16)  
  INCR_SCALAR_OPS(output, uint16) 
  INCR_SCALAR_OPS(output, int32)  
  INCR_SCALAR_OPS(output, uint32) 
  INCR_SCALAR_OPS(output, float)  
  INCR_SCALAR_OPS(output, int64)  
  INCR_SCALAR_OPS(output, uint64) 

  DECR_SCALAR_OPS(input, int8)    
  DECR_SCALAR_OPS(input, uint8)   
  DECR_SCALAR_OPS(input, int16)   
  DECR_SCALAR_OPS(input, uint16)  
  DECR_SCALAR_OPS(input, int32)   
  DECR_SCALAR_OPS(input, uint32)  
  DECR_SCALAR_OPS(input, float)   
  DECR_SCALAR_OPS(input, int64)   
  DECR_SCALAR_OPS(input, uint64)  

  DECR_SCALAR_OPS(output, int8)   
  DECR_SCALAR_OPS(output, uint8)  
  DECR_SCALAR_OPS(output, int16)  
  DECR_SCALAR_OPS(output, uint16) 
  DECR_SCALAR_OPS(output, int32)  
  DECR_SCALAR_OPS(output, uint32) 
  DECR_SCALAR_OPS(output, float)  
  DECR_SCALAR_OPS(output, int64)  
  DECR_SCALAR_OPS(output, uint64) 

  INCR_SCALAR_OPS(input, cint16)  
  INCR_SCALAR_OPS(input, cint32)  
#if __AIE_ARCH__<20
  INCR_SCALAR_OPS(input, cfloat)  
#endif

  INCR_SCALAR_OPS(output, cint16) 
  INCR_SCALAR_OPS(output, cint32) 
#if __AIE_ARCH__<20
  INCR_SCALAR_OPS(output, cfloat) 
#endif

  DECR_SCALAR_OPS(input, cint16)  
  DECR_SCALAR_OPS(input, cint32)  
#if __AIE_ARCH__<20
  DECR_SCALAR_OPS(input, cfloat)  
#endif

  DECR_SCALAR_OPS(output, cint16) 
  DECR_SCALAR_OPS(output, cint32) 
#if __AIE_ARCH__<20
  DECR_SCALAR_OPS(output, cfloat) 
#endif

#undef DECR_SCALAR_OPS
#undef INCR_SCALAR_OPS

#define INCR_VECTOR_OPS(direction, type, lanes)				      \
 static inline void window_incr_v ## lanes (direction ## _window_ ## type * w, int count) { \
    count *= lanes * sizeof(type) / sizeof(window_datatype);  						      \
    w->ptr = cyclic_add(w->ptr, count, w->buffer, w->size);             \
  }

#define DECR_VECTOR_OPS(direction, type, lanes)				      \
 static  inline void window_decr_v ## lanes (direction ## _window_ ## type * w, int count) { \
     window_incr_v ## lanes(w, -count);\
  }

#if __AIE_ARCH__<20
  // input/output [u]int64 v{4,8,16}
  // intput/output float   v{4,8,16,32}
  INCR_VECTOR_OPS(input, int64, 4)
  INCR_VECTOR_OPS(input, uint64, 4)
  INCR_VECTOR_OPS(input, float, 4)
  INCR_VECTOR_OPS(output, int64, 4)
  INCR_VECTOR_OPS(output, uint64, 4)
  INCR_VECTOR_OPS(output, float, 4)
  DECR_VECTOR_OPS(input, int64, 4)
  DECR_VECTOR_OPS(input, uint64, 4)
  DECR_VECTOR_OPS(input, float, 4)
  DECR_VECTOR_OPS(output, int64, 4)
  DECR_VECTOR_OPS(output, uint64, 4)
  DECR_VECTOR_OPS(output, float, 4)
  INCR_VECTOR_OPS(input, float, 8)
  INCR_VECTOR_OPS(input, int64, 8)
  INCR_VECTOR_OPS(input, uint64, 8)
  INCR_VECTOR_OPS(output, float, 8)
  INCR_VECTOR_OPS(output, int64, 8)
  INCR_VECTOR_OPS(output, uint64, 8)
  DECR_VECTOR_OPS(input, float, 8)
  DECR_VECTOR_OPS(input, int64, 8)
  DECR_VECTOR_OPS(input, uint64, 8)
  DECR_VECTOR_OPS(output, float, 8)
  DECR_VECTOR_OPS(output, int64, 8)
  DECR_VECTOR_OPS(output, uint64, 8)
  INCR_VECTOR_OPS(input, float,  16)
  INCR_VECTOR_OPS(input, int64, 16)
  INCR_VECTOR_OPS(input, uint64, 16)
  DECR_VECTOR_OPS(input, float,  16)
  DECR_VECTOR_OPS(input, int64,  16)
  DECR_VECTOR_OPS(input, uint64, 16)
  INCR_VECTOR_OPS(output, float,  16)
  INCR_VECTOR_OPS(output, int64, 16)
  INCR_VECTOR_OPS(output, uint64, 16)
  DECR_VECTOR_OPS(output, float,  16)
  DECR_VECTOR_OPS(output, int64, 16)
  DECR_VECTOR_OPS(output, uint64, 16)
  INCR_VECTOR_OPS(input, float,  32)
  DECR_VECTOR_OPS(input, float,  32)
  INCR_VECTOR_OPS(output, float,  32)
  DECR_VECTOR_OPS(output, float,  32)
#endif
  /* Handling 4 element vectors.  */
  INCR_VECTOR_OPS(input, int8, 4)    
  INCR_VECTOR_OPS(input, uint8, 4)   
  INCR_VECTOR_OPS(input, int16, 4)   
  INCR_VECTOR_OPS(input, uint16, 4)  
  INCR_VECTOR_OPS(input, int32, 4)   
  INCR_VECTOR_OPS(input, uint32, 4)  

  INCR_VECTOR_OPS(output, int8, 4)   
  INCR_VECTOR_OPS(output, uint8, 4)  
  INCR_VECTOR_OPS(output, int16, 4)  
  INCR_VECTOR_OPS(output, uint16, 4) 
  INCR_VECTOR_OPS(output, int32, 4)  
  INCR_VECTOR_OPS(output, uint32, 4) 

  DECR_VECTOR_OPS(input, int8, 4)   
  DECR_VECTOR_OPS(input, uint8, 4)  
  DECR_VECTOR_OPS(input, int16, 4)  
  DECR_VECTOR_OPS(input, uint16, 4) 
  DECR_VECTOR_OPS(input, int32, 4)  
  DECR_VECTOR_OPS(input, uint32, 4) 

  DECR_VECTOR_OPS(output, int8, 4)   
  DECR_VECTOR_OPS(output, uint8, 4)  
  DECR_VECTOR_OPS(output, int16, 4)  
  DECR_VECTOR_OPS(output, uint16, 4) 
  DECR_VECTOR_OPS(output, int32, 4)  
  DECR_VECTOR_OPS(output, uint32, 4) 

  /* Handling 8 element vectors. */
  INCR_VECTOR_OPS(input, int8,  8)   
  INCR_VECTOR_OPS(input, uint8, 8)   
  INCR_VECTOR_OPS(input, int16, 8)   
  INCR_VECTOR_OPS(input, uint16, 8)  
  INCR_VECTOR_OPS(input, int32, 8)   
  INCR_VECTOR_OPS(input, uint32, 8)  

 
  INCR_VECTOR_OPS(output, int8, 8)   
  INCR_VECTOR_OPS(output, uint8, 8)  
  INCR_VECTOR_OPS(output, int16, 8)  
  INCR_VECTOR_OPS(output, uint16, 8) 
  INCR_VECTOR_OPS(output, int32, 8)  
  INCR_VECTOR_OPS(output, uint32, 8) 

  DECR_VECTOR_OPS(input, int8, 8)    
  DECR_VECTOR_OPS(input, uint8, 8)   
  DECR_VECTOR_OPS(input, int16, 8)   
  DECR_VECTOR_OPS(input, uint16, 8)  
  DECR_VECTOR_OPS(input, int32, 8)   
  DECR_VECTOR_OPS(input, uint32, 8)  

  DECR_VECTOR_OPS(output, int8, 8)   
  DECR_VECTOR_OPS(output, uint8, 8)  
  DECR_VECTOR_OPS(output, int16, 8)  
  DECR_VECTOR_OPS(output, uint16, 8) 
  DECR_VECTOR_OPS(output, int32, 8)  
  DECR_VECTOR_OPS(output, uint32, 8) 


  /* Handling 16 element vectors.  */
  INCR_VECTOR_OPS(input, int8,  16)   
  INCR_VECTOR_OPS(input, uint8, 16)   
  INCR_VECTOR_OPS(input, int16,  16)  
  INCR_VECTOR_OPS(input, uint16, 16)  
  INCR_VECTOR_OPS(input, int32,  16)  
  INCR_VECTOR_OPS(input, uint32, 16)  

  DECR_VECTOR_OPS(input, int8,  16)   
  DECR_VECTOR_OPS(input, uint8, 16)   
  DECR_VECTOR_OPS(input, int16,  16)  
  DECR_VECTOR_OPS(input, uint16, 16)  
  DECR_VECTOR_OPS(input, int32,  16)  
  DECR_VECTOR_OPS(input, uint32, 16)  

 
  INCR_VECTOR_OPS(output, int8,  16)  
  INCR_VECTOR_OPS(output, uint8, 16)  
  INCR_VECTOR_OPS(output, int16,  16) 
  INCR_VECTOR_OPS(output, uint16, 16) 
  INCR_VECTOR_OPS(output, int32,  16) 
  INCR_VECTOR_OPS(output, uint32, 16) 

  DECR_VECTOR_OPS(output, int8,  16)  
  DECR_VECTOR_OPS(output, uint8, 16)  
  DECR_VECTOR_OPS(output, int16,  16) 
  DECR_VECTOR_OPS(output, uint16, 16) 
  DECR_VECTOR_OPS(output, int32,  16) 
  DECR_VECTOR_OPS(output, uint32, 16) 

  /* Handle 32 element vectors.  */
  INCR_VECTOR_OPS(input, int8,  32)   
  INCR_VECTOR_OPS(input, uint8, 32)   
  INCR_VECTOR_OPS(input, int16,  32)  
  INCR_VECTOR_OPS(input, uint16, 32)  
  INCR_VECTOR_OPS(input, int32,  32)  
  INCR_VECTOR_OPS(input, uint32, 32)  

  DECR_VECTOR_OPS(input, int8,  32)   
  DECR_VECTOR_OPS(input, uint8, 32)   
  DECR_VECTOR_OPS(input, int16,  32)  
  DECR_VECTOR_OPS(input, uint16, 32)  
  DECR_VECTOR_OPS(input, int32,  32)  
  DECR_VECTOR_OPS(input, uint32, 32)  

 
  INCR_VECTOR_OPS(output, int8,  32)  
  INCR_VECTOR_OPS(output, uint8, 32)  
  INCR_VECTOR_OPS(output, int16, 32)  
  INCR_VECTOR_OPS(output, uint16, 32) 
  INCR_VECTOR_OPS(output, int32,  32) 
  INCR_VECTOR_OPS(output, uint32, 32) 

  DECR_VECTOR_OPS(output, int8,  32)  
  DECR_VECTOR_OPS(output, uint8, 32)  
  DECR_VECTOR_OPS(output, int16,  32) 
  DECR_VECTOR_OPS(output, uint16, 32) 
  DECR_VECTOR_OPS(output, int32,  32) 
  DECR_VECTOR_OPS(output, uint32, 32) 

  /* Handles 64 element vectors.  */
  INCR_VECTOR_OPS(input, int8,  64)   
  INCR_VECTOR_OPS(input, uint8, 64)  
  INCR_VECTOR_OPS(input, uint8, 128)
  INCR_VECTOR_OPS(input, int8, 128) 
  INCR_VECTOR_OPS(input, int16,  64)  
  INCR_VECTOR_OPS(input, uint16, 64)  

  DECR_VECTOR_OPS(input, int8,  64)   
  DECR_VECTOR_OPS(input, uint8, 64)  
  DECR_VECTOR_OPS(input, uint8, 128)
  DECR_VECTOR_OPS(input, int8, 128) 
  DECR_VECTOR_OPS(input, int16,  64)  
  DECR_VECTOR_OPS(input, uint16, 64)  
 
  INCR_VECTOR_OPS(output, int8,  64)  
  INCR_VECTOR_OPS(output, uint8, 64) 
  INCR_VECTOR_OPS(output, uint8, 128)
  INCR_VECTOR_OPS(output, int8, 128) 
  INCR_VECTOR_OPS(output, int16, 64)  
  INCR_VECTOR_OPS(output, uint16, 64) 

  DECR_VECTOR_OPS(output, int8,  64)  
  DECR_VECTOR_OPS(output, uint8, 64) 
  DECR_VECTOR_OPS(output, uint8, 128)
  DECR_VECTOR_OPS(output, int8, 128) 
  DECR_VECTOR_OPS(output, int16,  64) 
  DECR_VECTOR_OPS(output, uint16, 64) 


  INCR_VECTOR_OPS(input, cint32, 4)  
#if __AIE_ARCH__<20
  INCR_VECTOR_OPS(input, cint16, 4)  
  INCR_VECTOR_OPS(input, cfloat, 4)  
#endif
  INCR_VECTOR_OPS(input, cint16, 8)  
  INCR_VECTOR_OPS(input, cint32, 8)  
  INCR_VECTOR_OPS(input, cint16, 16)  
#if __AIE_ARCH__<20
  INCR_VECTOR_OPS(input, cint32, 16)
  INCR_VECTOR_OPS(input, cint32, 2)
  INCR_VECTOR_OPS(input, cfloat, 16) 
  INCR_VECTOR_OPS(input, cfloat, 2)
  INCR_VECTOR_OPS(input, cfloat, 8) 
  INCR_VECTOR_OPS(input, cint16, 32)  
#endif

  INCR_VECTOR_OPS(output, cint32, 4)
  INCR_VECTOR_OPS(output, cint32, 8) 
#if __AIE_ARCH__<20
  INCR_VECTOR_OPS(output, cint16, 4) 
  INCR_VECTOR_OPS(output, cint32, 2)
  INCR_VECTOR_OPS(output, cfloat, 4) 
#endif
  INCR_VECTOR_OPS(output, cint16, 8) 
#if __AIE_ARCH__<20
  INCR_VECTOR_OPS(output, cfloat, 8)
  INCR_VECTOR_OPS(output, cfloat, 2)
#endif
  INCR_VECTOR_OPS(output, cint16, 16) 
#if __AIE_ARCH__<20
  INCR_VECTOR_OPS(output, cint32, 16) 
  INCR_VECTOR_OPS(output, cfloat, 16) 
  INCR_VECTOR_OPS(output, cint16, 32) 
#endif

  DECR_VECTOR_OPS(input, cint32, 4) 
#if __AIE_ARCH__<20
  DECR_VECTOR_OPS(input, cint16, 4) 
  DECR_VECTOR_OPS(input, cfloat, 4) 
#endif
  DECR_VECTOR_OPS(input, cint16, 8)  
  DECR_VECTOR_OPS(input, cint32, 8)  
  DECR_VECTOR_OPS(input, cint16, 16)  
#if __AIE_ARCH__<20
  DECR_VECTOR_OPS(input, cint32, 16) 
  DECR_VECTOR_OPS(input, cint32, 2)
  DECR_VECTOR_OPS(input, cfloat, 16) 
  DECR_VECTOR_OPS(input, cfloat, 2)
  DECR_VECTOR_OPS(input, cfloat, 8) 
  DECR_VECTOR_OPS(input, cint16, 32)  
#endif

  DECR_VECTOR_OPS(output, cint32, 4) 
#if __AIE_ARCH__<20
  DECR_VECTOR_OPS(output, cint16, 4) 
  DECR_VECTOR_OPS(output, cfloat, 4) 
#endif
  DECR_VECTOR_OPS(output, cint16, 8) 
  DECR_VECTOR_OPS(output, cint32, 8) 
#if __AIE_ARCH__<20
  DECR_VECTOR_OPS(output, cfloat, 8)
  DECR_VECTOR_OPS(output, cfloat, 2) 
#endif
  DECR_VECTOR_OPS(output, cint16, 16) 
#if __AIE_ARCH__<20
  DECR_VECTOR_OPS(output, cint32, 2)
  DECR_VECTOR_OPS(output, cfloat, 16) 
  DECR_VECTOR_OPS(output, cint16, 32)
#endif
  
#undef INCR_VECTOR_OPS
#undef DECR_VECTOR_OPS

// Scalar Read / Writes

#define SCALAR_OPS(scalartype)                   						\
  template <aie_dm_resource Resource = aie_dm_resource::none>                                   \
  static inline void window_write(output_window_ ## scalartype * w, scalartype value) {		\
    using T = aie_dm_resource_set_t<scalartype, Resource>;                                      \
    *((T* restrict)(w->ptr)) = value;	                                                        \
  }						                                                \
  template <aie_dm_resource Resource = aie_dm_resource::none>                                   \
  static inline void window_writeincr(output_window_ ## scalartype * w, scalartype value) {     \
    using T = aie_dm_resource_set_t<scalartype, Resource>;                                      \
    *((T* restrict)(w->ptr)) = value;                      	                                \
    window_incr(w,1);        	        	                                                \
  }                      									\
  template <aie_dm_resource Resource = aie_dm_resource::none>                                   \
  static inline scalartype window_read(input_window_ ## scalartype *w) {                        \
    using T = aie_dm_resource_set_t<scalartype, Resource>;                                      \
    return *((T* restrict)(w->ptr));          					                \
  } 						                         			\
  template <aie_dm_resource Resource = aie_dm_resource::none>                                   \
  static inline void window_read(input_window_ ## scalartype *w, scalartype & value) {          \
    using T = aie_dm_resource_set_t<scalartype, Resource>;                                      \
    value = *((T* restrict)(w->ptr));                  					\
  }                            									\
  template <aie_dm_resource Resource = aie_dm_resource::none>                                   \
  static inline void window_readincr(input_window_ ## scalartype *w, scalartype & value) {      \
    using T = aie_dm_resource_set_t<scalartype, Resource>;                                      \
    value = *((T* restrict)(w->ptr));						                \
    window_incr(w,1);                                                                           \
  }                                                                                             \
  template <aie_dm_resource Resource = aie_dm_resource::none>                                   \
  static inline scalartype window_readincr(input_window_ ## scalartype *w) {                    \
    scalartype  value;					                                 	\
    window_readincr<Resource>(w, value);					                \
    return value;                                                                               \
 } 

  SCALAR_OPS(int8)   // writes 1-bytes
  SCALAR_OPS(uint8)  // writes 1-bytes
  SCALAR_OPS(int16)  // writes 2-bytes
  SCALAR_OPS(uint16) // writes 2-bytes
  SCALAR_OPS(int32)  // writes 4-bytes
  SCALAR_OPS(uint32) // writes 4-bytes
  SCALAR_OPS(float)  // writes 4-bytes
  SCALAR_OPS(int64)  // writes 8-bytes
  SCALAR_OPS(uint64) // writes 8-bytes

  SCALAR_OPS(cint16) // writes 4-bytes
  SCALAR_OPS(cint32) // writes 8-bytes
#if __AIE_ARCH__<20
  SCALAR_OPS(cfloat) // writes 8-bytes
#endif

#undef SCALAR_OPS

// Vector Reads / Writes

#define VECTOR_OPS( type, lanes)                                   					\
  template <aie_dm_resource Resource = aie_dm_resource::none>                                           \
  static inline void window_write(output_window_ ## type * w, v ## lanes ## type  value) {		\
    X86SIM_CHECK_PTR_ALIGNMENT(w->ptr, __FUNCTION__);                                                   \
    using T = aie_dm_resource_set_t<v ## lanes ## type, Resource>;                                      \
    *((T* restrict)(w->ptr)) = value;			                                                \
  }                                                                                                     \
  template <aie_dm_resource Resource = aie_dm_resource::none>                                           \
  static inline void window_write(window_internal * w, v ## lanes ## type  value) {	   	        \
    X86SIM_CHECK_PTR_ALIGNMENT(w->head, __FUNCTION__);                                                  \
    using T = aie_dm_resource_set_t<v ## lanes ## type, Resource>;                                      \
    *((T* restrict)(w->head)) = value;               				       	                \
  }						                            			        \
  template <aie_dm_resource Resource = aie_dm_resource::none>                                           \
  static inline void window_writeincr(output_window_ ## type *w, v ## lanes ## type  value) {           \
    X86SIM_CHECK_PTR_ALIGNMENT(w->ptr, __FUNCTION__);                                                   \
    using T = aie_dm_resource_set_t<v ## lanes ## type, Resource>;                                      \
    *((T* restrict)(w->ptr)) = value;                       				                \
     window_incr_v ## lanes (w,1);                    					              	\
  }			     							                        \
  template <aie_dm_resource Resource = aie_dm_resource::none>                                           \
  static inline void window_read(input_window_ ## type * w, v ## lanes ## type & value ) {              \
    X86SIM_CHECK_PTR_ALIGNMENT(w->ptr, __FUNCTION__);                                                   \
    using T = aie_dm_resource_set_t<v ## lanes ## type, Resource>;                                      \
    value = *((T* restrict)(w->ptr));                        				                \
  }									                                \
  template <aie_dm_resource Resource = aie_dm_resource::none>                                           \
  static inline void window_read(window_internal * w, v ## lanes ## type & value ) {                    \
    X86SIM_CHECK_PTR_ALIGNMENT(w->head, __FUNCTION__);                                                  \
    using T = aie_dm_resource_set_t<v ## lanes ## type, Resource>;                                      \
    value = *((T* restrict)(w->head));                       				                \
  }                                                                                                     \
  template <aie_dm_resource Resource = aie_dm_resource::none>                                           \
  static inline v ## lanes ## type window_read_v ## lanes (input_window_ ## type * w) {                 \
    X86SIM_CHECK_PTR_ALIGNMENT(w->ptr, __FUNCTION__);                                                   \
    using T = aie_dm_resource_set_t<v ## lanes ## type, Resource>;                                      \
    v ## lanes ## type aux = *((T* restrict)(w->ptr));                                                  \
    return aux;                                                                                         \
  }                                                                                                     \
  template <aie_dm_resource Resource = aie_dm_resource::none>                                           \
  static inline void window_readincr(input_window_ ## type *w, v ## lanes ## type & value) {            \
    X86SIM_CHECK_PTR_ALIGNMENT(w->ptr, __FUNCTION__);                                                   \
    using T = aie_dm_resource_set_t<v ## lanes ## type, Resource>;                                      \
    value = *((T* restrict)(w->ptr));                        				                \
    window_incr_v ## lanes (w, 1);							                \
  }                                                                                                     \
  template <aie_dm_resource Resource = aie_dm_resource::none>                                           \
  static inline v ## lanes ## type window_readincr_v ## lanes (input_window_ ## type * w) {             \
    X86SIM_CHECK_PTR_ALIGNMENT(w->ptr, __FUNCTION__);                                                   \
    using T = aie_dm_resource_set_t<v ## lanes ## type, Resource>;                                      \
    v ## lanes ## type aux = *((T* restrict)(w->ptr));                                                  \
    int count = lanes * sizeof(type) / sizeof(window_datatype);  					\
    w->ptr = cyclic_add(w->ptr, count, w->buffer, w->size);                                             \
    return aux;                                                                                         \
  }                                                                                                     \
  template <aie_dm_resource Resource = aie_dm_resource::none>                                           \
  static inline void window_readdecr(input_window_ ## type *w, v ## lanes ## type & value) {            \
    X86SIM_CHECK_PTR_ALIGNMENT(w->ptr, __FUNCTION__);                                                   \
    using T = aie_dm_resource_set_t<v ## lanes ## type, Resource>;                                      \
    value = *((T* restrict)(w->ptr));                        				                \
    window_decr_v ## lanes (w, 1);							                \
  }                      									        \
  template <aie_dm_resource Resource = aie_dm_resource::none>                                           \
  static inline v ## lanes ## type window_readdecr_v ## lanes (input_window_ ## type * w) {             \
    X86SIM_CHECK_PTR_ALIGNMENT(w->ptr, __FUNCTION__);                                                   \
    using T = aie_dm_resource_set_t<v ## lanes ## type, Resource>;                                      \
    v ## lanes ## type aux = *((T* restrict)(w->ptr));                                                  \
    int count = lanes * sizeof(type) / sizeof(window_datatype);  					\
    w->ptr = cyclic_add(w->ptr, -count, w->buffer, w->size);                                            \
    return aux;                                                                                         \
  }                                                                                                     

#if __AIE_ARCH__>=20
/* 128-bit ops */
  VECTOR_OPS(uint16, 8)
  VECTOR_OPS(uint32, 4)

/* 256-bit ops */
  VECTOR_OPS(uint16, 16)
  VECTOR_OPS(uint32, 8)

/* 512-bit ops */
  VECTOR_OPS(uint16, 32)
  VECTOR_OPS(uint32, 16)

/* 1024-bit ops */
  VECTOR_OPS(uint16, 64)
  VECTOR_OPS(uint32, 32)
#else
  VECTOR_OPS(float, 4)
//  VECTOR_OPS(int64, 2)

  VECTOR_OPS(float, 8)
  VECTOR_OPS(int64, 4)

  VECTOR_OPS(float, 16)
  VECTOR_OPS(int64, 8)

  VECTOR_OPS(float, 32)
//  VECTOR_OPS(int64, 16)
#endif

/* 128-bit ops */
  VECTOR_OPS(int32, 4)
  VECTOR_OPS(int16, 8)
  VECTOR_OPS(int8, 16)
  VECTOR_OPS(uint8, 16)

/* 256-bit ops */
  VECTOR_OPS(int32, 8)
  VECTOR_OPS(int16, 16)
  VECTOR_OPS(int8, 32)
  VECTOR_OPS(uint8,32)

/* 512-bit ops */
  VECTOR_OPS(int32, 16)
  VECTOR_OPS(int16,32)
  VECTOR_OPS(int8,64)
  VECTOR_OPS(uint8,64)

/* 1024-bit ops */
  VECTOR_OPS(int32,32)
  VECTOR_OPS(int16,64)
  VECTOR_OPS(uint8, 128)
  VECTOR_OPS(int8, 128)
 
  VECTOR_OPS(cint32, 4)
#if __AIE_ARCH__<20
  VECTOR_OPS(cint16, 4)
  VECTOR_OPS(cfloat, 4)
#endif
  VECTOR_OPS(cint16, 8)
  VECTOR_OPS(cint16, 16)
#if __AIE_ARCH__<20
  VECTOR_OPS(cint32, 16)
  VECTOR_OPS(cfloat, 16)
#endif
  VECTOR_OPS(cint32, 8)
#if __AIE_ARCH__<20
  VECTOR_OPS(cint16, 32)
  VECTOR_OPS(cfloat, 2)
  VECTOR_OPS(cfloat, 8)
  VECTOR_OPS(cint32, 2)
#endif

#undef VECTOR_OPS

// window_bypass_copy(...) defined in window_interanal.h
// window_margin_copy(...) defined in window_internal.h

static inline void window_acquire(window_internal* w) {

 /* Currently window_acquire without Lock Type is a nop.
  * This API is generated to make consistencies with lock
  * decided by interposer. Ports without locks decided by
  * interposer should be called with this API to make
  * consistencies with lock acquired by ports.
  */
}

static inline void window_release(window_internal* w) {
    
 /* Currently window_release without Lock Type is a nop.
  * This API is generated to make consistencies with lock
  * decided by interposer. Ports without locks decided by
  * interposer should be called with this API to make
  * consistencies with lock acquired by ports.
  */
}

#ifdef __X86SIM__
namespace x86sim {
    void windowAcquire(window_internal* w, int type);
    void windowRelease(window_internal* w, int type);
}

#undef ACQREL_OPS

#define ACQREL_OPS(scalartype)					      \
  static inline void window_acquire(input_window_ ## scalartype* w) { \
      x86sim::windowAcquire((window_internal*) w, FOR_READ);\
  }\
  static inline void window_release(input_window_ ## scalartype* w) {	\
      x86sim::windowRelease((window_internal*) w, FOR_WRITE);\
  }\
  static inline void window_acquire(output_window_ ## scalartype* w) {	\
      x86sim::windowAcquire((window_internal*) w, FOR_WRITE);\
  } \
  static inline void window_release(output_window_ ## scalartype* w) {	\
      x86sim::windowRelease((window_internal*) w, FOR_READ);\
  }

ACQREL_OPS(int8)
ACQREL_OPS(uint8)
ACQREL_OPS(int16)
ACQREL_OPS(uint16)
ACQREL_OPS(int32)
ACQREL_OPS(uint32)
ACQREL_OPS(int64)
ACQREL_OPS(uint64)
ACQREL_OPS(float)

ACQREL_OPS(cint16)
ACQREL_OPS(cint32)
#if __AIE_ARCH__<20
ACQREL_OPS(cfloat)
#endif // if __AIE_ARCH__<20

#undef ACQREL_OPS


#else // ! __X86SIM__
static inline void adjustPingPongBuffer(window_internal* w,
		window_datatype * restrict ping_buffer,
                                  window_datatype * restrict pong_buffer,
                                  const int margin,
                                  const int index)
{
//    window_datatype *restrict h1 = ((1-index) ?   pong_buffer : ping_buffer) + margin;
//    h1 = w->head;
    w->buffer = index ? pong_buffer : ping_buffer;
    w->head =   (index ? pong_buffer  : ping_buffer ) + margin;
}

static inline void window_acquire(window_internal* w, 
                                  unsigned int ping_lockid,
                                  unsigned int pong_lockid,
                                  window_datatype * restrict ping_buffer,
                                  window_datatype * restrict pong_buffer,
                                  const int margin, 
                                  const int index,
                                  int type)
{
    // if (w->is_pingpong) {
    //   w->buffer = w->buffers[w->current_bufid];
    //   w->head = w->heads[w->current_bufid];
    //   w->lockid = w->lockids[w->current_bufid];
    // }
    // Below is the shortcut for the above, since w->is_pingpong is 0 or 1, 
    // and the answer is 0 for the former case, while it is w->current_bufid for the latter case:
    //acquire(w->lockids[w->is_pingpong & w->current_bufid],type);
    w->buffer = index ? pong_buffer : ping_buffer; 
    w->head =   (index ? pong_buffer  : ping_buffer ) + margin;
    //w->ptr =   index ? w->heads[1] : w->heads[0];
    //w->ptr = w->head; 
    //int lockid =  index ? w->lockids[1] : w->lockids[0];
#if (__AIE_ARCH__>=20)
    if (type == ACQ_WRITE)
        acquire_greater_equal(ping_lockid, 1);
    else
        acquire_greater_equal(pong_lockid, 1);
#else
    int lockid = index ? pong_lockid : ping_lockid;
    acquire(lockid, type);
#endif
}

static inline void window_release(window_internal* w, 
                                  unsigned int ping_lockid,
                                  unsigned int pong_lockid,
                                  window_datatype * restrict ping_buffer,
                                  window_datatype * restrict pong_buffer,
                                  const int margin,
                                  const int index,
                                  int type)
{
  // TBD: Pull margin copy code inside this function.
  //release(w->lockid, type);
  // w->current_bufid = w->is_pingpong ? (1 - w->current_bufid) : w->current_bufid;
  // Below is the shortcut for the above, since w->is_pingpong is 0 or 1, 
  // and w->current_bufid stays 0 for the former case, while it toggles for the latter case:
  
  //Making nested scope to allow assignment to restrict pointer
//    window_datatype *restrict h1 = (index ? pong_buffer : ping_buffer) + margin;
//    h1 = w->head;
//    int lockid =  index ? pong_lockid : ping_lockid ;//w->lockids[1] : w->lockids[0];
#if (__AIE_ARCH__>=20)
    if (type == REL_WRITE)
        release(ping_lockid, 1);
    else
        release(pong_lockid, 1);
#else
    int lockid =  index ? pong_lockid : ping_lockid ;//w->lockids[1] : w->lockids[0];
    release(lockid, type);
#endif
}

template<typename tpDataType>
static inline std::enable_if_t< is_window_data_type< tpDataType >::value >
window_acquire(input_window<tpDataType> *w)
{
    w->buffer = (window_datatype * __restrict)select(w->current_bufid , w->buffers[1], w->buffers[0]);
    w->head = w->ptr =  (window_datatype * __restrict)select(w->current_bufid , w->heads[1], w->heads[0]);
#if (__AIE_ARCH__>=20)
    acquire_greater_equal(w->lockids[1], 1);
#else
    int lockid =  select(w->current_bufid , w->lockids[1] , w->lockids[0]);
    acquire(lockid, ACQ_READ);
#endif
}

template<typename tpDataType>
static inline std::enable_if_t< is_window_data_type< tpDataType >::value >
window_release(input_window<tpDataType> *w)
{
#if (__AIE_ARCH__>=20)
    release(w->lockids[0], 1);
#else
    int lockid =  select(w->current_bufid , w->lockids[1] , w->lockids[0]);
    release(lockid, REL_WRITE);
#endif
    w->heads[w->current_bufid] = w->head;
    w->current_bufid = select((w->heads[1] == 0) , w->current_bufid , 1 - w->current_bufid);
}

template<typename tpDataType>
static inline std::enable_if_t< is_window_data_type< tpDataType >::value >
window_acquire(output_window<tpDataType> *w)
{
    w->buffer = (window_datatype * __restrict)select(w->current_bufid , w->buffers[1], w->buffers[0]);
    w->head = w->ptr =  (window_datatype * __restrict)select(w->current_bufid , w->heads[1], w->heads[0]);
#if (__AIE_ARCH__>=20)
    acquire_greater_equal(w->lockids[0], 1);
#else
    int lockid =  select(w->current_bufid , w->lockids[1] , w->lockids[0]);
    acquire(lockid, ACQ_WRITE);
#endif
}

template<typename tpDataType>
static inline std::enable_if_t< is_window_data_type< tpDataType >::value >
window_release(output_window<tpDataType> *w)
{
#if (__AIE_ARCH__>=20)
    release(w->lockids[1], 1);
#else
    int lockid =  select(w->current_bufid , w->lockids[1] , w->lockids[0]);
    release(lockid, REL_READ);
#endif
    w->heads[w->current_bufid] = w->head;
    w->current_bufid = select((w->heads[1] == 0) , w->current_bufid , 1 - w->current_bufid);
}

// optimized APIs

template<typename tpDataType>
static inline std::enable_if_t< is_window_data_type< tpDataType >::value >
window_acquire(input_window<tpDataType> *w,
               int const id,
               unsigned int const ping_lockid,
               unsigned int const pong_lockid,
               window_datatype *restrict ping_buffer,
               window_datatype  *restrict pong_buffer,
               bool const &isbufferHeadNotRequired = 0)
{
    if (isbufferHeadNotRequired)
        w->ptr =  (id ? pong_buffer : ping_buffer);
    else {
        w->ptr =  (id ? pong_buffer : ping_buffer);
        w->head =  (id ? pong_buffer : ping_buffer);
        w->buffer =  (id? pong_buffer : ping_buffer);
    }
#if (__AIE_ARCH__>=20)
    acquire_greater_equal(w->lockids[1], 1);
#else
    int lockid =  w->current_bufid ? w->lockids[1] : w->lockids[0];
    acquire(lockid, ACQ_READ);
#endif
}

template<typename tpDataType>
static inline std::enable_if_t< is_window_data_type< tpDataType >::value >
window_release(input_window<tpDataType> *w,
               int const id,
               unsigned int const ping_lockid,
               unsigned int const pong_lockid,
               window_datatype *restrict ping_buffer,
               window_datatype  *restrict pong_buffer,
               bool const &isbufferHeadNotRequired = 0)
{
    if (!isbufferHeadNotRequired)
    {
        window_datatype *restrict h1 = (id ? pong_buffer : ping_buffer);
        w->head = h1;
    }
#if (__AIE_ARCH__>=20)
    release(w->lockids[0], 1);
#else
    int lockid =  w->current_bufid ? w->lockids[1] : w->lockids[0];
    release(lockid, REL_WRITE);
#endif
}

template<typename tpDataType>
static inline std::enable_if_t< is_window_data_type< tpDataType >::value >
window_acquire(output_window<tpDataType> *w,
               int const id,
               unsigned int const ping_lockid,
               unsigned int const pong_lockid,
               window_datatype *restrict ping_buffer,
               window_datatype  *restrict pong_buffer,
               bool const &isbufferHeadNotRequired = 0)
{
    if (isbufferHeadNotRequired)
        w->ptr =  (id ? pong_buffer : ping_buffer);
    else
    {
        w->ptr =  (id ? pong_buffer : ping_buffer);
        w->head =  (id ? pong_buffer : ping_buffer);
        w->buffer =  (id ? pong_buffer : ping_buffer);
    }
#if (__AIE_ARCH__>=20)
    acquire_greater_equal(w->lockids[0], 1);
#else
    int lockid =  w->current_bufid ? w->lockids[1] : w->lockids[0];
    acquire(lockid, ACQ_WRITE);
#endif
}

template<typename tpDataType>
static inline std::enable_if_t< is_window_data_type< tpDataType >::value >
window_release(output_window<tpDataType> *w,
               int const id,
               unsigned int const ping_lockid,
               unsigned int const pong_lockid,
               window_datatype *restrict ping_buffer,
               window_datatype  *restrict pong_buffer,
               bool const &isbufferHeadNotRequired = 0)
{
    if (!isbufferHeadNotRequired)
    {
        window_datatype *restrict h1 = (id ? pong_buffer : ping_buffer); 
        w->head = h1;
    }
#if (__AIE_ARCH__>=20)
    release(w->lockids[1], 1);
#else
    int lockid =  w->current_bufid ? w->lockids[1] : w->lockids[0];
    release(lockid, REL_READ);
#endif
}


#endif  // ifdef __X86SIM__
 


template<typename T> static inline input_window<T> * get_input_async_window(window_internal * wind) { input_window<T> * toReturn = (input_window<T> *)wind; return toReturn; }
template<typename T> static inline output_window<T> * get_output_async_window(window_internal * wind) { output_window<T> * toReturn = (output_window<T> *)wind; return toReturn; }

template<typename T> static inline input_window<T> * get_input_window(window_internal * wind) { input_window<T> * toReturn = (input_window<T> *)wind; toReturn->ptr = wind->head; return toReturn; }
template<typename T> static inline output_window<T> * get_output_window(window_internal * wind) { output_window<T> * toReturn = (output_window<T> *)wind; toReturn->ptr = wind->head; return toReturn; }

template<typename T> static inline void window_copy(input_window<T> *dst, input_window<T> *src) { dst->ptr = chess_copy(src->ptr); dst->head = chess_copy(src->head); dst->buffer = chess_copy(src->buffer); dst->size = chess_copy(src->size); dst->winsize = chess_copy(src->winsize); }
template<typename T> static inline void window_copy(output_window<T> *dst, output_window<T> *src) { dst->ptr = chess_copy(src->ptr); dst->head = chess_copy(src->head); dst->buffer = chess_copy(src->buffer); dst->size = chess_copy(src->size); dst->winsize = chess_copy(src->winsize); }

template<typename T> static inline void window_init(window_internal *w, int const channels, T *buffer_ping, unsigned int lockid_ping, T *buffer_pong, unsigned int lockid_pong, int const size, int const winsize) { int s = (sizeof(T)) / sizeof(window_datatype); int const sz = (size * s); int const winsz = (winsize * s); window_init(w, channels, (window_datatype *)buffer_ping, lockid_ping, (window_datatype *)buffer_pong, lockid_pong, sz, winsz); }
template<typename T> static inline void window_init(window_internal *w, int const channels, T *buffer_ping, unsigned int lockid_ping, T *buffer_pong, unsigned int lockid_pong, int const size) { int const sz = (size * sizeof(T)) / sizeof(window_datatype); window_init(w, channels, buffer_ping, lockid_ping, buffer_pong, lockid_pong, sz, sz); }
template<typename T> static inline void window_init(window_internal *w, int const channels, T *buffer_ping, int const size, int const winsize) { int s = (sizeof(T)) / sizeof(window_datatype); int const sz = (size *s); int const winsz = (winsize * s); window_init(w, channels, (window_datatype *)buffer_ping, 0, (window_datatype *)buffer_ping, 0, sz, winsz); }
template<typename T> static inline void window_init(window_internal *w, int const channels, T *buffer_ping, int const size) { int const sz = (size * sizeof(T)) / sizeof(window_datatype); window_init(w, channels, (window_datatype *)buffer_ping, 0, (window_datatype *)buffer_ping, 0, sz, sz); }

template<typename T> static inline void set_window_size(input_window<T> *w, int const size) { set_window_size((window_internal *)w, size*(sizeof(T) / sizeof(window_datatype))); }
template<typename T> static inline void set_window_size(output_window<T> *w, int const size) { set_window_size((window_internal *)w, size*(sizeof(T) / sizeof(window_datatype))); }
template<typename T> static inline unsigned window_size(input_window<T> *w) { return window_size((window_internal *)w) / (sizeof(T) / sizeof(window_datatype)); }
template<typename T> static inline unsigned window_size(output_window<T> *w) { return window_size((window_internal *)w) / (sizeof(T) / sizeof(window_datatype)); }

template<typename T> static inline void window_incr(window_internal * w, int count) { count *= sizeof(T) / sizeof(window_datatype); w->head = cyclic_add(w->head, count, w->buffer, w->size); }
template<typename T> static inline void window_decr(window_internal * w, int count) { window_incr<T>(w, -count); }

template<typename T> static inline void window_incr(input_window<T> * w, int count) { count *= sizeof(T) / sizeof(window_datatype); w->ptr = cyclic_add(w->ptr, count, w->buffer, w->size); }
template<typename T> static inline void window_incr(output_window<T> * w, int count) { count *= sizeof(T) / sizeof(window_datatype); w->ptr = cyclic_add(w->ptr, count, w->buffer, w->size); }
template<typename T> static inline void window_decr(input_window<T> * w, int count) { window_incr(w, -count); }
template<typename T> static inline void window_decr(output_window<T> * w, int count) { window_incr(w, -count); }

template<size_t N, typename T> static inline void window_incr_v(input_window<T> * w, int count) { count *= N * sizeof(T) / sizeof(window_datatype); w->ptr = cyclic_add(w->ptr, count, w->buffer, w->size); }
template<size_t N, typename T> static inline void window_incr_v(output_window<T> * w, int count) { count *= N * sizeof(T) / sizeof(window_datatype); w->ptr = cyclic_add(w->ptr, count, w->buffer, w->size); }
template<size_t N, typename T> static inline void window_decr_v(input_window<T> * w, int count) { window_incr_v<N>(w, -count); }
template<size_t N, typename T> static inline void window_decr_v(output_window<T> * w, int count) { window_incr_v<N>(w, -count); }

template<typename T> static inline void window_write(output_window<T> * w, T value) { *((T *)(w->ptr)) = value; }
template<typename T> static inline void window_writeincr(output_window<T> * w, T value) { *((T *)(w->ptr)) = value; window_incr(w, 1); }
template<typename T> static inline T window_read(input_window<T> *w) { return *((T *)(w->ptr)); }
template<typename T> static inline void window_read(input_window<T> *w, T & value) { value = *((T *)(w->ptr)); }
template<typename T> static inline void window_readincr(input_window<T> *w, T & value) { value = *((T *)(w->ptr)); window_incr(w, 1); }
template<typename T> static inline T window_readincr(input_window<T> *w) { T value; window_readincr(w, value); return value; }

//vector operations of window_write, window_writeincr, window_read, window_readincr are implemented using macro as overloaded functions.
//The templated vector operations do not work because the function signature overlapped with scalar operations.
//e.g., window_writeincr<output_window_<int16>*, int32> is not allowed for scalar operation but vector function signature, window_writeincr(output_window_<T> *w, vNT value), makes it allowed, which causes incorrect behavior.


#endif
