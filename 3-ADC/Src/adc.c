/*
 * adc.c
 *
 *  Created on: Jul 8, 2025
 *      Author: ahmedabdelaziz
 */

#include "adc.h"


/**
 * @brief Initialize GPIO for ADC channel (e.g., PA1)
 */
void pa1_adc_init(void)
{
    /* Step 1: Enable clock for GPIOA */
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /* Step 2: Configure PA1 as analog input (ADC input) */
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_1;                // PA1
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;         // set to analog mode
    GPIO_InitStruct.Pull = GPIO_NOPULL;              // no pull-up or pull-down
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}


/**
 * @brief Initialize ADC1 for a single channel (e.g., Channel 1 on PA1)
 */
void adc1_init(void)
{
    /* Step 1: Enable clock for ADC1 */
    __HAL_RCC_ADC1_CLK_ENABLE();

    /* Step 2: Configure the ADC peripheral */
    hadc1.Instance = ADC1;

    hadc1.Init.OversamplingMode = DISABLE;                                         // oversampling disabled
    hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;                          // set clock divider
    hadc1.Init.Resolution = ADC_RESOLUTION_12B;                                    // 12-bit resolution
    hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;                                    // single channel
    hadc1.Init.ContinuousConvMode = DISABLE;                                       // one shot mode
    hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;               // software trigger
    hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;                                    // right aligned data
    hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;                                 // EOC after each conversion
    hadc1.Init.DMAContinuousRequests = DISABLE;                                    // no DMA
    hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;                                   // preserve data if overrun occurs

    if (HAL_ADC_Init(&hadc1) != HAL_OK)
    {
        /* Initialization Error */
        Error_Handler();
    }
}


