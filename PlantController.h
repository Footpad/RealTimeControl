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

class PlantController: public ControlLoop {
public:
	PlantController(Sensor *sensor, Actuator *actuator);
	virtual ~PlantController();

	void initialize();
	void step();
	void shutdown();

private:
	Sensor *sensor;
	Actuator *actuator;
};

#endif /* PLANTCONTROLLER_H_ */
