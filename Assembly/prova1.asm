; prova1.asm - Eletronica 7 manha
; Codigo para fazer a contagem em um display de 7segmentos, quando a interrupcao ex0 e' ativada conta progessivamente, quando a ex1 e' ativada conta regressivamente.
; Codigo desenvolvido por:
; Caio Moreira Gomes
; Michael Barney Galindo Junior
; Otacilio Saraiva Maia Neto


valor1 equ 0
valor2 equ 0
valor3 equ 10 ; Valores para serem utilizados na rotina de Delay

org 00h
sjmp SETUP ; Inicio do codigo

org 03h
sjmp EXT0 ; Quando a externa 0 e' ativada manda pra rotina respectiva

org 0Bh

org 13h
sjmp EXT1 ; Quando a externa 1 e' ativada manda para a rotina respectiva


SETUP: ; Rotina que inicializa o codigo, coloca em ordem na memoria os respectivos numeros do display, inicializa a interrupcao e habilita o display. 
	mov 2Fh, #0C0h ; numero 0
	mov 30h, #0F9h ; numero 1
	mov 31h, #0A4h ; numero 2
	mov 32h, #0B0h ; numero 3
	mov 33h, #099h ; numero 4
	mov 34h, #092h ; numero 5
	mov 35h, #082h ; numero 6
	mov 36h, #0F8h ; numero 7
	mov 37h, #080h ; numero 8
	mov 38h, #090h ; numero 9
	mov 39h, #0C0h ; numero 0
	mov 3Ah, #0C0h
	mov IE, #10000101b
	mov P1, #0FFh
	

RESET1:
	mov R0, #30h
BEGIN:
	mov P0, @R0
	cjne R0, #3Ah, FOLLOW
	sjmp RESET1

	FOLLOW:
		cjne R0, #2Fh, STAY
		sjmp RESET2
		STAY:
			cjne R2, #01, DEC_IT
			sjmp ADD_IT
			KEEP:
				call DELAY
				sjmp BEGIN


RESET2:
	mov R0, #39h

DEC_IT:
	dec R0
	sjmp KEEP

ADD_IT:
	inc R0
	sjmp KEEP

EXT0:
	mov R2, #01h
	reti
	
EXT1:
	mov R2, #00h
	reti

DELAY:
	mov R3, #valor1
	
	TIME:
		mov R4, #valor3
		TIME2:
		mov R5, #valor2
		djnz R5, $
		djnz R4, TIME2
		djnz R3, TIME

	ret

end
