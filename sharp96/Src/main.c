#include "stm32f1xx.h"
#include "gpio.h"
#include "gpio_exti.h"
#include "sharp96.h"
#include "rcc_config.h"
#include "tim.h"
#include "spi.h"
#include "rtc.h"
#include "rtc_app.h"
#include "mode.h"
#include "digital_clock.h"
#include "standby.h"
#include "test_img.h"

#define TEST	0
#define SET		0

uint8_t display_data[LCD_BUF_SIZE];
t_time current_time, temp_time, alarm_time;
process_mode_t mode;
uint8_t blink;
uint8_t flag, set_alarm;
uint8_t cycle, temp_cycle, alarm_times;

void mode_handler(void);
void flag_handler(void);
void (*button0_mode_ptr)(void);
void (*button1_mode_ptr)(void);
void (*button2_mode_ptr)(void);
void (*button3_mode_ptr)(void);

int main(void){
	SysClockConfig();
	RTC_clk_config();

	SPI1_pin_init();
	SPI1_master_config();
	SPI1_enable();

	GPIO_Pin_Configure(LED, OUTPUT_10MHZ, OUTPUT_GP_OD);
	Button_init();

	LCD_init();
	LCD_enable();

	RTC_interrupt_en();
	Wakeup_pin_init();
	Wakeup_pin_en();

	Timer2Config();
	Timer3Config();
	Timer4Config();

	if(SET){
		Set_dmy(2024, 12, 13, 2);
		Set_hms(5, 55, 55);
		Set_alarm(5, 57, 0);
		Set_cycle(3);
		Set_alarm_times(2);
	}

	if(TEST){
		for (int i = 0; i < LCD_BUF_SIZE; i++){
			display_data[i] = 0xff;
		}
		char str[] = "BUGGING";
		LCD_get_string(3, 7, display_data, str);
		LCD_send_image(display_data);
		LCD_display();
		Delay_ms(1000);
		LCD_send_image(stitch);
		Delay_ms(1000);
	}

	/*Read data in BKD*/
	Get_cycle(&cycle);
	Get_alarm_times(&alarm_times);

	/*Set initial value*/
	button0_mode_ptr = &set_dmy_mode;
	button1_mode_ptr = &set_hms_mode;
	button2_mode_ptr = &set_cycle_mode;
	button3_mode_ptr = &set_alarm_mode;
	mode = DISPLAY_MODE;
	flag = 0;

	while(1){
		Get_time(&current_time);
		flag_handler();
		mode_handler();
		LCD_display();
	}
}


void EXTI4_IRQHandler(void)
{
	if (EXTI->PR & (1<<4))    // If the PA4 triggered the interrupt
	{
		flag = 1;
		EXTI->PR |= (1<<4);  // Clear the interrupt flag by writing a 1
	}
}

void EXTI3_IRQHandler(void)
{
	if (EXTI->PR & (1<<3))    // If the PA3 triggered the interrupt
	{
		flag = 2;
		EXTI->PR |= (1<<3);  // Clear the interrupt flag by writing a 1
	}
}

void EXTI15_10_IRQHandler(void)
{

	if (EXTI->PR & (1<<11))    // If the PA11 triggered the interrupt
	{
		flag = 3;
		EXTI->PR |= (1<<11);  // Clear the interrupt flag by writing a 1
	}
	if (EXTI->PR & (1<<12))    // If the PA12 triggered the interrupt
	{
		flag = 4;
		EXTI->PR |= (1<<12);  // Clear the interrupt flag by writing a 1
	}
}

void EXTI9_5_IRQHandler(void)
{

	if (EXTI->PR & (1<<5))    // If the PB5 triggered the interrupt
	{
		flag = 3;
		EXTI->PR |= (1<<5);  // Clear the interrupt flag by writing a 1
	}

	if (EXTI->PR & (1<<6))    // If the PB6 triggered the interrupt
	{
		flag = 4;
		EXTI->PR |= (1<<6);  // Clear the interrupt flag by writing a 1
	}
}

void TIM3_IRQHandler(void){
	blink ^= 1;
    TIM3->SR &= ~TIM_SR_UIF;
}

void TIM4_IRQHandler(void){
	flag = 6;
    TIM4->SR &= ~TIM_SR_UIF;
}

void RTC_IRQHandler(void){
	flag = 5;
	RTC->CRL &= ~RTC_CRL_ALRF;
}

void flag_handler(void){
	switch (flag) {
		case 1:
			Delay_ms(100);
			Reset_timer4_counter();
			button0_mode_ptr();
			flag = 0;
			break;
		case 2:
			Delay_ms(100);
			Reset_timer4_counter();
			button1_mode_ptr();
			flag = 0;
			break;
		case 3:
			Delay_ms(100);
			Reset_timer4_counter();
			button2_mode_ptr();
			flag = 0;
			break;
		case 4:
			Delay_ms(100);
			Reset_timer4_counter();
			button3_mode_ptr();
			flag = 0;
			break;
		case 5:
			if(cycle & (1 << (current_time.day - 2))){
				mode = ALARM_MODE;
				GPIO_set_out_pin(GPIO_A, 5, 0);
			}
			flag = 0;
			break;
		case 6:
			/*Save data to BKD*/

			/*Enter standby mode*/
			Enter_standby_mode();
			break;
		default:
			flag = 0;
			break;
	}
}

void mode_handler(void){
	switch (mode) {
		case DISPLAY_MODE:
			button0_mode_ptr = &set_dmy_mode;
			button1_mode_ptr = &set_hms_mode;
			button2_mode_ptr = &set_cycle_mode;
			button3_mode_ptr = &set_alarm_mode;
			display_mode();
			break;
		case SET_DMY_MODE:
			temp_time = current_time;
			button0_mode_ptr = &display_mode;
			button1_mode_ptr = &set_year_mode;
			button2_mode_ptr = &display_mode;
			button3_mode_ptr = &display_mode;
			set_dmy_mode();
			break;
		case SET_YEAR_MODE:
			button0_mode_ptr = &display_mode;
			button1_mode_ptr = &set_mon_mode;
			button2_mode_ptr = &increase_year_mode;
			button3_mode_ptr = &decrease_year_mode;
			set_year_mode();
			break;
		case SET_MON_MODE:
			button0_mode_ptr = &display_mode;
			button1_mode_ptr = &set_date_mode;
			button2_mode_ptr = &increase_mon_mode;
			button3_mode_ptr = &decrease_mon_mode;
			set_mon_mode();
			break;
		case SET_DATE_MODE:
			button0_mode_ptr = &display_mode;
			button1_mode_ptr = &set_day_mode;
			button2_mode_ptr = &increase_date_mode;
			button3_mode_ptr = &decrease_date_mode;
			set_date_mode();
			break;
		case SET_DAY_MODE:
			button0_mode_ptr = &display_mode;
			button1_mode_ptr = &save_mode;
			button2_mode_ptr = &increase_day_mode;
			button3_mode_ptr = &decrease_day_mode;
			set_day_mode();
			break;
		case SET_HMS_MODE:
			button0_mode_ptr = &display_mode;
			button1_mode_ptr = &set_hour_mode;
			button2_mode_ptr = &display_mode;
			button3_mode_ptr = &display_mode;
			set_hms_mode();
			break;
		case SET_HOUR_MODE:
			button0_mode_ptr = &display_mode;
			button1_mode_ptr = &set_min_mode;
			button2_mode_ptr = &increase_hour_mode;
			button3_mode_ptr = &decrease_hour_mode;
			set_hour_mode();
			break;
		case SET_MIN_MODE:
			button0_mode_ptr = &display_mode;
			button1_mode_ptr = &set_sec_mode;
			button2_mode_ptr = &increase_min_mode;
			button3_mode_ptr = &decrease_min_mode;
			set_min_mode();
			break;
		case SET_SEC_MODE:
			button0_mode_ptr = &display_mode;
			button1_mode_ptr = &save_mode;
			button2_mode_ptr = &increase_sec_mode;
			button3_mode_ptr = &decrease_sec_mode;
			set_sec_mode();
			break;
		case SET_CYCLE_MODE:
			temp_cycle = cycle;
			button0_mode_ptr = &display_mode;
			button1_mode_ptr = &set_cycle_monday_mode;
			button2_mode_ptr = &display_mode;
			button3_mode_ptr = &display_mode;
			set_cycle_mode();
			break;
		case SET_CYCLE_MONDAY_MODE:
			button0_mode_ptr = &display_mode;
			button1_mode_ptr = &set_cycle_tuesday_mode;
			button2_mode_ptr = &change_cycle_mode;
			button3_mode_ptr = &change_cycle_mode;
			set_cycle_monday_mode();
			break;
		case SET_CYCLE_TUESDAY_MODE:
			button0_mode_ptr = &display_mode;
			button1_mode_ptr = &set_cycle_wednesday_mode;
			button2_mode_ptr = &change_cycle_mode;
			button3_mode_ptr = &change_cycle_mode;
			set_cycle_tuesday_mode();
			break;
		case SET_CYCLE_WEDNESDAY_MODE:
			button0_mode_ptr = &display_mode;
			button1_mode_ptr = &set_cycle_thurday_mode;
			button2_mode_ptr = &change_cycle_mode;
			button3_mode_ptr = &change_cycle_mode;
			set_cycle_wednesday_mode();
			break;
		case SET_CYCLE_THURDAY_MODE:
			button0_mode_ptr = &display_mode;
			button1_mode_ptr = &set_cycle_friday_mode;
			button2_mode_ptr = &change_cycle_mode;
			button3_mode_ptr = &change_cycle_mode;
			set_cycle_thurday_mode();
			break;
		case SET_CYCLE_FRIDAY_MODE:
			button0_mode_ptr = &display_mode;
			button1_mode_ptr = &set_cycle_saturday_mode;
			button2_mode_ptr = &change_cycle_mode;
			button3_mode_ptr = &change_cycle_mode;
			set_cycle_friday_mode();
			break;
		case SET_CYCLE_SATURDAY_MODE:
			button0_mode_ptr = &display_mode;
			button1_mode_ptr = &set_cycle_sunday_mode;
			button2_mode_ptr = &change_cycle_mode;
			button3_mode_ptr = &change_cycle_mode;
			set_cycle_saturday_mode();
			break;
		case SET_CYCLE_SUNDAY_MODE:
			button0_mode_ptr = &display_mode;
			button1_mode_ptr = &save_mode;
			button2_mode_ptr = &change_cycle_mode;
			button3_mode_ptr = &change_cycle_mode;
			set_cycle_sunday_mode();
			break;
		case SET_ALARM_MODE:
			set_alarm = 1;
			temp_time = alarm_time;
			button0_mode_ptr = &display_mode;
			button1_mode_ptr = &set_hour_mode;
			button2_mode_ptr = &display_mode;
			button3_mode_ptr = &display_mode;
			set_alarm_mode();
			break;
		case ALARM_MODE:
			button0_mode_ptr = &display_mode;
			button1_mode_ptr = &display_mode;
			button2_mode_ptr = &display_mode;
			button3_mode_ptr = &display_mode;
			alarm_mode();
			break;
		default:
			button0_mode_ptr = &set_dmy_mode;
			button1_mode_ptr = &set_hms_mode;
			button2_mode_ptr = &set_cycle_mode;
			button3_mode_ptr = &set_alarm_mode;
			display_mode();
			break;
	}
}
