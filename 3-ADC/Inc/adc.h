/*
 * adc.h
 *
 *  Created on: Jul 15, 2025
 *      Author: ahmedabdelaziz
 */

#ifndef ADC_H_
#define ADC_H_


#define GPIOAEN 		(1U<<0)
#define ADC1EN 			(1U<<9)    // Enable ADC1 connected to APB bus


static void pa1_adc_init();

#endif /* ADC_H_ */
