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
    b db 135
    c db 5
    e dd 67
    x dq 78
;x-(a*b*25+c*3)/(a+b)+e; a,b,c-byte; e-doubleword
; our code starts here
segment code use32 class=code
    start:
        mov eax,0; eax=0
        mov al,[a];al=a
        mov bl,[b]; bl=b
        mul bl ;ax=b*a
        
        mov bx,25
        mul bx ; dx:ax=a*b*25
        mov bx,ax; dx:bx=a*b*25
        
        mov al,[c]
        mov bl,3
        mul bl  ;ax=c*3
        
        mov cx,ax;cx=c*3
        mov ax,bx;dx:ax=a*b*25
        
        add ax,cx
        adc dx,0    ;dx:ax=(a*b*25+c*3)
        
        mov cl,[a]
        add cl,[b]
        adc ch,0;cx=a+b
        
        div cx;ax=(a*b*25+c*3)/(a+b)
        mov ecx,0
        mov cx,ax;ecx=(a*b*25+c*3)/(a+b)

        mov eax,[x]
        mov edx,[x+4];edx:eax=x
        
        sub eax,ecx
        sbb edx,0;;edx:eax=x-(a*b*25+c*3)/(a+b)
        
        mov ecx,[e];ecx=e
        add eax,ecx
        adc edx,0; edx:eax=x-(a*b*25+c*3)/(a+b)+e
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
