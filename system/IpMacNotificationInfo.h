#ifndef IPMACNOTIFICATIONINFO_H
#define IPMACNOTIFICATIONINFO_H

#include "Chunk.h"

class IpMacNotificationInfo : public Chunk {
	public:
		IpMacNotificationInfo(unsigned char *d, unsigned l);
		unsigned getPlatformIdDataLenght() const;
};

#endif /* IPMACNOTIFICATIONINFO_H */
