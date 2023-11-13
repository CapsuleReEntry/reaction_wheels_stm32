/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "main.h"
#include "cmsis_os.h"
#include "mpu6050.h"

#define START_ADDRS_FLASH_MPU 0x08005000
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
I2C_HandleTypeDef hi2c1;

UART_HandleTypeDef huart1;

/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* USER CODE BEGIN PV */
 MPU6050_t MPU6050;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_USART1_UART_Init(void);
void StartDefaultTask(void *argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
 // while (MPU6050_Init(&hi2c1) == 1);
  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

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

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 400000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
	uint8_t Flag = 0x00;
	uint32_t Addres_Write = START_ADDRS_FLASH_MPU;
	uint8_t WriteVal = 0;
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
		Flag |= MPU6050_Init(&hi2c1);
		
	FLASH_EraseInitTypeDef Settings_Flash_data;
	Settings_Flash_data.Banks = FLASH_BANK_1;
	Settings_Flash_data.NbPages = 1;
	Settings_Flash_data.PageAddress = START_ADDRS_FLASH_MPU;
	Settings_Flash_data.TypeErase = FLASH_TYPEERASE_PAGES;
//  /* USER CODE BEGIN 5 */
//	Flag |= HAL_FLASH_Unlock();
//	uint32_t page_error = 0; // ??????????, ? ??????? ????????? ????? ???????? ??? ????????? ????????
//	Flag |= HAL_FLASHEx_Erase(&Settings_Flash_data, &page_error);
//	
//	
//  uint32_t address = 0x08003000; // ?????? ? ?????? ???????? 127
//  uint16_t idata[] = {0x1941, 0x1945};    // ?????? ?? ???? ????? ??? ??????
//	
//	
//	for(uint8_t i = 0; i < 2; i++) {
//		Flag |= HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, address+i*4, idata[i]);
//	}
//	Flag |= HAL_FLASH_Lock();
//	char *PtrCh = "Hello!";



  /* Infinite loop */
  for(;;)
  {
		static uint32_t tmpIndex[113];
		static uint16_t tmpTemp[113];
		static uint32_t tmpX[113];
		static uint16_t tmpY[113];
		static uint16_t tmpZ[113];
		for(uint16_t i = 0; i<113; i++){
			MPU6050_Read_Gyro(&hi2c1, &MPU6050);
			MPU6050_Read_Temp(&hi2c1, &MPU6050);
			tmpIndex[i] = i;
			tmpTemp[i] = MPU6050.Temperature;
			tmpX[i] = MPU6050.Gyro_X_RAW;
			tmpY[i] = MPU6050.Gyro_Y_RAW;
			tmpZ[i] = MPU6050.Gyro_Z_RAW;
			osDelay(10);
		}
		Flag |= HAL_FLASH_Unlock();
		uint32_t page_error = 0;
   	Flag |= HAL_FLASHEx_Erase(&Settings_Flash_data, &page_error);
		uint32_t Addr = START_ADDRS_FLASH_MPU;
		uint16_t i = 0;
		while(Addr < (START_ADDRS_FLASH_MPU + 0x7FF)) { //0x7ff -2 kbytes ore one page
//			Addres_Write += i;
				Flag |= HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, Addr, tmpIndex[i]);
				Addr+=4;
				Flag |= HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, Addr, tmpTemp[i]);
				Addr+=4;
				Flag |= HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, Addr, tmpX[i]);
				Addr+=4;
				Flag |= HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, Addr, tmpY[i]);
				Addr+=4;
				Flag |= HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, Addr, tmpZ[i]);
				Addr+=4;
				Flag |= HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, Addr, '\n');
				Addr+=4;
				++i;
		}		
		Flag |= HAL_FLASH_Lock();
		Addr = START_ADDRS_FLASH_MPU;
		while(Addr < (START_ADDRS_FLASH_MPU + 0x7FF)) {
			Flag |= HAL_FLASH_Unlock();
			WriteVal = *(uint8_t*)Addr;
			Flag |= HAL_FLASH_Unlock();
			HAL_UART_Transmit(&huart1, &WriteVal, sizeof(uint8_t),100);
			Addr +=4;
		  osDelay(100);
		}
	
	}
  /* USER CODE END 5 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

