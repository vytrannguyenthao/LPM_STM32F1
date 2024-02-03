#include "gpio.h"

void GPIO_Pin_Configure(uint8_t GPIO_x, uint32_t Pin, uint32_t MODE, uint32_t FUNC){
	/************** STEPS TO FOLLOW *****************
	 * 1. Enable clock to access GPIO by setting IOPxEN in RCC_APB2ENR register.
	 * 2. Reset MODEx, CNFx bits by writing 0 in GPIOx_CRL / GPIOx_CRH register.
	 * 3. Configure GPIO by setting MODEx, CNFx bits in GPIOx_CRL / GPIOx_CRH register.
	************************************************/

	/*1.Enable clock to access GPIO by setting IOPxEN in RCC_APB2ENR register*/
	RCC->APB2ENR |= GPIO_x;

	if(Pin < 8){
		switch(GPIO_x){
			case GPIO_A:
				/*2.Reset MODEx, CNFx bits by writing 0 in GPIOx_CRL register*/
				GPIOA->CRL &= ~(0xf << (Pin << 2));

				/*3.Configure GPIO by setting MODEx, CNFx bits in GPIOx_CRL register*/
				GPIOA->CRL |= ((MODE | FUNC) << (Pin << 2));
			break;
			case GPIO_B:
				/*2.Reset MODEx, CNFx bits by writing 0 in GPIOx_CRL register*/
				GPIOB->CRL &= ~(0xf << (Pin << 2));

				/*3.Configure GPIO by setting MODEx, CNFx bits in GPIOx_CRL register*/
				GPIOB->CRL |= ((MODE | FUNC) << (Pin << 2));
			break;
			case GPIO_C:
				/*2.Reset MODEx, CNFx bits by writing 0 in GPIOx_CRL register*/
				GPIOC->CRL &= ~(0xf << (Pin << 2));

				/*3.Configure GPIO by setting MODEx, CNFx bits in GPIOx_CRL register*/
				GPIOC->CRL |= ((MODE | FUNC) << (Pin << 2));
			break;
			default:
				printf("Error!, gpio.c/GPIO_Pin_Configure\n");
			break;
		}
	}
	else{
		switch(GPIO_x){
			case GPIO_A:
				/*2.Reset MODEx, CNFx bits by writing 0 in GPIOx_CRH register*/
				GPIOA->CRH &= ~(0xf << ((Pin - 8) << 2));

				/*3.Configure GPIO by setting MODEx, CNFx bits in GPIOx_CRH register*/
				GPIOA->CRH |= ((MODE | FUNC) << ((Pin - 8) << 2));
			break;
			case GPIO_B:
				/*2.Reset MODEx, CNFx bits by writing 0 in GPIOx_CRH register*/
				GPIOB->CRH &= ~(0xf << ((Pin - 8) << 2));

				/*3.Configure GPIO by setting MODEx, CNFx bits in GPIOx_CRH register*/
				GPIOB->CRH |= ((MODE | FUNC) << ((Pin - 8) << 2));
			break;
			case GPIO_C:
				/*2.Reset MODEx, CNFx bits by writing 0 in GPIOx_CRH register*/
				GPIOC->CRH &= ~(0xf << ((Pin - 8) << 2));

				/*3.Configure GPIO by setting MODEx, CNFx bits in GPIOx_CRH register*/
				GPIOC->CRH |= ((MODE | FUNC) << ((Pin - 8) << 2));
			break;
			default:
				printf("Error!, gpio.c/GPIO_Pin_Configure\n");
			break;
		}
	}
}

void GPIO_set_out_pin(uint8_t GPIO_x, uint32_t Pin, uint8_t STATE){
	switch(GPIO_x){
		case GPIO_A:
			/*Reset ODRx bit by writing 0 in GPIOx_ODR register*/
			GPIOA->ODR &= ~(0x1 << Pin);

			/*Configure GPIO ouput state by setting ODRx bit in GPIOx_ODR register*/
			GPIOA->ODR |= (STATE << Pin);
		break;
		case GPIO_B:
			/*Reset ODRx bit by writing 0 in GPIOx_ODR register*/
			GPIOB->ODR &= ~(0x1 << Pin);

			/*Configure GPIO ouput state by setting ODRx bit in GPIOx_ODR register*/
			GPIOB->ODR |= (STATE << Pin);
		break;
		case GPIO_C:
			/*Reset ODRx bit by writing 0 in GPIOx_ODR register*/
			GPIOC->ODR &= ~(0x1 << Pin);

			/*Configure GPIO ouput state by setting ODRx bit in GPIOx_ODR register*/
			GPIOC->ODR |= (STATE << Pin);
		break;
		default:
			printf("Error!, gpio.c/GPIO_set_out_pin\n");
		break;
	}
}

void GPIO_toogle_out_pin(uint8_t GPIO_x, uint32_t Pin){
	switch(GPIO_x){
		case GPIO_A:
			GPIOA->ODR ^= (0x1 << Pin);
		break;
		case GPIO_B:
			GPIOB->ODR ^= (0x1 << Pin);

		break;
		case GPIO_C:
			GPIOC->ODR ^= (0x1 << Pin);
		break;
		default:
			printf("Error!, gpio.c/GPIO_toogle_out_pin\n");
		break;
	}
}

void Wakeup_pin_init(void){
	/*Enable clock to access GPIOA*/
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

	/*Set PA0 mode to input (00)*/
	GPIOA->CRL &= ~(GPIO_CRL_MODE0_0 | GPIO_CRL_MODE0_1);


	GPIOA->CRL &= ~GPIO_CRL_CNF0_0;
	GPIOA->CRL |= GPIO_CRL_CNF0_1;

	GPIOA->ODR &= ~GPIO_ODR_ODR0;
}


