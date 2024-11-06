//
// Created by Sunny on 24-11-6.
//

#include "ist.h"

void readMultiDataFromIST8310(uint8_t reg, uint8_t* data, uint8_t len) {
	HAL_I2C_Mem_Read(&hi2c3, (IST8310_ADDR << 1), reg, I2C_MEMADD_SIZE_8BIT, data, len, HAL_MAX_DELAY);
}

void writeSingleDataToIST8310(uint8_t reg, uint8_t data) {
	HAL_I2C_Mem_Write(&hi2c3, (IST8310_ADDR << 1), reg, I2C_MEMADD_SIZE_8BIT, &data, 1, HAL_MAX_DELAY);
}

IST8310::IST8310()
{
	chipId_ = 0x00;
	magX_ = 0;
	magY_ = 0;
	magZ_ = 0;
}

void IST8310::init()
{
	HAL_GPIO_WritePin(IST_RST_GPIO_Port, IST_RST_Pin, GPIO_PIN_RESET);
	HAL_Delay(50);
	HAL_GPIO_WritePin(IST_RST_GPIO_Port, IST_RST_Pin, GPIO_PIN_SET);
	HAL_Delay(50);

	readMultiDataFromIST8310(0x00, &chipId_, 1);

	writeSingleDataToIST8310(IST8310_CNTL1_REG, IST8310_CNTL1_200HZ);
	writeSingleDataToIST8310(IST8310_CNTL2_REG, IST8310_CNTL2_ENABLE_INT);
	writeSingleDataToIST8310(IST8310_AVGCNTL_REG, IST8310_AVGCNTL_FOUR);
}

void IST8310::readData()
{
	readMultiDataFromIST8310(IST8310_DATA_REG_START, rxData_, 6);
	int16_t magXData = (rxData_[1] << 8) | rxData_[0];
	int16_t magYData = (rxData_[3] << 8) | rxData_[2];
	int16_t magZData = (rxData_[5] << 8) | rxData_[4];
	magX_ = magXData * MAG_SEN;
	magY_ = magYData * MAG_SEN;
	magZ_ = magZData * MAG_SEN;
}

