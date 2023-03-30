#ifndef _COUNTER_H
#define _COUNTER_H

#include <stdint.h>

#define CNT_REG     *(uint32_t*)0xA0000010

uint32_t cnt_clk();


#endif
