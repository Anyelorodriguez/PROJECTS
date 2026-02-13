
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
			BEQ		UNI
			CMP		R0, #0x02
			BEQ		UNIR
			
			CMP		R0, #0x04
			BEQ.W	UNI2
			CMP		R0, #0x08
			BEQ.W	UNIR2
			
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
			
			MOVW	R5, #0x1DAC
			CMP		R3, R5
			BEQ		BORRAR
			CMP 	R1, #10
			BEQ 	DEC
			BX		LR

DEC:	
            MOV		R1,	#0
			STR 	R1, [R0]
			LDR 	R0, =CONTB 
			LDR		R1, [R0]	
			ADD		R1, #1
			STR 	R1, [R0]
			CMP 	R1, #10
			BEQ 	CEN
			BX		LR
CEN:	
			MOV		R1,	#0
			STR 	R1, [R0]
			LDR 	R0, =CONTC 
			LDR		R1, [R0]
			ADD		R1, #1
			STR 	R1, [R0]
			CMP 	R1, #10
			BEQ 	MIL
			BX		LR
MIL:        
            MOV		R1,	#0
			STR 	R1, [R0]
			LDR 	R0, =CONTD 
			LDR		R1, [R0]
			ADD		R1, #1
			STR 	R1, [R0]
			BX		LR
			
BORRAR:
			MOV		R3, #0
			LDR 	R4, =CONTT  
			STR 	R3, [R4]
            MOV		R1,	#0
		    LDR 	R0, =CONTD
		    STR 	R1, [R0]
			LDR 	R0, =CONTC
		    STR 	R1, [R0]
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
			BX		LR
DECR:	
            MOV		R1,	#9
			STR 	R1, [R0]
			LDR 	R0, =CONTB 
			LDR		R1, [R0]	
			SUBS	R1, #1
			STR 	R1, [R0]
			CMP 	R1, #-1
			BEQ 	CENR
			BX		LR
CENR:	
			MOV		R1,	#9
			STR 	R1, [R0]
			LDR 	R0, =CONTC 
			LDR		R1, [R0]
			SUBS	R1, #1
			STR 	R1, [R0]
			CMP 	R1, #-1
			BEQ 	MILR
			BX		LR
MILR:       
            MOV		R1,	#9
			STR 	R1, [R0]
			LDR 	R0, =CONTD 
			LDR		R1, [R0]
			SUBS	R1, #1
			STR 	R1, [R0]
			BX		LR
			
BORRARR:
			MOV		R3, #7595
			LDR 	R4, =CONTT  
			STR 	R3, [R4]
            MOV		R1,	#7
		    LDR 	R0, =CONTD
		    STR 	R1, [R0]
			MOV		R1,	#5
			LDR 	R0, =CONTC
		    STR 	R1, [R0]
			MOV		R1,	#9
			LDR 	R0, =CONTB
		    STR 	R1, [R0]
			MOV		R1,	#5
			LDR 	R0, =CONTA
		    STR 	R1, [R0]
			BX		LR

UNI2: 
            MOV		R1,	#0
			STR 	R1, [R0]
			LDR 	R0, =CONTA 
			LDR		R1, [R0]
			AND		R6,R1, #0x01
			CMP		R6,#0x01
			BEQ 	CONTADOR_PAR
			
			LDR 	R4, =CONTT 
			LDR		R3, [R4]
			ADD		R3, #2
			STR 	R3, [R4]
			
			ADD		R1, #2
			
			STR 	R1, [R0]
			MOVW	R5, #0x1DAC
			CMP		R3, R5
			BEQ		BORRAR
			CMP 	R1, #10
			BEQ 	DEC
			BX		LR
			
CONTADOR_PAR:
			SUB		R1, #1
			LDR 	R4, =CONTT 
			LDR		R3, [R4]
			SUB		R3, #1 
			STR 	R3, [R4]
			STR 	R1, [R0]
			
			BX		LR		


UNIR2: 
            MOV		R1,	#9
			STR 	R1, [R0]
			LDR 	R0, =CONTA 
			LDR		R1, [R0]
			
			AND		R6,R1, #0x01
			CMP		R6,#0x00
			BEQ		CONTADOR_IMPAR
			
			LDR 	R4, =CONTT 
			LDR		R3, [R4]
			SUBS	R3, #2 
			STR 	R3, [R4]
			
			SUBS	R1, #2
			STR 	R1, [R0]
			MOV		R5, #0xFFFFFFFF
			CMP		R3, R5
			BEQ		BORRARR
			CMP 	R1, #-1
			BEQ 	DECR
			BX		LR		

CONTADOR_IMPAR:
			ADD		R1, #1
			LDR 	R4, =CONTT 
			LDR		R3, [R4]
			ADD		R3, #1 
			STR 	R3, [R4]
			STR 	R1, [R0]
			
			BX		LR		
