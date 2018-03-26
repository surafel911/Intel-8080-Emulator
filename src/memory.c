#include <memory.h>

#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <error.h>

#define ROM_ADDRESS_SPACE	0x1FFF

static uint8_t _memory[USHRT_MAX];

// TODO: Find out the starting address for ROM to be loaded.
// TODO: Find out how many bytes are reserved for interrupts.

void
memory_load_program(const uint8_t* program, const uint16_t size)
{
	if (size > ROM_ADDRESS_SPACE) {
		error("Error: Program size exceeds ROM address space.");
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
	if (location <= ROM_ADDRESS_SPACE) {
		error("Error: Attempting to write in ROM address space.");
	}
	_memory[location] = word;
}
