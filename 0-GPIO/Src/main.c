
// For Buses Peripheral Addresses
#define PERIPH_BASE           (0x40000000UL)
#define AHB2_PERIPH_OFFSET    (0x0800 0000UL)
#define AHB2_PERIPH_BASE      (PERIPH_BASE + AHB2_PERIPH_OFFSET)

#define AHB1_PERIPH_OFFSET    (0x20000UL)
#define AHB1_PERIPH_BASE      (PERIPH_BASE + AHB1_PERIPH_OFFSET)


// For GPIO
#define GPIOA_OFFSET          (0x0000U)    // 0x0000 0000
#define GPIO_BASE 			  (AHB2_PERIPH_BASE + GPIOA_OFFSET)


// For Clock
#define RCC_OFFSET    		  (0x1000UL)
#define RCC_BASE 			  (AHB1_PERIPH_BASE + RCC_OFFSET)


//Enable the AHB2 peripheral
