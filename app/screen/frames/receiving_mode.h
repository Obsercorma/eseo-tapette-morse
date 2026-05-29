/*
 * screen_receiving_mode.h
 *
 *  Created on: 29 avr. 2026
 *      Author: thomasstrong
 */

#ifndef SCREEN_SCREEN_RECEIVING_MODE_H_
#define SCREEN_SCREEN_RECEIVING_MODE_H_

#include "stm32g4_utils.h"

/**
 * @brief Afficher la Frame principale
 * @param is_active: Indique si la réception est active ou non
 */
void receiving_mode_show_home(void);

/**
 * @brief Afficher une Frame indiquant à l'utilisateur si l'on autorise la réception des messages.
 */
void receiving_mode_show_question_message(void);

/**
 * @brief Affiche des composants textuels sur l'écran afin d'indiquer que le dispositif est en mode réception continue
 */
void receiving_mode_show_received_message(void);

/**
 * @brief Définit le message reçue à afficher à l'écran
 * @param msg: Message à afficher
 */
void receiving_mode_set_message(char* msg);

#endif /* SCREEN_SCREEN_RECEIVING_MODE_H_ */
