#include "DvbJApplicationDescriptor.h"

DvbJApplicationDescriptor::DvbJApplicationDescriptor() {
}

Iterator<Parameter> *DvbJApplicationDescriptor::getParametersIterator() const {
	return NULL;
}

unsigned DvbJApplicationDescriptor::Parameter::getParameterLength() const {
	return getByte(data, 0);
}

unsigned char *DvbJApplicationDescriptor::Parameter::getParameter(unsigned &length) const {
	unsigned length = getParameterLength();
	
	if (length != 0) {
		return &getByte(data, 1);
	}
	else {
		length = 0;
		return NULL;
	}
}
