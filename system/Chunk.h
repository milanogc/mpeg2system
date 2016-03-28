/**
 * Milano 2004.06.08-19:24 (YYYY.MM.DD-HH:MM)
 */

/* TODO implement deep copies */

#ifndef CHUNK_H
#define CHUNK_H

#define getByte(index) (data[(index)])
#define setByte(index,value) (data[(index)]=(value))

class Chunk {
	public:
		Chunk(unsigned char *d, unsigned l);
		Chunk(const Chunk &c);
		virtual ~Chunk();
		Chunk &operator=(const Chunk &c);
		
		unsigned char *getData() const;
		bool isAllocated() const;
		
		void setData(unsigned char *d, unsigned l);
		virtual unsigned getDataLength() const;
		virtual void finalize();
		virtual bool verify() const;
	
	protected:
		unsigned char *data;
		unsigned length;
		bool allocated;
};

#endif /* CHUNK_H */
