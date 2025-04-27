
#include <stm32f091rc_peripherals.h>


int main ()
{


	/* (1) Enable the peripheral clock of GPIOA */
	RCC->AHBENR |= GPIOAEN;

	/* (2) Set PA5 as Output PIN */
	GPIOA->MODER  |= (1U << 10);     // Set bit 10 to 1
	GPIOA->MODER  &= ~(1U << 11);    // Set bit 11 to 0

	while(1)
	{
		/* (3) Toggle PA5 */
		GPIOA->ODR  ^= LED_PIN_NUM;
    	for(int i=0; i<100000;i++);
	}

  return 0;
}
