
			.syntax unified
			.text
			.global led_blink
			
			.thumb_func

led_blink:	
			PUSH 	{LR}  				/* guardamos la direccion de retorno en la pila */		
			LDR		R0, [R0]
			POP 	{PC}   				/* retorno   */