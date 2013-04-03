/*
 * UserInput.cpp
 *
 *  Created on: Apr 1, 2013
 *      Author: dam7633
 */

#include "UserInput.h"
#include <iostream>
#include <sstream>

#define UI_THREAD_PRIORITY (9)

using namespace std;

UserInput::UserInput(PlantController *c) :
Thread("User Input"),
controller(c) {

}

UserInput::~UserInput() {
}

void* UserInput::run() {
	double kp, ki, kd;
	string inputBuffer;

	// Lower the priority of this thread so that it
	// does not block the controller.
	setPriority(UI_THREAD_PRIORITY);

	while (!killThread) {
		cout << "Enter PID controller constants (kp, ki, kd): ";
		getline(cin, inputBuffer);

		if (!cin) {
			stop();
		} else {
			stringstream ss;
			ss << inputBuffer;
			ss >> kp >> ki >> kd;

			controller->setParameters(kp, ki, kd);
		}
	}

	return NULL;
}
