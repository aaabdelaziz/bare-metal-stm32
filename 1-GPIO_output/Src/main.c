#include "stm32f0xx.h"

//#define STM32F091xC   add it at the paths and symbols

// Enable GPIOA clock
#define GPIOAEN      	 (1U<<17)
// Enable GPIOC clock
#define GPIOCEN      	 (1U<<19)

#define LED_PIN 5
#define BTN_PIN 13
#define LED_ON (1U << LED_PIN)
#define LED_OFF (1U << (LED_PIN + 16))
#define BTN_MASK (1U << BTN_PIN)


//Output: PIN5 SET/REST
#define LED_PIN_NUM_SET      (1U<<LED_PIN)
#define LED_PIN_NUM_REST   	 (1U<<(LED_PIN + 16))
//Input Button: PIN13 
#define BTN_PIN_NUM          (1U<<13)


int main(void)
{

	//Enable GPIOA, GPIOC Clocks
	RCC->AHBENR |= GPIOAEN;
	RCC->AHBENR |= GPIOCEN;

	 // Configure GPIOA-PIN5 as Output
	 GPIOA->MODER |= (1U<<10);  // MODER5
	 GPIOA->MODER &=~ (1U<<11);

	 //  Config GPIOC-PIN13 as Input
	 GPIOC->MODER &=~ (1U<<26);
	 GPIOC->MODER &=~ (1U<<27);


	while (1)
	{
		// Checking if Button is pressed, turn on LED, otherwise turn it off
		if (!(GPIOC->IDR & BTN_MASK)) {
			// Button is pressed (active-low)
			GPIOA->BSRR = LED_ON;
		} else {
			GPIOA->BSRR = LED_OFF;
		}
	}

	return 0;

}
