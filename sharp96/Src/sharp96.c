#include "sharp96.h"

static uint8_t VCom;

static uint8_t Toggle_VCOM(void){
	VCom ^= LCD_VCOM;
	return VCom;
}

static void LCD_send_byte(uint8_t data){
	SPI1_transmit_data(&data, 1);
}

static void LCD_send_cmd(uint8_t cmd){
	cmd |= Toggle_VCOM();
	SPI1_transmit_data(&cmd, 1);
}

static uint8_t Reverse_data(uint8_t data){
	data = ((data & 0x80) >> 7) | ((data & 0x40) >> 5) | ((data & 0x20) >> 3) | ((data & 0x10) >> 1)
			| ((data & 0x01) << 7) | ((data & 0x02) << 5) | ((data & 0x04) << 3) | ((data & 0x08) << 1);
	return data;
}
void LCD_send_toggle_VCOM(void){
	LCD_transmit_begin();
	LCD_send_cmd(LCD_CM_DISPLAY);
	LCD_send_byte(LCD_TRAILER_BYTE);
	LCD_transmit_cmplt();
}

void LCD_display(void){
	LCD_send_toggle_VCOM();
}

void LCD_init(void){
	/*Configure LCD_EN and LCD_CS pins to output mode*/
	GPIO_Pin_Configure(LCD_EN, OUTPUT_10MHZ, OUTPUT_GP_PP);
	GPIO_Pin_Configure(LCD_CS, OUTPUT_10MHZ, OUTPUT_GP_PP);
	GPIO_set_out_pin(LCD_CS, LOW);

	/*Enable LCD*/
	LCD_enable();

	/*Clear screen*/
	LCD_clear_screen();
}

void LCD_enable(void){
	/*Enable LCD by setting LCD_EN pin to HIGH*/
	GPIO_set_out_pin(LCD_EN, HIGH);
}

void LCD_disable(void){
	/*Disable LCD by setting LCD_EN pin to LOW*/
	GPIO_set_out_pin(LCD_EN, LOW);
}

void LCD_transmit_begin(void){
	GPIO_set_out_pin(LCD_CS, HIGH);
}

void LCD_transmit_cmplt(void){
	GPIO_set_out_pin(LCD_CS, LOW);
}

void LCD_clear_screen(void){
	LCD_transmit_begin();

	LCD_send_cmd(LCD_CM_CL);
	LCD_send_byte(LCD_TRAILER_BYTE);

	LCD_transmit_cmplt();
}

void LCD_clear_data(uint8_t data[]){
	for (int i = 0; i < LCD_BUF_SIZE; i++){
		data[i] = 0xff;
	}
}
void LCD_send_image(uint8_t data[LCD_BUF_SIZE]){
	LCD_transmit_begin();

	/*Send 1 byte for write command*/
	LCD_send_cmd(LCD_CM_WR);


	for(uint8_t line = 0; line < LCD_VERTICAL_MAX; line++){
		/*Send 1 byte for the line number*/
		LCD_send_byte(Reverse_data(line + 1));

		/*Send LCD_BYTES_LINE bytes data for 1 line*/
		for(int i = 0; i < LCD_BYTES_LINE; i++){
			LCD_send_byte(data[line * LCD_BYTES_LINE + i]);
		}

		/*Send 1 trailer byte to finish 1 line*/
		LCD_send_byte(LCD_TRAILER_BYTE);
	}
	/*Send another trailer byte to complete the process*/
	LCD_send_byte(LCD_TRAILER_BYTE);

	LCD_transmit_cmplt();
}

void LCD_send_1line(uint8_t line){
	LCD_transmit_begin();

	LCD_send_cmd(LCD_CM_WR);

	LCD_send_byte(Reverse_data(line));

	for(int i = 0; i < LCD_BYTES_LINE; i++){
		LCD_send_byte(0x00);
	}

	LCD_send_byte(LCD_TRAILER_BYTE);
	LCD_send_byte(LCD_TRAILER_BYTE);

	LCD_transmit_cmplt();
}
void LCD_get_char8x8(uint8_t x, uint8_t y, uint8_t data[LCD_BUF_SIZE], int ch){
	uint16_t lcd_pos, font_pos;
	for (int i = y; i < (y + 8); i++){
		lcd_pos = (y - 1) * LCD_BYTES_LINE * FONT_SIZE_8x8 + (i - y) * LCD_BYTES_LINE + (x - 1);
		font_pos = (ch - FONT_ASCII_OFFSET) * FONT_SIZE_8x8 + (i - y);
		data[lcd_pos] &= ~font8x8[font_pos];
	}
}
void LCD_get_string(uint8_t x_start, uint8_t y_start, uint8_t data[LCD_BUF_SIZE], char str[]){
	uint8_t x, y, n = 0;
	char ch;
	for(int i = 0; i < strlen(str); i++){
		strncpy(&ch, str + i, 1);
		x = x_start + i - LCD_BYTES_LINE * n;
		y = y_start + n;
		if (x >= (LCD_BYTES_LINE)){
			n++;
		}
		LCD_get_char8x8(x, y, data, ch);
	}
}
//void LCD_get_char8x16(uint8_t x, uint8_t y, uint8_t data[LCD_BUF_SIZE], int ch){
//	uint16_t lcd_pos, font_pos;
//	for (int i = y; i < (y + 16); i++){
//		lcd_pos = (y - 1) * LCD_BYTES_LINE * 8 + (i - y) * LCD_BYTES_LINE + (x - 1);
//		font_pos = (ch - FONT_ASCII_OFFSET) * 16 + (i - y);
//		data[lcd_pos] &= ~font8x16[font_pos];
//	}
//}
