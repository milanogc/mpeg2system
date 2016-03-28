#ifndef CAROUSELIDENTIFIERDESCRIPTOR_H
#define CAROUSELIDENTIFIERDESCRIPTOR_H

#include "Descriptor.h"

/* ETSI TS 102 812 V1.2.1 */

class CarouselIdentifierDescriptor : public Descriptor{
public:
	static const unsigned TAG = 0x13;
	
	CarouselIdentifierDescriptor(unsigned char *d, unsigned l);
	CarouselIdentifierDescriptor();
	
	unsigned getCarouselId() const;
	unsigned getFormatId() const;
	bool verify() const;
	
	void setCarouselId(unsigned id) const;
	void setFormatId(unsigned id) const;
	void finalize();
};

#endif // CAROUSELIDENTIFIERDESCRIPTOR_H
