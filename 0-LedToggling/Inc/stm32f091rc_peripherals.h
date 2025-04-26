
// stm32f091rc_peripherals.h

#ifndef STM32F091RC_PERIPHERALS_H
#define STM32F091RC_PERIPHERALS_H

#include <stdint.h> // for standard types

// Base addresses
#define FLASH_BASE          (0x08000000UL) // Flash memory
#define SRAM_BASE           (0x20000000UL) // SRAM
#define PERIPH_BASE         (0x40000000UL) // Peripheral base

// Peripheral bus bases
#define APB1PERIPH_BASE     (PERIPH_BASE)
#define APB2PERIPH_BASE     (PERIPH_BASE + 0x00010000UL)
#define AHBPERIPH_BASE      (PERIPH_BASE + 0x00020000UL)

// AHB peripherals
#define RCC_BASE            (AHBPERIPH_BASE + 0x00001000UL)
#define FLASH_R_BASE        (AHBPERIPH_BASE + 0x00002000UL)
#define GPIOA_BASE          (AHBPERIPH_BASE + 0x00000000UL)
#define GPIOB_BASE          (AHBPERIPH_BASE + 0x00000400UL)
#define GPIOC_BASE          (AHBPERIPH_BASE + 0x00000800UL)
#define GPIOD_BASE          (AHBPERIPH_BASE + 0x00000C00UL)
#define GPIOE_BASE          (AHBPERIPH_BASE + 0x00001000UL)
#define GPIOF_BASE          (AHBPERIPH_BASE + 0x00001400UL)

// APB1 peripherals
#define TIM2_BASE           (APB1PERIPH_BASE + 0x00000000UL)
#define TIM3_BASE           (APB1PERIPH_BASE + 0x00000400UL)
#define TIM6_BASE           (APB1PERIPH_BASE + 0x00001000UL)
#define TIM7_BASE           (APB1PERIPH_BASE + 0x00001400UL)
#define USART2_BASE         (APB1PERIPH_BASE + 0x00004400UL)
#define USART3_BASE         (APB1PERIPH_BASE + 0x00004800UL)
#define I2C1_BASE           (APB1PERIPH_BASE + 0x00005400UL)
#define I2C2_BASE           (APB1PERIPH_BASE + 0x00005800UL)

// APB2 peripherals
#define SYSCFG_BASE         (APB2PERIPH_BASE + 0x00000000UL)
#define EXTI_BASE           (APB2PERIPH_BASE + 0x00000400UL)
#define USART1_BASE         (APB2PERIPH_BASE + 0x00003800UL)
#define SPI1_BASE           (APB2PERIPH_BASE + 0x00003000UL)

// Clock
#define RCC_OFFSET    		  (0x1000UL)
#define RCC_BASE 			  (AHB1_PERIPH_BASE + RCC_OFFSET)    // 0x4002 1000

// Other useful peripheral bases
#define ADC_BASE            (APB2PERIPH_BASE + 0x00002400UL)
#define DAC_BASE            (APB1PERIPH_BASE + 0x00007400UL)
#define DMA1_BASE           (AHBPERIPH_BASE + 0x00000000UL)

// System Control Space
#define SCS_BASE            (0xE000E000UL)
#define NVIC_BASE           (SCS_BASE + 0x0100UL)
#define SCB_BASE            (SCS_BASE + 0x0D00UL)

// Mode Register (Define In/Out)
#define GPIOA_MODER      	  (0x28000000UL)

//Set GPIOA-PA5 to output
#define ODR_OFFSET            (1U<<10)                            // Set Bit 10 to 1
#define GPIOA_ODR 			  (GPIOA_ODR + ODR_OFFSET)

// Enable GPIOA Clock
#define IOPA  				  (1U<<0)

//PIN5
#define PIN5    			  (1U<<5)
#define LED_PIN_NUM           PIN5

#endif // STM32F091RC_PERIPHERALS_H