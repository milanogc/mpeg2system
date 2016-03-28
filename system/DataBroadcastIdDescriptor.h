#ifndef DATABROADCASTIDDESCRIPTOR_H
#define DATABROADCASTIDDESCRIPTOR_H

#include "Descriptor.h"

/* ETSI EN 300 468 V.1.5.1 */

class DataBroadcastIdDescriptor : public Descriptor {
public:
	static const unsigned TAG = 0x66;
	
	DataBroadcastIdDescriptor(unsigned char *d, unsigned l);
	DataBroadcastIdDescriptor();
	
	unsigned getDataBroadcastId() const;
	unsigned char *getSelectorBytes(unsigned &selectorLength) const;
	bool verify() const;
	
	void setDataBroadcastId(unsigned id);
	void setSelectorBytes(unsigned char *selectorBytes, unsigned selectorLength);
	void finalize();
};

#endif // DATABROADCASTIDDESCRIPTOR_H
