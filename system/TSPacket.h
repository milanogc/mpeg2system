/**
 * @author Milano Gadelha Carvalho
 * @date 2004.06.06 (YYYY.MM.DD)
 * @brief Transport Stream packet abstraction.
 */
#ifndef TSPACKET_H
#define TSPACKET_H

#include "Chunk.h"

enum AdaptFieldControl {
	AFC_RESERVED = 0,
	AFC_ONLY_PAYLOAD,
	AFC_ONLY_ADAPT_FIELD,
	AFC_BOTH_PAYLOAD_AND_ADAPT_FIELD
};

enum ScramblingControl {
	SC_NOT_SCRAMBLED = 0,
	SC_USER_DEFINED_1,
	SC_USER_DEFINED_2,
	SC_USER_DEFINED_3
};

class TSPacket : public Chunk {
public:
	static const unsigned PACKET_SIZE = 188;
	static const unsigned MAX_PAYLOAD_SIZE = 184;
	static const unsigned STUFFING_BYTE = 0xFF;
	static const unsigned SYNC_BYTE = 0x47;
	
	TSPacket(unsigned char *d);
	TSPacket();
	~TSPacket();
	
	/* --- basic --- */
	
	/* --- packet decoding --- */
	
	/* packet header */
	
	/**
	 * Get the sync byte of the packet.
	 * @return The sync byte, which should be the value 0x47.
	 */
	unsigned getSyncByte() const; /* 8 */
	
	/**
	 * Get the transport error indicator. If its value is true at least one bit is
	 * uncorrectable in the associated Transport Stream packet.
	 * @return The transport error indicator.
	 */
	bool getTransportErrorIndicator() const; /* 1 */
	
	/**
	 * Get the payload unit start indicator. It has normative meaning for Transport
	 * Stream packets that carry PES packets or PSI data.
	 * @return The payload unit start indicator.
	 */
	bool getPayloadUnitStartIndicator() const; /* 1 */
	
	/**
	 * Get the transport priority. When true it indicates that the associated packet
	 * is of greater priority than other packets having the same PID which do not
	 * have the transport priority enabled.
	 * @return The payload unit start indicator.
	 */
	bool getTransportPriority() const; /* 1 */
	
	/**
	 * Get the PID.
	 * The PID indicates the type of the data stored in the packet payload. Some
	 * values are reserved.
	 * @return The PID.
	 */
	int getPid() const; /* 13 */
	
	/**
	 * Get the transport scrambling control. If the packet is scrambled
	 * only the payload shall be scrambled. Neither the header nor the adaptation
	 * field should be scrambled.
	 * @return The scrambling control.
	 */
	ScramblingControl getTransportScramblingControl() const; /* 2 */
	
	/**
	 * Get the adaptation field control. This field is used to specify if the packet
	 * holds, besides the header, the adaptation field, the payload, or both.
	 * @return The adaptation field control.
	 */
	AdaptFieldControl getAdaptationFieldControl() const; /* 2 */
	
	/**
	 * Get the continuity counter.
	 * @return The continuity counter.
	 */
	unsigned getContinuityCounter() const; /* 4 */
	
	/* adaptation field */
	
	/**
	 * Inform if the packet has an adaptation field.
	 * @return True if the packets has an adaptation field, false otherwise.
	 */
	bool hasAdaptationField() const;
	
	/**
	 * Get the length of the adaptation field. Be sure that the adaptation field
	 * exist.
	 * @return The length of the adaptation field.
	 */
	unsigned getAdaptationFieldLength() const;
	
	/**
	 * Get the discontinuity indicator.
	 * @see ITU-T H.222.0 2.4.3.5 page 21 (discontinuity indicator)
	 * @return The discontinuity indicator.
	 */
	bool getDiscontinuityIndicator() const;
	
	/**
	 * Get the random access indicator.
	 * @return The random access indicator.
	 */
	bool getRandomAccessIndicator() const;
	
	/**
	 * Get the elementary stream priority indicator.
	 * @return The elementary stream priority indicator.
	 */
	bool getElementaryStreamPriorityIndicator();
	
	/**
	 * Get the PCR flag.
	 * @return The PCR flag.
	 */
	bool getPcrFlag() const;
	
	/**
	 * Get the OPCR flag.
	 * @return The OPCR flag.
	 */
	bool getOpcrFlag() const;
	
	/**
	 * Get the splicing point flag.
	 * @return The splicing point flag.
	 */
	bool getSplicingPointFlag() const;
	
	/**
	 * Get the transport private data flag.
	 * @return The transport private data flag.
	 */
	bool getTransportPrivateDataFlag() const;
	
	/**
	 * Get the adaptation field extension flag.
	 * @return The adaptation field extension flag.
	 */
	bool getAdaptationFieldExtensionFlag() const;
	
	/**
	 * Inform if the packet has a PCR.
	 * @return True if the packet has a PCR, false otherwise.
	 */
	bool hasPcr() const;
	
	/**
	 * Get the PCR base. The PCR base is value of 33 bits of a 29 KHz clock.
	 * Make sure the packet has a PCR by using hasPcr beforehand.
	 * @return The PCR base.
	 */
	unsigned long long getPcrBase() const; /* 33 */
	
	/**
	 * Get the PCR extension. The PCR extension is value of 9 bits of a 27 MHz clock.
	 * Make sure the packet has a PCR by using hasPcr beforehand.
	 * @return The PCR extension.
	 */
	unsigned getPcrExtension() const; /* 9 */
	
	/**
	 * Inform if the packet has an original PCR.
	 * @return True if the packet has an original PCR, false otherwise.
	 */
	bool hasOriginalPcr() const;
	
	/**
	 * Get the original PCR base.
	 * @return The original PCR base.
	 */
	unsigned long long getOriginalPcrBase() const; /* 33 */
	
	/**
	 * Get the original PCR extension.
	 * @return The original PCR extension.
	 */
	unsigned getOriginalPcrExtension() const; /* 9 */
	bool hasSpliceCountdown() const;
	unsigned getSpliceCountdown() const; /* 8 */
	bool hasTransportPrivateData() const;
	unsigned getTransportPrivateDataLength() const; /* 8 */
	unsigned char *getTransportDataBytes(unsigned &length) const;
	bool hasAdaptationFieldExtension() const;
	unsigned getAdaptationFieldExtensionLength() const;
	bool getLtwFlag() const;
	bool getPiecewiseRateFlag() const;
	bool getSeamlessSpliceFlag() const;
	bool hasLtw() const;
	bool getLtwValidFlag() const;
	unsigned getLtwOffset() const; /* 15 */
	bool hasPiecewiseRate() const;
	unsigned getPiecewiseRate() const; /* 22 */
	bool hasSeamlessSplice() const;
	unsigned getSpliceType() const; /* 4 */
	unsigned long long getDtsNextAu() const; /* 33 */
	
	/* payload */
	
	/**
	 * Get the length of the packet's payload.
	 * @return The length.
	 */
	unsigned getPayloadLength() const;
	
	/**
	 * Get the payload.
	 * @param length A variable wich will be filled with the length of the payload.
	 * @return The payload.
	 */
	unsigned char *getPayload(unsigned &length) const;
	
	/* aux */
	
	/**
	 * Get the length of the whole packet.
	 * @return The length.
	 */
	unsigned getDataLength() const;
	
	bool verify();
	
	/* --- packet coding --- */
	
	/* packet header */
	
	void setTransportErrorIndicator(bool transportError); /* 1 */
	void setPayloadUnitStartIndicator(bool payloadUnitStart); /* 1 */
	void setTransportPriority(bool transportPriority); /* 1 */
	void setPid(int pid); /* 13 */
	void setTransportScramblingControl(ScramblingControl scramblingControl); /* 2 */
	
	/**
	 * Set the adaptation field control. This field is very
	 * important since the existence of the adaptation field and payload is holded
	 * by the value of this field.
	 * @param adaptationFieldControl The value of the adaptation field.
	 */
	void setAdaptationFieldControl(AdaptFieldControl adaptationFieldControl); /* 2 */
	
	/**
	 * Set the continuity counter.
	 * @param continuityCounter The continuity counter value, its value should be
	 * in the range 0 to 15 since the field length is 4 bits.
	 */
	void setContinuityCounter(unsigned continuityCounter); /* 4 */
	
	/**
	 * Increment the continuity counter. Since the continuity counter is
	 * a field of 4 bits the values loop from 0 to 15.
	 */
	void incContinuityCounter();
	
	/* adaptation field */
	
	void setAdaptationFieldLength(unsigned aFieldLength);
	void setDiscontinuityIndicator(bool indicator);
	void setRandomAccessIndicator(bool indicator);
	void setElementaryStreamPriorityIndicator(bool indicator);
	void setPcrFlag(bool flag);
	void setOpcrFlag(bool flag);
	void setSplicingPointFlag(bool flag);
	void setTransportPrivateDataFlag(bool flag);
	void setAdaptationFieldExtensionFlag(bool flag);
	void setPcrBase(unsigned long long pcrBase); /* 33 */
	void setPcrExtension(unsigned pcrExtension); /* 9 */
	void setOriginalPcrBase(unsigned long long pcrBase); /* 33 */
	void setOriginalPcrExtension(unsigned pcrExtension); /* 9 */
	void setSpliceCountdown(unsigned countdown); /* 8 */
	void setTransportPrivateDataLength(unsigned dataLength); /* 8 */ /* TODO remove */
	void setTransportDataBytes(unsigned char *dataBytes, unsigned dataLength);
	void setAdaptationFieldExtensionLength(bool flag);
	void setLtwFlag(bool flag);
	void setPiecewiseRateFlag(bool flag);
	void setSeamlessSpliceFlag(bool flag);
	void setLtwValidFlag(bool flag);
	void setLtwOffset(unsigned offset); /* 15 */
	void setPiecewiseRate(unsigned rate); /* 22 */
	void setSpliceType(unsigned spliceType); /* 4 */
	void setDtsNextAu(unsigned long long dtsNextAu); /* 33 */
	
	/**
	 * Set the data of the payload.
	 * @param d The data to be copied to the payload.
	 * @param length The length of the data. The data length should not be greater than
	 * the length available in the payload.
	 */
	void setPayload(unsigned char *d, unsigned length);
	
	/**
	 * Set the fixed values of the packet. Such values correspond to reserved and
	 * other fields that should have a fixed value.
	 */
	void finalize();

protected:
	void setSyncByte(unsigned value);
};

#endif /* TSPACKET_H */
