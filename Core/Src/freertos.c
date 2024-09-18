/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include"lcd.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
extern struct DisplayInfo Battary_Box_Voltag;
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
struct DisplayInfo Battary_Box_Voltage={26,10,"电池箱电压:",1};
struct DisplayInfo Cell_Temprature={646,10,"电芯温度:",1};
struct DisplayInfo HV_Board_Temprature={26,130,"高压板温度:",1};
struct DisplayInfo Main_Control_Temprature={42,250,"主控温度:",1};
struct DisplayInfo Battary_Box_Power={678,130,"功率:",1};
struct DisplayInfo Cell_Voltage={646,250,"电芯电压:",1};
struct DisplayInfo LV_Voltage={10,370,"低压电池电压:",1};
struct DisplayInfo Inverter_Temprature={328,370,"驱动器温度:",1};
struct DisplayInfo Motor_Temprature={646,370,"电机温度:",1};
struct DisplayInfo SOC={376,10,"SOC:",1};
// LCD_Show_Chinese_String(26,10,176,32,32,(u8*)"电池箱电压:");
// 	LCD_Show_Chinese_String(376,10,64,32,32,(u8*)"SOC:");
// 	LCD_Show_Chinese_String(646,10,144,32,32,"电芯温度:");
	
// 	LCD_Show_Chinese_String(26,130,176,32,32,"高压板温度:");
// 	LCD_Show_Chinese_String(42,250,144,32,32,"主控温度:");
	
// 	LCD_Show_Chinese_String(678,130,72,32,32,"功率:");
// 	LCD_Show_Chinese_String(646,250,144,32,32,"电芯电压:");
	
// 	LCD_Show_Chinese_String(10,370,208,32,32,"低压电池电压:");
// 	LCD_Show_Chinese_String(328,370,176,32,32,"驱动器温度:");
// 	LCD_Show_Chinese_String(646,370,144,32,32,"电机温度:");

void StartDefaultTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
TaskHandle_t  Battary_Box_VoltageHandle;
TaskHandle_t Cell_TempratureHandle;
TaskHandle_t HV_Board_TempratureHandle;
TaskHandle_t Main_Control_TempratureHandle;
TaskHandle_t Battary_Box_PowerHandle;
TaskHandle_t Cell_VoltageHandle;
TaskHandle_t LV_VoltageHandle;
TaskHandle_t Inverter_TempratureHandle;
TaskHandle_t SOCHandle;
TaskHandle_t Motor_TempratureHandle;
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);


xTaskCreate(LCD_Print," Battary_Box_Voltage",128,&Battary_Box_Voltage,osPriorityNormal,&Battary_Box_VoltageHandle);
xTaskCreate(LCD_Print," Cell_Temprature",128,&Battary_Box_Voltage,osPriorityNormal,&Cell_TempratureHandle);
xTaskCreate(LCD_Print," HV_Board_Temprature",128,&Battary_Box_Voltage,osPriorityNormal,&HV_Board_TempratureHandle);
xTaskCreate(LCD_Print," Main_Control_Temprature",128,&Battary_Box_Voltage,osPriorityNormal,&Main_Control_TempratureHandle);
xTaskCreate(LCD_Print," Battary_Box_Power",128,&Battary_Box_Voltage,osPriorityNormal,&Battary_Box_PowerHandle);
xTaskCreate(LCD_Print," Cell_Voltage",128,&Battary_Box_Voltage,osPriorityNormal,&Cell_VoltageHandle);
xTaskCreate(LCD_Print," LV_Voltage",128,&Battary_Box_Voltage,osPriorityNormal,&LV_VoltageHandle);
xTaskCreate(LCD_Print," Inverter_Temprature",128,&Battary_Box_Voltage,osPriorityNormal,&Inverter_TempratureHandle);
xTaskCreate(LCD_Print," SOC",128,&Battary_Box_Voltage,osPriorityNormal,&SOCHandle);
xTaskCreate(LCD_Print," Motor_Temprature",128,&Battary_Box_Voltage,osPriorityNormal,&Motor_TempratureHandle);
  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

