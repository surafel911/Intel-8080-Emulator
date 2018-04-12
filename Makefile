CC = gcc

CFLAGS = \
		-m64 \
		-Wall \
		-Werror \
		-std=c99 \

BINARY = bin/intel-8080

CPPFLAGS = -Iinclude/

debug: src/*.c
	$(CC) -g $(CFLAGS) $^ $(CPPFLAGS) -o $(BINARY)

release: src/*.c
	$(CC) -O3 $(CFLAGS) $^ $(CPPFLAGS) -o $(BINARY)

clean:
	rm bin/intel-8080
