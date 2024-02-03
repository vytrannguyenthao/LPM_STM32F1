#include "rtc_app.h"

void Time_config(t_time *time, uint8_t year, uint8_t mon, uint8_t date, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec){
	time->year = year;
	time->mon = mon;
	time->date = date;
	time->day = day;

	/*Change the value of counter register*/
	uint32_t temp = hour*60*60 + min*60 + sec;
	RTC_set_counter(temp);
}
void Get_time(t_time *time){
	uint32_t temp = (uint32_t)RTC->CNTL | (uint32_t)(RTC->CNTH <<16);

	/*Restart counter register if its value > 86400 (1 day)*/
	if(temp > 86400){
		/*Reset counter register*/
		RTC_set_counter(0);

		/*Update day, date*/
		time->day++;
		time->date++;

		/*Check if there are acceptable value */
		Check_condition(time, DAY);
		Check_condition(time, DATE);

		/*Update month if up month flag value goes to ‘1’*/
		if(time->flag.up_mon == 1){
			/*Clear flag*/
			time->flag.up_mon = 0;

			/*Update month*/
			time->mon++;

			/*Check if there is acceptable value*/
			Check_condition(time, MON);

			/*Update year if up year flag value goes to ‘1’*/
			/*Clear flag*/
			time->flag.up_year = 0;

			/*Update year*/
			time->year++;
		}

		/*Change the value for temp*/
		temp = (uint32_t)RTC->CNTL | (uint32_t)(RTC->CNTH <<16);
	}

	/*Calculate time current*/
	time->hour = (uint8_t)(temp / (60 * 60));
	temp = temp % (60 * 60);
	time->min = (uint8_t)(temp / 60);
	temp = temp % 60;
	time->sec = (uint8_t)temp;
}

void Check_condition(t_time *time, uint8_t option){
	switch (option) {
		case DATE:
			if( (time->mon == 1) | (time->mon == 3) | (time->mon == 5) | (time->mon == 7) | (time->mon == 8) | (time->mon == 10) | (time->mon == 12)){
				if (time->date > 31){
					/*Change the acceptable value*/
					time->date = 1;

					/*Set the update month flag*/
					Set_flag(time->flag.up_mon);
				}
				if ( (time->mon == 4) | (time->mon == 6) | (time->mon == 9) | (time->mon == 11)){
					if (time->date > 30){
						/*Change the acceptable value*/
						time->date = 1;

						/*Set the update month flag*/
						Set_flag(time->flag.up_mon);
					}
				}
				if (time->mon == 2){
					if (time->year % 4 == 0){
						if (time->date > 29){
							/*Change the acceptable value*/
							time->date = 1;

							/*Set the update month flag*/
							Set_flag(time->flag.up_mon);
						}
					}
					else{
						if (time->date > 28){
							/*Change the acceptable value*/
							time->date = 1;

							/*Set the update month flag*/
							Set_flag(time->flag.up_mon);
						}
					}
				}
			}
			break;
		case DAY:
			if(time->day > 7){
				/*Change the acceptable value*/
				time->day = 1;
			}
			break;
		case MON:
			if(time->mon > 12){
				/*Change the acceptable value*/
				time->mon = 1;

				/*Set the update year flag*/
				Set_flag(time->flag.up_year);
			}
			break;
		default:
			/*nothing*/
			break;
	}
}

void Set_flag(uint8_t flag){
	flag = 1;
}
void Clear_flag(uint8_t flag){
	flag = 0;
}
