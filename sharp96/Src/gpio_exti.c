#include "gpio_exti.h"

void PA1_exti_init(void){
	/***********************Steps followed***********************
	 * 0. Configure GPIO pin to input Pull-up/ Pull-down mode.
	 * 1. Enable the AFIO bit in the RCC_APB2ENR Register.
	 * 2. Configure the EXTI configuration Register in the AFIO_EXTICRx.
	 * 3. Disable the EXTI Mask EXTI_IMR register.
	 * 4. Configure the Trigger Selection bits in EXTI_RTSR and EXTI_FTSR.
	 * 5. Set the Interrupt Priority.
	 * 6. Enable EXTI in NVIC.
	 ***********************************************************/

	/*0.Configure GPIO pin to Pull-up input mode*/
	/*Enable clock to access GPIOA*/
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

	/*Set PA1 to input mode*/
	GPIOA->CRL &= ~(GPIO_CRL_MODE1_0 | GPIO_CRL_MODE1_1);

	/*Set PA1 to input Pull-up/ Pull-down mode (10)*/
	GPIOA->CRL |= GPIO_CRL_CNF1_1;
	GPIOA->CRL &= ~GPIO_CRL_CNF1_0;

	/*Configure the ODR (1-> Pull UP, 0-> Pull down)*/
	GPIOA->ODR |= GPIO_ODR_ODR1;

	/*1.Enable the AFIO bit in the RCC_APB2ENR Register*/
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;

	/*2.Configure the EXTI configuration Register in the AFIO_EXTICRx*/
	AFIO->EXTICR[0] &= ~(0xf<<4);		//PA1

	/*3.Disable the EXTI Mask in EXTI_IMR register*/
	EXTI->IMR |= EXTI_IMR_IM1;

	/*4.Configure the Trigger Selection bits in EXTI_RTSR and EXTI_FTSR*/
	/*Enable Rising Edge Trigger for PA1*/
	EXTI->RTSR |= EXTI_RTSR_RT1;

	/*Disable Falling Edge Trigger for PA1*/
	EXTI->FTSR &= ~EXTI_FTSR_FT1;

	/*5.Set the Interrupt Priority*/
	NVIC_SetPriority(EXTI1_IRQn, 2);

	/*6.Enable EXTI in NVIC*/
	NVIC_EnableIRQ(EXTI1_IRQn);
}

void Button_init(void){
	/***********************Steps followed***********************
	 * 0. Configure GPIO pin to input Pull-up/ Pull-down mode.
	 * 1. Enable the AFIO bit in the RCC_APB2ENR Register.
	 * 2. Configure the EXTI configuration Register in the AFIO_EXTICRx.
	 * 3. Disable the EXTI Mask EXTI_IMR register.
	 * 4. Configure the Trigger Selection bits in EXTI_RTSR and EXTI_FTSR.
	 * 5. Set the Interrupt Priority.
	 * 6. Enable EXTI in NVIC.
	 ***********************************************************/

	/*0.Configure GPIO pin to Pull-up input mode*/
	/*Enable clock to access GPIOA*/
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

	/*Enable clock to access GPIOB*/
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;

//	/*Set PA4, PA3, PA11, PA12 to input mode*/
//	GPIOA->CRL &= ~(GPIO_CRL_MODE4_0 | GPIO_CRL_MODE4_1);
//	GPIOA->CRL &= ~(GPIO_CRL_MODE3_0 | GPIO_CRL_MODE3_1);
	GPIOA->CRH &= ~(GPIO_CRH_MODE11_0 | GPIO_CRH_MODE11_1);
	GPIOA->CRH &= ~(GPIO_CRH_MODE12_0 | GPIO_CRH_MODE12_1);

	/*Set PA4, PA3, PB5, PB6 to input mode*/
	GPIOA->CRL &= ~(GPIO_CRL_MODE4_0 | GPIO_CRL_MODE4_1);
	GPIOA->CRL &= ~(GPIO_CRL_MODE3_0 | GPIO_CRL_MODE3_1);
	GPIOB->CRL &= ~(GPIO_CRL_MODE5_0 | GPIO_CRL_MODE5_1);
	GPIOB->CRL &= ~(GPIO_CRL_MODE6_0 | GPIO_CRL_MODE6_1);

//	/*SeT PA4, PA3, PA11, PA12 to input Pull-up/ Pull-down mode (10)*/
//	GPIOA->CRL |= GPIO_CRL_CNF4_1;
//	GPIOA->CRL &= ~GPIO_CRL_CNF4_0;
//	GPIOA->CRL |= GPIO_CRL_CNF3_1;
//	GPIOA->CRL &= ~GPIO_CRL_CNF3_0;
	GPIOA->CRH|= GPIO_CRH_CNF11_1;
	GPIOA->CRH &= ~GPIO_CRH_CNF11_0;
	GPIOA->CRH |= GPIO_CRH_CNF12_1;
	GPIOA->CRH &= ~GPIO_CRH_CNF12_0;

	/*Set PA4, PA3, PB5, PB6 to input Pull-up/ Pull-down mode (10)*/
	GPIOA->CRL |= GPIO_CRL_CNF4_1;
	GPIOA->CRL &= ~GPIO_CRL_CNF4_0;
	GPIOA->CRL |= GPIO_CRL_CNF3_1;
	GPIOA->CRL &= ~GPIO_CRL_CNF3_0;
	GPIOB->CRL |= GPIO_CRL_CNF5_1;
	GPIOB->CRL &= ~GPIO_CRL_CNF5_0;
	GPIOB->CRL |= GPIO_CRL_CNF6_1;
	GPIOB->CRL &= ~GPIO_CRL_CNF6_0;

//	/*Configure the ODR (1-> Pull UP, 0-> Pull down)*/
//	GPIOA->ODR |= GPIO_ODR_ODR4;
//	GPIOA->ODR |= GPIO_ODR_ODR3;
	GPIOA->ODR |= GPIO_ODR_ODR11;
	GPIOA->ODR |= GPIO_ODR_ODR12;

	/*Configure the ODR (1-> Pull UP, 0-> Pull down)*/
	GPIOA->ODR |= GPIO_ODR_ODR4;
	GPIOA->ODR |= GPIO_ODR_ODR3;
	GPIOB->ODR |= GPIO_ODR_ODR5;
	GPIOB->ODR |= GPIO_ODR_ODR6;

	/*1.Enable the AFIO bit in the RCC_APB2ENR Register*/
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;

//	/*2.Configure the EXTI configuration Register in the AFIO_EXTICRx*/
//	AFIO->EXTICR[0] &= ~(0xf<<12);		//PA3
//	AFIO->EXTICR[1] &= ~(0xf<<0);		//PA4
	AFIO->EXTICR[2] &= ~(0xf<<12);		//PA11
	AFIO->EXTICR[3] &= ~(0xf<<0);		//PA12

	/*2.Configure the EXTI configuration Register in the AFIO_EXTICRx*/
	AFIO->EXTICR[0] &= ~(0xf<<12);		//PA3
	AFIO->EXTICR[1] &= ~(0xf<<0);		//PA4
	AFIO->EXTICR[1] &= ~(0xf<<4);		//PB5
	AFIO->EXTICR[1] |= (1<<4);			//PB5
	AFIO->EXTICR[1] &= ~(0xf<<8);		//PB5
	AFIO->EXTICR[1] |= (1<<8);			//PB6

//	/*3.Disable the EXTI Mask in EXTI_IMR register*/
//	EXTI->IMR |= EXTI_IMR_IM3;
//	EXTI->IMR |= EXTI_IMR_IM4;
	EXTI->IMR |= EXTI_IMR_IM11;
	EXTI->IMR |= EXTI_IMR_IM12;

	/*3.Disable the EXTI Mask in EXTI_IMR register*/
	EXTI->IMR |= EXTI_IMR_IM3;
	EXTI->IMR |= EXTI_IMR_IM4;
	EXTI->IMR |= EXTI_IMR_IM5;
	EXTI->IMR |= EXTI_IMR_IM6;

	/*4.Configure the Trigger Selection bits in EXTI_RTSR and EXTI_FTSR*/
//	/*Disable Rising Edge Trigger for PA4, PA3, PA11, PA12*/
//	EXTI->RTSR &= ~EXTI_RTSR_RT4;
//	EXTI->RTSR &= ~EXTI_RTSR_RT3;
	EXTI->RTSR &= ~EXTI_RTSR_RT11;
	EXTI->RTSR &= ~EXTI_RTSR_RT12;
//
//	/*Enable Falling Edge Trigger for PA4, PA3, PA11, PA12*/
//	EXTI->FTSR |= EXTI_FTSR_FT4;
//	EXTI->FTSR |= EXTI_FTSR_FT3;
	EXTI->FTSR |= EXTI_FTSR_FT11;
	EXTI->FTSR |= EXTI_FTSR_FT12;

	/*Disable Rising Edge Trigger for PA4, PA3, PB5, PB6*/
	EXTI->RTSR &= ~EXTI_RTSR_RT4;
	EXTI->RTSR &= ~EXTI_RTSR_RT3;
	EXTI->RTSR &= ~EXTI_RTSR_RT5;
	EXTI->RTSR &= ~EXTI_RTSR_RT6;

	/*Enable Falling Edge Trigger for PA4, PA3, PB5, PB6*/
	EXTI->FTSR |= EXTI_FTSR_FT4;
	EXTI->FTSR |= EXTI_FTSR_FT3;
	EXTI->FTSR |= EXTI_FTSR_FT5;
	EXTI->FTSR |= EXTI_FTSR_FT6;

	/*5.Set the Interrupt Priority*/
	NVIC_SetPriority(EXTI3_IRQn, 2);
	NVIC_SetPriority(EXTI4_IRQn, 2);
	NVIC_SetPriority(EXTI9_5_IRQn, 2);
	NVIC_SetPriority(EXTI15_10_IRQn, 2);

	/*6.Enable EXTI in NVIC*/
	NVIC_EnableIRQ(EXTI3_IRQn);
	NVIC_EnableIRQ(EXTI4_IRQn);
	NVIC_EnableIRQ(EXTI9_5_IRQn);
	NVIC_EnableIRQ(EXTI15_10_IRQn);
}

