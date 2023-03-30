#------------------------------------------------------------
#  copyright (c) 2020 SeoulTech All Rights Reserved
#------------------------------------------------------------
# Startup.s
#------------------------------------------------------------
# Author		: Hyun Woo Oh (ohhyunwoo@seoultech.ac.kr)
# Oranization	: SEOULTECH.
# Created 		: 2020.09.23
# Version		: 1.0
#-----------------------------------------------------------

#define __asmdef__
#include "asmdefs.h"

.section .excdata, "ax"
inttbl:
	.word IRQ_Syscall
	.word IRQ_Break
	.word IRQ_UART
	.word IRQ_int1
	.word IRQ_int2
	.word IRQ_int3
	.word IRQ_int4
	.word IRQ_int5
excdata_reserved:
    .word 0
    .word 0
    .word 0
    .word 0
    .word 0
    .word 0
    .word 0
    .word 0

#==============================================================================
.text
.global _start
_start:
.align 4	
#register init
    lui     $gp, 0x1000    # global pointer = 0x10000000
	lui     $sp, 0x1001    # stack  pointer = 0x10010000
	ori     $sp, 0x0000

#   main
	jal	main
	nop
    
    
    
#interrupt handler
.macro	def_IRQ_Handler	 handler_name
.align 4
.weak	\handler_name 
\handler_name:
	jr	$ra
.endm

def_IRQ_Handler		IRQ_Syscall
def_IRQ_Handler		IRQ_Break
def_IRQ_Handler		IRQ_UART		
def_IRQ_Handler		IRQ_int1
def_IRQ_Handler		IRQ_int2
def_IRQ_Handler		IRQ_int3
def_IRQ_Handler		IRQ_int4
def_IRQ_Handler		IRQ_int5

#undef __asmdef__
