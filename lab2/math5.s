.global main

.data
width:  .int 10
height: .int 3
fmt:    .asciz "answer = %d\n"

.text
main:
        movq height, %rsi
        leaq 3(, %rsi, 2), %rsi
        imulq width, %rsi
        leaq fmt, %rdi
        xorq %rax, %rax
        call printf
        xorq %rax, %rax
        ret
