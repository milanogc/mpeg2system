/**
 * Milano 2004.06.07-06:07 (YYYY.MM.DD-HH:MM)
 */

#ifndef STREAMIDENTIFIERDESCRIPTOR_H
#define STREAMIDENTIFIERDESCRIPTOR_H

#include "Descriptor.h"

class StreamIdentifierDescriptor : public Descriptor {
public:
	static const unsigned TAG = 0x52;
	
	StreamIdentifierDescriptor(unsigned char *d);
	StreamIdentifierDescriptor();
	
	/* --- decoding --- */
	
	unsigned getComponentTag() const;
	bool verify() const;
	
	/* --- coding --- */
	
	void setComponentTag(unsigned tag);
	void finalize(); /* overwrite */
};

#endif /* STREAMIDENTIFIERDESCRIPTOR_H */
