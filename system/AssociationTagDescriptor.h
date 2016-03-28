#ifndef ASSOCIATIONTAGDESCRIPTOR_H
#define ASSOCIATIONTAGDESCRIPTOR_H

#include "Descriptor.h"

/* 13818-6 */

class AssociationTagDescriptor : public Descriptor {
public:
	static const unsigned TAG = 0x14;
	
	AssociationTagDescriptor(unsigned char *d, unsigned l);
	AssociationTagDescriptor();
	~AssociationTagDescriptor();
	
	unsigned getAssociationTag() const;
	unsigned getUse() const;
	unsigned getSelectorLength() const;
	unsigned char *getSelector(unsigned &selectorLength) const;
	bool hasTransactionId() const;
	unsigned getTransactionId() const;
	bool hasTimeout() const;
	unsigned getTimeout() const;
	unsigned char* getPrivateData(unsigned &privateDataLength) const;
	bool verify() const;
	
	void setAssociationTag(unsigned tag);
	void setUse(unsigned use);
	void setSelectorLength(unsigned length);
	void setSelector(unsigned char *selector, unsigned selectorLength);
	void setTransactionId(unsigned id);
	void setTimeout(unsigned timeout);
	void setPrivateData(unsigned char *privateData, unsigned privateDataLength);
	void finalize();
};

#endif // ASSOCIATIONTAGDESCRIPTOR_H
