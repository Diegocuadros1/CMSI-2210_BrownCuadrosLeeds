section .data
        format_in: db "%d", 0
        format_out: db "the GCD of these two numbers is %d", 10, 0
        num1 dd 1
        num2 dd 1        

section .text
        global _main
        extern _printf
        extern _scanf
_main: 
        ;first number
        push num1
        push format_in
        call _scanf
        add esp, 8

        ;second number
        push num2
        push format_in
        call _scanf
        add esp, 8

        ; moving num1 & num2 into eax & ebx
        mov eax, [num1]
        mov ebx, [num2]

gcd_loop:
        cmp ebx, 0      ;check if ebx is 0
        je done         ;jump to done if ebx is 0

        ; eax % ebx
        xor edx, edx    ;clear edx
        div ebx         ;divide a by b quotient in eax, remainder in edx

        ;updating for next iteration
        mov eax, ebx     ;set a to old b
        mov ebx, edx    ;set b to remainer d

        jmp gcd_loop    ; jump back to beginning

done:
        ;eax contains gcd
        push eax             ; Push GCD value onto the stack
        push format_out      ; Push address of format string onto the stack
        call _printf         ; Call printf
        add esp, 8           ; Clean up the stack (2 arguments * 4 bytes each)

        ret                  ;exit program