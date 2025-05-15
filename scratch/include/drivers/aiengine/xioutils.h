// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef __XIOUTILS_H__
#define __XIOUTILS_H__

#include <stdint.h>

/* Low level read/write APIs for AIESIM */
void aiesim_WriteGM(uint64_t addr, const void* data, uint64_t size);
void aiesim_ReadGM(uint64_t addr, void* data, uint64_t size);

/* Low level read/write APIs for PL address space in AIESIM */
void XPl_Write32(uint64_t ctrl_pl_offset, uint32_t ctrl_ip_stride, int pl_ip_index, uint32_t relative_address, uint32_t value);
void XPl_Write64(uint64_t ctrl_pl_offset, uint32_t ctrl_ip_stride, int pl_ip_index, uint32_t relative_address, uint64_t value);
void XPl_Read32(uint64_t ctrl_pl_offset, uint32_t ctrl_ip_stride, int pl_ip_index, uint32_t relative_address, uint32_t& value);
void XPl_Read64(uint64_t ctrl_pl_offset, uint32_t ctrl_ip_stride, int pl_ip_index, uint32_t relative_address, uint64_t& value);
void XPl_IOstart();
#endif //__XIOUTILS_H__
