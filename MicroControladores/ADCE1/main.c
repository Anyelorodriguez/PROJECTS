
// Conversor de Analogo a Digital
#include <math.h>
#include "board.h"
#include "adc.h"
#include "PLL.h"
#include "Nokia5110.h"
#include "tm4c123gh6pm.h"

#include <stdio.h>
#include <stdlib.h>

// Fosc = 16MHz T = (1/Fosc) * 4 = 250ns 
// 1ms / 250ns = 4000

static void delay_ms(int delay)
{
		for(int i = 0;i < delay;i++)
		{
			for(int j = 0;j < 4000;j++)
			{}
		}
}

int main(void){

	double NIVEL = 0;
	double lectu = 0;
	//double logr2 = 0;
	double TEM = 0;
	double POT1 = 0;
	double POT2 = 0;
	
	unsigned short ADCvalue = 0;
	
  char buffer[20];

	board_init();
			
	PLL_Init();                           // set system clock to 50 MHz
  Nokia5110_Init();

  Nokia5110_Clear();
  Nokia5110_OutString("* CONVERSOR*");
  
	while(1)	
	{	
		sprintf(buffer,"DIS= %1.2f", NIVEL);    								// Guardamos el mensaje a desplegar
    Nokia5110_SetCursor(0,2);          
		Nokia5110_OutString(buffer);
		
		delay_ms(3);
		
		sprintf(buffer,"TEM= %1.2f", TEM);    								// Guardamos el mensaje a desplegar
    Nokia5110_SetCursor(0,3);          
		Nokia5110_OutString(buffer);
		
		delay_ms(3);
		
		sprintf(buffer,"POT1= %1.2f", POT1);    								// Guardamos el mensaje a desplegar
    Nokia5110_SetCursor(0,4);          
		Nokia5110_OutString(buffer);
		
		delay_ms(3);
		
		sprintf(buffer,"POT2= %1.2f", POT2);    								// Guardamos el mensaje a desplegar
		Nokia5110_SetCursor(0,5);          
		Nokia5110_OutString(buffer);
			
		delay_ms(25);    


		init_ADC(0);
		ADCvalue = ADC0_InSeq();
		lectu= ((ADCvalue/4096.0) * 3.3);
		NIVEL=0.0071 * ADCvalue-7.7994;
		/*R2=100000*(4096.0/(ADCvalue-1));
		valorldr=log(R2);
		NIVEL = 1/(0.00211+0.000038*valorldr+0.00000052*valorldr);	
		*/
		delay_ms(5); 
		init_ADC(1);
		ADCvalue = ADC0_InSeq();
		//TEM=0.0207*ADCvalue-21.555;
		/*valorldr=(4096.0*10/ADCvalue)-10;
		LDR = (800.69*pow(valorldr,-1.253));
		*/
		delay_ms(5);
		init_ADC(2); 
		ADCvalue = ADC0_InSeq();
		POT1 =  ((ADCvalue/4096.0) * 3.3);
		
		delay_ms(5);
		init_ADC(3); 
		ADCvalue = ADC0_InSeq();
		POT2 = ((ADCvalue/4096.0) * 3.3);
		delay_ms(5);
    
		
		GPIO_PORTB_DATA_R ^= 0x01;
				
	}
}