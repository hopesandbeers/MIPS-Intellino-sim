/******************************************************************************
* File:             gpio.h
*
* Author:           Hyunwoo Oh  
* Created:          02/24/22 
* Description:      GPIO Driver Header
*****************************************************************************/

#ifndef _GPIO_H_
#define _GPIO_H_

#include "pma.h"
#include "debug.h"


#define GPIO_IOTYPE_INPUT   0
#define GPIO_IOTYPE_OUTPUT  1

#define GPIO_JTAG_BANK      1

#define GPIO_BANK_0         0
#define GPIO_BANK_1         1
#define GPIO_BANK_2         2
#define GPIO_BANK_3         3

#define GPIO_SUCCESS        0
#define GPIO_PMA_INIT_FAIL  1
#define GPIO_PMA_MAP_FAIL   2
#define GPIO_PMA_UNMAP_FAIL 3

typedef struct stGPIO {
    uint32_t* MASK_DATA_LSW;
    uint32_t* MASK_DATA_MSW;
    uint32_t* DATA;
    uint32_t* DATA_RO;
    uint32_t* DIRM;
    uint32_t* OEN;
} GPIOObj;

uint8_t     gpio_init();
uint8_t     gpio_deinit();
uint8_t     gpio_getcurbank();
void        gpio_setcurbank(uint8_t bank);
uint32_t    gpio_getconfig();
void        gpio_setconfig(uint32_t iotypemask);
void        gpio_write(uint32_t value);
void gpio_writemask_lsw(uint32_t value);
void gpio_writemask_lsw(uint16_t mask, uint16_t value);
void gpio_writemask_msw(uint32_t value);
void gpio_writemask_msw(uint16_t mask, uint16_t value);
uint32_t    gpio_read();

#endif
