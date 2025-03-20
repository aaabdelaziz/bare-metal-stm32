
// For Buses Peripheral Addresses
#define PERIPH_BASE           (0x40000000UL)
#define AHB2_PERIPH_OFFSET    (0x0800 0000UL)
#define AHB2_PERIPH_BASE      (PERIPH_BASE + AHB2_PERIPH_OFFSET)  // 0x4800 0000

#define AHB1_PERIPH_OFFSET    (0x20000UL)
#define AHB1_PERIPH_BASE      (PERIPH_BASE + AHB1_PERIPH_OFFSET)  // 0x4002 0000


// For GPIO
#define GPIOA_OFFSET          (0x0000U)                           // 0x0000 0000
#define GPIO_BASE 			  (AHB2_PERIPH_BASE + GPIOA_OFFSET)   // 0x4800 0000


// For Clock
#define RCC_OFFSET    		  (0x1000UL)
#define RCC_BASE 			  (AHB1_PERIPH_BASE + RCC_OFFSET)    // 0x4002 1000

// Clock enable register (RCC_AHBENR)
#define AHB1EN_RCC_OFFSET     (0x14UL)
#define AHB1EN_RCC_BASE       (RCC_BASE + AHB1EN_RCC_OFFSET)     // 0x4002 1014

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
