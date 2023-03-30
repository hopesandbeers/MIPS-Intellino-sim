#include "include/calc.h"

posit32_t sqrtp32(posit32_t posit) {
    asm volatile (
            "sqrt.s  %0, %1;"
            : "=f"(posit)            // %0: output
            : "f"(posit)             // %1: input
            );
    return posit;
}
