#include <instructions.h>

#include <stdint.h>

#include <memory.h>
#include <register.h>

#define MAKE_RP(low, high) ((high << 8) | low)

void
mov_r(uint8_t r1, uint8_t r2)
{
	register_set_r(r1, register_get_r(r2));
}

void
mov_from_m(uint8_t r)
{
	register_set_r(r, memory_read(register_get_rp(REG_HL)));
}

void
mov_to_m(uint8_t r)
{
	memory_write(register_get_rp(REG_HL), register_get_r(r));
}

void
mvi(uint8_t r, uint8_t data)
{
	register_set_r(r, data);
}

void
mvi_m(uint8_t data)
{
	memory_write(register_get_rp(REG_HL), data);
}

void
lxi(uint8_t rp, uint8_t low, uint8_t high)
{
	register_set_rp(REG_HL, MAKE_RP(low, high));
}

void
lda(uint8_t low, uint8_t high)
{
	register_set_r(REG_A, memory_read(MAKE_RP(low, high)));
}

void
sta(uint8_t low, uint8_t high)
{
	memory_write(MAKE_RP(low, high), register_get_r(REG_A));
}

void
lhdl(uint8_t low, uint8_t high)
{
	register_set_r(REG_L, memory_read(register_get_rp(MAKE_RP(low, high))));
	register_set_r(REG_H, memory_read(register_get_rp(MAKE_RP(low, high) + 1)));
}

void
shld(uint8_t low, uint8_t high)
{
	memory_write(MAKE_RP(low, high), register_get_r(REG_L));
	memory_write(MAKE_RP(low, high) + 1, register_get_r(REG_H));
}

void
ldax(uint8_t rp)
{
	register_set_r(REG_A, memory_read(register_get_rp(rp)));
}

void
stax(uint8_t rp)
{
	memory_write(register_get_rp(rp), register_get_r(REG_A));
}

void
xchg(void)
{
	uint16_t tmp;

	tmp = register_get_rp(REG_HL);
	register_set_rp(REG_HL, register_get_rp(REG_DE));
	register_set_rp(REG_DE, tmp);
}

/*
 * Although instruction declarations may exist below, this marker designates
 * that the above functions are either in development or tested and approved.
 * Functions declared below are mearly there because I went ahead and created
 * them as well as created a rough implementation of their respective
 * instructions.
 * 
 * Typically the development of these functions progress in the order they
 * appear in as well as the pages (i.e. instructions at page 4-5 in the order
 * shown) they are found in the Intel 8080 Mircocomputer Systems User's Manual.
 */

#if 0

void
add_m(void)
{
}

void
add_r(uint8_t r)
{
}

void
add_i(uint8_t data)
{
}

void
add_rp(uint8_t rp)
{
}

void
add_carry_m(void)
{
}

void
add_carry_r(uint8_t r)
{
}

void
add_carry_i(uint8_t data)
{
}

void
sub_m(void)
{
}

void
sub_r(uint8_t r)
{
}

void
sub_i(uint8_t data)
{
}

void
sub_m_b(void)
{
}

void
sub_r_b(uint8_t r)
{
}

void
sub_i_b(uint8_t data)
{
}

void
increment_m(void)
{
}

void
increment_r(uint8_t r)
{
}

void
increment_rp(uint8_t rp)
{
}

void
decrement_m(void)
{
}

void
decrement_r(uint8_t r)
{
}

void
decrement_rp(uint8_t rp)
{
}

void
decimal_adjust_a(void)
{
}
#endif
