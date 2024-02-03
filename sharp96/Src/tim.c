#include "tim.h"

void Timer2Config(void){
	/***********************Steps followed***********************
	* 1. Enable Timer clock.
	* 2. Set the prescaler and the ARR.
	* 3. Enable the Timer, and wait for the update Flag to set.
	 ***********************************************************/

	/*1.Enable Timer 2 clock*/
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	/*2.Set the prescaler and the ARR*/
	/*Set TIM prescaler*/
	TIM2->PSC = 8-1;	//Each count by the counter take 1 microseccond

	/*Set TIM Auto-reload value*/
	TIM2->ARR = 0xffff-1;	//ARR resister is 16 bit resister

	/*3.Enable the Timer, and wait for the update Flag to set*/
	/*Enable timer*/
	TIM2->CR1 |= TIM_CR1_CEN;

	/*Wait for the update flag to set*/
	while(!(TIM2->SR & TIM_SR_UIF));
}

void Delay_us (uint16_t us){
	/***********************Steps followed***********************
	 * 1. RESET the Counter
	 * 2. Wait for the Counter to reach the entered value. As each count will take 1 us,
		 the total waiting time will be the required us delay
	 ***********************************************************/
	/*Reset counter*/
	TIM2->CNT = 0;

	/*Wait for the counter to reach the entered value*/
	while (TIM2->CNT < us);

}
void Delay_ms (uint16_t ms){
	for(uint16_t i = 0; i < ms; i++){
		Delay_us(1000);
	}
}

/*Timer 3 is using to blink data*/
void Timer3Config(void){
	/***********************Steps followed***********************
	* 1. Enable Timer clock.
	* 2. Set the prescaler and the ARR.
	* 3. Enable the Timer, and wait for the update Flag to set.
	 ***********************************************************/

	/*1.Enable Timer 3 clock*/
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

	/*2.Set the prescaler and the ARR*/
	/*Set TIM prescaler*/
	TIM3->PSC = 8000-1;	//Each count by the counter take 1 miliseccond

	/*Set TIM Auto-reload value*/
	TIM3->ARR = 500-1;		// 0.5s

	/*4.Enable interrupt*/
	/*Enable timer update envent bit*/
    TIM3->EGR |= TIM_EGR_UG;

    /*Enable update interrupt by setting UIE bit in TIM_DIER register */
    TIM3->DIER |= TIM_DIER_UIE;


	/*5.Set the Interrupt Priority*/
	NVIC_SetPriority(TIM3_IRQn, 1);

	/*6.Enable EXTI in NVIC*/
	NVIC_EnableIRQ(TIM3_IRQn);

	/*7.Enable the Timer, and wait for the update Flag to set*/
	/*Enable timer*/
	TIM3->CR1 |= TIM_CR1_CEN;

	/*Wait for the update flag to set*/
//	while(!(TIM3->SR & TIM_SR_UIF));
}

/*Timer 4 is using to calculate active time*/
void Timer4Config(void){
	/***********************Steps followed***********************
	* 1. Enable Timer clock.
	* 2. Set the prescaler and the ARR.
	* 3. Enable the Timer, and wait for the update Flag to set.
	 ***********************************************************/

	/*1.Enable Timer 4 clock*/
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

	/*2.Set the prescaler and the ARR*/
	/*Set TIM prescaler*/
	TIM4->PSC = 8000-1;	//Each count by the counter take 1 miliseccond

	/*Set TIM Auto-reload value*/
	TIM4->ARR = 10000-1;		// 10s

	/*4.Enable interrupt*/
	/*Enable timer update envent bit*/
    TIM4->EGR |= TIM_EGR_UG;

    /*Enable update interrupt by setting UIE bit in TIM_DIER register */
    TIM4->DIER |= TIM_DIER_UIE;


	/*5.Set the Interrupt Priority*/
	NVIC_SetPriority(TIM4_IRQn, 1);

	/*6.Enable EXTI in NVIC*/
	NVIC_EnableIRQ(TIM4_IRQn);

	/*7.Enable the Timer, and wait for the update Flag to set*/
	/*Enable timer*/
	TIM4->CR1 |= TIM_CR1_CEN;

	/*Wait for the update flag to set*/
//	while(!(TIM4->SR & TIM_SR_UIF));

	/*Clear timer interrupt flag*/
    TIM4->SR &= ~TIM_SR_UIF;
}

void Reset_timer4_counter(void){
	TIM4->CNT = 0;
}
