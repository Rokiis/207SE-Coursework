[BITS 16]
[ORG 0x7C00] ;Where the code gets mapped
top:
        mov ax,0x0000
        mov ds,ax
        mov si, name
        call writeString
        mov si, course
        call writeString
        mov si, sID
        call writeString
        mov si, game
        call writeString
        mov si,newline
        call writeString
        mov dx,5 ;Number of lines to be printed

        outer_loop:
            mov cx,5 ;Numbers of dots to put in line
            inner_loop:
                    mov si, dot
                    call writeString
                    dec cx
                    cmp cx,0
                    jne inner_loop
        mov si,newLine
        call writeString
            dec dx
            cmp dx,0
            jne outer_loop
            jmp done


writeString:
        mov ah,0x0E
        mov bh,0x00
        mov bl,0x07
nextchar:
        Lodsb
        ;;
        cmp al,0
        jz done
        int 0x10
        jmp nextchar
done:
    ret
    name db 'Rokas Navickas' ,13,10,0
    course db 'Computer Science' ,13,10,0
    sID db '7868629' ,13,10,0
    game db 'COD' ,13,10,0
    newLine db '' ,13,10,0
    newline db '' ,13,10,0
    dot db ' .' ,0
    times 510-($-$$) db 0
    dw 0xAA55   
