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

UserInput::UserInput(PlantContext *c) :
Thread("User Input"),
context(c) {

}

UserInput::~UserInput() {
}

void* UserInput::run() {
	double kp, ki, kd;
	double ref = 0.0;

	char inp;



	// Lower the priority of this thread so that it
	// does not block the controller.
	setPriority(UI_THREAD_PRIORITY);

	context->setRef(ref);

	cout << "Enter a command (h for help) \n";
	while (!killThread) {
		cout << "> ";
		cout.flush();

		cin >> inp;
		switch( inp ) {
		case 'p':
			cin >> kp >> ki >> kd;
			((PlantController*)context->getControlLoop())->setParameters(kp, ki, kd);
			break;
		case 'r':
			cin >> ref;
			context->setRef(ref);
			break;
		default:
			cout << "Invalid command!\n\n";
		case 'h':
			cout << "Commands are: \n" <<
					"\th - Help (this message)\n" <<
					"\tr - Set reference (Usage: r newRef)\n" <<
					"\tp - Set controller parameters (Usage: p newKp newKi newKd" << endl;
			break;
		}
	}

	return NULL;
}
