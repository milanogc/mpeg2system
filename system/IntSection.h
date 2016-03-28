/**
 * Milano 2004.06.06-16:17 (YYYY.MM.DD-HH:MM)
 */

#ifndef INTSECTION_H
#define INTSECTION_H

#include "PsiSection.h"

class IntSection : public PsiSection {
	public:
		IntSection(unsigned char *d, unsigned l);
		
		/* --- decoding --- */
		
		unsigned getActionType() const; /* 8 */
		unsigned getPlatformIdHash() const; /* 8 */
		unsigned getPlatformId() const; /* 24 */
		unsigned getProcessingOrder() const; /* 8 */
		bool verify() const;
		
		/* --- coding --- */
		void setActionType(unsigned action); /* 8 */
		void setPlatformId(unsigned id); /* 24 */
		void setProcessingOrder(unsigned order); /* 8 */
		void appendLoop(const unsigned char *loopData, unsigned loopDataLength);
		void finalize();
};

#endif /* INTSECTION_H */
