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
    b dw 3
    c dd 7
    d dq 8

; our code starts here
segment code use32 class=code
    start:
        ; a + b + c + d - (a + b) 
        mov eax, 0
        mov al, [a] ; a
        cbw 
        add ax, [b] ; a + b
        cwde 
        add eax, [c] ; a + b + c 
        
        push dword [d] 
        push dword [d+4]
        
        pop ebx 
        add eax, ebx 
        
        mov edx, 0
        mov ebx, 0 
        pop ebx 
        adc edx, ebx  ; a + b + c + d
        
        push eax 
        mov eax, 0
        mov ebx, 0
        mov al, [a]
        cbw 
        add ax, [b]
        cwde 
        
        push eax 
        pop ebx 
        pop eax 
        
        sub eax, ebx 
        sbb edx, 0
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
