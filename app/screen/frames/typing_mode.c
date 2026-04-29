/*
 * typing_mode.c
 *
 *  Created on: 29 avr. 2026
 *      Author: obsercorma
 */


#include "tft_ili9341/stm32g4_ili9341.h"
#include "tft_ili9341/stm32g4_fonts.h"
#include "screen/screen.h"
#include "screen/frames/typing_mode.h"

void typing_mode_show_instructions(){
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

void typing_mode_show_instructions_calibration(){
	ILI9341_printf(X_START-5, Y_START, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "[ MODE SAISIE - INSTRUCTIONS CALIBRATION ]");

	ILI9341_printf(X_START, Y_START+30, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "Nous allons vous demander de saisir des\nsequences pour calibrer la tapette");

	ILI9341_printf(X_START, Y_START+60, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "Utilisez M pour saisir \".\" et \"-\"\nR pour espace");

	ILI9341_printf(X_START, Y_START+90, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "L long pour passer au mode saisie \na 3 boutons");


	ILI9341_DrawFilledRectangle(X_START+80, Y_START+120, X_START+200, Y_START+140, ILI9341_COLOR_YELLOW);
	ILI9341_printf(X_START+85, Y_START+125, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "M pour continuer");
}

void typing_mode_show_btns_instructions(){
	ILI9341_printf(X_START-5, Y_START, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "[ MODE SAISIE - INSTRUCTIONS 3 BOUTONS ]");

	ILI9341_printf(X_START, Y_START+30, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "L pour saisir \".\"\n\nR pour saisir \"-\"\n\nM pour passer au prochain caractere\n\nMx2 pour espace");

	ILI9341_DrawFilledRectangle(X_START+80, Y_START+120, X_START+200, Y_START+140, ILI9341_COLOR_YELLOW);
	ILI9341_printf(X_START+85, Y_START+125, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "M pour continuer");
}

void typing_mode_show_sent_message_info(){
	ILI9341_printf(X_START+60, Y_START, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "[ MODE SAISIE - INFO ]");

	ILI9341_printf(X_START+30, Y_START+95, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "VOTRE MESSAGE A BIEN\n    ETE ENVOYE");

	ILI9341_printf(X_START+20, Y_START+155, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "Retour a la saisie dans 5 secondes");
}

void typing_mode_show_repeating_message_info(){
	ILI9341_printf(X_START+60, Y_START, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "[ MODE SAISIE - INFO ]");

	ILI9341_printf(X_START, Y_START+45, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "L'ecran va s'eteindre, la\nLED vous signalera quand\nvous recevrez une reponse");

	ILI9341_printf(X_START+5, Y_START+155, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "D long pour quitter et rallumer l'ecran");
}

void typing_mode_show_frame_empty_message(){
	ILI9341_printf(X_START+80, Y_START, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "[ MODE SAISIE ]");

	ILI9341_printf(X_START+70, Y_START+180, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "D long pour quitter");
}
