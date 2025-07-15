/*
 * uart.h
 *
 *  Created on: Jul 15, 2025
 *      Author: ahmedabdelaziz
 */

#ifndef UART_H_
#define UART_H_

#include "stm32f0xx.h"

// Define GPIOA clock enable macro
#define GPIOAEN    (1U<<17)   // Bit 17: I/O port A clock enable
#define UART2EN    (1U<<17)   // Bit 17: USART2 clock enable

// Baudrate calculation (for 9600 baud with 8 MHz PCLK)
#define SYS_FREQ     8000000
#define APB1_CLK     SYS_FREQ
#define UART_BAUDRATE 9600

void uart_tx_init(void);
uint16_t compute_uart_bd(uint32_t periph_clk, uint32_t baudrate);



#endif /* UART_H_ */
