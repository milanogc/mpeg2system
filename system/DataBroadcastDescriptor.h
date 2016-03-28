/**
 * @author Milano Gadelha Carvalho
 * @date 2004.06.07 (YYYY.MM.DD)
 */

#ifndef DATABROADCASTDESCRIPTOR_H
#define DATABROADCASTDESCRIPTOR_H

#include "Descriptor.h"

class DataBroadcastDescriptor : public Descriptor {
public:
	static const unsigned TAG = 0x64;
	static const unsigned MIN_LENGTH = 10;
	
	DataBroadcastDescriptor(unsigned char *d, unsigned l);
	
	/* decoding */
	unsigned getDataBroadcastId() const; /* 16 */
	unsigned getComponentTag() const; /* 8 */
	unsigned getSelectorLength() const; /* 8 */
	unsigned char *getSelectorBytes() const;
	unsigned getIso639LanguageCode() const; /* 24 */
	unsigned getTextLength() const; /* 8 */
	const unsigned char *getTextChars() const;
	bool verify() const;
	
	/* coding */
	void setDataBroadcastId(unsigned id); /* 16 */
	void setComponentTag(unsigned tag); /* 8 */
	void setSelector(const unsigned char *text, unsigned length);
	void setIso639LanguageCode(unsigned code); /* 24 */
	void setText(unsigned char *text, unsigned length);
	void finalize(); /* overwrite */
};

#endif /* DATABROADCASTDESCRIPTOR_H */
