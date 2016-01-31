        .global main

        .text
main:
        xor %rcx, %rcx
        xor %rsi, %rsi
for_each_nums:
        cmp count, %rcx
        jae for_each_nums_end
        mov nums(,%rcx,8), %rax
        cmp $50, %rax
        setg %dl
        cmp $100, %rax
        setl %dh
        and %dh, %dl
        movzx %dl, %rdx
        add %rdx, %rsi
        inc %rcx
        jmp for_each_nums
for_each_nums_end:
        lea fmt, %rdi
        xor %rax, %rax
        call printf
        xor %rax, %rax
        ret

        .data
nums:   .quad 3, 68, 2, 60, 2000, 51, 99, 102
count:  .quad 8
fmt:    .asciz "count = %u\n"
