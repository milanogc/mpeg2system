#include "SectionToPacket.h"
#include <string>

SectionToPacket::SectionToPacket() : section(NULL), sectionLength(0), readPos(0)
{
}

/**
 * Sets a section to be arranged into packets.
 * @param s The section.
 */
void SectionToPacket::setSection(Section *s) {
	section = s;
	
	if (section != NULL && section->verify())
		sectionLength = section->getDataLength();
	else
		sectionLength = 0;
	
	readPos = 0;
}

/**
 * Informs if there is more packets available to be get.
 * @return true if there is more packets available, false otherwise.
 */
bool SectionToPacket::hasNextPacket() const {
	return readPos < sectionLength;
}

/**
 * Get the next packet from the current section conversion.
 * @param packet The packet to be filled. Note that the only part of the packet
 * that is changed is its payload.
 */
void SectionToPacket::getNextPacket(TSPacket *packet) {
	if (hasNextPacket()) {
		unsigned payloadLength;
		unsigned char *payloadData = packet->getPayload(payloadLength);
		
		memset(&payloadData[0], 0xFF, payloadLength); /* TODO optimize */
		
		if (readPos == 0) {
			payloadData[0] = 0; /* pointer field */
			memcpy(&payloadData[1], section->getData(), payloadLength - 1);
			readPos += payloadLength - 1;
		}
		else {
			memcpy(&payloadData[0], section->getData() + readPos, payloadLength);
			readPos += payloadLength;
		}
		
		packet->finalize();
	}
}
