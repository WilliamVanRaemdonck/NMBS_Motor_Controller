/**
 * @file motor_bord.c
 * @brief Implementation of motor control functions.
 *
 * This file provides the implementation for functions used to control motor behavior,
 * read ADC values, and manage communication with peripherals.
 *
 * @date October 24, 2024
 * @author William Van Raemdonck
 */

// includes
#include "main.h"
#include <stdio.h>
#include "string.h"

// External variable declarations
extern ADC_HandleTypeDef hadc;
extern UART_HandleTypeDef huart1;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim15;
extern TIM_HandleTypeDef htim16;
extern TIM_HandleTypeDef htim17;

extern char* uartBuffer;

// Function to read the ADC value
void ReadADCValue(uint32_t *potValue) {
	HAL_ADC_Start(&hadc);
	HAL_ADC_PollForConversion(&hadc, HAL_MAX_DELAY);
	*potValue = HAL_ADC_GetValue(&hadc);
}

// Function to control the level LEDs based on the potentiometer value
void SetLevelLEDs(uint32_t potValue) {
	if (potValue < 50) {
		HAL_GPIO_WritePin(LED_LEVEL1_GPIO_Port, LED_LEVEL1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_LEVEL2_GPIO_Port, LED_LEVEL2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_LEVEL3_GPIO_Port, LED_LEVEL3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_LEVEL4_GPIO_Port, LED_LEVEL4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_LEVEL5_GPIO_Port, LED_LEVEL5_Pin, GPIO_PIN_RESET);
	}
	else if (potValue >= 50 && potValue < 100) {
		HAL_GPIO_WritePin(LED_LEVEL1_GPIO_Port, LED_LEVEL1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_LEVEL2_GPIO_Port, LED_LEVEL2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_LEVEL3_GPIO_Port, LED_LEVEL3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_LEVEL4_GPIO_Port, LED_LEVEL4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_LEVEL5_GPIO_Port, LED_LEVEL5_Pin, GPIO_PIN_RESET);
	}
	else if (potValue >= 100 && potValue < 150) {
		HAL_GPIO_WritePin(LED_LEVEL1_GPIO_Port, LED_LEVEL1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_LEVEL2_GPIO_Port, LED_LEVEL2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_LEVEL3_GPIO_Port, LED_LEVEL3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_LEVEL4_GPIO_Port, LED_LEVEL4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_LEVEL5_GPIO_Port, LED_LEVEL5_Pin, GPIO_PIN_RESET);
	}
	else if (potValue >= 150 && potValue < 200) {
		HAL_GPIO_WritePin(LED_LEVEL1_GPIO_Port, LED_LEVEL1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_LEVEL2_GPIO_Port, LED_LEVEL2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_LEVEL3_GPIO_Port, LED_LEVEL3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_LEVEL4_GPIO_Port, LED_LEVEL4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_LEVEL5_GPIO_Port, LED_LEVEL5_Pin, GPIO_PIN_RESET);
	}
	else if (potValue >= 200) {
		HAL_GPIO_WritePin(LED_LEVEL1_GPIO_Port, LED_LEVEL1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_LEVEL2_GPIO_Port, LED_LEVEL2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_LEVEL3_GPIO_Port, LED_LEVEL3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_LEVEL4_GPIO_Port, LED_LEVEL4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_LEVEL5_GPIO_Port, LED_LEVEL5_Pin, GPIO_PIN_SET);
	}
}

void SetMotorSpeedAndDirection_DC(uint8_t potValuePercent, GPIO_PinState motorDirection, uint8_t motorNumber){
	if(motorDirection == GPIO_PIN_SET){
		//forward
		switch (motorNumber) {
		case 1:
			htim3.Instance->CCR1 = 0; // Channel 1
			htim3.Instance->CCR2 = potValuePercent; // Channel 2

			break;
		case 2:
			htim3.Instance->CCR3 = 0; // Channel 3
			htim3.Instance->CCR4 = potValuePercent; // Channel 4

			break;
		case 3:
			htim15.Instance->CCR1 = 0; // Channel 1
			htim15.Instance->CCR2 = potValuePercent; // Channel 2
			break;
		default:
			sprintf(uartBuffer, "incorrect motor ID\r\n");
			HAL_UART_Transmit(&huart1, (uint8_t *)uartBuffer, strlen(uartBuffer), HAL_MAX_DELAY);
			break;
		}

		// Update LEDs
		HAL_GPIO_WritePin(LED_LINKS_GPIO_Port, LED_LINKS_Pin, GPIO_PIN_SET);   // Turn on "left" LED
		HAL_GPIO_WritePin(LED_RECHTS_GPIO_Port, LED_RECHTS_Pin, GPIO_PIN_RESET); // Turn off "right" LED
	}
	else{
		//backwards
		switch (motorNumber) {
		case 1:
			htim3.Instance->CCR1 = potValuePercent; // Channel 1
			htim3.Instance->CCR2 = 0; // Channel 2

			break;
		case 2:
			htim3.Instance->CCR3 = potValuePercent; // Channel 3
			htim3.Instance->CCR4 = 0; // Channel 4

			break;
		case 3:
			htim15.Instance->CCR1 = potValuePercent; // Channel 1
			htim15.Instance->CCR2 = 0; // Channel 2
			break;
		default:
			sprintf(uartBuffer, "incorrect motor ID\r\n");
			HAL_UART_Transmit(&huart1, (uint8_t *)uartBuffer, strlen(uartBuffer), HAL_MAX_DELAY);
			break;
		}

		// Update LEDs
		HAL_GPIO_WritePin(LED_LINKS_GPIO_Port, LED_LINKS_Pin, GPIO_PIN_RESET);  // Turn off "left" LED
		HAL_GPIO_WritePin(LED_RECHTS_GPIO_Port, LED_RECHTS_Pin, GPIO_PIN_SET);  // Turn on "right" LED
	}
}

void SetMotorSpeedAndDirection_3Phase(uint8_t potValuePercent, GPIO_PinState motorDirection){
	if(motorDirection == GPIO_PIN_SET){
		//forwards
		htim3.Instance->CCR3 = potValuePercent;
		htim3.Instance->CCR4 = 0;

		htim16.Instance->CCR1 = potValuePercent;
		htim17.Instance->CCR1 = 0;

		htim15.Instance->CCR1 = potValuePercent;
		htim15.Instance->CCR2 = 0;
	}
	else{
		//backwards
		htim3.Instance->CCR3 = 0;
		htim3.Instance->CCR4 = potValuePercent;

		htim16.Instance->CCR1 = 0;
		htim17.Instance->CCR1 = potValuePercent;

		htim15.Instance->CCR1 = 0;
		htim15.Instance->CCR2 = potValuePercent;
	}
}

