#include <iostream>
#include <Eigen/Dense>
#include <FenDL/FenDL.hxx>

int main() {

  NeuralNetwork network;
  network.setLayers<PerceptronLayer>({5,100,3});
  network.setActivationFunction(std::make_shared<Sigmoid>());
  system("pause");
}