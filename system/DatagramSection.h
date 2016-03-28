#ifndef DATAGRAMSECTION_H
#define DATAGRAMSECTION_H

#include "PsiSection.h"

class DatagramSection : public PsiSection {
public:
	DatagramSection(unsigned char *d, unsigned l);
	~DatagramSection();
	
	/* --- decoding --- */
	unsigned char *getMacAddress() const;
	bool verify() const;
	
	/* --- coding --- */
	void setMacAddress(unsigned char address[]);
	void setPayloadScramblingControl(unsigned control);
	void setAddressScramblingControl(unsigned control);
	void setLlcSnapFlag(bool flag);
	void setDatagramBytes(unsigned char *datagram, unsigned length);
	void finalize();
};

#endif // DATAGRAMSECTION_H
