
 /*==============================================================================
 * File:        stm32f091rc_gpioa.h
 * Description: This file contains GPIOA registers in stm32f091rc MCU
 * Author:      Ahmed Abdelaziz
 * Created:     26/04/2025
 * 
 *==============================================================================
 */

#ifndef STM32F091RC_GPIOA_H
#define STM32F091RC_GPIOA_H

    /*
    ==============================================================================+
    GPIO Registers Map (STM32F091RC)                                              |
    ==============================================================================+
    | Offset | Register      | Description                                        |
    +--------+---------------+----------------------------------------------------+
    | 0x00   | GPIOA_MODER    | GPIO port mode register                           |
    | 0x04   | GPIOA_OTYPER   | GPIO port output type register                    |
    | 0x08   | GPIOA_OSPEEDR  | GPIO port output speed register                   |
    | 0x0C   | GPIOA_PUPDR    | GPIO port pull-up/pull-down reg.                  |
    | 0x10   | GPIOA_IDR      | GPIO port input data register                     |
    | 0x14   | GPIOA_ODR      | GPIO port output data register                    |
    | 0x18   | GPIOA_BSRR     | GPIO port bit set/reset register                  |
    | 0x1C   | GPIOA_LCKR     | GPIO port configuration lock reg.                 |
    | 0x20   | GPIOA_AFRL     | GPIO alternate function low reg.                  |
    | 0x24   | GPIOA_AFRH     | GPIO alternate function high reg.                 |
    | 0x28   | GPIOA_BRR      | GPIO bit reset register                           |
    +-----------------------------------------------------------------------------+

    ===============================================================================
    GPIOA Registers Bit Definitions (STM32F091RC)
    ===============================================================================

    GPIOA_MODER (Mode Register) @ 0x00
    -----------------------------------
    | Bits 31:0 | 2 bits per pin (Pin 15 down to Pin 0):
    | 00: Input mode
    | 01: General purpose output mode
    | 10: Alternate function mode
    | 11: Analog mode

    GPIOA_OTYPER (Output Type Register) @ 0x04
    -------------------------------------------
    | Bit 15 to Bit 0: One bit per pin
    | 0: Output push-pull
    | 1: Output open-drain

    GPIOA_OSPEEDR (Output Speed Register) @ 0x08
    ---------------------------------------------
    | Bits 31:0 | 2 bits per pin:
    | 00: Low speed
    | 01: Medium speed
    | 10: High speed
    | 11: Very high speed

    GPIOA_PUPDR (Pull-up/Pull-down Register) @ 0x0C
    ------------------------------------------------
    | Bits 31:0 | 2 bits per pin:
    | 00: No pull-up, pull-down
    | 01: Pull-up
    | 10: Pull-down
    | 11: Reserved

    GPIOA_IDR (Input Data Register) @ 0x10
    ---------------------------------------
    | Bit 15 to Bit 0:
    | 0: Logic level 0 at the input pin
    | 1: Logic level 1 at the input pin

    GPIOA_ODR (Output Data Register) @ 0x14
    ----------------------------------------
    | Bit 15 to Bit 0:
    | 0: Output logic low (0)
    | 1: Output logic high (1)

    GPIOA_BSRR (Bit Set/Reset Register) @ 0x18
    -------------------------------------------
    | Bits 15:0 (BSy): Set corresponding ODR bit (1 = set)
    | Bits 31:16 (BRy): Reset corresponding ODR bit (1 = reset)

    GPIOA_LCKR (Configuration Lock Register) @ 0x1C
    -------------------------------------------------
    | Bit 16 (LCKK): Lock key (must follow locking sequence)
    | Bits 15:0 (LCKy): Lock bits for each pin

    GPIOA_AFRL (Alternate Function Low Register) @ 0x20
    ----------------------------------------------------
    | Bits 31:0 | 4 bits per pin for Pins 0 to 7:
    | 0000: AF0, 0001: AF1, ..., 1111: AF15

    GPIOA_AFRH (Alternate Function High Register) @ 0x24
    -----------------------------------------------------
    | Bits 31:0 | 4 bits per pin for Pins 8 to 15:
    | 0000: AF0, 0001: AF1, ..., 1111: AF15

    GPIOA_BRR (Bit Reset Register) @ 0x28
    --------------------------------------
    | Bit 15 to Bit 0:
    | 1: Reset corresponding ODR bit to 0
    | 0: No action

    ===============================================================================
    */

    typedef struct
    {
        volatile uint32_t MODER;   /*!< GPIO port mode register           (Offset: 0x00) */
        volatile uint32_t OTYPER;  /*!< GPIO port output type register    (Offset: 0x04) */
        volatile uint32_t OSPEEDR; /*!< GPIO port output speed register   (Offset: 0x08) */
        volatile uint32_t PUPDR;   /*!< GPIO port pull-up/pull-down reg.  (Offset: 0x0C) */
        volatile uint32_t IDR;     /*!< GPIO port input data register     (Offset: 0x10) */
        volatile uint32_t ODR;     /*!< GPIO port output data register    (Offset: 0x14) */
        volatile uint32_t BSRR;    /*!< GPIO port bit set/reset register  (Offset: 0x18) */
        volatile uint32_t LCKR;    /*!< GPIO port configuration lock reg. (Offset: 0x1C) */
        volatile uint32_t AFRL;    /*!< GPIO alternate function low reg.  (Offset: 0x20) */
        volatile uint32_t AFRH;    /*!< GPIO alternate function high reg. (Offset: 0x24) */
        volatile uint32_t BRR;     /*!< GPIO port bit reset register      (Offset: 0x28) */
    } GPIO_Type;
   
    // GPIOA Register
    #define GPIOA      	           ((GPIO_Type *) GPIOA_BASE)

    //PIN5
    #define PIN5    			   (1U<<5)
    #define LED_PIN_NUM            PIN5

#endif // STM32F091RC_GPIOA_H