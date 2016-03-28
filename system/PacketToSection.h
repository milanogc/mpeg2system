#ifndef PACKETTOSECTION_H
#define PACKETTOSECTION_H

#include "TSPacket.h"
#include "PsiSection.h"

class PacketToSection {
public:
	PacketToSection();
	~PacketToSection();
	
	bool isComplete() const;
	PsiSection *getSection() const;
	
	void reset();
	void appendPacket(TSPacket *packet);

private:
	unsigned pos;
	int pid;
	unsigned continuityCounter;
	PsiSection *section;
	
	unsigned char *skipPointerField(unsigned char *payload, unsigned &payloadLength);
};

#endif // PACKETTOSECTION_H
