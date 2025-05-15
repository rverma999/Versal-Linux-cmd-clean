// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef _SRC_X86SIM_INCLUDE_X86SIM_SOCKET_UTIL_IFC_H_
#define _SRC_X86SIM_INCLUDE_X86SIM_SOCKET_UTIL_IFC_H_

#include <cstddef>
#include <string>
#include <vector>
#include "symbolVisibility.h"

namespace x86sim {

class X86SIM_EXPORT SocketUtilIfc
{
public:
    virtual void createSocket() = 0;
    virtual bool sample_transaction(std::vector<char> &samples , bool &tlast, size_t &bytes) = 0;
    virtual void transport(char *samples, unsigned int length, bool tlast) = 0;
    virtual unsigned int barrier_wait(int timeout) = 0;
    virtual const std::string& socketId() const = 0;
};

class X86SIM_EXPORT SocketUtilFactory {
public:
    static SocketUtilIfc* socketUtil(std::string const &socketId, bool isInput);
};

}
#endif //ifndef _SRC_X86SIM_INCLUDE_X86SIM_SOCKET_UTIL_IFC_H_
