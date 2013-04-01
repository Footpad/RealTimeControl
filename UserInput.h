/*
 * UserInput.h
 *
 *  Created on: Apr 1, 2013
 *      Author: dam7633
 */

#ifndef USERINPUT_H_
#define USERINPUT_H_

#include "Thread.h"
#include "PlantContext.h"

class UserInput: public Thread {
public:
	UserInput(PlantContext *context);
	virtual ~UserInput();

	void* run();

private:
	PlantContext *context;
};

#endif /* USERINPUT_H_ */
