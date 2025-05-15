// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef __X86SIM_INCLUDE_STREAM_UTILS_H__
#define __X86SIM_INCLUDE_STREAM_UTILS_H__

#if defined(__X86SIM__) && __AIE_ARCH__<20
typedef v8float v8accfloat;
typedef v4cfloat v4caccfloat ;
#endif

namespace x86sim {

// Needed for aie::vector to work
template <typename T,typename... Types>
static constexpr bool is_convertible_to_one_of = (... || 
                       std::is_convertible_v<T, Types>);

template <typename T,typename... Types>
static constexpr bool is_one_of = (... || std::is_same_v<T, Types>);

#if __AIE_ARCH__<20

template<typename Ty>
static constexpr bool is_acc_data_type = is_convertible_to_one_of <Ty, 
                      v8acc48, v4cacc48, v4acc80, v2cacc80 >;

template<typename Ty>
static constexpr bool is_256bit_stream_data_type = is_convertible_to_one_of <Ty,
                      v32int8, v32uint8, v16int16, v8cint16, v8int32, v4cint32, 
                      v8float, v4cfloat >;

template<typename Ty>
static constexpr bool is_32bit_stream_data_type = is_convertible_to_one_of <Ty,
                      int32, uint32, float >;

template<typename Ty>
static constexpr bool is_128bit_stream_data_type = is_convertible_to_one_of <Ty,
                      v4cint16, v2cint32, v4float, v2cfloat, v4int32, v16int8, 
                      v8int16 >;

#endif // #if __AIE_ARCH__<20

#if __AIE_ARCH__>=20

template<typename Ty>
static constexpr bool is_32bit_stream_data_type = is_convertible_to_one_of <Ty, 
                      int, unsigned int, float, v8int4, v8uint4, v4int8, 
                      v4uint8, v2int16, v2uint16, cint16, v2bfloat16 >;

template<typename Ty>
static constexpr bool is_128bit_stream_data_type = is_convertible_to_one_of <Ty,
                      v4int32, v32int4, v32uint4, v16int8, v16uint8, v8int16, 
                      v8uint16, v4cint16, v4uint32, v2cint32, v8bfloat16, v4float
#if __AIE_ARCH__ == 20
                      , v2cfloat
#endif
                      >;

template<typename Ty>
static constexpr bool is_256bit_stream_data_type = is_convertible_to_one_of <Ty,
                      v8int32, v64int4, v64uint4, v32int8, v32uint8, v16int16, 
                      v16uint16, v8cint16, v8uint32, v4cint32, v16bfloat16, v8float
#if __AIE_ARCH__ == 20
                      , v4cfloat
#endif
                      >;

template<typename Ty>
static constexpr bool is_512bit_stream_data_type = is_convertible_to_one_of <Ty, 
                      v16int32, v128int4, v128uint4, v64int8, v64uint8, v32int16, 
                      v32uint16, v16cint16, v16uint32, v8cint32, v32bfloat16, v16float
#if __AIE_ARCH__ == 20
                      , v8cfloat
#endif
                      >;

template<typename Ty>
static constexpr bool is_1024bit_stream_data_type = is_convertible_to_one_of <Ty,
                      v32int32, v256int4, v256uint4, v128int8, v128uint8, 
                      v64int16, v64uint16, v32cint16, v32uint32, v16cint32, 
                      v64bfloat16, v32float
#if __AIE_ARCH__ == 20
                      , v16cfloat
#endif
                      >;

template<typename Ty>
static constexpr bool is_512bit_acc_data_type = is_convertible_to_one_of <Ty,
                      v16acc32, v8acc64, v4cacc64, v16accfloat, v128int4, 
                      v128uint4, v64int8, v64uint8, v32int16, v32uint16, 
                      v16cint16, v16int32, v16uint32, v8cint32, v32bfloat16 
#if __AIE_ARCH__ == 20
                      , v8cfloat, v8caccfloat
#endif // #if __AIE_ARCH__ == 20
#if __AIE_ARCH__ == 22
                      , v32float16, v64bfloat8, v64float8
#endif
                      > && sizeof(Ty) == 64;

template<typename Ty>
static constexpr bool is_1024bit_acc_data_type = is_convertible_to_one_of <Ty,
                      v32acc32, v16acc64, v8cacc64, v32accfloat, v256int4, 
                      v256uint4, v128int8, v128uint8, v64int16, v64uint16, 
                      v32cint16, v32int32, v32uint32, v16cint32
#if __AIE_ARCH__ == 20
                      , v16cfloat, v16caccfloat
#endif // #if __AIE_ARCH__ == 20
                      > && sizeof(Ty) == 128;

#endif // #if __AIE_ARCH__ >= 20

#if __AIE_ARCH__ > 20
template<typename Ty>
static constexpr bool is_2048bit_acc_data_type = is_convertible_to_one_of <Ty,
                      v64acc32, v64accfloat, v32acc64, v16cacc64
                      > && sizeof(Ty) == 256;
#endif // #if __AIE_ARCH__ > 20

template<typename T, typename V>
static constexpr bool is_valid_vector_acc_data_type = (
#if __AIE_ARCH__<20
                  (std::is_same_v<T, acc48> && std::is_convertible_v<V, v8acc48>) ||
                  (std::is_same_v<T, cacc48> && std::is_convertible_v<V, v4cacc48>) ||
                  (std::is_same_v<T, acc80> && std::is_convertible_v<V, v4acc80>) ||
                  (std::is_same_v<T, cacc80> && std::is_convertible_v<V, v2cacc80>) ||
                  (std::is_same_v<T, accfloat> && std::is_convertible_v<V, v8accfloat>) ||
                  (std::is_same_v<T, caccfloat> && std::is_convertible_v<V, v4caccfloat>) ||
                  (std::is_same_v<T, int8> && std::is_convertible_v<V, v32int8>) ||
                  (std::is_same_v<T, uint8> && std::is_convertible_v<V, v32uint8>) ||
                  (std::is_same_v<T, int16> && std::is_convertible_v<V, v16int16>) ||
                  (std::is_same_v<T, cint16> && std::is_convertible_v<V, v8cint16>) ||
                  (std::is_same_v<T, int32> && std::is_convertible_v<V, v8int32>) ||
                  (std::is_same_v<T, cint32> && std::is_convertible_v<V, v4cint32>) ||
                  (std::is_same_v<T, cfloat> && std::is_convertible_v<V, v4cfloat>) ||
                  (std::is_same_v<T, float> && std::is_convertible_v<V, v8float>) 
#else // #if __AIE_ARCH__>=20
                  (std::is_same_v<T, acc32> && std::is_convertible_v<V, v32acc32>) ||
                  (std::is_same_v<T, acc32> && std::is_convertible_v<V, v16acc32>) ||
                  (std::is_same_v<T, acc64> && std::is_convertible_v<V, v16acc64>) ||
                  (std::is_same_v<T, accfloat> && std::is_convertible_v<V, v16accfloat>) ||
                  (std::is_same_v<T, acc64> && std::is_convertible_v<V, v8acc64>) ||
                  (std::is_same_v<T, cacc64> && std::is_convertible_v<V, v8cacc64>) ||
                  (std::is_same_v<T, cacc64> && std::is_convertible_v<V, v4cacc64>) ||

                  (std::is_same_v<T, int4> && std::is_convertible_v<V, v128int4>) ||
                  (std::is_same_v<T, uint4> && std::is_convertible_v<V, v128uint4>) ||
 
                  (std::is_same_v<T, cint16> && std::is_convertible_v<V, v16cint16>) ||
                  (std::is_same_v<T, cint32> && std::is_convertible_v<V, v16cint32>) ||
                  (std::is_same_v<T, int32> && std::is_convertible_v<V, v16int32>) ||
                  (std::is_same_v<T, uint32> && std::is_convertible_v<V, v16uint32>) ||
 
                  (std::is_same_v<T, cint32> && std::is_convertible_v<V, v8cint32>) ||
 
                  (std::is_same_v<T, bfloat16> && std::is_convertible_v<V, v32bfloat16>) ||
                  (std::is_same_v<T, cint16> && std::is_convertible_v<V, v32cint16>) ||
                  (std::is_same_v<T, int16> && std::is_convertible_v<V, v32int16>) ||
                  (std::is_same_v<T, uint16> && std::is_convertible_v<V, v32uint16>) ||
                  (std::is_same_v<T, int32> && std::is_convertible_v<V, v32int32>) ||
                  (std::is_same_v<T, uint32> && std::is_convertible_v<V, v32uint32>) ||
 
                  (std::is_same_v<T, int16> && std::is_convertible_v<V, v64int16>) ||
                  (std::is_same_v<T, uint16> && std::is_convertible_v<V, v64uint16>) ||
                  (std::is_same_v<T, int8> && std::is_convertible_v<V, v64int8>) ||
                  (std::is_same_v<T, uint8> && std::is_convertible_v<V, v64uint8>) 
                    #if __AIE_ARCH__ == 20
                   || (std::is_same_v<T, caccfloat> && std::is_convertible_v<V, v8caccfloat>)
                    #endif // #if __AIE_ARCH__ == 20 
#endif
);

} // namespace x86sim

#endif //__X86SIM_INCLUDE_STREAM_UTILS_H__


