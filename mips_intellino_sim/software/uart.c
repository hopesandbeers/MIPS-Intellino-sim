#include "include/uart.h"

#define WAIT_TX_READY()     while((UART_SR & 0x00000001) == 0)
#define WAIT_RX_COMPLETE()  while((UART_SR & 0x00000002) == 0)


#define POSIT_TEN               (float)134217728
#define MAX_FRAC_LEN            8

#define KEYCODE_BS              0x08
#define KEYCODE_DEL             0x7F

char                    buff_str[64];

void uart_puts(const char* str) {
    uint8_t i;
    uint16_t len = strlen(str);
    for ( i = 0; i < len; i++ ) {
        WAIT_TX_READY();
        UART_TX = str[i];
    }
}
void uart_putc(char ch) {
    WAIT_TX_READY();
    UART_TX = ch;
}
void uart_puth(uint32_t hex) {
    int8_t len = -1;
    uint8_t temp;

    for ( ; hex != 0; hex >>= 4 ) {
        len++;
        temp = hex & 0xF;
        if ( temp < 10 )
            buff_str[len] = 0x30 | temp; 
        else 
            buff_str[len] = temp + 55;
    }

    if (len == -1) {
        WAIT_TX_READY();
        UART_TX = '0';
    }
    else {
        for ( ; len >= 0; len-- ) {
            WAIT_TX_READY();
            UART_TX = buff_str[len];
        }
    }
}

void uart_puthp(uint32_t hex, uint8_t place) {
    int8_t i;
    uint8_t temp;

    for ( i = 0; i < place; i++ ) {
        temp = hex & 0xF;
        if ( temp < 10 )
            buff_str[i] = 0x30 | temp; 
        else 
            buff_str[i] = temp + 55;
        hex >>= 4;
    }

    for ( i = place - 1; i >= 0; i-- ) {
        WAIT_TX_READY();
        UART_TX = buff_str[i];
    }

}

void uart_putd(uint32_t dec) {
    int8_t len = -1;
    uint8_t temp;

    for( ; dec != 0; dec /= 10) {
        len++;
        temp = dec % 10;
        buff_str[len] = 0x30 | temp; 
    }
    
    if (len == -1) {
        WAIT_TX_READY();
        UART_TX = '0';
    }
    else {
        for ( ; len >= 0; len-- ) {
            WAIT_TX_READY();
            UART_TX = buff_str[len];
        }
    }
}

void uart_putf(float f) {
    uint32_t* ptr;
    uint8_t sign;
    uint32_t temp;
    int8_t len = -1;
    uint8_t i;

    ptr = (uint32_t*)&f;

    // Get sign and abs(f)
    sign = (*ptr & 0x80000000) >> 31;
    *ptr = *ptr & 0x7FFFFFFF;

    // Get integer values
    temp = (int32_t)f;
    f = f - temp;
    
    // Print integer values
    for (; temp != 0; temp /= 10) {
        len++;
        buff_str[len] = 0x30 | (temp % 10);
    }

    if (sign) {
        WAIT_TX_READY();
        UART_TX = '-';
    }
    if (len == -1) {
        WAIT_TX_READY();
        UART_TX = '0';
    }
    else {
        for (; len >= 0; len --) {
            WAIT_TX_READY();
            UART_TX = buff_str[len];
        }
    }

    
    // Print dot
    WAIT_TX_READY();
    UART_TX = '.';
    // Print fractions
    for (i = 0; i < MAX_FRAC_LEN; i++) {
        f = f * POSIT_TEN;
        temp = (int32_t)f % 10;
        f -= temp;
        WAIT_TX_READY();
        UART_TX = 0x30 | temp;
    }
}

void uart_putfp(float f, uint8_t place) {
    uint32_t* ptr;
    uint8_t sign;
    uint32_t temp;
    int8_t len = -1;
    uint8_t i;

    ptr = (uint32_t*)&f;

    // Get sign and abs(f)
    sign = (*ptr & 0x80000000) >> 31;
    *ptr = *ptr & 0x7FFFFFFF;

    // Get integer values
    temp = (int32_t)f;
    f = f - temp;
    
    // Print integer values
    for (; temp != 0; temp /= 10) {
        len++;
        buff_str[len] = 0x30 | (temp % 10);
    }

    if (sign) {
        WAIT_TX_READY();
        UART_TX = '-';
    }
    if (len == -1) {
        WAIT_TX_READY();
        UART_TX = '0';
    }
    else {
        for (; len >= 0; len --) {
            WAIT_TX_READY();
            UART_TX = buff_str[len];
        }
    }

    // Print dot
    WAIT_TX_READY();
    UART_TX = '.';
    // Print fractions
    for (i = 0; i < place; i++) {
        f = f * POSIT_TEN;
        temp = (int32_t)f % 10;
        f -= temp;
        WAIT_TX_READY();
        UART_TX = 0x30 | temp;
    }

}

void uart_gets(char* buf) {
}

uint8_t uart_getc() {
    UART_SR = 0x00000000;
    WAIT_RX_COMPLETE();
    UART_SR = 0x00000000;
    return (uint8_t)UART_RX;
}

uint32_t uart_geth() {
    uint8_t temp;
    uint8_t ch_cnt = 1;
    uint32_t cnt = 0;
    while((temp = uart_getc()) != '\r') {
        if (temp >= 0x30 && temp < 0x3A) {
            cnt = (cnt << 4) | (temp & 0xF);
            ch_cnt += 1;
        }
        else if (temp >= 65 && temp < 71) {
            cnt = (cnt << 4) | (temp - 55);
            ch_cnt += 1;
        }
        else if (temp >= 97 && temp < 103) {
            cnt = (cnt << 4) | (temp - 87);
            ch_cnt += 1;
        }
        else if (temp == KEYCODE_BS) {
            cnt >>= 4;
            if ( ch_cnt > 0 )
                ch_cnt -= 1;
        }
        else
            continue;
        if (ch_cnt > 0)
            uart_putc(temp);
    }
    uart_putlf();
    return cnt;
}
