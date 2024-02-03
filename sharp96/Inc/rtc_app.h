#ifndef __RTC_APP_H__
#define __RTC_APP_H__

#include "stm32f1xx.h"
#include "rtc.h"

#define YEAR	0
#define MON		1
#define DATE	2
#define DAY		3
#define HOUR	4
#define MIN		5
#define SEC		6

#define MONDAY		2
#define TUESDAY		3
#define WEDNESDAY	4
#define THURSDAY	5
#define FRIDAY		6
#define SATURDAY	7
#define SUNDAY		8

typedef struct{
	volatile uint8_t up_mon;
	volatile uint8_t up_year;
}up_time_flag;

typedef struct{
	uint32_t year;
	uint8_t mon;
	uint8_t date;
	uint8_t day;
	uint8_t hour;
	uint8_t min;
	uint8_t sec;
	up_time_flag flag;
}t_time;

void Check_condition(t_time *time, uint8_t option);
void Time_config(t_time *time, uint8_t year, uint8_t mon, uint8_t date, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec);
void Get_time(t_time *time);
void Set_flag(uint8_t flag);
void Clear_flag(uint8_t flag);

#endif
