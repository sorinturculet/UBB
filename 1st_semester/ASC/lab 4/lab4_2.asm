bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a dw 1010101010101010b
    b dw 1111111100000000b
    c dd 0
;Se dau cuvintele A si B. Se cere dublucuvantul C:
;bitii 0-2 ai lui C au valoarea 0
;bitii 3-5 ai lui C au valoarea 1
;bitii 6-9 ai lui C coincid cu bitii 11-14 ai lui A
;bitii 10-15 ai lui C coincid cu bitii 1-6 ai lui B
;bitii 16-31 ai lui C au valoarea 1
segment code use32 class=code
    start:
        mov EBX,0
        mov AX,0000000000111000b
        or bx,ax ; bx=000000000011100 astfel am facut primele 2 cerinte
        
        mov ax,[a]
        and ax,0111100000000000b;mascam bitii 11-14 a lui a
        ror ax,5            ;ax=0000000101000000
        or bx,ax            ;bx=0000000101111000
        
        mov ax,[b]
        and ax,0000000001111110b;mascam bitii 1-6 a lui b ax=000000000000000
        rol ax,9 ;ax=000000000000000 mutam bitii 1-6 pe pozitiile 10-15
        or bx,ax;bx=0000000101111000
        
        mov eax,0
        mov ax,1111111111111111b
        rol eax,16 ;eax=1111111111111111 0000000000000000
        or ebx,eax; ebx=1111111111111111 0000000101111000
        
        mov [c],ebx
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
