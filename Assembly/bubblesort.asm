org 00h

VALUES:
	mov 40h, #10
	mov 41h, #5
	mov 42h, #17
	mov 43h, #6
	mov 44h, #18
	mov 45h, #38
	mov 46h, #1
	mov 47h, #17
	mov 48h, #99
	mov 49h, #44
	mov 4Ah, #2
		

SETUP:
    mov R2, #40h
    mov R3, #0Ah
    mov R4, #0Ah
    
RESET:
    mov R2, #40h
    mov R3, #0Ah
    
BEGIN:
    djnz R3, NEXT; olha o range definido em R3
    djnz R4, RESET
	sjmp FINAL
    NEXT:
        mov A, R2
		mov R0, A
        add A, #01h
        mov R1, A
        mov R2, A
        sjmp CHECKSWAP

CHECKSWAP:
    mov A, @R0
    subb A, @R1
    jb PSW.7, FOLLOW
    sjmp SWAPIT
    FOLLOW:
        sjmp BEGIN

SWAPIT:
    mov B, @R1
	mov A, @R0
    mov @R1, A
    mov @R0, B
    sjmp FOLLOW


FINAL:
	sjmp $; finaliza o programa
    
end
