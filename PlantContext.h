/*
 * PlantContext.h
 *
 *  Created on: Apr 1, 2013
 *      Author: dam7633
 */

#ifndef PLANTCONTEXT_H_
#define PLANTCONTEXT_H_

class PlantContext {
public:
	PlantContext();
	virtual ~PlantContext();

	void start();

	double getProportionalGain();
	void setProportionalGain(double p);

	double getIntegralGain();
	void setIntegralGain(double i);

	double getDerivateGain();
	void setDerivateGain(double d);

private:
	double proportionalGain;
	double integralGain;
	double derivateGain;
};

#endif /* PLANTCONTEXT_H_ */
