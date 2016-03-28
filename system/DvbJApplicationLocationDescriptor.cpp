#include "DvbJApplicationLocationDescriptor.h"
#include <string>
#include <cassert>

DvbJApplicationLocationDescriptor::DvbJApplicationLocationDescriptor(unsigned char *d, unsigned l) : Descriptor(d, l) {	
}

DvbJApplicationLocationDescriptor::DvbJApplicationLocationDescriptor() : Descriptor() {
	setBaseDirectoryLength(0);
	setClasspathExtensionLength(0);
	setInitialClassLength(0);
}

unsigned DvbJApplicationLocationDescriptor::getBaseDirectoryLength() const { /* 8 */
	return getByte(2);
}

unsigned char *DvbJApplicationLocationDescriptor::getBaseDirectory(unsigned &length) const {
	length = getBaseDirectoryLength();
	
	if (length == 0)
		return NULL;
	
	return &getByte(3);
}

unsigned DvbJApplicationLocationDescriptor::getClasspathExtensionLength() const { /* 8 */
	return getByte(3 + getBaseDirectoryLength());
}

unsigned char *DvbJApplicationLocationDescriptor::getClasspathExtension(unsigned &length) const {
	length = getClasspathExtensionLength();
	
	if (length == 0)
		return NULL;
	
	return &getByte(4 + getBaseDirectoryLength());
}

unsigned DvbJApplicationLocationDescriptor::getInitialClassLength() const {
	return getDescriptorLength() - (2 + getBaseDirectoryLength() + getClasspathExtensionLength());
}

unsigned char *DvbJApplicationLocationDescriptor::getInitialClass(unsigned &length) const {
	length = getInitialClassLength();
	
	if (length == 0)
		return NULL;
	
	return &getByte(4 + getBaseDirectoryLength() + getClasspathExtensionLength());
}

bool DvbJApplicationLocationDescriptor::verify() const {
	return true;
}

void DvbJApplicationLocationDescriptor::setBaseDirectory(unsigned char *directory) {
}

void DvbJApplicationLocationDescriptor::setClasspathExtension(unsigned char *classpath) {
}

void DvbJApplicationLocationDescriptor::setInitialClass(unsigned char *initial) {
}

void DvbJApplicationLocationDescriptor::finalize() {
}

/* private */

void DvbJApplicationLocationDescriptor::setBaseDirectoryLength(unsigned length) {
}

void DvbJApplicationLocationDescriptor::setClasspathExtensionLength(unsigned length) {
}

void DvbJApplicationLocationDescriptor::setInitialClassLength(unsigned length) {
}
