#include "stm32f0xx.h"

//#define STM32F091xC   add it at the paths and symbols

// Enable GPIOA clock
#define GPIOAEN      	 (1U<<17)

//PIN5 SET/REST
#define LED_PIN_NUM_SET      (1U<<5)
#define LED_PIN_NUM_REST   	 (1U<<21)


int main(void)
{

	RCC->AHBENR |= GPIOAEN;

	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~ (1U<<11);

	while(1)
	{
		// Enable the register
		GPIOA->BSRR = LED_PIN_NUM_SET;
		for(int i=0; i<10000;i++){}

		GPIOA->BSRR = LED_PIN_NUM_REST;
		for(int i=0; i<10000;i++){}
	}

	return 0;

}
