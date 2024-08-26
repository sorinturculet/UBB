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
    b dw 5 
    c dd 6
    d dq 8
;a+b-c+(d-a) fara semn
; our code starts here
segment code use32 class=code
    start:
        
        mov al,[a] ; al=a
        mov ah,0    ;ah=0
        add ax,[b]
        
        mov dx,0 ; dx:ax=a+b
        sub ax,[c]
        sbb dx,[c+2] ; dx:ax=a+b-c
        
        push dx
        push ax
        pop eax
        
        mov ebx,[d] 
        mov ecx,[d+4];ecx:ebx=d
        mov edx,0
        mov dl,[a] ;edx=a
        
        sub ebx,edx ;
        sbb ecx,0
        
        add ebx,eax 
        adc ecx,0 ;ecx:ebx=a+b-c+(d-a)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
