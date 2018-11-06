/*
 * InputNeuron.h
 *
 *  Created on: 04.11.2018
 *      Author: Markus
 */

#ifndef INPUTNEURON_H_
#define INPUTNEURON_H_

#include "Neuron.h"
#include "Connection.h"
#include <list>
#include <iostream>

class InputNeuron : public Neuron {

	float value = 0;
public:

	InputNeuron(float weight) {
		value = weight;
	}

	//Override
	float getValue() {
		return value;
	}

	void setValue(float in) {
		value = in;
	}


};

#endif /* INPUTNEURON_H_ */
