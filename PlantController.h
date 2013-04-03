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

class PlantController: public ControlLoop {
public:
	PlantController(Sensor *sensor, Actuator *actuator);
	virtual ~PlantController();

	void initialize();
	void step();
	void shutdown();

	double getProportionalGain();
	double getIntegralGain();
	double getDerivateGain();

	void setParameters(double kp, double ki, double kd);

private:
	Sensor *sensor;
	Actuator *actuator;

	double proportionalGain;
	double integralGain;
	double derivateGain;

	pthread_mutex_t parametersMutex;
};

#endif /* PLANTCONTROLLER_H_ */
