bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 14
    b db 73
    c db 91
    d dw 837
    x db 3

; our code starts here
segment code use32 class=code
    start:
        mov eax, 0
        mov ebx, 0
        
        mov al, [a]
        add al, [b]
        mul byte [x]
        
        mov bl, [c]
        dec byte [x]
        mul byte [x]
        
        sub al, bl
        add al, [d]
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
