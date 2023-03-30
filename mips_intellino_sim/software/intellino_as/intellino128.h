#ifndef _INTELLINO_AS_H
#define _INTELLINO_AS_H

#define INTELLINO_SETBASE(vecaddr, cataddr) \
    asm volatile ( "add  $k0,   %0, $0" ::"r"(vecaddr)); \
    asm volatile ( "add  $k1,   %0, $0" ::"r"(cataddr))

#define INTELLINO_TRAIN(num) \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+  0)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+  4)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+  8)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 12)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 16)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 20)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 24)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 28)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 32)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 36)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 40)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 44)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 48)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 52)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 56)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 60)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 64)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 68)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 72)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 76)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 80)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 84)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 88)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 92)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+ 96)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+100)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+104)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+108)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+112)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+116)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*128+120)); \
    asm volatile ( "lwc2 lcomp, %0($k0)"::"i"(num*128+124)); \
    asm volatile ( "lwc2 cat,   %0($k1)"::"i"(num*4))

#endif
