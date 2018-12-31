        .intel_syntax noprefix
        .text
        .globl  hoge
hoge:
        push    rbp
        mov     rbp, rsp
        mov     rax, 0
        pop     rbp
        ret
        .globl  huga
huga:
        push    rbp
        mov     rbp, rsp
        mov     rax, 0
        pop     rbp
        ret
