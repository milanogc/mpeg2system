/**
 * Milano 2004.06.07-06:07 (YYYY.MM.DD-HH:MM)
 */

#ifndef NITSECTION_H
#define NITSECTION_H

#include "PsiSection.h"
#include "Descriptor.h"

class NitSection : public PsiSection {
	public:
		class TransportStream;
		
		NitSection(unsigned char *d, unsigned l);
		
		/* --- decoding --- */
		
		unsigned getNetworkId() const; /* 16 */
		unsigned getNetworkDescriptorsLength() const; /* 12 */
		unsigned getTransportStreamLoopLength() const; /* 12 */
		bool verify() const;
		
		/* --- coding ---  */
		
		void setNetworkId(unsigned id); /* 16 */
		void setNetworkDescriptorsLength(unsigned length); /* 12 */
		void insertDescriptor(Descriptor *descriptor); /* TODO change to appendDescriptor */
		void setTransportStreamLoopLength(unsigned length); /* 12 */
		void finalize();
};

/*****************************************************************************
 * NitSection::TransportStream                                               *
 *****************************************************************************/

class NitSection::TransportStream : public Chunk {
	public:
		TransportStream(unsigned char *d, unsigned l);
		
		unsigned getDataLength() const;
		
		/* --- decoding ---  */
		
		unsigned getTransportStreamId() const; /* 16 */
		unsigned getOriginalNetworkId() const; /* 16 */
		unsigned getTransportDescriptorsLength() const; /* 12 */
		
		/* --- coding ---  */
		
		void setTransportStreamId(unsigned id); /* 16 */
		void setOriginalNetworkId(unsigned id); /* 16 */
		void setTransportDescriptorsLength(unsigned length); /* 12 */
		
		void finalize();
};

#endif /* NITSECTION_H */
