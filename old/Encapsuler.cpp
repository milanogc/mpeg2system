#include "Encapsuler.h"
#include <iostream>

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

Encapsuler::Encapsuler() {
	unsigned char macAddrMask[6] = {255, 255, 255, 255, 255, 0}; /* specified by you */
	unsigned char macAddr[6] = {0x06, 0x06, 0x06, 0x06, 0x06, 0x06}; /* specified by you */
	unsigned char ipV4mask[4] = {255, 255, 255, 0}; /* specified by you */
	unsigned char ipV4[4] = {10, 248, 0, 2}; /* specified by you */
	unsigned componentTag = 7; /* specified by you */
	unsigned dataStreamPid = 2600; /* specified by you */
	unsigned intSectionPid = 4400; /* specified by you */
	unsigned platformId = 0xFFF001; /* 0xFFF000 ... 0xFFFFFE, see ETSI 301 192 Annex D */ /* specified by you */
	unsigned actionType = 0x1;
	unsigned dbdLanguageCode = ('e' << 16) | ('n' << 8) | 'g'; /* eng */
	unsigned dbdTextLength = 5;
	unsigned char dbdTextChars[5] = {'L', 'A', 'V', 'I', 'D'}; /* TODO a valid value? */
	unsigned transportStreamId = 1; /* acquired from PAT, SDT... */
	unsigned originalNetworkId = 1; /* acquired from SDT, ... */
	unsigned networkId = 1;
	unsigned serviceId = 2; /* = programNumber */
	unsigned programNumber = serviceId; /* = serviceId */
	int pmtPid = 0x22; /* pid of the new PMT */
	
	/* BEGIN information to be added into PAT ----------------------------- */
	
	program = new PatSection::Program(true);
	program->setProgramNumber(programNumber);
	program->setPid(pmtPid);
	program->finalize();
	
	/* END information to be added into PAT ------------------------------- */
	
	/* BEGIN information to be added into PMT ----------------------------- */
	
	/* descriptor of the stream */
	StreamIdentifierDescriptor *siDescriptor = new StreamIdentifierDescriptor(NULL, 0);
	siDescriptor->setComponentTag(componentTag);
	siDescriptor->finalize();
	
	/* stream 1 (IP stream) */
	PmtSection::Stream *stream1 = new PmtSection::Stream(true, PmtSection::Stream::MIN_LENGTH + siDescriptor->getDataLength());
	/* ETSI EN 301 192 V.1.3.1 - 7.2.2 */
	/* The presence of a multiprotocol data stream in a service shall be
	 * indicated in the program map section of that service by setting the
	 * stream type of that stream to the value of 0x0D (see ISO/IEC 13818-6 [5])
	 *  or a user defined value. */
	stream1->setStreamType(0x0D);
	stream1->setElementaryPid(dataStreamPid);
	stream1->appendDescriptor(siDescriptor->getData(), siDescriptor->getDataLength()); /* TODO verify */
	stream1->finalize();
	
	/* siDescriptor is no longer needed since it was already copied into stream1 */
	delete siDescriptor;
	
	/* data broadcast id descriptor: made by hand */
	unsigned char dataBroadcastIdDescriptor[10] = {
		0x66, /* descriptor tag */
		8, /* descriptor length */
		0x00, /* data broadcast id 0 -> determine the usage of ip mac notification info structure */
		0x0B, /* data broadcast id 1 -> " */
		
		/* selector bytes: ip mac notification info */
		5, /* platform id data length */
		/* loop */
		(platformId & 0xFF0000) >> 16, /* platform id 0 */
		(platformId & 0x00FF00) >> 8, /* platform id 1 */
		platformId & 0x0000FF, /* platform id 2 */
		actionType & 0xFF, /* action type */
		0xC0 /*0xE0*/ /* 1100 0000 reserved 2b | INT version flag 1b | INT version 5b */
		/* end loop */
	}; /* see a079 5.8.1 */
	
	/* stream 2 (INT stream) */
	PmtSection::Stream *stream2 = new PmtSection::Stream(true, PmtSection::Stream::MIN_LENGTH + siDescriptor->getDataLength() + 10 /* dbid */); /* allocate */
	/* 0x05 -> a079 */
	stream2->setStreamType(0x05); /* ??? 0x0D ISO/IEC 13818-6 Sections (any type, including private data) */
	stream2->setElementaryPid(intSectionPid);
	stream2->appendDescriptor(dataBroadcastIdDescriptor, 10);
	stream2->finalize();
	
	/* create PMT table */
	
	unsigned char *pmtSectionData = new unsigned char[TSPacket::PACKET_SIZE];
	pmtSectionData[0] = 0; /* pointer field */
	
	/* PMT */
	PmtSection *myPmtSection = new PmtSection(false); /* TODO optimize, share data with intSectionPacket? */
	myPmtSection->setData(pmtSectionData + 1 /* skip pointer field */);
	/* generic fields */
	myPmtSection->setSectionLength(13); /* TODO PMT_SECTION_DEFAULT_LENGTH */
	myPmtSection->setProgramNumber(programNumber);
	myPmtSection->setVersionNumber(0);
	myPmtSection->setCurrentNextIndicator(true);
	myPmtSection->setPcrPid(NULL_PACKET_PID);
	myPmtSection->setProgramInfoLength(0); /* intialize */
	myPmtSection->appendStream(stream1->getData(), stream1->getDataLength()); /* stream will be copied */
	myPmtSection->appendStream(stream2->getData(), stream2->getDataLength()); /* stream will be copied */
	myPmtSection->finalize();
	
	delete stream1;
	delete stream2;
	
	/*************************************************************************/
	/* creating INT section packet */
	pmtSectionPacket = new TSPacket(NULL);
	pmtSectionPacket->setTransportErrorIndicator(false);
	pmtSectionPacket->setPayloadUnitStartIndicator(true);
	pmtSectionPacket->setTransportPriority(false);
	pmtSectionPacket->setPid(pmtPid);
	pmtSectionPacket->setTransportScramblingControl(0);
	pmtSectionPacket->setAdaptationFieldControl(ONLY_PAYLOAD); /* only payload */
	pmtSectionPacket->setContinuityCounter(0);
	pmtSectionPacket->setPayload(pmtSectionData, myPmtSection->getDataLength() + 1 /* pointer field */);
	pmtSectionPacket->finalize();
	
	delete myPmtSection;
	delete []pmtSectionData;
	
	/* END information to be added into PMT ------------------------------- */
	
	/* BEGIN information to be added into SDT ----------------------------- */
	
	/* service descriptor */
	
	unsigned char serviceDescriptor[19] = {
		0x48, /* descriptor tag */
		17, /* descriptor length */
		0x0C, /* service type -> 0x0C -> data broadcast service a079 and ETSI 300 468*/
		6, /* service provider name length */
		/* chars */
		'M', 'I', 'L', 'A', 'N', 'O', /* a079 says it must be ignored */
		8, /* service name length */
		/* chars */
		'I', 'N', 'T', 'E', 'R', 'N', 'E', 'T' /* a079 says it must be ignored */
	};
	
	/* multiprotocol encapsulation info */
	MpeInfo *mpeInfo = new MpeInfo(NULL); /* allocate */
	mpeInfo->setMacAddressRange(0x06); /* TODO try to use 0 ? */
	mpeInfo->setMacIpMappingFlag(true); /* IPv4 */
	mpeInfo->setAlignmentIndicator(false);
	mpeInfo->setMaxSectionsPerDatagram(0x01); /* ip datagram */
	mpeInfo->finalize();
	
	/* descriptor of the SDT */
	DataBroadcastDescriptor *dbDescriptor = new DataBroadcastDescriptor(NULL, DataBroadcastDescriptor::MIN_LENGTH + mpeInfo->getDataLength() + dbdTextLength); /* true means to allocate memory */
	dbDescriptor->setDataBroadcastId(0x0005); /* MPE */
	dbDescriptor->setComponentTag(componentTag);
	dbDescriptor->setSelector(mpeInfo->getData(), mpeInfo->getDataLength());
	dbDescriptor->setIso639LanguageCode(dbdLanguageCode);
	dbDescriptor->setText(dbdTextChars, dbdTextLength);
	dbDescriptor->setDescriptorLength(DataBroadcastDescriptor::MIN_LENGTH - 2 + mpeInfo->getDataLength() + dbdTextLength); /* TODO remove this method ? */
	dbDescriptor->finalize();
	
	delete mpeInfo;
	
	/* service of the SDT */
	service = new SdtSection::Service(NULL, TSPacket::PACKET_SIZE); /* TODO */
	service->setServiceId(serviceId);
	service->setEitScheduleFlag(false);
	service->setEitPresentFollowingFlag(false);
	service->setRunningStatus(0x04); /* TODO enumeration? */
	service->setFreeCaMode(false);
	service->setDescriptorsLoopLength(0); /* TODO? remove? */
	service->appendDescriptor(serviceDescriptor, 19);
	service->appendDescriptor(dbDescriptor->getData(), dbDescriptor->getDataLength());
	service->finalize();
	
	delete dbDescriptor;
	
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
	linkageDescriptor = new LinkageDescriptor(NULL, TSPacket::PACKET_SIZE); /* TODO optimize */
	linkageDescriptor->setDescriptorLength(8); /* TODO verify */
	linkageDescriptor->setTransportStreamId(transportStreamId);
	linkageDescriptor->setOriginalNetworkId(originalNetworkId);
	linkageDescriptor->setServiceId(serviceId);
	linkageDescriptor->setLinkageType(0x0B);
	linkageDescriptor->setPlatformIdDataLength(0); /* initialize */
	linkageDescriptor->appendPlatforms(platform, 13); /* it updates platform id data length */
	linkageDescriptor->finalize();
	
	/* END information to be added into NIT ------------------------------- */
	
	/* BEGIN creation of INT ---------------------------------------------- */
	
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
	
	unsigned char targetDescriptorLoop[26] = {
		/* target */
		0xF0, /* reserved 4, platform descriptor loop length 4 */
		24, /* platform descriptor loop length 8 */
		
		/* --- target mac address descriptor --- */
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
		
		/* --- target ip address descriptor --- */
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
	
//	unsigned char targetMacAddressDescriptor[16] = {
//		/* target */
//		0xF0, /* reserved 4, platform descriptor loop length 4 */
//		14, /* platform descriptor loop length 8 */
//		
//		/* descriptor */
//		0x07, /* descriptor tag */
//		12, /* descriptor length */
//		macAddrMask[0], /* mac addr mask 0 */
//		macAddrMask[1], /* mac addr mask 1 */
//		macAddrMask[2], /* mac addr mask 2 */
//		macAddrMask[3], /* mac addr mask 3 */
//		macAddrMask[4], /* mac addr mask 4 */
//		macAddrMask[5], /* mac addr mask 5 */
//		macAddr[0], /* mac addr 0 */
//		macAddr[1], /* mac addr 1 */
//		macAddr[2], /* mac addr 2 */
//		macAddr[3], /* mac addr 3 */
//		macAddr[4], /* mac addr 4 */
//		macAddr[5], /* mac addr 5 */
//	};
	
//	unsigned char targetIpAddressDescriptor[12] = {
//		/* target */
//		0xF0, /* reserved 4, platform descriptor loop length 4 */
//		10, /* platform descriptor loop length 8 */
//		
//		/* descriptor */
//		0x09, /* descriptor tag */
//		8, /* descriptor length */
//		ipV4mask[0], /* IPv4 addr mask 0 */
//		ipV4mask[1], /* IPv4 addr mask 1 */
//		ipV4mask[2], /* IPv4 addr mask 2 */
//		ipV4mask[3], /* IPv4 addr mask 3 */
//		/* loop */
//		ipV4[0], /* IPv4 addr 0 */
//		ipV4[1], /* IPv4 addr 1 */
//		ipV4[2], /* IPv4 addr 2 */
//		ipV4[3], /* IPv4 addr 3 */
//		/* end loop */
//	};
	
	unsigned char *intSectionData = new unsigned char[TSPacket::PACKET_SIZE];
	intSectionData[0] = 0; /* pointer field */
	
	/* INT */
	intSection = new IntSection(intSectionData + 1 /* skip pointer field */, 0); /* TODO optimize, share data with intSectionPacket? */
	/* generic fields */
	intSection->setSectionLength(13); /* INT_SECTION_DEFAULT_LENGTH */
	intSection->setVersionNumber(0);
	intSection->setCurrentNextIndicator(true);
	intSection->setSectionNumber(0);
	intSection->setLastSectionNumber(0);
	/* TODO implement section->setDefaults() */
	/* specific fields */
	intSection->setActionType(actionType);
	intSection->setPlatformId(platformId);
	intSection->setProcessingOrder(0x00); /* TODO verify: a079 OK */
	/* platform loop */
	intSection->appendLoop(ipMacStreamLocationDescriptor, 13); /* here? see a079 4.5.9 and ETSI 301 192 7.6.5.1 */
	/* target loop */
	intSection->appendLoop(targetDescriptorLoop, 26);
//	intSection->appendLoop(targetMacAddressDescriptor, 16); /* needed? see a079 4.5.9 */
//	intSection->appendLoop(targetIpAddressDescriptor, 12);
	/* operational */
	intSection->appendLoop(ipMacStreamLocationDescriptor, 13); /* here? see a079 4.5.9 and ETSI 301 192 7.6.5.1 */
	intSection->finalize();
	
	/* creating INT section packet */
	intSectionPacket = new TSPacket(NULL);
	intSectionPacket->setTransportErrorIndicator(false);
	intSectionPacket->setPayloadUnitStartIndicator(true);
	intSectionPacket->setTransportPriority(false);
	intSectionPacket->setPid(intSectionPid);
	intSectionPacket->setTransportScramblingControl(0);
	intSectionPacket->setAdaptationFieldControl(ONLY_PAYLOAD); /* only payload */
	intSectionPacket->setContinuityCounter(0);
	intSectionPacket->setPayload(intSectionData, intSection->getDataLength() + 1);
	intSectionPacket->finalize();
	
	delete intSection;
	delete []intSectionData;
	
	/* END creation of INT */
	
	packet = new TSPacket(NULL); /* false means to not allocate an internal buffer */
	section = new Section(false); /* generic section */
	patSection = new PatSection(false);
	pmtSection = new PmtSection(false);
	sdtSection = new SdtSection(false);
	nitSection = new NitSection(false);
	intSection = new IntSection(false);
	
	/* TODO replace the below line by: char *aux = (char *) malloc(sizeof(char) * 23 * 188); */
	aux = (char **) malloc(sizeof(char *) * 23);
	
	for (int i = 0; i < 23; i++)
		aux[i] = (char *) malloc(sizeof(char) * 188);
	
	count = 0; /* number of mpeg-2 ts packets to be sent */
	pos = 0; /* number of mpeg-2 ts packets already sent */
	/* ts information, pid, continuity counter */
	tsInfo.pid = 2600;
	tsInfo.continuityCounter = 0;
	
	/* intialize the capture of ip datagram packets */
	
	buf = buffer_new();
	buffer_init_capture(buf);
	
	sendIntSection = false;
	sendPmtSection = false;
}

Encapsuler::~Encapsuler() {
		delete program;
		delete linkageDescriptor;
		delete intSectionPacket;
		delete packet;
		delete section;
		delete patSection;
		delete pmtSection;
		delete sdtSection;
		delete nitSection;
		delete intSection;
		free(aux);
}

bool Encapsuler::processPacket(unsigned char *packetData) {
	unsigned char *payloadData;
	unsigned payloadLength;
	
	packet->setData(packetData);
	payloadData = packet->getPayload(payloadLength);
	
	if (packet->getPid() == NULL_PACKET_PID) { /* null packet */
		if (sendPmtSection) {
//			cout << "Writing our PmtSection..." << endl << endl;
			memcpy(packetData, pmtSectionPacket->getData(), TSPacket::PACKET_SIZE);
			pmtSection->setData(pmtSectionPacket->getPayload(payloadLength) + 1 /* skip pointer field */, payloadLength);
			pmtSectionPacket->incContinuityCounter();
			sendPmtSection = false;
		}
		else if (sendIntSection) {
//			cout << "Writing our IntSection..." << endl << endl;
			memcpy(packetData, intSectionPacket->getData(), TSPacket::PACKET_SIZE);
			intSection->setData(intSectionPacket->getPayload(payloadLength) + 1 /* skip pointer field */, payloadLength);
			intSectionPacket->incContinuityCounter();
			sendIntSection = false;
			
			return false;
		}
		else if (count == 0) {
			ipPacket = buffer_get_packet(buf);
			
			if (ipPacket != NULL) { /* an ip datagram is available, it needs to be encapsulated into MPE */
				/* convert from packet_t struct to IpDatagram struct */
				ipDatagram.length = ipPacket->length;
				ipDatagram.datagram = ipPacket->data;
				memcpy(ipDatagram.mac, ipPacket->mac, 6); /* copy mac address */
				cout << "Encapsuling IP packet into DSM-CC MPE format..." << endl; /* debug msg... */
				count = MultiprotocolEncapsulation(aux, &ipDatagram, &tsInfo) / TSPacket::PACKET_SIZE;
				pos = 0;
			}
		}
		
		if (count != 0) { /* there is a mpeg-2 ts packet (MPE format) to be written */
			cout << "Writing MPEG-2 TS packet...\n" << endl;
			memcpy(packetData, aux[pos], TSPacket::PACKET_SIZE);
			count--;
			pos++;
		}
	}
	else if (packet->getPid() == 0x0) { /* pat section */
		patSection->setData(payloadData + 1 /* skip pointer field */, payloadLength - 1);
		patSection->appendProgram(program->getData(), program->getDataLength());
		patSection->finalize();
//		cout << "New [Program added] ";
	}
	else if (packet->getPid() == 0x10) {
		section->setData(payloadData + 1 /* skip pointer field */, payloadLength - 1);
		
		if (section->getTableId() == 0x0040) { /* nit section (actual network) */
			nitSection->setData(payloadData + 1 /* skip pointer field */, payloadLength - 1);
			nitSection->insertDescriptor(linkageDescriptor); /* TODO verify */
			nitSection->finalize();
//			cout << "New [Linkage descriptor added] ";
			sendIntSection = true;
		}
	}
	else if (packet->getPid() == 0x11) {
		section->setData(payloadData + 1 /* skip pointer field */, payloadLength - 1);
		
		if (section->getTableId() == 0x0042) { /* sdt section */
			sdtSection->setData(payloadData + 1 /* skip pointer field */, payloadLength - 1);
			sdtSection->appendService(service->getData(), service->getDataLength());
			sdtSection->finalize();
//			cout << "New [Service added] ";
		}
	}
	else if (packet->getPid() == 0x20) {
		section->setData(payloadData + 1 /* skip pointer field */, payloadLength - 1);
		
		if (section->getTableId() == 0x0002) { /* pmt section */
			pmtSection->setData(payloadData + 1 /* skip pointer field */, payloadLength -1);
			sendPmtSection = true;
		}
	}
	
	return true;
}
