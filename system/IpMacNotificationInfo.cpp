#include "IpMacNotificationInfo.h"

IpMacNotificationInfo::IpMacNotificationInfo(unsigned char *d, unsigned l) : Chunk(d, l) {
}

unsigned IpMacNotificationInfo::getPlatformIdDataLenght() const {
	return data[0];
}
