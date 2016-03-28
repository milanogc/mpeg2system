/**
 * Milano 2004.06.07-06:07 (YYYY.MM.DD-HH:MM)
 */

#ifndef PSISECTION_H
#define PSISECTION_H

#include "Section.h"

/**
 * PsiSection implements a MPEG-2 Private Section with the section sintax
 * indicator set to '1'.
 */

class PsiSection : public Section {
	public:
		PsiSection(unsigned char *d, unsigned l);
		PsiSection();
		~PsiSection();
		
		unsigned getTableIdExtension() const; /* 16 */
		unsigned getVersionNumber() const; /* 5 */
		bool getCurrentNextIndicator() const; /* 1 */
		unsigned getSectionNumber() const; /* 8 */
		unsigned getLastSectionNumber() const; /* 8 */
		unsigned char *getPrivateData() const;
		unsigned getCrc32() const; /* 32 */
		
		/* --- decoding --- */
		bool verify() const;
		
		void setTableIdExtension(unsigned id); /* 16 */ /* TODO turn it protected ? */
		void setVersionNumber(unsigned version); /* 5 */
		void setCurrentNextIndicator(bool indicator); /* 1 */
		
		/**
		 * Set the current section number of the current table. A table is a composite
		 * of a number of sections.
		 */
		void setSectionNumber(unsigned number); /* 8 */
		
		/**
		 * Set the last section number of the current table. A table is a composite of a
		 * number of sections.
		 */
		void setLastSectionNumber(unsigned number); /* 8 */
		
		/**
		 * Finalize a section. It fills the reserved fields with the proper values and
		 * set the recalculated crc 32.
		 */
		
		/* --- coding -- */
		void finalize(); /* overwrite */
	
	protected:
		void appendData(unsigned pos, unsigned char *newData, unsigned newDataLength);
};

#endif /* PSISECTION_H */
