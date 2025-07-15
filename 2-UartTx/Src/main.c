#include "uart.h"

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
