#include <register.h>

#include <stdint.h>

#include <error.h>

static struct {
	uint16_t pc, sp;

	union {
		uint8_t sr, a;
		uint16_t psw;
	};

	union {
		uint8_t b, c;
		uint16_t bc;
	};

	union {
		uint8_t d, e;
		uint16_t de;
	};

	union {
		uint8_t h, l;
		uint16_t hl;
	};

} _registers;

uint8_t
register_get_r(uint8_t symbol)
{
	static uint8_t value;
	switch (symbol) {
		case REG_A:
			value = _registers.a;
		break;
		case REG_B:
			value = _registers.b;
		break;
		case REG_C:
			value = _registers.c;
		break;
		case REG_D:
			value = _registers.d;
		break;
		case REG_E:
			value = _registers.e;
		break;
		case REG_H:
			value = _registers.h;
		break;
		case REG_L:
			value = _registers.l;
		break;
		case REG_SR:
			value = _registers.sr;
		break;
		default:
			error("Error: Invalid register symbol provided.");
		break;
	}

	return value;
}

void
register_set_r(uint8_t symbol, uint8_t data)
{
	switch (symbol) {
		case REG_A:
			_registers.a = data;
		break;
		case REG_B:
			_registers.b = data;
		break;
		case REG_C:
			_registers.c = data;
		break;
		case REG_D:
			_registers.d = data;
		break;
		case REG_E:
			_registers.e = data;
		break;
		case REG_H:
			_registers.h = data;
		break;
		case REG_L:
			_registers.l = data;
		break;
		case REG_SR:
			_registers.sr ^= data;
		break;
		default:
			error("Error: Invalid register symbol provided.");
		break;
	}

}

uint16_t
register_get_rp(uint8_t symbol)
{
	static uint16_t value;
	switch (symbol) {
		case REG_BC:
			value = _registers.bc;
		break;
		case REG_DE:
			value = _registers.de;
		break;
		case REG_HL:
			value = _registers.hl;
		break;
		case REG_SP:
			value = _registers.sp;
		break;
		case REG_PC:
			value = _registers.pc;
		break;
		default:
			error("Error: Invalid register pair symbol provided.");
		break;
	}

	return value;
}

void
register_set_rp(uint8_t symbol, uint16_t data)
{
	switch (symbol) {
		case REG_BC:
			_registers.bc = data;
		break;
		case REG_DE:
			_registers.de = data;
		break;
		case REG_HL:
			_registers.hl = data;
		break;
		case REG_SP:
			_registers.sp = data;
		break;
		case REG_PC:
			_registers.pc = data;
		break;
		default:
			error("Error: Invalid register pair symbol provided.");
		break;
	}
}

