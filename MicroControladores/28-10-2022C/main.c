
#include	"tm4c123gh6pm.h"
#include	"board.h"

#include	rojo			0x02
#include	azul			0x04
#include	verde			0x08
#include	morado		0x06
#include	magenta		0x0C
#include	amarillo	0x0A
#include	blanco		0x0E
#include	APAGADO		0x00

int		main()
{
	board_init();
	
	
	while(1)
	{
	GPIO_PORTF_DATA_R=0x0A;	
	delay_ms(100);
	GPIO_PORTF_DATA_R=0x00;
	delay_ms(100);
	}
}

	
