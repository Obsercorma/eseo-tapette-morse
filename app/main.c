/**
 *******************************************************************************
 * @file 	main.c
 * @author 	jjo
 * @date 	Mar 29, 2024
 * @brief	Fichier principal de votre projet sur carte Nucléo STM32G431KB
 *******************************************************************************
 */

#include "config.h"
#include "stm32g4_sys.h"

#include "stm32g4_systick.h"
#include "stm32g4_gpio.h"
#include "stm32g4_uart.h"
#include "stm32g4_utils.h"
#include "screen/screen.h"
#include "screen/frames/home.h"
#include "screen/frames/shutdown.h"
#include "screen/frames/typing_mode.h"
#include "screen/frames/receiving_mode.h"
#include "buttons.h"
#include "bluetooth.h"
#include "screen/screen.h"
#include "morse.h"

#include <stdio.h>
#include <string.h>

/**
 * @brief  Point d'entrée de votre application
 */
int main(void) {
	/* Cette ligne doit rester la première de votre main !
	 * Elle permet d'initialiser toutes les couches basses des drivers (Hardware Abstraction Layer),
	 * condition préalable indispensable à l'exécution des lignes suivantes.
	 */
	HAL_Init();

	/* Initialisation des périphériques utilisés dans votre programme */
	BSP_GPIO_enable();

	bluetooth_init();

	//BSP_GPIO_pin_config(GPIOB, GPIO_PIN_4, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_LOW, GPIO_NO_AF);
	//HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);

	/* Indique que les printf sont dirigés vers l'UART2 */
	//BSP_SYS_set_std_usart(UART2_ID, UART2_ID, UART2_ID);
	//heartbeat();
	screen_init();
	//screen_show_mode(SCREEN_HOME_MODE);

	//HAL_Delay(3000);

	ScreenCallbacks_t screen_callbacks;
	home_show_home();
	screen_get_callbacks(&screen_callbacks);

	buttons_init();

	ButtonState_t btn_state;
	buttons_get_state(&btn_state);
	BluetoothData_t bt_data;
	char bluetooth_buffer[200];
	bluetooth_buffer[0] = '\0';
	size_t bluetooth_buffer_size = 0;
	uint8_t should_clear_screen = 1;

	/* Tâche de fond, boucle infinie, Infinite loop,... quelque soit son nom vous n'en sortirez jamais */
	while (1) {
		bluetooth_check_data(bluetooth_buffer, &bluetooth_buffer_size);
		bluetooth_get_data(&bt_data);

		buttons_update();
		buttons_get_state(&btn_state);

		screen_get_should_clear(&should_clear_screen);

		HAL_Delay(10);
		if (btn_state.event_type != BTN_EVENT_NONE) {
			if (should_clear_screen == 1) {
				screen_clear();
			}
			if (btn_state.which_btn == BTN_PIN_M_NUMBER) {
				if (btn_state.event_type == BTN_EVENT_LONG
						&& screen_callbacks.button_long_m != NULL) {
					screen_callbacks.button_long_m();
				} else if (btn_state.event_type == BTN_EVENT_DOUBLE
						&& screen_callbacks.button_double_m != NULL) {
					screen_callbacks.button_double_m();
				} else if (screen_callbacks.button_m != NULL) {
					screen_callbacks.button_m();
				}
			}
			if (btn_state.which_btn == BTN_PIN_U_NUMBER) {
				if (btn_state.event_type == BTN_EVENT_LONG
						&& screen_callbacks.button_long_u != NULL) {
					screen_callbacks.button_long_u();
				} else if (btn_state.event_type == BTN_EVENT_DOUBLE
						&& screen_callbacks.button_double_u != NULL) {
					screen_callbacks.button_double_u();
				} else if (screen_callbacks.button_u != NULL) {
					screen_callbacks.button_u();
				}
			}
			if (btn_state.which_btn == BTN_PIN_L_NUMBER) {
				if (btn_state.event_type == BTN_EVENT_LONG
						&& screen_callbacks.button_long_l != NULL) {
					screen_callbacks.button_long_l();
				} else if (btn_state.event_type == BTN_EVENT_DOUBLE
						&& screen_callbacks.button_double_l != NULL) {
					screen_callbacks.button_double_l();
				} else if (screen_callbacks.button_l != NULL) {
					screen_callbacks.button_l();
				}
			}
			if (btn_state.which_btn == BTN_PIN_R_NUMBER) {
				if (btn_state.event_type == BTN_EVENT_LONG
						&& screen_callbacks.button_long_r != NULL) {
					screen_callbacks.button_long_r();
				} else if (btn_state.event_type == BTN_EVENT_DOUBLE
						&& screen_callbacks.button_double_r != NULL) {
					screen_callbacks.button_double_r();
				} else if (screen_callbacks.button_r != NULL) {
					screen_callbacks.button_r();
				}
			}
			if (btn_state.which_btn == BTN_PIN_D_NUMBER) {
				if (btn_state.event_type == BTN_EVENT_LONG
						&& screen_callbacks.button_long_d != NULL) {
					screen_callbacks.button_long_d();
				} else if (btn_state.event_type == BTN_EVENT_DOUBLE
						&& screen_callbacks.button_double_d != NULL) {
					screen_callbacks.button_double_d();
				} else if (screen_callbacks.button_d != NULL) {
					screen_callbacks.button_d();
				}
			}
			screen_get_callbacks(&screen_callbacks);
			buttons_clear_event();
		}
	}
}
