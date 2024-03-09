#include <iostream>
#include <Eigen/Eigen>
#include <FenDL/FenDL.hxx>


int main() {
  NeuralNetwork network;

  //network.setLayers<PerceptronLayer>({2,50000,60000});


  network.addLayer<PerceptronLayer>(2);
  network.addLayer<PerceptronLayer>(5);
  network.addLayer<PerceptronLayer>(10);
  network.addLayer<PerceptronLayer>(5);
  network.addComplete();
  //network.deleteAllLayers();


  //std::cout << network.getNetworkInfo();

  Sigmoid activation;
  network.setActivationFunction(activation);

  network.layers[0]->_active_values(0,0) = 0.6;
  network.layers[0]->_active_values(0,1) = 0.12;

  network.forwardFeed();

  //for(auto i : network.layers)std::cout << i->_active_values << "\n\n\n";

  Eigen::MatrixXd ra(1,5);
  ra << 1,0,0,0,0;

  network.backPropogation(ra);

  for(auto i : network.layers)std::cout << i->_gradient << "\n\n\n";

  system("pause");

  return 0;
}