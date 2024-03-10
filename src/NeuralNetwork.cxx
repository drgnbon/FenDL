#include "FenDL/NeuralNetwork.hxx"
#include <iostream>

NeuralNetwork::NeuralNetwork()
{
	Sigmoid* _activation;
	SquareError* _loss;
	_current_activation_function = _activation;
	_current_loss_function = _loss;

}
NeuralNetwork::~NeuralNetwork() {}


