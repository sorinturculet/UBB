%ifndef __functie__
%define __functie__

    extern scanf
    import scanf msvcrt.dll
    citirecuvant:
         mov eax,[esp+8];textfinal
         mov ebx,[esp+12];text
         mov ecx,[esp+4];formats
         mov edi,eax
         citire:
            pushad
            
            push dword ebx
            push dword ecx
            call[scanf]
            add esp,4*2 ;citim primul cuvant
            
            popad
            
            mov esi,ebx
            
            push ecx
            
            mov ecx,0
            finalesi:
            inc ecx,
                inc esi
                cmp [esi],byte 0
                jnz finalesi
            dec esi; in momentul acesta esi arata inspre ultima litera a cuvantului, si ecx numarul de litere
            
            cmp [esi],byte '.'
            jnz repeta
                dec ecx
                dec esi
                mov edx,'.'; daca suntem la ultimul cuvant ii dam lui edx '.'
            
            repeta:
                std
                lodsb
                mov [edi],al
                inc edi
            loop repeta
            
            mov [edi],byte ' '
            inc edi
            
            
            pop ecx
            cmp edx,'.'
            jnz citire
            
    ret 12
%endif