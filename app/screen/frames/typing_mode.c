/*
 * typing_mode.c
 *
 *  Created on: 29 avr. 2026
 *      Author: obsercorma
 */

#include <string.h>

#include "tft_ili9341/stm32g4_ili9341.h"
#include "tft_ili9341/stm32g4_fonts.h"
#include "screen/screen.h"
#include "screen/frames/home.h"
#include "screen/frames/shutdown.h"
#include "screen/frames/typing_mode.h"
#include "bluetooth.h"
#include "stm32g4_sys.h"

static char current_message[200] = "";

static uint8_t st1 = 1;

/**
 * @brief Efface la zone de saisie
 */
void _typing_mode_blank_message(){
	ILI9341_DrawFilledRectangle(20, 40, 220, 160, ILI9341_COLOR_WHITE);
}

/**
 * @brief Efface le message courant stocké en mémoire
 */
void typing_mode_clear_current_message(){
	size_t len = strlen(current_message);
	for(size_t i = 0; i < len; i++){
		current_message[i] = '\0';
	}
}

/**
 * @brief Ajoute un caractère morse à la chaine
 */
void typing_mode_append_to_current_message(char c){
	size_t len = strlen(current_message);
	if(len < 100){ // Limite la taille du message à 100 caractères
		current_message[len] = c;
	}
	_typing_mode_blank_message(); // Efface la zone de saisie
	ILI9341_printf(X_START, Y_START+45, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "%s", current_message);
}

/**
 * @brief Retire le dernier caractère de la chaine
 */
void static _typing_mode_remove_last_character(){
	size_t len = strlen(current_message);
	if(len > 0){
		current_message[len-1] = '\0';
	}
	_typing_mode_blank_message(); // Efface la zone de saisie
	ILI9341_printf(X_START, Y_START+45, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "%s", current_message);
}

/**
 * @brief Gestion de l'ajout du point en Morse
 * @note Est exploité par le système de ScreenCallbacks
 * @see ScreenCallbacks_t screen.h
 */
void static _typing_mode_put_dot(){
	typing_mode_append_to_current_message('.');
}

/**
 * @brief Gestion de l'ajout du trait en Morse
 * @note Est exploité par le système de ScreenCallbacks
 * @see ScreenCallbacks_t screen.h
 */
void static _typing_mode_put_dash(){
	typing_mode_append_to_current_message('-');
}

/**
 * @brief Gestion de l'ajout d'un espace entre mots
 * @note Est exploité par le système de ScreenCallbacks
 * @see ScreenCallbacks_t screen.h
 */
void static _typing_mode_put_space(){
	typing_mode_append_to_current_message(' ');
}

/**
 * @brief Gestion de l'ajout d'une barre verticale (interprétation propriétaire des besoins de ce projet)
 * @note Est exploité par le système de ScreenCallbacks
 * @see ScreenCallbacks_t screen.h
 */
void static _typing_mode_put_new_word(){
	typing_mode_append_to_current_message('|');
}

void typing_mode_get_current_message(char* buffer, size_t size){
	if(current_message[0] != '\0' && size > 0){
		strncpy(buffer, current_message, size);
		buffer[size-1] = '\0';
	}else{
		buffer[0] = '\0';
	}
}

void typing_mode_show_sending_message_info(){
	bluetooth_send_data(current_message);
	ILI9341_printf(X_START+75, Y_START+160, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE, "[ ENVOI EN COURS ]");
}

void typing_mode_show_success_send(){
	ILI9341_DrawFilledRectangle(X_START+70, Y_START+160, X_START+160, Y_START+170, ILI9341_COLOR_WHITE);
	ILI9341_printf(X_START+80, Y_START+160, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_GREEN, "[ MESSAGE ENVOYE ]");
}

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
	ScreenCallbacks_t callbacks = {
		.button_u  = NULL,
		.button_m  = typing_mode_show_frame_empty_message,
		.button_r  = NULL,
		.button_l  = NULL,
		.button_long_d = home_show_home,
		.button_long_l = NULL,
		.button_long_m = NULL,
		.button_long_r = NULL,
		.button_long_u = NULL,
		.button_double_d = NULL,
		.button_double_l = NULL,
		.button_double_m = NULL,
		.button_double_r = NULL,
		.button_double_u = NULL
	};
	screen_should_clear(&st1);
	screen_clear();
	screen_set_callbacks(&callbacks);
	ILI9341_printf(X_START-5, Y_START, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "[ MODE SAISIE - INSTRUCTIONS 3 BOUTONS ]");

	ILI9341_printf(X_START, Y_START+30, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "L pour saisir \".\"\n\nR pour saisir \"-\"\n\nD pour effacer un caractere\n\nM pour passer au prochain caractere\n\nMx2 pour nouveau mot");

	ILI9341_DrawFilledRectangle(X_START+80, Y_START+150, X_START+200, Y_START+170, ILI9341_COLOR_YELLOW);
	ILI9341_printf(X_START+85, Y_START+155, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "M pour continuer");

	ILI9341_DrawFilledRectangle(X_START+70, Y_START+180, X_START+210, Y_START+200, ILI9341_COLOR_YELLOW);
	ILI9341_printf(X_START+75, Y_START+185, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "D long pour quitter");
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
	ScreenCallbacks_t callbacks = {
		.button_u  = NULL,
		.button_d  = _typing_mode_remove_last_character,
		.button_m  = _typing_mode_put_space,
		.button_r  = _typing_mode_put_dash,
		.button_l  = _typing_mode_put_dot,
		.button_long_d = typing_mode_show_btns_instructions,
		.button_long_u = shutdown_show_alert,
		.button_double_m = _typing_mode_put_new_word,
		.button_double_u = typing_mode_show_sending_message_info
	};

	screen_should_clear(0);
	typing_mode_clear_current_message();
	screen_set_callbacks(&callbacks);
	shutdown_should_go_back_to_home(typing_mode_show_btns_instructions);

	ILI9341_printf(X_START+80, Y_START, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "[ MODE SAISIE ]");

	if(current_message[0] != '\0')
		ILI9341_printf(X_START+30, Y_START+45, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "%s", current_message);

	ILI9341_printf(X_START+70, Y_START+180, &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_YELLOW, "[U 2x] pour envoyer");
	ILI9341_printf(X_START, Y_START+195, &Font_7x10, ILI9341_COLOR_WHITE, ILI9341_COLOR_RED, "[U long] mode veille [D long] pour quitter");
}
