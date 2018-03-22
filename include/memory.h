#pragma once

#include <stdint.h>

void
memory_load_program(const uint8_t* program, const uint16_t size);

uint8_t
memory_read(const uint16_t location);

void
memory_write(const uint16_t location, const uint8_t word);
