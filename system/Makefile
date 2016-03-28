CC = g++
CFLAGS = -c -ansi -Wall -O2 # -DNDEBUG
LDFLAGS = -L/usr/local/lib
SOURCES = \
	AitSection.cpp \
	ApplicationSignallingDescriptor.cpp \
	AssociationTagDescriptor.cpp \
	CarouselIdentifierDescriptor.cpp \
	Chunk.cpp \
	crc.c \
	DataBroadcastDescriptor.cpp \
	DataBroadcastIdDescriptor.cpp \
	Descriptor.cpp \
	DvbJApplicationLocationDescriptor.cpp \
	IntSection.cpp \
	IpMacNotificationInfo.cpp \
	LinkageDescriptor.cpp \
	MpeInfo.cpp \
	NitSection.cpp \
	PatSection.cpp \
	PesPacket.cpp \
	PmtSection.cpp \
	PsiSection.cpp \
	SdtSection.cpp \
	Section.cpp \
	SectionToPacket.cpp \
	StreamIdentifierDescriptor.cpp \
	TSPacket.cpp

OBJECTS = $(SOURCES:.cpp=.o) $(SOURCES:.c=.o)

all: $(OBJECTS)

c.o:
	$(CC) $(CFLAGS) $< -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -rf *.o

del:
	@del /q *.o *.exe
