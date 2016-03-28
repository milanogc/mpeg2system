/**
 * Milano 2004.06.08-19:24 (YYYY.MM.DD-HH:MM)
 */

#ifndef MPEINFO_H
#define MPEINFO_H

#include "Chunk.h"

class MpeInfo : public Chunk {
	public:
		MpeInfo(unsigned char *d);
		
		/* --- decoding --- */
		
		unsigned getMacAddressRange() const; /* 3 */
		bool getMacIpMappingFlag() const; /* 1 */
		bool getAlignmentIndicator() const; /* 8 */
		unsigned getMaxSectionsPerDatagram() const;
		unsigned getDataLength() const;
		bool verify() const;
		
		/* --- coding --- */
		
		void setMacAddressRange(unsigned range); /* 3 */
		void setMacIpMappingFlag(bool flag); /* 1 */
		void setAlignmentIndicator(bool indicator); /* 8 */
		void setMaxSectionsPerDatagram(unsigned max);
		void finalize();
};

#endif /* MPEINFO_H */
