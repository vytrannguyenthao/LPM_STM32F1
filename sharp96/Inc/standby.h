#ifndef __STANDBY_H__
#define __STANDBY_H__

#include "stm32f1xx.h"

#define WAKEUP_PIN	(1U<<0)		//PA0

void Enter_standby_mode(void);
void Wakeup_pin_en(void);

#endif
