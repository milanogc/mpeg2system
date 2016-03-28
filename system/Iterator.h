#ifndef ITERATOR_H
#define ITERATOR_H

#include <cassert> /* assert */

template <class T>
class Iterator {
public:
	Iterator(unsigned char *start, unsigned length);
	~Iterator();
	
	/**
	 * Inform if there is more elements to be retrieved.
	 * @return True if there is more elements, false otherwise.
	 */
	bool hasNext() const;
	
	/**
	 * Get the data of the next element.
	 * @param length Output param that informs the length of the returned data.
	 * @return The data of the next element.
	 */
	unsigned char *getNext(unsigned &length);
	
	/**
	 * Get the length of the data of the next element.
	 * @return The length of the data of the next element.
	 */
	unsigned getNextLength();

protected:
	unsigned char *data;
	unsigned dataLength;
	unsigned readPos;
	T templateObject;
};

template <class T>
Iterator<T>::Iterator(unsigned char *start, unsigned l) :
	data(start),
	dataLength(l),
	readPos(0),
	templateObject(start) {
}

template <class T>
Iterator<T>::~Iterator() {
	/* nothing to be deleted */
}

template <class T>
bool Iterator<T>::hasNext() const {
	return readPos < dataLength;
}

template <class T>
unsigned char *Iterator<T>::getNext(unsigned &length) {
	assert(hasNext());
	templateObject.setData(&data[readPos], 0);
	length = templateObject.getDataLength();
	readPos += length;
	return templateObject.getData();
}

template <class T>
unsigned Iterator<T>::getNextLength() {
	assert(hasNext());
	templateObject.setData(&data[readPos], 0);
	return templateObject.getDataLength();
}

#endif /* ITERATOR_H */
