 .text
 .set noreorder
 .globl __start
 .type __start,@function
 .ent __start
__start:
 .cpload $25
 move $31,$0
 addiu $sp,$sp,-32
 sw $gp,16($sp)
 lw $25,%call16(probe_main)($gp)
 jalr $25
 nop
 lw $gp,16($sp)
 move $4,$2
 lw $25,%call16(_exit)($gp)
 jalr $25
 nop
1: b 1b
 nop
 .end __start
