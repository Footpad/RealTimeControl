/*
 * PlantContext.cpp
 *
 *  Created on: Apr 1, 2013
 *      Author: dam7633
 */

#include "PlantContext.h"
#include <time.h>
#include <sys/siginfo.h>
#include "ControlLoop.h"

void timer_tick(union sigval sig) {
	PlantContext *context = (PlantContext *)sig.sival_ptr;
	context->getControlLoop()->step();
}

PlantContext::PlantContext() {
	// TODO Auto-generated constructor stub

}

PlantContext::~PlantContext() {
	// TODO Auto-generated destructor stub
}

void PlantContext::start() {
	timer_t timer;
	struct sigevent timerEvent;
	struct itimerspec timerSpec;

	SIGEV_THREAD_INIT(&timerEvent, timer_tick, this, NULL);

	timerSpec.it_interval.tv_nsec = 100000000;
	timerSpec.it_interval.tv_sec = 0;
	timerSpec.it_value.tv_nsec = 100000000;
	timerSpec.it_value.tv_sec = 0;

	timer_create(CLOCK_REALTIME, &timerEvent, &timer);
	timer_settime(timer, 0, &timerSpec, NULL);
}

double PlantContext::getError() {
	return error;
}

void PlantContext::setError(double e) {
	lastError = error;
	error = e;
}

double PlantContext::getLastError() {
	return lastError;
}

ControlLoop *PlantContext::getControlLoop() {
	return controlLoop;
}

void PlantContext::setControlLoop(ControlLoop *cl) {
	controlLoop = cl;
}

void PlantContext::setRef(double newRef) {
	ref = newRef;
}

double PlantContext::getRef() {
	return ref;
}

