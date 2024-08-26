bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fprintf, fclose,scanf
import exit msvcrt.dll  
import fopen msvcrt.dll  
import fprintf msvcrt.dll
import fclose msvcrt.dll
import scanf msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    nume_fisier db "vocile2.txt",0
    mod_acces db "w",0
    descriptor_fis dd -1
    newline db " ",0
    format db "%s",0
    cuvant db 0
   
;Se da un nume de fisier (definit in segmentul de date). Sa se creeze un fisier cu numele dat, apoi sa se citeasca de la tastatura cuvinte pana cand se citeste de la tastatura caracterul '$'. Sa se scrie in fisier doar cuvintele care contin cel putin o cifra.
; our code starts here
segment code use32 class=code
    start:
    
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp,4*2 ;cream fisierul
        
         mov [descriptor_fis], eax   ; salvam valoarea returnata de fopen in variabila descriptor_fis
        
        ; verificam daca functia fopen a creat cu succes fisierul (daca EAX != 0)
        cmp eax, 0
        je final
        
        repeta:
            push dword cuvant
            push dword format
            call [scanf]
            
            cmp byte [cuvant],'$'
                je inchidere
            mov esi,cuvant
                repeta2:
                 cmp byte[esi],0
                    je nowrite
                 cmp byte[esi],'0'
                    jb repeta2
                 cmp byte[esi],'9'
                    jbe write
                inc esi
                jmp repeta2
                
            write:
            push dword cuvant
            push dword [descriptor_fis]
            call [fprintf]
            add esp, 4*2
            
            push dword newline
            push dword [descriptor_fis]
            call [fprintf]
            add esp, 4*2
            nowrite:
     
        jmp repeta
        
        inchidere:
        ; apelam functia fclose pentru a inchide fisierul
        ; fclose(descriptor_fis)
        push dword [descriptor_fis]
        call [fclose]
        add esp, 4
        
        ; exit(0)
        final:
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
