#include "mode.h"

void display_mode(void){
	for (int i = 0; i < LCD_BUF_SIZE; i++){
		display_data[i] = 0xff;
	}
	char temp[10];
	itoa(current_time.date, temp, 10);
	LCD_get_string(1, 2, display_data, temp);
	LCD_get_string(3, 2, display_data, ":");
	itoa(current_time.mon, temp, 10);
	LCD_get_string(4, 2, display_data, temp);
	LCD_get_string(6, 2, display_data, ":");
	itoa(current_time.year, temp, 10);
	LCD_get_string(7, 2, display_data, temp);

	switch(current_time.day){
	case MONDAY:
		LCD_get_string(2, 4, display_data, "MONDAY");
		break;
	case TUESDAY:
		LCD_get_string(2, 4, display_data, "TUESDAY");
		break;
	case WEDNESDAY:
		LCD_get_string(2, 4, display_data, "WEDNESDAY");
		break;
	case THURSDAY:
		LCD_get_string(2, 4, display_data, "THURSDAY");
		break;
	case FRIDAY:
		LCD_get_string(2, 4, display_data, "FRIDAY");
		break;
	case SATURDAY:
		LCD_get_string(2, 4, display_data, "SATURDAY");
		break;
	case SUNDAY:
		LCD_get_string(2, 4, display_data, "SUNDAY");
		break;
	default:
		LCD_get_string(2, 4, display_data, "ERROR");
	}

	itoa(current_time.hour, temp, 10);
	LCD_get_string(1, 6, display_data, temp);
	LCD_get_string(3, 6, display_data, ":");
	itoa(current_time.min, temp, 10);
	LCD_get_string(4, 6, display_data, temp);
	LCD_get_string(6, 6, display_data, ":");
	itoa(current_time.sec, temp, 10);
	LCD_get_string(7, 6, display_data, temp);
	LCD_send_image(display_data);
	mode = DISPLAY_MODE;
}

void set_dmy_mode(void){
	for (int i = 0; i < LCD_BUF_SIZE; i++){
		display_data[i] = 0xff;
	}
	char temp[10];
	itoa(temp_time.date, temp, 10);
	LCD_get_string(1, 2, display_data, temp);
	LCD_get_string(3, 2, display_data, ":");
	itoa(temp_time.mon, temp, 10);
	LCD_get_string(4, 2, display_data, temp);
	LCD_get_string(6, 2, display_data, ":");
	itoa(temp_time.year, temp, 10);
	LCD_get_string(7, 2, display_data, temp);

	switch(temp_time.day){
	case MONDAY:
		LCD_get_string(2, 4, display_data, "MONDAY");
		break;
	case TUESDAY:
		LCD_get_string(2, 4, display_data, "TUESDAY");
		break;
	case WEDNESDAY:
		LCD_get_string(2, 4, display_data, "WEDNESDAY");
		break;
	case THURSDAY:
		LCD_get_string(2, 4, display_data, "THURSDAY");
		break;
	case FRIDAY:
		LCD_get_string(2, 4, display_data, "FRIDAY");
		break;
	case SATURDAY:
		LCD_get_string(2, 4, display_data, "SATURDAY");
		break;
	case SUNDAY:
		LCD_get_string(2, 4, display_data, "SUNDAY");
		break;
	default:
		LCD_get_string(2, 4, display_data, "ERROR");
	}
	LCD_send_image(display_data);
	mode = SET_DMY_MODE;
}

void set_year_mode(void){
	for (int i = 0; i < LCD_BUF_SIZE; i++){
		display_data[i] = 0xff;
	}
	char temp[10];
	itoa(temp_time.date, temp, 10);
	LCD_get_string(1, 2, display_data, temp);
	LCD_get_string(3, 2, display_data, ":");
	itoa(temp_time.mon, temp, 10);
	LCD_get_string(4, 2, display_data, temp);
	LCD_get_string(6, 2, display_data, ":");
	if(blink == 1){
		LCD_get_string(7, 2, display_data, "  ");
	}
	else{
		itoa(temp_time.year, temp, 10);
		LCD_get_string(7, 2, display_data, temp);
	}

	switch(temp_time.day){
	case MONDAY:
		LCD_get_string(2, 4, display_data, "MONDAY");
		break;
	case TUESDAY:
		LCD_get_string(2, 4, display_data, "TUESDAY");
		break;
	case WEDNESDAY:
		LCD_get_string(2, 4, display_data, "WEDNESDAY");
		break;
	case THURSDAY:
		LCD_get_string(2, 4, display_data, "THURSDAY");
		break;
	case FRIDAY:
		LCD_get_string(2, 4, display_data, "FRIDAY");
		break;
	case SATURDAY:
		LCD_get_string(2, 4, display_data, "SATURDAY");
		break;
	case SUNDAY:
		LCD_get_string(2, 4, display_data, "SUNDAY");
		break;
	default:
		LCD_get_string(2, 4, display_data, "ERROR");
	}

	LCD_send_image(display_data);
	mode = SET_YEAR_MODE;
}

void set_mon_mode(void){
	if(blink == 1){
		LCD_get_string(4, 2, display_data, "  ");
	}
	else{
		char temp[5];
		itoa(temp_time.mon, temp, 10);
		LCD_get_string(4, 2, display_data, temp);
	}
	LCD_send_image(display_data);
	mode = SET_MON_MODE;
}

void set_date_mode(void){
	if(blink == 1){
		LCD_get_string(1, 2, display_data, "  ");
	}
	else{
		char temp[10];
		itoa(current_time.date, temp, 10);
		LCD_get_string(1, 2, display_data, temp);
	}
	LCD_send_image(display_data);
	mode = SET_DATE_MODE;
}

void set_day_mode(void){
	if(blink == 1){
		LCD_get_string(2, 4, display_data, "         ");
	}
	else{
		switch(temp_time.day){
			case MONDAY:
				LCD_get_string(2, 4, display_data, "MONDAY");
				break;
			case TUESDAY:
				LCD_get_string(2, 4, display_data, "TUESDAY");
				break;
			case WEDNESDAY:
				LCD_get_string(2, 4, display_data, "WEDNESDAY");
				break;
			case THURSDAY:
				LCD_get_string(2, 4, display_data, "THURSDAY");
				break;
			case FRIDAY:
				LCD_get_string(2, 4, display_data, "FRIDAY");
				break;
			case SATURDAY:
				LCD_get_string(2, 4, display_data, "SATURDAY");
				break;
			case SUNDAY:
				LCD_get_string(2, 4, display_data, "SUNDAY");
				break;
			default:
				LCD_get_string(2, 4, display_data, "ERROR");
		}
	}

	mode = SET_DAY_MODE;
}

void increase_year_mode(void){
	temp_time.year++;
	if(temp_time.year >= 2100){
		temp_time.year = 2000;
	}
}

void decrease_year_mode(void){
	temp_time.year--;
	if(temp_time.year <= 2000){
		temp_time.year = 2099;
	}
}

void increase_mon_mode(void){
	temp_time.mon++;
	if(temp_time.mon >= 13){
		temp_time.mon = 1;
	}
}

void decrease_mon_mode(void){
	temp_time.mon--;
	if(temp_time.mon <= 0){
		temp_time.mon = 12;
	}
}

void increase_date_mode(void){
	temp_time.date++;
	if( (temp_time.mon == 1) | (temp_time.mon == 3) | (temp_time.mon == 5) | (temp_time.mon == 7) | (temp_time.mon == 8) | (temp_time.mon == 10) | (temp_time.mon == 12)){
		if (temp_time.date > 31){
			temp_time.date = 1;
		}
		if ( (temp_time.mon == 4) | (temp_time.mon == 6) | (temp_time.mon == 9) | (temp_time.mon == 11)){
			if (temp_time.date > 30){
				temp_time.date = 1;
			}
		}
		if (temp_time.mon == 2){
			if (temp_time.year % 4 == 0){
				if (temp_time.date > 29){
					temp_time.date = 1;
				}
			}
			else{
				if (temp_time.date > 28){
					temp_time.date = 1;
				}
			}
		}
	}
}

void decrease_date_mode(void){
	temp_time.date--;
	if( (temp_time.mon == 1) | (temp_time.mon == 3) | (temp_time.mon == 5) | (temp_time.mon == 7) | (temp_time.mon == 8) | (temp_time.mon == 10) | (temp_time.mon == 12)){
			if (temp_time.date < 1){
				temp_time.date = 31;
			}
			if ( (temp_time.mon == 4) | (temp_time.mon == 6) | (temp_time.mon == 9) | (temp_time.mon == 11)){
				if (temp_time.date < 1){
					temp_time.date = 30;
				}
			}
			if (temp_time.mon == 2){
				if (temp_time.year % 4 == 0){
					if (temp_time.date < 1){
						temp_time.date = 29;
					}
				}
				else{
					if (temp_time.date < 1){
						temp_time.date = 28;
					}
				}
			}
		}
}

void increase_day_mode(void){
	temp_time.day++;
	if(temp_time.day >= 9){
		temp_time.day = 2;
	}
}

void decrease_day_mode(void){
	temp_time.day--;
	if(temp_time.day <= 1){
		temp_time.day = 8;
	}
}

void save_mode(void){
	switch (mode) {
		case SET_DATE_MODE:
			Set_dmy(temp_time.year, temp_time.mon, temp_time.date, temp_time.day);
			break;
		case SET_SEC_MODE:
			if(set_alarm){
				alarm_time = temp_time;
				Set_alarm(alarm_time.hour, alarm_time.min, alarm_time.sec);
			}
			else{
				Set_hms(temp_time.hour, temp_time.min, temp_time.sec);
			}
			break;
		case SET_CYCLE_SUNDAY_MODE:
			cycle = temp_cycle;
			Set_cycle(cycle);
			break;
		default:
			break;
	}
	mode = DISPLAY_MODE;
}

void set_hms_mode(void){
	for (int i = 0; i < LCD_BUF_SIZE; i++){
		display_data[i] = 0xff;
	}
	char temp[10];
	itoa(temp_time.hour, temp, 10);
	LCD_get_string(1, 6, display_data, temp);
	LCD_get_string(3, 6, display_data, ":");
	itoa(temp_time.min, temp, 10);
	LCD_get_string(4, 6, display_data, temp);
	LCD_get_string(6, 6, display_data, ":");
	itoa(temp_time.sec, temp, 10);
	LCD_get_string(7, 6, display_data, temp);
	LCD_send_image(display_data);
	mode = SET_HMS_MODE;
}

void set_alarm_mode(void){
	for (int i = 0; i < LCD_BUF_SIZE; i++){
		display_data[i] = 0xff;
	}
	char temp[10];
	itoa(temp_time.hour, temp, 10);
	LCD_get_string(1, 6, display_data, temp);
	LCD_get_string(3, 6, display_data, ":");
	itoa(temp_time.min, temp, 10);
	LCD_get_string(4, 6, display_data, temp);
	LCD_get_string(6, 6, display_data, ":");
	itoa(temp_time.sec, temp, 10);
	LCD_get_string(7, 6, display_data, temp);
	LCD_send_image(display_data);
	mode = SET_ALARM_MODE;
}

void set_hour_mode(void){
	for (int i = 0; i < LCD_BUF_SIZE; i++){
		display_data[i] = 0xff;
	}
	char temp[10];
	if(blink == 1){
		LCD_get_string(1, 6, display_data, "  ");
	}
	else{
		itoa(temp_time.hour, temp, 10);
		LCD_get_string(1, 6, display_data, temp);
	}
	LCD_get_string(3, 6, display_data, ":");
	itoa(temp_time.min, temp, 10);
	LCD_get_string(4, 6, display_data, temp);
	LCD_get_string(6, 6, display_data, ":");
	itoa(temp_time.sec, temp, 10);
	LCD_get_string(7, 6, display_data, temp);
	LCD_send_image(display_data);
	mode = SET_HOUR_MODE;
}

void set_min_mode(void){
	for (int i = 0; i < LCD_BUF_SIZE; i++){
		display_data[i] = 0xff;
	}
	char temp[10];

	itoa(temp_time.hour, temp, 10);
	LCD_get_string(1, 6, display_data, temp);
	LCD_get_string(3, 6, display_data, ":");

	if(blink == 1){
		LCD_get_string(1, 6, display_data, "  ");
	}
	else{
		itoa(temp_time.min, temp, 10);
		LCD_get_string(4, 6, display_data, temp);
	}

	LCD_get_string(6, 6, display_data, ":");
	itoa(temp_time.sec, temp, 10);
	LCD_get_string(7, 6, display_data, temp);
	LCD_send_image(display_data);
	mode = SET_MIN_MODE;
}

void set_sec_mode(void){
	for (int i = 0; i < LCD_BUF_SIZE; i++){
		display_data[i] = 0xff;
	}
	char temp[10];

	itoa(temp_time.hour, temp, 10);
	LCD_get_string(1, 6, display_data, temp);
	LCD_get_string(3, 6, display_data, ":");
	itoa(temp_time.min, temp, 10);
	LCD_get_string(4, 6, display_data, temp);
	LCD_get_string(6, 6, display_data, ":");

	if(blink == 1){
		LCD_get_string(1, 6, display_data, "  ");
	}
	else{
		itoa(temp_time.sec, temp, 10);
		LCD_get_string(7, 6, display_data, temp);
	}

	LCD_send_image(display_data);
	mode = SET_SEC_MODE;
}

void increase_hour_mode(void){
	temp_time.hour++;
	if(temp_time.hour >= 24){
		temp_time.hour = 0;
	}
}

void decrease_hour_mode(void){
	temp_time.hour--;
	if(temp_time.hour >=24){
		temp_time.hour = 23;
	}
}

void increase_min_mode(void){
	temp_time.min++;
	if(temp_time.min >= 60){
		temp_time.min = 0;
	}
}

void decrease_min_mode(void){
	temp_time.min--;
	if(temp_time.min >= 60){
		temp_time.min = 59;
	}
}

void increase_sec_mode(void){
	temp_time.sec++;
	if(temp_time.sec >= 60){
		temp_time.sec = 0;
	}
}

void decrease_sec_mode(void){
	temp_time.sec--;
	if(temp_time.sec >= 60){
		temp_time.sec = 59;
	}
}

void set_cycle_mode(void){
	for (int i = 0; i < LCD_BUF_SIZE; i++){
		display_data[i] = 0xff;
	}
	LCD_get_string(1, 4, display_data, "MON");
	LCD_get_string(1, 6, display_data, "TUE");
	LCD_get_string(1, 8, display_data, "WED");
	LCD_get_string(1, 10, display_data, "THU");
	LCD_get_string(7, 4, display_data, "FRI");
	LCD_get_string(7, 6, display_data, "SAT");
	LCD_get_string(7, 8, display_data, "SUN");


	if(temp_cycle & (1 << 0)){
		LCD_get_string(5, 4, display_data, "X");
	}else{
		LCD_get_string(5, 4, display_data, " ");
	}
	if(temp_cycle & (1 << 1)){
		LCD_get_string(5, 6, display_data, "X");
	}else{
		LCD_get_string(5, 6, display_data, " ");
	}
	if(temp_cycle & (1 << 2)){
		LCD_get_string(5, 8, display_data, "X");
	}else{
		LCD_get_string(5, 8, display_data, " ");
	}
	if(temp_cycle & (1 << 3)){
		LCD_get_string(5, 10, display_data, "X");
	}else{
		LCD_get_string(5, 10, display_data, " ");
	}
	if(temp_cycle & (1 << 4)){
		LCD_get_string(11, 4, display_data, "X");
	}else{
		LCD_get_string(11, 4, display_data, " ");
	}
	if(temp_cycle & (1 << 5)){
		LCD_get_string(11, 6, display_data, "X");
	}else{
		LCD_get_string(11, 6, display_data, " ");
	}
	if(temp_cycle & (1 << 6)){
		LCD_get_string(11, 8, display_data, "X");
	}else{
		LCD_get_string(11, 8, display_data, " ");
	}
	mode = SET_CYCLE_MODE;
}

void set_cycle_monday_mode(void){
	for (int i = 0; i < LCD_BUF_SIZE; i++){
			display_data[i] = 0xff;
		}

	if(blink == 1){
		LCD_get_string(1, 4, display_data, "MON");
	}
	else{
		LCD_get_string(1, 4, display_data, "   ");
	}

	LCD_get_string(1, 6, display_data, "TUE");
	LCD_get_string(1, 8, display_data, "WED");
	LCD_get_string(1, 10, display_data, "THU");
	LCD_get_string(7, 4, display_data, "FRI");
	LCD_get_string(7, 6, display_data, "SAT");
	LCD_get_string(7, 8, display_data, "SUN");

	if(temp_cycle & (1 << 0)){
		LCD_get_string(5, 4, display_data, "X");
	}else{
		LCD_get_string(5, 4, display_data, " ");
	}
	if(temp_cycle & (1 << 1)){
		LCD_get_string(5, 6, display_data, "X");
	}else{
		LCD_get_string(5, 6, display_data, " ");
	}
	if(temp_cycle & (1 << 2)){
		LCD_get_string(5, 8, display_data, "X");
	}else{
		LCD_get_string(5, 8, display_data, " ");
	}
	if(temp_cycle & (1 << 3)){
		LCD_get_string(5, 10, display_data, "X");
	}else{
		LCD_get_string(5, 10, display_data, " ");
	}
	if(temp_cycle & (1 << 4)){
		LCD_get_string(11, 4, display_data, "X");
	}else{
		LCD_get_string(11, 4, display_data, " ");
	}
	if(temp_cycle & (1 << 5)){
		LCD_get_string(11, 6, display_data, "X");
	}else{
		LCD_get_string(11, 6, display_data, " ");
	}
	if(temp_cycle & (1 << 6)){
		LCD_get_string(11, 8, display_data, "X");
	}else{
		LCD_get_string(11, 8, display_data, " ");
	}
	mode = SET_CYCLE_MONDAY_MODE;
}

void set_cycle_tuesday_mode(void){
	for (int i = 0; i < LCD_BUF_SIZE; i++){
			display_data[i] = 0xff;
		}

	if(blink == 1){
		LCD_get_string(1, 6, display_data, "TUE");
	}
	else{
		LCD_get_string(1, 6, display_data, "   ");
	}

	LCD_get_string(1, 4, display_data, "MON");
	LCD_get_string(1, 8, display_data, "WED");
	LCD_get_string(1, 10, display_data, "THU");
	LCD_get_string(7, 4, display_data, "FRI");
	LCD_get_string(7, 6, display_data, "SAT");
	LCD_get_string(7, 8, display_data, "SUN");

	if(temp_cycle & (1 << 0)){
		LCD_get_string(5, 4, display_data, "X");
	}else{
		LCD_get_string(5, 4, display_data, " ");
	}
	if(temp_cycle & (1 << 1)){
		LCD_get_string(5, 6, display_data, "X");
	}else{
		LCD_get_string(5, 6, display_data, " ");
	}
	if(temp_cycle & (1 << 2)){
		LCD_get_string(5, 8, display_data, "X");
	}else{
		LCD_get_string(5, 8, display_data, " ");
	}
	if(temp_cycle & (1 << 3)){
		LCD_get_string(5, 10, display_data, "X");
	}else{
		LCD_get_string(5, 10, display_data, " ");
	}
	if(temp_cycle & (1 << 4)){
		LCD_get_string(11, 4, display_data, "X");
	}else{
		LCD_get_string(11, 4, display_data, " ");
	}
	if(temp_cycle & (1 << 5)){
		LCD_get_string(11, 6, display_data, "X");
	}else{
		LCD_get_string(11, 6, display_data, " ");
	}
	if(temp_cycle & (1 << 6)){
		LCD_get_string(11, 8, display_data, "X");
	}else{
		LCD_get_string(11, 8, display_data, " ");
	}
	mode = SET_CYCLE_TUESDAY_MODE;
}

void set_cycle_wednesday_mode(void){
	for (int i = 0; i < LCD_BUF_SIZE; i++){
			display_data[i] = 0xff;
		}

	if(blink == 1){
		LCD_get_string(1, 8, display_data, "WED");
	}
	else{
		LCD_get_string(1, 8, display_data, "   ");
	}

	LCD_get_string(1, 4, display_data, "MON");
	LCD_get_string(1, 6, display_data, "TUE");
	LCD_get_string(1, 10, display_data, "THU");
	LCD_get_string(7, 4, display_data, "FRI");
	LCD_get_string(7, 6, display_data, "SAT");
	LCD_get_string(7, 8, display_data, "SUN");

	if(temp_cycle & (1 << 0)){
		LCD_get_string(5, 4, display_data, "X");
	}else{
		LCD_get_string(5, 4, display_data, " ");
	}
	if(temp_cycle & (1 << 1)){
		LCD_get_string(5, 6, display_data, "X");
	}else{
		LCD_get_string(5, 6, display_data, " ");
	}
	if(temp_cycle & (1 << 2)){
		LCD_get_string(5, 8, display_data, "X");
	}else{
		LCD_get_string(5, 8, display_data, " ");
	}
	if(temp_cycle & (1 << 3)){
		LCD_get_string(5, 10, display_data, "X");
	}else{
		LCD_get_string(5, 10, display_data, " ");
	}
	if(temp_cycle & (1 << 4)){
		LCD_get_string(11, 4, display_data, "X");
	}else{
		LCD_get_string(11, 4, display_data, " ");
	}
	if(temp_cycle & (1 << 5)){
		LCD_get_string(11, 6, display_data, "X");
	}else{
		LCD_get_string(11, 6, display_data, " ");
	}
	if(temp_cycle & (1 << 6)){
		LCD_get_string(11, 8, display_data, "X");
	}else{
		LCD_get_string(11, 8, display_data, " ");
	}
	mode = SET_CYCLE_WEDNESDAY_MODE;
}

void set_cycle_thurday_mode(void){
	for (int i = 0; i < LCD_BUF_SIZE; i++){
			display_data[i] = 0xff;
		}

	if(blink == 1){
		LCD_get_string(1, 10, display_data, "THU");
	}
	else{
		LCD_get_string(1, 10, display_data, "   ");
	}

	LCD_get_string(1, 4, display_data, "MON");
	LCD_get_string(1, 6, display_data, "TUE");
	LCD_get_string(1, 8, display_data, "WED");
	LCD_get_string(7, 4, display_data, "FRI");
	LCD_get_string(7, 6, display_data, "SAT");
	LCD_get_string(7, 8, display_data, "SUN");

	if(temp_cycle & (1 << 0)){
		LCD_get_string(5, 4, display_data, "X");
	}else{
		LCD_get_string(5, 4, display_data, " ");
	}
	if(temp_cycle & (1 << 1)){
		LCD_get_string(5, 6, display_data, "X");
	}else{
		LCD_get_string(5, 6, display_data, " ");
	}
	if(temp_cycle & (1 << 2)){
		LCD_get_string(5, 8, display_data, "X");
	}else{
		LCD_get_string(5, 8, display_data, " ");
	}
	if(temp_cycle & (1 << 3)){
		LCD_get_string(5, 10, display_data, "X");
	}else{
		LCD_get_string(5, 10, display_data, " ");
	}
	if(temp_cycle & (1 << 4)){
		LCD_get_string(11, 4, display_data, "X");
	}else{
		LCD_get_string(11, 4, display_data, " ");
	}
	if(temp_cycle & (1 << 5)){
		LCD_get_string(11, 6, display_data, "X");
	}else{
		LCD_get_string(11, 6, display_data, " ");
	}
	if(temp_cycle & (1 << 6)){
		LCD_get_string(11, 8, display_data, "X");
	}else{
		LCD_get_string(11, 8, display_data, " ");
	}
	mode = SET_CYCLE_THURDAY_MODE;
}
void set_cycle_friday_mode(void){
	for (int i = 0; i < LCD_BUF_SIZE; i++){
			display_data[i] = 0xff;
		}

	if(blink == 1){
		LCD_get_string(7, 4, display_data, "FRI");
	}
	else{
		LCD_get_string(7, 4, display_data, "   ");
	}

	LCD_get_string(1, 4, display_data, "MON");
	LCD_get_string(1, 6, display_data, "TUE");
	LCD_get_string(1, 8, display_data, "WED");
	LCD_get_string(1, 10, display_data, "THU");
	LCD_get_string(7, 6, display_data, "SAT");
	LCD_get_string(7, 8, display_data, "SUN");

	if(temp_cycle & (1 << 0)){
		LCD_get_string(5, 4, display_data, "X");
	}else{
		LCD_get_string(5, 4, display_data, " ");
	}
	if(temp_cycle & (1 << 1)){
		LCD_get_string(5, 6, display_data, "X");
	}else{
		LCD_get_string(5, 6, display_data, " ");
	}
	if(temp_cycle & (1 << 2)){
		LCD_get_string(5, 8, display_data, "X");
	}else{
		LCD_get_string(5, 8, display_data, " ");
	}
	if(temp_cycle & (1 << 3)){
		LCD_get_string(5, 10, display_data, "X");
	}else{
		LCD_get_string(5, 10, display_data, " ");
	}
	if(temp_cycle & (1 << 4)){
		LCD_get_string(11, 4, display_data, "X");
	}else{
		LCD_get_string(11, 4, display_data, " ");
	}
	if(temp_cycle & (1 << 5)){
		LCD_get_string(11, 6, display_data, "X");
	}else{
		LCD_get_string(11, 6, display_data, " ");
	}
	if(temp_cycle & (1 << 6)){
		LCD_get_string(11, 8, display_data, "X");
	}else{
		LCD_get_string(11, 8, display_data, " ");
	}
	mode = SET_CYCLE_FRIDAY_MODE;
}

void set_cycle_saturday_mode(void){
	for (int i = 0; i < LCD_BUF_SIZE; i++){
			display_data[i] = 0xff;
		}

	if(blink == 1){
		LCD_get_string(7, 6, display_data, "SAT");
	}
	else{
		LCD_get_string(7, 6, display_data, "   ");
	}

	LCD_get_string(1, 4, display_data, "MON");
	LCD_get_string(1, 6, display_data, "TUE");
	LCD_get_string(1, 8, display_data, "WED");
	LCD_get_string(1, 10, display_data, "THU");
	LCD_get_string(7, 4, display_data, "FRI");
	LCD_get_string(7, 8, display_data, "SUN");

	if(temp_cycle & (1 << 0)){
		LCD_get_string(5, 4, display_data, "X");
	}else{
		LCD_get_string(5, 4, display_data, " ");
	}
	if(temp_cycle & (1 << 1)){
		LCD_get_string(5, 6, display_data, "X");
	}else{
		LCD_get_string(5, 6, display_data, " ");
	}
	if(temp_cycle & (1 << 2)){
		LCD_get_string(5, 8, display_data, "X");
	}else{
		LCD_get_string(5, 8, display_data, " ");
	}
	if(temp_cycle & (1 << 3)){
		LCD_get_string(5, 10, display_data, "X");
	}else{
		LCD_get_string(5, 10, display_data, " ");
	}
	if(temp_cycle & (1 << 4)){
		LCD_get_string(11, 4, display_data, "X");
	}else{
		LCD_get_string(11, 4, display_data, " ");
	}
	if(temp_cycle & (1 << 5)){
		LCD_get_string(11, 6, display_data, "X");
	}else{
		LCD_get_string(11, 6, display_data, " ");
	}
	if(temp_cycle & (1 << 6)){
		LCD_get_string(11, 8, display_data, "X");
	}else{
		LCD_get_string(11, 8, display_data, " ");
	}
	mode = SET_CYCLE_SATURDAY_MODE;
}

void set_cycle_sunday_mode(void){
	for (int i = 0; i < LCD_BUF_SIZE; i++){
			display_data[i] = 0xff;
		}

	if(blink == 1){
		LCD_get_string(7, 8, display_data, "SUN");
	}
	else{
		LCD_get_string(7, 8, display_data, "   ");
	}

	LCD_get_string(1, 4, display_data, "MON");
	LCD_get_string(1, 6, display_data, "TUE");
	LCD_get_string(1, 8, display_data, "WED");
	LCD_get_string(1, 10, display_data, "THU");
	LCD_get_string(7, 4, display_data, "FRI");
	LCD_get_string(7, 6, display_data, "SAT");

	if(temp_cycle & (1 << 0)){
		LCD_get_string(5, 4, display_data, "X");
	}else{
		LCD_get_string(5, 4, display_data, " ");
	}
	if(temp_cycle & (1 << 1)){
		LCD_get_string(5, 6, display_data, "X");
	}else{
		LCD_get_string(5, 6, display_data, " ");
	}
	if(temp_cycle & (1 << 2)){
		LCD_get_string(5, 8, display_data, "X");
	}else{
		LCD_get_string(5, 8, display_data, " ");
	}
	if(temp_cycle & (1 << 3)){
		LCD_get_string(5, 10, display_data, "X");
	}else{
		LCD_get_string(5, 10, display_data, " ");
	}
	if(temp_cycle & (1 << 4)){
		LCD_get_string(11, 4, display_data, "X");
	}else{
		LCD_get_string(11, 4, display_data, " ");
	}
	if(temp_cycle & (1 << 5)){
		LCD_get_string(11, 6, display_data, "X");
	}else{
		LCD_get_string(11, 6, display_data, " ");
	}
	if(temp_cycle & (1 << 6)){
		LCD_get_string(11, 8, display_data, "X");
	}else{
		LCD_get_string(11, 8, display_data, " ");
	}
	mode = SET_CYCLE_SUNDAY_MODE;
}

void change_cycle_mode(void){
	switch (mode) {
		case SET_CYCLE_MONDAY_MODE:
			temp_cycle ^= (1 << 0);
			break;
		case SET_CYCLE_TUESDAY_MODE:
			temp_cycle ^= (1 << 1);
			break;
		case SET_CYCLE_WEDNESDAY_MODE:
			temp_cycle ^= (1 << 2);
			break;
		case SET_CYCLE_THURDAY_MODE:
			temp_cycle ^= (1 << 3);
			break;
		case SET_CYCLE_FRIDAY_MODE:
			temp_cycle ^= (1 << 4);
			break;
		case SET_CYCLE_SATURDAY_MODE:
			temp_cycle ^= (1 << 5);
			break;
		case SET_CYCLE_SUNDAY_MODE:
			temp_cycle ^= (1 << 6);
			break;
		default:
			break;
	}
}
void alarm_mode(void){
	for (int i = 0; i < LCD_BUF_SIZE; i++){
		display_data[i] = 0xff;
	}
	LCD_get_string(1, 6, display_data, "ALARM!");
	if(current_time.min != alarm_time.min){
		Set_alarm_times(alarm_times--);
		if(alarm_times != 0){
			Set_alarm(current_time.hour, current_time.min + 4, current_time.sec);
		}
		else{
			Set_alarm(alarm_time.hour, alarm_time.min, alarm_time.sec);
		}
		mode = DISPLAY_MODE;
	}
	else{
		mode = ALARM_MODE;
	}
}

