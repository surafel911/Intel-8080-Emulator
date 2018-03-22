#pragma once

#include <stdint.h>

/*
 * Opcode function attributes:
 * 
 * a	- accumulator
 * b	- borrow
 * d 	- direct
 * i 	- indirect
 * m 	- memory
 * r 	- register
 * rp	- register pair
 */

void
move_r(uint8_t r1, uint8_t r2);

void
move_i(uint8_t r, uint8_t data);

void
move_to_m(uint8_t r);

void
move_to_m_i(uint8_t data);

void
move_from_m(uint8_t r);

void
load_rp_i(uint8_t low, uint8_t high);

void
load_a_i(uint8_t low, uint8_t high);

void
load_a_d(uint8_t low, uint8_t high);

void
store_a_i(uint8_t low, uint8_t high);

void
store_a_d(uint8_t low, uint8_t high);

void
load_hl_d(uint8_t low, uint8_t high);

void
store_hl_d(uint8_t low, uint8_t high);

void
exchange_hl_de(void);

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
