;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.3.0 #8604 (Dec 30 2013) (Linux)
; This file was generated Wed Jun  8 11:57:16 2016
;--------------------------------------------------------
	.module glcd
	.optsdcc -mmcs51 --model-large
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _glcd_set_pixel
	.globl _glcd_init
	.globl _glcd_write_cmd
	.globl _glcd_write_data
	.globl _delay
	.globl __sdcc_external_startup
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
	.globl _P4
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
	.globl _glcd_set_pixel_PARM_3
	.globl _glcd_set_pixel_PARM_2
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
_P4	=	0x00a1
__sdcc_external_startup_AUXR_1_1	=	0x008e
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
_glcd_set_pixel_sloc0_1_0:
	.ds 2
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
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
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
_gfx_buf:
	.ds 1024
_delay_x_1_2:
	.ds 2
_glcd_write_data_dat_1_4:
	.ds 1
_glcd_write_data_maskdata_1_5:
	.ds 1
_glcd_write_cmd_cmd_1_7:
	.ds 1
_glcd_write_cmd_maskdata_1_8:
	.ds 1
_glcd_set_pixel_PARM_2:
	.ds 2
_glcd_set_pixel_PARM_3:
	.ds 2
_glcd_set_pixel_x_1_12:
	.ds 2
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
;Allocation info for local variables in function '_sdcc_external_startup'
;------------------------------------------------------------
;AUXR                      Allocated with name '__sdcc_external_startup_AUXR_1_1'
;------------------------------------------------------------
;	glcd.c:16: int _sdcc_external_startup()
;	-----------------------------------------
;	 function _sdcc_external_startup
;	-----------------------------------------
__sdcc_external_startup:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	glcd.c:19: AUXR = 0x0;
	mov	__sdcc_external_startup_AUXR_1_1,#0x00
;	glcd.c:21: return 0;
	mov	dptr,#0x0000
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'delay'
;------------------------------------------------------------
;x                         Allocated with name '_delay_x_1_2'
;n                         Allocated with name '_delay_n_1_3'
;j                         Allocated with name '_delay_j_1_3'
;------------------------------------------------------------
;	glcd.c:25: void delay(int x)
;	-----------------------------------------
;	 function delay
;	-----------------------------------------
_delay:
	mov	r7,dph
	mov	a,dpl
	mov	dptr,#_delay_x_1_2
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
;	glcd.c:28: for(n = 0; n < x; n++)
	mov	dptr,#_delay_x_1_2
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	r4,#0x00
	mov	r5,#0x00
00107$:
	clr	c
	mov	a,r4
	subb	a,r6
	mov	a,r5
	xrl	a,#0x80
	mov	b,r7
	xrl	b,#0x80
	subb	a,b
	jnc	00109$
;	glcd.c:29: for(j = 0; j <= 50; j++);
	mov	r2,#0x33
	mov	r3,#0x00
00105$:
	dec	r2
	cjne	r2,#0xFF,00126$
	dec	r3
00126$:
	mov	a,r2
	orl	a,r3
	jnz	00105$
;	glcd.c:28: for(n = 0; n < x; n++)
	inc	r4
	cjne	r4,#0x00,00107$
	inc	r5
	sjmp	00107$
00109$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'glcd_write_data'
;------------------------------------------------------------
;dat                       Allocated with name '_glcd_write_data_dat_1_4'
;maskdata                  Allocated with name '_glcd_write_data_maskdata_1_5'
;------------------------------------------------------------
;	glcd.c:33: void glcd_write_data(unsigned char dat)
;	-----------------------------------------
;	 function glcd_write_data
;	-----------------------------------------
_glcd_write_data:
	mov	a,dpl
	mov	dptr,#_glcd_write_data_dat_1_4
	movx	@dptr,a
;	glcd.c:35: unsigned char maskdata = 0x80;
	mov	dptr,#_glcd_write_data_maskdata_1_5
	mov	a,#0x80
	movx	@dptr,a
;	glcd.c:37: LCD_CS = 0;
	clr	_P2_0
;	glcd.c:38: LCD_RS = 1;
	setb	_P2_2
;	glcd.c:40: while (maskdata) {
	mov	dptr,#_glcd_write_data_dat_1_4
	movx	a,@dptr
	mov	r7,a
00104$:
	mov	dptr,#_glcd_write_data_maskdata_1_5
	movx	a,@dptr
	mov	r6,a
	jz	00106$
;	glcd.c:41: P4 = P4 & ~LCD_SCL;
	mov	r5,_P4
	mov	a,#0xFE
	anl	a,r5
	mov	_P4,a
;	glcd.c:43: if (dat & maskdata)
	mov	a,r6
	anl	a,r7
	jz	00102$
;	glcd.c:44: P4 = P4 | LCD_SDA;
	orl	_P4,#0x04
	sjmp	00103$
00102$:
;	glcd.c:46: P4 = P4 & ~LCD_SDA;
	mov	r6,_P4
	mov	a,#0xFB
	anl	a,r6
	mov	_P4,a
00103$:
;	glcd.c:48: maskdata >>= 1;
	mov	dptr,#_glcd_write_data_maskdata_1_5
	movx	a,@dptr
	clr	c
	rrc	a
	mov	dptr,#_glcd_write_data_maskdata_1_5
	movx	@dptr,a
;	glcd.c:49: delay(200);
	mov	dptr,#0x00C8
	push	ar7
	lcall	_delay
	pop	ar7
;	glcd.c:50: P4 = P4 | LCD_SCL;
	orl	_P4,#0x01
	sjmp	00104$
00106$:
;	glcd.c:53: LCD_CS = 1;
	setb	_P2_0
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'glcd_write_cmd'
;------------------------------------------------------------
;cmd                       Allocated with name '_glcd_write_cmd_cmd_1_7'
;maskdata                  Allocated with name '_glcd_write_cmd_maskdata_1_8'
;------------------------------------------------------------
;	glcd.c:57: void glcd_write_cmd(unsigned char cmd)
;	-----------------------------------------
;	 function glcd_write_cmd
;	-----------------------------------------
_glcd_write_cmd:
	mov	a,dpl
	mov	dptr,#_glcd_write_cmd_cmd_1_7
	movx	@dptr,a
;	glcd.c:59: unsigned char maskdata = 0x80;
	mov	dptr,#_glcd_write_cmd_maskdata_1_8
	mov	a,#0x80
	movx	@dptr,a
;	glcd.c:61: LCD_RS = 0;
	clr	_P2_2
;	glcd.c:62: LCD_CS = 0;
	clr	_P2_0
;	glcd.c:64: while (maskdata) {
	mov	dptr,#_glcd_write_cmd_cmd_1_7
	movx	a,@dptr
	mov	r7,a
00104$:
	mov	dptr,#_glcd_write_cmd_maskdata_1_8
	movx	a,@dptr
	mov	r6,a
	jz	00106$
;	glcd.c:66: P4 = P4 &  ~LCD_SCL;
	mov	r5,_P4
	mov	a,#0xFE
	anl	a,r5
	mov	_P4,a
;	glcd.c:68: if (cmd & maskdata)
	mov	a,r6
	anl	a,r7
	jz	00102$
;	glcd.c:69: P4 = P4 | LCD_SDA;
	orl	_P4,#0x04
	sjmp	00103$
00102$:
;	glcd.c:71: P4 = P4 & ~LCD_SDA;
	mov	r6,_P4
	mov	a,#0xFB
	anl	a,r6
	mov	_P4,a
00103$:
;	glcd.c:73: maskdata >>= 1;
	mov	dptr,#_glcd_write_cmd_maskdata_1_8
	movx	a,@dptr
	clr	c
	rrc	a
	mov	dptr,#_glcd_write_cmd_maskdata_1_8
	movx	@dptr,a
;	glcd.c:74: delay(2);
	mov	dptr,#0x0002
	push	ar7
	lcall	_delay
	pop	ar7
;	glcd.c:75: P4 = P4 | LCD_SCL ;
	orl	_P4,#0x01
	sjmp	00104$
00106$:
;	glcd.c:78: LCD_CS = 1;
	setb	_P2_0
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'glcd_init'
;------------------------------------------------------------
;	glcd.c:81: void glcd_init(void)
;	-----------------------------------------
;	 function glcd_init
;	-----------------------------------------
_glcd_init:
;	glcd.c:83: RST = 0;
	clr	_P2_5
;	glcd.c:84: delay(1000);
	mov	dptr,#0x03E8
	lcall	_delay
;	glcd.c:85: RST = 1;
	setb	_P2_5
;	glcd.c:87: glcd_write_cmd(0xE2);            // S/W RESWT
	mov	dpl,#0xE2
	lcall	_glcd_write_cmd
;	glcd.c:88: glcd_write_cmd(0xA3);            // LCD bias
	mov	dpl,#0xA3
	lcall	_glcd_write_cmd
;	glcd.c:89: glcd_write_cmd(0xAF);            // Display ON
	mov	dpl,#0xAF
	lcall	_glcd_write_cmd
;	glcd.c:90: glcd_write_cmd(0xA0);            // segment direction.
	mov	dpl,#0xA0
	lcall	_glcd_write_cmd
;	glcd.c:91: glcd_write_cmd(0xC8);            // Common Direction.
	mov	dpl,#0xC8
	lcall	_glcd_write_cmd
;	glcd.c:92: glcd_write_cmd(0x22);            // Regultion resistor select  //25
	mov	dpl,#0x22
	lcall	_glcd_write_cmd
;	glcd.c:93: glcd_write_cmd(0x81);            // EV Select.
	mov	dpl,#0x81
	lcall	_glcd_write_cmd
;	glcd.c:94: glcd_write_cmd(0x2f);            // Select EV value.
	mov	dpl,#0x2F
	lcall	_glcd_write_cmd
;	glcd.c:95: glcd_write_cmd(0x2f);            // Power control
	mov	dpl,#0x2F
	lcall	_glcd_write_cmd
;	glcd.c:98: glcd_write_cmd(0x40);            // Initial display line 40
	mov	dpl,#0x40
	lcall	_glcd_write_cmd
;	glcd.c:99: glcd_write_cmd(0xB0);            // Set page address
	mov	dpl,#0xB0
	lcall	_glcd_write_cmd
;	glcd.c:100: glcd_write_cmd(0x10);            // Set coloumn addr  MSB
	mov	dpl,#0x10
	lcall	_glcd_write_cmd
;	glcd.c:101: glcd_write_cmd(0x00);            // Set coloumn addr LSB
	mov	dpl,#0x00
	lcall	_glcd_write_cmd
;	glcd.c:102: glcd_write_cmd(0xAF);            // Display ON
	mov	dpl,#0xAF
	lcall	_glcd_write_cmd
;	glcd.c:103: glcd_write_cmd(0xA4);            // A5 .Normal display, all pixels OFF.
	mov	dpl,#0xA4
	lcall	_glcd_write_cmd
;	glcd.c:104: glcd_write_cmd(0xA6);            // A7 .Normal display (Inverse Pixel)
	mov	dpl,#0xA6
	ljmp	_glcd_write_cmd
;------------------------------------------------------------
;Allocation info for local variables in function 'glcd_set_pixel'
;------------------------------------------------------------
;sloc0                     Allocated with name '_glcd_set_pixel_sloc0_1_0'
;y                         Allocated with name '_glcd_set_pixel_PARM_2'
;color                     Allocated with name '_glcd_set_pixel_PARM_3'
;x                         Allocated with name '_glcd_set_pixel_x_1_12'
;page                      Allocated with name '_glcd_set_pixel_page_1_13'
;col                       Allocated with name '_glcd_set_pixel_col_1_13'
;row_in_page               Allocated with name '_glcd_set_pixel_row_in_page_1_13'
;------------------------------------------------------------
;	glcd.c:107: void glcd_set_pixel(int x, int y, int color)
;	-----------------------------------------
;	 function glcd_set_pixel
;	-----------------------------------------
_glcd_set_pixel:
	mov	r7,dph
	mov	a,dpl
	mov	dptr,#_glcd_set_pixel_x_1_12
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
;	glcd.c:112: page = y / 8;
	mov	dptr,#_glcd_set_pixel_PARM_2
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	dptr,#__divsint_PARM_2
	mov	a,#0x08
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
;	glcd.c:115: glcd_write_cmd(PAGE_SEL | page);
	mov	dpl,r6
	mov	dph,r7
	push	ar7
	push	ar6
	lcall	__divsint
	mov	r4,dpl
	mov	r5,dph
	mov	a,#0xB0
	orl	a,r4
	mov	r2,a
	mov	ar3,r5
	mov	dpl,r2
	push	ar5
	push	ar4
	lcall	_glcd_write_cmd
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
;	glcd.c:118: col = ((x & 0xF0) >> 4) | 0x10;
	mov	dptr,#_glcd_set_pixel_x_1_12
	movx	a,@dptr
	mov	_glcd_set_pixel_sloc0_1_0,a
	inc	dptr
	movx	a,@dptr
	mov	(_glcd_set_pixel_sloc0_1_0 + 1),a
	mov	a,#0xF0
	anl	a,_glcd_set_pixel_sloc0_1_0
	mov	r0,a
	clr	a
	mov	r1,a
	swap	a
	xch	a,r0
	swap	a
	anl	a,#0x0F
	xrl	a,r0
	xch	a,r0
	anl	a,#0x0F
	xch	a,r0
	xrl	a,r0
	xch	a,r0
	jnb	acc.3,00109$
	orl	a,#0xF0
00109$:
	mov	r1,a
	orl	ar0,#0x10
;	glcd.c:119: glcd_write_cmd(COL_SEL|col);
	mov	a,#0x10
	orl	a,r0
	mov	r2,a
	mov	ar3,r1
	mov	dpl,r2
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar1
	push	ar0
	lcall	_glcd_write_cmd
;	glcd.c:120: glcd_write_cmd(x & 0xf);
	mov	a,#0x0F
	anl	a,_glcd_set_pixel_sloc0_1_0
	mov	dpl,a
	lcall	_glcd_write_cmd
	pop	ar0
	pop	ar1
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
;	glcd.c:123: row_in_page = y % 8;
	mov	dptr,#__modsint_PARM_2
	mov	a,#0x08
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
;	glcd.c:126: if (color)
	mov	dpl,r6
	mov	dph,r7
	push	ar5
	push	ar4
	push	ar1
	push	ar0
	lcall	__modsint
	mov	r6,dpl
	mov	r7,dph
	pop	ar0
	pop	ar1
	pop	ar4
	pop	ar5
	mov	dptr,#_glcd_set_pixel_PARM_3
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	orl	a,r2
	jz	00102$
;	glcd.c:127: gfx_buf[page][col] |= 1 << row_in_page;
	mov	ar2,r4
	mov	a,r5
	anl	a,#0x01
	mov	c,acc.0
	xch	a,r2
	rrc	a
	xch	a,r2
	rrc	a
	xch	a,r2
	mov	r3,a
	mov	a,r2
	add	a,#_gfx_buf
	mov	r2,a
	mov	a,r3
	addc	a,#(_gfx_buf >> 8)
	mov	r3,a
	mov	a,r0
	add	a,r2
	mov	r2,a
	mov	a,r1
	addc	a,r3
	mov	r3,a
	push	ar0
	push	ar1
	mov	b,r6
	inc	b
	mov	_glcd_set_pixel_sloc0_1_0,#0x01
	mov	(_glcd_set_pixel_sloc0_1_0 + 1),#0x00
	sjmp	00112$
00111$:
	mov	a,_glcd_set_pixel_sloc0_1_0
	add	a,_glcd_set_pixel_sloc0_1_0
	mov	_glcd_set_pixel_sloc0_1_0,a
	mov	a,(_glcd_set_pixel_sloc0_1_0 + 1)
	rlc	a
	mov	(_glcd_set_pixel_sloc0_1_0 + 1),a
00112$:
	djnz	b,00111$
	mov	dpl,r2
	mov	dph,r3
	movx	a,@dptr
	mov	r1,a
	mov	a,_glcd_set_pixel_sloc0_1_0
	orl	ar1,a
	mov	dpl,r2
	mov	dph,r3
	mov	a,r1
	movx	@dptr,a
	pop	ar1
	pop	ar0
	sjmp	00103$
00102$:
;	glcd.c:129: gfx_buf[page][col] &= ~(1 << row_in_page);
	mov	ar2,r4
	mov	a,r5
	anl	a,#0x01
	mov	c,acc.0
	xch	a,r2
	rrc	a
	xch	a,r2
	rrc	a
	xch	a,r2
	mov	r3,a
	mov	a,r2
	add	a,#_gfx_buf
	mov	r2,a
	mov	a,r3
	addc	a,#(_gfx_buf >> 8)
	mov	r3,a
	mov	a,r0
	add	a,r2
	mov	r2,a
	mov	a,r1
	addc	a,r3
	mov	r3,a
	mov	b,r6
	inc	b
	mov	r6,#0x01
	mov	r7,#0x00
	sjmp	00114$
00113$:
	mov	a,r6
	add	a,r6
	mov	r6,a
	mov	a,r7
	rlc	a
	mov	r7,a
00114$:
	djnz	b,00113$
	mov	a,r6
	cpl	a
	mov	r6,a
	mov	dpl,r2
	mov	dph,r3
	movx	a,@dptr
	mov	r7,a
	anl	ar6,a
	mov	dpl,r2
	mov	dph,r3
	mov	a,r6
	movx	@dptr,a
00103$:
;	glcd.c:131: glcd_write_data(gfx_buf[page][col]);
	mov	a,r5
	anl	a,#0x01
	mov	c,acc.0
	xch	a,r4
	rrc	a
	xch	a,r4
	rrc	a
	xch	a,r4
	mov	r5,a
	mov	a,r4
	add	a,#_gfx_buf
	mov	r4,a
	mov	a,r5
	addc	a,#(_gfx_buf >> 8)
	mov	r5,a
	mov	a,r0
	add	a,r4
	mov	dpl,a
	mov	a,r1
	addc	a,r5
	mov	dph,a
	movx	a,@dptr
	mov	dpl,a
	ljmp	_glcd_write_data
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;i                         Allocated with name '_main_i_1_14'
;j                         Allocated with name '_main_j_1_14'
;------------------------------------------------------------
;	glcd.c:139: int main()
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	glcd.c:143: glcd_init();
	lcall	_glcd_init
;	glcd.c:145: for (i = 0; i < 128; i++)
	mov	r6,#0x00
	mov	r7,#0x00
;	glcd.c:146: for (j = 0; j < 64; j++)
00109$:
	mov	ar4,r6
	mov	ar5,r7
	mov	r2,#0x00
	mov	r3,#0x00
00103$:
;	glcd.c:147: glcd_set_pixel(i, j, 1);
	mov	dptr,#_glcd_set_pixel_PARM_2
	mov	a,r2
	movx	@dptr,a
	mov	a,r3
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_glcd_set_pixel_PARM_3
	mov	a,#0x01
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r4
	mov	dph,r5
	push	ar5
	push	ar4
	push	ar3
	push	ar2
	lcall	_glcd_set_pixel
	pop	ar2
	pop	ar3
	pop	ar4
	pop	ar5
;	glcd.c:146: for (j = 0; j < 64; j++)
	inc	r2
	cjne	r2,#0x00,00123$
	inc	r3
00123$:
	clr	c
	mov	a,r2
	subb	a,#0x40
	mov	a,r3
	xrl	a,#0x80
	subb	a,#0x80
	jc	00103$
;	glcd.c:145: for (i = 0; i < 128; i++)
	mov	a,#0x01
	add	a,r4
	mov	r6,a
	clr	a
	addc	a,r5
	mov	r7,a
	clr	c
	mov	a,r6
	subb	a,#0x80
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x80
	jc	00109$
;	glcd.c:148: return 0;
	mov	dptr,#0x0000
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
