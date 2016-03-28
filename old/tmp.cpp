#define DUMMY_PID 8192
#define PAT_PID 0

class TsPacketFactory {
	public:
		TsPacketFactory();
		~TsPacketFactory();
		TsPacket *getTsPacket();
		void release(TsPacket *packet);
	
	protected:
		TsPacket **packets;
		int nPackets;
}



class TsPacketChain {
	public:
		TsPacketChain(TsPacket *actual, TsPacket *next);
		~TsPacketChain();
		TsPacket *getTsPacket();
		TsPacket *getNextTsPacket();
		void setTsPackets(TsPacket *actual, TsPacket *next);
	
	protected:
		TsPacket *packet;
		TsPacketChain *next;
}

TsPacketStream *sectionToTsPackets(Section *section, TsPacketFactory *factory);

#endif

int main(int argc, char **argv) {
	TsPacket *packet = factory->getTsPacket();
	PatSection *pat = new PatSection();
	PmtSection *pmt = new PmtSection();
	int pmtPid = DUMMY_PID;
	
	while (true) {
		/* acquire data */
		packet->loadData(data, TS_PACKET_SIZE);
		
		if (packet->getPid() == PAT_PID) {
			if (packet->getPayloadUnitStart() && !newPat->isClean())
				newPat->reset();
			
			if (!newPat->appendData(packet)) { /* append data from packet */
				/* discontinuity error ? */
				newPat->reset();
				continue;
			}
			
			if (newPat->isComplete()) {
				if (newPat->verify()) {
				}
			}
			
			PmtSection::PmtPrograms *programs = pat->getPrograms();
			
			if (programs)
				pmtPid = programs->getPid(); /* the first program */
		}
		else if (packet->getPid() == pmtPid) {
			if (packet->getPayloadUnitStart() && !newPmt->isClean())
				newPmt->reset();
			
			if (!newPmt->appendData(packet)) { /* append data from packet */
				/* discontinuity error ? */
				newPmt->reset();
				continue;
			}
			
			if (newPmt->isComplete()) {
				if (newPmt->verify()) {
					newPmt->addStream(stream); /* TODO define stream */
					newPmt->finalize(); /* update version, computes crc32, append stuffing bytes */
					
					/* convert to ts packets */
					TsPacketChain *chain = sectionToTsPackets(newPmt, factory);
					TsPacketChain *aux;
					
					while (stream != NULL) {
						chain->getTsPacket(); /* send packet */
						aux = stream;
						chain = chain->getNextTsPacket();
						delete aux;
					}
					
					/* swap */
					PmtSection *aux = pmt;
					pmt = newPmt;
					newPmt = aux;
				}
				else
					newPmt->reset();
			}
		}
		else {
			/* send packet */
		}
	}
	
	return 0;
}
