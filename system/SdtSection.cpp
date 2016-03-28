/**
 * Milano 2004.06.07-06:07 (YYYY.MM.DD-HH:MM)
 */

#include "SdtSection.h"
#include <string>

SdtSection::SdtSection(unsigned char *d, unsigned l) : PsiSection(d, l) {
}

/* --- decoding --- */

unsigned SdtSection::getTransportStreamId() const { /* just an alias */
	return getTableIdExtension();
}

unsigned SdtSection::getOriginalNetworkId() const { /* 16 */
	return ((data[8] << 8) & 0xFF00) | data[9];
}

bool SdtSection::verify() const {
	/* TODO implement */
	return PsiSection::verify();
}

/* --- coding --- */

void SdtSection::setTransportStreamId(unsigned id) { /* just an alias */
	setTableIdExtension(id); /* setTableIdExtension is protected in PsiSection */
}

void SdtSection::setOriginalNetworkId(unsigned id) { /* 16 */
	/* TODO verify */
	data[8] = (id & 0xFF00) >> 8;
	data[9] = id & 0xFF;
}

void SdtSection::appendService(unsigned char *serviceData, unsigned serviceDataLength) {
	appendData(getSectionLength() - 1, serviceData, serviceDataLength);
}

void SdtSection::finalize() {
	data[10] = 0xFF; /* reserved future use */
	PsiSection::finalize();
}

/*****************************************************************************
 * SdtSection::Service                                                       *
 *****************************************************************************/

SdtSection::Service::Service(unsigned char *d, unsigned l) : Chunk(d, l) {
	if (d == NULL) {
		setDescriptorsLoopLength(0); /* initialization */
	}
}

/* --- decoding --- */

unsigned SdtSection::Service::getServiceId() const { /* 16 */
	return (data[0] << 8) | data[1];
}

bool SdtSection::Service::getEitScheduleFlag() const { /* 1 */
	return (data[2] & 0x02) >> 1; /* 0000 0010 */
}

bool SdtSection::Service::getEitPresentFollowingFlag() const { /* 1 */
	return data[2] & 0x01; /* 0000 0001 */
}

unsigned SdtSection::Service::getRunningStatus() const { /* 3 */
	return (data[3] & 0xE0) >> 5; /* 1110 0000 */
}

bool SdtSection::Service::getFreeCaMode() const { /* 1 */
	return (data[3] & 0x10) >> 4; /* 0001 0000 */
}

unsigned SdtSection::Service::getDescriptorsLoopLength() const { /* 12 */
	return ((data[3] & 0x0F) << 8) | data[4];
}

unsigned SdtSection::Service::getDataLength() const {
	return 5 + getDescriptorsLoopLength();
}

bool SdtSection::Service::verify() const {
	/* TODO implement */
	return false;
}

/* --- coding --- */

void SdtSection::Service::setServiceId(unsigned id) { /* 16 */
	data[0] = (id & 0xFF00) >> 8;
	data[1] = id & 0x00FF;
}

void SdtSection::Service::setEitScheduleFlag(bool flag) { /* 1 */
	/* TODO verify */
	data[2] = (data[2] & 0xFD) | (flag << 1); /* 1111 1101 */
}

void SdtSection::Service::setEitPresentFollowingFlag(bool flag) { /* 1 */
	/* TODO verify */
	data[2] = (data[2] & 0xFE) | flag; /* 1111 1110 */
}

void SdtSection::Service::setRunningStatus(unsigned status) { /* 3 */
	/* TODO verify */
	data[3] = (data[3] & 0x1F) | ((status << 5) & 0xE0); /* 1110 0000 */
}

void SdtSection::Service::setFreeCaMode(bool mode) { /* 1 */
	data[3] = (data[3] & 0xEF) | (mode << 4); /* 1110 1111 */
}

/* TODO turn it private ? */
void SdtSection::Service::setDescriptorsLoopLength(unsigned length) {
	data[3] = (data[3] & 0xF0) | ((length >> 8) & 0x0F); /* 0000 1111 */
	data[4] = length & 0xFF;
}

void SdtSection::Service::appendDescriptor(unsigned char *descriptorData, unsigned descriptorDataLength) {
	/* TODO verify */
	unsigned loopLength = getDescriptorsLoopLength();
	memcpy(&data[5 + loopLength], descriptorData, descriptorDataLength);
	setDescriptorsLoopLength(loopLength + descriptorDataLength);
}

void SdtSection::Service::finalize() { /* 6 */
	data[2] = data[2] | 0xFC; /* 1111 1100 */
}
