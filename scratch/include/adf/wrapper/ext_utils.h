// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef PACKET_HANDLING_H
#define PACKET_HANDLING_H

unsigned int getPacketid(std::string work_dir, std::string port_name_to_get_pkt_id);

uint32_t generateHeader(unsigned int pcktType, unsigned int srcCol, unsigned int srcRow, unsigned int ID);

uint32_t generateCtrlHeader(unsigned int returnID, unsigned int op, unsigned int numWords, unsigned int addr);


#endif

