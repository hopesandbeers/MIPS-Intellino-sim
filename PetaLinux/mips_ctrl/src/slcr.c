
#include "slcr.h"

#define SLCR_LCK_MGC_NO     0x767B
#define SLCR_UNLCK_MGC_NO   0xDF0D

#define SCLR_BASE_ADDR      0xF8000000

#define WB_SCL              0x00
#define WP_LOCK             0x04
#define WP_UNLOCK           0x08
#define WP_LOCKSTA          0x0C

#define PS_RST_CTRL         0x200
#define FPGA_RST_CTRL       0x204
#define A9_CPU_SW_RST_CTRL  0x248
#define REBOOT_STATUS       0x258

#define SLCR_PMA_INIT()                                 \
    if (pma_init() == PMA_OPEN_MEMDEV_FAIL) {           \
        return SLCR_PMA_INIT_FAIL;                      \
    }

#define SLCR_PMA_MAP(pmaobj, OFFSET)                    \
    if (pma_map(&pmaobj, SCLR_BASE_ADDR + OFFSET, 4)    \
            == PMA_VADDR_MAPPING_FAIL) {                \
        debug_puts("SLCR_PMA_DEINIT");                  \
        pma_deinit();                                   \
        return SLCR_PMA_MAP_FAIL;                       \
    }

#define SLCR_PMA_UNMAP(pmaobj)                          \
    if (pma_unmap(&pmaobj)) {                           \
        debug_puts("SLCR_PMA_DEINIT");                  \
        pma_deinit();                                   \
        return SLCR_PMA_UNMAP_FAIL;                     \
    }

#define SLCR_READ(read_ptr, pmaobj, OFFSET)             \
    debug_puts("SLCR_PMA_INIT");                        \
    SLCR_PMA_INIT();                                    \
    debug_puts("SLCR_PMA_MAP");                         \
    SLCR_PMA_MAP(pmaobj, OFFSET);                       \
    debug_puts("SLCR_PMA_READ");                        \
    *read_ptr = pma_read(pmaobj);                       \
    debug_puts("SLCR_PMA_UNMAP");                       \
    SLCR_PMA_UNMAP(pmaobj);                             \
    debug_puts("SLCR_PMA_DEINIT");                      \
    pma_deinit();                                       \
    return SLCR_SUCCESS

#define SLCR_WRITE(pmaobj, OFFSET, value)               \
    debug_puts("SLCR_PMA_INIT");                        \
    SLCR_PMA_INIT();                                    \
    debug_puts("SLCR_PMA_MAP");                         \
    SLCR_PMA_MAP(pmaobj, OFFSET);                       \
    debug_puts("SLCR_PMA_WRITE");                       \
    pma_write(pmaobj, value);                           \
    debug_puts("SLCR_PMA_UNMAP");                       \
    SLCR_PMA_UNMAP(pmaobj);                             \
    debug_puts("SLCR_PMA_DEINIT");                      \
    pma_deinit();                                       \
    return SLCR_SUCCESS

uint8_t slcr_unlock() {
    PMAObj pma_wp_unlock;
    SLCR_WRITE(pma_wp_unlock, WP_UNLOCK, SLCR_UNLCK_MGC_NO);
}
uint8_t slcr_lock() {
    PMAObj pma_wp_lock;
    SLCR_WRITE(pma_wp_lock, WP_LOCK, SLCR_LCK_MGC_NO);
}
uint8_t slcr_get_lock_status(uint32_t *ret_ptr) {
    PMAObj pma_wp_locksta;
    SLCR_READ(ret_ptr, pma_wp_locksta, WP_LOCKSTA);
}
uint8_t slcr_fpga_reset(uint8_t value) {
    PMAObj pma_fpga_rst_ctrl;
    SLCR_WRITE(pma_fpga_rst_ctrl, FPGA_RST_CTRL, value);
}
