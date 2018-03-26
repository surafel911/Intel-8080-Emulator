#pragma once

#include <stdint.h>

#define MEM_ROM_OFFSET		0x40
#define MEM_RAM_SIZE		0x3FF
#define MEM_RAM_OFFSET		0x2000
#define MEM_VRAM_SIZE		0x1BFF
#define MEM_VRAM_OFFSET		0x2400

void
memory_load_program(const uint8_t* program, const uint16_t size);

uint8_t
memory_read(const uint16_t location);

void
memory_write(const uint16_t location, const uint8_t word);
