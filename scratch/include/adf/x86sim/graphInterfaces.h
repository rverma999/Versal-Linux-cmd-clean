// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef _SRC_X86SIM_INCLUDE_GRAPH_INTERFACES_H_
#define _SRC_X86SIM_INCLUDE_GRAPH_INTERFACES_H_

#include <vector>
#include "symbolVisibility.h"

namespace x86sim
{
class IMEKernel;
class IPLKernel;
class ISharedBuffer;
class ISimulator;
class GraphProperties;

class X86SIM_EXPORT DFGraph
{
public:
    DFGraph(ISimulator *simulator);
    ~DFGraph();

    ISimulator *getSimulator() const;

    // must be called before threads are started.
    virtual void setExecuteDuration(unsigned long secs);
    
    virtual void start();
    virtual void init();
    virtual void run();
    virtual void runFor(int numIters);
    virtual void wait();
    virtual void wait(unsigned long long timeOut);
    virtual void resume();
    virtual void finish();
    virtual void finish(unsigned long long timeOut);

    void addKernel(IMEKernel *kernel);
    void addKernel(IPLKernel *kernel);
    void addSharedBuffer(ISharedBuffer *buffer);

protected:
    friend class GraphPropertiesHelper;
    GraphProperties *_props;
};   

} // end of x86sim namespace

#endif // ifndef _SRC_X86SIM_INCLUDE_GRAPH_INTERFACES_H_
