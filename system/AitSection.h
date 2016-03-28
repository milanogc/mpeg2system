#ifndef AITSECTION_H
#define AITSECTION_H

#include "PsiSection.h"
#include "Iterator.h"
#include "Descriptor.h"

/* ETSI TS 102 812 V.1.2.1 pg. 218 */

enum ApplicationType {
	AT_RESERVED = 0x0,
	AT_DVB_J, /* 0x01 */
	AT_DVB_HTML, /* 0x02 */
	AT_UNKNOWN
};

/* DVB-J and DVB-HTML application control codes */
enum ApplicationControlCode {
	ACC_RESERVED = 0x0,
	ACC_AUTOSTART, /* 0x01 */
	ACC_PRESENT, /* 0x02 */
	ACC_DESTROY, /* 0x03 */
	ACC_KILL, /* 0x04 */
	ACC_PREFETCH, /* 0x05 */ /* specific for DVB-HTML */
	ACC_REMOTE, /* 0x06 */
	ACC_UNKNOWN
};

class AitSection : public PsiSection {
public:
	class ApplicationLoopItem;
	
	AitSection(unsigned char *d, unsigned l);
	AitSection();
	
	bool getTestApplicationFlag() const;
	ApplicationType getApplicationType() const; /* 15 */
	unsigned getCommonDescriptorsLength() const;
	Iterator<Descriptor> *getDescriptorsIterator() const;
	unsigned getApplicationLoopLength() const;
	Iterator<ApplicationLoopItem> *getApplicationLoopIterator() const;
};

class AitSection::ApplicationLoopItem : public Chunk {
public:
	ApplicationLoopItem(unsigned char *d, unsigned l);
	ApplicationLoopItem(unsigned char *d);
	ApplicationLoopItem();
	
	unsigned getDataLength() const;
	
	/* application identifier */
	unsigned getOrganizationId() const; /* 32 */
	unsigned getApplicationId() const; /* 16 */
	/* end */
	ApplicationControlCode getApplicationControlCode() const; /* 8 */
	unsigned getApplicationDescriptorsLoopLength() const; /* 12 */
	Iterator<Descriptor> *getDescriptorsIterator() const;
};

#endif // AITSECTION_H
