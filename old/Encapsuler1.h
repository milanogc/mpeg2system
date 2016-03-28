#ifndef ENCAPSULER_H
#define ENCAPSULER_H

#include "TSPacket.h"
#include "PatSection.h"
#include "PmtSection.h"
#include "SdtSection.h"
#include "NitSection.h"
#include "StreamIdentifierDescriptor.h"
#include "MpeInfo.h"
#include "DataBroadcastDescriptor.h"
#include "LinkageDescriptor.h"
#include "PrintVisitor.h"
#include "IntSection.h"

/* mpe */
//extern "C" {
//	#include "mpe/mpe.h"
//	#include "mpe/buffer/buffer.h"
//}

class Encapsuler {
	public:
		Encapsuler();
		~Encapsuler();
		
		bool processPacket(unsigned char *packetData);
		
		PrintVisitor *printVisitor;
		
		TSPacket *packet;
		TSPacket *pmtSectionPacket;
		TSPacket *intSectionPacket;
		
		Section *section; /* generic section */
		PatSection *patSection;
		PmtSection *pmtSection;
		SdtSection *sdtSection;
		NitSection *nitSection;
		IntSection *intSection;
		
		SdtSection::Service *service; /* to be added into SDT */
		PatSection::Program *program; /* to be added into PAT */
		LinkageDescriptor *linkageDescriptor; /* to be added int NIT */
		
		bool sendIntSection;
		bool sendPmtSection;
		
//		char **aux;
//		unsigned count;
//		unsigned pos;
//		IpDatagram ipDatagram;
//		TsInfo tsInfo = {2600, 0}; /* 2600 !!!!!!!!!!!!!!!!!!!!!!!!! */
//		buffer_t *buf;
//		packet_t *ipPacket;
};

#endif // ENCAPSULER_H
