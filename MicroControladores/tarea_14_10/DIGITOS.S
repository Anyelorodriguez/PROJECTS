.syntax unified
			.text
			.global DIGITOS
			
			.thumb_func

#define 	CONTA	0x20000000
#define		CONTB	0x20000004
#define		CONTC	0x20000008
#define		CONTD	0x2000000C

DIGITOS: 
			PUSH 	{LR}  				/* guardamos la direccion de retorno en la pila */		 
			MOV		R11,	R0
			MOV		R9,		R1
			MOV		R10,	R2
			CMP		R3,#0x00
			BNE		MENU
			

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
			
			MOV		R0,	#0x00
			STR 	R0, [R11]
			MOV		R0,	#0x40	/*ENCIENDE DISPLAY 2*/
			STR 	R0, [R9]
			LDR		R1, =CONTC
			LDR		R0, [R1]	
			BL		DISPLAY
			MOV		R0, #4
			BL		DELAY_MS
			
			MOV		R0,	#0x00
			STR 	R0, [R11]
			MOV		R0,	#0x80	/*ENCIENDE DISPLAY 1*/
			STR 	R0, [R9]
			LDR		R1, =CONTD
			LDR		R0, [R1]	
			BL		DISPLAY
			MOV		R0, #4
			BL		DELAY_MS
			
			SUB		R3, R3, #0x01	
			CMP		R3,#0
			BNE		MENU
			
			POP 	{PC}   				
			
			

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
SEG10:		MOV		R1, #0x90
			STR 	R1, [R10]               
			BX		LR
SEG11:		MOV		R1, #0x90
			STR 	R1, [R10]               
			BX		LR


DELAY_MS:	MOV		R1, #5333 
			SUBS 	R0, R0, #1                 
			BNE 	LOOP_MS
			BX  	LR                         
LOOP_MS:	SUBS 	R1, R1, #1                
			BNE 	LOOP_MS                    
			B		DELAY_MS