/*
 * PlantController.cpp
 *
 *  Created on: Apr 1, 2013
 *      Author: dam7633
 */

#include "PlantController.h"
#include "PlantContext.h"

PlantController::PlantController(Sensor *s, Actuator *a) :
sensor(s),
actuator(a),
proportionalGain(0.0),
integralGain(0.0),
derivativeGain(0.0),
lastOutput(0.0) {
	pthread_mutex_init(&parametersMutex, NULL);
}

PlantController::~PlantController() {
	pthread_mutex_destroy(&parametersMutex);
}

void PlantController::initialize(PlantContext *c) {
	context = c;
	integral = 0;
	derivative = 0;
}

void PlantController::step() {
	double currentReading = sensor->getValue();
	double setPoint = context->getRef();
	double error = (setPoint - currentReading);
	context->setError(error);

	integral += error; //integral + error;
	if(integral > MAX_INTEGRAL) {
		integral = MAX_INTEGRAL;
	} else if (integral < MIN_INTEGRAL) {
		integral = MIN_INTEGRAL;
	}
	derivative = (error - context->getLastError());

	double output = lastOutput + proportionalGain*error + integralGain*integral + derivativeGain*derivative;
	actuator->setValue( output );
	lastOutput = output;
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
	return derivativeGain;
}

void PlantController::setParameters(double kp, double ki, double kd) {
	pthread_mutex_lock(&parametersMutex);
	proportionalGain = kp;
	integralGain = ki;
	derivativeGain = kd;
	pthread_mutex_unlock(&parametersMutex);
}
