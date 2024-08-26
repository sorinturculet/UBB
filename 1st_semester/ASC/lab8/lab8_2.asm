bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,scanf,printf             ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import scanf msvcrt.dll  
import printf msvcrt.dll   ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    a dd 0
    format db "%d",0
    lowernumber dd 4294967295
    message db "Cel mai mic numar este %d",0
;Se citesc de la tastatura numere (in baza 10) pana cand se introduce cifra 0. Determinaţi şi afişaţi cel mai mic număr dintre cele citite.
; our code starts here
segment code use32 class=code
    start:
        repeta:
            push dword a
            push dword format
            call[scanf]
            add esp,4*2; eliberam parametri de pe stiva
            cmp word[a],0
                je final
            mov eax,[a]
            mov ebx,[lowernumber]
            cmp eax,ebx
            ja maimare
                mov [lowernumber],eax
            maimare:
        jmp repeta
        final:
        push dword [lowernumber]
        push dword message
        call [printf]
        add esp,4*2
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
