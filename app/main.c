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
#include "led_status.h"
#include "screen/screen.h"
#include "screen/frames/home.h"
#include "screen/frames/shutdown.h"
#include "screen/frames/typing_mode.h"
#include "screen/frames/receiving_mode.h"
#include "buttons.h"
#include "bluetooth.h"
#include "morse.h"

#include <stdio.h>
#include <string.h>

/**
  * @brief  Point d'entrée de votre application
  */
int main(void)
{
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

	screen_show_mode(SCREEN_HOME_MODE);

	led_status_init();

	buttons_init();

	ButtonState_t btn_state;
	buttons_get_state(&btn_state);
	BluetoothData_t bt_data;
	uint8_t bluetooth_buffer[200];
	bluetooth_buffer[0] = '\0';
	size_t bluetooth_buffer_size = 0;

	uint32_t last_tick = HAL_GetTick();


	/* Tâche de fond, boucle infinie, Infinite loop,... quelque soit son nom vous n'en sortirez jamais */
	while (1)
	{
		bluetooth_check_data(bluetooth_buffer, &bluetooth_buffer_size);
		bluetooth_get_data(&bt_data);
		buttons_get_state(&btn_state);
		if(bluetooth_buffer[0] != '\0'){
			screen_clear();
			volatile char* output; // 5 est une estimation de la taille maximale d'un message Morse correspondant à une chaîne de caractères (1 caractère = 4 symboles Morse + 1 espace)
			morse_encode(bluetooth_buffer, output);
			receiving_mode_show_received_message(output);
			bluetooth_buffer[0] = '\0';
			HAL_Delay(10000);
		}
		HAL_Delay(10);
		if(btn_state.new_event){
			screen_clear();
			if(btn_state.which_btn == BTN_PIN_M_NUMBER){
				home_show_home();
			}
			if(btn_state.which_btn == BTN_PIN_U_NUMBER){
				typing_mode_show_btns_instructions();
			}
			if(btn_state.which_btn == BTN_PIN_L_NUMBER){
				receiving_mode_show_question_message();
			}
			if(btn_state.which_btn == BTN_PIN_R_NUMBER){
				shutdown_show_alert();
			}
			if(btn_state.which_btn == BTN_PIN_D_NUMBER){
				typing_mode_show_instructions_calibration();
			}
			HAL_Delay(200);
		}
	}
}
