section .data
formatString db "Result: %u", 0Ah, 0

global _main
extern _makeNBOC
extern _printf
section .text
_main:
    ; Test 1
    push dword 0x12345678    ; Push argument for _makeNBOC (unsigned int)
    call _makeNBOC            ; Call the function
    add esp, 4               ; Clean up the stack
    ; EAX now holds the return value
    
    push eax                 ; Push return value for printf
    push formatString        ; Push format string for printf
    call _printf
    add esp, 8               ; Clean up the stack after printf

    ; Test 2
    push dword 0x87654321
    call _makeNBOC
    add esp, 4
    push eax
    push formatString
    call _printf
    add esp, 8

    ; Test 3
    push dword 0x00000001
    call _makeNBOC
    add esp, 4
    push eax
    push formatString
    call _printf
    add esp, 8

    ; Test 4
    push dword 0xFFFFFFFF
    call _makeNBOC
    add esp, 4
    push eax
    push formatString
    call _printf
    add esp, 8

    ; Test 5
    push dword 0x0000ABCD
    call _makeNBOC
    add esp, 4
    push eax
    push formatString
    call _printf
    add esp, 8

    ; Exit
    xor eax, eax
    ret
