

#include <stdlib.h>
#include <stdio.h>

#include "tm4c123gh6pm.h"
#include "board.h"
#include "display.h"
#include "Nokia5110.h"
#include "imagen.h"

/* Prototipo de la funcion */

int main()
{
	
	int contador = 0;
	float contador_float= 0.0;
	char buffer[12];
	
	board_init();
	Nokia5110_Init();
	Nokia5110_Clear();
		
	while(1)
	{
		Nokia5110_DrawFullImage(gif1);
		delay_ms(50);
		Nokia5110_DrawFullImage(gif2);
		delay_ms(50);
		Nokia5110_DrawFullImage(gif3);
		delay_ms(50);
		Nokia5110_DrawFullImage(gif4);
		delay_ms(50);
		Nokia5110_DrawFullImage(gif5);
		delay_ms(50);
		Nokia5110_DrawFullImage(gif6);
		delay_ms(50);
		Nokia5110_DrawFullImage(gif7);
		delay_ms(50);
		Nokia5110_DrawFullImage(gif8);
		delay_ms(50);
		Nokia5110_DrawFullImage(gif9);
		delay_ms(50);
		Nokia5110_DrawFullImage(gif10);
		delay_ms(50);
		Nokia5110_DrawFullImage(fantasma1);
		delay_ms(250);
		Nokia5110_DrawFullImage(fantasma2);
		delay_ms(250);
		
	}
	
}
