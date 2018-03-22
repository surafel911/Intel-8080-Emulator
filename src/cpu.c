#include <cpu.h>

#include <limits.h>
#include <stdio.h>
#include <stdint.h>

#include <error.h>
#include <instructions.h>
#include <memory.h>
#include <register.h>

#define SR_CARRY		0x1
#define SR_AUX_CARRY	0x2
#define SR_SIGN			0x4
#define SR_ZERO			0x8
#define SR_PARITY		0x16
#define SR_RUN			0x32

static inline void
cpu_execute(void)
{
#if 0
	static uint8_t opcode, operand;

	opcode = memory_read(_cpu.pc++);
	switch (opcode) {
		case NOP:
		break;
		case ADD:
			operand = memory_read(_cpu.pc);
			operand++;
		break;
		case MOV:
		break;
		default:
			error("Error: Invalid opcode read.");
		break;
	}
#else
	printf("Running\n");
#endif
}


void
cpu_run(const uint8_t* program, const uint16_t size)
{
	register_set_sr(SR_RUN);
	register_set_rp(REG_SP, USHRT_MAX - 1);
	memory_load_program(program, size);

	do {
		cpu_execute();
	} while (register_get_sr() & SR_RUN);
}

