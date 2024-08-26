
bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    e dw 3
    f dw 12
    d dw 7
;f*(e-2)/[3*(d-5)]
; our code starts here
segment code use32 class=code
    start:
       mov AX,[e]; AX=e
       sub AX,2; AX=e-2
       mov BX,[f]; BX=f
       mul BX; DX:AX=f*(e-2)
       push DX
       push AX
       pop EBX;EBX=f*(e-2) 12
       
       mov AX,[d]; AX=d
       sub AX,5; AX=d-5
       mov CX,3; CX=3
       mul CX; DX:AX=3*(d-5)
       push DX
       push AX
       pop ECX; EAX=3*(d-5) 6
       
       
       mov EDX,0
       
       mov EAX,EBX ;edx:eax=f*(e-2)
       div ECX      ;
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
