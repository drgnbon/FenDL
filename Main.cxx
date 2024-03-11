#include <iostream>
#include <Eigen/Eigen>
#include <FenDL/FenDL.hxx>


int main() {
  NeuralNetwork network;
  network.setLayers<PerceptronLayer>({2000,1000,2});

  Eigen::MatrixXd input;
  input = Eigen::MatrixXd::Random(1,2000);

  Eigen::MatrixXd answer(1,2);
  answer << 0.1,0.5;





  while(true)
  {
      network._layers[0]->_active_values = input;
      //network.forwardFeed();
      network.learn(input,answer,0.05);
      std::cout << network._current_loss_function->getMediumLoss(network._layers[network._layers.size()-1]->_active_values,answer) << "\n\n\n";
  }















  }