#include "stm32f0xx.h"


//define GPIOA for USART
#define GPIOAEN

// Enable the UART2 Tx PIN PA2

// Enable the UART2 Rx PIN PA3

#define


int main(void)
{

	// find out which IO pins that activate the USART

	// Configure UART Pins



	return 0;

}

void uart_tx_init(void)
{


	// APB peripheral reset register 1 (RCC_APB1RSTR)
	// Set bit 17 for USART2 RST
	/*
	 * Bit 17 USART2RST: USART2 reset
	 *	Set and cleared by software.
	 *  0: No effect
	 *	1: Reset USART2
	 *
	 * */


	//RCC_APB1ENR)
	// set bit 17 for USART2 EN
	/*
	* USART2EN: USART2 clock enable
	* Set and cleared by software.
	* 0: USART2 clock disabled
	* 1: USART2 clock enabled	
	*/

	//RCC_CFGR3) 
	/* bits 17 - 16 USART2SW[1:0]: 
	* USART2SW[1:0]: USART2 clock source selection (available only on STM32F07x and
	* 	STM32F09x devices)
	* 	This bit is set and cleared by software to select the USART2 clock source.
	* 	00: PCLK selected as USART2 clock source (default)
	* 	01: System clock (SYSCLK) selected as USART2 clock
	* 	10: LSE clock selected as USART2 clock
	* 	11: HSI clock selected as USART2 clock
 	*/

 	// RCC_APB1RSTR  --> bit 17 = USART2RST
	// RCC_APB1ENR   -->  bit 17 = USART2EN
	// RCC_CFGR3 	 -->   Bits 17 / 16 = USART2SW[1:0]

	// Peripheral alternate function:
	// – Connect the I/O to the desired AFx in one of the GPIOx_AFRL or GPIOx_AFRH
	// register.
	// – Select the type, pull-up/pull-down and output speed via the GPIOx_OTYPER,
	// GPIOx_PUPDR and GPIOx_OSPEEDER registers, respectively.
	// – Configure the desired I/O as an alternate function in the GPIOx_MODER register.

	// When the I/O port is programmed as alternate function:
	// • The output buffer can be configured in open-drain or push-pull mode
	// • The output buffer is driven by the signals coming from the peripheral (transmitter
	// enable and data)
	// • The Schmitt trigger input is activated
	// The weak pull-up and pull-down resistors are activated or not depending on the value
	// in the GPIOx_PUPDR register
	// • The data present on the I/O pin are sampled into the input data register every AHB
	// clock cycle
	// • A read access to the input data register gets the I/O state
	



	/** Configure teht e uart gpio pin **/
	// Enable the clock access the the gpioa
	RCC->AHBENR |= GPIOAEN;

	// Set PA2 mode to the alternate function
	GPIOA->MODER &=~ (1U<<16);

	// Set the PA2 alternate funtion type to UART_Tx (AF07)
	// looking to the alternate function map table and get the AFL AFR registers _> set it in GPIO_AFRL register 

	// Config the usart module
	// Enable the clock acces to the UART
	// Config baudrate
	//config the transfer direction

	//Enalbe the UART module

}