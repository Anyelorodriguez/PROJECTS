
#include <stdlib.h>
#include <stdio.h>

#include "tm4c123gh6pm.h"
#include "board.h"
#include "display.h"
#include "teclado.h"
#include "Nokia5110.h"

/* Prototipo de la funcion */

int main()
{
	
	int dato = 0;
	int entrada = 0;
	char buffer1[12];
	int limite = 9999 ; 
	
	
	board_init();
	
	Nokia5110_Init();
	Nokia5110_Clear();

	Nokia5110_OutString("Anyelo Rodri");
	Nokia5110_SetCursor(2,2);
	Nokia5110_OutString("Contador");
	while(1)
	{
		if (Lectura_tcl() == 13)
		{
			dato = teclado_4x4();
			limite=dato;
			entrada = 0;
		}
		if (Lectura() != 0)
		{
			entrada = Lectura();
		}
			
		if (entrada == 1)
		{
			dato++;
			
			if(dato > limite)
			{
				dato = 0;
			}
			
		}	
		else if (entrada == 2)
		{
			dato--;
			
			if(dato < 0)
			{
				dato = limite;
			}
			
		}
		else if (entrada == 4)
		{
			
			
			if(dato%2==0)
			{
				dato += 2;
			}
			else if (dato%2==1)
			{
			dato++;
			dato+=2;	
			}
			
			if(dato > limite)
			{
				dato = 0;
			}
			
		}	
		else if (entrada == 8)
		{
			if(dato%2==0)
			{
				dato--;
				dato-=2;
			}
			else if (dato%2==1)
			{
				dato-=2;	
			}
			
			if(dato < 0)
			{
				dato = limite;
			}
						
		}
		
		visualizacion(dato,10);
		Nokia5110_SetCursor(0,4);
		sprintf(buffer1,"Num = %5d", dato);
		Nokia5110_OutString(buffer1);
	}
	
	
}
