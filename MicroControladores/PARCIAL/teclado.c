#include <stdlib.h>
#include <stdio.h>


#include "tm4c123gh6pm.h"
#include "teclado.h"
//#include "Nokia5110.h"
//#include "display.h"
#include "board.h"

int Lenc(void)
{
	int b = 0;
	b = GPIO_PORTC_DATA_R & 0xF0;
	return	b;
}

int valor()
{
	int salida = 23;
	int num_decimal = 0;
	
	
	GPIO_PORTD_DATA_R = 0x0E; //COLUMNA 1
  num_decimal = Lenc();
	
	if(num_decimal == 0xE0)
	{
		salida = 1;
	}
	else if(num_decimal == 0xD0)
	{
		salida = 4;
	}
	else if(num_decimal == 0xB0)
	{
		salida = 7;
	}
	else if(num_decimal == 0x70) //BOTON * ASTERISCO
	{
		salida = 15;
	}
	
	GPIO_PORTD_DATA_R = 0x0D; 	//COLUMNA 2
  num_decimal = Lenc();
	
	if(num_decimal == 0xE0)
	{
		salida = 2;
	}
	else if(num_decimal == 0xD0)
	{
		salida = 5;
	}
	else if(num_decimal == 0xB0)
	{
		salida = 8;
	}
	else if(num_decimal == 0x70)		
	{
		salida = 0;
	}
	
	GPIO_PORTD_DATA_R = 0x0B; 	//COLUMNA 3
  num_decimal = Lenc();
	
	if(num_decimal == 0xE0)
	{
		salida = 3;
	}
	else if(num_decimal == 0xD0)
	{
		salida = 6;
	}
	else if(num_decimal == 0xB0)
	{
		salida = 9;
	}
	else if(num_decimal == 0x70)	//BOTON # NUMERAL
	{
		salida = 14;
	}
	
	GPIO_PORTD_DATA_R = 0x07; 	//COLUMNA 4
  num_decimal = Lenc();
	
	if(num_decimal == 0xE0)	// SALIR DE CAMBIAR NUMERO
	{
		salida = 10;
	}
	else if(num_decimal == 0xD0)//BOTOB B
	{
		salida = 11;
	}
	
	else if(num_decimal == 0xB0)			// BOTON C	//BOTON SALIR CAMBIAR NUMERO
	{
		salida = 12;
	}
	else if(num_decimal == 0x70)		//BOTON D		//BOTON ENTRAR CAMBIAR NUMERO
	{
		salida = 13;
	}
	
	
	
	return salida;
}

int teclado_4x4(void)
{

	char buffer1[12];
	int unidades = 0;
	int decenas = 0;
	int centenas = 0;
	int	umil = 0;
	int dmil = 0;
	int cmil = 0;
	
	
	int	total = 0;
	

	while(1)
	{
		
		Nokia5110_SetCursor(0,5);
		sprintf(buffer1,"int=%5d", 0);
		Nokia5110_OutString(buffer1);
		
		
		delay_ms(10);
		//visualizacion(unidades,100);
		if (valor()<10)
		{
			unidades=valor();
			break;
		}
		else if(valor()==12)
		{
			total=0;
			return total;
		}
	}
	while(1)
	{
		Nokia5110_SetCursor(0,5);
		sprintf(buffer1,"int=%5d", unidades);
		Nokia5110_OutString(buffer1);
		
		
		delay_ms(10);
		//visualizacion(unidades,100);
		if (valor()<10)
		{
			decenas=valor();
			break;
		}
		else if(valor()==12)
		{
			total=unidades;
			return total;
		}
	}
	while(1)
	{
		
		Nokia5110_SetCursor(0,5);
		sprintf(buffer1,"int=%5d", unidades*10+decenas);
		Nokia5110_OutString(buffer1);
		
		
		delay_ms(10);
		
		
		//visualizacion(unidades*10+decenas,100);
		if (valor()<10)
		{
			centenas=valor();
			break;
		}
		else if(valor()==12)
		{
			total=unidades*10+decenas;
			return total;
		}
	}
  while(1)
	{
		Nokia5110_SetCursor(0,5);
		sprintf(buffer1,"int=%5d", unidades*100+decenas*10+centenas);
		Nokia5110_OutString(buffer1);
		
		
		delay_ms(10);
		
		//visualizacion(unidades*100+decenas*10+centenas,100);
		
		if (valor()<10)
		{
			umil=valor();
			break;
		}
		else if(valor()==12)
		{
			total=unidades*100+decenas*10+centenas;
			return total;
		}

	}
	//-----------------------------------------------------------------------
	while(1)//decenas de mil
	{
		Nokia5110_SetCursor(0,5);
		sprintf(buffer1,"int=%5d", unidades*1000+decenas*100+centenas*10+umil);
		Nokia5110_OutString(buffer1);
		
		
		delay_ms(10);
		
		//visualizacion(unidades*100+decenas*10+centenas,100);
		
		if (valor()<10)
		{
			dmil=valor();
			break;
		}
		else if(valor()==12)
		{
			total=unidades*1000+decenas*100+centenas*10+umil;
			return total;
		}

	}
	while(1)//centenas de mil
	{
		Nokia5110_SetCursor(0,5);
		sprintf(buffer1,"int=%5d", unidades*10000+decenas*1000+centenas*100+umil*10+dmil);
		Nokia5110_OutString(buffer1);
		
		
		delay_ms(10);
		
		//visualizacion(unidades*100+decenas*10+centenas,100);
		
		if (valor()<10)
		{
			cmil=valor();
			break;
		}
		else if(valor()==12)
		{
			total=unidades*10000+decenas*1000+centenas*100+umil*10+dmil;
			return total;
		}

	}
	
	//-----------------------------------------------------------------------
	
	total=unidades*100000+decenas*10000+centenas*1000+umil*100+dmil*10+cmil;
	
	
	return	total;
	
	
}
int Lectura_tcl(void)
{
	int len = 0;
	len = valor();
	
	return len;
}
