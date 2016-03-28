#ifndef APPLICATIONSIGNALLINGDESCRIPTOR_H
#define APPLICATIONSIGNALLINGDESCRIPTOR_H

#include "Descriptor.h"

class ApplicationSignallingDescriptor : public Descriptor {
public:
	static const unsigned TAG = 0x6F;
	
	ApplicationSignallingDescriptor(unsigned char *d, unsigned l);
	ApplicationSignallingDescriptor();
	
	bool verify() const;
	
	void appendAppTypeAndAitVersion(unsigned appType, unsigned aitVersion);
	void finalize();
};

#endif // APPLICATIONSIGNALLINGDESCRIPTOR_H
