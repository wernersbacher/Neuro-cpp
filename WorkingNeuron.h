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
#include <list>
#include <iostream>

class WorkingNeuron : public Neuron {

	std::list<Connection> connections;

public:
	//Berechnung aller Werte der Connections mit Gewichtung
	float getValue() {
		float sum = 0;
		//std::cout << "connectons einträge: " << connections.size() << std::endl;

		for(auto it = connections.begin(); it != connections.end(); ++it) {
			sum = sum + it->getValue();
		}
		return sum;
	}

	void addConnection(Connection c) {
		connections.push_back(c);

		//std::cout << "neue add value:" << c.getValue() << std::endl;
		//std::cout << "connectons einträge: " << connections.size() << std::endl;
	}


};

#endif /* WORKINGNEURON_H_ */
