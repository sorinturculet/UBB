bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,printf,scanf              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll                ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a dd 0
    b dd 0FFh
    format db "%d",0
    formatadunare db "a+b=%x",0
    
;Sa se citeasca de la tastatura doua numere a si b (in baza 10) si sa se calculeze a+b. Sa se afiseze rezultatul adunarii in baza 16.
; our code starts here
segment code use32 class=cod
    start:
        push dword a
        push dword format
        call [scanf]
        add esp,4*2 ; citim a
        
        push dword b
        push dword format
        call [scanf]
        add esp,4*2; citim b
        
        mov eax,0
        mov ah,0
        mov al,[a]
        mov bl,[b]
        add al,bl
        adc ah,0        ;adunam a+b in eax
        
        push dword eax  ;punem pe stiva parametrul (a+b)
        push dword formatadunare    ;punem pe stiva adresa stringului
        call [printf]   ;afisam a+b=x unde x e suma 
         add esp, 4 * 2; eliberam parametri de pe stiva
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
