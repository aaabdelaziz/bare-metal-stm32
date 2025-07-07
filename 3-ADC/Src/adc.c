/*
 * adc.c
 *
 *  Created on: Jul 8, 2025
 *      Author: ahmedabdelaziz
 */

#include "adc.h"

void pa1_adc_init(void)
{

	/** configuring the ADC GPIO pins **/

	/*  Enable clock access to GPIOA */
	RCC->AHB1ENR |= GPIOEN;

	/* Set the modfe of the PA1 to analog */


	/** configuring the ADC Module **/

	/* Set */

	/* Set */
	 /* Configure the ADC peripheral */
	  hadc1.Instance = ADC1;
	  hadc1.Init.OversamplingMode = DISABLE;                           // disable oversampling
	  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;            // set clock prescaler
	  hadc1.Init.Resolution = ADC_RESOLUTION_12B;                      // 12-bit resolution
	  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;                      // single channel
	  hadc1.Init.ContinuousConvMode = DISABLE;                         // single conversion
	  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE; // software trigger
	  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;    				   // data right aligned
	  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV; 				   // end of conversion after one conversion
	  hadc1.Init.DMAContinuousRequests = DISABLE;    				   // no DMA
	  hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;   				   // preserve data in case of overrun

	  if (HAL_ADC_Init(&hadc1) != HAL_OK)
	  {
	    // Initialization Error
	    Error_Handler();
	  }

}

#include "adc.h"

