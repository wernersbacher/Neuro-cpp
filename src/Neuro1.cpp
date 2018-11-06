//============================================================================
// Name        : Neuro1.cpp
// Author      : Markus
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "NeuralNetwork.h"
using namespace std;

int main() {
	cout << "Neuronale Netze" << endl;
									//hidden mit input
	std::vector<float> weights = {3,-1,2,0,
									2,1,1,-1,
									1,-3,2,1,
									//hidden mit output
									1,2,1};

	NeuralNetwork net;

	InputNeuron *i1 = net.createNewInput(1);
	InputNeuron *i2 = net.createNewInput(2);
	InputNeuron *i3 = net.createNewInput(1);
	InputNeuron *i4 = net.createNewInput(1);

	i1->setValue(10 );

	net.createHiddenNeurons(3);

	WorkingNeuron *o1 = net.createNewOutput();

	net.createFullMesh(weights);

	/*
	std::list<WorkingNeuron> output = net.getOutputNeurons();
	for(auto it_o = output.begin(); it_o != output.end(); ++it_o)
		cout << "output[it]: " << it_o->getValue() << endl;*/

	cout << "Ausgabeneuron: " << o1->getValue() << endl;

	return 0;
}
