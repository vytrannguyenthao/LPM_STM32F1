#ifndef	__GPIO_H__
#define __GPIO_H__

#include "stm32f1xx.h"
#include "stdio.h"

/*Define GPIO*/
#define GPIO_A		(1U<<2)
#define GPIO_B		(1U<<3)
#define GPIO_C		(1U<<4)

/*Define GPIO pin mode*/
#define INPUT				(0U)
#define OUTPUT_10MHZ		(1U)
#define OUTPUT_2MHZ			(2U)
#define OUTPUT_50MHZ		(3U)

/*Define GPIO CNF bits*/
#define  INPUT_ANALOG       (0U) /*!< 00: Analog mode  */
#define  INPUT_FLOATING 	(4U) /*!< 01: Floating input (reset state)  */
#define  INPUT_PU_PD   		(8U) /*!< 10: Input with pull-up / pull-down  */
#define  OUTPUT_GP_PP   	(0U) /*!< 00: General purpose output push-pull  */
#define  OUTPUT_GP_OD   	(4U) /*!< 01: General purpose output Open-drain  */
#define  OUTPUT_AF_PP   	(8U) /*!< 10: Alternate function output Push-pull  */
#define  OUTPUT_AF_OD   	(CU) /*!< 11: Alternate function output Open-drain  */

/*Define GPIO Pin state*/
#define HIGH	1
#define LOW		0

/*Define peripheral pins*/
#define LED			GPIO_C, 13
#define SPI1_NSS	GPIO_A, 4
#define SPI1_SCK	GPIO_A, 5
#define SPI1_MISO	GPIO_A, 6
#define SPI1_MOSI	GPIO_A, 7


void GPIO_Pin_Configure(uint8_t GPIO_x, uint32_t Pin, uint32_t MODE, uint32_t FUNC);
void GPIO_set_out_pin(uint8_t GPIO_x, uint32_t Pin, uint8_t STATE);
void GPIO_toogle_out_pin(uint8_t GPIO_x, uint32_t Pin);
void Wakeup_pin_init(void);

#endif
