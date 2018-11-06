/*
 * NeuralNetwork.h
 *
 *  Created on: 04.11.2018
 *      Author: Markus
 */

#ifndef NEURALNETWORK_H_
#define NEURALNETWORK_H_

#include "InputNeuron.h"
#include "WorkingNeuron.h"
#include <list>
#include <vector>
#include <iostream>

class NeuralNetwork {

	std::list<InputNeuron> inputNeurons;
	std::list<WorkingNeuron> outputNeurons;
public:
	//NeuralNetwork();

	//Neues output erstellen
	WorkingNeuron* createNewOutput() {
		WorkingNeuron* out = new WorkingNeuron();
		outputNeurons.push_back(*out);
		return out;
	}

	//Neuen Input erstellen
	InputNeuron* createNewInput(float weight) {
		InputNeuron* in = new InputNeuron(weight);
		inputNeurons.push_back(*in);
		return &inputNeurons.back();
	}

	std::list<WorkingNeuron> getOutputNeurons() {
		return outputNeurons;
	}

	//Alles mit allem verbinden (außer natürlich Input unter sich), also layer)
	void createFullMesh() {
		for(auto it_o = outputNeurons.begin(); it_o != outputNeurons.end(); ++it_o) {
			for(auto it_i = inputNeurons.begin(); it_i != inputNeurons.end(); ++it_i) {
				//erstellt eine neue Connection und einen Pointer,
				// die Connection erhält als Params den Pointer auf das InputNeuron und Gewicht 0.
				//Connection con(&(*it_i), 0);
				//das Working/Output Neuron erhält diesen Connectionpointer zugewiesen
				//it_o->addConnection(con);

			}
		}

	}

	void createFullMesh(std::vector<float> arr) {
		if(arr.size() != inputNeurons.size() * outputNeurons.size()) {
			throw "hallo";
		}

		int i = 0;
		for(auto it_o = outputNeurons.begin(); it_o != outputNeurons.end(); ++it_o) {
			for(auto it_i = inputNeurons.begin(); it_i != inputNeurons.end(); ++it_i) {
				//erstellt eine neue Connection und einen Pointer,
				// die Connection erhält als Params den Pointer auf das InputNeuron und Gewicht aus Array
				Connection con(&(*it_i), arr[i++]);
				//std::cout << "InputValue: " << it_i->getValue() << std::endl;
				//std::cout << "neue connections value:" << con.getValue() << std::endl;
				//das Working/Output Neuron erhält diesen Connectionpointer zugewiesen
				it_o->addConnection(con);
			}
		}
	}

};

#endif /* NEURALNETWORK_H_ */
