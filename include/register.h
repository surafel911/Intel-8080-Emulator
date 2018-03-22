#pragma once

#include <stdint.h>

#define REG_A				0x7
#define REG_B				0x0
#define REG_C				0x1
#define REG_D				0x2
#define REG_E				0x3
#define REG_H				0x4
#define REG_L				0x5

#define REG_SR				0x6

#define REG_BC				0x0
#define REG_DE				0x1
#define REG_HL				0x2
#define REG_SP				0x3

#define REG_PC				0x4

#define SREG_CARRY			0x01
#define SREG_AUX_CARRY			0x02
#define SREG_SIGN			0x04
#define SREG_ZERO			0x08
#define SREG_PARITY			0x16
#define SREG_RUN			0x32

uint8_t
register_get_r(uint8_t symbol);

void
register_set_r(uint8_t symbol, uint8_t data);

uint16_t
register_get_rp(uint8_t symbol);

void
register_set_rp(uint8_t symbol, uint16_t data);
