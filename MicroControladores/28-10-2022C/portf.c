
#include 	"board.h"
#include	"tm4c123gh6pm.h"

void	init_PORTF(void);
void 	delay_ms(int delay);

void	init_PORTF(void)
{
	int	NOP=0;
	SYSCTL_RCGC2_R |=0x20;
	NOP = 0;
	NOP =	1;
	GPIO_PORTF_LOCK_R=0x4C4F434B;
	GPIO_PORTF_CR_R = 0xFF;
	GPIO_PORTF_AMSEL_R = 0x00;
	GPIO_PORTF_PCTL_R = 0x00;
	GPIO_PORTF_DIR_R = 0x0E;
	GPIO_PORTF_AFSEL_R = 0x00;
	GPIO_PORTF_PUR_R = 0x11;
	GPIO_PORTF_DEN_R = 0xFF;
	
}

