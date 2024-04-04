; This routine prints a string in 16-bit real mode
; The string to print is pointed by the BX register

[bits 16]
print_string:
    pusha                           ; Save all general purpose registers
.loop:
    mov al, [bx]                    ; Load the next byte of the string into AL
    inc bx                          ; Point BX to the next character
    or al, al                       ; Check if the character is null (end of string)
    jz .done                        ; If the character is null, we're done
    mov ah, 0x0E                    ; BIOS teletype function
    int 0x10                        ; BIOS interrupt
    jmp .loop                       ; Repeat for the next character
.done:
    popa                            ; Restore all general purpose registers
    ret                             ; Return from the routine
