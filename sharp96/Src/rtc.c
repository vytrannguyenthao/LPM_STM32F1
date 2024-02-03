#include "rtc.h"

void RTC_clk_config(void){
	/***********************Steps followed***********************
	 * 	1. Enable the power interface clock by setting the PWREN bit in the RCC_APB1ENR register.
	 * 	2. Enable the backup interface clock by setting the BKPEN bit in the RCC_APB1ENR register.
	 * 	3. Set the DBP bit the Power Control register (PWR_CR) to enable access to the Backup registers and RTC.
	 * 	4. Select the RTC clock source by setting RTCSEL in RCC_BDCR register.
	 * 	5. Enable clock source, wait until the bit set completely.
	 * 	6. Reset or release reset backup domain data by setting BDRST bit in RCC_BDCR register.
	 * 	7. Enable RTC clock by setting RTCEN bit in RTC_BDCR.
	 ***********************************************************/

	/*Enable the power interface clock by setting the PWREN bit in the RCC_APB1ENR register*/
	RCC->APB1ENR |= RCC_APB1ENR_PWREN;

	/*2.Enable the backup interface clock by setting the BKPEN bit in the RCC_APB1ENR register*/
	RCC->APB1ENR |= RCC_APB1ENR_BKPEN;

	/*3.Set the DBP bit the Power Control register (PWR_CR) to enable access to the Backup registers and RTC*/
	PWR->CR |= PWR_CR_DBP;

	/*4.Select the RTC clock source  to LSI by setting RTCSEL in RCC_BDCR register*/
	RCC->BDCR |= RCC_BDCR_RTCSEL_LSI;

	/*5.Enable LSI by setting LSION bit in the RCC_CSR register*/
	/*Enable LSI*/
	RCC->CSR |= RCC_CSR_LSION;

	/*Wait until the LSION bit is set completely*/
	while(!(RCC->CSR& RCC_CSR_LSIRDY));

	/*6.Release reset backup domain data by setting BDRST bit in RCC_BDCR register*/
	RCC->BDCR &= ~RCC_BDCR_BDRST;

	/*7.Enable RTC clock by setting RTCEN bit in RTC_BDCR*/
	RCC->BDCR |= RCC_BDCR_RTCEN;
}
void RTC_config_start(void){
	/***********************Steps followed***********************
	 * 	1. Poll RTOFF in the RTC_CRL register, wait until its value goes to ‘1’.
	 *	2. Set the CNF bit to enter configuration mode in the RTC_CRL register.
	 ***********************************************************/

	BKP_write_enable();
	while(!(RTC->CRL & RTC_CRL_RTOFF));

	/*1.Poll RTOFF in the RTC_CRL register, wait until its value goes to ‘1’*/
	while(!(RTC->CRL & RTC_CRL_RTOFF));

	/*2.Set the CNF bit to enter configuration mode in the RTC_CRL register*/
	RTC->CRL |= RTC_CRL_CNF;
}
void RTC_config_cmpt(void){
	/***********************Steps followed***********************
	 *	1. Clear the CNF bit to exit configuration mode in the RTC_CRL register.
	 *	2. Poll RTOFF in the RTC_CRL register, wait until its value goes to ‘1’ to check the end of the write operation.
	 ***********************************************************/

	/*1.Clear the CNF bit to exit configuration mode in the RTC_CRL register*/
	RTC->CRL &= ~RTC_CRL_CNF;

	/*2.Poll RTOFF in the RTC_CRL register, wait until its value goes to ‘1’ to check the end of the write operation*/
	while(!(RTC->CRL & RTC_CRL_RTOFF));

	while(!(RTC->CRL & RTC_CRL_RTOFF));
	BKP_write_disable();
}
void RTC_config(void){
	/***********************Steps followed***********************
	 * 	1. Call the RTC_config_start function.
	 *	2. Write to one or more RTC registers.
	 * 	3. Call the RTC_config_cmpt function.
	 ***********************************************************/

	/*1.Call the RTC_config_start function*/
	RTC_config_start();

	/*2.Write to one or more RTC registers*/
	/*Set the signal period of 1 second by writing 7FFF in the  RTC_PRLL register*/
	RTC->PRLL = (uint16_t)0X7FFF;
	RTC->PRLH = (uint16_t)0x0000;

	/*3.Call the RTC_config_cmpt function*/
	RTC_config_cmpt();
}

void RTC_interrupt_en(){
	/***********************Steps followed***********************
	 * 	1. Call the RTC_config_start function.
	 *	2. Enable RTC interrupts.
	 * 	3. Call the RTC_config_cmpt function.
	 ***********************************************************/

	/*1.Call the RTC_config_start function*/
	RTC_config_start();

	/*2.Enable RTC interrupts*/
	/*Enable Alarm interrupt by unmasked ALRIE bit in RTC_CRH*/
	RTC->CRH |= RTC_CRH_ALRIE;
	NVIC_EnableIRQ(RTC_IRQn);

	/*3.Call the RTC_config_cmpt function*/
	RTC_config_cmpt();
}

void RTC_set_alarm(uint32_t time){
	/***********************Steps followed***********************
	 * 	1. Call the RTC_config_start function.
	 *	2. Set alarm time in RTC_ALRL and RTC_ALRH register.
	 * 	3. Call the RTC_config_cmpt function.
	 ***********************************************************/

	/*1.Call the RTC_config_start function*/
	RTC_config_start();

	/*2.Set alarm time in RTC_ALRL and RTC_ALRH register*/
	RTC->ALRL = (uint16_t)time;
	RTC->ALRH = (uint16_t)(time>>16);

	/*3.Call the RTC_config_cmpt function*/
	RTC_config_cmpt();
}
void RTC_set_counter(uint32_t cnt){
	RTC_config_start();
	RTC->CNTL = (uint16_t)cnt;
	RTC->CNTH = (uint16_t)cnt>>16;
	RTC_config_cmpt();

}

void BKP_write_enable(void){
	PWR->CR |= PWR_CR_DBP;
}
void BKP_write_disable(void){
	PWR->CR &= ~PWR_CR_DBP;
}
