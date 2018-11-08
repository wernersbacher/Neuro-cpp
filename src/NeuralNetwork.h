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
#include <stdexcept>

class NeuralNetwork {

	std::list<InputNeuron> inputNeurons;
	std::list<WorkingNeuron> hiddenNeurons;
	std::list<WorkingNeuron> outputNeurons;
public:
	//NeuralNetwork();

	//Neues output erstellen
	WorkingNeuron* createNewOutput() {
		WorkingNeuron* out = new WorkingNeuron();
		outputNeurons.push_back(*out);
		return &outputNeurons.back();
	}

	//Neuen Input erstellen
	InputNeuron* createNewInput(float weight) {
		InputNeuron* in = new InputNeuron(weight);
		inputNeurons.push_back(*in);
		return &inputNeurons.back();
	}

	//Neuen Hidden Neuron erstellen
	void createHiddenNeurons(int amount) {
		for (int i = 0; i < amount; i++) {
			WorkingNeuron* hid = new WorkingNeuron();
			hiddenNeurons.push_back(*hid);
		}

	}

	void deltaLearning(std::vector<float> shoulds, float epsilon) {
		if (shoulds.size() != outputNeurons.size())
			throw std::runtime_error("Wrong shoulds size");
		if (0 != hiddenNeurons.size())
			throw std::runtime_error("Can't use deltaLearning with hiddenNeurons yet");

		int i = 0;
		for (auto it_o = outputNeurons.begin(); it_o != outputNeurons.end(); ++it_o) {
			float smallDelta = shoulds[i++] - it_o->getValue();
			it_o->deltaLearning(epsilon, smallDelta);
		}

	}

	//Alles mit allem verbinden (außer natürlich Input unter sich), also layer)
	void createFullMesh() {
		//direkt output mit input
		if (hiddenNeurons.size() == 0)
			for (auto it_o = outputNeurons.begin(); it_o != outputNeurons.end();
					++it_o) {
				for (auto it_i = inputNeurons.begin();
						it_i != inputNeurons.end(); ++it_i) {
					//erstellt eine neue Connection und einen Pointer,
					// die Connection erhält als Params den Pointer auf das InputNeuron und Gewicht 0.
					Connection con(&(*it_i), 0);
					//das Working/Output Neuron erhält diesen Connectionpointer zugewiesen
					it_o->addConnection(con);

				}
			}

		else {
			//output mit hidden
			for (auto it_o = outputNeurons.begin(); it_o != outputNeurons.end();
					++it_o) {
				for (auto it_h = hiddenNeurons.begin();
						it_h != hiddenNeurons.end(); ++it_h) {
					Connection con(&(*it_h), 0);
					it_o->addConnection(con);

				}
			}
			//hidden mit input
			for (auto it_h = hiddenNeurons.begin(); it_h != hiddenNeurons.end();
					++it_h) {
				for (auto it_i = inputNeurons.begin();
						it_i != inputNeurons.end(); ++it_i) {
					Connection con(&(*it_i), 0);
					it_h->addConnection(con);

				}
			}
		}

	}

	void createFullMesh(std::vector<float> arr) {

		if (hiddenNeurons.size() == 0) {
			//1 layer
			if (arr.size() != inputNeurons.size() * outputNeurons.size()) {
				throw "hallo";
			}
			int i = 0;
			for (auto it_o = outputNeurons.begin(); it_o != outputNeurons.end();
					++it_o) {
				for (auto it_i = inputNeurons.begin();
						it_i != inputNeurons.end(); ++it_i) {
					//erstellt eine neue Connection und einen Pointer,
					// die Connection erhält als Params den Pointer auf das InputNeuron und Gewicht aus Array
					Connection con(&(*it_i), arr[i++]);
					//das Working/Output Neuron erhält diesen Connectionpointer zugewiesen
					it_o->addConnection(con);
				}
			}
		} else {
			//2 layer
			if (arr.size()
					!= inputNeurons.size() * hiddenNeurons.size()
							+ hiddenNeurons.size() * outputNeurons.size()) {
				throw "gewichte falsch";
			}
			int i = 0;
			//hidden mit input
			for (auto it_h = hiddenNeurons.begin(); it_h != hiddenNeurons.end();
					++it_h) {
				for (auto it_i = inputNeurons.begin();
						it_i != inputNeurons.end(); ++it_i) {
					Connection con(&(*it_i), arr[i++]);
					it_h->addConnection(con);

				}
			}
			//output mit hidden
			for (auto it_o = outputNeurons.begin(); it_o != outputNeurons.end();
					++it_o) {
				for (auto it_h = hiddenNeurons.begin();
						it_h != hiddenNeurons.end(); ++it_h) {
					Connection con(&(*it_h), arr[i++]);
					it_o->addConnection(con);

				}
			}

		}

	}

};

#endif /* NEURALNETWORK_H_ */
