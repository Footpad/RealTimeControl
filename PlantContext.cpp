/*
 * PlantContext.cpp
 *
 *  Created on: Apr 1, 2013
 *      Author: dam7633
 */

#include "PlantContext.h"

PlantContext::PlantContext() {
	// TODO Auto-generated constructor stub

}

PlantContext::~PlantContext() {
	// TODO Auto-generated destructor stub
}

double PlantContext::getProportionalGain() {
	return proportionalGain;
}

void PlantContext::setProportionalGain(double p) {
	proportionalGain = p;
}

double PlantContext::getIntegralGain() {
	return integralGain;
}

void PlantContext::setIntegralGain(double i) {
	integralGain = i;
}

double PlantContext::getDerivateGain() {
	return derivateGain;
}
void PlantContext::setDerivateGain(double d) {
	derivateGain = d;
}
