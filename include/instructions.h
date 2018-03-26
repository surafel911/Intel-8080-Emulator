#pragma once

#include <stdint.h>

/*
 * Functions will usually have the same name as they appear in the instruction
 * set, but if there are multiple variants of an instruction such as indrect
 * or direct addressing, going from or too memory, etc. In which case the
 * the instruction name will be coupled with attributes listed above along
 * with a word or two.
 */

/*
 * Instruction function attributes:
 * r	- register
 * m 	- memory
 */

void
mov_r(uint8_t r1, uint8_t r2);

void
mov_from_m(uint8_t r);

void
mov_to_m(uint8_t r);

void
mvi(uint8_t r, uint8_t data);

void
mvi_m(uint8_t data);

void
lxi(uint8_t rp, uint8_t low, uint8_t high);

void
lda(uint8_t low, uint8_t high);

void
sta(uint8_t low, uint8_t high);

void
lhdl(uint8_t low, uint8_t high);

void
shld(uint8_t low, uint8_t high);

void
ldax(uint8_t rp);

void
stax(uint8_t rp);

void
xchg(void);

/*
 * Although instruction implentations may exist below, this marker designates
 * that the above functions are either in development or tested and approved.
 * Functions defined below are mearly there because I went ahead and created
 * them as well as created a rough implementation of their respective
 * instructions.
 * 
 * Typically the development of these functions progress in the order they
 * appear in as well as the pages (i.e. instructions at page 4-5 in the order
 * shown) they are found in the Intel 8080 Mircocomputer Systems User's Manual.
 */

#if 0

void
add_m(void);

void
add_r(uint8_t r);

void
add_i(uint8_t data);

void
add_rp(uint8_t rp);

void
add_carry_m(void);

void
add_carry_r(uint8_t r);

void
add_carry_i(uint8_t data);

void
sub_m(void);

void
sub_r(uint8_t r);

void
sub_i(uint8_t data);

void
sub_m_b(void);

void
sub_r_b(uint8_t r);

void
sub_i_b(uint8_t data);

void
increment_m(void);

void
increment_r(uint8_t r);

void
increment_rp(uint8_t rp);

void
decrement_m(void);

void
decrement_r(uint8_t r);

void
decrement_rp(uint8_t rp);

void
decimal_adjust_a(void);

#endif
