#include "ApplicationSignallingDescriptor.h"

ApplicationSignallingDescriptor::ApplicationSignallingDescriptor(unsigned char *d, unsigned l) : Descriptor(d, l) {
}

ApplicationSignallingDescriptor::ApplicationSignallingDescriptor() : Descriptor() {
}

bool ApplicationSignallingDescriptor::verify() const {
	if (getDescriptorTag() != TAG)
		return false;
	
	return true;
}

void ApplicationSignallingDescriptor::appendAppTypeAndAitVersion(unsigned appType, unsigned aitVersion) {
	unsigned pos = getDescriptorLength() + 2;
	setDescriptorLength(pos + 1);
	
	/* application type 16 */
	setByte(pos, (appType & 0xFF00) >> 8);
	setByte(pos + 1, appType & 0xFF);
	
	/* reserved 3 */ /* 1110 0000 */
	/* ait version 5 */
	setByte(pos + 2, 0xE0 | (aitVersion & 0x1F));
}

void ApplicationSignallingDescriptor::finalize() {
	/* TODO implement */
	Descriptor::setDescriptorTag(TAG);
	Descriptor::finalize();
}
