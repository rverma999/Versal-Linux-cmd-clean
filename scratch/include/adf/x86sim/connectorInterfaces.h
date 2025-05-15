// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef _SRC_X86SIM_INCLUDE_CONNECTOR_INTERFACES_H_
#define _SRC_X86SIM_INCLUDE_CONNECTOR_INTERFACES_H_

#include <cstdlib>
#include <string>
#include <vector>
#include "symbolVisibility.h"

struct window_internal;
struct output_pktstream;

namespace adf {
class io_buffer_internal;
class access_pattern;
} // namespace adf

namespace x86sim
{
class Progress;
class Connector;
class ISimulator;

class X86SIM_EXPORT IConnector
{
public:
    virtual ~IConnector(){}
    virtual void notify() = 0;
protected:
    virtual Connector *getConnector() = 0;
};

struct stream_internal;
class X86SIM_EXPORT IStreamConnector : public IConnector
{
public:
    virtual ~IStreamConnector(){}
    virtual stream_internal* stream() = 0;
    // This is only supported for a split stream connector.
    virtual void addBranch(IConnector *) = 0;
};

struct casc48_internal;

class X86SIM_EXPORT ICascadeStreamConnector : public IConnector
{
public:
    virtual ~ICascadeStreamConnector(){}
    virtual casc48_internal* stream() = 0;
};

class X86SIM_EXPORT IWindowConnector : public IConnector
{
public:
    virtual ~IWindowConnector(){}

    virtual window_internal* readWindow() = 0;
    virtual window_internal* writeWindow() = 0;
    virtual adf::io_buffer_internal *writePort() = 0;
    virtual adf::io_buffer_internal *readPort() = 0;
    virtual void setAccessPattern(unsigned int bitsPerElement, std::vector< adf::access_pattern > const&) = 0;
};

enum RtpProtocolType
{   
    RTPSYNCUPD, //synchronous rtp update
    RTPASYNCUPD, //asynchrnous rtp update
    RTPSYNCREAD, //synchronous rtp read
    RTPASYNCREAD, //asynchronous rtp read
    RTPASYNCNEW //asynchronous rtp update / read-new-data
};


class X86SIM_EXPORT IRtpConnector : public IConnector
{
public:
    virtual ~IRtpConnector(){}

    virtual int8_t* readBuffer() = 0;
    virtual int8_t* writeBuffer() = 0;
};

class X86SIM_EXPORT IGmemConnector : public IConnector
{
public:
    virtual ~IGmemConnector(){}

    virtual size_t getGmemSize() = 0;
    virtual void pl_gm(void* address, size_t total_size) = 0;
    virtual void* getAddress() = 0;
};

X86SIM_EXPORT void windowAcquire(window_internal *w, int type);
X86SIM_EXPORT void windowRelease(window_internal* w, int type);
X86SIM_EXPORT void acquireBufferPort(adf::io_buffer_internal *, unsigned);
X86SIM_EXPORT void releaseBufferPort(adf::io_buffer_internal *, unsigned);

class X86SIM_EXPORT ConnectorFactory
{
public:
   static IWindowConnector* windowConnector(ISimulator *sim,
                                            std::string const &label,
                                            size_t winsz /* window size bytes */,
                                            size_t osz /* overlap bytes */,
                                            adf::io_buffer_internal *wPort = nullptr,
                                            adf::io_buffer_internal *rPort = nullptr,
                                            size_t storageSize = 0,
                                            bool isSelfLoop = false);

    static IRtpConnector* rtpConnector(ISimulator *sim,
                                       std::string const &label, 
                                       size_t sz, 
                                       RtpProtocolType p);

    static IRtpConnector* rtpBrdcstConnector(ISimulator *sim,
                                             std::string const &label,
                                             size_t sz, 
                                             size_t numDst, 
                                             ... /* list of dst connectors */);

    static IStreamConnector* streamConnector(ISimulator *sim,
                                             std::string const &label,
                                             size_t size = 128,
                                             bool resizable = true,
                                             size_t fifoDepth = 0);

    static IStreamConnector* pktStreamConnector(ISimulator *sim,
                                                std::string const &label,
                                                std::vector<int> const &pktIds,
                                                size_t fifoDepth = 0);

    static IStreamConnector* splitStreamConnector(ISimulator *sim,
                                                  std::string const &label, 
                                                  std::vector<int> const &pktIds);

    static ICascadeStreamConnector* cascStreamConnector(ISimulator *sim,
                                                        std::string const &label);
    static IGmemConnector* gmemConnector(ISimulator *sim,
                                         std::string label);
};

//XXX TODO: int8_t* => int8_t void*
X86SIM_EXPORT void updateRtp(int8_t*, size_t, IRtpConnector*); 
X86SIM_EXPORT void readRtp(int8_t*, size_t, IRtpConnector*);

#undef T
#undef N

template <typename T, size_t N>
T (&toArrayRef(int8_t *p))[N]
{
    return *((T(*)[N]) p);
}

template <typename T>
T& toScalarRef(int8_t *p)
{
    T *ptr = (T*) p;
    return (*ptr);
}

template<typename tpCompTy>
    static inline typename tpCompTy::user_port_type &
    get_input_buffer(IConnector *conn)
{
    using UserTy = typename tpCompTy::user_port_type;
    auto wConn = static_cast<IWindowConnector*>(conn);
    return *static_cast<UserTy *>
        (static_cast<tpCompTy*>(wConn->readPort()));
}

template<typename tpCompTy>
    static inline typename tpCompTy::user_port_type &
    get_output_buffer(IConnector *conn)
{
    using UserTy = typename tpCompTy::user_port_type;
    auto wConn = static_cast<IWindowConnector*>(conn);
    return *static_cast<UserTy *>
        (static_cast<tpCompTy*>(wConn->writePort()));
}

#if 0
template<typename tpValueTy>
    static inline typename input_window<tpValueTy> *
    get_input_window(IConnector *conn)
{
    auto wConn = static_cast<IWindowConnector*>(conn);
    return reinterpret_cast<input_window<tpValueTy> *>
        (wConn->readWindow());
}

template<typename tpValueTy>
    static inline typename output_window<tpValueTy> *
    get_output_window(IConnector *conn)
{
    auto wConn = static_cast<IWindowConnector*>(conn);
    return reinterpret_cast<output_window<tpValueTy> *>
        (wConn->readWindow());
}
#endif

} //end of namespace x86sim

#endif // ifndef _SRC_X86SIM_INCLUDE_CONNECTOR_INTERFACES_H_


