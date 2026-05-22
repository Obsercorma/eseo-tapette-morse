/*
 * buttons.h
 *
 *  Created on: 27 avr. 2026
 *      Author: thomasstrong
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

#include "stm32g4_gpio.h"

#define BTN_PIN_U GPIO_PIN_0
#define BTN_PIN_R GPIO_PIN_1
#define BTN_PIN_D GPIO_PIN_2
#define BTN_PIN_L GPIO_PIN_11
#define BTN_PIN_M GPIO_PIN_12
#define BTN_PINS (BTN_PIN_U | BTN_PIN_R | BTN_PIN_D | BTN_PIN_L | BTN_PIN_M)

#define BTN_PIN_U_NUMBER 0
#define BTN_PIN_R_NUMBER 1
#define BTN_PIN_D_NUMBER 2
#define BTN_PIN_L_NUMBER 11
#define BTN_PIN_M_NUMBER 12

typedef struct {
	volatile uint8_t which_btn;
	volatile uint32_t duration;
	volatile uint8_t new_event;
} ButtonState_t;

/**
 * @brief Initialisation des GPIOs des boutons U (PA0), M (PA12), L (PA3), R (PA1) et D (PA2)
 */
void buttons_init(void);

void buttons_get_state(ButtonState_t* state);

#endif /* BUTTONS_H_ */
