/*
 * Neuron.h
 *
 *  Created on: 04.11.2018
 *      Author: Markus
 */

#ifndef NEURON_H_
#define NEURON_H_

class Neuron {
public:
	//Neuron();

	virtual float getValue() = 0;
	Neuron() {

	}
	virtual ~Neuron() {

	}

};

#endif /* NEURON_H_ */
