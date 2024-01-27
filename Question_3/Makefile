CC = gcc

CFLAGS = -Wall -g

all: encode decode

libCodec.o: libCodec.c libCodec.h

	$(CC) $(CFLAGS) -c libCodec.c
mainEncode.o: mainEncode.c libCodec.h

	$(CC) $(CFLAGS) -c mainEncode.c
mainDecode.o: mainDecode.c libCodec.h

	$(CC) $(CFLAGS) -c mainDecode.c
libCodec: libCodec.o

	$(CC) $(CFLAGS) -o libCodec libCodec.o
encode: libCodec.o mainEncode.o

	$(CC) $(CFLAGS) -o encode libCodec.o mainEncode.o
decode: libCodec.o mainDecode.o

	$(CC) $(CFLAGS) -o decode libCodec.o mainDecode.o
clean:

	rm -f libCodec.o mainEncode.o mainDecode.o encode decode libCodec