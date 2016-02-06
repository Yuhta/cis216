        .global main

        .text
main:
        mov number, %rsi
        mov %rsi, %rax
        and $1, %rax
        neg %rax
        shr $4, %rsi
        shld $4, %rax, %rsi
        lea fmt, %rdi
        xor %rax, %rax
        call printf
        xor %rax, %rax
        ret

        .data
number: .quad 0x448
fmt:    .asciz "result is = %u\n"
