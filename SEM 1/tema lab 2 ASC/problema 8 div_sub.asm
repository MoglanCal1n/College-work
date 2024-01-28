bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 5
    b db 10
    c db 8
    d db 3

; our code starts here
segment code use32 class=code
    start:
        mov eax, 0
        mov ebx, 0
        mov ebx, 75
        mul byte [b]
        
        mov ax, 100
        mul byte [a]
        add ax, [d]
        add ax, 5
        sub ax, bx
        
        mov ebx, 0
        
        mov bx, [c]
        sub bx, 5
        
        div bx
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
