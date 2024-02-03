/*
 * mode.c
 *
 *  Created on: Feb 3, 2024
 *      Author: Vy
 */
#include "mode.h"

void display_mode(void){
	  Paint_SelectImage(RedImage);
	  Paint_Clear(WHITE);
	  Paint_DrawString_EN(0, 10, "PIFLab", &Font32, WHITE, RED);
	  Paint_SelectImage(BlackImage);
	  Paint_Clear(WHITE);
	  Paint_DrawTime(30, 50, &current_time, &Font48, WHITE, BLACK);
	  Paint_DrawDate(30, 110, &current_date, &Font24, WHITE, BLACK);
	  EPD_1IN54B_Display(BlackImage, RedImage);
}


