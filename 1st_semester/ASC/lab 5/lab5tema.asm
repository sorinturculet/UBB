bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 2, 1, 3, 3, 4, 2, 6
    la equ $-a
    b db 4, 5, 7, 6, 2, 1
    lb equ $-b
    d times la+lb db 0
;Se dau 2 siruri de octeti A si B. Sa se construiasca sirul R care sa contina elementele lui B in ordine inversa urmate de elementele impare ale lui A.
;
; our code starts here
segment code use32 class=code
    start:
        mov ecx,lb ;punem in ecx lungimea lui b pt face bucla
        mov esi,0 
        jecxz Sfarsit
        Repeta:
            mov al,[b-1+ecx] ;am calculat folosind de lungimea sirului ecx practic pozitia elementului din coada si in timp ce ecx scade vine spre inceputul sirului
            mov [d+esi],al ; mutam in d elementul
            inc esi
        loop Repeta
        Sfarsit:
        
        mov ecx,la  ; punem in ecx lungimea lui a pt a face bucla
        mov esi,0 ;folosim esi index pentru sirul nostru
        mov ebx,0; folosim ebx index pentru elementele noi din d si il incrementam doar cand adaugam in d
        jecxz Sfarsit2
        Repeta2:
            mov al,[a+esi]
            rcr al,1 ; verificam in carry flag daca al este impar/par
            jnc par   ;se pare ca al este impar deci il adaugam la d
                mov al,[a+esi]
                mov [d+lb+ebx],al
                inc ebx
           par:
           inc esi
        loop Repeta2
        Sfarsit2:
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
