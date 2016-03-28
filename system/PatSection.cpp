/**
 * Milano 2004.06.07-06:07 (YYYY.MM.DD-HH:MM)
 */

#include "PatSection.h"
#include <string>

PatSection::PatSection(unsigned char *d, unsigned l) : PsiSection(d, l) {
}

PatSection::PatSection() : PsiSection() {
	setSectionLength(9); /* min length */
}

PatSection::~PatSection() {
}

Iterator<PatSection::Program> *PatSection::getProgramsIterator() const {
	unsigned programLoopLength = getSectionLength() - 5 /* before loop */ - 4 /* crc */;
	
	if (programLoopLength != 0) {
		return new Iterator<Program>(&data[8], programLoopLength);
	}
	else {
		return NULL;
	}
}

/* --- decoding -- */

unsigned PatSection::getTransportStreamId() const { /* a simple alias */
	return getTableIdExtension();
}

bool PatSection::verify() const {
	if (getPrivateIndicator())
		return false;
	
	if (getTableId() != TABLE_ID)
		return false;
	
	/* TODO verify each program */
	
	return PsiSection::verify();
}

/* --- coding -- */

void PatSection::setTransportStreamId(unsigned id) { /* a simple alias */
	setTableIdExtension(id);
}

void PatSection::appendProgram(unsigned char *programData, unsigned programDataLength) {
	unsigned sectionLength = getSectionLength();
	memcpy(&data[3 /* before */ + sectionLength - 4 /* crc */], programData, programDataLength);
	setSectionLength(sectionLength + programDataLength);
}

void PatSection::finalize() {
	setTableId(TABLE_ID);
	setPrivateIndicator(false);
	PsiSection::finalize();
}

/*****************************************************************************
 * PatSection::Program                                                       *
 *****************************************************************************/

PatSection::Program::Program(unsigned char *d) : Chunk(d, PatSection::Program::LENGTH) {
}

PatSection::Program::Program() : Chunk(NULL, PatSection::Program::LENGTH) {
}

PatSection::Program::~Program() {
}

/* --- decoding --- */

unsigned PatSection::Program::getProgramNumber() const { /* 16 */
	return (data[0] << 8) | data[1];
}

int PatSection::Program::getPid() const { /* 13 */
	return ((data[2] & 0x1F) << 8) | data[3]; /* 0001 1111 */
}

unsigned PatSection::Program::getDataLength() const {
	return 4;
}

bool PatSection::Program::verify() const {
	/* reserved */
	return (data[2] & 0xE0) == 0xE0; /* 1110 0000 */
}

/* --- coding --- */

void PatSection::Program::setProgramNumber(unsigned number) { /* 16 */
	data[0] = (number & 0xFF00) >> 8;
	data[1] = number & 0x00FF;
}

void PatSection::Program::setPid(int pid) { /* 13 */
	/* 13 */
	/* TODO milano! pay attention! */
	data[2] = (data[2] & 0xE0) | ((pid & 0x1F00) >> 8); /* 0001 1111 */ /* 5 */
	data[3] = pid & 0x00FF; /* 8 */
}

void PatSection::Program::finalize() {
	data[2] = data[2] | 0xE0; /* 1110 0000 */
}
