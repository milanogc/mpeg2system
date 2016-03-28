#include "CarouselIdentifierDescriptor.h"

CarouselIdentifierDescriptor::CarouselIdentifierDescriptor(unsigned char *d, unsigned l) : Descriptor(d, l) {
}

CarouselIdentifierDescriptor::CarouselIdentifierDescriptor() : Descriptor() {
	setDescriptorLength(5);
}

unsigned CarouselIdentifierDescriptor::getCarouselId() const { /* 32 */
	return (getByte(2) << 24) | (getByte(3) << 16) | (getByte(4) << 8) | getByte(5);
}

unsigned CarouselIdentifierDescriptor::getFormatId() const { /* 8 */
	return getByte(6);
}

bool CarouselIdentifierDescriptor::verify() const {
	/* TODO implement */
	return Descriptor::verify();
}

void CarouselIdentifierDescriptor::setCarouselId(unsigned id) const { /* 32 */
	setByte(2, (id & 0xFF000000) >> 24);
	setByte(3, (id & 0xFF0000) >> 16);
	setByte(4, (id & 0xFF00) >> 8);
	setByte(5, id & 0xFF);
}

void CarouselIdentifierDescriptor::setFormatId(unsigned id) const { /* 8 */
	setByte(6, id);
}

void CarouselIdentifierDescriptor::finalize() {
	/* TODO implement */
	Descriptor::setDescriptorTag(TAG);
	Descriptor::finalize();
}
