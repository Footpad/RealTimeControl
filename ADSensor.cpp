/*
 * ADSensor.cpp
 *
 *  Created on: Apr 1, 2013
 *      Author: dam7633
 */

#include "ADSensor.h"
#include <hw/inout.h>

#define MAX_VALUE (326768)
#define MAX_VOLTAGE (10)
#define MAX_INP_VOLTAGE (4)
#define MIN_INP_VOLTAGE (-4)
#define MAX_CHAR (127)
#define MIN_CHAR (-128)
#define CONVERSION_FACTOR (127/5)

ADSensor::ADSensor(uintptr_t c, uintptr_t s, uintptr_t m, uintptr_t l) :
Thread("ADSensor"),
ctrl_handle(c),
status_handle(s),
msb_handle(m),
lsb_handle(l) {
}

ADSensor::~ADSensor() {
}

double ADSensor::getValue() {
	// 4. Perform an A/D conversion on the current channel
	out8(ctrl_handle, 0x80);

	// 5. Wait for the conversion to finish
	while (in8(status_handle) >= 128){
	} // wait for the value to be ready

	// 6. Read the data from the board
	unsigned char lsb = in8(lsb_handle);
	unsigned char msb = in8(msb_handle);
	short raw_data = msb * 256 + lsb;

	// 7. Convert the data to a meaningful value
	double voltage = raw_data / (double)MAX_VALUE * (double)MAX_VOLTAGE;

	if(voltage > MAX_INP_VOLTAGE) {
		//printf("\rVoltage High  ");
		voltage = MAX_CHAR;
	} else if(voltage < MIN_INP_VOLTAGE) {
		//printf("\rVoltage Low   ");
		voltage = MIN_CHAR;
	} else {
		//printf("\r              ");
		// Scale voltage
		voltage *= CONVERSION_FACTOR;
	}
	//fflush(stdout);

	return (char)voltage;
}

void *ADSensor::run() {
	while (!killThread) {

	}
	return NULL;
}
