
//__________________________________________________________
#include "board.h"
#include "teclado.h"
#include "tm4c123gh6pm.h"

int Lectura_teclado(void)
{
	
	int C = 0;
	C = GPIO_PORTC_DATA_R;
	C = C & 0xF0;
	
   return C;
}

int tecla()
{   
   int valor = 23;
	int dato = 0;
	
	GPIO_PORTD_DATA_R = 0x0E; //COLUMNA 1
  dato = Lectura_teclado();
	if(dato == 0xC0)
	{
		valor = 1;
	}
	else if(dato == 0xD0)
	{
		valor = 4;
	}
	else if(dato == 0xB0)
	{
		valor = 7;
	}
	else if(dato == 0x70) //BOTON * ASTERISCO
	{
		valor = 15;
	}
	
	GPIO_PORTD_DATA_R = 0x0D; 	//COLUMNA 2
  dato = Lectura_teclado();
	
	if(dato == 0xC0)
	{
		valor = 2;
	}
	else if(dato == 0xD0)
	{
		valor = 5;
	}
	else if(dato == 0xB0)
	{
		valor = 8;
	}
	else if(dato == 0x70)		
	{
		valor = 0;
	}
	
	GPIO_PORTD_DATA_R = 0x0B; 	//COLUMNA 3
  dato = Lectura_teclado();
	
	if(dato == 0xC0)
	{
		valor = 3;
	}
	else if(dato == 0xD0)
	{
		valor = 6;
	}
	else if(dato == 0xB0)
	{
		valor = 9;
	}
	else if(dato == 0x70)	//BOTON # NUMERAL
	{
		valor = 14;
	}
	
	GPIO_PORTD_DATA_R = 0x07; 	//COLUMNA 4
  dato = Lectura_teclado();
	
	if(dato == 0x80)			// BOTON C	//BOTON SALIR CAMBIAR NUMERO
	{
		valor = 12;
	}
	else if(dato == 0x40)		//BOTON D		//BOTON ENTRAR CAMBIAR NUMERO
	{
		valor = 13;
	}


return valor;
}