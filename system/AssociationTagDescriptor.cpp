#include "AssociationTagDescriptor.h"
#include <string>
#include <cassert>

AssociationTagDescriptor::AssociationTagDescriptor(unsigned char *d, unsigned l) : Descriptor(d, l) {
}

AssociationTagDescriptor::AssociationTagDescriptor() : Descriptor() {
	setDescriptorLength(0);
	setSelectorLength(0);
}

AssociationTagDescriptor::~AssociationTagDescriptor() {
}

unsigned AssociationTagDescriptor::getAssociationTag() const { /* 16 */
	return (getByte(2) << 8) | getByte(3);
}

unsigned AssociationTagDescriptor::getUse() const { /* 16 */
	return (getByte(4) << 8) | getByte(5);
}

unsigned AssociationTagDescriptor::getSelectorLength() const { /* 8 */
	return getByte(6);
}

unsigned char *AssociationTagDescriptor::getSelector(unsigned &selectorLength) const {
	/* TODO implement */
	return NULL;
}

bool AssociationTagDescriptor::hasTransactionId() const {
	return getUse() == 0x00;
}

unsigned AssociationTagDescriptor::getTransactionId() const { /* 32 */
	assert(hasTransactionId());
	return (getByte(7) << 24) | (getByte(8) << 16) | (getByte(9) << 8) | getByte(10);
}

bool AssociationTagDescriptor::hasTimeout() const {
	return hasTransactionId();
}

unsigned AssociationTagDescriptor::getTimeout() const { /* 32 */
	assert(hasTimeout());
	return (getByte(11) << 24) | (getByte(12) << 16) | (getByte(13) << 8) | getByte(14);
}

unsigned char *AssociationTagDescriptor::getPrivateData(unsigned &privateDataLength) const {
	/* TODO implement */
	return NULL;
}

bool AssociationTagDescriptor::verify() const {
	if (getDescriptorTag() != TAG)
		return false;
	
	unsigned use = getUse();
	
	if (use == 0x00) {
		if (getSelectorLength() != 8) {
			return false;
		}
	}
	else if (use == 0x01) {
		if (getSelectorLength() != 0) {
			return false;
		}
	}
	
	return Descriptor::verify();
}

void AssociationTagDescriptor::setAssociationTag(unsigned tag) { /* 16 */
	setByte(2, (tag & 0xFF00) >> 8);
	setByte(3, tag & 0xFF);
}

void AssociationTagDescriptor::setUse(unsigned use) { /* 16 */
	setByte(4, (use & 0xFF00) >> 8);
	setByte(5, use & 0xFF);
	
	if (use == 0x00) {
		setDescriptorLength(15);
		setSelectorLength(8);
	}
	else if (use == 0x01) {
		setDescriptorLength(7);
		setSelectorLength(0);
	}
}

void AssociationTagDescriptor::setSelectorLength(unsigned length) { /* 8 */
	setByte(6, length);
}

void AssociationTagDescriptor::setSelector(unsigned char *selector, unsigned selectorLength) {
	setSelectorLength(selectorLength);
	/* TODO implement */
}

void AssociationTagDescriptor::setTransactionId(unsigned id) { /* 32 */
	assert(hasTransactionId());
	
	setByte(7, (id & 0xFF000000) >> 24);
	setByte(8, (id & 0xFF0000) >> 16);
	setByte(9, (id & 0xFF00) >> 8);
	setByte(10, id & 0xFF);
}

void AssociationTagDescriptor::setTimeout(unsigned timeout) { /* 32 */
	assert(hasTimeout());
	
	setByte(7, (timeout & 0xFF000000) >> 24);
	setByte(8, (timeout & 0xFF0000) >> 16);
	setByte(9, (timeout & 0xFF00) >> 8);
	setByte(10, timeout & 0xFF);
}

void AssociationTagDescriptor::setPrivateData(unsigned char *privateData, unsigned privateDataLength) {
	/* TODO implement */
}

void AssociationTagDescriptor::finalize() {
	Descriptor::setDescriptorTag(TAG);
	unsigned use = getUse();
	
	if (use == 0x00) {
		setSelectorLength(8);
	}
	else if (use == 0x01) {
		setSelectorLength(0);
	}
	
	Descriptor::finalize();
}
