/*
 * screen.h
 *
 *  Created on: 27 avr. 2026
 *      Author: thomasstrong
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include "stm32g4_sys.h"

// Positions de départs sur l'écran
#define X_START 20
#define Y_START 20
#define X_END 300

// Délai avant mise en veille
#define SECONDS_BEFORE_SHUTDOWN 30U

/**
 * @brief Définition d'un type de Callback atrendu et à executer au moment d'une intéraction utilisateur
 */
typedef void (*ButtonCallback)(void);

/**
 * @brief Structure permettant d'enregistrer les adresses de fonctions à appeler (Callbacks) par rapport à la frame (et de ses options) affichés à l'écran.
 * @note Cette structure dispose de propriétés pour gérer les trois types d'événements (appui court, long et double)
 */
typedef struct ScreenCallbacks_t {
	ButtonCallback button_u;
	ButtonCallback button_m;
	ButtonCallback button_r;
	ButtonCallback button_l;
	ButtonCallback button_d;
	ButtonCallback button_long_d;
	ButtonCallback button_long_u;
	ButtonCallback button_long_m;
	ButtonCallback button_long_r;
	ButtonCallback button_long_l;
	ButtonCallback button_double_u;
	ButtonCallback button_double_m;
	ButtonCallback button_double_r;
	ButtonCallback button_double_l;
	ButtonCallback button_double_d;
} ScreenCallbacks_t;

/**
 * @brief Initialisation de l'écran ILI9341
 * @note La touch screen et l'extension SD est exclue.
 */
void screen_init(void);

/**
 * @brief Efface tout le contenu de l'écran
 */
void screen_clear(void);

/**
 * @brief Définit si l'écran doit être effacé avant d'afficher une nouvelle frame
 * @param should_clear 1 pour effacer l'écran, 0 pour ne pas l'effacer
 */
void screen_should_clear(uint8_t* should_clear);

/**
 * @brief Récupère l'état actuel de la configuration d'effacement de l'écran
 * @param should_clear Un pointeur vers une variable où stocker l'état actuel (1 pour effacer, 0 pour ne pas effacer)
 */
void screen_get_should_clear(uint8_t* should_clear);

/**
 * @brief Définit les callbacks à appeler lors de l'appui sur les boutons
 * @param callbacks Un pointeur vers une structure contenant les callbacks à définir
 */
void screen_set_callbacks(ScreenCallbacks_t* callbacks);

/**
 * @brief Récupère les callbacks actuellement définis
 * @param callbacks Un pointeur vers une structure où stocker les callbacks actuels
 */
void screen_get_callbacks(ScreenCallbacks_t* callbacks);

#endif /* SCREEN_H_ */
