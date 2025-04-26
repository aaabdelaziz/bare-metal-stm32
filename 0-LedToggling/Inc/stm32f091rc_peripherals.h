/*==============================================================================
 * File:        stm32f091rc_peripherals.h
 * Description: This file contain base addresses for most imortant peripherals in stm32f091rc MCU
 * Author:      Ahmed Abdelaziz
 * Created:     25/04/2025
 * 
 * Notes:
 * - Peripherals are added basded on need.
 *==============================================================================
 */

#ifndef STM32F091RC_PERIPHERALS_H
#define STM32F091RC_PERIPHERALS_H

    #include <stdint.h> // for standard types

    /*------------------------------------------------------------------------------
    * Offset Definitions:
    * These macros define register offsets relative to the base address.
    * Used for register access in memory-mapped I/O operations.
    *----------------------------------------------------------------------------*/
    // Peripheral bus offsets
    #define APB2PERIPH_OFFSET     (0x00010000UL)
    #define AHB1PERIPH_OFFSET     (0x00020000UL)
    #define AHB2PERIPH_OFFSET     (0x08000000UL)
    
    // AHB2 peripherals offsets
    #define GPIOA_OFFSET          (0x00000000UL)
    #define GPIOB_OFFSET          (0x00000400UL)
    #define GPIOC_OFFSET          (0x00000800UL)
    #define GPIOD_OFFSET          (0x00000C00UL)
    #define GPIOE_OFFSET          (0x00001000UL)
    #define GPIOF_OFFSET          (0x00001400UL)

    // AHB1 peripherals offsets
    #define DMA_OFFSET            (0x00000000UL)
    #define RCC_OFFSET            (0x00001000UL)
    #define FLASH_R_OFFSET        (0x00002000UL)

    // APB1 peripherals offsets
    #define TIM2_OFFSET           (0x00000000UL)
    #define TIM3_OFFSET           (0x00000400UL)
    #define TIM6_OFFSET           (0x00001000UL)
    #define TIM7_OFFSET           (0x00001400UL)
    #define TIM14_OFFSET          (0x00002000UL)
    #define USART2_OFFSET         (0x00004400UL)
    #define USART3_OFFSET         (0x00004800UL)
    #define USART4_OFFSET         (0x00004C00UL)
    #define USART5_OFFSET         (0x00005000UL)
    #define I2C1_OFFSET           (0x00005400UL)
    #define I2C2_OFFSET           (0x00005800UL)
    #define SPI2_OFFSET           (0x00003800UL)
    #define DAC_OFFSET            (0x00007400UL)

    // APB2 peripherals offsets
    #define SYSCFG_OFFSET         (0x00000000UL)
    #define EXTI_OFFSET           (0x00000400UL)
    #define USART1_OFFSET         (0x00003800UL)
    #define USART6_OFFSET         (0x00001400UL)
    #define USART7_OFFSET         (0x00001800UL)
    #define USART8_OFFSET         (0x00001C00UL)
    #define SPI1_OFFSET           (0x00003000UL)
    #define ADC_OFFSET            (0x00002400UL)
    #define TIM1_OFFSET           (0x00002C00UL)
    #define TIM15_OFFSET          (0x00004000UL)
    #define TIM16_OFFSET          (0x00004400UL)
    #define TIM17_OFFSET          (0x00004800UL)

    // System Control Space offsets
    #define NVIC_OFFSET           (0x0100UL)
    #define SCB_OFFSET            (0x0D00UL)

    //Set GPIOA-PA5 to output
    #define ODR_OFFSET            (1U<<10) 

    /*------------------------------------------------------------------------------
    * Base Definitions:
    * These macros define register offsets relative to the base address.
    * Used for register access in memory-mapped I/O operations.
    *----------------------------------------------------------------------------*/

    // Base addresses
    #define FLASH_BASE          (0x08000000UL) // Flash memory
    #define SRAM_BASE           (0x20000000UL) // SRAM
    #define PERIPH_BASE         (0x40000000UL) // Peripheral base
    
    // Peripheral bus bases
    #define APB1PERIPH_BASE     (PERIPH_BASE)
    #define APB2PERIPH_BASE     (PERIPH_BASE + APB2PERIPH_OFFSET)
    #define AHB1PERIPH_BASE     (PERIPH_BASE + AHB1PERIPH_OFFSET)
    #define AHB2PERIPH_BASE     (PERIPH_BASE + AHB2PERIPH_OFFSET)

    // AHB1 peripherals base
    #define RCC_BASE            (AHB1PERIPH_BASE + RCC_OFFSET)              // Clock
    #define FLASH_R_BASE        (AHB1PERIPH_BASE + FLASH_R_OFFSET)          
    #define DMA_BASE            (AHB1PERIPH_BASE + DMA1_OFFSET)

    // AHB2 peripherals base
    #define GPIOA_BASE          (AHB2PERIPH_BASE + GPIOA_OFFSET)            
    #define GPIOB_BASE          (AHB2PERIPH_BASE + GPIOB_OFFSET)
    #define GPIOC_BASE          (AHB2PERIPH_BASE + GPIOC_OFFSET)
    #define GPIOD_BASE          (AHB2PERIPH_BASE + GPIOD_OFFSET)
    #define GPIOE_BASE          (AHB2PERIPH_BASE + GPIOE_OFFSET)
    #define GPIOF_BASE          (AHB2PERIPH_BASE + GPIOF_OFFSET)

    // APB1 peripherals base
    #define TIM2_BASE           (APB1PERIPH_BASE + TIM2_OFFSET)
    #define TIM3_BASE           (APB1PERIPH_BASE + TIM3_OFFSET)
    #define TIM6_BASE           (APB1PERIPH_BASE + TIM6_OFFSET)
    #define TIM7_BASE           (APB1PERIPH_BASE + TIM7_OFFSET)
    #define TIM14_BASE          (APB1PERIPH_BASE + TIM14_OFFSET)
    #define USART2_BASE         (APB1PERIPH_BASE + USART2_OFFSET)
    #define USART3_BASE         (APB1PERIPH_BASE + USART3_OFFSET)
    #define USART4_BASE         (APB1PERIPH_BASE + USART4_OFFSET)
    #define USART5_BASE         (APB1PERIPH_BASE + USART5_OFFSET)
    #define I2C1_BASE           (APB1PERIPH_BASE + I2C1_OFFSET)
    #define I2C2_BASE           (APB1PERIPH_BASE + I2C2_OFFSET)
    #define SPI2_BASE           (APB1PERIPH_BASE + SPI2_OFFSET)
    #define DAC_BASE            (APB1PERIPH_BASE + DAC_OFFSET)

    // APB2 peripherals base
    #define SYSCFG_BASE         (APB2PERIPH_BASE + SYSCFG_OFFSET)
    #define EXTI_BASE           (APB2PERIPH_BASE + EXTI_OFFSET)
    #define USART1_BASE         (APB2PERIPH_BASE + USART1_OFFSET)
    #define USART6_BASE         (APB2PERIPH_BASE + USART6_OFFSET)
    #define USART7_BASE         (APB2PERIPH_BASE + USART7_OFFSET)
    #define USART8_BASE         (APB2PERIPH_BASE + USART8_OFFSET)
    #define SPI1_BASE           (APB2PERIPH_BASE + SPI1_OFFSET)
    #define ADC_BASE            (APB2PERIPH_BASE + ADC_OFFSET)
    #define TIM1_BASE           (APB2PERIPH_BASE + TIM1_OFFSET)
    #define TIM15_BASE          (APB2PERIPH_BASE + TIM15_OFFSET)
    #define TIM16_BASE          (APB2PERIPH_BASE + TIM16_OFFSET)
    #define TIM17_BASE          (APB2PERIPH_BASE + TIM17_OFFSET)

    // System Control Space base
    #define SCS_BASE            (0xE000E000UL)
    #define NVIC_BASE           (SCS_BASE + NVIC_OFFSET)
    #define SCB_BASE            (SCS_BASE + SCB_OFFSET)

    /*------------------------------------------------------------------------------
    * GPIO Definitions:
    * These macros define gpios operation.
    * Used for register access in memory-mapped I/O operations.
    *----------------------------------------------------------------------------*/

    // Mode Register (Define In/Out) 
    #define GPIOA_MODER      	  (0x28000000UL)

                           // Set Bit 10 to 1
    #define GPIOA_ODR 			  (GPIOA_ODR + ODR_OFFSET)

    // Enable GPIOA Clock
    #define IOPA  				  (1U<<0)

    //PIN5
    #define PIN5    			  (1U<<5)
    #define LED_PIN_NUM           PIN5

#endif // STM32F091RC_PERIPHERALS_H