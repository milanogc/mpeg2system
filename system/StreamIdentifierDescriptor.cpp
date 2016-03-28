/**
 * Milano 2004.06.07-06:07 (YYYY.MM.DD-HH:MM)
 */

#include "StreamIdentifierDescriptor.h"
#include <cassert>
#include <string>

StreamIdentifierDescriptor::StreamIdentifierDescriptor(unsigned char *d) : Descriptor(d, 3) {
	assert(d != NULL);
}

StreamIdentifierDescriptor::StreamIdentifierDescriptor() : Descriptor(NULL, 3) {
}

/* --- decoding --- */
unsigned StreamIdentifierDescriptor::getComponentTag() const {
	return data[2];
}

bool StreamIdentifierDescriptor::verify() const {
	if (getDescriptorTag() != TAG)
		return false;
	
	return Descriptor::verify();	
}

/* --- coding --- */

void StreamIdentifierDescriptor::setComponentTag(unsigned tag) {
	data[2] = tag & 0xFF;
}

void StreamIdentifierDescriptor::finalize() {
	Descriptor::setDescriptorTag(TAG);
	Descriptor::setDescriptorLength(1);
	Descriptor::finalize();
}
