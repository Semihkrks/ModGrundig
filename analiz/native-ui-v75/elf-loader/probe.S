 .text
 .set noreorder
 .globl __start
__start:
 addiu $4,$0,74
 addiu $2,$0,4001
 syscall
 nop
