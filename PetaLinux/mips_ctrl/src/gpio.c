/******************************************************************************
* File:             gpio.c
*
* Author:           Hyunwoo Oh  
* Created:          02/24/22 
* Description:      GPIO Driver Source
*****************************************************************************/

#include "gpio.h"
#include "gpio_defs.h"


PMAObj pma_gpio;
GPIOObj GPIO[4];
GPIOObj* cur_gpio;
uint8_t gpio_bank;

uint8_t gpio_init() {
    uint8_t i;
    uint32_t temp;
    /*** Mapping physical base address to virtual address ***/
    debug_puts("    GPIO_PMA_INIT");
    if (pma_init() == PMA_OPEN_MEMDEV_FAIL) {
        return GPIO_PMA_INIT_FAIL;
    }
    if (pma_map(&pma_gpio, GPIO_BASE_ADDR, 0x300) 
            == PMA_VADDR_MAPPING_FAIL ) {
        debug_puts("GPIO_PMA_DEINIT");
        pma_deinit();
        return GPIO_PMA_MAP_FAIL;
    }

    for (i = 0; i < 4; i++) {
        cur_gpio = &GPIO[i];
        /*** Mapping addresses for each components ***/
        debug_printf("Initializing GPIO bank address %d\n", i);

        // MASK_DATA_LSW
        temp = (uint32_t)pma_gpio.virt_addr + MASK_DATA_LSW(i);
        debug_printf("    GPIO[%d]->MASK_DATA_LSW = BASE_ADDR + MASK_DATA_LSW(%d)   = 0x%08X\n", i, i, temp);
        cur_gpio->MASK_DATA_LSW = (uint32_t*)temp;
        debug_printf("0x%08X\n", *(cur_gpio->MASK_DATA_LSW));
        
        // MASK_DATA_MSW
        temp = (uint32_t)pma_gpio.virt_addr + MASK_DATA_MSW(i);
        debug_printf("    GPIO[%d]->MASK_DATA_MSW = BASE_ADDR + MASK_DATA_MSW(%d)   = 0x%08X\n", i, i, temp);
        cur_gpio->MASK_DATA_MSW = (uint32_t*)temp;
        debug_printf("0x%08X\n", *(cur_gpio->MASK_DATA_MSW));

        // DATA
        temp = (uint32_t)pma_gpio.virt_addr + DATA(i);
        debug_printf("    GPIO[%d]->DATA    =       BASE_ADDR + DATA(%d)            = 0x%08X\n", i, i, temp);
        cur_gpio->DATA = (uint32_t*)temp;
        debug_printf("0x%08X\n", *(cur_gpio->DATA));
        
        // DATA_RO
        temp = (uint32_t)pma_gpio.virt_addr + DATA_RO(i);
        debug_printf("    GPIO[%d]->DATA_RO =       BASE_ADDR + DATA_RO(%d)         = 0x%08X\n", i, i, temp);
        cur_gpio->DATA_RO = (uint32_t*)temp;
        debug_printf("0x%08X\n", *(cur_gpio->DATA_RO));

        // DIRM
        temp = (uint32_t)pma_gpio.virt_addr + DIRM(i);
        debug_printf("    GPIO[%d]->DIRM    =       BASE_ADDR + DIRM(%d)            = 0x%08X\n", i, i, temp);
        cur_gpio->DIRM = (uint32_t*)temp;
        debug_printf("0x%08X\n", *(cur_gpio->DIRM));

        // OEN
        temp = (uint32_t)pma_gpio.virt_addr + OEN(i);
        debug_printf("    GPIO[%d]->OEN     =       BASE_ADDR + OEN(%d)             = 0x%08X\n", i, i, temp);
        cur_gpio->OEN = (uint32_t*)temp;
        debug_printf("0x%08X\n", *(cur_gpio->OEN));
    }
    return GPIO_SUCCESS;
    
}

uint8_t gpio_deinit() {
    if (pma_unmap(&pma_gpio)) {
        debug_puts("    GPIO_PMA_DEINIT");
        pma_deinit();
        return GPIO_PMA_UNMAP_FAIL;
    }
    debug_puts("    GPIO_PMA_DEINIT");
    return pma_deinit();
}

uint8_t gpio_getcurbank() {
    return gpio_bank;
}

void gpio_setcurbank(uint8_t bank) {
    debug_printf("Set current GPIO bank to %d\n", bank);
    gpio_bank = bank;
    cur_gpio = &GPIO[bank];
}

uint32_t gpio_getconfig(){
    return *(cur_gpio->DIRM);
}

void gpio_setconfig(uint32_t iotypemask) {
    /*** Configure GPIO (Only Input / Output can be configurable) ***/
    debug_printf("Configuring GPIO bank %d\n", gpio_bank);
    debug_printf("    Write IO configuration on DIRM_%d and OEN_%d\n", gpio_bank, gpio_bank);
    // Write to DIRM
    debug_printf("    *GPIO[%d]->DIRM = 0x%08X\n", gpio_bank, iotypemask);
    *(cur_gpio->DIRM) = iotypemask;
    // Write to OEN
    debug_printf("    *GPIO[%d]->OEN  = 0x%08X\n", gpio_bank, iotypemask);
    *(cur_gpio->OEN)  = iotypemask;
}

void gpio_write(uint32_t value) {
    *(cur_gpio->DATA) = value;
}

uint32_t gpio_read() {
    return *(cur_gpio->DATA_RO);
}

void gpio_writemask_lsw(uint32_t value) {
    *(cur_gpio->MASK_DATA_LSW) = value;
}

void gpio_writemask_lsw(uint16_t mask, uint16_t value) {
    *(cur_gpio->MASK_DATA_LSW) = (mask << 16) | value;
}

void gpio_writemask_msw(uint32_t value) {
    *(cur_gpio->MASK_DATA_MSW) = value;
}

void gpio_writemask_msw(uint16_t mask, uint16_t value) {
    *(cur_gpio->MASK_DATA_MSW) = (mask << 16) | value;
}



