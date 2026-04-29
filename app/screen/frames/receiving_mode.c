/*
 * receiving_mode_frames.c
 *
 *  Created on: 29 avr. 2026
 *      Author: thomasstrong
 */

#include "tft_ili9341/stm32g4_ili9341.h"
#include "tft_ili9341/stm32g4_fonts.h"
#include "screen/screen.h"
#include "screen/frames/receiving_mode.h"


void receiving_mode_show_home(uint8_t is_active){
	ILI9341_DrawFilledRectangle(X_START, Y_START, X_END, 60, ILI9341_COLOR_BLUE); // @suppress("Symbol is not resolved")
	ILI9341_printf(X_START+15, Y_START+15, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, is_active ? "Activer" : "Desactiver");
	ILI9341_printf(X_END-75, Y_START+15, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "[Bouton M]");

	ILI9341_DrawFilledRectangle(X_START, Y_START+50, X_END, 110, ILI9341_COLOR_BLUE);
	ILI9341_printf(X_START+15, Y_START+65, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "Afficher message");
	ILI9341_printf(X_END-75, Y_START+65, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "[Bouton U]");
}

void receiving_mode_show_question_message(){
	ILI9341_printf(X_START+20, Y_START, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "[ MODE RECEPTION - MESSAGE ENTRANT ]");

	ILI9341_printf(X_START-5, Y_START+65, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "Souihaitez vous afficher le\nmessage recu ?");

	ILI9341_printf(X_START+30, Y_START+130, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "OUI [L]");
	ILI9341_printf(X_START+180, Y_START+130, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "NON [R]");

	ILI9341_printf(X_START+30, Y_START+170, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_RED, "Attention, vous ne pourrez le\n consulter qu'une seule fois ");
}
