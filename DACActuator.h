/*
 * DACActuator.h
 *
 *  Created on: Apr 1, 2013
 *      Author: dam7633
 */

#ifndef DACACTUATOR_H_
#define DACACTUATOR_H_

#include <stdint.h>
#include "Actuator.h"
#include "Thread.h"

class DACActuator: public Actuator, Thread {
public:
	DACActuator(uintptr_t status_handle, uintptr_t msb_handle, uintptr_t lsb_handle);
	virtual ~DACActuator();

	void *run();

	void setValue(double value);
private:
	uintptr_t status_handle;
	uintptr_t msb_handle;
	uintptr_t lsb_handle;
};

#endif /* DACACTUATOR_H_ */
