/*
 * PlantController.h
 *
 *  Created on: Apr 1, 2013
 *      Author: dam7633
 */

#ifndef PLANTCONTROLLER_H_
#define PLANTCONTROLLER_H_

#include "ControlLoop.h"
#include "Sensor.h"
#include "Actuator.h"
#include <pthread.h>

#define MAX_INTEGRAL (2)
#define MIN_INTEGRAL (-2)

class PlantContext;

class PlantController: public ControlLoop {
public:
	PlantController(Sensor *sensor, Actuator *actuator);
	virtual ~PlantController();

	void initialize(PlantContext *context);
	void step();
	void shutdown();

	double getProportionalGain();
	double getIntegralGain();
	double getDerivateGain();

	void setParameters(double kp, double ki, double kd);

private:
	Sensor *sensor;
	Actuator *actuator;
	PlantContext *context;

	double proportionalGain;
	double integralGain;
	double derivativeGain;

	double integral;
	double derivative;

	double lastOutput;

	pthread_mutex_t parametersMutex;
};

#endif /* PLANTCONTROLLER_H_ */
