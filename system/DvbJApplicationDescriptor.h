#ifndef DVBJAPPLICATIONDESCRIPTOR_H
#define DVBJAPPLICATIONDESCRIPTOR_H

#include "Descriptor.h"
#include "Iterator.h"

class DvbJApplicationDescriptor : public Descriptor{
public:
	class Parameter;
	
	static const unsigned TAG = 0x03;
	
	DvbJApplicationDescriptor(unsigned char *d, unsigned l);
	DvbJApplicationDescriptor();
	
	Iterator<Parameter> *getParametersIterator() const;
};

class DvbJApplicationDescriptor::Parameter : public Chunk {
public:
	Parameter(unsigned char *d);
	unsigned getParameterLength() const;
	unsigned char *getParameter(unsigned &length) const;
};

#endif // DVBJAPPLICATIONDESCRIPTOR_H
