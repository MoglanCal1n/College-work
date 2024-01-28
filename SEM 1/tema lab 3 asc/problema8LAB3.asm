bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    
    a db 7
    b dw 4
    c dd 8
    d dq 3
    
; our code starts here
segment code use32 class=code
    start:
        ;(a+b-d)+(a-b-d) = 8
        
        mov eax, 0
        mov ebx, 0
        mov ecx, 0
        mov edx, 0
        
        
        mov al, [a] ; al = 7
        mov ah, 0 ; ax = 7
        add ax, [b] ; ax = 7 + 4
        
        
        sub eax, [d]
        
        mov cl, [a]
        mov ch, 0
        sub cx, [b] 
        
        sub ecx, [d]
        
        add eax, ecx 
        
        
        
        
        
        
        
        
        
        
        
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
