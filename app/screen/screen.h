/*
 * screen.h
 *
 *  Created on: 27 avr. 2026
 *      Author: thomasstrong
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#define X_START 20
#define Y_START 20
#define X_END 300

#define SECONDS_BEFORE_SHUTDOWN 30U

typedef enum {
	SCREEN_LEARNING_MODE = 0,
	SCREEN_HOME_MODE,
	SCREEN_STANDBY_MODE,
	SCREEN_TYPING_MODE,
	SCREEN_RECEIVING_MODE
} ScreenMode;

typedef void (*ButtonCallback)(void);


typedef struct ScreenCallbacks_t {
	ButtonCallback button_u;
	ButtonCallback button_m;
	ButtonCallback button_r;
	ButtonCallback button_l;
	ButtonCallback button_d;
} ScreenCallbacks_t;

/**
 * @brief Initialisation de l'écran ILI9341
 * @note La touch screen et l'extension SD est exclue.
 */
void screen_init(void);

void screen_show_mode(ScreenMode mode);

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

ScreenMode screen_get_mode(void);

/**
 * @brief Efface tout le contenu de l'écran
 */
void screen_clear(void);

#endif /* SCREEN_H_ */
