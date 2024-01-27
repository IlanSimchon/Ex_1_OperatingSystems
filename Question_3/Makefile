CC = gcc
CFLAGS = -Wall -g

all: libCodec.so encode decode

libCodec.o: libCodec.c libCodec.h
	$(CC) $(CFLAGS) -c -fPIC libCodec.c

libCodec.so: libCodec.o
	$(CC) -shared -o libCodec.so libCodec.o

mainEncode.o: mainEncode.c libCodec.h
	$(CC) $(CFLAGS) -c mainEncode.c

mainDecode.o: mainDecode.c libCodec.h
	$(CC) $(CFLAGS) -c mainDecode.c

encode: libCodec.so mainEncode.o
	$(CC) $(CFLAGS) -o encode mainEncode.o -L. -lCodec

decode: libCodec.so mainDecode.o
	$(CC) $(CFLAGS) -o decode mainDecode.o -L. -lCodec

clean:
	rm -f libCodec.o mainEncode.o mainDecode.o encode decode libCodec.so
