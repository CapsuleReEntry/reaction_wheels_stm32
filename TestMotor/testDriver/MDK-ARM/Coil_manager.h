#include "stm32f1xx_hal.h"

#define Q1 GPIO_PIN_11
#define Q2 GPIO_PIN_10
#define Q3 GPIO_PIN_1
#define Q4 GPIO_PIN_0
#define Q5 GPIO_PIN_7
#define Q6 GPIO_PIN_6

void Connect_Coil1_Coil2_Coil3();
void Connect_Coil1_Coil3_Coil2();
void Connect_Coil2_Coil3_Coil1();
void Connect_Coil2_Coil1_Coil3();
void Connect_Coil3_Coil1_Coil2();
void Connect_Coil3_Coil2_Coil1();

void Connect_Disable_all_Coil();