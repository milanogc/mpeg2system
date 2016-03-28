#include "TSPacket.h"
#include "PatSection.h"
#include "PmtSection.h"
#include "SdtSection.h"
#include "StreamIdentifierDescriptor.h"
#include "MpeInfo.h"
#include "DataBroadcastDescriptor.h"

#define RECV_BUFFER_SIZE 2048

#include <unistd.h> /* getopt */
#include <stdlib.h>
#include <string.h>

/* network */
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

/* mpe */
extern "C" {
	#include "mpe/mpe.h"
	#include "mpe/buffer/buffer.h"
}

#include <iostream>

using namespace std;

int showPat(PatSection *patSection);
void showPmt(PmtSection *pmtSection);
void showSdt(SdtSection *sdtSection);

int main(int argc, char **argv) {
	/* params processing */
	
	int listeningPort = -1;
	char *targetIpAddress = NULL;
	int targetPort = -1;
	
	while (true) {
		int opt = getopt(argc, argv, "l:a:p:");
		
		if (opt == -1)
			break;
		
		switch (opt) {
			case 'l': /* local port. format: number */
				listeningPort = atoi(optarg);
				break;
			
			case 'a': /* target ip address. format: number.number.number.number:number */
				targetIpAddress = optarg;
				break;
			
			case 'p': /* target ip address. format: number.number.number.number:number */
				targetPort = atoi(optarg);
				break;
		}
	}
	
	cout << "listening port: " << listeningPort << endl;
	cout << "target ip address: " << targetIpAddress << endl;
	cout << "target port: " << targetPort << endl;
	
	/* source socket */
	
	int sourceSocket = socket(PF_INET, SOCK_DGRAM, 0);
	
	if (sourceSocket <= 0)
		return -1;
	
	sockaddr_in sourceAddr;
	sourceAddr.sin_family = PF_INET;
	sourceAddr.sin_addr.s_addr = INADDR_ANY;
	sourceAddr.sin_port = htons(listeningPort);
	unsigned sourceAddrLen = sizeof(sourceAddr);
	
	if (bind(sourceSocket, (struct sockaddr *) &sourceAddr, sizeof(sourceAddr)) < 0)
		return -1; /* binding error */
	
	/* target socket */
	
	int targetSocket = socket(PF_INET, SOCK_DGRAM, 0);
	
	if (targetSocket <= 0)
		return -1; /* error creating socket */
	
	sockaddr_in targetAddr;
	targetAddr.sin_family = PF_INET;
	targetAddr.sin_addr.s_addr = inet_addr(targetIpAddress);
	targetAddr.sin_port = htons(targetPort);
	
	/* start of the game ;) */
	
	unsigned char *packetData = new unsigned char[RECV_BUFFER_SIZE];
	TSPacket *packet = new TSPacket();
	unsigned componentTag = 0;
	unsigned dataStreamPid = 2600;
	unsigned dbdLanguageCode = 0;
	unsigned dbdTextLength = 0;
	unsigned char *dbdTextChars = NULL;
	
	/* BEGIN information to be added into PMT */
	
	/* descriptor of the stream */
	StreamIdentifierDescriptor *siDescriptor = new StreamIdentifierDescriptor(true); /* allocate */
	siDescriptor->setComponentTag(componentTag);
	siDescriptor->finalize();
	
	/* stream */
	PmtSection::Stream *stream = new PmtSection::Stream(true, PMT_STREAM_MIN_LENGTH + siDescriptor->getDataLength()); /* allocate */
	stream->setStreamType(0x0D); /* TODO add comment explaining */
	stream->setElementaryPid(dataStreamPid);
	stream->setEsInfoLength(0); /* initialize */
	stream->appendDescriptor(siDescriptor); /* descriptor will be copied */
	stream->finalize();
	
	/* END information to be added into PMT */
	
	/* BEGIN information to be added into SDT */
	
	/* multiprotocol encapsulation info */
	MpeInfo *mpeInfo = new MpeInfo(true); /* allocate */
	mpeInfo->setMacAddressRange(0x06);
	mpeInfo->setMacIpMappingFlag(true);
	mpeInfo->setAlignmentIndicator(false); /* ? */
	mpeInfo->setMaxSectionsPerDatagram(0x01); /* ip datagram */
	mpeInfo->finalize();
	
	/* descriptor of sdt */
	DataBroadcastDescriptor *dbDescriptor = new DataBroadcastDescriptor(true, DBD_MIN_LENGTH + mpeInfo->getDataLength() + dbdTextLength); /* true means to allocate memory */
	dbDescriptor->setDataBroadcastId(0x0005); /* MPE */
	dbDescriptor->setComponentTag(componentTag); /* 8 */
	dbDescriptor->setSelectorLength(mpeInfo->getDataLength()); /* TODO needed? */
	dbDescriptor->setSelectorBytes(mpeInfo->getData(), mpeInfo->getDataLength());
	dbDescriptor->setIso639LanguageCode(dbdLanguageCode); /* 24 */
	dbDescriptor->setTextLength(dbdTextLength); /* TODO needed? */ /* 8 */
	dbDescriptor->setTextChars(dbdTextChars, dbdTextLength);
	dbDescriptor->setDescriptorLength(DBD_MIN_LENGTH - 2 + mpeInfo->getDataLength() + dbdTextLength);
	dbDescriptor->finalize();
	
	/* END information to be added into SDT */
	
	/* TODO replace the below line by: char *aux = (char *) malloc(sizeof(char) * 23 * 188); */
	char **aux = (char **) malloc(sizeof(char *) * 23);
	
	for (int i = 0; i < 23; i++)
		aux[i] = (char *) malloc(sizeof(char) * 188);
	
	unsigned count = 0; /* number of mpeg-2 ts packets to be sent */
	unsigned pos = 0; /* number of mpeg-2 ts packets already sent */
	IpDatagram ipDatagram;
	TsInfo tsInfo = {2600, 0}; /* ts information, pid, continuity counter */
	
	/* intialize the capture of ip datagram packets */
	
	buffer_t *buf = buffer_new();
	buffer_init_capture(buf);
	packet_t *ipPacket;
	
	while (true) {
		/* --- receive packets from source --- */
		
		unsigned nReceivedBytes = recvfrom(sourceSocket, packetData, RECV_BUFFER_SIZE, 0, (sockaddr *) &sourceAddr, &sourceAddrLen);
		
		if (nReceivedBytes <= 0)
			return -1; /* communication failed */
		
		/* --- process --- */
		
		unsigned nTsPackets = nReceivedBytes / TS_PACKET_SIZE; /* number of received mpeg-2 ts packets */
		unsigned char *payloadData;
		unsigned payloadLength;
		int pmtPid = -1;
		
		for (unsigned i = 0; i < nTsPackets; i++) {
			packet->setData(packetData);
			payloadData = packet->getPayload(payloadLength);
			
			if (packet->getPid() == 0x1FFF) { /* null packet */
				if (count == 0) {
					ipPacket = buffer_get_packet(buf);
					
					if (ipPacket != NULL) { /* an ip datagram is available, it needs to be encapsulated into MPE */
						/* convert from packet_t struct to IpDatagram struct */
						ipDatagram.length = ipPacket->length;
						ipDatagram.datagram = ipPacket->data;
						memcpy(ipDatagram.mac, ipPacket->mac, 6); /* copy mac address */
						cout << "Encapsuling IP packet into DSM-CC MPE format..." << endl; /* debug msg... */
						count = MultiprotocolEncapsulation(aux, &ipDatagram, &tsInfo) / 188;
						pos = 0;
					}
				}
				
				if (count != 0) { /* there is a mpeg-2 ts packet (MPE format) to be written */
					cout << "Writing MPEG-2 TS packet...\n" << endl;
					memcpy(packetData, aux[pos], TS_PACKET_SIZE);
					count--;
					pos++;
				}
			}
			else if (packet->getPid() == 0x0000) { /* pat section */
				PatSection *patSection = new PatSection(false); /* don't allocate */
				patSection->setData(payloadData, payloadLength);
				pmtPid = showPat(patSection);
				
				delete patSection; /* it deletes programs too */
			}
			else if (packet->getPid() == pmtPid) {
				Section *section = new Section(false); /* don't allocate */
				section->setData(payloadData, payloadLength);
				
				if (section->getTableId() == 0x0002) { /* pmt section */
					PmtSection *pmtSection = new PmtSection(false); /* don't allocate */
					pmtSection->setData(payloadData, payloadLength);
					//~ showPmt(pmtSection);
					pmtSection->appendStream(stream); /* stream will be copied */
					pmtSection->finalize();
					//~ cout << "New ";
					//~ showPmt(pmtSection);
					
					delete pmtSection;
				}
				
				delete section;
			}
			else if (packet->getPid() == 0x11) {
				Section *section = new Section();
				section->setData(payloadData, payloadLength);
				
				if (section->getTableId() == 0x0042) { /* sdt section */
					SdtSection *sdtSection = new SdtSection(false); /* don't allocate */
					sdtSection->setData(payloadData, payloadLength);
					showSdt(sdtSection);
					
					SdtSection::Service *service = sdtSection->getServices();
					
					if (service != NULL) { /* append descriptor in the first service */
						service->appendDescriptor(dbDescriptor); /* descriptor will be copied */
						service->finalize();
						sdtSection->setSectionLength(sdtSection->getSectionLength() + dbDescriptor->getDataLength()); /* new section length */
					}
					
					//~ sdtSection->finalize();
					//~ cout << "New ";
					//~ showSdt(sdtSection);
					
					delete sdtSection;
				}
				
				delete section;
			}
			
			packetData += TS_PACKET_SIZE; /* next mpeg-2 ts packet */
		}
		
		/* --- send packets to target --- */
		
		if (sendto(targetSocket, packetData, nReceivedBytes, 0, (sockaddr *) &targetAddr, sizeof(targetAddr)) <= 0)
			return -1; /* communication failed */
	}
	
	/* cleaning the house */
	
	close(sourceSocket);
	close(targetSocket);
	
	delete dbDescriptor;
	delete mpeInfo;
	delete stream;
	delete siDescriptor;
	delete packet;
	delete []packetData;
	
	return 0;
}


/*****************************************************************************
 * AUX FUNCTIONS                                                             *
 *****************************************************************************/

int showPat(PatSection *patSection) {
	cout << "PAT [" << endl;
	cout << "	TableId: " << patSection->getTableId() << endl;
	cout << "	SectionLength: " << patSection->getSectionLength() << endl;
	cout << "	TransportStreamId: " << patSection->getTransportStreamId() << endl;
	cout << "	VersionNumber: " << patSection->getVersionNumber() << endl;
	cout << "	CurrentNextIndicator: " << patSection->getCurrentNextIndicator() << endl;
	cout << "	SectionNumber: " << patSection->getSectionNumber() << endl;
	cout << "	LastSectionNumber: " << patSection->getLastSectionNumber() << endl;
	cout << "	Loop [" << endl;
	
	const PatSection::Program *program = patSection->getPrograms();
	int pmtPid = -1;
	
	while (program != NULL) {
		cout << "		Program [" << endl;
		cout << "			ProgramNumber: " << program->getProgramNumber() << endl;
		cout << "			Pid: " << program->getPid() << endl;
		cout << "		]" << endl;
		
		pmtPid = program->getPid();
		program = program->next; /* next program */
	}
	
	cout << "	]" << endl;
	cout << "]" << endl;
	cout << "Verify: " << patSection->verify() << endl << endl;
	
	return pmtPid;
}

void showPmt(PmtSection *pmtSection) {
	cout << "PMT [" << endl;
	cout << "	TableId: " << pmtSection->getTableId() << endl;
	cout << "	SectionLength: " << pmtSection->getSectionLength() << endl;
	cout << "	ProgramNumber: " << pmtSection->getProgramNumber() << endl;
	cout << "	VersionNumber: " << pmtSection->getVersionNumber() << endl;
	cout << "	CurrentNextIndicator: " << pmtSection->getCurrentNextIndicator() << endl;
	cout << "	SectionNumber: " << pmtSection->getSectionNumber() << endl;
	cout << "	LastSectionNumber: " << pmtSection->getLastSectionNumber() << endl;
	cout << "	PcrPid: " << pmtSection->getPcrPid() << endl;
	cout << "	ProgramInfoLength: " << pmtSection->getProgramInfoLength() << endl;
	cout << "	Descriptors Loop [ " << endl;
	
	const Descriptor *descriptor = pmtSection->getDescriptors();
	
	while (descriptor != NULL) {
		cout << "		Descriptor [" << endl;
		cout << "			DescriptorTag: " << descriptor->getDescriptorTag() << endl;
		cout << "			DescriptorLength: " << descriptor->getDescriptorLength() << endl;
		cout << "		]" << endl;
		
		descriptor = descriptor->next;
	}
	
	cout << "	]" << endl;
	cout << "	Streams [" << endl;
	
	PmtSection::Stream *stream = pmtSection->getStreams();
	
	while (stream != NULL) {
		cout << "		Stream [" << endl;
		cout << "			StreamType: " << stream->getStreamType() << endl;
		cout << "			ElementaryPid: " << stream->getElementaryPid() << endl;
		cout << "			EsInfoLength: " << stream->getEsInfoLength() << endl;
		cout << "			Descriptors [" << endl;
		
		const Descriptor *descriptor = stream->getDescriptors();
		
		while (descriptor != NULL) {
			cout << "				Descriptor [" << endl;
			cout << "					DescriptorTag: " << descriptor->getDescriptorTag() << endl;
			cout << "					DescriptorLength: " << descriptor->getDescriptorLength() << endl;
			cout << "				]" << endl;
			
			descriptor = descriptor->next;
		}
		
		cout << "			]" << endl;
		cout << "		]" << endl;
		stream = stream->next;
	}
	
	cout << "	]" << endl;
	cout << "]" << endl;
	cout << "Verify: " << pmtSection->verify() << endl << endl;
}

void showSdt(SdtSection *sdtSection) {
	cout << "SDT [" << endl;
	cout << "	TableId: " << sdtSection->getTableId() << endl;
	cout << "	SectionLength: " << sdtSection->getSectionLength() << endl;
	cout << "	TransportStreamId: " << sdtSection->getTransportStreamId() << endl;
	cout << "	VersionNumber: " << sdtSection->getVersionNumber() << endl;
	cout << "	CurrentNextIndicator: " << sdtSection->getCurrentNextIndicator() << endl;
	cout << "	SectionNumber: " << sdtSection->getSectionNumber() << endl;
	cout << "	LastSectionNumber: " << sdtSection->getLastSectionNumber() << endl;
	cout << "	OriginalNetworkId: " << sdtSection->getOriginalNetworkId() << endl;
	cout << "	Services [" << endl;
	
	SdtSection::Service *service = sdtSection->getServices();
	
	while (service != NULL) {
		cout << "		Service [" << endl;
		cout << "			EitScheduleFlag: " << service->getEitScheduleFlag() << endl;
		cout << "			EitPresentFollowingFlag: " << service->getEitPresentFollowingFlag() << endl;
		cout << "			RunningStatus: " << service->getRunningStatus() << endl;
		cout << "			FreeCaMode: " << service->getFreeCaMode() << endl;
		cout << "			DescriptorsLoopLength: " << service->getDescriptorsLoopLength() << endl;
		cout << "			Descriptors [" << endl;
		
		const Descriptor *descriptor = service->getDescriptors();
		
		while (descriptor != NULL) {
			cout << "				Descriptor [" << endl;
			cout << "					DescriptorTag: " << descriptor->getDescriptorTag() << endl;
			cout << "					DescriptorLength: " << descriptor->getDescriptorLength() << endl;
			
			if (descriptor->getDescriptorTag() == 0x64) {
				DataBroadcastDescriptor *dbDescriptor = new DataBroadcastDescriptor(false);
				dbDescriptor->setData(descriptor->getData());
				
				MpeInfo *mpeInfo = new MpeInfo(false);
				mpeInfo->setData(dbDescriptor->getSelectorBytes(), dbDescriptor->getSelectorLength());
				
				cout << "					MpeInfo [" << endl;
				cout << "						MacAddressRange: " << mpeInfo->getMacAddressRange() << endl;
				cout << "						MacIpMappingFlag: " << mpeInfo->getMacIpMappingFlag() << endl;
				cout << "						AlignmentIndicator: " << mpeInfo->getAlignmentIndicator() << endl;
				cout << "						MaxSectionsPerDatagram: " << mpeInfo->getMaxSectionsPerDatagram() << endl;
				cout << "					]" << endl;
				
				delete mpeInfo;
				delete dbDescriptor;
			}
			
			cout << "				]" << endl;
			
			descriptor = descriptor->next;
		}
		
		cout << "			]" << endl;
		cout << "		]" << endl;
		
		service = service->next;
	}
	
	cout << "	]" << endl;
	cout << "]" << endl;
	cout << "Verify: " << sdtSection->verify() << endl << endl;
}
