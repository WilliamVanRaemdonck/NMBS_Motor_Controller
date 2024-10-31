/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define START_STOP_Pin GPIO_PIN_14
#define START_STOP_GPIO_Port GPIOC
#define MOTOR_LR_Pin GPIO_PIN_15
#define MOTOR_LR_GPIO_Port GPIOC
#define MOTOR_SELECT1_Pin GPIO_PIN_0
#define MOTOR_SELECT1_GPIO_Port GPIOF
#define MOTOR_SELECT2_Pin GPIO_PIN_1
#define MOTOR_SELECT2_GPIO_Port GPIOF
#define POT_METER_Pin GPIO_PIN_2
#define POT_METER_GPIO_Port GPIOA
#define LED_LEVEL1_Pin GPIO_PIN_3
#define LED_LEVEL1_GPIO_Port GPIOA
#define LED_LEVEL2_Pin GPIO_PIN_4
#define LED_LEVEL2_GPIO_Port GPIOF
#define LED_LEVEL3_Pin GPIO_PIN_5
#define LED_LEVEL3_GPIO_Port GPIOF
#define LED_LEVEL4_Pin GPIO_PIN_4
#define LED_LEVEL4_GPIO_Port GPIOA
#define LED_LEVEL5_Pin GPIO_PIN_5
#define LED_LEVEL5_GPIO_Port GPIOA
#define LED_LINKS_Pin GPIO_PIN_7
#define LED_LINKS_GPIO_Port GPIOA
#define LED_RECHTS_Pin GPIO_PIN_4
#define LED_RECHTS_GPIO_Port GPIOC
#define LED_MOTOR1_Pin GPIO_PIN_0
#define LED_MOTOR1_GPIO_Port GPIOB
#define LED_MOTOR2_Pin GPIO_PIN_1
#define LED_MOTOR2_GPIO_Port GPIOB
#define ERROR_IN_Pin GPIO_PIN_12
#define ERROR_IN_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
