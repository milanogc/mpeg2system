/**
 * Milano 2004.06.07-06:07 (YYYY.MM.DD-HH:MM)
 */

#ifndef PATSECTION_H
#define PATSECTION_H

#include "PsiSection.h"
#include "Iterator.h"

class PatSection : public PsiSection {
	public:
		class Program;
		static const unsigned TABLE_ID = 0x0;
		
		PatSection(unsigned char *d, unsigned l);
		PatSection();
		~PatSection();
		
		Iterator<Program> *getProgramsIterator() const;
		
		/* --- decoding --- */
		
		unsigned getTransportStreamId() const;
		bool verify() const;
		
		/* --- coding --- */
		
		void setTransportStreamId(unsigned id);
		void appendProgram(unsigned char *programData, unsigned programDataLength);
		
		void finalize();
};

/*****************************************************************************
 * PatSection::Program                                                       *
 *****************************************************************************/

class PatSection::Program : public Chunk {
	public:
		static const unsigned LENGTH = 4;
		
		/**
		 *  This constructor doesn't need the data's size because it must be equals to PatSection::Program::LENGTH.
		 */
		Program(unsigned char *d);
		Program();
		~Program();
		
		/* --- decoding --- */
		
		unsigned getProgramNumber() const; /* 16 */
		int getPid() const; /* 13 */
		unsigned getDataLength() const;
		bool verify() const;
		
		/* --- coding --- */
		
		void setProgramNumber(unsigned number); /* 16 */
		void setPid(int pid); /* 13 */
		void finalize();
};

#endif /* PATSECTION_H */
