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

#include <stdio.h>


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

	//BSP_GPIO_pin_config(GPIOB, GPIO_PIN_4, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_LOW, GPIO_NO_AF);
	//HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
	BSP_UART_init(UART2_ID,38400);
	BSP_UART_init(UART1_ID, 38400);

	/* Indique que les printf sont dirigés vers l'UART2 */
	//BSP_SYS_set_std_usart(UART2_ID, UART2_ID, UART2_ID);

	//heartbeat();


	screen_init();
	//screen_show_mode(SCREEN_HOME_MODE);

	//HAL_Delay(3000);

	screen_show_mode(SCREEN_RECEIVING_MODE);

	led_status_init();


	/* Tâche de fond, boucle infinie, Infinite loop,... quelque soit son nom vous n'en sortirez jamais */
	while (1)
	{
		HAL_Delay(1000);
		led_status_switch(1);
		HAL_Delay(1000);
		led_status_switch(0);
	}
}
