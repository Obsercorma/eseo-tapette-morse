/*
 * bluetooth.h
 *
 *  Created on: 22 mai 2026
 *      Author: thomasstrong
 */

#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

/**
 * @brief Initialisation du module Bluetooth HC-05
 */
void bluetooth_init(void);


/**
 * @brief Verifie si des donnees sont disponibles sur le module Bluetooth, et les affiche sur l'UART2
 */
void bluetooth_check_data(void);

#endif /* BLUETOOTH_H_ */
