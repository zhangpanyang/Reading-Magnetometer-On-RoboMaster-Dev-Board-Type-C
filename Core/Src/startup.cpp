//
// Created by Sunny on 24-11-6.
//

#include "startup.h"

#include "ist.h"

extern IST8310 ist;
void startup()
{
	ist.init();
	while (1)
	{
		ist.readData();
		HAL_Delay(100);
	}
}

