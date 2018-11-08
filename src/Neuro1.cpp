//============================================================================
// Name        : Neuro1.cpp
// Author      : Markus
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "NeuralNetwork.h"
#include <windows.h>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;
std::string getexepath()
{
  char result[ MAX_PATH ];
  return std::string( result, GetModuleFileName( NULL, result, MAX_PATH ) );
}

void outputCSVArr(std::vector<std::vector<float> > parsedCsv) {
	for (int i = 0; i < parsedCsv.size(); i++)
		{
		    for (int j = 0; j < parsedCsv[i].size(); j++)
		    {
		        cout << parsedCsv[i][j] << ", ";
		    }
		    cout << std::endl;
		}
}

int main() {


	//LEarning MNIST

	NeuralNetwork net;


	//vector< vector<InputNeuron*> > inputs;
	InputNeuron* inputs[28][28];
	vector< WorkingNeuron* > outputs(10);
	vector<float> weights(28*28*10);

	//Create Input neurons
	for(int i = 0; i<28; i++) {
		vector<InputNeuron*> row(28);
		//inputs.push_back(row);
		for(int k = 0; k<28; k++)  {
			InputNeuron* in = net.createNewInput(0);
			inputs[i][k] = in;
			//inputs[i].push_back(in);
		}
	}

	//create output neurons
	for(int k = 0; k<10; k++)
		outputs[k] = net.createNewOutput();

	//Create starting weights
	for(int i=0; i<weights.size(); i++)
		weights[i] = rand() % 10 - 6;

	//create full mesh
	net.createFullMesh();


	//LOAD CSV DATA
	std::ifstream data("train2.csv");
	std::string line;
	std::vector<std::vector<float> > parsedCsv;

	if (!data.is_open()) {
		cout << "closed" << endl;
	}

	while (std::getline(data, line)) {
		std::stringstream lineStream(line);
		std::string cell;
		std::vector<float> parsedRow;
		while (std::getline(lineStream, cell, ',')) {
			parsedRow.push_back(std::stod(cell));
		}

		parsedCsv.push_back(parsedRow);
	}

	/*
	 * TODO:
	 * ergebnisse anzeigen lassen.
	 * testdaten drüber laufen lassen.
	 */

	float epsilon = 0.01;
	//LEARN
	int l = 0;
	while(l++ < 10) {

		for(int i= 0; i< parsedCsv.size(); i++) {
			//Schleife für alle Test-Daten
			cout << "test: "<< l << endl;


			for(int x = 0; x < 28; x++) {
				for(int y = 0; y < 28; y++) {
					//x Reihen * 28 (Breite), plus Stelle in der Zeile, +1
					float input = parsedCsv[i][x*28 + y + 1];
					cout << input << ", ";
					inputs[x][y]->setValue(input);
				}
				cout << endl;
			}

			std::vector<float> shoulds(10);
			shoulds[parsedCsv[i][0]] = 1;

			net.deltaLearning(shoulds, epsilon);
		}

		epsilon *= 0.9;
	}

	/*
*/








	/*cout << "Neuronale Netze" << endl;
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

	i1->setValue(10);

	net.createHiddenNeurons(3);

	WorkingNeuron *o1 = net.createNewOutput();

	net.createFullMesh(true);

	cout << "Ausgabeneuron: " << o1->getValue() << endl;*/

	return 0;
}
