section .data
    ; Define the byte of data we want to check
    byte_data db 01101101b  ; Example byte: 01101001

    ; Message formats for output
    msg_even db "Parity Bit (Odd Parity): 1", 10, 0
    msg_odd  db "Parity Bit (Odd Parity): 0", 10, 0


section .text
    global _main
    extern _printf

_main:
    mov eax, 0          ; Clear EAX register
    mov al, [byte_data] ; Move the byte data into AL (lower 8 bits of EAX)

    mov ecx, 0          ; Counter set to 0

    ; Initialize loop counter
    mov edx, 8          ; We need to check 8 bits

count_bits:
    test al, 1          ; Perform bitwise AND between AL and 1
    jz skip_increment   ; If result is zero, bit is 0; skip increment

    ; If result is 1, increment the counter
    inc ecx

skip_increment:
    ; Shift AL right by 1 to check the next bit
    shr al, 1

    ; Decrement loop counter and loop back if not zero
    dec edx
    jnz count_bits

    ; After counting, check if the count is even or odd
    ; We'll use bitwise AND with 1 to check the least significant bit
    test ecx, 1         ; Check if count is odd (LSB is 1)
    jz even_count       ; If zero flag is set, count is even

odd_count:
    ; Count is odd, parity bit should be 0
    ; Print the message for parity bit 0
    push msg_odd
    call _printf
    jmp exit_program

even_count:
    ; Count is even, parity bit should be 1
    ; Print the message for parity bit 1
    push msg_even
    call _printf
    jmp exit_program

exit_program:
    ; Exit the program
    mov eax, 1          ; sys_exit syscall number
    mov ebx, 0          ; Exit code 0
    int 80h             ; Make syscall

section .data
len_msg_even equ $ - msg_even
len_msg_odd  equ $ - msg_odd
