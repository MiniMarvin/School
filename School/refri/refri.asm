;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.3.0 #8604 (Dec 30 2013) (Linux)
; This file was generated Wed Jun  8 12:20:57 2016
;--------------------------------------------------------
	.module refri
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _TF2
	.globl _EXF2
	.globl _RCLK
	.globl _TCLK
	.globl _EXEN2
	.globl _TR2
	.globl _C_T2
	.globl _CP_RL2
	.globl _T2CON_7
	.globl _T2CON_6
	.globl _T2CON_5
	.globl _T2CON_4
	.globl _T2CON_3
	.globl _T2CON_2
	.globl _T2CON_1
	.globl _T2CON_0
	.globl _PT2
	.globl _ET2
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _F1
	.globl _P
	.globl _PS
	.globl _PT1
	.globl _PX1
	.globl _PT0
	.globl _PX0
	.globl _RD
	.globl _WR
	.globl _T1
	.globl _T0
	.globl _INT1
	.globl _INT0
	.globl _TXD
	.globl _RXD
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _EA
	.globl _ES
	.globl _ET1
	.globl _EX1
	.globl _ET0
	.globl _EX0
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _SM0
	.globl _SM1
	.globl _SM2
	.globl _REN
	.globl _TB8
	.globl _RB8
	.globl _TI
	.globl _RI
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _TF1
	.globl _TR1
	.globl _TF0
	.globl _TR0
	.globl _IE1
	.globl _IT1
	.globl _IE0
	.globl _IT0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _TH2
	.globl _TL2
	.globl _RCAP2H
	.globl _RCAP2L
	.globl _T2CON
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _IP
	.globl _P3
	.globl _IE
	.globl _P2
	.globl _SBUF
	.globl _SCON
	.globl _P1
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _check_PARM_1
	.globl _selectFlag
	.globl _total
	.globl _check
	.globl _config
	.globl _Delay_ms
	.globl _selectRefri
	.globl _returnMoney
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0	=	0x0080
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_P1	=	0x0090
_SCON	=	0x0098
_SBUF	=	0x0099
_P2	=	0x00a0
_IE	=	0x00a8
_P3	=	0x00b0
_IP	=	0x00b8
_PSW	=	0x00d0
_ACC	=	0x00e0
_B	=	0x00f0
_T2CON	=	0x00c8
_RCAP2L	=	0x00ca
_RCAP2H	=	0x00cb
_TL2	=	0x00cc
_TH2	=	0x00cd
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0_0	=	0x0080
_P0_1	=	0x0081
_P0_2	=	0x0082
_P0_3	=	0x0083
_P0_4	=	0x0084
_P0_5	=	0x0085
_P0_6	=	0x0086
_P0_7	=	0x0087
_IT0	=	0x0088
_IE0	=	0x0089
_IT1	=	0x008a
_IE1	=	0x008b
_TR0	=	0x008c
_TF0	=	0x008d
_TR1	=	0x008e
_TF1	=	0x008f
_P1_0	=	0x0090
_P1_1	=	0x0091
_P1_2	=	0x0092
_P1_3	=	0x0093
_P1_4	=	0x0094
_P1_5	=	0x0095
_P1_6	=	0x0096
_P1_7	=	0x0097
_RI	=	0x0098
_TI	=	0x0099
_RB8	=	0x009a
_TB8	=	0x009b
_REN	=	0x009c
_SM2	=	0x009d
_SM1	=	0x009e
_SM0	=	0x009f
_P2_0	=	0x00a0
_P2_1	=	0x00a1
_P2_2	=	0x00a2
_P2_3	=	0x00a3
_P2_4	=	0x00a4
_P2_5	=	0x00a5
_P2_6	=	0x00a6
_P2_7	=	0x00a7
_EX0	=	0x00a8
_ET0	=	0x00a9
_EX1	=	0x00aa
_ET1	=	0x00ab
_ES	=	0x00ac
_EA	=	0x00af
_P3_0	=	0x00b0
_P3_1	=	0x00b1
_P3_2	=	0x00b2
_P3_3	=	0x00b3
_P3_4	=	0x00b4
_P3_5	=	0x00b5
_P3_6	=	0x00b6
_P3_7	=	0x00b7
_RXD	=	0x00b0
_TXD	=	0x00b1
_INT0	=	0x00b2
_INT1	=	0x00b3
_T0	=	0x00b4
_T1	=	0x00b5
_WR	=	0x00b6
_RD	=	0x00b7
_PX0	=	0x00b8
_PT0	=	0x00b9
_PX1	=	0x00ba
_PT1	=	0x00bb
_PS	=	0x00bc
_P	=	0x00d0
_F1	=	0x00d1
_OV	=	0x00d2
_RS0	=	0x00d3
_RS1	=	0x00d4
_F0	=	0x00d5
_AC	=	0x00d6
_CY	=	0x00d7
_ET2	=	0x00ad
_PT2	=	0x00bd
_T2CON_0	=	0x00c8
_T2CON_1	=	0x00c9
_T2CON_2	=	0x00ca
_T2CON_3	=	0x00cb
_T2CON_4	=	0x00cc
_T2CON_5	=	0x00cd
_T2CON_6	=	0x00ce
_T2CON_7	=	0x00cf
_CP_RL2	=	0x00c8
_C_T2	=	0x00c9
_TR2	=	0x00ca
_EXEN2	=	0x00cb
_TCLK	=	0x00cc
_RCLK	=	0x00cd
_EXF2	=	0x00ce
_TF2	=	0x00cf
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_total::
	.ds 2
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG	(DATA)
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
_selectFlag::
	.ds 1
_check_PARM_1:
	.ds 1
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
;	refri.c:20: unsigned int total = 0;
	clr	a
	mov	_total,a
	mov	(_total + 1),a
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	ljmp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;	refri.c:23: void main() {
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	refri.c:24: config();
	lcall	_config
;	refri.c:27: selectFlag = 0;
	clr	_selectFlag
;	refri.c:29: while(1){
00117$:
;	refri.c:32: if(check(select)) selectFlag = 1;
	mov	c,_P2_3
	mov	_check_PARM_1,c
	lcall	_check
	jnc	00113$
	setb	_selectFlag
;	refri.c:34: while(selectFlag == 1) {
00113$:
	jnb	_selectFlag,00117$
;	refri.c:35: P2_7 = 0x00;
	clr	_P2_7
;	refri.c:37: if( check(add_25) ) total += 25;
	mov	c,_P2_0
	mov	_check_PARM_1,c
	lcall	_check
	jnc	00104$
	mov	a,#0x19
	add	a,_total
	mov	_total,a
	clr	a
	addc	a,(_total + 1)
	mov	(_total + 1),a
00104$:
;	refri.c:38: if( check(add_50) ) total += 50;
	mov	c,_P2_1
	mov	_check_PARM_1,c
	lcall	_check
	jnc	00106$
	mov	a,#0x32
	add	a,_total
	mov	_total,a
	clr	a
	addc	a,(_total + 1)
	mov	(_total + 1),a
00106$:
;	refri.c:39: if( check(add_100) ) total += 100;
	mov	c,_P2_2
	mov	_check_PARM_1,c
	lcall	_check
	jnc	00108$
	mov	a,#0x64
	add	a,_total
	mov	_total,a
	clr	a
	addc	a,(_total + 1)
	mov	(_total + 1),a
00108$:
;	refri.c:42: if( check(abortit) ) {
	mov	c,_P2_4
	mov	_check_PARM_1,c
	lcall	_check
	jnc	00110$
;	refri.c:43: returnMoney();
	lcall	_returnMoney
;	refri.c:44: total = 0;
	clr	a
	mov	_total,a
	mov	(_total + 1),a
;	refri.c:45: P2_7 = 0x01;
	setb	_P2_7
00110$:
;	refri.c:49: if(total >= 350){
	clr	c
	mov	a,_total
	subb	a,#0x5E
	mov	a,(_total + 1)
	subb	a,#0x01
	jc	00113$
;	refri.c:50: selectRefri();
	lcall	_selectRefri
	sjmp	00113$
;------------------------------------------------------------
;Allocation info for local variables in function 'check'
;------------------------------------------------------------
;	refri.c:63: bit check(bit pt) {
;	-----------------------------------------
;	 function check
;	-----------------------------------------
_check:
;	refri.c:64: if(!pt) { 
	jb	_check_PARM_1,00104$
;	refri.c:65: Delay_ms(1);
	mov	dptr,#0x0001
	lcall	_Delay_ms
;	refri.c:66: if(!pt) return 1;
	jb	_check_PARM_1,00104$
	setb	c
	ret
00104$:
;	refri.c:68: return 0;
	clr	c
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'config'
;------------------------------------------------------------
;	refri.c:75: void config() {
;	-----------------------------------------
;	 function config
;	-----------------------------------------
_config:
;	refri.c:77: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'Delay_ms'
;------------------------------------------------------------
;mytime                    Allocated to registers r6 r7 
;i                         Allocated to registers r4 r5 
;j                         Allocated to registers r2 r3 
;------------------------------------------------------------
;	refri.c:85: void Delay_ms(unsigned int mytime) {
;	-----------------------------------------
;	 function Delay_ms
;	-----------------------------------------
_Delay_ms:
	mov	r6,dpl
	mov	r7,dph
;	refri.c:87: for (i=0; i < mytime; i++)
	mov	r4,#0x00
	mov	r5,#0x00
00107$:
	clr	c
	mov	a,r4
	subb	a,r6
	mov	a,r5
	subb	a,r7
	jnc	00109$
;	refri.c:88: for (j=0; j < 1275; j++); //1ms delay
	mov	r2,#0xFB
	mov	r3,#0x04
00105$:
	dec	r2
	cjne	r2,#0xFF,00126$
	dec	r3
00126$:
	mov	a,r2
	orl	a,r3
	jnz	00105$
;	refri.c:87: for (i=0; i < mytime; i++)
	inc	r4
	cjne	r4,#0x00,00107$
	inc	r5
	sjmp	00107$
00109$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'selectRefri'
;------------------------------------------------------------
;	refri.c:95: void selectRefri() {
;	-----------------------------------------
;	 function selectRefri
;	-----------------------------------------
_selectRefri:
;	refri.c:97: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'returnMoney'
;------------------------------------------------------------
;	refri.c:103: void returnMoney() {
;	-----------------------------------------
;	 function returnMoney
;	-----------------------------------------
_returnMoney:
;	refri.c:104: P1 = 0b01010101;
	mov	_P1,#0x55
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
