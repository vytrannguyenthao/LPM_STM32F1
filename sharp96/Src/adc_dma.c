#include "adc_dma.h"

void adc_init(void){
	/***********************Steps followed***********************
	* 1. Enable ADC and GPIO clock.
	* 2. Set the prescaler in the Clock configuration register (RCC_CFGR).
	* 3. Set the Scan Mode in the Control Register 1 (CR1).
	* 4. Set the Continuous Conversion, External Event, DMA and Data Alignment in Control Reg 2 (CR2).
	* 5. Set the Sampling Time for the channels in ADC_SMPRx.
	* 6. Set the Regular channel sequence length in ADC_SQR1.
	* 7. Set the channels sequence in ADC_SQRx.
	* 8. Set the Respective GPIO PINs in the Analog Mode.
	 ***********************************************************/

	/*1.Enable ADC and GPIO clock*/
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

	/*2.Set the ADC prescaler in the Clock configuration register (RCC_CFGR)*/
	RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6;

	/*3.Disable the Scan Mode in the Control Register 1 (CR1)*/
	ADC1->CR1 &= ~ADC_CR1_SCAN;

	/*4.Set the Continuous Conversion, External Event, DMA and Data Alignment in Control Reg 2 (CR2)*/
	/*Disable continuous conversion*/
	ADC1->CR2 &= ~ADC_CR2_CONT;

	/*External Event selection pointed to Timer 3 TRGO event bit (100)*/
	ADC1->CR2 &= ~(ADC_CR2_EXTSEL_0 | ADC_CR2_EXTSEL_1);
	ADC1->CR2 |= ADC_CR2_EXTSEL_2;

	/*Enable DMA*/
	ADC1->CR2 |= ADC_CR2_DMA;

	/*Set data align is right*/
	ADC1->CR2 &= ~ADC_CR2_ALIGN;

	/*5. Set the Sampling Time for the channels in ADC_SMPRx*/
	/*Set sampling time of channel 0 is 1.5 cycles*/
	ADC1->SMPR2 &= ~(ADC_SMPR2_SMP0_0 | ADC_SMPR2_SMP0_1 | ADC_SMPR2_SMP0_2);

	/*6.Set the Regular channel sequence length in ADC_SQR1*/
	/*Set SQR1_L = 0 for 1 conversions*/
	ADC1->SQR1 &= ~ADC_SQR1_L_0;
	ADC1->SQR1 &= ~ADC_SQR1_L_1;
	ADC1->SQR1 &= ~ADC_SQR1_L_2;
	ADC1->SQR1 &= ~ADC_SQR1_L_3;

	/*7.Set the channels sequence in ADC_SQR3*/
	/*Set SQ1 for Channel 0*/
	ADC1->SQR3 |= (0U<<0);

	/*8.Set the Respective GPIO PINs in the Analog Mode*/
	/*Set PA0 mode to analog input mode*/
	GPIOA->CRL &= ~(1U<<0);
	GPIOA->CRL &= ~(1U<<1);
	GPIOA->CRL &= ~(1U<<2);
	GPIOA->CRL &= ~(1U<<3);

}

void dma_init(void){
	/***********************Steps followed***********************
	* 1. Enable DMA clock.
	* 2. Set the DATA Direction.
	* 3. Enable/Disable the Circular Mode.
	* 4. Enable/Disable the Memory Increment and Peripheral Increment.
	* 5. Set the Data Size.
	* 6. Select the channel for the Stream.
	 ***********************************************************/

	/*1.Enable DMA clock*/
	RCC->AHBENR |= RCC_AHBENR_DMA1EN;

	/*2.Set the DATA Direction*/
	/*Read from memory*/
	DMA1_Channel1->CCR |=  DMA_CCR_DIR;
	DMA1_Channel4->CCR |=  DMA_CCR_DIR;

	/*3.Enable the Circular Mode.*/
	DMA1_Channel1->CCR |= DMA_CCR_CIRC;
	DMA1_Channel4->CCR |= DMA_CCR_CIRC;

	/*4.Enable/Disable the Memory Increment and Peripheral Increment*/
	/*Enable the Memory Increment*/
	DMA1_Channel1->CCR |= DMA_CCR_MINC;
	DMA1_Channel4->CCR |= DMA_CCR_MINC;

	/*Disable the Peripheral Increment*/
	DMA1_Channel1->CCR &= ~DMA_CCR_PINC;
	DMA1_Channel4->CCR &= ~DMA_CCR_PINC;

	/*5.Set the Data Size*/
	/*Set MSize i.e Memory data size to word*/
	DMA1_Channel1->CCR &= ~(1U<<11);
	DMA1_Channel1->CCR |= (1U<<10);

	DMA1_Channel4->CCR &= ~(1U<<11);
	DMA1_Channel4->CCR |= (1U<<10);

	/*Set PSize i.e Peripheral data size to word*/
	DMA1_Channel1->CCR &= ~(1U<<9);
	DMA1_Channel1->CCR |= (1U<<8);

	DMA1_Channel4->CCR &= ~(1U<<9);
	DMA1_Channel4->CCR |= (1U<<8);
}

void adc_enable(void){
	/***********************Steps followed***********************
	* 1. Enable the ADC by setting ADON bit in CR2.
	* 2. Wait for ADC to stabilize (approx 10us).
	 ***********************************************************/

	/*1.Enable the ADC by setting ADON bit in CR2*/
	ADC1->CR2 |= ADC_CR2_ADON;

	/*Wait for ADC to stabilize (10us)*/
	Delay_us(10);
}

void adc_start(void){
	/***********************Steps followed***********************
	* 1. Clear the Status register(ADC_SR).
	* 2. Enable/Disable conversion on external event in CR2.
	* 3. Start the Conversion by Setting the SWSTART bit in CR2 if SWSTART is selected as trigger event.
	 ***********************************************************/

	/*1.Clear the Status register(ADC_SR)*/
	ADC1->SR = 0;

	/*2.Enable conversion on external event in CR2*/
	ADC1->CR2 |= ADC_CR2_EXTTRIG;

	/*3.Start the Conversion by Setting the SWSTART bit in CR2 if SWSTART is selected as trigger event*/
//	ADC1->CR2 |= ADC_CR2_SWSTART;
}

void dma1_ch1_config(uint32_t perph_adr, uint32_t mem_adr, uint16_t size){
	/***********************Steps followed***********************
	* 1. Set the Data Size in the CNDTR Register.
	* 2. Set the Peripheral Address and the Memory Address.
	* 3. Enable the DMA Channels in the CCR Register.
	* Some peripherals don't need a start condition, like UART, so as soon as you enable the DMA, the transfer will begin.
	* While Peripherals like ADC needs the Start condition, so Start the ADC later in the program, to enable the transfer.
	 ***********************************************************/

	dma_init();
	int a[500];
	a[1] = 5;
	/*1.Set the Data Size in the CNDTR Register*/
	DMA1_Channel1->CNDTR = size + a[1];

	/*2.Set the Peripheral Address and the Memory Address*/
	/*Set the Peripheral Address in CPAR Register*/
	DMA1_Channel1->CPAR = perph_adr;

	/*Set the Memory Address in CMAR Register*/
	DMA1_Channel1->CMAR = mem_adr;

	/*3.Enable the DMA Channels in the CCR Register*/
	DMA1_Channel1->CCR |= DMA_CCR_EN;
}
void dma1_ch4_config(uint32_t scr_adr, uint32_t des_adr, uint16_t size){
	/***********************Steps followed***********************
	* 1. Set the Data Size in the CNDTR Register.
	* 2. Set the Peripheral Address and the Memory Address.
	* 3. Enable the DMA Channels in the CCR Register.
	* Some peripherals don't need a start condition, like UART, so as soon as you enable the DMA, the transfer will begin.
	* While Peripherals like ADC needs the Start condition, so Start the ADC later in the program, to enable the transfer.
	 ***********************************************************/

	/*1.Set the Data Size in the CNDTR Register*/
	DMA1_Channel4->CNDTR = size;

	/*2.Set the Peripheral Address and the Memory Address*/
	/*Set the Peripheral Address in CPAR Register*/
	DMA1_Channel4->CPAR = scr_adr;

	/*Set the Memory Address in CMAR Register*/
	DMA1_Channel4->CMAR = des_adr;

	/*3.Enable the DMA Channels in the CCR Register*/
	DMA1_Channel4->CCR |= DMA_CCR_EN;
}

