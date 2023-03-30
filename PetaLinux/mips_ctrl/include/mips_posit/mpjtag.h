#ifndef _MPJTAG_H_
#define _MPJTAG_H_

#include <time.h>
#include "gpio.h"
#include "debug.h"


#define MPJTAG_SUCCESS  0
#define MPJTAG_FAIL     1

uint8_t mpjtag_init_system();
uint8_t mpjtag_deinit_system();
void mpjtag_reset();
void mpjtag_instr_preload();
void mpjtag_instr_extest();
void mpjtag_instr_bypass();
void mpjtag_proc_stop();
void mpjtag_ram_write(uint32_t addr, uint32_t data);

#endif /* ifndef _MPJTAG_H_ */
