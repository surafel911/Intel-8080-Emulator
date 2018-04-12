#include <cpu.h>

#include <limits.h>
#include <stdio.h>
#include <stdint.h>

#include <error.h>
#include <instructions.h>
#include <memory.h>
#include <register.h>

void
cpu_execute(void)
{
	static uint8_t opcode;

	opcode = memory_read(register_get_rp(REG_PC));

#if 0
	switch (opcode) {
		/* NOP */
		case 0x00:
		case 0x10:
		case 0x20:
		case 0x30:
		case 0x08:
		case 0x18:
		case 0x28:
		case 0x38:
		break;
		/* STAX */
		case 0x02:
			stax(REG_BC);
		break;
		case 0x12:
			stax(REG_DE);
		break;
		/* SHLD */
		case 0x22:
		break;
		/* STA */
		case 0x32:
		break;
		/* INR */
		case 0x04:
		case 0x14:
		case 0x24:
		case 0x34:
		case 0x0C:
		case 0x1C:
		case 0x2C:
		case 0x3C:
		break;
		/* DCR */
		case 0x05:
		case 0x15:
		case 0x25:
		case 0x35:
		case 0x0D:
		case 0x1D:
		case 0x2D:
		case 0x3D:
		break;
		/* MVI */
		case 0x06:
		case 0x16:
		case 0x26:
		case 0x36:
		case 0x0E:
		case 0x1E:
		case 0x2E:
		case 0x3E:
		break;
		/* RLC */
		case 0x07:
		break;
		/* RAL */
		case 0x17:
		break;
		/* DAA */
		case 0x27:
		break;
		/* STC */
		case 0x37:
		break;
		/* DAD */
		case 0x09:
		case 0x19:
		case 0x29:
		case 0x39:
		break;
		/* LDAX */
		case 0x0A:
			ldax(REG_BC);
		break;
		case 0x1A:
			ldax(REG_DE);
		break;
		/* LHLD */
		case 0x2A:
		break;
		/* LDA */
		case 0x3A:
		break;
		/* DCX */
		case 0x0B:
		case 0x1B:
		case 0x2B:
		case 0x3B:
		break;
		/* RRC */
		case 0x0F:
		break;
		/* RAR */
		case 0x1F:
		break;
		/* CMA */
		case 0x2F:
		break;
		/* CMC */
		case 0x3F:
		break;

		/* MOV */
		case 0x40:
		case 0x50:
		case 0x60:
		case 0x70:
		case 0x41:
		case 0x51:
		case 0x61:
		case 0x71:
		case 0x42:
		case 0x52:
		case 0x62:
		case 0x72:
		case 0x43:
		case 0x53:
		case 0x63:
		case 0x73:
		case 0x44:
		case 0x54:
		case 0x64:
		case 0x74:
		case 0x45:
		case 0x55:
		case 0x65:
		case 0x75:
		case 0x46:
		case 0x56:
		case 0x66:
		break;
		/* HLT */
		case 0x76:
		break;
		/* LXI */
		case 0x01:
		case 0x11:
		case 0x21:
		case 0x31:
		break;
		
		default:
			error("Error: Invalid opcode read \'%d\'.", opcode);
		break;
	}
#else
	printf("%X\n", opcode);
#endif
}


void
cpu_run(const uint8_t* program, const uint16_t size)
{

	do {
		cpu_execute();
	} while (register_get_r(REG_SR) & SREG_RUN);
}

