/**
 * Milano 2004.06.08-19:24 (YYYY.MM.DD-HH:MM)
 */

#include "Chunk.h"
#include <string>
#include <cassert>

Chunk::Chunk(unsigned char *d, unsigned l) {
	allocated = d == NULL;
	length = l;
	
	if (allocated) {
		assert(length > 0);
		data = new unsigned char[length];
	}
	else {
		data = d;
	}
}

//Chunk::Chunk(const Chunk &c) :
//	allocated = true;
//}

Chunk::~Chunk() {
	if (allocated) /* internally allocated */
		delete []data;
}

//Chunk &Chunk::operator=(const Chunk &c) {
//	/* TODO implement */
//}

unsigned char *Chunk::getData() const {
	return data;
}

bool Chunk::isAllocated() const {
	return allocated;
}

unsigned Chunk::getDataLength() const {
	return 0; /* we don't know ;) */
}

void Chunk::setData(unsigned char *d, unsigned l) {
	if (allocated) { /* copy */
		/*assert(l != 0);*/
		memcpy(data, d, l);
	}
	else { /* point to */
		assert(d != NULL);
		data = d;
		length = l;
	}
}

void Chunk::finalize() {
	/* do nothing */
}

bool Chunk::verify() const {
	return true;
}
