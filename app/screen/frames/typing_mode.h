/*
 * typing_mode.h
 *
 *  Created on: 29 avr. 2026
 *      Author: thomasstrong
 */

#ifndef SCREEN_FRAMES_TYPING_MODE_H_
#define SCREEN_FRAMES_TYPING_MODE_H_

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
