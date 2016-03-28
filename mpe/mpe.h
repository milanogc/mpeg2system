#ifndef _MPE_H_
#define _MPE_H_

#define MAX_DATA_LENGTH_PER_SECTION 4080
#define MAX_TS_PAYLOAD_LENGTH 184
#define TS_PACKET_LENGTH 188
#define SECTION_LENGTH 4096

/* IP datagram information */
typedef struct {
	unsigned int length; /* datagram length */
	char mac[6]; /* mac address */
	char *datagram; /* the datagram itself */
} IpDatagram;

/* transport stream packets information */
typedef struct {
	int pid; /* pid of the packet */
	int continuityCounter; /* continuity counter of the packet*/
} TsInfo;

/**
 * Convert an IP datagram into Multiprotocol Encapsulaion transport stream packets
 * @param buf The output, it must have at least 23 * 188 bytes
 * @param ipDatagram The datagram to be converted
 * @param tsInfo Aux information to the transport stream packets
 * @return The number of written bytes in buf
 */
int MultiprotocolEncapsulation(char **buf, IpDatagram *ipDatagram, TsInfo *tsInfo);

#endif
