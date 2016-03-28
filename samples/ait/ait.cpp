#include "TSPacket.h"
#include "AitSection.h"
#include "DvbJApplicationLocationDescriptor.h"
#include <iostream>
#include <cstdio>

using namespace std;

void show(unsigned char *s, unsigned length) {
	for (unsigned i = 0; i < length; i++) {
		cout << s[i];
	}
}

int main(int argc, char **argv) {
	if (argc < 2) {
		cout << "Input file missing!" << endl;
		return -1;
	}
	
	FILE *f = fopen(argv[1], "rb");

	if (!f) {
		cout << "File error!" << endl;
		return -1;
	}
	
	TSPacket *packet = new TSPacket();
	fread(packet->getData(), sizeof(unsigned char), TSPacket::PACKET_SIZE, f);
	fclose(f);
	unsigned length;
	unsigned char *data = packet->getPayload(length);
	AitSection *ait = new AitSection(data + 1 + data[0], length - 1 - data[0]);
	Iterator<AitSection::ApplicationLoopItem> *appItemIterator = ait->getApplicationLoopIterator();
	AitSection::ApplicationLoopItem *appItem = new AitSection::ApplicationLoopItem();
	
	while (appItemIterator->hasNext()) {
		data = appItemIterator->getNext(length);
		appItem->setData(data, length);
		
		Iterator<Descriptor> *descIterator = appItem->getDescriptorsIterator();
		Descriptor *desc = new Descriptor();
		
		while (descIterator->hasNext()) {
			data = descIterator->getNext(length);
			desc->setData(data, length);
			cout << "TAG: " << desc->getDescriptorTag() << endl;
			
			if (desc->getDescriptorTag() == DvbJApplicationLocationDescriptor::TAG) {
				DvbJApplicationLocationDescriptor *appDesc = new DvbJApplicationLocationDescriptor(data, length);
				data = appDesc->getBaseDirectory(length);
				cout << "Base Directory: '";
				show(data, length);
				cout << "'" << endl;
				data = appDesc->getClasspathExtension(length);
				cout << "Classpath Extension: '";
				show(data, length);
				cout << "'" << endl;
				data = appDesc->getInitialClass(length);
				cout << "Initial Class: '";
				show(data, length);
				cout << "'" << endl;
				
				break;
			}
		}
		
		delete descIterator;
		delete desc;
	}
	
	delete appItem;
	delete appItemIterator;
	delete ait;
	delete packet;
	
	return 0;
}

