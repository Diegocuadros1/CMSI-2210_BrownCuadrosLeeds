section .text
global _findGCD

_findGCD:
    mov eax, [esp + 4] ; moving first argument (num1) into eax
    mov ebx, [esp + 8] ; moving second argument (num2) into ebx

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
    ;eax = gcd
    ret