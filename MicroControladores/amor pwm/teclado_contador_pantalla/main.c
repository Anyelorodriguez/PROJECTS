
#include <stdlib.h>
#include <stdio.h>

#include "tm4c123gh6pm.h"
#include "board.h"
#include "display.h"
#include "teclado.h"
#include "Nokia5110.h"

// en todos los .h(librerias) se llaman las funciones

/* Prototipo de la funcion */

int main()
{
	
	int dato = 0;   // dato de inicio
	int entrada = 0; // dato de los botones 
	
	int uni = 0;
	int dec = 0;
	int cen = 0;
	int umi = 0;
	char buffer[12];
	
	int limite = 0;
		
	
	board_init();    //funcion del board.h (funcion para configurar los puertos)
	
	Nokia5110_Init();
	Nokia5110_Clear();
	
	Nokia5110_OutString("Ximena C");
	Nokia5110_SetCursor(0,2);
	Nokia5110_OutString("contador");
	
	while(1)
	{
		
		if (tecla() == 13) //esta funcion esta en teclado.h ____
		{
			entrada = 0;
		  while(1) //unidades
			{
				delay_ms(100);
				visualizacion(0,100);
				Nokia5110_SetCursor(0,3);
				sprintf(buffer,"Num1 = %4d", 0);
				Nokia5110_OutString(buffer);
			  uni = tecla();
				if (uni<10)
				{
					break;
				}
		   }
			while(1) //decenas
			{
				delay_ms(100);
				visualizacion(uni,100);
				Nokia5110_SetCursor(0,3);
				sprintf(buffer,"Num1 = %4d", uni);
				Nokia5110_OutString(buffer);
			  dec = tecla();
				if (dec<10)
				{
					uni=uni*10;
					dec=dec*1;
					break;
				}
		   }
			while(1) //cesntemas
			{
				delay_ms(100);
				visualizacion(uni+dec,100);
				Nokia5110_SetCursor(0,3);
				sprintf(buffer,"Num1 = %4d", (uni+dec));
				Nokia5110_OutString(buffer);
			  cen = tecla();
				if (cen<10)
				{
					uni=uni*10;//arriba ya se multiplico poe 10, tonces uni*100
					dec=dec*10;
					cen=cen*1;
					break;
				}
		   }
			while(1) //uni de mil
			{
				delay_ms(100);
				visualizacion(uni+dec+cen,100);
				Nokia5110_SetCursor(0,3);
				sprintf(buffer,"Num1 = %4d", (uni+dec+cen));
				Nokia5110_OutString(buffer);
			  umi = tecla();
				if (umi<10)
				{
					uni=uni*10;//arriba ya se multiplico poe 10, tonces uni*1000
					dec=dec*10;
					cen=cen*10;
					umi=umi*1;
					break;
				}
		   }
			dato=umi+uni+dec+cen;
			  limite = dato;
		 }
		if (Lectura() != 0)  // esta en board.h--- el valor que devuelve la funcion cuando es diferente a 0
		{
			entrada = Lectura(); // se guarda en entrada el valor de loa botones 
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
			//impar de a 2
			if(dato%2==0)// % da el residuo
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
		
		visualizacion(dato,50);//funcion  para ver en el display, manda dato y delay
		Nokia5110_SetCursor(0,3);
		sprintf(buffer,"Num1 = %4d", dato);
		Nokia5110_OutString(buffer);
	}
	
	
}
