#include "FenDL/NeuralNetwork.hxx"
#include <iostream>

NeuralNetwork::NeuralNetwork()
{
  Sigmoid _activation;
  _current_activation_function = &_activation;

}
NeuralNetwork::~NeuralNetwork() {}


