#include "DataBroadcastIdDescriptor.h"
#include <string>

DataBroadcastIdDescriptor::DataBroadcastIdDescriptor(unsigned char *d, unsigned l) : Descriptor(d, l) {
	if (d == NULL) {
		setDescriptorLength(2);
	}
}

DataBroadcastIdDescriptor::DataBroadcastIdDescriptor() : Descriptor() {
	setDescriptorLength(2);
}

unsigned DataBroadcastIdDescriptor::getDataBroadcastId() const { /* 16 */
	return (getByte(2) << 8) | getByte(3);
}

unsigned char *DataBroadcastIdDescriptor::getSelectorBytes(unsigned &selectorLength) const {
	/* TODO implement */
	return NULL;
}

bool DataBroadcastIdDescriptor::verify() const {
	/* TODO implement */
	return true;
}

void DataBroadcastIdDescriptor::setDataBroadcastId(unsigned id) { /* 16 */
	setByte(2, (id & 0xFF00) >> 8);
	setByte(3, id & 0xFF);
}

void DataBroadcastIdDescriptor::setSelectorBytes(unsigned char *selectorBytes, unsigned selectorLength) {
	/* TODO implement */
}

void DataBroadcastIdDescriptor::finalize() {
	/* TODO implement */
	Descriptor::setDescriptorTag(TAG);
	Descriptor::finalize();
}
