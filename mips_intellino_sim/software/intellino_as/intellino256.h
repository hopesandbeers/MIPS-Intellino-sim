#ifndef _INTELLINO_AS_H
#define _INTELLINO_AS_H

#define INTELLINO_SETBASE(vecaddr, cataddr) \
    asm volatile ( "add  $k0,   %0, $0" ::"r"(vecaddr)); \
    asm volatile ( "add  $k1,   %0, $0" ::"r"(cataddr))

#define INTELLINO_TRAIN(num) \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+  0)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+  4)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+  8)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 12)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 16)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 20)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 24)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 28)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 32)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 36)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 40)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 44)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 48)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 52)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 56)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 60)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 64)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 68)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 72)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 76)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 80)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 84)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 88)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 92)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+ 96)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+100)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+104)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+108)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+112)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+116)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+120)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+124)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+128)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+132)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+136)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+140)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+144)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+148)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+152)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+156)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+160)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+164)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+168)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+172)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+176)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+180)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+184)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+188)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+192)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+196)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+200)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+204)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+208)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+212)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+216)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+220)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+224)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+228)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+232)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+236)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+240)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+244)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*256+248)); \
    asm volatile ( "lwc2 lcomp, %0($k0)"::"i"(num*256+252)); \
    asm volatile ( "lwc2 cat,   %0($k1)"::"i"(num*4))

#endif
