#include "Coil_manager.h"

void Connect_Coil1_Coil2_Coil3(){
	HAL_GPIO_WritePin(GPIOB,Q1,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,Q4,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,Q5,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,Q6,GPIO_PIN_RESET);
}

void Connect_Coil1_Coil3_Coil2(){
	HAL_GPIO_WritePin(GPIOB,Q1,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,Q6,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,Q3,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,Q4,GPIO_PIN_RESET);	
}

void Connect_Coil2_Coil3_Coil1(){
	HAL_GPIO_WritePin(GPIOB,Q3,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,Q6,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,Q1,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,Q2,GPIO_PIN_RESET);	
}

void Connect_Coil2_Coil1_Coil3(){
	HAL_GPIO_WritePin(GPIOB,Q3,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,Q2,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,Q5,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,Q6,GPIO_PIN_RESET);	
}

void Connect_Coil3_Coil1_Coil2(){
	HAL_GPIO_WritePin(GPIOA,Q5,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,Q2,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,Q3,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,Q4,GPIO_PIN_RESET);	
}

void Connect_Coil3_Coil2_Coil1(){
	HAL_GPIO_WritePin(GPIOA,Q5,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,Q3,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,Q1,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,Q2,GPIO_PIN_RESET);	
}

void Connect_Disable_all_Coil(){
	HAL_GPIO_WritePin(GPIOB,Q1,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,Q2,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,Q3,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,Q4,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,Q5,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,Q6,GPIO_PIN_RESET);	
}