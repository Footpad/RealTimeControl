/*
 * UserInput.h
 *
 *  Created on: Apr 1, 2013
 *      Author: dam7633
 */

#ifndef USERINPUT_H_
#define USERINPUT_H_

#include "Thread.h"
#include "PlantController.h"

class UserInput: public Thread {
public:
	UserInput(PlantController *context);
	virtual ~UserInput();

	void* run();

private:
	PlantController *controller;
};

#endif /* USERINPUT_H_ */
