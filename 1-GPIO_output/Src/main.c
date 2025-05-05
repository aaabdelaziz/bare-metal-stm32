#include "stm32f0xx.h"

//#define STM32F091xC   add it at the paths and symbols

// Enable GPIOA clock
#define GPIOAEN      	 (1U<<17)
// Enable GPIOC clock
#define GPIOCEN      	 (1U<<21)

//Output: PIN5 SET/REST
#define LED_PIN_NUM_SET      (1U<<5)
#define LED_PIN_NUM_REST   	 (1U<<21)
//Input Button: PIN13 
#define BTN_PIN_NUM          (1U<<13)


int main(void)
{

	//Enable GPIOA, GPIOC Clock
	RCC->AHBENR |= GPIOAEN;
	RCC->AHBENR |= GPIOCEN;

	// Config GPIOA-PIN5 as Output
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~ (1U<<11);

	//  Config GPIOC-PIN13 as Input
	GPIOC->MODER &=~ (1U<<26);
	GPIOC->MODER &=~ (1U<<27);


	while(1)
	{
		// Checking if Button is pressed, turn on LED, otherwisse turn it off
		if(GPIOC->IDR & BTN_PIN_NUM)
		{

			// Turn Led ON
			GPIOA->BSRR = LED_PIN_NUM_SET;
			for(int i=0; i<10000;i++){}
		}
		else
		{
			// Turn Led Off
			GPIOA->BSRR = LED_PIN_NUM_REST;
			for(int i=0; i<10000;i++){}
		}
	}

	return 0;

}
