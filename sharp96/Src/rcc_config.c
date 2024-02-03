#include "rcc_config.h"

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow :
  *            System Clock source            = HSI
  *            SYSCLK(Hz)                     = 8 000 000
  *            HCLK(Hz)                       = 8 000 000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 1
  *            APB2 Prescaler                 = 1
  *            HSI Frequency(Hz)              = 8 000 000
  *            VDD(V)                         = 3.3
  *            Flash Latency(WS)              = 0
  * @param  None
  * @retval None
  */
void SysClockConfig(void){
	/***********************Steps followed***********************
	 * 1.	ENABLE HSI and wait for HSI to become Ready.
	 * 2.	Set the POWER ENABLE CLOCK.
	 * 3.	Configure the FLASH PREFETCH and the LATENCY Related Setting.
	 * 4.	Configure the PRESCALARS HCLK, PCLK1, PCLK2.
	 * 5.	Configure the MAIN PLL.
	 * 6.	Enable the PLL and wait for it to become ready.
	 * 7.	Select the Clock Source and wait for it to be set.
	 ***********************************************************/

	/*1.ENABLE HSI and wait for HSE to become Ready*/
	/*Enable HSI*/
	RCC->CR |= RCC_CR_HSION;

	/*Wait for HSI to become ready*/
	while(!(RCC->CR & RCC_CR_HSIRDY));

	/*2.Set the POWER ENABLE CLOCK*/
	RCC->APB1ENR |= RCC_APB1ENR_PWREN;

	/*3.Configure the FLASH PREFETCH and the LATENCY Related Setting*/
	/*Enable the flash prefetch*/
	FLASH->ACR |= FLASH_ACR_PRFTBE;

	/*Wait for flash prefetch to become enable*/
	while (!(FLASH->ACR & FLASH_ACR_PRFTBS));

	/*Set the flash latency*/
	FLASH->ACR |= FLASH_ACR_LATENCY_0;

	/*4.Configure the PRESCALERS HCLK, PCLK1, PCLK2*/
	/*Set the AHB prescaler*/
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;

	/*Set the AHB1 prescaler*/
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV1;

	/*Set the AHB2 prescaler*/
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;

	/*7.Select the Clock Source and wait for it to be set*/
	/*Select the Clock Source*/
	RCC->CFGR |= RCC_CFGR_SWS_HSI;

	/*Wait for clock source setting completely*/
	//while ((RCC->CFGR & ((1<<2) | (1<<3))));
}
