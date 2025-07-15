#include "adc.h"


int main(void)
{

	// Initialize ADC to read from internal temperature sensor
	pa1_adc_init();

	while(1)
	{
		adc_internal_temp_read();
	}

    return 0;
}

