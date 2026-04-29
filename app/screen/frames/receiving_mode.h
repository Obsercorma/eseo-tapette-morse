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
void receiving_mode_show_home(uint8_t is_active);

/**
 * @brief Afficher une Frame indiquant à l'utilisateur si l'on autorise la réception des messages.
 */
void receiving_mode_show_question_message(void);

#endif /* SCREEN_SCREEN_RECEIVING_MODE_H_ */
