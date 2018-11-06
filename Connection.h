/*
 * Connection.h
 *
 *  Created on: 04.11.2018
 *      Author: Markus
 */

#ifndef CONNECTION_H_
#define CONNECTION_H_

#include "Neuron.h"
#include <iostream>

class Connection {

	Neuron *_neuron;
	float _weight;

public:
	Connection(Neuron *neuron, float weight) {
		_neuron = neuron;
		_weight = weight;

	}

	float getValue() {
		return _neuron->getValue() * _weight;
	}

	float getWeight() {
		return _weight;
	}
};

#endif /* CONNECTION_H_ */
