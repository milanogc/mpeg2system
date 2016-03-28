/**
 * Milano 2004.06.06-16:17 (YYYY.MM.DD-HH:MM)
 * TODO check for bugs
 */

#include "Section.h"
#include <string>
#include <cassert>

Section::Section(unsigned char *d, unsigned l) : Chunk(d, l) {
}

Section::Section() : Chunk(NULL, MAX_LENGTH) {
	setSectionLength(0); /* min length */
}

//Section::Section(const Section &s) : Chunk(s) {
//}

Section::~Section() {
}

//Section &Section::operator=(const Section &s) {
//	Chunk::operator=(s);
//}

/* --- BEGIN section decoding --- */

unsigned Section::getTableId() const { /* 8 */
	return getByte(0);
}

bool Section::getSectionSyntaxIndicator() const { /* 1 */
	return getByte(1) & 0x80;
}

bool Section::getPrivateIndicator() const { /* 1 */
	return getByte(1) & 0x40;
}

unsigned Section::getSectionLength() const { /* 12 */
	unsigned sectionLength = ((getByte(1) & 0x0F) << 8) | getByte(2);
	/* ITU-T H.222.0 2.4.4.11 page 48 (private section length) */
	assert(sectionLength <= 4093);
	
	return sectionLength;
}

unsigned Section::getDataLength() const {
	return getSectionLength() + 3;
}

bool Section::verify() const {
	return true; /* not sure */
}

/* END section decoding */

/* --- BEGIN section coding --- */

void Section::setTableId(unsigned id) { /* 8 */
	assert(id <= 0xFF);
	setByte(0, 0xFF & id);
}

void Section::setSectionSyntaxIndicator(bool indicator) { /* 1 */
	setByte(1, (getByte(1) & 0x7F) | ((indicator & 0x01) << 7));
}

void Section::setPrivateIndicator(bool indicator) { /* 1 */
	setByte(1, (getByte(1) & 0xBF) | ((indicator & 0x01) << 6));
}

void Section::setSectionLength(unsigned length) { /* 12 */
	assert(length <= MAX_LENGTH - 3);
	setByte(1, (length >> 8) & 0x0F);
	setByte(2, length & 0xFF);
}

void Section::finalize() {
	/* reserved 2 (after section_syntax_indicator) */
	setByte(1, getByte(1) | 0x30); /* 0011 0000 */
}
