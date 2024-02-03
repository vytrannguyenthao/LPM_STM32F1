/*
 * digital_clock.h
 *
 *  Created on: Oct 22, 2023
 *      Author: GMT
 */

#ifndef DIGITAL_CLOCK_H_
#define DIGITAL_CLOCK_H_

#include "rtc.h"
#include "stm32f1xx.h"
#include "rtc_app.h"

extern t_time current_time, temp_time, alarm_time;

void Set_year(uint8_t year);
void Set_month(uint8_t month);
void Set_date(uint8_t date);
void Set_day(uint8_t day);
void Set_hour(uint8_t hour);
void Set_min(uint8_t min);
void Set_sec(uint8_t sec);
void Set_dmy(uint32_t year, uint8_t mon, uint8_t date, uint8_t day);
void Set_hms(uint8_t hour, uint8_t min, uint8_t sec);
void Set_cycle(uint8_t cycle);
void Get_cycle(uint8_t *cycle);
void Set_alarm(uint8_t hour, uint8_t min, uint8_t sec);
void Set_alarm_times(uint8_t times);
void Get_alarm_times(uint8_t *times);

#endif /* DIGITAL_CLOCK_H_ */
