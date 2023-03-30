/******************************************************************************
* File:             mpjtag.c
*
* Author:           Hyunwoo Oh  
* Created:          02/28/22 
* Description:      MIPS_posit System JTAG control code
*****************************************************************************/
/* JTAG Map 
 * ram_rd[31:0]
 * ram_wd[31:0]
 * ram_addr[31:0]
 * ram_we[0:3]
 * hreset_n
 * Total: 101
*/

#include "mips_posit/mpjtag.h"

struct timespec jtag_delay = {0, 20};
volatile int dly;

//#define JTAG_DELAY()  nanosleep(&jtag_delay, NULL)
/*#define JTAG_DELAY()  \
    __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm ("nop"); \
    __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm ("nop"); \
    __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm ("nop"); \
    __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm ("nop"); \
    __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm ("nop"); \
    __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm ("nop"); \
    __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm ("nop"); \
    __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm ("nop"); \
    __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm ("nop"); \
    __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm ("nop"); \
    __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm ("nop"); \
    __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm ("nop"); \
    __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm__ ("nop"); __asm ("nop")
    */
#define JTAG_DELAY()    for (dly = 0; dly < 26; ++dly)
#define RESULT mpjtag_result

#define GPIO_BANK   GPIO_BANK_2

#define TCK_MASK    0x00000008
#define TMS_MASK    0x00000004
#define TDI_MASK    0x00000002
#define TDO_MASK    0x00000001

#define MASK_DATA   *(cur_gpio->MASK_DATA_LSW)
#define DATA        *(cur_gpio->DATA)
#define DATA_RO     *(cur_gpio->DATA_RO)

#define DATA_MASK   ~(TCK_MASK | TMS_MASK | TDI_MASK)

extern GPIOObj* cur_gpio;

#define GPIO_WRITE_MASK(value)  MASK_DATA = ((DATA_MASK << 16) | (value))
#define GPIO_WRITE(value)       DATA = value

#define JTAG_WRITE_TCK(tck) \
    MASK_DATA = (((~TCK_MASK) << 16) | (tck << 3)); \
    JTAG_DELAY()
    
#define JTAG_WRITE(tms, tdi) \
    GPIO_WRITE_MASK(/*(0 << 3) |*/ (tms << 2) | (tdi << 1)); \
    JTAG_DELAY(); \
    JTAG_WRITE_TCK(1); \
    JTAG_DELAY()

#define DEBUG_PRINT(TMS_STR, TDI_STR) \
    debug_printf("        TMS: %s\n", TMS_STR); \
    debug_printf("        TDI: %s\n", TDI_STR)

// JTAG change state to SHIFTDR
// 00
// xx
#define JTAG_STATE_TO_SHIFTDR() \
    DEBUG_PRINT("00", "xx"); \
    JTAG_WRITE(0, 0); \
    JTAG_WRITE(0, 0)

// JTAG go back to DR state from Exit1DR
// 11
// xx
#define JTAG_STATE_TO_DR() \
    DEBUG_PRINT("11", "xx"); \
    JTAG_WRITE(1, 0); \
    JTAG_WRITE(1, 0)

uint32_t mpjtag_result;

uint8_t mpjtag_init_system() {
    debug_printf("    MPJTAG system initialize...");
    RESULT = gpio_init();
    if (RESULT) {
        debug_puts("failed");
        return MPJTAG_FAIL;
    }
    else
        debug_puts("success");
    gpio_setcurbank(GPIO_BANK);
    GPIO_WRITE_MASK(0xE);   JTAG_DELAY();
    return MPJTAG_SUCCESS;
}

uint8_t mpjtag_deinit_system() {
    debug_printf("    MPJTAG system deinitialize...");
    RESULT = gpio_deinit();
    if (RESULT) {
        debug_puts("failed");
        return MPJTAG_FAIL;
    }
    else
        debug_puts("success");

    return MPJTAG_SUCCESS;
}

void mpjtag_reset() {
    // Reset TAP Ctrl
    // 11111 01
    // xxxxx xx
    debug_puts("    MPJTAG Reset TAP Controller");
    DEBUG_PRINT("11111 01", "xxxxx xx");

    JTAG_WRITE(1,0);
    JTAG_WRITE(1,0);
    JTAG_WRITE(1,0);
    JTAG_WRITE(1,0);
    JTAG_WRITE(1,0);

    JTAG_WRITE(0,0);
    JTAG_WRITE(1,0);
}

void mpjtag_instr_preload() {
    // Set JTAG Instruction to SAMPLE/PRELOAD
    // 10 01 11
    // xx 01 xx
    debug_puts("    MPJTAG Change JTAG instruction to SAMPLE/PRELOAD");
    DEBUG_PRINT("10 01 11", "xx 01 xx");

    JTAG_WRITE(1,0);
    JTAG_WRITE(0,0);

    JTAG_WRITE(0,0);
    JTAG_WRITE(1,1);

    JTAG_WRITE(1,0);
    JTAG_WRITE(1,0);
}

void mpjtag_instr_extest() {
    // Set JTAG Instruction to EXTEST
    // 10 01 11
    // xx 00 xx
    debug_puts("    MPJTAG Change JTAG instruction to EXTEST");
    DEBUG_PRINT("10 01 11", "xx 00 xx");

    JTAG_WRITE(1,0);
    JTAG_WRITE(0,0);

    JTAG_WRITE(0,0);
    JTAG_WRITE(1,0);

    JTAG_WRITE(1,0);
    JTAG_WRITE(1,0);
}

void mpjtag_instr_bypass() {
    // Set JTAG Instruction to BYPASS
    // 10 01 11
    // xx 11 xx
    debug_puts("    MPJTAG Change JTAG instruction to BYPASS");
    DEBUG_PRINT("10 01 11", "xx 11 xx");
    
    JTAG_WRITE(1,0);
    JTAG_WRITE(0,0);

    JTAG_WRITE(0,1);
    JTAG_WRITE(1,1);

    JTAG_WRITE(1,0);
    JTAG_WRITE(1,0);
}
void mpjtag_proc_stop() {
    debug_puts("    MPJTAG turning off mips processor");
    // SHIFTDR -> Write -> DR
    // 00001
    // 00000

    JTAG_STATE_TO_SHIFTDR();

    DEBUG_PRINT("00001", "00000");

    JTAG_WRITE(0,0);
    JTAG_WRITE(0,0);
    JTAG_WRITE(0,0);
    JTAG_WRITE(0,0);
    JTAG_WRITE(1,0);

    JTAG_STATE_TO_DR();
}

void mpjtag_ram_write(uint32_t addr, uint32_t data) {
    debug_puts("    MPJTAG writing data to ram");
    debug_printf("        Address:  %08X\n", addr);
    debug_printf("        Data:     %08X\n", data);
    // SHIFTDR -> Write -> DR
    //             Address                            Data               we[3:0], iscached, hreset_n
    // 00000000000000000000000000000000 00000000000000000000000000000000 000001
    //            addr[31:0]                        data[31:0]           111110
    JTAG_STATE_TO_SHIFTDR();

    JTAG_WRITE(0, (data & 0x80000000) >> 31);
    JTAG_WRITE(0, (data & 0x40000000) >> 30);
    JTAG_WRITE(0, (data & 0x20000000) >> 29);
    JTAG_WRITE(0, (data & 0x10000000) >> 28);
    JTAG_WRITE(0, (data & 0x08000000) >> 27);
    JTAG_WRITE(0, (data & 0x04000000) >> 26);
    JTAG_WRITE(0, (data & 0x02000000) >> 25);
    JTAG_WRITE(0, (data & 0x01000000) >> 24);
    JTAG_WRITE(0, (data & 0x00800000) >> 23);
    JTAG_WRITE(0, (data & 0x00400000) >> 22);
    JTAG_WRITE(0, (data & 0x00200000) >> 21);
    JTAG_WRITE(0, (data & 0x00100000) >> 20);
    JTAG_WRITE(0, (data & 0x00080000) >> 19);
    JTAG_WRITE(0, (data & 0x00040000) >> 18);
    JTAG_WRITE(0, (data & 0x00020000) >> 17);
    JTAG_WRITE(0, (data & 0x00010000) >> 16);
    JTAG_WRITE(0, (data & 0x00008000) >> 15);
    JTAG_WRITE(0, (data & 0x00004000) >> 14);
    JTAG_WRITE(0, (data & 0x00002000) >> 13);
    JTAG_WRITE(0, (data & 0x00001000) >> 12);
    JTAG_WRITE(0, (data & 0x00000800) >> 11);
    JTAG_WRITE(0, (data & 0x00000400) >> 10);
    JTAG_WRITE(0, (data & 0x00000200) >>  9);
    JTAG_WRITE(0, (data & 0x00000100) >>  8);
    JTAG_WRITE(0, (data & 0x00000080) >>  7);
    JTAG_WRITE(0, (data & 0x00000040) >>  6);
    JTAG_WRITE(0, (data & 0x00000020) >>  5);
    JTAG_WRITE(0, (data & 0x00000010) >>  4);
    JTAG_WRITE(0, (data & 0x00000008) >>  3);
    JTAG_WRITE(0, (data & 0x00000004) >>  2);
    JTAG_WRITE(0, (data & 0x00000002) >>  1);
    JTAG_WRITE(0, (data & 0x00000001) >>  0);

    JTAG_WRITE(0, (addr & 0x80000000) >> 31);
    JTAG_WRITE(0, (addr & 0x40000000) >> 30);
    JTAG_WRITE(0, (addr & 0x20000000) >> 29);
    JTAG_WRITE(0, (addr & 0x10000000) >> 28);
    JTAG_WRITE(0, (addr & 0x08000000) >> 27);
    JTAG_WRITE(0, (addr & 0x04000000) >> 26);
    JTAG_WRITE(0, (addr & 0x02000000) >> 25);
    JTAG_WRITE(0, (addr & 0x01000000) >> 24);
    JTAG_WRITE(0, (addr & 0x00800000) >> 23);
    JTAG_WRITE(0, (addr & 0x00400000) >> 22);
    JTAG_WRITE(0, (addr & 0x00200000) >> 21);
    JTAG_WRITE(0, (addr & 0x00100000) >> 20);
    JTAG_WRITE(0, (addr & 0x00080000) >> 19);
    JTAG_WRITE(0, (addr & 0x00040000) >> 18);
    JTAG_WRITE(0, (addr & 0x00020000) >> 17);
    JTAG_WRITE(0, (addr & 0x00010000) >> 16);
    JTAG_WRITE(0, (addr & 0x00008000) >> 15);
    JTAG_WRITE(0, (addr & 0x00004000) >> 14);
    JTAG_WRITE(0, (addr & 0x00002000) >> 13);
    JTAG_WRITE(0, (addr & 0x00001000) >> 12);
    JTAG_WRITE(0, (addr & 0x00000800) >> 11);
    JTAG_WRITE(0, (addr & 0x00000400) >> 10);
    JTAG_WRITE(0, (addr & 0x00000200) >>  9);
    JTAG_WRITE(0, (addr & 0x00000100) >>  8);
    JTAG_WRITE(0, (addr & 0x00000080) >>  7);
    JTAG_WRITE(0, (addr & 0x00000040) >>  6);
    JTAG_WRITE(0, (addr & 0x00000020) >>  5);
    JTAG_WRITE(0, (addr & 0x00000010) >>  4);
    JTAG_WRITE(0, (addr & 0x00000008) >>  3);
    JTAG_WRITE(0, (addr & 0x00000004) >>  2);
    JTAG_WRITE(0, (addr & 0x00000002) >>  1);
    JTAG_WRITE(0, (addr & 0x00000001) >>  0);

    JTAG_WRITE(0,1);
    JTAG_WRITE(0,1);
    JTAG_WRITE(0,1);
    JTAG_WRITE(0,1);
    JTAG_WRITE(0,1);
    JTAG_WRITE(1,0);

    JTAG_STATE_TO_DR();
}


#undef RESULT
