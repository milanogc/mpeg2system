#include "PesPacket.h"
#include <string>
#include <cassert>

PesPacket::PesPacket(unsigned char *d, unsigned l) : Chunk(d, l) {
}

PesPacket::PesPacket() : Chunk(NULL, 65542) {
}

PesPacket::~PesPacket() {
}

unsigned PesPacket::getPacketStartCodePrefix() const { /* 24 */
	return (getByte(0) << 16) |  (getByte(1) << 8) | getByte(2);
}

unsigned PesPacket::getStreamId() const { /* 8 */
	return getByte(3);
}

unsigned PesPacket::getPesPacketLength() const { /* 16 */
	return (getByte(4) << 8) | getByte(5);
}

unsigned PesPacket::getPesScramblingControl() const { /* 2 */ /* TODO enum */
	return (getByte(6) & 0x30) >> 4; /* 0011 0000 */
}

bool PesPacket::getPesPriority() const { /* 1 */
	return (getByte(6) & 0x08) >> 3; /* 0000 1000 */
}

bool PesPacket::getDataAlignmentIndicator() const { /* 1 */
	return (getByte(6) & 0x04) >> 2; /* 0000 0100 */
}

bool PesPacket::getCopyright() const { /* 1 */
	return (getByte(6) & 0x02) >> 1; /* 0000 0010 */
}

unsigned PesPacket::getOriginalOrCopy() const { /* 2 */
	return getByte(6) & 0x01; /* 0000 0001 */
}

unsigned PesPacket::getPtsDtsFlags() const { /* 2 */
	unsigned flags = (getByte(7) & 0xC0) >> 6;
	
	assert(flags != 1);
	
	return flags; /* 1100 0000 */
}

bool PesPacket::getEscrFlag() const {
	return (getByte(7) & 0x20) >> 5; /* 0010 0000 */
}

bool PesPacket::getEsRateFlag() const {
	return (getByte(7) & 0x10) >> 4; /* 0001 0000 */
}

bool PesPacket::getDsmTrickModeFlag() const {
	return (getByte(7) & 0x08) >> 3; /* 0000 1000 */
}

bool PesPacket::getAdditionalCopyInfoFlag() const {
	return (getByte(7) & 0x04) >> 2; /* 0000 0100 */
}

bool PesPacket::getPesCrcFlag() const {
	return (getByte(7) & 0x02) >> 1; /* 0000 0010 */
}

bool PesPacket::getPesExtensionFlag() const {
	return getByte(7) & 0x01; /* 0000 0001 */
}

unsigned PesPacket::getPesHeaderDataLength() const { /* 8 */
	return getByte(8);
}

bool PesPacket::hasPts() const {
	switch (getStreamId()) {
		case PROGRAM_STREAM_MAP:
		case PRIVATE_STREAM_1:
		case PADDING_STREAM:
		case PRIVATE_STREAM_2:
		case ECM_STREAM:
		case EMM_STREAM:
		case PROGRAM_STREAM_DIRECTORY:
		case DSMCC_STREAM:
		case ITU_T_REC_H_222_1_TYPE_E_STREAM:
			return false;
		default:
			unsigned flags = getPtsDtsFlags();
			return (flags == 0x2) || (flags == 0x3);
	}
}

unsigned long long PesPacket::getPts() const { /* 33 */
	assert(hasPts());
	
	return
		((unsigned long long) (getByte(9) & 0x0E) << 29) |
		((((getByte(10) << 8) | (getByte(11) & 0xFE))) << 14) |
		(((getByte(12) << 8) | getByte(13)) >> 1);
}

bool PesPacket::hasDts() const {
	switch (getStreamId()) {
		case PROGRAM_STREAM_MAP:
		case PRIVATE_STREAM_1:
		case PADDING_STREAM:
		case PRIVATE_STREAM_2:
		case ECM_STREAM:
		case EMM_STREAM:
		case PROGRAM_STREAM_DIRECTORY:
		case DSMCC_STREAM:
		case ITU_T_REC_H_222_1_TYPE_E_STREAM:
			return false;
		default:
			return getPtsDtsFlags() == 0x3;
	}
}

unsigned long long PesPacket::getDts() const { /* 33 */
	assert(hasDts());
	
	return
		((unsigned long long) (getByte(14) & 0x0E) << 29) |
		((((getByte(15) << 8) | (getByte(16) & 0xFE))) << 14) |
		(((getByte(17) << 8) | getByte(18)) >> 1);
}

bool PesPacket::hasEscr() const {
	switch (getStreamId()) {
		case PROGRAM_STREAM_MAP:
		case PRIVATE_STREAM_1:
		case PADDING_STREAM:
		case PRIVATE_STREAM_2:
		case ECM_STREAM:
		case EMM_STREAM:
		case PROGRAM_STREAM_DIRECTORY:
		case DSMCC_STREAM:
		case ITU_T_REC_H_222_1_TYPE_E_STREAM:
			return false;
		default:
			return getEscrFlag();
	}
}

unsigned long long PesPacket::getEscrBase() const {
	assert(hasEscr());
	unsigned pos = 9; /* start pos */
	
	if (hasPts()) {
		pos += 5;
		
		if (hasDts()) {
			pos += 5;
		}
	}
	
	return 0; /* TODO implement */
}

unsigned PesPacket::getEscrExtension() const {
	return 0; /* TODO implement */
}

bool PesPacket::hasEsRate() const {
	return getEsRateFlag();
}

unsigned PesPacket::getEsRate() const { /* 22 */
	assert(hasEsRate());
	unsigned pos = 9; /* start pos */
	
	if (hasPts()) {
		pos += 5;
		
		if (hasDts()) {
			pos += 5;
		}
	}
	
	if (hasEscr()) {
		pos += 6;
	}
	
	return ((getByte(pos) & 0x7F) << 15) + (getByte(pos + 1) << 7) + (getByte(pos + 2) >> 1);
}

bool PesPacket::hasDsmTrickMode() const {
	return getDsmTrickModeFlag();
}

bool PesPacket::hasAdditionalCopyInfo() const {
	return getAdditionalCopyInfoFlag();
}

bool PesPacket::getAdditionalCopyInfo() const { /* 7 */
	assert(hasAdditionalCopyInfo());
	unsigned pos = 9; /* start pos */
	
	if (hasPts()) {
		pos += 5;
		
		if (hasDts()) {
			pos += 5;
		}
	}
	
	if (hasEscr()) {
		pos += 6;
	}
	
	if (hasDsmTrickMode()) {
		pos += 1;
	}
	
	return getByte(pos) & 0x7F;
}

bool PesPacket::hasPesCrc() const {
	return getPesCrcFlag();
}

bool PesPacket::hasPesExtension() const {
	return getPesExtensionFlag();
}

bool PesPacket::getPesPrivateDataFlag() const {
	return false; /* TODO implement */
}

bool PesPacket::getPackHeaderFieldFlag() const {
	return false; /* TODO implement */
}

unsigned PesPacket::getPackFieldLength() const { /* 8 */
	return 0; /* TODO implement */
}

bool PesPacket::getProgramPacketSequenceCounterFlag() const {
	return false; /* TODO implement */
}

bool PesPacket::getPStdBufferFlag() const {
	return false; /* TODO implement */
}

bool PesPacket::getPesExtensionFlag2() const {
	return false; /* TODO implement */
}

bool PesPacket::hasPrivateData() const {
	if (!getPesExtensionFlag())
		return false;
	
	return getPesPrivateDataFlag();
}

bool PesPacket::hasPackHeader() const {
	return getPackHeaderFieldFlag();
}

bool PesPacket::hasProgramPacketSequenceCounter() const {
	return getProgramPacketSequenceCounterFlag();
}

bool PesPacket::hasPStdBuffer() const {
	return getPStdBufferFlag();
}

bool PesPacket::hasPesExtension2() const {
	return getPesExtensionFlag2();
}

unsigned PesPacket::getPesExtensionFieldLength() const { /* 7 */
	return 0; /* TODO implement */
}

unsigned char *PesPacket::getPesPacketData() const {
	unsigned pos = 9; /* start pos */
	
	if (hasPts()) {
		pos += 5;
		
		if (hasDts()) {
			pos += 5;
		}
	}
	
	if (hasEscr()) {
		pos += 6;
	}
	
	if (hasEsRate()) {
		pos += 3;
	}
	
	if (hasDsmTrickMode()) {
		pos += 1;
	}
	
	if (hasAdditionalCopyInfo()) {
		pos += 1;
	}
	
	if (hasPesCrc()) {
		pos += 2;
	}
	
	if (hasPesExtension()) {
		pos += 1;
		
		if (hasPrivateData()) {
			pos += 16;
		}
		
		if (hasPackHeader()) {
			pos += 1 + getPackFieldLength();
		}
		
		if (hasProgramPacketSequenceCounter()) {
			pos += 2;
		}
		
		if (hasPStdBuffer()) {
			pos += 2;
		}
		
		if (hasPesExtension2()) {
			pos += 1 + getPesExtensionFieldLength();
		}
	}
	
	/* stuffing bytes */
	
	/* pes packet data */
	
	return NULL;
}

unsigned PesPacket::getDataLength() const {
	/* packet start code prefix: 3*/
	/* stream id: 1 */
	/* pes packet length: 2 */
	return 6 + getPesPacketLength();
}

bool PesPacket::verify() const {
	return false; /* TODO implement */
}

/* -- coding -- */

void PesPacket::setPacketStartCodePrefix(unsigned prefix) { /* 24 */
	setByte(0, (prefix & 0xFF0000) >> 16);
	setByte(1, (prefix & 0x00FF00) >> 8);
	setByte(2, prefix & 0x0000FF);
}

void PesPacket::setStreamId(unsigned id) { /* 8 */
	setByte(3, id & 0xFF);
}

void PesPacket::setPesPacketLength(unsigned packetLength) { /* 16 */
	setByte(4, (packetLength & 0xFF00) >> 8);
	setByte(5, packetLength & 0xFF);
}

void PesPacket::setPesScramblingControl(unsigned sControl) { /* 2 */ /* TODO enum */
	/* TODO implement */
}
	
void PesPacket::setPesPriority(bool priority) { /* 1 */
	/* TODO implement */
}
	
void PesPacket::setDataAlignmentIndicator(bool indicator) { /* 1 */
	/* TODO implement */
}

void PesPacket::setCopyright(bool copyright) { /* 1 */
	/* TODO implement */
}

void PesPacket::setOriginalOrCopy(bool originalOrCopy) { /* 1 */
	/* TODO implement */
}

void PesPacket::setPtsDtsFlags(unsigned flags) { /* 2 */
	/* TODO implement */
}

void PesPacket::setEscrFlag(bool flag) {
	/* TODO implement */
}

void PesPacket::setEsRateFlag(bool flag) {
	/* TODO implement */
}

void PesPacket::setDsmTrickModeFlag(bool flag) {
	/* TODO implement */
}

void PesPacket::setAdditionalCopyInfoFlag(bool flag) {
	/* TODO implement */
}

void PesPacket::setPesCrcFlag(bool flag) {
	/* TODO implement */
}

void PesPacket::setPesExtensionFlag(bool flag) {
	/* TODO implement */
}

void PesPacket::setPesHeaderDataLength(unsigned length) {
	/* TODO implement */
}

void PesPacket::setPts(unsigned long long pts) { /* 33 */
	assert(hasPts());
	
	setByte(9, (pts & 0x380000000LL) >> 30); /* 11 1000 0000 0000 0000 0000 0000 0000 0000 */
	setByte(10, (pts & 0xFF000000) >> 24); /* 1111 1111 */
	setByte(11, (((pts & 0x7F0000) >> 15) | 0x1)); /* 0111 1111 */
	setByte(12, (pts & 0xFF00) >> 8); /* 1111 1111 */
	setByte(13, ((pts & 0x7F) << 1) | 0x1); /* 0111 1111 */
}

void PesPacket::setDts(unsigned long long dts) { /* 33 */
	assert(hasDts());
}

void PesPacket::setEscrBase(unsigned long long base) {
	assert(hasEscr());
}

void PesPacket::setEscrExtension(unsigned extension) {
	assert(hasEscr());
}


void PesPacket::finalize() {
	/* TODO implement */
}
