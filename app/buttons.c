/*
 * buttons.c
 *
 *  Created on: 29 avr. 2026
 *      Author: obsercorma
 */

#include "buttons.h"
#include "stm32g4_gpio.h"
#include "stm32g4_extit.h"

static void callback_handler(uint8_t GPIO_Pin);

ButtonState_t button_state;

void buttons_init(){
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_SYSCFG_CLK_ENABLE();

	BSP_GPIO_pin_config(GPIOA, BTN_PINS, GPIO_MODE_IT_RISING_FALLING, GPIO_PULLUP, GPIO_SPEED_LOW, GPIO_NO_AF);

	BSP_EXTIT_set_callback(callback_handler, BTN_PIN_U_NUMBER, 1);
	BSP_EXTIT_set_callback(callback_handler, BTN_PIN_R_NUMBER, 1);
	BSP_EXTIT_set_callback(callback_handler, BTN_PIN_D_NUMBER, 1);
	BSP_EXTIT_set_callback(callback_handler, BTN_PIN_L_NUMBER, 1);
	BSP_EXTIT_set_callback(callback_handler, BTN_PIN_M_NUMBER, 1);

	button_state.which_btn = 0;
	button_state.duration = 0;
	button_state.new_event = 0;
}

void buttons_get_state(ButtonState_t* state){
	(*state) = button_state;
}


static void callback_handler(uint8_t GPIO_Pin){
	if(button_state.new_event && button_state.which_btn == GPIO_Pin){
		button_state.duration = HAL_GetTick() - button_state.duration;
		button_state.new_event = 0;
	}else{
		button_state.which_btn = GPIO_Pin;
		button_state.duration = HAL_GetTick();
		button_state.new_event = HAL_GPIO_ReadPin(GPIOA, (1 << GPIO_Pin)) == GPIO_PIN_RESET ? 1 : 0; // state = 1 si appuyé, 0 si relâché
	}
}
