.global main

.data
distance:       .int 155
speed:          .int 60
fmt:            .asciz "%d hours and %d minutes\n"

.text
main:
        xor %rdx, %rdx
        movq distance, %rax
        movl speed, %ecx
        divl %ecx
        movq %rax, %rsi
        movq %rdx, %rax
        movq $60, %rdi
        mulq %rdi
        xor %rdx, %rdx
        divl %ecx
        movq %rax, %rdx
        leaq fmt, %rdi
        xor %rax, %rax
        call printf
        xor %rax, %rax
        ret
