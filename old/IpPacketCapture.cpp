#include <netinet/ether.h>
#include <netinet/in.h>
#include <pcap.h>
#include <string>

class IpPacketCapture {
	public:
		static const int MPE_IP_MTU = 4080;
		
		IpPacketCapture(char device[]) {
			captureDevice = device;
			
			if (captureDevice == NULL) {
				captureDevice = "eth0";
			}
			
			/* open the device for capture in promiscuos mode */
			pcap_lookupnet(captureDevice, &net, &mask, errBuf);
			handle = pcap_open_live(captureDevice, BUFSIZ, 1, TIMEOUT, errBuf);
		}
		
		~IpPacketCapture() {
			pcap_close(handle);
		}
		
		bool getPacket(unsigned char ipDatagram[], unsigned &ipDatagramLength, unsigned char ip[]) {
			ipDatagramLength = 0;
			
			/* grab a packet */
			packet = pcap_next(handle, &header);
			
			/* check its length and type */
			if ((packet == NULL) || (header.len > MPE_IP_MTU)  || (header.len <= SIZE_ETHERNET)) {
				return false;
			}
			else {
				ethernet = (struct ether_header*) (packet); /* cast to ethernet */
				
				if (htons(ethernet->ether_type) != ETHERTYPE_IP)
					return false; /* not interested in this kind of traffic */
				
				/* IP */
				memcpy(ip, ethernet->ether_dhost, 6);
				
				/* datagram */
				ipDatagramLength = header.len - SIZE_ETHERNET;
				memcpy(ipDatagram, packet + SIZE_ETHERNET, ipDatagramLength);
				
				return true;
			}
		}
	
	private:
		char* captureDevice; /* the selected capture device */
		pcap_t *handle; /* session handle */
		char errBuf[PCAP_ERRBUF_SIZE]; /* error buffer */
		bpf_u_int32 mask; /* our netmask */
		bpf_u_int32 net; /* our IP */
		struct pcap_pkthdr header; /* the header that pcap gives back */
		const u_char *packet; /* the actual packet */
		const struct ether_header *ethernet; /* cast to ethernet struct */
		static const int SIZE_ETHERNET = sizeof(struct ether_header); /* size of ethernet struct */
		static const int TIMEOUT = 500;
};
