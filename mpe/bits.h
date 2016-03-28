#ifndef _BITS_H_
#define _BITS_H_

/* state of the buffer and the buffer itself */
typedef struct {
	int index;
	int mask;
	char *data;
} BitsBuffer;

/**
 * Intialize the BitsBuffer struct and bind the data to it
 * @param buffer
 * @param data
 */
static inline void initBits(BitsBuffer *buffer, char *data)
{
	buffer->index = 0;
	buffer->mask = 0x80;
	buffer->data = data;
	buffer->data[0] = 0;
}

/**
 * Write value into buffer using n bits
 * @param buffer The buffer
 * @param n The number of bits
 * @param value The value to be written into buffer
 */
static inline void writeBits(BitsBuffer *buffer, int n, int value)
{
	while (n > 0) {
		n--;
		
		if ((value >> n) & 0x01)
			buffer->data[buffer->index] |= buffer->mask;
		else
			buffer->data[buffer->index] &= ~buffer->mask;
		
		buffer->mask >>= 1;
		
		if (buffer->mask == 0) {
			buffer->index++;
			buffer->mask = 0x80;
		}
	}
}

/**
 * Skip a number of bytes in buffer
 * @param buffer The buffer
 * @param n The number of bytes to be skiped
 */
static inline void skipBytes(BitsBuffer *buffer, int n)
{
	buffer->index += n;
}

#endif
