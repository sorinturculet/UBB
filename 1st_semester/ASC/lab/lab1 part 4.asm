;(a*2)+2*(b-3)-d-2*c
bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a dw 2
    b dw 4
    c dw 5
    d dw 4
    doi EQU 2
; our code starts here
segment code use32 class=code
    start:
        mov AX,[a];AX=a
        mov BX,2; BX=2
        mul BX; DX:AX=a*2
        push DX
        push AX
        pop ECX;ECX=a*2
        
        mov BX,[b];CX=b
        sub BX,3;CX=b-3
        mov AX,2; AX=2
        mul BX;DX:AX= 2*(b-3)
        push DX
        push AX
        pop EBX; EBX=2*(b-3)
        
        add EBX,ECX;EBX=a*2+2*(b-3)
        
        mov AX,[c];AX=c
        mov CX,2;CX=2
        mul CX; DX:AX=c*2
        push DX
        push AX
        pop ECX;ECX=c*2
        
        sub EBX,[d];EBX=2*(b-3)-d
        sub EBX,ECX;EBX=2*(b-3)-d-c*2
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
