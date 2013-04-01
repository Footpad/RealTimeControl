/*
 * ControlLoop.h
 *
 *  Created on: Apr 1, 2013
 *      Author: dam7633
 */

#ifndef CONTROLLOOP_H_
#define CONTROLLOOP_H_

class ControlLoop {
public:
	virtual void initialize() = 0;
	virtual void step() = 0;
	virtual void shutdown() = 0;
};

#endif /* CONTROLLOOP_H_ */
