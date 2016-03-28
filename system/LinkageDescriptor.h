#ifndef LINKAGEDESCRIPTOR_H
#define LINKAGEDESCRIPTOR_H

#include "Descriptor.h"

class LinkageDescriptor : public Descriptor {
public:
	class Platform; /* inner class */
	static const unsigned TAG = 0x4A;
	
	LinkageDescriptor(unsigned char *d, unsigned l);
	
	/* --- decoding --- */
	unsigned getTransportStreamId() const; /* 16 */
	unsigned getOriginalNetworkId() const; /* 16 */
	unsigned getServiceId() const; /* 16 */
	unsigned getLinkageType() const; /* 8 */ /* 0x0B */
	unsigned getPlatformIdDataLength() const; /* 8 */
	bool verify() const;
	
	/* --- coding --- */
	void setTransportStreamId(unsigned id);
	void setOriginalNetworkId(unsigned id);
	void setServiceId(unsigned id);
	void setLinkageType(unsigned type);
	void setPlatformIdDataLength(unsigned length);
	void appendPlatforms(const unsigned char *platformData, unsigned platformDataLength);
	void finalize();
};

/*****************************************************************************
 * LinkageDescriptor::Platform                                              *
 *****************************************************************************/

class LinkageDescriptor::Platform : public Chunk {
	public:
		class PlatformName;
		
		Platform(unsigned char *d, unsigned l);
		
		/* --- decoding --- */
		unsigned getPlatformId() const; /* 24 */
		unsigned getPlatformNameLoopLength() const; /* 8 */
		
		/* --- coding --- */
		void setPlatformId(unsigned id); /* 24 */
		void setPlatformNameLoopLength(unsigned length); /* 8 */
};

/*****************************************************************************
 * LinkageDescriptor::Platform::PlatformName                               *
 *****************************************************************************/

class LinkageDescriptor::Platform::PlatformName : public Chunk {
	public:
		PlatformName(unsigned char *d, unsigned l);
		
		/* --- decoding --- */
		unsigned getIso639LanguageCode() const; /* 24 */
		unsigned getPlatformNameLength() const; /* 8 */
		const unsigned char *getText() const;
		
		/* --- coding --- */
		void setIso639LanguageCode(unsigned code); /* 24 */
		void setPlatformNameLength(unsigned length); /* 8 */
		void setText(const unsigned char *text);
};

#endif /* LINKAGEDESCRIPTOR_H */
