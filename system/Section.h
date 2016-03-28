/**
 * Milano 2004.06.06-16:17 (YYYY.MM.DD-HH:MM)
 */

#ifndef SECTION_H
#define SECTION_H

#include "Chunk.h"

/**
 * Section
 * The getters don't verify if its fields were set previously so make sure they
 * were.
 */

class Section : public Chunk {
public:
	static const unsigned MAX_LENGTH = 4096;
	
	Section(unsigned char *d, unsigned l);
	Section();
	Section(const Section &s);
	~Section();
	Section &operator=(const Section &s);
	
	/* --- section decoding --- */
	
	unsigned getTableId() const; /* 8 */
	bool getSectionSyntaxIndicator() const; /* 1 */
	bool getPrivateIndicator() const; /* 1 */
	unsigned getSectionLength() const; /* 12 */
	
	/**
	 * Inform, in bytes, the length that is needed to accommodate the section.
	 * Note: Make sure that the section length was set properly.
	 */
	unsigned getDataLength() const; /* overwrite */
	
	/**
	 * Verify if the section is well formed
	 * @return True if it is well formed, false otherwise.
	 */
	bool verify() const; /* overwrite */
	
	/* --- section coding --- */
	
	void setSectionLength(unsigned length); /* 12 */
	
	void finalize(); /* overwrite */

protected:
	/**
	 * Set the table id, it is a protected method because sub classes should
	 * specify this value.
	 */
	void setTableId(unsigned id); /* 8 */
	
	/**
	 * Set the section syntax indicator, it is a protected method because sub
	 * classes should specify this value.
	 */
	void setSectionSyntaxIndicator(bool indicator); /* 1 */
	
	/**
	 * Set the private indicator, it is a protected method because sub classes
	 * should specify this value.
	 */
	void setPrivateIndicator(bool indicator); /* 1 */
};

#endif /* SECTION_H */
