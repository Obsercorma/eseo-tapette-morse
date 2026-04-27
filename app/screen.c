/*
 * screen.c
 *
 *  Created on: 27 avr. 2026
 *      Author: obsercorma
 */


#include "screen.h"
#include "tft_ili9341/stm32g4_ili9341.h"
#include "tft_ili9341/stm32g4_fonts.h"

#define X_START 20
#define Y_START 20
#define X_END 300

ScreenMode selectedMode;

void show_home_mode();

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
	// TODO: call methods according to the selected mode
	switch(mode){
		case SCREEN_HOME_MODE:
			show_home_mode();
			break;
		default:
			break;
	}
}

ScreenMode screen_get_mode(){
	return selectedMode;
}

void show_home_mode(){
	// Draw the Typing option mode
	ILI9341_DrawFilledRectangle(X_START, Y_START, X_END, 60, ILI9341_COLOR_BLUE); // @suppress("Symbol is not resolved")
	ILI9341_printf(X_START+15, Y_START+15, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "Mode Saisi");
	ILI9341_printf(X_END-75, Y_START+15, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "[Bouton U]");

	// Draw the Receiving mode
	ILI9341_DrawFilledRectangle(X_START, Y_START+50, X_END, 110, ILI9341_COLOR_BLUE);
	ILI9341_printf(X_START+15, Y_START+65, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "Mode Reception");
	ILI9341_printf(X_END-75, Y_START+65, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "[Bouton M]");

	// Draw the Learning mode
	ILI9341_DrawFilledRectangle(X_START, Y_START+100, X_END, 160, ILI9341_COLOR_BLUE);
	ILI9341_printf(X_START+15, Y_START+115, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "Mode Veille");
	ILI9341_printf(X_END-95, Y_START+115, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "[Bouton R x2]");

	// Draw the Learning mode
	ILI9341_DrawFilledRectangle(X_START, Y_START+150, X_END, 210, ILI9341_COLOR_BLUE);
	ILI9341_printf(X_START+15, Y_START+165, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "Mode Apprentissage");
	ILI9341_printf(X_END-75, Y_START+165, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "[Bouton L]");
}















