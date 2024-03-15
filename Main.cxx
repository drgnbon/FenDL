#include <iostream>
#include <Eigen/Dense>
#include <FenDL/FenDL.hxx>

int main() {
    //Sinc

  NeuralNetwork network;
  TrainerStrategy ts(std::make_shared<ADAM>());
  network.setLayers<PerceptronLayer>({500,2000,3});
  network.setActivationFunction(std::make_shared<Sinc>());

  int t = 0;

  Matrixd input;
  Matrixd output(1,3);

  input.setRandom(1,500);
  output << 0.2,0.1,0.1;


  while(t < 10000000){

      t++;
      std::cout << t << " : ";

      ts.train(network,input,output,0.005,false);

      std::cout << network._current_loss_function -> getMediumLoss(network._layers[network._layers.size()-1]->_active_values,output) << " \n" ;
      //std::cin.get();
  }

  //std::cin.get();
}