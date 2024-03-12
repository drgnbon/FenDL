#include <iostream>
#include <Eigen/Eigen>
#include <FenDL/FenDL.hxx>

int main() {


  //srand(time(NULL));
  NeuralNetwork network;
  network.setLayers<PerceptronLayer>({5000,100,3});


  network.setActivationFunction(std::make_shared<Sigmoid>());


  Eigen::MatrixXd input;
  input = Eigen::MatrixXd::Random(1,5000);

  Eigen::MatrixXd answer;
  answer = Eigen::MatrixXd::Random(1,3);

  int t = 0;

  while(true)
  {
	  t++;
	  std::cout << t << " : ";

	  network.learn(input,answer,0.1);

	  std::cout <<  network._current_loss_function->getMediumLoss(network._layers[network._layers.size()-1]->_active_values,answer) << "\n\n\n";
	  std::cout << "\n";

	  //system("pause");
  }

}