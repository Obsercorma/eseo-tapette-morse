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
	char data_from_bluetooth[200];
	char data_to_bluetooth[200];
} BluetoothData_t;

/**
 * @brief Initialisation du module Bluetooth HC-05
 */
void bluetooth_init(void);


/**
 * @brief Verifie si des donnees sont disponibles sur le module Bluetooth, et les affiche sur l'UART2
 */
void bluetooth_check_data(char* bluetooth_buffer, size_t* buffer_size);

/**
 * @brief Envoie des donnees au module Bluetooth
 * @param data Pointeur vers les donnees a envoyer
 * @param length Longueur des donnees a envoyer
 */
void bluetooth_send_data(char* data);

/*
 * @brief Recupere les donnees recues par le module Bluetooth et les stocke dans la structure BluetoothData_t
 */
void bluetooth_get_data(BluetoothData_t* data);

/**
 * @brief Efface les donnees recues par le module Bluetooth dans la structure BluetoothData_t
 */
void bluetooth_clear_data_from(void);

#endif /* BLUETOOTH_H_ */
