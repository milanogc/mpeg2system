#ifndef PESPACKET_H
#define PESPACKET_H

#include "Chunk.h"

#define PROGRAM_STREAM_MAP              0xBC
#define PRIVATE_STREAM_1                0xBD
#define PADDING_STREAM                  0xBE
#define PRIVATE_STREAM_2                0xBF
#define ECM_STREAM                      0xF0
#define EMM_STREAM                      0xF1
#define PROGRAM_STREAM_DIRECTORY        0xFF
#define DSMCC_STREAM                    0xF2
#define ITU_T_REC_H_222_1_TYPE_E_STREAM 0xF8

class PesPacket : public Chunk {
	public:
		PesPacket(unsigned char *d, unsigned l);
		
		/**
		 * This constructor creates a bounded PES Packet...
		 */
		PesPacket();
		
		~PesPacket();
		
		/* -- decoding -- */
		
		unsigned getPacketStartCodePrefix() const; /* 24 */
		unsigned getStreamId() const; /* 8 */
		unsigned getPesPacketLength() const; /* 16 */
		unsigned getPesScramblingControl() const; /* 2 */ /* TODO enum */
		bool getPesPriority() const; /* 1 */
		bool getDataAlignmentIndicator() const; /* 1 */
		bool getCopyright() const; /* 1 */
		unsigned getOriginalOrCopy() const;
		unsigned getPtsDtsFlags() const; /* 2 */
		bool getEscrFlag() const;
		bool getEsRateFlag() const;
		bool getDsmTrickModeFlag() const;
		bool getAdditionalCopyInfoFlag() const;
		bool getPesCrcFlag() const;
		bool getPesExtensionFlag() const;
		unsigned getPesHeaderDataLength() const;
		bool hasPts() const;
		unsigned long long getPts() const; /* 33 */
		bool hasDts() const;
		unsigned long long getDts() const; /* 33 */
		bool hasEscr() const;
		unsigned long long getEscrBase() const;
		unsigned getEscrExtension() const;
		bool hasEsRate() const;
		unsigned getEsRate() const; /* 22 */
		bool hasDsmTrickMode() const;
		bool hasAdditionalCopyInfo() const;
		bool getAdditionalCopyInfo() const; /* 7 */
		bool hasPesCrc() const;
		bool hasPesExtension() const;
		bool getPesPrivateDataFlag() const;
		bool getPackHeaderFieldFlag() const;
		bool getProgramPacketSequenceCounterFlag() const;
		bool getPStdBufferFlag() const;
		bool getPesExtensionFlag2() const;
		bool hasPrivateData() const;
		bool hasPackHeader() const;
		unsigned getPackFieldLength() const; /* 8 */
		bool hasProgramPacketSequenceCounter() const;
		bool hasPStdBuffer() const;
		bool hasPesExtension2() const;
		unsigned getPesExtensionFieldLength() const; /* 7 */
		
		unsigned char *getPesPacketData() const;
		unsigned getDataLength() const;
		bool verify() const;
		
		/* -- coding -- */
		
		void setPacketStartCodePrefix(unsigned prefix); /* TODO protected */ /* 24 */
		void setStreamId(unsigned id); /* 8 */
		void setPesPacketLength(unsigned packetLength); /* 16 */
		void setPesScramblingControl(unsigned sControl); /* 2 */ /* TODO enum */
		void setPesPriority(bool priority); /* 1 */
		void setDataAlignmentIndicator(bool indicator); /* 1 */
		void setCopyright(bool copyright); /* 1 */
		void setOriginalOrCopy(bool originalOrCopy); /* 1 */
		void setPtsDtsFlags(unsigned flags); /* 2 */
		void setEscrFlag(bool flag);
		void setEsRateFlag(bool flag);
		void setDsmTrickModeFlag(bool flag);
		void setAdditionalCopyInfoFlag(bool flag);
		void setPesCrcFlag(bool flag);
		void setPesExtensionFlag(bool flag);
		void setPesHeaderDataLength(unsigned length);
		void setPts(unsigned long long pts); /* 33 */
		void setDts(unsigned long long dts); /* 33 */
		void setEscrBase(unsigned long long base);
		void setEscrExtension(unsigned extension);
		void setEsRate(unsigned rate); /* 22 */
		
		void finalize();
};

#endif // PESPACKET_H
