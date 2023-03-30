#ifndef _UART_H
#define _UART_H

#include <stdint.h>
#include <string.h>
#define UART_TX		*(uint32_t*)0xA0000000
#define UART_RX		*(uint32_t*)0xA0000004
#define UART_SR		*(uint32_t*)0xA0000008

// UART Put(string ,char, hex, decimal, float(posit))
void uart_puts(const char* str);
void uart_putc(char ch);
void uart_puth(uint32_t hex);
void uart_puthp(uint32_t hex, uint8_t place);
void uart_putd(uint32_t dec);
void uart_putf(float f);
void uart_putfp(float f, uint8_t place);
// UART Get(string, char, hex)
void uart_gets(char* buf);
uint8_t uart_getc();
uint32_t uart_geth();


#define uart_putlf()    uart_puts("\r\n")

#endif
