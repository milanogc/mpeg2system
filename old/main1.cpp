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

#define RECV_BUFFER_SIZE 188

#include <iostream>
#include <fstream>

using namespace std;

/*
5: RegistrationDescriptor
6: DataStreamAlignmentDescriptor
10: Iso639LanguageDescriptor
11: SystemClockDescriptor
14: MaximumBitrateDescriptor
16: SmothingBufferDescriptor
64: NetworkDescriptorName
72: ServiceDescriptor
82: StreamIdentifierDescriptor
100: DataBroadcastDescriptor
106: Ac3Descriptor
*/

int main(int argc, char **argv) {
	unsigned char macAddrMask[6] = {1, 2, 3, 4, 5, 6}; /* TODO change */
	unsigned char macAddr[6] = {6, 5, 4, 3, 2, 1}; /* TODO change */
	unsigned char ipV4mask[4] = {255, 255, 255, 255};
	unsigned char ipV4[4] = {10, 248, 0, 1}; /* TODO change */
	unsigned componentTag = 7; /* specified by you */
	unsigned dataStreamPid = 2600; /* specified by you */
	unsigned platformId = 0xFFF001; /* 0xFFF000 ... 0xFFFFFE, see ETSI 301 192 Annex D */ /* specified by you */
	unsigned actionType = 0x1;
	unsigned dbdLanguageCode = ('e' << 16) | ('n' << 8) | 'g'; /* eng */
	unsigned dbdTextLength = 5;
	unsigned char dbdTextChars[5] = {'L', 'A', 'V', 'I', 'D'}; /* TODO a valid value? */
	unsigned intSectionPid = 4400; /* specified by you */
	unsigned transportStreamId = 1; /* acquired from PAT, SDT... */
	unsigned originalNetworkId = 1; /* acquired from SDT, ... */
	unsigned networkId = 1;
	unsigned serviceId = 1; /* acquired from SDT, ... */
	int pmtPid = 0x20; /* acquired from PAT */
	unsigned platformIdHash = ((platformId & 0xFF0000) >> 16) ^ ((platformId & 0x00FF00) >> 8) ^ (platformId & 0x0000FF);
	
	/* debug aux */
	PrintVisitor *printVisitor = new PrintVisitor();
	
	/* BEGIN information to be added into PMT ----------------------------- */
	
	/* descriptor of the stream */
	StreamIdentifierDescriptor *siDescriptor = new StreamIdentifierDescriptor(true); /* allocate */
	siDescriptor->setComponentTag(componentTag);
	siDescriptor->finalize();
	
	/* stream 1 (IP stream) */
	PmtSection::Stream *stream1 = new PmtSection::Stream(true, PMT_STREAM_MIN_LENGTH + siDescriptor->getDataLength() + 10 /* dbid */); /* allocate */
	/* ETSI EN 301 192 V.1.3.1 - 7.2.2 */
	/* The presence of a multiprotocol data stream in a service shall be
	 * indicated in the program map section of that service by setting the
	 * stream type of that stream to the value of 0x0D (see ISO/IEC 13818-6 [5])
	 *  or a user defined value. */
	stream1->setStreamType(0x0D);
	stream1->setElementaryPid(dataStreamPid);
	stream1->setEsInfoLength(0); /* initialize */
	stream1->appendDescriptor(siDescriptor->getData(), siDescriptor->getDataLength()); /* TODO verify */
	stream1->finalize();
	
	/* data broadcast id descriptor: made by hand */
	unsigned char dataBroadcastIdDescriptor[10] = {
		0x66, /* descriptor tag */
		8, /* descriptor length */
		0x00, /* data broadcast id 0 */
		0x0B, /* data broadcast id 1 -> determine the usage of ip mac notification info structure */
		
		/* selector bytes: ip mac notification info */
		5, /* platform id data length */
		/* loop */
		(platformId & 0xFF0000) >> 16, /* platform id 0 */
		(platformId & 0x00FF00) >> 8, /* platform id 1 */
		platformId & 0x0000FF, /* platform id 2 */
		actionType, /* action type */
		0xC0 /* 1100 0000 reserved 2b | INT version flag 1b | INT version 5b */
		/* end loop */
	};
	
	/* stream 2 (INT stream) */
	PmtSection::Stream *stream2 = new PmtSection::Stream(true, PMT_STREAM_MIN_LENGTH + siDescriptor->getDataLength() + 10 /* dbid */); /* allocate */
	stream2->setStreamType(0x0D); /* ??? ISO/IEC 13818-6 Sections (any type, including private data) */
	stream2->setElementaryPid(intSectionPid);
	stream2->setEsInfoLength(0); /* initialization */
	stream2->appendDescriptor(dataBroadcastIdDescriptor, 10);
	stream2->finalize();
	
	/* END information to be added into PMT ------------------------------- */
	
	/* BEGIN information to be added into SDT ----------------------------- */
	
	/* multiprotocol encapsulation info */
	MpeInfo *mpeInfo = new MpeInfo(true); /* allocate */
	mpeInfo->setMacAddressRange(0x06);
	mpeInfo->setMacIpMappingFlag(true);
	mpeInfo->setAlignmentIndicator(false); /* default */
	mpeInfo->setMaxSectionsPerDatagram(0x01); /* ip datagram */
	mpeInfo->finalize();
	
	/* descriptor of the SDT */
	DataBroadcastDescriptor *dbDescriptor = new DataBroadcastDescriptor(true, DBD_MIN_LENGTH + mpeInfo->getDataLength() + dbdTextLength); /* true means to allocate memory */
	dbDescriptor->setDataBroadcastId(0x0005); /* MPE */
	dbDescriptor->setComponentTag(componentTag);
	dbDescriptor->setSelectorLength(mpeInfo->getDataLength());
	dbDescriptor->setSelectorBytes(mpeInfo->getData(), mpeInfo->getDataLength());
	dbDescriptor->setIso639LanguageCode(dbdLanguageCode);
	dbDescriptor->setTextLength(dbdTextLength);
	dbDescriptor->setTextChars(dbdTextChars, dbdTextLength);
	dbDescriptor->setDescriptorLength(DBD_MIN_LENGTH - 2 + mpeInfo->getDataLength() + dbdTextLength);
	dbDescriptor->finalize();
	
	/* END information to be added into SDT ------------------------------- */
	
	/* BEGIN information to be added into NIT ----------------------------- */
	
	unsigned char platform[13] = {
		/* loop 1 */
		(platformId & 0xFF0000) >> 16, /* platform id 0 */
		(platformId & 0x00FF00) >> 8, /* platform id 1 */
		platformId & 0x0000FF, /* platform id 2 */
		9, /* platform name loop length */
		/* loop 2 */
		'e', 'n', 'g', /* iso 639 language code */
		5, /* platform name loop length */
		'L', 'A', 'V', 'I', 'D', /* text */
		/* end loop 2 */
		/* end loop 1 */
	};
	
	/* linkage descriptor */
	LinkageDescriptor *linkageDescriptor = new LinkageDescriptor(true, 188); /* TODO optimize */
	linkageDescriptor->setDescriptorLength(8); /* TODO verify */
	linkageDescriptor->setTransportStreamId(transportStreamId);
	linkageDescriptor->setOriginalNetworkId(originalNetworkId);
	linkageDescriptor->setServiceId(serviceId);
	linkageDescriptor->setLinkageType(0x0B);
	linkageDescriptor->setPlatformIdDataLength(0); /* initialize */
	linkageDescriptor->appendPlatforms(platform, 13); /* it updates platform id data length */
	linkageDescriptor->finalize();
	
	/* END information to be added into NIT ------------------------------- */
	
	/* BEGIN creation of INT */
	
	/* ip/mac platform name descriptor ? */
	
	/* ip/mac platform prov name descriptor ? */
	
	/* platform - ip/mac stream location descriptor ? */
	
	unsigned char ipMacStreamLocationDescriptor[13] = {
		/* platform */
		0xF0, /* reserved 4, platform descriptor loop length 4 */
		11, /* platform descriptor loop length 8 */
		
		/* descriptor */
		0x13, /* descriptor tag 8 */
		9, /* descriptor length 8 */
		(networkId & 0x00FF00) >> 8, /* network id 0 */
		networkId & 0x0000FF, /* network id 1 */
		(originalNetworkId & 0x00FF00) >> 8, /* original network id 0 */
		originalNetworkId & 0x0000FF, /* original network id 1 */
		(transportStreamId & 0x00FF00) >> 8, /* transport stream id 0 */
		transportStreamId & 0x0000FF, /* transport stream id 1 */
		(serviceId & 0x00FF00) >> 8, /* service id 0 */
		serviceId & 0x0000FF, /* service id 1 */
		componentTag /* component tag 8 */
	};
	
	/* target ip address descriptor ? */
	
	unsigned char targetMacAddressDescriptor[16] = {
		/* target */
		0xF0, /* reserved 4, platform descriptor loop length 4 */
		14, /* platform descriptor loop length 8 */
		
		/* descriptor */
		0x07, /* descriptor tag */
		12, /* descriptor length */
		macAddrMask[0], /* mac addr mask 0 */
		macAddrMask[1], /* mac addr mask 1 */
		macAddrMask[2], /* mac addr mask 2 */
		macAddrMask[3], /* mac addr mask 3 */
		macAddrMask[4], /* mac addr mask 4 */
		macAddrMask[5], /* mac addr mask 5 */
		macAddr[0], /* mac addr 0 */
		macAddr[1], /* mac addr 1 */
		macAddr[2], /* mac addr 2 */
		macAddr[3], /* mac addr 3 */
		macAddr[4], /* mac addr 4 */
		macAddr[5], /* mac addr 5 */
	};
	
	unsigned char targetIpAddressDescriptor[12] = {
		/* target */
		0xF0, /* reserved 4, platform descriptor loop length 4 */
		10, /* platform descriptor loop length 8 */
		
		/* descriptor */
		0x09, /* descriptor tag */
		8, /* descriptor length */
		ipV4mask[0], /* IPv4 addr mask 0 */
		ipV4mask[1], /* IPv4 addr mask 1 */
		ipV4mask[2], /* IPv4 addr mask 2 */
		ipV4mask[3], /* IPv4 addr mask 3 */
		/* loop */
		ipV4[0], /* IPv4 addr 0 */
		ipV4[1], /* IPv4 addr 1 */
		ipV4[2], /* IPv4 addr 2 */
		ipV4[3], /* IPv4 addr 3 */
		/* end loop */
	};
	
	/* INT */
	IntSection *intSection = new IntSection(true, 188); /* TODO optimize, share data with intSectionPacket? */
	/* generic fields */
	intSection->setSectionLength(13); /* INT_SECTION_DEFAULT_LENGTH */
	intSection->setVersionNumber(0);
	intSection->setCurrentNextIndicator(true);
	intSection->setSectionNumber(0);
	intSection->setLastSectionNumber(0);
	/* TODO implement section->setDefaults() */
	/* specific fields */
	intSection->setActionType(actionType);
	intSection->setPlatformIdHash(platformIdHash);
	intSection->setPlatformId(platformId);
	intSection->setProcessingOrder(0x00); /* TODO verify */
	/* platform loop */
	intSection->appendLoop(ipMacStreamLocationDescriptor, 13);
	/* target loop */
	intSection->appendLoop(targetMacAddressDescriptor, 16);
	intSection->appendLoop(targetIpAddressDescriptor, 12);
	intSection->finalize();
	
	intSection->accept(printVisitor);
	
	/* creating INT section packet */
	TSPacket *intSectionPacket = new TSPacket(true, 188);
	intSectionPacket->setTransportError(false);
	intSectionPacket->setPayloadUnitStart(true);
	intSectionPacket->setTransportPriority(false);
	intSectionPacket->setPid(intSectionPid);
	intSectionPacket->setTransportScramblingControl(0);
	intSectionPacket->setAdaptionFieldControl(0x1); /* only payload */
	intSectionPacket->setContinuityCounter(0);
	
	/* END creation of INT */
	
	unsigned char *packetData = new unsigned char[RECV_BUFFER_SIZE]; /* buffer used by everybody */
	TSPacket *packet = new TSPacket(false); /* false means to not allocate an internal buffer */
	Section *section = new Section(false); /* generic section */
	PatSection *patSection = new PatSection(false);
	PmtSection *pmtSection = new PmtSection(false);
	SdtSection *sdtSection = new SdtSection(false);
	NitSection *nitSection = new NitSection(false);
	
	ifstream in("dump.ts", ios::binary); /* input file */
	
	while (in.read((char *) packetData, RECV_BUFFER_SIZE)) {
		/* --- receive packets from source --- */
		
		/* --- process --- */
		unsigned char *payloadData;
		unsigned payloadLength;
		
		packet->setData(packetData);
		payloadData = packet->getPayload(payloadLength);
		
		if (packet->getPid() == 0x1FFF) { /* null packet */
			/* send int section and ip datagrams here */
		}
		else if (packet->getPid() == 0x0000) { /* pat section */
			patSection->setData(payloadData, payloadLength);
			patSection->accept(printVisitor);
		}
		else if (packet->getPid() == 0x10) {
			section->setData(payloadData, payloadLength);
			
			if (section->getTableId() == 0x0040) { /* nit section (actual network) */
				nitSection->setData(payloadData, payloadLength);
				nitSection->accept(printVisitor);
				nitSection->insertDescriptor(linkageDescriptor); /* TODO verify */
				nitSection->finalize();
				cout << "New ";
				nitSection->accept(printVisitor);
				
				break; /* only for fast stopping */
			}
		}
		else if (packet->getPid() == 0x11) {
			section->setData(payloadData, payloadLength);
			
			if (section->getTableId() == 0x0042) { /* sdt section */
				sdtSection->setData(payloadData, payloadLength);
				sdtSection->accept(printVisitor);
				
				SdtSection::Service *service = sdtSection->getServices();
				
				if (service != NULL) { /* append descriptor in the first service */
					service->appendDescriptor(dbDescriptor); /* descriptor will be copied */
					service->finalize();
					sdtSection->setSectionLength(sdtSection->getSectionLength() + dbDescriptor->getDataLength()); /* new section length */
				}
				
				sdtSection->finalize();
				cout << "New ";
				sdtSection->accept(printVisitor);
			}
		}
		else if (packet->getPid() == pmtPid) {
			section->setData(payloadData, payloadLength);
			
			if (section->getTableId() == 0x0002) { /* pmt section */
				pmtSection->setData(payloadData, payloadLength);
				pmtSection->accept(printVisitor);
				pmtSection->appendStream(stream1); /* stream will be copied */
				pmtSection->appendStream(stream2); /* stream will be copied */
				pmtSection->finalize();
				cout << "New ";
				pmtSection->accept(printVisitor);
			}
		}
	}
	
	in.close();
	
	/* cleaning the house */
	
	delete printVisitor;
	delete sdtSection;
	delete pmtSection;
	delete patSection;
	delete section;
	delete dbDescriptor;
	delete mpeInfo;
	delete stream1;
	delete stream2;
	delete siDescriptor;
	delete packet;
	delete []packetData;
	delete linkageDescriptor;
	delete nitSection;
	delete intSectionPacket;
	
	cout << "*** End of file ***" << endl;
	
	return 0;
}
