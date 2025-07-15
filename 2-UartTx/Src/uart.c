/*
 * uart.c
 *
 *  Created on: Jul 15, 2025
 *      Author: ahmedabdelaziz
 */


#include "uart.h"


void uart_tx_init(void)
{
    /************ Configure UART GPIO pins ************/
    // Enable clock access to GPIOA
    RCC->AHBENR |= GPIOAEN;

    // Set PA2 and PA3 to alternate function mode
    GPIOA->MODER &= ~((1U<<4) | (1U<<6));  // Clear bits
    GPIOA->MODER |=  ((1U<<5) | (1U<<7));  // Set bits: 10 = AF mode for PA2, PA3

    // Set AF1 (USART2) for PA2 and PA3
    GPIOA->AFR[0] &= ~((0xF << 8) | (0xF << 12));  // Clear bits for AFRL PA2, PA3
    GPIOA->AFR[0] |=  ((1 << 8) | (1 << 12));      // AF1 for USART2 on PA2 and PA3

    /************ Configure USART2 module ************/
    // Enable clock access to USART2
    RCC->APB1ENR |= UART2EN;

    // Disable USART before configuration
    USART2->CR1 &= ~USART_CR1_UE;

    // Set baudrate
    USART2->BRR = compute_uart_bd(APB1_CLK, UART_BAUDRATE);

    // Set word length to 8 bits, no parity, 1 stop bit (default)
    USART2->CR1 = USART_CR1_TE | USART_CR1_RE;  // Enable transmitter and receiver

    // Enable USART2
    USART2->CR1 |= USART_CR1_UE;
}

uint16_t compute_uart_bd(uint32_t periph_clk, uint32_t baudrate)
{
    return (periph_clk + (baudrate/2U)) / baudrate;
}
