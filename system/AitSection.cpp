#include "AitSection.h"
#include <string>
#include <cassert>

AitSection::AitSection(unsigned char *d, unsigned l) : PsiSection(d, l) {
}

AitSection::AitSection() : PsiSection() {
}

bool AitSection::getTestApplicationFlag() const {
	return getTableIdExtension() & 0x80;
}

ApplicationType AitSection::getApplicationType() const {
	unsigned at = getTableIdExtension() & 0x7F;
	
	switch (at) {
		case 0x0: return AT_RESERVED;
		case 0x1: return AT_DVB_J;
		case 0x2: return AT_DVB_HTML;
		default:  return AT_UNKNOWN;
	}
}

unsigned AitSection::getCommonDescriptorsLength() const { /* 12 */
	return ((getByte(8) & 0x0F) << 8) | getByte(9);
}

Iterator<Descriptor> *AitSection::getDescriptorsIterator() const {
	unsigned descLength = getCommonDescriptorsLength();
	
	if (descLength != 0) {
		return new Iterator<Descriptor>(&data[10], descLength);
	}
	else {
		return NULL;
	}
}

unsigned AitSection::getApplicationLoopLength() const { /* 12 */
	unsigned pos = 10 + getCommonDescriptorsLength();
	return ((getByte(pos) & 0x0F) << 8) | getByte(pos + 1);
}

Iterator<AitSection::ApplicationLoopItem> *AitSection::getApplicationLoopIterator() const {
	unsigned loopLength = getApplicationLoopLength();
	
	if (loopLength != 0) {
		unsigned pos = 12 + getCommonDescriptorsLength();
		return new Iterator<AitSection::ApplicationLoopItem>(&data[pos], loopLength);
	}
	else {
		return NULL;
	}
}

/*****************************************************************************
 * AitSection::ApplicationLoopItem                                           *
 *****************************************************************************/

AitSection::ApplicationLoopItem::ApplicationLoopItem(unsigned char *d, unsigned l) : Chunk(d, l) {
}

AitSection::ApplicationLoopItem::ApplicationLoopItem(unsigned char *d) : Chunk(d, 0) {
	assert (d != NULL);
}

AitSection::ApplicationLoopItem::ApplicationLoopItem() : Chunk(NULL, 4105) {
}

unsigned AitSection::ApplicationLoopItem::getDataLength() const {
	return 9 + getApplicationDescriptorsLoopLength();
}

unsigned AitSection::ApplicationLoopItem::getOrganizationId() const { /* 32 */
	return
		(getByte(0) << 24) |
		(getByte(1) << 16) |
		(getByte(2) <<  8) |
		(getByte(3)      );
}

unsigned AitSection::ApplicationLoopItem::getApplicationId() const { /* 16 */
	return (getByte(4) << 8) | getByte(5);
}

ApplicationControlCode AitSection::ApplicationLoopItem::getApplicationControlCode() const { /* 8 */
	unsigned acc = getByte(6);
	
	switch (acc) {
		case 0x00: return ACC_RESERVED;
		case 0x01: return ACC_AUTOSTART;
		case 0x02: return ACC_PRESENT;
		case 0x03: return ACC_DESTROY;
		case 0x04: return ACC_KILL;
		case 0x05: return ACC_PREFETCH; /* specific for DVB-HTML */
		case 0x06: return ACC_REMOTE;
		default:   return ACC_UNKNOWN;
	}
}

unsigned AitSection::ApplicationLoopItem::getApplicationDescriptorsLoopLength() const { /* 12 */
	return ((getByte(7) & 0x0F) << 8) | getByte(8);
}

Iterator<Descriptor> *AitSection::ApplicationLoopItem::getDescriptorsIterator() const {
	unsigned descLength = getApplicationDescriptorsLoopLength();
	
	if (descLength != 0) {
		return new Iterator<Descriptor>(&data[9], descLength);
	}
	else {
		return NULL;
	}
}
