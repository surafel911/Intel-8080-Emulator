CC = gcc

CFLAGS = \
		-m64 \
		-Wall \
		-Werror \
		-std=c99 \

BINARY = bin/intel-8080

SOURCES = src/*.c

INCLUDES = -Iinclude/

debug:
	$(CC) -g $(CFLAGS) $(SOURCES) $(INCLUDES) -o $(BINARY)

release:
	$(CC) -O3 $(CFLAGS) $(SOURCES) $(INCLUDES) -o $(BINARY)
