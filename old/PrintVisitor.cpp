#include "PrintVisitor.h"
#include <iostream>
#include <ctype.h>
#include <stdio.h>

using std::cout;
using std::endl;

static void printHexDump(unsigned char *buf, int n);

void PrintVisitor::printDescriptors(unsigned char *descriptorsData, unsigned descriptorsDataLength) {
	cout << "Descriptors [" << endl;
	
	Descriptor *descriptor = new Descriptor(false);
	
	while (descriptorsDataLength != 0) {
		descriptor->setData(descriptorsData);
		descriptor->accept(this);
		descriptorsDataLength -= descriptor->getDataLength();
		descriptorsData += descriptor->getDataLength();
	}
	
	cout << "]" << endl;
	
	delete descriptor;
}

void PrintVisitor::visit(TSPacket *packet) {
	cout << "TS Packet Dump [" << endl;
	printHexDump(packet->getData(), TS_PACKET_SIZE);
	cout << "]" << endl;
	
	cout << endl;
	
	cout << "TS Packet [" << endl;
	cout << "SyncByte: " << packet->getSyncByte() << endl;
	cout << "TransportErrorIndicator: " << packet->getTransportErrorIndicator() << endl;
	cout << "PayloadUnitStartIndicator: " << packet->getPayloadUnitStartIndicator() << endl;
	cout << "TransportPriority: " << packet->getTransportPriority() << endl;
	cout << "Pid: " << packet->getPid() << endl;
	cout << "TransportScramblingControl: " << packet->getTransportScramblingControl() << endl;
	cout << "AdaptationFieldControl: " << packet->getAdaptationFieldControl() << endl;
	cout << "ContinuityCounter: " << packet->getContinuityCounter() << endl;
	cout << "Payload [ " << endl;
	
	unsigned payloadLength;
	unsigned char *payloadData = packet->getPayload(payloadLength);
	
	printHexDump(payloadData, payloadLength);
	
	cout << "]" << endl;
	cout << "]" << endl << endl;
}

void PrintVisitor::visit(Descriptor *descriptor) {
	unsigned descLength = descriptor->getDescriptorLength();
	unsigned char *descData = descriptor->getData() + 2;

	cout << "Descriptor [" << endl;
	cout << "DescriptorTag: " << descriptor->getDescriptorTag() << endl;
	cout << "DescriptorLength: " << descLength << endl;
	cout << "Data [" << endl;
	
	printHexDump(descData, descLength);
	
	cout << "]" << endl;
	cout << "]" << endl;
}

void PrintVisitor::visit(Section *section) {
	cout << "Section [" << endl;
	cout << "TableId: " << section->getTableId() << endl;
	cout << "SectionSyntaxIndicator: " << section->getSectionSyntaxIndicator() << endl; /* 1 */
	cout << "PrivateIndicator: " << section->getPrivateIndicator() << endl; /* 1 */
	cout << "SectionLength: " << section->getSectionLength() << endl;
	
	if (section->getSectionSyntaxIndicator()) {
		cout << "VersionNumber: " << section->getVersionNumber() << endl;
		cout << "CurrentNextIndicator: " << section->getCurrentNextIndicator() << endl;
		cout << "SectionNumber: " << section->getSectionNumber() << endl;
		cout << "LastSectionNumber: " << section->getLastSectionNumber() << endl;
	}
	
	cout << "]" << endl << endl;
}

void PrintVisitor::visit(PatSection *patSection) {
	cout << "PAT Section [" << endl;
	cout << "TableId: " << patSection->getTableId() << endl;
	cout << "SectionLength: " << patSection->getSectionLength() << endl;
	cout << "TransportStreamId: " << patSection->getTransportStreamId() << endl;
	cout << "VersionNumber: " << patSection->getVersionNumber() << endl;
	cout << "CurrentNextIndicator: " << patSection->getCurrentNextIndicator() << endl;
	cout << "SectionNumber: " << patSection->getSectionNumber() << endl;
	cout << "LastSectionNumber: " << patSection->getLastSectionNumber() << endl;
	cout << "Program Loop [" << endl;
	
	unsigned loopLength;
	unsigned char *programLoopData = patSection->getProgramLoopStart(loopLength);
	PatSection::Program *program = new PatSection::Program(false);
	
	while (loopLength != 0) {
		program->setData(programLoopData);
		programLoopData += PAT_PROGRAM_LOOP_LENGTH;
		loopLength -= PAT_PROGRAM_LOOP_LENGTH;
		
		cout << "Program [" << endl;
		cout << "ProgramNumber: " << program->getProgramNumber() << endl;
		cout << "Pid: " << program->getPid() << endl;
		cout << "]" << endl;
	}
	
	delete program;
	
	cout << "]" << endl;
	cout << "]" << endl;
	cout << "Verify: " << patSection->verify() << endl << endl;
}

void PrintVisitor::visit(PmtSection *pmtSection) {
	cout << "PMT Section [" << endl;
	cout << "TableId: " << pmtSection->getTableId() << endl;
	cout << "SectionLength: " << pmtSection->getSectionLength() << endl;
	cout << "ProgramNumber: " << pmtSection->getProgramNumber() << endl;
	cout << "VersionNumber: " << pmtSection->getVersionNumber() << endl;
	cout << "CurrentNextIndicator: " << pmtSection->getCurrentNextIndicator() << endl;
	cout << "SectionNumber: " << pmtSection->getSectionNumber() << endl;
	cout << "LastSectionNumber: " << pmtSection->getLastSectionNumber() << endl;
	cout << "PcrPid: " << pmtSection->getPcrPid() << endl;
	cout << "ProgramInfoLength: " << pmtSection->getProgramInfoLength() << endl;
	
	printDescriptors(pmtSection->getData() + 12, pmtSection->getProgramInfoLength());
	
	cout << "Streams [" << endl;
	
	unsigned loopLength = pmtSection->getSectionLength() - 13 - pmtSection->getProgramInfoLength();
	unsigned char *streamsData = pmtSection->getData() + 12 + pmtSection->getProgramInfoLength();
	PmtSection::Stream *stream = new PmtSection::Stream(false);
	
	while (loopLength != 0) {
		stream->setData(streamsData);
		streamsData += stream->getDataLength();
		loopLength -= stream->getDataLength();
		
		cout << "Stream [" << endl;
		cout << "StreamType: " << stream->getStreamType() << endl;
		cout << "ElementaryPid: " << stream->getElementaryPid() << endl;
		cout << "EsInfoLength: " << stream->getEsInfoLength() << endl;
		
		printDescriptors(stream->getData() + 5, stream->getEsInfoLength());
		
		cout << "]" << endl;
	}
	
	cout << "]" << endl;
	cout << "]" << endl;
	cout << "Verify: " << pmtSection->verify() << endl << endl;
}

void PrintVisitor::visit(SdtSection *sdtSection) {
	cout << "SDT Section [" << endl;
	cout << "TableId: " << sdtSection->getTableId() << endl;
	cout << "SectionLength: " << sdtSection->getSectionLength() << endl;
	cout << "TransportStreamId: " << sdtSection->getTransportStreamId() << endl;
	cout << "VersionNumber: " << sdtSection->getVersionNumber() << endl;
	cout << "CurrentNextIndicator: " << sdtSection->getCurrentNextIndicator() << endl;
	cout << "SectionNumber: " << sdtSection->getSectionNumber() << endl;
	cout << "LastSectionNumber: " << sdtSection->getLastSectionNumber() << endl;
	cout << "OriginalNetworkId: " << sdtSection->getOriginalNetworkId() << endl;
	cout << "Services [" << endl;
	
	unsigned loopLength = sdtSection->getSectionLength() - 12;
	unsigned char *data = sdtSection->getData() + 11; /* loop data */
	SdtSection::Service *service = new SdtSection::Service(false);
	
	while (loopLength != 0) {
		service->setData(data);
		data += 5 + service->getDescriptorsLoopLength();
		loopLength -= 5 + service->getDescriptorsLoopLength();
		
		cout << "Service [" << endl;
		cout << "ServiceId: " << service->getServiceId() << endl;
		cout << "EitScheduleFlag: " << service->getEitScheduleFlag() << endl;
		cout << "EitPresentFollowingFlag: " << service->getEitPresentFollowingFlag() << endl;
		cout << "RunningStatus: " << service->getRunningStatus() << endl;
		cout << "FreeCaMode: " << service->getFreeCaMode() << endl;
		cout << "DescriptorsLoopLength: " << service->getDescriptorsLoopLength() << endl;
		
		printDescriptors(service->getData() + 5, service->getDescriptorsLoopLength());
	}
	
	delete service;
	
	cout << "]" << endl;
	cout << "]" << endl;
	cout << "Verify: " << sdtSection->verify() << endl << endl;
}

void PrintVisitor::visit(NitSection *nitSection) {
	cout << "NIT Section [" << endl;
	cout << "TableId: " << nitSection->getTableId() << endl;
	cout << "SectionLength: " << nitSection->getSectionLength() << endl;
	cout << "NetworkId: " << nitSection->getNetworkId() << endl;
	cout << "VersionNumber: " << nitSection->getVersionNumber() << endl;
	cout << "CurrentNextIndicator: " << nitSection->getCurrentNextIndicator() << endl;
	cout << "SectionNumber: " << nitSection->getSectionNumber() << endl;
	cout << "LastSectionNumber: " << nitSection->getLastSectionNumber() << endl;
	cout << "NetworkDescriptorsLength: " << nitSection->getNetworkDescriptorsLength() << endl;
	
	printDescriptors(nitSection->getData() + 10, nitSection->getNetworkDescriptorsLength());
	
	cout << "TransportStreamLoopLength: " << nitSection->getTransportStreamLoopLength() << endl;
	
	cout << "Transport Streams [" << endl;
	
	unsigned loopLength = nitSection->getSectionLength() - 13 - nitSection->getNetworkDescriptorsLength();
	unsigned char *transportsData = nitSection->getData() + 12 + nitSection->getNetworkDescriptorsLength();
	NitSection::TransportStream *transport = new NitSection::TransportStream(false);
	
	while (loopLength != 0) {
		transport->setData(transportsData);
		transportsData += transport->getDataLength();
		loopLength -= transport->getDataLength();
		
		cout << "Transport Stream [" << endl;
		cout << "TransportStreamId: " << transport->getTransportStreamId() << endl;
		cout << "OriginalNetworkId: " << transport->getOriginalNetworkId() << endl;
		cout << "TransportDescriptorsLength: " << transport->getTransportDescriptorsLength() << endl;
		
		printDescriptors(transport->getData() + 6, transport->getTransportDescriptorsLength());
		
		cout << "]" << endl;
	}
	
	cout << "]" << endl;
	
	cout << "]" << endl;
	cout << "Verify: " << nitSection->verify() << endl << endl;
}

void PrintVisitor::visit(IntSection *intSection) {
	cout << "INT Section [" << endl;
	cout << "TableId: " << intSection->getTableId() << endl;
	cout << "SectionLength: " << intSection->getSectionLength() << endl;
	cout << "ActionType: " << intSection->getActionType() << endl;
	cout << "PlatformIdHash: " << intSection->getPlatformIdHash() << endl;
	cout << "VersionNumber: " << intSection->getVersionNumber() << endl;
	cout << "CurrentNextIndicator: " << intSection->getCurrentNextIndicator() << endl;
	cout << "SectionNumber: " << intSection->getSectionNumber() << endl;
	cout << "LastSectionNumber: " << intSection->getLastSectionNumber() << endl;
	cout << "PlatformId: " << intSection->getPlatformId() << endl;
	cout << "ProcessingOrder: " << intSection->getProcessingOrder() << endl;
	cout << "Data:" << endl;
	
	printHexDump(intSection->getData() + 12, intSection->getSectionLength() - 13);
	
	cout << "]" << endl;
	cout << "Verify: " << intSection->verify() << endl << endl;
}

/*****************************************************************************
 * AUX FUNCTIONS                                                             *
 *****************************************************************************/

static void printHexDump(unsigned char *buf, int n) {
	int i;
	int j = 0;
	int k;
	unsigned char c;
	int WID = 16;
	
	while (j * WID < n) {
		printf("\t%04x:  ", j * WID);
		
		for (i = 0; i < WID; i++) {
			if ((i + j * WID) >= n)
				break;
			
			c = buf[i + j * WID];
			printf("%02x ", (int) c);
			
			if ((i + 1) % 8 == 0)
				printf(" ");
		}
		
		for (k = i; k < WID; k++) {
			printf("   ");
			
			if ((k + 1) % 8 == 0)
				printf(" ");
		}
		
		printf(" ");
		
		for (i = 0; i < WID; i++) {
			if ((i + j * WID) >= n)
				break;
			
			c = buf[i + j * WID];
			printf("%c", isprint((int) c) ? c : '.');
		}
		
		printf("\n");
		j++;
	}
}
