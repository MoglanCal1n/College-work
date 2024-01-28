bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 4
    b db 4
    c db 3
    d db 2
    e dw 1
    x dq 8

; our code starts here
segment code use32 class=code
    start:
        ; (a*b-2*c*d)/(c-e)+x/a; a,b,c,d-byte; e-word; x-qword
       
       mov eax, 0
       mov ebx, 0
       mov ecx, 0
       mov edx, 0
        
       mov al, [a]
       cbw 
       imul byte [b] 
       
       mov bx, ax 
       
       mov ax, 2 
       imul byte [c] 
       imul byte [d] 
       
       sub bx, ax 
       mov cx, bx 
       
       mov al, [c]
       cbw  
       sub ax, [e]
       
       mov bx, ax 
       mov ax, cx 
       
       idiv bx 
       
       mov ebx, 0
       mov bx, ax 
       
       mov al, [a] 
       cbw 
       cwde
       mov ecx, eax 
       
       
       mov eax, dword [x+0]
       mov edx, dword [x+4]
       
       idiv ecx 
       
       add eax, ebx 
       
        
      
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
