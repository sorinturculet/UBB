bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 3
    b db -123
    c db 5
    e dd -67
    x dq 78
;x-(a*b*25+c*3)/(a+b)+e; a,b,c-byte; e-doubleword
; our code starts here
segment code use32 class=code
    start:
        mov al,[a]
        cbw ;ax=a
        mov bx,ax
        mov al,[b]
        cbw 
        imul bx;dx:ax=a*b
        push dx
        push ax
        pop eax;eax=a*b
        
        mov ebx,25
        imul ebx;edx:eax=a*b*25
        mov ebx,eax;edx:ebx=a*b*25
        mov ecx,edx ;ecx:ebx=a*b*25
   
        mov al,[c]
        mov dl,3
        imul dl; ax=c*3
        cwde ;eax
        cdq ; edx:eax
        add ebx,eax
        adc ecx,edx; ecx:ebx=a*b*25+c*3
        
        mov al,[a]
        cbw;ax=a
        mov dx,ax ;cx=a
        mov al,[b];al=b
        cbw        ;ax=b
        add ax,dx;dx=a+b=-132
        cwde; eax=a+b
        
        mov edx,ecx;edx:ebx=a*b*25+c*3
        mov ecx,eax;ecx=a+b*25
        mov eax,ebx;edx:eax=a*b*25+c*3
        ;x-(a*b*25+c*3)/(a+b)+e;
        idiv ecx;eax=(a*b*25+c*3)/(a+b)
        mov ebx,[x]
        mov ecx,[x+4];ecx:ebx=x=78
        cdq; edx:eax=(a*b*25+c*3)/(a+b)
        
        sub ebx,eax
        sbb ecx,edx;ecx:ebx=x-(a*b*25+c*3)/(a+b)
        
        mov eax,[e]
        cdq         ;edx:eax=e
        add ebx,eax
        adc ecx,edx; ecx:ebx=x-(a*b*25+c*3)/(a+b)+e
        
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
