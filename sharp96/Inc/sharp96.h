#ifndef __SHARP96_H__
#define __SHARP96_H__

#include "font8x8.h"
#include <stdio.h>
#include <string.h>
#include "stm32f1xx.h"
#include "gpio.h"
#include "spi.h"

/*Define GPIO pins are used for SHARP96 LCD*/
#define LCD_EN		GPIO_A, 1
#define	LCD_CS		GPIO_A, 2
#define	LCD_CLK		SPI1_SCK
#define	LCD_SIMO	SPI1_MOSI

/*Define SHARP96 LCD Parameters*/
#define LCD_VERTICAL_MAX		96
#define LCD_HORIZONTAL_MAX		96
#define LCD_BYTES_LINE			LCD_HORIZONTAL_MAX / 8
#define LCD_BUF_SIZE			LCD_VERTICAL_MAX * LCD_BYTES_LINE

/*Define SHARP96 LCD command*/
#define LCD_CM_WR			0x80		//Write line command
#define LCD_CM_CL			0x20		//Clear memory command
#define LCD_TRAILER_BYTE	0X00		//Trailer bit
#define LCD_VCOM			0x40		//VCom bit
#define LCD_CM_DISPLAY			0X00		//Display command

void LCD_init(void);
void LCD_enable(void);
void LCD_disable(void);
void LCD_transmit_begin(void);
void LCD_transmit_cmplt(void);
void LCD_display(void);
void LCD_clear_screen(void);
void LCD_clear_data(uint8_t data[]);
void LCD_send_toggle_VCOM(void);
void LCD_send_1line(uint8_t line);
void LCD_send_image(uint8_t data[LCD_BUF_SIZE]);
void LCD_get_char8x8(uint8_t x, uint8_t y, uint8_t data[LCD_BUF_SIZE], int ch);
//void LCD_get_char8x16(uint8_t x, uint8_t y, uint8_t data[LCD_BUF_SIZE], int ch);
void LCD_get_string(uint8_t x_start, uint8_t y_start, uint8_t data[LCD_BUF_SIZE], char str[]);

#endif
