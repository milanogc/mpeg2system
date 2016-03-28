/**
 * Milano 2004.06.07-06:07 (YYYY.MM.DD-HH:MM)
 */

#ifndef PMTSECTION_H
#define PMTSECTION_H

#include "PsiSection.h"
#include "Descriptor.h"
#include "Iterator.h"

class PmtSection : public PsiSection {
public:
	class Stream;
	static const unsigned TABLE_ID = 0x2;
	
	PmtSection(unsigned char *d, unsigned l);
	PmtSection();
	
	/* --- decoding --- */
	
	unsigned getProgramNumber() const;
	int getPcrPid() const;
	unsigned getProgramInfoLength() const;
	Iterator<Descriptor> *getDescriptorsIterator() const;
	Iterator<Stream> *getStreamsIterator() const;
	bool verify() const;
	
	/* --- coding --- */
	
	void setProgramNumber(unsigned id); /* 16 */
	void setPcrPid(int pid);
	void setProgramInfoLength(unsigned length);
	void appendDescriptor(unsigned char *descriptorData, unsigned descriptorLength); /* TODO implement */
	void appendDescriptor(Descriptor &descriptorData); /* TODO implement */
	void appendStream(unsigned char *streamData, unsigned streamLength);
	void appendStream(Stream &stream);
	void finalize();
};

/*****************************************************************************
 * PmtSection::Stream                                                        *
 *****************************************************************************/

class PmtSection::Stream : public Chunk {
public:
	static const unsigned MIN_LENGTH = 5;
	
	Stream(unsigned char *d, unsigned l);
	Stream(unsigned char *d);
	Stream();
	
	/* --- decoding --- */
	
	unsigned getStreamType() const; /* 8 */
	int getElementaryPid() const; /* 13 */
	unsigned getEsInfoLength() const; /* 12 */
	Iterator<Descriptor> *getDescriptorsIterator() const;
	
	unsigned getDataLength() const;
	bool verify() const;
	
	/* --- coding --- */
	
	void setStreamType(unsigned type); /* 8 */
	void setElementaryPid(int pid); /* 13 */
	void setEsInfoLength(unsigned length); /* 12 */
	void appendDescriptor(unsigned char *descriptorData, unsigned descriptorDataLength);
	void appendDescriptor(Descriptor &descriptor);
	
	void finalize();
};

#endif /* PMTSECTION_H */
