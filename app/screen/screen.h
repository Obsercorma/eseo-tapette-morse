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

/**
 * @brief Initialisation de l'écran ILI9341
 * @note La touch screen et l'extension SD est exclue.
 */
void screen_init(void);

void screen_show_mode(ScreenMode mode);

ScreenMode screen_get_mode(void);

#endif /* SCREEN_H_ */
