/*
 * digital_clock.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Vy
 */
#include "digital_clock.h"

void Set_year(uint8_t year){
	current_time.year = year;
	//Save the new time to Backup Register
	BKP_write_enable();
	BKP->DR1 = year;
	BKP_write_disable();
}

void Set_month(uint8_t month){
	current_time.mon = month;
	//Save the new time to Backup Register
	BKP_write_enable();
	BKP->DR2 = month;
	BKP_write_disable();
}

void Set_date(uint8_t date){
	current_time.date = date;
	//Save the new time to Backup Register
	BKP_write_enable();
	BKP->DR3 = date;
	BKP_write_disable();
}

void Set_day(uint8_t day){
	current_time.day = day;
	//Save the new time to Backup Register
	BKP_write_enable();
	BKP->DR4 = day;
	BKP_write_disable();
}

void Set_hour(uint8_t hour){
	current_time.hour = hour;
	/*Change the value of counter register*/
	uint32_t temp = current_time.hour*60*60 + current_time.min*60 + current_time.sec;
	RTC_set_counter(temp);
}

void Set_min(uint8_t min){
	current_time.min = min;
	/*Change the value of counter register*/
	uint32_t temp = current_time.hour*60*60 + current_time.min*60 + current_time.sec;
	RTC_set_counter(temp);
}

void Set_sec(uint8_t sec){
	current_time.sec = sec;
	/*Change the value of counter register*/
	uint32_t temp = current_time.hour*60*60 + current_time.min*60 + current_time.sec;
	RTC_set_counter(temp);
}


void Set_hms(uint8_t hour, uint8_t min, uint8_t sec){
	current_time.hour = hour;
	current_time.min = min;
	current_time.sec = sec;
	/*Change the value of counter register*/
	uint32_t temp = current_time.hour*60*60 + current_time.min*60 + current_time.sec;
	RTC_set_counter(temp);
}

void Set_dmy(uint32_t year, uint8_t mon, uint8_t date, uint8_t day){
	current_time.year = year;
	current_time.mon = mon;
	current_time.date = date;
	current_time.day = day;

	/*Change data in backup register*/
	BKP_write_enable();
	BKP->DR1 = year;
	BKP->DR2 = mon;
	BKP->DR3 = date;
	BKP->DR4 = day;
	BKP_write_disable();
}


void Set_cycle(uint8_t cycle){
	/*Change data in backup register*/
	BKP_write_enable();
	BKP->DR5 = cycle;
	BKP_write_disable();
}

void Get_cycle(uint8_t *cycle){
	/*Change data in backup register*/
	BKP_write_enable();
	*cycle = BKP->DR5;
	BKP_write_disable();
}

void Set_alarm_times(uint8_t times){
	/*Change data in backup register*/
	BKP_write_enable();
	BKP->DR6 = times;
	BKP_write_disable();
}

void Get_alarm_times(uint8_t *times){
	/*Change data in backup register*/
	BKP_write_enable();
	*times = BKP->DR6;
	BKP_write_disable();
}

void Set_alarm(uint8_t hour, uint8_t min, uint8_t sec){
	alarm_time.hour = hour;
	alarm_time.min = min;
	alarm_time.sec = sec;

	/*Change the value of counter register*/
	uint32_t temp = alarm_time.hour*60*60 + alarm_time.min*60 + alarm_time.sec;
	RTC_set_alarm(temp);
}
