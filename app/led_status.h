/*
 * led_status.h
 *
 *  Created on: 27 avr. 2026
 *      Author: obsercorma
 */

#ifndef LED_STATUS_H_
#define LED_STATUS_H_

#include "stm32g4_utils.h"


/**
 * @brief Initialisation LED de status
 */
void led_status_init(void);


/**
 * @brief Change l'etat de la LED de status
 * @param status: État de sortie de la LED (1 = Allumé ; 0 = Eteint)
 */
void led_status_switch(uint8_t status);

#endif /* LED_STATUS_H_ */
