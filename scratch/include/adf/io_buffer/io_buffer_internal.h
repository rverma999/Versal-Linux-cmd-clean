// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// *****************************************************************************
// File: io_buffer_internal.h
// 
/// This file contains the definitions of the bufer_port_internal class.
// *****************************************************************************
#ifndef SRC_IO_BUFFER_IO_BUFFER_INTERNAL_H_
#define SRC_IO_BUFFER_IO_BUFFER_INTERNAL_H_

#ifdef __X86SIM__
#include <cstdint>
#include <vector>
namespace x86sim {
class IWindowConnector;
void acquireBufferPort(IWindowConnector *, unsigned value);
void releaseBufferPort(IWindowConnector *, unsigned value);
} // namespace x86sim
#endif // ifdef __X86SIM__

namespace adf {
//******************************************************************************
// class io_buffer_internal
//
/// This is a datatype agnostic interface used by x86sim. For non x86sim flows
/// it is an empty class.
//******************************************************************************
class io_buffer_internal {
public:
#ifdef __X86SIM__
    using internal_datatype = int8_t;

    io_buffer_internal()
        :_iConn {}
        {}
    virtual                           ~io_buffer_internal() {}
    virtual void                      _iInit(x86sim::IWindowConnector *conn,
                                             internal_datatype *buf0,
                                             internal_datatype *buf1)
    {
    }
    inline x86sim::IWindowConnector  *_iGetConnector() const
    {
        return _iConn;
    }
    virtual internal_datatype        *_iData() const
    {
        return nullptr;
    }
    virtual void                      _iSetData()
    {
    }
    virtual void                      _iSetHead()
    {
    }
    virtual unsigned                  _iGetCurrentBufId() const
    {
        return 0;
    }
    virtual void                      _iToggleCurrentBufId()
    {
    }
    virtual void* _iGetBuf(unsigned id) const
    {
        return nullptr;
    }
    // size excluding margin in bytes.
    virtual uint32_t                  _iGetSize() const
    {
        return 0;
    }
    // size inluding margin in bytes.
    virtual uint32_t                  _iGetSizeInclMargin() const
    {
        return 0;
    }
    virtual void                      _iSetSizes(std::vector<uint32_t> const&)
    {
    }
    virtual void                      _iGetSizes(std::vector<uint32_t> &) const
    {
    }
    virtual void                      _iMarginCopy()
    {
    }
protected:
    x86sim::IWindowConnector         *_iConn;
#endif
};
} // namespace adf

#endif // ifndef SRC_IO_BUFFER_IO_BUFFER_INTERNAL_H_
