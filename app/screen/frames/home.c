/*
 * screen_home.c
 *
 *  Created on: 29 avr. 2026
 *      Author: obsercorma
 */

#include "screen/screen.h"
#include "screen/frames/home.h"
#include "tft_ili9341/stm32g4_ili9341.h"
#include "tft_ili9341/stm32g4_fonts.h"

void home_show_home(){
	ILI9341_DrawFilledRectangle(X_START, Y_START, X_END, 60, ILI9341_COLOR_BLUE); // @suppress("Symbol is not resolved")
	ILI9341_printf(X_START+15, Y_START+15, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "Mode Saisi");
	ILI9341_printf(X_END-75, Y_START+15, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "[Bouton U]");

	ILI9341_DrawFilledRectangle(X_START, Y_START+50, X_END, 110, ILI9341_COLOR_BLUE);
	ILI9341_printf(X_START+15, Y_START+65, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "Mode Reception");
	ILI9341_printf(X_END-75, Y_START+65, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "[Bouton M]");

	ILI9341_DrawFilledRectangle(X_START, Y_START+100, X_END, 160, ILI9341_COLOR_BLUE);
	ILI9341_printf(X_START+15, Y_START+115, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "Mode Veille");
	ILI9341_printf(X_END-95, Y_START+115, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "[Bouton R x2]");

	ILI9341_DrawFilledRectangle(X_START, Y_START+150, X_END, 210, ILI9341_COLOR_BLUE);
	ILI9341_printf(X_START+15, Y_START+165, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "Mode Apprentissage");
	ILI9341_printf(X_END-75, Y_START+165, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "[Bouton L]");
}
