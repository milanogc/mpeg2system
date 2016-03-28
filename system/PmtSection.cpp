/**
 * Milano 2004.06.07-06:07 (YYYY.MM.DD-HH:MM)
 */

#include "PmtSection.h"
#include <string>
#include <cassert>

PmtSection::PmtSection(unsigned char *d, unsigned l) : PsiSection(d, l) {
}

PmtSection::PmtSection() : PsiSection() {
	setSectionLength(13); /* min length */
}

/* --- decoding --- */

unsigned PmtSection::getProgramNumber() const {
	unsigned programNumber = getTableIdExtension();
	assert(programNumber < 1016); /* The program number should never be longer than 1016 */
	
	return programNumber;
}

int PmtSection::getPcrPid() const { /* 13 */
	return ((data[8] & 0x1F) << 8) | data[9]; /* 0001 1111 */
}

unsigned PmtSection::getProgramInfoLength() const { /* 12 */
	unsigned programInfoLength = ((data[10] & 0x0F) << 8) | data[11]; /* 0000 1111 */
	assert((programInfoLength >> 10) == 0x0); /* "The first two bits of the program info length is not '00'. */
	
	return programInfoLength;
}

Iterator<Descriptor> *PmtSection::getDescriptorsIterator() const {
	unsigned programInfoLength = getProgramInfoLength();
	
	if (programInfoLength != 0) {
		return new Iterator<Descriptor>(&data[12], programInfoLength);
	}
	else {
		return NULL;
	}
}

Iterator<PmtSection::Stream> *PmtSection::getStreamsIterator() const {
	unsigned programInfoLength = getProgramInfoLength();
	unsigned streamsLength = getSectionLength() - 13 - getProgramInfoLength();
	
	if (streamsLength != 0) {
		return new Iterator<PmtSection::Stream>(&data[12 + programInfoLength], streamsLength);
	}
	else {
		return NULL;
	}
}

bool PmtSection::verify() const {
	if (getPrivateIndicator())
		return false;
	
	if (getTableId() != TABLE_ID)
		return false;
	
	return PsiSection::verify();
}

/* --- coding --- */

void PmtSection::setProgramNumber(unsigned id) { /* 16 */
	setTableIdExtension(id);
}

void PmtSection::setPcrPid(int pid) { /* 13 */
	data[8] = (data[8] & 0xE0) | ((pid >> 8) & 0x1F); /* 0001 1111 */
	data[9] = pid & 0xFF;
}

void PmtSection::setProgramInfoLength(unsigned length) {
	data[10] = (data[10] & 0xF0) | ((length >> 8) & 0x0F); /* 0000 1111 */
	data[11] = length & 0xFF;
}

void PmtSection::appendDescriptor(unsigned char *descriptorData, unsigned descriptorDataLength) {
	/* TODO implement */
}

void PmtSection::appendDescriptor(Descriptor &descriptor) {
	appendDescriptor(descriptor.getData(), descriptor.getDataLength());
}

void PmtSection::appendStream(unsigned char *streamData, unsigned streamDataLength) {
	unsigned sectionLength = getSectionLength(); /* actual section length */
	appendData(3 /* before */ + sectionLength - 4 /* crc */, streamData, streamDataLength);
}

void PmtSection::appendStream(Stream &stream) {
	appendStream(stream.getData(), stream.getDataLength());
}

void PmtSection::finalize() {
	/* reserved after last_section_number: 3 */
	data[8] = data[8] | 0xE0; /* 1110 0000 */
	
	/* reserved after PCR_PID: 4 */
	data[10] = data[10] | 0xF0; /* 1111 0000 */
	
	/* TODO finalize each descriptor ? */
	
	/* TODO finalize each stream ? */
		
	setTableId(TABLE_ID);
	setSectionNumber(0x0);
	setLastSectionNumber(0x0);
	PsiSection::finalize(); /* crc32... */
}

/*****************************************************************************
 * PmtSection::Stream                                                        *
 *****************************************************************************/

PmtSection::Stream::Stream(unsigned char *d, unsigned l) : Chunk(d, l) {
	if (d == NULL) {
		setEsInfoLength(0); /* initial value, to inform that the loop is empty */
	}
}

PmtSection::Stream::Stream(unsigned char *d) : Chunk(d, 0) {
	assert (d != NULL);
}

PmtSection::Stream::Stream() : Chunk(NULL, 1029) {
	setEsInfoLength(0); /* initial value, to inform that the loop is empty */
}

/* --- decoding --- */

unsigned PmtSection::Stream::getStreamType() const { /* 8 */
	return data[0];
}

int PmtSection::Stream::getElementaryPid() const { /* 13 */
	return ((data[1] & 0x1F) << 8) | data[2]; /* 0001 1111 */
}

unsigned PmtSection::Stream::getEsInfoLength() const { /* 12 */
	return ((data[3] & 0x0F) << 8) | data[4]; /* 0000 1111 */
}

Iterator<Descriptor> *PmtSection::Stream::getDescriptorsIterator() const {
	unsigned esInfoLength = getEsInfoLength();
	
	if (esInfoLength != 0) {
		return new Iterator<Descriptor>(&data[5], esInfoLength);
	}
	else {
		return NULL;
	}
}

unsigned PmtSection::Stream::getDataLength() const {
	return 5 + getEsInfoLength();
}

bool PmtSection::Stream::verify() const {
	/* TODO implement */
	return false;
}

/* --- coding --- */

void PmtSection::Stream::setStreamType(unsigned type) { /* 8 */
	data[0] = type & 0xFF;
}

void PmtSection::Stream::setElementaryPid(int pid) { /* 13 */
	data[1] = (data[1] & 0xE0) | ((pid >> 8) & 0x1F); /* 0001 1111 */
	data[2] = pid & 0xFF;
}

void PmtSection::Stream::setEsInfoLength(unsigned length) { /* 12 */
	data[3] = (data[3] & 0xF0) | ((length >> 8) & 0x0F); /* 0000 1111 */
	data[4] = length & 0xFF;
}

void PmtSection::Stream::appendDescriptor(unsigned char *descriptorData, unsigned descriptorDataLength) {
	unsigned infoLength = getEsInfoLength(); /* actual length */
	memcpy(&data[5 + infoLength], descriptorData, descriptorDataLength);
	setEsInfoLength(infoLength + descriptorDataLength); /* new section length */
}

void PmtSection::Stream::appendDescriptor(Descriptor &descriptor) {
	appendDescriptor(descriptor.getData(), descriptor.getDataLength());
}

void PmtSection::Stream::finalize() {
	/* reserved 1: 3 */
	data[1] = data[1] | 0xE0; /* 1110 0000 */
	
	/* reserved 2: 3 */
	data[3] = data[3] | 0xF0; /* 1111 0000 */
}
