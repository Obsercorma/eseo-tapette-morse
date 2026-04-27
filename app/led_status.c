/*
 * led_status.c
 *
 *  Created on: 27 avr. 2026
 *      Author: thomasstrong
 */

#include "led_status.h"
#include "stm32g4_gpio.h"

void led_status_init(){
	BSP_GPIO_pin_config(GPIOB, GPIO_PIN_0, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_LOW, GPIO_NO_AF);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
}

void led_status_switch(uint8_t status){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, status);
}
