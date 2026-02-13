
#include	"tm4c123gh6pm.h"

#define		ON					1
#define		OFF					0x00
#define		puertoA			0x40004000
#define		puertoB			0x40005000
#define		puertoC			0x40006000
#define		puertoD			0x40007000
#define		puertoE			0x40024000
#define		puertoF			0x40025000
#define		ENTRADA			0x00
#define		SALIDA			0xFF
#define		LOCK				0x01

void init_PORT (int puer,int io,int lk,int clk);
int main(void)
{
	init_PORT(puertoB,SALIDA,OFF,0x02);
	
	init_PORT(puertoD,SALIDA,LOCK,0x08);
	
	init_PORT(puertoE,SALIDA,OFF,0x10);
	
	init_PORT(puertoF,ENTRADA,LOCK,0x20);
	
	int a;

	
	while(1)
	{
		primero(&GPIO_PORTE_DATA_R,&GPIO_PORTD_DATA_R,&GPIO_PORTB_DATA_R,&GPIO_PORTF_DATA_R);
		
}
	
}