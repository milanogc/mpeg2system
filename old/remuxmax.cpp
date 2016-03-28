/* infra */
#include "TSPacket.h"
#include "PatSection.h"
#include "PmtSection.h"
#include "SdtSection.h"
#include "StreamIdentifierDescriptor.h"
#include "MpeInfo.h"
#include "DataBroadcastDescriptor.h"
#include "PrintVisitor.h"

/* max */
#include "LinkageDescriptor.h"
#include "NitSection.h"
#include "IntSection.h"

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

#define RECV_BUFFER_SIZE 2048

#include <iostream> /* cout */
#include <stdio.h> /* FILE */

using namespace std;

static void loadConfiguration(int &listeningPort, char *&destAddress, int &destPort);

int main(int argc, char **argv) {
	int listeningPort;
	char *targetIpAddress;
	int targetPort;
	
	/* fill with the values acquired from the configuration file */
	loadConfiguration(listeningPort, targetIpAddress, targetPort);
	
	/* source socket */
	
	int sourceSocket = socket(PF_INET, SOCK_DGRAM, 0);
	
	if (sourceSocket <= 0)
		return -1;
	
	sockaddr_in sourceAddr;
	sourceAddr.sin_family = PF_INET;
	sourceAddr.sin_addr.s_addr = INADDR_ANY;
	sourceAddr.sin_port = htons(listeningPort); /* port to listen */
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
	
	/* linkage descriptor */
	
	unsigned platformId = 0; /* TODO give a valid value */
	unsigned intSectionPid = 0; /* TODO give a valid value */
	
	LinkageDescriptor *linkageDescriptor = new LinkageDescriptor(true);
	linkageDescriptor->setTransportStreamId(0/*?*/); /* obter do NIT ou do SDT, no SDT os valores possiveis sao 0x42 e 0x46 */
	linkageDescriptor->setOriginalNetworkId(0/*?*/); /* obter do NIT */
	linkageDescriptor->setServiceId(0/*?*/); /* obter do SDT */
	linkageDescriptor->setLinkageType(0x0B);
	linkageDescriptor->setPlatformIdDataLength(0); /* initialize */
	/*linkageDescriptor->appendPlatform(platform);*/ /* TODO */ /* it updates platform_id_data_length */
	
	/* linkage descriptor */
	
	/* BEGIN INT section */
	
	IntSection *intSection = new IntSection(true);
	/* TODO set the other fields */
	intSection->setActionType(0x01);
	intSection->setPlataformIdHash(0/*?*/); /* TODO */
	intSection->setPlataformId(platformId);
	intSection->setProcessingOrder(0x00); /* ? */
	
	TSPacket *intSectionPacket = new TSPacket(true);
	intSectionPacket->setTransportError(0); /* 1 */
	intSectionPacket->setPayloadUnitStart(1); /* 1 */
	intSectionPacket->setTransportPriority(0); /* 1 */
	intSectionPacket->setPid(intSectionPid); /* 13 */ /* TODO */
	intSectionPacket->setTransportScramblingControl(0); /* 2 */
	intSectionPacket->setAdaptionFieldControl(1); /* 2 */ /* only payload */
	intSectionPacket->setContinuityCounter(0); /* 4 */
	
	/* END INT section */
	
	/* BEGIN information to be added into PMT ----------------------------- */
	
	unsigned componentTag = 7; /* TODO give a valid value */
	unsigned dataStreamPid = 2600;
	
	/* descriptor of the stream */
	StreamIdentifierDescriptor *siDescriptor = new StreamIdentifierDescriptor(true); /* allocate */
	siDescriptor->setComponentTag(componentTag);
	siDescriptor->finalize();
	
	/* data_broadcast_id_descriptor */
	unsigned char dataBroadcastIdDescriptor[10] = {
		0x66, /* descriptor_tag */
		2 + 6, /* descriptor_length: 2 + selector_bytes_length */
		0x00, /* data_broadcast_id 0 */
		0x0B, /* data_broadcast_id 1 */
		
		/* selector bytes: ipMacNotificationInfo */
		
		0x04, /* platform_id_data_length */
		(platformId & 0xFF0000) << 16, /* platform_id 0 */
		(platformId & 0x00FF00) << 8, /* platform_id 1 */
		platformId & 0x0000FF, /* platform_id 2 */
		0x01, /* action_type */
		0xC0 /* 1100 0000 reserved 2, INT_version_flag 1, INT_version 5 */
	};
	
	/* stream */
	PmtSection::Stream *stream = new PmtSection::Stream(true, PMT_STREAM_MIN_LENGTH + siDescriptor->getDataLength()); /* allocate */
	stream->setStreamType(0x0D); /* TODO add comment explaining */
	stream->setElementaryPid(dataStreamPid);
	stream->setEsInfoLength(0); /* initialize */
	stream->appendDescriptor(siDescriptor); /* descriptor will be copied */
	stream->appendDescriptor(dataBroadcastIdDescriptor, 10); /* TODO */
	stream->finalize();
	
	/* END information to be added into PMT ------------------------------- */
	
	/* BEGIN information to be added into SDT ----------------------------- */
	
	unsigned dbdLanguageCode = ('e' << 16) | ('n' << 8) | 'g'; /* eng */
	unsigned dbdTextLength = 0; /* TODO */
	unsigned char *dbdTextChars = NULL; /* TODO */
	
	/* multiprotocol encapsulation info */
	MpeInfo *mpeInfo = new MpeInfo(true); /* allocate */
	mpeInfo->setMacAddressRange(0x06);
	mpeInfo->setMacIpMappingFlag(true);
	mpeInfo->setAlignmentIndicator(false); /* ? */
	mpeInfo->setMaxSectionsPerDatagram(0x01); /* ip datagram */
	mpeInfo->finalize();
	
	/* descriptor of the SDT */
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
	
	/* END information to be added into SDT ------------------------------- */
	
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
	
	PrintVisitor *printVisitor = new PrintVisitor();
	unsigned char *packetData = new unsigned char[RECV_BUFFER_SIZE]; /* buffer used by everybody */
	TSPacket *packet = new TSPacket(false); /* false means to not allocate an internal buffer */
	Section *section = new Section(false);
	PatSection *patSection = new PatSection(false);
	PmtSection *pmtSection = new PmtSection(false);
	SdtSection *sdtSection = new SdtSection(false);
	NitSection *nitSection = new NitSection(false);
	
	int pmtPid = -1; /* dummy pid */
	bool sendIntSection = false;
	
	while (true) {
		/* --- receive packets from source --- */
		
		unsigned nReceivedBytes = recvfrom(sourceSocket, packetData, RECV_BUFFER_SIZE, 0, (sockaddr *) &sourceAddr, &sourceAddrLen);
		
		if (nReceivedBytes <= 0)
			return -1; /* communication failed */
		
		/* --- process --- */
		
		unsigned nTsPackets = nReceivedBytes / TS_PACKET_SIZE; /* number of received mpeg-2 ts packets */
		unsigned char *payloadData;
		unsigned payloadLength;
		
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
				
				if (count != 0 && sendIntSection) {
					cout << "Writing IntSection..." << endl;
					intSectionPacket->setPayload(intSection->getData(), intSection->getDataLength());
					memcpy(packetData, intSection->getData(), 188);
					intSectionPacket->incContinuityCounter();
					intSectionPacket->resetPayload();
					sendIntSection = false;
				}
			}
			else if (packet->getPid() == 0x0000) { /* pat section */
				patSection->setData(payloadData, payloadLength);
				patSection->accept(printVisitor);
				
				const PatSection::Program *program = patSection->getPrograms();
				
				while (program != NULL) {
					pmtPid = program->getPid();
					program = program->next; /* next program */
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
					pmtSection->appendStream(stream); /* stream will be copied */
					pmtSection->finalize();
					cout << "New ";
					pmtSection->accept(printVisitor);
				}
			}
			else if (packet->getPid() == 0x10) {
				section->setData(payloadData, payloadLength);
				
				if (section->getTableId() == 0x0040) { /* nit section (actual network) */
					nitSection->setData(payloadData, payloadLength);
					nitSection->insertDescriptor(linkageDescriptor);
					nitSection->finalize();
					sendIntSection = true;
				}
			}
			
			packetData += TS_PACKET_SIZE; /* next mpeg-2 ts packet */
		}
		
		/* --- send packets to target --- */
		
		if (sendto(targetSocket, packetData, nReceivedBytes, 0, (sockaddr *) &targetAddr, sizeof(targetAddr)) <= 0)
			return -1; /* communication failed */
	}
	
	/* cleaning the house */
	
	delete printVisitor;
	delete sdtSection;
	delete pmtSection;
	delete patSection;
	delete section;
	delete dbDescriptor;
	delete mpeInfo;
	delete stream;
	delete siDescriptor;
	delete packet;
	delete []packetData;
	
	cout << "*** End of file ***" << endl;
	
	return 0;
}

/*****************************************************************************
 * AUX FUNCTIONS                                                             *
 *****************************************************************************/

/* read a line from f. returns the line without the leading '\n' */
static char *readline(FILE *f) {
	char line[1024];
	
	if ((fgets(line, 1024, f)) == NULL)
		return NULL;
	
	line[strlen(line)-1] = '\0';
	
	if (line[strlen(line)-1] == '\r')
		line[strlen(line)-1] = '\0';
	
	return strdup(line);
}

static void loadConfiguration(int &listeningPort, char *&destAddress, int &destPort) {
	FILE *f = fopen("/etc/buffer.conf", "r");
	char *id;
	char *arg;
	listeningPort = -1;
	destAddress = NULL;
	destPort = -1;
	
	if (f == NULL) {
		printf("Erro...");
		exit(-1);
	}
	
	while ((id = readline(f)) != NULL) {
		if (isspace(*id) || *id == '#') {
			free(id);
			continue;
		}
		else {
			arg = strchr(id, '=');

			if (arg != 0) {
				*arg++ = '\0';
				
				if (strcasecmp(id, "LISTENING_PORT") == 0) {
					listeningPort = atoi(arg);
				}
				else if (strcasecmp(id, "DEST_ADDRESS") == 0) {
					destAddress = strdup(arg);
				}
				else if (strcasecmp(id, "DEST_PORT") == 0) {
					destPort = atoi(arg);
				}
			}
		}
		
		free(id);
	}
	
	if (listeningPort <= 0) {
		printf("Porta de escuta invalida!\n");
		exit(-1);
	}
	
	printf("Porta de escuta: %d\n", listeningPort);
	
	if (destPort <= 0) {
		printf("Porta de destino invalida!\n");
		exit(-1);
	}
	
	printf("Porta do destino: %d\n", destPort);
	
	if (destAddress == NULL) {
		printf("Endereco de destino invalido!\n");
		exit(-1);
	}
}
