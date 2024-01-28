bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a dw 750 
    b dw 980
    c dw 1100 
    d dw 699

; our code starts here
segment code use32 class=code
    start:
        mov eax, 0
        mov ebx, 0
        
        mov ax, [a]
        add ax, [b]
        add ax, [c]
        
        mov bx, [d]
        add bx, [d]
        
        sub ax, bx
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
