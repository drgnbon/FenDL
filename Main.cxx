#include <iostream>
#include <Eigen/Eigen>
#include <FenDL/FenDL.hxx>


int main() {

  //srand(time(NULL));
  NeuralNetwork network;
  network.setLayers<PerceptronLayer>({51,10000,2});

  /*Sigmoid x;
  network.setActivationFunction(std::make_shared<Sigmoid>(x));*/

  Eigen::MatrixXd input;
  input = Eigen::MatrixXd::Random(1,51);

  Eigen::MatrixXd answer(1,2);
  answer << 0.1,0.5;


	int t = 0;


  while(true)
  {
	  t++;
      network._layers[0]->_active_values = input;
      //network.forwardFeed();
	  std::cout << t << " : ";

	  //std::cout << t << " :\n" << network._layers[1]->_active_values(0);// << "\n\n" << network._layers[1]->_weights << "\n\n"  << (network._layers[1]->_active_values*network._layers[1]->_weights)(0) << "\n\n\n\n";
      network.learn(input,answer,0.5);
      //std::cout << t << " : " <<  network._current_loss_function->getMediumLoss(network._layers[network._layers.size()-1]->_active_values,answer) << "\n\n\n";
		std::cout << "\n";
	  //std::cout << t << "\t : " << network._layers[1]->_gradient(0) << "\n";

	  system("pause");
  }


}