
#include <math.h>
#include "adc.h"
#include "PLL.h"

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "PWM.h"

#include <stdlib.h>
#include <stdio.h>
#include "Nokia5110.h"
#include "teclado.h"
#include "board.h"

// FUNCTION PROTOTYPES: Each subroutine defined

void delay_ms(int delay);


int main(void)
{
	
	int dato = 0;
	int ciclo=0;
	int uni = 0;
	int dec = 0;
	int cen = 0;
	int umi = 0;
	int dmi=0;
	int cmi=0;
	char buffer[12];
	float POT1=0;
	float POT2=0;
	float ADCvalue=0;
	
	uint16_t frec=0;
		
	board_init();    //funcion del board.h (funcion para configurar los puertos)
	
	Nokia5110_Init();
	Nokia5110_Clear();
	
	Nokia5110_OutString("Anyelo Rodri");
	
	while(1)
	{	
			init_ADC(0);
			ADCvalue = ADC0_InSeq();
			POT1=ADCvalue ;
			delay_ms(1);
			
			init_ADC(1);
			ADCvalue = ADC0_InSeq();
			POT2=ADCvalue;
			delay_ms(1);
			if (tecla() == 13) //esta funcion esta en teclado.h ____
		{
			
			Nokia5110_SetCursor(0,5);
			sprintf(buffer,"ingre dat");
			Nokia5110_OutString(buffer);
		  while(1) //unidades
			{
				Nokia5110_SetCursor(0,2);
				sprintf(buffer,"f1 = %4d", 0);
				Nokia5110_OutString(buffer);
			  uni = tecla();
				if (uni<10)
				{
					break;
				}
		   }
			while(1) //decenas
			{
				Nokia5110_SetCursor(0,2);
				sprintf(buffer,"f1 = %4d", uni);
				Nokia5110_OutString(buffer);
				delay_ms(50);
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
				//visualizacion(uni+dec,100);
				Nokia5110_SetCursor(0,2);
				sprintf(buffer,"f1 = %4d", (uni+dec));
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
				//visualizacion(uni+dec+cen,100);
				Nokia5110_SetCursor(0,2);
				sprintf(buffer,"f1 = %4d", (uni+dec+cen));
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
			//--------------------------------------------------------------------------------------------------------
			 while(1) //d de mil
			{
				delay_ms(100);
				//visualizacion(uni+dec+cen+umi,100);
				Nokia5110_SetCursor(0,2);
				sprintf(buffer,"f1 = %4d", (uni+dec+cen));
				Nokia5110_OutString(buffer);
			  dmi = tecla();
				if (dmi<10)
				{
					uni=uni*10;//arriba ya se multiplico poe 10, tonces uni*1000
					dec=dec*10;
					cen=cen*10;
					umi=umi*10;
					dmi=dmi*1;
					break;
				}
		   }
			while(1) //centenas de mil
			{
				delay_ms(100);
				//visualizacion(uni+dec+cen+umi+dmi,100);
				Nokia5110_SetCursor(0,2);
				sprintf(buffer,"f1 = %4d", (uni+dec+cen));
				Nokia5110_OutString(buffer);
			  cmi = tecla();
				if (cmi<10)
				{
					uni=uni*10;//arriba ya se multiplico poe 10, tonces uni*1000
					dec=dec*10;
					cen=cen*10;
					umi=umi*10;
					dmi=dmi*10;
					cmi=cmi*1;
					
					break;
				}
		   }
			 
			//--------------------------------------------------------------------------------------------------------
			dato=uni+dec;
//			limite = dato;
			Nokia5110_SetCursor(0,5);
			sprintf(buffer,"------------");
			Nokia5110_OutString(buffer);
		 }
		
			frec=8*pow(10,6)*pow(dato,-0.999);
			PWM0A_Init(frec,frec/2);		
			PWM0B_Init(frec,frec/2);	
			
			Nokia5110_SetCursor(0,2);
			sprintf(buffer,"f1 = %4d", dato);
			Nokia5110_OutString(buffer);
			 
			
			 
			sprintf(buffer,"POT1= %1.2f", POT1);    								// Guardamos el mensaje a desplegar
			Nokia5110_SetCursor(0,3);          
			Nokia5110_OutString(buffer);
			delay_ms(1);
				
				
			sprintf(buffer,"POT2= %1.2f", POT2);    								// Guardamos el mensaje a desplegar
			Nokia5110_SetCursor(0,4);          
			Nokia5110_OutString(buffer);
			delay_ms(1);
		
		 
	}
}	

void delay_ms(int delay)
{

	for(int j=0;j<delay;j++)
	{	
		for(int i=0;i<20000;i++)
		{}
	}

}
