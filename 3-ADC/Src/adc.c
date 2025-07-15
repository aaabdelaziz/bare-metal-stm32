/*
 * adc.c
 *
 *  Created on: Jul 15, 2025
 *      Author: ahmedabdelaziz
 */
#include "adc.h"

void pa1_adc_init()
{
	/***** Config the 12 bit ADC *********/

	/* 0. Set PA1 analog mode for GPIOA */
	//	Don't forget VDDA must be ≥ 2.4V for ADC and temp sensor to function properly.
	//	Enable SYSCFG and GPIOA clocks only if using external ADC channels (not needed here, but Ok to configure).
	//	ADC_IN16 is not connected to any external pin, it's internal.
	/* (1) Enable the peripheral clock of GPIOA */
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	/* (2) Select analog mode for PA1 - by setting PA1 to alternate function */
	GPIOA->MODER |= GPIO_MODER_MODER1; /* (2) */


	/* 1. Enable ADC interface Clock */
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

	/* 2. Configure ADC Module */
	// ADC Common Configuration Register (Enable temperature sensor connected to channel ADC_IN16)
	// TSEN: enables internal temperature sensor
	// VREFEN: enables internal reference voltage (required for temperature sensor)
	ADC->CCR |= ADC_CCR_TSEN | ADC_CCR_VREFEN;

	// 3. Configure prescaler: default is fine (PCLK/4)
	ADC1->CR |= ADC_CR_ADCAL;           // Start calibration
	while (ADC1->CR & ADC_CR_ADCAL);    // Wait for calibration to complete

	// 4. DC Configuration register (Set ADC Resolution & Align Data)
	ADC1->CFGR1 &= ~ADC_CFGR1_RES;     // 12-bit resolution
	ADC1->CFGR1 &= ~ADC_CFGR1_ALIGN;   // Right-aligned

	// 5. Select Channel ADC_IN16 (Temperature Sensor)
	//	SCANDIR: Scan sequence direction
	//	This bit is set and cleared by software to select the direction in which the channels will be
	//	scanned in the sequence.
	//	0: Upward scan (from CHSEL0 to CHSEL18)
	//	1: Backward scan (from CHSEL18 to CHSEL0)
	ADC1->CHSELR = ADC_CHSELR_CHSEL16;  // Only select channel 16

	//	6. Enable ADC and Wait for Readiness
	ADC1->CR |= ADC_CR_ADEN;
	while (!(ADC1->ISR & ADC_ISR_ADRDY)); // Wait until ADC is ready

	/* Conversion sequence start */
	/* Conversion sequence Length */

}

void adc_internal_temp_read()
{
	float temp_celsius=0.0;

	//	7. Start Conversion and Read Value
	ADC1->CR |= ADC_CR_ADSTART;               // Start conversion
	while (!(ADC1->ISR & ADC_ISR_EOC));       // Wait for end of conversion
	uint16_t adc_value = ADC1->DR;            // Read ADC value
	// Assume: TS_CAL1 = 30°C @ 1.43V, TS_CAL2 = 110°C @ 1.85V


	//float temperature = ((adc_value * VREF / 4095.0) - V25) / Avg_Slope + 25;
	temp_celsius = ((adc_value * 3.3 / 4095.0) - 1.43) / 0.0043 + 25;

	/* Temperature sensor calibration value address */
	//	#define TEMP110_CAL_ADDR ((uint16_t*) ((uint32_t) 0x1FFFF7C2))
	//	#define TEMP30_CAL_ADDR ((uint16_t*) ((uint32_t) 0x1FFFF7B8))
	//	#define VDD_CALIB ((uint16_t) (330))
	//	#define VDD_APPLI ((uint16_t) (300))
	//
	//	int32_t temperature; /* will contain the temperature in degrees Celsius */
	//	temperature = (((int32_t) ADC1->DR * VDD_APPLI / VDD_CALIB)	- (int32_t) *TEMP30_CAL_ADDR );
	//	temperature = temperature * (int32_t)(110 - 30);
	//	temperature = temperature / (int32_t)(*TEMP110_CAL_ADDR - *TEMP30_CAL_ADDR);
	//	temperature = temperature + 30;

}
