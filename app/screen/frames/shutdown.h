/*
 * shutdown_frames.h
 *
 *  Created on: 29 avr. 2026
 *      Author: obsercorma
 */

#ifndef SCREEN_SHUTDOWN_FRAMES_H_
#define SCREEN_SHUTDOWN_FRAMES_H_

#include "screen/screen.h"

/**
 * @brief Affiche une Frame d'alerte  de mise en veille automatique
 * @note Cette frame indique à l'utilisateur que le dispositif va se mettre en veille après un certain délai.
 */
void shutdown_show_auto_alert(void);

/**
 * @brief Renseigne l'adresse de la fonction de callback à appeler pour afficher sur l'écran
 * @param should_to_go_back Pointeur vers la fonction de callback
 */
void shutdown_should_go_back_to_home(ButtonCallback  should_to_go_back);

/**
 * @brief Affiche une Frame demandant à l'utilisateur si oui ou non le dispositif doit être en veille.
 */
void shutdown_show_alert(void);

#endif /* SCREEN_SHUTDOWN_FRAMES_H_ */
