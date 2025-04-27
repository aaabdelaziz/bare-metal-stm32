
 /*==============================================================================
 * File:        stm32f091rc_RCC.h
 * Description: This file contains RCC registers in stm32f091rc MCU
 * Author:      Ahmed Abdelaziz
 * Created:     26/04/2025
 * 
 *==============================================================================
 */

#ifndef STM32F091RC_RCC_H
#define STM32F091RC_RCC_H

    /*
    ===============================================================================+
    RCC Registers Map (STM32F091RC)                                                |
    ===============================================================================+
    | Offset | Register            | Description                                   |
    |--------|---------------------|-----------------------------------------------+
    | 0x00   | RCC_CR              | Clock control register                        |
    | 0x04   | RCC_CFGR            | Clock configuration register                  |
    | 0x08   | RCC_CIR             | Clock interrupt register                      |
    | 0x0C   | RCC_APB2RSTR        | APB2 peripheral reset register                |
    | 0x10   | RCC_APB1RSTR        | APB1 peripheral reset register                |
    | 0x14   | RCC_AHBENR          | AHB peripheral clock enable register          |
    | 0x18   | RCC_APB2ENR         | APB2 peripheral clock enable register         |
    | 0x1C   | RCC_APB1ENR         | APB1 peripheral clock enable register         |
    | 0x20   | RCC_BDCR            | Backup domain control register                |
    | 0x24   | RCC_CSR             | Control/status register                       |
    | 0x28   | RCC_AHBRSTR         | AHB peripheral reset register                 |
    | 0x2C   | RCC_CFGR2           | Clock configuration register 2                |
    | 0x30   | RCC_CFGR3           | Clock configuration register 3                |
    ===============================================================================+


    ===============================================================================
    RCC Registers Bit Definitions (Selected Highlights)
    ===============================================================================

    RCC_CR (Clock Control Register) @ 0x00
    ---------------------------------------
    | Bit 0: HSION     (Internal High Speed clock enable)
    | Bit 1: HSIRDY    (Internal High Speed clock ready flag)
    | Bit 8: HSEON     (External High Speed clock enable)
    | Bit 9: HSERDY    (External High Speed clock ready flag)
    | Bit 16: PLLON    (PLL enable)
    | Bit 25: CSSON    (Clock Security System enable)

    RCC_CFGR (Clock Configuration Register) @ 0x04
    -----------------------------------------------
    | Bits 1:0   SW[1:0]    (System clock switch)
    | Bits 3:2   SWS[1:0]   (System clock switch status)
    | Bits 7:4   HPRE[3:0]  (AHB prescaler)
    | Bits 10:8  PPRE[2:0]  (APB low-speed prescaler)
    | Bit 15     MCO        (Microcontroller clock output)

    RCC_AHBENR (AHB Clock Enable Register) @ 0x14
    ----------------------------------------------
    | Bit 0: DMAEN    (DMA clock enable)
    | Bit 17: GPIOAEN (GPIOA clock enable)
    | Bit 18: GPIOBEN (GPIOB clock enable)
    | Bit 19: GPIOCEN (GPIOC clock enable)
    | Bit 22: CRCEN   (CRC clock enable)

    RCC_APB2ENR (APB2 Clock Enable Register) @ 0x18
    ------------------------------------------------
    | Bit 0: SYSCFGEN (System configuration controller clock enable)
    | Bit 9: USART1EN (USART1 clock enable)
    | Bit 14: TIM1EN  (Timer 1 clock enable)

    RCC_APB1ENR (APB1 Clock Enable Register) @ 0x1C
    ------------------------------------------------
    | Bit 14: I2C1EN  (I2C1 clock enable)
    | Bit 17: USART2EN (USART2 clock enable)
    ===============================================================================
    */

    typedef struct
    {
        volatile uint32_t CR;         /*!< Clock control register                     (Offset: 0x00) */
        volatile uint32_t CFGR;       /*!< Clock configuration register               (Offset: 0x04) */
        volatile uint32_t CIR;        /*!< Clock interrupt register                   (Offset: 0x08) */
        volatile uint32_t APB2RSTR;   /*!< APB2 peripheral reset register             (Offset: 0x0C) */
        volatile uint32_t APB1RSTR;   /*!< APB1 peripheral reset register             (Offset: 0x10) */
        volatile uint32_t AHBENR;     /*!< AHB peripheral clock enable register       (Offset: 0x14) */
        volatile uint32_t APB2ENR;    /*!< APB2 peripheral clock enable register      (Offset: 0x18) */
        volatile uint32_t APB1ENR;    /*!< APB1 peripheral clock enable register      (Offset: 0x1C) */
        volatile uint32_t BDCR;       /*!< Backup domain control register             (Offset: 0x20) */
        volatile uint32_t CSR;        /*!< Control/status register                    (Offset: 0x24) */
        volatile uint32_t AHBRSTR;    /*!< AHB peripheral reset register              (Offset: 0x28) */
        volatile uint32_t CFGR2;      /*!< Clock configuration register 2             (Offset: 0x2C) */
        volatile uint32_t CFGR3;      /*!< Clock configuration register 3             (Offset: 0x30) */
    } RCC_Type;

    // RCC Register
    #define RCC           ((RCC_Type *) RCC_BASE)

    // Enable GPIOA clock
    #define GPIOAEN       (1U<<17)

#endif // STM32F091RC_RCC_H