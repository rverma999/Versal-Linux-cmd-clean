// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// Adapted from http://www.boost.org/more/separate_compilation.html

#ifndef CDO_API_DYNLINK_H
#define CDO_API_DYNLINK_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              

//------------------Enable dynamic linking on windows-------------------------// 
#ifdef RDI_BUILD
# ifdef _MSC_VER
#  ifdef CDO_DRIVER_SOURCE
#   define CDO_DRIVER_EXPORT __declspec(dllexport)
#  else
#   define CDO_DRIVER_EXPORT __declspec(dllimport)
#  endif  
# endif
# ifdef __GNUC__
#  ifdef CDO_DRIVER_SOURCE
#   define CDO_DRIVER_EXPORT __attribute__ ((visibility("default")))
#  else
#   define CDO_DRIVER_EXPORT
#  endif
# endif
#endif

#ifndef CDO_DRIVER_EXPORT
# define CDO_DRIVER_EXPORT
#endif

#endif // #ifndef CDO_API_DYNLINK_H