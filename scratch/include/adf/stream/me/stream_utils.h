// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef __STREAM_ME_STREAM_UTILS_H__
#define __STREAM_ME_STREAM_UTILS_H__

namespace stream_utils {

template <typename T,typename... Types>
static constexpr bool is_one_of = (... || std::is_same_v<T, Types>);

template <typename T>
static constexpr unsigned type_bits_value = sizeof(T) * 8;

#if __AIE_ARCH__<20
template <typename T>
struct aie_stream_resource {
    static constexpr bool is_in_a = 
        (aie_stream_resource_in_get_v<T> == aie_stream_resource_in::a);
    
    static constexpr bool is_in_b = 
        (aie_stream_resource_in_get_v<T> == aie_stream_resource_in::b);
    
    static constexpr bool is_out_a = 
        (aie_stream_resource_out_get_v<T> == aie_stream_resource_out::a);
    
    static constexpr bool is_out_b = 
        (aie_stream_resource_out_get_v<T> == aie_stream_resource_out::b);
};
 
template <typename T>
static constexpr bool is_valid_type = is_one_of<T, int8, int16, int32, float,
                                                int64, uint8, uint16, uint32,
                                             uint64, cint16, cint32, cfloat>;

template <typename T>
static constexpr bool is_complex = is_one_of<T, cint16, cint32, cfloat>;

template <typename T>
static constexpr bool is_cfloat = is_one_of<T, cfloat>;

template <typename T>
static constexpr bool is_valid_acc_type = is_one_of<T, acc48, acc80, accfloat,
                                                   cacc48, cacc80, caccfloat>;

template<typename T, typename V>
struct is_valid_vector_accum_type {
    static constexpr 
    bool value = ((std::is_same_v<T, acc80> && (std::is_same_v<V, v4acc80> || 
                   std::is_convertible_v<V, v4acc80>)) || 
                  (std::is_same_v<T, cacc48> && (std::is_same_v<V, v4cacc48> ||
                   std::is_convertible_v<V, v4cacc48>)) || 
                  (std::is_same_v<T, cacc80> && (std::is_same_v<V, v2cacc80> ||
                   std::is_convertible_v<V, v2cacc80>)) || 
                  (std::is_same_v<T, acc48> && (std::is_same_v<V, v32int8> ||
                   std::is_convertible_v<V, v32int8>)) || 
                  (std::is_same_v<T, acc48> && (std::is_same_v<V, v32uint8> ||
                   std::is_convertible_v<V, v32uint8>)) || 
                  (std::is_same_v<T, acc48> && (std::is_same_v<V, v16int16> ||
                   std::is_convertible_v<V, v16int16>)) || 
                  (std::is_same_v<T, acc48> && (std::is_same_v<V, v8cint16> ||
                   std::is_convertible_v<V, v8cint16>)) || 
                  (std::is_same_v<T, acc48> && (std::is_same_v<V, v8int32> ||
                   std::is_convertible_v<V, v8int32>)) || 
                  (std::is_same_v<T, cacc48> && (std::is_same_v<V, v4cint32> ||
                   std::is_convertible_v<V, v4cint32>)) || 
                  (std::is_same_v<T, cacc48> && (std::is_same_v<V, v4cfloat> ||
                   std::is_convertible_v<V, v4cfloat>)) || 
                  (std::is_same_v<T, acc48> && (std::is_same_v<V, v8acc48> ||
                   std::is_convertible_v<V, v8acc48>)) || 
                  (std::is_same_v<T, acc48> && (std::is_same_v<V, v8float> ||
                   std::is_convertible_v<V, v8float>)));
};

#else // #ifdef __AIE_ARCH__<20

template <typename T>
static constexpr bool is_valid_type = is_one_of<T, int4, uint4, bfloat16, int32, int64, float, 
                                                       uint32, uint64,
                                                        cint16, cint32
#if __AIE_ARCH__==20
                                                        , cfloat
#endif
#if __AIE_ARCH__>=22
                                                        , float16, bfloat8, float8                                                        
#endif
                                                        >;
template <typename T>
static constexpr bool is_complex = is_one_of<T, cint16, cint32
#if __AIE_ARCH__==20
                                            , cfloat
#endif
                                            >;

template <typename T>
static constexpr bool is_cfloat =
#if __AIE_ARCH__==20
                                    is_one_of<T, cfloat>;
#else
                                    false;
#endif

template<typename T, typename V>
struct is_valid_vector_accum_type {
    static constexpr 
    bool value = ((std::is_same_v<T, acc32> && (std::is_same_v<V, v16acc32> ||
                   std::is_convertible_v<V, v16acc32>)) || 
                  (std::is_same_v<T, acc64> && (std::is_same_v<V, v8acc64> ||
                    std::is_convertible_v<V, v8acc64>)) || 
                  (std::is_same_v<T, cacc64> && (std::is_same_v<V, v4cacc64> ||
                   std::is_convertible_v<V, v4cacc64>)) || 
                  (std::is_same_v<T, accfloat> && (std::is_same_v<V, v16accfloat> ||
                   std::is_convertible_v<V, v16accfloat>)));
};

template <>
static constexpr unsigned type_bits_value<int4> = 4;

template <>
static constexpr unsigned type_bits_value<uint4> = 4;

template <typename T>
static constexpr bool is_bfloat16 = is_one_of<T, bfloat16>;
#endif // #ifdef __AIE_ARCH__<20
#if __AIE_ARCH__>=22
template <typename T>
static constexpr bool is_float16 = is_one_of<T, float16>;

template <typename T>
static constexpr bool is_bfloat8 = is_one_of<T, bfloat8>;

template <typename T>
static constexpr bool is_float8 = is_one_of<T, float8>;
#endif

template <typename T>
static constexpr bool is_float = is_one_of<T, float>;


template <typename T, typename streamTy>
static inline int32
aie_stream_get_ss(input_stream<streamTy> * ss)
{
#if __AIE_ARCH__ < 20
    if constexpr (stream_utils::aie_stream_resource<T>::is_in_a)
        return _get_ss_SS_rsrc1(ss);
    else if constexpr (stream_utils::aie_stream_resource<T>::is_in_b)
        return _get_ss_SS_rsrc2(ss);
    else
        return get_ss(ss->channel);
#elif __AIE_ARCH__ <= 22
    return get_ss();
#elif __AIE_ARCH__ == 40        // AIE4 FIXME
    return get_ss(ss->channel);
#endif
}

template <typename T, typename streamTy>
static inline int32
aie_stream_get_ss(input_stream<streamTy> * ss, bool &tlast)
{
#if __AIE_ARCH__<20
    int32 origVal;
    if constexpr (stream_utils::aie_stream_resource<T>::is_in_a)
        origVal =  _get_ss_SS_rsrc1(ss, tlast);
    else if constexpr (stream_utils::aie_stream_resource<T>::is_in_b)
        origVal =  _get_ss_SS_rsrc2(ss, tlast);
    else
    {
        origVal =  get_ss(ss->channel);
        chess_protect_access bool &tl = tlast;
        if (ss->channel)
          tl = get_ss1_tlast();
        else
          tl = get_ss0_tlast();
    }
    return origVal;
#elif __AIE_ARCH__ <= 22
    return get_ss(tlast);
#elif __AIE_ARCH__ == 40
    return get_ss(ss->channel);     // AIE4 FIXME
#endif
}

template <typename T, typename streamTy>
static inline void
aie_stream_put_ms(output_stream<streamTy> * ss, int32 value, bool tlast)
{
#if __AIE_ARCH__<20
    if constexpr (stream_utils::aie_stream_resource<T>::is_out_a)
        _put_ms_MS_rsrc1(ss, value, tlast);
    else if constexpr (stream_utils::aie_stream_resource<T>::is_out_b)
        _put_ms_MS_rsrc2(ss, value, tlast);
    else
        put_ms(ss->channel, value,tlast);
#else    // AIE4 FIXME (REVFIEW)
    put_ms(value, tlast);
#endif
}


#if __AIE_ARCH__<20
template <typename T>
static inline v8int16
aie_stream_get_wss(input_stream<int16> * ss)
{
    if constexpr (stream_utils::aie_stream_resource<T>::is_in_a)
        return as_v8int16(_get_wss_WSS_rsrc1(ss));
    else if constexpr (stream_utils::aie_stream_resource<T>::is_in_b)
        return as_v8int16(_get_wss_WSS_rsrc2(ss));
    else 
        return get_wss(ss->channel);
}

template <typename T>
static inline v8int16
aie_stream_get_wss(input_stream<int16> * ss, bool &tlast)
{
    v8int16 origVal;
    if constexpr (stream_utils::aie_stream_resource<T>::is_in_a)
        origVal =  as_v8int16(_get_wss_WSS_rsrc1(ss, tlast));
    else if constexpr (stream_utils::aie_stream_resource<T>::is_in_b)
        origVal =  as_v8int16(_get_wss_WSS_rsrc2(ss, tlast));
    else
    {
        origVal =  get_wss(ss->channel);
        chess_protect_access bool &tl = tlast;
        if (ss->channel)
          tl = get_wss1_tlast();
        else
          tl = get_wss0_tlast();
    }
    return origVal;
}

template <typename T>
static inline void
aie_stream_put_wms(output_stream<int16> * ss, v8int16 value, bool &tlast)
{
    if constexpr (stream_utils::aie_stream_resource<T>::is_out_a)
        _put_wms_WMS_rsrc1(ss, as_v4int32(value), tlast);
    else if constexpr (stream_utils::aie_stream_resource<T>::is_out_b)
        _put_wms_WMS_rsrc2(ss, as_v4int32(value), tlast);
    else
        put_wms(ss->channel, value, tlast);
}

#endif // #ifdef __AIE_ARCH__<20

template <typename streamTy, typename vectorTy>
static inline void
aie_stream_put_mcd(output_stream<streamTy> * ss, vectorTy value)
{
    put_mcd(value);
}
}

#endif // __STREAM_ME_STREAM_UTILS_H__
