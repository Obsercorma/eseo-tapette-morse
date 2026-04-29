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

ScreenMode selectedMode;


void screen_init(){
	ILI9341_Init();
	ILI9341_Rotate(ILI9341_Orientation_Landscape_2);
	ILI9341_DisplayOff();
	ILI9341_DisplayOn();
	ILI9341_Fill(ILI9341_COLOR_WHITE);
	selectedMode = SCREEN_HOME_MODE;
}

void screen_show_mode(ScreenMode mode){
	selectedMode = mode;
	ILI9341_Fill(ILI9341_COLOR_WHITE); // Clear the screen
	// TODO: call methods according to the selected mode
	switch(mode){
		case SCREEN_HOME_MODE:
			home_show_home();
			break;
		case SCREEN_RECEIVING_MODE:
			typing_mode_show_frame_empty_message();
			break;
		default:
			break;
	}
}

ScreenMode screen_get_mode(){
	return selectedMode;
}
