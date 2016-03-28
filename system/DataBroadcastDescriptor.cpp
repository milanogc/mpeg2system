#include "DataBroadcastDescriptor.h"
#include <string>

DataBroadcastDescriptor::DataBroadcastDescriptor(unsigned char *d, unsigned l) : Descriptor(d, l) {
	if (d != NULL) {
		/*setDescriptorLength(getDescriptorLength() + ?)*/
	}
}

/* --- decoding --- */

unsigned DataBroadcastDescriptor::getDataBroadcastId() const { /* 16 */
	return (data[2] << 8) | data[3];
}

unsigned DataBroadcastDescriptor::getComponentTag() const { /* 8 */
	return data[4];
}

unsigned DataBroadcastDescriptor::getSelectorLength() const { /* 8 */
	return data[5];
}

unsigned char *DataBroadcastDescriptor::getSelectorBytes() const {
	if (getSelectorLength() == 0)
		return NULL;
	
	return &data[6];
}

unsigned DataBroadcastDescriptor::getIso639LanguageCode() const { /* 24 */
	unsigned selectorLength = getSelectorLength();
	
	return (data[6 + selectorLength] << 16) | (data[7 + selectorLength] << 8) | data[8 + selectorLength];
}

unsigned DataBroadcastDescriptor::getTextLength() const { /* 8 */
	return data[9 + getSelectorLength()];
}

const unsigned char *DataBroadcastDescriptor::getTextChars() const {
	if (getTextLength() == 0)
		return NULL;
	
	return &data[10 + getSelectorLength()];
}

bool DataBroadcastDescriptor::verify() const {
	/* TODO is it ok? */
	if (getDescriptorTag() != TAG)
		return false;
	
	return true;
}

/* --- coding --- */

void DataBroadcastDescriptor::setDataBroadcastId(unsigned id) { /* 16 */
	data[2] = (id & 0xFF00) >> 8;
	data[3] = id & 0xFF;
}

void DataBroadcastDescriptor::setComponentTag(unsigned tag) { /* 8 */
	data[4] = tag & 0xFF;
}

void DataBroadcastDescriptor::setSelector(const unsigned char *text, unsigned length) {
	data[5] = length & 0xFF; /* selector length */ /* 8 */
	memcpy(&data[6], text, length); /* selector bytes */
}

void DataBroadcastDescriptor::setIso639LanguageCode(unsigned code) { /* 24 */
	unsigned selectorLength = getSelectorLength();
	
	data[6 + selectorLength] = (code & 0xFF0000) >> 16;
	data[7 + selectorLength] = (code & 0x00FF00) >> 8;
	data[8 + selectorLength] = code & 0x0000FF;
}

void DataBroadcastDescriptor::setText(unsigned char *text, unsigned length) {
	data[9 + getSelectorLength()] = length & 0xFF; /* text length */ /* 8 */
	memcpy(&data[10 + getSelectorLength()], text, length); /* text chars */
}

void DataBroadcastDescriptor::finalize() { /* overwrite */
	Descriptor::setDescriptorTag(TAG);
	Descriptor::finalize();
}
