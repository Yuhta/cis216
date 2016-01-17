.global main

.data
x:              .int 9
dy:             .int 10
dx:             .int 6
intercept:      .int -2
fmt:            .asciz "answer = %d\n"

.text
main:
        movq dy, %rax
        imulq x, %rax
        xor %rdx, %rdx
        movl dx, %esi
        idivl %esi
        addq intercept, %rax
        movq %rax, %rsi
        leaq fmt, %rdi
        xor %rax, %rax
        call printf
        xor %rax, %rax
        ret
