org 00h

SETUP:
    mov R2, #80h
    mov R3, #0Ah
    mov R4, #0Ah
    
RESET:
    mov R2, #80h
    mov R3, #0Ah
    
BEGIN:
    djnz R3, NEXT; olha o range definido em R3
    djnz R4, RESET
    sjmp $; finaliza o programa
    NEXT:
        mov R0, @R2
        mov A, R2
        add A, #01h
        mov R1, A
        mov R2, A
        sjmp CHECKSWAP

CHECKSWAP:
    mov A, @R0
    subb A, @R1
    jb FOLLOW, C
    sjmp SWAPIT
    FOLLOW:
        sjmp BEGIN

SWAPIT:
    mov B, @R1
    mov @R1, R0
    mov @R0, B
    sjmp FOLLOW
    
end