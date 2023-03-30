#ifndef _DEBUG_H_
#define _DEBUG_H_

#ifdef Debug

#include <stdio.h>
#include <string.h>
#include <errno.h>

#define debug_puts(str)         puts(str)
#define debug_printf(fmt, ...)  printf(fmt, ##__VA_ARGS__)

#else

#define debug_puts(str)  
#define debug_printf(fmt, ...)  

#endif

#endif
