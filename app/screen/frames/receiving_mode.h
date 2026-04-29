/*
 * screen_receiving_mode.h
 *
 *  Created on: 29 avr. 2026
 *      Author: thomasstrong
 */

#ifndef SCREEN_SCREEN_RECEIVING_MODE_H_
#define SCREEN_SCREEN_RECEIVING_MODE_H_

#include "stm32g4_utils.h"

void receiving_mode_show_home(uint8_t is_active);

void receiving_mode_show_instructions(void);

void receiving_mode_show_instructions_calibration(void);

void receiving_mode_show_btns_instructions(void);

#endif /* SCREEN_SCREEN_RECEIVING_MODE_H_ */
