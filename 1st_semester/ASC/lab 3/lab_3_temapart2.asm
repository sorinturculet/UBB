bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exis\ts even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db -6
    b dw 167
    c dd -255
;c+a+b+b+a cu semn
; our code starts here
segment code use32 class=code
    start:
        mov ecx,[c];ecx=c
        mov al,[a];al=a
        cbw     ;ax=a
        cwde    ;eax=a
        add ecx,eax;ecx=c+a
        
        mov ax,[b];ax=b
        cwde      ;eax=b
        add ecx,eax;ecx=c+a+b
        add ecx,eax;ecx=c+a+b+b
        
        mov al,[a];al=a
        cbw     ;ax=a
        cwde    ;eax=a
        add ecx,eax;ecx=c+a+b+b+a
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
