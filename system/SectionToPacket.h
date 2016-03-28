#include "Section.h"
#include "TSPacket.h"

#ifndef SECTIONTOPACKET_H
#define SECTIONTOPACKET_H

class SectionToPacket {
public:
	SectionToPacket();
	
	void setSection(Section *s);
	bool hasNextPacket() const;
	void getNextPacket(TSPacket *packet);

private:
	Section *section;
	unsigned sectionLength;
	unsigned readPos;
};

#endif // SECTIONTOPACKET
