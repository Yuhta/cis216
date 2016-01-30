.global main

.data
charstr:
        .asciz "abcdef"

.text
main:
        movb $88, %dl
        movq $0, %rax
loop:
        movb %dl, charstr(%rax)
        incq %rax
        incq %rax
        cmpb $0, charstr(%rax)
        jne loop

        leaq charstr, %rdi
        call puts
        xorq %rax, %rax
        ret
