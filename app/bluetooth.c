/*
 * bluetooth.c
 *
 *  Created on: 22 mai 2026
 *      Author: thomasstrong
 */

#include "bluetooth.h"
#include "stm32g4_uart.h"
#include "stm32g4_sys.h"
#include <stdio.h>

void bluetooth_init(){
	BSP_UART_init(UART1_ID, 38400); // Init UART for HC05
	BSP_UART_init(UART2_ID,38400); // Init UART for debug (printf)
}

void bluetooth_check_data(){
	while(BSP_UART_data_ready(UART1_ID)){
		uint8_t data = BSP_UART_getc(UART1_ID);
		BSP_UART_putc(UART2_ID, data); // Affiche les données reçues sur l'UART2 (pour debug)
	}
	while(BSP_UART_data_ready(UART2_ID)){
		uint8_t data = BSP_UART_getc(UART2_ID);
		BSP_UART_putc(UART1_ID, data); // Envoie les données reçues sur l'UART2 vers le module Bluetooth (pour debug)
	}
}
