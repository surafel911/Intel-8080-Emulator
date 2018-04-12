#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <emulator.h>

static struct {
	FILE* file;
	uint16_t size;
} binary[4];

static struct {
	uint8_t* code;
	uint16_t size;
} program;

int
main(int argc, char* argv[])
{
	uint8_t index;
	uint16_t offset;

	if (argc == 1) {
		error("Error: No binary file(s) provided.");
	}

//	TODO: The binary file isn't being read correctly.
	for (index = 0; index < argc - 1; index ++) {
		binary[index].file = fopen(argv[index + 1], "rb");
		if (binary[index].file == NULL) {
			error("Error: Failed to load binary file \'%s\'.", argv[index + 1]);
		}

		fseek(binary[index].file, 0, SEEK_END);
		binary[index].size = ftell(binary[index].file);
		program.size += binary[index].size;
		fseek(binary[index].file, 0, SEEK_SET);
	}

	offset = 0;
	program.code = malloc(sizeof(*program.code) * program.size);
	for (index = 0; index < argc - 1; index ++) {
		fread(
			(void*)program.code + offset,
			sizeof(*program.code),
			binary[index].size,
			binary[index].file
			);

		offset += binary[index].size;
	}

	for (index = 0; index < argc - 1; index ++) {
		fclose(binary[index].file);
	}

	printf("%d", sizeof(uint8_t*));

//	emulator_run((const uint8_t*)program.code, (const uint16_t)program.size);
}
