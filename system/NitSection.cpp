#include "NitSection.h"
#include <string>

NitSection::NitSection(unsigned char *d, unsigned l) : PsiSection(d, l) {
}

/* --- decoding --- */

unsigned NitSection::getNetworkId() const { /* 16 */
	return getTableIdExtension();
}

unsigned NitSection::getNetworkDescriptorsLength() const { /* 12 */
	return ((data[8] & 0x0F) << 8) | data[9];
}

unsigned NitSection::getTransportStreamLoopLength() const { /* 12 */
	/* TODO verify */
	unsigned length = getNetworkDescriptorsLength();
	return ((data[10 + length] & 0x0F) << 8) | data[11 + length];
}

bool NitSection::verify() const {
	/* TODO implement */
	return PsiSection::verify();
}

/* --- coding ---  */

void NitSection::setNetworkId(unsigned id) { /* 16 */
	setTableIdExtension(id);
}

void NitSection::setNetworkDescriptorsLength(unsigned length) { /* 12 */
	/* TODO verify */
	data[8] = data[8] | ((length & 0x0F00) >> 8);
	data[9] = length & 0xFF;
}

/**
 * It changes section_length and network_descriptors_length.
 * TODO: Up to now it is inserting the descriptor only at the beginning.
 */
void NitSection::insertDescriptor(Descriptor *descriptor) {
	/* TODO verify */
	unsigned descLength = descriptor->getDataLength();
	
	/* TODO verify the range */
	for (int i = getDataLength() - 4 /* crc32 */; i != 9 ; i--) /* reverse copy */
		data[i + descLength] = data[i];
	
	memcpy(data + 10, descriptor->getData(), descLength); /* TODO verify */
	setSectionLength(getSectionLength() + descLength);
	setNetworkDescriptorsLength(getNetworkDescriptorsLength() + descLength);
}

void NitSection::setTransportStreamLoopLength(unsigned length) { /* 12 */
	/* TODO verify */
	unsigned descLength = getNetworkDescriptorsLength();
	data[10 + descLength] = data[10 + descLength] | ((length & 0x0F00) >> 8);
	data[11 + descLength] = length & 0xFF;
}

void NitSection::finalize() {
	/* TODO verify */
	setPrivateIndicator(true); /* reserved future use 1 */
	
	/* reserved future use 4 */
	data[8] = data[8] | 0xF0;
	
	/* reserved future use 4 */
	unsigned descLength = getNetworkDescriptorsLength();
	data[10 + descLength] = data[10 + descLength] | 0xF0;
	
	PsiSection::finalize();
}

/*****************************************************************************
 * NitSection::TransportStream                                               *
 *****************************************************************************/

NitSection::TransportStream::TransportStream(unsigned char *d, unsigned l) : Chunk(d, l) {
}

unsigned NitSection::TransportStream::getDataLength() const {
	return 6 + getTransportDescriptorsLength();
}

/* --- decoding ---  */

unsigned NitSection::TransportStream::getTransportStreamId() const { /* 16 */
	/* TODO verify */
	return (data[0] << 8) | data[1];
}

unsigned NitSection::TransportStream::getOriginalNetworkId() const { /* 16 */
	/* TODO verify */
	return (data[2] << 8) | data[3];
}

unsigned NitSection::TransportStream::getTransportDescriptorsLength() const { /* 12 */
	return ((data[4] & 0x0F) << 8) | data[5];
}

/* --- coding ---  */

void NitSection::TransportStream::setTransportStreamId(unsigned id) { /* 16 */
	/* TODO verify */
	data[0] = (id & 0xFF00) >> 8;
	data[1] = id & 0xFF;
}

void NitSection::TransportStream::setOriginalNetworkId(unsigned id) { /* 16 */
	/* TODO verify */
	data[2] = (id & 0xFF00) >> 8;
	data[3] = id & 0xFF;
}

void NitSection::TransportStream::setTransportDescriptorsLength(unsigned length) { /* 12 */
	/* TODO verify */
	data[4] = (length & 0x0F00) >> 8;
	data[5] = length & 0xFF;
}

void NitSection::TransportStream::finalize() {
	/* TODO verify */
	/* reserved_future_use */
	data[4] = data[4] | 0xF0;
}
