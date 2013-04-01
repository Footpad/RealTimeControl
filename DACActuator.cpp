/*
 * DACActuator.cpp
 *
 *  Created on: Apr 1, 2013
 *      Author: dam7633
 */

#include "DACActuator.h"

DACActuator::DACActuator(uintptr_t c, uintptr_t m, uintptr_t l) :
Thread("DACActuator"),
ctrl_handle(c),
msb_handle(m),
lsb_handle(l) {
}

DACActuator::~DACActuator() {
}

void *DACActuator::run() {
	while (!killThread) {

	}

	return NULL;
}

void DACActuator::setValue(double value) {

}
