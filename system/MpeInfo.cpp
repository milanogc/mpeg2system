/**
 * Milano 2004.06.08-19:24 (YYYY.MM.DD-HH:MM)
 */

#include "MpeInfo.h"

MpeInfo::MpeInfo(unsigned char *d) : Chunk(d, 2) {
}

/* --- decoding --- */

unsigned MpeInfo::getMacAddressRange() const { /* 3 */
	return (data[0] & 0xE0) >> 5; /* 1110 0000 */
}

bool MpeInfo::getMacIpMappingFlag() const { /* 1 */
	return (data[0] & 0x10) >> 4; /* 0001 0000 */
}

bool MpeInfo::getAlignmentIndicator() const { /* 1 */
	return (data[0] & 0x08) >> 3; /* 0000 1000 */
}

unsigned MpeInfo::getMaxSectionsPerDatagram() const {
	return data[1];
}

unsigned MpeInfo::getDataLength() const {
	return 2;
}

bool MpeInfo::verify() const {
	return false; /* TODO implement */
}

/* --- coding --- */

void MpeInfo::setMacAddressRange(unsigned range) { /* 3 */
	data[0] = (data[0] & 0x1F) | ((range & 0x07) << 5); /* 1110 0000 */
}

void MpeInfo::setMacIpMappingFlag(bool flag) { /* 1 */
	data[0] = (data[0] & 0xEF ) | (flag << 4); /* 0001 0000 */
}

void MpeInfo::setAlignmentIndicator(bool indicator) { /* 1 */
	data[0] = (data[0] & 0xF7) | (indicator << 3); /* 0000 1000 */
}

void MpeInfo::setMaxSectionsPerDatagram(unsigned max) {
	data[1] = max & 0xFF;
}

void MpeInfo::finalize() {
	/* reserved */
	data[0] = data[0] | 0x7;
}
