#ifndef _SLCR_H_
#define _SLCR_H_


#include <stdint.h>
#include "pma.h"
#include "debug.h"

#define SLCR_SUCCESS        0
#define SLCR_PMA_INIT_FAIL  1
#define SLCR_PMA_MAP_FAIL   2
#define SLCR_PMA_UNMAP_FAIL 3

uint8_t slcr_unlock();
uint8_t slcr_lock();
uint8_t slcr_get_lock_status(uint32_t *ret_ptr);
uint8_t slcr_fpga_reset(uint8_t value);
#endif
