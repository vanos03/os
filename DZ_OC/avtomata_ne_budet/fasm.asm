proc rc4, k, kn, d, dn
; k - ключ
; kn - размер ключа
; d - буфер
; dn - размер буфера
; ------------------------------------
    locals
        s rb 256
        v dd 256
    endl

    lea edi, [s]
    mov esi, edi

    xor ecx, ecx
    xor eax, eax
@@: stosb
    inc eax
    cmp eax, [v]
    jne @b

    xor edi, edi
@@: mov bl, byte[esi + ecx]
    add edi, ebx

    mov eax, ecx
    xor edx, edx
    mov ebx, [kn]
    div ebx

    mov eax, [k]
    mov bl, byte[eax + edx]
    add edi, ebx

    mov eax, edi
    mov ebx, [v]
    div ebx

    mov edi, edx

    mov bl, [esi + ecx]
    xchg [esi + edi], bl
    mov [esi + ecx], bl

    inc ecx
    cmp ecx, [v]
    jne @b

    xor ecx, ecx
    xor eax, eax
    xor edi, edi

@@: push eax
    inc ecx
    mov eax, ecx
    xor edx, edx
    mov ebx, [v]
    div ebx
    mov ecx, edx

    mov bl, byte[esi + ecx]
    add edi, ebx

    mov eax, edi
    mov ebx, [v]
    div ebx
    mov edi, edx

    mov bl, [esi + ecx]
    xchg [esi + edi], bl
    mov [esi + ecx], bl

    mov al, byte[esi + ecx]
    add al, byte[esi + edi]
    mov ebx, [v]
    div ebx

    mov bl, byte[esi + edx]

    pop eax
    add eax, [d]
    xor [eax], bl
    sub eax, [d]

    inc eax
    cmp eax, [dn]
    jne @b

    ret
endp
