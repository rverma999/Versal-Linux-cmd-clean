
#ifndef __ADF_H__
#define __ADF_H__

// Intrinsic Macros
#ifdef __AIENGINE__
  #include "adf/intrinsics.h"
#ifndef __AIECC__
  #include "adf/window/window.h"
#endif
  #include "adf/stream/streams.h"
  #include "adf/io_buffer/io_buffer.h"
  #include "adf/redefine.h"
  #include "adf/aie/tile_control.h"
#else // ! AI ENGINE
  #include "adf/new_frontend/adf.h"
#endif

#if (defined(__X86SIM__) && (defined(__AIENGINE__) || defined(__PL_KERNEL__)))
   #include "adf/x86sim/streamApi.h"
#endif  


#ifdef __X86SIM__
#define X86SIM_THREAD_LOCAL thread_local
#else
#define X86SIM_THREAD_LOCAL
#endif //end ifdef __X86SIM__

#endif // end __ADF_H__
