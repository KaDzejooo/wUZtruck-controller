/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
#include "stm32h7xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */



typedef struct{
	int size; // size of message
	char Data[257]; // message data
}uartData_t;

typedef struct{
// contains all settings and button states from ui

	 int aux[4]; //main screen buttons
	 int lights[8]; //toggle channels from lights screen
	 double settings[8]; //value settings
	 int idle; // if on idle screen
	  /* expo fact
	   * smooth fact
	   *
	   */
}model2user;

typedef struct{
	int joy1x; // 65536 max
	int joy1y;
	int joy2x;
	int joy2y;
	int trigg;
	int bttn1; // button joy1
	int bttn2; // button joy2
	int bttn3; // d-pad buttons
	int bttn4; //
	int bttn5; //
	int bttn6; //
}dataToSend;
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ButtonUser_Pin GPIO_PIN_3
#define ButtonUser_GPIO_Port GPIOE
#define LCD_BL_CTRL_Pin GPIO_PIN_15
#define LCD_BL_CTRL_GPIO_Port GPIOG
#define ARD_D4_Pin GPIO_PIN_4
#define ARD_D4_GPIO_Port GPIOG
#define RENDER_TIME_Pin GPIO_PIN_3
#define RENDER_TIME_GPIO_Port GPIOG
#define MCU_ACTIVE_Pin GPIO_PIN_15
#define MCU_ACTIVE_GPIO_Port GPIOB
#define LCD_DISP_Pin GPIO_PIN_10
#define LCD_DISP_GPIO_Port GPIOD
#define LED1_Pin GPIO_PIN_2
#define LED1_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_3
#define LED2_GPIO_Port GPIOC
#define VSYNC_FREQ_Pin GPIO_PIN_0
#define VSYNC_FREQ_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
