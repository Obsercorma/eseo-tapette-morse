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

void show_home_mode(void);
void show_receiving_mode(uint8_t is_active);
void show_instructions_receiving_mode(void);

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
			show_home_mode();
			break;
		case SCREEN_RECEIVING_MODE:
			//show_receiving_mode(1);
			show_instructions_receiving_mode();
		default:
			break;
	}
}

ScreenMode screen_get_mode(){
	return selectedMode;
}

void show_home_mode(){
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

void show_receiving_mode(uint8_t is_active){
	ILI9341_DrawFilledRectangle(X_START, Y_START, X_END, 60, ILI9341_COLOR_BLUE); // @suppress("Symbol is not resolved")
	ILI9341_printf(X_START+15, Y_START+15, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, is_active ? "Activer" : "Desactiver");
	ILI9341_printf(X_END-75, Y_START+15, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "[Bouton M]");

	ILI9341_DrawFilledRectangle(X_START, Y_START+50, X_END, 110, ILI9341_COLOR_BLUE);
	ILI9341_printf(X_START+15, Y_START+65, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "Afficher message");
	ILI9341_printf(X_END-75, Y_START+65, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "[Bouton U]");
}


void show_instructions_receiving_mode(){
	// Draw the Typing option mode
	ILI9341_printf(X_START+40, Y_START, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "[ MODE SAISIE - INSTRUCTIONS ]");

	ILI9341_printf(X_START, Y_START+30, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "Supprimer carractere :");
	ILI9341_printf(X_END-70, Y_START+30, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "[Bouton D]");

	ILI9341_printf(X_START, Y_START+60, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "Envoi simple :");
	ILI9341_printf(X_END-90, Y_START+60, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "[Bouton U x2]");

	ILI9341_printf(X_START, Y_START+90, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "Envoi repete :");
	ILI9341_printf(X_END-105, Y_START+90, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "[Bouton U long]");

	ILI9341_printf(X_START, Y_START+120, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "Changer de mode :");
	ILI9341_printf(X_END-105, Y_START+120, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "[Bouton L long]");

	ILI9341_DrawFilledRectangle(X_START+80, Y_START+160, X_START+200, Y_START+180, ILI9341_COLOR_YELLOW);
	ILI9341_printf(X_START+85, Y_START+165, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "M pour continuer");
}










