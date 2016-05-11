; prova1.asm - Eletronica 7 manha
; Codigo para fazer a contagem em um display de 7segmentos, quando a interrupcao ex0 e' ativada conta progessivamente, quando a ex1 e' ativada conta regressivamente.
; Codigo desenvolvido por:
; Caio Moreira Gomes
; Michael Barney Galindo Junior
; Otacilio Saraiva Maia Neto


valor1 equ 80
valor2 equ 100
valor3 equ 1 ; Valores para serem utilizados na rotina de Delay

org 00h
ljmp SETUP ; Inicio do codigo

org 03h
ljmp EXT0 ; Quando a externa 0 e' ativada manda pra rotina respectiva

org 0Bh
ljmp SET_DISP

org 13h
ljmp EXT1 ; Quando a externa 1 e' ativada manda para a rotina respectiva


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
	mov 3Ah, #0C0h ; numero 0 
	mov IE, #10000111b ; Habilita as interrupcoes externas
	mov P1, #0FFh ; Habilita os displays da placa
	mov R2, 01h; Inicializa a flag de contagem em 01h, para que por default, a contagem seja inicializada progressivamente caso nenhuma interrupcao seja habilitada.
	mov TMOD, #01h
	mov TH0, #HIGH(0FFFFh - 30)
	mov TL0, #LOW(0FFFFh - 30)
	setb TCON.4
	mov R1, #3Ah
	
RESET1: ; Reset da contagem das dezenas de forma progressiva
	mov R0, #2Fh ; reseta a contagem para a posicao de memoria 2fh, correspondente ao numero 0.
	
BEGIN:
	;call SET_DISP ; Chama a rotina de Set do display
	cjne R0, #3Ah, FOLLOW ; Compara se a contagem nao estourou incrementando.
	
	cjne R2, #01h, POPIT
	ljmp DEC_IT1
	
	POPIT:
	ljmp ADD_IT1 ;soma 1 ao registrador R1
	NETIT:
	ljmp RESET1 ; Caso tenha estourado a contagem, reseta a mesma.
	
	FOLLOW: ; Label para continuar a contagem caso nao tenha estourado progressivamente
		cjne R0, #2Fh, STAY ; compara se a contagem nao estourou decrementando.
		
		;ljmp DEC_IT1 ; Se a flag estiver em 00h, e' porque a contagem e' regressiva.
		
		RETFROMDEC1:
		
		ljmp RESET2 ; Caso tenha estourado a contagem, reseta a mesma. 
		STAY: ; Segunda label para continuar a contagem caso a mesma nao tenha estourado regressivamente.
			cjne R2, #01h, DEC_IT ; O registrador 2 armazena uma flag, se esta flag conter o valor 01h a contagem e' progressiva.
			ljmp ADD_IT ; Se a flag estiver em 00h, e' porque a contagem e' regressiva.
			KEEP: ; Label para chamar o delay e reiniciar o codigo.
				call DELAY ; Chama a rotina que faz esperar um determinado tempo para trocar o estado do display.
				ljmp BEGIN ; reinicia o codigo.


RESET2: ; Reset da contagem das unidades de forma regressiva
	mov R0, #39h ; reseta a contagem para a posicao de memoria 39h, correspondente ao numero 0.
	dec R1
	cjne R1, #2Fh, FFT3 ; Compara se a contagem nao estourou incrementando.
	ljmp RESET2_1
	FFT3:
	ljmp BEGIN

RESET1_1: ; Reset da contagem das unidades de forma progressiva
	mov R1, #2Fh; Inicia a contagem na posicao de memoria 2fh, correspondente ao numero 0.
	ljmp BEGIN
		
RESET2_1: ; Reset da contagem das dezenas de forma regressiva
	mov R1, #39h ; reseta a contagem para a posicao de memoria 39h, correspondente ao numero 0.
	ljmp BEGIN

DEC_IT: ; Rotina que decrementa o registrador 0, reponsavel por apontar para o respectivo numero na memoria.
	dec R0 ; Decrementa o registrador;
	ljmp KEEP ; Volta para o codigo.

ADD_IT: ; Rotina que incrementa o registrador 0, reponsavel por apontar para o respectivo numero na memoria.
	inc R0 ; Incrementa o registrador;
	ljmp KEEP ; Volta ao codigo

EXT0:
	mov R2, #01h ; Seta a flag de contagem para a forma progressiva.
	reti ; Volta para o codigo
	 
EXT1:
	mov R2, #00h ; Seta a flag de contagem para a forma regressiva
	reti

DELAY: ; Rotina que espera um determinado tempo
	mov R3, #valor1
	
	TIME:
		mov R4, #valor3
		TIME2:
		mov R5, #valor2
		djnz R5, $
		djnz R4, TIME2
		djnz R3, TIME

	ret

SET_DISP: ; Multiplexacao do display
	
	clr TCON.4
	clr TCON.5
	
	; A cada 90 ciclos de maquina inverte o display a ser mostrado. 
	mov TH0, #HIGH(0FFFFh - 90) 
	mov TL0, #LOW(0FFFFh - 90)
	
	cjne A, #01, JUST_NEXT
		mov P1, #00000001b
		mov P0, @R0
		mov A, #00
		setb TCON.4
	reti
	JUST_NEXT:
		mov P1, #00000010b
		mov P0, @R1
		mov A, #01
		setb TCON.4
	reti
	
DEC_IT1: ; Decrementa para o display das dezenas
	dec R1
	cjne R1, #2Fh, FFT1 ; Compara se a contagem nao estourou incrementando.
	ljmp RESET2_1
	FFT1:
	ljmp NETIT

ADD_IT1: ; Incrementa para o display das dezenas
	inc R1
	cjne R1, #3Ah, FFT2 ; Compara se a contagem nao estourou incrementando.
	ljmp RESET1_1
	FFT2:
		ljmp NETIT

end

