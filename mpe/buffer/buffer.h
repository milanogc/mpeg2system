/** 
    @file buffer.h
    Defines the interface to capture the packets.

    This File defines a buffer that is filed with
    network packets matching a filter defined in the
    config file (./buffer.conf).  It defines also
    a interface to let the user receive the most
    recent packet.
 */

#ifndef BUFFER_H

typedef struct __packets__ packet_t;
struct __packets__ {
  unsigned length;
  char mac[6];
  char data[65536];
};

/* defines the user interface to access the buffer. */
typedef struct __buffer__ buffer_t;
struct __buffer__ {
  unsigned buffer_size;	        /* maximum #packets */
  unsigned out_pos;		/* position for output pkts */
  unsigned in_pos;		/* position for input pkts */
  packet_t *packets;		/* contains the apckets */
};

/**
   @fn buffer_t *buffer_new(void)
   @brief Alloc space and initialize a new buffer.
   @return a pointer to the newly alloced buffer.
 */
buffer_t *buffer_new(void);

/**
   @fn void buffer_free(buffer_t *)
   @brief Relieses memory alloced by buffer_new
   @param b A buffer returned by new_buffer
 */
void buffer_free(buffer_t *b);

/**
   @fn void buffer_init_capture(buffer_t *b)
   @brief Initialize the packet capture
   @param b A buffer returned by new_buffer.
 */
void buffer_init_capture(buffer_t *b);

/**
   @fn void buffer_stop_capture(buffer_t *b)
   @brief Stops the packet capture.
   @param b A buffer returned by new_buffer.
 */
void buffer_stop_capture(buffer_t *b);

/**
   @fn packet_t *buffer_get_packet(buffer_t *b)
   @brief Get the first packet in the buffer..
   @param b A buffer returned by new_buffer.
 */
packet_t *buffer_get_packet(buffer_t *b);

/**
   @fn int buffer_is_empty(buffer_t *b)
   @brief Function to test if buffer is empty
   @param b A buffer returned by new_buffer.
   @return non zero if b is empty, zero otherwise.
 */
int buffer_is_empty(buffer_t *b);

/**
   @fn int buffer_is_full(buffer_t *b)
   @brief Function to test if buffer is full.
   @param b A buffer returned by new_buffer.
   @return non zero if b is full, zero otherwise.
 */
int buffer_is_full(buffer_t *b);

#endif /* ! BUFFER_H */
