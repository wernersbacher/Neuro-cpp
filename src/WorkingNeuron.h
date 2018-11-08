/*
 * WorkingNeuron.h
 *
 *  Created on: 04.11.2018
 *      Author: Markus
 */

#ifndef WORKINGNEURON_H_
#define WORKINGNEURON_H_

#include "Neuron.h"
#include "Connection.h"
#include "ActivationFunctions.h"
#include <list>
#include <iostream>

class WorkingNeuron : public Neuron {

	std::list<Connection> connections;
	ActivationFunction* activationFunction = new Identity;

public:
	//Berechnung aller Werte der Connections mit Gewichtung
	float getValue() {
		float sum = 0;
		for(auto it = connections.begin(); it != connections.end(); ++it) {
			sum = sum + it->getValue();
		}
		return activationFunction->activation(sum);
	}

	void addConnection(Connection c) {
		connections.push_back(c);

	}

	void deltaLearning(float epsilon, float smallDelta) {
		int i=0;
		for(auto it = connections.begin(); it != connections.end(); ++it) {
				//Delta wik = epsilon * delta * ak
			float bigDelta = epsilon * smallDelta * it->getValue();
			it->addWeight(bigDelta);
		}
	}

};

#endif /* WORKINGNEURON_H_ */
