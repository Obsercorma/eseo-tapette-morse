/*
 * shutdown_frames.c
 *
 *  Created on: 29 avr. 2026
 *      Author: thomasstrong
 */

#include "screen/screen.h"
#include "screen/frames/shutdown.h"
#include "tft_ili9341/stm32g4_ili9341.h"
#include "tft_ili9341/stm32g4_fonts.h"

void shutdown_show_auto_alert(){
	ILI9341_printf(X_START+40, Y_START, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_RED, "[ MODE VEILLE AUTO ]");

	ILI9341_printf(X_START, Y_START+50, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "La tapette va etre mise en  veille dans %u secondes", SECONDS_BEFORE_SHUTDOWN);

	ILI9341_DrawFilledRectangle(X_START+15, Y_START+115, X_START+280, Y_START+145, ILI9341_COLOR_RED);
	ILI9341_printf(X_START+20, Y_START+120, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_RED, "L'ecran va s'eteindre !");

	ILI9341_printf(X_START+20, Y_START+180, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "Appuyez sur une touche pour annuler");
}

void shutdown_show_alert(){
	ILI9341_printf(X_START+70, Y_START, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_RED, "[ MODE VEILLE ]");

	ILI9341_printf(X_START+20, Y_START+50, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "Souhaitez-vous vraiment\n   mettre en veille ?");

	ILI9341_printf(X_START+30, Y_START+130, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "OUI [L]");
	ILI9341_printf(X_START+180, Y_START+130, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "NON [R]");
}
