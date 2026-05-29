/*
 * screen.c
 *
 *  Created on: 27 avr. 2026
 *      Author: obsercorma
 */


#include "screen/screen.h"
#include "screen/frames/home.h"
#include "screen/frames/shutdown.h"
#include "screen/frames/typing_mode.h"
#include "screen/frames/receiving_mode.h"
#include "tft_ili9341/stm32g4_ili9341.h"
#include "tft_ili9341/stm32g4_fonts.h"


static ScreenCallbacks_t options_callbacks;

static uint8_t should_clear_screen = 1;

void screen_init(){
	ILI9341_Init();
	ILI9341_Rotate(ILI9341_Orientation_Landscape_2);
	ILI9341_DisplayOff();
	ILI9341_DisplayOn();
	ILI9341_Fill(ILI9341_COLOR_WHITE);
	options_callbacks.button_u = NULL;
	options_callbacks.button_m = NULL;
	options_callbacks.button_r = NULL;
	options_callbacks.button_l = NULL;
	options_callbacks.button_d = NULL;
	options_callbacks.button_long_d = NULL;
	options_callbacks.button_long_u = NULL;
	options_callbacks.button_long_m = NULL;
	options_callbacks.button_long_r = NULL;
	options_callbacks.button_double_u = NULL;
	options_callbacks.button_double_l = NULL;
	options_callbacks.button_double_m = NULL;
	options_callbacks.button_double_r = NULL;
	options_callbacks.button_double_d = NULL;
}

void screen_clear(){
	ILI9341_Fill(ILI9341_COLOR_WHITE);
}

void screen_should_clear(uint8_t* should_clear){
	should_clear_screen = *should_clear;
}

void screen_get_should_clear(uint8_t* should_clear){
	*should_clear = should_clear_screen;
}

void screen_set_callbacks(ScreenCallbacks_t* callbacks){
	if(callbacks != NULL){
		options_callbacks.button_u = callbacks->button_u;
		options_callbacks.button_m = callbacks->button_m;
		options_callbacks.button_r = callbacks->button_r;
		options_callbacks.button_l = callbacks->button_l;
		options_callbacks.button_d = callbacks->button_d;
		options_callbacks.button_long_d = callbacks->button_long_d;
		options_callbacks.button_long_u = callbacks->button_long_u;
		options_callbacks.button_long_m = callbacks->button_long_m;
		options_callbacks.button_long_r = callbacks->button_long_r;
		options_callbacks.button_double_u = callbacks->button_double_u;
		options_callbacks.button_double_l = callbacks->button_double_l;
		options_callbacks.button_double_m = callbacks->button_double_m;
		options_callbacks.button_double_r = callbacks->button_double_r;
		options_callbacks.button_double_d = callbacks->button_double_d;
	}
}

void screen_get_callbacks(ScreenCallbacks_t* callbacks){
	if(callbacks != NULL){
		callbacks->button_u = options_callbacks.button_u;
		callbacks->button_m = options_callbacks.button_m;
		callbacks->button_r = options_callbacks.button_r;
		callbacks->button_l = options_callbacks.button_l;
		callbacks->button_d = options_callbacks.button_d;
		callbacks->button_long_d = options_callbacks.button_long_d;
		callbacks->button_long_u = options_callbacks.button_long_u;
		callbacks->button_long_m = options_callbacks.button_long_m;
		callbacks->button_long_r = options_callbacks.button_long_r;
		callbacks->button_double_u = options_callbacks.button_double_u;
		callbacks->button_double_l = options_callbacks.button_double_l;
		callbacks->button_double_m = options_callbacks.button_double_m;
		callbacks->button_double_r = options_callbacks.button_double_r;
		callbacks->button_double_d = options_callbacks.button_double_d;
	}
}
