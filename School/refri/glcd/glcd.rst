                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.3.0 #8604 (Dec 30 2013) (Linux)
                              4 ; This file was generated Wed Jun  8 11:57:16 2016
                              5 ;--------------------------------------------------------
                              6 	.module glcd
                              7 	.optsdcc -mmcs51 --model-large
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _glcd_set_pixel
                             14 	.globl _glcd_init
                             15 	.globl _glcd_write_cmd
                             16 	.globl _glcd_write_data
                             17 	.globl _delay
                             18 	.globl __sdcc_external_startup
                             19 	.globl _TF2
                             20 	.globl _EXF2
                             21 	.globl _RCLK
                             22 	.globl _TCLK
                             23 	.globl _EXEN2
                             24 	.globl _TR2
                             25 	.globl _C_T2
                             26 	.globl _CP_RL2
                             27 	.globl _T2CON_7
                             28 	.globl _T2CON_6
                             29 	.globl _T2CON_5
                             30 	.globl _T2CON_4
                             31 	.globl _T2CON_3
                             32 	.globl _T2CON_2
                             33 	.globl _T2CON_1
                             34 	.globl _T2CON_0
                             35 	.globl _PT2
                             36 	.globl _ET2
                             37 	.globl _CY
                             38 	.globl _AC
                             39 	.globl _F0
                             40 	.globl _RS1
                             41 	.globl _RS0
                             42 	.globl _OV
                             43 	.globl _F1
                             44 	.globl _P
                             45 	.globl _PS
                             46 	.globl _PT1
                             47 	.globl _PX1
                             48 	.globl _PT0
                             49 	.globl _PX0
                             50 	.globl _RD
                             51 	.globl _WR
                             52 	.globl _T1
                             53 	.globl _T0
                             54 	.globl _INT1
                             55 	.globl _INT0
                             56 	.globl _TXD
                             57 	.globl _RXD
                             58 	.globl _P3_7
                             59 	.globl _P3_6
                             60 	.globl _P3_5
                             61 	.globl _P3_4
                             62 	.globl _P3_3
                             63 	.globl _P3_2
                             64 	.globl _P3_1
                             65 	.globl _P3_0
                             66 	.globl _EA
                             67 	.globl _ES
                             68 	.globl _ET1
                             69 	.globl _EX1
                             70 	.globl _ET0
                             71 	.globl _EX0
                             72 	.globl _P2_7
                             73 	.globl _P2_6
                             74 	.globl _P2_5
                             75 	.globl _P2_4
                             76 	.globl _P2_3
                             77 	.globl _P2_2
                             78 	.globl _P2_1
                             79 	.globl _P2_0
                             80 	.globl _SM0
                             81 	.globl _SM1
                             82 	.globl _SM2
                             83 	.globl _REN
                             84 	.globl _TB8
                             85 	.globl _RB8
                             86 	.globl _TI
                             87 	.globl _RI
                             88 	.globl _P1_7
                             89 	.globl _P1_6
                             90 	.globl _P1_5
                             91 	.globl _P1_4
                             92 	.globl _P1_3
                             93 	.globl _P1_2
                             94 	.globl _P1_1
                             95 	.globl _P1_0
                             96 	.globl _TF1
                             97 	.globl _TR1
                             98 	.globl _TF0
                             99 	.globl _TR0
                            100 	.globl _IE1
                            101 	.globl _IT1
                            102 	.globl _IE0
                            103 	.globl _IT0
                            104 	.globl _P0_7
                            105 	.globl _P0_6
                            106 	.globl _P0_5
                            107 	.globl _P0_4
                            108 	.globl _P0_3
                            109 	.globl _P0_2
                            110 	.globl _P0_1
                            111 	.globl _P0_0
                            112 	.globl _P4
                            113 	.globl _TH2
                            114 	.globl _TL2
                            115 	.globl _RCAP2H
                            116 	.globl _RCAP2L
                            117 	.globl _T2CON
                            118 	.globl _B
                            119 	.globl _ACC
                            120 	.globl _PSW
                            121 	.globl _IP
                            122 	.globl _P3
                            123 	.globl _IE
                            124 	.globl _P2
                            125 	.globl _SBUF
                            126 	.globl _SCON
                            127 	.globl _P1
                            128 	.globl _TH1
                            129 	.globl _TH0
                            130 	.globl _TL1
                            131 	.globl _TL0
                            132 	.globl _TMOD
                            133 	.globl _TCON
                            134 	.globl _PCON
                            135 	.globl _DPH
                            136 	.globl _DPL
                            137 	.globl _SP
                            138 	.globl _P0
                            139 	.globl _glcd_set_pixel_PARM_3
                            140 	.globl _glcd_set_pixel_PARM_2
                            141 ;--------------------------------------------------------
                            142 ; special function registers
                            143 ;--------------------------------------------------------
                            144 	.area RSEG    (ABS,DATA)
   0000                     145 	.org 0x0000
                     0080   146 _P0	=	0x0080
                     0081   147 _SP	=	0x0081
                     0082   148 _DPL	=	0x0082
                     0083   149 _DPH	=	0x0083
                     0087   150 _PCON	=	0x0087
                     0088   151 _TCON	=	0x0088
                     0089   152 _TMOD	=	0x0089
                     008A   153 _TL0	=	0x008a
                     008B   154 _TL1	=	0x008b
                     008C   155 _TH0	=	0x008c
                     008D   156 _TH1	=	0x008d
                     0090   157 _P1	=	0x0090
                     0098   158 _SCON	=	0x0098
                     0099   159 _SBUF	=	0x0099
                     00A0   160 _P2	=	0x00a0
                     00A8   161 _IE	=	0x00a8
                     00B0   162 _P3	=	0x00b0
                     00B8   163 _IP	=	0x00b8
                     00D0   164 _PSW	=	0x00d0
                     00E0   165 _ACC	=	0x00e0
                     00F0   166 _B	=	0x00f0
                     00C8   167 _T2CON	=	0x00c8
                     00CA   168 _RCAP2L	=	0x00ca
                     00CB   169 _RCAP2H	=	0x00cb
                     00CC   170 _TL2	=	0x00cc
                     00CD   171 _TH2	=	0x00cd
                     00A1   172 _P4	=	0x00a1
                     008E   173 __sdcc_external_startup_AUXR_1_1	=	0x008e
                            174 ;--------------------------------------------------------
                            175 ; special function bits
                            176 ;--------------------------------------------------------
                            177 	.area RSEG    (ABS,DATA)
   0000                     178 	.org 0x0000
                     0080   179 _P0_0	=	0x0080
                     0081   180 _P0_1	=	0x0081
                     0082   181 _P0_2	=	0x0082
                     0083   182 _P0_3	=	0x0083
                     0084   183 _P0_4	=	0x0084
                     0085   184 _P0_5	=	0x0085
                     0086   185 _P0_6	=	0x0086
                     0087   186 _P0_7	=	0x0087
                     0088   187 _IT0	=	0x0088
                     0089   188 _IE0	=	0x0089
                     008A   189 _IT1	=	0x008a
                     008B   190 _IE1	=	0x008b
                     008C   191 _TR0	=	0x008c
                     008D   192 _TF0	=	0x008d
                     008E   193 _TR1	=	0x008e
                     008F   194 _TF1	=	0x008f
                     0090   195 _P1_0	=	0x0090
                     0091   196 _P1_1	=	0x0091
                     0092   197 _P1_2	=	0x0092
                     0093   198 _P1_3	=	0x0093
                     0094   199 _P1_4	=	0x0094
                     0095   200 _P1_5	=	0x0095
                     0096   201 _P1_6	=	0x0096
                     0097   202 _P1_7	=	0x0097
                     0098   203 _RI	=	0x0098
                     0099   204 _TI	=	0x0099
                     009A   205 _RB8	=	0x009a
                     009B   206 _TB8	=	0x009b
                     009C   207 _REN	=	0x009c
                     009D   208 _SM2	=	0x009d
                     009E   209 _SM1	=	0x009e
                     009F   210 _SM0	=	0x009f
                     00A0   211 _P2_0	=	0x00a0
                     00A1   212 _P2_1	=	0x00a1
                     00A2   213 _P2_2	=	0x00a2
                     00A3   214 _P2_3	=	0x00a3
                     00A4   215 _P2_4	=	0x00a4
                     00A5   216 _P2_5	=	0x00a5
                     00A6   217 _P2_6	=	0x00a6
                     00A7   218 _P2_7	=	0x00a7
                     00A8   219 _EX0	=	0x00a8
                     00A9   220 _ET0	=	0x00a9
                     00AA   221 _EX1	=	0x00aa
                     00AB   222 _ET1	=	0x00ab
                     00AC   223 _ES	=	0x00ac
                     00AF   224 _EA	=	0x00af
                     00B0   225 _P3_0	=	0x00b0
                     00B1   226 _P3_1	=	0x00b1
                     00B2   227 _P3_2	=	0x00b2
                     00B3   228 _P3_3	=	0x00b3
                     00B4   229 _P3_4	=	0x00b4
                     00B5   230 _P3_5	=	0x00b5
                     00B6   231 _P3_6	=	0x00b6
                     00B7   232 _P3_7	=	0x00b7
                     00B0   233 _RXD	=	0x00b0
                     00B1   234 _TXD	=	0x00b1
                     00B2   235 _INT0	=	0x00b2
                     00B3   236 _INT1	=	0x00b3
                     00B4   237 _T0	=	0x00b4
                     00B5   238 _T1	=	0x00b5
                     00B6   239 _WR	=	0x00b6
                     00B7   240 _RD	=	0x00b7
                     00B8   241 _PX0	=	0x00b8
                     00B9   242 _PT0	=	0x00b9
                     00BA   243 _PX1	=	0x00ba
                     00BB   244 _PT1	=	0x00bb
                     00BC   245 _PS	=	0x00bc
                     00D0   246 _P	=	0x00d0
                     00D1   247 _F1	=	0x00d1
                     00D2   248 _OV	=	0x00d2
                     00D3   249 _RS0	=	0x00d3
                     00D4   250 _RS1	=	0x00d4
                     00D5   251 _F0	=	0x00d5
                     00D6   252 _AC	=	0x00d6
                     00D7   253 _CY	=	0x00d7
                     00AD   254 _ET2	=	0x00ad
                     00BD   255 _PT2	=	0x00bd
                     00C8   256 _T2CON_0	=	0x00c8
                     00C9   257 _T2CON_1	=	0x00c9
                     00CA   258 _T2CON_2	=	0x00ca
                     00CB   259 _T2CON_3	=	0x00cb
                     00CC   260 _T2CON_4	=	0x00cc
                     00CD   261 _T2CON_5	=	0x00cd
                     00CE   262 _T2CON_6	=	0x00ce
                     00CF   263 _T2CON_7	=	0x00cf
                     00C8   264 _CP_RL2	=	0x00c8
                     00C9   265 _C_T2	=	0x00c9
                     00CA   266 _TR2	=	0x00ca
                     00CB   267 _EXEN2	=	0x00cb
                     00CC   268 _TCLK	=	0x00cc
                     00CD   269 _RCLK	=	0x00cd
                     00CE   270 _EXF2	=	0x00ce
                     00CF   271 _TF2	=	0x00cf
                            272 ;--------------------------------------------------------
                            273 ; overlayable register banks
                            274 ;--------------------------------------------------------
                            275 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     276 	.ds 8
                            277 ;--------------------------------------------------------
                            278 ; internal ram data
                            279 ;--------------------------------------------------------
                            280 	.area DSEG    (DATA)
   0008                     281 _glcd_set_pixel_sloc0_1_0:
   0008                     282 	.ds 2
                            283 ;--------------------------------------------------------
                            284 ; overlayable items in internal ram 
                            285 ;--------------------------------------------------------
                            286 ;--------------------------------------------------------
                            287 ; Stack segment in internal ram 
                            288 ;--------------------------------------------------------
                            289 	.area	SSEG	(DATA)
   0021                     290 __start__stack:
   0021                     291 	.ds	1
                            292 
                            293 ;--------------------------------------------------------
                            294 ; indirectly addressable internal ram data
                            295 ;--------------------------------------------------------
                            296 	.area ISEG    (DATA)
                            297 ;--------------------------------------------------------
                            298 ; absolute internal ram data
                            299 ;--------------------------------------------------------
                            300 	.area IABS    (ABS,DATA)
                            301 	.area IABS    (ABS,DATA)
                            302 ;--------------------------------------------------------
                            303 ; bit data
                            304 ;--------------------------------------------------------
                            305 	.area BSEG    (BIT)
                            306 ;--------------------------------------------------------
                            307 ; paged external ram data
                            308 ;--------------------------------------------------------
                            309 	.area PSEG    (PAG,XDATA)
                            310 ;--------------------------------------------------------
                            311 ; external ram data
                            312 ;--------------------------------------------------------
                            313 	.area XSEG    (XDATA)
   0000                     314 _gfx_buf:
   0000                     315 	.ds 1024
   0400                     316 _delay_x_1_2:
   0400                     317 	.ds 2
   0402                     318 _glcd_write_data_dat_1_4:
   0402                     319 	.ds 1
   0403                     320 _glcd_write_data_maskdata_1_5:
   0403                     321 	.ds 1
   0404                     322 _glcd_write_cmd_cmd_1_7:
   0404                     323 	.ds 1
   0405                     324 _glcd_write_cmd_maskdata_1_8:
   0405                     325 	.ds 1
   0406                     326 _glcd_set_pixel_PARM_2:
   0406                     327 	.ds 2
   0408                     328 _glcd_set_pixel_PARM_3:
   0408                     329 	.ds 2
   040A                     330 _glcd_set_pixel_x_1_12:
   040A                     331 	.ds 2
                            332 ;--------------------------------------------------------
                            333 ; absolute external ram data
                            334 ;--------------------------------------------------------
                            335 	.area XABS    (ABS,XDATA)
                            336 ;--------------------------------------------------------
                            337 ; external initialized ram data
                            338 ;--------------------------------------------------------
                            339 	.area XISEG   (XDATA)
                            340 	.area HOME    (CODE)
                            341 	.area GSINIT0 (CODE)
                            342 	.area GSINIT1 (CODE)
                            343 	.area GSINIT2 (CODE)
                            344 	.area GSINIT3 (CODE)
                            345 	.area GSINIT4 (CODE)
                            346 	.area GSINIT5 (CODE)
                            347 	.area GSINIT  (CODE)
                            348 	.area GSFINAL (CODE)
                            349 	.area CSEG    (CODE)
                            350 ;--------------------------------------------------------
                            351 ; interrupt vector 
                            352 ;--------------------------------------------------------
                            353 	.area HOME    (CODE)
   0000                     354 __interrupt_vect:
   0000 02 00 06      [24]  355 	ljmp	__sdcc_gsinit_startup
                            356 ;--------------------------------------------------------
                            357 ; global & static initialisations
                            358 ;--------------------------------------------------------
                            359 	.area HOME    (CODE)
                            360 	.area GSINIT  (CODE)
                            361 	.area GSFINAL (CODE)
                            362 	.area GSINIT  (CODE)
                            363 	.globl __sdcc_gsinit_startup
                            364 	.globl __sdcc_program_startup
                            365 	.globl __start__stack
                            366 	.globl __mcs51_genXINIT
                            367 	.globl __mcs51_genXRAMCLEAR
                            368 	.globl __mcs51_genRAMCLEAR
                            369 	.area GSFINAL (CODE)
   005F 02 00 03      [24]  370 	ljmp	__sdcc_program_startup
                            371 ;--------------------------------------------------------
                            372 ; Home
                            373 ;--------------------------------------------------------
                            374 	.area HOME    (CODE)
                            375 	.area HOME    (CODE)
   0003                     376 __sdcc_program_startup:
   0003 02 03 1E      [24]  377 	ljmp	_main
                            378 ;	return from main will return to caller
                            379 ;--------------------------------------------------------
                            380 ; code
                            381 ;--------------------------------------------------------
                            382 	.area CSEG    (CODE)
                            383 ;------------------------------------------------------------
                            384 ;Allocation info for local variables in function '_sdcc_external_startup'
                            385 ;------------------------------------------------------------
                            386 ;AUXR                      Allocated with name '__sdcc_external_startup_AUXR_1_1'
                            387 ;------------------------------------------------------------
                            388 ;	glcd.c:16: int _sdcc_external_startup()
                            389 ;	-----------------------------------------
                            390 ;	 function _sdcc_external_startup
                            391 ;	-----------------------------------------
   0062                     392 __sdcc_external_startup:
                     0007   393 	ar7 = 0x07
                     0006   394 	ar6 = 0x06
                     0005   395 	ar5 = 0x05
                     0004   396 	ar4 = 0x04
                     0003   397 	ar3 = 0x03
                     0002   398 	ar2 = 0x02
                     0001   399 	ar1 = 0x01
                     0000   400 	ar0 = 0x00
                            401 ;	glcd.c:19: AUXR = 0x0;
   0062 75 8E 00      [24]  402 	mov	__sdcc_external_startup_AUXR_1_1,#0x00
                            403 ;	glcd.c:21: return 0;
   0065 90 00 00      [24]  404 	mov	dptr,#0x0000
   0068 22            [24]  405 	ret
                            406 ;------------------------------------------------------------
                            407 ;Allocation info for local variables in function 'delay'
                            408 ;------------------------------------------------------------
                            409 ;x                         Allocated with name '_delay_x_1_2'
                            410 ;n                         Allocated with name '_delay_n_1_3'
                            411 ;j                         Allocated with name '_delay_j_1_3'
                            412 ;------------------------------------------------------------
                            413 ;	glcd.c:25: void delay(int x)
                            414 ;	-----------------------------------------
                            415 ;	 function delay
                            416 ;	-----------------------------------------
   0069                     417 _delay:
   0069 AF 83         [24]  418 	mov	r7,dph
   006B E5 82         [12]  419 	mov	a,dpl
   006D 90 04 00      [24]  420 	mov	dptr,#_delay_x_1_2
   0070 F0            [24]  421 	movx	@dptr,a
   0071 EF            [12]  422 	mov	a,r7
   0072 A3            [24]  423 	inc	dptr
   0073 F0            [24]  424 	movx	@dptr,a
                            425 ;	glcd.c:28: for(n = 0; n < x; n++)
   0074 90 04 00      [24]  426 	mov	dptr,#_delay_x_1_2
   0077 E0            [24]  427 	movx	a,@dptr
   0078 FE            [12]  428 	mov	r6,a
   0079 A3            [24]  429 	inc	dptr
   007A E0            [24]  430 	movx	a,@dptr
   007B FF            [12]  431 	mov	r7,a
   007C 7C 00         [12]  432 	mov	r4,#0x00
   007E 7D 00         [12]  433 	mov	r5,#0x00
   0080                     434 00107$:
   0080 C3            [12]  435 	clr	c
   0081 EC            [12]  436 	mov	a,r4
   0082 9E            [12]  437 	subb	a,r6
   0083 ED            [12]  438 	mov	a,r5
   0084 64 80         [12]  439 	xrl	a,#0x80
   0086 8F F0         [24]  440 	mov	b,r7
   0088 63 F0 80      [24]  441 	xrl	b,#0x80
   008B 95 F0         [12]  442 	subb	a,b
   008D 50 14         [24]  443 	jnc	00109$
                            444 ;	glcd.c:29: for(j = 0; j <= 50; j++);
   008F 7A 33         [12]  445 	mov	r2,#0x33
   0091 7B 00         [12]  446 	mov	r3,#0x00
   0093                     447 00105$:
   0093 1A            [12]  448 	dec	r2
   0094 BA FF 01      [24]  449 	cjne	r2,#0xFF,00126$
   0097 1B            [12]  450 	dec	r3
   0098                     451 00126$:
   0098 EA            [12]  452 	mov	a,r2
   0099 4B            [12]  453 	orl	a,r3
   009A 70 F7         [24]  454 	jnz	00105$
                            455 ;	glcd.c:28: for(n = 0; n < x; n++)
   009C 0C            [12]  456 	inc	r4
   009D BC 00 E0      [24]  457 	cjne	r4,#0x00,00107$
   00A0 0D            [12]  458 	inc	r5
   00A1 80 DD         [24]  459 	sjmp	00107$
   00A3                     460 00109$:
   00A3 22            [24]  461 	ret
                            462 ;------------------------------------------------------------
                            463 ;Allocation info for local variables in function 'glcd_write_data'
                            464 ;------------------------------------------------------------
                            465 ;dat                       Allocated with name '_glcd_write_data_dat_1_4'
                            466 ;maskdata                  Allocated with name '_glcd_write_data_maskdata_1_5'
                            467 ;------------------------------------------------------------
                            468 ;	glcd.c:33: void glcd_write_data(unsigned char dat)
                            469 ;	-----------------------------------------
                            470 ;	 function glcd_write_data
                            471 ;	-----------------------------------------
   00A4                     472 _glcd_write_data:
   00A4 E5 82         [12]  473 	mov	a,dpl
   00A6 90 04 02      [24]  474 	mov	dptr,#_glcd_write_data_dat_1_4
   00A9 F0            [24]  475 	movx	@dptr,a
                            476 ;	glcd.c:35: unsigned char maskdata = 0x80;
   00AA 90 04 03      [24]  477 	mov	dptr,#_glcd_write_data_maskdata_1_5
   00AD 74 80         [12]  478 	mov	a,#0x80
   00AF F0            [24]  479 	movx	@dptr,a
                            480 ;	glcd.c:37: LCD_CS = 0;
   00B0 C2 A0         [12]  481 	clr	_P2_0
                            482 ;	glcd.c:38: LCD_RS = 1;
   00B2 D2 A2         [12]  483 	setb	_P2_2
                            484 ;	glcd.c:40: while (maskdata) {
   00B4 90 04 02      [24]  485 	mov	dptr,#_glcd_write_data_dat_1_4
   00B7 E0            [24]  486 	movx	a,@dptr
   00B8 FF            [12]  487 	mov	r7,a
   00B9                     488 00104$:
   00B9 90 04 03      [24]  489 	mov	dptr,#_glcd_write_data_maskdata_1_5
   00BC E0            [24]  490 	movx	a,@dptr
   00BD FE            [12]  491 	mov	r6,a
   00BE 60 30         [24]  492 	jz	00106$
                            493 ;	glcd.c:41: P4 = P4 & ~LCD_SCL;
   00C0 AD A1         [24]  494 	mov	r5,_P4
   00C2 74 FE         [12]  495 	mov	a,#0xFE
   00C4 5D            [12]  496 	anl	a,r5
   00C5 F5 A1         [12]  497 	mov	_P4,a
                            498 ;	glcd.c:43: if (dat & maskdata)
   00C7 EE            [12]  499 	mov	a,r6
   00C8 5F            [12]  500 	anl	a,r7
   00C9 60 05         [24]  501 	jz	00102$
                            502 ;	glcd.c:44: P4 = P4 | LCD_SDA;
   00CB 43 A1 04      [24]  503 	orl	_P4,#0x04
   00CE 80 07         [24]  504 	sjmp	00103$
   00D0                     505 00102$:
                            506 ;	glcd.c:46: P4 = P4 & ~LCD_SDA;
   00D0 AE A1         [24]  507 	mov	r6,_P4
   00D2 74 FB         [12]  508 	mov	a,#0xFB
   00D4 5E            [12]  509 	anl	a,r6
   00D5 F5 A1         [12]  510 	mov	_P4,a
   00D7                     511 00103$:
                            512 ;	glcd.c:48: maskdata >>= 1;
   00D7 90 04 03      [24]  513 	mov	dptr,#_glcd_write_data_maskdata_1_5
   00DA E0            [24]  514 	movx	a,@dptr
   00DB C3            [12]  515 	clr	c
   00DC 13            [12]  516 	rrc	a
   00DD 90 04 03      [24]  517 	mov	dptr,#_glcd_write_data_maskdata_1_5
   00E0 F0            [24]  518 	movx	@dptr,a
                            519 ;	glcd.c:49: delay(200);
   00E1 90 00 C8      [24]  520 	mov	dptr,#0x00C8
   00E4 C0 07         [24]  521 	push	ar7
   00E6 12 00 69      [24]  522 	lcall	_delay
   00E9 D0 07         [24]  523 	pop	ar7
                            524 ;	glcd.c:50: P4 = P4 | LCD_SCL;
   00EB 43 A1 01      [24]  525 	orl	_P4,#0x01
   00EE 80 C9         [24]  526 	sjmp	00104$
   00F0                     527 00106$:
                            528 ;	glcd.c:53: LCD_CS = 1;
   00F0 D2 A0         [12]  529 	setb	_P2_0
   00F2 22            [24]  530 	ret
                            531 ;------------------------------------------------------------
                            532 ;Allocation info for local variables in function 'glcd_write_cmd'
                            533 ;------------------------------------------------------------
                            534 ;cmd                       Allocated with name '_glcd_write_cmd_cmd_1_7'
                            535 ;maskdata                  Allocated with name '_glcd_write_cmd_maskdata_1_8'
                            536 ;------------------------------------------------------------
                            537 ;	glcd.c:57: void glcd_write_cmd(unsigned char cmd)
                            538 ;	-----------------------------------------
                            539 ;	 function glcd_write_cmd
                            540 ;	-----------------------------------------
   00F3                     541 _glcd_write_cmd:
   00F3 E5 82         [12]  542 	mov	a,dpl
   00F5 90 04 04      [24]  543 	mov	dptr,#_glcd_write_cmd_cmd_1_7
   00F8 F0            [24]  544 	movx	@dptr,a
                            545 ;	glcd.c:59: unsigned char maskdata = 0x80;
   00F9 90 04 05      [24]  546 	mov	dptr,#_glcd_write_cmd_maskdata_1_8
   00FC 74 80         [12]  547 	mov	a,#0x80
   00FE F0            [24]  548 	movx	@dptr,a
                            549 ;	glcd.c:61: LCD_RS = 0;
   00FF C2 A2         [12]  550 	clr	_P2_2
                            551 ;	glcd.c:62: LCD_CS = 0;
   0101 C2 A0         [12]  552 	clr	_P2_0
                            553 ;	glcd.c:64: while (maskdata) {
   0103 90 04 04      [24]  554 	mov	dptr,#_glcd_write_cmd_cmd_1_7
   0106 E0            [24]  555 	movx	a,@dptr
   0107 FF            [12]  556 	mov	r7,a
   0108                     557 00104$:
   0108 90 04 05      [24]  558 	mov	dptr,#_glcd_write_cmd_maskdata_1_8
   010B E0            [24]  559 	movx	a,@dptr
   010C FE            [12]  560 	mov	r6,a
   010D 60 30         [24]  561 	jz	00106$
                            562 ;	glcd.c:66: P4 = P4 &  ~LCD_SCL;
   010F AD A1         [24]  563 	mov	r5,_P4
   0111 74 FE         [12]  564 	mov	a,#0xFE
   0113 5D            [12]  565 	anl	a,r5
   0114 F5 A1         [12]  566 	mov	_P4,a
                            567 ;	glcd.c:68: if (cmd & maskdata)
   0116 EE            [12]  568 	mov	a,r6
   0117 5F            [12]  569 	anl	a,r7
   0118 60 05         [24]  570 	jz	00102$
                            571 ;	glcd.c:69: P4 = P4 | LCD_SDA;
   011A 43 A1 04      [24]  572 	orl	_P4,#0x04
   011D 80 07         [24]  573 	sjmp	00103$
   011F                     574 00102$:
                            575 ;	glcd.c:71: P4 = P4 & ~LCD_SDA;
   011F AE A1         [24]  576 	mov	r6,_P4
   0121 74 FB         [12]  577 	mov	a,#0xFB
   0123 5E            [12]  578 	anl	a,r6
   0124 F5 A1         [12]  579 	mov	_P4,a
   0126                     580 00103$:
                            581 ;	glcd.c:73: maskdata >>= 1;
   0126 90 04 05      [24]  582 	mov	dptr,#_glcd_write_cmd_maskdata_1_8
   0129 E0            [24]  583 	movx	a,@dptr
   012A C3            [12]  584 	clr	c
   012B 13            [12]  585 	rrc	a
   012C 90 04 05      [24]  586 	mov	dptr,#_glcd_write_cmd_maskdata_1_8
   012F F0            [24]  587 	movx	@dptr,a
                            588 ;	glcd.c:74: delay(2);
   0130 90 00 02      [24]  589 	mov	dptr,#0x0002
   0133 C0 07         [24]  590 	push	ar7
   0135 12 00 69      [24]  591 	lcall	_delay
   0138 D0 07         [24]  592 	pop	ar7
                            593 ;	glcd.c:75: P4 = P4 | LCD_SCL ;
   013A 43 A1 01      [24]  594 	orl	_P4,#0x01
   013D 80 C9         [24]  595 	sjmp	00104$
   013F                     596 00106$:
                            597 ;	glcd.c:78: LCD_CS = 1;
   013F D2 A0         [12]  598 	setb	_P2_0
   0141 22            [24]  599 	ret
                            600 ;------------------------------------------------------------
                            601 ;Allocation info for local variables in function 'glcd_init'
                            602 ;------------------------------------------------------------
                            603 ;	glcd.c:81: void glcd_init(void)
                            604 ;	-----------------------------------------
                            605 ;	 function glcd_init
                            606 ;	-----------------------------------------
   0142                     607 _glcd_init:
                            608 ;	glcd.c:83: RST = 0;
   0142 C2 A5         [12]  609 	clr	_P2_5
                            610 ;	glcd.c:84: delay(1000);
   0144 90 03 E8      [24]  611 	mov	dptr,#0x03E8
   0147 12 00 69      [24]  612 	lcall	_delay
                            613 ;	glcd.c:85: RST = 1;
   014A D2 A5         [12]  614 	setb	_P2_5
                            615 ;	glcd.c:87: glcd_write_cmd(0xE2);            // S/W RESWT
   014C 75 82 E2      [24]  616 	mov	dpl,#0xE2
   014F 12 00 F3      [24]  617 	lcall	_glcd_write_cmd
                            618 ;	glcd.c:88: glcd_write_cmd(0xA3);            // LCD bias
   0152 75 82 A3      [24]  619 	mov	dpl,#0xA3
   0155 12 00 F3      [24]  620 	lcall	_glcd_write_cmd
                            621 ;	glcd.c:89: glcd_write_cmd(0xAF);            // Display ON
   0158 75 82 AF      [24]  622 	mov	dpl,#0xAF
   015B 12 00 F3      [24]  623 	lcall	_glcd_write_cmd
                            624 ;	glcd.c:90: glcd_write_cmd(0xA0);            // segment direction.
   015E 75 82 A0      [24]  625 	mov	dpl,#0xA0
   0161 12 00 F3      [24]  626 	lcall	_glcd_write_cmd
                            627 ;	glcd.c:91: glcd_write_cmd(0xC8);            // Common Direction.
   0164 75 82 C8      [24]  628 	mov	dpl,#0xC8
   0167 12 00 F3      [24]  629 	lcall	_glcd_write_cmd
                            630 ;	glcd.c:92: glcd_write_cmd(0x22);            // Regultion resistor select  //25
   016A 75 82 22      [24]  631 	mov	dpl,#0x22
   016D 12 00 F3      [24]  632 	lcall	_glcd_write_cmd
                            633 ;	glcd.c:93: glcd_write_cmd(0x81);            // EV Select.
   0170 75 82 81      [24]  634 	mov	dpl,#0x81
   0173 12 00 F3      [24]  635 	lcall	_glcd_write_cmd
                            636 ;	glcd.c:94: glcd_write_cmd(0x2f);            // Select EV value.
   0176 75 82 2F      [24]  637 	mov	dpl,#0x2F
   0179 12 00 F3      [24]  638 	lcall	_glcd_write_cmd
                            639 ;	glcd.c:95: glcd_write_cmd(0x2f);            // Power control
   017C 75 82 2F      [24]  640 	mov	dpl,#0x2F
   017F 12 00 F3      [24]  641 	lcall	_glcd_write_cmd
                            642 ;	glcd.c:98: glcd_write_cmd(0x40);            // Initial display line 40
   0182 75 82 40      [24]  643 	mov	dpl,#0x40
   0185 12 00 F3      [24]  644 	lcall	_glcd_write_cmd
                            645 ;	glcd.c:99: glcd_write_cmd(0xB0);            // Set page address
   0188 75 82 B0      [24]  646 	mov	dpl,#0xB0
   018B 12 00 F3      [24]  647 	lcall	_glcd_write_cmd
                            648 ;	glcd.c:100: glcd_write_cmd(0x10);            // Set coloumn addr  MSB
   018E 75 82 10      [24]  649 	mov	dpl,#0x10
   0191 12 00 F3      [24]  650 	lcall	_glcd_write_cmd
                            651 ;	glcd.c:101: glcd_write_cmd(0x00);            // Set coloumn addr LSB
   0194 75 82 00      [24]  652 	mov	dpl,#0x00
   0197 12 00 F3      [24]  653 	lcall	_glcd_write_cmd
                            654 ;	glcd.c:102: glcd_write_cmd(0xAF);            // Display ON
   019A 75 82 AF      [24]  655 	mov	dpl,#0xAF
   019D 12 00 F3      [24]  656 	lcall	_glcd_write_cmd
                            657 ;	glcd.c:103: glcd_write_cmd(0xA4);            // A5 .Normal display, all pixels OFF.
   01A0 75 82 A4      [24]  658 	mov	dpl,#0xA4
   01A3 12 00 F3      [24]  659 	lcall	_glcd_write_cmd
                            660 ;	glcd.c:104: glcd_write_cmd(0xA6);            // A7 .Normal display (Inverse Pixel)
   01A6 75 82 A6      [24]  661 	mov	dpl,#0xA6
   01A9 02 00 F3      [24]  662 	ljmp	_glcd_write_cmd
                            663 ;------------------------------------------------------------
                            664 ;Allocation info for local variables in function 'glcd_set_pixel'
                            665 ;------------------------------------------------------------
                            666 ;sloc0                     Allocated with name '_glcd_set_pixel_sloc0_1_0'
                            667 ;y                         Allocated with name '_glcd_set_pixel_PARM_2'
                            668 ;color                     Allocated with name '_glcd_set_pixel_PARM_3'
                            669 ;x                         Allocated with name '_glcd_set_pixel_x_1_12'
                            670 ;page                      Allocated with name '_glcd_set_pixel_page_1_13'
                            671 ;col                       Allocated with name '_glcd_set_pixel_col_1_13'
                            672 ;row_in_page               Allocated with name '_glcd_set_pixel_row_in_page_1_13'
                            673 ;------------------------------------------------------------
                            674 ;	glcd.c:107: void glcd_set_pixel(int x, int y, int color)
                            675 ;	-----------------------------------------
                            676 ;	 function glcd_set_pixel
                            677 ;	-----------------------------------------
   01AC                     678 _glcd_set_pixel:
   01AC AF 83         [24]  679 	mov	r7,dph
   01AE E5 82         [12]  680 	mov	a,dpl
   01B0 90 04 0A      [24]  681 	mov	dptr,#_glcd_set_pixel_x_1_12
   01B3 F0            [24]  682 	movx	@dptr,a
   01B4 EF            [12]  683 	mov	a,r7
   01B5 A3            [24]  684 	inc	dptr
   01B6 F0            [24]  685 	movx	@dptr,a
                            686 ;	glcd.c:112: page = y / 8;
   01B7 90 04 06      [24]  687 	mov	dptr,#_glcd_set_pixel_PARM_2
   01BA E0            [24]  688 	movx	a,@dptr
   01BB FE            [12]  689 	mov	r6,a
   01BC A3            [24]  690 	inc	dptr
   01BD E0            [24]  691 	movx	a,@dptr
   01BE FF            [12]  692 	mov	r7,a
   01BF 90 04 15      [24]  693 	mov	dptr,#__divsint_PARM_2
   01C2 74 08         [12]  694 	mov	a,#0x08
   01C4 F0            [24]  695 	movx	@dptr,a
   01C5 E4            [12]  696 	clr	a
   01C6 A3            [24]  697 	inc	dptr
   01C7 F0            [24]  698 	movx	@dptr,a
                            699 ;	glcd.c:115: glcd_write_cmd(PAGE_SEL | page);
   01C8 8E 82         [24]  700 	mov	dpl,r6
   01CA 8F 83         [24]  701 	mov	dph,r7
   01CC C0 07         [24]  702 	push	ar7
   01CE C0 06         [24]  703 	push	ar6
   01D0 12 04 91      [24]  704 	lcall	__divsint
   01D3 AC 82         [24]  705 	mov	r4,dpl
   01D5 AD 83         [24]  706 	mov	r5,dph
   01D7 74 B0         [12]  707 	mov	a,#0xB0
   01D9 4C            [12]  708 	orl	a,r4
   01DA FA            [12]  709 	mov	r2,a
   01DB 8D 03         [24]  710 	mov	ar3,r5
   01DD 8A 82         [24]  711 	mov	dpl,r2
   01DF C0 05         [24]  712 	push	ar5
   01E1 C0 04         [24]  713 	push	ar4
   01E3 12 00 F3      [24]  714 	lcall	_glcd_write_cmd
   01E6 D0 04         [24]  715 	pop	ar4
   01E8 D0 05         [24]  716 	pop	ar5
   01EA D0 06         [24]  717 	pop	ar6
   01EC D0 07         [24]  718 	pop	ar7
                            719 ;	glcd.c:118: col = ((x & 0xF0) >> 4) | 0x10;
   01EE 90 04 0A      [24]  720 	mov	dptr,#_glcd_set_pixel_x_1_12
   01F1 E0            [24]  721 	movx	a,@dptr
   01F2 F5 08         [12]  722 	mov	_glcd_set_pixel_sloc0_1_0,a
   01F4 A3            [24]  723 	inc	dptr
   01F5 E0            [24]  724 	movx	a,@dptr
   01F6 F5 09         [12]  725 	mov	(_glcd_set_pixel_sloc0_1_0 + 1),a
   01F8 74 F0         [12]  726 	mov	a,#0xF0
   01FA 55 08         [12]  727 	anl	a,_glcd_set_pixel_sloc0_1_0
   01FC F8            [12]  728 	mov	r0,a
   01FD E4            [12]  729 	clr	a
   01FE F9            [12]  730 	mov	r1,a
   01FF C4            [12]  731 	swap	a
   0200 C8            [12]  732 	xch	a,r0
   0201 C4            [12]  733 	swap	a
   0202 54 0F         [12]  734 	anl	a,#0x0F
   0204 68            [12]  735 	xrl	a,r0
   0205 C8            [12]  736 	xch	a,r0
   0206 54 0F         [12]  737 	anl	a,#0x0F
   0208 C8            [12]  738 	xch	a,r0
   0209 68            [12]  739 	xrl	a,r0
   020A C8            [12]  740 	xch	a,r0
   020B 30 E3 02      [24]  741 	jnb	acc.3,00109$
   020E 44 F0         [12]  742 	orl	a,#0xF0
   0210                     743 00109$:
   0210 F9            [12]  744 	mov	r1,a
   0211 43 00 10      [24]  745 	orl	ar0,#0x10
                            746 ;	glcd.c:119: glcd_write_cmd(COL_SEL|col);
   0214 74 10         [12]  747 	mov	a,#0x10
   0216 48            [12]  748 	orl	a,r0
   0217 FA            [12]  749 	mov	r2,a
   0218 89 03         [24]  750 	mov	ar3,r1
   021A 8A 82         [24]  751 	mov	dpl,r2
   021C C0 07         [24]  752 	push	ar7
   021E C0 06         [24]  753 	push	ar6
   0220 C0 05         [24]  754 	push	ar5
   0222 C0 04         [24]  755 	push	ar4
   0224 C0 01         [24]  756 	push	ar1
   0226 C0 00         [24]  757 	push	ar0
   0228 12 00 F3      [24]  758 	lcall	_glcd_write_cmd
                            759 ;	glcd.c:120: glcd_write_cmd(x & 0xf);
   022B 74 0F         [12]  760 	mov	a,#0x0F
   022D 55 08         [12]  761 	anl	a,_glcd_set_pixel_sloc0_1_0
   022F F5 82         [12]  762 	mov	dpl,a
   0231 12 00 F3      [24]  763 	lcall	_glcd_write_cmd
   0234 D0 00         [24]  764 	pop	ar0
   0236 D0 01         [24]  765 	pop	ar1
   0238 D0 04         [24]  766 	pop	ar4
   023A D0 05         [24]  767 	pop	ar5
   023C D0 06         [24]  768 	pop	ar6
   023E D0 07         [24]  769 	pop	ar7
                            770 ;	glcd.c:123: row_in_page = y % 8;
   0240 90 04 0C      [24]  771 	mov	dptr,#__modsint_PARM_2
   0243 74 08         [12]  772 	mov	a,#0x08
   0245 F0            [24]  773 	movx	@dptr,a
   0246 E4            [12]  774 	clr	a
   0247 A3            [24]  775 	inc	dptr
   0248 F0            [24]  776 	movx	@dptr,a
                            777 ;	glcd.c:126: if (color)
   0249 8E 82         [24]  778 	mov	dpl,r6
   024B 8F 83         [24]  779 	mov	dph,r7
   024D C0 05         [24]  780 	push	ar5
   024F C0 04         [24]  781 	push	ar4
   0251 C0 01         [24]  782 	push	ar1
   0253 C0 00         [24]  783 	push	ar0
   0255 12 03 7B      [24]  784 	lcall	__modsint
   0258 AE 82         [24]  785 	mov	r6,dpl
   025A AF 83         [24]  786 	mov	r7,dph
   025C D0 00         [24]  787 	pop	ar0
   025E D0 01         [24]  788 	pop	ar1
   0260 D0 04         [24]  789 	pop	ar4
   0262 D0 05         [24]  790 	pop	ar5
   0264 90 04 08      [24]  791 	mov	dptr,#_glcd_set_pixel_PARM_3
   0267 E0            [24]  792 	movx	a,@dptr
   0268 FA            [12]  793 	mov	r2,a
   0269 A3            [24]  794 	inc	dptr
   026A E0            [24]  795 	movx	a,@dptr
   026B FB            [12]  796 	mov	r3,a
   026C 4A            [12]  797 	orl	a,r2
   026D 60 4F         [24]  798 	jz	00102$
                            799 ;	glcd.c:127: gfx_buf[page][col] |= 1 << row_in_page;
   026F 8C 02         [24]  800 	mov	ar2,r4
   0271 ED            [12]  801 	mov	a,r5
   0272 54 01         [12]  802 	anl	a,#0x01
   0274 A2 E0         [12]  803 	mov	c,acc.0
   0276 CA            [12]  804 	xch	a,r2
   0277 13            [12]  805 	rrc	a
   0278 CA            [12]  806 	xch	a,r2
   0279 13            [12]  807 	rrc	a
   027A CA            [12]  808 	xch	a,r2
   027B FB            [12]  809 	mov	r3,a
   027C EA            [12]  810 	mov	a,r2
   027D 24 00         [12]  811 	add	a,#_gfx_buf
   027F FA            [12]  812 	mov	r2,a
   0280 EB            [12]  813 	mov	a,r3
   0281 34 00         [12]  814 	addc	a,#(_gfx_buf >> 8)
   0283 FB            [12]  815 	mov	r3,a
   0284 E8            [12]  816 	mov	a,r0
   0285 2A            [12]  817 	add	a,r2
   0286 FA            [12]  818 	mov	r2,a
   0287 E9            [12]  819 	mov	a,r1
   0288 3B            [12]  820 	addc	a,r3
   0289 FB            [12]  821 	mov	r3,a
   028A C0 00         [24]  822 	push	ar0
   028C C0 01         [24]  823 	push	ar1
   028E 8E F0         [24]  824 	mov	b,r6
   0290 05 F0         [12]  825 	inc	b
   0292 75 08 01      [24]  826 	mov	_glcd_set_pixel_sloc0_1_0,#0x01
   0295 75 09 00      [24]  827 	mov	(_glcd_set_pixel_sloc0_1_0 + 1),#0x00
   0298 80 0B         [24]  828 	sjmp	00112$
   029A                     829 00111$:
   029A E5 08         [12]  830 	mov	a,_glcd_set_pixel_sloc0_1_0
   029C 25 08         [12]  831 	add	a,_glcd_set_pixel_sloc0_1_0
   029E F5 08         [12]  832 	mov	_glcd_set_pixel_sloc0_1_0,a
   02A0 E5 09         [12]  833 	mov	a,(_glcd_set_pixel_sloc0_1_0 + 1)
   02A2 33            [12]  834 	rlc	a
   02A3 F5 09         [12]  835 	mov	(_glcd_set_pixel_sloc0_1_0 + 1),a
   02A5                     836 00112$:
   02A5 D5 F0 F2      [24]  837 	djnz	b,00111$
   02A8 8A 82         [24]  838 	mov	dpl,r2
   02AA 8B 83         [24]  839 	mov	dph,r3
   02AC E0            [24]  840 	movx	a,@dptr
   02AD F9            [12]  841 	mov	r1,a
   02AE E5 08         [12]  842 	mov	a,_glcd_set_pixel_sloc0_1_0
   02B0 42 01         [12]  843 	orl	ar1,a
   02B2 8A 82         [24]  844 	mov	dpl,r2
   02B4 8B 83         [24]  845 	mov	dph,r3
   02B6 E9            [12]  846 	mov	a,r1
   02B7 F0            [24]  847 	movx	@dptr,a
   02B8 D0 01         [24]  848 	pop	ar1
   02BA D0 00         [24]  849 	pop	ar0
   02BC 80 3F         [24]  850 	sjmp	00103$
   02BE                     851 00102$:
                            852 ;	glcd.c:129: gfx_buf[page][col] &= ~(1 << row_in_page);
   02BE 8C 02         [24]  853 	mov	ar2,r4
   02C0 ED            [12]  854 	mov	a,r5
   02C1 54 01         [12]  855 	anl	a,#0x01
   02C3 A2 E0         [12]  856 	mov	c,acc.0
   02C5 CA            [12]  857 	xch	a,r2
   02C6 13            [12]  858 	rrc	a
   02C7 CA            [12]  859 	xch	a,r2
   02C8 13            [12]  860 	rrc	a
   02C9 CA            [12]  861 	xch	a,r2
   02CA FB            [12]  862 	mov	r3,a
   02CB EA            [12]  863 	mov	a,r2
   02CC 24 00         [12]  864 	add	a,#_gfx_buf
   02CE FA            [12]  865 	mov	r2,a
   02CF EB            [12]  866 	mov	a,r3
   02D0 34 00         [12]  867 	addc	a,#(_gfx_buf >> 8)
   02D2 FB            [12]  868 	mov	r3,a
   02D3 E8            [12]  869 	mov	a,r0
   02D4 2A            [12]  870 	add	a,r2
   02D5 FA            [12]  871 	mov	r2,a
   02D6 E9            [12]  872 	mov	a,r1
   02D7 3B            [12]  873 	addc	a,r3
   02D8 FB            [12]  874 	mov	r3,a
   02D9 8E F0         [24]  875 	mov	b,r6
   02DB 05 F0         [12]  876 	inc	b
   02DD 7E 01         [12]  877 	mov	r6,#0x01
   02DF 7F 00         [12]  878 	mov	r7,#0x00
   02E1 80 06         [24]  879 	sjmp	00114$
   02E3                     880 00113$:
   02E3 EE            [12]  881 	mov	a,r6
   02E4 2E            [12]  882 	add	a,r6
   02E5 FE            [12]  883 	mov	r6,a
   02E6 EF            [12]  884 	mov	a,r7
   02E7 33            [12]  885 	rlc	a
   02E8 FF            [12]  886 	mov	r7,a
   02E9                     887 00114$:
   02E9 D5 F0 F7      [24]  888 	djnz	b,00113$
   02EC EE            [12]  889 	mov	a,r6
   02ED F4            [12]  890 	cpl	a
   02EE FE            [12]  891 	mov	r6,a
   02EF 8A 82         [24]  892 	mov	dpl,r2
   02F1 8B 83         [24]  893 	mov	dph,r3
   02F3 E0            [24]  894 	movx	a,@dptr
   02F4 FF            [12]  895 	mov	r7,a
   02F5 52 06         [12]  896 	anl	ar6,a
   02F7 8A 82         [24]  897 	mov	dpl,r2
   02F9 8B 83         [24]  898 	mov	dph,r3
   02FB EE            [12]  899 	mov	a,r6
   02FC F0            [24]  900 	movx	@dptr,a
   02FD                     901 00103$:
                            902 ;	glcd.c:131: glcd_write_data(gfx_buf[page][col]);
   02FD ED            [12]  903 	mov	a,r5
   02FE 54 01         [12]  904 	anl	a,#0x01
   0300 A2 E0         [12]  905 	mov	c,acc.0
   0302 CC            [12]  906 	xch	a,r4
   0303 13            [12]  907 	rrc	a
   0304 CC            [12]  908 	xch	a,r4
   0305 13            [12]  909 	rrc	a
   0306 CC            [12]  910 	xch	a,r4
   0307 FD            [12]  911 	mov	r5,a
   0308 EC            [12]  912 	mov	a,r4
   0309 24 00         [12]  913 	add	a,#_gfx_buf
   030B FC            [12]  914 	mov	r4,a
   030C ED            [12]  915 	mov	a,r5
   030D 34 00         [12]  916 	addc	a,#(_gfx_buf >> 8)
   030F FD            [12]  917 	mov	r5,a
   0310 E8            [12]  918 	mov	a,r0
   0311 2C            [12]  919 	add	a,r4
   0312 F5 82         [12]  920 	mov	dpl,a
   0314 E9            [12]  921 	mov	a,r1
   0315 3D            [12]  922 	addc	a,r5
   0316 F5 83         [12]  923 	mov	dph,a
   0318 E0            [24]  924 	movx	a,@dptr
   0319 F5 82         [12]  925 	mov	dpl,a
   031B 02 00 A4      [24]  926 	ljmp	_glcd_write_data
                            927 ;------------------------------------------------------------
                            928 ;Allocation info for local variables in function 'main'
                            929 ;------------------------------------------------------------
                            930 ;i                         Allocated with name '_main_i_1_14'
                            931 ;j                         Allocated with name '_main_j_1_14'
                            932 ;------------------------------------------------------------
                            933 ;	glcd.c:139: int main()
                            934 ;	-----------------------------------------
                            935 ;	 function main
                            936 ;	-----------------------------------------
   031E                     937 _main:
                            938 ;	glcd.c:143: glcd_init();
   031E 12 01 42      [24]  939 	lcall	_glcd_init
                            940 ;	glcd.c:145: for (i = 0; i < 128; i++)
   0321 7E 00         [12]  941 	mov	r6,#0x00
   0323 7F 00         [12]  942 	mov	r7,#0x00
                            943 ;	glcd.c:146: for (j = 0; j < 64; j++)
   0325                     944 00109$:
   0325 8E 04         [24]  945 	mov	ar4,r6
   0327 8F 05         [24]  946 	mov	ar5,r7
   0329 7A 00         [12]  947 	mov	r2,#0x00
   032B 7B 00         [12]  948 	mov	r3,#0x00
   032D                     949 00103$:
                            950 ;	glcd.c:147: glcd_set_pixel(i, j, 1);
   032D 90 04 06      [24]  951 	mov	dptr,#_glcd_set_pixel_PARM_2
   0330 EA            [12]  952 	mov	a,r2
   0331 F0            [24]  953 	movx	@dptr,a
   0332 EB            [12]  954 	mov	a,r3
   0333 A3            [24]  955 	inc	dptr
   0334 F0            [24]  956 	movx	@dptr,a
   0335 90 04 08      [24]  957 	mov	dptr,#_glcd_set_pixel_PARM_3
   0338 74 01         [12]  958 	mov	a,#0x01
   033A F0            [24]  959 	movx	@dptr,a
   033B E4            [12]  960 	clr	a
   033C A3            [24]  961 	inc	dptr
   033D F0            [24]  962 	movx	@dptr,a
   033E 8C 82         [24]  963 	mov	dpl,r4
   0340 8D 83         [24]  964 	mov	dph,r5
   0342 C0 05         [24]  965 	push	ar5
   0344 C0 04         [24]  966 	push	ar4
   0346 C0 03         [24]  967 	push	ar3
   0348 C0 02         [24]  968 	push	ar2
   034A 12 01 AC      [24]  969 	lcall	_glcd_set_pixel
   034D D0 02         [24]  970 	pop	ar2
   034F D0 03         [24]  971 	pop	ar3
   0351 D0 04         [24]  972 	pop	ar4
   0353 D0 05         [24]  973 	pop	ar5
                            974 ;	glcd.c:146: for (j = 0; j < 64; j++)
   0355 0A            [12]  975 	inc	r2
   0356 BA 00 01      [24]  976 	cjne	r2,#0x00,00123$
   0359 0B            [12]  977 	inc	r3
   035A                     978 00123$:
   035A C3            [12]  979 	clr	c
   035B EA            [12]  980 	mov	a,r2
   035C 94 40         [12]  981 	subb	a,#0x40
   035E EB            [12]  982 	mov	a,r3
   035F 64 80         [12]  983 	xrl	a,#0x80
   0361 94 80         [12]  984 	subb	a,#0x80
   0363 40 C8         [24]  985 	jc	00103$
                            986 ;	glcd.c:145: for (i = 0; i < 128; i++)
   0365 74 01         [12]  987 	mov	a,#0x01
   0367 2C            [12]  988 	add	a,r4
   0368 FE            [12]  989 	mov	r6,a
   0369 E4            [12]  990 	clr	a
   036A 3D            [12]  991 	addc	a,r5
   036B FF            [12]  992 	mov	r7,a
   036C C3            [12]  993 	clr	c
   036D EE            [12]  994 	mov	a,r6
   036E 94 80         [12]  995 	subb	a,#0x80
   0370 EF            [12]  996 	mov	a,r7
   0371 64 80         [12]  997 	xrl	a,#0x80
   0373 94 80         [12]  998 	subb	a,#0x80
   0375 40 AE         [24]  999 	jc	00109$
                           1000 ;	glcd.c:148: return 0;
   0377 90 00 00      [24] 1001 	mov	dptr,#0x0000
   037A 22            [24] 1002 	ret
                           1003 	.area CSEG    (CODE)
                           1004 	.area CONST   (CODE)
                           1005 	.area XINIT   (CODE)
                           1006 	.area CABS    (ABS,CODE)
