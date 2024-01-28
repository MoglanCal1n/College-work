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
    b dw 7
    c dd 3
    d dq 2

; our code starts here
segment code use32 class=code
    start:
        ;(b+c+d)-(a+a) = 4
        mov eax, 0
        mov ax, [b] 
        cwde  
        add ax, [c] ; b+c
        cdq 
        add eax, [d] ; (b+c+d)
        adc edx, 0
        
        push eax 
        
        mov eax, 0
        mov al, [a]
        add al, [a]
        cbw 
        adc ax, 0
        cwde 
        cdq 
        
        push eax 
        pop ebx
        pop eax
        
        sub eax, ebx
        sbb edx, 0
      
               
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
