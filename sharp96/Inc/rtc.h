#ifndef __RTC_H__
#define	__RTC_H__

#include "stm32f1xx.h"

void RTC_clk_config(void);
void RTC_config(void);
void RTC_config_start(void);
void RTC_config_cmpt(void);
void RTC_interrupt_en();
void RTC_set_alarm(uint32_t time);
void RTC_set_counter(uint32_t cnt);
void BKP_write_disable(void);
void BKP_write_enable(void);

#endif
