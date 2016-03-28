#include "IntSection.h"

#include <string>

IntSection::IntSection(unsigned char *d, unsigned l) : PsiSection(d, l) {
}

/* --- decoding --- */

unsigned IntSection::getActionType() const { /* 8 */
	return (getTableIdExtension() & 0xFF00) >> 8;
}

/**
 * NOTE: There isn't a setPlatformIdHash because its task is accomplished by
 * setPlatformId.
 */
unsigned IntSection::getPlatformIdHash() const { /* 8 */
	return getTableIdExtension() & 0xFF;
}

unsigned IntSection::getPlatformId() const { /* 24 */
	return (data[8] << 16) | (data[9] << 8) | data[10];
}

unsigned IntSection::getProcessingOrder() const { /* 8 */
	return data[11];
}

bool IntSection::verify() const {
	/* TODO implement */
	return PsiSection::verify();
}

/* --- coding --- */

void IntSection::setActionType(unsigned action) { /* 8 */
	/* TODO verify */
	data[3] = action;
}

void IntSection::setPlatformId(unsigned id) { /* 24 */
	/* TODO verify */
	
	/* platform id hash */
	data[4] = ((id & 0xFF0000) >> 16) ^ ((id & 0x00FF00) >> 8) ^ (id & 0x0000FF);
	
	/* platform id */
	data[8] = (id & 0xFF0000) >> 16;
	data[9] = (id & 0x00FF00) >> 8;
	data[10] = id & 0x0000FF;
}

void IntSection::setProcessingOrder(unsigned order) { /* 8 */
	/* TODO verify */
	data[11] = order;
}

void IntSection::appendLoop(const unsigned char *loopData, unsigned loopDataLength) {
	/* TODO verify */
	unsigned sectionLength = getSectionLength();
	memcpy(&data[3 /* before */ + sectionLength - 4 /* crc */], loopData, loopDataLength);
	setSectionLength(sectionLength + loopDataLength);
}

void IntSection::finalize() {
	/* TODO verify */
	setTableId(0x4C);
	setPrivateIndicator(true); /* reserved for future use */
	PsiSection::finalize();
}
