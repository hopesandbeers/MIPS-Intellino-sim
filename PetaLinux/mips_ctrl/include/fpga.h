#ifndef _FPGA_H_
#define _FPGA_H_

#include "slcr.h"
#include "debug.h"

#define FPGA_RESET_MODE_HIGH    0x00000000
#define FPGA_RESET_MODE_LOW     0x00000001

uint8_t fpga_init();
uint8_t fpga_reset(uint8_t mode);

#endif
