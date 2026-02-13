// PWMtest.c
// Runs on TM4C123
// Use PWM0/PB6 and PWM1/PB7 to generate pulse-width modulated outputs.
// Daniel Valvano
// March 28, 2014

/* This example accompanies the book
   "Embedded Systems: Real Time Interfacing to ARM Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2014
  Program 6.7, section 6.3.2

 Copyright 2014 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */
//adc
#include <math.h>
#include "adc.h"
#include "PLL.h"

#include <stdlib.h>
#include <stdio.h>

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "PWM.h"

#include "Nokia5110.h"
#include "teclado.h"
#include "board.h"

// FUNCTION PROTOTYPES: Each subroutine defined

void delay_ms(int delay);


int main(void)
{
	board_init();
	//adc
	int POT1 = 1;
	int POT2 = 0;
	unsigned short ADCvalue = 0;
	init_ADC(1);
	
	
	char buffer1[12]; 
	
	board_init();
	
	Nokia5110_Init();
	Nokia5110_Clear();

	Nokia5110_OutString("Ximena Cabia");
	
	
	uint16_t duty = 0;
	int duty1 = 0;
	int frec = 500;
	int frec1 = 500;
	int frec_int = 0;
	int frec_int1 = 0;
	PWM0A_Init(0, 0);        			// initialize PWM0, 500 Hz, 25% duty
	PWM0B_Init(0, 0); 
	PWM1D_Init(0, 0);
		
	while(1)
	{
		
		sprintf(buffer1,"POT1= %4d", POT1);    								// Guardamos el mensaje a desplegar
    Nokia5110_SetCursor(0,3);          
		Nokia5110_OutString(buffer1);
		delay_ms(1);
		
		
		sprintf(buffer1,"POT2= %4d", POT2);    								// Guardamos el mensaje a desplegar
    Nokia5110_SetCursor(0,4);          
		Nokia5110_OutString(buffer1);
		delay_ms(1);
		
		
		if (Lectura_tcl() == 13)
		{
			frec = teclado_4x4();
			Nokia5110_SetCursor(0,5);
			sprintf(buffer1,"------------");
			Nokia5110_OutString(buffer1);
		}
		if (Lectura_tcl() == 10)
		{
			frec1 = teclado_4x4();
			Nokia5110_SetCursor(0,5);
			sprintf(buffer1,"------------");
			Nokia5110_OutString(buffer1);
		}
		
		frec_int = 8*pow(10,6)*pow(frec,-0.999);
		frec_int1 = 8*pow(10,6)*pow(frec1,-0.999);
		
		duty=(frec_int/4096)*POT1;
		duty1=(frec_int1/4096)*POT1;
		
		delay_ms(10);
		
		PWM0A_Duty(frec_int,duty);        			// initialize PWM0, 500 Hz, 25% duty   b6
		PWM0B_Duty(frec_int,duty);
		PWM1D_Duty(frec_int1,frec_int1/2);
		
//		PWM0A_Duty(frec_int,(frec_int/4096)*POT1);     
//		PWM0B_Duty(frec_int,(frec_int/4096)*POT1);
//		PWM1D_Duty(frec_int1,(frec_int1/4096)*(POT1));
		
		
		delay_ms(1);
		
		Nokia5110_SetCursor(0,1);
		sprintf(buffer1,"f1=%6d", frec);
		Nokia5110_OutString(buffer1);
		
		Nokia5110_SetCursor(0,2);
		sprintf(buffer1,"f2=%6d", frec1);
		Nokia5110_OutString(buffer1);
		delay_ms(1);
		
		ADC0_SSMUX3_R = (ADC0_SSMUX3_R&0xFFFFFFF0)+0;
		ADCvalue = ADC0_InSeq();
		POT1=ADCvalue ;
		delay_ms(1);
		
		ADC0_SSMUX3_R = (ADC0_SSMUX3_R&0xFFFFFFF0)+1;
		ADCvalue = ADC0_InSeq();
		POT2=ADCvalue;
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
