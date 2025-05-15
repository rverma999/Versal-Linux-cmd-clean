// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// *****************************************************************************
// File: progress.h
// 
/// This file contains the definition of the Progres class.
// *****************************************************************************
#ifndef _SRC_X86SIM_INCLUDE_PROGRESS_H_
#define _SRC_X86SIM_INCLUDE_PROGRESS_H_

#include <exception>
#include <memory>
#include "symbolVisibility.h"

namespace x86sim {

// *****************************************************************************
// class Progress
// 
/// This is the progress class. It provides a mechanism for monitoring the
/// threads of the simulation and terminating threads. 
// *****************************************************************************
class X86SIM_EXPORT Progress {
public:
   struct StopRequested: public std::exception {};

   Progress();
   Progress(Progress const&) = delete;
   ~Progress();

   void incrNumWorking();
   void decrNumWorking();
   int  getNumWorking();
   void preWaitDecrNumWorking(volatile bool &waiting);
   void postWaitIncrNumWorking(volatile bool &waiting);
   void preNotifyIncrNumWorking(volatile bool &otherIsWaiting);
   void waitUntilAllStalled();
   bool waitUntilAllStalled(unsigned numSeconds);
   void waitUntilOnlyPSRunning();
   void setTerminationRequested();
   void notify();

private:
   class Impl;
   std::unique_ptr<Impl> m_impl;
};
} // namespace x86sim

#define PROGRESS_INCR_NUM_WORKING(P) \
    if ((P)) {                       \
        (P)->incrNumWorking();       \
    }

#define PROGRESS_DECR_NUM_WORKING(P) \
    if ((P)) {                       \
        (P)->decrNumWorking();       \
    }

#define PROGRESS_PRE_WAIT_DECR_NUM_WORKING(P,W) \
    if ((P)) {                                  \
        (P)->preWaitDecrNumWorking(W);          \
    }

#define PROGRESS_POST_WAIT_INCR_NUM_WORKING(P,W) \
    if ((P)) {                                   \
        (P)->postWaitIncrNumWorking(W);          \
    }

#define PROGRESS_PRE_NOTIFY_INCR_NUM_WORKING(P,W) \
    if ((P)) {                                    \
        (P)->preNotifyIncrNumWorking(W);          \
    }

#define PROGRESS_WAIT_UNTIL_ALL_STALLED(P) \
    if ((P)) {                             \
        (P)->waitUntilAllStalled();        \
    }

#endif // ifndef _SRC_X86SIM_INCLUDE_PROGRESS_H_
