/*
 * DACActuator.cpp
 *
 *  Created on: Apr 1, 2013
 *      Author: dam7633
 */

#include "DACActuator.h"
#include <hw/inout.h>

#define MAX_DA_CODE (4095)
#define MIN_DA_CODE (0)
#define OUTPUT_REFERENCE (10)
#define DAC_CHANNEL (0)

DACActuator::DACActuator(uintptr_t s, uintptr_t m, uintptr_t l) :
Thread("DACActuator"),
status_handle(s),
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
	// Convert the output value to a DAC code.
	short daCode = (value / OUTPUT_REFERENCE) * 2048 + 2048;

	// Clip the DAC code.
	if (daCode > MAX_DA_CODE) {
		daCode = MAX_DA_CODE;
	} else if (daCode < MIN_DA_CODE) {
		daCode = MIN_DA_CODE;
	}

	// Split the DAC code into LSB (8 bits) and MSB (4 bits).
	unsigned char lsb = daCode & 255;
	unsigned char msb = daCode / 256;

	// Write to the specified DAC channel.
	out8(lsb_handle, lsb);
	out8(msb_handle, msb + (DAC_CHANNEL << 6));

	// Wait for the D/A to finish.
	while ((in8(status_handle) & 0b00001000) != 0) { }
}
