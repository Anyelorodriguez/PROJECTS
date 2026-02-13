
#include "stdint.h"
#include <stdio.h>
#include "tm4c123gh6pm.h"
#include "PWM.h"

#define PWM_0_GENA_ACTCMPAD_ONE 0x000000C0  // Set the output signal to 1
#define PWM_0_GENA_ACTLOAD_ZERO 0x00000008  // Set the output signal to 0
#define PWM_0_GENB_ACTCMPBD_ONE 0x00000C00  // Set the output signal to 1
#define PWM_0_GENB_ACTLOAD_ZERO 0x00000008  // Set the output signal to 0

#define SYSCTL_RCC_USEPWMDIV    0x00100000  // Enable PWM Clock Divisor
#define SYSCTL_RCC_PWMDIV_M     0x000E0000  // PWM Unit Clock Divisor
#define SYSCTL_RCC_PWMDIV_2     0x00000000  // /2


void PWM0A_Init(uint16_t period, uint16_t duty)
{
  SYSCTL_RCGCPWM_R |= 0x01;             								// 1) activate PWM0
	for(int delay= 0;delay<50;delay++)										// allow time to finish activating	      
  SYSCTL_RCGCGPIO_R |= 0x02;            								// 2) activate port B
	for(int delay= 0;delay<50;delay++)										// allow time to finish activating	      

	GPIO_PORTB_AFSEL_R |= 0x40;           								// enable alt funct on PB6
  GPIO_PORTB_PCTL_R &= (unsigned long)~0x0F000000;     	// configure PB6 as PWM0
  GPIO_PORTB_PCTL_R |= (unsigned long)0x04000000;
  GPIO_PORTB_AMSEL_R &= (unsigned long)~0x40;          	// disable analog functionality on PB6
  GPIO_PORTB_DEN_R |= 0x40;             								// enable digital I/O on PB6
  SYSCTL_RCC_R = (unsigned long)(0x00100000 |           // 3) use PWM divider
      (SYSCTL_RCC_R & (unsigned long)(~0x000E0000)));   //    configure for /2 divider
  PWM0_0_CTL_R = 0;                     								// 4) re-loading down-counting mode
  PWM0_0_GENA_R = 0xC8;                 								// low on LOAD, high on CMPA down
  // PB6 goes low on LOAD
  // PB6 goes high on CMPA down
  PWM0_0_LOAD_R = period ;           								// 5) cycles needed to count down to 0
  PWM0_0_CMPA_R = duty ;             								// 6) count value when output rises
  PWM0_0_CTL_R |= 0x00000001;           								// 7) start PWM0
  PWM0_ENABLE_R |= 0x00000001;          								// enable PB6/M0PWM0
}
// change duty cycle of PB6
// duty is number of PWM clock cycles output is high  (2<=duty<=period-1)
void PWM0A_Duty(uint16_t period,uint16_t duty)
{
	PWM0_0_LOAD_R = period ;
  PWM0_0_CMPA_R = duty ;             // 6) count value when output rises
	PWM0_0_CTL_R |= 0x00000001;           								// 7) start PWM0
  PWM0_ENABLE_R |= 0x00000001;          								// enable PB6/M0PWM0
}
// period is 16-bit number of PWM clock cycles in one period (3<=period)
// period for PB6 and PB7 must be the same
// duty is number of PWM clock cycles output is high  (2<=duty<=period-1)
// PWM clock rate = processor clock rate/SYSCTL_RCC_PWMDIV
//                = BusClock/2 
//                = 80 MHz/2 = 40 MHz (in this example)

void PWM0B_Init(uint16_t period, uint16_t duty)
{
	SYSCTL_RCGCPWM_R |= 0x01;            	 								// 1) activate PWM0
  for(int delay= 0;delay<50;delay++)										// allow time to finish activating	      
	SYSCTL_RCGCGPIO_R |= 0x02;            								// 2) activate port B
	for(int delay= 0;delay<50;delay++)										// allow time to finish activating	      
  
	GPIO_PORTB_AFSEL_R |= 0x80;           								// enable alt funct on PB7
  GPIO_PORTB_PCTL_R &= ~0xF0000000; 					    			// configure PB7 as M0PWM1
  GPIO_PORTB_PCTL_R |= 0x40000000;
  GPIO_PORTB_AMSEL_R &= (unsigned long)~0x80;          	// disable analog functionality on PB7
  GPIO_PORTB_DEN_R |= 0x80;             								// enable digital I/O on PB7
  SYSCTL_RCC_R |= (unsigned long)SYSCTL_RCC_USEPWMDIV; 	// 3) use PWM divider
  SYSCTL_RCC_R &= (unsigned long)~SYSCTL_RCC_PWMDIV_M; 	//    clear PWM divider field
  SYSCTL_RCC_R += (unsigned long)SYSCTL_RCC_PWMDIV_2;  	//    configure for /2 divider
  PWM0_0_CTL_R = 0;                     								// 4) re-loading down-counting mode
  PWM0_0_GENB_R = (PWM_0_GENB_ACTCMPBD_ONE|PWM_0_GENB_ACTLOAD_ZERO);
  // PB7 goes low on LOAD
  // PB7 goes high on CMPB down
  PWM0_0_LOAD_R = period ;           								// 5) cycles needed to count down to 0
  PWM0_0_CMPB_R = duty ;             								// 6) count value when output rises
  PWM0_0_CTL_R |= 0x00000001;           								// 7) start PWM0
  PWM0_ENABLE_R |= 0x00000002;          								// enable PB7/M0PWM1
}
// change duty cycle of PB7
// duty is number of PWM clock cycles output is high  (2<=duty<=period-1)
void PWM0B_Duty(uint16_t period,uint16_t duty)
{
	PWM0_0_LOAD_R = period ;
  PWM0_0_CMPB_R = duty ;             // 6) count value when output rises
	PWM0_0_CTL_R |= 0x00000001;           								// 7) start PWM0
  PWM0_ENABLE_R |= 0x00000002; 
	
}

//--------------------------------------------------------------------------------------------------------------------------------------
// Output on PF3/M0PWM2
void PWM1D_Init(uint16_t period, uint16_t duty)
{
	SYSCTL_RCGCPWM_R |= (1<<1);            	 								// 1) activate PWM1
  for(int delay= 0;delay<50;delay++)										// allow time to finish activating	      
	SYSCTL_RCGCGPIO_R |= (1<<5);            								// 2) activate port F
	for(int delay= 0;delay<50;delay++)										// allow time to finish activating	      
  SYSCTL_RCC_R = (unsigned long)(0x00100000 |           // 3) use PWM divider
      (SYSCTL_RCC_R & (unsigned long)(~0x000E0000)));
	
	GPIO_PORTF_AFSEL_R = (1<<3);           								// enable alt funct on PF3
  GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&~0x0000F000)|0x00005000; 					    			// configure PF3 as M0PWM2
  GPIO_PORTF_AMSEL_R &= (unsigned long)~0x08;          	// disable analog functionality on PF3
  GPIO_PORTF_DEN_R |= (1<<3);             								// enable digital I/O on PF3
	PWM1_3_CTL_R&=~(1<<0);                     								// 4) re-loading down-counting mode
  PWM1_3_GENB_R = 0x0000008C;
  // Pf3 goes low on LOAD
  // Pf3 goes high on CMPB down
  PWM1_3_LOAD_R = period ;           								// 5) cycles needed to count down to 0
  PWM1_3_CMPA_R = duty ;             								// 6) count value when output rises
  PWM1_3_CTL_R |= 1;           								// 7) start PWM1
  PWM1_ENABLE_R = (1<<7);   	// enable PF3/M1PWM3
}
// change duty cycle of PB7
// duty is number of PWM clock cycles output is high  (2<=duty<=period-1)
void PWM1D_Duty(uint16_t period, uint16_t duty)
{
	PWM1_3_LOAD_R = period;
  PWM1_3_CMPA_R = duty;             // 6) count value when output rises
}
//--------------------------------------------------------------------------------------------------------------------------------------