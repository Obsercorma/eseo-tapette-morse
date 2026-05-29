/*
 * buttons.c
 *
 *  Created on: 29 avr. 2026
 *      Author: obsercorma
 */

#include "buttons.h"
#include "led_status.h"
#include "stm32g4_gpio.h"
#include "stm32g4_extit.h"

ButtonState_t button_state;
static uint8_t waiting_second[16] = {0};
static uint32_t first_release[16] = {0};

static void callback_handler(uint8_t GPIO_Pin);

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
	button_state.is_long_press = 0;

	led_status_init();
}

void buttons_get_state(ButtonState_t* state){
	(*state) = button_state;
}

void buttons_clear_event(){
	button_state.new_event = 0;
	button_state.duration = 0;
	button_state.is_long_press = 0;
	button_state.is_double_press = 0;
	button_state.event_type = BTN_EVENT_NONE;
}

void buttons_update(void)
{
	uint32_t now = HAL_GetTick();

	for(int i = 0; i < 16; i++)
	{
		if(waiting_second[i] &&
		   (now - first_release[i] >= BTN_DOUBLE_PRESS_WINDOW))
		{
			button_state.which_btn = i;
			button_state.event_type = BTN_EVENT_SIMPLE;
			button_state.new_event = 0;
			button_state.duration = 1;

			waiting_second[i] = 0;
		}
	}
}


static void callback_handler(uint8_t GPIO_Pin)
{
	static uint32_t last_gpio[16] = {0};

	uint32_t now = HAL_GetTick();

	if(now - last_gpio[GPIO_Pin] < BTN_DEBOUNCE_MS)
		return;

	last_gpio[GPIO_Pin] = now;

	GPIO_PinState state = HAL_GPIO_ReadPin(GPIOA, (1 << GPIO_Pin));

	if(state == GPIO_PIN_RESET)
	{
		button_state.which_btn = GPIO_Pin;
		button_state.duration = now;
		button_state.new_event = 1;
		led_status_switch(1);
	}
	else
	{
		if(button_state.which_btn == GPIO_Pin && button_state.new_event)
		{
			uint32_t press_duration = now - button_state.duration;

			button_state.duration = press_duration;
			button_state.new_event = 0;

			if(press_duration >= BTN_LONG_PRESS_DURATION)
			{
				button_state.event_type = BTN_EVENT_LONG;
				waiting_second[GPIO_Pin] = 0;
			}
			else
			{
				if(waiting_second[GPIO_Pin] &&
				   (now - first_release[GPIO_Pin] <= BTN_DOUBLE_PRESS_WINDOW))
				{
					button_state.event_type = BTN_EVENT_DOUBLE;
					waiting_second[GPIO_Pin] = 0;
				}
				else
				{
					first_release[GPIO_Pin] = now;
					waiting_second[GPIO_Pin] = 1;
					button_state.event_type = BTN_EVENT_NONE;
				}
			}
		}

		led_status_switch(0);
	}
}
