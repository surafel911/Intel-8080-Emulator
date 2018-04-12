#pragma once

#include <stdint.h>

#define MEMORY_ROM_OFFSET		0x40
#define MEMORY_RAM_SIZE			0x3FF
#define MEMORY_RAM_OFFSET		0x2000
#define MEMORY_VRAM_SIZE		0x1BFF
#define MEMORY_VRAM_OFFSET		0x2400

void
memory_load_program(const uint8_t* program, const uint16_t size);

uint8_t
memory_read(const uint16_t location);

void
memory_write(const uint16_t location, const uint8_t word);
