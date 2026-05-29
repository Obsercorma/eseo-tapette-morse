/*
 * typing_mode.h
 *
 *  Created on: 29 avr. 2026
 *      Author: thomasstrong
 */

#ifndef SCREEN_FRAMES_TYPING_MODE_H_
#define SCREEN_FRAMES_TYPING_MODE_H_

#include "stm32g4_sys.h"

/**
 * @brief Récupère le message en cours de saisie
 * @param buffer Buffer dans lequel le message sera copié
 * @param size Taille du buffer
 */
void typing_mode_get_current_message(char* buffer, size_t size);

/**
 * @brief Efface le message en cours de saisie
 */
void typing_mode_clear_current_message(void);

/**
 * @brief Ajoute un caractère à la fin du message en cours de saisie
 * @param c Caractère à ajouter
 */
void typing_mode_append_to_current_message(char c);

/**
 * @brief Affiche un message indiquant que l'envoi est en cours
 */
void typing_mode_show_sending_message_info(void);

/**
 * @brief Affiche un message de success post-envoi
 */
void typing_mode_show_success_send(void);

/**
 * @brief Affiche les instructions du mode de saisie
 */
void typing_mode_show_instructions(void);

/**
 * @brief Affiche les instructions de calibration du mode de saisie
 */
void typing_mode_show_instructions_calibration(void);

/**
 * @brief Affiche les instructions pour la saisie à 3 boutons
 */
void typing_mode_show_btns_instructions(void);

/**
 * @brief Affiche un message de succes indiquant que le code morse a bien été envoyé
 */
void typing_mode_show_sent_message_info(void);

/**
 * @brief Affiche un message indiquant l'envoi répété d'un code morse
 */
void typing_mode_show_repeating_message_info(void);


/**
 * @brief Affiche une frame laissant un espace vide dédié pour la saisie du code morse
 * @note Une commande est affiché pour quitter la saisie.
 */
void typing_mode_show_frame_empty_message(void);

#endif /* SCREEN_FRAMES_TYPING_MODE_H_ */
