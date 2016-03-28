#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern "C" {
	#include "mpe.h"
	#include "crc.h"
	#include "buffer/buffer.h"
}

#define BUFFERSIZE 2048

/* read a line from f. returns the line without the leading '\n' */
static char *readline(FILE *f) {
	char line[1024];
	
	if ((fgets(line, 1024, f)) == NULL)
		return NULL;
	
	line[strlen(line)-1] = '\0';
	
	if (line[strlen(line)-1] == '\r')
		line[strlen(line)-1] = '\0';
	
	return strdup(line);
}

int main(int argc, char **argv) {
	/* configuration */
	FILE *f = fopen("/etc/buffer.conf", "r");
	char *id;
	char *arg;
	char *destAddress = NULL;
	int listeningPort = -1;
	int destPort = -1;
	
	if (f == NULL) {
		printf("Erro...");
		exit(-1);
	}
	
	while ((id = readline(f)) != NULL) {
		if (isspace(*id) || *id == '#') {
			free(id);
			continue;
		}
		else {
			arg = strchr(id, '=');

			if (arg != 0) {
				*arg++ = '\0';
				
				if (strcasecmp(id, "LISTENING_PORT") == 0) {
					listeningPort = atoi(arg);
				}
				else if (strcasecmp(id, "DEST_ADDRESS") == 0) {
					destAddress = strdup(arg);
				}
				else if (strcasecmp(id, "DEST_PORT") == 0) {
					destPort = atoi(arg);
				}
			}
		}
		
		free(id);
	}

	if (listeningPort <= 0) {
		printf("Porta de escuta invalida!\n");
		exit(-1);
	}

	printf("Porta de escuta: %d\n", listeningPort);
	
	if (destPort <= 0) {
		printf("Porta de destino invalida!\n");
		exit(-1);
	}

	printf("Porta do destino: %d\n", destPort);
	
	if (destAddress == NULL) {
		printf("Endereco de destino invalido!\n");
		exit(-1);
	}

	printf("Endereco destino: %s\n", destAddress);

	/* end configuration */
	
	int socEncoder = socket(PF_INET, SOCK_DGRAM, 0);
	
	if (socEncoder <= 0) {
		perror("Erro ao criar socket!");
		exit(-1);
	}
	
	sockaddr_in localAddr;
	localAddr.sin_family = PF_INET;
	localAddr.sin_addr.s_addr = INADDR_ANY;
	localAddr.sin_port = htons(listeningPort);
	
	if (bind(socEncoder, (struct sockaddr *) &localAddr, sizeof(localAddr)) < 0) {
		perror("Erro ao fazer bind!");
		exit(-1);
	}
	
	unsigned nReceivedBytes;
	unsigned nPackets;
	unsigned char sendBuf[BUFFERSIZE];
	sockaddr_in encoderAddr;
	unsigned encoderAddrLen = sizeof(encoderAddr);
	int socDst = socket(PF_INET, SOCK_DGRAM, 0);
	
	if (socDst < 0) {
		perror("Erro ao criar socket!");
		exit(-1);
	}
	
	sockaddr_in dstAddr;
	dstAddr.sin_family = PF_INET;
	dstAddr.sin_addr.s_addr = inet_addr(destAddress); /* destiny's address */
	dstAddr.sin_port = htons(destPort); /* destiny's port */
	
	/* TODO replace the below line by: char *aux = (char *) malloc(sizeof(char) * 23 * 188); */
	char **aux = (char **) malloc(sizeof(char *) * 23);
	
	for (int i = 0; i < 23; i++)
		aux[i] = (char *) malloc(sizeof(char) * 188);
	
	unsigned count = 0; /* number of mpeg-2 ts packets to be sent */
	unsigned pos = 0; /* number of mpeg-2 ts packets already sent */
	IpDatagram ipDatagram;
	TsInfo tsInfo = {2600, 0}; /* ts information, pid, continuity counter */
	
	/* intialize the capture of ip datagram packets */
	
	buffer_t *buf = buffer_new();
	buffer_init_capture(buf);
	packet_t *packet;
	
	for (;;) {
		/* receive packets */
		nReceivedBytes = recvfrom(socEncoder, sendBuf, BUFFERSIZE, 0, (sockaddr *) &encoderAddr, &encoderAddrLen);
		
		if (nReceivedBytes <= 0) {
			perror("Falha na comunicacao com o encoder!");
			exit (-1);
		}
		
		/* precess */
		
		unsigned char *myBuf = sendBuf;
		unsigned pid;
		nPackets = nReceivedBytes / 188; /* number of received mpeg-2 ts packets */
		
		for (int i = 0; i < nPackets; i++) {
			pid = ((myBuf[1] & 0x1F) << 8) | myBuf[2]; /* pid of the received mpeg-2 ts packet */
			
			if (pid == 8191) { /* null mpeg-2 ts packet, it may be replaced */
				if (count == 0) { /* get an ip datagram to be multiplexed */
					packet = buffer_get_packet(buf);
					
					if (packet != NULL) { /* an ip datagram is available, it needs to be encapsulated into MPE */
						/* convert from packet_t struct to IpDatagram struct */
						ipDatagram.length = packet->length;
						ipDatagram.datagram = packet->data;
						memcpy(ipDatagram.mac, packet->mac, 6); /* copy mac address */
						printf("Encapsulando pacote ip no formato DSM-CC MPE...\n"); /* debug msg... */
						count = MultiprotocolEncapsulation(aux, &ipDatagram, &tsInfo) / 188;
						pos = 0;
					}
				}
				
				if (count != 0) { /* there is a mpeg-2 ts packet (MPE format) to be written */
					printf("Escrevendo pacote mpeg-2 ts...\n");
					memcpy(myBuf, aux[pos], 188);
					count--;
					pos++;
				}
			}
			else if (pid == 32) { /* alterar pmt */
				/*printf("pmt -> %d\n", myBuf[7]);*/ /* section length */
				myBuf[7] += 5; /* aumentando section length */
				/*for (int j = 8; j < 74; j++)
				printf("--->[%d] %d\n", j, myBuf[j]);*/
				/*printf("--->%d\n", myBuf[45]);*/ /* stream type */
				/*printf("--->%d\n", ((myBuf[46] & 0x1f) << 8) | myBuf[47]);*/ /* elementary pid */
				/*printf("--->%d\n", ((myBuf[48] & 0x0f) << 8) | myBuf[49]);*/ /* es info length */
				
				/* novo ES (notificacao do MPE)  */
				/* 22 eh o ultimo es info length */
				myBuf[50 + 22 + 0] = 0x0d; /* stream type */
				myBuf[50 + 22 + 1] = 0xca; /* reserved + es pid */
				myBuf[50 + 22 + 2] = 0x28; /* es pid */
				myBuf[50 + 22 + 3] = 0xF0; /* reserved + es info length */
				myBuf[50 + 22 + 4] = 0x0; /* es info length */
				
				/* CRC */
				unsigned int crc = calculateCRC(myBuf + 5, myBuf[7] - 1);
				myBuf[50 + 22 + 5] = (0xFF000000 & crc) >> 24;
				myBuf[50 + 22 + 6] = (0x00FF0000 & crc) >> 16;
				myBuf[50 + 22 + 7] = (0x0000FF00 & crc) >> 8;
				myBuf[50 + 22 + 8] = (0x000000FF & crc);
			}
			#if 1
			else if (pid = 0x11) { /* sdt ? */
				/* 0100 0000  */
				if (myBuf[1] & 0x40) { /* payload unit start indicator is set */
					printf("pointer\ttable_id\tlength\n");
					printf("%d\t0x%X\t%d\n", myBuf[4], myBuf[5 + myBuf[4]], ((myBuf[6] & 0x0F) << 8) | myBuf[7]);
				}
			}
			#endif
			
			myBuf += 188; /* go to the next mpeg-2 ts packet */
		}
		
		/* send packets */
		
		if (sendto(socDst, sendBuf, nReceivedBytes, 0, (sockaddr *) &dstAddr, sizeof(dstAddr)) <= 0) {
			perror("Erro ao enviar datagrama para destino!");
			exit(-1);
		}
	}
	
	/* stop the capture of ip datagram packets, will it be reached? not really... */
	
	buffer_stop_capture(buf);
	buffer_free(buf);
	
	return 0;
}
