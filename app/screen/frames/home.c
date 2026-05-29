/*
 * screen_home.c
 *
 *  Created on: 29 avr. 2026
 *      Author: obsercorma
 */

#include "screen/screen.h"
#include "screen/frames/home.h"
#include "screen/frames/shutdown.h"
#include "screen/frames/typing_mode.h"
#include "screen/frames/receiving_mode.h"
#include "tft_ili9341/stm32g4_ili9341.h"
#include "tft_ili9341/stm32g4_fonts.h"

void home_show_home(){
	ScreenCallbacks_t callbacks = {
		.button_u  = typing_mode_show_btns_instructions,
		.button_m  = receiving_mode_show_home,
		.button_r  = NULL,
		.button_l  = NULL,
		.button_long_d = NULL,
		.button_long_u = NULL,
		.button_long_m = NULL,
		.button_long_r = NULL,
		.button_double_r = shutdown_show_alert,
		.button_double_u = NULL,
		.button_double_m = NULL,
		.button_double_l = NULL,
	};
	shutdown_should_go_back_to_home(home_show_home);
	screen_set_callbacks(&callbacks);

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
