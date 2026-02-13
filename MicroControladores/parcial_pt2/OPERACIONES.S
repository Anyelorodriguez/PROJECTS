
.syntax unified
			.text
			.global OPERACIONES
			
			.thumb_func
	
#define 	CONTA	0x20000000
#define		CONTB	0x20000004
#define		CONTC	0x20000008
#define		CONTD	0x2000000C
#define		CONTT	0x20000010

OPERACIONES:

			CMP		R0, #0x01
			BEQ		NUM43
			CMP		R0, #0x02
			BEQ		UNI
			CMP		R0, #0x04
			BEQ		UNIR
			CMP		R0, #0x08
			BEQ.W	PAUSA
			
			BX		LR

UNI: 
            MOV		R1,	#0
			STR 	R1, [R0]
			LDR 	R0, =CONTA 
			LDR		R1, [R0]
			ADD		R1, #1
			STR 	R1, [R0]
			
			LDR 	R4, =CONTT 
			LDR		R3, [R4]
			ADD		R3, #1 
			STR 	R3, [R4]
			
			MOVW	R5, #0x62
			CMP		R3, R5
			BEQ		BORRAR
			CMP 	R1, #10
			BEQ 	DEC
			B		UNI

DEC:	
            MOV		R1,	#0
			STR 	R1, [R0]
			LDR 	R0, =CONTB 
			LDR		R1, [R0]	
			ADD		R1, #1
			STR 	R1, [R0]
			B		UNI

			
BORRAR:
			MOV		R3, #0
			LDR 	R4, =CONTT  
			STR 	R3, [R4]
            MOV		R1,	#0
			LDR 	R0, =CONTB
		    STR 	R1, [R0]
			LDR 	R0, =CONTA
		    STR 	R1, [R0]
			BX		LR


UNIR: 
            MOV		R1,	#9
			STR 	R1, [R0]
			LDR 	R0, =CONTA 
			LDR		R1, [R0]
			SUBS	R1, #1
			
			LDR 	R4, =CONTT 
			LDR		R3, [R4]
			SUBS	R3, #1 
			STR 	R3, [R4]
			
			STR 	R1, [R0]
			MOV		R5, #0xFFFFFFFF
			CMP		R3, R5 
			BEQ		BORRARR
			CMP 	R1, #-1
			BEQ 	DECR
			B		UNIR
DECR:	
            MOV		R1,	#9
			STR 	R1, [R0]
			LDR 	R0, =CONTB 
			LDR		R1, [R0]	
			SUBS	R1, #1
			STR 	R1, [R0]
			B		UNIR

			
BORRARR:
			MOV		R3, #97
			LDR 	R4, =CONTT  
			STR 	R3, [R4]
            MOV		R1,	#9
			LDR 	R0, =CONTB
		    STR 	R1, [R0]
			MOV		R1,	#7
			LDR 	R0, =CONTA
		    STR 	R1, [R0]
			BX		LR

INICIO:
			MOV		R0,	R7
			BX		LR