// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
/* cdo_driver.h  */
#ifndef _CDO_DRIVER_H_
#define _CDO_DRIVER_H_

#include <stdbool.h>
#include <stdint.h>
#include <cdo_api_dynlink.h>

enum byte_ordering{Little_Endian, Big_Endian};

enum CDO_COMMAND {
    CDO_CMD_DMA_WRITE     = 0x105U,
    CDO_CMD_MASK_POLL64   = 0x106U,
    CDO_CMD_MASK_WRITE64  = 0x107U,
    CDO_CMD_WRITE64       = 0x108U,
    CDO_CMD_NO_OPERATION  = 0x111U
};

typedef struct cdoHeader {

	/* Format:
	 *  0x0 - No. of remaining words in header,
	 *  0x4 - Identification Word,
	 *  0x8 - Version,
	 *  0xC - CDO Length,
	 *  0x10- Checksum 	 */

	const uint32_t NumWords;
	const uint32_t IdentWord;
	const uint32_t Version;

	uint32_t CDOLength; // Length of CDO object in words excluding header.
	uint32_t CheckSum; // one's complement of sum of all fields in header i.e. ~(NumWords+IdentWord+Version+Length)

} cdoHeader;

CDO_DRIVER_EXPORT void startCDOFileStream(const char* cdoFileName);
CDO_DRIVER_EXPORT void endCurrentCDOFileStream();
CDO_DRIVER_EXPORT void FileHeader();
CDO_DRIVER_EXPORT void EnAXIdebug();
CDO_DRIVER_EXPORT void setEndianness(bool endianness);
CDO_DRIVER_EXPORT void SectionHeader();
CDO_DRIVER_EXPORT void configureHeader();
CDO_DRIVER_EXPORT unsigned int getPadBytesForDmaWrCmdAlignment(uint32_t DmaCmdLength);
CDO_DRIVER_EXPORT void insertNoOpCommand(unsigned int numPadBytes);
CDO_DRIVER_EXPORT void insertDmaWriteCmdHdr(uint32_t DmaCmdLength);
CDO_DRIVER_EXPORT void disableDmaCmdAlignment();


#endif /* _CDO_DRIVER_H_ */
