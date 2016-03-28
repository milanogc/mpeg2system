#define RECV_BUFFER_SIZE 188

#include "Encapsuler.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {
	ifstream in(argv[1], ios::binary); /* input file */
	ofstream of("res.ts", ios::binary);
	
	Encapsuler *encapsuler = new Encapsuler();
	unsigned char *packetData = new unsigned char[RECV_BUFFER_SIZE];
	TSPacket *packet = new TSPacket(false);
	
	while (in.read((char *) packetData, RECV_BUFFER_SIZE)) {
		if (!encapsuler->processPacket(packetData))
			break;
		
		packet->setData(packetData);
		
		if (packet->getPid() != 8191)
			of.write((char *) packetData, 188);
	}
	
	of.write((char *) packetData, 188);
	in.close();
	of.close();
	cout << "*** End of file ***" << endl;
	
	return 0;
}
