       
section .data
num1   dq     24
num2   dq     18
str db "GCD: %d", 10, 0

section .bss
        gcd_res resq 1

section .text
global _main
exern _printf

_main: 
        ; moving rax rbx into num1 and num2
        mov rax, num1
        mov rbx, num2

gcd_loop:
        cmp rbx, 0      ;check if rbx is 0
        je done         ;jump to done if rbx is 0

        xor rdx, rdx    ;clear rdx
        div rbx         ;divide rax by rbx
        mov rax, rbx    ;move rbx into rax
        mov rbx, rdx    ;move rdx into rbx
        jmp gcd_loop


done:
        mov qword [gcd_res], rax

        lea rdi, [str]
        mov rsi, rax
        xor rax, rax             
        call _printf

        ; Exit the program
        mov rax, 60               ; sys_exit syscall number
        xor rdi, rdi              ; Exit code 0
        syscall

section .data
num1:   equ     24
num2:   equ     18
modnums:   equ   0
