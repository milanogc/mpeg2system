#include <string.h>
#include <stdio.h>
#include "bits.h"
#include "crc.h"
#include "mpe.h"

/* local functions */
static int buildDatagramSection(char *datagramSection, IpDatagram *ipDatagram);
static int sectionToTsPackets(char **packetsBuffer, char *datagramSection, int length, TsInfo *tsInfo);

int MultiprotocolEncapsulation(char **buf, IpDatagram *ipDatagram, TsInfo *tsInfo)
{
	/* a section has 4096 bytes but we have to consider an aditional byte for pointer_field */
	char datagramSection[SECTION_LENGTH + 1];
	int length;
	int numberOfPackets;
	
	if (ipDatagram->length <= 0 || ipDatagram->length > MAX_DATA_LENGTH_PER_SECTION) {
		/* debug output */
		fprintf(stderr, "MPE: invalid datagram length: %d\n", ipDatagram->length);
		return 0; /* error */
	}
	
	/* build section */
	/* length has the number of written bytes into datagramSection */
	length = buildDatagramSection(datagramSection, ipDatagram);
	
	/* build packets */
	numberOfPackets = sectionToTsPackets(buf, datagramSection, length, tsInfo);
	
	return TS_PACKET_LENGTH * numberOfPackets; /* number of written bytes */
}

/**
 * Build a datagram section
 * @param datagramSection The output
 * @param ipDatagram The datagram to be encapsulated
 * @return The number of written bytes into datagramSection
 */
static int buildDatagramSection(char *datagramSection, IpDatagram *ipDatagram) {
	BitsBuffer bits;
	initBits(&bits, datagramSection);
	
	/* program specific information --------------------------------------- */
	
	/* pointer_field              8 |  0x0 */
	writeBits(&bits, 8, 0x0);
	
	/* --- datagram section ----------------------------------------------- */
	
	/* table_id                   8 | 0x3E */
	writeBits(&bits, 8, 0x3E);
	/* section_syntax_indicator   1 |  0x1 */
	writeBits(&bits, 1, 0x1);
	/* private_indicator          1 |  0x0 */
	writeBits(&bits, 1, 0x0);
	/* reserved                   2 |  0x3 */
	writeBits(&bits, 2, 0x3);
	/* section_length            12 |      */
	writeBits(&bits, 12, ipDatagram->length + 13);
	/* MAC_address_6              8 |      */
	writeBits(&bits, 8, ipDatagram->mac[5]);
	/* MAC_address_5              8 |      */
	writeBits(&bits, 8, ipDatagram->mac[4]);
	/* reserved                   2 |  0x3 */
	writeBits(&bits, 2, 0x3);
	/* payload_scrambling_control 2 |  0x0 */
	writeBits(&bits, 2, 0x0);
	/* address_scrambling_control 2 |  0x0 */
	writeBits(&bits, 2, 0x0);
	/* LLC_SNAP_flag              1 |  0x0 */
	writeBits(&bits, 1, 0x0);
	/* current_next_indicator     1 |  0x1 */
	writeBits(&bits, 1, 0x1);
	/* section_number             8 |  0x0 */
	writeBits(&bits, 8, 0x0);
	/* last_section_number        8 |  0x0 */
	writeBits(&bits, 8, 0x0);
	/* MAC_address_4              8 |      */
	writeBits(&bits, 8, ipDatagram->mac[3]);
	/* MAC_address_3              8 |      */
	writeBits(&bits, 8, ipDatagram->mac[2]);
	/* MAC_address_2              8 |      */
	writeBits(&bits, 8, ipDatagram->mac[1]);
	/* MAC_address_1              8 |      */
	writeBits(&bits, 8, ipDatagram->mac[0]);
	
	/* IP_datagram_data_bytes              */
	
	memcpy(datagramSection + bits.index, ipDatagram->datagram, ipDatagram->length);
	skipBytes(&bits, ipDatagram->length);
	
	/* CRC_32                    32 |      */
	writeBits(&bits, 32, calculateCRC(datagramSection + 1 /* skip pointer field */, bits.index - 1));
	
	/* 17 is the number of bytes of the fields */
	return 17 + ipDatagram->length;
}

/**
 * Convert a section into TS packets
 * @param packetsBuffer The output
 * @param datagramSection The section to be converted into packets
 * @param length The length of the section
 * @param tsInfo Aux information about the generated packets
 * @return The number of written packets
 */
static int sectionToTsPackets(char **packetsBuffer, char *datagramSection, int length, TsInfo *tsInfo) {
	int numberOfPackets = length / MAX_TS_PAYLOAD_LENGTH + (length % MAX_TS_PAYLOAD_LENGTH == 0 ? 0 : 1);
	int producedPackets = 0;
	int payloadUnitStartIndicator = 0x1; /* first packet */
	BitsBuffer bits;
	
	while (producedPackets != numberOfPackets - 1) { /* full packets */
		initBits(&bits, packetsBuffer[producedPackets]);
		
		/* --- header ----------------------------------------------------- */
		
		/* sync byte */
		writeBits(&bits, 8, 0x47);
		/* transport error indicator */
		writeBits(&bits, 1, 0x0);
		/* payload_unit_start_indicator signals the start of a datagram in a packet */
		writeBits(&bits, 1, payloadUnitStartIndicator);
		/* transport_priority */
		writeBits(&bits, 1, 0x0);
		/* pid */
		writeBits(&bits, 13, tsInfo->pid);
		/* transport scrambling control */
		writeBits(&bits, 2, 0x0);
		/* adptation field control */
		writeBits(&bits, 2, 0x1);
		/* continuity counter */
		writeBits(&bits, 4, tsInfo->continuityCounter);
		
		/* --- payload ---------------------------------------------------- */
		
		memcpy(
			packetsBuffer[producedPackets] + bits.index,
			datagramSection + MAX_TS_PAYLOAD_LENGTH * producedPackets,
			MAX_TS_PAYLOAD_LENGTH /* 184 bytes */
		);
		
		/* update fields */
		
		/* increment the continuity counter of this stream */
		tsInfo->continuityCounter = (tsInfo->continuityCounter + 1) % 16;
		payloadUnitStartIndicator = 0x0; /* first packet already processed */
		producedPackets++;
	}
	
	/* last packet */
	printf("alo1\n");
	initBits(&bits, packetsBuffer[producedPackets]);
	printf("alo2\n");
	
	/* --- header --------------------------------------------------------- */
	
	/* sync byte */
	writeBits(&bits, 8, 0x47);
	/* transport error indicator */
	writeBits(&bits, 1, 0x0);
	/* payload_unit_start_indicator signals the start of a datagram in a packet */
	writeBits(&bits, 1, payloadUnitStartIndicator);
	/* transport_priority */
	writeBits(&bits, 1, 0x0);
	/* pid */
	writeBits(&bits, 13, tsInfo->pid);
	/* transport scrambling control */
	writeBits(&bits, 2, 0x0);
	/* adptation field control */
	writeBits(&bits, 2, 0x1);
	/* continuity counter */
	writeBits(&bits, 4, tsInfo->continuityCounter);
	
	/* --- payload -------------------------------------------------------- */
	
	/* data */
	memcpy(
		packetsBuffer[producedPackets] + bits.index,
		datagramSection + MAX_TS_PAYLOAD_LENGTH * producedPackets,
		length % MAX_TS_PAYLOAD_LENGTH == 0 ? MAX_TS_PAYLOAD_LENGTH : length % MAX_TS_PAYLOAD_LENGTH
	);
	
	/* stuffing bytes */
	memset(
		packetsBuffer[producedPackets] + bits.index + length % MAX_TS_PAYLOAD_LENGTH,
		0xFF,
		length % MAX_TS_PAYLOAD_LENGTH == 0 ? 0 : MAX_TS_PAYLOAD_LENGTH - length % MAX_TS_PAYLOAD_LENGTH
	);
	
	/* update fields */
	
	/* increment the continuity counter of this stream */
	tsInfo->continuityCounter = (tsInfo->continuityCounter + 1) % 16;
	
	return numberOfPackets;
}
