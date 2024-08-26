bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
extern printf
extern scanf
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    mesajsir db "Introduceti un sir de caractere(20 maxim):",0
    mesajn db "Introduceti un numar reprezentat pe un octet:",0
    sir resb 22
    n dd 0
    formatn db "%d",0
    formatsir db "%s",0
    sirpar times 61 db 0
    
;Se citeste de la tastatura un cuvant (sir de caractere de maxim 20 de caractere) si un numar reprezentat pe un octet. Daca numarul este impar se cere criptarea cuvantului prin adunarea la fiecare caracter a numarului citit modulo 20. Daca numarul este par se cere criptarea cuvantului prin adaugarea dupa fiecare consoana a gruparii "p"+consoana. Se cere afisarea cuvantului criptat.


segment code use32 class=code
    start:
        push mesajsir
        call[printf]
        add esp,4   ;afisam mesaj
        
        push sir
        push formatsir
        call[scanf]
        add esp,4*2 ;citim sirul
        
        push mesajn
        call[printf]
        add esp,4   ;afisam mesaj
        
        push n
        push formatn
        call[scanf]
        add esp,4*2;citim numarul
        
        mov eax,[n]
        mov cl,1
        rcr eax,cl
        jc impar
        jnc par ;verificam daca numarul este impar prin rotirea sa cu carry o pozitie la dreapta. Un nr impar => cel mai nesemnificativ bit=1
        
            impar:
            mov esi,sir
            mov eax,[n]
            mov edx,0   ;edx:eax=n
            mov ecx,20  ;ecx=20
            idiv ecx    ;edx=n%20, mai exact dl=n%20, deoarece restul este reprezentat pe un byte( 0<=rest<20)
            
                repetaimpar:
                cmp [esi],byte 0    ;verificam daca am ajuns la finalul cuvantului
                je finalimpar       ;daca da am terminat criptarea
                add [esi],byte dl   ;adaugam dl, care este n%20
                inc esi             ;incrementam sa mergem mai departe in sir
                jmp repetaimpar
            finalimpar:
            push sir
            call[printf]
            add esp,4       ;afisam textfinal
            jmp final       ;iesim din program
            
            
            par:
            mov esi,sir     ;punem in esi destinatia sirului mama
            mov edi,sirpar  ;punem in edi destinatia sirului final
            cld             ;lucram cu movsb deci dam clear la direction flag
                repetapar:
                cmp [esi],byte 0
                je finalpar     ;verificam daca am ajuns la finalul cuvantului, astfel sarim la afisare
                movsb       ;am mutat litera in cuvant
                cmp [esi-1],byte 'A'
                    je vocala
                cmp [esi-1],byte 'E'
                    je vocala
                cmp [esi-1],byte 'I'
                    je vocala
                cmp [esi-1],byte 'O'
                    je vocala
                cmp [esi-1],byte 'U'
                    je vocala
                cmp [esi-1],byte 'a'
                    je vocala
                cmp [esi-1],byte 'e'
                    je vocala
                cmp [esi-1],byte 'i'
                    je vocala
                cmp [esi-1],byte 'o'
                    je vocala
                cmp [esi-1],byte 'u'
                    je vocala          ;verificam daca suntem la o consoana, daca suntem la vocala va sari peste urm 5 instructiuni
                    
                mov [edi],byte 'p'  
                inc edi
                mov al,[esi-1]
                mov [edi],al
                inc edi            ;adaugam structura p+consoara dupa vocala
                
                vocala:
                jmp repetapar
            finalpar:
            push sirpar
            call[printf]
            add esp,4       ;afisam textfinal
            jmp final       ;iesim din program
        
        final:
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
