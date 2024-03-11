#include <iostream>
#include <Eigen/Eigen>
#include <FenDL/FenDL.hxx>


int main() {
  NeuralNetwork network;
  network.setLayers<PerceptronLayer>({2,5,3,4,6,2});

  Eigen::MatrixXd input(1,2);
  input << 0.15,0.5;

  Eigen::MatrixXd answer(1,2);
  answer << 1,0;





  while(true)
  {
      network._layers[0]->_active_values = input;
      network.forwardFeed();
      network.learn(input,answer,0.0001);
      std::cout << network._current_loss_function->getMediumLoss(network._layers[network._layers.size()-1]->_active_values,answer) << "\n\n\n";

  }















  }