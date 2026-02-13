#include <stdlib.h>
#include <stdio.h>

#include "tm4c123gh6pm.h"
#include "board.h"
#include "display.h"
#include "Nokia5110.h"
#include "imagen.h"
//#include "imagen1.h"

#define COLUMNAS	84
#define FILAS			6
#define MAX_SIZE	COLUMNAS*FILAS
//#define MAX_COLUMNA COLUMNAS*FILAS

/* Prototipo de la funcion */

int main()
{
	
//	int contador = 0;
//	float contador_float= 0.0;
//	char buffer[12];
	
	char imagen[MAX_SIZE];
//	char imagen1[MAX_COLUMNA];

	for(int i=0 ; i < MAX_SIZE; i++)
	{
		imagen[i] = 0;
	}	
//	for(int i=0 ; i < MAX_COLUMNA; i++)
//	{
//		imagen1[i] = 0;
//	}	

	

	board_init();
	Nokia5110_Init();
	Nokia5110_Clear();
	
	imagen[253] = 0x01;
	imagen[254] = 0x01;
	imagen[255] = 0x01;
	imagen[256] = 0x02;
	imagen[257] = 0x02;
	imagen[258] = 0x07;
	imagen[259] = 0x04;
	imagen[260] = 0x05;
	imagen[261] = 0x03;
	
	imagen[337-168] = 0xC0;
	imagen[338-168] = 0x20;
	imagen[339-168] = 0x30;
	imagen[340-168] = 0xD0;
	imagen[341-168] = 0x10;
	imagen[342-168] = 0x60;
	imagen[343-168] = 0xA0;
	imagen[344-168] = 0xA0;
	imagen[345-168] = 0xA0;
	imagen[346-168] = 0xC0;	
		
	Nokia5110_DrawFullImage(imagen);
	delay_ms(5);
	
	char 	entrada = 0;
	char 	pix 		= 0;
	char 	pixa 		= 0;
	int 	i = 0;
	int   j = 0;

	while(1)
	{	

		entrada = Lectura();

		if (entrada == 0)
		{			
			for( j = 0 ; j < FILAS ; j++)
			{
				for( i = 0 ; i < COLUMNAS ; i++)
				{
					Fondo[(i)+(j*COLUMNAS)] = Fondo[(i+1)+(j*COLUMNAS)]; 			
				}
				Fondo[((j+1)*COLUMNAS)-1] = Fondo[j*COLUMNAS];				
			}
		}
		
		if (entrada == 0)
		{		
			for( i=0 ; i < COLUMNAS ;i++)
			{	
				for( j = FILAS-1 ; j >= 0; j--)
				{
					pixa = ((imagen[i+(COLUMNAS*j)])&0x01) << 7;
					imagen[i+(COLUMNAS*(j))]= ((imagen[i+(COLUMNAS*(j))]&0xFE) >> 1) + pix;
					pix = pixa;
				}		
			}
		}
		if (entrada == 0)
		{		
			for( i=0 ; i < COLUMNAS ;i++)
			{	
				for( j = FILAS-1 ; j >= 0; j--)
				{
					pixa = ((imagen[i+(COLUMNAS*j)])&0x01) << 7;
					imagen[i+(COLUMNAS*(j))]= ((imagen[i+(COLUMNAS*(j))]&0xFE) >> 1) + pix;
					pix = pixa;
				}		
			}
		}
		
		
		if (entrada == P1_ON)
		{		
			for( i=0 ; i < COLUMNAS ;i++)
			{					
				for( j=0 ; j < FILAS; j++)
				{
					pixa = ((imagen[i+(COLUMNAS*j)])&0x80) >> 7;
					imagen[i+(COLUMNAS*(j))]= ((imagen[i+(COLUMNAS*(j))]&0x7F) << 1) + pix;
					pix = pixa;
				}		
			}
		}
		if (entrada == P1_ON)
		{		
			for( i=0 ; i < COLUMNAS ;i++)
			{					
				for( j=0 ; j < FILAS; j++)
				{
					pixa = ((imagen[i+(COLUMNAS*j)])&0x80) >> 7;
					imagen[i+(COLUMNAS*(j))]= ((imagen[i+(COLUMNAS*(j))]&0x7F) << 1) + pix;
					pix = pixa;
				}		
			}
		}
		if (entrada == P1_ON)
		{		
			for( i=0 ; i < COLUMNAS ;i++)
			{					
				for( j=0 ; j < FILAS; j++)
				{
					pixa = ((imagen[i+(COLUMNAS*j)])&0x80) >> 7;
					imagen[i+(COLUMNAS*(j))]= ((imagen[i+(COLUMNAS*(j))]&0x7F) << 1) + pix;
					pix = pixa;
				}		
			}
		}
		if (entrada == P1_ON)
		{		
			for( i=0 ; i < COLUMNAS ;i++)
			{					
				for( j=0 ; j < FILAS; j++)
				{
					pixa = ((imagen[i+(COLUMNAS*j)])&0x80) >> 7;
					imagen[i+(COLUMNAS*(j))]= ((imagen[i+(COLUMNAS*(j))]&0x7F) << 1) + pix;
					pix = pixa;
				}		
			}
		}
		if (entrada == P1_ON)
		{		
			for( i=0 ; i < COLUMNAS ;i++)
			{					
				for( j=0 ; j < FILAS; j++)
				{
					pixa = ((imagen[i+(COLUMNAS*j)])&0x80) >> 7;
					imagen[i+(COLUMNAS*(j))]= ((imagen[i+(COLUMNAS*(j))]&0x7F) << 1) + pix;
					pix = pixa;
				}		
			}
		}
		
		Nokia5110_DrawFullImage(imagen);
		delay_ms(50);
		Nokia5110_DrawFullImage(Fondo);
		delay_ms(50);
	
	}
}