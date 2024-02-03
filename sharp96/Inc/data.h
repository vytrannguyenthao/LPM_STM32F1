/*
 * data.h
 *
 *  Created on: Jan 11, 2024
 *      Author: Vy
 */

#ifndef DATA_H_
#define DATA_H_

#include <stdlib.h>
#include <stdio.h>
#include "sharp96.h"
#include "stm32f1xx.h"

extern uint8_t display_data[LCD_BUF_SIZE];
extern uint8_t set_dmy_data[LCD_BUF_SIZE];
extern uint8_t set_hms_data[LCD_BUF_SIZE];

#endif /* DATA_H_ */
