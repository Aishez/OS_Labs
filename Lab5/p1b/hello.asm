section .text
    mov ah, 0x0e   ; Set tele-type mode (output to screen)

    mov al, 'H'    ; Load the ASCII code for 'H' into register AL
    int 0x10       ; Call BIOS interrupt to print character

    mov al, 'e'    
    int 0x10       

    mov al, 'l'    
    int 0x10       

    mov al, 'l'    
    int 0x10       

    mov al, 'o'    
    int 0x10       

    jmp $          ; halting the system

    times 510 - ($ - $$) db 0
    dw 0xaa55