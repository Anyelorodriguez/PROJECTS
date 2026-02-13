
.syntax unified
			.text
			.global primero
			
			.thumb_func

#define 	CONT	0x20000000


primero:		
			PUSH	{LR}
			MOV		R11,	R0
			MOV		R9,		R1
			MOV		R10,	R2
			MOV		R12,	R3
						
			LDR		R0, [R12]
			CMP		R0, #0x01
			BEQ		HORARIO
			CMP		R0, #0x02
			BEQ		ANTIHORARIO
			CMP		R0, #0x04
			BEQ.W	PAUSA
			CMP		R0, #0x08
			BEQ.W	INICIO
			B		INICIO
			

HORARIO:
			
			LDR 	R1, =CONT
			LDR		R0, [R1]
			CMP		R0,#12
			BEQ		REINICIO
			BL		DISPLAY
			LDR 	R1, =CONT
			LDR		R0, [R1]
			ADD		R0,#1
			STR 	R0, [R1]
			
			MOV		R0, #100
			BL		DELAY_MS
			
			
			LDR		R0, [R12]
			CMP		R0, #0x01
			BEQ		HORARIO
			CMP		R0, #0x02
			BEQ		ANTIHORARIO
			CMP		R0, #0x04
			BEQ.W	PAUSA
			CMP		R0, #0x08
			BEQ.W	INICIO
			B		HORARIO

ANTIHORARIO:
			
			LDR 	R1, =CONT
			LDR		R0, [R1]
			CMP		R0,#-1
			BEQ		REINICIO2
			BL		DISPLAY
			LDR 	R1, =CONT
			LDR		R0, [R1]
			SUB		R0,#1
			STR 	R0, [R1]
			
			MOV		R0, #100
			BL		DELAY_MS
			
			
			
			LDR		R0, [R12]
			CMP		R0, #0x01
			BEQ		HORARIO
			CMP		R0, #0x02
			BEQ		ANTIHORARIO
			CMP		R0, #0x04
			BEQ.W	PAUSA
			CMP		R0, #0x08
			BEQ.W	INICIO
			B		ANTIHORARIO
			
PAUSA:
			LDR 	R1, =CONT
			LDR		R0, [R1]
			BL		DISPLAY
			MOV		R0, #100
			BL		DELAY_MS
			
			LDR		R0, [R12]
			CMP		R0, #0x01
			BEQ		HORARIO
			CMP		R0, #0x02
			BEQ		ANTIHORARIO
			CMP		R0, #0x04
			BEQ.W	PAUSA
			CMP		R0, #0x08
			BEQ.W	INICIO
			B		PAUSA
INICIO:
			MOV		R0,	#0
			LDR 	R1, =CONT 
			STR 	R0, [R1]
			BL		DISPLAY
			MOV		R0, #100
			BL		DELAY_MS
			
			LDR		R0, [R12]
			CMP		R0, #0x01
			BEQ		HORARIO
			CMP		R0, #0x02
			BEQ		ANTIHORARIO
			CMP		R0, #0x04
			BEQ.W	PAUSA
			CMP		R0, #0x08
			BEQ.W	INICIO
			B		INICIO




DISPLAY:	CMP 	R0, #0x00 
			BEQ 	SEG0
			CMP 	R0, #0x01
			BEQ 	SEG1
			CMP 	R0, #0x02
			BEQ 	SEG2
			CMP 	R0, #0x03
			BEQ 	SEG3
			CMP 	R0, #0x04
			BEQ 	SEG4
			CMP 	R0, #0x05
			BEQ 	SEG5
			CMP 	R0, #0x06
			BEQ 	SEG6
			CMP 	R0, #0x07
			BEQ 	SEG7
			CMP 	R0, #0x08
			BEQ 	SEG8
			CMP 	R0, #0x09
			BEQ 	SEG9  
			CMP 	R0, #0x0A
			BEQ 	SEG10
			CMP 	R0, #0x0B
			BEQ 	SEG11
			
			BX		LR

SEG0:		
			MOV		R0,	#0x00	/*APAGA DISPLAY 3-4*/
			STR 	R0, [R11]
			MOV		R0,	#0x80	/*ENCIENDE DISPLAY 1*/
			STR 	R0, [R9]
			
			MOV		R1, #0xFE
			STR 	R1, [R10]               
			BX		LR
SEG1:		
			MOV		R0,	#0x00	/*APAGA DISPLAY 3-4*/
			STR 	R0, [R11]
			MOV		R0,	#0x40	/*ENCIENDE DISPLAY 2*/
			STR 	R0, [R9]
			
			MOV		R1, #0xFE
			STR 	R1, [R10]               
			BX		LR

SEG2:		
			MOV		R0,	#0x00	/*APAGA DISPLAY 1-2*/
			STR 	R0, [R9]
			MOV		R0,	#0x20	/*ENCIENDE DISPLAY 3*/
			STR 	R0, [R11]
			
			
			MOV		R1, #0xFE
			STR 	R1, [R10]               
			BX		LR
SEG3:		
			MOV		R0,	#0x00	/*APAGA DISPLAY 1-2*/
			STR 	R0, [R9]
			MOV		R0,	#0x10	/*ENCIENDE DISPLAY 4*/
			STR 	R0, [R11]
			
			MOV		R1, #0xFE
			STR 	R1, [R10]               
			BX		LR
SEG4:		
			MOV		R0,	#0x00	/*APAGA DISPLAY 1-2*/
			STR 	R0, [R9]
			MOV		R0,	#0x10	/*ENCIENDE DISPLAY 4*/
			STR 	R0, [R11]
			
			MOV		R1, #0xFD
			STR 	R1, [R10]               
			BX		LR

SEG5:		
			MOV		R0,	#0x00	/*APAGA DISPLAY 1-2*/
			STR 	R0, [R9]
			MOV		R0,	#0x10	/*ENCIENDE DISPLAY 4*/
			STR 	R0, [R11]
			
			MOV		R1, #0xFB
			STR 	R1, [R10]               
			BX		LR
SEG6:		
			MOV		R0,	#0x00	/*APAGA DISPLAY 1-2*/
			STR 	R0, [R9]
			MOV		R0,	#0x10	/*ENCIENDE DISPLAY 4*/
			STR 	R0, [R11]

			MOV		R1, #0xF7
			STR 	R1, [R10]               
			BX		LR
			
SEG7:		
			MOV		R0,	#0x00	/*APAGA DISPLAY 1-2*/
			STR 	R0, [R9]
			MOV		R0,	#0x20	/*ENCIENDE DISPLAY 3*/
			STR 	R0, [R11]
			
			MOV		R1, #0xF7
			STR 	R1, [R10]               
			BX		LR
	
SEG8:		
			MOV		R0,	#0x00	/*APAGA DISPLAY 3-4*/
			STR 	R0, [R11]
			MOV		R0,	#0x40	/*ENCIENDE DISPLAY 2*/
			STR 	R0, [R9]
			
			MOV		R1, #0xF7
			STR 	R1, [R10]               
			BX		LR

SEG9:		
			
			MOV		R0,	#0x00	/*APAGA DISPLAY 3-4*/
			STR 	R0, [R11]
			MOV		R0,	#0x80	/*ENCIENDE DISPLAY 1*/
			STR 	R0, [R9]
			
			MOV		R1, #0xF7
			STR 	R1, [R10]               
			BX		LR

SEG10:		
			
			MOV		R0,	#0x00	/*APAGA DISPLAY 3-4*/
			STR 	R0, [R11]
			MOV		R0,	#0x80	/*ENCIENDE DISPLAY 1*/
			STR 	R0, [R9]
			
			MOV		R1, #0xEF
			STR 	R1, [R10]               
			BX		LR

SEG11:		
			
			MOV		R0,	#0x00	/*APAGA DISPLAY 3-4*/
			STR 	R0, [R11]
			MOV		R0,	#0x80	/*ENCIENDE DISPLAY 1*/
			STR 	R0, [R9]
			
			MOV		R1, #0xDF
			STR 	R1, [R10]               
			BX		LR



DELAY_MS:	MOV		R1, #5333 
			SUBS 	R0, R0, #1                 
			BNE 	LOOP_MS
			BX  	LR                         
LOOP_MS:	SUBS 	R1, R1, #1                
			BNE 	LOOP_MS                    
			B		DELAY_MS

REINICIO:
			MOV		R0,	#0
			LDR 	R1, =CONT 
			STR 	R0, [R1]
			B		HORARIO
REINICIO2:
			MOV		R0,	#11
			LDR 	R1, =CONT 
			STR 	R0, [R1]
			B		ANTIHORARIO