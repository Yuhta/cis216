        .global main

        .text
main:
        lea str, %rdi
        call strchk
        mov %rax, %rsi
        lea fmt, %rdi
        xor %rax, %rax
        call printf
        xor %rax, %rax
        ret

checkch:
        xor %rax, %rax
        cmp $'a', %rdi
        je yes
        cmp $'e', %rdi
        je yes
        cmp $'i', %rdi
        je yes
        cmp $'o', %rdi
        je yes
        cmp $'u', %rdi
        je yes
        ret
yes:    mov $1, %rax
        ret

strchk:
        push %r12
        push %rbx
        xor %r12, %r12
        mov %rdi, %rbx
strchk_for_each_char:
        mov (%rbx), %cl
        test $0xFF, %cl
        jz strchk_end_for_each_char
        movzx %cl, %rdi
        call checkch
        add %rax, %r12
        inc %rbx
        jmp strchk_for_each_char
strchk_end_for_each_char:
        mov %r12, %rax
        pop %rbx
        pop %r12
        ret

        .data
str:    .asciz "aei0956xyz\n"
fmt:    .asciz "number of characters that pass test = %u\n"
