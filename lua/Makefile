CC = g++
WARN = -ansi -Wall

# set lua path
LUA = /c/Lua
#LUA = /usr/local
LUAINC = $(LUA)/include
LUALIB = $(LUA)/lib

# set tolua path
TOLUA = /c/Lua/tolua
#TOLUA = /home/milano/usr/tolua

INCDIR = -I$(LUAINC) -I$(TOLUA)/include -I./..
LIBDIR = -L$(LUALIB) -L$(TOLUA)/lib

CPPFLAGS = -O2 $(WARN) $(INCDIR)
LIBS = $(LIBDIR) -ltolua -llua -llualib

OBJS = \
	../PatSection.o \
	../PesPacket.o \
	../PmtSection.o \
	../PsiSection.o \
	../Section.o \
	../Descriptor.o \
	../ApplicationSignallingDescriptor.o \
	../AssociationTagDescriptor.o \
	../CarouselIdentifierDescriptor.o \
	../DataBroadcastIdDescriptor.o \
	../StreamIdentifierDescriptor.o \
	../TSPacket.o \
	../crc.o \
	../Chunk.o

PKGS = \
	Chunk.pkg \
	Iterator.pkg \
	TSPacket.pkg \
	PesPacket.pkg \
	Descriptor.pkg \
	Section.pkg \
	PsiSection.pkg \
	PatSection.pkg \
	PmtSection.pkg \
	ApplicationSignallingDescriptor.pkg \
	AssociationTagDescriptor.pkg \
	CarouselIdentifierDescriptor.pkg \
	DataBroadcastIdDescriptor.pkg \
	StreamIdentifierDescriptor.pkg

all: luampeg2.so # dll

luampeg2.so: mpeg2.cpp Lmpeg2.o
	$(CC) $(CPPFLAGS) mpeg2.cpp -shared -o luampeg2.dll Lmpeg2.o $(OBJS) $(LIBS)

Lmpeg2.o: Lmpeg2.cpp
	$(CC) $(CPPFLAGS) -c Lmpeg2.cpp

Lmpeg2.cpp: $(PKGS)
	cat $(PKGS) > mpeg2.pkg
	$(TOLUA)/bin/tolua -S -o Lmpeg2.cpp mpeg2.pkg

clean:
	@rm -f main main.exe *.o rm luampeg2.dll mpeg2.pkg Lmpeg2.cpp
