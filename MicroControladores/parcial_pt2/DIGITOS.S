.syntax unified
			.text
			.global DIGITOS
			
			.thumb_func

#define 	CONTA	0x20000000
#define		CONTB	0x20000004
#define		DLY		50
#define		CONTT	0x20000010


DIGITOS: 
			PUSH 	{LR}  				/* guardamos la direccion de retorno en la pila */		 
			MOV		R11,	R0
			MOV		R9,		R1
			MOV		R10,	R2
			MOV		R12,	R3
			MOV		R6,		DLY
			B		MENU
			

MENU:
			
			MOV		R0,	#0x00	/*REINICIA LAS VARIABLES DE CONTROL DEL DISPLAY PARA QUE SE VEAN LOS DATOS BIEN*/
			STR 	R0, [R9]
			MOV		R0,	#0x10	/*ENCIENDE DISPLAY 4*/
			STR 	R0, [R11]               
			LDR		R1, =CONTA	/* ENVIA DATO QUE SE QUIERE VER EN PANTALLA */
			LDR		R0, [R1]	
			BL		DISPLAY		/*ENVIA A FUNCION DE DATO EN PANTALLA*/
			MOV		R0, #4
			BL		DELAY_MS	/*TIEMPO ENTRE ENCENDIDO DE LEDS*/
		
		    MOV		R0,	#0x00
			STR 	R0, [R9]
			MOV		R0,	#0x20
			STR 	R0, [R11]	/*ENCIENDE DISPLAY 3*/
			LDR		R1, =CONTB
			LDR		R0, [R1]	
			BL		DISPLAY
			MOV		R0, #4
			BL		DELAY_MS
			
			
			SUB		R6, R6, #0x01	
			CMP		R6,#0
			BNE		MENU
			
			B		OPERACIONES
			   				
			

OPERACIONES:
			LDR		R0,[R12]
			CMP		R0, #0x01
			BEQ		NUM43
			CMP		R0, #0x02
			BEQ		UNI
			CMP		R0, #0x04
			BEQ		UNIR
			CMP		R0, #0x08
			BEQ		PAUSA
			B		PAUSA

NUM43:	
			MOV		R6, DLY
			MOV		R1,	#0x03
			LDR 	R0, =CONTA
			STR 	R1, [R0]
			
			MOV		R1,	#0x04
			LDR 	R0, =CONTB
			STR 	R1, [R0]
			
			LDR 	R4, =CONTT 
			MOV		R3, #43 
			STR 	R3, [R4]
			
			BL		DISPLAY2
			LDR		R0,[R12]
			CMP		R0, #0x01
			BEQ		NUM43
			CMP		R0, #0x02
			BEQ		UNI
			CMP		R0, #0x04
			BEQ		UNIR
			CMP		R0, #0x08
			BEQ		PAUSA
			B		NUM43
UNI: 
			MOV		R6, DLY
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
			CMP 	R3, #2
			BEQ 	INICIO
			CMP 	R3, #3
			BEQ 	INICIO
			CMP 	R3, #5
			BEQ 	INICIO
			CMP 	R3, #7
			BEQ 	INICIO
			CMP 	R3, #11
			BEQ 	INICIO
			CMP 	R3, #13
			BEQ 	INICIO
			CMP 	R3, #17
			BEQ 	INICIO
			CMP 	R3, #19
			BEQ 	INICIO
			CMP 	R3, #23
			BEQ 	INICIO
			CMP 	R3, #29
			BEQ 	INICIO
			CMP 	R3, #31
			BEQ 	INICIO
			CMP 	R3, #37
			BEQ 	INICIO
			CMP 	R3, #41
			BEQ 	INICIO
			CMP 	R3, #43
			BEQ 	INICIO
			CMP 	R3, #47
			BEQ 	INICIO
			CMP 	R3, #53
			BEQ 	INICIO
			CMP 	R3, #59
			BEQ 	INICIO
			CMP 	R3, #61
			BEQ 	INICIO
			CMP 	R3, #67
			BEQ 	INICIO
			CMP 	R3, #71
			BEQ 	INICIO
			CMP 	R3, #73
			BEQ 	INICIO
			CMP 	R3, #79
			BEQ 	INICIO
			CMP 	R3, #83
			BEQ 	INICIO
			CMP 	R3, #89
			BEQ 	INICIO
			CMP 	R3, #97
			BEQ 	INICIO
			
			
			
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
			B		UNI


UNIR: 
			MOV		R6, DLY
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
			CMP 	R3, #2
			BEQ 	INICIO1
			CMP 	R3, #3
			BEQ 	INICIO1
			CMP 	R3, #5
			BEQ 	INICIO1
			CMP 	R3, #7
			BEQ 	INICIO1
			CMP 	R3, #11
			BEQ 	INICIO1
			CMP 	R3, #13
			BEQ 	INICIO1
			CMP 	R3, #17
			BEQ 	INICIO1
			CMP 	R3, #23
			BEQ 	INICIO1
			CMP 	R3, #31
			BEQ 	INICIO1
			CMP 	R3, #37
			BEQ 	INICIO1
			CMP 	R3, #41
			BEQ 	INICIO1
			CMP 	R3, #43
			BEQ 	INICIO1
			CMP 	R3, #47
			BEQ 	INICIO1
			CMP 	R3, #53
			BEQ 	INICIO1
			CMP 	R3, #61
			BEQ 	INICIO1
			CMP 	R3, #67
			BEQ 	INICIO1
			CMP 	R3, #71
			BEQ 	INICIO1
			CMP 	R3, #73
			BEQ 	INICIO1
			
			CMP 	R3, #83
			BEQ 	INICIO1
			CMP 	R3, #97
			BEQ 	INICIO1
			
			B		UNIR
DECR:	
            MOV		R1,	#9
			STR 	R1, [R0]
			LDR 	R0, =CONTB 
			LDR		R1, [R0]	
			SUBS	R1, #1
			STR 	R1, [R0]
			
			CMP 	R3, #19
			BEQ 	INICIO1
			CMP 	R3, #29
			BEQ 	INICIO1
			CMP 	R3, #59
			BEQ 	INICIO1
			CMP 	R3, #79
			BEQ 	INICIO1
			CMP 	R3, #89
			BEQ 	INICIO1
			
			B		UNIR

			
BORRARR:
			MOV		R3, #98
			LDR 	R4, =CONTT  
			STR 	R3, [R4]
            MOV		R1,	#9
			LDR 	R0, =CONTB
		    STR 	R1, [R0]
			MOV		R1,	#8
			LDR 	R0, =CONTA
		    STR 	R1, [R0]
			B		UNIR

INICIO:		
			BL		DISPLAY2
			LDR		R0,[R12]
			CMP		R0, #0x01
			BEQ		NUM43
			CMP		R0, #0x02
			BEQ		UNI
			CMP		R0, #0x04
			BEQ		UNIR
			CMP		R0, #0x08
			BEQ		PAUSA
			B		UNI

INICIO1:		
			BL		DISPLAY2
			LDR		R0,[R12]
			CMP		R0, #0x01
			BEQ		NUM43
			CMP		R0, #0x02
			BEQ		UNI
			CMP		R0, #0x04
			BEQ		UNIR
			CMP		R0, #0x08
			BEQ		PAUSA
			B		UNIR
			
			
PAUSA:		
			MOV		R6, DLY
			BL		DISPLAY2
			LDR		R0,[R12]
			CMP		R0, #0x01
			BEQ		NUM43
			CMP		R0, #0x02
			BEQ		UNI
			CMP		R0, #0x04
			BEQ		UNIR
			CMP		R0, #0x08
			BEQ		PAUSA
			B		PAUSA


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
			BX		LR

SEG0:		MOV		R1, #0xC0
			STR 	R1, [R10]               
			BX		LR
SEG1:		MOV		R1, #0xF9
			STR 	R1, [R10]               
			BX		LR
SEG2:		MOV		R1, #0xA4
			STR 	R1, [R10]               
			BX		LR
SEG3:		MOV		R1, #0xB0
			STR 	R1, [R10]               
			BX		LR
SEG4:		MOV		R1, #0x99
			STR 	R1, [R10]               
			BX		LR
SEG5:		MOV		R1, #0x92
			STR 	R1, [R10]               
			BX		LR
SEG6:		MOV		R1, #0x82
			STR 	R1, [R10]               
			BX		LR
SEG7:		MOV		R1, #0xF8
			STR 	R1, [R10]               
			BX		LR
SEG8:		MOV		R1, #0x80
			STR 	R1, [R10]               
			BX		LR
SEG9:		MOV		R1, #0x90
			STR 	R1, [R10]               
			BX		LR

DELAY_MS:	MOV		R1, #5333 
			SUBS 	R0, R0, #1                 
			BNE 	LOOP_MS
			BX  	LR                         
LOOP_MS:	SUBS 	R1, R1, #1                
			BNE 	LOOP_MS                    
			B		DELAY_MS

DISPLAY2:
			
			CMP		R6, DLY
			BEQ		GLR
			MOV		R0,	#0x00	/*REINICIA LAS VARIABLES DE CONTROL DEL DISPLAY PARA QUE SE VEAN LOS DATOS BIEN*/
			STR 	R0, [R9]
			MOV		R0,	#0x10	/*ENCIENDE DISPLAY 4*/
			STR 	R0, [R11]               
			LDR		R1, =CONTA	/* ENVIA DATO QUE SE QUIERE VER EN PANTALLA */
			LDR		R0, [R1]	
			BL		DISPLAY		/*ENVIA A FUNCION DE DATO EN PANTALLA*/
			MOV		R0, #4
			BL		DELAY_MS	/*TIEMPO ENTRE ENCENDIDO DE LEDS*/
		
		    MOV		R0,	#0x00
			STR 	R0, [R9]
			MOV		R0,	#0x20
			STR 	R0, [R11]	/*ENCIENDE DISPLAY 3*/
			LDR		R1, =CONTB
			LDR		R0, [R1]	
			BL		DISPLAY
			MOV		R0, #4
			BL		DELAY_MS
			
			
			SUB		R6, R6, #0x01	
			CMP		R6,#0
			BNE		DISPLAY2
			MOV		LR,R7
			BX		LR

GLR:		
			SUB		R6,#1
			MOV		R7,LR
			B		DISPLAY2
			