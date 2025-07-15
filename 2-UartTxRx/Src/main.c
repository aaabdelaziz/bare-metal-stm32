#define STM32F091xC
#include "stm32f0xx.h"

// Define GPIOA clock enable macro
#define GPIOAEN    (1U<<17)   // Bit 17: I/O port A clock enable
#define UART2EN    (1U<<17)   // Bit 17: USART2 clock enable

// Baudrate calculation (for 9600 baud with 8 MHz PCLK)
#define SYS_FREQ     8000000
#define APB1_CLK     SYS_FREQ
#define UART_BAUDRATE 9600

static void uart_tx_init(void);
static uint16_t compute_uart_bd(uint32_t periph_clk,uint32_t baudrate);


int main(void)
{
    uart_tx_init();

    while (1)
    {
        // Wait until TXE (Transmit data register empty) flag is set
        while (!(USART2->ISR & USART_ISR_TXE)) {}


        // Send a byte (for example, ASCII 'A')
        USART2->TDR = 'A';

        // Wait a bit before sending next byte
        for (volatile int i = 0; i < 100000; i++);
    }

    return 0;
}

static void uart_tx_init(void)
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

static uint16_t compute_uart_bd(uint32_t periph_clk, uint32_t baudrate)
{
    return (periph_clk + (baudrate/2U)) / baudrate;
}
