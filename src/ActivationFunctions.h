/*
 * ActivationFunctions.h
 *
 *  Created on: 06.11.2018
 *      Author: Markus
 */

#ifndef ACTIVATIONFUNCTIONS_H_
#define ACTIVATIONFUNCTIONS_H_

class ActivationFunction {
public:
	virtual float activation(float input) = 0;
};


class Identity : public ActivationFunction {
public:
	float activation(float input)  {
		return input;
	}
	Identity() {}
};


class Boolean : public ActivationFunction {
public:
	float activation(float input)  {
		if(input < 0)
			return 0;
		return 1;
	}
};





#endif /* ACTIVATIONFUNCTIONS_H_ */
