/******************************************************************************
* File:             main.c
*
* Author:           Hyunwoo Oh  
* Created:          03/01/22 
* Description:      MIPS posit control software
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gpio.h"

#include "mips_posit/mpjtag.h"

// GPIO2 (EMIO[31:0]) MASK
// GPIO2 Output: [31] reset_n [3] tck [2] tms [1] tdi
// GPIO2 Input:  [0] tdo
#define GPIO_BANK2_OUTPUT_MASK   0x8000000E
#define GPIO_BANK2_INPUT_MASK    0x00000001
// GPIO3 (EMIO[63:32]) MASK
// GPIO3 Output: [3] led3 [2] led2 [1] led1 [0] led[0]
// GPIO3 Input:  None
#define GPIO_BANK3_OUTPUT_MASK   0x0000000F
#define GPIO_BANK3_INPUT_MASK    0x00000000

int main() {
    uint32_t result;

    FILE* fp;
    uint32_t buf = 0;
    uint32_t i;
    uint32_t endaddr;
    uint8_t mips_onoff_status;
    uint8_t led_onoff_status;
    char *str_onoff[2] = {"OFF", "ON"};

    uint16_t size_urom, size_uram, size_kram;
    size_urom = size_uram = size_kram = 0;


    // Initialize GPIO 
    printf("GPIO initialize");
    result = gpio_init();
    if (result) {
        puts("failed");
        return -1;
    }
    else
        puts("success");

    // Set Current GPIO Bank to 2
    printf("GPIO set current bank to 2\n");
    gpio_setcurbank(2);

    // Configure current GPIO bank (2)
    printf("GPIO configure current bank (2)\n");
    gpio_setconfig(GPIO_BANK2_OUTPUT_MASK);

    // Write to current GPIO bank (2)
    printf("GPIO write data to current bank (2)\n");
    gpio_write(0x0000000E);

    sleep(1);

    // Write to current GPIO bank (2)
    printf("GPIO write data to current bank (2)\n");
    gpio_write(0x8000000E);

    // Set Current GPIO Bank to 0
    printf("GPIO set current bank to 0\n");
    gpio_setcurbank(0);

    // Read configuration of current GPIO bank (0)
    result = gpio_getconfig();
    printf("GPIO read configuration of current bank (0)\n");
    printf("Configuration: 0x%08X\n", result);

    // Set configuration of current GPIO bank (0)
    printf("GPIO configure current bank (0)\n");
    gpio_setconfig(result | 0x00000080);

    // Read configuration of current GPIO bank (0)
    result = gpio_getconfig();
    printf("GPIO read configuration of current bank (0)\n");
    printf("Configuration: 0x%08X\n", result);

    // Write to current GPIO bank (0) -> LED On
    printf("GPIO write data to current bank (0)\n");
    gpio_write(0x00000000);
    gpio_writemask_lsw((uint16_t)~0x0080, 0x0080);

    printf("GPIO deinitialize...");
    result = gpio_deinit();
    if (result) {
        puts("failed");
        return -1;
    }
    else
        puts("success");

    mips_onoff_status = 1;
    led_onoff_status = 1;

    while (1) {
        system("clear");
        puts  ("MIPS posit control software");
        puts  ("version 1.0.0");
        puts  ("Created by Hyunwoo Oh.");
        puts  ("------------------------------------");
        puts  ("Please select menu");
        puts  ("0: MIPS processor on/off");
        puts  ("1: Program MIPS processor");
        puts  ("2: Sample LED on/off");
        puts  ("9: Exit");
        puts  ("------------------------------------");
        printf("Select menu: "); scanf("%d", &result);
        
        if (result == 0) {
            while (1) {
                system("clear");
                puts  ("MIPS processor on/off");
                puts  ("------------------------------------");
                printf("Current status: %s\n", str_onoff[mips_onoff_status]);
                puts  ("------------------------------------");
                puts  ("Please select menu");
                puts  ("0: Toggle on/off");
                puts  ("9: Return to previous menu");
                puts  ("------------------------------------");
                printf("Select menu: "); scanf("%d", &result);
                if (result == 0) {
                    gpio_init();
                    gpio_setcurbank(2);
                    mips_onoff_status = !mips_onoff_status;
                    gpio_writemask_msw((uint16_t)~0x8000, (uint16_t)mips_onoff_status << 15);
                    gpio_deinit();
                }
                else {
                    break;
                }
            }
        }
        else if (result == 1) {
            char buff[256];
            system("clear");
            puts  ("Program MIPS processor");
            puts  ("------------------------------------");
            printf("Select file: "); scanf("%s", buff);
            if (buff[0] == '~') {
                char temp[255];
                strncpy(temp, buff + 1, strlen(buff)-1);
                sprintf(buff, "%s%s", getenv("HOME"), temp);
            }
            printf("Selected file path: %s\n", buff);
            puts  ("------------------------------------");
            printf("Reading file...");
            fp = fopen(buff, "rb");
            if ( fp != NULL )
                puts("success");
            else {
                puts("failed");
                break;
            }
            printf("MPJTAG Operations \n");
            mpjtag_init_system();
            mpjtag_reset();
            mpjtag_instr_preload();
            // Read size of the each segments
            fseek(fp, 0x1FFFD, SEEK_SET);
            fread((uint8_t*)(&size_kram) + 1, 1, 1, fp);
            fread((uint8_t*)(&size_uram) + 1, 1, 1, fp);
            fread((uint8_t*)(&size_urom) + 1, 1, 1, fp);
            printf("Size of the UROM: 0x%08X\n", size_urom);
            printf("Size of the URAM: 0x%08X\n", size_uram);
            printf("Size of the KRAM: 0x%08X\n", size_kram);

            mpjtag_proc_stop();
            mpjtag_instr_extest();

#define USEG_ADDR 0x40000000
#define KSEG_ADDR 0x00000000

            // Write UROM
            fseek(fp, 0, SEEK_SET);
            i = USEG_ADDR;
            endaddr = i + size_urom;
            for (; i < endaddr; i += 4) {
                fread((uint8_t*)&buf + 3, 1, 1, fp);
                fread((uint8_t*)&buf + 2, 1, 1, fp);
                fread((uint8_t*)&buf + 1, 1, 1, fp);
                fread((uint8_t*)&buf + 0, 1, 1, fp);
                mpjtag_ram_write(i, buf);
            }

            // Write URAM
            fseek(fp, 0x8000, SEEK_SET);
            i = USEG_ADDR + 0x10000000;
            endaddr = i + size_uram;
            for (;  i < endaddr; i += 4 ) {
                fread((uint8_t*)&buf + 3, 1, 1, fp);
                fread((uint8_t*)&buf + 2, 1, 1, fp);
                fread((uint8_t*)&buf + 1, 1, 1, fp);
                fread((uint8_t*)&buf + 0, 1, 1, fp);
                mpjtag_ram_write(i, buf);
            }

            // Write KRAM
            fseek(fp, 0x10000, SEEK_SET);
            i = KSEG_ADDR;
            endaddr = i + size_kram;
            for (;  i < endaddr; i += 4) {
                fread((uint8_t*)&buf + 3, 1, 1, fp);
                fread((uint8_t*)&buf + 2, 1, 1, fp);
                fread((uint8_t*)&buf + 1, 1, 1, fp);
                fread((uint8_t*)&buf + 0, 1, 1, fp);
                mpjtag_ram_write(i, buf);
            }
            mpjtag_instr_bypass();
            mpjtag_deinit_system();

            fclose(fp);
        }
        else if (result == 2) {
            system("clear");
            while (1) {
                puts  ("Sample LED on/off");
                puts  ("------------------------------------");
                printf("Current status: %s\n", str_onoff[mips_onoff_status]);
                puts  ("------------------------------------");
                puts  ("Please select menu");
                puts  ("0: Toggle on/off");
                puts  ("9: Return to previous menu");
                puts  ("------------------------------------");
                printf("Select menu: "); scanf("%d", &result);
                if (result == 0) {
                    gpio_init();
                    gpio_setcurbank(0);
                    led_onoff_status = !led_onoff_status;
                    gpio_write(0x00000000 | ((uint32_t)led_onoff_status << 7));
                    gpio_deinit();
                }
                else {
                    break;
                }
            }
        }
        else if (result == 9) {
            break;
        }
        

    }

    return 0;
}
