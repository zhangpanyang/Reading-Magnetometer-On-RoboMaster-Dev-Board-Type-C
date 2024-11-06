//
// Created by Sunny on 24-11-6.
//

#include "callback.h"

extern IST8310 ist;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == IST_INT_Pin)
	{
		ist.readData();
	}
}