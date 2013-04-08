/*
 * PlantContext.h
 *
 *  Created on: Apr 1, 2013
 *      Author: dam7633
 */

#ifndef PLANTCONTEXT_H_
#define PLANTCONTEXT_H_

class ControlLoop;

class PlantContext {
public:
	PlantContext();
	virtual ~PlantContext();

	void start();

	void setRef(double newRef);
	double getRef();

	double getError();
	void setError(double error);
	double getLastError();

	ControlLoop *getControlLoop();
	void setControlLoop(ControlLoop *cl);

private:
	double ref;

	double error;
	double lastError;

	ControlLoop *controlLoop;
};

#endif /* PLANTCONTEXT_H_ */
