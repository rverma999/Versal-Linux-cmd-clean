// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef __ADF_LIBSYNTH__
#define __ADF_LIBSYNTH__

#include "adf.h"

namespace adflibsynth {
  class libsynth
  {
  public:
    libsynth();

    void REGISTER_LIBRARY_SYNTH_API(const char *);
  };
}

#endif // __ADF_LIBSYNTH__
