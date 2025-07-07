#include "stm32f0xx.h"
#include "adc.h"

// Define GPIOA clock enable macro
#define GPIOAEN    (1U<<17)   // Bit 17: I/O port A clock enable
#define UART2EN    (1U<<17)   // Bit 17: USART2 clock enable

// Baudrate calculation (for 9600 baud with 8 MHz PCLK)
#define SYS_FREQ     8000000
#define APB1_CLK     SYS_FREQ
#define UART_BAUDRATE 9600

int main(void)
{

    while (1)
    {

    }

    return 0;
}
