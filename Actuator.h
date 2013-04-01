/*
 * Actuator.h
 *
 *  Created on: Apr 1, 2013
 *      Author: dam7633
 */

#ifndef ACTUATOR_H_
#define ACTUATOR_H_

class Actuator {
public:
	virtual void setValue(double val) = 0;
};

#endif /* ACTUATOR_H_ */
