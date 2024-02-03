#include "standby.h"

void Wakeup_pin_en(void){
	/***********************Steps followed***********************
	 * 1. Wait for wakeup pin to be released.
	 * 2. Disable wakeup pin by setting EWUP bit in PWR_CSR register.
	 * 3. Clear all wakeup flags by setting the CWUF bit in PWR_CR.
	 * 4. Enable wakeup pin by setting EWUP bit in PWR_CSR register.
	 ***********************************************************/

	/*1.Wait for wakeup pin to be released*/
	while((GPIOA->IDR & WAKEUP_PIN) == WAKEUP_PIN){}

	/*2.Disable wakeup pin by setting EWUP bit in PWR_CSR register*/
	PWR->CSR &= ~PWR_CSR_EWUP;

	/*3.Clear all wakeup flags by setting the CWUF bit in PWR_CR*/
	PWR->CR |= PWR_CR_CWUF;

	/*4.Enable wakeup pin by setting EWUP bit in PWR_CSR register*/
	PWR->CSR |= PWR_CSR_EWUP;
}

void Enter_standby_mode(void){
	/***********************Steps followed***********************
	 * 1. Enter StandBy mode by setting PDDS bit in PWR_CR register.
	 * 2. Set SLEEPDEEP bit in SCB_SCR register.
	 * 3. Wait for interrupt or event.
	 ***********************************************************/

	/*1.Enter StandBy mode by setting PDDS bit in PWR_CR register*/
	PWR->CR |= PWR_CR_PDDS;

	/*2.Set SLEEPDEEP bit in SCB_SCR register*/
	SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

	/*3. Wait for interrupt*/
	__WFI();
}
