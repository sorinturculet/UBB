bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    sir DD 12345607h, 1A2B3C15h
    ls equ ($-sir)
    d times ls db 0
;Se da un sir S de dublucuvinte.
;Sa se obtina sirul D format din octetii dublucuvintelor din sirul D sortati in ordine descrescatoare in interpretarea fara semn.

; our code starts here
segment code use32 class=code
    start:
        mov esi,sir
        mov edi,d
        mov ecx,ls
        cld; mergem de la stanga la dreapta
        repeta:
            movsb
        loop repeta
        ;am mutat octetii din sirul sursa in sirul destinatie
        
        mov esi,0;i
        mov edi,1;j
        transf: ;for i, for j cu comparatie
            mov dl,[d+esi];mutam in dl termenul i
            mov dh,[d+edi];mutam in dh termenul j
            cmp dl,dh   ; comparam i si j
            jb maimic
                mov [d+esi],dh  ;schimbam elementele daca j este mai mare decat i
                mov [d+edi],dl
            maimic:
            
            inc edi     ;incrementam j
            cmp edi,ls  ;verificam daca j este mai mare decat ls(lungimea sirului)
            jz incrementare2
                jmp finalloop   ;daca este mai mare inseamna ca trebuie sa iteram i ul si sa readucem j ul la valoarea i+1
            incrementare2:
                inc esi
                mov edi,esi     ;facem ce am zis in comentariul de mai sus
                inc edi
            finalloop:
            cmp esi,ls-1    ;verificam daca i ul a ajuns la maxim(ls) si in caz pozitiv iesim din bucla (stoploop)
            jz stoploop
        jmp transf  ;reluam bucla
        
        stoploop:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
