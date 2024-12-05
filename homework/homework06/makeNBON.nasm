global main
extern makeNBOC
extern printf

section .data
formatString db "Result: %u", 0Ah, 0

section .text
main:
    ; Test 1
    push dword 0x12345678    ; Push argument for makeNBOC (unsigned int)
    call makeNBOC            ; Call the function
    add esp, 4               ; Clean up the stack
    ; EAX now holds the return value
    
    push eax                 ; Push return value for printf
    push formatString        ; Push format string for printf
    call printf
    add esp, 8               ; Clean up the stack after printf

    ; Test 2
    push dword 0x87654321
    call makeNBOC
    add esp, 4
    push eax
    push formatString
    call printf
    add esp, 8

    ; Test 3
    push dword 0x00000001
    call makeNBOC
    add esp, 4
    push eax
    push formatString
    call printf
    add esp, 8

    ; Test 4
    push dword 0xFFFFFFFF
    call makeNBOC
    add esp, 4
    push eax
    push formatString
    call printf
    add esp, 8

    ; Test 5
    push dword 0x0000ABCD
    call makeNBOC
    add esp, 4
    push eax
    push formatString
    call printf
    add esp, 8

    ; Exit
    xor eax, eax
    ret
