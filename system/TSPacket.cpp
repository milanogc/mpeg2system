#include "TSPacket.h"
#include <string> /* memcpy, memset */
#include <cassert> /* assert */

TSPacket::TSPacket(unsigned char *d) : Chunk(d, PACKET_SIZE) {
}

TSPacket::TSPacket() : Chunk(NULL, PACKET_SIZE) {
}

TSPacket::~TSPacket() {
}

/* --- basic --- */

/* --- packet decoding --- */

unsigned TSPacket::getSyncByte() const { /* 8 */
	return getByte(0);
}

bool TSPacket::getTransportErrorIndicator() const { /* 1 */
	return (getByte(1) & 0x80)/* >> 7*/; /* TODO right? */
}

bool TSPacket::getPayloadUnitStartIndicator() const { /* 1 */
	return (getByte(1) & 0x40)/* >> 6*/;
}

bool TSPacket::getTransportPriority() const { /* 1 */
	/* 0010 0000 */
	return (getByte(1) & 0x20)/* >> 5*/;
}

int TSPacket::getPid() const { /* 13 */
	return ((getByte(1) & 0x1F) << 8) | getByte(2);
}

ScramblingControl TSPacket::getTransportScramblingControl() const { /* 2 */
	unsigned sControl = (getByte(3) & 0xC0) >> 6;
	
	switch (sControl) {
		case 0x1: return SC_USER_DEFINED_1;
		case 0x2: return SC_USER_DEFINED_2;
		case 0x3: return SC_USER_DEFINED_3;
	}
	
	return SC_NOT_SCRAMBLED; /* 0x0 */
}

AdaptFieldControl TSPacket::getAdaptationFieldControl() const { /* 2 */
	unsigned aFieldControl = (getByte(3) & 0x30) >> 4;
	
	switch (aFieldControl) {
		case 0x1: return AFC_ONLY_PAYLOAD;
		case 0x2: return AFC_ONLY_ADAPT_FIELD;
		case 0x3: return AFC_BOTH_PAYLOAD_AND_ADAPT_FIELD;
	}
	
	return AFC_RESERVED; /* 0x0 */
}

unsigned TSPacket::getContinuityCounter() const { /* 4 */
	return getByte(3) & 0x0F;
}

bool TSPacket::hasAdaptationField() const {
	return getAdaptationFieldControl() == AFC_ONLY_ADAPT_FIELD
		|| getAdaptationFieldControl() == AFC_BOTH_PAYLOAD_AND_ADAPT_FIELD;
}

unsigned TSPacket::getAdaptationFieldLength() const {
	assert(hasAdaptationField());
	
	unsigned aFieldLength = getByte(4);
	
	switch (getAdaptationFieldControl()) {
		case AFC_ONLY_ADAPT_FIELD:
			assert(aFieldLength == 183);
			break;
		case AFC_BOTH_PAYLOAD_AND_ADAPT_FIELD:
			assert(0 <= aFieldLength && aFieldLength <= 182);
			break;
		default:
			break;
	}
	
	return aFieldLength;
}

bool TSPacket::getDiscontinuityIndicator() const {
	assert(getAdaptationFieldLength());
	
	return getByte(5) & 0x80; /* 1000 0000 */
}

bool TSPacket::getRandomAccessIndicator() const {
	assert(getAdaptationFieldLength());
	
	return getByte(5) & 0x40; /* 0100 0000 */
}

bool TSPacket::getElementaryStreamPriorityIndicator() {
	assert(getAdaptationFieldLength());
	
	return getByte(5) & 0x20; /* 0010 0000 */
}

bool TSPacket::getPcrFlag() const {
	assert(getAdaptationFieldLength());
	
	return getByte(5) & 0x10; /* 0001 0000 */
}

bool TSPacket::getOpcrFlag() const {
	assert(getAdaptationFieldLength());
	
	return getByte(5) & 0x08; /* 0000 1000 */
}

bool TSPacket::getSplicingPointFlag() const {
	assert(getAdaptationFieldLength());
	
	return getByte(5) & 0x04; /* 0000 0100 */
}

bool TSPacket::getTransportPrivateDataFlag() const {
	assert(getAdaptationFieldLength());
	
	return getByte(5) & 0x02; /* 0000 0010 */
}

bool TSPacket::getAdaptationFieldExtensionFlag() const {
	assert(getAdaptationFieldLength());
	
	return getByte(5) & 0x01; /* 0000 0001 */
}

bool TSPacket::hasPcr() const {
	return hasAdaptationField() && (getAdaptationFieldLength() != 0) && getPcrFlag();
}

unsigned long long TSPacket::getPcrBase() const { /* 33 */
	assert(hasPcr());
	
	return
		((unsigned long long) (data[6] << 25)) |
		(getByte(7) << 17) |
		(getByte(8) << 9) |
		(getByte(9) << 1) |
		((getByte(10)) >> 7);
}

unsigned TSPacket::getPcrExtension() const { /* 9 */
	return ((getByte(10) & 0x1) << 8) | getByte(11);
}

bool TSPacket::hasOriginalPcr() const {
	return hasAdaptationField() && (getAdaptationFieldLength() != 0) && getOpcrFlag();
}

unsigned long long TSPacket::getOriginalPcrBase() const { /* 33 */
	assert(hasOriginalPcr());
	
	return
		((unsigned long long) (data[6] << 25)) |
		(getByte(7) << 17) |
		(getByte(8) << 9) |
		(getByte(9) << 1) |
		((getByte(10)) >> 7);
}

/**
 * TODO document and implement
 */
unsigned TSPacket::getOriginalPcrExtension() const { /* 9 */
	/* TODO implement */
	return 0;
}

/**
 * TODO document and implement
 */
bool TSPacket::hasSpliceCountdown() const {
	/* TODO implement */
	return false;
}

/**
 * TODO document and implement
 */
unsigned TSPacket::getSpliceCountdown() const { /* 8 */
	/* TODO implement */
	return 0;
}

/**
 * TODO document and implement
 */
bool TSPacket::hasTransportPrivateData() const {
	/* TODO implement */
	return false;
}

/**
 * TODO document and implement
 */
unsigned TSPacket::getTransportPrivateDataLength() const { /* 8 */
	/* TODO implement */
	return 0;
}

/**
 * TODO document and implement
 */
unsigned char *TSPacket::getTransportDataBytes(unsigned &length) const {
	/* TODO implement */
	return NULL;
}

/**
 * TODO document and implement
 */
bool TSPacket::hasAdaptationFieldExtension() const {
	/* TODO implement */
	return false;
}

/**
 * TODO document and implement
 */
unsigned TSPacket::getAdaptationFieldExtensionLength() const {
	/* TODO implement */
	return 0;
}

/**
 * TODO document and implement
 */
bool TSPacket::getLtwFlag() const {
	/* TODO implement */
	return false;
}

/**
 * TODO document and implement
 */
bool TSPacket::getPiecewiseRateFlag() const {
	/* TODO implement */
	return false;
}

/**
 * TODO document and implement
 */
bool TSPacket::getSeamlessSpliceFlag() const {
	/* TODO implement */
	return false;
}

/**
 * TODO document and implement
 */
bool TSPacket::hasLtw() const {
	/* TODO implement */
	return false;
}

/**
 * TODO document and implement
 */
bool TSPacket::getLtwValidFlag() const {
	/* TODO implement */
	return false;
}

/**
 * TODO document and implement
 */
unsigned TSPacket::getLtwOffset() const {
	/* TODO implement */
	return 0;
}

/**
 * TODO document and implement
 */
bool TSPacket::hasPiecewiseRate() const {
	/* TODO implement */
	return false;
}

/**
 * TODO document and implement
 */
unsigned TSPacket::getPiecewiseRate() const /* 22 */ {
	/* TODO implement */
	return 0;
}

/**
 * TODO document and implement
 */
bool TSPacket::hasSeamlessSplice() const {
	/* TODO implement */
	return false;
}

/**
 * TODO document and implement
 */
unsigned TSPacket::getSpliceType() const { /* 4 */
	/* TODO implement */
	return 0;
}

/**
 * TODO document and implement
 */
unsigned long long TSPacket::getDtsNextAu() const { /* 33 */
	/* TODO implement */
	return 0;
}

unsigned TSPacket::getPayloadLength() const {
	AdaptFieldControl aFieldControl = getAdaptationFieldControl();
	
	if (aFieldControl & 0x1) { /* aFieldControl is either 0x1 or 0x3: payload is present */
		unsigned aFieldLength = 0;
		
		if (aFieldControl == 0x3) /* adaption field is present */
			aFieldLength = getAdaptationFieldLength() + 1; /* the '1' is to include the aFieldLength itself */
		
		if (aFieldLength <= 183) /* ???? */
			return MAX_PAYLOAD_SIZE - aFieldLength;
	}
	
	return 0; /* no payload */
}

unsigned char *TSPacket::getPayload(unsigned &length) const {
	length = getPayloadLength();
	
	if (length == 0)
		return NULL;
	
	return &data[TSPacket::PACKET_SIZE - length];
}

unsigned TSPacket::getDataLength() const {
	return PACKET_SIZE;
}

/* header coding */

/**
 * TODO document
 */
void TSPacket::setSyncByte(unsigned value) { /* protected */
	setByte(0, value);
}

/**
 * TODO document
 */
void TSPacket::setTransportErrorIndicator(bool transportError) { /* 1 */
	setByte(1, (getByte(1) & 0x7F) | (transportError << 7)); /* 0111 1111 */
}

/**
 * TODO document
 */
void TSPacket::setPayloadUnitStartIndicator(bool payloadUnitStart) { /* 1 */
	setByte(1, (data[1] & 0xBF) | (payloadUnitStart << 6)); /* 1011 1111 */
}

/**
 * TODO document
 */
void TSPacket::setTransportPriority(bool transportPriority) { /* 1 */
	setByte(1, (data[1] & 0xDF) | (transportPriority << 5)); /* 1101 1111 */
}

/**
 * TODO document
 */
void TSPacket::setPid(int pid) { /* 13 */
	setByte(1, (data[1] & 0xE0) | ((pid & 0x1F00) >> 8)); /* 5 */
	setByte(2, pid & 0x00FF); /* 8 */
}

/**
 * TODO document
 */
void TSPacket::setTransportScramblingControl(ScramblingControl scramblingControl) { /* 2 */	
	setByte(3, (getByte(3) & 0x3F) | ((scramblingControl << 6) & 0xC0)); /* 0011 1111 */
}

void TSPacket::setAdaptationFieldControl(AdaptFieldControl adaptationFieldControl) { /* 2 */	
	setByte(3, (getByte(3) & 0xCF) | ((adaptationFieldControl & 0x3) << 4)); /* 1100 1111 */
}

void TSPacket::setContinuityCounter(unsigned continuityCounter) { /* 4 */
	continuityCounter = continuityCounter % 16;
	setByte(3, (getByte(3) & 0xF0) | (continuityCounter & 0x0F)); /* 1111 0000 */
}

void TSPacket::incContinuityCounter() {
	setByte(3, ((getByte(3) + 1) & 0x0F) | (getByte(3) & 0xF0));
}

/* adaptation field */

/**
 * TODO document and implement
 */
void TSPacket::setAdaptationFieldLength(unsigned aFieldLength) {
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setDiscontinuityIndicator(bool indicator) {
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setRandomAccessIndicator(bool indicator) {
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setElementaryStreamPriorityIndicator(bool indicator) {
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setPcrFlag(bool flag) {
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setOpcrFlag(bool flag) {
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setSplicingPointFlag(bool flag) {
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setTransportPrivateDataFlag(bool flag) {
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setAdaptationFieldExtensionFlag(bool flag) {
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setPcrBase(unsigned long long pcrBase) { /* 33 */
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setPcrExtension(unsigned pcrExtension) { /* 9 */
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setOriginalPcrBase(unsigned long long pcrBase) { /* 33 */
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setOriginalPcrExtension(unsigned pcrExtension) { /* 9 */
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setSpliceCountdown(unsigned countdown) { /* 8 */
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setTransportPrivateDataLength(unsigned dataLength) { /* 8 */ /* TODO remove */
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setTransportDataBytes(unsigned char *dataBytes, unsigned dataLength) {
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setAdaptationFieldExtensionLength(bool flag) {
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setLtwFlag(bool flag) {
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setPiecewiseRateFlag(bool flag) {
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setSeamlessSpliceFlag(bool flag) {
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setLtwValidFlag(bool flag) {
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setLtwOffset(unsigned offset) { /* 15 */
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setPiecewiseRate(unsigned rate) { /* 22 */
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setSpliceType(unsigned spliceType) { /* 4 */
	/* TODO implement */
}

/**
 * TODO document and implement
 */
void TSPacket::setDtsNextAu(unsigned long long dtsNextAu) { /* 33 */
	/* TODO implement */
}

/* payload */

void TSPacket::setPayload(unsigned char *d, unsigned length) {
	unsigned available;
	unsigned char *payload = getPayload(available);
	
	/* be sure that the available data is enough */
	assert(length <= available);
	
	/* copy data */
	memcpy(payload, d, length);
	
	/* fill the remaining data with stuffing bytes */
	memset(payload + length, STUFFING_BYTE, available - length);
}

void TSPacket::finalize() {
	/* TODO is it ok? isn't it missing something? */
	setSyncByte(SYNC_BYTE);
}
