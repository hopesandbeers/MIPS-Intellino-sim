#include "fpga.h"


#define FPGA_RST_STS    0x00

uint8_t fpga_init() {
    uint8_t result;
    debug_puts("    fpga_reset(FPGA_RESET_MODE_LOW)");
    result = fpga_reset(FPGA_RESET_MODE_LOW);
    if (result) {
        return result;
    }
    debug_puts("    sleep(1)");
    sleep(1);
    debug_puts("    fpga_reset(FPGA_RESET_MODE_HIGH)");
    result = fpga_reset(FPGA_RESET_MODE_HIGH);
    if (result) return result;
    return 0;
}

uint8_t fpga_reset(uint8_t mode) {
    uint8_t result;
    result = slcr_unlock();
    if (result) {
        debug_puts("Error on SLCR Unlock: ");
        if (result == SLCR_PMA_INIT_FAIL) debug_puts("    SLCR_PMA_INIT_FAIL");
        else if (result == SLCR_PMA_MAP_FAIL) debug_puts("    SLCR_PMA_MAP_FAIL");
        else if (result == SLCR_PMA_UNMAP_FAIL) debug_puts("    SLCR_PMA_UNMAP_FAIL");
        return result;
    }
    result = slcr_fpga_reset(mode);
    if (result){
        debug_puts("Error on accessing SLCR_FPGA_RST_CTRL: ");
        if (result == SLCR_PMA_INIT_FAIL) debug_puts("    SLCR_PMA_INIT_FAIL");
        else if (result == SLCR_PMA_MAP_FAIL) debug_puts("    SLCR_PMA_MAP_FAIL");
        else if (result == SLCR_PMA_UNMAP_FAIL) debug_puts("    SLCR_PMA_UNMAP_FAIL");
        return result;
    }
    result = slcr_lock();
    if (result) {
        debug_puts("Error on SLCR lock: ");
        if (result == SLCR_PMA_INIT_FAIL) debug_puts("    SLCR_PMA_INIT_FAIL");
        else if (result == SLCR_PMA_MAP_FAIL) debug_puts("    SLCR_PMA_MAP_FAIL");
        else if (result == SLCR_PMA_UNMAP_FAIL) debug_puts("    SLCR_PMA_UNMAP_FAIL");
        return result;
    }
    return 0;
}
