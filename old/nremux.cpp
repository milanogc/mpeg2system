#define RECV_BUFFER_SIZE 2048

#include "Encapsuler.h"

#include <string.h>
#include <ctype.h>

/* network */
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <stdio.h> /* FILE */
#include <stdlib.h>

#include <iostream>
using namespace std;

static void loadConfiguration(int &listeningPort, char *&destAddress, int &destPort);

int main(int argc, char **argv) {
	Encapsuler *encapsuler = new Encapsuler();
	unsigned char *packetData = new unsigned char[RECV_BUFFER_SIZE];
	
	int sourcePort;
	char *targetIpAddress;
	int targetPort;
	
	/* fill with the values acquired from the configuration file */
	loadConfiguration(sourcePort, targetIpAddress, targetPort);
	
	/* --- source socket --- */
	
	int sourceSocket = socket(PF_INET, SOCK_DGRAM, 0);
	
	if (sourceSocket <= 0) {
		cout << "error creating socket 1" << endl;
		return -1; /* error creating socket */
	}
	
	sockaddr_in sourceAddr;
	sourceAddr.sin_family = PF_INET;
	sourceAddr.sin_addr.s_addr = INADDR_ANY;
	sourceAddr.sin_port = htons(sourcePort); /* port to listen */
	unsigned sourceAddrLen = sizeof(sourceAddr);
	
	if (bind(sourceSocket, (struct sockaddr *) &sourceAddr, sizeof(sourceAddr)) < 0) {
		cout << "binding error" << endl;
		return -1; /* binding error */
	}
	
	/* --- target socket --- */
	
	int targetSocket = socket(PF_INET, SOCK_DGRAM, 0);
	
	if (targetSocket <= 0) {
		cout << "error creating socket 2" << endl;
		return -1; /* error creating socket */
	}
	
	sockaddr_in targetAddr;
	targetAddr.sin_family = PF_INET;
	targetAddr.sin_addr.s_addr = inet_addr(targetIpAddress);
	targetAddr.sin_port = htons(targetPort);
	
	while (true) {
		/* --- receive packets from source --- */
		
		int nReceivedBytes = recvfrom(sourceSocket, packetData, RECV_BUFFER_SIZE, 0, (sockaddr *) &sourceAddr, &sourceAddrLen);
		
		if (nReceivedBytes <= 0) {
			cout << "communication failed 1" << endl;
			return -1; /* communication failed */
		}
		
		/* --- process --- */
		
		int nTsPackets = nReceivedBytes / TS_PACKET_SIZE; /* number of received mpeg-2 ts packets */
		
		for (int i = 0; i < nTsPackets; i++) { /* process each packet */
			encapsuler->processPacket(packetData + TS_PACKET_SIZE * i);
		}
		
		/* --- send packets to target --- */
		
		if (sendto(targetSocket, packetData, nReceivedBytes, 0, (sockaddr *) &targetAddr, sizeof(targetAddr)) <= 0) {
			cout << "communication failed 2" << endl;
			return -1; /* communication failed */
		}
	}
	
	delete []packetData;
	delete encapsuler;
	
	return 0;
}

/*****************************************************************************
 * AUX FUNCTIONS                                                             *
 *****************************************************************************/

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

static void loadConfiguration(int &listeningPort, char *&destAddress, int &destPort) {
	FILE *f = fopen("/etc/buffer.conf", "r");
	char *id;
	char *arg;
	listeningPort = -1;
	destAddress = NULL;
	destPort = -1;
	
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
}
