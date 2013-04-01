/*
 * ADSensor.h
 *
 *  Created on: Apr 1, 2013
 *      Author: dam7633
 */

#ifndef ADSENSOR_H_
#define ADSENSOR_H_

#include <stdint.h>
#include "Sensor.h"
#include "Thread.h"

class ADSensor: public Sensor, Thread {
public:
	ADSensor(uintptr_t ctrl_handle, uintptr_t status_handle, uintptr_t msb_handle, uintptr_t lsb_handle);
	virtual ~ADSensor();

	double getValue();

	void *run();

private:
	uintptr_t ctrl_handle;
	uintptr_t status_handle;
	uintptr_t msb_handle;
	uintptr_t lsb_handle;
};

#endif /* ADSENSOR_H_ */
