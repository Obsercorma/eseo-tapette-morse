/*
 * bluetooth.c
 *
 *  Created on: 22 mai 2026
 *      Author: thomasstrong
 */

#include "bluetooth.h"
#include "stm32g4_uart.h"
#include "stm32g4_sys.h"
#include "stm32g4xx_hal_uart.h"
#include <stdio.h>

BluetoothData_t bluetooth_data;

BluetoothMessagesCases_e blCase = BL_NONE;

void bluetooth_init(){
	BSP_UART_init(UART1_ID, 9600); // Init UART for HC05
	BSP_UART_init(UART2_ID, 38400); // Init UART for debug (printf)
	//BSP_UART_puts(UART1_ID, "Hello world!\n", 0); // Change le nom du module Bluetooth
}

void bluetooth_get_status(BluetoothMessagesCases_e* cs){
	(*cs) = blCase;
}

void bluetooth_set_status(BluetoothMessagesCases_e cs){
	blCase = cs;
}

void bluetooth_send_data(char* data){
	BSP_UART_puts(UART1_ID, (const char*)data, 0);
}

void bluetooth_get_data(BluetoothData_t* data){
	(*data) = bluetooth_data;
}

void bluetooth_set_data(BluetoothData_t* data){
	bluetooth_data = *data;
}

void bluetooth_clear_data_from(){
	bluetooth_data.data_from_bluetooth[0] = '\0';
}

void bluetooth_check_data(char* bluetooth_buffer, size_t* buffer_size){
	uint8_t index = 0;

	while(BSP_UART_data_ready(UART1_ID)){

		char c = BSP_UART_getc(UART1_ID);

		if(c == '\r' || c == '\n'){

			if(index > 0){
				bluetooth_buffer[index] = '\0';
				*buffer_size = index;

				index = 0;
				return;
			}

			continue;
		}

		if(index < 199){
			bluetooth_buffer[index++] = c;
		}
	}
}
