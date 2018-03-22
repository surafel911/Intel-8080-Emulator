#include <memory.h>

#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <error.h>

#define PROGRAM_MAX_SIZE	0x1FFF

static uint8_t _memory[USHRT_MAX];

// TODO: Find out of there is any limit to programmable ROM.
// TODO: Find out the starting address for ROM to be loaded.
// TODO: Find out how many bytes are reserved for interrupts.

void
memory_load_program(const uint8_t* program, const uint16_t size)
{
	if (size > PROGRAM_MAX_SIZE) {
		error("Error: Program size too large.");
	}

	memcpy((void*)_memory + 64, (void*)program, size * 2);
	free((uint16_t*)program);
}

uint8_t
memory_read(const uint16_t location)
{
	return _memory[location];
}

void
memory_write(const uint16_t location, const uint8_t word)
{
	_memory[location] = word;
}
