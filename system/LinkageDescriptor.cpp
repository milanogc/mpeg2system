#include "LinkageDescriptor.h"
#include <string>

LinkageDescriptor::LinkageDescriptor(unsigned char *d, unsigned l) : Descriptor(d, l) {
}

/* --- decoding --- */

unsigned LinkageDescriptor::getTransportStreamId() const { /* 16 */
	/* TODO verify */
	return (data[2] << 8) | data[3];
}

unsigned LinkageDescriptor::getOriginalNetworkId() const { /* 16 */
	/* TODO verify */
	return (data[4] << 8) | data[5];
}

unsigned LinkageDescriptor::getServiceId() const { /* 16 */
	/* TODO verify */
	return (data[6] << 8) | data[7];
}

unsigned LinkageDescriptor::getLinkageType() const { /* 8 */ /* 0x0B */
	/* TODO verify */
	return data[8];
}

unsigned LinkageDescriptor::getPlatformIdDataLength() const { /* 8 */
	/* TODO verify */
	return data[9];
}

bool LinkageDescriptor::verify() const {
	/* TODO is it ok? */
	if (getDescriptorTag() != TAG)
		return false;
	
	return true;
}

/* --- coding --- */

void LinkageDescriptor::setTransportStreamId(unsigned id) { /* 16 */
	/* TODO verify */
	data[2] = (id & 0xFF00) >> 8;
	data[3] = id & 0xFF;
}

void LinkageDescriptor::setOriginalNetworkId(unsigned id) { /* 16 */
	/* TODO verify */
	data[4] = (id & 0xFF00) >> 8;
	data[5] = id & 0xFF;
}

void LinkageDescriptor::setServiceId(unsigned id) { /* 16 */
	/* TODO verify */
	data[6] = (id & 0xFF00) >> 8;
	data[7] = id & 0xFF;
}

void LinkageDescriptor::setLinkageType(unsigned type) { /* 8 */ /* 0x0B */
	/* TODO verify */
	data[8] = type;
}

void LinkageDescriptor::setPlatformIdDataLength(unsigned length) { /* 8 */
	/* TODO verify */
	data[9] = length;
}

/**
 *  Obs.: It discards the private data bytes.
 */
void LinkageDescriptor::appendPlatforms(const unsigned char *platformData, unsigned platformDataLength) {
	/* TODO verify */
	unsigned descLength = getDescriptorLength();
	memcpy(&data[2 + descLength], platformData, platformDataLength);
	setDescriptorLength(descLength + platformDataLength);
	setPlatformIdDataLength(getPlatformIdDataLength() + platformDataLength);
}

void LinkageDescriptor::finalize() {
	/* TODO verify */
	setDescriptorTag(TAG);
	Descriptor::finalize();
}

/*****************************************************************************
 * LinkageDescriptor::Platform                                              *
 *****************************************************************************/

LinkageDescriptor::Platform::Platform(unsigned char *d, unsigned l) : Chunk(d, l) {
}

/* --- decoding --- */

unsigned LinkageDescriptor::Platform::getPlatformId() const { /* 24 */
	return (data[0] << 16) | (data[1] << 8) | data[2];
}

unsigned LinkageDescriptor::Platform::getPlatformNameLoopLength() const { /* 8 */
	return data[3];
}

/* --- coding --- */

void LinkageDescriptor::Platform::setPlatformId(unsigned id) { /* 24 */
	data[0] = (id & 0xFF0000) >> 16;
	data[1] = (id & 0x00FF00) >> 8;
	data[2] = id & 0x0000FF;
}

void LinkageDescriptor::Platform::setPlatformNameLoopLength(unsigned length) { /* 8 */
	data[3] = length;
}

 /*****************************************************************************
 * LinkageDescriptor::Platform::PlatformName                               *
 *****************************************************************************/

LinkageDescriptor::Platform::PlatformName::PlatformName(unsigned char *d, unsigned l) : Chunk(d, l) {
}


/* --- decoding --- */

unsigned LinkageDescriptor::Platform::PlatformName::getIso639LanguageCode() const { /* 24 */
	return (data[0] << 16) | (data[1] << 8) | data[2];
}

unsigned LinkageDescriptor::Platform::PlatformName::getPlatformNameLength() const { /* 8 */
	return data[3];
}

const unsigned char *LinkageDescriptor::Platform::PlatformName::getText() const {
	return &data[4];
}

/* --- coding --- */

void LinkageDescriptor::Platform::PlatformName::setIso639LanguageCode(unsigned code) { /* 24 */
	data[0] = (code & 0xFF0000) >> 16;
	data[1] = (code & 0x00FF00) >> 8;
	data[2] = code & 0x0000FF;
}

void LinkageDescriptor::Platform::PlatformName::setPlatformNameLength(unsigned length) { /* 8 */
	data[3] = length;
}

void LinkageDescriptor::Platform::PlatformName::setText(const unsigned char *text) {
	memcpy(&data[4], text, getPlatformNameLength());
}
