/*
 * UserInput.cpp
 *
 *  Created on: Apr 1, 2013
 *      Author: dam7633
 */

#include "UserInput.h"
#include <iostream>

using namespace std;

UserInput::UserInput(PlantContext *c) :
Thread("User Input"),
context(c) {

}

UserInput::~UserInput() {
}

void* UserInput::run() {
	double kp, ki, kd;

	while (!killThread) {
		cout << "Enter PID controller constants (kp, ki, kd): ";
		cin >> kp >> ki >> kd;

		if (!cin) {
			stop();
		} else {
			context->setProportionalGain(kp);
			context->setIntegralGain(ki);
			context->setDerivateGain(kd);
		}
	}

	return NULL;
}
