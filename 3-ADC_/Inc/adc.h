/*
 * adc.h
 *
 *  Created on: Jul 8, 2025
 *      Author: ahmedabdelaziz
 */

#ifndef ADC_H_
#define ADC_H_

#include "stm32f0xx.h"

#define GPIOEN      (1U<<0)
#define ADC1EN      (1U<<8)

void pa1_adc_init(void);

ADC_TypeDef hadc1;

#endif /* ADC_H_ */
