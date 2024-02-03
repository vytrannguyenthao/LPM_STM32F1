#include "spi.h"

void SPI1_pin_init(void){
	/*Configure SPI1 pin to alternative mode*/
	GPIO_Pin_Configure(SPI1_MOSI, OUTPUT_10MHZ, OUTPUT_AF_PP);
	GPIO_Pin_Configure(SPI1_SCK, OUTPUT_10MHZ, OUTPUT_AF_PP);
}
void SPI1_set_LSB(void){
	SPI1->CR1 |= SPI_CR1_LSBFIRST;
}

void SPI1_set_MSB(void){
	SPI1->CR1 &= ~SPI_CR1_LSBFIRST;
}

void SPI1_enable(void){
	SPI1->CR1 |= SPI_CR1_SPE;
}

void SPI1_disable(void){
	SPI1->CR1 &= ~SPI_CR1_SPE;

}
void SPI1_master_config(void){
	/***********************STEPS TO FOLLOW ***********************
	 * 1. Enable clock to access SPI by setting SPI1EN in RCC_APB2ENR register.
	 * 2. Configure the Control Register 1 (CR1).
	 * 2.1. Select the serial clock baud rate by setting the BR[2:0] bits in SPI_CR1 register.
	 * 2.2. Select relationships between the data transfer and the serial clock by setting CPOL, CPHA bits in SPI_CR1 register.
	 * 2.3. Select 8-bit or 16-bit data frame format by setting DFF bit in SPI_CR1 register.
	 * 2.4. Configure the LSBFIRST bit in the SPI_CR1 register to define the frame format.	 * 2.5. Select the mode for mcu by setting MSTR bit SPI_CR1 register.
	 * 2.6. Set SSM and SSI if select software slave management.
	 * 3. Configure the Control Register 2 (CR2).
	 * 4. Reset the SPI data register.
	 ***********************************************************/

	/*1.Enable clock to access SPI by setting SPI1EN in RCC_APB2ENR register*/
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;

	/*2.Configure the Control Register 1 (CR1)*/
	/*2.1.Select the serial clock baud rate by setting the BR[2:0] bits in SPI_CR1 register*/
	/*011: fPCLK/8*/
	SPI1->CR1 &= ~(SPI_CR1_BR_2);
	SPI1->CR1 |= SPI_CR1_BR_0 | SPI_CR1_BR_1 ;

	/*2.2.Select relationships between the data transfer and the serial clock by setting CPOL, CPHA bits in SPI_CR1 register*/
	SPI1->CR1 &= ~SPI_CR1_CPOL;
	SPI1->CR1 &= ~SPI_CR1_CPHA;

	/*2.3.Select 8-bit data frame format by setting DFF bit in SPI_CR1 register*/
	SPI1->CR1 &= ~SPI_CR1_DFF;

	/*2.4.Configure the LSBFIRST bit in the SPI_CR1 register to define the frame format*/
	SPI1_set_MSB();

	/*2.5.Select the master mode for mcu by setting MSTR bit SPI_CR1 register*/
	SPI1->CR1 |= SPI_CR1_MSTR;

	/*2.6.Set SSM and SSI if select software slave management*/
	SPI1->CR1 |= SPI_CR1_SSM;
	SPI1->CR1 |= SPI_CR1_SSI;

	/*3.Configure the Control Register 2 (CR2)*/
	SPI1->CR2 = 0;

	/*4.Reset the SPI data register.*/
	SPI1->DR = 0;
}

void SPI1_transmit_data(uint8_t *data, uint8_t size){
	/************** STEPS TO FOLLOW *****************
	 * 1. Wait for the TXE bit to set in the Status Register.
	 * 2. Write the data to the Data Register.
	 * 3. Wait for the BSY bit to reset in Status Register.
	 * 4. Clear the Overrun flag by reading DR and SR.
	************************************************/

	for(int i = 0; i < size; i++){
		/*1.Wait for the TXE bit to set in the Status Register*/
		while(!((SPI1->SR & SPI_SR_TXE) == SPI_SR_TXE)){}

		/*2.Write the data to the Data Register*/
		SPI1->DR = *(data + i);
	}

	/*3.Wait for the BSY bit to reset in Status Register*/
	while(((SPI1->SR & SPI_SR_BSY) == SPI_SR_BSY)){}

	/*4.Clear the Overrun flag by reading DR and SR*/
	uint8_t temp = SPI1->DR;
	temp = SPI1->SR;
}
