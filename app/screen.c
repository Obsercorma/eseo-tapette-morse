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

#define SECONDS_BEFORE_SHUTDOWN 30U

ScreenMode selectedMode;

void show_home_mode(void);
void show_receiving_mode(uint8_t is_active);
void show_instructions_receiving_mode(void);
void show_calibration_instructions_receiving_mode(void);
void show_switching_three_btns_instructions();
void show_auto_shutdown_alert();
void show_shutdown_alert();


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
			show_shutdown_alert();
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

void show_calibration_instructions_receiving_mode(){
	ILI9341_printf(X_START-5, Y_START, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "[ MODE SAISIE - INSTRUCTIONS CALIBRATION ]");

	ILI9341_printf(X_START, Y_START+30, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "Nous allons vous demander de saisir des\nsequences pour calibrer la tapette");

	ILI9341_printf(X_START, Y_START+60, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "Utilisez M pour saisir \".\" et \"-\"\nR pour espace");

	ILI9341_printf(X_START, Y_START+90, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "L long pour passer au mode saisie \na 3 boutons");


	ILI9341_DrawFilledRectangle(X_START+80, Y_START+120, X_START+200, Y_START+140, ILI9341_COLOR_YELLOW);
	ILI9341_printf(X_START+85, Y_START+125, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "M pour continuer");
}

void show_switching_three_btns_instructions(){
	ILI9341_printf(X_START-5, Y_START, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "[ MODE SAISIE - INSTRUCTIONS 3 BOUTONS ]");

	ILI9341_printf(X_START, Y_START+30, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "L pour saisir \".\"\n\nR pour saisir \"-\"\n\nM pour passer au prochain caractere\n\nMx2 pour espace");

	ILI9341_DrawFilledRectangle(X_START+80, Y_START+120, X_START+200, Y_START+140, ILI9341_COLOR_YELLOW);
	ILI9341_printf(X_START+85, Y_START+125, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "M pour continuer");
}


void show_auto_shutdown_alert(){
	ILI9341_printf(X_START+40, Y_START, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_RED, "[ MODE VEILLE AUTO ]");

	ILI9341_printf(X_START, Y_START+50, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "La tapette va etre mise en  veille dans %u secondes", SECONDS_BEFORE_SHUTDOWN);

	ILI9341_DrawFilledRectangle(X_START+15, Y_START+115, X_START+280, Y_START+145, ILI9341_COLOR_RED);
	ILI9341_printf(X_START+20, Y_START+120, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_RED, "L'ecran va s'eteindre !");

	ILI9341_printf(X_START+20, Y_START+180, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "Appuyez sur une touche pour annuler");
}

void show_shutdown_alert(){
	ILI9341_printf(X_START+70, Y_START, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_RED, "[ MODE VEILLE ]");

	ILI9341_printf(X_START+20, Y_START+50, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "Souhaitez-vous vraiment\n   mettre en veille ?");

	ILI9341_printf(X_START+30, Y_START+130, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "OUI [L]");
	ILI9341_printf(X_START+180, Y_START+130, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "NON [R]");
}




