/*
 * buttons.h
 *
 *  Created on: 27 avr. 2026
 *      Author: thomasstrong
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

#include "stm32g4_gpio.h"

// Emplacements GPIO pour la gestion des boutons
#define BTN_PIN_U GPIO_PIN_0
#define BTN_PIN_R GPIO_PIN_1
#define BTN_PIN_D GPIO_PIN_2
#define BTN_PIN_L GPIO_PIN_11
#define BTN_PIN_M GPIO_PIN_12

// Groupement des GPIOS
#define BTN_PINS (BTN_PIN_U | BTN_PIN_R | BTN_PIN_D | BTN_PIN_L | BTN_PIN_M)

// Identifiants EXTI de chaque boutons
#define BTN_PIN_U_NUMBER 0
#define BTN_PIN_R_NUMBER 1
#define BTN_PIN_D_NUMBER 2
#define BTN_PIN_L_NUMBER 11
#define BTN_PIN_M_NUMBER 12

// Durée minimale pour un appui long (1.5 secs)
#define BTN_LONG_PRESS_DURATION 1500U

// Durée minimale d'intervale entre le 1er et le 2nd appui (500 ms)
#define BTN_DOUBLE_PRESS_WINDOW 500U

// Durée minimale Debounce (50 ms)
#define BTN_DEBOUNCE_MS 50U

// Gestion des types d'événements
// Evénement nul
#define BTN_EVENT_NONE    0

// Evénement de type appui simple (un seul appui)
#define BTN_EVENT_SIMPLE  1

// Evénement de type appui double (deux appuis)
#define BTN_EVENT_DOUBLE  2

// Evénement de type appui long
#define BTN_EVENT_LONG    3

/**
 * @brief Structure permettant d'obtenir des détails sur un événement
 */
typedef struct {
	volatile uint8_t which_btn;
	volatile uint32_t duration;
	volatile uint8_t new_event;
	volatile uint8_t is_long_press;
	volatile uint8_t is_double_press;
	volatile uint8_t event_type;
} ButtonState_t;

/**
 * @brief Initialisation des GPIOs des boutons U (PA0), M (PA12), L (PA3), R (PA1) et D (PA2)
 */
void buttons_init(void);


/**
 * @brief Efface l'événement de bouton en cours, doit être appelé après avoir traité un événement de bouton
 */
void buttons_clear_event(void);

/**
 * @brief Met à jour l'état des boutons, doit être appelé régulièrement dans la boucle principale pour gérer les événements de double pression
 */
void buttons_update(void);

/**
 * @brief Permet d'obtenir les détails d'un événement au moment où l'on appel cette fonction buttons_get_state
 * @param state: Détails de l'événement
 */
void buttons_get_state(ButtonState_t* state);

#endif /* BUTTONS_H_ */
