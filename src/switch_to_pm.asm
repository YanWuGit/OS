[bits 16]
; Switch to protected mode
switch_to_pm:

    

    ; We must switch of interrupts until we have
    ; set - up the protected mode interrupt vector
    ; otherwise interrupts will run riot.
    cli


    ; Load our global descriptor table , which defines
    ; the protected mode segments ( e.g. for code and data )
    lgdt [gdt_descriptor]

    ; To make the switch to protected mode , we set
    ; the first bit of CR0 , a control register
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax 

    ; Make a far jump ( i.e. to a new segment ) to our 32 - bit
    ; code. This also forces the CPU to flush its cache of
    ; pre - fetched and real - mode decoded instructions , which can
    ; cause problems.
    jmp CODE_SEG:init_pm

[bits 32]
    ; Initialise registers and the stack once in PM.
    init_pm:
        ; Now in PM , our old segments are meaningless ,
        ; so we point our segment registers to the
        ; data selector we defined in our GDT
        mov ax, DATA_SEG
        mov ds, ax
        mov ss, ax
        mov es, ax
        mov fs, ax
        mov gs, ax

        ; Update our stack position so it is right
        ; at the top of the free space.
        mov ebp, 0x90000               
        mov esp, ebp

    ; Clear the screen and print a character to let us know we're in PM
    call clear_screen
    call print_char_pm

        ; Call the procedure that starts your 32-bit code
        call BEGIN_PM                   

        ; Definitions of gdt_descriptor, CODE_SEG, DATA_SEG, BEGIN_PM, etc. should be elsewhere.
        ; This file just contains the bits to switch to PM.

; Function to clear the screen
clear_screen:
    mov edi, 0xB8000          ; Start address of text-mode video memory
    mov ecx, 2000             ; Number of characters on a standard 80x25 screen
    mov ax, 0x0720            ; Attribute-byte pair (gray on black space character)
clear_loop:
    stosw                     ; Write AX to ES:EDI and increase DI by 2
    loop clear_loop
    ret

; Function to print a single character in PM
print_char_pm:
    mov edi, 0xB8000          ; Start address of text-mode video memory
    mov al, 'P'               ; Character to print
    mov ah, 0x07              ; Attribute byte (light gray on black)
    stosw                     ; Write AX to ES:EDI
    ret