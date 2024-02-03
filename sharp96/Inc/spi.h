#ifndef __SPI_H__
#define __SPI_H__

#include <stdio.h>
#include "stm32f1xx.h"
#include "gpio.h"

void SPI1_transmit_data(uint8_t *data, uint8_t size);
void SPI1_master_config(void);
void SPI1_pin_init(void);
void SPI1_set_MSB(void);
void SPI1_set_LSB(void);
void SPI1_disable(void);
void SPI1_enable(void);

#endif
