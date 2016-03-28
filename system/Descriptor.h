/**
 * Milano 2004.06.07-06:07 (YYYY.MM.DD-HH:MM)
 */

#ifndef DESCRIPTOR_H
#define DESCRIPTOR_H

#include "Chunk.h"

class Descriptor : public Chunk {
public:
	static const unsigned MAX_LENGTH = 258;
	
	Descriptor(unsigned char *d, unsigned l);
	Descriptor(unsigned char *d);
	Descriptor();
	~Descriptor();
	
	unsigned getDataLength() const; /* overwrite */
	
	/* decoding */
	unsigned getDescriptorTag() const; /* 8 */
	unsigned getDescriptorLength() const; /* 8 */
	bool verify() const;
	
	/* coding */
	void finalize();

protected:
	void setDescriptorTag(unsigned tag); /* 8 */
	void setDescriptorLength(unsigned length); /* 8 */
};

#endif /* DESCRIPTOR_H */
