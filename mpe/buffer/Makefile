CC = gcc
CFLAGS = -Wall -ggdb -O3 -D__DEBUG__ `glib-config --cflags`
LIBS = -pthread -lpcap `glib-config --libs`

buffer.o: buffer.c multi.o hash.o
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

main: main.c buffer.o multi.o hash.o
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

hash: hash.o
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

.PHONY: clean
clean:
	rm -f *~ *.o main hash
