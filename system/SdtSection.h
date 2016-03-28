/**
 * Milano 2004.06.06-16:17 (YYYY.MM.DD-HH:MM)
 */

#ifndef SDTSECTION_H
#define SDTSECTION_H

#include "PsiSection.h"
#include "Descriptor.h"

class SdtSection : public PsiSection {
	public:
		class Service;
		
		SdtSection(unsigned char *d, unsigned l);
		
		/* --- decoding --- */
		
		unsigned getTransportStreamId() const; /* 16 */
		unsigned getOriginalNetworkId() const; /* 16 */
		bool verify() const;
		
		/* --- coding --- */
		
		void setTransportStreamId(unsigned id); /* 16 */
		void setOriginalNetworkId(unsigned id); /* 16 */
		void appendService(unsigned char *serviceData, unsigned serviceDataLength);
		void finalize();
};

/*****************************************************************************
 * SdtSection::Service                                                       *
 *****************************************************************************/

class SdtSection::Service : public Chunk {
	public:
		Service(unsigned char *d, unsigned l);
		
		/* --- decoding --- */
		
		unsigned getServiceId() const; /* 16 */
		bool getEitScheduleFlag() const; /* 1 */
		bool getEitPresentFollowingFlag() const; /* 1 */
		unsigned getRunningStatus() const; /* 3 */
		bool getFreeCaMode() const; /* 1 */
		unsigned getDescriptorsLoopLength() const; /* 12 */
		unsigned getDataLength() const;
		bool verify() const;
		
		/* --- coding --- */
		
		void setServiceId(unsigned id); /* 16 */
		void setEitScheduleFlag(bool flag); /* 1 */
		void setEitPresentFollowingFlag(bool flag); /* 1 */
		void setRunningStatus(unsigned status); /* 3 */
		void setFreeCaMode(bool mode); /* 1 */
		void setDescriptorsLoopLength(unsigned length);
		void appendDescriptor(unsigned char *descriptorData, unsigned descriptorDataLength);
		void finalize();
};

#endif /* SDTSECTION_H */
