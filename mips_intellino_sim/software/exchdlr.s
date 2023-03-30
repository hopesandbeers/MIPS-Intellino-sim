#define __asmdef__
#include "asmdefs.h"

.extern  IRQ_Syscall
.extern  IRQ_Break
.extern  IRQ_UART
.extern  IRQ_int1
.extern  IRQ_int2
.extern  IRQ_int3
.extern  IRQ_int4
.extern  IRQ_int5
.extern  inttbl

.section .excdata, "ax"
exctbl:
	.word int_find
    .word exc_done
    .word exc_done
    .word exc_done
    .word exc_ld_hdlr
    .word exc_st_hdlr
    .word exc_done
    .word exc_done
    .word int_syscall_hdlr
    .word int_break_hdlr
    .word exc_instr_hdlr
    .word exc_cop_hdlr
    .word exc_ovf_hdlr
    .word exc_done
    .word exc_done
    .word exc_done

.section .excvec ,"ax"
exc_start:
    .set noat
    .set noreorder

    # Save previous registers to Stack
    addiu   $sp, $sp, -108
    sw      $at, 104($sp)
    sw      $v0, 100($sp)
    sw      $v1,  96($sp)
    sw      $a0,  92($sp)
    sw      $a1,  88($sp)
    sw      $a2,  84($sp)
    sw      $a3,  80($sp)
    sw      $t0,  76($sp)
    sw      $t1,  72($sp)
    sw      $t2,  68($sp)
    sw      $t3,  64($sp)
    sw      $t4,  60($sp)
    sw      $t5,  56($sp)
    sw      $t6,  52($sp)
    sw      $t7,  48($sp)
    sw      $s0,  44($sp)
    sw      $s1,  40($sp)
    sw      $s2,  36($sp)
    sw      $s3,  32($sp)
    sw      $s4,  28($sp)
    sw      $s5,  24($sp)
    sw      $s6,  20($sp)
    sw      $s7,  16($sp)
    sw      $t8,  12($sp)
    sw      $t9,   8($sp)
    sw      $fp,   4($sp)
    mfc0    $t2, C0_CAUSE
    andi    $t2, $t2, 0x3f
    lui     $at, 0x8000
    or      $t2, $at, $t2
#    lw      $t2, exctbl($t2)
    lw      $t2, 64($t2)
    mfc0    $t1, C0_STATUS
    sw      $ra,   0($sp)
    jr      $t2
    mfc0    $t2, C0_CAUSE
    .set at
    .set reorder

exc_ld_hdlr:
    j       int_find
    mfc0    $t2, C0_CAUSE

exc_st_hdlr:
    j       int_find
    mfc0    $t2, C0_CAUSE

int_syscall_hdlr:
    .set noreorder
    .set noat

    # $at = 0x80000000, $t2 = C0_CAUSE
    xori    $t2, $t2,  0x0100
    mtc0    $t2, C0_CAUSE
    lw      $k1, 0($at) 
    jalr    $k1
    mfc0    $t1, C0_STATUS
    j       int_find
    mfc0    $t2, C0_CAUSE
    .set reorder
    .set at

int_break_hdlr:
    .set noreorder
    .set noat

    # $at = 0x80000000, $t2 = C0_CAUSE
    xori    $t2, $t2,  0x0200
    mtc0    $t2, C0_CAUSE
    lw      $k1, 4($at)
    jalr    $k1
    mfc0    $t1, C0_STATUS
    j       int_find
    mfc0    $t2, C0_CAUSE
    .set reorder
    .set at

exc_instr_hdlr:
    j       int_find
    mfc0    $t2, C0_CAUSE

exc_cop_hdlr:
    j       int_find
    mfc0    $t2, C0_CAUSE

exc_ovf_hdlr:
    j       int_find
    mfc0    $t2, C0_CAUSE

int_find:
    .set noreorder
    .set noat
    lui     $at, 0x8000
    .set at

    # $t1 = C0_STATUS, $t2 = C0_CAUSE
    and     $t1, $t2, $t1        # mask interrupt

    # Find Interrupt, Jump if 1
    andi    $k0, $t1, 0x0100
    bnez    $k0, jthdlr0

    andi    $k0, $t1, 0x0200
    bnez    $k0, jthdlr1

    andi    $k0, $t1, 0x0400
    bnez    $k0, jthdlr2

    andi    $k0, $t1, 0x0800
    bnez    $k0, jthdlr3

    andi    $k0, $t1, 0x1000
    bnez    $k0, jthdlr4

    andi    $k0, $t1, 0x2000
    bnez    $k0, jthdlr5

    andi    $k0, $t1, 0x4000
    bnez    $k0, jthdlr6

    andi    $k0, $t1, 0x8000
    bnez    $k0, jthdlr7

    .set reorder

exc_done:
    .set noreorder
    lw      $v0, 100($sp)
    .set noat

    # Load previous registers from Stack
    lw      $at, 104($sp)
    .set at

    lw      $v1,  96($sp)
    lw      $a0,  92($sp)
    lw      $a1,  88($sp)
    lw      $a2,  84($sp)
    lw      $a3,  80($sp)
    lw      $t0,  76($sp)
    lw      $t1,  72($sp)
    lw      $t2,  68($sp)
    lw      $t3,  64($sp)
    lw      $t4,  60($sp)
    lw      $t5,  56($sp)
    lw      $t6,  52($sp)
    lw      $t7,  48($sp)
    lw      $s0,  44($sp)
    lw      $s1,  40($sp)
    lw      $s2,  36($sp)
    lw      $s3,  32($sp)
    lw      $s4,  28($sp)
    lw      $s5,  24($sp)
    lw      $s6,  20($sp)
    lw      $s7,  16($sp)
    lw      $t8,  12($sp)
    lw      $t9,   8($sp)
    lw      $fp,   4($sp)
    lw      $ra,   0($sp)
    addiu   $sp, $sp, 108

    mfc0    $k0, C0_EPC
    jr      $k0
    rfe
    .set reorder

jthdlr0:
    .set noreorder
    .set noat

    # $at = inttbl(0x80000000)
    # Clear IP Bit, Jump to IRQ Handler
    lw      $k1, 0($at)
    mfc0    $t2, C0_CAUSE
    xori    $t2, $t2, 0x0100
    mtc0    $t2, C0_CAUSE
    jalr    $k1
    mfc0    $t1, C0_STATUS
    j       int_find
    mfc0    $t2, C0_CAUSE

jthdlr1:
    lw      $k1, 4($at)
    mfc0    $t2, C0_CAUSE
    xori    $t2, $t2, 0x0200
    mtc0    $t2, C0_CAUSE
    jalr    $k1
    mfc0    $t1, C0_STATUS
    j       int_find
    mfc0    $t2, C0_CAUSE

jthdlr2:
    lw      $k1, 8($at)
    mfc0    $t2, C0_CAUSE
    xori    $t2, $t2, 0x0400
    mtc0    $t2, C0_CAUSE
    jalr    $k1
    mfc0    $t1, C0_STATUS
    j       int_find
    mfc0    $t2, C0_CAUSE

jthdlr3:
    lw      $k1, 12($at)
    mfc0    $t2, C0_CAUSE
    xori    $t2, $t2, 0x0800
    mtc0    $t2, C0_CAUSE
    jalr    $k1
    mfc0    $t1, C0_STATUS
    j       int_find
    mfc0    $t2, C0_CAUSE

jthdlr4:
    lw      $k1, 16($at)
    mfc0    $t2, C0_CAUSE
    xori    $t2, $t2, 0x1000
    mtc0    $t2, C0_CAUSE
    jalr    $k1
    mfc0    $t1, C0_STATUS
    j       int_find
    mfc0    $t2, C0_CAUSE

jthdlr5:
    lw      $k1, 20($at)
    mfc0    $t2, C0_CAUSE
    xori    $t2, $t2, 0x2000
    mtc0    $t2, C0_CAUSE
    jalr    $k1
    mfc0    $t1, C0_STATUS
    j       int_find
    mfc0    $t2, C0_CAUSE

jthdlr6:
    lw      $k1, 24($at)
    mfc0    $t2, C0_CAUSE
    xori    $t2, $t2, 0x4000
    mtc0    $t2, C0_CAUSE
    jalr    $k1
    mfc0    $t1, C0_STATUS
    j       int_find
    mfc0    $t2, C0_CAUSE

jthdlr7:
    lw      $k1, 28($at)
    mfc0    $t2, C0_CAUSE
    xori    $t2, $t2, 0x8000
    mtc0    $t2, C0_CAUSE
    jalr    $k1
    mfc0    $t1, C0_STATUS
    j       int_find
    mfc0    $t2, C0_CAUSE

    .set at
    .set reorder


#undef __asmdef__
