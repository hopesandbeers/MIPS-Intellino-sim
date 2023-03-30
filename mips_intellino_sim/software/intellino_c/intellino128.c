#include "intellino.h"
void intellino_train (uint32_t* data_ptr, uint8_t cat) {
    asm volatile ( ".set noreorder");
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"(  0));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"(  4));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"(  8));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 12));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 16));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 20));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 24));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 28));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 32));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 36));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 40));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 44));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 48));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 52));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 56));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 60));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 64));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 68));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 72));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 76));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 80));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 84));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 88));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 92));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"( 96));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"(100));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"(104));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"(108));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"(112));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"(116));
    asm volatile ( "lwc2 comp,  %0($a0)"::"i"(120));
    asm volatile ( "lwc2 lcomp, %0($a0)"::"i"(124));
    asm volatile ( "mtc2 $a1, cat");
    asm volatile ( ".set reorder");
}
Intellino_Result intellino_inference (uint32_t* data_ptr) {
    Intellino_Result result;
    asm volatile ( "add  $at,   %0, $0" ::"r"(data_ptr));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"(  0));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"(  4));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"(  8));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 12));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 16));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 20));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 24));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 28));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 32));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 36));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 40));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 44));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 48));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 52));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 56));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 60));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 64));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 68));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 72));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 76));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 80));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 84));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 88));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 92));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"( 96));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"(100));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"(104));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"(108));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"(112));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"(116));
    asm volatile ( "lwc2 comp,  %0($at)"::"i"(120));
    asm volatile ( "lwc2 lcomp, %0($at)"::"i"(124));
    asm volatile ( "nop\n\t \
                    nop\n\t \
                    nop\n\t \
                    nop\n\t \
                    nop");
    asm volatile ( "mfc2 %0, cat\n\t \
                    mfc2 %1, dist"
                   : "=r" (result.Category),
                     "=r" (result.Distance)
                   : );
    return result;
}

void intellino_forget (uint8_t nid) {
    asm volatile ( "mtc2 %0, nid"::"r"(nid));
    asm volatile ( "mtc2 %0, forget"::"r"(nid));
}

void intellino_clear () {
    asm volatile ( "mtc2 $0, clear");
}
