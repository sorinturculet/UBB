; a-b-d+2+c+(10-b)
bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 6
    b db 3
    c db 2
    d db 8

; our code starts here
segment code use32 class=code
    start:
        mov AL,[a];AL=a
        sub AL,[b];AL=a-b
        sub AL,[d];AL=a-b-d
        add AL,2;AL=a-b-d+2
        add AL,[c];AL=a-b-d+2+c
        
        mov AH,10;AH=10
        sub AH,[b];AH=10-b
        
        add AH,AL; AH=AH-AL
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
