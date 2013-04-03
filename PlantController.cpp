/*
 * PlantController.cpp
 *
 *  Created on: Apr 1, 2013
 *      Author: dam7633
 */

#include "PlantController.h"

PlantController::PlantController(Sensor *s, Actuator *a) :
sensor(s),
actuator(a) {
	pthread_mutex_init(&parametersMutex, NULL);
}

PlantController::~PlantController() {
	pthread_mutex_destroy(&parametersMutex);
}

void PlantController::initialize() {

}

void PlantController::step() {

}

void PlantController::shutdown() {

}

double PlantController::getProportionalGain() {
	return proportionalGain;
}

double PlantController::getIntegralGain() {
	return integralGain;
}

double PlantController::getDerivateGain() {
	return derivateGain;
}

void PlantController::setParameters(double kp, double ki, double kd) {
	pthread_mutex_lock(&parametersMutex);
	proportionalGain = kp;
	integralGain = ki;
	derivateGain = kd;
	pthread_mutex_unlock(&parametersMutex);
}
