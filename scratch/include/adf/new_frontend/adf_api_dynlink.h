// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// Adapted from http://www.boost.org/more/separate_compilation.html

#ifndef adf_api_dynlink_h
#define adf_api_dynlink_h

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              

//------------------Enable dynamic linking on windows-------------------------// 

#ifdef RDI_BUILD
# ifdef _MSC_VER
#  ifdef ADF_API_SOURCE
#   define ADF_API_EXPORT __declspec(dllexport)
#  else
#   define ADF_API_EXPORT __declspec(dllimport)
#  endif  
# endif
# ifdef __GNUC__
#  ifdef ADF_API_SOURCE
#   define ADF_API_EXPORT __attribute__ ((visibility("default")))
#  else
#   define ADF_API_EXPORT
#  endif
# endif
#endif

#ifdef RDI_BUILD
# ifdef _MSC_VER
#  ifdef XV_MEIR_SOURCE
#   define XV_MEIR_EXPORT __declspec(dllexport)
#  else
#   define XV_MEIR_EXPORT __declspec(dllimport)
#  endif  
# endif
# ifdef __GNUC__
#  ifdef XV_MEIR_SOURCE
#   define XV_MEIR_EXPORT __attribute__ ((visibility("default")))
#  else
#   define XV_MEIR_EXPORT
#  endif
# endif
#endif


#ifndef ADF_API_EXPORT
# define ADF_API_EXPORT
#endif

#ifndef XV_MEIR_EXPORT
# define XV_MEIR_EXPORT
#endif

#endif // #ifndef adf_api_dynlink_h
