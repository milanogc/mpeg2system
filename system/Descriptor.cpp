/**
 * Milano 2004.06.07-06:07 (YYYY.MM.DD-HH:MM)
 */

#include "Descriptor.h"
#include <cassert>
#include <string>

Descriptor::Descriptor(unsigned char *d, unsigned l) : Chunk(d, l) {
	if (d == NULL) {
		setDescriptorLength(0);
	}
}

Descriptor::Descriptor(unsigned char *d) : Chunk(d, 0) {
	assert(d != NULL);
}

Descriptor::Descriptor() : Chunk(NULL, MAX_LENGTH) {
	setDescriptorLength(0);
}

Descriptor::~Descriptor() {
}

unsigned Descriptor::getDataLength() const {
	return 2 + getDescriptorLength();
}

/* --- decoding --- */

unsigned Descriptor::getDescriptorTag() const { /* 8 */
	return data[0];
}

unsigned Descriptor::getDescriptorLength() const { /* 8 */
	return data[1];
}

bool Descriptor::verify() const {
	return true;
}

/* --- coding --- */

void Descriptor::setDescriptorTag(unsigned tag) { /* 8 */
	data[0] = tag & 0xFF;
}

void Descriptor::setDescriptorLength(unsigned length) { /* 8 */
	data[1] = length & 0xFF;
}

void Descriptor::finalize() {
	/* believe! it has nothing to do */
}
