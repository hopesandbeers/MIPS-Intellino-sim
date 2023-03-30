#ifndef _INTELLINO_AS_H
#define _INTELLINO_AS_H

#define INTELLINO_SETBASE(vecaddr, cataddr) \
    asm volatile ( "add  $k0,   %0, $0" ::"r"(vecaddr)); \
    asm volatile ( "add  $k1,   %0, $0" ::"r"(cataddr))

#define INTELLINO_TRAIN(num) \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+  0)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+  4)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+  8)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 12)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 16)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 20)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 24)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 28)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 32)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 36)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 40)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 44)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 48)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 52)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 56)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 60)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 64)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 68)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 72)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 76)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 80)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 84)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 88)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 92)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+ 96)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+100)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+104)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+108)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+112)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+116)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+120)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+124)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+128)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+132)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+136)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+140)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+144)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+148)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+152)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+156)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+160)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+164)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+168)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+172)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+176)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+180)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+184)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+188)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+192)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+196)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+200)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+204)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+208)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+212)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+216)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+220)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+224)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+228)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+232)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+236)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+240)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+244)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+248)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+252)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+256)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+260)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+264)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+268)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+272)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+276)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+280)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+284)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+288)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+292)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+296)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+300)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+304)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+308)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+312)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+316)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+320)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+324)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+328)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+332)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+336)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+340)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+344)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+348)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+352)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+356)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+360)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+364)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+368)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+372)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+376)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+380)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+384)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+388)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+392)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+396)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+400)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+404)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+408)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+412)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+416)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+420)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+424)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+428)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+432)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+436)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+440)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+444)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+448)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+452)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+456)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+460)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+464)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+468)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+472)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+476)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+480)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+484)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+488)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+492)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+496)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+500)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*512+504)); \
    asm volatile ( "lwc2 lcomp, %0($k0)"::"i"(num*512+508)); \
    asm volatile ( "lwc2 cat,   %0($k1)"::"i"(num*4))

#endif
