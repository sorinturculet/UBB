bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fclose,fprintf
import exit msvcrt.dll  
import fopen msvcrt.dll  
import fclose msvcrt.dll
import fprintf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
   nume_fisier db "vocile.txt",0
   mod_acces db "w", 0          ; modul de deschidere a fisierului - 
                                 ; w - pentru scriere. daca fiserul nu exista, se va crea                                   
    descriptor_fis dd -1         ; variabila in care vom salva descriptorul fisierului - necesar pentru a putea face referire la fisier
   
   format db "%s",0
   
   text db "AvbMi?.mdw(24?/)*",0
   len db $-text-1
;Se dau un nume de fisier si un text (definite in segmentul de date). Textul contine litere mici, litere mari, cifre si caractere speciale. Sa se inlocuiasca toate caracterele speciale din textul dat cu caracterul 'X'. Sa se creeze un fisier cu numele dat si sa se scrie textul obtinut in fisier.
; our code starts here
segment code use32 class=code
    start:
        ; apelam fopen pentru a crea fisierul
        ; functia va returna in EAX descriptorul fisierului sau 0 in caz de eroare
        ; eax = fopen(nume_fisier, mod_acces)
        push dword mod_acces     
        push dword nume_fisier
        call [fopen]
        add esp,4*2
        
        mov [descriptor_fis], eax
        ; verificam daca functia fopen a creat cu succes fisierul (daca EAX != 0)
        cmp eax, 0
        je final
        
        mov ecx,[len]
        mov esi,text
        mov edi,text
        repeta:
            lodsb
            cmp al,'0'
                jb change
            cmp al,'9'
                jbe nochange
            cmp al,'A'
                jb change
            cmp al,'Z'
                jbe nochange
            cmp al,'a'
                jb change
            cmp al,'z'
                jb nochange
            jb change
        change:
            mov al,'X'
        nochange:
            stosb
        loop repeta
        
        ; apelam functia fclose pentru a inchide fisierul
        ; fclose(descriptor_fis)
        push text
        push dword [descriptor_fis]
        call [fprintf]
        add esp,4*1
        
        push dword [descriptor_fis]
        call [fclose]
        add esp, 4
        
        
        ; exit(0)
        final:
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
