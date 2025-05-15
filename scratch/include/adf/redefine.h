
#ifndef __REDEFINE_H__
#define __REDEFINE_H__

// Redefine registration macros to no-op in __AIENGINE__
#ifdef __AIENGINE__
#define REGISTER_PARAMETER(var)
#define REGISTER_FUNCTION(func)
#endif

#endif


