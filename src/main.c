#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <cpu.h>
#include <error.h>

int
main(int argc, char* argv[])
{
	FILE* binary;
	uint8_t* program;
	uint16_t size;	

	if (argc == 1) {
		error("Error: No binary file provided.");
	}

	binary = fopen(argv[argc - 1], "r");
	if (binary == NULL) {
		error("Error: Failed to load binary file.");
	}

	fseek(binary, 0, SEEK_END);
	size = ftell(binary);
	fseek(binary, 0, SEEK_SET);

	program = malloc(sizeof(*program) * ftell(binary));
	fread((void*)program, sizeof(*program), size, binary);
	fclose(binary);

	cpu_run((const uint8_t*)program, (const uint16_t)size);
}
