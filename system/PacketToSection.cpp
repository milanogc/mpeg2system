#include "PacketToSection.h"
#include <string>
#include <cassert>

PacketToSection::PacketToSection()
{
	section = new PsiSection();
	reset();
}

PacketToSection::~PacketToSection()
{
	delete section;
}

bool PacketToSection::isComplete() const {
	return section->getSectionLength() <= pos + 0;
}

PsiSection *PacketToSection::getSection() const {
	assert(isComplete());
	return section;
}

void PacketToSection::reset() {
	pos = 0;
}

void PacketToSection::appendPacket(TSPacket *packet) {
	if (pos == 0) {
		if (!packet->getPayloadUnitStartIndicator()) {
			return;
		}
		
		pid = packet->getPid();
	}
	else {
		if (packet->getPid() != pid) {
			return;
		}
		
		/* discontinuity ? */
		if ((continuityCounter + 1) % 16 != packet->getContinuityCounter()) {
			if (packet->getPayloadUnitStartIndicator()) {
				reset();
			}
			else {
				return;
			}
		}
	}
	
	continuityCounter = packet->getContinuityCounter();
	
	unsigned payloadLength;
	unsigned char *payload = packet->getPayload(payloadLength);
	
	if (pos == 0) {
		memcpy(section->getPrivateData() + pos, payload, payloadLength);
	}
	else {
		memcpy(section->getPrivateData() + pos, payload, payloadLength);
	}
	
	pos += payloadLength;
}
