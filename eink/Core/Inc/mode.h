/*
 * mode.h
 *
 *  Created on: Nov 2, 2023
 *      Author: Vy
 */

#ifndef MODE_H_
#define MODE_H_

#include <stdlib.h>
#include <stdio.h>
#include "stm32f1xx.h"
#include "../User/e-Paper/EPD_1in54b.h"
#include "../User/Config/DEV_Config.h"
#include "../User/GUI/GUI_Paint.h"

typedef enum
{
  DISPLAY_MODE,
  SET_DMY_MODE,
  SET_YEAR_MODE,
  SET_MON_MODE,
  SET_DATE_MODE,
  SET_DAY_MODE,
  SET_HMS_MODE,
  SET_HOUR_MODE,
  SET_MIN_MODE,
  SET_SEC_MODE,
  SET_CYCLE_MODE,
  SET_CYCLE_MONDAY_MODE,
  SET_CYCLE_TUESDAY_MODE,
  SET_CYCLE_WEDNESDAY_MODE,
  SET_CYCLE_THURDAY_MODE,
  SET_CYCLE_FRIDAY_MODE,
  SET_CYCLE_SATURDAY_MODE,
  SET_CYCLE_SUNDAY_MODE,
  SET_ALARM_MODE,
  SET_ALARM_HOUR_MODE,
  SET_ALARM_MIN_MODE,
  SET_ALARM_SEC_MODE,
  ALARM_MODE
}process_mode_t;

extern RTC_TimeTypeDef current_time, temp_time, alarm_time;
extern RTC_DateTypeDef current_date, temp_date, alarm_date;
extern uint8_t blink;
extern uint8_t cycle, temp_cycle, alarm_times;
extern process_mode_t mode;
extern UBYTE *BlackImage, *RedImage;
extern UWORD Imagesize;
extern void (*button0_mode_ptr)(void);
extern void (*button1_mode_ptr)(void);
extern void (*button2_mode_ptr)(void);
extern void (*button3_mode_ptr)(void);

// mode chính
void display_mode(void);
void set_dmy_mode(void);
void set_hms_mode(void);
void set_cycle_mode(void);
void set_alarm_mode(void);

void save_mode(void);

// set dmy mode
void set_year_mode(void);
void set_mon_mode(void);
void set_date_mode(void);
void set_day_mode(void);

void increase_year_mode(void);
void decrease_year_mode(void);
void increase_mon_mode(void);
void decrease_mon_mode(void);
void increase_day_mode(void);
void decrease_day_mode(void);
void increase_date_mode(void);
void decrease_date_mode(void);

// set hms mode
void set_hour_mode(void);
void set_min_mode(void);
void set_sec_mode(void);

void increase_hour_mode(void);
void decrease_hour_mode(void);
void increase_min_mode(void);
void decrease_min_mode(void);
void increase_sec_mode(void);
void decrease_sec_mode(void);

// set cycle mode
void set_cycle_monday_mode(void);
void set_cycle_tuesday_mode(void);
void set_cycle_wednesday_mode(void);
void set_cycle_thurday_mode(void);
void set_cycle_friday_mode(void);
void set_cycle_saturday_mode(void);
void set_cycle_sunday_mode(void);
void change_cycle_mode(void);

//alarm mode
void set_alarm_mode(void);
void alarm_mode(void);

#endif /* MODE_H_ */
