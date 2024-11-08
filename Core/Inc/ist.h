//
// Created by Sunny on 24-11-6.
//

#ifndef IST_H
#define IST_H

#include "main.h"
#include "i2c.h"

class IST8310
{
private:
	uint8_t rxData_[6];
public:
	uint8_t chipId_;
	float magX_;
	float magY_;
	float magZ_;
	// float temp_;
	IST8310();
	void init();
	void readData();
};

#define IST8310_ADDR 0x0E
#define IST8310_DATA_REG_START 0x03

#define IST8310_STAT1_REG 0x02
#define IST8310_STAT2_REG 0x09
#define IST8310_CNTL1_REG 0x0A
#define IST8310_CNTL2_REG 0x0B
#define IST8310_AVGCNTL_REG 0x41

#define IST8310_CNTL1_200HZ 0x0B
#define IST8310_CNTL2_ENABLE_INT 0x08
#define IST8310_CNTL2_HIGH_INT 0x04
#define IST8310_AVGCNTL_FOUR 0x12

#define MAG_SEN 0.3f

#endif //IST_H
