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

; our code starts here
;bitii 0-4 ai lui C coincid cu bitii 11-15 ai lui A
;bitii 5-11 ai lui C au valoarea 1
;bitii 12-15 ai lui C coincid cu bitii 8-11 ai lui B
;bitii 16-31 ai lui C coincid cu bitii lui A
segment code use32 class=code
    start:
        mov ebx,0 ; calculam in bx rezultatul
        
        mov ax,[a]
        and ax,1111100000000000b ; ax=101010000000000
        mov cl,5
        rol ax,cl   ;ax=000000000010101
        or bx,ax    ;bx=000000000010101
        
        or bx,0000111111100000b; bx=0000111111110101
        
        mov ax,[b]
        and ax,0000111100000000b ;ax=000011110000000b
        mov cl,4
        rol ax,cl; ax=111100000000000b
        or bx,ax ;bx=1111111111110101
        
        mov eax,0
        mov ax,[a] ; eax=0000000000000000 1010101010101010b
        rol eax,16
        or ebx,eax ;eax=1010101010101010 1111111111110101b
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
