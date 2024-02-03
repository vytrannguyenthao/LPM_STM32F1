#ifndef	__ADC_DMA_H__
#define __ADC_DMA_H__

#include <tim.h>
#include "stm32f1xx.h"

void adc_init(void);
void adc_enable(void);
void adc_start(void);
void dma_init(void);
void dma1_ch1_config(uint32_t perph_adr, uint32_t mem_adr, uint16_t size);
void dma1_ch4_config(uint32_t perph_adr, uint32_t mem_adr, uint16_t size);
#endif
