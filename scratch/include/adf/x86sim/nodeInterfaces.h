// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef _SRC_X86SIM_INCLUDE_NODE_INTERFACES_H_
#define _SRC_X86SIM_INCLUDE_NODE_INTERFACES_H_

#include <string>
#include <memory>
#include <chrono>
#include "connectorInterfaces.h"
#include "xmcPlatformBufferInterfaces.h"
#include "symbolVisibility.h"

namespace adf 
{
class access_pattern;
}
namespace x86sim
{
class NodeProperties;
class ISimulator;
class StreamHelperBase;
class SocketUtilIfc;

class X86SIM_EXPORT INode
{
public:
    INode();
    virtual ~INode();
    virtual void addInput(IConnector*, bool /*needAcquire */ =false);
    virtual void addOutput(IConnector*, bool /* needAcquire */ =false);
    virtual IConnector* input(unsigned int);
    virtual IConnector* output(unsigned int);
    virtual bool isAsyncInput(unsigned int);
    virtual bool isAsyncOutput(unsigned int);
    virtual const std::string& label() const;

    virtual void start(bool /*join */ = false);
    virtual void runFor(const long);
    virtual void wait();
    virtual void notify();
    virtual void finish();
    virtual void setExecuteDuration(unsigned long secs);

protected:
    friend class NodePropertiesHelper;
    virtual void execute() = 0;

protected:
    NodeProperties* _props;
};

class X86SIM_EXPORT IKernel : public INode
{
public:
    using Clock = std::chrono::steady_clock;
    
    IKernel();
    virtual ~IKernel();
    
    virtual void start(bool /*join */ = false) override;
    virtual void wait() override;
    virtual bool waitUntil(Clock::time_point expirationTime);
    virtual void notify();
    virtual void finish() override;
    virtual bool finishUntil(Clock::time_point expirationTime);
    virtual void setExecuteDuration(unsigned long secs);
protected:
    virtual void prepareKernelInvocation();
    virtual void finishKernelInvocation();
    virtual void invokeKernel() = 0;
};

typedef void (*InitFunc)(void);
class X86SIM_EXPORT IMEKernel : public IKernel
{
public:
    using UserObjCtor = void* (*)(void**);
    using UserObjDtor = void (*)(void*);
    
   IMEKernel(ISimulator *simulator,
             std::string const&);
    virtual ~IMEKernel();
    virtual void addInitFunc(InitFunc func);
    virtual void setUserObjectCtor(UserObjCtor);
    virtual void setUserObjectDtor(UserObjDtor);
    virtual void* getUserObject() const;
    virtual void addUserParam(size_t);
    virtual void** getUserParams() const;
    virtual void setRepetitionCount(const unsigned long long);

    virtual void runFor(const long) override;

    virtual void addInput(IConnector*, bool = false) override;
    virtual void addOutput(IConnector*, bool = false) override;

    void setBypassSelector(IRtpConnector*, bool);
protected:
    virtual void execute() override;
    bool needToBypass();
    void doBypassCopy();
};

class X86SIM_EXPORT IPLKernel : public IKernel
{
public:
   IPLKernel(ISimulator *simulator,
             std::string const&,
             bool freeRunning);
    virtual ~IPLKernel();
    virtual void runFor(const long) override;
protected:
    virtual void execute() override;
};

class X86SIM_EXPORT IPlatformStreamNode: public INode
{
public:
    virtual bool connectHlsStream(void * stream,
                                  size_t datumSize,
                                  std::unique_ptr<StreamHelperBase> helper) = 0;
};

class X86SIM_EXPORT IGMIO: public INode
{
public:
    virtual ~IGMIO() {}

    virtual void gm2aie_nb(const void* addr, size_t sz) = 0;
    virtual void aie2gm_nb(void* addr, size_t sz) = 0;
    virtual void pl_gm(void* address, size_t total_size) = 0;
};

class X86SIM_EXPORT ISharedBuffer: public INode 
{
public:
    using Clock = std::chrono::steady_clock;
    virtual ~ISharedBuffer() {}

    virtual void addInput(unsigned index, IConnector*, bool =false) = 0;
    virtual void addOutput(unsigned index, IConnector*, bool =false) = 0; 
    virtual void setRepetitionCount(const unsigned long long) = 0;
    virtual bool finishUntil(Clock::time_point) = 0;
    virtual bool waitUntil(Clock::time_point) =0;
    virtual void setWriterAccessPattern(unsigned index,
                               std::vector< adf::access_pattern > const&) = 0;
    virtual void setReaderAccessPattern(unsigned index,
                               std::vector< adf::access_pattern > const&) = 0;
    virtual void setAddress(const void* ptr) = 0;
    virtual void gm2aieNb(unsigned index) = 0;
    virtual void aie2gmNb(unsigned index) = 0;
    virtual void externalBufferWait(unsigned index, bool isInput) = 0;
};

enum FileIOType {
    INT4,
    UINT4,
    BFLOAT16,
    FLOAT16,
    BFLOAT8,
    FLOAT8,
    INT8,
    UINT8,
    UINT16,
    INT16,
    INT32,
    UINT32,
    UINT64,
    INT64,
    CINT16,
    CINT32,
    FLOAT,
    CFLOAT
};

enum class PlatformStreamDataType {
    kAxis,
    kAxiu,
    kInt,
    kFloat,
    kCint,
    kCfloat
};

class X86SIM_EXPORT NodeFactory {
public:
   static IPlatformStreamNode *streamReader(ISimulator *simulator,
                                            std::string const &label,
                                            bool isPktstream);

   static IPlatformStreamNode *streamWriter(ISimulator *simulator,
                                            std::string const &label,
                                            bool isPktstream);

   static INode* fileReader(ISimulator *simulator,
                            std::string const &label,
                            std::string const &filename,
                            bool isPktstream,
                            FileIOType t,
                            size_t busWidth,
                            bool hexFormat);

   static INode* fileWriter(ISimulator *simulator,
                            std::string const &label,
                            std::string const &filename,
                            bool isPktstream,
                            FileIOType t,
                            size_t busWidth,
                            bool hexFormat);

    static INode* streamBroadcaster(ISimulator *simulator,
                                    std::string const &label,
                                    IStreamConnector* inpStream);

    static INode* windowBroadcaster(ISimulator *simulator,
                                        std::string const &label,
                                        IWindowConnector* inpWindow);

    static IGMIO* gmNode(ISimulator *simulator,
                         std::string const &label,
                         bool isInput);

    static INode* mergeAdapter(ISimulator *simulator,
                               std::string const &label,
                               int numBranches,
                               bool ordered);
    static INode* pktControlAgent(ISimulator *simulator,
                                  std::string const &label);

    static INode* bufferReader(ISimulator *simulator,
                               std::string const &label,
                               IPlatformBuffer *buf,
                               size_t datumWidth,
                               size_t busWidth);
   
    static INode* bufferWriter(ISimulator *simulator,
                               std::string const &label,
                               IPlatformBuffer *buf,
                               size_t datumWidth,
                               size_t busWidth);

    static INode* bufferReaderRtp(ISimulator *simulator,
                                  std::string const &label,
                                  IPlatformBuffer *buf,
                                  size_t size);

    static INode* bufferWriterRtp(ISimulator *simulator,
                                  std::string const &label,
                                  IPlatformBuffer *buf,
                                  size_t size);

    static INode* externalBufferAdapter(ISimulator *simulator, 
                                        std::string const &label,
                                        IPlatformBuffer *pbuf,
                                        ISharedBuffer *sbuf,
                                        size_t bufferSize,
                                        bool isInput);
   
    static INode* socketReader(ISimulator *iSim,
                                std::string const &label,
                                SocketUtilIfc *socket,
                                bool isPktstream,
                                size_t dataSize,
                                size_t busWidth);

    static INode* socketWriter(ISimulator *iSim,
                                std::string const &label,
                                SocketUtilIfc *socket,
                                bool isPktstream,
                                size_t dataSize,
                                size_t busWidth);
    
    static ISharedBuffer* sharedBuffer(ISimulator *iSim,
                                       std::string const &label,
                                       unsigned int bitsPerElement,
                                       size_t bufferSize,
                                       unsigned int numInputs,
                                       unsigned int numOutputs,
                                       bool     singleBuffer);
    static ISharedBuffer* externalBuffer(ISimulator *iSim,
                                       std::string const &label,
                                       unsigned int bitsPerElement,
                                       size_t bufferSize,
                                       unsigned int numInputs,
                                       unsigned int numOutputs);
};


} //end of namespace x86sim

#endif // ifndef _SRC_X86SIM_INCLUDE_NODE_INTERFACES_H_

