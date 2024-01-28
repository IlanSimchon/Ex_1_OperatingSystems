CC = gcc
CFLAGS = -Wall -g

all: libencriptor.so encode decode

libencriptor.o: libCodec.c libCodec.h
	$(CC) $(CFLAGS) -c -fPIC libCodec.c -o libencriptor.o

libencriptor.so: libencriptor.o
	$(CC) -shared -o libencriptor.so libencriptor.o

mainEncode.o: mainEncode.c libCodec.h
	$(CC) $(CFLAGS) -c mainEncode.c

mainDecode.o: mainDecode.c libCodec.h
	$(CC) $(CFLAGS) -c mainDecode.c

encode: libencriptor.so mainEncode.o
	$(CC) $(CFLAGS) -o encode mainEncode.o -L. -lencriptor

decode: libencriptor.so mainDecode.o
	$(CC) $(CFLAGS) -o decode mainDecode.o -L. -lencriptor

clean:
	rm -f libencriptor.o mainEncode.o mainDecode.o encode decode libencriptor.so
