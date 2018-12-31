        .intel_syntax noprefix
        .text
        .globl  f
f:
        push    rbp
        mov     rbp, rsp
        mov     rax, 0
        pop     rbp
        ret
