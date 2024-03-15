#include <iostream>
#include <Eigen/Dense>
#include <FenDL/FenDL.hxx>

int main() {
  srand(time(NULL));
  NeuralNetwork network;
  network.setLayers<PerceptronLayer>({500,20,3});
  network.setActivationFunction(std::make_shared<Sinc>());



  TrainerStrategy ts(network,std::make_shared<ADAM>(network),std::make_shared<SquareError>());

  int t = 0;

  Matrixd input;
  Matrixd output(1,3);

  input.setRandom(1,500);
  output << 0.2,0.1,0.1;


  while(t < 10000000){

      t++;
      std::cout << t << " : ";

      ts.train(input,output,0.00005,false);

      std::cout << network._current_loss_function -> getMediumLoss(network._layers[network._layers.size()-1]->_active_values,output) << " \n" ;
      //std::cin.get();
  }

  //std::cin.get();
}