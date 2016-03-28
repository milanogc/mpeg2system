/**
 * Milano 2004.06.07-06:07 (YYYY.MM.DD-HH:MM)
 */

#include "PsiSection.h"
#include "crc.h"
#include <string>
#include <cassert>

PsiSection::PsiSection(unsigned char *d, unsigned l) : Section(d, l) {
}

PsiSection::PsiSection() : Section() {
	setSectionLength(9); /* min length */
}

PsiSection::~PsiSection() {
}

unsigned PsiSection::getTableIdExtension() const { /* 16 */
	return (getByte(3) << 8) | getByte(4);
}

unsigned PsiSection::getVersionNumber() const { /* 5 */
	return (getByte(5) & 0x3E) >> 1; /* 0011 1110 */
}

bool PsiSection::getCurrentNextIndicator() const { /* 1 */
	return getByte(5) & 0x01; /* 0000 0001 */
}

unsigned PsiSection::getSectionNumber() const { /* 8 */
	return getByte(6);
}

unsigned PsiSection::getLastSectionNumber() const { /* 8 */
	return getByte(7);
}

unsigned char *PsiSection::getPrivateData() const {
	return &getByte(8);
}

unsigned PsiSection::getCrc32() const { /* 32 */
	/* TODO is it necessary? */
	unsigned sectionLength = getSectionLength();
	return (getByte(sectionLength - 1) << 24) | (getByte(sectionLength) << 16) | (getByte(sectionLength + 1) << 8) | getByte(sectionLength + 2);
}

bool PsiSection::verify() const {
	if (Section::verify() && getSectionSyntaxIndicator()) /* crc32 exists */
		return getCrc32() == calculateCrc(data, getSectionLength() - 1);
	
	return false;
}

void PsiSection::setTableIdExtension(unsigned id) { /* 16 */
	assert(id <= 0xFFFF);
	setByte(3, (id & 0xFF00) >> 8);
	setByte(4, id & 0x00FF);
}

void PsiSection::setVersionNumber(unsigned version) { /* 5 */
	assert(version <= 0x1F);
	/* 1100 0001 */
	setByte(5, (getByte(5) & 0xC1) | ((version & 0x1F) << 1));
}

void PsiSection::setCurrentNextIndicator(bool indicator) { /* 1 */
	/* 1111 1110 */
	setByte(5, (getByte(5) & 0xFE) | (indicator & 0x01));
}

void PsiSection::setSectionNumber(unsigned number) { /* 8 */
	assert(number <= 0xFF);
	setByte(6, 0xFF & number);
}

void PsiSection::setLastSectionNumber(unsigned number) { /* 8 */
	assert(number <= 0xFF);
	setByte(7, 0xFF & number);
}

void PsiSection::finalize() {
	Section::finalize();
	Section::setSectionSyntaxIndicator(true);
	
	/* reserved 2 (after table_id_extension) */
	setByte(5, getByte(5) | 0xC0); /* 1100 0000 */
	
	/* crc 32 */
	unsigned sectionLength = getSectionLength();
	unsigned crc = calculateCrc(data, sectionLength - 1);
	
	setByte(sectionLength - 1, (crc & 0xFF000000) >> 24);
	setByte(sectionLength    , (crc & 0x00FF0000) >> 16);
	setByte(sectionLength + 1, (crc & 0x0000FF00) >>  8);
	setByte(sectionLength + 2, (crc & 0x000000FF)      );
}

/* protected */

void PsiSection::appendData(unsigned pos, unsigned char *newData, unsigned newDataLength) {
	memcpy(&data[pos], newData, newDataLength);
	setSectionLength(getSectionLength() + newDataLength);
}
