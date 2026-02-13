;BRAYAN ANYELO RODRIGUEZ LANCHEROS 201910880 


;realizar las siguientes operaciones (usando operaciones no signadas) r1=1000 r2=2000 r3=4000 r1=r3-r2 r2=r2-r1
VAR1		EQU	 	0x20000000
VAR2		EQU	 	0x20000004
VAR3		EQU	 	0x20000008

		AREA    |.text|, CODE, READONLY, ALIGN=2
		ENTRY
		EXPORT  __main
				
__main
		LDR 	R1, =VAR1    
		LDR 	R2, =VAR2  
		LDR 	R3, =VAR3  
		 
		MOV		R4, #1000
		STR		R4, [R1]  ;se guarda el valor del registro 4 en la posicion de memoria r1
		MOV		R5, #2000
		STR		R5, [R2]
		MOV		R6, #4000
		STR		R6, [R3]
		SUB		R8, R6,R5
		STR		R8, [R1]
		ADD		R7, R4,R5
		STR		R7, [R2]


		ALIGN                           
		END
