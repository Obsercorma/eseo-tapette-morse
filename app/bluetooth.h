/*
 * bluetooth.h
 *
 *  Created on: 22 mai 2026
 *      Author: thomasstrong
 */

#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include "stm32g4_sys.h"

typedef struct {
	volatile uint8_t* data_from_bluetooth;
	volatile uint8_t* data_to_bluetooth;
} BluetoothData_t;

/**
 * @brief Initialisation du module Bluetooth HC-05
 */
void bluetooth_init(void);


/**
 * @brief Verifie si des donnees sont disponibles sur le module Bluetooth, et les affiche sur l'UART2
 */
void bluetooth_check_data(void);

/**
 * @brief Envoie des donnees au module Bluetooth
 * @param data Pointeur vers les donnees a envoyer
 * @param length Longueur des donnees a envoyer
 */
void bluetooth_send_data(uint8_t* data);

/*
 * @brief Recupere les donnees recues par le module Bluetooth et les stocke dans la structure BluetoothData_t
 */
void bluetooth_get_data(BluetoothData_t* data);

#endif /* BLUETOOTH_H_ */
