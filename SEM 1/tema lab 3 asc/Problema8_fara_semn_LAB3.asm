bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a dw 1
    b dw 3
    c db 3
    d db 2
    e dd 6
    x dq 8

; our code starts here
segment code use32 class=code
    start:
        ; 1/a+200*b-c/(d+1)+x/a-e; a,b-word; c,d-byte; e-doubleword; x-qword
        
        mov eax, 0; eax = 0
        mov ebx, 0; ebx = 0
        mov edx, 0; edx = 0
        
        mov ax, 1 ; ax = 1
        mov bx, [a] ; bx = a
        div bx ; dx:ax = 1/a 
        
        push dx; dx in stiva
        push ax; ax in stiva
        
        mov eax, 200; eax = 200
        mul word [b] ; eax = 200 * b
        
        pop ebx ; ebx = 1/a
        
        add ebx, eax ; ebx = 1/a + 200*b
        
        
        mov eax, 0; eax = 0
        mov al, [c]; al = c
        mov ah, 0; ax = c 
        mov ecx, 0
        mov cl, [d] ; cl = d
        inc cl ; cl += 1
        div cl ; dx:ax  = c/(d+1) // idiv
        push dx 
        push ax 
        pop eax 
        sub ebx, eax ; ebx = 1/a+200*b-c/(d+1) 
        
        mov ecx, 0 ;  
        mov cl, [a]
        mov eax, dword [x+0]
        mov edx, dword [x+4] 
        
        div ecx 
        
        add eax, ebx ; 1/a+200*b-c/(d+1)+x/a 
        
        sub eax, [e]; 1/a+200*b-c/(d+1)+x/a-e   
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
