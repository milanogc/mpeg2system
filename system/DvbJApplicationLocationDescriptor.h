#ifndef DVBJAPPLICATIONLOCATIONDESCRIPTOR_H
#define DVBJAPPLICATIONLOCATIONDESCRIPTOR_H

#include "Descriptor.h"

class DvbJApplicationLocationDescriptor : public Descriptor {
public:
	static const unsigned TAG = 0x04;
	
	DvbJApplicationLocationDescriptor(unsigned char *d, unsigned l);
	DvbJApplicationLocationDescriptor();
	
	unsigned getBaseDirectoryLength() const;
	unsigned char *getBaseDirectory(unsigned &length) const;
	unsigned getClasspathExtensionLength() const;
	unsigned char *getClasspathExtension(unsigned &length) const;
	unsigned getInitialClassLength() const; /**/
	unsigned char *getInitialClass(unsigned &length) const;
	bool verify() const;
	
	void setBaseDirectory(unsigned char *directory);
	void setClasspathExtension(unsigned char *classpath);
	void setInitialClass(unsigned char *initial);
	void finalize();

private:
	void setBaseDirectoryLength(unsigned length);
	void setClasspathExtensionLength(unsigned length);
	void setInitialClassLength(unsigned length);
};

#endif // DVBJAPPLICATIONLOCATIONDESCRIPTOR_H
