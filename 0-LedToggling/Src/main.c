
#include <stm32f091rc_peripherals.h>


int main ()
{


	/* (1) Enable the peripheral clock of GPIOA */
	RCC_AHB1EN_R |= GPIOAEN;

	/* (2) Set PA5 as Output PIN */
	GPIOA_MODE_R |= (1U << 10);    // Set bit 10 to 1
	GPIOA_MODE_R &= ~(1U << 11);    // Set bit 11 to 0

	while(1)
	{
		/* (3) Toggle PA5 */
		GPIOA_ODR_R  ^= LED_PIN_NUM;
    	for(int i=0; i<100000;i++);
	}

  return 0;
}
