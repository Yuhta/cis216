        .global main

        .text
main:
        lea ans, %rsi
        mov %rsi, %rcx
for_each_char:
        mov (%rcx), %al
        cmp $0, %al
        je end_for_each_char
        cmp $'A', %al
        jl not_letter
        xor $0x20, %al
        mov %al, (%rcx)
not_letter:
        inc %rcx
        jmp for_each_char
end_for_each_char:

        mov number, %rdx
        sar $5, %rdx

        lea fmt, %rdi
        xor %rax, %rax
        call printf
        xor %rax, %rax
        ret

        .data
number: .quad -32760
ans:    .asciz "NUM dIVIDED bY 32 = "
fmt:    .asciz "%s%d\n"
