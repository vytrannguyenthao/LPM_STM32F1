#ifndef __TIM_H__
#define	__TIM_H__

#include "stm32f1xx.h"

void Timer2Config(void);
void Timer3Config(void);
void Timer4Config(void);
void Delay_us (uint16_t us);
void Delay_ms (uint16_t ms);
void Reset_timer4_counter(void);

#endif
