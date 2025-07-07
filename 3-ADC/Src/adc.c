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



